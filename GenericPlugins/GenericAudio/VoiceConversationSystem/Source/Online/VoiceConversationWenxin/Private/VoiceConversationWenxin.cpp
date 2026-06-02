// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceConversationWenxin.h"

#include "Config/VoiceConversationWenxinConfigDataAsset.h"
#include "Component/VoiceConversationComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceConversationServiceFeature.h"

namespace
{
	class FVoiceConversationWenxinProvider final : public IVoiceConversationServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			static const FName ProviderName(TEXT("Wenxin"));
			return ProviderName;
		}

		virtual bool IsOnlineService() const override
		{
			return true;
		}

		virtual bool StartSession(UVoiceConversationComponent& InComponent, const FVoiceConversationStartRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UWenxinConversationConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UWenxinConversationConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}

			OutMessage = FString::Printf(TEXT("Wenxin conversation session started. Model=%s"), *InRequest.ModelId);
			InComponent.NotifyProviderSessionStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}

		virtual void StopSession(UVoiceConversationComponent& InComponent) override
		{
			InComponent.NotifyProviderSessionStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Wenxin conversation stopped."));
		}

		virtual bool SendUserMessage(UVoiceConversationComponent& InComponent, const FString& InMessage, FString& OutMessage) override
		{
			OutMessage = FString::Printf(TEXT("Wenxin conversation accepted message. Length=%d"), InMessage.Len());
			return true;
		}
	};

	FVoiceConversationWenxinProvider GProvider;
}

void FVoiceConversationWenxinModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceConversationServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationWenxin startup."));
}

void FVoiceConversationWenxinModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceConversationServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceConversationServiceFeatureInterface::GetFeatureName(), &GProvider);
	}

	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationWenxin shutdown."));
}

IMPLEMENT_MODULE(FVoiceConversationWenxinModule, VoiceConversationWenxin)
