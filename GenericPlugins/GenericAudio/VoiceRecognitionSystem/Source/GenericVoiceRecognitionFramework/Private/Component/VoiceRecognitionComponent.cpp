// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Component/VoiceRecognitionComponent.h"

#include "Interface/VoiceRecognitionInterface.h"
#include "Provider/VoiceRecognitionServiceFeature.h"
#include "Route/VoiceRouteResolver.h"

UVoiceRecognitionComponent::UVoiceRecognitionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetRecognitionState(EVoiceRecognitionState::Idle);
}

bool UVoiceRecognitionComponent::StartRecognition()
{
	if (bIsRecognizing)
	{
		return true;
	}

	const FVoiceRecognitionStartRequest Request = BuildStartRequest();
	OnRecognitionInitialized.Broadcast(MakeProviderEvent(NAME_None, EVoiceRouteSource::None, TEXT("Recognition component initialized request.")));

	SetRecognitionState(EVoiceRecognitionState::Initializing);
	SetVoiceComponentState(EVoiceComponentState::Starting);

	FString LastMessage = TEXT("No recognition provider candidates available.");
	const TArray<FVoiceProviderRouteCandidate> Candidates = FVoiceRouteResolver::BuildCandidates(Request.RoutePolicy, Request.OnlineProvider, Request.OfflineProvider);
	for (const FVoiceProviderRouteCandidate& Candidate : Candidates)
	{
		if (IVoiceRecognitionServiceFeatureInterface* Feature = IVoiceRecognitionServiceFeatureInterface::FindFeatureByName(Candidate.ProviderName))
		{
			if (TryStartWithFeature(*Feature, Candidate.RouteSource, Request, LastMessage))
			{
				return true;
			}
		}
	}

	SetVoiceError(LastMessage);
	SetRecognitionState(EVoiceRecognitionState::Error);
	OnRecognitionError.Broadcast(MakeProviderEvent(NAME_None, EVoiceRouteSource::None, LastMessage));
	ForwardErrorToOwner(LastMessage);
	return false;
}

void UVoiceRecognitionComponent::StopRecognition()
{
	if (!bIsRecognizing)
	{
		return;
	}

	if (IVoiceRecognitionServiceFeatureInterface* Feature = IVoiceRecognitionServiceFeatureInterface::FindFeatureByName(GetSelectedProviderName()))
	{
		Feature->StopRecognition(*this);
	}
	else
	{
		NotifyProviderRecognitionStopped(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Recognition provider already unavailable when stopping."));
	}
}

void UVoiceRecognitionComponent::RestartRecognition()
{
	StopRecognition();
	StartRecognition();
}

bool UVoiceRecognitionComponent::SubmitAudioPcm16Bytes(const TArray<uint8>& InAudioPcm16Bytes, const int32 InSampleRate, const int32 InNumChannels)
{
	if (!bIsRecognizing)
	{
		NotifyProviderRecognitionError(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Recognition component is not active."));
		return false;
	}

	IVoiceRecognitionServiceFeatureInterface* Feature = IVoiceRecognitionServiceFeatureInterface::FindFeatureByName(GetSelectedProviderName());
	if (Feature == nullptr)
	{
		NotifyProviderRecognitionError(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Recognition provider feature is unavailable."));
		return false;
	}

	FString Message;
	const bool bSuccess = Feature->SubmitAudio(*this, InAudioPcm16Bytes, InSampleRate, InNumChannels, Message);
	if (!bSuccess)
	{
		NotifyProviderRecognitionError(GetSelectedProviderName(), GetSelectedRouteSource(), Message);
	}
	else
	{
		UE_LOG(LogVoiceRecognition, Verbose, TEXT("Recognition audio buffer submitted. Provider=%s Bytes=%d SampleRate=%d NumChannels=%d"),
			*GetSelectedProviderName().ToString(),
			InAudioPcm16Bytes.Num(),
			InSampleRate,
			InNumChannels);
	}

	return bSuccess;
}

bool UVoiceRecognitionComponent::RecognizeAudioFile(const FString& InAudioFilePath)
{
	if (!bIsRecognizing)
	{
		NotifyProviderRecognitionError(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Recognition component is not active."));
		return false;
	}

	IVoiceRecognitionServiceFeatureInterface* Feature = IVoiceRecognitionServiceFeatureInterface::FindFeatureByName(GetSelectedProviderName());
	if (Feature == nullptr)
	{
		NotifyProviderRecognitionError(GetSelectedProviderName(), GetSelectedRouteSource(), TEXT("Recognition provider feature is unavailable."));
		return false;
	}

	FString Message;
	const bool bSuccess = Feature->SubmitAudioFile(*this, InAudioFilePath, Message);
	if (!bSuccess)
	{
		NotifyProviderRecognitionError(GetSelectedProviderName(), GetSelectedRouteSource(), Message);
	}

	return bSuccess;
}

void UVoiceRecognitionComponent::SimulatePartialResult(const FString& InText, const float InConfidence, const FString& InMessage)
{
	NotifyRecognitionPartial(GetSelectedProviderName(), GetSelectedRouteSource(), InText, InConfidence, InMessage);
}

void UVoiceRecognitionComponent::SimulateFinalResult(const FString& InText, const float InConfidence, const FString& InMessage)
{
	NotifyRecognitionFinal(GetSelectedProviderName(), GetSelectedRouteSource(), InText, InConfidence, InMessage);
}

void UVoiceRecognitionComponent::NotifyProviderRecognitionStarted(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage)
{
	bIsRecognizing = true;
	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Running);
	SetRecognitionState(EVoiceRecognitionState::Listening);
	OnRecognitionStarted.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InMessage));
}

void UVoiceRecognitionComponent::NotifyProviderRecognitionStopped(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage)
{
	bIsRecognizing = false;
	SetVoiceRouteInfo(InProviderName, InRouteSource, InMessage);
	SetVoiceComponentState(EVoiceComponentState::Ready);
	SetRecognitionState(EVoiceRecognitionState::Stopped);
	OnRecognitionStopped.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InMessage));
}

void UVoiceRecognitionComponent::NotifyProviderRecognitionError(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InErrorMessage)
{
	UE_LOG(LogVoiceRecognition, Error, TEXT("Recognition provider '%s' failed. Route=%d Message=%s"),
		*InProviderName.ToString(),
		static_cast<int32>(InRouteSource),
		*InErrorMessage);

	SetVoiceRouteInfo(InProviderName, InRouteSource, InErrorMessage);
	SetVoiceError(InErrorMessage);
	SetRecognitionState(EVoiceRecognitionState::Error);
	OnRecognitionError.Broadcast(MakeProviderEvent(InProviderName, InRouteSource, InErrorMessage));
	ForwardErrorToOwner(InErrorMessage);
}

void UVoiceRecognitionComponent::NotifyRecognitionPartial(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InText, const float InConfidence, const FString& InMessage)
{
	FVoiceRecognitionResult Result;
	Result.bSuccessful = true;
	Result.bIsFinal = false;
	Result.ProviderName = InProviderName;
	Result.RouteSource = InRouteSource;
	Result.Text = InText;
	Result.Confidence = InConfidence;
	Result.Message = InMessage;

	SetRecognitionState(EVoiceRecognitionState::Recognizing);
	OnRecognitionPartial.Broadcast(Result);
	ForwardPartialToOwner(Result);
}

void UVoiceRecognitionComponent::NotifyRecognitionFinal(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InText, const float InConfidence, const FString& InMessage)
{
	FVoiceRecognitionResult Result;
	Result.bSuccessful = true;
	Result.bIsFinal = true;
	Result.ProviderName = InProviderName;
	Result.RouteSource = InRouteSource;
	Result.Text = InText;
	Result.Confidence = InConfidence;
	Result.Message = InMessage;

	SetRecognitionState(EVoiceRecognitionState::Completed);
	OnRecognitionFinal.Broadcast(Result);
	ForwardFinalToOwner(Result);
}

void UVoiceRecognitionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StopRecognition();
	Super::EndPlay(EndPlayReason);
}

FVoiceRecognitionStartRequest UVoiceRecognitionComponent::BuildStartRequest() const
{
	FVoiceRecognitionStartRequest Request;
	Request.RoutePolicy = RoutePolicy;
	Request.OnlineProvider = OnlineProvider;
	Request.OfflineProvider = OfflineProvider;
	Request.Language = Language;
	Request.SampleRate = SampleRate;
	Request.bEnableVad = bEnableVad;
	Request.bEnablePunctuation = bEnablePunctuation;

	return Request;
}

bool UVoiceRecognitionComponent::TryStartWithFeature(IVoiceRecognitionServiceFeatureInterface& InFeature, const EVoiceRouteSource InRouteSource, const FVoiceRecognitionStartRequest& InRequest, FString& OutMessage)
{
	if (InRouteSource == EVoiceRouteSource::Online && !bEnableOnlineRoute)
	{
		OutMessage = TEXT("Online recognition is disabled.");
		return false;
	}

	if (InRouteSource == EVoiceRouteSource::Offline && !bEnableOfflineRoute)
	{
		OutMessage = TEXT("Offline recognition is disabled.");
		return false;
	}

	return InFeature.StartRecognition(*this, InRequest, OutMessage);
}

void UVoiceRecognitionComponent::SetRecognitionState(const EVoiceRecognitionState InState)
{
	if (RecognitionState == InState)
	{
		return;
	}

	RecognitionState = InState;
	OnRecognitionStateChanged.Broadcast(RecognitionState);
	ForwardStateToOwner(RecognitionState);
}

void UVoiceRecognitionComponent::ForwardStateToOwner(const EVoiceRecognitionState InState) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceRecognitionInterface::StaticClass()))
		{
			IVoiceRecognitionInterface::Execute_OnRecognitionStateChanged(OwnerActor, InState);
		}
	}
}

void UVoiceRecognitionComponent::ForwardPartialToOwner(const FVoiceRecognitionResult& InResult) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceRecognitionInterface::StaticClass()))
		{
			IVoiceRecognitionInterface::Execute_OnRecognitionPartialResult(OwnerActor, InResult);
		}
	}
}

void UVoiceRecognitionComponent::ForwardFinalToOwner(const FVoiceRecognitionResult& InResult) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceRecognitionInterface::StaticClass()))
		{
			IVoiceRecognitionInterface::Execute_OnRecognitionFinalResult(OwnerActor, InResult);
		}
	}
}

void UVoiceRecognitionComponent::ForwardErrorToOwner(const FString& InMessage) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoiceRecognitionInterface::StaticClass()))
		{
			IVoiceRecognitionInterface::Execute_OnRecognitionError(OwnerActor, InMessage);
		}
	}
}

FVoiceRecognitionProviderEvent UVoiceRecognitionComponent::MakeProviderEvent(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InMessage) const
{
	FVoiceRecognitionProviderEvent Event;
	Event.ProviderName = InProviderName;
	Event.RouteSource = InRouteSource;
	Event.Message = InMessage;
	return Event;
}
