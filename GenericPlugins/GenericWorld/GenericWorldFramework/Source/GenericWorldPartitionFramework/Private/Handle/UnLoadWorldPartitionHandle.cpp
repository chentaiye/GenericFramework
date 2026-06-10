// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Handle/UnLoadWorldPartitionHandle.h"

void UUnLoadWorldPartitionHandle::Initialize(const FUnloadWorldPartitionSetting& InSetting, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	Initialize(TArray<FUnloadWorldPartitionSetting>{InSetting}, OnOnceFinish, OnFinish);
}

void UUnLoadWorldPartitionHandle::Initialize(TArray<FUnloadWorldPartitionSetting> InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	for (const FUnloadWorldPartitionSetting& Setting : InSettings)
	{
		if (Setting.IsValid() && !UnLoadWorldPartitionSettings.Contains(Setting))
		{
			UnLoadWorldPartitionSettings.Add(Setting);
		}
	}

	OnUnLoadWorldPartitionOnceFinish = OnOnceFinish;
	OnUnLoadWorldPartitionFinish = OnFinish;
}

void UUnLoadWorldPartitionHandle::RemoveCell(UWorldPartitionRuntimeCell* InCell)
{
	const int32 Index = GetIndexByCell(InCell);
	if (Index >= GetCellIndex())
	{
		UnLoadWorldPartitionSettings.RemoveAll([InCell](const FUnloadWorldPartitionSetting& Setting)
		{
			return Setting.Cell == InCell;
		});
	}
}

TArray<UWorldPartitionRuntimeCell*> UUnLoadWorldPartitionHandle::GetCells() const
{
	TArray<UWorldPartitionRuntimeCell*> Cells;
	Cells.Reserve(UnLoadWorldPartitionSettings.Num());

	for (const FUnloadWorldPartitionSetting& Setting : UnLoadWorldPartitionSettings)
	{
		Cells.Add(Setting.Cell);
	}

	return Cells;
}

void UUnLoadWorldPartitionHandle::ExecuteHandle(int32 Index)
{
	if (!UnLoadWorldPartitionSettings.IsValidIndex(Index))
	{
		OnOnceFinish();
		return;
	}

	/** 已经 Unloaded 的 Cell 不再提交卸载，避免等待一个不会变化的状态。 */
	UWorldPartitionRuntimeCell* Cell = UnLoadWorldPartitionSettings[Index].Cell;
	if (!::IsValid(Cell) || Cell->GetCurrentState() == EWorldPartitionRuntimeCellState::Unloaded)
	{
		OnOnceFinish();
		return;
	}

	/** Unload 只提交请求，后续通过轮询等待 Cell 真正回到 Unloaded。 */
	Cell->Unload();
	StartWaitCurrentCell();
}

void UUnLoadWorldPartitionHandle::HandleOnOnceFinish()
{
	Super::HandleOnOnceFinish();
	OnUnLoadWorldPartitionOnceFinish.ExecuteIfBound();
}

void UUnLoadWorldPartitionHandle::HandleOnFinish()
{
	Super::HandleOnFinish();
	OnUnLoadWorldPartitionFinish.ExecuteIfBound();
}

TArray<FUnloadWorldPartitionSetting> UUnLoadWorldPartitionHandle::GetUnLoadWorldPartitionSettingsCopy() const
{
	return UnLoadWorldPartitionSettings;
}

bool UUnLoadWorldPartitionHandle::GetCurrentUnLoadWorldPartitionSetting(FUnloadWorldPartitionSetting& OutSetting) const
{
	if (UnLoadWorldPartitionSettings.IsValidIndex(GetCellIndex()))
	{
		OutSetting = UnLoadWorldPartitionSettings[GetCellIndex()];
		return true;
	}

	OutSetting = FUnloadWorldPartitionSetting();
	return false;
}

bool UUnLoadWorldPartitionHandle::IsCurrentCellOperationFinished() const
{
	if (UWorldPartitionRuntimeCell* Cell = GetCellByIndex(GetCellIndex()))
	{
		return Cell->GetCurrentState() == EWorldPartitionRuntimeCellState::Unloaded;
	}

	return true;
}
