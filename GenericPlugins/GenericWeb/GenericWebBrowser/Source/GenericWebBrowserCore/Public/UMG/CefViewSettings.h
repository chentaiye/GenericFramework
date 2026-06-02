//
//  Copyright ? 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
#include <Math/Color.h>
// CoreUObject/Public/
#include <UObject/ObjectMacros.h>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewTypes.h>
#pragma endregion

#pragma region "Generated Header"
#include "CefViewSettings.generated.h"
#pragma endregion

/** 暴露单个 CEF 视图的字体、语言和 Web 能力开关。 */
USTRUCT(BlueprintType)
struct UCEFVIEW_API FCefViewSettings
{
  GENERATED_BODY()

  /** 当前视图默认绘制背景色。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FColor BackgroundColor=FColor::White;

  /** 页面未指定字体时使用的标准字体族。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString StandardFontFamily;

  /** 等宽文本使用的字体族。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString FixedFontFamily;

  /** 衬线字体回退族。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString SerifFontFamily;

  /** 无衬线字体回退族。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString SansSerifFontFamily;

  /** 手写体字体回退族。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString CursiveFontFamily;

  /** 装饰性字体回退族。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString FantasyFontFamily;

  /** 普通文本默认字号。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default", //
    meta=(ClampMin="0", UIMin="0"))
  int32 DefaultFontSize=0;

  /** 等宽文本默认字号。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default", //
    meta=(ClampMin="0", UIMin="0"))
  int32 DefaultFixedFontSize=0;

  /** 页面文本允许渲染的最小字号。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default", //
    meta=(ClampMin="0", UIMin="0"))
  int32 MinimumFontSize=0;

  /** CEF 布局计算使用的最小逻辑字号。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default", //
    meta=(ClampMin="0", UIMin="0"))
  int32 MinimumLogicalFontSize=0;

  /** 页面未声明编码时采用的默认字符编码。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString DefaultEncoding;

  /** 当前视图请求使用的 Accept-Language 字符串。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  FString AcceptLanguageList;

  /** 控制页面是否允许加载远程字体。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState RemoteFonts=ECefViewFeatureState::Default;

  /** 控制当前视图是否允许运行 JavaScript。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState Javascript=ECefViewFeatureState::Default;

  /** 控制脚本是否可以关闭由脚本打开的窗口。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState AllowJavascriptCloseWindows=ECefViewFeatureState::Default;

  /** 控制脚本是否可以访问剪贴板内容。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState AllowJavascriptAccessClipboard=ECefViewFeatureState::Default;

  /** 控制脚本是否可以通过 DOM paste 能力写入页面。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState AllowJavascriptDomPaste=ECefViewFeatureState::Default;

  /** 控制当前视图是否启用 CEF 插件能力。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState Plugins=ECefViewFeatureState::Default;

  /** 控制页面图片资源是否自动加载。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState ImageLoading=ECefViewFeatureState::Default;

  /** 控制独立图片页面是否自动缩放适配视图。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState ImageShrinkStandaloneToFit=ECefViewFeatureState::Default;

  /** 控制页面中的文本区域是否允许用户拖拽调整大小。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState TextAreaResize=ECefViewFeatureState::Default;

  /** 控制 Tab 键是否在页面链接间移动焦点。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState TabToLinks=ECefViewFeatureState::Default;

  /** 控制页面是否可以使用 Local Storage。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState LocalStorage=ECefViewFeatureState::Default;

  /** 控制页面是否可以使用浏览器数据库存储能力。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState Databases=ECefViewFeatureState::Default;

  /** 控制当前视图是否允许使用 WebGL。 */
  UPROPERTY(//
    EditAnywhere, //
    BlueprintReadWrite, //
    Category="Default")
  ECefViewFeatureState WebGL=ECefViewFeatureState::Default;
};
