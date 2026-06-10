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
		if (UWorld* World = Context.GetWorld())
		{
			return World;
		}

		const FStateTreeDataView WorldData = Context.GetContextDataByName(FName(TEXT("World")));
		return WorldData.GetMutablePtr<UWorld>();
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

	static void ResetTask(FLoadDefaultMenuTaskInstanceData& InstanceData)
	{
		InstanceData.CreatedMenuCollections.Reset();
		InstanceData.bIsFinished = false;
	}

	static bool RegisterStartupMenusForPlayer(APlayerController* PlayerController, const TArray<TSubclassOf<UMenuCollection>>& InMenuCollectionClasses, TArray<TWeakObjectPtr<UMenuCollection>>& OutCreatedMenuCollections)
	{
		if (!PlayerController)
		{
			return true;
		}

		UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
		if (!MenuSubsystem)
		{
			UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultMenuTask failed because MenuSubsystem is missing."));
			return false;
		}

		bool bSucceeded = true;
		for (const TSubclassOf<UMenuCollection>& MenuCollectionClass : InMenuCollectionClasses)
		{
			if (!MenuCollectionClass)
			{
				continue;
			}

			UMenuCollection* MenuCollection = MenuSubsystem->RegisterMenuCollection(MenuCollectionClass, true);
			if (!MenuCollection)
			{
				bSucceeded = false;
				UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultMenuTask failed to register startup menu collection. Class: %s"), *MenuCollectionClass->GetName());
				continue;
			}

			OutCreatedMenuCollections.Add(MenuCollection);
		}

		return bSucceeded;
	}
}

FLoadDefaultMenuTask::FLoadDefaultMenuTask()
{
	bShouldCallTick = false;
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

	const bool bHasLocalPlayer = UE::GenericMenu::LoadDefaultMenuTask::HasLocalPlayerController(World);
	if (MenuCollectionClasses.IsEmpty() || !bHasLocalPlayer)
	{
		InstanceData.bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	TArray<TWeakObjectPtr<UMenuCollection>> CreatedMenuCollections;
	bool bSucceeded = true;
	for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
	{
		APlayerController* PlayerController = It->Get();
		if (!PlayerController || !PlayerController->IsLocalController())
		{
			continue;
		}

		bSucceeded &= UE::GenericMenu::LoadDefaultMenuTask::RegisterStartupMenusForPlayer(PlayerController, MenuCollectionClasses, CreatedMenuCollections);
	}

	if (!bSucceeded)
	{
		return EStateTreeRunStatus::Failed;
	}

	InstanceData.CreatedMenuCollections = MoveTemp(CreatedMenuCollections);
	InstanceData.bIsFinished = true;
	return EStateTreeRunStatus::Succeeded;
}
