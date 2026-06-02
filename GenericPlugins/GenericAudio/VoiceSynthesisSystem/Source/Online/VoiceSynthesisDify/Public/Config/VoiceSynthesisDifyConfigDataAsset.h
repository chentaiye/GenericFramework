// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceSynthesisDifyConfigDataAsset.generated.h"

/** 配置Dify合成配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UDifySynthesisConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Dify合成配置数据资源默认状态。 */
	VOICESYNTHESISDIFY_API UDifySynthesisConfigDataAsset();

	VOICESYNTHESISDIFY_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Dify基础URL。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Dify")
	FString DifyBaseUrl;

	/** 配置Dify API键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Dify")
	FString DifyApiKey;

	/** 配置Dify应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Dify")
	FString DifyApplicationId;
};
