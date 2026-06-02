//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "Logger.h"
#pragma endregion

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#include <Windows/AllowWindowsPlatformTypes.h>
#include <Windows.h>
#include <Windows/HideWindowsPlatformTypes.h>
#endif
#pragma endregion

#pragma region <STL Headers>
#include <thread>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#include "LogLevel.h"
#include "LoggerAdapter.h"
#pragma endregion

#define NEWLINE "\r\n"

namespace Common {
void
InitializeLogger(LogLevel minLevel)
{
  LoggerAdapter::getInstance().init(minLevel);
  Logger::setMinLevel(minLevel);
}

void
ExitLogger()
{
  LoggerAdapter::getInstance().uninit();
}

LogLevel Logger::m_minLevel;

Logger::Logger()
  : m_level(LogLevel::kLevelTrace)
{
}

Logger::Logger(LogLevel level)
  : m_level(level)
{
}

Logger::Logger(const char* fileName, int lineNum, const char* function, LogLevel level)
  : Logger(level)
{
  m_fileName = fileName;
  m_lineNumber = lineNum;
  m_function = function;
}

Logger::~Logger()
{
  if (m_level < m_minLevel) {
    /** 低于当前全局级别的消息直接丢弃，减少 CEF 高频回调中的日志开销。 */
    return;
  }

  /** 组装调用点、函数名和消息正文，交给底层适配器统一输出。 */
  LogStream ls;
  if (!m_fileName.empty()) {
    /** 日志输出只保留文件名，避免完整路径在编辑器日志中占据过多空间。 */
    std::filesystem::path path = m_fileName;
    auto name = path.filename();
    ls << "(" << name << ":" << m_lineNumber << ")";
  }
  if (!m_function.empty()) {
    ls << "[" << m_function << "]";
  }
  ls << m_msgStream.toString();

  auto logMsg = ls.toString();

  /** 最终交给日志适配器写入 UE 日志分类。 */
  LoggerAdapter::getInstance().log(logMsg, m_level);
}

void
Logger::setMinLevel(LogLevel minLevel)
{
  m_minLevel = minLevel;
}
} // namespace Common
