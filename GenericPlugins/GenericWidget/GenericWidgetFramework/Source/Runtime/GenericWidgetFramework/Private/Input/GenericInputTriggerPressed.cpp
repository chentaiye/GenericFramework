// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputTriggerPressed.h"

EGenericInputTriggerState UGenericInputTriggerPressed::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	if (TriggerContext.bIsPressed && !TriggerContext.bWasPressed)
	{
		return EGenericInputTriggerState::Triggered;
	}

	return TriggerContext.bIsPressed ? EGenericInputTriggerState::Ongoing : EGenericInputTriggerState::None;
}
