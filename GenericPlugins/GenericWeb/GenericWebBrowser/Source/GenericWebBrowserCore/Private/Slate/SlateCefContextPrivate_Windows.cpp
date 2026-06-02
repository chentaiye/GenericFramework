//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
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
#include "Common/Platform.h"
#include "Details/CCefAppDelegate.h"
#pragma endregion

using namespace Common;

struct DllSearchGuard
{
  FString SearchDirectory;

  DllSearchGuard(const FString& Directory)
    : SearchDirectory(Directory)
  {
    FPlatformProcess::PushDllDirectory(*SearchDirectory);
  }

  ~DllSearchGuard()
  { //
    FPlatformProcess::PopDllDirectory(*SearchDirectory);
  }
};

bool
FSlateCefContext::FSlateCefContextPrivate::InitializeCef(const FSlateCefSettings& InSlateCefSettings)
{
  FCefViewModule* CurrentModule = FModuleManager::GetModulePtr<FCefViewModule>(TEXT("GenericWebBrowserCore"));
  if (!CurrentModule) {
    logError() << "Failed to get current module";
    return false;
  }

  FString CefViewCoreDir = CurrentModule->GetCefViewCoreDir();
  DllSearchGuard CefViewCoreDirGuard(*CefViewCoreDir);

  FString CefLibPath = CefViewCoreDir / TEXT("libcef.dll");
  CefLibPath = FPaths::ConvertRelativePathToFull(CefLibPath);
  if (!FPaths::FileExists(CefLibPath)) {
    logError() << "libcef.dll not found at:" << *CefLibPath;
    return false;
  }

#if CEF_VERSION_MAJOR < 112
  /** 旧版 CEF 需要显式启用 Windows 7 及以上系统的高 DPI 支持。 */
  CefEnableHighDPISupport();
#endif

  /** 先填充跨平台 CEF 配置，再叠加 Windows 专用启动参数。 */
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
  FString CefViewWingPath = CurrentModule->GetCefViewCoreDir();
  CefViewWingPath /= TEXT(kCefViewRenderProcessName);
  CefViewWingPath = FPaths::ConvertRelativePathToFull(CefViewWingPath);
  if (!FPaths::FileExists(CefViewWingPath) && !FPaths::FileExists(CefViewWingPath + TEXT(".exe"))) {
    logError() << "CefView subprocess not found at:" << *CefViewWingPath;
    return false;
  }
  CefString(&CefSettings.browser_subprocess_path) = Convert::StringF2C(CefViewWingPath);

  auto CommandLineArgs = InSlateCefSettings.CommandLineArgs;

  /** 用 Windows Job 管理 CEF 子进程，插件进程退出时联动清理渲染进程。 */
  windowsJobName_ =
    FString::Printf(TEXT("UCefView-Job-{0b05c48c-05ed-4cc9-b33f-2470c435ead5}-%d"), ::GetCurrentProcessId());
  windowsJobHandle_ = ::CreateJobObject(nullptr, *windowsJobName_);
  if (NULL != windowsJobHandle_ && INVALID_HANDLE_VALUE != windowsJobHandle_) {
    /** Job 关闭时杀掉关联子进程，并允许 CEF 子进程按需脱离作业限制。 */
    JOBOBJECT_EXTENDED_LIMIT_INFORMATION info;
    ::ZeroMemory(&info, sizeof(info));
    info.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE | JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK;
    if (!::SetInformationJobObject(windowsJobHandle_, JobObjectExtendedLimitInformation, &info, sizeof(info))) {
      logWarn() << "Failed to set information for windows job object:" << GetLastError();
    }
    CommandLineArgs.Add(TEXT(kCefViewWindowsJobNameKey), windowsJobName_);
  } else {
    logWarn() << "Failed to create windows job object:" << ::GetLastError();
  }

  /** 创建 CEF App 并启动进程级 CEF 上下文。 */
  auto AppDelegate = std::make_shared<CCefAppDelegate>(CommandLineArgs);
  auto BuiltinSchemeName = Convert::StringF2C(InSlateCefSettings.BuiltinSchemeName.ToString());
  auto BridgeObjectName = Convert::StringF2C(InSlateCefSettings.BridgeObjectName.ToString());
  auto App = new CefViewBrowserApp(BuiltinSchemeName, BridgeObjectName, AppDelegate);

  void* SandboxInfo = nullptr;
#if defined(CEF_USE_SANDBOX)
  /** 沙箱信息对象必须覆盖整个 CEF 生命周期，细节见 CEF 的 cef_sandbox_win.h。 */
  static CefScopedSandboxInfo ScopedSandbox;
  SandboxInfo = ScopedSandbox.sandbox_info();
#endif

  CefMainArgs MainArgs(::GetModuleHandle(nullptr));
  if (!CefInitialize(MainArgs, CefSettings, App, SandboxInfo)) {
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

  /** 关闭 Job 句柄会触发子进程清理策略。 */
  if (windowsJobHandle_) {
    ::CloseHandle(windowsJobHandle_);
    windowsJobHandle_ = nullptr;
  }
}
#endif
