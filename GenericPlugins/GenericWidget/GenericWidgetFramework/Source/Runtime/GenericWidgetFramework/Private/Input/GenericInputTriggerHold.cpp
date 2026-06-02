// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputTriggerHold.h"

EGenericInputTriggerState UGenericInputTriggerHold::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	if (!IsContextActuated(TriggerContext))
	{
		HeldDuration = 0.0f;
		bTriggered = false;
		return EGenericInputTriggerState::None;
	}

	HeldDuration = CalculateHeldDuration(TriggerContext);
	if (HeldDuration < HoldTimeThreshold)
	{
		return EGenericInputTriggerState::Ongoing;
	}

	if (bIsOneShot && bTriggered)
	{
		return EGenericInputTriggerState::Ongoing;
	}

	bTriggered = true;
	return EGenericInputTriggerState::Triggered;
}

void UGenericInputTriggerHold::Reset()
{
	Super::Reset();
	bTriggered = false;
}
