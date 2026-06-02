// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/VoicePlaybackAsyncAction.h"

#include "Component/VoicePlaybackComponent.h"
#include "Sound/SoundBase.h"

UVoicePlaybackAsyncAction* UVoicePlaybackAsyncAction::PlaySound(UVoicePlaybackComponent* InPlaybackComponent, USoundBase* InSound, const float InVolumeMultiplier, const float InPitchMultiplier, const bool bInLooping)
{
	UVoicePlaybackAsyncAction* Action = NewObject<UVoicePlaybackAsyncAction>();
	Action->PlaybackComponent = InPlaybackComponent;
	Action->Sound = InSound;
	Action->VolumeMultiplier = InVolumeMultiplier;
	Action->PitchMultiplier = InPitchMultiplier;
	Action->bLooping = bInLooping;
	return Action;
}

void UVoicePlaybackAsyncAction::Activate()
{
	if (PlaybackComponent == nullptr)
	{
		OnError.Broadcast(MakeErrorEvent(TEXT("Playback component is null.")));
		SetReadyToDestroy();
		return;
	}

	PlaybackComponent->OnPlaybackStarted.AddDynamic(this, &UVoicePlaybackAsyncAction::HandleStarted);
	PlaybackComponent->OnPlaybackCompletedEvent.AddDynamic(this, &UVoicePlaybackAsyncAction::HandleCompleted);
	PlaybackComponent->OnPlaybackError.AddDynamic(this, &UVoicePlaybackAsyncAction::HandleError);
	bBound = true;

	if (!PlaybackComponent->PlaySound(Sound, VolumeMultiplier, PitchMultiplier, bLooping) && bBound)
	{
		HandleError(MakeErrorEvent(TEXT("PlaySound failed.")));
	}
}

void UVoicePlaybackAsyncAction::HandleStarted(FVoicePlaybackEvent InEvent)
{
	OnStarted.Broadcast(InEvent);
}

void UVoicePlaybackAsyncAction::HandleCompleted(FVoicePlaybackEvent InEvent)
{
	OnCompleted.Broadcast(InEvent);
	Unbind();
	SetReadyToDestroy();
}

void UVoicePlaybackAsyncAction::HandleError(FVoicePlaybackEvent InEvent)
{
	OnError.Broadcast(InEvent);
	Unbind();
	SetReadyToDestroy();
}

void UVoicePlaybackAsyncAction::Unbind()
{
	if (!bBound || PlaybackComponent == nullptr)
	{
		return;
	}

	PlaybackComponent->OnPlaybackStarted.RemoveDynamic(this, &UVoicePlaybackAsyncAction::HandleStarted);
	PlaybackComponent->OnPlaybackCompletedEvent.RemoveDynamic(this, &UVoicePlaybackAsyncAction::HandleCompleted);
	PlaybackComponent->OnPlaybackError.RemoveDynamic(this, &UVoicePlaybackAsyncAction::HandleError);
	bBound = false;
}

FVoicePlaybackEvent UVoicePlaybackAsyncAction::MakeErrorEvent(const FString& InMessage)
{
	FVoicePlaybackEvent Event;
	Event.Message = InMessage;
	return Event;
}
