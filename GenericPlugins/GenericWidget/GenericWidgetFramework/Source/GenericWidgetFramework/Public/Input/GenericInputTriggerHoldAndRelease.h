// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/GenericInputTrigger.h"
#include "GenericInputTriggerHoldAndRelease.generated.h"

/** 输入按住超过指定时间并释放时触发。 */
UCLASS(MinimalAPI, meta=(DisplayName="Hold And Release"))
class UGenericInputTriggerHoldAndRelease : public UGenericInputTriggerTimedBase
{
	GENERATED_BODY()

public:
	/** 记录Hold时间Threshold。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings", meta=(ClampMin="0"))
	float HoldTimeThreshold = 1.0f;

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
};
