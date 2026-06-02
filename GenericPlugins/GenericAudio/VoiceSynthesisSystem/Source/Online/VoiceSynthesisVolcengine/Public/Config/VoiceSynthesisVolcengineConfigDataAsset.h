// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceSynthesisVolcengineConfigDataAsset.generated.h"

/** 配置火山引擎合成配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UVolcengineSynthesisConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化火山引擎合成配置数据资源默认状态。 */
	VOICESYNTHESISVOLCENGINE_API UVolcengineSynthesisConfigDataAsset();

	VOICESYNTHESISVOLCENGINE_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置火山引擎应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Volcengine")
	FString VolcengineAppId;

	/** 配置火山引擎访问令牌。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Volcengine")
	FString VolcengineAccessToken;

	/** 配置火山引擎Secret键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Volcengine")
	FString VolcengineSecretKey;

	/** 配置火山引擎集群。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Volcengine")
	FString VolcengineCluster;

	/** 配置火山引擎资源ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Volcengine")
	FString VolcengineResourceId;
};
