#include "GenericWebWidgetBase.h"

#include "GenericWebFramework.h"
#include "Widgets/SNullWidget.h"

UGenericWebWidgetBase::UGenericWebWidgetBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericWebWidgetBase::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	DestroyWidgetInternal();
}

TSharedRef<SWidget> UGenericWebWidgetBase::RebuildWidget()
{
	return BuildWidgetInternal();
}

void UGenericWebWidgetBase::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	SynchronizePropertiesInternal();
}

void UGenericWebWidgetBase::LoadUrl(const FString& InUrl)
{
	InitialUrl = InUrl;
	SetLastErrorInternal({true, 1, TEXT("Backend does not implement LoadUrl."), GetBackendType()});
	UE_LOG(LogGenericWeb, Warning, TEXT("%s does not implement LoadUrl."), *GetClass()->GetName());
}

void UGenericWebWidgetBase::Reload()
{
	SetLastErrorInternal({true, 2, TEXT("Backend does not implement Reload."), GetBackendType()});
	UE_LOG(LogGenericWeb, Warning, TEXT("%s does not implement Reload."), *GetClass()->GetName());
}

void UGenericWebWidgetBase::StopLoad()
{
	SetLastErrorInternal({true, 3, TEXT("Backend does not implement StopLoad."), GetBackendType()});
	UE_LOG(LogGenericWeb, Warning, TEXT("%s does not implement StopLoad."), *GetClass()->GetName());
}

void UGenericWebWidgetBase::ExecuteJavascript(const FString& Script, FOnGenericWebScriptExecuted Callback)
{
	FGenericWebScriptResult Result;
	Result.bSuccess = false;
	Result.ErrorText = TEXT("Backend does not implement ExecuteJavascript.");
	Result.Result = Script;

	SetLastErrorInternal({true, 4, Result.ErrorText, GetBackendType()});
	UE_LOG(LogGenericWeb, Warning, TEXT("%s does not implement ExecuteJavascript."), *GetClass()->GetName());

	if (Callback.IsBound())
	{
		Callback.Execute(Result);
	}
}

void UGenericWebWidgetBase::SetWebViewVisibility(ESlateVisibility InVisibility)
{
	SetVisibility(InVisibility);
}

EGenericWebBackendType UGenericWebWidgetBase::GetBackendType() const
{
	return BackendType;
}

bool UGenericWebWidgetBase::IsBackendAvailable() const
{
	return bBackendAvailable;
}

FGenericWebNavigationState UGenericWebWidgetBase::GetNavigationState() const
{
	return NavigationState;
}

FGenericWebError UGenericWebWidgetBase::GetLastError() const
{
	return LastError;
}

void UGenericWebWidgetBase::SetBackendTypeInternal(EGenericWebBackendType InBackendType)
{
	BackendType = InBackendType;
}

void UGenericWebWidgetBase::SetBackendAvailabilityInternal(bool bInAvailable)
{
	bBackendAvailable = bInAvailable;
}

void UGenericWebWidgetBase::SetLastErrorInternal(const FGenericWebError& InError)
{
	LastError = InError;
}

void UGenericWebWidgetBase::BroadcastLoadStartedInternal(const FString& Url)
{
	NavigationState.Url = Url;
	NavigationState.bIsLoading = true;
	NavigationState.LoadState = EGenericWebLoadState::Loading;
	OnLoadStarted.Broadcast(Url);
	BroadcastNavigationStateChangedInternal();
}

void UGenericWebWidgetBase::BroadcastLoadCompletedInternal(const FGenericWebLoadResult& Result)
{
	NavigationState.Url = Result.Url.IsEmpty() ? NavigationState.Url : Result.Url;
	NavigationState.bIsLoading = false;
	NavigationState.LoadState = Result.bSuccess ? EGenericWebLoadState::Completed : EGenericWebLoadState::Failed;
	OnLoadCompleted.Broadcast(Result);
	BroadcastNavigationStateChangedInternal();
}

void UGenericWebWidgetBase::BroadcastUrlChangedInternal(const FString& Url)
{
	NavigationState.Url = Url;
	BroadcastNavigationStateChangedInternal();
}

void UGenericWebWidgetBase::BroadcastTitleChangedInternal(const FString& Title)
{
	NavigationState.Title = Title;
	BroadcastNavigationStateChangedInternal();
}

void UGenericWebWidgetBase::BroadcastNavigationStateChangedInternal()
{
	OnNavigationStateChanged.Broadcast(NavigationState);
}

void UGenericWebWidgetBase::BroadcastMessageReceivedInternal(const FGenericWebMessage& Message)
{
	OnMessageReceived.Broadcast(Message);
}

void UGenericWebWidgetBase::BroadcastDownloadUpdatedInternal(const FGenericWebDownloadInfo& DownloadInfo)
{
	OnDownloadUpdated.Broadcast(DownloadInfo);
}

void UGenericWebWidgetBase::BroadcastMonitorEventInternal(const FGenericWebMonitorEvent& EventInfo)
{
	OnMonitorEvent.Broadcast(EventInfo);
}

void UGenericWebWidgetBase::DestroyWidgetInternal()
{
}

void UGenericWebWidgetBase::SynchronizePropertiesInternal()
{
}

TSharedRef<SWidget> UGenericWebWidgetBase::BuildWidgetInternal()
{
	return SNullWidget::NullWidget;
}
