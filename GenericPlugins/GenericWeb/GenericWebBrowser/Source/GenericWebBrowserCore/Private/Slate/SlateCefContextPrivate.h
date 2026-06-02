//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#if defined(PLATFORM_MAC) && PLATFORM_MAC
#include <CoreFoundation/CFRunLoop.h>
#endif
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#include "HeadersCefViewCore.h"
#pragma endregion

#pragma region <Project Public Headers>
#include <Slate/SlateCefContext.h>
#pragma endregion

#pragma region "Project Private headers"
#include "Details/CCefAppDelegate.h"
#pragma endregion

/** 作为当前模块SlateCefCon文本能力控件，负责把运行时状态呈现到Slate或UMG层。 */
class FSlateCefContext::FSlateCefContextPrivate
{
public:
  /** 初始化空的 CEF 上下文私有状态。 */
  FSlateCefContextPrivate();

  ~FSlateCefContextPrivate();

  /** CEF View Core 的 App 对象。 */
  CefRefPtr<CefViewBrowserApp> pApp_;

  /** 记录pApp委托。 */
  CCefAppDelegate::RefPtr pAppDelegate_;

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
  /** 绑定 CEF 子进程生命周期的 Windows Job 句柄。 */
  HANDLE windowsJobHandle_ = nullptr;

  /** Windows Job 名称，用于诊断和创建句柄。 */
  FString windowsJobName_;
#endif

#if defined(PLATFORM_MAC) && PLATFORM_MAC
  /** 外部消息循环模式下驱动 CEF 工作的 RunLoop Timer。 */
  CFRunLoopTimerRef cefWorkerTimer_ = nullptr;
#endif

  /** 根据项目配置初始化 CEF 运行时。 */
  bool InitializeCef(const FSlateCefSettings& InSlateCefSettings);

  /** 停止 CEF 运行时并释放平台资源。 */
  void ShutdownCef();

/** 构建Cef设置，供CEF浏览器创建和运行时配置复用。 */
  void BuildCefSettings(CefSettings& InCefSettings, const FSlateCefSettings& InSlateCefSettings);

  /** 把本地目录和归档文件映射注册到 CEF App。 */
  void AddResourceMapping(CefViewBrowserApp* InApp, const FSlateCefSettings& InSlateCefSettings);
};
