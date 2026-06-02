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
#include "Details/Handlers/Utils/InputUtils.h"
#pragma endregion

using namespace Common;

void
CCefClientDelegate::addressChanged(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame, const CefString& url)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto bid = browser->GetIdentifier();
  auto fid = Convert::FrameIdC2F(frame->GetIdentifier());
  auto u = Convert::StringC2F(url);

  logDebug() << "CCefClientDelegate::addressChanged:" << u;

  // workaround for: https://github.com/chromiumembedded/cef/issues/3870
  if (privateHost->bHasCefGotFocus && browser->GetHost()) {
    browser->GetHost()->SetFocus(true);
  }

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, fid, u]() {
    if (auto host = weakHost.Pin()) {
      host->OnAddressChanged.ExecuteIfBound(fid, u);
    }
  });
}

void
CCefClientDelegate::titleChanged(CefRefPtr<CefBrowser>& browser, const CefString& title)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto bid = browser->GetIdentifier();
  auto t = Convert::StringC2F(title);

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, t]() {
    if (auto host = weakHost.Pin()) {
      host->OnTitleChanged.ExecuteIfBound(t);
    }
  });
}

void
CCefClientDelegate::faviconURLChanged(CefRefPtr<CefBrowser>& browser, const std::vector<CefString>& icon_urls)
{
  AcquireAndValidatePrivateHost(privateHost);

  TArray<FString> urls;
  for (auto& iconUrl : icon_urls) {
    urls.Add(Convert::StringC2F(iconUrl.ToString()));
  }

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, urls]() {
    if (auto host = weakHost.Pin()) {
      host->OnFaviconUrlChanged.ExecuteIfBound(urls);
    }
  });
}

void
CCefClientDelegate::fullscreenModeChanged(CefRefPtr<CefBrowser>& browser, bool fullscreen)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, fullscreen]() {
    if (auto host = weakHost.Pin()) {
      host->OnFullscreenModeChanged.ExecuteIfBound(fullscreen);
    }
  });
}

bool
CCefClientDelegate::tooltipMessage(CefRefPtr<CefBrowser>& browser, const CefString& text)
{
  /** 返回 false 让 CEF 继续使用默认 tooltip 行为。 */
  return false;
}

void
CCefClientDelegate::statusMessage(CefRefPtr<CefBrowser>& browser, const CefString& value)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto msg = Convert::StringC2F(value);

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, msg]() {
    if (auto host = weakHost.Pin()) {
      host->OnStatusMessage.ExecuteIfBound(msg);
    }
  });
}

void
CCefClientDelegate::consoleMessage(CefRefPtr<CefBrowser>& browser, const CefString& message, int level)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto msg = Convert::StringC2F(message);

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, msg, level]() {
    if (auto host = weakHost.Pin()) {
      host->OnConsoleMessage.ExecuteIfBound(msg, level);
    }
  });
}

void
CCefClientDelegate::loadingProgressChanged(CefRefPtr<CefBrowser>& browser, double progress)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto weakHost = privateHost->m_pHost;
  AsyncTask(ENamedThreads::GameThread, [weakHost, progress]() {
    if (auto host = weakHost.Pin()) {
      host->OnLoadingProgressChanged.ExecuteIfBound(progress);
    }
  });
}

bool
CCefClientDelegate::cursorChanged(CefRefPtr<CefBrowser>& browser,
                                  CefCursorHandle cursor,
                                  cef_cursor_type_t type,
                                  const CefCursorInfo& custom_cursor_info)
{
  AcquireAndValidatePrivateHostWithReturn(privateHost, false);

  privateHost->OnCefCursorChanged(cursor, type, custom_cursor_info);
  return true;
}
