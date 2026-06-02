//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// ApplicationCore/Public/
#include <GenericPlatform/ITextInputMethodSystem.h>
// Core/Public/
#include <UObject/WeakObjectPtrTemplates.h>
// CoreUObject/Public/
#include <UObject/StrongObjectPtr.h>
#pragma endregion

#pragma region <Platform Headers>
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#include <Windows/AllowWindowsPlatformTypes.h>
#include <Windows.h>
#include <Windows/HideWindowsPlatformTypes.h>
#endif
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#include "Common/Log.h"
#pragma endregion

namespace Common {
namespace Windows {
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
/** 将 Windows 输入法候选窗口位置同步到当前 Slate 文本输入上下文。 */
void
UpdateIMMWindowPositions(const TSharedRef<ITextInputMethodContext>& InInputContext);
#endif
} // namespace Windows

} // namespace Common
