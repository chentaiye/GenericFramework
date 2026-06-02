// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/SubscribeIOTRealtimeAsyncAction.h"

#include "Subsystem/IOTSubsystem.h"

USubscribeIOTRealtimeAsyncAction* USubscribeIOTRealtimeAsyncAction::SubscribeIOTRealtime(const UObject* WorldContextObject)
{
	USubscribeIOTRealtimeAsyncAction* Action = NewObject<USubscribeIOTRealtimeAsyncAction>();
	Action->WorldContextObject = const_cast<UObject*>(WorldContextObject);
	return Action;
}

void USubscribeIOTRealtimeAsyncAction::Activate()
{
	UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject);
	if (!Subsystem)
	{
		FinishError(TEXT("Unable to resolve IOT Subsystem"));
		return;
	}

	if (Subsystem->IsRealtimeActive())
	{
		FinishSuccess();
		return;
	}

	Subsystem->OnRealtimeStateChanged.AddDynamic(this, &USubscribeIOTRealtimeAsyncAction::HandleRealtimeStateChanged);
	Subsystem->OnConnectionStateChanged.AddDynamic(this, &USubscribeIOTRealtimeAsyncAction::HandleConnectionStateChanged);
	if (!Subsystem->SubscribeRealtime())
	{
		FinishError(TEXT("Failed to start realtime subscription"));
	}
}

void USubscribeIOTRealtimeAsyncAction::HandleRealtimeStateChanged(const bool bInRealtimeActive)
{
	if (bInRealtimeActive)
	{
		FinishSuccess();
	}
}

void USubscribeIOTRealtimeAsyncAction::HandleConnectionStateChanged(const EIOTConnectionState InConnectionState)
{
	if (InConnectionState == EIOTConnectionState::Error)
	{
		if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
		{
			FinishError(Subsystem->GetLastErrorMessage());
		}
		else
		{
			FinishError(TEXT("Realtime subscription failed"));
		}
	}
}

void USubscribeIOTRealtimeAsyncAction::FinishSuccess()
{
	if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
	{
		Subsystem->OnRealtimeStateChanged.RemoveAll(this);
		Subsystem->OnConnectionStateChanged.RemoveAll(this);
	}

	OnSuccess.Broadcast();
	SetReadyToDestroy();
}

void USubscribeIOTRealtimeAsyncAction::FinishError(const FString& InErrorMessage)
{
	if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
	{
		Subsystem->OnRealtimeStateChanged.RemoveAll(this);
		Subsystem->OnConnectionStateChanged.RemoveAll(this);
	}

	OnError.Broadcast(InErrorMessage.IsEmpty() ? TEXT("Realtime subscription failed") : InErrorMessage);
	SetReadyToDestroy();
}
