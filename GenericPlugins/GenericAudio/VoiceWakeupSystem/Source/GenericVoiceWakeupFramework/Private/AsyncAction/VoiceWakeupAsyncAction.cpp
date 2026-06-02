// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/VoiceWakeupAsyncAction.h"

#include "Component/VoiceWakeupComponent.h"

UVoiceWakeupAsyncAction* UVoiceWakeupAsyncAction::StartWakeup(UVoiceWakeupComponent* InWakeupComponent)
{
	UVoiceWakeupAsyncAction* Action = NewObject<UVoiceWakeupAsyncAction>();
	Action->WakeupComponent = InWakeupComponent;
	return Action;
}

void UVoiceWakeupAsyncAction::Activate()
{
	if (WakeupComponent == nullptr)
	{
		OnError.Broadcast(MakeErrorEvent(TEXT("Wakeup component is null.")));
		SetReadyToDestroy();
		return;
	}

	WakeupComponent->OnWakeupStarted.AddDynamic(this, &UVoiceWakeupAsyncAction::HandleStarted);
	WakeupComponent->OnWakeupDetectedEvent.AddDynamic(this, &UVoiceWakeupAsyncAction::HandleDetected);
	WakeupComponent->OnWakeupError.AddDynamic(this, &UVoiceWakeupAsyncAction::HandleError);
	bBound = true;

	if (!WakeupComponent->StartListening() && bBound)
	{
		HandleError(MakeErrorEvent(TEXT("StartWakeup failed.")));
	}
}

void UVoiceWakeupAsyncAction::HandleStarted(FVoiceWakeupProviderEvent InEvent)
{
	OnStarted.Broadcast(InEvent);
}

void UVoiceWakeupAsyncAction::HandleDetected(FVoiceWakeupResult InResult)
{
	OnDetected.Broadcast(InResult);
}

void UVoiceWakeupAsyncAction::HandleError(FVoiceWakeupProviderEvent InEvent)
{
	OnError.Broadcast(InEvent);
	Unbind();
	SetReadyToDestroy();
}

void UVoiceWakeupAsyncAction::Unbind()
{
	if (!bBound || WakeupComponent == nullptr)
	{
		return;
	}

	WakeupComponent->OnWakeupStarted.RemoveDynamic(this, &UVoiceWakeupAsyncAction::HandleStarted);
	WakeupComponent->OnWakeupDetectedEvent.RemoveDynamic(this, &UVoiceWakeupAsyncAction::HandleDetected);
	WakeupComponent->OnWakeupError.RemoveDynamic(this, &UVoiceWakeupAsyncAction::HandleError);
	bBound = false;
}

FVoiceWakeupProviderEvent UVoiceWakeupAsyncAction::MakeErrorEvent(const FString& InMessage)
{
	FVoiceWakeupProviderEvent Event;
	Event.Message = InMessage;
	return Event;
}
