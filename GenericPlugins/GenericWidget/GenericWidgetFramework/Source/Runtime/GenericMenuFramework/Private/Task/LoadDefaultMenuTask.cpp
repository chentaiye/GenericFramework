// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/LoadDefaultMenuTask.h"

#include "Base/MenuCollection.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "StateTreeExecutionContext.h"
#include "Subsystem/MenuSubsystem.h"
#include "WidgetType.h"

namespace UE::GenericMenu::LoadDefaultMenuTask
{
	static UWorld* ResolveWorld(FStateTreeExecutionContext& Context)
	{
		return Context.GetWorld();
	}

	static bool HasLocalPlayerController(UWorld* World)
	{
		if (!World)
		{
			return false;
		}

		for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
		{
			const APlayerController* PlayerController = It->Get();
			if (PlayerController && PlayerController->IsLocalController())
			{
				return true;
			}
		}

		return false;
	}

	static void ClearPendingTimer(const TSharedPtr<FLoadDefaultMenuTaskRuntimeState>& RuntimeState)
	{
		if (!RuntimeState)
		{
			return;
		}

		if (UWorld* World = RuntimeState->World.Get())
		{
			World->GetTimerManager().ClearTimer(RuntimeState->BuildStartupMenusHandle);
		}
	}

	static void ResetTask(FLoadDefaultMenuTaskInstanceData& InstanceData)
	{
		ClearPendingTimer(InstanceData.RuntimeState);
		InstanceData.CreatedMenuCollections.Reset();
		InstanceData.bIsFinished = false;
		InstanceData.RuntimeState.Reset();
	}

	static void CopyCreatedMenuCollectionsToInstanceData(const TSharedRef<FLoadDefaultMenuTaskRuntimeState>& RuntimeState, FLoadDefaultMenuTaskInstanceData& InstanceData)
	{
		InstanceData.CreatedMenuCollections.Reset();
		for (const TWeakObjectPtr<UMenuCollection>& MenuCollection : RuntimeState->CreatedMenuCollections)
		{
			if (MenuCollection.IsValid())
			{
				InstanceData.CreatedMenuCollections.Add(MenuCollection);
			}
		}
	}

	static void RegisterStartupMenusForPlayer(APlayerController* PlayerController, const TSharedRef<FLoadDefaultMenuTaskRuntimeState>& RuntimeState)
	{
		if (!PlayerController)
		{
			return;
		}

		UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
		if (!MenuSubsystem)
		{
			RuntimeState->bHasFailed = true;
			UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultMenuTask failed because MenuSubsystem is missing."));
			return;
		}

		for (const TSubclassOf<UMenuCollection>& MenuCollectionClass : RuntimeState->MenuCollectionClasses)
		{
			if (!MenuCollectionClass)
			{
				continue;
			}

			UMenuCollection* MenuCollection = MenuSubsystem->RegisterMenuCollection(MenuCollectionClass, true);
			if (!MenuCollection)
			{
				RuntimeState->bHasFailed = true;
				UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultMenuTask failed to register startup menu collection. Class: %s"), *MenuCollectionClass->GetName());
				continue;
			}

			RuntimeState->CreatedMenuCollections.Add(MenuCollection);
		}
	}

	static void BuildStartupMenusAfterRouteTreeBuilt(TSharedRef<FLoadDefaultMenuTaskRuntimeState> RuntimeState)
	{
		if (RuntimeState->bIsFinished || RuntimeState->bHasFailed)
		{
			return;
		}

		UWorld* World = RuntimeState->World.Get();
		if (!World)
		{
			RuntimeState->bHasFailed = true;
			return;
		}

		for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
		{
			APlayerController* PlayerController = It->Get();
			if (!PlayerController || !PlayerController->IsLocalController())
			{
				continue;
			}

			RegisterStartupMenusForPlayer(PlayerController, RuntimeState);
		}

		RuntimeState->bIsFinished = !RuntimeState->bHasFailed;
	}
}

FLoadDefaultMenuTask::FLoadDefaultMenuTask()
{
	bShouldCallTick = true;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FLoadDefaultMenuTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericMenu::LoadDefaultMenuTask::ResetTask(InstanceData);

	UWorld* World = UE::GenericMenu::LoadDefaultMenuTask::ResolveWorld(Context);
	if (!World)
	{
		return EStateTreeRunStatus::Failed;
	}

	TSharedRef<FLoadDefaultMenuTaskRuntimeState> RuntimeState = MakeShared<FLoadDefaultMenuTaskRuntimeState>();
	RuntimeState->World = World;
	RuntimeState->MenuCollectionClasses = MenuCollectionClasses;
	InstanceData.RuntimeState = RuntimeState;

	const bool bHasLocalPlayer = UE::GenericMenu::LoadDefaultMenuTask::HasLocalPlayerController(World);
	if (MenuCollectionClasses.IsEmpty() || !bHasLocalPlayer)
	{
		RuntimeState->bIsFinished = true;
		InstanceData.bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	RuntimeState->BuildStartupMenusHandle = World->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateLambda(
		[RuntimeState]()
		{
			UE::GenericMenu::LoadDefaultMenuTask::BuildStartupMenusAfterRouteTreeBuilt(RuntimeState);
		}));

	return EStateTreeRunStatus::Running;
}

void FLoadDefaultMenuTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericMenu::LoadDefaultMenuTask::ClearPendingTimer(InstanceData.RuntimeState);
}

EStateTreeRunStatus FLoadDefaultMenuTask::Tick(FStateTreeExecutionContext& Context, float DeltaTime) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (!InstanceData.RuntimeState || InstanceData.RuntimeState->bHasFailed)
	{
		return EStateTreeRunStatus::Failed;
	}

	if (InstanceData.RuntimeState->bIsFinished)
	{
		UE::GenericMenu::LoadDefaultMenuTask::CopyCreatedMenuCollectionsToInstanceData(InstanceData.RuntimeState.ToSharedRef(), Context.GetInstanceData(*this));
		Context.GetInstanceData(*this).bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}
