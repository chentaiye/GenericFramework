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
#include <CefVersion.h>
#pragma endregion

#pragma region "Generated Header"
#include "CefViewTypes.generated.h"
#pragma endregion

/** 封装 CEF 帧标识，屏蔽不同 CEF 版本中 FrameId 类型差异。 */
USTRUCT(BlueprintType)
struct UCEFVIEW_API FCefFrameId
{
  GENERATED_BODY()

  /** 创建空帧标识，用于未绑定具体 CEF Frame 的默认状态。 */
  FCefFrameId() {}

#if CEF_VERSION_MAJOR < 122
  /** 从旧版 CEF 的整型 FrameId 构造帧标识。 */
  FCefFrameId(int64 Id)
    : Value(Id)
  {
  }

  /** 旧版 CEF 使用的整型帧标识。 */
  int64 Value = 0;
#else
  /** 从新版 CEF 的字符串 FrameId 构造帧标识。 */
  FCefFrameId(const TCHAR* Id)
    : Value(Id)
  {
  }

  /** 新版 CEF 使用的字符串帧标识。 */
  FString Value = TEXT("");
#endif
};

/** 表示浏览器设置项是否沿用默认值、强制启用或强制禁用。 */
UENUM(BlueprintType)
enum class ECefViewFeatureState : uint8
{
  /** 沿用 CEF 或全局配置的默认行为。 */
  Default=0,

  /** 显式启用该浏览器能力。 */
  Enabled=1,

  /** 显式禁用该浏览器能力。 */
  Disabled=2,
};

/** 映射 CEF 窗口打开意图，供弹窗创建事件判断新页面应如何承载。 */
UENUM(BlueprintType)
enum class ECefWindowOpenDisposition : uint8
{
  /** CEF 未提供明确打开方式。 */
  Unknown,

  /** 在当前页面上下文中导航。 */
  CurrentTab,

  /** 复用已有的唯一标签页。 */
  SingletonTab,

  /** 请求创建前台标签页。 */
  NewForeGroundTab,

  /** 请求创建后台标签页。 */
  NewBackgroundTab,

  /** 请求创建弹窗浏览器。 */
  NewPopup,

  /** 请求创建独立窗口。 */
  NewWindow,

  /** 表示Cef窗口OpenDisposition的存档目标Disk分支。 */
  SaveToDisk,

  /** 请求使用无痕上下文打开。 */
  OffTheRecord,

  /** 请求宿主忽略本次打开动作。 */
  IgnoreAction,
};

/** 描述本地目录到内置 Scheme URL 的映射，用于让页面访问项目资源。 */
USTRUCT(BlueprintType)
struct UCEFVIEW_API FLocalFolderResourceMapping
{
  GENERATED_BODY()

  /** 映射后暴露给页面访问的 URL 前缀。 */
  UPROPERTY(EditAnywhere, //
            BlueprintReadWrite, //
            Category="Default")
  FString Url;

  /** 相对 Content 目录的本地资源目录。 */
  UPROPERTY(EditAnywhere, //
            BlueprintReadWrite, //
            Category="Default", //
            meta=(RelativeToGameContentDir))
  FDirectoryPath Path;

  /** 多个映射命中同一 URL 时的匹配优先级。 */
  UPROPERTY(EditAnywhere, //
            BlueprintReadWrite, //
            Category="Default")
  int32 Priority=0;

  bool operator==(const FLocalFolderResourceMapping& Other) { return Url == Other.Url && Path.Path == Other.Path.Path && Priority == Other.Priority; }
  bool operator!=(const FLocalFolderResourceMapping& Other) { return !(*this == Other); }
};

/** 描述压缩包资源到内置 Scheme URL 的映射，用于从归档中提供页面资源。 */
USTRUCT(BlueprintType)
struct UCEFVIEW_API FArchiveFileResourceMapping
{
  GENERATED_BODY()

  /** 映射后暴露给页面访问的 URL 前缀。 */
  UPROPERTY(EditAnywhere,        //
            BlueprintReadWrite,  //
            Category="Default" //
  )
  FString Url;

  /** 相对项目目录的归档文件路径。 */
  UPROPERTY(EditAnywhere, //
            BlueprintReadWrite, //
            Category="Default", //
            meta=(RelativeToGameDir))
  FFilePath Path;

  /** 读取加密归档时使用的密码。 */
  UPROPERTY(EditAnywhere, //
            BlueprintReadWrite, //
            Category="Default")
  FString Password;

  /** 多个映射命中同一 URL 时的匹配优先级。 */
  UPROPERTY(EditAnywhere, //
            BlueprintReadWrite, //
            Category="Default")
  int32 Priority=0;

  bool operator==(const FArchiveFileResourceMapping& Other) { return Url == Other.Url && Path.FilePath == Other.Path.FilePath && Password == Other.Password && Priority == Other.Priority; }
  bool operator!=(const FArchiveFileResourceMapping& Other) { return !(*this == Other); }
};
