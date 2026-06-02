// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceRecognitionSherpaOnnx.h"

#include "Config/VoiceRecognitionSherpaOnnxConfigDataAsset.h"
#include "Component/VoiceRecognitionComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Misc/Paths.h"
#include "Provider/VoiceRecognitionServiceFeature.h"

namespace
{
	class FVoiceRecognitionSherpaOnnxProvider final : public IVoiceRecognitionServiceFeatureInterface
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

		virtual bool StartRecognition(UVoiceRecognitionComponent& InComponent, const FVoiceRecognitionStartRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const USherpaOnnxRecognitionConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<USherpaOnnxRecognitionConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Offline,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}

			OutMessage = FString::Printf(TEXT("SherpaOnnx recognition framework mode started. ModelRoot=%s SampleRate=%d"),
				*FPaths::ConvertRelativePathToFull(Config->SherpaOnnxModelRoot.Path),
				InRequest.SampleRate);
			InComponent.NotifyProviderRecognitionStarted(GetProviderName(), EVoiceRouteSource::Offline, OutMessage);
			return true;
		}

		virtual void StopRecognition(UVoiceRecognitionComponent& InComponent) override
		{
			InComponent.NotifyProviderRecognitionStopped(GetProviderName(), EVoiceRouteSource::Offline, TEXT("SherpaOnnx recognition provider stopped."));
		}

		virtual bool SubmitAudio(UVoiceRecognitionComponent& InComponent, const TArray<uint8>& InAudioPcm16Bytes, const int32 InSampleRate, const int32 InNumChannels, FString& OutMessage) override
		{
			if (InAudioPcm16Bytes.IsEmpty())
			{
				OutMessage = TEXT("SherpaOnnx recognition received an empty PCM buffer.");
				return false;
			}

			OutMessage = FString::Printf(TEXT("SherpaOnnx recognition buffered %d bytes at %d Hz with %d channel(s)."), InAudioPcm16Bytes.Num(), InSampleRate, InNumChannels);
			return true;
		}

		virtual bool SubmitAudioFile(UVoiceRecognitionComponent& InComponent, const FString& InAudioFilePath, FString& OutMessage) override
		{
			if (!FPaths::FileExists(InAudioFilePath))
			{
				OutMessage = FString::Printf(TEXT("Recognition audio file does not exist: %s"), *InAudioFilePath);
				return false;
			}

			OutMessage = FString::Printf(TEXT("SherpaOnnx recognition accepted audio file: %s"), *InAudioFilePath);
			return true;
		}
	};

	FVoiceRecognitionSherpaOnnxProvider GVoiceRecognitionSherpaOnnxProvider;
}

void FVoiceRecognitionSherpaOnnxModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(IVoiceRecognitionServiceFeatureInterface::GetFeatureName(), &GVoiceRecognitionSherpaOnnxProvider);
	UE_LOG(LogVoiceRecognition, Log, TEXT("VoiceRecognitionSherpaOnnx startup."));
}

void FVoiceRecognitionSherpaOnnxModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceRecognitionServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceRecognitionServiceFeatureInterface::GetFeatureName(), &GVoiceRecognitionSherpaOnnxProvider);
	}

	UE_LOG(LogVoiceRecognition, Log, TEXT("VoiceRecognitionSherpaOnnx shutdown."));
}

IMPLEMENT_MODULE(FVoiceRecognitionSherpaOnnxModule, VoiceRecognitionSherpaOnnx)
