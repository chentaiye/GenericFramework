// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceConversationDifyConfigDataAsset.generated.h"

/** 配置Dify Conversation配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UDifyConversationConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Dify Conversation配置数据资源默认状态。 */
	VOICECONVERSATIONDIFY_API UDifyConversationConfigDataAsset();

	VOICECONVERSATIONDIFY_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Dify基础URL。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Dify")
	FString DifyBaseUrl;

	/** 配置Dify API键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Dify")
	FString DifyApiKey;

	/** 配置Dify应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Dify")
	FString DifyApplicationId;
};
