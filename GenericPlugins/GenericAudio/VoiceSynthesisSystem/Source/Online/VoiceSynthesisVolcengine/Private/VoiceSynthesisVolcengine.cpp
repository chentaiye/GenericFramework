// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceSynthesisVolcengine.h"

#include "Config/VoiceSynthesisVolcengineConfigDataAsset.h"
#include "Component/VoiceSynthesisComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceSynthesisServiceFeature.h"

namespace
{
	class FVoiceSynthesisVolcengineProvider final : public IVoiceSynthesisServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override { static const FName Name(TEXT("Volcengine")); return Name; }
		virtual bool IsOnlineService() const override { return true; }
		virtual bool Synthesize(UVoiceSynthesisComponent& InComponent, const FVoiceSynthesisRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UVolcengineSynthesisConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UVolcengineSynthesisConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}
			OutMessage = FString::Printf(TEXT("Volcengine synthesis framework mode started. VoiceId=%s Output=%s"), *InRequest.VoiceId, *InRequest.OutputFilePath);
			InComponent.NotifyProviderSynthesisStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}
		virtual void CancelSynthesis(UVoiceSynthesisComponent& InComponent) override
		{
			InComponent.NotifyProviderSynthesisStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Volcengine synthesis cancelled."));
		}
	};
	FVoiceSynthesisVolcengineProvider GProvider;
}

void FVoiceSynthesisVolcengineModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisVolcengine startup."));
}

void FVoiceSynthesisVolcengineModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceSynthesisServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	}
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisVolcengine shutdown."));
}

IMPLEMENT_MODULE(FVoiceSynthesisVolcengineModule, VoiceSynthesisVolcengine)
