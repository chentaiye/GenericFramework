//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <functional>
#include <string>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Log/LogLevel.h"
#include "Common/Log/LogStream.h"
#pragma endregion

namespace Common {
/** 聚合日志级别、调用点和消息缓冲，析构时写入日志适配器。 */
class Logger
{
public:
  /** 创建默认 Trace 级别日志记录器。 */
  Logger();

  /** 创建指定级别的日志记录器。 */
  Logger(LogLevel level);

  /** 创建带调用点信息的日志记录器。 */
  Logger(const char* fileName, int lineNum = 0, const char* function = "", LogLevel level = LogLevel::kLevelTrace);

  ~Logger();

  /** 设置低于该级别的日志不再输出。 */
  static void setMinLevel(LogLevel minLevel);

  /** 返回本次日志的消息流。 */
  LogStream& Stream() { return m_msgStream; }

private:
  /** 缓存本次日志消息内容。 */
  LogStream m_msgStream;

  /** 本次日志级别。 */
  LogLevel m_level;

  /** 调用点文件名。 */
  std::string m_fileName;

  /** 调用点函数名。 */
  std::string m_function;

  /** 调用点行号。 */
  int m_lineNumber = 0;

  /** 全局最小输出级别。 */
  static LogLevel m_minLevel;
};
} // namespace Common
