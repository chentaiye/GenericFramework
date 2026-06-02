//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/Map.h>
#include <Containers/UnrealString.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <string>
#include <unordered_map>
#include <functional>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#include "HeadersCefViewCore.h"
#pragma endregion

/** CEF 请求宿主安排消息循环工作时使用的调度回调。 */
using CefMessageLoopSchedulerCallback = std::function<void(int64_t)>;

/** 接入 CEF App 级回调，负责命令行参数和外部消息循环调度。 */
class CCefAppDelegate : public CefViewBrowserAppDelegateInterface
{
public:
  /** 缓存命令行开关和消息循环调度回调。 */
  CCefAppDelegate(const TMap<FString, FString>& args,
                  const CefMessageLoopSchedulerCallback& cb = CefMessageLoopSchedulerCallback());

  ~CCefAppDelegate();

protected:
  virtual void onBeforeCommandLineProcessing(const CefString& process_type,
                                             CefRefPtr<CefCommandLine> command_line) override;
  virtual void onBeforeChildProcessLaunch(CefRefPtr<CefCommandLine> command_line) override;
  void onScheduleMessageLoopWork(int64_t delay_ms) override;

private:
  /** 初始化 CEF 子进程时追加的命令行参数。 */
  TMap<FString, FString> commandLineArgs_;

  /** 把 CEF 外部消息循环调度请求转交给宿主线程。 */
  CefMessageLoopSchedulerCallback cefMessageLoopSchedulerCallback_;
};
