// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "TimerManager.h"
#include "LoadDefaultLayoutTask.generated.h"

class UGenericLayout;

/** 记录 Layout 注册后的跨帧验证状态，用下一帧的子系统结果决定 StateTree 任务成败。 */
struct FLoadDefaultLayoutTaskRuntimeState
{
	TWeakObjectPtr<UWorld> World;
	FTimerHandle ValidateLayoutHandle;
	bool bIsFinished = false;
	bool bHasFailed = false;
};

/** StateTree 实例数据持有等待中的 Layout 验证状态，Tick 会根据它返回最终结果。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FLoadDefaultLayoutTaskInstanceData
{
	GENERATED_BODY()

	bool bIsFinished = false;
	TSharedPtr<FLoadDefaultLayoutTaskRuntimeState> RuntimeState;
};

/** 为每个本地玩家注册 UI 根布局，并等待下一帧确认 LayoutSubsystem 已持有布局后再放行后续状态。 */
USTRUCT(meta=(DisplayName="Load Default Layout", Category="Project"))
struct GENERICWIDGETFRAMEWORK_API FLoadDefaultLayoutTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadDefaultLayoutTask();

	using FInstanceDataType = FLoadDefaultLayoutTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;

	/** 要注册到本地玩家 LayoutSubsystem 的根布局类；为空、没有本地玩家或玩家已有 Layout 时不会创建新布局。 */
	UPROPERTY(EditAnywhere, Category="Project")
	TSubclassOf<UGenericLayout> LayoutClass;
};
