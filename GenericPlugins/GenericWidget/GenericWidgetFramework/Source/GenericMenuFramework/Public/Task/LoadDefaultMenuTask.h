// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "TimerManager.h"
#include "LoadDefaultMenuTask.generated.h"

class UMenuCollection;

/** 记录默认菜单集延迟注册的运行时上下文，用下一帧结果回填 StateTree 实例数据。 */
struct FLoadDefaultMenuTaskRuntimeState
{
	TWeakObjectPtr<UWorld> World;
	FTimerHandle BuildStartupMenusHandle;
	TArray<TSubclassOf<UMenuCollection>> MenuCollectionClasses;
	TArray<TWeakObjectPtr<UMenuCollection>> CreatedMenuCollections;
	bool bIsFinished = false;
	bool bHasFailed = false;
};

/** StateTree 实例数据记录本任务注册出的菜单集，供后续节点或绑定读取。 */
USTRUCT()
struct GENERICMENUFRAMEWORK_API FLoadDefaultMenuTaskInstanceData
{
	GENERATED_BODY()

	TArray<TWeakObjectPtr<UMenuCollection>> CreatedMenuCollections;
	bool bIsFinished = false;
	TSharedPtr<FLoadDefaultMenuTaskRuntimeState> RuntimeState;
};

/** 延后一帧通过每个本地玩家的 MenuSubsystem 注册默认菜单集，适合放在 UI 路由初始化之后执行。 */
USTRUCT(meta=(DisplayName="Load Default Menu", Category="Project"))
struct GENERICMENUFRAMEWORK_API FLoadDefaultMenuTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadDefaultMenuTask();

	using FInstanceDataType = FLoadDefaultMenuTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;

	/** 需要随世界启动注册的菜单集类型；空列表或没有本地玩家时任务直接成功。 */
	UPROPERTY(EditAnywhere, Category="Project", meta=(AllowAbstract="false"))
	TArray<TSubclassOf<UMenuCollection>> MenuCollectionClasses;
};
