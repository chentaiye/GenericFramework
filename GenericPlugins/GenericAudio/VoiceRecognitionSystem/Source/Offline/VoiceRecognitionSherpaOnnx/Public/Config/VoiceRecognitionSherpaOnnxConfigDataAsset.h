// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceRecognitionSherpaOnnxConfigDataAsset.generated.h"

/** 配置Sherpa Onnx Recognition配置。 */
UCLASS(MinimalAPI, BlueprintType)
class USherpaOnnxRecognitionConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Sherpa Onnx Recognition配置数据资源默认状态。 */
	VOICERECOGNITIONSHERPAONNX_API USherpaOnnxRecognitionConfigDataAsset();

	VOICERECOGNITIONSHERPAONNX_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Sherpa Onnx模型Root。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Recognition|SherpaOnnx", meta=(RelativeToGameDir))
	FDirectoryPath SherpaOnnxModelRoot;
};
