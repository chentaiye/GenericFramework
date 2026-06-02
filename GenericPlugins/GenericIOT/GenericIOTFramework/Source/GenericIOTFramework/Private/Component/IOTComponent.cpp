// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Component/IOTComponent.h"

#include "Subsystem/IOTSubsystem.h"

UIOTComponent::UIOTComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UIOTComponent::OnRegister()
{
	Super::OnRegister();
	BindToSubsystem();
	RefreshCachedBinding();
}

void UIOTComponent::OnUnregister()
{
	UnbindFromSubsystem();
	Super::OnUnregister();
}

void UIOTComponent::BindEntityId(const FString& InEntityId)
{
	EntityId = InEntityId.TrimStartAndEnd();
	RefreshCachedBinding();
}

void UIOTComponent::ClearBinding()
{
	EntityId.Reset();
	DeviceId.Reset();
	CurrentDescriptor = FIOTDeviceDescriptor();
	CurrentState = FIOTDeviceState();
}

FString UIOTComponent::ExecuteCommand(const EIOTCapabilityKind CapabilityKind, const FString& CommandName, const TMap<FString, FString>& Parameters)
{
	if (UIOTSubsystem* Subsystem = ResolveSubsystem())
	{
		FIOTCommandRequest Request;
		Request.DeviceId = DeviceId;
		Request.CapabilityKind = CapabilityKind;
		Request.CommandName = CommandName;
		Request.Parameters = Parameters;
		return Subsystem->ExecuteCommand(Request);
	}

	return FString();
}

FString UIOTComponent::ExecuteRawService(const FName Domain, const FName Service, const TMap<FString, FString>& Params)
{
	if (UIOTSubsystem* Subsystem = ResolveSubsystem())
	{
		return Subsystem->ExecuteRawService(DeviceId, Domain, Service, Params);
	}

	return FString();
}

FString UIOTComponent::TurnOn()
{
	return ExecuteCommand(EIOTCapabilityKind::Power, TEXT("TurnOn"), TMap<FString, FString>());
}

FString UIOTComponent::TurnOff()
{
	return ExecuteCommand(EIOTCapabilityKind::Power, TEXT("TurnOff"), TMap<FString, FString>());
}

FString UIOTComponent::Toggle()
{
	return ExecuteCommand(EIOTCapabilityKind::Toggle, TEXT("Toggle"), TMap<FString, FString>());
}

FString UIOTComponent::SetNumericValue(const float InValue)
{
	TMap<FString, FString> Params;
	Params.Add(TEXT("value"), FString::SanitizeFloat(InValue));
	return ExecuteCommand(EIOTCapabilityKind::NumericValue, TEXT("SetValue"), Params);
}

FString UIOTComponent::SetOption(const FString& InOption)
{
	TMap<FString, FString> Params;
	Params.Add(TEXT("option"), InOption);
	return ExecuteCommand(EIOTCapabilityKind::Option, TEXT("SetOption"), Params);
}

FString UIOTComponent::Trigger()
{
	return ExecuteCommand(EIOTCapabilityKind::Trigger, TEXT("Trigger"), TMap<FString, FString>());
}

void UIOTComponent::HandleSubsystemConnectionStateChanged(const EIOTConnectionState InConnectionState)
{
	OnConnectionChanged.Broadcast(InConnectionState);
}

void UIOTComponent::HandleSubsystemDeviceStateChanged(FIOTDeviceDescriptor InDevice, FIOTDeviceState InState)
{
	if (InDevice.EntityId == EntityId || InDevice.DeviceId == DeviceId)
	{
		CurrentDescriptor = MoveTemp(InDevice);
		CurrentState = MoveTemp(InState);
		DeviceId = CurrentDescriptor.DeviceId;
		OnStateChanged.Broadcast(CurrentDescriptor, CurrentState);
	}
}

void UIOTComponent::HandleSubsystemCommandCompleted(FIOTCommandRequest InRequest, FIOTCommandResult InResult)
{
	if (InRequest.DeviceId == DeviceId)
	{
		if (InResult.bSucceeded)
		{
			OnCommandSucceeded.Broadcast(InRequest, InResult);
		}
		else
		{
			OnCommandFailed.Broadcast(InRequest, InResult);
		}
	}
}

void UIOTComponent::BindToSubsystem()
{
	if (UIOTSubsystem* Subsystem = ResolveSubsystem())
	{
		Subsystem->OnConnectionStateChanged.AddDynamic(this, &UIOTComponent::HandleSubsystemConnectionStateChanged);
		Subsystem->OnDeviceStateChanged.AddDynamic(this, &UIOTComponent::HandleSubsystemDeviceStateChanged);
		Subsystem->OnCommandCompleted.AddDynamic(this, &UIOTComponent::HandleSubsystemCommandCompleted);
	}
}

void UIOTComponent::UnbindFromSubsystem()
{
	if (UIOTSubsystem* Subsystem = ResolveSubsystem())
	{
		Subsystem->OnConnectionStateChanged.RemoveAll(this);
		Subsystem->OnDeviceStateChanged.RemoveAll(this);
		Subsystem->OnCommandCompleted.RemoveAll(this);
	}
}

void UIOTComponent::RefreshCachedBinding()
{
	if (EntityId.IsEmpty())
	{
		return;
	}

	if (UIOTSubsystem* Subsystem = ResolveSubsystem())
	{
		FIOTDeviceDescriptor Descriptor;
		if (Subsystem->TryGetDeviceByEntityId(EntityId, Descriptor))
		{
			CurrentDescriptor = Descriptor;
			DeviceId = Descriptor.DeviceId;
			Subsystem->TryGetDeviceState(DeviceId, CurrentState);
		}
	}
}

UIOTSubsystem* UIOTComponent::ResolveSubsystem() const
{
	return UIOTSubsystem::Get(this);
}
