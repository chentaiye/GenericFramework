// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Config/VoiceProviderConfigDataAsset.h"
#include "Component/VoiceComponentBase.h"
#include "VoiceConversationTypes.h"
#include "VoiceConversationComponent.generated.h"

class IVoiceConversationServiceFeatureInterface;

/** 作为语音Conversation组件能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UVoiceConversationComponent : public UVoiceComponentBase
{
	GENERATED_BODY()

public:
	/** 初始化语音Conversation组件默认状态。 */
	GENERICVOICECONVERSATIONFRAMEWORK_API UVoiceConversationComponent();

	/** 驱动启动对话会话对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Conversation")
	GENERICVOICECONVERSATIONFRAMEWORK_API bool StartConversationSession();

	/** 驱动停止对话会话对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Conversation")
	GENERICVOICECONVERSATIONFRAMEWORK_API void StopConversationSession();

	/** 执行发送User文本，并同步当前模块的状态缓存与回调。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Conversation")
	GENERICVOICECONVERSATIONFRAMEWORK_API bool SendUserText(const FString& InText);

	/** 模拟Assistant回复。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Conversation")
	GENERICVOICECONVERSATIONFRAMEWORK_API void SimulateAssistantReply(const FString& InReplyText, const FString& InMessage = TEXT("Manual assistant reply."));

	/** 判断会话激活是否成立。 */
	UFUNCTION(BlueprintPure, Category="Voice|Conversation")
	bool IsSessionActive() const { return bSessionActive; }

	/** 获取Conversation状态。 */
	UFUNCTION(BlueprintPure, Category="Voice|Conversation")
	EVoiceConversationState GetConversationState() const { return ConversationState; }

	/** 获取Conversation History。 */
	UFUNCTION(BlueprintPure, Category="Voice|Conversation")
	TArray<FVoiceConversationMessage> GetConversationHistory() const { return ConversationHistory; }

	/** 获取提供器Configs。 */
	const TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>>& GetProviderConfigs() const { return ProviderConfigs; }

	/** 通知提供器会话开始。 */
	GENERICVOICECONVERSATIONFRAMEWORK_API void NotifyProviderSessionStarted(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage);

	/** 通知提供器会话Stopped。 */
	GENERICVOICECONVERSATIONFRAMEWORK_API void NotifyProviderSessionStopped(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage);

	/** 通知提供器回复。 */
	GENERICVOICECONVERSATIONFRAMEWORK_API void NotifyProviderReply(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InContent, const FString& InMessage);

	/** 通知提供器错误。 */
	GENERICVOICECONVERSATIONFRAMEWORK_API void NotifyProviderError(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InErrorMessage);

	UPROPERTY(BlueprintAssignable, Category="Voice|Conversation")
	FVoiceConversationProviderEventSignature OnConversationStarted;

	UPROPERTY(BlueprintAssignable, Category="Voice|Conversation")
	FVoiceConversationProviderEventSignature OnConversationStopped;

	UPROPERTY(BlueprintAssignable, Category="Voice|Conversation")
	FVoiceConversationReplySignature OnConversationReplyEvent;

	UPROPERTY(BlueprintAssignable, Category="Voice|Conversation")
	FVoiceConversationProviderEventSignature OnConversationError;

	UPROPERTY(BlueprintAssignable, Category="Voice|Conversation")
	FVoiceConversationStateSignature OnConversationStateChanged;

	/** 记录路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Conversation")
	EVoiceRoutePolicy RoutePolicy=EVoiceRoutePolicy::OnlineFirst;

	/** 在在线 Provider 名称时广播给蓝图或上层监听者。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Conversation")
	FName OnlineProvider=TEXT("Dify");

	/** 离线提供器。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Conversation")
	FName OfflineProvider=TEXT("LocalConversation");

	/** 记录ModelId。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Conversation")
	FString ModelId;

	/** 记录SystemPrompt。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Conversation", meta=(MultiLine="true"))
	FString SystemPrompt;

	/** 启用在线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Conversation")
	bool bEnableOnlineRoute=true;

	/** 启用离线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Conversation")
	bool bEnableOfflineRoute=true;

	/** 提供器Configs列表。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Conversation|Provider")
	TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>> ProviderConfigs;

protected:
	GENERICVOICECONVERSATIONFRAMEWORK_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
/** 构建启动请求，供语音服务请求发送复用。 */
	FVoiceConversationStartRequest BuildStartRequest() const;

	/** 尝试尝试启动带特性，失败时通过返回值或输出参数交还调用方处理。 */
	bool TryStartWithFeature(IVoiceConversationServiceFeatureInterface& InFeature, EVoiceRouteSource InRouteSource, const FVoiceConversationStartRequest& InRequest, FString& OutMessage);

	/** 设置Conversation状态。 */
	void SetConversationState(EVoiceConversationState InState);

	/** 转发转发状态目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardStateToOwner(EVoiceConversationState InState) const;

	/** 转发转发Reply目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardReplyToOwner(const FVoiceConversationReply& InReply) const;

	/** 转发转发Error目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardErrorToOwner(const FString& InMessage) const;

	/** 创建提供器事件。 */
	FVoiceConversationProviderEvent MakeProviderEvent(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage) const;

private:
	/** 标记会话激活。 */
	UPROPERTY(Transient)
	bool bSessionActive=false;

	/** 记录对话状态。 */
	UPROPERTY(Transient)
	EVoiceConversationState ConversationState=EVoiceConversationState::Idle;

	/** 保存对话History列表，供语音系统批量处理。 */
	UPROPERTY(Transient)
	TArray<FVoiceConversationMessage> ConversationHistory;
};
