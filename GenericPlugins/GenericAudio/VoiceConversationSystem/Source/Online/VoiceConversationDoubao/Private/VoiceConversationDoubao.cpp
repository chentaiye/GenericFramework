// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceConversationDoubao.h"

#include "Config/VoiceConversationDoubaoConfigDataAsset.h"
#include "Component/VoiceConversationComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceConversationServiceFeature.h"

namespace
{
	class FVoiceConversationDoubaoProvider final : public IVoiceConversationServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			static const FName ProviderName(TEXT("Doubao"));
			return ProviderName;
		}

		virtual bool IsOnlineService() const override
		{
			return true;
		}

		virtual bool StartSession(UVoiceConversationComponent& InComponent, const FVoiceConversationStartRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UDoubaoConversationConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UDoubaoConversationConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}

			OutMessage = FString::Printf(TEXT("Doubao conversation session started. Model=%s"), *InRequest.ModelId);
			InComponent.NotifyProviderSessionStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}

		virtual void StopSession(UVoiceConversationComponent& InComponent) override
		{
			InComponent.NotifyProviderSessionStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Doubao conversation stopped."));
		}

		virtual bool SendUserMessage(UVoiceConversationComponent& InComponent, const FString& InMessage, FString& OutMessage) override
		{
			OutMessage = FString::Printf(TEXT("Doubao conversation accepted message. Length=%d"), InMessage.Len());
			return true;
		}
	};

	FVoiceConversationDoubaoProvider GProvider;
}

void FVoiceConversationDoubaoModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceConversationServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationDoubao startup."));
}

void FVoiceConversationDoubaoModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceConversationServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceConversationServiceFeatureInterface::GetFeatureName(), &GProvider);
	}

	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationDoubao shutdown."));
}

IMPLEMENT_MODULE(FVoiceConversationDoubaoModule, VoiceConversationDoubao)
