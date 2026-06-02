// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Component/VoiceSynthesisComponent.h"

#include "Interface/VoiceSynthesisInterface.h"
#include "Provider/VoiceSynthesisServiceFeature.h"
#include "Route/VoiceRouteResolver.h"

UVoiceSynthesisComponent::UVoiceSynthesisComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetSynthesisState(EVoiceSynthesisState::Idle);
}

bool UVoiceSynthesisComponent::SynthesizeText(const FString& InText, const FString& InOutputFilePath)
{
	if (bIsSynthesizing)
	{
		return true;
	}

	if (InText.TrimStartAndEnd().IsEmpty())
	{
		NotifyProviderSynthesisError(NAME_None, EVoiceRouteSource::None, TEXT("Synthesis text is empty."));
		return false;
	}

	const FVoiceSynthesisRequest Request = BuildRequest(InText, InOutputFilePath);
	OnSynthesisInitialized.Broadcast(MakeProviderEvent(NAME_None, EVoiceRouteSource::None, TEXT("Synthesis request initialized.")));

	SetSynthesisState(EVoiceSynthesisState::Initializing);
	SetVoiceComponentState(EVoiceComponentState::Starting);

	FString LastMessage = TEXT("No synthesis provider candidates available.");
	const TArray<FVoiceProviderRouteCandidate> Candidates = FVoiceRouteResolver::BuildCandidates(Request.RoutePolicy, Request.OnlineProvider, Request.OfflineProvider);
	for (const FVoiceProviderRouteCandidate& Candidate : Candidates)
	{
		if (IVoiceSynthesisServiceFeatureInterface* Feature = IVoiceSynthesisServiceFeatureInterface::FindFeatureByName(Candidate.ProviderName))
		{
			if (TryStartWithFeature(*Feature, Candidate.RouteSource, Request, LastMessage))
			{
				return true;
			}
		}
	}

	NotifyProviderSynthesisError(NAME_None, EVoiceRouteSource::None, LastMessage);
	return false;
}

void UVoiceSynthesisComponent::CancelSynthesis()
{
	if (!bIsSynthesizing)
	{
		return;
	}

	if (IVoiceSynthesisServiceFeatureInterface* Feature = IVoiceSynthesisServiceFeatureInterface::FindFeatureByName(GetSelectedProviderName()))
	{
		Feature->CancelSynthesis(*this);
	}
	else
	{
		NotifyProviderSynthesisStopped(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Synthesis provider already unavailable when cancelling."));
	}
}

void UVoiceSynthesisComponent::SimulateSynthesisCompleted(const FString& InText, const FString& InAudioFilePath, const FString& InMessage)
{
	NotifyProviderSynthesisCompleted(GetSelectedProviderName(), GetSelectedRouteSource(), InText, InAudioFilePath, InMessage);
}

void UVoiceSynthesisComponent::NotifyProviderSynthesisStarted(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage)
{
	bIsSynthesizing = true;
	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Running);
	SetSynthesisState(EVoiceSynthesisState::Synthesizing);
	OnSynthesisStarted.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InMessage));
}

void UVoiceSynthesisComponent::NotifyProviderSynthesisCompleted(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InText, const FString& InAudioFilePath, const FString& InMessage)
{
	bIsSynthesizing = false;
	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Ready);
	SetSynthesisState(EVoiceSynthesisState::Completed);

	FVoiceSynthesisResult Result;
	Result.bSuccessful = true;
	Result.ProviderName = InProviderName;
	Result.RouteSource = InRouteSource;
	Result.Text = InText;
	Result.AudioFilePath = InAudioFilePath;
	Result.Message = InMessage;

	OnSynthesisCompletedEvent.Broadcast(Result);
	ForwardResultToOwner(Result);
}

void UVoiceSynthesisComponent::NotifyProviderSynthesisStopped(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage)
{
	bIsSynthesizing = false;
	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Ready);
	SetSynthesisState(EVoiceSynthesisState::Stopped);
	OnSynthesisStopped.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InMessage));
}

void UVoiceSynthesisComponent::NotifyProviderSynthesisError(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InErrorMessage)
{
	UE_LOG(LogVoiceSynthesis, Error, TEXT("Synthesis provider '%s' failed. Route=%d Message=%s"),
		*InProviderName.ToString(),
		static_cast<int32>(InRouteSource),
		*InErrorMessage);

	SetVoiceRouteInfo(InProviderName, InRouteSource, InErrorMessage);
	SetVoiceError(InErrorMessage);
	SetSynthesisState(EVoiceSynthesisState::Error);
	OnSynthesisError.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InErrorMessage));
	ForwardErrorToOwner(InErrorMessage);
}

void UVoiceSynthesisComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	CancelSynthesis();
	Super::EndPlay(EndPlayReason);
}

FVoiceSynthesisRequest UVoiceSynthesisComponent::BuildRequest(const FString& InText, const FString& InOutputFilePath) const
{
	FVoiceSynthesisRequest Request;
	Request.RoutePolicy = RoutePolicy;
	Request.OnlineProvider = OnlineProvider;
	Request.OfflineProvider = OfflineProvider;
	Request.Language = Language;
	Request.Text = InText;
	Request.VoiceId = VoiceId;
	Request.SpeechRate = SpeechRate;
	Request.Pitch = Pitch;
	Request.Volume = Volume;
	Request.OutputFilePath = InOutputFilePath;

	return Request;
}

bool UVoiceSynthesisComponent::TryStartWithFeature(IVoiceSynthesisServiceFeatureInterface& InFeature, const EVoiceRouteSource InRouteSource, const FVoiceSynthesisRequest& InRequest, FString& OutMessage)
{
	if (InRouteSource == EVoiceRouteSource::Online && !bEnableOnlineRoute)
	{
		OutMessage = TEXT("Online synthesis is disabled.");
		return false;
	}

	if (InRouteSource == EVoiceRouteSource::Offline && !bEnableOfflineRoute)
	{
		OutMessage = TEXT("Offline synthesis is disabled.");
		return false;
	}

	return InFeature.Synthesize(*this, InRequest, OutMessage);
}

void UVoiceSynthesisComponent::SetSynthesisState(const EVoiceSynthesisState InState)
{
	if (SynthesisState == InState)
	{
		return;
	}

	SynthesisState = InState;
	OnSynthesisStateChanged.Broadcast(SynthesisState);
	ForwardStateToOwner(SynthesisState);
}

void UVoiceSynthesisComponent::ForwardStateToOwner(const EVoiceSynthesisState InState) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceSynthesisInterface::StaticClass()))
		{
			IVoiceSynthesisInterface::Execute_OnSynthesisStateChanged(OwnerActor, InState);
		}
	}
}

void UVoiceSynthesisComponent::ForwardResultToOwner(const FVoiceSynthesisResult& InResult) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceSynthesisInterface::StaticClass()))
		{
			IVoiceSynthesisInterface::Execute_OnSynthesisCompleted(OwnerActor, InResult);
		}
	}
}

void UVoiceSynthesisComponent::ForwardErrorToOwner(const FString& InMessage) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceSynthesisInterface::StaticClass()))
		{
			IVoiceSynthesisInterface::Execute_OnSynthesisError(OwnerActor, InMessage);
		}
	}
}

FVoiceSynthesisProviderEvent UVoiceSynthesisComponent::MakeProviderEvent(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage) const
{
	FVoiceSynthesisProviderEvent Event;
	Event.ProviderName = InProviderName;
	Event.RouteSource = InRouteSource;
	Event.Message = InMessage;
	return Event;
}
