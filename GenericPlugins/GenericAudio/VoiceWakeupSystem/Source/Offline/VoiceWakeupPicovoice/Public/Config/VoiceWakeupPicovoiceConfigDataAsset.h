// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Config/VoiceProviderConfigDataAsset.h"
#include "VoiceWakeupPicovoiceConfigDataAsset.generated.h"

/** 配置Picovoice唤醒配置。 */
UCLASS(MinimalAPI, BlueprintType)
class UPicovoiceWakeupConfigDataAsset : public UVoiceProviderConfigDataAsset
{
	GENERATED_BODY()

public:
	/** 初始化Picovoice唤醒配置数据资源默认状态。 */
	VOICEWAKEUPPICOVOICE_API UPicovoiceWakeupConfigDataAsset();

	VOICEWAKEUPPICOVOICE_API virtual bool ValidateConfig(FString& OutMessage) const override;

	/** 配置Picovoice访问键。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Picovoice")
	FString PicovoiceAccessKey;

	/** 配置Picovoice模型文件。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Picovoice", meta=(RelativeToGameDir))
	FFilePath PicovoiceModelFile;

	/** 配置Picovoice Keyword Files。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Wakeup|Picovoice", meta=(RelativeToGameDir))
	TArray<FFilePath> PicovoiceKeywordFiles;
};
