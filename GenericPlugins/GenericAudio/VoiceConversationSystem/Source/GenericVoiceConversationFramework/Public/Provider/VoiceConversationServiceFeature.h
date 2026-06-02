// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Features/IModularFeatures.h"
#include "VoiceConversationTypes.h"

class UVoiceConversationComponent;

/** 定义语音ConversationService特性接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICECONVERSATIONFRAMEWORK_API IVoiceConversationServiceFeatureInterface : public IModularFeature
{
public:
	/** 获取特性名称。 */
	static FName GetFeatureName()
	{
		static const FName FeatureName(TEXT("VoiceConversationService"));
		return FeatureName;
	}

	virtual ~IVoiceConversationServiceFeatureInterface() = default;

	/** 获取提供器名称。 */
	virtual FName GetProviderName() const = 0;

	/** 判断在线Service是否成立。 */
	virtual bool IsOnlineService() const = 0;

	/** 驱动启动会话对应的语音系统生命周期或播放流程。 */
	virtual bool StartSession(UVoiceConversationComponent& InComponent, const FVoiceConversationStartRequest& InRequest, FString& OutMessage) = 0;

	/** 驱动停止会话对应的语音系统生命周期或播放流程。 */
	virtual void StopSession(UVoiceConversationComponent& InComponent) = 0;

	/** 执行发送User消息，并同步当前模块的状态缓存与回调。 */
	virtual bool SendUserMessage(UVoiceConversationComponent& InComponent, const FString& InMessage, FString& OutMessage) = 0;

	/** 获取可用Features。 */
	static TArray<IVoiceConversationServiceFeatureInterface*> GetAvailableFeatures()
	{
		return IModularFeatures::Get().GetModularFeatureImplementations<IVoiceConversationServiceFeatureInterface>(GetFeatureName());
	}

	/** 查找特性按名称。 */
	static IVoiceConversationServiceFeatureInterface* FindFeatureByName(const FName InProviderName)
	{
		if (InProviderName.IsNone()) { return nullptr; }

		for (IVoiceConversationServiceFeatureInterface* Feature : GetAvailableFeatures())
		{
			if (Feature != nullptr && Feature->GetProviderName() == InProviderName) { return Feature; }
		}

		return nullptr;
	}
};
