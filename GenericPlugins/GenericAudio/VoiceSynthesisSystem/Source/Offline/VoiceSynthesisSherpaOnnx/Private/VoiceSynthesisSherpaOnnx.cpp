// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceSynthesisSherpaOnnx.h"

#include "Config/VoiceSynthesisSherpaOnnxConfigDataAsset.h"
#include "Component/VoiceSynthesisComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceSynthesisServiceFeature.h"

namespace
{
	class FVoiceSynthesisSherpaOnnxProvider final : public IVoiceSynthesisServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override { static const FName Name(TEXT("SherpaOnnx")); return Name; }
		virtual bool IsOnlineService() const override { return false; }
		virtual bool Synthesize(UVoiceSynthesisComponent& InComponent, const FVoiceSynthesisRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const USherpaOnnxSynthesisConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<USherpaOnnxSynthesisConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Offline,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}
			OutMessage = FString::Printf(TEXT("SherpaOnnx synthesis framework mode started. VoiceId=%s"), *InRequest.VoiceId);
			InComponent.NotifyProviderSynthesisStarted(GetProviderName(), EVoiceRouteSource::Offline, OutMessage);
			return true;
		}
		virtual void CancelSynthesis(UVoiceSynthesisComponent& InComponent) override
		{
			InComponent.NotifyProviderSynthesisStopped(GetProviderName(), EVoiceRouteSource::Offline, TEXT("SherpaOnnx synthesis cancelled."));
		}
	};
	FVoiceSynthesisSherpaOnnxProvider GProvider;
}

void FVoiceSynthesisSherpaOnnxModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisSherpaOnnx startup."));
}

void FVoiceSynthesisSherpaOnnxModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceSynthesisServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	}
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisSherpaOnnx shutdown."));
}

IMPLEMENT_MODULE(FVoiceSynthesisSherpaOnnxModule, VoiceSynthesisSherpaOnnx)
