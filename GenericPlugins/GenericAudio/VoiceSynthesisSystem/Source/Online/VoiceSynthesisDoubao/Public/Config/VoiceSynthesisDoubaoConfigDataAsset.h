// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceSynthesisDoubaoConfigDataAsset.generated.h"

/** 配置Doubao合成配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UDoubaoSynthesisConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Doubao合成配置数据资源默认状态。 */
	VOICESYNTHESISDOUBAO_API UDoubaoSynthesisConfigDataAsset();

	VOICESYNTHESISDOUBAO_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Doubao应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Doubao")
	FString DoubaoAppId;

	/** 配置Doubao访问令牌。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Doubao")
	FString DoubaoAccessToken;

	/** 配置Doubao Secret键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Doubao")
	FString DoubaoSecretKey;

	/** 配置Doubao集群。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Doubao")
	FString DoubaoCluster;

	/** 配置Doubao模型ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Doubao")
	FString DoubaoModelId;

	/** 配置Doubao资源ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Doubao")
	FString DoubaoResourceId;
};
