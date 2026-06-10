// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Obect/GenericObject.h"
#include "PlayerInputIdleAction.generated.h"

/** 可内联配置的空闲输入动作对象，由空闲动作组件持有并通过计时器驱动开始、停止和反向状态。 */
UCLASS(Abstract, EditInlineNew, MinimalAPI)
class UPlayerInputIdleAction : public UGenericObject, public FTickableGameObject
{
	GENERATED_BODY()

	/* FTickableGameObject */
protected:
	virtual TStatId GetStatId() const override;
	virtual UWorld* GetTickableGameObjectWorld() const override;
	virtual void Tick(float DeltaTime) override;

	/* UPlayerInputIdleAction */
public:
	/** 重置等待与反向计时器，并在 ActionWaitTime 后触发空闲动作开始。 */
	UFUNCTION(BlueprintCallable, Category="Player Input Idle Action")
	GENERICINPUTSYSTEM_API void Start();

	/** 在刷新输入未命中排除键时停止当前动作，并重新安排下一次空闲等待。 */
	UFUNCTION(BlueprintCallable, Category="Player Input Idle Action")
	GENERICINPUTSYSTEM_API void Stop();

protected:
	/** 将动作标记为已开始、通知蓝图开始事件，并设置反向相关计时器的生命周期。 */
	GENERICINPUTSYSTEM_API virtual void HandleStartAction();

	/** 清除已开始状态并通知蓝图停止事件，供刷新输入或生命周期结束时收束空闲动作表现。 */
	GENERICINPUTSYSTEM_API virtual void HandleStopAction();

	/** 翻转反向状态，并在尚未启动反向计时器时按 ReverseDuration 循环调度自身。 */
	GENERICINPUTSYSTEM_API virtual void HandleReverseAction();

	/** 空闲等待结束后由 C++ 调用的蓝图扩展点，用于播放具体开始表现。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Player Input Idle Action")
	void OnActionStart();

	/** 输入刷新打断空闲动作时由 C++ 调用的蓝图扩展点，用于收束具体表现。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Player Input Idle Action")
	void OnActionStop();

	/** 每帧输出当前反向进度 Alpha，供蓝图根据 DeltaTime 和进度更新空闲表现。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Player Input Idle Action")
	void OnActionToggle(float DeltaTime, float Alpha);

public:
	/** 控制 Tick 是否累积 ReverseTime 并向 OnActionToggle 输出往返进度。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Input Idle Action")
	bool bEnableReverse=false;

	/** Stop 或 Start 后等待进入空闲动作的时间，计时结束会调用 HandleStartAction。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Input Idle Action", meta=(UIMin=0, ClampMin=0, Units="s"))
	float ActionWaitTime=30.f;

	/** 反向进度从一端移动到另一端的时长，用于计算 OnActionToggle 的 Alpha。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Input Idle Action", meta=(UIMin=0, ClampMin=0, Units="s"))
	float ReverseDuration=10.f;

	/** Stop 响应刷新输入前检查的按键集合，任一按键按下时跳过停止与重新等待。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Input Idle Action")
	TSet<FKey> ExcludeKeysWhenRefresh;

protected:
	/** 通过外层空闲动作组件查找拥有者玩家控制器，供排除键检测使用。 */
	UFUNCTION(BlueprintPure, Category="Player Input Idle Action")
	GENERICINPUTSYSTEM_API APlayerController* GetOwnerPlayerController() const;

	/** 暴露当前动作是否已进入空闲开始状态，供蓝图读取 C++ 计时结果。 */
	UFUNCTION(BlueprintPure, Category="Player Input Idle Action")
	GENERICINPUTSYSTEM_API bool GetIsActionStart() const;

	/** 暴露当前动作是否处于反向阶段，供蓝图按内部状态分支表现。 */
	UFUNCTION(BlueprintPure, Category="Player Input Idle Action")
	GENERICINPUTSYSTEM_API bool GetIsActionReverse() const;

private:
	/** 保存等待进入空闲动作的计时器句柄，Start 和 Stop 会先失效旧句柄再重新调度。 */
	FTimerHandle WaitingTimerHandle;

	/** 保存反向切换计时器句柄，用于避免重复启动并控制反向状态循环。 */
	FTimerHandle ReverseMovementTimerHandle;

	/** 保存 HandleStartAction 和 HandleStopAction 维护的动作激活状态，Tick 依赖它决定是否推进反向时间。 */
	bool bIsActionStart = false;

	/** 保存当前反向方向，HandleReverseAction 翻转它后影响 ReverseTime 的增减方向。 */
	bool bIsActionReverse = false;

	/** 累积反向播放时间，Tick 用它除以 ReverseDuration 生成传给蓝图的 Alpha。 */
	float ReverseTime = 0.f;
};
