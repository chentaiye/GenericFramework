//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#if defined(PLATFORM_LINUX) && PLATFORM_LINUX

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
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#include "HeadersCefViewCore.h"
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

bool
FSlateCefContext::FSlateCefContextPrivate::InitializeCef(const FSlateCefSettings& InSlateCefSettings)
{
  /** 先填充跨平台 CEF 配置，再叠加 Linux 专用启动参数。 */
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

  CefSettings.no_sandbox = true;
  CefSettings.multi_threaded_message_loop = true;
  CefSettings.external_message_pump = false;

  /** CEF 子进程必须指向随插件分发的 CefView 渲染进程可执行文件。 */
  FCefViewModule* CurrentModule = FModuleManager::GetModulePtr<FCefViewModule>(TEXT("GenericWebBrowserCore"));
  if (!CurrentModule) {
    logError() << "Failed to get current module";
    return false;
  }
  FString CefViewWingPath = CurrentModule->GetCefViewCoreDir();
  CefViewWingPath /= TEXT(kCefViewRenderProcessName);
  CefViewWingPath = FPaths::ConvertRelativePathToFull(CefViewWingPath);
  if (!FPaths::FileExists(CefViewWingPath)) {
    logError() << "CefView subprocess not found at:" << *CefViewWingPath;
    return false;
  }
  CefString(&CefSettings.browser_subprocess_path) = Convert::StringF2C(CefViewWingPath);

  /** 创建 CEF App 并启动进程级 CEF 上下文。 */
  auto AppDelegate = std::make_shared<CCefAppDelegate>(InSlateCefSettings.CommandLineArgs);
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

  return true;
}

void
FSlateCefContext::FSlateCefContextPrivate::ShutdownCef()
{
  if (!pApp_)
    return;

  pAppDelegate_ = nullptr;
  pApp_ = nullptr;

  /** 关闭进程级 CEF 上下文。 */
  CefShutdown();
}
#endif
