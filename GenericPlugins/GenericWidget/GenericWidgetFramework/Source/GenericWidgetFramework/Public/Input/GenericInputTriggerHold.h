// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/GenericInputTrigger.h"
#include "GenericInputTriggerHold.generated.h"

/** 输入按住超过指定时间后触发。 */
UCLASS(MinimalAPI, meta=(DisplayName="Hold"))
class UGenericInputTriggerHold : public UGenericInputTriggerTimedBase
{
	GENERATED_BODY()

public:
	/** 记录Hold时间Threshold。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings", meta=(ClampMin="0"))
	float HoldTimeThreshold = 1.0f;

	/** 控制满足按住时间后是否只触发一次。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings")
	bool bIsOneShot = false;

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
	GENERICWIDGETFRAMEWORK_API virtual void Reset() override;

private:
	/** 标记当前按住周期是否已经触发过。 */
	UPROPERTY(Transient)
	bool bTriggered = false;
};
