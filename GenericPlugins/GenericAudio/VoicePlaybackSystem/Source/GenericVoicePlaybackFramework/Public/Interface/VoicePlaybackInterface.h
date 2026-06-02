// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VoicePlaybackTypes.h"
#include "VoicePlaybackInterface.generated.h"

/** 定义语音Playback接口契约，供模块在不同实现之间解耦调用。 */
UINTERFACE(MinimalAPI, BlueprintType)
class UVoicePlaybackInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义语音Playback接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICEPLAYBACKFRAMEWORK_API IVoicePlaybackInterface
{
	GENERATED_BODY()

public:
	/** 响应播放状态变化回调，并把外部事件转换为当前对象状态或委托通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Playback")
	void OnPlaybackStateChanged(EVoicePlaybackState InState);

	/** 响应Playback完成。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Playback")
	void OnPlaybackCompleted();

	/** 响应Playback错误。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Playback")
	void OnPlaybackError(const FString& InErrorMessage);
};
