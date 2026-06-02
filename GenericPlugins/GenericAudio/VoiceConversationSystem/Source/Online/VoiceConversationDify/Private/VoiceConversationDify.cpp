// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceConversationDify.h"

#include "Config/VoiceConversationDifyConfigDataAsset.h"
#include "Component/VoiceConversationComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceConversationServiceFeature.h"

namespace
{
	class FVoiceConversationDifyProvider final : public IVoiceConversationServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			static const FName ProviderName(TEXT("Dify"));
			return ProviderName;
		}

		virtual bool IsOnlineService() const override
		{
			return true;
		}

		virtual bool StartSession(UVoiceConversationComponent& InComponent, const FVoiceConversationStartRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UDifyConversationConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UDifyConversationConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}

			OutMessage = FString::Printf(TEXT("Dify conversation session started. Model=%s"), *InRequest.ModelId);
			InComponent.NotifyProviderSessionStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}

		virtual void StopSession(UVoiceConversationComponent& InComponent) override
		{
			InComponent.NotifyProviderSessionStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Dify conversation stopped."));
		}

		virtual bool SendUserMessage(UVoiceConversationComponent& InComponent, const FString& InMessage, FString& OutMessage) override
		{
			OutMessage = FString::Printf(TEXT("Dify conversation accepted message. Length=%d"), InMessage.Len());
			return true;
		}
	};

	FVoiceConversationDifyProvider GProvider;
}

void FVoiceConversationDifyModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceConversationServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationDify startup."));
}

void FVoiceConversationDifyModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceConversationServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceConversationServiceFeatureInterface::GetFeatureName(), &GProvider);
	}

	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationDify shutdown."));
}

IMPLEMENT_MODULE(FVoiceConversationDifyModule, VoiceConversationDify)
