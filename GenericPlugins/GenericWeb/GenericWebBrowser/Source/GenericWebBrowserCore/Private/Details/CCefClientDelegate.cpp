//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "CCefClientDelegate.h"
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
#include <Slate/SCefView.h>
#pragma endregion

#pragma region "Project Private Headers"
#include "Common/Log.h"
#include "Common/Convert.h"
#include "Slate/SCefViewPrivate.h"
#pragma endregion

using namespace Common;

CCefClientDelegate::CCefClientDelegate(TSharedRef<SCefViewPrivate> p)
  : pSCefViewPrivate_(p)
{
}

CCefClientDelegate::~CCefClientDelegate()
{
  logDebug() << "CCefClientDelegate is being destructed";
}

void
CCefClientDelegate::processUrlRequest(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame, const CefString& url)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto host = privateHost->m_pHost.Pin();
  if (host) {
    auto bid = browser->GetIdentifier();
    auto fid = Convert::FrameIdC2F(frame->GetIdentifier());
    auto u = Convert::StringC2F(url);

    if (IsInGameThread()) {
      host->OnUrlRequest.ExecuteIfBound(bid, fid, u);
    } else {
      auto weakHost = privateHost->m_pHost;
      AsyncTask(                   //
        ENamedThreads::GameThread, //
        [weakHost, bid, fid, u]() {
          if (auto host = weakHost.Pin()) {
            host->OnUrlRequest.ExecuteIfBound(bid, fid, u);
          }
        });
    }
  }
}

void
CCefClientDelegate::processQueryRequest(CefRefPtr<CefBrowser>& browser,
                                        CefRefPtr<CefFrame>& frame,
                                        const CefString& request,
                                        const int64_t query_id)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto host = privateHost->m_pHost.Pin();
  if (!host || !host->OnQueryRequest.IsBound()) {
    privateHost->ResponseCefQuery(query_id, false, "", -1);
    return;
  }

  auto bid = browser->GetIdentifier();
  auto fid = Convert::FrameIdC2F(frame->GetIdentifier());
  auto req = Convert::StringC2F(request);
  if (IsInGameThread()) {
    host->OnQueryRequest.Execute(bid, fid, query_id, req);
  } else {
    auto weakHost = privateHost->m_pHost;
    AsyncTask(                   //
      ENamedThreads::GameThread, //
      [weakHost, bid, fid, query_id, req]() {
        if (auto host = weakHost.Pin()) {
          host->OnQueryRequest.Execute(bid, fid, query_id, req);
        }
      });
  }
}

void
CCefClientDelegate::invokeMethodNotify(CefRefPtr<CefBrowser>& browser,
                                       CefRefPtr<CefFrame>& frame,
                                       const CefString& method,
                                       const CefRefPtr<CefListValue>& arguments)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto host = privateHost->m_pHost.Pin();
  if (host) {
    auto bid = browser->GetIdentifier();
    auto fid = Convert::FrameIdC2F(frame->GetIdentifier());
    auto m = Convert::StringC2F(method);

    /** CEF 进程消息参数先转换为 JSON 值数组，再交给 Slate/UMG 事件层。 */
    TArray<TSharedPtr<FJsonValue>> jsonArgs;
    for (int i = 0; i < arguments->GetSize(); i++) {
      TSharedPtr<FJsonValue> arg;
      auto cV = arguments->GetValue(i);
      Convert::CefValueToJsonValue(arg, cV.get());
      jsonArgs.Add(arg);
    }

    if (IsInGameThread()) {
      host->OnInvokeMethod.ExecuteIfBound(bid, fid, m, jsonArgs);
    } else {
      auto weakHost = privateHost->m_pHost;
      AsyncTask(                   //
        ENamedThreads::GameThread, //
        [weakHost, bid, fid, m, jsonArgs]() {
          if (auto host = weakHost.Pin()) {
            host->OnInvokeMethod.ExecuteIfBound(bid, fid, m, jsonArgs);
          }
        });
    }
  }
}

void
CCefClientDelegate::reportJSResult(CefRefPtr<CefBrowser>& browser,
                                   CefRefPtr<CefFrame>& frame,
                                   const CefString& context,
                                   const CefRefPtr<CefValue>& result)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto host = privateHost->m_pHost.Pin();
  if (host) {
    auto bid = browser->GetIdentifier();
    auto fid = Convert::FrameIdC2F(frame->GetIdentifier());
    auto ctx = Convert::StringC2F(context);

    /** JavaScript 异步结果保持结构化 JSON 值，最终由上层决定如何序列化或消费。 */
    TSharedPtr<FJsonValue> jsonResult;
    Convert::CefValueToJsonValue(jsonResult, result.get());

    if (IsInGameThread()) {
      host->OnReportJavascriptResult.ExecuteIfBound(bid, fid, ctx, jsonResult);
    } else {
      auto weakHost = privateHost->m_pHost;
      AsyncTask(                   //
        ENamedThreads::GameThread, //
        [weakHost, bid, fid, ctx, jsonResult]() {
          if (auto host = weakHost.Pin()) {
            host->OnReportJavascriptResult.ExecuteIfBound(bid, fid, ctx, jsonResult);
          }
        });
    }
  }
}

void
CCefClientDelegate::focusedEditableNodeChanged(CefRefPtr<CefBrowser>& browser,
                                               CefRefPtr<CefFrame>& frame,
                                               bool focusOnEditableNode)
{
  AcquireAndValidatePrivateHost(privateHost);

  if (IsInGameThread()) {
    privateHost->OnCefInputStateChanged(focusOnEditableNode);
  } else {
    auto weakPrivate = pSCefViewPrivate_;
    AsyncTask(                   //
      ENamedThreads::GameThread, //
      [weakPrivate, focusOnEditableNode]() {
        if (auto p = weakPrivate.Pin()) {
          p->OnCefInputStateChanged(focusOnEditableNode);
        }
      });
  }
}
