// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_WorldPartition.h"

#include "Subsystem/GenericWorldPartitionSubsystem.h"
#include "GameFramework/Actor.h"

void UBPFunctions_WorldPartition::LoadCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionFinish FinishCallback = OnFinish;
		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->LoadCell(Cell, HandleFinish);
	}
}

void UBPFunctions_WorldPartition::LoadCells(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionOnceFinish OnceFinishCallback = OnOnceFinish;
		FHandleWorldPartitionFinish FinishCallback = OnFinish;

		const FOnHandleWorldPartitionOnceFinish HandleOnceFinish = FOnHandleWorldPartitionOnceFinish::CreateLambda([OnceFinishCallback]() mutable
		{
			OnceFinishCallback.ExecuteIfBound();
		});

		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->LoadCells(Cells, HandleOnceFinish, HandleFinish);
	}
}

void UBPFunctions_WorldPartition::LoadCellsBySetting(const UObject* WorldContextObject, TArray<FLoadWorldPartitionSetting> LoadWorldPartitionSettings, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionOnceFinish OnceFinishCallback = OnOnceFinish;
		FHandleWorldPartitionFinish FinishCallback = OnFinish;

		const FOnHandleWorldPartitionOnceFinish HandleOnceFinish = FOnHandleWorldPartitionOnceFinish::CreateLambda([OnceFinishCallback]() mutable
		{
			OnceFinishCallback.ExecuteIfBound();
		});

		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->LoadCellsBySetting(LoadWorldPartitionSettings, HandleOnceFinish, HandleFinish);
	}
}

void UBPFunctions_WorldPartition::UnloadCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionFinish FinishCallback = OnFinish;
		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->UnloadCell(Cell, HandleFinish);
	}
}

void UBPFunctions_WorldPartition::UnloadCells(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionOnceFinish OnceFinishCallback = OnOnceFinish;
		FHandleWorldPartitionFinish FinishCallback = OnFinish;

		const FOnHandleWorldPartitionOnceFinish HandleOnceFinish = FOnHandleWorldPartitionOnceFinish::CreateLambda([OnceFinishCallback]() mutable
		{
			OnceFinishCallback.ExecuteIfBound();
		});

		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->UnloadCells(Cells, HandleOnceFinish, HandleFinish);
	}
}

void UBPFunctions_WorldPartition::UnloadCellsBySetting(const UObject* WorldContextObject, TArray<FUnloadWorldPartitionSetting> UnloadWorldPartitionSettings, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionOnceFinish OnceFinishCallback = OnOnceFinish;
		FHandleWorldPartitionFinish FinishCallback = OnFinish;

		const FOnHandleWorldPartitionOnceFinish HandleOnceFinish = FOnHandleWorldPartitionOnceFinish::CreateLambda([OnceFinishCallback]() mutable
		{
			OnceFinishCallback.ExecuteIfBound();
		});

		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->UnloadCellsBySetting(UnloadWorldPartitionSettings, HandleOnceFinish, HandleFinish);
	}
}

void UBPFunctions_WorldPartition::SetCellVisibility(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell, bool bVisible, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionFinish FinishCallback = OnFinish;
		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->SetCellVisibility(Cell, bVisible, HandleFinish);
	}
}

void UBPFunctions_WorldPartition::SetCellsVisibility(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells, bool bVisible, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionOnceFinish OnceFinishCallback = OnOnceFinish;
		FHandleWorldPartitionFinish FinishCallback = OnFinish;

		const FOnHandleWorldPartitionOnceFinish HandleOnceFinish = FOnHandleWorldPartitionOnceFinish::CreateLambda([OnceFinishCallback]() mutable
		{
			OnceFinishCallback.ExecuteIfBound();
		});

		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->SetCellsVisibility(Cells, bVisible, HandleOnceFinish, HandleFinish);
	}
}

void UBPFunctions_WorldPartition::SetCellsVisibilityBySetting(const UObject* WorldContextObject, TArray<FSetWorldPartitionVisibilitySetting> SetWorldPartitionVisibilitySettings, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish)
{
	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		FHandleWorldPartitionOnceFinish OnceFinishCallback = OnOnceFinish;
		FHandleWorldPartitionFinish FinishCallback = OnFinish;

		const FOnHandleWorldPartitionOnceFinish HandleOnceFinish = FOnHandleWorldPartitionOnceFinish::CreateLambda([OnceFinishCallback]() mutable
		{
			OnceFinishCallback.ExecuteIfBound();
		});

		const FOnHandleWorldPartitionFinish HandleFinish = FOnHandleWorldPartitionFinish::CreateLambda([FinishCallback]() mutable
		{
			FinishCallback.ExecuteIfBound();
		});

		WorldPartitionSubsystem->SetCellsVisibilityBySetting(SetWorldPartitionVisibilitySettings, HandleOnceFinish, HandleFinish);
	}
}

UWorldPartition* UBPFunctions_WorldPartition::GetCurrentWorldPartition(const UObject* WorldContextObject)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetCurrentWorldPartition();
	}

	return nullptr;
}

TArray<UWorldPartitionRuntimeCell*> UBPFunctions_WorldPartition::GetCurrentWorldPartitionRuntimeCells(const UObject* WorldContextObject)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetCurrentWorldPartitionRuntimeCells();
	}

	return TArray<UWorldPartitionRuntimeCell*>();
}

EWorldPartitionRuntimeCellState UBPFunctions_WorldPartition::GetCellState(UWorldPartitionRuntimeCell* Cell)
{
	return ::IsValid(Cell) ? Cell->GetCurrentState() : EWorldPartitionRuntimeCellState::Unloaded;
}

bool UBPFunctions_WorldPartition::IsCellLoaded(UWorldPartitionRuntimeCell* Cell)
{
	return GetCellState(Cell) >= EWorldPartitionRuntimeCellState::Loaded;
}

bool UBPFunctions_WorldPartition::IsCellVisible(UWorldPartitionRuntimeCell* Cell)
{
	return GetCellState(Cell) == EWorldPartitionRuntimeCellState::Activated;
}

bool UBPFunctions_WorldPartition::IsCurrentWorldContainCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->IsCurrentWorldContainCell(Cell);
	}

	return false;
}

bool UBPFunctions_WorldPartition::IsStreamingCompleted(const UObject* WorldContextObject)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->IsStreamingCompleted();
	}

	return true;
}

TArray<UDataLayerInstance*> UBPFunctions_WorldPartition::GetDataLayerInstances(const UObject* WorldContextObject)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerInstances();
	}

	return TArray<UDataLayerInstance*>();
}

UDataLayerInstance* UBPFunctions_WorldPartition::GetDataLayerInstanceFromAsset(const UObject* WorldContextObject, const UDataLayerAsset* DataLayerAsset)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerInstanceFromAsset(DataLayerAsset);
	}

	return nullptr;
}

UDataLayerInstance* UBPFunctions_WorldPartition::GetDataLayerInstanceFromName(const UObject* WorldContextObject, FName DataLayerInstanceName)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerInstanceFromName(DataLayerInstanceName);
	}

	return nullptr;
}

bool UBPFunctions_WorldPartition::SetDataLayerInstanceRuntimeState(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance, EDataLayerRuntimeState State, bool bIsRecursive)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->SetDataLayerInstanceRuntimeState(DataLayerInstance, State, bIsRecursive);
	}

	return false;
}

bool UBPFunctions_WorldPartition::SetDataLayerRuntimeStateByAsset(const UObject* WorldContextObject, const UDataLayerAsset* DataLayerAsset, EDataLayerRuntimeState State, bool bIsRecursive)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->SetDataLayerRuntimeState(DataLayerAsset, State, bIsRecursive);
	}

	return false;
}

bool UBPFunctions_WorldPartition::SetDataLayerRuntimeStateByName(const UObject* WorldContextObject, FName DataLayerInstanceName, EDataLayerRuntimeState State, bool bIsRecursive)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->SetDataLayerRuntimeStateByName(DataLayerInstanceName, State, bIsRecursive);
	}

	return false;
}

bool UBPFunctions_WorldPartition::LoadDataLayer(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance, bool bIsRecursive)
{
	return SetDataLayerInstanceRuntimeState(WorldContextObject, DataLayerInstance, EDataLayerRuntimeState::Loaded, bIsRecursive);
}

bool UBPFunctions_WorldPartition::ActivateDataLayer(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance, bool bIsRecursive)
{
	return SetDataLayerInstanceRuntimeState(WorldContextObject, DataLayerInstance, EDataLayerRuntimeState::Activated, bIsRecursive);
}

bool UBPFunctions_WorldPartition::UnloadDataLayer(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance, bool bIsRecursive)
{
	return SetDataLayerInstanceRuntimeState(WorldContextObject, DataLayerInstance, EDataLayerRuntimeState::Unloaded, bIsRecursive);
}

EDataLayerRuntimeState UBPFunctions_WorldPartition::GetDataLayerInstanceRuntimeState(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerInstanceRuntimeState(DataLayerInstance);
	}

	return EDataLayerRuntimeState::Unloaded;
}

EDataLayerRuntimeState UBPFunctions_WorldPartition::GetDataLayerInstanceEffectiveRuntimeState(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerInstanceEffectiveRuntimeState(DataLayerInstance);
	}

	return EDataLayerRuntimeState::Unloaded;
}

EDataLayerRuntimeState UBPFunctions_WorldPartition::GetDataLayerRuntimeStateByAsset(const UObject* WorldContextObject, const UDataLayerAsset* DataLayerAsset)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerRuntimeStateByAsset(DataLayerAsset);
	}

	return EDataLayerRuntimeState::Unloaded;
}

EDataLayerRuntimeState UBPFunctions_WorldPartition::GetDataLayerEffectiveRuntimeStateByAsset(const UObject* WorldContextObject, const UDataLayerAsset* DataLayerAsset)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerEffectiveRuntimeStateByAsset(DataLayerAsset);
	}

	return EDataLayerRuntimeState::Unloaded;
}

EDataLayerRuntimeState UBPFunctions_WorldPartition::GetDataLayerRuntimeStateByName(const UObject* WorldContextObject, FName DataLayerInstanceName)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerRuntimeStateByName(DataLayerInstanceName);
	}

	return EDataLayerRuntimeState::Unloaded;
}

EDataLayerRuntimeState UBPFunctions_WorldPartition::GetDataLayerEffectiveRuntimeStateByName(const UObject* WorldContextObject, FName DataLayerInstanceName)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetDataLayerEffectiveRuntimeStateByName(DataLayerInstanceName);
	}

	return EDataLayerRuntimeState::Unloaded;
}

TArray<FName> UBPFunctions_WorldPartition::GetEffectiveLoadedDataLayerNames(const UObject* WorldContextObject)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetEffectiveLoadedDataLayerNames();
	}

	return TArray<FName>();
}

TArray<FName> UBPFunctions_WorldPartition::GetEffectiveActiveDataLayerNames(const UObject* WorldContextObject)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->GetEffectiveActiveDataLayerNames();
	}

	return TArray<FName>();
}

bool UBPFunctions_WorldPartition::IsAnyDataLayerInEffectiveRuntimeState(const UObject* WorldContextObject, const TArray<FName>& DataLayerNames, EDataLayerRuntimeState State)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->IsAnyDataLayerInEffectiveRuntimeState(DataLayerNames, State);
	}

	return false;
}

bool UBPFunctions_WorldPartition::IsAllDataLayerInEffectiveRuntimeState(const UObject* WorldContextObject, const TArray<FName>& DataLayerNames, EDataLayerRuntimeState State)
{
	if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		return WorldPartitionSubsystem->IsAllDataLayerInEffectiveRuntimeState(DataLayerNames, State);
	}

	return false;
}

TArray<UDataLayerInstance*> UBPFunctions_WorldPartition::GetActorDataLayerInstances(const AActor* Actor)
{
	if (::IsValid(Actor))
	{
		if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(Actor))
		{
			return WorldPartitionSubsystem->GetActorDataLayerInstances(Actor);
		}
	}

	return TArray<UDataLayerInstance*>();
}

TArray<FName> UBPFunctions_WorldPartition::GetActorDataLayerInstanceNames(const AActor* Actor)
{
	if (::IsValid(Actor))
	{
		if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(Actor))
		{
			return WorldPartitionSubsystem->GetActorDataLayerInstanceNames(Actor);
		}
	}

	return TArray<FName>();
}

TArray<UDataLayerInstance*> UBPFunctions_WorldPartition::GetCellDataLayerInstances(UWorldPartitionRuntimeCell* Cell)
{
	if (::IsValid(Cell))
	{
		if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(Cell))
		{
			return WorldPartitionSubsystem->GetCellDataLayerInstances(Cell);
		}
	}

	return TArray<UDataLayerInstance*>();
}

TArray<FName> UBPFunctions_WorldPartition::GetCellDataLayerInstanceNames(UWorldPartitionRuntimeCell* Cell)
{
	if (::IsValid(Cell))
	{
		if (const UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(Cell))
		{
			return WorldPartitionSubsystem->GetCellDataLayerInstanceNames(Cell);
		}
	}

	return TArray<FName>();
}
