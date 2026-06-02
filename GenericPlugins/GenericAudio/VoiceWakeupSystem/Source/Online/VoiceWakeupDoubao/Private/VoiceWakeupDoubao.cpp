// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceWakeupDoubao.h"

#include "Config/VoiceWakeupDoubaoConfigDataAsset.h"
#include "Component/VoiceWakeupComponent.h"
#include "VoiceTypes.h"
#include "Provider/VoiceWakeupServiceFeature.h"

namespace
{
	class FVoiceWakeupDoubaoProvider final : public IVoiceWakeupServiceFeatureInterface
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

		virtual bool StartListening(UVoiceWakeupComponent& InComponent, const FVoiceWakeupStartRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UDoubaoWakeupConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UDoubaoWakeupConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}

			OutMessage = TEXT("Doubao wakeup provider entered framework mode. Use SimulateWakeup or replace the provider implementation with the final online bridge.");
			UE_LOG(LogVoiceWakeup, Warning, TEXT("Doubao wakeup provider started in framework mode. KeywordCount=%d"), InRequest.Keywords.Num());
			InComponent.NotifyProviderListeningStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}

		virtual void StopListening(UVoiceWakeupComponent& InComponent) override
		{
			InComponent.NotifyProviderStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Doubao wakeup provider stopped."));
		}
	};

	FVoiceWakeupDoubaoProvider GVoiceWakeupDoubaoProvider;
}

void FVoiceWakeupDoubaoModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceWakeupServiceFeatureInterface::GetFeatureName(), &GVoiceWakeupDoubaoProvider);
	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupDoubao startup."));
}

void FVoiceWakeupDoubaoModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceWakeupServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceWakeupServiceFeatureInterface::GetFeatureName(), &GVoiceWakeupDoubaoProvider);
	}

	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupDoubao shutdown."));
}

IMPLEMENT_MODULE(FVoiceWakeupDoubaoModule, VoiceWakeupDoubao)
