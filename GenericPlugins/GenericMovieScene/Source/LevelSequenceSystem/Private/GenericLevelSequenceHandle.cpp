// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericLevelSequenceHandle.h"

#include "Camera/CameraComponent.h"
#include "GameplayMessageSubsystem.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "LevelSequenceType.h"
#include "MovieSceneType.h"
#include "Type/DebugType.h"

namespace
{
	// 统一把句柄状态和最后相机视图封装成 GameplayMessage，避免每个播放钩子重复组包逻辑。
	void BroadcastLevelSequenceMessage(const UObject* WorldContextObject, const FGameplayTag Channel, UGenericLevelSequenceHandle* LevelSequenceHandle)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnLevelSequenceMessage Message;
		Message.LevelSequenceHandle = LevelSequenceHandle;
		Message.CameraView = IsValid(LevelSequenceHandle) ? LevelSequenceHandle->GetLastCameraView() : FLevelSequenceCameraView();
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(Channel, Message);
	}
}

void UGenericLevelSequenceHandle::OnMovieSceneOpened()
{
	Super::OnMovieSceneOpened();

	if (!IsValid(LevelSequencePlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("OnMovieSceneOpened Failed: Invalid LevelSequencePlayer"))
		return;
	}

	// 只在播放器有效后绑定运行期事件，关闭时按同一组委托统一解绑。
	LevelSequencePlayer->OnPlay.AddUniqueDynamic(this, &UGenericLevelSequenceHandle::OnPlay);
	LevelSequencePlayer->OnPlayReverse.AddUniqueDynamic(this, &UGenericLevelSequenceHandle::OnPlayReverse);
	LevelSequencePlayer->OnPause.AddUniqueDynamic(this, &UGenericLevelSequenceHandle::OnPause);
	LevelSequencePlayer->OnStop.AddUniqueDynamic(this, &UGenericLevelSequenceHandle::OnStop);
	LevelSequencePlayer->OnFinished.AddUniqueDynamic(this, &UGenericLevelSequenceHandle::OnFinished);
	LevelSequencePlayer->OnCameraCut.AddUniqueDynamic(this, &UGenericLevelSequenceHandle::OnCameraCut);
	LevelSequenceUpdatedDelegateHandle = LevelSequencePlayer->OnSequenceUpdated().AddUObject(this, &UGenericLevelSequenceHandle::OnSequenceUpdated);
}

void UGenericLevelSequenceHandle::OnMovieSceneClosed()
{
	Super::OnMovieSceneClosed();

	if (IsValid(LevelSequencePlayer))
	{
		// 关闭时先停播再解绑委托，保证 Stop 触发的状态广播仍能走完整句柄路径。
		if (LevelSequencePlayer->IsPlaying())
		{
			LevelSequencePlayer->Stop();
		}

		LevelSequencePlayer->OnPlay.RemoveAll(this);
		LevelSequencePlayer->OnPlayReverse.RemoveAll(this);
		LevelSequencePlayer->OnPause.RemoveAll(this);
		LevelSequencePlayer->OnStop.RemoveAll(this);
		LevelSequencePlayer->OnFinished.RemoveAll(this);
		LevelSequencePlayer->OnCameraCut.RemoveAll(this);
		LevelSequencePlayer->OnSequenceUpdated().Remove(LevelSequenceUpdatedDelegateHandle);
		LevelSequenceUpdatedDelegateHandle.Reset();
		LevelSequencePlayer = nullptr;
	}

	// LevelSequenceActor 由子系统创建，句柄关闭时负责销毁，避免世界中残留临时 Actor。
	if (IsValid(LevelSequenceActor) && !LevelSequenceActor->IsActorBeingDestroyed())
	{
		LevelSequenceActor->Destroy();
	}
	LevelSequenceActor = nullptr;
	ResetCameraViewCache();
}

void UGenericLevelSequenceHandle::OnMovieScenePlay()
{
	Super::OnMovieScenePlay();
	// 新一轮播放必须丢弃上一轮缓存，否则结束回切可能使用旧相机。
	ResetCameraViewCache();
	CacheCurrentCameraView();
	BroadcastLevelSequenceMessage(this, TAG_GameplayMessage_Channel_LevelSequence_OnPlay, this);
}

void UGenericLevelSequenceHandle::OnMovieScenePlayReverse()
{
	Super::OnMovieScenePlayReverse();
	// 反向播放同样视为新一轮序列评估，先清空旧的最后相机缓存。
	ResetCameraViewCache();
	CacheCurrentCameraView();
	BroadcastLevelSequenceMessage(this, TAG_GameplayMessage_Channel_LevelSequence_OnPlayReverse, this);
}

void UGenericLevelSequenceHandle::OnMovieScenePause()
{
	Super::OnMovieScenePause();
	CacheCurrentCameraView();
	BroadcastLevelSequenceMessage(this, TAG_GameplayMessage_Channel_LevelSequence_OnPause, this);
}

void UGenericLevelSequenceHandle::OnMovieSceneStop()
{
	Super::OnMovieSceneStop();
	// Stop 阶段 Sequencer 可能已经清空 CameraCut，只广播并保留播放阶段捕获的最后有效视图。
	BroadcastLevelSequenceMessage(this, TAG_GameplayMessage_Channel_LevelSequence_OnStop, this);
}

void UGenericLevelSequenceHandle::OnMovieSceneSeek()
{
	Super::OnMovieSceneSeek();
	CacheCurrentCameraView();
	BroadcastLevelSequenceMessage(this, TAG_GameplayMessage_Channel_LevelSequence_OnSeek, this);
}

void UGenericLevelSequenceHandle::OnMovieScenePlayFinish()
{
	Super::OnMovieScenePlayFinish();
	// Finish 阶段不再重新取 CameraCut，避免空相机覆盖自然播放期间缓存的最后一帧视图。
	BroadcastLevelSequenceMessage(this, TAG_GameplayMessage_Channel_LevelSequence_OnFinish, this);
}

bool UGenericLevelSequenceHandle::PlayMovieScene()
{
	if (!IsValid(LevelSequencePlayer))
	{
		return false;
	}

	LevelSequencePlayer->Play();
	return true;
}

bool UGenericLevelSequenceHandle::PlayMovieSceneFromStart()
{
	if (!IsValid(LevelSequencePlayer))
	{
		return false;
	}

	LevelSequencePlayer->SetPlaybackPosition(FMovieSceneSequencePlaybackParams(FFrameTime(0), EUpdatePositionMethod::Jump));
	LevelSequencePlayer->Play();
	return true;
}

bool UGenericLevelSequenceHandle::PlayLoopingMovieScene(int32 NumLoops)
{
	if (!IsValid(LevelSequencePlayer))
	{
		return false;
	}

	if (IsValid(LevelSequenceActor))
	{
		FMovieSceneSequencePlaybackSettings Settings = LevelSequenceActor->PlaybackSettings;
		Settings.LoopCount.Value = NumLoops;
		SetPlaybackSettings(Settings);
	}

	LevelSequencePlayer->PlayLooping(NumLoops);
	return true;
}

bool UGenericLevelSequenceHandle::PlayReverseMovieScene()
{
	if (!IsValid(LevelSequencePlayer))
	{
		return false;
	}

	LevelSequencePlayer->PlayReverse();
	return true;
}

bool UGenericLevelSequenceHandle::PauseMovieScene()
{
	if (!IsValid(LevelSequencePlayer))
	{
		return false;
	}

	LevelSequencePlayer->Pause();
	return true;
}

bool UGenericLevelSequenceHandle::StopMovieScene()
{
	if (!IsValid(LevelSequencePlayer))
	{
		return false;
	}

	// 主动 Stop 前先抓一次当前相机，防止 Stop 过程清空 CameraCut 后丢失最后帧。
	CacheCurrentCameraView();
	LevelSequencePlayer->Stop();
	return true;
}

bool UGenericLevelSequenceHandle::SeekMovieScene(FTimecode SeekTime)
{
	if (!IsValid(LevelSequencePlayer))
	{
		return false;
	}

	const FMovieSceneSequencePlaybackParams SeekParams = FMovieSceneSequencePlaybackParams(FFrameTime(SeekTime.ToFrameNumber(LevelSequencePlayer->GetFrameRate())), EUpdatePositionMethod::Jump);
	LevelSequencePlayer->SetPlaybackPosition(SeekParams);

	Super::SeekMovieScene(SeekTime);
	return true;
}

void UGenericLevelSequenceHandle::ChangeMovieSceneDirection()
{
	if (IsValid(LevelSequencePlayer))
	{
		LevelSequencePlayer->ChangePlaybackDirection();
	}
}

bool UGenericLevelSequenceHandle::IsPlaying()
{
	return IsValid(LevelSequencePlayer) && LevelSequencePlayer->IsPlaying();
}

bool UGenericLevelSequenceHandle::IsLooping()
{
	return GetPlaybackSettings().LoopCount.Value != 0;
}

bool UGenericLevelSequenceHandle::IsPaused()
{
	return IsValid(LevelSequencePlayer) && LevelSequencePlayer->IsPaused();
}

bool UGenericLevelSequenceHandle::IsReversed()
{
	return IsValid(LevelSequencePlayer) && LevelSequencePlayer->IsReversed();
}

FTimecode UGenericLevelSequenceHandle::GetCurrentTime()
{
	return IsValid(LevelSequencePlayer) ? LevelSequencePlayer->GetCurrentTime().ToTimecode() : FTimecode();
}

FTimecode UGenericLevelSequenceHandle::GetDuration()
{
	return IsValid(LevelSequencePlayer) ? LevelSequencePlayer->GetDuration().ToTimecode() : FTimecode();
}

FFrameRate UGenericLevelSequenceHandle::GetFrameRate()
{
	return IsValid(LevelSequencePlayer) ? LevelSequencePlayer->GetFrameRate() : FFrameRate();
}

void UGenericLevelSequenceHandle::SetFrameRate(FFrameRate FrameRate)
{
	if (IsValid(LevelSequencePlayer))
	{
		LevelSequencePlayer->SetFrameRate(FrameRate);
	}
}

float UGenericLevelSequenceHandle::GetPlayRate()
{
	return IsValid(LevelSequencePlayer) ? LevelSequencePlayer->GetPlayRate() : 1.f;
}

void UGenericLevelSequenceHandle::SetPlayRate(float InPlayRate)
{
	if (IsValid(LevelSequencePlayer))
	{
		LevelSequencePlayer->SetPlayRate(InPlayRate);
	}
}

void UGenericLevelSequenceHandle::SetTimeRange(float StartTime, float Duration)
{
	if (IsValid(LevelSequencePlayer))
	{
		LevelSequencePlayer->SetTimeRange(StartTime, Duration);
	}
}

bool UGenericLevelSequenceHandle::GetDisableCameraCuts() const
{
	return IsValid(LevelSequencePlayer) && LevelSequencePlayer->GetDisableCameraCuts();
}

void UGenericLevelSequenceHandle::SetDisableCameraCuts(bool bInDisableCameraCuts)
{
	if (IsValid(LevelSequencePlayer))
	{
		LevelSequencePlayer->SetDisableCameraCuts(bInDisableCameraCuts);
	}
}

ALevelSequenceActor* UGenericLevelSequenceHandle::GetLevelSequenceActor() const
{
	return LevelSequenceActor;
}

ULevelSequencePlayer* UGenericLevelSequenceHandle::GetULevelSequencePlayer() const
{
	return LevelSequencePlayer;
}

FString UGenericLevelSequenceHandle::GetSequenceName() const
{
	return IsValid(LevelSequencePlayer) ? LevelSequencePlayer->GetSequenceName() : FString();
}

FLevelSequenceCameraView UGenericLevelSequenceHandle::GetLastCameraView() const
{
	return LastCameraView;
}

ULevelSequence* UGenericLevelSequenceHandle::GetSequence() const
{
	return IsValid(LevelSequenceActor) ? LevelSequenceActor->GetSequence() : nullptr;
}

void UGenericLevelSequenceHandle::SetSequence(ULevelSequence* InSequence, bool bIsPlay)
{
	if (!IsValid(LevelSequenceActor) || !IsValid(LevelSequencePlayer) || !IsValid(InSequence))
	{
		return;
	}

	LevelSequencePlayer->Stop();
	LevelSequenceActor->SetSequence(InSequence);

	if (bIsPlay)
	{
		PlayMovieScene();
	}
}

FMovieSceneSequencePlaybackSettings UGenericLevelSequenceHandle::GetPlaybackSettings() const
{
	return IsValid(LevelSequenceActor) ? LevelSequenceActor->PlaybackSettings : FMovieSceneSequencePlaybackSettings();
}

void UGenericLevelSequenceHandle::SetPlaybackSettings(const FMovieSceneSequencePlaybackSettings& InSettings)
{
	if (IsValid(LevelSequenceActor))
	{
		LevelSequenceActor->PlaybackSettings = InSettings;
	}

	if (IsValid(LevelSequencePlayer))
	{
		LevelSequencePlayer->SetPlaybackSettings(InSettings);
	}
}

void UGenericLevelSequenceHandle::OnPlay()
{
	OnMovieScenePlay();
}

void UGenericLevelSequenceHandle::OnPlayReverse()
{
	OnMovieScenePlayReverse();
}

void UGenericLevelSequenceHandle::OnPause()
{
	OnMovieScenePause();
}

void UGenericLevelSequenceHandle::OnStop()
{
	OnMovieSceneStop();
}

void UGenericLevelSequenceHandle::OnFinished()
{
	OnMovieScenePlayFinish();
}

void UGenericLevelSequenceHandle::OnCameraCut(UCameraComponent* InCameraComponent)
{
	CacheCameraView(InCameraComponent);
}

void UGenericLevelSequenceHandle::OnSequenceUpdated(const UMovieSceneSequencePlayer&, FFrameTime, FFrameTime)
{
	// 播放器停止/完成后的评估回调可能携带空 CameraCut，直接返回避免覆盖 LastCameraView。
	if (!IsValid(LevelSequencePlayer) || (!LevelSequencePlayer->IsPlaying() && !LevelSequencePlayer->IsPaused()))
	{
		return;
	}

	CacheCurrentCameraView();
}

bool UGenericLevelSequenceHandle::CacheCameraView(UCameraComponent* InCameraComponent)
{
	if (!IsValid(InCameraComponent))
	{
		return false;
	}

	FMinimalViewInfo CameraView;
	InCameraComponent->GetCameraView(0.f, CameraView);

	LastCameraView.CameraComponent = InCameraComponent;
	LastCameraView.CameraView = CameraView;
	LastCameraView.bHasCameraView = true;
	return true;
}

bool UGenericLevelSequenceHandle::CacheCurrentCameraView()
{
	return CacheCameraView(GetActiveCameraComponent());
}

UCameraComponent* UGenericLevelSequenceHandle::GetActiveCameraComponent() const
{
	if (!IsValid(LevelSequencePlayer))
	{
		return nullptr;
	}

	UCameraComponent* ActiveCameraComponent = LevelSequencePlayer->GetActiveCameraComponent();
	if (IsValid(ActiveCameraComponent))
	{
		return ActiveCameraComponent;
	}

	// UE 在某些结束帧会让 ActiveCamera 为空，快照仍可能保留当前帧相机引用。
	FLevelSequencePlayerSnapshot Snapshot;
	LevelSequencePlayer->TakeFrameSnapshot(Snapshot);
	return Snapshot.CameraComponent.Get();
}

void UGenericLevelSequenceHandle::ResetCameraViewCache()
{
	LastCameraView = FLevelSequenceCameraView();
}
