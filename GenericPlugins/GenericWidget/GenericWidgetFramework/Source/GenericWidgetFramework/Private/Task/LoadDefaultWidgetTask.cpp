// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/LoadDefaultWidgetTask.h"

#include "Base/GenericWidget.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "StateTreeExecutionContext.h"
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

	static void ResetTask(FLoadDefaultWidgetTaskInstanceData& InstanceData)
	{
		InstanceData.CreatedWidgets.Reset();
		InstanceData.bIsFinished = false;
	}

	static bool CreateStartupWidgetsForPlayer(APlayerController* PlayerController, const TArray<TSubclassOf<UGenericWidget>>& WidgetClasses, TArray<TWeakObjectPtr<UGenericWidget>>& OutCreatedWidgets)
	{
		if (!PlayerController)
		{
			return true;
		}

		bool bSucceeded = true;
		for (const TSubclassOf<UGenericWidget>& WidgetClass : WidgetClasses)
		{
			if (!WidgetClass)
			{
				continue;
			}

			UGenericWidget* Widget = CreateWidget<UGenericWidget>(PlayerController, WidgetClass);
			if (!Widget)
			{
				bSucceeded = false;
				UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultWidgetTask failed to create startup widget. Class: %s"), *WidgetClass->GetName());
				continue;
			}

			Widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			if (!Widget->AddToPlayerScreen())
			{
				bSucceeded = false;
				UE_LOG(GenericLogUI, Warning, TEXT("LoadDefaultWidgetTask failed to add startup widget to player screen. Widget: %s"), *Widget->GetName());
				continue;
			}

			OutCreatedWidgets.Add(Widget);
		}

		return bSucceeded;
	}
}

FLoadDefaultWidgetTask::FLoadDefaultWidgetTask()
{
	bShouldCallTick = false;
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

	const bool bHasLocalPlayer = UE::GenericWidget::LoadDefaultWidgetTask::HasLocalPlayerController(World);
	if (GenericWidgetClasses.IsEmpty() || !bHasLocalPlayer)
	{
		InstanceData.bIsFinished = true;
		return EStateTreeRunStatus::Succeeded;
	}

	TArray<TWeakObjectPtr<UGenericWidget>> CreatedWidgets;
	bool bSucceeded = true;
	for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
	{
		APlayerController* PlayerController = It->Get();
		if (!PlayerController || !PlayerController->IsLocalController())
		{
			continue;
		}

		bSucceeded &= UE::GenericWidget::LoadDefaultWidgetTask::CreateStartupWidgetsForPlayer(PlayerController, GenericWidgetClasses, CreatedWidgets);
	}

	if (!bSucceeded)
	{
		return EStateTreeRunStatus::Failed;
	}

	InstanceData.CreatedWidgets = MoveTemp(CreatedWidgets);
	InstanceData.bIsFinished = true;
	return EStateTreeRunStatus::Succeeded;
}
