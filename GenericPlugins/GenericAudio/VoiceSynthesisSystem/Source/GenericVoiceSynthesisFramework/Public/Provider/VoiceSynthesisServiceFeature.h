// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Features/IModularFeatures.h"
#include "VoiceSynthesisTypes.h"

class UVoiceSynthesisComponent;

/** 定义语音合成Service特性接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICESYNTHESISFRAMEWORK_API IVoiceSynthesisServiceFeatureInterface : public IModularFeature
{
public:
	/** 获取特性名称。 */
	static FName GetFeatureName()
	{
		static const FName FeatureName(TEXT("VoiceSynthesisService"));
		return FeatureName;
	}

	virtual ~IVoiceSynthesisServiceFeatureInterface() = default;

	/** 获取提供器名称。 */
	virtual FName GetProviderName() const = 0;

	/** 判断在线Service是否成立。 */
	virtual bool IsOnlineService() const = 0;

	/** 向语音合成服务提交Synthesize请求，并通过回调返回音频结果。 */
	virtual bool Synthesize(UVoiceSynthesisComponent& InComponent, const FVoiceSynthesisRequest& InRequest, FString& OutMessage) = 0;

	/** 判断是否可以cel合成。 */
	virtual void CancelSynthesis(UVoiceSynthesisComponent& InComponent) = 0;

	/** 获取可用Features。 */
	static TArray<IVoiceSynthesisServiceFeatureInterface*> GetAvailableFeatures()
	{
		return IModularFeatures::Get().GetModularFeatureImplementations<IVoiceSynthesisServiceFeatureInterface>(GetFeatureName());
	}

	/** 查找特性按名称。 */
	static IVoiceSynthesisServiceFeatureInterface* FindFeatureByName(const FName InProviderName)
	{
		if (InProviderName.IsNone()) { return nullptr; }

		for (IVoiceSynthesisServiceFeatureInterface* Feature : GetAvailableFeatures())
		{
			if (Feature != nullptr && Feature->GetProviderName() == InProviderName) { return Feature; }
		}

		return nullptr;
	}
};
