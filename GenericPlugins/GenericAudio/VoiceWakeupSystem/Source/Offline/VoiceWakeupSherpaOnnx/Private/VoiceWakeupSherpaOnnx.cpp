// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceWakeupSherpaOnnx.h"

#include "Config/VoiceWakeupSherpaOnnxConfigDataAsset.h"
#include "Component/VoiceWakeupComponent.h"
#include "VoiceTypes.h"
#include "Misc/Paths.h"
#include "Provider/VoiceWakeupServiceFeature.h"

namespace
{
	class FVoiceWakeupSherpaOnnxProvider final : public IVoiceWakeupServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			static const FName ProviderName(TEXT("SherpaOnnx"));
			return ProviderName;
		}

		virtual bool IsOnlineService() const override
		{
			return false;
		}

		virtual bool StartListening(UVoiceWakeupComponent& InComponent, const FVoiceWakeupStartRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const USherpaOnnxWakeupConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<USherpaOnnxWakeupConfigDataAsset>(
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
				TEXT("SherpaOnnx wakeup framework mode started. ModelRoot=%s KeywordCount=%d"),
				*FPaths::ConvertRelativePathToFull(Config->SherpaOnnxModelRoot.Path),
				InRequest.Keywords.Num());
			UE_LOG(LogVoiceWakeup, Warning, TEXT("%s"), *OutMessage);
			InComponent.NotifyProviderListeningStarted(GetProviderName(), EVoiceRouteSource::Offline, OutMessage);
			return true;
		}

		virtual void StopListening(UVoiceWakeupComponent& InComponent) override
		{
			InComponent.NotifyProviderStopped(GetProviderName(), EVoiceRouteSource::Offline, TEXT("SherpaOnnx wakeup provider stopped."));
		}
	};

	FVoiceWakeupSherpaOnnxProvider GVoiceWakeupSherpaOnnxProvider;
}

void FVoiceWakeupSherpaOnnxModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceWakeupServiceFeatureInterface::GetFeatureName(), &GVoiceWakeupSherpaOnnxProvider);
	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupSherpaOnnx startup."));
}

void FVoiceWakeupSherpaOnnxModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceWakeupServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceWakeupServiceFeatureInterface::GetFeatureName(), &GVoiceWakeupSherpaOnnxProvider);
	}

	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupSherpaOnnx shutdown."));
}

IMPLEMENT_MODULE(FVoiceWakeupSherpaOnnxModule, VoiceWakeupSherpaOnnx)
