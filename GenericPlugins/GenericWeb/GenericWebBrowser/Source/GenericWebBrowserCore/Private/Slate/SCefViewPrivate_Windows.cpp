//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS

#pragma region "Self Header"
#include "SCefViewPrivate.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Misc/CString.h>
#include <Misc/ScopeLock.h>
#include <Misc/EngineVersionComparison.h>
// Engine/Public/
#include <Rendering/Texture2DResource.h>

//  D3D RHI headers
#if UE_VERSION_EQUAL_OR_GREATER(5, 1, 0)
// Windows/D3D11RHI/Public/
#include <ID3D11DynamicRHI.h>
// D3D12RHI/Public/
#include <ID3D12DynamicRHI.h>
#elif UE_VERSION_EQUAL_OR_GREATER(5, 0, 0)
// Windows/D3D11RHI/Private/
#include <D3D11RHIPrivate.h>
// D3D12RHI/Private/
#include <D3D12RHIPrivate.h>
#endif
#pragma endregion

#pragma region <Platform Headers>
#include <Windows/AllowWindowsPlatformTypes.h>
#include <d3d11_1.h>
#include <d3d12.h>
#include <wrl/client.h>
#include <Windows/HideWindowsPlatformTypes.h>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefContext.h>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Log.h"
#pragma endregion

#define HEX_STRING(i) FString::Printf(TEXT("0x%X"), i)

#if UE_VERSION_EQUAL_OR_GREATER(5, 1, 0)
using UED3D11DynamicRHI = ID3D11DynamicRHI;
using UED3D12DynamicRHI = ID3D12DynamicRHI;
#else
using UED3D11DynamicRHI = FD3D11DynamicRHI;
using UED3D12DynamicRHI = FD3D12DynamicRHI;
#endif

class FCefOsrBulkData::SharedTextureData
{
public:
  Microsoft::WRL::ComPtr<ID3D11Texture2D> D3D11Texture2D;
  Microsoft::WRL::ComPtr<ID3D12Resource> D3D12Resource;
};

void
FCefOsrBulkData::RetainSharedTexture(void* InHandle, EPixelFormat InPixelFormat)
{
  HRESULT Result = E_FAIL;
  if (0 == FCString::Stricmp(TEXT("D3D11"), GDynamicRHI->GetName())) {
    /////////////////////////////////////////////////////////////
    /** D3D11 路径通过共享句柄打开 CEF 提供的纹理。 */
    ID3D11Device* D3D11Device = static_cast<ID3D11Device*>(GDynamicRHI->RHIGetNativeDevice());

    /** OpenSharedResource1 需要 ID3D11Device1 接口。 */
    Microsoft::WRL::ComPtr<ID3D11Device1> D3D11Device1;
    Result = D3D11Device->QueryInterface(IID_PPV_ARGS(&D3D11Device1));
    if (!D3D11Device1) {
      logError() << "Failed to open ID3D11Device1 device:" << HEX_STRING(Result);
      return;
    }

    /** 将 CEF 回调中的共享句柄转换为可被 Unreal RHI 包装的 D3D11 纹理。 */
    Microsoft::WRL::ComPtr<ID3D11Texture2D> SharedD3D11Texture2D;
    Result = D3D11Device1->OpenSharedResource1(InHandle, IID_PPV_ARGS(&SharedD3D11Texture2D));
    if (!SharedD3D11Texture2D) {
      logError() << "Failed to open shared texture:" << HEX_STRING(Result);
      return;
    }

    {
      FScopeLock ScopeLock(&Lock);
      PixelFormat = InPixelFormat;
      SharedTexture->D3D11Texture2D = SharedD3D11Texture2D;
    }
  } else if (0 == FCString::Stricmp(TEXT("D3D12"), GDynamicRHI->GetName())) {
    /////////////////////////////////////////////////////////////
    /** D3D12 路径通过共享句柄打开 CEF 提供的资源。 */
    ID3D12Device* D3D12Device = static_cast<ID3D12Device*>(GDynamicRHI->RHIGetNativeDevice());

    /** 将 CEF 回调中的共享句柄转换为 D3D12 资源。 */
    Microsoft::WRL::ComPtr<ID3D12Resource> SharedD3D12Resource;
    Result = D3D12Device->OpenSharedHandle(InHandle, IID_PPV_ARGS(&SharedD3D12Resource));
    if (!SharedD3D12Resource) {
      logError() << "Failed to open shared texture:" << HEX_STRING(Result);
      return;
    }

    {
      FScopeLock ScopeLock(&Lock);
      PixelFormat = InPixelFormat;
      SharedTexture->D3D12Resource = SharedD3D12Resource;
    }
  } else {
    logWarn() << "Unsupported RHI:" << GDynamicRHI->GetName();
  }
}

void
FCefOsrBulkData::InitSharedTextureData()
{
  SharedTexture = MakePimpl<SharedTextureData>();
}

void*
FCefOsrBulkData::GetSharedTextureHandle() const
{
  return nullptr;
}

uint32
FCefOsrBulkData::GetSharedTextureSize() const
{
  return 0;
}

UETexture2DRHIRef
FCefOsrBulkData::CreateTextureFromSharedTexture(FRHICommandListImmediate& RHICommandList)
{
  UETexture2DRHIRef TextureRHI;

  FScopeLock ScopeLock(&Lock);
  if (0 == FCString::Stricmp(TEXT("D3D11"), GDynamicRHI->GetName())) {
    /** D3D11 后备纹理为空说明本帧还没有新的共享资源可上传。 */
    if (!SharedTexture->D3D11Texture2D) {
      return TextureRHI;
    }

    /** 用 Unreal D3D11 RHI 包装共享纹理资源，供 Slate 绘制。 */
    TextureRHI = static_cast<UED3D11DynamicRHI*>(GDynamicRHI)
                   ->RHICreateTexture2DFromResource(
                     PixelFormat, TexCreate_Shared, FClearValueBinding::None, SharedTexture->D3D11Texture2D.Get());
  } else if (0 == FCString::Stricmp(TEXT("D3D12"), GDynamicRHI->GetName())) {
    /** D3D12 后备资源为空说明本帧还没有新的共享资源可上传。 */
    if (!SharedTexture->D3D12Resource) {
      return TextureRHI;
    }

    /** 用 Unreal D3D12 RHI 包装共享资源，供 Slate 绘制。 */
    TextureRHI = static_cast<UED3D12DynamicRHI*>(GDynamicRHI)
                   ->RHICreateTexture2DFromResource(
                     PixelFormat, TexCreate_Shared, FClearValueBinding::None, SharedTexture->D3D12Resource.Get());
  } else {
    logWarn() << "Unsupported RHI:" << GDynamicRHI->GetName();
  }

  if (!TextureRHI.IsValid()) {
    logError() << "Failed to create RHI texture from shared resource";
    return TextureRHI;
  }

  DiscardSharedTexture();
  return TextureRHI;
}

void
FCefOsrBulkData::DiscardSharedTexture()
{
  SharedTexture->D3D11Texture2D.Reset();
  SharedTexture->D3D12Resource.Reset();
  PixelFormat = EPixelFormat::PF_Unknown;
}
#endif
