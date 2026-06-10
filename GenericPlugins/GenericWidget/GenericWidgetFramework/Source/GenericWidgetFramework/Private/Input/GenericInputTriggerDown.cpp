// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputTriggerDown.h"

EGenericInputTriggerState UGenericInputTriggerDown::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	return IsContextActuated(TriggerContext) ? EGenericInputTriggerState::Triggered : EGenericInputTriggerState::None;
}
