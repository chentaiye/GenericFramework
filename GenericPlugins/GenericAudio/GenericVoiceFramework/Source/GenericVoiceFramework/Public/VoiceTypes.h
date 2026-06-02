// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceTypes.generated.h"

GENERICVOICEFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogVoiceFramework, Log, All);
GENERICVOICEFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogVoiceWakeup, Log, All);
GENERICVOICEFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogVoiceRecognition, Log, All);
GENERICVOICEFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogVoiceSynthesis, Log, All);
GENERICVOICEFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogVoicePlayback, Log, All);
GENERICVOICEFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogVoiceConversation, Log, All);

/** 定义语音路由策略取值。 */
UENUM(BlueprintType)
enum class EVoiceRoutePolicy : uint8
{
	/** 优先使用在线 Provider，在线不可用时回退离线 Provider。 */
	OnlineFirst,

	/** 优先使用离线 Provider，离线不可用时回退在线 Provider。 */
	OfflineFirst,

	/** 只允许使用在线 Provider，不执行离线回退。 */
	OnlineOnly,

	/** 只允许使用离线 Provider，不执行在线回退。 */
	OfflineOnly,

	/** 预留混合路由策略，用于后续并行或组合式 Provider。 */
	Hybrid
};

/** 定义语音路由来源取值。 */
UENUM(BlueprintType)
enum class EVoiceRouteSource : uint8
{
	/** 未选择任何路由。 */
	None,

	/** 当前使用在线 Provider。 */
	Online,

	/** 当前使用离线 Provider。 */
	Offline
};

/** 定义语音语言取值。 */
UENUM(BlueprintType)
enum class EVoiceLanguage : uint8
{
	/** 自动检测或由 Provider 自行决定语种。 */
	Auto,

	/** 中文。 */
	Chinese,

	/** 英文。 */
	English
};

/** 定义语音组件状态取值。 */
UENUM(BlueprintType)
enum class EVoiceComponentState : uint8
{
	/** 组件尚未初始化。 */
	Uninitialized,

	/** 组件已准备好，可以接收请求。 */
	Ready,

	/** 组件正在启动 Provider 或会话。 */
	Starting,

	/** 组件正在运行。 */
	Running,

	/** 组件正在停止 Provider 或会话。 */
	Stopping,

	/** 组件处于错误状态。 */
	Error
};

/** 封装语音提供器路由Candidate。 */
USTRUCT(BlueprintType)
struct GENERICVOICEFRAMEWORK_API FVoiceProviderRouteCandidate
{
	GENERATED_BODY()

public:
	/** 候选 Provider 的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice")
	EVoiceRouteSource RouteSource = EVoiceRouteSource::None;

	/** 候选 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice")
	FName ProviderName=NAME_None;
};

/** 封装语音路由Decision。 */
USTRUCT(BlueprintType)
struct GENERICVOICEFRAMEWORK_API FVoiceRouteDecision
{
	GENERATED_BODY()

public:
	/** 路由是否成功决策。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice")
	bool bSuccessful=false;

	/** 本次使用的路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice")
	EVoiceRoutePolicy Policy=EVoiceRoutePolicy::OnlineFirst;

	/** 本次最终选择的在线或离线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice")
	EVoiceRouteSource SelectedRoute=EVoiceRouteSource::None;

	/** 本次最终选择的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice")
	FName SelectedProvider=NAME_None;

	/** 路由结果说明或失败原因。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice")
	FString Message;
};
