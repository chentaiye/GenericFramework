//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
#include <HAL/Platform.h>
// CoreUObject/Public/
#include <UObject/ObjectMacros.h>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewTypes.h>
#pragma endregion

/** Slate 层使用的 CEF 日志级别，最终转换为 CEF 原生日志配置。 */
enum class ESlateCefLogLevel : uint8
{
  /** 使用 CEF 默认日志级别。 */
  Default,

  /** 输出最详细的诊断日志。 */
  Verbose,

  /** 输出调试级别日志。 */
  Debug,

  /** 输出普通运行信息。 */
  Info,

  /** 仅输出警告及更严重日志。 */
  Warning,

  /** 仅输出错误及更严重日志。 */
  Error,

  /** 仅输出致命错误日志。 */
  Fatal,

  /** 禁用 CEF 日志输出。 */
  Disable = 99
};

/** 进程级 Slate CEF 初始化配置，由 UEngineSubsystem 转换后传入。 */
struct UCEFVIEW_API FSlateCefSettings
{
  /** 注入页面脚本环境的桥接对象名称。 */
  FName BridgeObjectName = TEXT("UCefViewBridge");

  /** 内置资源 Scheme 名称，用于本地目录和归档文件映射。 */
  FName BuiltinSchemeName = TEXT("UCefView");

  /** 覆盖 CEF 默认 User-Agent，留空时使用运行时默认值。 */
  FString UserAgent;

  /** 初始化时注册的全局归档资源映射。 */
  TArray<FArchiveFileResourceMapping> ArchiveFileResourceMapping;

  /** 初始化时注册的全局本地目录资源映射。 */
  TArray<FLocalFolderResourceMapping> LocalFolderResourceMapping;

  /** 浏览器视图默认背景色。 */
  FColor BackgroundColor = FColor::White;

  /** 传给 CEF 的界面和内容区域语言设置。 */
  FString Locale;

  /** CEF 请求头和语言协商使用的 Accept-Language 列表。 */
  TArray<FString> AcceptLanguageList;

  /** 允许会话 Cookie 随 CEF 用户数据目录持久化。 */
  bool PersistSessionCookies = true;

  /** 允许浏览器用户偏好写入持久化存储。 */
  bool PersistUserPreferences = true;

  /** 控制 CEF 运行时日志详细程度。 */
  ESlateCefLogLevel LogLevel = ESlateCefLogLevel::Default;

  /** CEF 远程调试端口，设为 0 时禁用远程调试。 */
  int32 RemoteDebuggingPort = 0;

  /** 阻止宿主进程命令行参数继续传递给 CEF。 */
  bool DisableCommandLineArgsPassthrough = false;

  /** 禁用 CEF 沙箱，适配当前插件随包分发的二进制布局。 */
  bool DisableSandbox = true;

  /** 附加传给 CEF 的命令行开关表。 */
  TMap<FString, FString> CommandLineArgs = //
    {
      { TEXT("remote-allow-origins"), TEXT("*") },
    };
};
