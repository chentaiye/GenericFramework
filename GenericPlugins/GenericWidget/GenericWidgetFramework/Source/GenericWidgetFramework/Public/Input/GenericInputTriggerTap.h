// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/GenericInputTrigger.h"
#include "GenericInputTriggerTap.generated.h"

/** 输入在指定时间内按下并释放时触发。 */
UCLASS(MinimalAPI, meta=(DisplayName="Tap"))
class UGenericInputTriggerTap : public UGenericInputTriggerTimedBase
{
	GENERATED_BODY()

public:
	/** 记录TapRelease时间Threshold。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings", meta=(ClampMin="0"))
	float TapReleaseTimeThreshold = 0.2f;

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
};
