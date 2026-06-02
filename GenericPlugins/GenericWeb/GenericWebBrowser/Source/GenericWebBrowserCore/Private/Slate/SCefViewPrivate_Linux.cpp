//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#if defined(PLATFORM_LINUX) && PLATFORM_LINUX

#pragma region "Self Header"
#include "SCefViewPrivate.h"
#pragma endregion

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
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
{};

void
FCefOsrBulkData::RetainSharedTexture(void* InHandle, EPixelFormat InPixelFormat)
{
  FScopeLock ScopeLock(&Lock);
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
  FScopeLock ScopeLock(&Lock);
  return nullptr;
}

void
FCefOsrBulkData::DiscardSharedTexture()
{
}
#endif
