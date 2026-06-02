// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceTypes.h"
#include "VoiceConversationTypes.generated.h"

/** 定义语音Conversation状态取值。 */
UENUM(BlueprintType)
enum class EVoiceConversationState : uint8
{
	/** 对话组件空闲。 */
	Idle,

	/** 对话会话正在启动。 */
	Starting,

	/** 对话会话已准备好。 */
	Ready,

	/** 已发送用户消息，正在等待回复。 */
	WaitingReply,

	/** 对话会话已停止。 */
	Stopped,

	/** 对话流程发生错误。 */
	Error
};

/** 定义语音Conversation Role取值。 */
UENUM(BlueprintType)
enum class EVoiceConversationRole : uint8
{
	/** 系统提示角色。 */
	System,

	/** 用户输入角色。 */
	User,

	/** 助手回复角色。 */
	Assistant
};

/** 封装语音Conversation消息。 */
USTRUCT(BlueprintType)
struct GENERICVOICECONVERSATIONFRAMEWORK_API FVoiceConversationMessage
{
	GENERATED_BODY()

public:
	/** 对话消息角色。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	EVoiceConversationRole Role = EVoiceConversationRole::User;

	/** 对话消息内容。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FString Content;
};

/** 封装语音Conversation Start请求。 */
USTRUCT(BlueprintType)
struct GENERICVOICECONVERSATIONFRAMEWORK_API FVoiceConversationStartRequest
{
	GENERATED_BODY()

public:
	/** 本次对话会话使用的在线或离线路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	EVoiceRoutePolicy RoutePolicy=EVoiceRoutePolicy::OnlineFirst;

	/** 在线对话 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FName OnlineProvider=NAME_None;

	/** 离线对话 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FName OfflineProvider=NAME_None;

	/** 对话模型 ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FString ModelId;

	/** 对话系统提示词。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FString SystemPrompt;
};

/** 封装语音Conversation回复。 */
USTRUCT(BlueprintType)
struct GENERICVOICECONVERSATIONFRAMEWORK_API FVoiceConversationReply
{
	GENERATED_BODY()

public:
	/** 对话回复是否成功。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	bool bSuccessful=false;

	/** 产生回复的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FName ProviderName=NAME_None;

	/** 产生回复的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** 助手回复文本内容。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FString Content;

	/** 回复结果说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FString Message;
};

/** 语音Conversation提供器事件结构体。 */
USTRUCT(BlueprintType)
struct GENERICVOICECONVERSATIONFRAMEWORK_API FVoiceConversationProviderEvent
{
	GENERATED_BODY()

public:
	/** 触发事件的 Provider 名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FName ProviderName=NAME_None;

	/** 触发事件的在线或离线路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** Provider 事件说明或错误信息。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice Conversation")
	FString Message;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceConversationProviderEventSignature, FVoiceConversationProviderEvent, Event);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceConversationReplySignature, FVoiceConversationReply, Reply);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVoiceConversationStateSignature, EVoiceConversationState, State);
