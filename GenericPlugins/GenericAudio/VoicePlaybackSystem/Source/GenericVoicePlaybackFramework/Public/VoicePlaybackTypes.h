// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoicePlaybackTypes.generated.h"

/** 定义语音Playback状态取值。 */
UENUM(BlueprintType)
enum class EVoicePlaybackState : uint8
{
	/** 播放组件空闲。 */
	Idle,

	/** 播放组件正在准备音频资源。 */
	Preparing,

	/** 播放组件正在播放。 */
	Playing,

	/** 播放已暂停。 */
	Paused,

	/** 播放已停止。 */
	Stopped,

	/** 播放已自然完成。 */
	Completed,

	/** 播放流程发生错误。 */
	Error
};

/** 封装语音Playback事件。 */
USTRUCT(BlueprintType)
struct GENERICVOICEPLAYBACKFRAMEWORK_API FVoicePlaybackEvent
{
	GENERATED_BODY()

public:
	/** 播放事件说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Playback")
	FString Message;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoicePlaybackEventSignature, FVoicePlaybackEvent, Event);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoicePlaybackStateSignature, EVoicePlaybackState, State);
