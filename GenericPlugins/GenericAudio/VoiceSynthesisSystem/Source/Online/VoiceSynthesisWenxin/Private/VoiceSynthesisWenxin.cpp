// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceSynthesisWenxin.h"

#include "Config/VoiceSynthesisWenxinConfigDataAsset.h"
#include "Component/VoiceSynthesisComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Provider/VoiceSynthesisServiceFeature.h"

namespace
{
	class FVoiceSynthesisWenxinProvider final : public IVoiceSynthesisServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override { static const FName Name(TEXT("Wenxin")); return Name; }
		virtual bool IsOnlineService() const override { return true; }
		virtual bool Synthesize(UVoiceSynthesisComponent& InComponent, const FVoiceSynthesisRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UWenxinSynthesisConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UWenxinSynthesisConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}
			OutMessage = FString::Printf(TEXT("Wenxin synthesis framework mode started. TextLength=%d"), InRequest.Text.Len());
			InComponent.NotifyProviderSynthesisStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}
		virtual void CancelSynthesis(UVoiceSynthesisComponent& InComponent) override
		{
			InComponent.NotifyProviderSynthesisStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Wenxin synthesis cancelled."));
		}
	};
	FVoiceSynthesisWenxinProvider GProvider;
}

void FVoiceSynthesisWenxinModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisWenxin startup."));
}

void FVoiceSynthesisWenxinModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceSynthesisServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceSynthesisServiceFeatureInterface::GetFeatureName(), &GProvider);
	}
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisWenxin shutdown."));
}

IMPLEMENT_MODULE(FVoiceSynthesisWenxinModule, VoiceSynthesisWenxin)
