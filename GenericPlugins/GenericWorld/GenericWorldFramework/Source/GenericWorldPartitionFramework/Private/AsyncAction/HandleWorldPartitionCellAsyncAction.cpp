// Copyright ChenTaiye 2025. All Rights Reserved.

#include "AsyncAction/HandleWorldPartitionCellAsyncAction.h"

#include "Subsystem/GenericWorldPartitionSubsystem.h"

UHandleWorldPartitionCellAsyncAction* UHandleWorldPartitionCellAsyncAction::AsyncLoadCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell)
{
	UHandleWorldPartitionCellAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->LoadCell(Cell, FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

UHandleWorldPartitionCellAsyncAction* UHandleWorldPartitionCellAsyncAction::AsyncUnloadCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell)
{
	UHandleWorldPartitionCellAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->UnloadCell(Cell, FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

UHandleWorldPartitionCellAsyncAction* UHandleWorldPartitionCellAsyncAction::AsyncSetCellVisibility(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell, bool bVisible)
{
	UHandleWorldPartitionCellAsyncAction* NewAction = NewObject<UHandleWorldPartitionCellAsyncAction>();

	if (UGenericWorldPartitionSubsystem* WorldPartitionSubsystem = UGenericWorldPartitionSubsystem::Get(WorldContextObject))
	{
		WorldPartitionSubsystem->SetCellVisibility(Cell, bVisible, FOnHandleWorldPartitionFinish::CreateUObject(NewAction, &UHandleWorldPartitionCellAsyncAction::OnHandleFinish));
	}

	return NewAction;
}

void UHandleWorldPartitionCellAsyncAction::OnHandleFinish() const
{
	OnFinish.Broadcast();
}
