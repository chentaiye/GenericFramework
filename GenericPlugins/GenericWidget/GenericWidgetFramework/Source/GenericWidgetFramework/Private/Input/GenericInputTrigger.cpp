// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputTrigger.h"

bool UGenericInputTrigger::IsActuated(const FInputActionValue& InValue) const
{
	return FMath::Abs(InValue.GetMagnitude()) >= ActuationThreshold;
}

EGenericInputTriggerType UGenericInputTrigger::GetTriggerType() const
{
	return GetTriggerTypeNative();
}

EGenericInputTriggerState UGenericInputTrigger::UpdateState(const FGenericInputTriggerContext& TriggerContext)
{
	LastValue = TriggerContext.InputValue;
	return UpdateStateNative(TriggerContext);
}

void UGenericInputTrigger::Reset()
{
	LastValue.Reset();
}

EGenericInputTriggerType UGenericInputTrigger::GetTriggerTypeNative() const
{
	return EGenericInputTriggerType::Explicit;
}

EGenericInputTriggerState UGenericInputTrigger::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	return IsContextActuated(TriggerContext) ? EGenericInputTriggerState::Triggered : EGenericInputTriggerState::None;
}

bool UGenericInputTrigger::IsContextActuated(const FGenericInputTriggerContext& TriggerContext) const
{
	return TriggerContext.bIsPressed || IsActuated(TriggerContext.InputValue);
}

EGenericInputTriggerState UGenericInputTriggerTimedBase::UpdateStateNative(const FGenericInputTriggerContext& TriggerContext)
{
	if (!IsContextActuated(TriggerContext))
	{
		HeldDuration = 0.0f;
		return EGenericInputTriggerState::None;
	}

	HeldDuration = CalculateHeldDuration(TriggerContext);
	return EGenericInputTriggerState::Ongoing;
}

void UGenericInputTriggerTimedBase::Reset()
{
	Super::Reset();
	HeldDuration = 0.0f;
}

float UGenericInputTriggerTimedBase::CalculateHeldDuration(const FGenericInputTriggerContext& TriggerContext) const
{
	if (!IsContextActuated(TriggerContext))
	{
		return 0.0f;
	}

	if (TriggerContext.HeldDuration > 0.0f)
	{
		return TriggerContext.HeldDuration;
	}

	return HeldDuration + TriggerContext.DeltaTime;
}
