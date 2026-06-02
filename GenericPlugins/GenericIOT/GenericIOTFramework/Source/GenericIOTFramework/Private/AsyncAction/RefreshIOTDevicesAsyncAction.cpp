// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/RefreshIOTDevicesAsyncAction.h"

#include "Subsystem/IOTSubsystem.h"

URefreshIOTDevicesAsyncAction* URefreshIOTDevicesAsyncAction::RefreshIOTDevices(const UObject* WorldContextObject)
{
	URefreshIOTDevicesAsyncAction* Action = NewObject<URefreshIOTDevicesAsyncAction>();
	Action->WorldContextObject = const_cast<UObject*>(WorldContextObject);
	return Action;
}

void URefreshIOTDevicesAsyncAction::Activate()
{
	UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject);
	if (!Subsystem)
	{
		FinishError(TEXT("Unable to resolve IOT Subsystem"));
		return;
	}

	Subsystem->OnDevicesRefreshed.AddDynamic(this, &URefreshIOTDevicesAsyncAction::HandleDevicesRefreshed);
	Subsystem->OnConnectionStateChanged.AddDynamic(this, &URefreshIOTDevicesAsyncAction::HandleConnectionStateChanged);
	if (!Subsystem->RefreshDevices())
	{
		FinishError(TEXT("Failed to start device refresh"));
	}
}

void URefreshIOTDevicesAsyncAction::HandleDevicesRefreshed(const int32 InDeviceCount)
{
	FinishSuccess(InDeviceCount);
}

void URefreshIOTDevicesAsyncAction::HandleConnectionStateChanged(const EIOTConnectionState InConnectionState)
{
	if (InConnectionState == EIOTConnectionState::Error)
	{
		if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
		{
			FinishError(Subsystem->GetLastErrorMessage());
		}
		else
		{
			FinishError(TEXT("Device refresh failed"));
		}
	}
}

void URefreshIOTDevicesAsyncAction::FinishSuccess(const int32 InDeviceCount)
{
	if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
	{
		Subsystem->OnDevicesRefreshed.RemoveAll(this);
		Subsystem->OnConnectionStateChanged.RemoveAll(this);
	}

	OnSuccess.Broadcast(InDeviceCount);
	SetReadyToDestroy();
}

void URefreshIOTDevicesAsyncAction::FinishError(const FString& InErrorMessage)
{
	if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
	{
		Subsystem->OnDevicesRefreshed.RemoveAll(this);
		Subsystem->OnConnectionStateChanged.RemoveAll(this);
	}

	OnError.Broadcast(InErrorMessage.IsEmpty() ? TEXT("Device refresh failed") : InErrorMessage);
	SetReadyToDestroy();
}
