// Copyright ChenTaiye 2025. All Rights Reserved. 

#include "GenericLevelSequenceSubsystem.h"

#include "GenericLevelSequenceHandle.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MovieSceneType.h"
#include "Type/DebugType.h"

UGenericLevelSequenceSubsystem* UGenericLevelSequenceSubsystem::Get(const UObject* WorldContextObject)
{
	if (const UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		return World->GetSubsystem<ThisClass>();
	}
	return nullptr;
}

UGenericLevelSequenceHandle* UGenericLevelSequenceSubsystem::ConstructLevelSequenceHandle(const UObject* WorldContextObject, ULevelSequence* InLevelSequence, const FMovieSceneSequencePlaybackSettings& InSettings)
{
	if (!IsValid(InLevelSequence))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("ConstructLevelSequenceHandle Failed: Invalid LevelSequence"))
		return nullptr;
	}

	if (UGenericLevelSequenceSubsystem* GenericLevelSequenceSubsystem = UGenericLevelSequenceSubsystem::Get(WorldContextObject))
	{
		UGenericLevelSequenceHandle* NewHandle = NewObject<UGenericLevelSequenceHandle>(GenericLevelSequenceSubsystem);

		// Runtime 创建的 Actor/Player 由句柄保存，避免 CreateLevelSequencePlayer 返回的临时 Actor 被 GC 或遗留。
		ALevelSequenceActor* LevelSequenceActor = nullptr;
		ULevelSequencePlayer* LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GenericLevelSequenceSubsystem, InLevelSequence, InSettings, LevelSequenceActor);
		if (!IsValid(LevelSequenceActor) || !IsValid(LevelSequencePlayer))
		{
			GenericLOG(GenericLogMovieScene, Error, TEXT("ConstructLevelSequenceHandle Failed: Unable To Create LevelSequencePlayer"))
			return nullptr;
		}

		NewHandle->LevelSequenceActor = LevelSequenceActor;
		NewHandle->LevelSequencePlayer = LevelSequencePlayer;
		// 注册会立即调用 OpenMovieScene 绑定播放器委托，调用方拿到句柄时已经进入可控状态。
		GenericLevelSequenceSubsystem->RegisterLevelSequenceHandle(NewHandle);

		return NewHandle;
	}

	return nullptr;
}

void UGenericLevelSequenceSubsystem::DeconstructLevelSequenceHandle(const UObject* WorldContextObject, UGenericLevelSequenceHandle* InHandle)
{
	if (UGenericLevelSequenceSubsystem* GenericLevelSequenceSubsystem = UGenericLevelSequenceSubsystem::Get(WorldContextObject))
	{
		GenericLevelSequenceSubsystem->UnRegisterLevelSequenceHandle(InHandle);
	}
}

void UGenericLevelSequenceSubsystem::RegisterLevelSequenceHandle(UGenericLevelSequenceHandle* InHandle)
{
	if (!IsValid(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is InValid"))
		return;
	}

	if (LevelSequenceHandles.Contains(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is Already Register"))
		return;
	}

	LevelSequenceHandles.Add(InHandle);
	// 加入列表后再打开，确保打开流程触发的事件仍处于子系统托管生命周期内。
	InHandle->OpenMovieScene();
}

void UGenericLevelSequenceSubsystem::UnRegisterLevelSequenceHandle(UGenericLevelSequenceHandle* InHandle)
{
	if (!IsValid(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is InValid"))
		return;
	}

	if (!LevelSequenceHandles.Contains(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is Already UnRegister"))
		return;
	}

	// 先关闭再移除，让关闭流程仍能访问子系统托管上下文。
	InHandle->CloseMovieScene();
	LevelSequenceHandles.Remove(InHandle);
}
