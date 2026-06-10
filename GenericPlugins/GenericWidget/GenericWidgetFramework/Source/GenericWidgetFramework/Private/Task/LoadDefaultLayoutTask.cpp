// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/LoadDefaultLayoutTask.h"

#include "Base/GenericLayout.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "StateTreeExecutionContext.h"
#include "Subsystem/GenericLayoutSubsystem.h"
#include "WidgetType.h"

namespace UE::GenericWidget::LoadDefaultLayoutTask
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

	static void ResetTask(FLoadDefaultLayoutTaskInstanceData& InstanceData)
	{
		InstanceData.bIsFinished = false;
	}

	static bool RegisterDefaultLayout(UWorld* World, const TSubclassOf<UGenericLayout>& LayoutClass)
	{
		if (!World || !LayoutClass)
		{
			return true;
		}

		bool bFailed = false;
		for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
		{
			APlayerController* PlayerController = It->Get();
			if (!PlayerController || !PlayerController->IsLocalController())
			{
				continue;
			}

			UGenericLayoutSubsystem* LayoutSubsystem = UGenericLayoutSubsystem::Get(PlayerController);
			if (!LayoutSubsystem)
			{
				bFailed = true;
				UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultLayoutTask failed because GenericLayoutSubsystem is missing. Class: %s"), *LayoutClass->GetName());
				continue;
			}

			if (!LayoutSubsystem->HasLayout() && !LayoutSubsystem->RegisterLayout(LayoutClass))
			{
				bFailed = true;
				UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultLayoutTask failed to register layout. Class: %s"), *LayoutClass->GetName());
			}
		}

		return !bFailed;
	}

}

FLoadDefaultLayoutTask::FLoadDefaultLayoutTask()
{
	bShouldCallTick = false;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FLoadDefaultLayoutTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericWidget::LoadDefaultLayoutTask::ResetTask(InstanceData);

	UWorld* World = UE::GenericWidget::LoadDefaultLayoutTask::ResolveWorld(Context);
	if (!World)
	{
		return EStateTreeRunStatus::Failed;
	}

	const bool bHasLocalPlayer = UE::GenericWidget::LoadDefaultLayoutTask::HasLocalPlayerController(World);
	if (!bHasLocalPlayer || !LayoutClass)
	{
		InstanceData.bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	if (!UE::GenericWidget::LoadDefaultLayoutTask::RegisterDefaultLayout(World, LayoutClass))
	{
		return EStateTreeRunStatus::Failed;
	}

	InstanceData.bIsFinished = true;
	return EStateTreeRunStatus::Succeeded;
}
