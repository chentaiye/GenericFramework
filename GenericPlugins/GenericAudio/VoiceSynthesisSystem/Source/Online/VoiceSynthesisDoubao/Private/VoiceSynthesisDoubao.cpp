// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceSynthesisDoubao.h"

#include "Config/VoiceSynthesisDoubaoConfigDataAsset.h"
#include "Component/VoiceSynthesisComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceSynthesisServiceFeature.h"

namespace
{
	class FVoiceSynthesisDoubaoProvider final : public IVoiceSynthesisServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override { static const FName Name(TEXT("Doubao")); return Name; }
		virtual bool IsOnlineService() const override { return true; }
		virtual bool Synthesize(UVoiceSynthesisComponent& InComponent, const FVoiceSynthesisRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UDoubaoSynthesisConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UDoubaoSynthesisConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}
			OutMessage = FString::Printf(TEXT("Doubao synthesis framework mode started. VoiceId=%s"), *InRequest.VoiceId);
			InComponent.NotifyProviderSynthesisStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}
		virtual void CancelSynthesis(UVoiceSynthesisComponent& InComponent) override
		{
			InComponent.NotifyProviderSynthesisStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Doubao synthesis cancelled."));
		}
	};
	FVoiceSynthesisDoubaoProvider GProvider;
}

void FVoiceSynthesisDoubaoModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisDoubao startup."));
}

void FVoiceSynthesisDoubaoModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceSynthesisServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	}
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisDoubao shutdown."));
}

IMPLEMENT_MODULE(FVoiceSynthesisDoubaoModule, VoiceSynthesisDoubao)
