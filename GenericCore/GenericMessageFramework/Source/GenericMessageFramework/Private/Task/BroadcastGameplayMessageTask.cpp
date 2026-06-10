// Copyright Epic Games, Inc. All Rights Reserved.

#include "Task/BroadcastGameplayMessageTask.h"

#include "Engine/World.h"
#include "StateTreeExecutionContext.h"

namespace UE::GenericMessage::BroadcastGameplayMessageTask
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
}

FBroadcastGameplayMessageTask::FBroadcastGameplayMessageTask()
{
	bShouldCallTick = false;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FBroadcastGameplayMessageTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	UWorld* World = UE::GenericMessage::BroadcastGameplayMessageTask::ResolveWorld(Context);
	if (!World || !Channel.IsValid() || !UGameplayMessageSubsystem::HasInstance(World))
	{
		return EStateTreeRunStatus::Failed;
	}

	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(World);
	if (Message.IsValid())
	{
		MessageSubsystem.BroadcastMessageStruct(Channel, Message.GetScriptStruct(), Message.GetMemory());
	}
	else
	{
		MessageSubsystem.BroadcastMessage(Channel);
	}

	return EStateTreeRunStatus::Succeeded;
}
