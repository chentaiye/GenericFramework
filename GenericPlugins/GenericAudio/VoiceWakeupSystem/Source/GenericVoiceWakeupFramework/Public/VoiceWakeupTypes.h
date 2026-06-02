// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceTypes.h"
#include "VoiceWakeupTypes.generated.h"

/** 定义语音唤醒状态取值。 */
UENUM(BlueprintType)
enum class EVoiceWakeupState : uint8
{
	/** 唤醒组件空闲。 */
	Idle,

	/** 唤醒组件正在初始化 Provider。 */
	Initializing,

	/** 唤醒组件正在监听唤醒词。 */
	Listening,

	/** 唤醒词触发后的冷却状态。 */
	Cooldown,

	/** 唤醒监听已停止。 */
	Stopped,

	/** 唤醒流程发生错误。 */
	Error
};

/** 封装语音唤醒Start请求。 */
USTRUCT(BlueprintType)
struct GENERICVOICEWAKEUPFRAMEWORK_API FVoiceWakeupStartRequest
{
	GENERATED_BODY()

public:
	/** 本次唤醒启动使用的在线或离线路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	EVoiceRoutePolicy RoutePolicy = EVoiceRoutePolicy::OnlineFirst;

	/** 在线唤醒 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	FName OnlineProvider=NAME_None;

	/** 离线唤醒 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	FName OfflineProvider=NAME_None;

	/** 唤醒词识别语言。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	EVoiceLanguage Language=EVoiceLanguage::Chinese;

	/** 唤醒词列表。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	TArray<FString> Keywords;

	/** 唤醒灵敏度，范围通常为 0 到 1。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	float Sensitivity=0.5f;

	/** 唤醒成功后的冷却时间，单位秒。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	float CooldownSeconds=1.0f;
};

/** 封装语音唤醒结果。 */
USTRUCT(BlueprintType)
struct GENERICVOICEWAKEUPFRAMEWORK_API FVoiceWakeupResult
{
	GENERATED_BODY()

public:
	/** 唤醒结果是否成功。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	bool bSuccessful=false;

	/** 产生唤醒结果的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	FName ProviderName=NAME_None;

	/** 产生唤醒结果的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** 命中的唤醒词。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	FString Keyword;

	/** 唤醒置信度。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	float Confidence=0.0f;

	/** 唤醒结果说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	FString Message;
};

/** 封装语音唤醒提供器事件。 */
USTRUCT(BlueprintType)
struct GENERICVOICEWAKEUPFRAMEWORK_API FVoiceWakeupProviderEvent
{
	GENERATED_BODY()

public:
	/** 触发事件的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	FName ProviderName=NAME_None;

	/** 触发事件的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** Provider 事件说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Wakeup")
	FString Message;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceWakeupProviderEventSignature, FVoiceWakeupProviderEvent, Event);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceWakeupResultSignature, FVoiceWakeupResult, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceWakeupStateSignature, EVoiceWakeupState, State);
