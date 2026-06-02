// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceWakeupXfyunConfigDataAsset.generated.h"

/** 配置Xfyun唤醒配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UXfyunWakeupConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Xfyun唤醒配置数据资源默认状态。 */
	VOICEWAKEUPXFYUN_API UXfyunWakeupConfigDataAsset();

	VOICEWAKEUPXFYUN_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Xfyun应用ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Xfyun")
	FString XfyunAppId;

	/** 配置Xfyun API键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Xfyun")
	FString XfyunApiKey;

	/** 配置Xfyun API Secret。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Xfyun")
	FString XfyunApiSecret;

	/** 配置Xfyun唤醒资源文件。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Xfyun", meta=(RelativeToGameDir))
	FFilePath XfyunWakeupResourceFile;
};
