//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "Details/CCefClientDelegate.h"
#pragma endregion

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
// Core/Public/
#include <Async/Async.h>
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

void
CCefClientDelegate::takeFocus(CefRefPtr<CefBrowser>& browser, bool next)
{
  AcquireAndValidatePrivateHost(privateHost);

  privateHost->OnCefReleasedFocus(next);
}

bool
CCefClientDelegate::setFocus(CefRefPtr<CefBrowser>& browser)
{
  AcquireAndValidatePrivateHostWithReturn(privateHost, false);

  return privateHost->OnCefRequestFocus();
}

void
CCefClientDelegate::gotFocus(CefRefPtr<CefBrowser>& browser)
{
  AcquireAndValidatePrivateHost(privateHost);

  privateHost->OnCefGotFocus();
}
