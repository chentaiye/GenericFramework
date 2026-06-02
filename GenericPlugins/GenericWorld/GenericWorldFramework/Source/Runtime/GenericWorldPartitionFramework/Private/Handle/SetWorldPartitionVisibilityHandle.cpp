// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Handle/SetWorldPartitionVisibilityHandle.h"

void USetWorldPartitionVisibilityHandle::Initialize(const FSetWorldPartitionVisibilitySetting& InSetting, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	Initialize(TArray<FSetWorldPartitionVisibilitySetting>{InSetting}, OnOnceFinish, OnFinish);
}

void USetWorldPartitionVisibilityHandle::Initialize(TArray<FSetWorldPartitionVisibilitySetting> InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	for (const FSetWorldPartitionVisibilitySetting& Setting : InSettings)
	{
		if (Setting.IsValid() && !SetWorldPartitionVisibilitySettings.Contains(Setting))
		{
			SetWorldPartitionVisibilitySettings.Add(Setting);
		}
	}

	OnSetWorldPartitionVisibilityOnceFinish = OnOnceFinish;
	OnSetWorldPartitionVisibilityFinish = OnFinish;
}

void USetWorldPartitionVisibilityHandle::RemoveCell(UWorldPartitionRuntimeCell* InCell)
{
	const int32 Index = GetIndexByCell(InCell);
	if (Index >= GetCellIndex())
	{
		SetWorldPartitionVisibilitySettings.RemoveAll([InCell](const FSetWorldPartitionVisibilitySetting& Setting)
		{
			return Setting.Cell == InCell;
		});
	}
}

TArray<UWorldPartitionRuntimeCell*> USetWorldPartitionVisibilityHandle::GetCells() const
{
	TArray<UWorldPartitionRuntimeCell*> Cells;
	Cells.Reserve(SetWorldPartitionVisibilitySettings.Num());

	for (const FSetWorldPartitionVisibilitySetting& Setting : SetWorldPartitionVisibilitySettings)
	{
		Cells.Add(Setting.Cell);
	}

	return Cells;
}

void USetWorldPartitionVisibilityHandle::ExecuteHandle(int32 Index)
{
	if (!SetWorldPartitionVisibilitySettings.IsValidIndex(Index))
	{
		OnOnceFinish();
		return;
	}

	const FSetWorldPartitionVisibilitySetting& Setting = SetWorldPartitionVisibilitySettings[Index];
	UWorldPartitionRuntimeCell* Cell = Setting.Cell;
	if (!::IsValid(Cell))
	{
		OnOnceFinish();
		return;
	}

	const EWorldPartitionRuntimeCellState CurrentState = Cell->GetCurrentState();
	const bool bAlreadyVisible = CurrentState == EWorldPartitionRuntimeCellState::Activated;
	const bool bAlreadyHidden = CurrentState != EWorldPartitionRuntimeCellState::Activated;

	/** 目标状态已经满足时跳过提交，避免重复 Activate/Deactivate 干扰流送队列。 */
	if ((Setting.bVisible && bAlreadyVisible) || (!Setting.bVisible && bAlreadyHidden))
	{
		OnOnceFinish();
		return;
	}

	/** 可见性只在 Activated 与非 Activated 之间切换，加载准备由 World Partition 自身处理。 */
	if (Setting.bVisible)
	{
		Cell->Activate();
	}
	else
	{
		Cell->Deactivate();
	}

	StartWaitCurrentCell();
}

void USetWorldPartitionVisibilityHandle::HandleOnOnceFinish()
{
	Super::HandleOnOnceFinish();
	OnSetWorldPartitionVisibilityOnceFinish.ExecuteIfBound();
}

void USetWorldPartitionVisibilityHandle::HandleOnFinish()
{
	Super::HandleOnFinish();
	OnSetWorldPartitionVisibilityFinish.ExecuteIfBound();
}

TArray<FSetWorldPartitionVisibilitySetting> USetWorldPartitionVisibilityHandle::GetSetWorldPartitionVisibilitySettingsCopy() const
{
	return SetWorldPartitionVisibilitySettings;
}

bool USetWorldPartitionVisibilityHandle::GetCurrentSetWorldPartitionVisibilitySetting(FSetWorldPartitionVisibilitySetting& OutSetting) const
{
	if (SetWorldPartitionVisibilitySettings.IsValidIndex(GetCellIndex()))
	{
		OutSetting = SetWorldPartitionVisibilitySettings[GetCellIndex()];
		return true;
	}

	OutSetting = FSetWorldPartitionVisibilitySetting();
	return false;
}

bool USetWorldPartitionVisibilityHandle::IsCurrentCellOperationFinished() const
{
	if (GetCells().IsValidIndex(GetCellIndex()))
	{
		const FSetWorldPartitionVisibilitySetting& Setting = SetWorldPartitionVisibilitySettings[GetCellIndex()];
		if (UWorldPartitionRuntimeCell* Cell = Setting.Cell)
		{
			const EWorldPartitionRuntimeCellState CurrentState = Cell->GetCurrentState();
			return Setting.bVisible ? CurrentState == EWorldPartitionRuntimeCellState::Activated : CurrentState != EWorldPartitionRuntimeCellState::Activated;
		}
	}

	return true;
}
