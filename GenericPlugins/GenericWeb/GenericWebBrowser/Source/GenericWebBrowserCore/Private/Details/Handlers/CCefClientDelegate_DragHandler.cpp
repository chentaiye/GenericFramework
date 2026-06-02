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

bool
CCefClientDelegate::onDragEnter(CefRefPtr<CefBrowser>& browser,
                                CefRefPtr<CefDragData>& dragData,
                                CefDragHandler::DragOperationsMask mask)
{
  AcquireAndValidatePrivateHostWithReturn(privateHost, true);

  /** CEF 约定返回 true 表示取消拖入，因此这里取反宿主 Drop 许可。 */
  return !privateHost->ShouldAllowDrop(dragData, mask);
}

void
CCefClientDelegate::draggableRegionChanged(CefRefPtr<CefBrowser>& browser,
                                           CefRefPtr<CefFrame>& frame,
                                           const std::vector<CefDraggableRegion>& regions)
{
  AcquireAndValidatePrivateHost(privateHost);
}
