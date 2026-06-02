// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/ConnectIOTPlatformAsyncAction.h"

#include "Subsystem/IOTSubsystem.h"

UConnectIOTPlatformAsyncAction* UConnectIOTPlatformAsyncAction::ConnectIOTPlatform(const UObject* WorldContextObject, FIOTPlatformEndpointConfig InEndpointConfig, const bool bApplyEndpointConfig)
{
	UConnectIOTPlatformAsyncAction* Action = NewObject<UConnectIOTPlatformAsyncAction>();
	Action->WorldContextObject = const_cast<UObject*>(WorldContextObject);
	Action->EndpointConfig = MoveTemp(InEndpointConfig);
	Action->bShouldApplyEndpointConfig = bApplyEndpointConfig;
	return Action;
}

void UConnectIOTPlatformAsyncAction::Activate()
{
	UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject);
	if (!Subsystem)
	{
		FinishError(TEXT("Unable to resolve IOT Subsystem"));
		return;
	}

	if (bShouldApplyEndpointConfig)
	{
		Subsystem->SetEndpointConfig(EndpointConfig);
	}

	if (Subsystem->IsConnected())
	{
		FinishSuccess();
		return;
	}

	Subsystem->OnConnectionStateChanged.AddDynamic(this, &UConnectIOTPlatformAsyncAction::HandleConnectionStateChanged);
	if (!Subsystem->ConnectHomeAssistant())
	{
		FinishError(TEXT("Failed to start platform connection"));
	}
}

void UConnectIOTPlatformAsyncAction::HandleConnectionStateChanged(const EIOTConnectionState InConnectionState)
{
	UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject);
	if (!Subsystem)
	{
		FinishError(TEXT("IOT Subsystem is no longer valid"));
		return;
	}

	if (InConnectionState == EIOTConnectionState::Connected)
	{
		FinishSuccess();
	}
	else if (InConnectionState == EIOTConnectionState::Error)
	{
		FinishError(Subsystem->GetLastErrorMessage());
	}
}

void UConnectIOTPlatformAsyncAction::FinishSuccess()
{
	if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
	{
		Subsystem->OnConnectionStateChanged.RemoveAll(this);
		OnSuccess.Broadcast(Subsystem->GetEndpointConfig());
	}
	else
	{
		OnSuccess.Broadcast(EndpointConfig);
	}

	SetReadyToDestroy();
}

void UConnectIOTPlatformAsyncAction::FinishError(const FString& InErrorMessage)
{
	if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
	{
		Subsystem->OnConnectionStateChanged.RemoveAll(this);
	}

	OnError.Broadcast(InErrorMessage.IsEmpty() ? TEXT("Platform connection failed") : InErrorMessage);
	SetReadyToDestroy();
}
