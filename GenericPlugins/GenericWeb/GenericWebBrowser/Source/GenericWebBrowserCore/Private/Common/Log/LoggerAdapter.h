//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
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
/** 把内部日志消息转接到 Unreal 日志系统。 */
class LoggerAdapter
{
public:
  /** 返回进程内唯一日志适配器实例。 */
  static LoggerAdapter& getInstance()
  {
    static LoggerAdapter s_instance;
    return s_instance;
  }

  /** 初始化日志适配器并设置最小输出级别。 */
  void init(LogLevel minLevel);

  /** 将一条内部日志写入 Unreal 日志分类。 */
  void log(const FString& msg, LogLevel level);

  /** 关闭日志适配器。 */
  void uninit();
};
} // namespace Common
