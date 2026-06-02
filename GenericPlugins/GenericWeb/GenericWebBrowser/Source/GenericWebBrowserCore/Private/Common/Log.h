//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <filesystem>
#include <functional>
#include <sstream>
#include <string>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewTypes.h>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Log/LogLevel.h"
#include "Common/Log/LogStream.h"
#include "Common/Log/Logger.h"
#pragma endregion

namespace Common {
/** 设置全局日志最小级别并准备日志输出适配器。 */
void
InitializeLogger(LogLevel minLevel = LogLevel::kLevelTrace);

/** 释放全局日志输出适配器。 */
void
ExitLogger();

/** 用 RAII 管理日志系统初始化和退出。 */
struct LogInitializer
{
  LogInitializer(LogLevel minLevel = LogLevel::kLevelTrace)
  {
    //
    Common::InitializeLogger(minLevel);
  }

  ~LogInitializer()
  {
    //
    Common::ExitLogger();
  }
};
} // namespace Common

namespace Common {
/** 在函数进入和退出时自动写入成对日志，便于跟踪 CEF 回调流程。 */
class FunctionLogger
{
public:
  FunctionLogger(const char* fn, int ln, const char* func)
    : ln_(ln)
    , fn_(fn)
    , func_(func)
  {
    Logger(fn_.c_str(), ln_, func_.c_str(), LogLevel::kLevelInfo).Stream() << "+++";
  }

  ~FunctionLogger()
  {
    //
    Logger(fn_.c_str(), ln_, func_.c_str(), LogLevel::kLevelInfo).Stream() << "---";
  }

  /** 调用点所在行号。 */
  int ln_;

  /** 调用点所在文件名。 */
  std::string fn_;

  /** 调用点所在函数名。 */
  std::string func_;
};
} // namespace Common

#define logXxxLevel(level) Common::Logger(__FILE__, __LINE__, __FUNCTION__, level).Stream()

#if !UE_BUILD_SHIPPING
#define FLog() Common::FunctionLogger __fl__(__FILE__, __LINE__, __FUNCTION__);
#define logTrace() logXxxLevel(Common::LogLevel::kLevelInfo)
#define logDebug() logXxxLevel(Common::LogLevel::kLevelInfo)
#define logInfo() logXxxLevel(Common::LogLevel::kLevelInfo)
#define logWarn() logXxxLevel(Common::LogLevel::kLevelWarn)
#define logError() logXxxLevel(Common::LogLevel::kLevelError)
#define logFatal() logXxxLevel(Common::LogLevel::kLevelFatal)
#else
#define FLog()
#define logTrace() Common::NopStream()
#define logDebug() Common::NopStream()
#define logInfo() logXxxLevel(Common::LogLevel::kLevelInfo)
#define logWarn() logXxxLevel(Common::LogLevel::kLevelWarn)
#define logError() logXxxLevel(Common::LogLevel::kLevelError)
#define logFatal() logXxxLevel(Common::LogLevel::kLevelFatal)
#endif
