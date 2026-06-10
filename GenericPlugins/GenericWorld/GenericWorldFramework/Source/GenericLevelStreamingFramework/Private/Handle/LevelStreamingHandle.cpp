// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Handle/LevelStreamingHandle.h"

FOnLevelStreamingHandleOnceFinish& ULevelStreamingHandle::GetHandleOnceFinishEvent()
{
	return OnOnceFinishEvent;
}

FOnLevelStreamingHandleFinish& ULevelStreamingHandle::GetHandleFinishEvent()
{
	return OnFinishEvent;
}

void ULevelStreamingHandle::Startup()
{
	bIsFinished = false;

	if (GetLevels().IsValidIndex(LevelIndex))
	{
		bIsRunning = true;
		ExecuteHandle(LevelIndex);
	}
	else
	{
		OnFinish();
	}
}

int32 ULevelStreamingHandle::GetLevelIndex() const
{
	return LevelIndex;
}

int32 ULevelStreamingHandle::GetLevelCount()
{
	return GetLevels().Num();
}

int32 ULevelStreamingHandle::GetCompletedLevelCount()
{
	if (bIsFinished)
	{
		return GetLevelCount();
	}

	return bIsRunning ? LevelIndex : 0;
}

int32 ULevelStreamingHandle::GetRemainingLevelCount()
{
	if (bIsFinished)
	{
		return 0;
	}

	const int32 LevelCount = GetLevelCount();
	return bIsRunning ? FMath::Max(0, LevelCount - LevelIndex) : LevelCount;
}

bool ULevelStreamingHandle::IsRunning() const
{
	return bIsRunning;
}

bool ULevelStreamingHandle::IsFinished() const
{
	return bIsFinished;
}

bool ULevelStreamingHandle::HasPendingLevels()
{
	return bIsRunning && GetLevels().IsValidIndex(LevelIndex);
}

bool ULevelStreamingHandle::IsValidLevelIndex(int32 InIndex)
{
	return GetLevels().IsValidIndex(InIndex);
}

TSoftObjectPtr<UWorld> ULevelStreamingHandle::GetLastFinishedLevel() const
{
	return LastFinishedLevel;
}

TSoftObjectPtr<UWorld> ULevelStreamingHandle::GetLevelByIndex(int32 InIndex)
{
	const TArray<TSoftObjectPtr<UWorld>> Levels = GetLevels();
	if (Levels.IsValidIndex(InIndex))
	{
		return Levels[InIndex];
	}
	return nullptr;
}

int32 ULevelStreamingHandle::GetIndexByLevel(const TSoftObjectPtr<UWorld>& InLevel)
{
	if (InLevel.IsNull())
	{
		return INDEX_NONE;
	}

	const FSoftObjectPath TargetPath = InLevel.ToSoftObjectPath();
	const TArray<TSoftObjectPtr<UWorld>> Levels = GetLevels();
	for (int32 Index = 0; Index < Levels.Num(); ++Index)
	{
		if (Levels[Index].ToSoftObjectPath() == TargetPath)
		{
			return Index;
		}
	}

	return INDEX_NONE;
}

bool ULevelStreamingHandle::ContainsLevel(const TSoftObjectPtr<UWorld>& InLevel)
{
	return GetIndexByLevel(InLevel) != INDEX_NONE;
}

void ULevelStreamingHandle::OnOnceFinish()
{
	LastFinishedLevel = GetLevelByIndex(LevelIndex);
	++LevelIndex;
	HandleOnOnceFinish();
	BroadcastOnceFinish();

	if (GetLevels().IsValidIndex(LevelIndex))
	{
		ExecuteHandle(LevelIndex);
	}
	else
	{
		OnFinish();
	}
}

void ULevelStreamingHandle::HandleOnOnceFinish()
{
}

void ULevelStreamingHandle::OnFinish()
{
	LevelIndex = 0;
	bIsRunning = false;
	bIsFinished = true;
	HandleOnFinish();
	BroadcastFinish();
	LastFinishedLevel.Reset();
}

void ULevelStreamingHandle::HandleOnFinish()
{
}

void ULevelStreamingHandle::BroadcastOnceFinish()
{
	OnOnceFinishEvent.Broadcast(this, LastFinishedLevel);
	BPDelegate_OnOnceFinish.Broadcast(this, LastFinishedLevel);
}

void ULevelStreamingHandle::BroadcastFinish()
{
	OnFinishEvent.Broadcast(this);
	BPDelegate_OnFinish.Broadcast(this);
}
