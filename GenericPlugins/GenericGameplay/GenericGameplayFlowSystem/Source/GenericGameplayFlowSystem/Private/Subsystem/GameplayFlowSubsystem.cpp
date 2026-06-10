// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GameplayFlowSubsystem.h"

#include "Base/GameplayFlowStateTreeSchema.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameplayFlowType.h"
#include "Settings/GameplayFlowWorldSettings.h"
#include "StateTree.h"
#include "StateTreeExecutionContext.h"
#include "WorldSettings/GenericWorldSettingsSubsystem.h"

UGameplayFlowSubsystem* UGameplayFlowSubsystem::Get(const UObject* WorldContextObject)
{
	const UWorld* World = WorldContextObject ? WorldContextObject->GetWorld() : nullptr;
	return World ? World->GetSubsystem<UGameplayFlowSubsystem>() : nullptr;
}

bool UGameplayFlowSubsystem::StartGameplayFlow(UStateTree* StateTree)
{
	UWorld* World = GetWorld();
	if (!World || !StateTree)
	{
		return false;
	}

	if (!ValidateStateTree(StateTree))
	{
		return false;
	}

	StopGameplayFlow(EStateTreeRunStatus::Stopped);

	ActiveStateTree = StateTree;
	bIsGameplayFlowRunning = true;

	FStateTreeExecutionContext Context(*this, *ActiveStateTree, StateTreeInstanceData, FOnCollectStateTreeExternalData::CreateUObject(this, &UGameplayFlowSubsystem::CollectExternalData));
	if (!SetContextRequirements(Context))
	{
		UE_LOG(GenericLogGameplayFlow, Warning, TEXT("GameplayFlowSubsystem failed to bind StateTree context data. Asset: %s"), *GetNameSafe(ActiveStateTree));
		FinishGameplayFlow(EStateTreeRunStatus::Failed);
		return false;
	}

	const EStateTreeRunStatus StartStatus = Context.Start();
	if (StartStatus != EStateTreeRunStatus::Running)
	{
		FinishGameplayFlow(StartStatus);
		return StartStatus == EStateTreeRunStatus::Succeeded;
	}

	return true;
}

void UGameplayFlowSubsystem::StopGameplayFlow(EStateTreeRunStatus CompletionStatus)
{
	if (!bIsGameplayFlowRunning || !ActiveStateTree)
	{
		FinishGameplayFlow(CompletionStatus);
		return;
	}

	FStateTreeExecutionContext Context(*this, *ActiveStateTree, StateTreeInstanceData, FOnCollectStateTreeExternalData::CreateUObject(this, &UGameplayFlowSubsystem::CollectExternalData));
	if (SetContextRequirements(Context))
	{
		Context.Stop(CompletionStatus);
	}

	FinishGameplayFlow(CompletionStatus);
}

void UGameplayFlowSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsGameplayFlowRunning || !ActiveStateTree)
	{
		return;
	}

	FStateTreeExecutionContext Context(*this, *ActiveStateTree, StateTreeInstanceData, FOnCollectStateTreeExternalData::CreateUObject(this, &UGameplayFlowSubsystem::CollectExternalData));
	if (!SetContextRequirements(Context))
	{
		UE_LOG(GenericLogGameplayFlow, Warning, TEXT("GameplayFlowSubsystem failed to tick because StateTree context data is invalid. Asset: %s"), *GetNameSafe(ActiveStateTree));
		Context.Stop(EStateTreeRunStatus::Failed);
		FinishGameplayFlow(EStateTreeRunStatus::Failed);
		return;
	}

	const EStateTreeRunStatus TickStatus = Context.Tick(DeltaTime);
	if (TickStatus != EStateTreeRunStatus::Running)
	{
		FinishGameplayFlow(TickStatus);
	}
}

bool UGameplayFlowSubsystem::IsTickable() const
{
	return Super::IsTickable() && bIsGameplayFlowRunning;
}

void UGameplayFlowSubsystem::OnWorldBeginTearDown(UWorld* InWorld)
{
	StopGameplayFlow(EStateTreeRunStatus::Stopped);
	Super::OnWorldBeginTearDown(InWorld);
}

void UGameplayFlowSubsystem::Deinitialize()
{
	StopGameplayFlow(EStateTreeRunStatus::Stopped);
	Super::Deinitialize();
}

bool UGameplayFlowSubsystem::ValidateStateTree(const UStateTree* StateTree) const
{
	if (!StateTree)
	{
		return false;
	}

	if (!StateTree->GetSchema() || !StateTree->GetSchema()->IsA<UGameplayFlowStateTreeSchema>())
	{
		UE_LOG(GenericLogGameplayFlow, Warning, TEXT("GameplayFlowSubsystem can only enter StateTree assets using GameplayFlowStateTreeSchema. Asset: %s"), *GetNameSafe(StateTree));
		return false;
	}

	if (!StateTree->IsReadyToRun())
	{
		UE_LOG(GenericLogGameplayFlow, Warning, TEXT("GameplayFlowSubsystem failed to enter because the StateTree is not compiled or not ready. Asset: %s"), *GetNameSafe(StateTree));
		return false;
	}

	return true;
}

bool UGameplayFlowSubsystem::SetContextRequirements(FStateTreeExecutionContext& Context) const
{
	UWorld* World = GetWorld();
	UGameplayFlowWorldSettings* WorldSettings = ResolveWorldSettings();
	if (!World || !WorldSettings)
	{
		return false;
	}

	Context.SetContextDataByName(UE::GenericGameplayFlow::StateTreeContextDataNames::World, FStateTreeDataView(World));
	Context.SetContextDataByName(UE::GenericGameplayFlow::StateTreeContextDataNames::WorldSettings, FStateTreeDataView(WorldSettings));
	return Context.AreContextDataViewsValid();
}

UGameplayFlowWorldSettings* UGameplayFlowSubsystem::ResolveWorldSettings() const
{
	const UWorld* World = GetWorld();
	const UGenericWorldSettingsSubsystem* WorldSettingsSubsystem = World ? World->GetSubsystem<UGenericWorldSettingsSubsystem>() : nullptr;
	return WorldSettingsSubsystem ? WorldSettingsSubsystem->GetWorldSetting<UGameplayFlowWorldSettings>() : nullptr;
}

bool UGameplayFlowSubsystem::CollectExternalData(const FStateTreeExecutionContext& Context, const UStateTree* StateTree, TArrayView<const FStateTreeExternalDataDesc> Descs, TArrayView<FStateTreeDataView> OutDataViews) const
{
	UWorld* World = GetWorld();
	UGameplayFlowWorldSettings* WorldSettings = ResolveWorldSettings();
	if (!World || !WorldSettings)
	{
		return false;
	}

	for (int32 Index = 0; Index < Descs.Num(); ++Index)
	{
		const FStateTreeExternalDataDesc& Desc = Descs[Index];
		const UClass* DescClass = Cast<UClass>(Desc.Struct.Get());
		if (!DescClass)
		{
			continue;
		}

		if (DescClass == UWorld::StaticClass())
		{
			OutDataViews[Index] = FStateTreeDataView(World);
		}
		else if (DescClass->IsChildOf(UGameplayFlowWorldSettings::StaticClass()))
		{
			OutDataViews[Index] = FStateTreeDataView(WorldSettings);
		}
		else if (DescClass->IsChildOf(UWorldSubsystem::StaticClass()))
		{
			OutDataViews[Index] = FStateTreeDataView(World->GetSubsystemBase(TSubclassOf<UWorldSubsystem>(const_cast<UClass*>(DescClass))));
		}
		else if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			if (DescClass->IsChildOf(UGameInstanceSubsystem::StaticClass()))
			{
				OutDataViews[Index] = FStateTreeDataView(GameInstance->GetSubsystemBase(TSubclassOf<UGameInstanceSubsystem>(const_cast<UClass*>(DescClass))));
			}
		}

		if (!OutDataViews[Index].IsValid() && Desc.Requirement == EStateTreeExternalDataRequirement::Required)
		{
			return false;
		}
	}

	return true;
}

void UGameplayFlowSubsystem::FinishGameplayFlow(EStateTreeRunStatus CompletionStatus)
{
	bIsGameplayFlowRunning = false;
	ActiveStateTree = nullptr;
	StateTreeInstanceData.Reset();
}
