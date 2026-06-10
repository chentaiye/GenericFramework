// Copyright ChenTaiye 2025. All Rights Reserved. 

#include "GenericMediaSubsystem.h"

#include "GenericMediaHandle.h"
#include "MediaSource.h"
#include "MovieSceneType.h"
#include "Type/DebugType.h"

UGenericMediaSubsystem* UGenericMediaSubsystem::Get(const UObject* WorldContextObject)
{
	if (const UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		return World->GetSubsystem<ThisClass>();
	}
	return nullptr;
}

UGenericMediaHandle* UGenericMediaSubsystem::ConstructMediaHandle(const UObject* WorldContextObject, UMediaPlayer* InMediaPlayer, UMediaSource* InMediaSource, const FMediaPlayerOptions& InOptions)
{
	if (!IsValid(InMediaPlayer) || !IsValid(InMediaSource))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("ConstructMediaHandle Failed: Invalid MediaPlayer or MediaSource"))
		return nullptr;
	}

	if (UGenericMediaSubsystem* GenericLevelSequenceSubsystem = UGenericMediaSubsystem::Get(WorldContextObject))
	{
		UGenericMediaHandle* NewHandle = NewObject<UGenericMediaHandle>(GenericLevelSequenceSubsystem);
		// Register 会立即绑定媒体事件并发起异步打开；子系统列表负责后续统一反注册。
		NewHandle->Register(InMediaPlayer, InMediaSource, InOptions);
		GenericLevelSequenceSubsystem->RegisterMediaHandle(NewHandle);

		return NewHandle;
	}

	return nullptr;
}

void UGenericMediaSubsystem::DeconstructMediaHandle(const UObject* WorldContextObject, UGenericMediaHandle* InHandle)
{
	if (UGenericMediaSubsystem* GenericMediaSubsystem = UGenericMediaSubsystem::Get(WorldContextObject))
	{
		GenericMediaSubsystem->UnRegisterMediaHandle(InHandle);
	}
}

void UGenericMediaSubsystem::RegisterMediaHandle(UGenericMediaHandle* InHandle)
{
	if (!IsValid(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is InValid"))
		return;
	}

	if (MediaHandles.Contains(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is Already Register"))
		return;
	}

	// 这里只做托管登记，媒体打开和事件绑定已经在 UGenericMediaHandle::Register 中完成。
	MediaHandles.Add(InHandle);
}

void UGenericMediaSubsystem::UnRegisterMediaHandle(UGenericMediaHandle* InHandle)
{
	if (!IsValid(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is InValid"))
		return;
	}

	if (!MediaHandles.Contains(InHandle))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Handle Is Already UnRegister"))
		return;
	}

	// 反注册时由句柄关闭底层播放器并解绑动态委托。
	InHandle->CloseMovieScene();
	MediaHandles.Remove(InHandle);
}
