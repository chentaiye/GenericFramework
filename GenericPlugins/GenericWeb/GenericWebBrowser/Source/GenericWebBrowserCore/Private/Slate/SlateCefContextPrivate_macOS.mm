//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#if defined(PLATFORM_MAC) && PLATFORM_MAC

#pragma region "Self Header"
#include "SlateCefContextPrivate.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Misc/MessageDialog.h>
#include <Misc/Paths.h>
#include <Modules/ModuleManager.h>
#include <HAL/PlatformFileManager.h>
#include <GenericPlatform/GenericPlatformFile.h>
// CoreUObject/Public/
#include <UObject/StrongObjectPtr.h>
#pragma endregion

#pragma region <Platform Headers>
#import <Cocoa/Cocoa.h>
#import <objc/runtime.h>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#include "HeadersCefViewCore.h"
#include <include/cef_application_mac.h>
#include <include/cef_sandbox_mac.h>
#include <include/wrapper/cef_library_loader.h>
#pragma endregion

#pragma region <Project Public Headers>
#include "CefViewModule.h"
#pragma endregion

#pragma region "Project Private headers"
#include "Common/Convert.h"
#include "Common/Log.h"
#include "Details/CCefAppDelegate.h"
#pragma endregion

using namespace Common;

#define CEF_BINARY_NAME "Chromium Embedded Framework"
#define CEF_FRAMEWORK_NAME "Chromium Embedded Framework.framework"
#define HELPER_BINARY_NAME kCefViewRenderProcessName
#define HELPER_BUNDLE_NAME HELPER_BINARY_NAME ".app"

const CFTimeInterval kCefWorkerIntervalSec = (1.0 / 60); // 60 FPS 消息泵节奏。

bool g_handling_send_event = false;

@interface
NSApplication (CocoaCefApp)<CefAppProtocol>
- (void)_swizzled_sendEvent:(NSEvent*)event;
- (void)_swizzled_terminate:(id)sender;
@end

@implementation
NSApplication (CocoaCefApp)
/** 拦截 NSApplication 事件分发和退出路径，满足 CEF macOS 集成对主循环的要求。 */
+ (void)load
{
  /** sendEvent 需要包在 CefScopedSendingEvent 中，让 CEF 正确处理嵌套事件。 */
  Method original_sendEvent = class_getInstanceMethod(self, @selector(sendEvent:));
  Method swizzled_sendEvent = class_getInstanceMethod(self, @selector(_swizzled_sendEvent:));
  method_exchangeImplementations(original_sendEvent, swizzled_sendEvent);

  /** 退出事件也走 swizzle 路径，避免 CEF 与 Cocoa 生命周期顺序不一致。 */
  Method original_terminate = class_getInstanceMethod(self, @selector(terminate:));
  Method swizzled_terminate = class_getInstanceMethod(self, @selector(_swizzled_terminate:));
  method_exchangeImplementations(original_terminate, swizzled_terminate);
}

- (BOOL)isHandlingSendEvent
{
  return g_handling_send_event;
}

- (void)setHandlingSendEvent:(BOOL)handlingSendEvent
{
  g_handling_send_event = handlingSendEvent;
}

- (void)_swizzled_sendEvent:(NSEvent*)event
{
  CefScopedSendingEvent sendingEventScoper;

  [self _swizzled_sendEvent:event];
}

- (void)_swizzled_terminate:(id)sender
{

  [self _swizzled_terminate:sender];
}
@end

void
OnCefWorkerTimer(CFRunLoopTimerRef Timer, void* Context)
{
  CefDoMessageLoopWork();
}

bool
FSlateCefContext::FSlateCefContextPrivate::InitializeCef(const FSlateCefSettings& InSlateCefSettings)
{
  /** CEF 的 macOS 初始化必须在主线程执行，非主线程调用时同步切回主队列。 */
  if (![NSThread isMainThread]) {
    __block bool result = false;
    dispatch_sync(dispatch_get_main_queue(), ^() {
      result = InitializeCef(InSlateCefSettings);
    });
    return result;
  }

  /** 插件模块提供 CEF framework 和 helper bundle 的根目录。 */
  FCefViewModule* CurrentModule = FModuleManager::GetModulePtr<FCefViewModule>(TEXT("GenericWebBrowserCore"));
  if (!CurrentModule) {
    logError() << "Failed to get current module";
    return false;
  }
  /** CEF framework 随插件二进制目录分发。 */
  FString CefFrameworkPath = CurrentModule->GetCefViewCoreDir();
  CefFrameworkPath /= TEXT(CEF_FRAMEWORK_NAME);
  CefFrameworkPath = FPaths::ConvertRelativePathToFull(CefFrameworkPath);

  /** 原生 CEF 动态库位于 framework 内部，需要先验证文件存在。 */
  FString CefLibraryPath = CefFrameworkPath;
  CefLibraryPath /= TEXT(CEF_BINARY_NAME);
  CefLibraryPath = FPaths::ConvertRelativePathToFull(CefLibraryPath);
  if (!FPaths::FileExists(CefLibraryPath)) {
    logError() << "CEF library file not found at:" << *CefLibraryPath;
    return false;
  }

  /** macOS 子进程以 app bundle 形式分发，CEF 需要指向 bundle 内的实际可执行文件。 */
  FString CefViewWingPath = CurrentModule->GetCefViewCoreDir();
  CefViewWingPath /= TEXT(HELPER_BUNDLE_NAME);
  CefViewWingPath /= TEXT("Contents");
  CefViewWingPath /= TEXT("MacOS");
  CefViewWingPath /= TEXT(HELPER_BINARY_NAME);
  CefViewWingPath = FPaths::ConvertRelativePathToFull(CefViewWingPath);
  if (!FPaths::FileExists(CefViewWingPath)) {
    logError() << "CefView subprocess not found at:" << *CefViewWingPath;
    return false;
  }

  /** 初始化前手动加载 CEF 动态库，关闭时再对称卸载。 */
  std::string CefLibraryPathUTF8 = TCHAR_TO_UTF8(*CefLibraryPath);
  if (1 != cef_load_library(CefLibraryPathUTF8.c_str())) {
    logError() << "Failed to load CEF library at:" << *CefLibraryPath;
    return false;
  }

  /** 先填充跨平台 CEF 配置，再叠加 macOS 专用启动参数。 */
  CefSettings CefSettings;
  BuildCefSettings(CefSettings, InSlateCefSettings);

  /** 保持与当前 CEF 版本要求一致的固定启动项。 */
#if CEF_VERSION_MAJOR >= 125 && CEF_VERSION_MAJOR <= 127
  //  https://github.com/chromiumembedded/cef/issues/3685
  CefSettings.chrome_runtime = true;
#endif
#if CEF_VERSION_MAJOR < 128
  CefSettings.pack_loading_disabled = false;
#endif

  CefSettings.multi_threaded_message_loop = false;
  CefSettings.external_message_pump = true;

  /** 设置 framework 与子进程路径，供 CEF 在启动渲染进程时解析。 */
  CefString(&CefSettings.framework_dir_path) = Convert::StringF2C(CefFrameworkPath);
  CefString(&CefSettings.browser_subprocess_path) = Convert::StringF2C(CefViewWingPath);

  /** 主应用 bundle 路径用于 CEF 在 macOS 上定位资源和应用上下文。 */
  std::string MainBundlePath = [[NSBundle mainBundle] bundlePath].UTF8String;
  CefString(&CefSettings.main_bundle_path) = MainBundlePath;

  /** 外部消息泵模式下，CEF 通过回调安排下一次主线程消息处理。 */
  auto CefMessageLoopCallback = [](int64 InDelayMS) {
    CFRunLoopTimerRef SingleShotTimer = CFRunLoopTimerCreateWithHandler(
      kCFAllocatorDefault, CFAbsoluteTimeGetCurrent() + InDelayMS * 1.0f / 1000, 0, 0, 0, ^(CFRunLoopTimerRef timer) {
        OnCefWorkerTimer(timer, nullptr);
        CFRunLoopRemoveTimer(CFRunLoopGetMain(), timer, kCFRunLoopDefaultMode);
        CFRelease(timer);
      });
    CFRunLoopAddTimer(CFRunLoopGetMain(), SingleShotTimer, kCFRunLoopDefaultMode);
  };

  /** 创建 CEF App 并启动进程级 CEF 上下文。 */
  auto AppDelegate = std::make_shared<CCefAppDelegate>(InSlateCefSettings.CommandLineArgs, CefMessageLoopCallback);
  auto BuiltinSchemeName = Convert::StringF2C(InSlateCefSettings.BuiltinSchemeName.ToString());
  auto BridgeObjectName = Convert::StringF2C(InSlateCefSettings.BridgeObjectName.ToString());
  auto App = new CefViewBrowserApp(BuiltinSchemeName, BridgeObjectName, AppDelegate);

  CefMainArgs MainArgs;
  if (!CefInitialize(MainArgs, CefSettings, App, nullptr)) {
    assert(0);
    return false;
  }

  /** CEF 初始化成功后注册内置 scheme 的本地资源映射。 */
  AddResourceMapping(App, InSlateCefSettings);

  pApp_ = App;
  pAppDelegate_ = AppDelegate;

  /** 定时消息泵兜底推进 CEF 任务，保持页面在 UE 主循环中持续响应。 */
  cefWorkerTimer_ = CFRunLoopTimerCreate(kCFAllocatorDefault,
                                         CFAbsoluteTimeGetCurrent() + kCefWorkerIntervalSec,
                                         kCefWorkerIntervalSec,
                                         0,
                                         0,
                                         (CFRunLoopTimerCallBack)OnCefWorkerTimer,
                                         nullptr);
  CFRunLoopAddTimer(CFRunLoopGetMain(), cefWorkerTimer_, kCFRunLoopDefaultMode);

  return true;
}

void
FSlateCefContext::FSlateCefContextPrivate::ShutdownCef()
{
  /** CEF 的 macOS 关闭必须回到主线程，与初始化线程要求保持一致。 */
  if (![NSThread isMainThread]) {
    dispatch_sync(dispatch_get_main_queue(), ^() {
      /** 回到主线程后执行真正的 CEF 关闭流程。 */
      ShutdownCef();
    });
    return;
  }

  if (!pApp_)
    return;

  pAppDelegate_ = nullptr;
  pApp_ = nullptr;

  /** 停止定时消息泵，避免关闭 CEF 后仍有 RunLoop 回调触发。 */
  CFRunLoopRemoveTimer(CFRunLoopGetMain(), cefWorkerTimer_, kCFRunLoopDefaultMode);
  CFRelease(cefWorkerTimer_);
  cefWorkerTimer_ = nullptr;

  /** 与初始化阶段的动态库加载配对释放。 */
  cef_unload_library();
}
#endif
