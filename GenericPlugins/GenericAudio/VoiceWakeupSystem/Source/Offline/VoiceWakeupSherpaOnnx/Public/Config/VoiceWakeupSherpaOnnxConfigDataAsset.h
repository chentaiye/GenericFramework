// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceWakeupSherpaOnnxConfigDataAsset.generated.h"

/** 配置Sherpa Onnx唤醒配置。 */
UCLASS(MinimalAPI, BlueprintType)
class USherpaOnnxWakeupConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Sherpa Onnx唤醒配置数据资源默认状态。 */
	VOICEWAKEUPSHERPAONNX_API USherpaOnnxWakeupConfigDataAsset();

	VOICEWAKEUPSHERPAONNX_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Sherpa Onnx模型Root。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|SherpaOnnx", meta=(RelativeToGameDir))
	FDirectoryPath SherpaOnnxModelRoot;
};
