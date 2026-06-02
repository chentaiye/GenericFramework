// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "InputCoreTypes.h"
#include "GenericInputTrigger.generated.h"

/** 表示输入触发器当前评估出的轻量状态。 */
UENUM(BlueprintType)
enum class EGenericInputTriggerState : uint8
{
	/** 没有满足任何触发条件。 */
	None,

	/** 触发条件正在持续评估但尚未完成。 */
	Ongoing,

	/** 触发条件已经满足。 */
	Triggered
};

/** 表示输入触发器参与组合评估时的类型。 */
UENUM(BlueprintType)
enum class EGenericInputTriggerType : uint8
{
	/** 任意显式触发器触发即可使行为触发。 */
	Explicit,

	/** 所有隐式触发器都触发时才允许行为触发。 */
	Implicit,

	/** 触发时阻止行为继续触发。 */
	Blocker
};

/** 保存通用 UI流程中的通用InputTriggerContext数据，供运行时传递和蓝图访问。 */
USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FGenericInputTriggerContext
{
	GENERATED_BODY()

	/** 记录键。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	FKey Key;

	/** 记录Input值。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	FInputActionValue InputValue;

	/** 记录Delta时间。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	float DeltaTime = 0.0f;

	/** 标记当前帧按键是否处于按下状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	bool bIsPressed = false;

	/** 标记上一帧按键是否处于按下状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	bool bWasPressed = false;

	/** 记录当前时间。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	double CurrentTime = 0.0;

	/** 记录Held耗时。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	float HeldDuration = 0.0f;

	/** 记录Released耗时。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	float ReleasedDuration = 0.0f;
};

/** 表示一个按键如何从输入状态转换为触发状态。 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced, MinimalAPI)
class UGenericInputTrigger : public UObject
{
	GENERATED_BODY()

public:
	/** 判断输入值达到触发阈值所需的最小幅度。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings", meta=(ClampMin="0"))
	float ActuationThreshold = 0.5f;

	/** 控制该触发器是否需要在没有输入变化时仍然每帧评估。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trigger Settings")
	bool bShouldAlwaysTick = false;

	/** 记录Last值。 */
	UPROPERTY(BlueprintReadOnly, Category="Trigger Settings")
	FInputActionValue LastValue;

public:
	/** 检查输入值是否已经达到触发阈值。 */
	UFUNCTION(BlueprintCallable, Category="Trigger")
	GENERICWIDGETFRAMEWORK_API bool IsActuated(const FInputActionValue& InValue) const;

	/** 获取该触发器参与组合评估时的类型。 */
	UFUNCTION(BlueprintCallable, Category="Trigger")
	GENERICWIDGETFRAMEWORK_API EGenericInputTriggerType GetTriggerType() const;

	/** 根据外部输入状态更新并返回当前触发状态。 */
	UFUNCTION(BlueprintCallable, Category="Trigger")
	GENERICWIDGETFRAMEWORK_API EGenericInputTriggerState UpdateState(const FGenericInputTriggerContext& TriggerContext);

	/** 刷新Reset相关缓存或运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Trigger")
	GENERICWIDGETFRAMEWORK_API virtual void Reset();

protected:
	/** 返回子类自定义的触发器类型。 */
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerType GetTriggerTypeNative() const;

	/** 执行子类自定义的触发状态评估。 */
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext);

	/** 检查输入上下文是否已经达到触发阈值或处于按下状态。 */
	GENERICWIDGETFRAMEWORK_API bool IsContextActuated(const FGenericInputTriggerContext& TriggerContext) const;
};

/** 表示带有持续时间评估能力的按键触发器基类。 */
UCLASS(Abstract, MinimalAPI)
class UGenericInputTriggerTimedBase : public UGenericInputTrigger
{
	GENERATED_BODY()

public:
	/** 控制按住时间是否由外部按时间膨胀后的DeltaTime提供。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trigger Settings")
	bool bAffectedByTimeDilation = false;

protected:
	/** 记录Held耗时。 */
	UPROPERTY(BlueprintReadOnly, Category="Trigger Settings")
	float HeldDuration = 0.0f;

protected:
	GENERICWIDGETFRAMEWORK_API virtual EGenericInputTriggerState UpdateStateNative(const FGenericInputTriggerContext& TriggerContext) override;
	GENERICWIDGETFRAMEWORK_API virtual void Reset() override;

	/** 计算本次评估后的连续按住时间。 */
	GENERICWIDGETFRAMEWORK_API float CalculateHeldDuration(const FGenericInputTriggerContext& TriggerContext) const;
};
