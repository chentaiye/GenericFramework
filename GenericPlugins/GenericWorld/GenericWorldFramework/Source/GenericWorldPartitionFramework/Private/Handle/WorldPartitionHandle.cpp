// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Handle/WorldPartitionHandle.h"

FOnWorldPartitionHandleOnceFinish& UWorldPartitionHandle::GetHandleOnceFinishEvent()
{
	return OnOnceFinishEvent;
}

FOnWorldPartitionHandleFinish& UWorldPartitionHandle::GetHandleFinishEvent()
{
	return OnFinishEvent;
}

void UWorldPartitionHandle::Startup()
{
	bIsFinished = false;

	if (GetCells().IsValidIndex(CellIndex))
	{
		bIsRunning = true;
		ExecuteHandle(CellIndex);
	}
	else
	{
		OnFinish();
	}
}

int32 UWorldPartitionHandle::GetCellIndex() const
{
	return CellIndex;
}

int32 UWorldPartitionHandle::GetCellCount() const
{
	return GetCells().Num();
}

int32 UWorldPartitionHandle::GetCompletedCellCount() const
{
	if (bIsFinished)
	{
		return GetCellCount();
	}

	return bIsRunning ? CellIndex : 0;
}

int32 UWorldPartitionHandle::GetRemainingCellCount() const
{
	if (bIsFinished)
	{
		return 0;
	}

	const int32 CellCount = GetCellCount();
	return bIsRunning ? FMath::Max(0, CellCount - CellIndex) : CellCount;
}

bool UWorldPartitionHandle::IsRunning() const
{
	return bIsRunning;
}

bool UWorldPartitionHandle::IsFinished() const
{
	return bIsFinished;
}

bool UWorldPartitionHandle::HasPendingCells() const
{
	return bIsRunning && GetCells().IsValidIndex(CellIndex);
}

bool UWorldPartitionHandle::IsValidCellIndex(int32 InIndex) const
{
	return GetCells().IsValidIndex(InIndex);
}

UWorldPartitionRuntimeCell* UWorldPartitionHandle::GetLastFinishedCell() const
{
	return LastFinishedCell;
}

UWorldPartitionRuntimeCell* UWorldPartitionHandle::GetCellByIndex(int32 InIndex) const
{
	const TArray<UWorldPartitionRuntimeCell*> Cells = GetCells();
	return Cells.IsValidIndex(InIndex) ? Cells[InIndex] : nullptr;
}

int32 UWorldPartitionHandle::GetIndexByCell(UWorldPartitionRuntimeCell* InCell) const
{
	if (!::IsValid(InCell))
	{
		return INDEX_NONE;
	}

	return GetCells().IndexOfByKey(InCell);
}

bool UWorldPartitionHandle::ContainsCell(UWorldPartitionRuntimeCell* InCell) const
{
	return GetIndexByCell(InCell) != INDEX_NONE;
}

void UWorldPartitionHandle::OnOnceFinish()
{
	StopWaitCurrentCell();

	/** 先记录完成的 Cell 再推进索引，保证 OnceFinish 广播能拿到刚完成的目标。 */
	LastFinishedCell = GetCellByIndex(CellIndex);
	++CellIndex;

	HandleOnOnceFinish();
	BroadcastOnceFinish();

	if (GetCells().IsValidIndex(CellIndex))
	{
		ExecuteHandle(CellIndex);
	}
	else
	{
		OnFinish();
	}
}

void UWorldPartitionHandle::HandleOnOnceFinish()
{
}

void UWorldPartitionHandle::OnFinish()
{
	StopWaitCurrentCell();

	/** 整组请求完成后重置索引，句柄对象如果被复用也不会残留上一次进度。 */
	CellIndex = 0;
	bIsRunning = false;
	bIsFinished = true;
	HandleOnFinish();
	BroadcastFinish();
	LastFinishedCell = nullptr;
}

void UWorldPartitionHandle::HandleOnFinish()
{
}

void UWorldPartitionHandle::StartWaitCurrentCell()
{
	if (!GetWorld())
	{
		OnOnceFinish();
		return;
	}

	StopWaitCurrentCell();
	/** Cell 的流送状态通常在后续 Tick 更新，因此这里用下一帧轮询而不是同步判定。 */
	WaitingTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateUObject(this, &UWorldPartitionHandle::WaitCurrentCellNextTick));
}

void UWorldPartitionHandle::StopWaitCurrentCell()
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(WaitingTimerHandle);
	}
}

void UWorldPartitionHandle::BroadcastOnceFinish()
{
	OnOnceFinishEvent.Broadcast(this, LastFinishedCell);
	BPDelegate_OnOnceFinish.Broadcast(this, LastFinishedCell);
}

void UWorldPartitionHandle::BroadcastFinish()
{
	OnFinishEvent.Broadcast(this);
	BPDelegate_OnFinish.Broadcast(this);
}

void UWorldPartitionHandle::WaitCurrentCellNextTick()
{
	if (IsCurrentCellOperationFinished())
	{
		OnOnceFinish();
		return;
	}

	StartWaitCurrentCell();
}
