//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "GenericWebBrowserCore/Public/Slate/SCefView.h"
#pragma endregion

#pragma region <Engine Headers>
// CoreUObject/Public/
#include <UObject/Class.h>
#include <UObject/UnrealType.h>
// Json/Public/
#include <Dom/JsonValue.h>
#include <Dom/JsonObject.h>
#include <Serialization/JsonReader.h>
#include <Serialization/JsonSerializer.h>
// Slate/Public/
#include <SlateOptMacros.h>
#include <Framework/Application/SlateApplication.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#include "SlateCefContextPrivate.h"
#include "Common/Log.h"
#include "Common/Convert.h"
#include "SCefViewPrivate.h"
#pragma endregion

using namespace Common;

namespace
{
bool IsSlateVisibilityRendered(EVisibility InVisibility)
{
  return InVisibility != EVisibility::Collapsed && InVisibility != EVisibility::Hidden;
}
}

#if CEF_VERSION_MAJOR < 122
const FCefFrameId SCefView::MainFrameID = 0;
const FCefFrameId SCefView::AllFrameID = -1;
#else
const FCefFrameId SCefView::MainFrameID = TEXT("0");
const FCefFrameId SCefView::AllFrameID = TEXT("-1");
#endif

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

SLATE_IMPLEMENT_WIDGET(SCefView)

void
SCefView::PrivateRegisterAttributes(FSlateAttributeInitializer& AttributeInitializer)
{
}

SCefView::SCefView()
  : SWidget()
{
}

SCefView::~SCefView()
{
  if (m_pImpl) {
    m_pImpl->Uninitialize();
  }
  m_pImpl.Reset();

  logDebug() << "SCefView destructed";
}

#define FARGS_ASSIGN_FIELD(f) f = InArgs._##f

void
SCefView::Construct(const FArguments& InArgs)
{
  FARGS_ASSIGN_FIELD(Url);
  FARGS_ASSIGN_FIELD(bEnableContextMenu);
  FARGS_ASSIGN_FIELD(bAcceptDrops);
  FARGS_ASSIGN_FIELD(bAllowDrag);
  FARGS_ASSIGN_FIELD(bEnableAlphaHitTestPassthrough);
  FARGS_ASSIGN_FIELD(AlphaHitTestThreshold);

  FARGS_ASSIGN_FIELD(OnLoadStateChanged);
  FARGS_ASSIGN_FIELD(OnLoadStart);
  FARGS_ASSIGN_FIELD(OnLoadEnd);
  FARGS_ASSIGN_FIELD(OnLoadError);
  FARGS_ASSIGN_FIELD(OnDraggableRegionChanged);
  FARGS_ASSIGN_FIELD(OnAddressChanged);
  FARGS_ASSIGN_FIELD(OnTitleChanged);
  FARGS_ASSIGN_FIELD(OnFaviconUrlChanged);
  FARGS_ASSIGN_FIELD(OnFullscreenModeChanged);
  FARGS_ASSIGN_FIELD(OnStatusMessage);
  FARGS_ASSIGN_FIELD(OnConsoleMessage);
  FARGS_ASSIGN_FIELD(OnLoadingProgressChanged);
  FARGS_ASSIGN_FIELD(OnUrlRequest);
  FARGS_ASSIGN_FIELD(OnQueryRequest);
  FARGS_ASSIGN_FIELD(OnInvokeMethod);
  FARGS_ASSIGN_FIELD(OnReportJavascriptResult);
  FARGS_ASSIGN_FIELD(OnNativeBrowserCreated);
  FARGS_ASSIGN_FIELD(OnCreateNewBrowser);
  RequestedVisibility = EVisibility::Visible;
  bIsAlphaInputPassthroughActive = false;

  m_pImpl = MakeShared<SCefViewPrivate>(SharedThis(this));
  m_pImpl->Initialize(InArgs._Settings);
}

void
SCefView::SetUrl(const FString& InUrl)
{
  if (Url != InUrl) {
    Url = InUrl;
    if (m_pImpl) {
      m_pImpl->NavigateToUrl(Url);
    }
  }
}

FString
SCefView::GetUrl() const
{
  return Url;
}

void
SCefView::SetEnableContextMenu(bool bInEnableContextMenu)
{
  bEnableContextMenu = bInEnableContextMenu;
}

bool
SCefView::IsContextMenuEnabled() const
{
  return bEnableContextMenu;
}

void
SCefView::SetAcceptDrops(bool bInAcceptDrops)
{
  bAcceptDrops = bInAcceptDrops;
}

bool
SCefView::IsAcceptDrops() const
{
  return bAcceptDrops;
}

void
SCefView::SetAllowDrag(bool bInAllowDrag)
{
  bAllowDrag = bInAllowDrag;
}

bool
SCefView::IsAllowDrag() const
{
  return bAllowDrag;
}

void
SCefView::SetEnableAlphaHitTestPassthrough(bool bInEnableAlphaHitTestPassthrough)
{
  bEnableAlphaHitTestPassthrough = bInEnableAlphaHitTestPassthrough;

  if (!bEnableAlphaHitTestPassthrough) {
    SetAlphaInputPassthroughActive(false);
  } else {
    UpdateResolvedVisibility();
  }
}

bool
SCefView::IsAlphaHitTestPassthroughEnabled() const
{
  return bEnableAlphaHitTestPassthrough;
}

void
SCefView::SetAlphaHitTestThreshold(uint8 InAlphaHitTestThreshold)
{
  AlphaHitTestThreshold = InAlphaHitTestThreshold;
}

uint8
SCefView::GetAlphaHitTestThreshold() const
{
  return AlphaHitTestThreshold;
}

void
SCefView::CreateNativeBrowser(const FSlateCefViewSettings& InCefViewSettings)
{
  if (m_pImpl) {
    m_pImpl->CreateCefBrowser(InCefViewSettings);
  }
}

void
SCefView::DestroyNativeBrowser()
{
  if (m_pImpl) {
    m_pImpl->DestroyCefBrowser();
  }
}

void
SCefView::AddLocalFolderResource(const FString& InFolderPath, const FString& InTargetUrl, int32 InPriority /*= 0*/)
{
  if (m_pImpl->pCefBrowser) {
    m_pImpl->pCefClient->AddLocalDirectoryResourceProvider(
      Convert::StringF2C(InFolderPath), Convert::StringF2C(InTargetUrl), InPriority);
  }
}

void
SCefView::AddArchiveFileResource(const FString& InArchivePath,
                                 const FString& InTargetUrl,
                                 const FString& InPassword /*= ""*/,
                                 int32 InPriority /*= 0*/)
{
  if (m_pImpl->pCefBrowser) {
    m_pImpl->pCefClient->AddArchiveResourceProvider(
      Convert::StringF2C(InArchivePath), Convert::StringF2C(InTargetUrl), Convert::StringF2C(InPassword), InPriority);
  }
}

int64
SCefView::GetBrowserId() const
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->pCefBrowser->GetIdentifier();
  }
  return 0;
}

bool
SCefView::BrowserCanGoBack()
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->pCefBrowser->CanGoBack();
  }
  return false;
}

bool
SCefView::BrowserCanGoForward()
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->pCefBrowser->CanGoForward();
  }
  return false;
}

void
SCefView::BrowserGoBack()
{
  if (m_pImpl->pCefBrowser) {
    m_pImpl->pCefBrowser->GoBack();
    m_pImpl->pCefBrowser->GetHost()->WasResized();
  }
}

void
SCefView::BrowserGoForward()
{
  if (m_pImpl->pCefBrowser) {
    m_pImpl->pCefBrowser->GoForward();
    m_pImpl->pCefBrowser->GetHost()->WasResized();
  }
}

bool
SCefView::IsBrowserLoading()
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->pCefBrowser->IsLoading();
  }
  return false;
}

void
SCefView::BrowserReload()
{
  if (m_pImpl->pCefBrowser) {
    m_pImpl->pCefBrowser->Reload();
  }
}

void
SCefView::BrowserStopLoad()
{
  if (m_pImpl->pCefBrowser) {
    m_pImpl->pCefBrowser->StopLoad();
  }
}

bool
SCefView::TriggerEventForFrame(const FString& InName,
                               const TArray<TSharedPtr<FJsonValue>>& InArgs,
                               const FCefFrameId& InFrameId)
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->TriggerCefEvent(InName, InArgs, InFrameId);
  }
  return false;
}

bool
SCefView::TriggerEventForMainFrame(const FString& InName, const TArray<TSharedPtr<FJsonValue>>& InArgs)
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->TriggerCefEvent(InName, InArgs, SCefView::MainFrameID);
  }
  return false;
}

bool
SCefView::BroadcastEvent(const FString& InName, const TArray<TSharedPtr<FJsonValue>>& InArgs)
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->TriggerCefEvent(InName, InArgs, SCefView::AllFrameID);
  }
  return false;
}

bool
SCefView::ResponseUCefQuery(const int64 InQueryId,
                            const bool bInIsSuccess,
                            const FString& InResponse,
                            const int32 InError)
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->ResponseCefQuery(InQueryId, bInIsSuccess, InResponse, InError);
  }
  return false;
}

bool
SCefView::ExecuteJavascript(const FCefFrameId& InFrameId, const FString& InJavascriptCode, const FString& InTargetUrl)
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->ExecuteJavascript(InFrameId, InJavascriptCode, InTargetUrl);
  }
  return false;
}

bool
SCefView::ExecuteJavascriptWithResult(const FCefFrameId& InFrameId,
                                      const FString& InJavascriptCode,
                                      const FString& InTargetUrl,
                                      const FString& InExecuteContext)
{
  if (m_pImpl->pCefBrowser) {
    return m_pImpl->ExecuteJavascriptWithResult(InFrameId, InJavascriptCode, InTargetUrl, InExecuteContext);
  }
  return false;
}

bool
SCefView::SetPreference(const FString& InPreferenceName, const FString& InPreferenceValue, FString& OutError)
{
  if (m_pImpl->pCefBrowser) {
    TSharedPtr<FJsonValue> JsonValue;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InPreferenceValue);
    if (FJsonSerializer::Deserialize(Reader, JsonValue) && JsonValue.IsValid()) {
      return m_pImpl->SetPreference(InPreferenceName, JsonValue, OutError);
    }
  }
  return false;
}

void
SCefView::SetDisablePopupContextMenu(bool bInIsDisable)
{
}

bool
SCefView::IsPopupContextMenuDisabled()
{
  return false;
}

bool
SCefView::HasDevTools()
{
  return false;
}

void
SCefView::ShowDevTools()
{
}

void
SCefView::CloseDevTools()
{
}

void
SCefView::OnNewBrowser(const FCefFrameId& InSourceFrameId,
                       const FString& InTargetUrl,
                       const FString& InFrameName,
                       const ECefWindowOpenDisposition& InTargetDisposition,
                       const FIntRect& InDesiredRect)
{
  FLog();

  OnCreateNewBrowser.ExecuteIfBound(InSourceFrameId, InTargetUrl, InFrameName, InTargetDisposition, InDesiredRect);
}

bool
SCefView::OnNewPopup(const FCefFrameId& InSourceFrameId,
                     const FString& InTargetUrl,
                     FString& InFrameName,
                     ECefWindowOpenDisposition InTargetDisposition,
                     FIntRect& InDesiredRect,
                     FSlateCefViewSettings& InBrowserSettings,
                     bool& bInDisableJavascriptAccess)
{
  FLog();
  return false;
}

bool
SCefView::OnRequestCloseFromWeb()
{
  FLog();
  return false;
}

void
SCefView::SetVisibility(TAttribute<EVisibility> InVisibility)
{
  RequestedVisibility = InVisibility.Get();
  if (RequestedVisibility != EVisibility::Visible) {
    bIsAlphaInputPassthroughActive = false;
  }

  UpdateResolvedVisibility();
}

void
SCefView::UpdateResolvedVisibility()
{
  EVisibility ResolvedVisibility = RequestedVisibility;
  if (RequestedVisibility == EVisibility::Visible && bEnableAlphaHitTestPassthrough && bIsAlphaInputPassthroughActive) {
    ResolvedVisibility = EVisibility::SelfHitTestInvisible;
  }

  if (ResolvedVisibility != GetVisibility() && m_pImpl) {
    m_pImpl->OnVisibilityEvent(IsSlateVisibilityRendered(ResolvedVisibility));
  }

  Super::SetVisibility(ResolvedVisibility);
}

bool
SCefView::ShouldPassthroughPointerInput(const FGeometry& InGeometry, const FVector2D& InLocalPos)
{
  if (!bEnableAlphaHitTestPassthrough || !m_pImpl || RequestedVisibility != EVisibility::Visible) {
    return false;
  }

  if (!FSlateApplication::IsInitialized()) {
    return false;
  }

  if (FSlateApplication::Get().GetPressedMouseButtons().Num() > 0) {
    return false;
  }

  return m_pImpl->ShouldPassthroughInput(InLocalPos, InGeometry.GetLocalSize(), AlphaHitTestThreshold);
}

void
SCefView::SetAlphaInputPassthroughActive(bool bInIsActive)
{
  if (bIsAlphaInputPassthroughActive == bInIsActive) {
    return;
  }

  bIsAlphaInputPassthroughActive = bInIsActive;
  UpdateResolvedVisibility();
}

void
SCefView::UpdateAlphaHitTestState(const FGeometry& InGeometry)
{
  if (!bEnableAlphaHitTestPassthrough || RequestedVisibility != EVisibility::Visible || !FSlateApplication::IsInitialized()) {
    SetAlphaInputPassthroughActive(false);
    return;
  }

  const FVector2D CursorPosition = FSlateApplication::Get().GetCursorPos();
  const FVector2D LocalPosition = InGeometry.AbsoluteToLocal(CursorPosition);
  SetAlphaInputPassthroughActive(ShouldPassthroughPointerInput(InGeometry, LocalPosition));
}

void
SCefView::Tick(const FGeometry& InAllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
  Super::Tick(InAllottedGeometry, InCurrentTime, InDeltaTime);
  if (m_pImpl) {
    m_pImpl->UpdateTick(InAllottedGeometry, InCurrentTime, InDeltaTime);
  }

  UpdateAlphaHitTestState(InAllottedGeometry);
}

FChildren*
SCefView::GetChildren()
{
  if (m_pImpl) {
    return &(m_pImpl->ChildrenOverlaySlot);
  }
  return &FNoChildren::NoChildrenInstance;
}

void
SCefView::OnArrangeChildren(const FGeometry& InAllottedGeometry, FArrangedChildren& InArrangedChildren) const
{
  if (m_pImpl) {
    m_pImpl->ArrangeChildren(InAllottedGeometry, InArrangedChildren);
  }
}

FVector2D
SCefView::ComputeDesiredSize(float InLayoutScaleMultiplier) const
{
  if (m_pImpl && m_pImpl->CefViewFrameTexture) {
    return FVector2D(                           //
      m_pImpl->CefViewFrameTexture->GetWidth(), //
      m_pImpl->CefViewFrameTexture->GetHeight() //
    );
  }
  return FVector2D::ZeroVector;
}

int32
SCefView::OnPaint(const FPaintArgs& InArgs,
                  const FGeometry& InAllottedGeometry,
                  const FSlateRect& InMyCullingRect,
                  FSlateWindowElementList& InOutDrawElements,
                  int32 InLayerId,
                  const FWidgetStyle& InWidgetStyle,
                  bool bInParentEnabled) const
{
  return m_pImpl->PaintWidget( //
    InArgs,
    InAllottedGeometry,
    InMyCullingRect,
    InOutDrawElements,
    InLayerId,
    InWidgetStyle,
    ShouldBeEnabled(bInParentEnabled));
}

TOptional<TSharedRef<SWidget>>
SCefView::OnMapCursor(const FCursorReply& InCursorReply) const
{
  if (GetCursor() == EMouseCursor::Custom && m_pImpl && m_pImpl->CustomCursorImage) {
    return TOptional<TSharedRef<SWidget>>(m_pImpl->CustomCursorImage.ToSharedRef());
  }

  return TOptional<TSharedRef<SWidget>>();
}

bool
SCefView::SupportsKeyboardFocus() const
{
  return true;
}

FReply
SCefView::OnFocusReceived(const FGeometry& InMyGeometry, const FFocusEvent& InFocusEvent)
{
  FLog();
  m_pImpl->OnFocusEvent(true, InFocusEvent);
  return FReply::Handled();
}

void
SCefView::OnFocusLost(const FFocusEvent& InFocusEvent)
{
  FLog();

  m_pImpl->OnFocusEvent(false, InFocusEvent);
}

FNavigationReply
SCefView::OnNavigation(const FGeometry& InGeometry, const FNavigationEvent& InNavigationEvent)
{
  FLog();
  return FNavigationReply::Escape();
}

void
SCefView::OnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  Super::OnMouseEnter(InGeometry, InMouseEvent);

  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return;
  }

  SetAlphaInputPassthroughActive(false);
  m_pImpl->OnMouseMoveEvent(InMouseEvent, LocalPosition, false);
}

void
SCefView::OnMouseLeave(const FPointerEvent& InMouseEvent)
{
  Super::OnMouseLeave(InMouseEvent);
  SetAlphaInputPassthroughActive(false);

  FVector2D LocalPosition = GetCachedGeometry().AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
  m_pImpl->OnMouseMoveEvent(InMouseEvent, LocalPosition, true);
}

FReply
SCefView::OnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnMouseMove(InGeometry, InMouseEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnMouseMoveEvent(InMouseEvent, LocalPosition, false);
  return FReply::Handled();
}

FReply
SCefView::OnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  return Super::OnPreviewMouseButtonDown(InGeometry, InMouseEvent);
}

FReply
SCefView::OnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnMouseButtonDown(InGeometry, InMouseEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnMouseButtonDownEvent(InMouseEvent, LocalPosition);
  return FReply::Handled();
}

FReply
SCefView::OnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnMouseButtonUp(InGeometry, InMouseEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnMouseButtonUpEvent(InMouseEvent, LocalPosition);
  return FReply::Handled();
}

FReply
SCefView::OnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  FLog();
  logDebug() << "======= OnMouseButtonDoubleClick:" << InMouseEvent.GetTouchForce();

  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnMouseButtonDoubleClick(InGeometry, InMouseEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnMouseButtonDoubleClickEvent(InMouseEvent, LocalPosition);
  return FReply::Handled();
}

FReply
SCefView::OnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnMouseWheel(InGeometry, InMouseEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnMouseWheelEvent(InMouseEvent, LocalPosition);
  return FReply::Handled();
}

FReply
SCefView::OnTouchGesture(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
  FLog();
  logDebug() << "======= OnTouchGesture:" << InGestureEvent.GetTouchForce();

  auto Reply = Super::OnTouchGesture(InGeometry, InGestureEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  return FReply::Unhandled();
}

FReply
SCefView::OnTouchStarted(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent)
{
  FLog();
  logDebug() << "======= OnTouchStarted:" << InTouchEvent.GetTouchForce();

  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InTouchEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnTouchStarted(InGeometry, InTouchEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnTouchStartedEvent(InTouchEvent, LocalPosition);
  return FReply::Handled();
}

FReply
SCefView::OnTouchFirstMove(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent)
{
  FLog();
  logDebug() << "======= OnTouchFirstMove:" << InTouchEvent.GetTouchForce();

  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InTouchEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnTouchFirstMove(InGeometry, InTouchEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnTouchMovedEvent(InTouchEvent, LocalPosition);
  return FReply::Handled();
}

FReply
SCefView::OnTouchMoved(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent)
{
  // FLog();
  // logDebug() << "======= OnTouchMoved:" << InTouchEvent.GetTouchForce();

  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InTouchEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnTouchMoved(InGeometry, InTouchEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnTouchMovedEvent(InTouchEvent, LocalPosition);
  return FReply::Handled();
}

FReply
SCefView::OnTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent)
{
  FLog();
  logDebug() << "======= OnTouchEnded:" << InTouchEvent.GetTouchForce();

  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InTouchEvent.GetScreenSpacePosition());
  if (ShouldPassthroughPointerInput(InGeometry, LocalPosition)) {
    SetAlphaInputPassthroughActive(true);
    return FReply::Unhandled();
  }

  SetAlphaInputPassthroughActive(false);
  auto Reply = Super::OnTouchEnded(InGeometry, InTouchEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  m_pImpl->OnTouchEndedEvent(InTouchEvent, LocalPosition);
  return FReply::Handled();
}

FReply
SCefView::OnTouchForceChanged(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent)
{
  FLog();
  logDebug() << "======= OnTouchForceChanged:" << InTouchEvent.GetTouchForce();

  auto Reply = Super::OnTouchForceChanged(InGeometry, InTouchEvent);
  if (Reply.IsEventHandled()) {
    return Reply;
  }

  return FReply::Unhandled();
}

FReply
SCefView::OnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
  FLog();
  logDebug() << "======= OnPreviewKeyDown:" << InKeyEvent.GetKey().GetDisplayName().ToString();
  return Super::OnPreviewKeyDown(InGeometry, InKeyEvent);
}

FReply
SCefView::OnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
  FLog();
  logDebug() << "======= OnKeyDown:" << InKeyEvent.GetKey().GetDisplayName().ToString();
  m_pImpl->OnKeyDownEvent(InKeyEvent);
  return FReply::Handled();
}

FReply
SCefView::OnKeyChar(const FGeometry& InGeometry, const FCharacterEvent& InCharacterEvent)
{
  FLog();
  logDebug() << "======= OnKeyChar:" << InCharacterEvent.GetCharacter();
  m_pImpl->OnKeyCharEvent(InCharacterEvent);
  return FReply::Handled();
}

FReply
SCefView::OnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
  FLog();
  logDebug() << "======= OnKeyUp:" << InKeyEvent.GetKey().GetDisplayName().ToString();
  m_pImpl->OnKeyUpEvent(InKeyEvent);
  return FReply::Handled();
}

void
SCefView::OnDragEnter(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent)
{
  FLog();
  logDebug() << "======= OnDragEnter:";
  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
  m_pImpl->OnDragEnter(InDragDropEvent, LocalPosition);
}

FReply
SCefView::OnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent)
{
  // FLog();
  // logDebug() << "======= OnDragOver:";
  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
  return m_pImpl->OnDragOver(InDragDropEvent, LocalPosition);
}

FReply
SCefView::OnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent)
{
  FLog();
  logDebug() << "======= OnDrop:";
  FVector2D LocalPosition = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
  return m_pImpl->OnDrop(InDragDropEvent, LocalPosition);
}

void
SCefView::OnDragLeave(const FDragDropEvent& InDragDropEvent)
{
  FLog();
  logDebug() << "======= OnDragLeave:";
  m_pImpl->OnDragLeave(InDragDropEvent);
}

FReply
SCefView::OnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  FLog();
  logDebug() << "======= OnDragDetected:";
  return m_pImpl->OnDragDetected(InGeometry, InMouseEvent);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
