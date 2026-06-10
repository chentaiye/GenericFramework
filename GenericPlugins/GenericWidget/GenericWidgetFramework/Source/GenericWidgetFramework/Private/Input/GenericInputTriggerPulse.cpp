// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputTriggerPulse.h"

EGenericInputTriggerState UGenericInputTriggerPulse::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	if (!IsContextActuated(TriggerContext))
	{
		Reset();
		return EGenericInputTriggerState::None;
	}

	HeldDuration = CalculateHeldDuration(TriggerContext);
	const int32 DesiredTriggerCount = (bTriggerOnStart ? 1 : 0) + FMath::FloorToInt(HeldDuration / FMath::Max(Interval, UE_SMALL_NUMBER));
	if (DesiredTriggerCount > TriggerCount && (TriggerLimit <= 0 || TriggerCount < TriggerLimit))
	{
		++TriggerCount;
		return EGenericInputTriggerState::Triggered;
	}

	return EGenericInputTriggerState::Ongoing;
}

void UGenericInputTriggerPulse::Reset()
{
	Super::Reset();
	TriggerCount = 0;
}
