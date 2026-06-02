// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceTypes.h"
#include "VoiceSynthesisTypes.generated.h"

/** 定义语音合成状态取值。 */
UENUM(BlueprintType)
enum class EVoiceSynthesisState : uint8
{
	/** 语音合成组件空闲。 */
	Idle,

	/** 语音合成组件正在初始化 Provider。 */
	Initializing,

	/** 语音合成组件正在合成音频。 */
	Synthesizing,

	/** 语音合成已完成。 */
	Completed,

	/** 语音合成已停止或取消。 */
	Stopped,

	/** 语音合成流程发生错误。 */
	Error
};

/** 封装语音合成请求。 */
USTRUCT(BlueprintType)
struct GENERICVOICESYNTHESISFRAMEWORK_API FVoiceSynthesisRequest
{
	GENERATED_BODY()

public:
	/** 本次语音合成使用的在线或离线路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	EVoiceRoutePolicy RoutePolicy = EVoiceRoutePolicy::OnlineFirst;

	/** 在线语音合成 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FName OnlineProvider=NAME_None;

	/** 离线语音合成 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FName OfflineProvider=NAME_None;

	/** 语音合成语言。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	EVoiceLanguage Language=EVoiceLanguage::Chinese;

	/** 待合成文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FString Text;

	/** 音色或发音人 ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FString VoiceId;

	/** 语速倍率。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	float SpeechRate=1.0f;

	/** 音高倍率。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	float Pitch=1.0f;

	/** 音量倍率。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	float Volume=1.0f;

	/** 合成音频输出文件路径。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FString OutputFilePath;
};

/** 封装语音合成结果。 */
USTRUCT(BlueprintType)
struct GENERICVOICESYNTHESISFRAMEWORK_API FVoiceSynthesisResult
{
	GENERATED_BODY()

public:
	/** 语音合成结果是否成功。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	bool bSuccessful=false;

	/** 产生结果的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FName ProviderName=NAME_None;

	/** 产生结果的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** 已合成的原始文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FString Text;

	/** 合成后的音频文件路径。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FString AudioFilePath;

	/** 合成结果说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FString Message;
};

/** 封装语音合成提供器事件。 */
USTRUCT(BlueprintType)
struct GENERICVOICESYNTHESISFRAMEWORK_API FVoiceSynthesisProviderEvent
{
	GENERATED_BODY()

public:
	/** 触发事件的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FName ProviderName=NAME_None;

	/** 触发事件的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** Provider 事件说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Synthesis")
	FString Message;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceSynthesisProviderEventSignature, FVoiceSynthesisProviderEvent, Event);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceSynthesisResultSignature, FVoiceSynthesisResult, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceSynthesisStateSignature, EVoiceSynthesisState, State);
