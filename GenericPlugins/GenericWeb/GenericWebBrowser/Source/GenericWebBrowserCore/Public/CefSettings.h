//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
// CoreUObject/Public/
#include <UObject/ObjectMacros.h>
// DeveloperSettings/Public/
#include <Engine/DeveloperSettings.h>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewTypes.h>
#pragma endregion

#pragma region "Generated Header"
#include "CefSettings.generated.h"
#pragma endregion

/** 映射 CEF 原生日志级别，用于控制浏览器运行时输出。 */
UENUM(BlueprintType)
enum class ECefLogLevel : uint8
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

/** 保存当前模块Cef设置能力配置，供模块初始化和运行时读取。 */
UCLASS(BlueprintType, Config = "Engine", DefaultConfig)
class UCEFVIEW_API UCefSettings : public UDeveloperSettings
{
  GENERATED_BODY()

#pragma region Properties
public:
  /** 注入页面脚本环境的桥接对象名称。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Interoplation")
  FName BridgeObjectName=TEXT("UCefViewBridge");

  /** 内置资源 Scheme 名称，用于本地目录和归档文件映射。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Interoplation")
  FName BuiltinSchemeName=TEXT("UCefView");

  /** 覆盖 CEF 默认 User-Agent，留空时使用运行时默认值。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Interoplation")
  FString UserAgent;

  /** 全局归档资源映射，在 CEF 上下文初始化时注册。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Resource Mapping")
  TArray<FArchiveFileResourceMapping> ArchiveFileResourceMapping;

  /** 全局本地目录资源映射，在 CEF 上下文初始化时注册。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Resource Mapping")
  TArray<FLocalFolderResourceMapping> LocalFolderResourceMapping;

  /** 浏览器视图默认背景色，单个视图可继续覆盖。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Appearance")
  FColor BackgroundColor=FColor::White;

  /** 传给 CEF 的界面和内容区域语言设置。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Appearance")
  FString Locale;

  /** CEF 请求头和语言协商使用的 Accept-Language 列表。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Appearance")
  TArray<FString> AcceptLanguageList;

  /** 允许会话 Cookie 随 CEF 用户数据目录持久化。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Storage")
  bool PersistSessionCookies=true;

  /** 允许浏览器用户偏好写入持久化存储。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Storage")
  bool PersistUserPreferences=true;

  /** 控制 CEF 运行时日志详细程度。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Diagnostic")
  ECefLogLevel LogLevel=ECefLogLevel::Default;

  /** CEF 远程调试端口，设为 0 时禁用远程调试。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Diagnostic", //
    meta=(ClampMin="0", ClampMax="65535", UIMin="0", UIMax="65535"))
  int32 RemoteDebuggingPort=0;

  /** 阻止宿主进程命令行参数继续传递给 CEF。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Misc")
  bool DisableCommandLineArgsPassthrough=false;

  /** 禁用 CEF 沙箱，适配当前插件随包分发的二进制布局。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Misc")
  bool DisableSandbox=true;

  /** 附加传给 CEF 的命令行开关表。 */
  UPROPERTY(//
    Config, //
    EditAnywhere, //
    Category="Misc")
  TMap<FString, FString> CommandLineArgs = //
    {
      { TEXT("remote-allow-origins"), TEXT("*") },
    };
#pragma endregion

#if WITH_EDITOR
  void PostEditChangeProperty(struct FPropertyChangedEvent& InPropertyChangedEvent) override;
#endif
};
