// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceConversationLocal.h"

#include "Component/VoiceConversationComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceConversationServiceFeature.h"

namespace
{
	class FVoiceConversationLocalProvider final : public IVoiceConversationServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			static const FName ProviderName(TEXT("LocalConversation"));
			return ProviderName;
		}

		virtual bool IsOnlineService() const override
		{
			return false;
		}

		virtual bool StartSession(UVoiceConversationComponent& InComponent, const FVoiceConversationStartRequest& InRequest, FString& OutMessage) override
		{
			OutMessage = FString::Printf(TEXT("Local conversation session started. Model=%s"), *InRequest.ModelId);
			InComponent.NotifyProviderSessionStarted(GetProviderName(), EVoiceRouteSource::Offline, OutMessage);
			return true;
		}

		virtual void StopSession(UVoiceConversationComponent& InComponent) override
		{
			InComponent.NotifyProviderSessionStopped(GetProviderName(), EVoiceRouteSource::Offline, TEXT("Local conversation stopped."));
		}

		virtual bool SendUserMessage(UVoiceConversationComponent& InComponent, const FString& InMessage, FString& OutMessage) override
		{
			OutMessage = FString::Printf(TEXT("Local conversation accepted message. Length=%d"), InMessage.Len());
			return true;
		}
	};

	FVoiceConversationLocalProvider GProvider;
}

void FVoiceConversationLocalModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceConversationServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationLocal startup."));
}

void FVoiceConversationLocalModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceConversationServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceConversationServiceFeatureInterface::GetFeatureName(), &GProvider);
	}

	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationLocal shutdown."));
}

IMPLEMENT_MODULE(FVoiceConversationLocalModule, VoiceConversationLocal)
