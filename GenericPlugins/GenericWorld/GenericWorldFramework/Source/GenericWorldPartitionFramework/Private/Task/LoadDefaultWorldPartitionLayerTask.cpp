// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Task/LoadDefaultWorldPartitionLayerTask.h"

#include "Engine/World.h"
#include "StateTreeExecutionContext.h"
#include "Subsystem/GenericWorldPartitionSubsystem.h"
#include "WorldPartition/DataLayer/DataLayerAsset.h"
#include "WorldPartition/DataLayer/DataLayerInstance.h"

namespace UE::GenericWorldPartition::LoadDefaultWorldPartitionLayerTask
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

	static void AddUniqueValidDataLayer(TArray<TObjectPtr<UDataLayerAsset>>& OutDataLayers, UDataLayerAsset* InDataLayer)
	{
		if (IsValid(InDataLayer))
		{
			OutDataLayers.AddUnique(InDataLayer);
		}
	}

	static bool ApplyDefaultDataLayerStates(
		UGenericWorldPartitionSubsystem* WorldPartitionSubsystem,
		bool bLoadAllCurrentWorldDataLayers,
		const TArray<TObjectPtr<UDataLayerAsset>>& LoadedDataLayers,
		const TArray<TObjectPtr<UDataLayerAsset>>& VisibleDataLayers)
	{
		if (!WorldPartitionSubsystem)
		{
			return false;
		}

		bool bHasFailure = false;
		if (bLoadAllCurrentWorldDataLayers)
		{
			for (const UDataLayerInstance* DataLayerInstance : WorldPartitionSubsystem->GetDataLayerInstances())
			{
				if (IsValid(DataLayerInstance) && !WorldPartitionSubsystem->SetDataLayerInstanceRuntimeState(DataLayerInstance, EDataLayerRuntimeState::Loaded))
				{
					bHasFailure = true;
					UE_LOG(GenericLogWorldPartition, Warning, TEXT("LoadDefaultWorldPartitionLayerTask failed to load data layer instance. Name: %s"), *DataLayerInstance->GetDataLayerFName().ToString());
				}
			}
		}

		TArray<TObjectPtr<UDataLayerAsset>> DataLayersToLoad;
		for (TObjectPtr<UDataLayerAsset> DataLayer : LoadedDataLayers)
		{
			AddUniqueValidDataLayer(DataLayersToLoad, DataLayer);
		}

		for (TObjectPtr<UDataLayerAsset> DataLayer : DataLayersToLoad)
		{
			if (!WorldPartitionSubsystem->SetDataLayerRuntimeState(DataLayer, EDataLayerRuntimeState::Loaded))
			{
				bHasFailure = true;
				UE_LOG(GenericLogWorldPartition, Warning, TEXT("LoadDefaultWorldPartitionLayerTask failed to load data layer asset. Asset: %s"), *GetNameSafe(DataLayer));
			}
		}

		TArray<TObjectPtr<UDataLayerAsset>> DataLayersToActivate;
		for (TObjectPtr<UDataLayerAsset> DataLayer : VisibleDataLayers)
		{
			AddUniqueValidDataLayer(DataLayersToActivate, DataLayer);
		}

		for (TObjectPtr<UDataLayerAsset> DataLayer : DataLayersToActivate)
		{
			if (!WorldPartitionSubsystem->SetDataLayerRuntimeState(DataLayer, EDataLayerRuntimeState::Activated))
			{
				bHasFailure = true;
				UE_LOG(GenericLogWorldPartition, Warning, TEXT("LoadDefaultWorldPartitionLayerTask failed to activate data layer asset. Asset: %s"), *GetNameSafe(DataLayer));
			}
		}

		return !bHasFailure;
	}
}

FLoadDefaultWorldPartitionLayerTask::FLoadDefaultWorldPartitionLayerTask()
{
	bShouldCallTick = false;
	bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FLoadDefaultWorldPartitionLayerTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	UWorld* World = UE::GenericWorldPartition::LoadDefaultWorldPartitionLayerTask::ResolveWorld(Context);
	if (!World)
	{
		return EStateTreeRunStatus::Failed;
	}

	if (!World->IsPartitionedWorld())
	{
		UE_LOG(GenericLogWorldPartition, Warning, TEXT("LoadDefaultWorldPartitionLayerTask can only run in World Partition worlds. World: %s"), *GetNameSafe(World));
		return EStateTreeRunStatus::Failed;
	}

	UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = World->GetSubsystem<UGenericWorldPartitionSubsystem>();
	if (!WorldPartitionSubsystem)
	{
		UE_LOG(GenericLogWorldPartition, Warning, TEXT("LoadDefaultWorldPartitionLayerTask failed because GenericWorldPartitionSubsystem is missing. World: %s"), *GetNameSafe(World));
		return EStateTreeRunStatus::Failed;
	}

	const bool bSucceeded = UE::GenericWorldPartition::LoadDefaultWorldPartitionLayerTask::ApplyDefaultDataLayerStates(
		WorldPartitionSubsystem,
		bLoadAllCurrentWorldDataLayers,
		LoadedDataLayers,
		VisibleDataLayers);

	return bSucceeded ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
}
