//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
#include <Containers/StringConv.h>
// Json/Public/
#include <Dom/JsonValue.h>
#include <Dom/JsonObject.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <string>
#include <vector>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewTypes.h>
#pragma endregion

#pragma region "Project Private Headers"
#include "HeadersCefViewCore.h"
#pragma endregion

namespace Common::Convert {
/** 将 CEF 字符串按 UTF-8 转换为 Unreal FString。 */
inline FString
StringC2F(const CefString& s)
{
  return (TCHAR*)FUTF8ToTCHAR(s.ToString().c_str()).Get();
}

/** 将 Unreal FString 按 UTF-8 转换为 CEF 字符串。 */
inline CefString
StringF2C(const FString& s)
{
  return (char*)FTCHARToUTF8(*s).Get();
}

/** 将 CEF FrameId 转换为跨版本封装后的 Unreal 类型。 */
inline FCefFrameId
FrameIdC2F(const CefFrameId& id)
{
#if CEF_VERSION_MAJOR < 122
  return id;
#else
  return *StringC2F(id);
#endif
}

/** 将封装后的 Unreal FrameId 还原为当前 CEF 版本使用的类型。 */
inline CefFrameId
FrameIdF2C(const FCefFrameId& id)
{
#if CEF_VERSION_MAJOR < 122
  return id;
#else
  return StringF2C(id.Value);
#endif
}

/** 递归转换 CEF Value 为 Unreal JSON Value。 */
void
CefValueToJsonValue(TSharedPtr<FJsonValue>& jValue, CefValue* cValue);

/** 递归转换 Unreal JSON Value 为 CEF Value。 */
void
JsonValueToCefValue(CefValue* cValue, const TSharedPtr<FJsonValue>& jValue);
}; // namespace Common::Convert
