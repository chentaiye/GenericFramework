//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

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
#pragma endregion

namespace Common {
/** 内部日志级别，按严重程度递增排列。 */
enum class LogLevel : int
{
  /** 详细跟踪日志。 */
  kLevelTrace = 0,

  /** 调试日志。 */
  kLevelDebug,

  /** 普通信息日志。 */
  kLevelInfo,

  /** 警告日志。 */
  kLevelWarn,

  /** 错误日志。 */
  kLevelError,

  /** 致命错误日志。 */
  kLevelFatal,

  /** 日志级别数量哨兵值。 */
  kNumLogLevels
};
} // namespace Common
