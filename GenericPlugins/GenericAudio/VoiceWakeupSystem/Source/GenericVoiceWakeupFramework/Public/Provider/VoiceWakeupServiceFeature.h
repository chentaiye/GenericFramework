// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Features/IModularFeatures.h"
#include "VoiceWakeupTypes.h"

class UVoiceWakeupComponent;

/** 定义语音唤醒Service特性接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICEWAKEUPFRAMEWORK_API IVoiceWakeupServiceFeatureInterface : public IModularFeature
{
public:
	/** 获取特性名称。 */
	static FName GetFeatureName()
	{
		static const FName FeatureName(TEXT("VoiceWakeupService"));
		return FeatureName;
	}

	virtual ~IVoiceWakeupServiceFeatureInterface() = default;

	/** 获取提供器名称。 */
	virtual FName GetProviderName() const = 0;

	/** 判断在线Service是否成立。 */
	virtual bool IsOnlineService() const = 0;

	/** 驱动启动Listening对应的语音系统生命周期或播放流程。 */
	virtual bool StartListening(UVoiceWakeupComponent& InComponent, const FVoiceWakeupStartRequest& InRequest, FString& OutMessage) = 0;

	/** 驱动停止Listening对应的语音系统生命周期或播放流程。 */
	virtual void StopListening(UVoiceWakeupComponent& InComponent) = 0;

	/** 获取可用Features。 */
	static TArray<IVoiceWakeupServiceFeatureInterface*> GetAvailableFeatures()
	{
		return IModularFeatures::Get().GetModularFeatureImplementations<IVoiceWakeupServiceFeatureInterface>(GetFeatureName());
	}

	/** 查找特性按名称。 */
	static IVoiceWakeupServiceFeatureInterface* FindFeatureByName(const FName InProviderName)
	{
		if (InProviderName.IsNone()) { return nullptr; }

		for (IVoiceWakeupServiceFeatureInterface* Feature : GetAvailableFeatures())
		{
			if (Feature != nullptr && Feature->GetProviderName() == InProviderName) { return Feature; }
		}

		return nullptr;
	}
};
