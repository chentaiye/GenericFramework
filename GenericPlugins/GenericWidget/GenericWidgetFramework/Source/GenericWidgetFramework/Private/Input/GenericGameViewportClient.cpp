// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericGameViewportClient.h"

#include "Engine/Engine.h"
#include "Engine/LocalPlayer.h"
#include "Subsystem/GenericActionSubsystem.h"

namespace
{
	UGenericActionSubsystem* GetActionSubsystem(ULocalPlayer* LocalPlayer)
	{
		return UGenericActionSubsystem::Get(LocalPlayer);
	}

	ULocalPlayer* GetLocalPlayerFromInputDevice(const UGameViewportClient* ViewportClient, FInputDeviceId InputDevice)
	{
		return GEngine ? GEngine->GetLocalPlayerFromInputDevice(ViewportClient, InputDevice) : nullptr;
	}

}

bool UGenericGameViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	if (UGenericActionSubsystem* ActionSubsystem = GetActionSubsystem(GetLocalPlayerFromInputDevice(this, EventArgs.InputDevice)))
	{
		if (ActionSubsystem->HandleViewportInputKey(EventArgs))
		{
			return true;
		}
	}

	return Super::InputKey(EventArgs);
}

bool UGenericGameViewportClient::InputTouch(FViewport* InViewport, const FInputDeviceId DeviceId, uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, uint32 TouchpadIndex, const uint64 Timestamp)
{
	if (UGenericActionSubsystem* ActionSubsystem = GetActionSubsystem(GetLocalPlayerFromInputDevice(this, DeviceId)))
	{
		if (ActionSubsystem->HandleViewportInputTouch(InViewport, DeviceId, Handle, Type, TouchLocation, Force, TouchpadIndex, Timestamp))
		{
			return true;
		}
	}

	return Super::InputTouch(InViewport, DeviceId, Handle, Type, TouchLocation, Force, TouchpadIndex, Timestamp);
}
