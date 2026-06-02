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

/** Slate 层使用的 CEF 视图配置，与 UMG 配置结构保持字段语义一致。 */
struct UCEFVIEW_API FSlateCefViewSettings
{
  /** 普通文本默认字号。 */
  int32 DefaultFontSize;

  /** 等宽文本默认字号。 */
  int32 DefaultFixedFontSize;

  /** 页面文本允许渲染的最小字号。 */
  int32 MinimumFontSize;

  /** CEF 布局计算使用的最小逻辑字号。 */
  int32 MinimumLogicalFontSize;

  /** 当前视图默认绘制背景色。 */
  FColor BackgroundColor = FColor::White;

  /** 页面未指定字体时使用的标准字体族。 */
  FString StandardFontFamily;

  /** 等宽文本使用的字体族。 */
  FString FixedFontFamily;

  /** 衬线字体回退族。 */
  FString SerifFontFamily;

  /** 无衬线字体回退族。 */
  FString SansSerifFontFamily;

  /** 手写体字体回退族。 */
  FString CursiveFontFamily;

  /** 装饰性字体回退族。 */
  FString FantasyFontFamily;

  /** 页面未声明编码时采用的默认字符编码。 */
  FString DefaultEncoding;

  /** 当前视图请求使用的 Accept-Language 字符串。 */
  FString AcceptLanguageList;

  /** 控制页面是否允许加载远程字体。 */
  ECefViewFeatureState RemoteFonts = ECefViewFeatureState::Default;

  /** 控制当前视图是否允许运行 JavaScript。 */
  ECefViewFeatureState Javascript = ECefViewFeatureState::Default;

  /** 控制脚本是否可以关闭由脚本打开的窗口。 */
  ECefViewFeatureState AllowJavascriptCloseWindows = ECefViewFeatureState::Default;

  /** 控制脚本是否可以访问剪贴板内容。 */
  ECefViewFeatureState AllowJavascriptAccessClipboard = ECefViewFeatureState::Default;

  /** 控制脚本是否可以通过 DOM paste 能力写入页面。 */
  ECefViewFeatureState AllowJavascriptDomPaste = ECefViewFeatureState::Default;

  /** 控制当前视图是否启用 CEF 插件能力。 */
  ECefViewFeatureState Plugins = ECefViewFeatureState::Default;

  /** 控制页面图片资源是否自动加载。 */
  ECefViewFeatureState ImageLoading = ECefViewFeatureState::Default;

  /** 控制独立图片页面是否自动缩放适配视图。 */
  ECefViewFeatureState ImageShrinkStandaloneToFit = ECefViewFeatureState::Default;

  /** 控制页面中的文本区域是否允许用户拖拽调整大小。 */
  ECefViewFeatureState TextAreaResize = ECefViewFeatureState::Default;

  /** 控制 Tab 键是否在页面链接间移动焦点。 */
  ECefViewFeatureState TabToLinks = ECefViewFeatureState::Default;

  /** 控制页面是否可以使用 Local Storage。 */
  ECefViewFeatureState LocalStorage = ECefViewFeatureState::Default;

  /** 控制页面是否可以使用浏览器数据库存储能力。 */
  ECefViewFeatureState Databases = ECefViewFeatureState::Default;

  /** 控制当前视图是否允许使用 WebGL。 */
  ECefViewFeatureState WebGL = ECefViewFeatureState::Default;
};
