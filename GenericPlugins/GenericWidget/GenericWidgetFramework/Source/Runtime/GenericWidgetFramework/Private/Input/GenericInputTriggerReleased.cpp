// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputTriggerReleased.h"

EGenericInputTriggerState UGenericInputTriggerReleased::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	return !TriggerContext.bIsPressed && TriggerContext.bWasPressed ? EGenericInputTriggerState::Triggered : EGenericInputTriggerState::None;
}
