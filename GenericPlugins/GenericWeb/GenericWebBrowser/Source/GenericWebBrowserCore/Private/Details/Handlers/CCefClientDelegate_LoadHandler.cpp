//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "Details/CCefClientDelegate.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Async/Async.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Convert.h"
#include "Common/Log.h"
#include "Slate/SCefViewPrivate.h"
#pragma endregion

using namespace Common;

void
CCefClientDelegate::loadingStateChanged(CefRefPtr<CefBrowser>& browser,
                                        bool isLoading,
                                        bool canGoBack,
                                        bool canGoForward)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, browser, isLoading, canGoBack, canGoForward]() {
    auto host = weakHost.Pin();
    if (host) {
      host->OnLoadStateChanged.ExecuteIfBound(browser->GetIdentifier(), isLoading, canGoBack, canGoForward);
    }
  });
}

void
CCefClientDelegate::loadStart(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame, int transitionType)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, browser, frame, transitionType]() {
    auto host = weakHost.Pin();
    if (host) {
      host->OnLoadStart.ExecuteIfBound(
        browser->GetIdentifier(), Convert::FrameIdC2F(frame->GetIdentifier()), frame->IsMain(), transitionType);
    }
  });
}

void
CCefClientDelegate::loadEnd(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame, int httpStatusCode)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, browser, frame, httpStatusCode]() {
    auto host = weakHost.Pin();
    if (host) {
      host->OnLoadEnd.ExecuteIfBound(
        browser->GetIdentifier(), Convert::FrameIdC2F(frame->GetIdentifier()), frame->IsMain(), httpStatusCode);
    }
  });
}

void
CCefClientDelegate::loadError(CefRefPtr<CefBrowser>& browser,
                              CefRefPtr<CefFrame>& frame,
                              int errorCode,
                              const CefString& errorMsg,
                              const CefString& failedUrl,
                              bool& handled)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto host = privateHost->m_pHost.Pin();
  if (host) {
    host->OnLoadError.ExecuteIfBound(browser->GetIdentifier(),
                                     Convert::FrameIdC2F(frame->GetIdentifier()),
                                     frame->IsMain(),
                                     errorCode,
                                     Convert::StringC2F(errorMsg),
                                     Convert::StringC2F(failedUrl),
                                     handled);
  }
}
