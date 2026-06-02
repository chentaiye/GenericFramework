// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Features/IModularFeatures.h"
#include "VoiceRecognitionTypes.h"

class UVoiceRecognitionComponent;

/** 定义语音RecognitionService特性接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICERECOGNITIONFRAMEWORK_API IVoiceRecognitionServiceFeatureInterface : public IModularFeature
{
public:
	/** 获取特性名称。 */
	static FName GetFeatureName()
	{
		static const FName FeatureName(TEXT("VoiceRecognitionService"));
		return FeatureName;
	}

	virtual ~IVoiceRecognitionServiceFeatureInterface() = default;

	/** 获取提供器名称。 */
	virtual FName GetProviderName() const = 0;

	/** 判断在线Service是否成立。 */
	virtual bool IsOnlineService() const = 0;

	/** 驱动启动识别对应的语音系统生命周期或播放流程。 */
	virtual bool StartRecognition(UVoiceRecognitionComponent& InComponent, const FVoiceRecognitionStartRequest& InRequest, FString& OutMessage) = 0;

	/** 驱动停止识别对应的语音系统生命周期或播放流程。 */
	virtual void StopRecognition(UVoiceRecognitionComponent& InComponent) = 0;

	/** 执行Submit音频流程，并把结果同步给语音系统相关状态。 */
	virtual bool SubmitAudio(UVoiceRecognitionComponent& InComponent, const TArray<uint8>& InAudioPcm16Bytes, int32 InSampleRate, int32 InNumChannels, FString& OutMessage) = 0;

	/** 执行Submit音频File流程，并把结果同步给语音系统相关状态。 */
	virtual bool SubmitAudioFile(UVoiceRecognitionComponent& InComponent, const FString& InAudioFilePath, FString& OutMessage) = 0;

	/** 获取可用Features。 */
	static TArray<IVoiceRecognitionServiceFeatureInterface*> GetAvailableFeatures()
	{
		return IModularFeatures::Get().GetModularFeatureImplementations<IVoiceRecognitionServiceFeatureInterface>(GetFeatureName());
	}

	/** 查找特性按名称。 */
	static IVoiceRecognitionServiceFeatureInterface* FindFeatureByName(const FName InProviderName)
	{
		if (InProviderName.IsNone()) { return nullptr; }

		for (IVoiceRecognitionServiceFeatureInterface* Feature : GetAvailableFeatures())
		{
			if (Feature != nullptr && Feature->GetProviderName() == InProviderName) { return Feature; }
		}

		return nullptr;
	}
};
