// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/LoadCurrentWorldLevelStreamingTask.h"

#include "Handle/LevelStreamingHandle.h"
#include "Handle/LoadLevelStreamingHandle.h"
#include "Misc/EngineVersionComparison.h"
#include "StateTreeExecutionContext.h"
#include "Subsystem/GenericLevelStreamingSubsystem.h"

namespace UE::GenericLevelStreaming::LoadCurrentWorldLevelStreamingTask
{
	static UWorld* ResolveWorld(FStateTreeExecutionContext& Context)
	{
		if (UWorld* World = Context.GetWorld())
		{
			return World;
		}

#if UE_VERSION_OLDER_THAN(5, 7, 0)
		for (const FStateTreeExternalDataDesc& Desc : Context.GetContextDataDescs())
		{
			if (Desc.Name == FName(TEXT("World")))
			{
				return Context.GetExternalDataView(Desc.Handle).GetMutablePtr<UWorld>();
			}
		}
		return nullptr;
#else
		const FStateTreeDataView WorldData = Context.GetContextDataByName(FName(TEXT("World")));
		return WorldData.GetMutablePtr<UWorld>();
#endif
	}

	static UGenericLevelStreamingSubsystem* ResolveSubsystem(FStateTreeExecutionContext& Context)
	{
		UWorld* World = ResolveWorld(Context);
		return World ? World->GetSubsystem<UGenericLevelStreamingSubsystem>() : nullptr;
	}

	static void ResetTask(FLoadCurrentWorldLevelStreamingTaskInstanceData& InstanceData)
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

	static FLoadCurrentWorldLevelStreamingTaskInstanceData* GetInstanceDataPtr(TStateTreeInstanceDataStructRef<FLoadCurrentWorldLevelStreamingTaskInstanceData>& InstanceDataRef)
	{
#if UE_VERSION_OLDER_THAN(5, 5, 0)
		return InstanceDataRef.IsValid() ? &(*InstanceDataRef) : nullptr;
#else
		return InstanceDataRef.GetPtr();
#endif
	}

	static EStateTreeRunStatus StartTask(FLoadCurrentWorldLevelStreamingTaskInstanceData& InstanceData, ULevelStreamingHandle* Handle, const bool bAllowNoHandleAsSuccess, TStateTreeInstanceDataStructRef<FLoadCurrentWorldLevelStreamingTaskInstanceData> InstanceDataRef)
	{
		InstanceData.RuntimeState = MakeShared<FLoadCurrentWorldLevelStreamingTaskRuntimeState>();

		if (!Handle)
		{
			InstanceData.RuntimeState->bIsFinished = bAllowNoHandleAsSuccess;
			InstanceData.RuntimeState->bHasFailed = !bAllowNoHandleAsSuccess;
			InstanceData.bIsFinished = bAllowNoHandleAsSuccess;
			return bAllowNoHandleAsSuccess ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
		}

		TSharedRef<FLoadCurrentWorldLevelStreamingTaskRuntimeState> RuntimeState = InstanceData.RuntimeState.ToSharedRef();
		RuntimeState->Handle = Handle;

		RuntimeState->OnceFinishHandle = Handle->GetHandleOnceFinishEvent().AddLambda(
			[InstanceDataRef, RuntimeState](ULevelStreamingHandle* InHandle, TSoftObjectPtr<UWorld> InLevel) mutable
			{
				if (RuntimeState->bHasFailed || RuntimeState->bIsFinished)
				{
					return;
				}

				if (FLoadCurrentWorldLevelStreamingTaskInstanceData* InstanceData = GetInstanceDataPtr(InstanceDataRef))
				{
					InstanceData->LastFinishedLevel = InLevel;
					++InstanceData->FinishedCount;
				}
			});

		RuntimeState->FinishHandle = Handle->GetHandleFinishEvent().AddLambda(
			[InstanceDataRef, RuntimeState](ULevelStreamingHandle* InHandle) mutable
			{
				if (RuntimeState->bHasFailed)
				{
					return;
				}

				RuntimeState->bIsFinished = true;
				if (FLoadCurrentWorldLevelStreamingTaskInstanceData* InstanceData = GetInstanceDataPtr(InstanceDataRef))
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

FLoadCurrentWorldLevelStreamingTask::FLoadCurrentWorldLevelStreamingTask()
{
	bShouldCallTick = true;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FLoadCurrentWorldLevelStreamingTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericLevelStreaming::LoadCurrentWorldLevelStreamingTask::ResetTask(InstanceData);

	UGenericLevelStreamingSubsystem* Subsystem = UE::GenericLevelStreaming::LoadCurrentWorldLevelStreamingTask::ResolveSubsystem(Context);
	if (!Subsystem)
	{
		return EStateTreeRunStatus::Failed;
	}

	const bool bHasLevelsToLoad = !Subsystem->GetCurrentWorldLevelStreamingList().IsEmpty();
	ULoadLevelStreamingHandle* Handle = Subsystem->LoadCurrentWorldLevelStreaming();
	return UE::GenericLevelStreaming::LoadCurrentWorldLevelStreamingTask::StartTask(InstanceData, Handle, !bHasLevelsToLoad, Context.GetInstanceDataStructRef(*this));
}

void FLoadCurrentWorldLevelStreamingTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	UE::GenericLevelStreaming::LoadCurrentWorldLevelStreamingTask::ResetTask(Context.GetInstanceData(*this));
}

EStateTreeRunStatus FLoadCurrentWorldLevelStreamingTask::Tick(FStateTreeExecutionContext& Context, float DeltaTime) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (!InstanceData.RuntimeState || InstanceData.RuntimeState->bHasFailed)
	{
		return EStateTreeRunStatus::Failed;
	}

	return InstanceData.RuntimeState->bIsFinished ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Running;
}
