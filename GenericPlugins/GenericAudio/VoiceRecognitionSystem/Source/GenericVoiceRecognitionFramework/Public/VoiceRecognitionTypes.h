// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceTypes.h"
#include "VoiceRecognitionTypes.generated.h"

/** 定义语音Recognition状态取值。 */
UENUM(BlueprintType)
enum class EVoiceRecognitionState : uint8
{
	/** 语音识别组件空闲。 */
	Idle,

	/** 语音识别组件正在初始化 Provider。 */
	Initializing,

	/** 语音识别组件正在监听或等待音频输入。 */
	Listening,

	/** 表示语音识别状态中的Recognizing分支。 */
	Recognizing,

	/** 语音识别已完成最终结果。 */
	Completed,

	/** 语音识别已停止。 */
	Stopped,

	/** 语音识别流程发生错误。 */
	Error
};

/** 封装语音Recognition Start请求。 */
USTRUCT(BlueprintType)
struct GENERICVOICERECOGNITIONFRAMEWORK_API FVoiceRecognitionStartRequest
{
	GENERATED_BODY()

public:
	/** 本次语音识别启动使用的在线或离线路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	EVoiceRoutePolicy RoutePolicy = EVoiceRoutePolicy::OnlineFirst;

	/** 在线语音识别 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	FName OnlineProvider=NAME_None;

	/** 离线语音识别 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	FName OfflineProvider=NAME_None;

	/** 语音识别语言。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	EVoiceLanguage Language=EVoiceLanguage::Chinese;

	/** 输入音频采样率。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	int32 SampleRate=16000;

	/** 是否启用端点检测或语音活动检测。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	bool bEnableVad=true;

	/** 是否启用自动标点。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	bool bEnablePunctuation=true;
};

/** 封装语音Recognition结果。 */
USTRUCT(BlueprintType)
struct GENERICVOICERECOGNITIONFRAMEWORK_API FVoiceRecognitionResult
{
	GENERATED_BODY()

public:
	/** 语音识别结果是否成功。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	bool bSuccessful=false;

	/** 是否为最终识别结果。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	bool bIsFinal=false;

	/** 产生结果的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	FName ProviderName=NAME_None;

	/** 产生结果的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** 识别出的文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	FString Text;

	/** 识别置信度。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	float Confidence=0.0f;

	/** 结果说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	FString Message;
};

/** 语音Recognition提供器事件结构体。 */
USTRUCT(BlueprintType)
struct GENERICVOICERECOGNITIONFRAMEWORK_API FVoiceRecognitionProviderEvent
{
	GENERATED_BODY()

public:
	/** 触发事件的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	FName ProviderName=NAME_None;

	/** 触发事件的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** Provider 事件说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Recognition")
	FString Message;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceRecognitionProviderEventSignature, FVoiceRecognitionProviderEvent, Event);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceRecognitionResultSignature, FVoiceRecognitionResult, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceRecognitionStateSignature, EVoiceRecognitionState, State);
