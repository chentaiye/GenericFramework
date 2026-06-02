//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "CefViewModule.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/Array.h>
#include <Misc/Paths.h>
// Projects/Public/
#include <Interfaces/IPluginManager.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefContext.h>
#pragma endregion

#pragma region "Project Private headers"
#include "HeadersCefViewCore.h"
#include "Common/Log.h"
#pragma endregion

namespace
{
FString
GetCefViewCorePlatformDirectory()
{
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
  return TEXT("Win64");
#elif defined(PLATFORM_MAC) && PLATFORM_MAC
#if TARGET_CPU_ARM64
  return TEXT("Mac/arm64");
#elif TARGET_CPU_X86_64
  return TEXT("Mac/x86_64");
#endif
#elif defined(PLATFORM_LINUX) && PLATFORM_LINUX
  return TEXT("Linux");
#elif defined(PLATFORM_LINUXARM64) && PLATFORM_LINUXARM64
  return TEXT("LinuxArm64");
#else
  return FString();
#endif
}

FString
GetCefViewCoreMarkerPath(const FString& InRuntimeDirectory)
{
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
  return FPaths::Combine(InRuntimeDirectory, TEXT("libcef.dll"));
#elif defined(PLATFORM_MAC) && PLATFORM_MAC
  return FPaths::Combine(InRuntimeDirectory,
                         TEXT("Chromium Embedded Framework.framework"),
                         TEXT("Chromium Embedded Framework"));
#elif defined(PLATFORM_LINUX) && PLATFORM_LINUX
  return FPaths::Combine(InRuntimeDirectory, TEXT("libcef.so"));
#elif defined(PLATFORM_LINUXARM64) && PLATFORM_LINUXARM64
  return FPaths::Combine(InRuntimeDirectory, TEXT("libcef.so"));
#else
  return InRuntimeDirectory;
#endif
}

void
AddCefViewCoreCandidatesForPlugin(TArray<FString>& OutCandidates, const TCHAR* InPluginName)
{
  TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(InPluginName);
  if (!Plugin.IsValid()) {
    return;
  }

  const FString PlatformDirectory = GetCefViewCorePlatformDirectory();
  if (PlatformDirectory.IsEmpty()) {
    return;
  }

  OutCandidates.Add(FPaths::Combine(Plugin->GetBaseDir(), TEXT("Binaries/ThirdParty/CefViewCore"), PlatformDirectory));
  OutCandidates.Add(
    FPaths::Combine(Plugin->GetBaseDir(), TEXT("Source/ThirdParty/CefViewCore/bin"), PlatformDirectory));
}

FString
ResolveCefViewCoreDirectory()
{
  TArray<FString> Candidates;
  AddCefViewCoreCandidatesForPlugin(Candidates, TEXT("GenericWebBrowser"));
  AddCefViewCoreCandidatesForPlugin(Candidates, TEXT("GenericWebFramework"));

  for (const FString& Candidate : Candidates) {
    const FString FullCandidate = FPaths::ConvertRelativePathToFull(Candidate);
    if (FPaths::FileExists(GetCefViewCoreMarkerPath(FullCandidate))) {
      return FullCandidate;
    }
  }

  for (const FString& Candidate : Candidates) {
    const FString FullCandidate = FPaths::ConvertRelativePathToFull(Candidate);
    logWarn() << "CEF runtime marker not found at:" << *GetCefViewCoreMarkerPath(FullCandidate);
  }

  return Candidates.Num() > 0 ? FPaths::ConvertRelativePathToFull(Candidates[0]) : FString();
}
}

void
FCefViewModule::StartupModule()
{
  /** 模块启动时先接入内部日志，确保后续 CEF 路径和生命周期问题能进入 UE 日志。 */
  Common::InitializeLogger();

  /** CEF 运行库可能跟随封装插件或基础插件分发，启动时解析到真实存在的目录。 */
  CefViewCoreDir = ResolveCefViewCoreDirectory();
  logInfo() << "CEF runtime directory:" << *CefViewCoreDir;
}

void
FCefViewModule::ShutdownModule()
{
  /** 模块卸载时关闭日志适配，避免后续静态清理阶段继续访问 UE 日志系统。 */
  Common::ExitLogger();
}

FString
FCefViewModule::GetCefViewCoreDir()
{
  return CefViewCoreDir;
}

IMPLEMENT_MODULE(FCefViewModule, GenericWebBrowserCore)
