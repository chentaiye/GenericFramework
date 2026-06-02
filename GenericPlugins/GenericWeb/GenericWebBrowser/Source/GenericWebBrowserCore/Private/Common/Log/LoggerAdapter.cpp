//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "LoggerAdapter.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Misc/DateTime.h>
#include <Logging/LogMacros.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <iostream>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#pragma endregion

DEFINE_LOG_CATEGORY_STATIC(LogUCefView, Log, All);

namespace Common {
void
LoggerAdapter::init(LogLevel minLevel)
{
  /** 初始化完成后写入首条日志，用于确认内部日志链路已经接到 UE 日志系统。 */
  UE_LOG(LogUCefView, Display, TEXT("********************* UCefView Module Logger Started *********************"));
}

void
LoggerAdapter::log(const FString& msg, LogLevel level)
{
  auto now = FDateTime::Now();
  FString dt = now.ToString(TEXT("%Y-%m-%d %H:%M:%S"));
  int32 ms = now.GetMillisecond();
  switch (level) {
    case LogLevel::kLevelTrace:
      UE_LOG(LogUCefView, VeryVerbose, TEXT("%s.%03d|%s"), *(dt), ms, *msg);
      break;
    case LogLevel::kLevelDebug:
      UE_LOG(LogUCefView, Verbose, TEXT("%s.%03d|%s"), *(dt), ms, *msg);
      break;
    case LogLevel::kLevelInfo:
      UE_LOG(LogUCefView, Display, TEXT("%s.%03d|%s"), *(dt), ms, *msg);
      break;
    case LogLevel::kLevelWarn:
      UE_LOG(LogUCefView, Warning, TEXT("%s.%03d|%s"), *(dt), ms, *msg);
      break;
    case LogLevel::kLevelError:
      UE_LOG(LogUCefView, Error, TEXT("%s.%03d|%s"), *(dt), ms, *msg);
      break;
    case LogLevel::kLevelFatal:
      UE_LOG(LogUCefView, Fatal, TEXT("%s.%03d|%s"), *(dt), ms, *msg);
      break;
  }
}

void
LoggerAdapter::uninit()
{
  UE_LOG(LogUCefView, Display, TEXT("********************* UCefView Module Logger Exited *********************"));
}
} // namespace Common
