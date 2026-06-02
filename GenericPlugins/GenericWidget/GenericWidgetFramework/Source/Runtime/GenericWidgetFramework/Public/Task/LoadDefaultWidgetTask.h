// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "TimerManager.h"
#include "LoadDefaultWidgetTask.generated.h"

class UGenericWidget;

/** 记录默认 Widget 延迟创建的运行时上下文，用下一帧结果回填 StateTree 实例数据。 */
struct FLoadDefaultWidgetTaskRuntimeState
{
	TWeakObjectPtr<UWorld> World;
	FTimerHandle CreateStartupWidgetsHandle;
	TArray<TSubclassOf<UGenericWidget>> GenericWidgetClasses;
	TArray<TWeakObjectPtr<UGenericWidget>> CreatedWidgets;
	bool bIsFinished = false;
	bool bHasFailed = false;
};

/** StateTree 实例数据记录本任务创建出的 Widget，供后续节点或绑定读取。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FLoadDefaultWidgetTaskInstanceData
{
	GENERATED_BODY()

	TArray<TWeakObjectPtr<UGenericWidget>> CreatedWidgets;
	bool bIsFinished = false;
	TSharedPtr<FLoadDefaultWidgetTaskRuntimeState> RuntimeState;
};

/** 延后一帧为每个本地玩家创建业务 Widget 并加入 PlayerScreen，适合放在默认 Layout 完成之后执行。 */
USTRUCT(meta=(DisplayName="Load Default Widget", Category="Project"))
struct GENERICWIDGETFRAMEWORK_API FLoadDefaultWidgetTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadDefaultWidgetTask();

	using FInstanceDataType = FLoadDefaultWidgetTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;

	/** 需要随世界启动创建的业务 Widget 类；空列表或没有本地玩家时任务直接成功。 */
	UPROPERTY(EditAnywhere, Category="Project")
	TArray<TSubclassOf<UGenericWidget>> GenericWidgetClasses;
};
