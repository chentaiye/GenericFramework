// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceConversationTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "VoiceConversationAsyncAction.generated.h"

class UVoiceConversationComponent;

/** 封装语音Conversation异步动作能力蓝图异步节点，负责启动请求并广播完成结果。 */
UCLASS(MinimalAPI)
class UVoiceConversationAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 执行发送文本，并同步当前模块的状态缓存与回调。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Conversation", meta=(BlueprintInternalUseOnly="true"))
	static GENERICVOICECONVERSATIONFRAMEWORK_API UVoiceConversationAsyncAction* SendText(UVoiceConversationComponent* InConversationComponent, const FString& InText, bool bInStartSessionIfNeeded = true);

	GENERICVOICECONVERSATIONFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceConversationProviderEventSignature OnStarted;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceConversationReplySignature OnReply;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceConversationProviderEventSignature OnError;

private:
	/** 执行句柄Started流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICECONVERSATIONFRAMEWORK_API void HandleStarted(FVoiceConversationProviderEvent InEvent);

	/** 执行句柄Reply流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICECONVERSATIONFRAMEWORK_API void HandleReply(FVoiceConversationReply InReply);

	/** 执行句柄Error流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICECONVERSATIONFRAMEWORK_API void HandleError(FVoiceConversationProviderEvent InEvent);

	/** 尝试尝试发送文本，失败时通过返回值或输出参数交还调用方处理。 */
	void TrySendText();

	/** 解绑，保持对象生命周期内的委托连接一致。 */
	void Unbind();

	/** 创建错误事件。 */
	static FVoiceConversationProviderEvent MakeErrorEvent(const FString& InMessage);

private:
	/** 持有对话组件实例，供语音系统运行时复用。 */
	UPROPERTY()
	TObjectPtr<UVoiceConversationComponent> ConversationComponent=nullptr;

	/** 记录文本。 */
	FString Text;

	/** 标记启动会话IfNeeded状态。 */
	bool bStartSessionIfNeeded = true;

	/** 标记Bound状态。 */
	bool bBound = false;

	/** 标记消息Sent。 */
	bool bMessageSent = false;
};
