// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericMovieSceneHandle.h"
#include "MediaPlayer.h"
#include "GenericMediaHandle.generated.h"

class UMediaSource;
class UMediaPlayer;

/** 基于 UMediaPlayer 的电影场景句柄，负责打开媒体源、代理播放控制并把媒体事件转成通用句柄事件。 */
UCLASS(MinimalAPI)
class UGenericMediaHandle : public UGenericMovieSceneHandle
{
	GENERATED_UCLASS_BODY()

public:
	/** 绑定媒体播放器、媒体源和打开参数，重置循环状态后注册底层媒体事件并开始打开来源。 */
	MEDIASYSTEM_API void Register(UMediaPlayer* InMediaPlayer, UMediaSource* InMediaSource, const FMediaPlayerOptions& InOptions);

	/* IMovieSceneInterface */
public:
	/** 使用已注册的 MediaPlayer、MediaSource 和 Options 打开媒体源。 */
	MEDIASYSTEM_API virtual void OpenMovieScene() override;

	/** 触发通用关闭流程，最终解绑媒体播放器委托并释放注册对象。 */
	MEDIASYSTEM_API virtual void CloseMovieScene() override;

protected:
	/** 媒体源打开成功后的通用打开钩子，目前保留父类行为。 */
	MEDIASYSTEM_API virtual void OnMovieSceneOpened() override;

	/** 关闭钩子，重置初始化和循环状态、解绑媒体事件并关闭底层播放器。 */
	MEDIASYSTEM_API virtual void OnMovieSceneClosed() override;

	/** 正向播放钩子，广播 Media OnPlay GameplayMessage。 */
	MEDIASYSTEM_API virtual void OnMovieScenePlay() override;

	/** 反向播放钩子，广播 Media OnPlayReverse GameplayMessage。 */
	MEDIASYSTEM_API virtual void OnMovieScenePlayReverse() override;

	/** 暂停钩子，广播 Media OnPause GameplayMessage。 */
	MEDIASYSTEM_API virtual void OnMovieScenePause() override;

	/** 停止钩子，广播 Media OnStop GameplayMessage。 */
	MEDIASYSTEM_API virtual void OnMovieSceneStop() override;

	/** 跳转钩子，广播 Media OnSeek GameplayMessage。 */
	MEDIASYSTEM_API virtual void OnMovieSceneSeek() override;

	/** 播放完成钩子，广播 Media OnFinish GameplayMessage。 */
	MEDIASYSTEM_API virtual void OnMovieScenePlayFinish() override;

public:
	/** 从当前位置正向播放媒体，并初始化一次播放的循环计数。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool PlayMovieScene() override;

	/** 回到媒体开头后正向播放，并初始化一次播放的循环计数。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool PlayMovieSceneFromStart() override;

	/** 从开头循环播放媒体，NumLoops 小于 0 时走底层播放器无限循环。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool PlayLoopingMovieScene(int32 NumLoops = -1) override;

	/** 以负播放速率反向播放媒体，执行前校验底层播放器是否支持反向速率。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool PlayReverseMovieScene() override;

	/** 暂停媒体播放，播放头保留在当前位置。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool PauseMovieScene() override;

	/** 停止媒体播放并跳回开头，同时清空句柄维护的循环状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool StopMovieScene() override;

	/** 跳转到指定时间码位置，执行前校验媒体源是否支持 Seeking。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool SeekMovieScene(FTimecode SeekTime) override;

	/** 在正向和反向播放速率之间切换，只有目标速率受支持时才写入播放器。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual void ChangeMovieSceneDirection() override;

	/** 查询底层媒体播放器是否正在播放。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool IsPlaying() override;

	/** 查询句柄有限循环、无限循环或底层播放器循环状态。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool IsLooping() override;

	/** 查询底层媒体播放器是否处于暂停状态。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool IsPaused() override;

	/** 查询当前播放速率是否为负，用于判断媒体是否反向播放。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual bool IsReversed() override;

	/** 将底层媒体时间转换为时间码返回。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual FTimecode GetCurrentTime() override;

	/** 将底层媒体总时长转换为时间码返回。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual FTimecode GetDuration() override;

	/** 优先读取当前视频轨道帧率，缺失时使用默认 30fps。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual FFrameRate GetFrameRate() override;

	/** 保留通用接口入口，媒体真实帧率由视频轨道决定。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual void SetFrameRate(FFrameRate FrameRate) override;

	/** 读取底层媒体播放器当前播放速率。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual float GetPlayRate() override;

	/** 设置底层媒体播放器播放速率。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual void SetPlayRate(float InPlayRate) override;

	/* UMediaHandle */
public:
	/** 查询底层播放器是否处于错误状态，蓝图侧可据此阻止后续播放控制。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool HasError() const;

	/** 查询媒体是否正在缓冲，供播放 UI 区分加载中和可播放状态。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool IsBuffering() const;

	/** 查询媒体是否正在建立连接，网络媒体源可用它反馈连接进度。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool IsConnecting() const;

	/** 查询媒体是否处于准备阶段，避免在源尚未准备好时触发播放。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool IsPreparing() const;

	/** 判断播放器是否已经关闭或不存在，反注册后用于确认资源释放结果。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool IsClosed() const;

	/** 判断播放器是否已经可播放，播放入口会依赖初始化完成状态进一步保护调用。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool IsReady() const;

	/** 查询底层媒体是否支持暂停，供上层控制条决定是否显示暂停能力。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool CanPause() const;

	/** 预检指定媒体源是否可由当前播放器播放，避免 Register 前后选择不兼容来源。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool CanPlaySource(UMediaSource* InMediaSource) const;

	/** 预检 URL 是否可由当前播放器播放，供外部在切换媒体地址前做兼容判断。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool CanPlayUrl(const FString& Url) const;

	/** 返回底层播放器解析出的媒体名称，用于 UI 展示当前打开的媒体条目。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API virtual FText GetMediaName() const;

	/** 返回实际承载播放的媒体播放器名称，便于诊断平台播放器选择结果。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FName GetPlayerName() const;

	/** 返回配置期望使用的播放器名称，用来和实际播放器名称对比排查回退行为。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FName GetDesiredPlayerName() const;

	/** 收集当前播放器支持的播放速率范围，供外部设置速率前做能力过滤。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API void GetSupportedRates(TArray<FFloatRange>& OutRates, bool Unthinned) const;

	/** 返回当前打开媒体的 URL；播放器无效时返回稳定空字符串引用，避免悬空引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API const FString& GetUrl() const;

	/** 设置阻塞读取的目标时间点，用于需要同步等待特定媒体时间的场景。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API void SetBlockOnTime(const FTimespan& Time) const;

	/** 设置阻塞读取的时间范围，直接转发给底层播放器以控制媒体样本等待区间。 */
	MEDIASYSTEM_API void SetBlockOnTimeRange(const TRange<FTimespan>& TimeRange) const;

	/** 设置底层播放器循环标记；句柄自己的有限循环计数仍由 PlayLoopingMovieScene 维护。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SetLooping(bool Looping) const;

	/** 设置底层播放器原生音量，返回值反映播放器是否接受该音量设置。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SetNativeVolume(float Volume);

	/** 读取播放器的时间延迟，用于同步媒体时间和 Sequencer 或外部时钟。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FTimespan GetTimeDelay() const;

	/** 设置播放器的时间延迟，让外部可以补偿媒体与时间轴之间的偏移。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API void SetTimeDelay(FTimespan TimeDelay);

	/** 判断目标播放速率是否受支持，反向播放和变速播放会据此决定是否继续。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SupportsRate(float Rate, bool Unthinned) const;

	/** 判断播放器是否支持拖动预览，供时间轴 UI 决定是否开放 scrub 操作。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SupportsScrubbing() const;

	/** 判断播放器是否支持精确跳转，SeekMovieScene 会在执行前使用同类能力保护。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SupportsSeeking() const;

public:
	/** 返回指定媒体轨道类型的轨道数量，用于枚举音频、视频或字幕轨道。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API int32 GetNumTracks(EMediaPlayerTrack TrackType) const;

	/** 返回指定轨道可用格式数量，供外部在切换格式前构建有效索引。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API int32 GetNumTrackFormats(EMediaPlayerTrack TrackType, int32 TrackIndex) const;

	/** 返回指定类型当前选中的轨道索引，无播放器时返回 INDEX_NONE。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API int32 GetSelectedTrack(EMediaPlayerTrack TrackType) const;

	/** 返回轨道的显示名称，便于蓝图 UI 展示用户可选择的媒体轨道。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FText GetTrackDisplayName(EMediaPlayerTrack TrackType, int32 TrackIndex) const;

	/** 返回轨道当前格式索引，用于和可用格式列表一起恢复播放器配置。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API int32 GetTrackFormat(EMediaPlayerTrack TrackType, int32 TrackIndex) const;

	/** 返回轨道语言标识，供多语言音频或字幕选择界面使用。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FString GetTrackLanguage(EMediaPlayerTrack TrackType, int32 TrackIndex) const;

	/** 切换指定类型的活动轨道，成功后播放器会使用新的音频、视频或字幕来源。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SelectTrack(EMediaPlayerTrack TrackType, int32 TrackIndex);

	/** 切换指定轨道的格式索引，用于在同一媒体轨道内选择码率或分辨率。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SetTrackFormat(EMediaPlayerTrack TrackType, int32 TrackIndex, int32 FormatIndex);

	/** 读取音频格式的声道数，供声音配置界面展示或校验输出能力。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API int32 GetAudioTrackChannels(int32 TrackIndex, int32 FormatIndex) const;

	/** 读取音频格式编码类型，便于调试当前媒体源的音频流。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FString GetAudioTrackType(int32 TrackIndex, int32 FormatIndex) const;

	/** 读取音频采样率，供外部判断音频轨道质量或同步配置。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API int32 GetAudioTrackSampleRate(int32 TrackIndex, int32 FormatIndex) const;

	/** 读取视频格式编码类型，便于调试当前媒体源的视频流。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FString GetVideoTrackType(int32 TrackIndex, int32 FormatIndex) const;

	/** 读取视频宽高比，供显示容器按媒体内容调整布局。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API float GetVideoTrackAspectRatio(int32 TrackIndex, int32 FormatIndex) const;

	/** 读取视频尺寸，供外部创建或调整承载媒体的显示资源。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FIntPoint GetVideoTrackDimensions(int32 TrackIndex, int32 FormatIndex) const;

	/** 读取当前视频格式帧率，GetFrameRate 会优先使用这个值换算时间码。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API float GetVideoTrackFrameRate(int32 TrackIndex, int32 FormatIndex) const;

	/** 读取视频格式支持的帧率范围，供变更帧率前筛选合法值。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FFloatRange GetVideoTrackFrameRates(int32 TrackIndex, int32 FormatIndex) const;

	/** 为指定视频轨道格式请求新的帧率，成功后影响媒体时间码换算和播放表现。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SetVideoTrackFrameRate(int32 TrackIndex, int32 FormatIndex, float FrameRate);

public:
	/** 读取全景或可旋转媒体的水平视场角，用于外部同步媒体视口参数。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API float GetHorizontalFieldOfView() const;

	/** 读取全景或可旋转媒体的垂直视场角，用于外部同步媒体视口参数。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API float GetVerticalFieldOfView() const;

	/** 读取媒体视图旋转，供交互式媒体视口恢复当前观察方向。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API FRotator GetViewRotation() const;

	/** 写入媒体视场角，Absolute 决定是覆盖还是相对调整底层播放器视图。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SetViewField(float Horizontal, float Vertical, bool Absolute);

	/** 写入媒体视图旋转，Absolute 决定是覆盖还是相对调整当前观察方向。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Handle")
	MEDIASYSTEM_API bool SetViewRotation(const FRotator& Rotation, bool Absolute);

public:
	/** 返回当前注册的媒体播放器，子系统反注册或 CloseMovieScene 后会被清空。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API UMediaPlayer* GetMediaPlayer() const;

	/** 返回当前注册的媒体源，句柄关闭后会置空以避免继续访问已释放播放上下文。 */
	UFUNCTION(BlueprintPure, Category="Generic Media Handle")
	MEDIASYSTEM_API UMediaSource* GetMediaSource() const;

private:
	/** 媒体源打开成功时标记初始化完成，并触发通用打开事件。 */
	UFUNCTION(Category="Generic Media Handle")
	void OnMediaOpened(FString OpenedUrl);

	/** 媒体源打开失败时清除初始化状态并输出失败 URL，阻止后续播放入口通过校验。 */
	UFUNCTION(Category="Generic Media Handle")
	void OnMediaOpenFailed(FString FailedUrl);

	/** 底层播放器关闭时重置循环状态，并通过停止钩子同步上层状态。 */
	UFUNCTION(Category="Generic Media Handle")
	void OnMediaClosed();

	/** 播放到结尾时维护有限循环计数，循环耗尽后触发播放完成事件。 */
	UFUNCTION(Category="Generic Media Handle")
	void OnEndReached();

	/** 底层跳转完成时转发通用跳转事件，保持蓝图监听和播放器状态一致。 */
	UFUNCTION(Category="Generic Media Handle")
	void OnSeekCompleted();

	/** 媒体播放被挂起时转发暂停事件，供上层 UI 进入暂停状态。 */
	UFUNCTION(Category="Generic Media Handle")
	void OnPlaybackSuspended();

	/** 媒体播放恢复时转发播放事件，恢复上层播放状态。 */
	UFUNCTION(Category="Generic Media Handle")
	void OnPlaybackResumed();

public:
	/** 注册到句柄的底层播放器，所有媒体控制和状态查询都会通过它执行。 */
	UPROPERTY(Transient)
	TObjectPtr<UMediaPlayer> MediaPlayer=nullptr;

	/** 注册到句柄的媒体源，OpenMovieScene 使用它和 Options 打开实际媒体内容。 */
	UPROPERTY(Transient)
	TObjectPtr<UMediaSource> MediaSource=nullptr;

private:
	/** 标记媒体源是否已经成功打开，播放和跳转入口用它拒绝未准备好的调用。 */
	uint8 bIsMediaInitialize : 1;

	/** 控制无限循环模式，OnEndReached 在该模式下不消耗剩余次数。 */
	bool bLoopIndefinitely = false;

	/** 决定有限循环还能重播多少次，播放到结尾时递减并在归零后广播完成。 */
	int32 RemainingLoopCount = 0;

	/** 缓存打开媒体源时传入的选项，OpenMovieScene 重新打开来源时保持同一配置。 */
	FMediaPlayerOptions Options;
};
