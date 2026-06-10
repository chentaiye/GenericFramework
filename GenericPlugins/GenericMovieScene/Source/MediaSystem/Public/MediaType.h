// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "MediaType.generated.h"

class UGenericMediaHandle;

/** Media 模块的 GameplayMessage 根通道，用于按父 Tag 过滤所有媒体播放事件。 */
MEDIASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Media);

/** 媒体开始正向播放时广播，消息体携带触发播放的媒体句柄。 */
MEDIASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Media_OnPlay);

/** 媒体开始反向播放时广播，依赖底层播放器支持负速率。 */
MEDIASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Media_OnPlayReverse);

/** 媒体暂停或播放被挂起时广播，供 UI 和外部流程进入暂停状态。 */
MEDIASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Media_OnPause);

/** 媒体停止或关闭时广播，表示当前播放状态已经退出。 */
MEDIASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Media_OnStop);

/** 媒体跳转完成时广播，供时间轴或 UI 同步当前媒体时间。 */
MEDIASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Media_OnSeek);

/** 媒体播放到结尾且循环次数耗尽时广播。 */
MEDIASYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_Media_OnFinish);

/** 媒体播放状态消息，统一通过 GameplayMessage 广播给 UI 和流程监听方。 */
USTRUCT(BlueprintType)
struct MEDIASYSTEM_API FOnMediaMessage
{
	GENERATED_BODY()

public:
	/** 触发事件的媒体句柄，监听方可通过它继续查询播放器、媒体源和播放状态。 */
	UPROPERTY(BlueprintReadOnly, Category="Media Message")
	TObjectPtr<UGenericMediaHandle> MediaHandle = nullptr;
};
