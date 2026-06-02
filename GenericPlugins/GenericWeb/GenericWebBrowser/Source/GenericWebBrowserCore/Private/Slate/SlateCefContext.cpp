//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
// UCefView/Public/
#include "Slate/SlateCefContext.h"
#pragma endregion

#pragma region <Engine Headers>
// CoreUObject/Public/
#include <UObject/Class.h>
#include <UObject/UnrealType.h>
// Json/Public/
#include <Dom/JsonValue.h>
#include <Dom/JsonObject.h>
#include <Serialization/JsonReader.h>
#include <Serialization/JsonSerializer.h>
// Slate/Public/
#include <SlateOptMacros.h>
#include <Framework/Application/SlateApplication.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#include "SlateCefContextPrivate.h"
#include "Common/Log.h"
#include "Common/Convert.h"
#include "SCefViewPrivate.h"
#pragma endregion

using namespace Common;

TSharedPtr<FSlateCefContext> FSlateCefContext::CurrentContext = nullptr;

FSlateCefContext::FSlateCefContext()
  : m_pImp(MakePimpl<FSlateCefContextPrivate>())
{
}

FSlateCefContext::~FSlateCefContext()
{
  m_pImp.Reset();
}

void
FSlateCefContext::Create(const FSlateCefSettings& InSettings)
{
  check(!CurrentContext.IsValid());

  TSharedPtr<FSlateCefContext> ContextInstnace = MakeShareable(new FSlateCefContext());
  if (ContextInstnace->m_pImp->InitializeCef(InSettings)) {
    CurrentContext = ContextInstnace;
  }
}

void
FSlateCefContext::Shutdown()
{
  if (CurrentContext.IsValid()) {
    CurrentContext->m_pImp->ShutdownCef();
    CurrentContext.Reset();
  }
}

bool
FSlateCefContext::IsInitialized()
{
  return CurrentContext.IsValid();
}

FSlateCefContext&
FSlateCefContext::Get()
{
  return *CurrentContext;
}

void
FSlateCefContext::AddLocalFolderResource(const FString& InPath, const FString& InUrl, int32 InPriority /*= 0*/)
{
  m_pImp->pApp_->AddLocalFolderResource(Convert::StringF2C(InPath), Convert::StringF2C(InUrl), InPriority);
}

void
FSlateCefContext::AddArchiveFileResource(const FString& InPath,
                                         const FString& InUrl,
                                         const FString& InPassword,
                                         int32 InPriority /*= 0*/)
{
  m_pImp->pApp_->AddArchiveResource(
    Convert::StringF2C(InPath), Convert::StringF2C(InUrl), Convert::StringF2C(InPassword), InPriority);
}

bool
FSlateCefContext::AddCookie(const FString& InName,
                            const FString& InValue,
                            const FString& InDomain,
                            const FString& InUrl)
{
  CefCookie Cookie;
  CefString(&Cookie.name) = Convert::StringF2C(InName);
  CefString(&Cookie.value) = Convert::StringF2C(InValue);
  CefString(&Cookie.domain) = Convert::StringF2C(InDomain);
  return CefCookieManager::GetGlobalManager(nullptr)->SetCookie(Convert::StringF2C(InUrl), Cookie, nullptr);
}

bool
FSlateCefContext::DeleteAllCookies()
{
  return CefCookieManager::GetGlobalManager(nullptr)->DeleteCookies(CefString(), CefString(), nullptr);
}

bool
FSlateCefContext::AddCrossOriginWhitelistEntry(const FString& InSourceOrigin,
                                               const FString& InTargetSchema,
                                               const FString& InTargetDomain,
                                               bool InAllowTargetSubdomains)
{
  auto Source = Convert::StringF2C(InSourceOrigin);
  auto Schema = Convert::StringF2C(InTargetSchema);
  auto Domain = Convert::StringF2C(InTargetDomain);
  return CefAddCrossOriginWhitelistEntry(Source, Schema, Domain, InAllowTargetSubdomains);
}

bool
FSlateCefContext::RemoveCrossOriginWhitelistEntry(const FString& InSourceOrigin,
                                                  const FString& InTargetSchema,
                                                  const FString& InTargetDomain,
                                                  bool InAllowTargetSubdomains)
{
  auto Source = Convert::StringF2C(InSourceOrigin);
  auto Schema = Convert::StringF2C(InTargetSchema);
  auto Domain = Convert::StringF2C(InTargetDomain);
  return CefRemoveCrossOriginWhitelistEntry(Source, Schema, Domain, InAllowTargetSubdomains);
}

void
FSlateCefContext::ClearCrossOriginWhitelistEntry()
{
  CefClearCrossOriginWhitelist();
}
