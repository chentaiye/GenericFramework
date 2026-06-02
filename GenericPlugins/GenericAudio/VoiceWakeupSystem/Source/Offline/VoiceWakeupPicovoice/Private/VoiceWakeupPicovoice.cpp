// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceWakeupPicovoice.h"

#include "Config/VoiceWakeupPicovoiceConfigDataAsset.h"
#include "Component/VoiceWakeupComponent.h"
#include "VoiceTypes.h"
#include "Provider/VoiceWakeupServiceFeature.h"

namespace
{
	class FVoiceWakeupPicovoiceProvider final : public IVoiceWakeupServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			static const FName ProviderName(TEXT("Picovoice"));
			return ProviderName;
		}

		virtual bool IsOnlineService() const override
		{
			return false;
		}

		virtual bool StartListening(UVoiceWakeupComponent& InComponent, const FVoiceWakeupStartRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UPicovoiceWakeupConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UPicovoiceWakeupConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Offline,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}

			OutMessage = FString::Printf(
				TEXT("Picovoice wakeup provider entered framework mode. KeywordCount=%d Sensitivity=%.2f"),
				InRequest.Keywords.Num(),
				InRequest.Sensitivity);
			UE_LOG(LogVoiceWakeup, Warning, TEXT("%s"), *OutMessage);
			InComponent.NotifyProviderListeningStarted(GetProviderName(), EVoiceRouteSource::Offline, OutMessage);
			return true;
		}

		virtual void StopListening(UVoiceWakeupComponent& InComponent) override
		{
			InComponent.NotifyProviderStopped(GetProviderName(), EVoiceRouteSource::Offline, TEXT("Picovoice wakeup provider stopped."));
		}
	};

	FVoiceWakeupPicovoiceProvider GVoiceWakeupPicovoiceProvider;
}

void FVoiceWakeupPicovoiceModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceWakeupServiceFeatureInterface::GetFeatureName(), &GVoiceWakeupPicovoiceProvider);
	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupPicovoice startup."));
}

void FVoiceWakeupPicovoiceModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceWakeupServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceWakeupServiceFeatureInterface::GetFeatureName(), &GVoiceWakeupPicovoiceProvider);
	}

	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupPicovoice shutdown."));
}

IMPLEMENT_MODULE(FVoiceWakeupPicovoiceModule, VoiceWakeupPicovoice)
