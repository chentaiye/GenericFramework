// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceSynthesisWenxinConfigDataAsset.generated.h"

/** 配置Wenxin合成配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UWenxinSynthesisConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Wenxin合成配置数据资源默认状态。 */
	VOICESYNTHESISWENXIN_API UWenxinSynthesisConfigDataAsset();

	VOICESYNTHESISWENXIN_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Wenxin应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Wenxin")
	FString WenxinAppId;

	/** 配置Wenxin API键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Wenxin")
	FString WenxinApiKey;

	/** 配置Wenxin Secret键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Wenxin")
	FString WenxinSecretKey;

	/** 配置Wenxin访问令牌。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Wenxin")
	FString WenxinAccessToken;

	/** 配置Wenxin模型ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|Wenxin")
	FString WenxinModelId;
};
