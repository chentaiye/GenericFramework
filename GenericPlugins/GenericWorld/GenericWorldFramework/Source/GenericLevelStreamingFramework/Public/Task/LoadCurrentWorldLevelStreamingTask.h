// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "LoadCurrentWorldLevelStreamingTask.generated.h"

class ULevelStreamingHandle;

/** 桥接 LevelStreaming 句柄和 StateTree Tick，把单项完成和整体完成事件写回实例数据。 */
struct FLoadCurrentWorldLevelStreamingTaskRuntimeState
{
	TWeakObjectPtr<ULevelStreamingHandle> Handle;
	FDelegateHandle OnceFinishHandle;
	FDelegateHandle FinishHandle;
	bool bIsFinished = false;
	bool bHasFailed = false;
};

/** StateTree 实例数据记录最近完成的流关卡和完成数量，便于后续节点判断加载进度。 */
USTRUCT()
struct GENERICLEVELSTREAMINGFRAMEWORK_API FLoadCurrentWorldLevelStreamingTaskInstanceData
{
	GENERATED_BODY()

	TSoftObjectPtr<UWorld> LastFinishedLevel = nullptr;
	int32 FinishedCount = 0;
	bool bIsFinished = false;
	TSharedPtr<FLoadCurrentWorldLevelStreamingTaskRuntimeState> RuntimeState;
};

/** 预加载当前世界中可手动控制且尚未加载的流关卡；没有可加载关卡时直接成功。 */
USTRUCT(meta=(DisplayName="Load Current World Level Streaming", Category="LevelStreaming"))
struct GENERICLEVELSTREAMINGFRAMEWORK_API FLoadCurrentWorldLevelStreamingTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadCurrentWorldLevelStreamingTask();

	using FInstanceDataType = FLoadCurrentWorldLevelStreamingTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
};
