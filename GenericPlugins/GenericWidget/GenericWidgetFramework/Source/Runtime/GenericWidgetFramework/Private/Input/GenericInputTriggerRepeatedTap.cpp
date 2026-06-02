// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputTriggerRepeatedTap.h"

EGenericInputTriggerState UGenericInputTriggerRepeatedTap::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	if (LastTapTime > 0.0 && TriggerContext.CurrentTime - LastTapTime > RepeatDelay)
	{
		TapCount = 0;
		LastTapTime = 0.0;
		HeldDuration = 0.0f;
		return EGenericInputTriggerState::None;
	}

	if (IsContextActuated(TriggerContext))
	{
		HeldDuration = CalculateHeldDuration(TriggerContext);
		return EGenericInputTriggerState::Ongoing;
	}

	if (!TriggerContext.bWasPressed)
	{
		HeldDuration = 0.0f;
		return TapCount > 0 ? EGenericInputTriggerState::Ongoing : EGenericInputTriggerState::None;
	}

	const float ReleasedHeldDuration = TriggerContext.HeldDuration > 0.0f ? TriggerContext.HeldDuration : HeldDuration;
	HeldDuration = 0.0f;
	if (ReleasedHeldDuration > TapReleaseTimeThreshold)
	{
		TapCount = 0;
		LastTapTime = 0.0;
		return EGenericInputTriggerState::None;
	}

	++TapCount;
	LastTapTime = TriggerContext.CurrentTime;
	if (TapCount >= NumberOfTapsWhichTriggerRepeat)
	{
		TapCount = 0;
		LastTapTime = 0.0;
		return EGenericInputTriggerState::Triggered;
	}

	return EGenericInputTriggerState::Ongoing;
}

void UGenericInputTriggerRepeatedTap::Reset()
{
	Super::Reset();
	TapCount = 0;
	LastTapTime = 0.0;
}
