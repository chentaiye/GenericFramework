// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraView/CameraViewSyncPolicy.h"
#include "GameplayMessageSubsystem.h"
#include "LevelSequenceType.h"
#include "LevelSequenceCameraViewSyncPolicy.generated.h"

class APlayerController;
class ALevelSequenceActor;
class UCameraComponent;
class UGenericLevelSequenceHandle;
class ULevelSequencePlayer;
class UMovieSceneSequencePlayer;
class USpringArmComponent;
class USyncCameraViewComponent;

/** 监听 LevelSequence 播放消息并在播放结束后把拥有者相机同步到最后有效序列相机视图。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class ULevelSequenceCameraViewSyncPolicy : public UCameraViewSyncPolicy
{
	GENERATED_BODY()

public:
	/** 初始化策略并注册 LevelSequence GameplayMessage 监听。 */
	LEVELSEQUENCESYSTEM_API virtual void InitializeCameraViewSyncPolicy(USyncCameraViewComponent* InOwnerComponent) override;

	/** 反初始化策略，解绑消息和播放器委托并清空运行时缓存。 */
	LEVELSEQUENCESYSTEM_API virtual void DeinitializeCameraViewSyncPolicy() override;

	/** 每帧缓存正在播放的序列相机视图，并处理场景内直接放置 LevelSequenceActor 的回切同步。 */
	LEVELSEQUENCESYSTEM_API virtual void TickCameraViewSyncPolicy(float DeltaSeconds) override;

protected:
	/** 收到正向播放消息时开始跟踪该句柄和播放器。 */
	LEVELSEQUENCESYSTEM_API virtual void HandleLevelSequencePlayMessage(FGameplayTag InChannel, const FOnLevelSequenceMessage& InMessage);

	/** 收到反向播放消息时开始跟踪该句柄和播放器。 */
	LEVELSEQUENCESYSTEM_API virtual void HandleLevelSequencePlayReverseMessage(FGameplayTag InChannel, const FOnLevelSequenceMessage& InMessage);

	/** 暂停时刷新当前有效相机视图，避免后续恢复相机时使用旧帧。 */
	LEVELSEQUENCESYSTEM_API virtual void HandleLevelSequencePauseMessage(FGameplayTag InChannel, const FOnLevelSequenceMessage& InMessage);

	/** 停止时使用消息或缓存的最后视图同步拥有者相机，然后清理跟踪状态。 */
	LEVELSEQUENCESYSTEM_API virtual void HandleLevelSequenceStopMessage(FGameplayTag InChannel, const FOnLevelSequenceMessage& InMessage);

	/** 跳转完成时刷新当前有效相机视图。 */
	LEVELSEQUENCESYSTEM_API virtual void HandleLevelSequenceSeekMessage(FGameplayTag InChannel, const FOnLevelSequenceMessage& InMessage);

	/** 自然播放完成时使用最后有效视图同步拥有者相机，然后清理跟踪状态。 */
	LEVELSEQUENCESYSTEM_API virtual void HandleLevelSequenceFinishMessage(FGameplayTag InChannel, const FOnLevelSequenceMessage& InMessage);

protected:
	/** 执行最终相机同步，派生类可重写以改变同步行为。 */
	LEVELSEQUENCESYSTEM_API virtual void SyncLevelSequenceCameraView(APlayerController* InPlayerController, const FLevelSequenceCameraView& InCameraView);

private:
	/** 将拥有者 Actor、SpringArm 和 CameraComponent 对齐到指定相机视图。 */
	void AlignCameraToCameraView(APlayerController* InPlayerController, const FLevelSequenceCameraView& InCameraView, bool bInSetViewTarget) const;

	/** 把 FMinimalViewInfo 中的投影、后处理和第一人称参数应用到目标相机组件。 */
	void ApplyCameraViewParameters(const FMinimalViewInfo& InSourceCameraView, UCameraComponent* InTargetCameraComponent) const;

	/** 缓存当前被 GameplayMessage 跟踪的 LevelSequencePlayer 相机视图。 */
	bool CacheActiveLevelSequenceCameraView();

	/** 扫描世界内直接放置并播放的 LevelSequenceActor，兼容未通过句柄播放的序列。 */
	bool CacheObservedLevelSequenceCameraView(APlayerController* InPlayerController);

	/** 从相机组件读取完整视图参数，过滤拥有者自身相机避免自同步。 */
	bool CacheCameraView(UCameraComponent* InCameraComponent, FLevelSequenceCameraView& OutCameraView) const;

	/** 获取当前有效相机，当前 CameraCut 为空时允许回退到已经缓存的最后有效组件。 */
	UCameraComponent* GetActiveLevelSequenceCameraComponent(ULevelSequencePlayer* InLevelSequencePlayer) const;

	/** 只读取播放器当前有效 CameraCut 或快照，不使用历史缓存。 */
	UCameraComponent* GetCurrentLevelSequenceCameraComponent(ULevelSequencePlayer* InLevelSequencePlayer) const;

	/** 按 PlayerCameraManager、消息缓存、策略缓存的优先级确定最终同步视图。 */
	FLevelSequenceCameraView GetFinalLevelSequenceCameraView(APlayerController* InPlayerController, const FLevelSequenceCameraView& InMessageCameraView, ULevelSequencePlayer* InLevelSequencePlayer) const;

	/** 从拥有者 Pawn 上读取本地 PlayerController。 */
	APlayerController* GetOwnerPlayerController() const;

	/** 返回拥有者身上的目标相机组件。 */
	UCameraComponent* GetTargetCameraComponent() const;

	/** 返回拥有者身上的目标 SpringArm 组件。 */
	USpringArmComponent* GetTargetSpringArmComponent() const;

	/** 判断传入相机是否属于拥有者自身，避免把 Pawn 相机当成序列相机。 */
	bool IsOwnerCameraComponent(const UCameraComponent* InCameraComponent) const;

	/** 校验消息中的句柄和播放器是否仍是当前跟踪对象。 */
	bool IsTrackedLevelSequence(UGenericLevelSequenceHandle* InLevelSequenceHandle, ULevelSequencePlayer* InLevelSequencePlayer) const;

	/** LevelSequence 评估后缓存当前有效 CameraCut，结束后清空 CameraCut 不会覆盖缓存。 */
	void HandleLevelSequencePlayerUpdated(const UMovieSceneSequencePlayer& InSequencePlayer, FFrameTime InCurrentTime, FFrameTime InPreviousTime);

	/** 直接观察到的场景序列停止时尝试执行相机同步。 */
	UFUNCTION()
	void HandleObservedLevelSequencePlayerStop();

	/** 直接观察到的场景序列完成时尝试执行相机同步。 */
	UFUNCTION()
	void HandleObservedLevelSequencePlayerFinish();

	/** 绑定播放器评估更新委托，用于逐帧捕获最后有效相机视图。 */
	void RegisterLevelSequencePlayerUpdate(ULevelSequencePlayer* InLevelSequencePlayer);

	/** 注册所有 LevelSequence GameplayMessage 通道监听。 */
	void RegisterLevelSequenceListeners(AActor* InOwnerActor);

	/** 绑定直接放置 LevelSequenceActor 的 Stop/Finish 事件并开始缓存其相机视图。 */
	void RegisterObservedLevelSequencePlayer(ULevelSequencePlayer* InLevelSequencePlayer);

	/** 清理跟踪句柄、播放器委托和最后相机视图缓存。 */
	void ResetLevelSequenceSyncState();

	/** 判断给定相机视图是否适合同步到拥有者相机。 */
	bool ShouldSyncLevelSequenceCameraView(APlayerController* InPlayerController, const FLevelSequenceCameraView& InCameraView) const;

	/** 判断直接观察的序列是否已经切回拥有者，只有切回后才执行同步。 */
	bool ShouldSyncObservedLevelSequenceCameraView(APlayerController* InPlayerController) const;

	/** 设置当前 GameplayMessage 驱动的跟踪对象并立即缓存一次相机视图。 */
	void TrackLevelSequence(UGenericLevelSequenceHandle* InLevelSequenceHandle, ULevelSequencePlayer* InLevelSequencePlayer);

	/** 从当前播放器相机或 PlayerCameraManager 中尝试捕获一个可用视图。 */
	bool TryCacheLevelSequencePlayerCameraView(APlayerController* InPlayerController, ULevelSequencePlayer* InLevelSequencePlayer, FLevelSequenceCameraView& OutCameraView) const;

	/** 从 GameplayMessage 中解析本地控制器、句柄和播放器。 */
	bool TryGetLevelSequenceMessageContext(const FOnLevelSequenceMessage& InMessage, APlayerController*& OutPlayerController, UGenericLevelSequenceHandle*& OutLevelSequenceHandle, ULevelSequencePlayer*& OutLevelSequencePlayer) const;

	/** 当 PlayerCameraManager 仍指向序列相机时读取真实渲染视图。 */
	bool TryGetPlayerCameraManagerView(APlayerController* InPlayerController, UCameraComponent* InSourceCameraComponent, FLevelSequenceCameraView& OutCameraView) const;

	/** 对直接观察到的场景序列尝试执行一次播放结束后的相机同步。 */
	void TrySyncObservedLevelSequenceCameraView(APlayerController* InPlayerController);

	/** 解绑当前 LevelSequencePlayer 的评估更新委托。 */
	void UnregisterLevelSequencePlayerUpdate();

	/** 解绑所有 GameplayMessage 通道监听。 */
	void UnregisterLevelSequenceListeners();

	/** 解绑直接观察播放器的 Stop/Finish 事件。 */
	void UnregisterObservedLevelSequencePlayer();

private:
	/** 正向播放消息监听句柄。 */
	FGameplayMessageListenerHandle LevelSequencePlayListenerHandle;

	/** 反向播放消息监听句柄。 */
	FGameplayMessageListenerHandle LevelSequencePlayReverseListenerHandle;

	/** 暂停消息监听句柄。 */
	FGameplayMessageListenerHandle LevelSequencePauseListenerHandle;

	/** 停止消息监听句柄。 */
	FGameplayMessageListenerHandle LevelSequenceStopListenerHandle;

	/** 跳转消息监听句柄。 */
	FGameplayMessageListenerHandle LevelSequenceSeekListenerHandle;

	/** 播放完成消息监听句柄。 */
	FGameplayMessageListenerHandle LevelSequenceFinishListenerHandle;

	/** GameplayMessage 驱动的当前关卡序列句柄。 */
	TWeakObjectPtr<UGenericLevelSequenceHandle> ActiveLevelSequenceHandle;

	/** GameplayMessage 驱动的当前关卡序列播放器。 */
	TWeakObjectPtr<ULevelSequencePlayer> ActiveLevelSequencePlayer;

	/** 从场景中直接扫描并观察到的关卡序列播放器。 */
	TWeakObjectPtr<ULevelSequencePlayer> ObservedLevelSequencePlayer;

	/** 当前绑定 OnSequenceUpdated 的播放器。 */
	TWeakObjectPtr<ULevelSequencePlayer> LevelSequenceUpdatedPlayer;

	/** 最后一次有效的序列相机视图，用于播放完成后恢复玩法相机。 */
	FLevelSequenceCameraView CachedLevelSequenceCameraView;

	/** OnSequenceUpdated 绑定句柄，用于切换播放器或反初始化时精确解绑。 */
	FDelegateHandle LevelSequenceUpdatedDelegateHandle;
};
