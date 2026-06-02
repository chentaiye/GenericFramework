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

///
/// Called to retrieve the root window rectangle in screen DIP coordinates.
/// Return true if the rectangle was provided. If this method returns false
/// the rectangle from GetViewRect will be used.
///
bool
CCefClientDelegate::getRootScreenRect(CefRefPtr<CefBrowser>& browser, CefRect& rect)
{
  return false;
}

///
/// Called to retrieve the view rectangle in screen DIP coordinates. This
/// method must always provide a non-empty rectangle.
///
void
CCefClientDelegate::getViewRect(CefRefPtr<CefBrowser>& browser, CefRect& rect)
{
  rect.Set(0, 0, 1, 1);

  AcquireAndValidatePrivateHost(privateHost);

  auto size = privateHost->CachedGeometry.GetLocalSize();
  rect.Set(0, 0, size.X > 0 ? size.X : 1, size.Y > 0 ? size.Y : 1);
}

///
/// Called to retrieve the translation from view DIP coordinates to screen
/// coordinates. Windows/Linux should provide screen device (pixel)
/// coordinates and MacOS should provide screen DIP coordinates. Return true
/// if the requested coordinates were provided.
///
bool
CCefClientDelegate::getScreenPoint(CefRefPtr<CefBrowser>& browser, int viewX, int viewY, int& screenX, int& screenY)
{
  return false;
}

///
/// Called to allow the client to fill in the CefScreenInfo object with
/// appropriate values. Return true if the |screen_info| structure has been
/// modified.
///
/// If the screen info rectangle is left empty the rectangle from GetViewRect
/// will be used. If the rectangle is still empty or invalid popups may not be
/// drawn correctly.
///
bool
CCefClientDelegate::getScreenInfo(CefRefPtr<CefBrowser>& browser, CefScreenInfo& screen_info)
{
  AcquireAndValidatePrivateHostWithReturn(privateHost, false);

  screen_info.depth = 32;
  if (privateHost->CachedScaleFactor > 0) {
    screen_info.device_scale_factor = privateHost->CachedScaleFactor;
  } else {
    screen_info.device_scale_factor = 1.0f;
  }

  return true;
}

void
CCefClientDelegate::onPopupShow(CefRefPtr<CefBrowser>& browser, bool show)
{
  FLog();

  AcquireAndValidatePrivateHost(privateHost);

  privateHost->bIsCefPopupShowing = show;
}

void
CCefClientDelegate::onPopupSize(CefRefPtr<CefBrowser>& browser, const CefRect& rect)
{
  FLog();

  AcquireAndValidatePrivateHost(privateHost);

  privateHost->CefPopupFrameRect = FIntRect(rect.x, rect.y, rect.width, rect.height);
}

void
CCefClientDelegate::onPaint(CefRefPtr<CefBrowser>& browser,
                            CefRenderHandler::PaintElementType type,
                            const CefRenderHandler::RectList& dirtyRects,
                            const void* buffer,
                            int width,
                            int height)
{
  AcquireAndValidatePrivateHost(privateHost);

  FIntRect region;
  for (auto& rect : dirtyRects) {
    region.Union(FIntRect(rect.x, rect.y, rect.x + rect.width, rect.y + rect.height));
  }

  if (PET_VIEW == type) {
    privateHost->OnOsrUpdateViewFromPixelBuffer(buffer, width, height, region);
  } else if (PET_POPUP == type) {
    privateHost->OnOsrUpdatePopupFromPixelBuffer(buffer, width, height, region);
  } else {
  }
}

///
/// Called when an element has been rendered to the shared texture handle.
/// |type| indicates whether the element is the view or the popup widget.
/// |dirtyRects| contains the set of rectangles in pixel coordinates that need
/// to be repainted. |info| contains the shared handle; on Windows it is a
/// HANDLE to a texture that can be opened with D3D11 OpenSharedResource, on
/// macOS it is an IOSurface pointer that can be opened with Metal or OpenGL,
/// and on Linux it contains several planes, each with an fd to the underlying
/// system native buffer.
///
/// The underlying implementation uses a pool to deliver frames. As a result,
/// the handle may differ every frame depending on how many frames are
/// in-progress. The handle's resource cannot be cached and cannot be accessed
/// outside of this callback. It should be reopened each time this callback is
/// executed and the contents should be copied to a texture owned by the
/// client application. The contents of |info| will be released back to the
/// pool after this callback returns.
///
#if CEF_VERSION_MAJOR < 125
//
// For CEF version below 125, hardware acceleration is not supported officially.
// You need to compile your own CEF with a patch applied. Please refer to:
// https://www.magpcss.org/ceforum/viewtopic.php?f=6&t=17551
// You need to build CEF/Chromium locally and apply this PR:
// https://bitbucket.org/chromiumembedded/cef/pull-requests/285
//
void
CCefClientDelegate::onAcceleratedPaint(CefRefPtr<CefBrowser> browser,
                                       CefRenderHandler::PaintElementType type,
                                       const CefRenderHandler::RectList& dirtyRects,
                                       void* shared_handle)
{
  AcquireAndValidatePrivateHost(privateHost);

  FIntRect region;
  for (auto& rect : dirtyRects) {
    region.Union(FIntRect(rect.x, rect.y, rect.width, rect.height));
  }

  if (PET_VIEW == type) {
    privateHost->OnOsrUpdateViewFromSharedTexture(info.shared_texture_handle, 0, region);
  } else if (PET_POPUP == type) {
    privateHost->OnOsrUpdatePopupFromSharedTexture(info.shared_texture_handle, 0, region);
  } else {
  }
}
#else
void
CCefClientDelegate::onAcceleratedPaint(CefRefPtr<CefBrowser>& browser,
                                       CefRenderHandler::PaintElementType type,
                                       const CefRenderHandler::RectList& dirtyRects,
                                       const CefAcceleratedPaintInfo& info)
{
  AcquireAndValidatePrivateHost(privateHost);

  FIntRect region;
  for (auto& rect : dirtyRects) {
    region.Union(FIntRect(rect.x, rect.y, rect.x + rect.width, rect.y + rect.height));
  }

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
  if (PET_VIEW == type) {
    privateHost->OnOsrUpdateViewFromSharedTexture(info.shared_texture_handle, info.format, region);
  } else if (PET_POPUP == type) {
    privateHost->OnOsrUpdatePopupFromSharedTexture(info.shared_texture_handle, info.format, region);
  } else {
  }
#elif defined(PLATFORM_MAC) && PLATFORM_MAC
  if (PET_VIEW == type) {
    privateHost->OnOsrUpdateViewFromSharedTexture(info.shared_texture_io_surface, info.format, region);
  } else if (PET_POPUP == type) {
    privateHost->OnOsrUpdatePopupFromSharedTexture(info.shared_texture_io_surface, info.format, region);
  } else {
  }
#elif defined(PLATFORM_LINUX) && PLATFORM_LINUX
#else
#endif
}
#endif

bool
CCefClientDelegate::startDragging(CefRefPtr<CefBrowser>& browser,
                                  CefRefPtr<CefDragData>& drag_data,
                                  CefRenderHandler::DragOperationsMask allowed_ops,
                                  int x,
                                  int y)
{
  FLog();

  AcquireAndValidatePrivateHostWithReturn(privateHost, false);

  return privateHost->ShouldAllowDrag(drag_data, allowed_ops, x, y);
}

void
CCefClientDelegate::updateDragCursor(CefRefPtr<CefBrowser>& browser, CefRenderHandler::DragOperation operation)
{
  AcquireAndValidatePrivateHost(privateHost);

  privateHost->UpdateDragOperation(operation);
}

void
CCefClientDelegate::onScrollOffsetChanged(CefRefPtr<CefBrowser>& browser, double x, double y)
{
}

void
CCefClientDelegate::onImeCompositionRangeChanged(CefRefPtr<CefBrowser>& browser,
                                                 const CefRange& selected_range,
                                                 const CefRenderHandler::RectList& character_bounds)
{
  AcquireAndValidatePrivateHost(privateHost);

  TArray<FIntRect> charBounds;
  for (auto& b : character_bounds) {
    charBounds.Add(FIntRect(b.x, b.y, b.x + b.width, b.y + b.height));
  }

  privateHost->OnCefImeCompositionRangeChanged(FVector2D(selected_range.from, selected_range.to), charBounds);
}

void
CCefClientDelegate::onTextSelectionChanged(CefRefPtr<CefBrowser>& browser,
                                           const CefString& selected_text,
                                           const CefRange& selected_range)
{
  AcquireAndValidatePrivateHost(privateHost);

  auto text = Convert::StringC2F(selected_text);
  privateHost->OnCefTextSelectionChanged(text, FVector2D(selected_range.from, selected_range.to));
}

void
CCefClientDelegate::onVirtualKeyboardRequested(CefRefPtr<CefBrowser>& browser,
                                               CefRenderHandler::TextInputMode input_mode)
{
  AcquireAndValidatePrivateHost(privateHost);

  privateHost->OnCefVirtualKeyboardRequested(input_mode);
}
