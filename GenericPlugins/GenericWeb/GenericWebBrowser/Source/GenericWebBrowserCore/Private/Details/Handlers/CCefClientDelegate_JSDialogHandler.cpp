//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "Details/CCefClientDelegate.h"
#pragma endregion

#pragma region <Engine Headers>
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

bool
CCefClientDelegate::onJSDialog(CefRefPtr<CefBrowser>& browser,
                               const CefString& origin_url,
                               CefJSDialogHandler::JSDialogType dialog_type,
                               const CefString& message_text,
                               const CefString& default_prompt_text,
                               CefRefPtr<CefJSDialogCallback>& callback,
                               bool& suppress_message)
{
  /// Called to run a JavaScript dialog.
  ///
  /// If |origin_url| is non-empty it can be passed to the CefFormatUrlForSecurityDisplay
  /// function to retrieve a secureand user-friendly display string.
  ///
  /// The |default_prompt_text| value will be specified for prompt dialogs only.
  ///
  /// Set |suppress_message| to true and return false to suppress the message
  /// (suppressing messages is preferable to immediately executing the callback
  /// as this is used to detect presumably malicious behavior like spamming alert
  /// messages in onbeforeunload).
  ///
  /// Set |suppress_message| to false and return false to use the default
  /// implementation (the default implementation will show one modal dialog at a
  /// time and suppress any additional dialog requests until the displayed
  /// dialog is dismissed).
  ///
  /// Return true if the application will use a custom dialog or if the callback has
  /// been executed immediately. Custom dialogs may be either modal or modeless. If a
  /// custom dialog is used the application must execute |callback| once the custom
  /// dialog is dismissed.

  AcquireAndValidatePrivateHostWithReturn(privateHost, false);

  auto safeOrignUrl = CefFormatUrlForSecurityDisplay(origin_url);
  auto orignalUrl = Convert::StringC2F(safeOrignUrl);
  auto messageText = Convert::StringC2F(message_text);
  auto defaultPromptText = Convert::StringC2F(default_prompt_text);
  return privateHost->OnJSDialog(
    browser, orignalUrl, dialog_type, messageText, defaultPromptText, callback, suppress_message);
}

bool
CCefClientDelegate::onBeforeUnloadDialog(CefRefPtr<CefBrowser>& browser,
                                         const CefString& message_text,
                                         bool is_reload,
                                         CefRefPtr<CefJSDialogCallback>& callback)
{
  /// Called to run a dialog asking the user if they want to leave a page.
  /// Return false to use the default dialog implementation. Return true if the
  /// application will use a custom dialog or if the callback has been executed
  /// immediately. Custom dialogs may be either modal or modeless. If a custom
  /// dialog is used the application must execute |callback| once the custom
  /// dialog is dismissed.

  AcquireAndValidatePrivateHostWithReturn(privateHost, false);

  auto messageText = Convert::StringC2F(message_text);
  return privateHost->OnBeforeUnloadDialog(browser, messageText, is_reload, callback);
}

void
CCefClientDelegate::onResetDialogState(CefRefPtr<CefBrowser>& browser)
{
  /// Called to cancel any pending dialogs and reset any saved dialog state.
  /// Will be called due to events like page navigation irregardless of whether
  /// any dialogs are currently pending.

  AcquireAndValidatePrivateHost(privateHost);

  privateHost->OnResetDialogState(browser);
}

void
CCefClientDelegate::onDialogClosed(CefRefPtr<CefBrowser>& browser)
{
  AcquireAndValidatePrivateHost(privateHost);

  privateHost->OnDialogClosed(browser);
}
