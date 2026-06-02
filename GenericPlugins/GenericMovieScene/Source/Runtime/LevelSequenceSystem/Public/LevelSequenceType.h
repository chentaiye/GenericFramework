// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraTypes.h"
#include "NativeGameplayTags.h"
#include "LevelSequenceType.generated.h"

class UCameraComponent;
class UGenericLevelSequenceHandle;

/** LevelSequence 模块的 GameplayMessage 根通道，用于按父 Tag 过滤所有序列播放事件。 */
LEVELSEQUENCESYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelSequence);

/** 序列开始正向播放时广播，消息体携带触发播放的句柄和最近一次相机视图。 */
LEVELSEQUENCESYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelSequence_OnPlay);

/** 序列开始反向播放时广播，供外部按反向播放流程同步状态。 */
LEVELSEQUENCESYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelSequence_OnPlayReverse);

/** 序列暂停时广播，句柄会在广播前尽量缓存当前相机视图。 */
LEVELSEQUENCESYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelSequence_OnPause);

/** 序列停止时广播，主要用于中断播放或手动停止后的状态同步。 */
LEVELSEQUENCESYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelSequence_OnStop);

/** 序列完成跳转后广播，供 UI 或运行时逻辑同步播放头位置。 */
LEVELSEQUENCESYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelSequence_OnSeek);

/** 序列自然播放完成时广播，依赖方可在此恢复玩法相机或清理播放状态。 */
LEVELSEQUENCESYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelSequence_OnFinish);

/** 保存 LevelSequence 播放期间最后一次有效的相机组件和完整视图参数。 */
USTRUCT(BlueprintType)
struct LEVELSEQUENCESYSTEM_API FLevelSequenceCameraView
{
	GENERATED_BODY()

public:
	/** 当前 CameraCut 对应的相机组件；结束阶段可能失效，使用前需校验。 */
	UPROPERTY(BlueprintReadOnly, Category="Level Sequence Camera View")
	TObjectPtr<UCameraComponent> CameraComponent = nullptr;

	/** 从相机组件或 PlayerCameraManager 捕获的完整相机视图，用于播放结束后还原玩法相机。 */
	UPROPERTY(BlueprintReadOnly, Category="Level Sequence Camera View")
	FMinimalViewInfo CameraView;

	/** 标记 CameraView 是否来自一次有效捕获，避免默认视图被误当作最后一帧。 */
	UPROPERTY(BlueprintReadOnly, Category="Level Sequence Camera View")
	bool bHasCameraView = false;
};

/** LevelSequence 播放状态消息，统一通过 GameplayMessage 广播给相机同步和其他监听方。 */
USTRUCT(BlueprintType)
struct LEVELSEQUENCESYSTEM_API FOnLevelSequenceMessage
{
	GENERATED_BODY()

public:
	/** 触发事件的关卡序列句柄，监听方可据此读取播放器和序列上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Level Sequence Message")
	TObjectPtr<UGenericLevelSequenceHandle> LevelSequenceHandle = nullptr;

	/** 广播时句柄缓存的最后相机视图，播放结束后仍可用于对齐 Pawn 相机。 */
	UPROPERTY(BlueprintReadOnly, Category="Level Sequence Message")
	FLevelSequenceCameraView CameraView;
};
