//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "SlateCefContextPrivate.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Misc/MessageDialog.h>
#include <Misc/Paths.h>
#include <Modules/ModuleManager.h>
#include <HAL/PlatformFileManager.h>
// Core/Public/
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

FSlateCefContext::FSlateCefContextPrivate::FSlateCefContextPrivate() {}

FSlateCefContext::FSlateCefContextPrivate::~FSlateCefContextPrivate() {}

void
FSlateCefContext::FSlateCefContextPrivate::BuildCefSettings(CefSettings& InCefSettings,
                                                            const FSlateCefSettings& InSlateCefSettings)
{
  CefString(&InCefSettings.locale) = Convert::StringF2C(InSlateCefSettings.Locale);
  CefString(&InCefSettings.user_agent) = Convert::StringF2C(InSlateCefSettings.UserAgent);

  FString JoinedLangList;
  for (const FString& Lang : InSlateCefSettings.AcceptLanguageList) {
    if (!Lang.IsEmpty()) {
      JoinedLangList += Lang;
      JoinedLangList += TEXT(",");
    }
  }
  CefString(&InCefSettings.accept_language_list) = Convert::StringF2C(JoinedLangList);

  /** 将 CEF 缓存和用户数据固定到项目 Saved 目录，避免污染引擎或插件目录。 */
  FString StorageRoot = FPaths::ProjectSavedDir() / TEXT("GenericWeb/Browser");
  if (!StorageRoot.IsEmpty()) {
    StorageRoot = FPaths::ConvertRelativePathToFull(StorageRoot);
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (PlatformFile.DirectoryExists(*StorageRoot) || PlatformFile.CreateDirectoryTree(*StorageRoot)) {
#if CEF_VERSION_MAJOR < 115
      CefString(&InCefSettings.user_data_path) = Convert::StringF2C(StorageRoot);
#else
      CefString(&InCefSettings.root_cache_path) = Convert::StringF2C(StorageRoot);
#endif
      CefString(&InCefSettings.cache_path) = Convert::StringF2C(StorageRoot);
    } else {
      logError() << "Failed to create storage folder:" << *StorageRoot;
    }
  }

  InCefSettings.log_severity = static_cast<cef_log_severity_t>(InSlateCefSettings.LogLevel);
  InCefSettings.persist_session_cookies = InSlateCefSettings.PersistSessionCookies;
  InCefSettings.persist_user_preferences = InSlateCefSettings.PersistUserPreferences;
  InCefSettings.remote_debugging_port = InSlateCefSettings.RemoteDebuggingPort;
  InCefSettings.background_color = InSlateCefSettings.BackgroundColor.ToPackedARGB();
  InCefSettings.command_line_args_disabled = InSlateCefSettings.DisableCommandLineArgsPassthrough;
  InCefSettings.no_sandbox = InSlateCefSettings.DisableSandbox;

  InCefSettings.windowless_rendering_enabled = true;
}

void
FSlateCefContext::FSlateCefContextPrivate::AddResourceMapping(CefViewBrowserApp* InApp,
                                                              const FSlateCefSettings& InSlateCefSettings)
{
  /** 注册归档资源映射，使内置 scheme 可以从项目目录读取打包资源。 */
  for (const auto& Mapping : InSlateCefSettings.ArchiveFileResourceMapping) {
    if (Mapping.Path.FilePath.IsEmpty() || Mapping.Url.IsEmpty()) {
      continue;
    }

    auto GameDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
    auto ArchivePath = FPaths::RemoveDuplicateSlashes(FPaths::Combine(GameDir, Mapping.Path.FilePath));
    auto Path = Convert::StringF2C(ArchivePath);
    auto Url = Convert::StringF2C(Mapping.Url);
    auto Password = Convert::StringF2C(Mapping.Password);
    InApp->AddArchiveResource(Path, Url, Password, Mapping.Priority);
  }

  /** 注册本地目录映射，使页面可以通过内置 scheme 访问项目 Content 下的资源。 */
  for (const auto& Mapping : InSlateCefSettings.LocalFolderResourceMapping) {
    if (Mapping.Path.Path.IsEmpty() || Mapping.Url.IsEmpty()) {
      continue;
    }

    auto GameContentDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
    auto FolderPath = FPaths::RemoveDuplicateSlashes(FPaths::Combine(GameContentDir, Mapping.Path.Path));
    auto Path = Convert::StringF2C(FolderPath);
    auto Url = Convert::StringF2C(Mapping.Url);
    InApp->AddLocalFolderResource(Path, Url, Mapping.Priority);
  }
}
