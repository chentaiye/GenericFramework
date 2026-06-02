// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceConversationDoubaoConfigDataAsset.generated.h"

/** 配置Doubao Conversation配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UDoubaoConversationConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Doubao Conversation配置数据资源默认状态。 */
	VOICECONVERSATIONDOUBAO_API UDoubaoConversationConfigDataAsset();

	VOICECONVERSATIONDOUBAO_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Doubao应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Doubao")
	FString DoubaoAppId;

	/** 配置Doubao访问令牌。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Doubao")
	FString DoubaoAccessToken;

	/** 配置Doubao Secret键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Doubao")
	FString DoubaoSecretKey;

	/** 配置Doubao集群。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Doubao")
	FString DoubaoCluster;

	/** 配置Doubao模型ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Doubao")
	FString DoubaoModelId;

	/** 配置Doubao资源ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Conversation|Doubao")
	FString DoubaoResourceId;
};
