// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceSynthesisSherpaOnnxConfigDataAsset.generated.h"

/** 配置Sherpa Onnx合成配置。 */
UCLASS(MinimalAPI, BlueprintType)
class USherpaOnnxSynthesisConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Sherpa Onnx合成配置数据资源默认状态。 */
	VOICESYNTHESISSHERPAONNX_API USherpaOnnxSynthesisConfigDataAsset();

	VOICESYNTHESISSHERPAONNX_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Sherpa Onnx模型Root。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Synthesis|SherpaOnnx", meta=(RelativeToGameDir))
	FDirectoryPath SherpaOnnxModelRoot;
};
