// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Audio.generated.h"

/** 集中暴露音频蓝图函数库接口，让蓝图通过稳定入口访问Unreal 通用工具功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_Audio : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 转换WAV文件To声音Wave，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	UFUNCTION(BlueprintCallable, Meta=(DisplayName="Convert .wav file to USoundWave"), Category="AzSpeech|Audio")
	static UNREALMISC_API USoundWave* ConvertWavFileToSoundWave(const FString& FileName, const FString& OutputAssetName, const FString& PackagePath = "");

	/** 转换音频数据To声音Wave，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	UFUNCTION(BlueprintCallable, Category="AzSpeech")
	static UNREALMISC_API USoundWave* ConvertAudioDataToSoundWave(const TArray<uint8>& RawData, const FString& OutputAssetName, const FString& PackagePath = "");
};
