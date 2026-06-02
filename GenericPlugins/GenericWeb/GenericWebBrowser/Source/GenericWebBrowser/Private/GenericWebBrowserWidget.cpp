#include "GenericWebBrowserWidget.h"

#include "GenericWebFramework.h"
#if WITH_EDITOR
#include "CefContext.h"
#include "SWebBrowser.h"
#include "WebBrowserModule.h"
#include "Engine/Engine.h"
#endif
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"

namespace
{
TSharedRef<SWidget> BuildGenericWebBrowserPlaceholder()
{
	return SNew(SBox)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("GenericWebBrowser")))
		];
}
}

UGenericWebBrowserWidget::UGenericWebBrowserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetBackendTypeInternal(EGenericWebBackendType::Browser);
	SetBackendAvailabilityInternal(true);
}

void UGenericWebBrowserWidget::LoadUrl(const FString& InUrl)
{
	InitialUrl = InUrl;
	if (LegacyWidget)
	{
		LegacyWidget->NavigateToUrl(InUrl);
		return;
	}

#if WITH_EDITOR
	if (FallbackBrowserWidget.IsValid())
	{
		FallbackBrowserWidget->LoadURL(InUrl);
		return;
	}
#endif

	SetLastErrorInternal({true, 301, TEXT("CEF backend is not available."), EGenericWebBackendType::Browser});
}

void UGenericWebBrowserWidget::Reload()
{
	if (LegacyWidget)
	{
		LegacyWidget->BrowserReload();
		return;
	}

#if WITH_EDITOR
	if (FallbackBrowserWidget.IsValid())
	{
		FallbackBrowserWidget->Reload();
		return;
	}
#endif

	SetLastErrorInternal({true, 302, TEXT("CEF backend is not available."), EGenericWebBackendType::Browser});
}

void UGenericWebBrowserWidget::StopLoad()
{
	if (LegacyWidget)
	{
		LegacyWidget->BrowserStopLoad();
		return;
	}

#if WITH_EDITOR
	if (FallbackBrowserWidget.IsValid())
	{
		FallbackBrowserWidget->StopLoad();
		return;
	}
#endif

	SetLastErrorInternal({true, 303, TEXT("CEF backend is not available."), EGenericWebBackendType::Browser});
}

void UGenericWebBrowserWidget::ExecuteJavascript(const FString& Script, FOnGenericWebScriptExecuted Callback)
{
	if (LegacyWidget)
	{
		const FString ContextId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
		PendingScriptCallbacks.Add(ContextId, Callback);
		LegacyWidget->ExecuteJavascriptWithResult(UCefView::MainFrameID, Script, NavigationState.Url, ContextId);
		return;
	}

#if WITH_EDITOR
	if (FallbackBrowserWidget.IsValid())
	{
		FallbackBrowserWidget->ExecuteJavascript(Script);
		FGenericWebScriptResult Result;
		Result.bSuccess = true;
		Result.Result = Script;
		if (Callback.IsBound())
		{
			Callback.Execute(Result);
		}
		return;
	}
#endif

	{
		FGenericWebScriptResult Result;
		Result.bSuccess = false;
		Result.ErrorText = TEXT("CEF backend is not available.");
		if (Callback.IsBound())
		{
			Callback.Execute(Result);
		}
		return;
	}
}

void UGenericWebBrowserWidget::SetWebViewVisibility(ESlateVisibility InVisibility)
{
	Super::SetWebViewVisibility(InVisibility);

	if (LegacyWidget)
	{
		LegacyWidget->SetVisibility(InVisibility);
	}

#if WITH_EDITOR
	if (FallbackBrowserWidget.IsValid())
	{
		FallbackBrowserWidget->SetVisibility(UWidget::ConvertSerializedVisibilityToRuntime(InVisibility));
	}
#endif
}

TSharedRef<SWidget> UGenericWebBrowserWidget::BuildWidgetInternal()
{
	if (ShouldUsePlaceholderWidget())
	{
		DestroyWidgetInternal();
		return BuildGenericWebBrowserPlaceholder();
	}

#if WITH_EDITOR
	if (!TryEnsureLegacyCefBackend())
	{
		return BuildFallbackBrowserWidget();
	}

	FallbackBrowserWidget.Reset();
#endif

	if (!LegacyWidget)
	{
		LegacyWidget = NewObject<UCefView>(this, NAME_None, RF_Transient);
		LegacyWidget->OnLoadStateChanged.AddUniqueDynamic(this, &UGenericWebBrowserWidget::HandleLegacyLoadStateChanged);
		LegacyWidget->OnLoadStart.AddUniqueDynamic(this, &UGenericWebBrowserWidget::HandleLegacyLoadStart);
		LegacyWidget->OnLoadEnd.AddUniqueDynamic(this, &UGenericWebBrowserWidget::HandleLegacyLoadEnd);
		LegacyWidget->OnLoadError.AddUniqueDynamic(this, &UGenericWebBrowserWidget::HandleLegacyLoadError);
		LegacyWidget->OnAddressChanged.AddUniqueDynamic(this, &UGenericWebBrowserWidget::HandleLegacyAddressChanged);
		LegacyWidget->OnTitleChanged.AddUniqueDynamic(this, &UGenericWebBrowserWidget::HandleLegacyTitleChanged);
		LegacyWidget->OnInvokeMethod.AddUniqueDynamic(this, &UGenericWebBrowserWidget::HandleLegacyInvokeMethod);
		LegacyWidget->OnReportJavascriptResult.AddUniqueDynamic(this, &UGenericWebBrowserWidget::HandleLegacyScriptResult);
	}

	ApplySettingsToLegacy();

	return LegacyWidget->TakeWidget();
}

void UGenericWebBrowserWidget::DestroyWidgetInternal()
{
#if WITH_EDITOR
	FallbackBrowserWidget.Reset();
#endif

	if (!LegacyWidget)
	{
		return;
	}

	LegacyWidget->OnLoadStateChanged.RemoveDynamic(this, &UGenericWebBrowserWidget::HandleLegacyLoadStateChanged);
	LegacyWidget->OnLoadStart.RemoveDynamic(this, &UGenericWebBrowserWidget::HandleLegacyLoadStart);
	LegacyWidget->OnLoadEnd.RemoveDynamic(this, &UGenericWebBrowserWidget::HandleLegacyLoadEnd);
	LegacyWidget->OnLoadError.RemoveDynamic(this, &UGenericWebBrowserWidget::HandleLegacyLoadError);
	LegacyWidget->OnAddressChanged.RemoveDynamic(this, &UGenericWebBrowserWidget::HandleLegacyAddressChanged);
	LegacyWidget->OnTitleChanged.RemoveDynamic(this, &UGenericWebBrowserWidget::HandleLegacyTitleChanged);
	LegacyWidget->OnInvokeMethod.RemoveDynamic(this, &UGenericWebBrowserWidget::HandleLegacyInvokeMethod);
	LegacyWidget->OnReportJavascriptResult.RemoveDynamic(this, &UGenericWebBrowserWidget::HandleLegacyScriptResult);
	LegacyWidget->ReleaseSlateResources(true);
	PendingScriptCallbacks.Empty();
	LegacyWidget = nullptr;
}

void UGenericWebBrowserWidget::SynchronizePropertiesInternal()
{
	ApplySettingsToLegacy();
}

bool UGenericWebBrowserWidget::ShouldUsePlaceholderWidget() const
{
	return IsDesignTime()
		|| IsTemplate()
		|| GIsSavingPackage
		|| HasAnyFlags(RF_ClassDefaultObject | RF_ArchetypeObject);
}

#if WITH_EDITOR
bool UGenericWebBrowserWidget::TryEnsureLegacyCefBackend()
{
	if (IWebBrowserModule::IsAvailable() && IWebBrowserModule::Get().IsWebModuleAvailable())
	{
		SetBackendAvailabilityInternal(false);
		SetLastErrorInternal({true, 304, TEXT("Engine WebBrowser has already initialized CEF. Falling back to engine WebBrowser."), EGenericWebBackendType::Browser});
		UE_LOG(LogGenericWeb, Log, TEXT("Engine WebBrowser is already available. GenericWebBrowser will use it for %s."), *InitialUrl);
		return false;
	}

	UCefContext* CefContext = GEngine ? GEngine->GetEngineSubsystem<UCefContext>() : nullptr;
	if (!CefContext)
	{
		SetBackendAvailabilityInternal(false);
		SetLastErrorInternal({true, 305, TEXT("UCefContext is not available."), EGenericWebBackendType::Browser});
		UE_LOG(LogGenericWeb, Warning, TEXT("GenericWebBrowser cannot find UCefContext. Falling back to engine WebBrowser for %s."), *InitialUrl);
		return false;
	}

	if (CefContext->EnsureCefInitialized())
	{
		SetBackendAvailabilityInternal(true);
		return true;
	}

	SetBackendAvailabilityInternal(false);
	SetLastErrorInternal({true, 306, TEXT("UCefView CEF initialization failed. Falling back to engine WebBrowser."), EGenericWebBackendType::Browser});
	UE_LOG(LogGenericWeb, Warning, TEXT("UCefView CEF initialization failed. Falling back to engine WebBrowser for %s."), *InitialUrl);
	return false;
}

TSharedRef<SWidget> UGenericWebBrowserWidget::BuildFallbackBrowserWidget()
{
	if (!IWebBrowserModule::Get().IsWebModuleAvailable())
	{
		SetBackendAvailabilityInternal(false);
		SetLastErrorInternal({true, 307, TEXT("Engine WebBrowser module is not available."), EGenericWebBackendType::Browser});
		UE_LOG(LogGenericWeb, Error, TEXT("Engine WebBrowser module is not available for GenericWebBrowser."));
		return BuildGenericWebBrowserPlaceholder();
	}

	DestroyWidgetInternal();

	TSharedRef<SWebBrowser> Browser = SNew(SWebBrowser)
		.InitialURL(InitialUrl)
		.ShowControls(false)
		.ShowAddressBar(false)
		.ShowErrorMessage(true)
		.SupportsTransparency(ViewSettings.BackgroundColor.A < 255)
		.BackgroundColor(ViewSettings.BackgroundColor)
		.OnLoadStarted(FSimpleDelegate::CreateUObject(this, &UGenericWebBrowserWidget::HandleFallbackLoadStarted))
		.OnLoadCompleted(FSimpleDelegate::CreateUObject(this, &UGenericWebBrowserWidget::HandleFallbackLoadCompleted))
		.OnLoadError(FSimpleDelegate::CreateUObject(this, &UGenericWebBrowserWidget::HandleFallbackLoadError))
		.OnUrlChanged(FOnTextChanged::CreateUObject(this, &UGenericWebBrowserWidget::HandleFallbackUrlChanged))
		.OnTitleChanged(FOnTextChanged::CreateUObject(this, &UGenericWebBrowserWidget::HandleFallbackTitleChanged))
		.OnSuppressContextMenu(FOnSuppressContextMenu::CreateUObject(this, &UGenericWebBrowserWidget::HandleFallbackSuppressContextMenu));

	FallbackBrowserWidget = Browser;
	FallbackBrowserWidget->SetVisibility(UWidget::ConvertSerializedVisibilityToRuntime(GetVisibility()));
	SetBackendAvailabilityInternal(true);

	UE_LOG(LogGenericWeb, Log, TEXT("GenericWebBrowser is using engine WebBrowser fallback for %s."), *InitialUrl);
	return Browser;
}
#endif

void UGenericWebBrowserWidget::CreateMonitorEvent(EGenericWebMonitorEventType EventType, const FString& Message, bool bSuccess)
{
	FGenericWebMonitorEvent EventInfo;
	EventInfo.EventType = EventType;
	EventInfo.Url = NavigationState.Url;
	EventInfo.Title = NavigationState.Title;
	EventInfo.Message = Message;
	EventInfo.bSuccess = bSuccess;
	BroadcastMonitorEventInternal(EventInfo);
}

void UGenericWebBrowserWidget::ApplySettingsToLegacy()
{
	if (!LegacyWidget)
	{
		return;
	}

	LegacyWidget->Url = InitialUrl;
	LegacyWidget->bEnableContextMenu = false;
	LegacyWidget->bAcceptDrops = false;
	LegacyWidget->bAllowDrag = false;
	LegacyWidget->Settings.BackgroundColor = ViewSettings.BackgroundColor;
	LegacyWidget->bEnableAlphaHitTestPassthrough = ViewSettings.bEnableAlphaHitTestPassthrough;
	LegacyWidget->AlphaHitTestThreshold = ViewSettings.AlphaHitTestThreshold;
}

#if WITH_EDITOR
void UGenericWebBrowserWidget::HandleFallbackLoadStarted()
{
	const FString Url = FallbackBrowserWidget.IsValid() ? FallbackBrowserWidget->GetUrl() : InitialUrl;
	BroadcastLoadStartedInternal(Url.IsEmpty() ? InitialUrl : Url);
	CreateMonitorEvent(EGenericWebMonitorEventType::LoadStarted, NavigationState.Url, true);
}

void UGenericWebBrowserWidget::HandleFallbackLoadCompleted()
{
	FGenericWebLoadResult Result;
	Result.bSuccess = true;
	Result.StatusCode = 200;
	Result.Url = FallbackBrowserWidget.IsValid() ? FallbackBrowserWidget->GetUrl() : NavigationState.Url;
	BroadcastLoadCompletedInternal(Result);
	CreateMonitorEvent(EGenericWebMonitorEventType::LoadCompleted, TEXT("Engine WebBrowser completed load."), true);
}

void UGenericWebBrowserWidget::HandleFallbackLoadError()
{
	FGenericWebLoadResult Result;
	Result.bSuccess = false;
	Result.StatusCode = 0;
	Result.Url = FallbackBrowserWidget.IsValid() ? FallbackBrowserWidget->GetUrl() : NavigationState.Url;
	Result.ErrorText = TEXT("Engine WebBrowser failed to load the page.");
	BroadcastLoadCompletedInternal(Result);
	SetLastErrorInternal({true, 308, Result.ErrorText, EGenericWebBackendType::Browser});
	CreateMonitorEvent(EGenericWebMonitorEventType::LoadCompleted, Result.ErrorText, false);
}

void UGenericWebBrowserWidget::HandleFallbackUrlChanged(const FText& NewUrl)
{
	BroadcastUrlChangedInternal(NewUrl.ToString());
	CreateMonitorEvent(EGenericWebMonitorEventType::UrlChanged, NavigationState.Url, true);
}

void UGenericWebBrowserWidget::HandleFallbackTitleChanged(const FText& NewTitle)
{
	BroadcastTitleChangedInternal(NewTitle.ToString());
	CreateMonitorEvent(EGenericWebMonitorEventType::TitleChanged, NavigationState.Title, true);
}

bool UGenericWebBrowserWidget::HandleFallbackSuppressContextMenu() const
{
	return true;
}
#endif

void UGenericWebBrowserWidget::HandleLegacyLoadStateChanged(const int64& BrowserId, bool bIsLoading, bool bCanGoBack, bool bCanGoForward)
{
	NavigationState.bIsLoading = bIsLoading;
	NavigationState.bCanGoBack = bCanGoBack;
	NavigationState.bCanGoForward = bCanGoForward;
	NavigationState.LoadState = bIsLoading ? EGenericWebLoadState::Loading : NavigationState.LoadState;
	BroadcastNavigationStateChangedInternal();
}

void UGenericWebBrowserWidget::HandleLegacyLoadStart(const int64& BrowserId, const FCefFrameId& FrameId, bool bIsMainFrame, int TransitionType)
{
	if (!bIsMainFrame)
	{
		return;
	}

	BroadcastLoadStartedInternal(NavigationState.Url.IsEmpty() ? InitialUrl : NavigationState.Url);
	CreateMonitorEvent(EGenericWebMonitorEventType::LoadStarted, NavigationState.Url, true);
}

void UGenericWebBrowserWidget::HandleLegacyLoadEnd(const int64& BrowserId, const FCefFrameId& FrameId, bool bIsMainFrame, int HttpStatusCode)
{
	if (!bIsMainFrame)
	{
		return;
	}

	FGenericWebLoadResult Result;
	Result.bSuccess = HttpStatusCode < 400;
	Result.StatusCode = HttpStatusCode;
	Result.Url = NavigationState.Url;
	BroadcastLoadCompletedInternal(Result);
	CreateMonitorEvent(EGenericWebMonitorEventType::LoadCompleted, FString::Printf(TEXT("HTTP %d"), HttpStatusCode), Result.bSuccess);
}

void UGenericWebBrowserWidget::HandleLegacyLoadError(const int64& BrowserId, const FCefFrameId& FrameId, bool bIsMainFrame, int ErrorCode, const FString& ErrorMessage, const FString& FailedUrl)
{
	if (!bIsMainFrame)
	{
		return;
	}

	FGenericWebLoadResult Result;
	Result.bSuccess = false;
	Result.StatusCode = ErrorCode;
	Result.Url = FailedUrl;
	Result.ErrorText = ErrorMessage;
	BroadcastLoadCompletedInternal(Result);
	CreateMonitorEvent(EGenericWebMonitorEventType::LoadCompleted, ErrorMessage, false);
}

void UGenericWebBrowserWidget::HandleLegacyAddressChanged(const FCefFrameId& FrameId, const FString& NewAddress)
{
	BroadcastUrlChangedInternal(NewAddress);
	CreateMonitorEvent(EGenericWebMonitorEventType::UrlChanged, NewAddress, true);
}

void UGenericWebBrowserWidget::HandleLegacyTitleChanged(const FString& Title)
{
	BroadcastTitleChangedInternal(Title);
	CreateMonitorEvent(EGenericWebMonitorEventType::TitleChanged, Title, true);
}

void UGenericWebBrowserWidget::HandleLegacyInvokeMethod(const int64& BrowserId, const FCefFrameId& FrameId, const FString& Method, const FString& Arguments)
{
	FGenericWebMessage Message;
	Message.Name = Method;
	Message.Payload = Arguments;
	Message.Source = TEXT("Browser");
	BroadcastMessageReceivedInternal(Message);
}

void UGenericWebBrowserWidget::HandleLegacyScriptResult(const int64& BrowserId, const FCefFrameId& FrameId, const FString& Context, const FString& Result)
{
	FGenericWebScriptResult ScriptResult;
	ScriptResult.bSuccess = true;
	ScriptResult.Context = Context;
	ScriptResult.Result = Result;

	if (FOnGenericWebScriptExecuted* Callback = PendingScriptCallbacks.Find(Context))
	{
		if (Callback->IsBound())
		{
			Callback->Execute(ScriptResult);
		}

		PendingScriptCallbacks.Remove(Context);
	}
}
