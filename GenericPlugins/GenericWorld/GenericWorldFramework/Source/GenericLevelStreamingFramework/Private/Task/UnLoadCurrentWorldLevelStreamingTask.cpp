// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/UnLoadCurrentWorldLevelStreamingTask.h"

#include "Engine/LevelStreaming.h"
#include "Engine/LevelStreamingAlwaysLoaded.h"
#include "Engine/World.h"
#include "Handle/LevelStreamingHandle.h"
#include "Handle/UnLoadLevelStreamingHandle.h"
#include "StateTreeExecutionContext.h"
#include "Subsystem/GenericLevelStreamingSubsystem.h"

namespace UE::GenericLevelStreaming::UnLoadCurrentWorldLevelStreamingTask
{
	static UWorld* ResolveWorld(FStateTreeExecutionContext& Context)
	{
		if (UWorld* World = Context.GetWorld())
		{
			return World;
		}

		const FStateTreeDataView WorldData = Context.GetContextDataByName(FName(TEXT("World")));
		return WorldData.GetMutablePtr<UWorld>();
	}

	static UGenericLevelStreamingSubsystem* ResolveSubsystem(FStateTreeExecutionContext& Context)
	{
		UWorld* World = ResolveWorld(Context);
		return World ? World->GetSubsystem<UGenericLevelStreamingSubsystem>() : nullptr;
	}

	static bool HasLevelsToUnLoad(const UGenericLevelStreamingSubsystem& Subsystem)
	{
		const UWorld* World = Subsystem.GetWorld();
		if (!World)
		{
			return false;
		}

		for (ULevelStreaming* StreamingLevel : World->GetStreamingLevels())
		{
			if (!StreamingLevel || !StreamingLevel->IsLevelLoaded())
			{
				continue;
			}

			if (Cast<ULevelStreamingAlwaysLoaded>(StreamingLevel))
			{
				continue;
			}

			return true;
		}

		return false;
	}

	static void ResetTask(FUnLoadCurrentWorldLevelStreamingTaskInstanceData& InstanceData)
	{
		if (InstanceData.RuntimeState)
		{
			if (ULevelStreamingHandle* Handle = InstanceData.RuntimeState->Handle.Get())
			{
				if (InstanceData.RuntimeState->OnceFinishHandle.IsValid())
				{
					Handle->GetHandleOnceFinishEvent().Remove(InstanceData.RuntimeState->OnceFinishHandle);
				}

				if (InstanceData.RuntimeState->FinishHandle.IsValid())
				{
					Handle->GetHandleFinishEvent().Remove(InstanceData.RuntimeState->FinishHandle);
				}
			}
		}

		InstanceData.LastFinishedLevel.Reset();
		InstanceData.FinishedCount = 0;
		InstanceData.bIsFinished = false;
		InstanceData.RuntimeState.Reset();
	}

	static EStateTreeRunStatus StartTask(FUnLoadCurrentWorldLevelStreamingTaskInstanceData& InstanceData, ULevelStreamingHandle* Handle, const bool bAllowNoHandleAsSuccess, TStateTreeInstanceDataStructRef<FUnLoadCurrentWorldLevelStreamingTaskInstanceData> InstanceDataRef)
	{
		InstanceData.RuntimeState = MakeShared<FUnLoadCurrentWorldLevelStreamingTaskRuntimeState>();

		if (!Handle)
		{
			InstanceData.RuntimeState->bIsFinished = bAllowNoHandleAsSuccess;
			InstanceData.RuntimeState->bHasFailed = !bAllowNoHandleAsSuccess;
			InstanceData.bIsFinished = bAllowNoHandleAsSuccess;
			return bAllowNoHandleAsSuccess ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
		}

		TSharedRef<FUnLoadCurrentWorldLevelStreamingTaskRuntimeState> RuntimeState = InstanceData.RuntimeState.ToSharedRef();
		RuntimeState->Handle = Handle;

		RuntimeState->OnceFinishHandle = Handle->GetHandleOnceFinishEvent().AddLambda(
			[InstanceDataRef, RuntimeState](ULevelStreamingHandle* InHandle, TSoftObjectPtr<UWorld> InLevel)
			{
				if (RuntimeState->bHasFailed || RuntimeState->bIsFinished)
				{
					return;
				}

				if (FUnLoadCurrentWorldLevelStreamingTaskInstanceData* InstanceData = InstanceDataRef.GetPtr())
				{
					InstanceData->LastFinishedLevel = InLevel;
					++InstanceData->FinishedCount;
				}
			});

		RuntimeState->FinishHandle = Handle->GetHandleFinishEvent().AddLambda(
			[InstanceDataRef, RuntimeState](ULevelStreamingHandle* InHandle)
			{
				if (RuntimeState->bHasFailed)
				{
					return;
				}

				RuntimeState->bIsFinished = true;
				if (FUnLoadCurrentWorldLevelStreamingTaskInstanceData* InstanceData = InstanceDataRef.GetPtr())
				{
					InstanceData->bIsFinished = true;
				}
			});

		if (Handle->IsFinished())
		{
			RuntimeState->bIsFinished = true;
			InstanceData.bIsFinished = true;
			return EStateTreeRunStatus::Succeeded;
		}

		return EStateTreeRunStatus::Running;
	}
}

FUnLoadCurrentWorldLevelStreamingTask::FUnLoadCurrentWorldLevelStreamingTask()
{
	bShouldCallTick = true;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FUnLoadCurrentWorldLevelStreamingTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericLevelStreaming::UnLoadCurrentWorldLevelStreamingTask::ResetTask(InstanceData);

	UGenericLevelStreamingSubsystem* Subsystem = UE::GenericLevelStreaming::UnLoadCurrentWorldLevelStreamingTask::ResolveSubsystem(Context);
	if (!Subsystem)
	{
		return EStateTreeRunStatus::Failed;
	}

	const bool bHasLevelsToUnLoad = UE::GenericLevelStreaming::UnLoadCurrentWorldLevelStreamingTask::HasLevelsToUnLoad(*Subsystem);
	UUnLoadLevelStreamingHandle* Handle = Subsystem->UnLoadCurrentWorldLevelStreaming();
	return UE::GenericLevelStreaming::UnLoadCurrentWorldLevelStreamingTask::StartTask(InstanceData, Handle, !bHasLevelsToUnLoad, Context.GetInstanceDataStructRef(*this));
}

void FUnLoadCurrentWorldLevelStreamingTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	UE::GenericLevelStreaming::UnLoadCurrentWorldLevelStreamingTask::ResetTask(Context.GetInstanceData(*this));
}

EStateTreeRunStatus FUnLoadCurrentWorldLevelStreamingTask::Tick(FStateTreeExecutionContext& Context, float DeltaTime) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (!InstanceData.RuntimeState || InstanceData.RuntimeState->bHasFailed)
	{
		return EStateTreeRunStatus::Failed;
	}

	return InstanceData.RuntimeState->bIsFinished ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Running;
}
