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

void
CCefClientDelegate::onBeforeDownload(CefRefPtr<CefBrowser>& browser,
                                     CefRefPtr<CefDownloadItem>& download_item,
                                     const CefString& suggested_name,
                                     CefRefPtr<CefBeforeDownloadCallback>& callback)
{
  FLog();

  AcquireAndValidatePrivateHost(privateHost);

  logDebug() << "onBeforeDownload, percent: " << download_item->GetPercentComplete() << "% \n"
             << download_item->GetTotalBytes() << "/" << download_item->GetReceivedBytes() << "\n"
             << "  inProgress: " << download_item->IsInProgress() << "\n"
             << "  canceled: " << download_item->IsCanceled() << "\n"
             << "  complete: " << download_item->IsComplete();

  privateHost->OnBeforeDownload(browser, download_item, Convert::StringC2F(suggested_name), callback);
}

void
CCefClientDelegate::onDownloadUpdated(CefRefPtr<CefBrowser>& browser,
                                      CefRefPtr<CefDownloadItem>& download_item,
                                      CefRefPtr<CefDownloadItemCallback>& callback)
{
  FLog();

  AcquireAndValidatePrivateHost(privateHost);

  logDebug() << "onDownloadUpdated, percent: " << download_item->GetPercentComplete() << "% \n"
             << download_item->GetTotalBytes() << "/" << download_item->GetReceivedBytes() << "\n"
             << "  inProgress: " << download_item->IsInProgress() << "\n"
             << "  canceled: " << download_item->IsCanceled() << "\n"
             << "  complete: " << download_item->IsComplete();

  privateHost->OnDownloadUpdated(browser, download_item, callback);
}
