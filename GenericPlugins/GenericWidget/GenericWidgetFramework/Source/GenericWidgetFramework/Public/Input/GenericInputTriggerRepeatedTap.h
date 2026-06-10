// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/GenericInputTriggerTap.h"
#include "GenericInputTriggerRepeatedTap.generated.h"

/** 输入在限定间隔内连续点击指定次数时触发。 */
UCLASS(MinimalAPI, meta=(DisplayName="Repeated Tap"))
class UGenericInputTriggerRepeatedTap : public UGenericInputTriggerTap
{
	GENERATED_BODY()

public:
	/** 记录RepeatDelay。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings", meta=(ClampMin="0"))
	float RepeatDelay = 0.4f;

	/** 记录NumberOfTapsWhichTriggerRepeat。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings", meta=(ClampMin="1"))
	int32 NumberOfTapsWhichTriggerRepeat = 2;

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
	GENERICWIDGETFRAMEWORK_API virtual void Reset() override;

private:
	/** 记录TapCount。 */
	UPROPERTY(Transient)
	int32 TapCount = 0;

	/** 记录LastTap时间。 */
	UPROPERTY(Transient)
	double LastTapTime = 0.0;
};
