// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/GenericInputTrigger.h"
#include "GenericInputTriggerReleased.generated.h"

/** 输入从按下变为释放时触发一次。 */
UCLASS(MinimalAPI, meta=(DisplayName="Released"))
class UGenericInputTriggerReleased : public UGenericInputTrigger
{
	GENERATED_BODY()

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
};
