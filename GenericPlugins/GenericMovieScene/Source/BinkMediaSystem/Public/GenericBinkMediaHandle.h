// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericMovieSceneHandle.h"
#include "BinkMediaPlayer.h"
#include "BinkMediaTexture.h"
#include "GenericBinkMediaHandle.generated.h"

/** 基于 UBinkMediaPlayer 的电影场景句柄，负责打开 Bink URL、同步纹理并转发播放状态事件。 */
UCLASS(MinimalAPI)
class UGenericBinkMediaHandle : public UGenericMovieSceneHandle
{
	GENERATED_UCLASS_BODY()

public:
	/** 绑定 Bink 播放器和可选纹理，重置循环状态后注册底层事件并开始打开媒体。 */
	BINKMEDIASYSTEM_API void Register(UBinkMediaPlayer* InBinkMediaPlayer, UBinkMediaTexture* InBinkMediaTexture = nullptr);

	/* IMovieSceneInterface */
public:
	BINKMEDIASYSTEM_API virtual void OpenMovieScene() override;
	BINKMEDIASYSTEM_API virtual void CloseMovieScene() override;

protected:
	BINKMEDIASYSTEM_API virtual void OnMovieSceneOpened() override;
	BINKMEDIASYSTEM_API virtual void OnMovieSceneClosed() override;

public:
	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool PlayMovieScene() override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool PlayMovieSceneFromStart() override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool PlayLoopingMovieScene(int32 NumLoops = -1) override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool PlayReverseMovieScene() override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool PauseMovieScene() override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool StopMovieScene() override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool SeekMovieScene(FTimecode SeekTime) override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual void ChangeMovieSceneDirection() override;

	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool IsPlaying() override;

	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool IsLooping() override;

	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool IsPaused() override;

	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual bool IsReversed() override;

	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual FTimecode GetCurrentTime() override;

	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual FTimecode GetDuration() override;

	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual FFrameRate GetFrameRate() override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual void SetFrameRate(FFrameRate FrameRate) override;

	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual float GetPlayRate() override;

	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API virtual void SetPlayRate(float InPlayRate) override;

	/* UBinkMediaHandle */
public:
	/** 判断 Bink 播放器是否已经初始化完成，播放入口用该状态拒绝未就绪调用。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API bool IsReady() const;

	/** 判断 Bink 播放器是否不存在或已停止，关闭流程后用于确认资源释放结果。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API bool IsClosed() const;

	/** 查询底层 Bink 播放器是否支持暂停，供上层控制条决定是否暴露暂停操作。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API bool CanPause() const;

	/** 根据当前 URL 生成媒体名称，供 UI 展示正在播放的 Bink 资源。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API FText GetMediaName() const;

	/** 返回 Bink 播放器当前 URL；播放器无效时返回稳定空字符串引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API const FString& GetUrl() const;

	/** 设置底层播放器循环标记；有限循环次数仍由句柄的 RemainingLoopCount 维护。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API bool SetLooping(bool Looping) const;

	/** 设置 Bink 播放器音量，播放器无效时保持空操作以兼容关闭后的蓝图调用。 */
	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API void SetVolume(float Volume);

	/** 校验目标速率是否受 Bink 播放器支持，SetPlayRate 会据此输出能力差异。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API bool SupportsRate(float Rate, bool Unthinned) const;

	/** 判断 Bink 播放器是否支持拖动预览，供时间轴 UI 决定是否开放 scrub 操作。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API bool SupportsScrubbing() const;

	/** 判断 Bink 播放器是否支持跳转，SeekMovieScene 会在执行前使用同类能力保护。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API bool SupportsSeeking() const;

	/** 读取当前 Bink 视频尺寸，供外部创建或调整显示纹理承载区域。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API FIntPoint GetDimensions() const;

public:
	/** 返回当前注册的 Bink 播放器，CloseMovieScene 后会被清空。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API UBinkMediaPlayer* GetBinkMediaPlayer() const;

	/** 返回当前绑定的 Bink 纹理，句柄关闭时会先解除其播放器引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Bink Media Handle")
	BINKMEDIASYSTEM_API UBinkMediaTexture* GetBinkMediaTexture() const;

private:
	/** Bink URL 打开成功时标记初始化完成，重新绑定纹理并触发通用打开事件。 */
	UFUNCTION(Category="Generic Bink Media Handle")
	void OnMediaOpened(FString OpenedUrl);

	/** 底层 Bink 播放器关闭时重置循环状态，并通过停止钩子同步上层状态。 */
	UFUNCTION(Category="Generic Bink Media Handle")
	void OnMediaClosed();

	/** 播放到结尾时维护有限循环计数，循环耗尽后触发播放完成事件。 */
	UFUNCTION(Category="Generic Bink Media Handle")
	void OnMediaReachedEnd();

	/** Bink 播放被挂起时转发暂停事件，供上层 UI 进入暂停状态。 */
	UFUNCTION(Category="Generic Bink Media Handle")
	void OnPlaybackSuspended();

	/** 在显式 URL 与播放器当前 URL 之间选择打开地址，避免 OpenMovieScene 使用空路径。 */
	BINKMEDIASYSTEM_API FString ResolveOpenUrl() const;

public:
	/** 注册到句柄的 Bink 播放器，所有播放控制和状态查询都会通过它执行。 */
	UPROPERTY(Transient)
	TObjectPtr<UBinkMediaPlayer> BinkMediaPlayer=nullptr;

	/** 可选的 Bink 输出纹理，Register 和打开成功后都会把播放器同步到该纹理。 */
	UPROPERTY(Transient)
	TObjectPtr<UBinkMediaTexture> BinkMediaTexture=nullptr;

private:
	/** 标记 Bink URL 是否已经成功打开，播放和跳转入口用它拒绝未准备好的调用。 */
	uint8 bIsMediaInitialize : 1;

	/** 控制无限循环模式，OnMediaReachedEnd 在该模式下不消耗剩余次数。 */
	bool bLoopIndefinitely = false;

	/** 决定有限循环还能重播多少次，播放到结尾时递减并在归零后广播完成。 */
	int32 RemainingLoopCount = 0;
};
