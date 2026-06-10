// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericMediaHandle.h"

#include "GameplayMessageSubsystem.h"
#include "MediaSource.h"
#include "MediaPlayer.h"
#include "MediaPlaylist.h"
#include "MediaType.h"
#include "MovieSceneType.h"
#include "Type/DebugType.h"

namespace
{
	// 媒体源尚未打开或视频轨道没有帧率时，用固定 30fps 保持时间码换算稳定。
	constexpr int32 DefaultMediaFrameRate = 30;

	// 媒体播放钩子统一通过 GameplayMessage 对外通知，消息体只暴露句柄上下文。
	void BroadcastMediaMessage(const UObject* WorldContextObject, const FGameplayTag Channel, UGenericMediaHandle* MediaHandle)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnMediaMessage Message;
		Message.MediaHandle = MediaHandle;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(Channel, Message);
	}
}

UGenericMediaHandle::UGenericMediaHandle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	  bIsMediaInitialize(false)
{
}

void UGenericMediaHandle::Register(UMediaPlayer* InMediaPlayer, UMediaSource* InMediaSource, const FMediaPlayerOptions& InOptions)
{
	if (!IsValid(InMediaPlayer) || !IsValid(InMediaSource))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("Media Handle Register Failed: Invalid MediaPlayer or MediaSource"))
		return;
	}

	MediaPlayer = InMediaPlayer;
	MediaSource = InMediaSource;
	Options = InOptions;
	bIsMediaInitialize = false;
	bLoopIndefinitely = false;
	RemainingLoopCount = 0;

	// Register 只记录对象和绑定播放器事件，实际可播放状态要等 OnMediaOpened 回调确认。
	MediaPlayer->OnMediaOpened.AddUniqueDynamic(this, &UGenericMediaHandle::OnMediaOpened);
	MediaPlayer->OnMediaOpenFailed.AddUniqueDynamic(this, &UGenericMediaHandle::OnMediaOpenFailed);
	MediaPlayer->OnMediaClosed.AddUniqueDynamic(this, &UGenericMediaHandle::OnMediaClosed);
	MediaPlayer->OnEndReached.AddUniqueDynamic(this, &UGenericMediaHandle::OnEndReached);
	MediaPlayer->OnSeekCompleted.AddUniqueDynamic(this, &UGenericMediaHandle::OnSeekCompleted);
	MediaPlayer->OnPlaybackSuspended.AddUniqueDynamic(this, &UGenericMediaHandle::OnPlaybackSuspended);
	MediaPlayer->OnPlaybackResumed.AddUniqueDynamic(this, &UGenericMediaHandle::OnPlaybackResumed);

	OpenMovieScene();
}

void UGenericMediaHandle::OpenMovieScene()
{
	if (!IsValid(MediaPlayer) || !IsValid(MediaSource))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("OpenMovieScene Failed: Invalid MediaPlayer or MediaSource"))
		return;
	}

	bIsMediaInitialize = false;
	// 打开媒体源是异步流程，OpenSourceWithOptions 成功只代表请求已发起。
	if (!MediaPlayer->OpenSourceWithOptions(MediaSource, Options))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("OpenMovieScene Failed: Unable to open media source"))
	}
}

void UGenericMediaHandle::CloseMovieScene()
{
	if (!IsValid(MediaPlayer))
	{
		bIsMediaInitialize = false;
		MediaSource = nullptr;
		return;
	}

	Super::CloseMovieScene();
}

void UGenericMediaHandle::OnMovieSceneOpened()
{
	Super::OnMovieSceneOpened();
}

void UGenericMediaHandle::OnMovieSceneClosed()
{
	Super::OnMovieSceneClosed();

	bIsMediaInitialize = false;
	bLoopIndefinitely = false;
	RemainingLoopCount = 0;

	if (IsValid(MediaPlayer))
	{
		// 关闭时先暂停再解绑事件，防止后续 MediaPlayer 回调访问已经释放的句柄状态。
		if (MediaPlayer->IsPlaying())
		{
			MediaPlayer->Pause();
		}

		MediaPlayer->OnMediaOpened.RemoveAll(this);
		MediaPlayer->OnMediaOpenFailed.RemoveAll(this);
		MediaPlayer->OnMediaClosed.RemoveAll(this);
		MediaPlayer->OnEndReached.RemoveAll(this);
		MediaPlayer->OnSeekCompleted.RemoveAll(this);
		MediaPlayer->OnPlaybackSuspended.RemoveAll(this);
		MediaPlayer->OnPlaybackResumed.RemoveAll(this);

		MediaPlayer->Close();
		MediaPlayer = nullptr;
	}

	MediaSource = nullptr;
}

void UGenericMediaHandle::OnMovieScenePlay()
{
	Super::OnMovieScenePlay();
	BroadcastMediaMessage(this, TAG_GameplayMessage_Channel_Media_OnPlay, this);
}

void UGenericMediaHandle::OnMovieScenePlayReverse()
{
	Super::OnMovieScenePlayReverse();
	BroadcastMediaMessage(this, TAG_GameplayMessage_Channel_Media_OnPlayReverse, this);
}

void UGenericMediaHandle::OnMovieScenePause()
{
	Super::OnMovieScenePause();
	BroadcastMediaMessage(this, TAG_GameplayMessage_Channel_Media_OnPause, this);
}

void UGenericMediaHandle::OnMovieSceneStop()
{
	Super::OnMovieSceneStop();
	BroadcastMediaMessage(this, TAG_GameplayMessage_Channel_Media_OnStop, this);
}

void UGenericMediaHandle::OnMovieSceneSeek()
{
	Super::OnMovieSceneSeek();
	BroadcastMediaMessage(this, TAG_GameplayMessage_Channel_Media_OnSeek, this);
}

void UGenericMediaHandle::OnMovieScenePlayFinish()
{
	Super::OnMovieScenePlayFinish();
	BroadcastMediaMessage(this, TAG_GameplayMessage_Channel_Media_OnFinish, this);
}

bool UGenericMediaHandle::PlayMovieScene()
{
	if (!bIsMediaInitialize || !IsValid(MediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayMovieScene Failed: Media Is Not Ready"))
		return false;
	}

	// 普通播放按一次播放处理，结尾由 OnEndReached 触发完成消息。
	bLoopIndefinitely = false;
	RemainingLoopCount = 1;
	MediaPlayer->SetLooping(false);

	if (!MediaPlayer->Play())
	{
		return false;
	}

	Super::PlayMovieScene();
	return true;
}

bool UGenericMediaHandle::PlayMovieSceneFromStart()
{
	if (!bIsMediaInitialize || !IsValid(MediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayMovieSceneFromStart Failed: Media Is Not Ready"))
		return false;
	}

	// 从头播放同样重置为一次播放，避免沿用上一次循环播放留下的计数。
	bLoopIndefinitely = false;
	RemainingLoopCount = 1;
	MediaPlayer->SetLooping(false);
	MediaPlayer->Rewind();

	if (!MediaPlayer->Play())
	{
		return false;
	}

	Super::PlayMovieSceneFromStart();
	return true;
}

bool UGenericMediaHandle::PlayLoopingMovieScene(int32 NumLoops)
{
	if (!bIsMediaInitialize || !IsValid(MediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayLoopingMovieScene Failed: Media Is Not Ready"))
		return false;
	}

	// NumLoops < 0 交给底层播放器无限循环；有限循环由句柄在 OnEndReached 中手动递减。
	bLoopIndefinitely = NumLoops < 0;
	RemainingLoopCount = bLoopIndefinitely ? INDEX_NONE : FMath::Max(NumLoops, 1);
	MediaPlayer->SetLooping(bLoopIndefinitely);
	MediaPlayer->Rewind();

	if (!MediaPlayer->Play())
	{
		return false;
	}

	Super::PlayLoopingMovieScene(NumLoops);
	return true;
}

bool UGenericMediaHandle::PlayReverseMovieScene()
{
	if (!bIsMediaInitialize || !IsValid(MediaPlayer))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayReverseMovieScene Failed: Media Is Not Ready"))
		return false;
	}

	const float CurrentRate = MediaPlayer->GetRate();
	const float ReverseRate = -FMath::Max(FMath::Abs(CurrentRate), 1.f);
	// MediaPlayer 对负速率支持受平台和源类型限制，失败时不改变播放状态。
	if (!MediaPlayer->SupportsRate(ReverseRate, false) && !MediaPlayer->SupportsRate(ReverseRate, true))
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("PlayReverseMovieScene Failed: Reverse Rate Is Not Supported"))
		return false;
	}

	bLoopIndefinitely = false;
	RemainingLoopCount = 1;
	MediaPlayer->SetLooping(false);

	if (!MediaPlayer->SetRate(ReverseRate))
	{
		return false;
	}

	Super::PlayReverseMovieScene();
	return true;
}

bool UGenericMediaHandle::PauseMovieScene()
{
	if (!IsValid(MediaPlayer))
	{
		return false;
	}

	if (!MediaPlayer->Pause())
	{
		return false;
	}

	Super::PauseMovieScene();
	return true;
}

bool UGenericMediaHandle::StopMovieScene()
{
	if (!IsValid(MediaPlayer))
	{
		return false;
	}

	// Stop 语义保持为暂停并回到零点，同时清掉句柄维护的循环状态。
	bLoopIndefinitely = false;
	RemainingLoopCount = 0;
	MediaPlayer->SetLooping(false);
	MediaPlayer->Pause();
	MediaPlayer->Seek(FTimespan::Zero());

	Super::StopMovieScene();
	return true;
}

bool UGenericMediaHandle::SeekMovieScene(FTimecode SeekTime)
{
	if (!bIsMediaInitialize || !IsValid(MediaPlayer))
	{
		return false;
	}

	if (!MediaPlayer->SupportsSeeking())
	{
		GenericLOG(GenericLogMovieScene, Error, TEXT("SeekMovieScene Failed: Media Does Not Support Seeking"))
		return false;
	}

	// Timecode 依赖当前视频轨道帧率换算为媒体时间。
	return MediaPlayer->Seek(SeekTime.ToTimespan(GetFrameRate()));
}

void UGenericMediaHandle::ChangeMovieSceneDirection()
{
	if (!IsValid(MediaPlayer))
	{
		return;
	}

	const float CurrentRate = MediaPlayer->GetRate();
	const float TargetRate = CurrentRate < 0.f ? FMath::Max(FMath::Abs(CurrentRate), 1.f) : -FMath::Max(FMath::Abs(CurrentRate), 1.f);
	if (MediaPlayer->SupportsRate(TargetRate, false) || MediaPlayer->SupportsRate(TargetRate, true))
	{
		MediaPlayer->SetRate(TargetRate);
	}
}

bool UGenericMediaHandle::IsPlaying()
{
	return IsValid(MediaPlayer) && MediaPlayer->IsPlaying();
}

bool UGenericMediaHandle::IsLooping()
{
	return bLoopIndefinitely || RemainingLoopCount > 1 || (IsValid(MediaPlayer) && MediaPlayer->IsLooping());
}

bool UGenericMediaHandle::IsPaused()
{
	return IsValid(MediaPlayer) && MediaPlayer->IsPaused();
}

bool UGenericMediaHandle::IsReversed()
{
	return IsValid(MediaPlayer) && MediaPlayer->GetRate() < 0.f;
}

FTimecode UGenericMediaHandle::GetCurrentTime()
{
	if (!IsValid(MediaPlayer))
	{
		return FTimecode();
	}

	return FTimecode::FromTimespan(MediaPlayer->GetTime(), GetFrameRate(), true);
}

FTimecode UGenericMediaHandle::GetDuration()
{
	if (!IsValid(MediaPlayer))
	{
		return FTimecode();
	}

	return FTimecode::FromTimespan(MediaPlayer->GetDuration(), GetFrameRate(), true);
}

FFrameRate UGenericMediaHandle::GetFrameRate()
{
	if (!IsValid(MediaPlayer))
	{
		return FFrameRate(DefaultMediaFrameRate, 1);
	}

	// 优先使用当前选中视频轨道的实际帧率，避免时间码与媒体源时间轴漂移。
	const int32 TrackIndex = MediaPlayer->GetSelectedTrack(EMediaPlayerTrack::Video);
	if (TrackIndex != INDEX_NONE)
	{
		const int32 FormatIndex = MediaPlayer->GetTrackFormat(EMediaPlayerTrack::Video, TrackIndex);
		if (FormatIndex != INDEX_NONE)
		{
			const float FrameRate = MediaPlayer->GetVideoTrackFrameRate(TrackIndex, FormatIndex);
			if (FrameRate > 0.f)
			{
				return FFrameRate(FMath::Max(FMath::RoundToInt(FrameRate), 1), 1);
			}
		}
	}

	return FFrameRate(DefaultMediaFrameRate, 1);
}

void UGenericMediaHandle::SetFrameRate(FFrameRate FrameRate)
{
	Super::SetFrameRate(FrameRate);
}

float UGenericMediaHandle::GetPlayRate()
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetRate() : 1.f;
}

void UGenericMediaHandle::SetPlayRate(float InPlayRate)
{
	if (IsValid(MediaPlayer))
	{
		MediaPlayer->SetRate(InPlayRate);
	}
}

bool UGenericMediaHandle::HasError() const
{
	return IsValid(MediaPlayer) && MediaPlayer->HasError();
}

bool UGenericMediaHandle::IsBuffering() const
{
	return IsValid(MediaPlayer) && MediaPlayer->IsBuffering();
}

bool UGenericMediaHandle::IsConnecting() const
{
	return IsValid(MediaPlayer) && MediaPlayer->IsConnecting();
}

bool UGenericMediaHandle::IsPreparing() const
{
	return IsValid(MediaPlayer) && MediaPlayer->IsPreparing();
}

bool UGenericMediaHandle::IsClosed() const
{
	return !IsValid(MediaPlayer) || MediaPlayer->IsClosed();
}

bool UGenericMediaHandle::IsReady() const
{
	return IsValid(MediaPlayer) && MediaPlayer->IsReady();
}

bool UGenericMediaHandle::CanPause() const
{
	return IsValid(MediaPlayer) && MediaPlayer->CanPause();
}

bool UGenericMediaHandle::CanPlaySource(UMediaSource* InMediaSource) const
{
	return IsValid(MediaPlayer) && MediaPlayer->CanPlaySource(InMediaSource);
}

bool UGenericMediaHandle::CanPlayUrl(const FString& Url) const
{
	return IsValid(MediaPlayer) && MediaPlayer->CanPlayUrl(Url);
}

FText UGenericMediaHandle::GetMediaName() const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetMediaName() : FText::GetEmpty();
}

FName UGenericMediaHandle::GetPlayerName() const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetPlayerName() : NAME_None;
}

FName UGenericMediaHandle::GetDesiredPlayerName() const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetDesiredPlayerName() : NAME_None;
}

void UGenericMediaHandle::GetSupportedRates(TArray<FFloatRange>& OutRates, bool Unthinned) const
{
	OutRates.Reset();
	if (IsValid(MediaPlayer))
	{
		MediaPlayer->GetSupportedRates(OutRates, Unthinned);
	}
}

const FString& UGenericMediaHandle::GetUrl() const
{
	static const FString EmptyUrl;
	return IsValid(MediaPlayer) ? MediaPlayer->GetUrl() : EmptyUrl;
}

void UGenericMediaHandle::SetBlockOnTime(const FTimespan& Time) const
{
	if (IsValid(MediaPlayer))
	{
		MediaPlayer->SetBlockOnTime(Time);
	}
}

void UGenericMediaHandle::SetBlockOnTimeRange(const TRange<FTimespan>& TimeRange) const
{
	if (IsValid(MediaPlayer))
	{
		MediaPlayer->SetBlockOnTimeRange(TimeRange);
	}
}

bool UGenericMediaHandle::SetLooping(bool Looping) const
{
	return IsValid(MediaPlayer) && MediaPlayer->SetLooping(Looping);
}

bool UGenericMediaHandle::SetNativeVolume(float Volume)
{
	return IsValid(MediaPlayer) && MediaPlayer->SetNativeVolume(Volume);
}

FTimespan UGenericMediaHandle::GetTimeDelay() const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetTimeDelay() : FTimespan::Zero();
}

void UGenericMediaHandle::SetTimeDelay(FTimespan TimeDelay)
{
	if (IsValid(MediaPlayer))
	{
		MediaPlayer->SetTimeDelay(TimeDelay);
	}
}

bool UGenericMediaHandle::SupportsRate(float Rate, bool Unthinned) const
{
	return IsValid(MediaPlayer) && MediaPlayer->SupportsRate(Rate, Unthinned);
}

bool UGenericMediaHandle::SupportsScrubbing() const
{
	return IsValid(MediaPlayer) && MediaPlayer->SupportsScrubbing();
}

bool UGenericMediaHandle::SupportsSeeking() const
{
	return IsValid(MediaPlayer) && MediaPlayer->SupportsSeeking();
}

int32 UGenericMediaHandle::GetNumTracks(EMediaPlayerTrack TrackType) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetNumTracks(TrackType) : 0;
}

int32 UGenericMediaHandle::GetNumTrackFormats(EMediaPlayerTrack TrackType, int32 TrackIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetNumTrackFormats(TrackType, TrackIndex) : 0;
}

int32 UGenericMediaHandle::GetSelectedTrack(EMediaPlayerTrack TrackType) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetSelectedTrack(TrackType) : INDEX_NONE;
}

FText UGenericMediaHandle::GetTrackDisplayName(EMediaPlayerTrack TrackType, int32 TrackIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetTrackDisplayName(TrackType, TrackIndex) : FText::GetEmpty();
}

int32 UGenericMediaHandle::GetTrackFormat(EMediaPlayerTrack TrackType, int32 TrackIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetTrackFormat(TrackType, TrackIndex) : INDEX_NONE;
}

FString UGenericMediaHandle::GetTrackLanguage(EMediaPlayerTrack TrackType, int32 TrackIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetTrackLanguage(TrackType, TrackIndex) : FString();
}

bool UGenericMediaHandle::SelectTrack(EMediaPlayerTrack TrackType, int32 TrackIndex)
{
	return IsValid(MediaPlayer) && MediaPlayer->SelectTrack(TrackType, TrackIndex);
}

bool UGenericMediaHandle::SetTrackFormat(EMediaPlayerTrack TrackType, int32 TrackIndex, int32 FormatIndex)
{
	return IsValid(MediaPlayer) && MediaPlayer->SetTrackFormat(TrackType, TrackIndex, FormatIndex);
}

int32 UGenericMediaHandle::GetAudioTrackChannels(int32 TrackIndex, int32 FormatIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetAudioTrackChannels(TrackIndex, FormatIndex) : 0;
}

FString UGenericMediaHandle::GetAudioTrackType(int32 TrackIndex, int32 FormatIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetAudioTrackType(TrackIndex, FormatIndex) : FString();
}

int32 UGenericMediaHandle::GetAudioTrackSampleRate(int32 TrackIndex, int32 FormatIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetAudioTrackSampleRate(TrackIndex, FormatIndex) : 0;
}

FString UGenericMediaHandle::GetVideoTrackType(int32 TrackIndex, int32 FormatIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetVideoTrackType(TrackIndex, FormatIndex) : FString();
}

float UGenericMediaHandle::GetVideoTrackAspectRatio(int32 TrackIndex, int32 FormatIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetVideoTrackAspectRatio(TrackIndex, FormatIndex) : 0.f;
}

FIntPoint UGenericMediaHandle::GetVideoTrackDimensions(int32 TrackIndex, int32 FormatIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetVideoTrackDimensions(TrackIndex, FormatIndex) : FIntPoint::ZeroValue;
}

float UGenericMediaHandle::GetVideoTrackFrameRate(int32 TrackIndex, int32 FormatIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetVideoTrackFrameRate(TrackIndex, FormatIndex) : 0.f;
}

FFloatRange UGenericMediaHandle::GetVideoTrackFrameRates(int32 TrackIndex, int32 FormatIndex) const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetVideoTrackFrameRates(TrackIndex, FormatIndex) : FFloatRange();
}

bool UGenericMediaHandle::SetVideoTrackFrameRate(int32 TrackIndex, int32 FormatIndex, float FrameRate)
{
	return IsValid(MediaPlayer) && MediaPlayer->SetVideoTrackFrameRate(TrackIndex, FormatIndex, FrameRate);
}

float UGenericMediaHandle::GetHorizontalFieldOfView() const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetHorizontalFieldOfView() : 0.f;
}

float UGenericMediaHandle::GetVerticalFieldOfView() const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetVerticalFieldOfView() : 0.f;
}

FRotator UGenericMediaHandle::GetViewRotation() const
{
	return IsValid(MediaPlayer) ? MediaPlayer->GetViewRotation() : FRotator::ZeroRotator;
}

bool UGenericMediaHandle::SetViewField(float Horizontal, float Vertical, bool Absolute)
{
	return IsValid(MediaPlayer) && MediaPlayer->SetViewField(Horizontal, Vertical, Absolute);
}

bool UGenericMediaHandle::SetViewRotation(const FRotator& Rotation, bool Absolute)
{
	return IsValid(MediaPlayer) && MediaPlayer->SetViewRotation(Rotation, Absolute);
}

UMediaPlayer* UGenericMediaHandle::GetMediaPlayer() const
{
	return MediaPlayer;
}

UMediaSource* UGenericMediaHandle::GetMediaSource() const
{
	return MediaSource;
}

void UGenericMediaHandle::OnMediaOpened(FString OpenedUrl)
{
	// 只有媒体实际打开成功后才触发通用 OpenMovieScene，外部播放入口才会通过初始化校验。
	bIsMediaInitialize = true;
	Super::OpenMovieScene();
}

void UGenericMediaHandle::OnMediaOpenFailed(FString FailedUrl)
{
	bIsMediaInitialize = false;
	GenericLOG(GenericLogMovieScene, Error, TEXT("Media Open Fail : %s"), *FailedUrl)
}

void UGenericMediaHandle::OnMediaClosed()
{
	// 底层关闭等价于停止播放，重置循环状态后向外广播 Stop。
	bIsMediaInitialize = false;
	bLoopIndefinitely = false;
	RemainingLoopCount = 0;
	OnMovieSceneStop();
}

void UGenericMediaHandle::OnEndReached()
{
	if (bLoopIndefinitely)
	{
		return;
	}

	// 有限循环由句柄接管，避免底层 SetLooping(true) 无法表达指定次数。
	if (RemainingLoopCount > 1)
	{
		--RemainingLoopCount;
		MediaPlayer->Rewind();
		MediaPlayer->Play();
		return;
	}

	RemainingLoopCount = 0;
	OnMovieScenePlayFinish();
}

void UGenericMediaHandle::OnSeekCompleted()
{
	// Seek 完成后再广播，保证监听方读取到的是跳转后的时间。
	OnMovieSceneSeek();
}

void UGenericMediaHandle::OnPlaybackSuspended()
{
	OnMovieScenePause();
}

void UGenericMediaHandle::OnPlaybackResumed()
{
	OnMovieScenePlay();
}
