// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputTriggerTap.h"

EGenericInputTriggerState UGenericInputTriggerTap::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	if (IsContextActuated(TriggerContext))
	{
		HeldDuration = CalculateHeldDuration(TriggerContext);
		return EGenericInputTriggerState::Ongoing;
	}

	if (TriggerContext.bWasPressed)
	{
		const float ReleasedHeldDuration = TriggerContext.HeldDuration > 0.0f ? TriggerContext.HeldDuration : HeldDuration;
		HeldDuration = 0.0f;
		return ReleasedHeldDuration <= TapReleaseTimeThreshold ? EGenericInputTriggerState::Triggered : EGenericInputTriggerState::None;
	}

	HeldDuration = 0.0f;
	return EGenericInputTriggerState::None;
}
