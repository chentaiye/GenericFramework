// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoicePlaybackTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "VoicePlaybackAsyncAction.generated.h"

class UVoicePlaybackComponent;
class USoundBase;

/** 封装语音Playback异步动作能力蓝图异步节点，负责启动请求并广播完成结果。 */
UCLASS(MinimalAPI)
class UVoicePlaybackAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 驱动播放Sound对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Playback", meta=(BlueprintInternalUseOnly="true"))
	static GENERICVOICEPLAYBACKFRAMEWORK_API UVoicePlaybackAsyncAction* PlaySound(UVoicePlaybackComponent* InPlaybackComponent, USoundBase* InSound, float InVolumeMultiplier = 1.0f, float InPitchMultiplier = 1.0f, bool bInLooping = false);

	GENERICVOICEPLAYBACKFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoicePlaybackEventSignature OnStarted;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoicePlaybackEventSignature OnCompleted;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoicePlaybackEventSignature OnError;

private:
	/** 执行句柄Started流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICEPLAYBACKFRAMEWORK_API void HandleStarted(FVoicePlaybackEvent InEvent);

	/** 执行句柄Completed流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICEPLAYBACKFRAMEWORK_API void HandleCompleted(FVoicePlaybackEvent InEvent);

	/** 执行句柄Error流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICEPLAYBACKFRAMEWORK_API void HandleError(FVoicePlaybackEvent InEvent);

	/** 解绑，保持对象生命周期内的委托连接一致。 */
	void Unbind();

	/** 创建错误事件。 */
	static FVoicePlaybackEvent MakeErrorEvent(const FString& InMessage);

private:
	/** 持有播放组件实例，供语音系统运行时复用。 */
	UPROPERTY()
	TObjectPtr<UVoicePlaybackComponent> PlaybackComponent=nullptr;

	/** 缓存声音。 */
	UPROPERTY()
	TObjectPtr<USoundBase> Sound=nullptr;

	/** 记录VolumeMultiplier。 */
	float VolumeMultiplier = 1.0f;

	/** 记录PitchMultiplier。 */
	float PitchMultiplier = 1.0f;

	/** 标记Looping状态。 */
	bool bLooping = false;

	/** 标记Bound状态。 */
	bool bBound = false;
};
