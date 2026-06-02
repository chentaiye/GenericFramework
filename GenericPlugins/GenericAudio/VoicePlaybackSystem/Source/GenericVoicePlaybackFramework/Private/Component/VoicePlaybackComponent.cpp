// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Component/VoicePlaybackComponent.h"

#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "Interface/VoicePlaybackInterface.h"
#include "Sound/SoundBase.h"

UVoicePlaybackComponent::UVoicePlaybackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetPlaybackState(EVoicePlaybackState::Idle);
}

bool UVoicePlaybackComponent::PlaySound(USoundBase* InSound, const float InVolumeMultiplier, const float InPitchMultiplier, const bool bInLooping)
{
	(void)bInLooping;

	if (IsPlaying() && !bAllowInterrupt)
	{
		const FString ErrorMessage = TEXT("Playback interrupt is disabled.");
		SetVoiceError(ErrorMessage);
		OnPlaybackError.Broadcast(MakeEvent(ErrorMessage));
		ForwardErrorToOwner(ErrorMessage);
		return false;
	}

	if (InSound == nullptr)
	{
		const FString ErrorMessage = TEXT("Playback sound asset is null.");
		SetVoiceError(ErrorMessage);
		SetPlaybackState(EVoicePlaybackState::Error);
		OnPlaybackError.Broadcast(MakeEvent(ErrorMessage));
		ForwardErrorToOwner(ErrorMessage);
		return false;
	}

	EnsureAudioComponent();
	if (ManagedAudioComponent == nullptr)
	{
		const FString ErrorMessage = TEXT("Playback audio component could not be created.");
		SetVoiceError(ErrorMessage);
		SetPlaybackState(EVoicePlaybackState::Error);
		OnPlaybackError.Broadcast(MakeEvent(ErrorMessage));
		ForwardErrorToOwner(ErrorMessage);
		return false;
	}

	ManagedAudioComponent->Stop();
	ManagedAudioComponent->SetSound(InSound);
	ManagedAudioComponent->SetVolumeMultiplier(InVolumeMultiplier * DefaultVolumeMultiplier);
	ManagedAudioComponent->SetPitchMultiplier(InPitchMultiplier * DefaultPitchMultiplier);
	ManagedAudioComponent->bIsUISound = true;
	ManagedAudioComponent->bAutoDestroy = false;
	ManagedAudioComponent->bAllowSpatialization = false;
	ManagedAudioComponent->Play();

	SetVoiceRouteInfo(TEXT("EnginePlayback"), EVoiceRouteSource::Offline, TEXT("Audio playback started."));
	SetVoiceComponentState(EVoiceComponentState::Running);
	SetPlaybackState(EVoicePlaybackState::Playing);
	OnPlaybackStarted.Broadcast(MakeEvent(TEXT("Playback started.")));
	return true;
}

void UVoicePlaybackComponent::StopPlayback()
{
	if (ManagedAudioComponent != nullptr)
	{
		ManagedAudioComponent->Stop();
	}

	SetVoiceComponentState(EVoiceComponentState::Ready);
	SetPlaybackState(EVoicePlaybackState::Stopped);
	OnPlaybackStopped.Broadcast(MakeEvent(TEXT("Playback stopped.")));
}

void UVoicePlaybackComponent::PausePlayback()
{
	if (ManagedAudioComponent == nullptr || !ManagedAudioComponent->IsPlaying())
	{
		return;
	}

	ManagedAudioComponent->SetPaused(true);
	SetPlaybackState(EVoicePlaybackState::Paused);
	OnPlaybackPaused.Broadcast(MakeEvent(TEXT("Playback paused.")));
}

void UVoicePlaybackComponent::ResumePlayback()
{
	if (ManagedAudioComponent == nullptr)
	{
		return;
	}

	ManagedAudioComponent->SetPaused(false);
	SetPlaybackState(EVoicePlaybackState::Playing);
	OnPlaybackResumed.Broadcast(MakeEvent(TEXT("Playback resumed.")));
}

bool UVoicePlaybackComponent::IsPlaying() const
{
	return ManagedAudioComponent != nullptr && ManagedAudioComponent->IsPlaying();
}

void UVoicePlaybackComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StopPlayback();
	Super::EndPlay(EndPlayReason);
}

void UVoicePlaybackComponent::EnsureAudioComponent()
{
	if (ManagedAudioComponent != nullptr)
	{
		return;
	}

	AActor* OwnerActor = GetOwner();
	if (OwnerActor == nullptr)
	{
		return;
	}

	ManagedAudioComponent = NewObject<UAudioComponent>(OwnerActor, TEXT("VoicePlaybackAudioComponent"));
	if (ManagedAudioComponent == nullptr)
	{
		return;
	}

	ManagedAudioComponent->bAutoActivate = false;
	ManagedAudioComponent->RegisterComponent();
	if (USceneComponent* RootComponent = OwnerActor->GetRootComponent())
	{
		ManagedAudioComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}
	ManagedAudioComponent->OnAudioFinished.AddDynamic(this, &UVoicePlaybackComponent::HandleAudioFinished);
}

void UVoicePlaybackComponent::HandleAudioFinished()
{
	SetVoiceComponentState(EVoiceComponentState::Ready);
	SetPlaybackState(EVoicePlaybackState::Completed);
	OnPlaybackCompletedEvent.Broadcast(MakeEvent(TEXT("Playback completed.")));
	ForwardCompletedToOwner();
}

void UVoicePlaybackComponent::SetPlaybackState(const EVoicePlaybackState InState)
{
	if (PlaybackState == InState)
	{
		return;
	}

	PlaybackState = InState;
	OnPlaybackStateChanged.Broadcast(PlaybackState);
	ForwardStateToOwner(PlaybackState);
}

void UVoicePlaybackComponent::ForwardStateToOwner(const EVoicePlaybackState InState) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoicePlaybackInterface::StaticClass()))
		{
			IVoicePlaybackInterface::Execute_OnPlaybackStateChanged(OwnerActor, InState);
		}
	}
}

void UVoicePlaybackComponent::ForwardCompletedToOwner() const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoicePlaybackInterface::StaticClass()))
		{
			IVoicePlaybackInterface::Execute_OnPlaybackCompleted(OwnerActor);
		}
	}
}

void UVoicePlaybackComponent::ForwardErrorToOwner(const FString& InErrorMessage) const
{
	if (AActor* OwnerActor = GetOwner())
	{
		if (OwnerActor->GetClass()->ImplementsInterface(UVoicePlaybackInterface::StaticClass()))
		{
			IVoicePlaybackInterface::Execute_OnPlaybackError(OwnerActor, InErrorMessage);
		}
	}
}

FVoicePlaybackEvent UVoicePlaybackComponent::MakeEvent(const FString& InMessage) const
{
	FVoicePlaybackEvent Event;
	Event.Message = InMessage;
	return Event;
}
