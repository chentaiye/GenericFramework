//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "LogStream.h"
#pragma endregion

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <sstream>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#pragma endregion

namespace Common {

Common::LogStream&
LogStream::operator<<(bool value)
{
  /** 日志流统一输出布尔文本，避免 FString 追加时出现平台相关格式差异。 */
  if (value)
    m_stream += TEXT("true");
  else
    m_stream += TEXT("false");
  return *this;
}

Common::LogStream&
LogStream::operator<<(LogLevel level)
{
  switch (level) {
    case LogLevel::kLevelTrace:
      m_stream += TEXT("|TRACE|");
      break;
    case LogLevel::kLevelDebug:
      m_stream += TEXT("|DEBUG|");
      break;
    case LogLevel::kLevelInfo:
      m_stream += TEXT("|INFO |");
      break;
    case LogLevel::kLevelWarn:
      m_stream += TEXT("|WARN |");
      break;
    case LogLevel::kLevelError:
      m_stream += TEXT("|ERROR|");
      break;
    case LogLevel::kLevelFatal:
      m_stream += TEXT("|FATAL|");
      break;
  }
  return *this;
}

Common::LogStream&
LogStream::operator<<(const FString& value)
{
  m_stream += value;
  return *this;
}

Common::LogStream&
LogStream::operator<<(const std::filesystem::path& value)
{
  m_stream += WCHAR_TO_TCHAR(value.wstring().c_str());
  return *this;
}

Common::LogStream&
LogStream::operator<<(const std::wstring& value)
{
  m_stream += WCHAR_TO_TCHAR(value.c_str());
  return *this;
}

Common::LogStream&
LogStream::operator<<(const wchar_t& value)
{
  *this << std::wstring(1, value);
  return *this;
}

Common::LogStream&
LogStream::operator<<(const wchar_t* value)
{
  if (nullptr == value)
    return *this;

  *this << std::wstring(value);
  return *this;
}

Common::LogStream&
LogStream::operator<<(const std::u16string& value)
{
  m_stream += UTF16_TO_TCHAR(value.c_str());
  return *this;
}

Common::LogStream&
LogStream::operator<<(const char16_t& value)
{
  *this << std::u16string(1, value);
  return *this;
}

Common::LogStream&
LogStream::operator<<(const char16_t* value)
{
  if (nullptr == value)
    return *this;

  *this << std::u16string(value);
  return *this;
}

Common::LogStream&
LogStream::operator<<(const std::string& value)
{
  m_stream += UTF8_TO_TCHAR(value.c_str());
  return *this;
}

Common::LogStream&
LogStream::operator<<(const char& value)
{
  *this << std::string(1, value);
  return *this;
}

Common::LogStream&
LogStream::operator<<(const char* value)
{
  if (nullptr == value)
    return *this;

  *this << std::string(value);
  return *this;
}

Common::LogStream&
LogStream::operator<<(long value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(unsigned long value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(long long value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(unsigned long long value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(double value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(long double value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(short value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(int value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(unsigned short value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(unsigned int value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(float value)
{
  *this << std::to_wstring(value).c_str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(const void* value)
{
  std::wostringstream oss;
  oss << L"0x" << std::hex << value;
  *this << oss.str();
  return *this;
}

Common::LogStream&
LogStream::operator<<(std::nullptr_t)
{
  *this << TEXT("nullptr");
  return *this;
}

} // namespace Common
