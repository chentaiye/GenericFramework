// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericMovieSceneHandle.h"
#include "LevelSequenceType.h"
#include "MovieSceneSequencePlayer.h"
#include "GenericLevelSequenceHandle.generated.h"

class ULevelSequence;
class ULevelSequencePlayer;
class ALevelSequenceActor;
class UCameraComponent;

/** 基于 LevelSequenceActor/Player 的电影场景句柄，代理序列播放控制并转发播放器事件。 */
UCLASS(MinimalAPI)
class UGenericLevelSequenceHandle : public UGenericMovieSceneHandle
{
	GENERATED_BODY()

	/* IMovieSceneInterface */
protected:
	/** 打开电影场景后绑定 LevelSequencePlayer 的播放、停止、完成和相机切换事件。 */
	LEVELSEQUENCESYSTEM_API virtual void OnMovieSceneOpened() override;

	/** 关闭电影场景时停止播放、解绑播放器委托、销毁临时 LevelSequenceActor 并清空相机缓存。 */
	LEVELSEQUENCESYSTEM_API virtual void OnMovieSceneClosed() override;

	/** 正向播放钩子，重置旧相机缓存并广播 OnPlay GameplayMessage。 */
	LEVELSEQUENCESYSTEM_API virtual void OnMovieScenePlay() override;

	/** 反向播放钩子，重置旧相机缓存并广播 OnPlayReverse GameplayMessage。 */
	LEVELSEQUENCESYSTEM_API virtual void OnMovieScenePlayReverse() override;

	/** 暂停钩子，缓存当前 CameraCut 相机视图并广播 OnPause GameplayMessage。 */
	LEVELSEQUENCESYSTEM_API virtual void OnMovieScenePause() override;

	/** 停止钩子，只广播停止消息，避免播放结束后被清空的 CameraCut 覆盖最后有效相机视图。 */
	LEVELSEQUENCESYSTEM_API virtual void OnMovieSceneStop() override;

	/** 跳转钩子，缓存跳转后的当前相机视图并广播 OnSeek GameplayMessage。 */
	LEVELSEQUENCESYSTEM_API virtual void OnMovieSceneSeek() override;

	/** 播放完成钩子，广播完成消息并保留播放阶段已经缓存的最后有效相机视图。 */
	LEVELSEQUENCESYSTEM_API virtual void OnMovieScenePlayFinish() override;

public:
	/** 从当前播放位置开始正向播放关卡序列。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool PlayMovieScene() override;

	/** 将播放头跳到序列开头后开始正向播放。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool PlayMovieSceneFromStart() override;

	/** 按指定循环次数播放序列，NumLoops 小于 0 时表示无限循环。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool PlayLoopingMovieScene(int32 NumLoops = -1) override;

	/** 从当前播放位置开始反向播放关卡序列。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool PlayReverseMovieScene() override;

	/** 暂停当前序列播放，保留播放头位置。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool PauseMovieScene() override;

	/** 停止当前序列播放，调用前先尝试缓存最后有效 CameraCut 视图。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool StopMovieScene() override;

	/** 将序列播放头跳转到指定时间码位置。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool SeekMovieScene(FTimecode SeekTime) override;

	/** 切换当前播放方向，正向和反向播放状态互相转换。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual void ChangeMovieSceneDirection() override;

	/** 查询底层 LevelSequencePlayer 是否正在播放。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool IsPlaying() override;

	/** 查询当前播放设置是否处于循环模式。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool IsLooping() override;

	/** 查询底层 LevelSequencePlayer 是否处于暂停状态。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool IsPaused() override;

	/** 查询底层 LevelSequencePlayer 是否正在反向播放。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual bool IsReversed() override;

	/** 返回当前播放头时间，播放器无效时返回默认时间码。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual FTimecode GetCurrentTime() override;

	/** 返回序列总时长，播放器无效时返回默认时间码。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual FTimecode GetDuration() override;

	/** 返回 LevelSequencePlayer 当前使用的帧率。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual FFrameRate GetFrameRate() override;

	/** 设置 LevelSequencePlayer 的帧率，供时间码换算和播放控制使用。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual void SetFrameRate(FFrameRate FrameRate) override;

	/** 返回当前序列播放速率。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual float GetPlayRate() override;

	/** 设置当前序列播放速率，负速率由反向播放接口负责。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API virtual void SetPlayRate(float InPlayRate) override;

	/* ULevelSequenceHandle */
public:
	/** 设置序列播放器的有效播放时间范围，后续播放和跳转都会限制在该区间内。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API void SetTimeRange(float StartTime, float Duration);

	/** 查询当前序列播放器是否禁用相机切换，供外部同步预览或运行时镜头策略。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API bool GetDisableCameraCuts() const;

	/** 设置是否禁用相机切换，并直接写入当前 LevelSequencePlayer 的播放行为。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API void SetDisableCameraCuts(bool bInDisableCameraCuts);

public:
	/** 返回子系统创建的序列 Actor，关闭句柄时该 Actor 会被销毁。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API ALevelSequenceActor* GetLevelSequenceActor() const;

	/** 返回当前序列播放器，所有播放、跳转和设置操作都会通过它执行。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API ULevelSequencePlayer* GetULevelSequencePlayer() const;

	/** 返回播放器聚焦的序列名称，用于 UI 标识当前句柄控制的关卡序列。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API FString GetSequenceName() const;

	/** 返回句柄最近一次捕获到的 LevelSequence 相机视图。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API FLevelSequenceCameraView GetLastCameraView() const;

public:
	/** 从序列 Actor 读取当前 Sequence 资产，未创建 Actor 时返回空指针。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API ULevelSequence* GetSequence() const;

	/** 替换序列 Actor 绑定的 Sequence，必要时停止旧序列并按参数立即播放新序列。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API void SetSequence(ULevelSequence* InSequence, bool bIsPlay = true);

	/** 读取 Actor 上保存的播放设置，循环状态查询会使用其中的 LoopCount。 */
	UFUNCTION(BlueprintPure, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API FMovieSceneSequencePlaybackSettings GetPlaybackSettings() const;

	/** 同步更新 Actor 和 Player 的播放设置，保证后续播放和当前播放器配置一致。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Handle")
	LEVELSEQUENCESYSTEM_API void SetPlaybackSettings(const FMovieSceneSequencePlaybackSettings& InSettings);

private:
	/** LevelSequencePlayer 播放事件回调，转发到通用播放钩子广播给句柄监听者。 */
	UFUNCTION(Category="Generic Level Sequence Handle")
	void OnPlay();

	/** LevelSequencePlayer 反向播放事件回调，转发到通用反向播放钩子。 */
	UFUNCTION(Category="Generic Level Sequence Handle")
	void OnPlayReverse();

	/** LevelSequencePlayer 暂停事件回调，转发到通用暂停钩子。 */
	UFUNCTION(Category="Generic Level Sequence Handle")
	void OnPause();

	/** LevelSequencePlayer 停止事件回调，转发到通用停止钩子。 */
	UFUNCTION(Category="Generic Level Sequence Handle")
	void OnStop();

	/** LevelSequencePlayer 播放完成事件回调，转发到通用完成钩子。 */
	UFUNCTION(Category="Generic Level Sequence Handle")
	void OnFinished();

	/** CameraCut 事件回调，只在传入有效相机时更新最后相机视图缓存。 */
	UFUNCTION(Category="Generic Level Sequence Handle")
	void OnCameraCut(UCameraComponent* InCameraComponent);

private:
	/** 序列评估后更新当前有效 CameraCut 缓存，停止/完成后的清空 CameraCut 不会覆盖缓存。 */
	void OnSequenceUpdated(const UMovieSceneSequencePlayer& InSequencePlayer, FFrameTime InCurrentTime, FFrameTime InPreviousTime);

	/** 从指定相机组件读取完整视图参数并写入 LastCameraView。 */
	bool CacheCameraView(UCameraComponent* InCameraComponent);

	/** 从 LevelSequencePlayer 当前 CameraCut 或快照里读取相机并刷新 LastCameraView。 */
	bool CacheCurrentCameraView();

	/** 获取当前有效 CameraCut 相机，ActiveCamera 为空时回退到播放器快照。 */
	UCameraComponent* GetActiveCameraComponent() const;

	/** 清空最后相机视图缓存，通常在新一轮播放开始或句柄关闭时调用。 */
	void ResetCameraViewCache();

public:
	/** 子系统创建的序列 Actor，承载 Sequence 资产和播放设置，关闭时由句柄销毁。 */
	UPROPERTY()
	TObjectPtr<ALevelSequenceActor> LevelSequenceActor=nullptr;

	/** 子系统创建的序列播放器，句柄通过它执行播放控制并订阅播放状态事件。 */
	UPROPERTY()
	TObjectPtr<ULevelSequencePlayer> LevelSequencePlayer=nullptr;

private:
	/** 最后一次有效 CameraCut 视图缓存，用于播放完成后恢复 Pawn 相机位置。 */
	UPROPERTY(Transient)
	FLevelSequenceCameraView LastCameraView;

	/** OnSequenceUpdated 的绑定句柄，关闭电影场景时用于精确解绑。 */
	FDelegateHandle LevelSequenceUpdatedDelegateHandle;
};
