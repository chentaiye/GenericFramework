// Copyright Epic Games, Inc. All Rights Reserved.

#include "Task/ListenForGameplayMessageTask.h"

#include "Engine/World.h"
#include "StateTreeExecutionContext.h"

namespace UE::GenericMessage::ListenForGameplayMessageTask
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

	static void ResetTask(FListenForGameplayMessageTaskInstanceData& InstanceData)
	{
		if (InstanceData.RuntimeState)
		{
			for (FGameplayMessageListenerHandle& ListenerHandle : InstanceData.RuntimeState->ListenerHandles)
			{
				ListenerHandle.Unregister();
			}
		}

		InstanceData.LastMatchedChannel = FGameplayTag();
		InstanceData.bHasFailed = false;
		InstanceData.bHasSucceeded = false;
		InstanceData.RuntimeState.Reset();
	}

	static void SetMatchedResult(
		const TSharedRef<FListenForGameplayMessageTaskRuntimeState>& RuntimeState,
		TStateTreeInstanceDataStructRef<FListenForGameplayMessageTaskInstanceData> InstanceDataRef,
		FGameplayTag ActualChannel,
		const bool bFailureChannel)
	{
		if (RuntimeState->bHasFailed)
		{
			return;
		}

		RuntimeState->LastMatchedChannel = ActualChannel;

		if (bFailureChannel)
		{
			RuntimeState->bHasFailed = true;
		}
		else
		{
			RuntimeState->bHasSucceeded = true;
		}

		if (FListenForGameplayMessageTaskInstanceData* InstanceData = InstanceDataRef.GetPtr())
		{
			InstanceData->LastMatchedChannel = ActualChannel;
			InstanceData->bHasFailed = RuntimeState->bHasFailed;
			InstanceData->bHasSucceeded = RuntimeState->bHasSucceeded;
		}
	}

	static void RegisterListenersForChannels(
		UGameplayMessageSubsystem& MessageSubsystem,
		const TArray<FGameplayTag>& Channels,
		const bool bFailureChannel,
		const EGameplayMessageMatch MatchType,
		const TSharedRef<FListenForGameplayMessageTaskRuntimeState>& RuntimeState,
		TStateTreeInstanceDataStructRef<FListenForGameplayMessageTaskInstanceData> InstanceDataRef)
	{
		TSet<FGameplayTag> RegisteredChannels;
		for (const FGameplayTag& Channel : Channels)
		{
			if (!Channel.IsValid() || RegisteredChannels.Contains(Channel))
			{
				continue;
			}

			RegisteredChannels.Add(Channel);
			FGameplayMessageListenerHandle ListenerHandle = MessageSubsystem.RegisterListener(
				Channel,
				[RuntimeState, InstanceDataRef, bFailureChannel](FGameplayTag ActualChannel)
				{
					UE::GenericMessage::ListenForGameplayMessageTask::SetMatchedResult(RuntimeState, InstanceDataRef, ActualChannel, bFailureChannel);
				},
				MatchType);

			if (ListenerHandle.IsValid())
			{
				RuntimeState->ListenerHandles.Add(ListenerHandle);
			}
		}
	}
}

FListenForGameplayMessageTask::FListenForGameplayMessageTask()
{
	bShouldCallTick = true;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FListenForGameplayMessageTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericMessage::ListenForGameplayMessageTask::ResetTask(InstanceData);

	UWorld* World = UE::GenericMessage::ListenForGameplayMessageTask::ResolveWorld(Context);
	if (!World || !UGameplayMessageSubsystem::HasInstance(World))
	{
		return EStateTreeRunStatus::Failed;
	}

	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(World);
	TSharedRef<FListenForGameplayMessageTaskRuntimeState> RuntimeState = MakeShared<FListenForGameplayMessageTaskRuntimeState>();
	InstanceData.RuntimeState = RuntimeState;

	TStateTreeInstanceDataStructRef<FInstanceDataType> InstanceDataRef = Context.GetInstanceDataStructRef(*this);
	UE::GenericMessage::ListenForGameplayMessageTask::RegisterListenersForChannels(MessageSubsystem, SuccessChannels, false, MatchType, RuntimeState, InstanceDataRef);
	UE::GenericMessage::ListenForGameplayMessageTask::RegisterListenersForChannels(MessageSubsystem, FailureChannels, true, MatchType, RuntimeState, InstanceDataRef);

	return EStateTreeRunStatus::Running;
}

void FListenForGameplayMessageTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	UE::GenericMessage::ListenForGameplayMessageTask::ResetTask(Context.GetInstanceData(*this));
}

EStateTreeRunStatus FListenForGameplayMessageTask::Tick(FStateTreeExecutionContext& Context, float DeltaTime) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (!InstanceData.RuntimeState)
	{
		return EStateTreeRunStatus::Failed;
	}

	if (InstanceData.RuntimeState->bHasFailed)
	{
		return EStateTreeRunStatus::Failed;
	}

	return InstanceData.RuntimeState->bHasSucceeded ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Running;
}
