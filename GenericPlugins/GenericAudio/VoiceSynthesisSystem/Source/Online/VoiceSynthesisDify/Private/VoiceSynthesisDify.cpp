// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceSynthesisDify.h"

#include "Config/VoiceSynthesisDifyConfigDataAsset.h"
#include "Component/VoiceSynthesisComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceSynthesisServiceFeature.h"

namespace
{
	class FVoiceSynthesisDifyProvider final : public IVoiceSynthesisServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override { static const FName Name(TEXT("Dify")); return Name; }
		virtual bool IsOnlineService() const override { return true; }
		virtual bool Synthesize(UVoiceSynthesisComponent& InComponent, const FVoiceSynthesisRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UDifySynthesisConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UDifySynthesisConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}
			OutMessage = FString::Printf(TEXT("Dify synthesis framework mode started. TextLength=%d"), InRequest.Text.Len());
			InComponent.NotifyProviderSynthesisStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}
		virtual void CancelSynthesis(UVoiceSynthesisComponent& InComponent) override
		{
			InComponent.NotifyProviderSynthesisStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Dify synthesis cancelled."));
		}
	};
	FVoiceSynthesisDifyProvider GProvider;
}

void FVoiceSynthesisDifyModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisDify startup."));
}

void FVoiceSynthesisDifyModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceSynthesisServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	}
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisDify shutdown."));
}

IMPLEMENT_MODULE(FVoiceSynthesisDifyModule, VoiceSynthesisDify)
