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
#include "Details/Handlers/Utils/MenuUtils.h"
#pragma endregion

using namespace Common;

void
CCefClientDelegate::onBeforeContextMenu(CefRefPtr<CefBrowser>& browser,
                                        CefRefPtr<CefFrame>& frame,
                                        CefRefPtr<CefContextMenuParams>& params,
                                        CefRefPtr<CefMenuModel>& model)
{
  FLog();

  AcquireAndValidatePrivateHost(privateHost);

  /** 离屏弹窗不走当前主视图的 Slate 菜单路径。 */
  if (browser->IsPopup()) {
    return;
  }

  auto fid = Convert::FrameIdC2F(frame->GetIdentifier());
  privateHost->OnBeforeCefContextMenu(fid, model);
}

bool
CCefClientDelegate::onRunContextMenu(CefRefPtr<CefBrowser>& browser,
                                     CefRefPtr<CefFrame>& frame,
                                     CefRefPtr<CefContextMenuParams>& params,
                                     CefRefPtr<CefMenuModel>& model,
                                     CefRefPtr<CefRunContextMenuCallback>& callback)
{
  FLog();

  AcquireAndValidatePrivateHostWithReturn(privateHost, false);

  /** 离屏弹窗不走当前主视图的 Slate 菜单路径。 */
  if (browser->IsPopup()) {
    return false;
  }

  auto fid = Convert::FrameIdC2F(frame->GetIdentifier());
  FVector2D pos(params->GetXCoord(), params->GetYCoord());
  privateHost->OnRunCefContextMenu(fid, model, pos, callback);

  return true;
}

bool
CCefClientDelegate::onContextMenuCommand(CefRefPtr<CefBrowser>& browser,
                                         CefRefPtr<CefFrame>& frame,
                                         CefRefPtr<CefContextMenuParams>& params,
                                         int command_id,
                                         CefContextMenuHandler::EventFlags event_flags)
{
  FLog();

  return false;
}

void
CCefClientDelegate::onContextMenuDismissed(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame)
{
  FLog();

  AcquireAndValidatePrivateHost(privateHost);

  auto fid = Convert::FrameIdC2F(frame->GetIdentifier());
  privateHost->OnCefContextMenuDismissed(fid);
}
