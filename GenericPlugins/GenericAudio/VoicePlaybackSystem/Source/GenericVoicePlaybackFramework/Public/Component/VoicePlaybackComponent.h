// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Component/VoiceComponentBase.h"
#include "VoicePlaybackTypes.h"
#include "VoicePlaybackComponent.generated.h"

class UAudioComponent;
class USoundBase;

/** 承载语音Playback组件能力组件职责，衔接拥有者对象与模块内部实现。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UVoicePlaybackComponent : public UVoiceComponentBase
{
	GENERATED_BODY()

public:
	/** 初始化语音Playback组件的默认运行状态。 */
	GENERICVOICEPLAYBACKFRAMEWORK_API UVoicePlaybackComponent();

	/** 驱动播放Sound对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Playback")
	GENERICVOICEPLAYBACKFRAMEWORK_API bool PlaySound(USoundBase* InSound, float InVolumeMultiplier = 1.0f, float InPitchMultiplier = 1.0f, bool bInLooping = false);

	/** 驱动停止播放对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Playback")
	GENERICVOICEPLAYBACKFRAMEWORK_API void StopPlayback();

	/** 驱动暂停播放对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Playback")
	GENERICVOICEPLAYBACKFRAMEWORK_API void PausePlayback();

	/** 驱动Resume播放对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Playback")
	GENERICVOICEPLAYBACKFRAMEWORK_API void ResumePlayback();

	/** 判断Playing是否成立。 */
	UFUNCTION(BlueprintPure, Category="Voice|Playback")
	GENERICVOICEPLAYBACKFRAMEWORK_API bool IsPlaying() const;

	/** 获取Playback状态。 */
	UFUNCTION(BlueprintPure, Category="Voice|Playback")
	EVoicePlaybackState GetPlaybackState() const { return PlaybackState; }

	UPROPERTY(BlueprintAssignable, Category="Voice|Playback")
	FVoicePlaybackEventSignature OnPlaybackStarted;

	UPROPERTY(BlueprintAssignable, Category="Voice|Playback")
	FVoicePlaybackEventSignature OnPlaybackPaused;

	UPROPERTY(BlueprintAssignable, Category="Voice|Playback")
	FVoicePlaybackEventSignature OnPlaybackResumed;

	UPROPERTY(BlueprintAssignable, Category="Voice|Playback")
	FVoicePlaybackEventSignature OnPlaybackStopped;

	UPROPERTY(BlueprintAssignable, Category="Voice|Playback")
	FVoicePlaybackEventSignature OnPlaybackCompletedEvent;

	UPROPERTY(BlueprintAssignable, Category="Voice|Playback")
	FVoicePlaybackEventSignature OnPlaybackError;

	UPROPERTY(BlueprintAssignable, Category="Voice|Playback")
	FVoicePlaybackStateSignature OnPlaybackStateChanged;

	/** 允许Interrupt。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Playback")
	bool bAllowInterrupt=true;

	/** 记录DefaultVolumeMultiplier。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Playback", meta=(ClampMin="0.0"))
	float DefaultVolumeMultiplier=1.0f;

	/** 记录DefaultPitchMultiplier。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Playback", meta=(ClampMin="0.0"))
	float DefaultPitchMultiplier=1.0f;

protected:
	GENERICVOICEPLAYBACKFRAMEWORK_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	/** 确保音频组件。 */
	void EnsureAudioComponent();

	/** 执行句柄音频Finished流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice")
	GENERICVOICEPLAYBACKFRAMEWORK_API void HandleAudioFinished();

	/** 设置Playback状态。 */
	void SetPlaybackState(EVoicePlaybackState InState);

	/** 转发转发状态目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardStateToOwner(EVoicePlaybackState InState) const;

	/** 转发转发Completed目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardCompletedToOwner() const;

	/** 转发转发Error目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardErrorToOwner(const FString& InErrorMessage) const;

	/** 创建事件。 */
	FVoicePlaybackEvent MakeEvent(const FString& InMessage) const;

private:
	/** 持有Managed音频组件实例，供语音系统运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UAudioComponent> ManagedAudioComponent=nullptr;

	/** 记录播放状态。 */
	UPROPERTY(Transient)
	EVoicePlaybackState PlaybackState=EVoicePlaybackState::Idle;
};
