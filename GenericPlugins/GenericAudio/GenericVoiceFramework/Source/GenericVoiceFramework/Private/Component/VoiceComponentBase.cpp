// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Component/VoiceComponentBase.h"

UVoiceComponentBase::UVoiceComponentBase()
{
	PrimaryComponentTick.bCanEverTick = false;
	VoiceComponentState = EVoiceComponentState::Ready;
}

void UVoiceComponentBase::SetVoiceComponentState(const EVoiceComponentState InState)
{
	if (VoiceComponentState == InState)
	{
		return;
	}

	const EVoiceComponentState PreviousState = VoiceComponentState;
	VoiceComponentState = InState;
	OnVoiceComponentStateChanged.Broadcast(this, PreviousState, VoiceComponentState);
}

void UVoiceComponentBase::SetVoiceRouteInfo(const FName InProviderName, const EVoiceRouteSource InRouteSource, const FString& InStatusMessage)
{
	SelectedProviderName = InProviderName;
	SelectedRouteSource = InRouteSource;
	LastStatusMessage = InStatusMessage;
	LastErrorMessage.Reset();
}

void UVoiceComponentBase::SetVoiceError(const FString& InErrorMessage)
{
	LastErrorMessage = InErrorMessage;
	LastStatusMessage = InErrorMessage;
	SetVoiceComponentState(EVoiceComponentState::Error);
}
