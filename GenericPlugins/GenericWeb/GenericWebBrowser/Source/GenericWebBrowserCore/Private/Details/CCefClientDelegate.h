//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Templates/SharedPointer.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <string>
#include <vector>
#pragma endregion

#pragma region <Thirdparty Headers>
#include "HeadersCefViewCore.h"
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#pragma endregion

#define AcquireAndValidatePrivateHost(p)                                                                               \
  auto p = pSCefViewPrivate_.Pin();                                                                                    \
  if (!p || !p->pCefBrowser || !browser->IsSame(p->pCefBrowser)) {                                                     \
    return;                                                                                                            \
  }

#define AcquireAndValidatePrivateHostWithReturn(p, r)                                                                  \
  auto p = pSCefViewPrivate_.Pin();                                                                                    \
  if (!p || !p->pCefBrowser || !browser->IsSame(p->pCefBrowser)) {                                                     \
    return r;                                                                                                          \
  }

class SCefViewPrivate;

/** 接入 CEF Browser Client 级回调，并把事件分发回对应的 SCefViewPrivate。 */
class CCefClientDelegate
  : public CefViewBrowserClientDelegateInterface
  , public std::enable_shared_from_this<CCefClientDelegate>
{
public:
  typedef std::shared_ptr<CCefClientDelegate> RefPtr;
  typedef std::weak_ptr<CCefClientDelegate> WeakPtr;

private:
  /** 弱引用所属 Slate CEF 视图私有实现，防止 CEF 回调延长控件生命周期。 */
  TWeakPtr<SCefViewPrivate> pSCefViewPrivate_;

public:
  CCefClientDelegate(TSharedRef<SCefViewPrivate> p);

  ~CCefClientDelegate();

  virtual void processUrlRequest(CefRefPtr<CefBrowser>& browser,
                                 CefRefPtr<CefFrame>& frame,
                                 const CefString& url) override;

  virtual void processQueryRequest(CefRefPtr<CefBrowser>& browser,
                                   CefRefPtr<CefFrame>& frame,
                                   const CefString& query,
                                   const int64_t query_id) override;

  virtual void invokeMethodNotify(CefRefPtr<CefBrowser>& browser,
                                  CefRefPtr<CefFrame>& frame,
                                  const CefString& method,
                                  const CefRefPtr<CefListValue>& arguments) override;
  virtual void reportJSResult(CefRefPtr<CefBrowser>& browser,
                              CefRefPtr<CefFrame>& frame,
                              const CefString& context,
                              const CefRefPtr<CefValue>& result) override;

  virtual void focusedEditableNodeChanged(CefRefPtr<CefBrowser>& browser,
                                          CefRefPtr<CefFrame>& frame,
                                          bool focusOnEditableNode) override;

  /** CEF 上下文菜单回调分组。 */
#pragma region ContextMenuHandler
  virtual void onBeforeContextMenu(CefRefPtr<CefBrowser>& browser,
                                   CefRefPtr<CefFrame>& frame,
                                   CefRefPtr<CefContextMenuParams>& params,
                                   CefRefPtr<CefMenuModel>& model) override;

  virtual bool onRunContextMenu(CefRefPtr<CefBrowser>& browser,
                                CefRefPtr<CefFrame>& frame,
                                CefRefPtr<CefContextMenuParams>& params,
                                CefRefPtr<CefMenuModel>& model,
                                CefRefPtr<CefRunContextMenuCallback>& callback) override;

  virtual bool onContextMenuCommand(CefRefPtr<CefBrowser>& browser,
                                    CefRefPtr<CefFrame>& frame,
                                    CefRefPtr<CefContextMenuParams>& params,
                                    int command_id,
                                    CefContextMenuHandler::EventFlags event_flags) override;
  virtual void onContextMenuDismissed(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame) override;
#pragma endregion

  /** CEF 文件对话框回调分组。 */
#pragma region DialogHandler
  virtual bool onFileDialog(CefRefPtr<CefBrowser>& browser,
                            CefBrowserHost::FileDialogMode mode,
                            const CefString& title,
                            const CefString& default_file_path,
                            const std::vector<CefString>& accept_filters,
#if CEF_VERSION_MAJOR < 102
                            int selected_accept_filter,
#endif
                            CefRefPtr<CefFileDialogCallback>& callback) override;
#pragma endregion

  /** CEF 页面显示状态回调分组。 */
#pragma region DisplayHandler
  virtual void addressChanged(CefRefPtr<CefBrowser>& browser,
                              CefRefPtr<CefFrame>& frame,
                              const CefString& url) override;
  virtual void titleChanged(CefRefPtr<CefBrowser>& browser, const CefString& title) override;
  virtual void faviconURLChanged(CefRefPtr<CefBrowser>& browser, const std::vector<CefString>& icon_urls) override;
  virtual void fullscreenModeChanged(CefRefPtr<CefBrowser>& browser, bool fullscreen) override;
  virtual bool tooltipMessage(CefRefPtr<CefBrowser>& browser, const CefString& text) override;
  virtual void statusMessage(CefRefPtr<CefBrowser>& browser, const CefString& value) override;
  virtual void consoleMessage(CefRefPtr<CefBrowser>& browser, const CefString& message, int level) override;
  virtual void loadingProgressChanged(CefRefPtr<CefBrowser>& browser, double progress) override;
  virtual bool cursorChanged(CefRefPtr<CefBrowser>& browser,
                             CefCursorHandle cursor,
                             cef_cursor_type_t type,
                             const CefCursorInfo& custom_cursor_info) override;
#pragma endregion

  /** CEF 下载回调分组。 */
#pragma region DownloadHander
  virtual void onBeforeDownload(CefRefPtr<CefBrowser>& browser,
                                CefRefPtr<CefDownloadItem>& download_item,
                                const CefString& suggested_name,
                                CefRefPtr<CefBeforeDownloadCallback>& callback) override;

  virtual void onDownloadUpdated(CefRefPtr<CefBrowser>& browser,
                                 CefRefPtr<CefDownloadItem>& download_item,
                                 CefRefPtr<CefDownloadItemCallback>& callback) override;
#pragma endregion

  /** CEF 拖拽回调分组。 */
#pragma region DragHandler
  virtual bool onDragEnter(CefRefPtr<CefBrowser>& browser,
                           CefRefPtr<CefDragData>& dragData,
                           CefDragHandler::DragOperationsMask mask) override;
  virtual void draggableRegionChanged(CefRefPtr<CefBrowser>& browser,
                                      CefRefPtr<CefFrame>& frame,
                                      const std::vector<CefDraggableRegion>& regions) override;
#pragma endregion

  /** CEF 焦点回调分组。 */
#pragma region FocusHandler
  virtual void takeFocus(CefRefPtr<CefBrowser>& browser, bool next) override;
  virtual bool setFocus(CefRefPtr<CefBrowser>& browser) override;
  virtual void gotFocus(CefRefPtr<CefBrowser>& browser) override;
#pragma endregion

  /** CEF JavaScript 对话框回调分组。 */
#pragma region JSDialogHandler
  virtual bool onJSDialog(CefRefPtr<CefBrowser>& browser,
                          const CefString& origin_url,
                          CefJSDialogHandler::JSDialogType dialog_type,
                          const CefString& message_text,
                          const CefString& default_prompt_text,
                          CefRefPtr<CefJSDialogCallback>& callback,
                          bool& suppress_message) override;
  virtual bool onBeforeUnloadDialog(CefRefPtr<CefBrowser>& browser,
                                    const CefString& message_text,
                                    bool is_reload,
                                    CefRefPtr<CefJSDialogCallback>& callback) override;
  virtual void onResetDialogState(CefRefPtr<CefBrowser>& browser) override;
  virtual void onDialogClosed(CefRefPtr<CefBrowser>& browser) override;
#pragma endregion

  /** CEF 键盘输入回调分组。 */
#pragma region KeyboardHandler
  virtual bool onPreKeyEvent(CefRefPtr<CefBrowser>& browser,
                             const CefKeyEvent& event,
                             CefEventHandle os_event,
                             bool* is_keyboard_shortcut) override;
  virtual bool onKeyEvent(CefRefPtr<CefBrowser>& browser, const CefKeyEvent& event, CefEventHandle os_event) override;
#pragma endregion

  /** CEF 浏览器生命周期回调分组。 */
#pragma region LifeSpanHandler
  virtual bool onBeforePopup(CefRefPtr<CefBrowser>& browser,
                             CefRefPtr<CefFrame>& frame,
                             const CefString& targetUrl,
                             const CefString& targetFrameName,
                             CefLifeSpanHandler::WindowOpenDisposition targetDisposition,
                             CefWindowInfo& windowInfo,
                             CefBrowserSettings& settings,
                             bool& disableJavascriptAccess) override;
  virtual void onAfterCreate(CefRefPtr<CefBrowser>& browser) override;
  virtual bool doClose(CefRefPtr<CefBrowser>& browser) override;
  virtual bool requestClose(CefRefPtr<CefBrowser>& browser) override;
  virtual void onBeforeClose(CefRefPtr<CefBrowser>& browser) override;
#pragma endregion

  /** CEF 页面加载回调分组。 */
#pragma region LoadHandler
  virtual void loadingStateChanged(CefRefPtr<CefBrowser>& browser,
                                   bool isLoading,
                                   bool canGoBack,
                                   bool canGoForward) override;
  virtual void loadStart(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame, int transitionType) override;
  virtual void loadEnd(CefRefPtr<CefBrowser>& browser, CefRefPtr<CefFrame>& frame, int httpStatusCode) override;
  virtual void loadError(CefRefPtr<CefBrowser>& browser,
                         CefRefPtr<CefFrame>& frame,
                         int errorCode,
                         const CefString& errorMsg,
                         const CefString& failedUrl,
                         bool& handled) override;
#pragma endregion

  /** CEF 离屏渲染回调分组。 */
#pragma region RenderHandler
  virtual bool getRootScreenRect(CefRefPtr<CefBrowser>& browser, CefRect& rect) override;
  virtual void getViewRect(CefRefPtr<CefBrowser>& browser, CefRect& rect) override;
  virtual bool getScreenPoint(CefRefPtr<CefBrowser>& browser,
                              int viewX,
                              int viewY,
                              int& screenX,
                              int& screenY) override;
  virtual bool getScreenInfo(CefRefPtr<CefBrowser>& browser, CefScreenInfo& screen_info) override;
  virtual void onPopupShow(CefRefPtr<CefBrowser>& browser, bool show) override;
  virtual void onPopupSize(CefRefPtr<CefBrowser>& browser, const CefRect& rect) override;
  virtual void onPaint(CefRefPtr<CefBrowser>& browser,
                       CefRenderHandler::PaintElementType type,
                       const CefRenderHandler::RectList& dirtyRects,
                       const void* buffer,
                       int width,
                       int height) override;
#if CEF_VERSION_MAJOR < 124
  virtual void onAcceleratedPaint(CefRefPtr<CefBrowser>& browser,
                                  CefRenderHandler::PaintElementType type,
                                  const CefRenderHandler::RectList& dirtyRects,
                                  void* shared_handle) override;
#else
  virtual void onAcceleratedPaint(CefRefPtr<CefBrowser>& browser,
                                  CefRenderHandler::PaintElementType type,
                                  const CefRenderHandler::RectList& dirtyRects,
                                  const CefAcceleratedPaintInfo& info) override;
#endif
  virtual bool startDragging(CefRefPtr<CefBrowser>& browser,
                             CefRefPtr<CefDragData>& drag_data,
                             CefRenderHandler::DragOperationsMask allowed_ops,
                             int x,
                             int y) override;
  virtual void updateDragCursor(CefRefPtr<CefBrowser>& browser, CefRenderHandler::DragOperation operation) override;
  virtual void onScrollOffsetChanged(CefRefPtr<CefBrowser>& browser, double x, double y) override;
  virtual void onImeCompositionRangeChanged(CefRefPtr<CefBrowser>& browser,
                                            const CefRange& selected_range,
                                            const CefRenderHandler::RectList& character_bounds) override;
  virtual void onTextSelectionChanged(CefRefPtr<CefBrowser>& browser,
                                      const CefString& selected_text,
                                      const CefRange& selected_range) override;
  virtual void onVirtualKeyboardRequested(CefRefPtr<CefBrowser>& browser,
                                          CefRenderHandler::TextInputMode input_mode) override;
#pragma endregion
};
