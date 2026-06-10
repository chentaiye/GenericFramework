// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/GenericInputTrigger.h"
#include "GenericInputTriggerDown.generated.h"

/** 输入超过阈值时持续触发。 */
UCLASS(MinimalAPI, meta=(DisplayName="Down"))
class UGenericInputTriggerDown : public UGenericInputTrigger
{
	GENERATED_BODY()

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
};
