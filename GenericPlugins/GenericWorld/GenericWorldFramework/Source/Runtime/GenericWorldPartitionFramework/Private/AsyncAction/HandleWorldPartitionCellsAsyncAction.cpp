// Copyright ChenTaiye 2025. All Rights Reserved.

#include "AsyncAction/HandleWorldPartitionCellsAsyncAction.h"

#include "Subsystem/GenericWorldPartitionSubsystem.h"

UHandleWorldPartitionCellsAsyncAction* UHandleWorldPartitionCellsAsyncAction::AsyncLoadCells(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells)
{
	UHandleWorldPartitionCellsAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellsAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->LoadCells(Cells, FOnHandleWorldPartitionOnceFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleOnceFinish), FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

UHandleWorldPartitionCellsAsyncAction* UHandleWorldPartitionCellsAsyncAction::AsyncLoadCellsBySetting(const UObject* WorldContextObject, TArray<FLoadWorldPartitionSetting> LoadWorldPartitionSettings)
{
	UHandleWorldPartitionCellsAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellsAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->LoadCellsBySetting(LoadWorldPartitionSettings, FOnHandleWorldPartitionOnceFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleOnceFinish), FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

UHandleWorldPartitionCellsAsyncAction* UHandleWorldPartitionCellsAsyncAction::AsyncUnloadCells(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells)
{
	UHandleWorldPartitionCellsAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellsAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->UnloadCells(Cells, FOnHandleWorldPartitionOnceFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleOnceFinish), FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

UHandleWorldPartitionCellsAsyncAction* UHandleWorldPartitionCellsAsyncAction::AsyncUnloadCellsBySetting(const UObject* WorldContextObject, TArray<FUnloadWorldPartitionSetting> UnloadWorldPartitionSettings)
{
	UHandleWorldPartitionCellsAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellsAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->UnloadCellsBySetting(UnloadWorldPartitionSettings, FOnHandleWorldPartitionOnceFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleOnceFinish), FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

UHandleWorldPartitionCellsAsyncAction* UHandleWorldPartitionCellsAsyncAction::AsyncSetCellsVisibility(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells, bool bVisible)
{
	UHandleWorldPartitionCellsAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellsAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->SetCellsVisibility(Cells, bVisible, FOnHandleWorldPartitionOnceFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleOnceFinish), FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

UHandleWorldPartitionCellsAsyncAction* UHandleWorldPartitionCellsAsyncAction::AsyncSetCellsVisibilityBySetting(const UObject* WorldContextObject, TArray<FSetWorldPartitionVisibilitySetting> SetWorldPartitionVisibilitySettings)
{
	UHandleWorldPartitionCellsAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellsAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->SetCellsVisibilityBySetting(SetWorldPartitionVisibilitySettings, FOnHandleWorldPartitionOnceFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleOnceFinish), FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellsAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

void UHandleWorldPartitionCellsAsyncAction::OnHandleOnceFinish() const
{
	OnOnceFinish.Broadcast();
}

void UHandleWorldPartitionCellsAsyncAction::OnHandleFinish() const
{
	OnFinish.Broadcast();
}
