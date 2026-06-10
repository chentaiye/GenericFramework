// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/GenericInputTrigger.h"
#include "GenericInputTriggerPulse.generated.h"

/** 输入保持按下时按固定间隔脉冲触发。 */
UCLASS(MinimalAPI, meta=(DisplayName="Pulse"))
class UGenericInputTriggerPulse : public UGenericInputTriggerTimedBase
{
	GENERATED_BODY()

public:
	/** 控制按下开始时是否立即触发一次。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings")
	bool bTriggerOnStart = true;

	/** 记录间隔。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings", meta=(ClampMin="0.001"))
	float Interval = 0.5f;

	/** 记录TriggerLimit。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings", meta=(ClampMin="0"))
	int32 TriggerLimit = 0;

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
	GENERICWIDGETFRAMEWORK_API virtual void Reset() override;

private:
	/** 记录TriggerCount。 */
	UPROPERTY(Transient)
	int32 TriggerCount = 0;
};
