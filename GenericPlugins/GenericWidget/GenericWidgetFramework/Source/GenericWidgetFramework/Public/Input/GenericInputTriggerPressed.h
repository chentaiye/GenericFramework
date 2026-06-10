// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/GenericInputTrigger.h"
#include "GenericInputTriggerPressed.generated.h"

/** 输入从释放变为按下时触发一次。 */
UCLASS(MinimalAPI, meta=(DisplayName="Pressed"))
class UGenericInputTriggerPressed : public UGenericInputTrigger
{
	GENERATED_BODY()

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
};
