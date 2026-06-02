// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceWakeupDoubaoConfigDataAsset.generated.h"

/** 配置Doubao唤醒配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UDoubaoWakeupConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Doubao唤醒配置数据资源默认状态。 */
	VOICEWAKEUPDOUBAO_API UDoubaoWakeupConfigDataAsset();

	VOICEWAKEUPDOUBAO_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Doubao应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Doubao")
	FString DoubaoAppId;

	/** 配置Doubao访问令牌。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Doubao")
	FString DoubaoAccessToken;

	/** 配置Doubao Secret键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Doubao")
	FString DoubaoSecretKey;

	/** 配置Doubao集群。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Doubao")
	FString DoubaoCluster;

	/** 配置Doubao资源ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Doubao")
	FString DoubaoResourceId;
};
