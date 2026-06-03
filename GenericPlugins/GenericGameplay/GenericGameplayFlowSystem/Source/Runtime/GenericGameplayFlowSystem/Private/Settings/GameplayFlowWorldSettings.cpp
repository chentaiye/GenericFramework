// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Settings/GameplayFlowWorldSettings.h"

#include "Base/GameplayFlowStateTreeSchema.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameplayFlowType.h"
#include "Misc/EngineVersionComparison.h"
#include "StateTree.h"
#include "StateTreeExecutionContext.h"
#include "StateTreeInstanceData.h"

namespace UE::GenericGameplayFlow
{
	static bool SetContextRequirements(FStateTreeExecutionContext& Context, UWorld* World, UGameplayFlowWorldSettings* WorldSettings)
	{
		if (!World || !WorldSettings)
		{
			return false;
		}

#if !UE_VERSION_OLDER_THAN(5, 5, 0)
		Context.SetContextDataByName(StateTreeContextDataNames::World, FStateTreeDataView(World));
		Context.SetContextDataByName(StateTreeContextDataNames::WorldSettings, FStateTreeDataView(WorldSettings));
		return Context.AreContextDataViewsValid();
#else
		for (const FStateTreeExternalDataDesc& Desc : Context.GetContextDataDescs())
		{
			if (Desc.Name == StateTreeContextDataNames::World)
			{
				Context.SetExternalData(Desc.Handle, FStateTreeDataView(World));
			}
			else if (Desc.Name == StateTreeContextDataNames::WorldSettings)
			{
				Context.SetExternalData(Desc.Handle, FStateTreeDataView(WorldSettings));
			}
		}

		for (const FStateTreeExternalDataDesc& Desc : Context.GetExternalDataDescs())
		{
			const UClass* DescClass = Cast<UClass>(Desc.Struct.Get());
			if (!DescClass)
			{
				continue;
			}

			if (DescClass == UWorld::StaticClass())
			{
				Context.SetExternalData(Desc.Handle, FStateTreeDataView(World));
			}
			else if (DescClass->IsChildOf(UGameplayFlowWorldSettings::StaticClass()))
			{
				Context.SetExternalData(Desc.Handle, FStateTreeDataView(WorldSettings));
			}
			else if (DescClass->IsChildOf(UWorldSubsystem::StaticClass()))
			{
				Context.SetExternalData(Desc.Handle, FStateTreeDataView(World->GetSubsystemBase(TSubclassOf<UWorldSubsystem>(const_cast<UClass*>(DescClass)))));
			}
			else if (UGameInstance* GameInstance = World->GetGameInstance())
			{
				if (DescClass->IsChildOf(UGameInstanceSubsystem::StaticClass()))
				{
					Context.SetExternalData(Desc.Handle, FStateTreeDataView(GameInstance->GetSubsystemBase(TSubclassOf<UGameInstanceSubsystem>(const_cast<UClass*>(DescClass)))));
				}
			}
		}

		return Context.AreExternalDataViewsValid();
#endif
	}

	static bool CollectExternalData(UWorld* World, UGameplayFlowWorldSettings* WorldSettings, const FStateTreeExecutionContext& Context, const UStateTree* StateTree, TArrayView<const FStateTreeExternalDataDesc> Descs, TArrayView<FStateTreeDataView> OutDataViews)
	{
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
}

void UGameplayFlowWorldSettings::OnWorldSettingsBeginPlay_Implementation(UWorld* World)
{
	Super::OnWorldSettingsBeginPlay_Implementation(World);

	UStateTree* StateTree = StateTreeReference.GetMutableStateTree();
	if (!World || !StateTree)
	{
		return;
	}

	if (!StateTree->GetSchema() || !StateTree->GetSchema()->IsA<UGameplayFlowStateTreeSchema>())
	{
		UE_LOG(GenericLogGameplayFlow, Warning, TEXT("GameplayFlowWorldSettings can only enter StateTree assets using GameplayFlowStateTreeSchema. Asset: %s"), *GetNameSafe(StateTree));
		return;
	}

	if (!StateTree->IsReadyToRun())
	{
		UE_LOG(GenericLogGameplayFlow, Warning, TEXT("GameplayFlowWorldSettings failed to enter because the StateTree is not compiled or not ready. Asset: %s"), *GetNameSafe(StateTree));
		return;
	}

	FStateTreeInstanceData InstanceData;
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	FStateTreeExecutionContext Context(*this, *StateTree, InstanceData, FOnCollectStateTreeExternalData::CreateLambda(
		[World, this](const FStateTreeExecutionContext& InContext, const UStateTree* InStateTree, TArrayView<const FStateTreeExternalDataDesc> Descs, TArrayView<FStateTreeDataView> OutDataViews)
		{
			return UE::GenericGameplayFlow::CollectExternalData(World, this, InContext, InStateTree, Descs, OutDataViews);
		}));
#else
	FStateTreeExecutionContext Context(*this, *StateTree, InstanceData);
#endif

	if (!UE::GenericGameplayFlow::SetContextRequirements(Context, World, this))
	{
		UE_LOG(GenericLogGameplayFlow, Warning, TEXT("GameplayFlowWorldSettings failed to bind StateTree context data. Asset: %s"), *GetNameSafe(StateTree));
		return;
	}

#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	Context.Start(&StateTreeReference.GetParameters());
#else
	Context.SetParameters(StateTreeReference.GetParameters());
	Context.Start();
#endif
}

#if WITH_EDITOR
FName UGameplayFlowWorldSettings::GetSettingsCategory_Implementation() const
{
	return FName(TEXT("GameplayFlow"));
}
#endif
