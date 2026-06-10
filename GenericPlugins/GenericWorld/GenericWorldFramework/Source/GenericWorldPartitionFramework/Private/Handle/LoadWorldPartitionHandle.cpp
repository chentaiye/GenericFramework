// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Handle/LoadWorldPartitionHandle.h"

void ULoadWorldPartitionHandle::Initialize(const FLoadWorldPartitionSetting& InSetting, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	Initialize(TArray<FLoadWorldPartitionSetting>{InSetting}, OnOnceFinish, OnFinish);
}

void ULoadWorldPartitionHandle::Initialize(TArray<FLoadWorldPartitionSetting> InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	for (const FLoadWorldPartitionSetting& Setting : InSettings)
	{
		if (Setting.IsValid() && !LoadWorldPartitionSettings.Contains(Setting))
		{
			LoadWorldPartitionSettings.Add(Setting);
		}
	}

	OnLoadWorldPartitionOnceFinish = OnOnceFinish;
	OnLoadWorldPartitionFinish = OnFinish;
}

void ULoadWorldPartitionHandle::RemoveCell(UWorldPartitionRuntimeCell* InCell)
{
	const int32 Index = GetIndexByCell(InCell);
	if (Index >= GetCellIndex())
	{
		LoadWorldPartitionSettings.RemoveAll([InCell](const FLoadWorldPartitionSetting& Setting)
		{
			return Setting.Cell == InCell;
		});
	}
}

TArray<UWorldPartitionRuntimeCell*> ULoadWorldPartitionHandle::GetCells() const
{
	TArray<UWorldPartitionRuntimeCell*> Cells;
	Cells.Reserve(LoadWorldPartitionSettings.Num());

	for (const FLoadWorldPartitionSetting& Setting : LoadWorldPartitionSettings)
	{
		Cells.Add(Setting.Cell);
	}

	return Cells;
}

void ULoadWorldPartitionHandle::ExecuteHandle(int32 Index)
{
	if (!LoadWorldPartitionSettings.IsValidIndex(Index))
	{
		OnOnceFinish();
		return;
	}

	/** 已经 Loaded 或 Activated 的 Cell 不再重复调用 Load，直接进入下一个目标。 */
	UWorldPartitionRuntimeCell* Cell = LoadWorldPartitionSettings[Index].Cell;
	if (!::IsValid(Cell) || Cell->GetCurrentState() >= EWorldPartitionRuntimeCellState::Loaded)
	{
		OnOnceFinish();
		return;
	}

	/** Load 只提交请求，实际状态变化由 World Partition 后续 Tick 推进。 */
	Cell->Load();
	StartWaitCurrentCell();
}

void ULoadWorldPartitionHandle::HandleOnOnceFinish()
{
	Super::HandleOnOnceFinish();
	OnLoadWorldPartitionOnceFinish.ExecuteIfBound();
}

void ULoadWorldPartitionHandle::HandleOnFinish()
{
	Super::HandleOnFinish();
	OnLoadWorldPartitionFinish.ExecuteIfBound();
}

TArray<FLoadWorldPartitionSetting> ULoadWorldPartitionHandle::GetLoadWorldPartitionSettingsCopy() const
{
	return LoadWorldPartitionSettings;
}

bool ULoadWorldPartitionHandle::GetCurrentLoadWorldPartitionSetting(FLoadWorldPartitionSetting& OutSetting) const
{
	if (LoadWorldPartitionSettings.IsValidIndex(GetCellIndex()))
	{
		OutSetting = LoadWorldPartitionSettings[GetCellIndex()];
		return true;
	}

	OutSetting = FLoadWorldPartitionSetting();
	return false;
}

bool ULoadWorldPartitionHandle::IsCurrentCellOperationFinished() const
{
	if (UWorldPartitionRuntimeCell* Cell = GetCellByIndex(GetCellIndex()))
	{
		return Cell->GetCurrentState() >= EWorldPartitionRuntimeCellState::Loaded;
	}

	return true;
}
