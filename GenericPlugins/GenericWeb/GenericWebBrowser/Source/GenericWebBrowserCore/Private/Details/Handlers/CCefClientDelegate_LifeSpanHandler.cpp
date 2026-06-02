//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "Details/CCefClientDelegate.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Math/IntRect.h>
#pragma endregion

#pragma region <Platform Headers>
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#include <Windows/AllowWindowsPlatformTypes.h>
#include <Windows.h>
#include <Windows/HideWindowsPlatformTypes.h>
#endif
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

#define DEFAULT_POPUP_WIDTH 800
#define DEFAULT_POPUP_HEIGHT 600

using namespace Common;

bool
CCefClientDelegate::onBeforePopup(CefRefPtr<CefBrowser>& browser,
                                  CefRefPtr<CefFrame>& frame,
                                  const CefString& targetUrl,
                                  const CefString& targetFrameName,
                                  CefLifeSpanHandler::WindowOpenDisposition targetDisposition,
                                  CefWindowInfo& windowInfo,
                                  CefBrowserSettings& settings,
                                  bool& disableJavascriptAccess)
{
  bool cancel = true;

  auto privateHost = pSCefViewPrivate_.Pin();
  if (!privateHost) {
    return cancel;
  }

  auto url = Convert::StringC2F(targetUrl);
  auto name = Convert::StringC2F(targetFrameName);
#if CEF_VERSION_MAJOR > 95
  auto rc = FIntRect(windowInfo.bounds.x,
                     windowInfo.bounds.y,
                     windowInfo.bounds.x + windowInfo.bounds.width,
                     windowInfo.bounds.y + windowInfo.bounds.height);
#else
  auto rc =
    FIntRect(windowInfo.x, windowInfo.y, windowInfo.x + windowInfo.width, windowInfo.ex_style + windowInfo.height);
#endif

  // QCefSetting s;
  // QCefSettingPrivate::CopyFromCefBrowserSettings(&s, &settings);

#if CEF_VERSION_MAJOR < 119
  auto CefNewPopupValue = CefLifeSpanHandler::WindowOpenDisposition::WOD_NEW_POPUP;
#else
  auto CefNewPopupValue = CefLifeSpanHandler::WindowOpenDisposition::CEF_WOD_NEW_POPUP;
#endif

  if (targetDisposition == CefNewPopupValue) {
    /** JavaScript 打开的弹窗需要交给 CEF 原生 popup 生命周期，保证脚本侧拿到新窗口身份。 */

    /** 这里预留从 CEF BrowserSettings 回填 Slate 配置的扩展点。 */
    FSlateCefViewSettings slateCefViewSettings;
    // TODO:

    cancel = privateHost->OnBeforeManagedPopupBrowser(Convert::FrameIdC2F(frame->GetIdentifier()),
                                                      url,
                                                      name,
                                                      (int32)targetDisposition,
                                                      rc,
                                                      slateCefViewSettings,
                                                      disableJavascriptAccess);
    if (!cancel) {
      /** 上层允许弹窗后，把可能修改过的窗口名和位置写回 CEF WindowInfo。 */
      // TODO:

      CefString(&windowInfo.window_name) = Convert::StringF2C(name);
#if CEF_VERSION_MAJOR > 95
      windowInfo.bounds = { rc.Min.X, rc.Min.Y, rc.Width(), rc.Height() };
#else
      windowInfo.x = rc.Min.X;
      windowInfo.y = rc.Min.Y;
      windowInfo.width = rc.Width();
      windowInfo.height = rc.Height();
#endif
    }
  } else {
    /** 非 JavaScript 弹窗不需要绑定脚本窗口身份，由上层创建独立浏览器承载。 */
    privateHost->OnBeforeIsolatedPopupBrowser(
      Convert::FrameIdC2F(frame->GetIdentifier()), url, name, (int32)targetDisposition, rc);
  }

  return cancel;
}

void
CCefClientDelegate::onAfterCreate(CefRefPtr<CefBrowser>& browser)
{
  auto privateHost = pSCefViewPrivate_.Pin();
  if (!privateHost) {
    return;
  }

  if (browser->IsPopup()) {
    /** CEF popup 创建完成后记录到弹窗生命周期路径。 */
    privateHost->OnAfterCefPopupBrowserCreated(browser);
  } else {
    /** 普通主浏览器创建完成后成为当前视图的主 CEF Browser。 */
    privateHost->OnAfeterCefMainBrowserCreated(browser);
  }
}

bool
CCefClientDelegate::doClose(CefRefPtr<CefBrowser>& browser)
{
  auto privateHost = pSCefViewPrivate_.Pin();
  if (!privateHost) {
    return false;
  }

  logDebug() << "destroy browser from native";

  return false;
}

bool
CCefClientDelegate::requestClose(CefRefPtr<CefBrowser>& browser)
{
  auto privateHost = pSCefViewPrivate_.Pin();
  if (!privateHost) {
    return false;
  }

  logDebug() << "destroy browser request from web";
  bool ignoreClose = false;

  return privateHost->OnRequestCloseFromWeb();
}

void
CCefClientDelegate::onBeforeClose(CefRefPtr<CefBrowser>& browser)
{
}
