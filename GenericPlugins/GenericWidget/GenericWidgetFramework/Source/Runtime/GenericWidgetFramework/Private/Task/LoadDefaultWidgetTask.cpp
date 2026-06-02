// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/LoadDefaultWidgetTask.h"

#include "Base/GenericWidget.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "StateTreeExecutionContext.h"
#include "TimerManager.h"
#include "WidgetType.h"

namespace UE::GenericWidget::LoadDefaultWidgetTask
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

	static void ClearPendingTimer(const TSharedPtr<FLoadDefaultWidgetTaskRuntimeState>& RuntimeState)
	{
		if (!RuntimeState)
		{
			return;
		}

		if (UWorld* World = RuntimeState->World.Get())
		{
			World->GetTimerManager().ClearTimer(RuntimeState->CreateStartupWidgetsHandle);
		}
	}

	static void ResetTask(FLoadDefaultWidgetTaskInstanceData& InstanceData)
	{
		ClearPendingTimer(InstanceData.RuntimeState);
		InstanceData.CreatedWidgets.Reset();
		InstanceData.bIsFinished = false;
		InstanceData.RuntimeState.Reset();
	}

	static void CopyCreatedWidgetsToInstanceData(const TSharedRef<FLoadDefaultWidgetTaskRuntimeState>& RuntimeState, FLoadDefaultWidgetTaskInstanceData& InstanceData)
	{
		InstanceData.CreatedWidgets.Reset();
		for (const TWeakObjectPtr<UGenericWidget>& Widget : RuntimeState->CreatedWidgets)
		{
			if (Widget.IsValid())
			{
				InstanceData.CreatedWidgets.Add(Widget);
			}
		}
	}

	static void CreateStartupWidgetsForPlayer(APlayerController* PlayerController, const TSharedRef<FLoadDefaultWidgetTaskRuntimeState>& RuntimeState)
	{
		if (!PlayerController)
		{
			return;
		}

		for (const TSubclassOf<UGenericWidget>& WidgetClass : RuntimeState->GenericWidgetClasses)
		{
			if (!WidgetClass)
			{
				continue;
			}

			UGenericWidget* Widget = CreateWidget<UGenericWidget>(PlayerController, WidgetClass);
			if (!Widget)
			{
				RuntimeState->bHasFailed = true;
				UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultWidgetTask failed to create startup widget. Class: %s"), *WidgetClass->GetName());
				continue;
			}

			Widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			if (!Widget->AddToPlayerScreen())
			{
				RuntimeState->bHasFailed = true;
				UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultWidgetTask failed to add startup widget to player screen. Widget: %s"), *Widget->GetName());
				continue;
			}

			RuntimeState->CreatedWidgets.Add(Widget);
		}
	}

	static void CreateStartupWidgetsAfterRouteTreeBuilt(TSharedRef<FLoadDefaultWidgetTaskRuntimeState> RuntimeState)
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

			CreateStartupWidgetsForPlayer(PlayerController, RuntimeState);
		}

		RuntimeState->bIsFinished = !RuntimeState->bHasFailed;
	}
}

FLoadDefaultWidgetTask::FLoadDefaultWidgetTask()
{
	bShouldCallTick = true;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FLoadDefaultWidgetTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericWidget::LoadDefaultWidgetTask::ResetTask(InstanceData);

	UWorld* World = UE::GenericWidget::LoadDefaultWidgetTask::ResolveWorld(Context);
	if (!World)
	{
		return EStateTreeRunStatus::Failed;
	}

	TSharedRef<FLoadDefaultWidgetTaskRuntimeState> RuntimeState = MakeShared<FLoadDefaultWidgetTaskRuntimeState>();
	RuntimeState->World = World;
	RuntimeState->GenericWidgetClasses = GenericWidgetClasses;
	InstanceData.RuntimeState = RuntimeState;

	const bool bHasLocalPlayer = UE::GenericWidget::LoadDefaultWidgetTask::HasLocalPlayerController(World);
	if (GenericWidgetClasses.IsEmpty() || !bHasLocalPlayer)
	{
		RuntimeState->bIsFinished = true;
		InstanceData.bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	RuntimeState->CreateStartupWidgetsHandle = World->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateLambda(
		[RuntimeState]()
		{
			UE::GenericWidget::LoadDefaultWidgetTask::CreateStartupWidgetsAfterRouteTreeBuilt(RuntimeState);
		}));

	return EStateTreeRunStatus::Running;
}

void FLoadDefaultWidgetTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	UE::GenericWidget::LoadDefaultWidgetTask::ClearPendingTimer(InstanceData.RuntimeState);
}

EStateTreeRunStatus FLoadDefaultWidgetTask::Tick(FStateTreeExecutionContext& Context, float DeltaTime) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (!InstanceData.RuntimeState || InstanceData.RuntimeState->bHasFailed)
	{
		return EStateTreeRunStatus::Failed;
	}

	if (InstanceData.RuntimeState->bIsFinished)
	{
		UE::GenericWidget::LoadDefaultWidgetTask::CopyCreatedWidgetsToInstanceData(InstanceData.RuntimeState.ToSharedRef(), Context.GetInstanceData(*this));
		Context.GetInstanceData(*this).bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	return EStateTreeRunStatus::Running;
}
