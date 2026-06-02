// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceConversationWenxinConfigDataAsset.generated.h"

/** 配置Wenxin Conversation配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UWenxinConversationConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Wenxin Conversation配置数据资源默认状态。 */
	VOICECONVERSATIONWENXIN_API UWenxinConversationConfigDataAsset();

	VOICECONVERSATIONWENXIN_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Wenxin应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Wenxin")
	FString WenxinAppId;

	/** 配置Wenxin API键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Wenxin")
	FString WenxinApiKey;

	/** 配置Wenxin Secret键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Wenxin")
	FString WenxinSecretKey;

	/** 配置Wenxin访问令牌。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Wenxin")
	FString WenxinAccessToken;

	/** 配置Wenxin模型ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Wenxin")
	FString WenxinModelId;
};
