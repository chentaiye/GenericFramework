//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "CefContext.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <HAL/PlatformFileManager.h>
#include <Modules/ModuleManager.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewModule.h>
#include <Slate/SlateCefContext.h>
#pragma endregion

#pragma region "Project Private headers"
#include "Common/Convert.h"
#include "Common/Log.h"
#include "HeadersCefViewCore.h"
#pragma endregion

using namespace Common;

bool
UCefContext::ShouldCreateSubsystem(UObject* Outer) const
{
  return Super::ShouldCreateSubsystem(Outer) && !IsRunningCommandlet() && !IsRunningDedicatedServer();
}

void
UCefContext::Initialize(FSubsystemCollectionBase& InCollection)
{
  Super::Initialize(InCollection);
}

bool
UCefContext::EnsureCefInitialized()
{
  if (FSlateCefContext::IsInitialized()) {
    return true;
  }

  /** 将引擎子系统配置投影到 Slate 层，Slate 层再负责转成 CEF 原生配置。 */
  FSlateCefSettings SlateCefSettings;
  SlateCefSettings.BridgeObjectName = Settings->BridgeObjectName;
  SlateCefSettings.BuiltinSchemeName = Settings->BuiltinSchemeName;
  SlateCefSettings.UserAgent = Settings->UserAgent;
  SlateCefSettings.ArchiveFileResourceMapping = Settings->ArchiveFileResourceMapping;
  SlateCefSettings.LocalFolderResourceMapping = Settings->LocalFolderResourceMapping;
  SlateCefSettings.BackgroundColor = Settings->BackgroundColor;
  SlateCefSettings.Locale = Settings->Locale;
  SlateCefSettings.AcceptLanguageList = Settings->AcceptLanguageList;
  SlateCefSettings.PersistSessionCookies = Settings->PersistSessionCookies;
  SlateCefSettings.PersistUserPreferences = Settings->PersistUserPreferences;
  SlateCefSettings.LogLevel = static_cast<ESlateCefLogLevel>(Settings->LogLevel);
  SlateCefSettings.RemoteDebuggingPort = Settings->RemoteDebuggingPort;
  SlateCefSettings.DisableCommandLineArgsPassthrough = Settings->DisableCommandLineArgsPassthrough;
  SlateCefSettings.DisableSandbox = Settings->DisableSandbox;
  SlateCefSettings.CommandLineArgs = Settings->CommandLineArgs;

  /** 初始化进程级 CEF 上下文；后续所有 SCefView 都复用这一份 CEF 生命周期。 */
  FSlateCefContext::Create(SlateCefSettings);

  return FSlateCefContext::IsInitialized();
}

void
UCefContext::Deinitialize()
{
  FSlateCefContext::Shutdown();

  Super::Deinitialize();
}

bool
UCefContext::bIsCefInitialized() const
{
  return FSlateCefContext::IsInitialized();
}

void
UCefContext::AddLocalFolderResource(const FString& InPath, const FString& InUrl, int32 InPriority /*= 0*/)
{
  if (!EnsureCefInitialized()) {
    return;
  }

  FSlateCefContext::Get().AddLocalFolderResource(InPath, InUrl, InPriority);
}

void
UCefContext::AddArchiveFileResource(const FString& InPath,
                                    const FString& InUrl,
                                    const FString& InPassword,
                                    int32 InPriority /*= 0*/)
{
  if (!EnsureCefInitialized()) {
    return;
  }

  FSlateCefContext::Get().AddArchiveFileResource(InPath, InUrl, InPassword, InPriority);
}

bool
UCefContext::AddCookie(const FString& InName, const FString& InValue, const FString& InDomain, const FString& InUrl)
{
  if (!EnsureCefInitialized()) {
    return false;
  }

  return FSlateCefContext::Get().AddCookie(InName, InValue, InDomain, InUrl);
}

bool
UCefContext::DeleteAllCookies()
{
  if (!EnsureCefInitialized()) {
    return false;
  }

  return FSlateCefContext::Get().DeleteAllCookies();
}

bool
UCefContext::AddCrossOriginWhitelistEntry(const FString& InSourceOrigin,
                                          const FString& InTargetSchema,
                                          const FString& InTargetDomain,
                                          bool InAllowTargetSubdomains)
{
  if (!EnsureCefInitialized()) {
    return false;
  }

  return FSlateCefContext::Get().AddCrossOriginWhitelistEntry(
    InSourceOrigin,
    InTargetSchema,
    InTargetDomain,
    InAllowTargetSubdomains
    );
}

bool
UCefContext::RemoveCrossOriginWhitelistEntry(const FString& InSourceOrigin,
                                             const FString& InTargetSchema,
                                             const FString& InTargetDomain,
                                             bool InAllowTargetSubdomains)
{
  if (!EnsureCefInitialized()) {
    return false;
  }

  return FSlateCefContext::Get().RemoveCrossOriginWhitelistEntry(
    InSourceOrigin,
    InTargetSchema,
    InTargetDomain,
    InAllowTargetSubdomains
    );
}

void
UCefContext::ClearCrossOriginWhitelistEntry()
{
  if (!EnsureCefInitialized()) {
    return;
  }

  return FSlateCefContext::Get().ClearCrossOriginWhitelistEntry();
}
