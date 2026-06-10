// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/LoadDefaultLayoutTask.h"

#include "Base/GenericLayout.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "StateTreeExecutionContext.h"
#include "Subsystem/GenericLayoutSubsystem.h"
#include "TimerManager.h"
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

	static void ClearPendingTimer(const TSharedPtr<FLoadDefaultLayoutTaskRuntimeState>& RuntimeState)
	{
		if (!RuntimeState)
		{
			return;
		}

		if (UWorld* World = RuntimeState->World.Get())
		{
			World->GetTimerManager().ClearTimer(RuntimeState->ValidateLayoutHandle);
		}
	}

	static void ResetTask(FLoadDefaultLayoutTaskInstanceData& InstanceData)
	{
		ClearPendingTimer(InstanceData.RuntimeState);
		InstanceData.bIsFinished = false;
		InstanceData.RuntimeState.Reset();
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

	static bool AreLocalPlayerLayoutsReady(UWorld* World, const bool bRequireLayout)
	{
		if (!World)
		{
			return false;
		}

		for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
		{
			APlayerController* PlayerController = It->Get();
			if (!PlayerController || !PlayerController->IsLocalController())
			{
				continue;
			}

			const UGenericLayoutSubsystem* LayoutSubsystem = UGenericLayoutSubsystem::Get(PlayerController);
			if (!LayoutSubsystem)
			{
				return false;
			}

			if (bRequireLayout && !LayoutSubsystem->HasLayout())
			{
				return false;
			}
		}

		return true;
	}

	static void ValidateLayoutAfterSlateSync(const TSharedRef<FLoadDefaultLayoutTaskRuntimeState>& RuntimeState, const bool bRequireLayout)
	{
		if (RuntimeState->bIsFinished || RuntimeState->bHasFailed)
		{
			return;
		}

		UWorld* World = RuntimeState->World.Get();
		if (!AreLocalPlayerLayoutsReady(World, bRequireLayout))
		{
			RuntimeState->bHasFailed = true;
			return;
		}

		RuntimeState->bIsFinished = true;
	}
}

FLoadDefaultLayoutTask::FLoadDefaultLayoutTask()
{
	bShouldCallTick = true;
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

	TSharedRef<FLoadDefaultLayoutTaskRuntimeState> RuntimeState = MakeShared<FLoadDefaultLayoutTaskRuntimeState>();
	RuntimeState->World = World;
	InstanceData.RuntimeState = RuntimeState;

	const bool bHasLocalPlayer = UE::GenericWidget::LoadDefaultLayoutTask::HasLocalPlayerController(World);
	if (!bHasLocalPlayer || !LayoutClass)
	{
		RuntimeState->bIsFinished = true;
		InstanceData.bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	if (!UE::GenericWidget::LoadDefaultLayoutTask::RegisterDefaultLayout(World, LayoutClass))
	{
		RuntimeState->bHasFailed = true;
		return EStateTreeRunStatus::Failed;
	}

	RuntimeState->ValidateLayoutHandle = World->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateLambda(
		[RuntimeState]()
		{
			UE::GenericWidget::LoadDefaultLayoutTask::ValidateLayoutAfterSlateSync(RuntimeState, true);
		}));

	return EStateTreeRunStatus::Running;
}

void FLoadDefaultLayoutTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericWidget::LoadDefaultLayoutTask::ClearPendingTimer(InstanceData.RuntimeState);
}

EStateTreeRunStatus FLoadDefaultLayoutTask::Tick(FStateTreeExecutionContext& Context, float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (!InstanceData.RuntimeState || InstanceData.RuntimeState->bHasFailed)
	{
		return EStateTreeRunStatus::Failed;
	}

	if (InstanceData.RuntimeState->bIsFinished)
	{
		InstanceData.bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}
