// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "UnLoadCurrentWorldLevelStreamingTask.generated.h"

class ULevelStreamingHandle;

struct FUnLoadCurrentWorldLevelStreamingTaskRuntimeState
{
	TWeakObjectPtr<ULevelStreamingHandle> Handle;
	FDelegateHandle OnceFinishHandle;
	FDelegateHandle FinishHandle;
	bool bIsFinished = false;
	bool bHasFailed = false;
};

USTRUCT()
struct GENERICLEVELSTREAMINGFRAMEWORK_API FUnLoadCurrentWorldLevelStreamingTaskInstanceData
{
	GENERATED_BODY()

	TSoftObjectPtr<UWorld> LastFinishedLevel = nullptr;
	int32 FinishedCount = 0;
	bool bIsFinished = false;
	TSharedPtr<FUnLoadCurrentWorldLevelStreamingTaskRuntimeState> RuntimeState;
};

USTRUCT(meta=(DisplayName="UnLoad Current World Level Streaming", Category="LevelStreaming"))
struct GENERICLEVELSTREAMINGFRAMEWORK_API FUnLoadCurrentWorldLevelStreamingTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FUnLoadCurrentWorldLevelStreamingTask();

	using FInstanceDataType = FUnLoadCurrentWorldLevelStreamingTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
};
