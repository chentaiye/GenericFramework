//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
// Json/Public/
#include <Dom/JsonValue.h>
#include <Dom/JsonObject.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <filesystem>
#include <string>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Log/LogLevel.h"
#pragma endregion

namespace Common {
/** 承载当前模块LogStream职责，衔接上层调用与模块内部实现。 */
class LogStream
{
public:
  LogStream& operator<<(bool value);
  LogStream& operator<<(LogLevel level);
  LogStream& operator<<(const FString& value);
  LogStream& operator<<(const std::filesystem::path& value);
  LogStream& operator<<(const std::wstring& value);
  LogStream& operator<<(const wchar_t& value);
  LogStream& operator<<(const wchar_t* value);
  LogStream& operator<<(const std::u16string& value);
  LogStream& operator<<(const char16_t& value);
  LogStream& operator<<(const char16_t* value);
  LogStream& operator<<(const std::string& value);
  LogStream& operator<<(const char& value);
  LogStream& operator<<(const char* value);
  LogStream& operator<<(long value);
  LogStream& operator<<(unsigned long value);
  LogStream& operator<<(long long value);
  LogStream& operator<<(unsigned long long value);
  LogStream& operator<<(double value);
  LogStream& operator<<(long double value);
  LogStream& operator<<(short value);
  LogStream& operator<<(int value);
  LogStream& operator<<(unsigned short value);
  LogStream& operator<<(unsigned int value);
  LogStream& operator<<(float value);
  LogStream& operator<<(const void* value);
  LogStream& operator<<(std::nullptr_t);

  /** 返回当前缓冲中的完整日志文本。 */
  const FString& toString() const { return m_stream; }

  /** 返回当前日志文本长度。 */
  int32 length() const { return m_stream.Len(); }

  /** 清空当前日志文本缓冲。 */
  void reset() { m_stream.Empty(); }

private:
  /** 累积本次日志消息的字符串缓冲。 */
  mutable FString m_stream;
};

/** Shipping 下吞掉调试日志的空流实现。 */
class NopStream
{
public:
  template<typename T>
  NopStream& operator<<(const T& value) { return *this; }
};
} // namespace Common
