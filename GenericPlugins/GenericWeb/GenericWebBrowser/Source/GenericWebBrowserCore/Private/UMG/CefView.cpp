//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "UMG/CefView.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Async/Async.h>
// Engine/Classes/
#include <Engine/Engine.h>
#include <Engine/Texture2D.h>
// Json/Public/
#include <Serialization/JsonSerializer.h>
#include <Serialization/JsonWriter.h>
// Slate/Public/
#include <Widgets/Layout/SBox.h>
#include <Widgets/Text/STextBlock.h>
// SlateCore/Public/
#include <Rendering/SlateRenderer.h>
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

#pragma region "Project Private headers"
#include "Common/Convert.h"
#include "Common/Log.h"
#pragma endregion

using namespace Common;

#if CEF_VERSION_MAJOR < 122
const FCefFrameId UCefView::MainFrameID = 0;
const FCefFrameId UCefView::AllFrameID = -1;
#else
const FCefFrameId UCefView::MainFrameID = TEXT("0");
const FCefFrameId UCefView::AllFrameID = TEXT("-1");
#endif

UCefView::UCefView()
{
  FLog();
}

UCefView::~UCefView()
{
  if (SlateCefView) {
    SlateCefView.Reset();
  }
  logDebug() << "UCefView destructed";
}

#define BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(x)                                                                     \
  On##x(SCefView::FOn##x##Event::CreateUObject(this, &UCefView::OnSlate##x##Event))

#define COPY_PROPRETY_TO_STRUCT(s, p, u) s.p = u.p

TSharedRef<SWidget>
UCefView::RebuildWidget()
{
  FLog();

  /** UMG 重建阶段必须先确保进程级 CEF 上下文可用，否则只返回设计时占位控件。 */
  UCefContext* CefContext = GEngine->GetEngineSubsystem<UCefContext>();
  if (IsDesignTime()                      //
      || !CefContext                      //
      || !CefContext->EnsureCefInitialized() //
  ) {
    return SNew(SBox)
      .HAlign(HAlign_Center)
      .VAlign(VAlign_Center)[                                   //
        SNew(STextBlock)                                        //
          .Font(FCoreStyle::GetDefaultFontStyle("Regular", 64)) //
          .Text(FText::FromString(TEXT("CefView")))             //
    ];
  } else {
    FSlateCefViewSettings SlateCefViewSettings;
    SlateCefViewSettings.DefaultFontSize = Settings.DefaultFontSize;
    SlateCefViewSettings.DefaultFixedFontSize = Settings.DefaultFixedFontSize;
    SlateCefViewSettings.MinimumFontSize = Settings.MinimumFontSize;
    SlateCefViewSettings.MinimumLogicalFontSize = Settings.MinimumLogicalFontSize;
    SlateCefViewSettings.BackgroundColor = Settings.BackgroundColor;
    SlateCefViewSettings.StandardFontFamily = Settings.StandardFontFamily;
    SlateCefViewSettings.FixedFontFamily = Settings.FixedFontFamily;
    SlateCefViewSettings.SerifFontFamily = Settings.SerifFontFamily;
    SlateCefViewSettings.SansSerifFontFamily = Settings.SansSerifFontFamily;
    SlateCefViewSettings.CursiveFontFamily = Settings.CursiveFontFamily;
    SlateCefViewSettings.FantasyFontFamily = Settings.FantasyFontFamily;
    SlateCefViewSettings.DefaultEncoding = Settings.DefaultEncoding;
    SlateCefViewSettings.AcceptLanguageList = Settings.AcceptLanguageList;
    SlateCefViewSettings.RemoteFonts = Settings.RemoteFonts;
    SlateCefViewSettings.Javascript = Settings.Javascript;
    SlateCefViewSettings.AllowJavascriptCloseWindows = Settings.AllowJavascriptCloseWindows;
    SlateCefViewSettings.AllowJavascriptAccessClipboard = Settings.AllowJavascriptAccessClipboard;
    SlateCefViewSettings.AllowJavascriptDomPaste = Settings.AllowJavascriptDomPaste;
    SlateCefViewSettings.Plugins = Settings.Plugins;
    SlateCefViewSettings.ImageLoading = Settings.ImageLoading;
    SlateCefViewSettings.ImageShrinkStandaloneToFit = Settings.ImageShrinkStandaloneToFit;
    SlateCefViewSettings.TextAreaResize = Settings.TextAreaResize;
    SlateCefViewSettings.TabToLinks = Settings.TabToLinks;
    SlateCefViewSettings.LocalStorage = Settings.LocalStorage;
    SlateCefViewSettings.Databases = Settings.Databases;
    SlateCefViewSettings.WebGL = Settings.WebGL;

    /** 构造底层 Slate CEF 视图，并把 Slate 事件统一绑定回当前 UMG 控件。 */
    SlateCefView = SNew(SCefView)                                                     //
                     .Url(this->Url)                                                  //
                     .bEnableContextMenu(this->bEnableContextMenu)                    //
                     .bAcceptDrops(this->bAcceptDrops)                                //
                     .bAllowDrag(this->bAllowDrag)                                    //
                     .bEnableAlphaHitTestPassthrough(this->bEnableAlphaHitTestPassthrough) //
                     .AlphaHitTestThreshold(this->AlphaHitTestThreshold)               //
                     .Settings(SlateCefViewSettings)                                  //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(LoadStateChanged)       //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(LoadStart)              //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(LoadEnd)                //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(LoadError)              //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(DraggableRegionChanged) //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(AddressChanged)         //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(TitleChanged)           //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(FaviconUrlChanged)      //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(FullscreenModeChanged)  //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(StatusMessage)          //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(ConsoleMessage)         //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(LoadingProgressChanged) //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(UrlRequest)             //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(QueryRequest)           //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(InvokeMethod)           //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(ReportJavascriptResult) //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(NativeBrowserCreated)   //
                     .BIND_SCEFVIEW_EVENT_TO_UCEFVIEW_HANDLER(CreateNewBrowser)       //
      ;

    /** UMG 持有共享引用，Slate 资源释放时再统一清理。 */
    return SlateCefView.ToSharedRef();
  }
}

void
UCefView::SynchronizeProperties()
{
  FLog();

  Super::SynchronizeProperties();

  if (SlateCefView) {
    SlateCefView->SetUrl(Url);
    SlateCefView->SetEnableContextMenu(bEnableContextMenu);
    SlateCefView->SetAcceptDrops(bAcceptDrops);
    SlateCefView->SetAllowDrag(bAllowDrag);
    SlateCefView->SetEnableAlphaHitTestPassthrough(bEnableAlphaHitTestPassthrough);
    SlateCefView->SetAlphaHitTestThreshold(AlphaHitTestThreshold);
  }
}

void
UCefView::ReleaseSlateResources(bool bInReleaseChildren)
{
  FLog();

  Super::ReleaseSlateResources(bInReleaseChildren);

  if (SlateCefView) {
    SlateCefView.Reset();
  }
}

#if WITH_EDITOR
const FText
UCefView::GetPaletteCategory()
{
  return FText::FromString(TEXT("CefView"));
}
#endif

void
UCefView::AddLocalFolderResource(const FString& InFolderPath, const FString& InTargetUrl, int32 InPriority /*= 0*/)
{
  if (SlateCefView) {
    SlateCefView->AddLocalFolderResource(InFolderPath, InTargetUrl, InPriority);
  }
}

void
UCefView::AddArchiveFileResource(const FString& InArchivePath,
                                 const FString& InTargetUrl,
                                 const FString& InPassword /*= ""*/,
                                 int32 InPriority /*= 0*/)
{
  if (SlateCefView) {
    SlateCefView->AddArchiveFileResource(InArchivePath, InTargetUrl, InPassword, InPriority);
  }
}

int64
UCefView::GetBrowserId()
{
  if (SlateCefView) {
    return SlateCefView->GetBrowserId();
  }
  return 0;
}

void
UCefView::NavigateToUrl(const FString& InTargetUrl)
{
  Url = InTargetUrl;
  if (SlateCefView) {
    SlateCefView->SetUrl(Url);
  }
}

bool
UCefView::BrowserCanGoBack()
{
  if (SlateCefView) {
    return SlateCefView->BrowserCanGoBack();
  }
  return false;
}

bool
UCefView::BrowserCanGoForward()
{
  if (SlateCefView) {
    return SlateCefView->BrowserCanGoForward();
  }
  return false;
}

void
UCefView::BrowserGoBack()
{
  if (SlateCefView) {
    SlateCefView->BrowserGoBack();
  }
}

void
UCefView::BrowserGoForward()
{
  if (SlateCefView) {
    SlateCefView->BrowserGoForward();
  }
}

bool
UCefView::IsBrowserLoading()
{
  if (SlateCefView) {
    return SlateCefView->IsBrowserLoading();
  }
  return false;
}

void
UCefView::BrowserReload()
{
  if (SlateCefView) {
    SlateCefView->BrowserReload();
  }
}

void
UCefView::BrowserStopLoad()
{
  if (SlateCefView) {
    SlateCefView->BrowserStopLoad();
  }
}

bool
UCefView::TriggerEventForFrame(const UCefViewEvent* InCefViewEvent, const FCefFrameId& InFrameId)
{
  if (SlateCefView) {
    return SlateCefView->TriggerEventForFrame(InCefViewEvent->Name, InCefViewEvent->Arguments, InFrameId);
  }
  return false;
}

bool
UCefView::TriggerEventForMainFrame(const UCefViewEvent* InCefViewEvent)
{
  if (SlateCefView) {
    return SlateCefView->TriggerEventForMainFrame(InCefViewEvent->Name, InCefViewEvent->Arguments);
  }
  return false;
}

bool
UCefView::BroadcastEvent(const UCefViewEvent* InCefViewEvent)
{
  if (SlateCefView) {
    return SlateCefView->BroadcastEvent(InCefViewEvent->Name, InCefViewEvent->Arguments);
  }
  return false;
}

bool
UCefView::ResponseUCefQuery(const UCefViewQuery* InCefQuery)
{
  if (SlateCefView && SlateCefView->ResponseUCefQuery( //
                        InCefQuery->GetId(),           //
                        InCefQuery->IsSuccess,         //
                        InCefQuery->Response,          //
                        InCefQuery->ErrorCode          //
                        )) {
    InCefQuery->MarkAsReplied();
  }
  return false;
}

bool
UCefView::ExecuteJavascript(const FCefFrameId& InFrameId, const FString& InJavascriptCode, const FString& InTargetUrl)
{
  if (SlateCefView) {
    return SlateCefView->ExecuteJavascript(InFrameId, InJavascriptCode, InTargetUrl);
  }
  return false;
}

bool
UCefView::ExecuteJavascriptWithResult(const FCefFrameId& InFrameId,
                                      const FString& InJavascriptCode,
                                      const FString& InTargetUrl,
                                      const FString& InExecuteContext)
{
  if (SlateCefView) {
    return SlateCefView->ExecuteJavascriptWithResult(InFrameId, InJavascriptCode, InTargetUrl, InExecuteContext);
  }
  return false;
}

bool
UCefView::SetPreference(const FString& InPreferenceName, const FString& InPreferenceValue, FString& InError)
{
  if (SlateCefView) {
    return SlateCefView->SetPreference(InPreferenceName, InPreferenceValue, InError);
  }
  return false;
}

void
UCefView::SetDisablePopupContextMenu(bool bInIsDisable)
{
}

bool
UCefView::IsPopupContextMenuDisabled()
{
  return false;
}

bool
UCefView::HasDevTools()
{
  return false;
}

void
UCefView::ShowDevTools()
{
}

void
UCefView::CloseDevTools()
{
}

void
UCefView::SetEnableDragAndDrop(bool bInIsEnable)
{
}

bool
UCefView::IsDragAndDropEnabled() const
{
  return false;
}

void
UCefView::OnNewBrowser(const FCefFrameId& InSourceFrameId,
                       const FString& InUrl,
                       const FString& InName,
                       ECefWindowOpenDisposition InTargetDisposition,
                       FIntRect& InRect)
{
  // FLog();
}

bool
UCefView::OnNewPopup(const FCefFrameId& InFrameId,
                     const FString& InTargetUrl,
                     FString& InTargetFrameName,
                     ECefWindowOpenDisposition InTargetDisposition,
                     FIntRect& InRect,
                     FSlateCefViewSettings& InSettings,
                     bool& bInDisableJavascriptAccess)
{
  // FLog();
  return false;
}

bool
UCefView::OnRequestCloseFromWeb()
{
  // FLog();
  return false;
}

void
UCefView::OnSlateLoadStateChangedEvent(const int64& InBrowserId,
                                       bool bInIsLoading,
                                       bool bInCanGoBack,
                                       bool bInCanGoForward)
{
  // FLog();
  OnLoadStateChanged.Broadcast(InBrowserId, bInIsLoading, bInCanGoBack, bInCanGoForward);
}

void
UCefView::OnSlateLoadStartEvent(const int64& InBrowserId,
                                const FCefFrameId& InFrameId,
                                bool bInIsMainFrame,
                                int InTransitionType)
{
  // FLog();
  OnLoadStart.Broadcast(InBrowserId, InFrameId, bInIsMainFrame, InTransitionType);
}

void
UCefView::OnSlateLoadEndEvent(const int64& InBrowserId,
                              const FCefFrameId& InFrameId,
                              bool bInIsMainFrame,
                              int InHttpStatusCode)
{
  // FLog();
  OnLoadEnd.Broadcast(InBrowserId, InFrameId, bInIsMainFrame, InHttpStatusCode);
}

void
UCefView::OnSlateLoadErrorEvent(const int64& InBrowserId,
                                const FCefFrameId& InFrameId,
                                bool bInIsMainFrame,
                                int InErrorCode,
                                const FString& InErrorMsg,
                                const FString& InFailedUrl,
                                bool& bInHandled)
{
  // FLog();

  /** 延迟广播加载错误，先让底层按未处理错误路径完成内部状态更新。 */
  TWeakObjectPtr<UCefView> WeakSelf = this;
  AsyncTask(ENamedThreads::GameThread_Local,
            [WeakSelf, InBrowserId, InFrameId, bInIsMainFrame, InErrorCode, InErrorMsg, InFailedUrl]() {
              auto Self = WeakSelf.Get();
              if (Self) {
                Self->OnLoadError.Broadcast(
                  InBrowserId, InFrameId, bInIsMainFrame, InErrorCode, InErrorMsg, InFailedUrl);
              }
            });
}

void
UCefView::OnSlateDraggableRegionChangedEvent(const FVector4& InDraggableRegion, const FVector4& InNonDraggableRegion)
{
  // FLog();
  OnDraggableRegionChanged.Broadcast(InDraggableRegion, InNonDraggableRegion);
}

void
UCefView::OnSlateAddressChangedEvent(const FCefFrameId& InFrameId, const FString& InNewAddress)
{
  // FLog();
  OnAddressChanged.Broadcast(InFrameId, InNewAddress);
}

void
UCefView::OnSlateTitleChangedEvent(const FString& InTitle)
{
  // FLog();
  OnTitleChanged.Broadcast(InTitle);
}

void
UCefView::OnSlateFaviconUrlChangedEvent(const TArray<FString>& InUrls)
{
  // FLog();
  OnFaviconUrlChanged.Broadcast(InUrls);
}

void
UCefView::OnSlateFullscreenModeChangedEvent(bool bInFullscreen)
{
  // FLog();
  OnFullscreenModeChanged.Broadcast(bInFullscreen);
}

void
UCefView::OnSlateStatusMessageEvent(const FString& InMessage)
{
  // FLog();
  OnStatusMessage.Broadcast(InMessage);
}

void
UCefView::OnSlateConsoleMessageEvent(const FString& InMessage, int32 InLevel)
{
  // FLog();
  OnConsoleMessage.Broadcast(InMessage, InLevel);
}

void
UCefView::OnSlateLoadingProgressChangedEvent(double InProgress)
{
  // FLog();
  OnLoadingProgressChanged.Broadcast(InProgress);
}

void
UCefView::OnSlateUrlRequestEvent(const int64& InBrowserId, const FCefFrameId& InFrameId, const FString& InRequestUrl)
{
  // FLog();
  OnUrlRequest.Broadcast(InBrowserId, InFrameId, InRequestUrl);
}

void
UCefView::OnSlateQueryRequestEvent(const int64& InBrowserId,
                                   const FCefFrameId& InFrameId,
                                   const int64& InQueryId,
                                   const FString& InRequest)
{
  // FLog();
  if (OnQueryRequest.IsBound()) {
    UCefViewQuery* Query = NewObject<UCefViewQuery>(this);
    Query->SetIdAndRequest(InQueryId, InRequest);
    OnQueryRequest.Broadcast(InBrowserId, InFrameId, Query);
  } else {
    if (SlateCefView) {
      SlateCefView->ResponseUCefQuery( //
        InQueryId,                     //
        false,                         //
        FString(),                     //
        -1                             //
      );
    }
  }
}

void
UCefView::OnSlateInvokeMethodEvent(const int64& InBrowserId,
                                   const FCefFrameId& InFrameId,
                                   const FString& InMethod,
                                   const TArray<TSharedPtr<FJsonValue>>& InArguments)
{
  // FLog();
  /** Slate 层传入结构化参数，蓝图事件使用字符串形式的 JSON 参数列表。 */
  FString StrArgs;
  auto StrWriter = TJsonWriterFactory<>::Create(&StrArgs);
  FJsonSerializer::Serialize(InArguments, StrWriter);

  OnInvokeMethod.Broadcast(InBrowserId, InFrameId, InMethod, StrArgs);
}

void
UCefView::OnSlateReportJavascriptResultEvent(const int64& InBrowserId,
                                             const FCefFrameId& InFrameId,
                                             const FString& InContext,
                                             const TSharedPtr<FJsonValue>& InResult)
{
  // FLog();
  /** JavaScript 执行结果在进入蓝图前序列化为 JSON 字符串。 */
  FString StrResult;

  if (InResult && InResult->Type != EJson::None) {
    auto StrWriter = TJsonWriterFactory<>::Create(&StrResult);
    FJsonSerializer::Serialize(InResult, FString(), StrWriter);
  }

  OnReportJavascriptResult.Broadcast(InBrowserId, InFrameId, InContext, StrResult);
}

void
UCefView::OnSlateNativeBrowserCreatedEvent()
{
  // FLog();
  OnNativeBrowserCreated.Broadcast();
}

void
UCefView::OnSlateCreateNewBrowserEvent(const FCefFrameId& InSourceFrameId,
                                       const FString& InUrl,
                                       const FString& InName,
                                       const ECefWindowOpenDisposition& InTargetDisposition,
                                       const FIntRect& InRect)
{
  OnCreateNewBrowser.Broadcast(InSourceFrameId,
                               InUrl,
                               InName,
                               InTargetDisposition,
                               FVector4(InRect.Min.X, InRect.Min.Y, InRect.Max.X, InRect.Max.Y));
}
