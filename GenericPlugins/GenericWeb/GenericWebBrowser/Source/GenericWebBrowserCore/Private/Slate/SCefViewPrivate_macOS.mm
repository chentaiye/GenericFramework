//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#if (defined(PLATFORM_MAC) && PLATFORM_MAC)

#pragma region "Self Header"
#include "SCefViewPrivate.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/ResourceArray.h>
// RHI/Public/
#include <RHICommandList.h>
#pragma endregion

#pragma region <Platform Headers>
#import <Metal/Metal.h>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Log.h"
#pragma endregion

class FCefOsrBulkData::SharedTextureData
{
public:
  IOSurfaceRef IOSurfaceHandle = nullptr;
};

void
FCefOsrBulkData::RetainSharedTexture(void* InHandle, EPixelFormat InPixelFormat)
{
  FScopeLock ScopeLock(&Lock);
  
  DiscardSharedTexture();
  
  IOSurfaceRef Handle = (IOSurfaceRef)(InHandle);
  CFRetain(Handle);
  PixelFormat = InPixelFormat;
  SharedTexture->IOSurfaceHandle = Handle;
}

void
FCefOsrBulkData::InitSharedTextureData()
{
#if !UE_VERSION_EQUAL_OR_GREATER(5, 7, 0)
  Type = FResourceBulkDataInterface::EBulkDataType::VREyeBuffer;
#endif
  SharedTexture = MakePimpl<SharedTextureData>();
}

void*
FCefOsrBulkData::GetSharedTextureHandle() const
{
  return (void*)(SharedTexture->IOSurfaceHandle);
}

uint32
FCefOsrBulkData::GetSharedTextureSize() const
{
  return IOSurfaceGetAllocSize(SharedTexture->IOSurfaceHandle);
}

UETexture2DRHIRef
FCefOsrBulkData::CreateTextureFromSharedTexture(FRHICommandListImmediate& RHICommandList)
{
  UETexture2DRHIRef TextureRHI;
  ETextureCreateFlags TextureCreateFlags = TexCreate_ShaderResource;
  ERHIAccess TextureInitialState = ERHIAccess::Present | ERHIAccess::SRVMask;

  FScopeLock ScopeLock(&Lock);
  if (!SharedTexture->IOSurfaceHandle) {
    /** IOSurface 为空说明本帧还没有新的共享纹理可上传。 */
    return TextureRHI;
  }

  @autoreleasepool {
#if UE_VERSION_EQUAL_OR_GREATER(5, 7, 0)
    /** UE 5.7 起使用初始化器接口创建 IOSurface 纹理。 */
    auto RHITextureDesc = FRHITextureCreateDesc::Create2D( //
      TEXT("UCefViewTextureWithIOSurface"),                //
      IOSurfaceGetWidth(SharedTexture->IOSurfaceHandle),   //
      IOSurfaceGetHeight(SharedTexture->IOSurfaceHandle),  //
      PixelFormat);
    RHITextureDesc.SetInitActionBulkData(this);
    RHITextureDesc.SetFlags(TextureCreateFlags);
    RHITextureDesc.SetInitialState(TextureInitialState);

  TextureRHI = GDynamicRHI->RHICreateTextureInitializer(RHICommandList, RHITextureDesc).Finalize();
#elif UE_VERSION_EQUAL_OR_GREATER(5, 4, 0)
    /** UE 5.4 到 5.6 使用 FRHITextureCreateDesc 直接创建纹理。 */
    auto RHITextureDesc = FRHITextureCreateDesc::Create2D( //
      TEXT("UCefViewTextureWithIOSurface"),                //
      IOSurfaceGetWidth(SharedTexture->IOSurfaceHandle),   //
      IOSurfaceGetHeight(SharedTexture->IOSurfaceHandle),  //
      PixelFormat);
    RHITextureDesc.SetBulkData(this);
    RHITextureDesc.SetFlags(TextureCreateFlags);
    RHITextureDesc.SetInitialState(TextureInitialState);

    TextureRHI = GDynamicRHI->RHICreateTexture(RHICommandList, RHITextureDesc);
#elif UE_VERSION_EQUAL_OR_GREATER(5, 1, 0)
    /** UE 5.1 到 5.3 需要走渲染线程纹理创建接口。 */
    auto RHITextureDesc = FRHITextureCreateDesc::Create2D( //
      TEXT("UCefViewTextureWithIOSurface"),                //
      IOSurfaceGetWidth(SharedTexture->IOSurfaceHandle),   //
      IOSurfaceGetHeight(SharedTexture->IOSurfaceHandle),  //
      PixelFormat);
    RHITextureDesc.SetBulkData(this);
    RHITextureDesc.SetFlags(TextureCreateFlags);
    RHITextureDesc.SetInitialState(TextureInitialState);

    TextureRHI = GDynamicRHI->RHICreateTexture_RenderThread(RHICommandList, RHITextureDesc);
#else
    /** UE 5.0 仍使用旧版 2D 纹理创建接口。 */
    FRHIResourceCreateInfo RHIResourceCreateInfo(TEXT("UCefViewTextureWithIOSurface"), this);

    TextureRHI = GDynamicRHI->RHICreateTexture2D_RenderThread( //
      RHICommandList,                                          //
      IOSurfaceGetWidth(SharedTexture->IOSurfaceHandle),       // uint32 SizeX,
      IOSurfaceGetHeight(SharedTexture->IOSurfaceHandle),      // uint32 SizeY,
      PixelFormat,                                             // uint8 Format,
      1,                                                       // uint32 NumMips,
      1,                                                       // uint32 NumSamples,
      TextureCreateFlags,                                      // ETextureCreateFlags Flags,
      TextureInitialState,                                     // ERHIAccess InResourceState,
      RHIResourceCreateInfo                                    // FRHIResourceCreateInfo & CreateInfo
    );
#endif
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
  if (SharedTexture->IOSurfaceHandle == nullptr) {
    return;
  }
  
  IOSurfaceRef Handle = SharedTexture->IOSurfaceHandle;
  SharedTexture->IOSurfaceHandle = nullptr;
  CFRelease(Handle);
  PixelFormat = EPixelFormat::PF_Unknown;
}
#endif
