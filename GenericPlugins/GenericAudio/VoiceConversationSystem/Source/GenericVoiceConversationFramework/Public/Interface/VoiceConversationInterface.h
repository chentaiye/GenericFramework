// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VoiceConversationTypes.h"
#include "VoiceConversationInterface.generated.h"

/** 定义语音Conversation接口契约，供模块在不同实现之间解耦调用。 */
UINTERFACE(MinimalAPI, BlueprintType)
class UVoiceConversationInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义语音Conversation接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICECONVERSATIONFRAMEWORK_API IVoiceConversationInterface
{
	GENERATED_BODY()

public:
	/** 响应对话状态变化回调，并把外部事件转换为当前对象状态或委托通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Conversation")
	void OnConversationStateChanged(EVoiceConversationState InState);

	/** 响应Conversation回复。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Conversation")
	void OnConversationReply(const FVoiceConversationReply& InReply);

	/** 响应Conversation错误。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Conversation")
	void OnConversationError(const FString& InErrorMessage);
};
