// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Component/VoiceWakeupComponent.h"

#include "Engine/World.h"
#include "Interface/VoiceWakeupInterface.h"
#include "Provider/VoiceWakeupServiceFeature.h"
#include "Route/VoiceRouteResolver.h"

UVoiceWakeupComponent::UVoiceWakeupComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetWakeupState(EVoiceWakeupState::Idle);
}

bool UVoiceWakeupComponent::StartListening()
{
	if (bIsListening)
	{
		return true;
	}

	const FVoiceWakeupStartRequest Request = BuildStartRequest();
	OnWakeupInitialized.Broadcast(MakeProviderEvent(NAME_None, EVoiceRouteSource::None, TEXT("Wakeup component initialized request.")));

	SetWakeupState(EVoiceWakeupState::Initializing);
	SetVoiceComponentState(EVoiceComponentState::Starting);

	FString LastMessage = TEXT("No wakeup provider candidates available.");
	const TArray<FVoiceProviderRouteCandidate> Candidates = FVoiceRouteResolver::BuildCandidates(Request.RoutePolicy, Request.OnlineProvider, Request.OfflineProvider);
	for (int32 Index = 0; Index < Candidates.Num(); ++Index)
	{
		const FVoiceProviderRouteCandidate& Candidate = Candidates[Index];
		IVoiceWakeupServiceFeatureInterface* Feature = IVoiceWakeupServiceFeatureInterface::FindFeatureByName(Candidate.ProviderName);
		if (Feature != nullptr && TryStartWithFeature(*Feature, Candidate.RouteSource, Request, LastMessage))
		{
			return true;
		}

		if (Index + 1 < Candidates.Num())
		{
			OnWakeupFallbackTriggered.Broadcast(MakeProviderEvent(Candidate.ProviderName, Candidate.RouteSource, LastMessage));
		}
	}

	SetVoiceError(LastMessage);
	SetWakeupState(EVoiceWakeupState::Error);
	OnWakeupError.Broadcast(MakeProviderEvent(NAME_None, EVoiceRouteSource::None, LastMessage));
	ForwardWakeupErrorToOwner(LastMessage);
	return false;
}

void UVoiceWakeupComponent::StopListening()
{
	if (!bIsListening)
	{
		return;
	}

	if (IVoiceWakeupServiceFeatureInterface* Feature = IVoiceWakeupServiceFeatureInterface::FindFeatureByName(GetSelectedProviderName()))
	{
		Feature->StopListening(*this);
	}
	else
	{
		NotifyProviderStopped(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Wakeup provider already unavailable when stopping."));
	}
}

void UVoiceWakeupComponent::RestartListening()
{
	StopListening();
	StartListening();
}

void UVoiceWakeupComponent::SimulateWakeup(const FString& InKeyword, const float InConfidence, const FString& InMessage)
{
	if (!bIsListening)
	{
		NotifyProviderError(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Cannot simulate wakeup while component is not listening."));
		return;
	}

	NotifyWakeupDetected(GetSelectedProviderName(), GetSelectedRouteSource(), InKeyword, InConfidence, InMessage);
}

void UVoiceWakeupComponent::NotifyProviderListeningStarted(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage)
{
	bIsListening = true;
	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Running);
	SetWakeupState(EVoiceWakeupState::Listening);

	const FVoiceWakeupProviderEvent Event = MakeProviderEvent(InProviderName, InRouteSource, InMessage);
	OnWakeupProviderChanged.Broadcast(Event);
	OnWakeupRouteChanged.Broadcast(Event);
	OnWakeupStarted.Broadcast(Event);
	OnWakeupListening.Broadcast(Event);
}

void UVoiceWakeupComponent::NotifyProviderStopped(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage)
{
	bIsListening = false;
	bIsCoolingDown = false;
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(CooldownTimerHandle);
	}

	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Ready);
	SetWakeupState(EVoiceWakeupState::Stopped);
	OnWakeupStopped.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InMessage));
}

void UVoiceWakeupComponent::NotifyProviderError(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InErrorMessage)
{
	UE_LOG(LogVoiceWakeup, Error, TEXT("Wakeup provider '%s' failed. Route=%d Message=%s"),
		*InProviderName.ToString(),
		static_cast<int32>(InRouteSource),
		*InErrorMessage);

	SetVoiceRouteInfo(InProviderName, InRouteSource, InErrorMessage);
	SetVoiceError(InErrorMessage);
	SetWakeupState(EVoiceWakeupState::Error);
	OnWakeupError.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InErrorMessage));
	ForwardWakeupErrorToOwner(InErrorMessage);
}

void UVoiceWakeupComponent::NotifyWakeupDetected(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InKeyword, const float InConfidence, const FString& InMessage)
{
	FVoiceWakeupResult Result;
	Result.bSuccessful = true;
	Result.ProviderName = InProviderName;
	Result.RouteSource = InRouteSource;
	Result.Keyword = InKeyword;
	Result.Confidence = InConfidence;
	Result.Message = InMessage;

	if (bIsCoolingDown)
	{
		OnWakeupRejected.Broadcast(Result);
		return;
	}

	UE_LOG(LogVoiceWakeup, Log, TEXT("Wakeup detected. Provider=%s Route=%d Keyword=%s Confidence=%.3f"),
		*InProviderName.ToString(),
		static_cast<int32>(InRouteSource),
		*InKeyword,
		InConfidence);

	OnWakeupDetectedEvent.Broadcast(Result);
	ForwardWakeupToOwner(Result);
	EnterCooldown(Result);
}

void UVoiceWakeupComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StopListening();
	Super::EndPlay(EndPlayReason);
}

FVoiceWakeupStartRequest UVoiceWakeupComponent::BuildStartRequest() const
{
	FVoiceWakeupStartRequest Request;
	Request.RoutePolicy = RoutePolicy;
	Request.OnlineProvider = OnlineProvider;
	Request.OfflineProvider = OfflineProvider;
	Request.Language = Language;
	Request.Keywords = Keywords;
	Request.Sensitivity = Sensitivity;
	Request.CooldownSeconds = CooldownSeconds;

	return Request;
}

bool UVoiceWakeupComponent::TryStartWithFeature(IVoiceWakeupServiceFeatureInterface& InFeature, const EVoiceRouteSource InRouteSource, const FVoiceWakeupStartRequest& InRequest, FString& OutMessage)
{
	if (InRouteSource == EVoiceRouteSource::Online && !bEnableOnlineRoute)
	{
		OutMessage = TEXT("Online wakeup is disabled.");
		return false;
	}

	if (InRouteSource == EVoiceRouteSource::Offline && !bEnableOfflineRoute)
	{
		OutMessage = TEXT("Offline wakeup is disabled.");
		return false;
	}

	return InFeature.StartListening(*this, InRequest, OutMessage);
}

void UVoiceWakeupComponent::SetWakeupState(const EVoiceWakeupState InState)
{
	if (WakeupState == InState)
	{
		return;
	}

	WakeupState = InState;
	OnWakeupStateChanged.Broadcast(WakeupState);
	ForwardWakeupStateToOwner(WakeupState);
}

void UVoiceWakeupComponent::EnterCooldown(const FVoiceWakeupResult& InResult)
{
	const FVoiceWakeupStartRequest Request = BuildStartRequest();
	if (Request.CooldownSeconds <= 0.0f)
	{
		return;
	}

	if (UWorld* World = GetWorld())
	{
		bIsCoolingDown = true;
		SetWakeupState(EVoiceWakeupState::Cooldown);
		OnWakeupCooldownStarted.Broadcast(MakeProviderEvent(InResult.ProviderName, InResult.RouteSource, TEXT("Wakeup cooldown started.")));
		World->GetTimerManager().SetTimer(CooldownTimerHandle, this, &UVoiceWakeupComponent::LeaveCooldown, Request.CooldownSeconds, false);
	}
}

void UVoiceWakeupComponent::LeaveCooldown()
{
	bIsCoolingDown = false;
	SetWakeupState(bIsListening ? EVoiceWakeupState::Listening : EVoiceWakeupState::Stopped);
	OnWakeupCooldownFinished.Broadcast(MakeProviderEvent(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Wakeup cooldown finished.")));
}

void UVoiceWakeupComponent::ForwardWakeupToOwner(const FVoiceWakeupResult& InResult) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceWakeupInterface::StaticClass()))
		{
			IVoiceWakeupInterface::Execute_OnWakeupDetected(OwnerActor, InResult);
		}
	}
}

void UVoiceWakeupComponent::ForwardWakeupErrorToOwner(const FString& InMessage) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceWakeupInterface::StaticClass()))
		{
			IVoiceWakeupInterface::Execute_OnWakeupError(OwnerActor, InMessage);
		}
	}
}

void UVoiceWakeupComponent::ForwardWakeupStateToOwner(const EVoiceWakeupState InState) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceWakeupInterface::StaticClass()))
		{
			IVoiceWakeupInterface::Execute_OnWakeupStateChanged(OwnerActor, InState);
		}
	}
}

FVoiceWakeupProviderEvent UVoiceWakeupComponent::MakeProviderEvent(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage) const
{
	FVoiceWakeupProviderEvent Event;
	Event.ProviderName = InProviderName;
	Event.RouteSource = InRouteSource;
	Event.Message = InMessage;
	return Event;
}
