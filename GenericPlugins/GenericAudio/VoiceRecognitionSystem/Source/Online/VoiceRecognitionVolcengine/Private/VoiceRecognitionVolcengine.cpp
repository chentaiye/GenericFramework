// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceRecognitionVolcengine.h"

#include "Config/VoiceRecognitionVolcengineConfigDataAsset.h"
#include "Component/VoiceRecognitionComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Provider/VoiceRecognitionServiceFeature.h"

namespace
{
	class FVoiceRecognitionVolcengineProvider final : public IVoiceRecognitionServiceFeatureInterface
	{
	public:
		virtual FName GetProviderName() const override
		{
			static const FName ProviderName(TEXT("Volcengine"));
			return ProviderName;
		}

		virtual bool IsOnlineService() const override
		{
			return true;
		}

		virtual bool StartRecognition(UVoiceRecognitionComponent& InComponent, const FVoiceRecognitionStartRequest& InRequest, FString& OutMessage) override
		{
			FString ConfigMessage;
			const UVolcengineRecognitionConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UVolcengineRecognitionConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}

			OutMessage = FString::Printf(TEXT("Volcengine recognition provider started. SampleRate=%d VAD=%d Punctuation=%d"),
				InRequest.SampleRate,
				InRequest.bEnableVad ? 1 : 0,
				InRequest.bEnablePunctuation ? 1 : 0);
			UE_LOG(LogVoiceRecognition, Log, TEXT("%s"), *OutMessage);
			InComponent.NotifyProviderRecognitionStarted(GetProviderName(), EVoiceRouteSource::Online, OutMessage);
			return true;
		}

		virtual void StopRecognition(UVoiceRecognitionComponent& InComponent) override
		{
			InComponent.NotifyProviderRecognitionStopped(GetProviderName(), EVoiceRouteSource::Online, TEXT("Volcengine recognition provider stopped."));
		}

		virtual bool SubmitAudio(UVoiceRecognitionComponent& InComponent, const TArray<uint8>& InAudioPcm16Bytes, const int32 InSampleRate, const int32 InNumChannels, FString& OutMessage) override
		{
			if (InAudioPcm16Bytes.IsEmpty())
			{
				OutMessage = TEXT("Volcengine recognition received an empty PCM buffer.");
				return false;
			}

			OutMessage = FString::Printf(TEXT("Volcengine recognition buffered %d bytes at %d Hz with %d channel(s)."), InAudioPcm16Bytes.Num(), InSampleRate, InNumChannels);
			UE_LOG(LogVoiceRecognition, Verbose, TEXT("%s"), *OutMessage);
			return true;
		}

		virtual bool SubmitAudioFile(UVoiceRecognitionComponent& InComponent, const FString& InAudioFilePath, FString& OutMessage) override
		{
			if (!FPaths::FileExists(InAudioFilePath))
			{
				OutMessage = FString::Printf(TEXT("Recognition audio file does not exist: %s"), *InAudioFilePath);
				return false;
			}

			OutMessage = FString::Printf(TEXT("Volcengine recognition accepted audio file: %s"), *InAudioFilePath);
			UE_LOG(LogVoiceRecognition, Log, TEXT("%s"), *OutMessage);
			return true;
		}
	};

	FVoiceRecognitionVolcengineProvider GVoiceRecognitionVolcengineProvider;

	TArray<FString> GetWhitelistedRuntimeLibs()
	{
		TArray<FString> WhitelistedLibs;
#ifdef VOLCENGINERTC_WHITELISTED_BINARIES
		const FString WhitelistedLibsDef(VOLCENGINERTC_WHITELISTED_BINARIES);
		WhitelistedLibsDef.ParseIntoArray(WhitelistedLibs, TEXT(";"));
#endif
		return WhitelistedLibs;
	}

	FString GetRuntimeLibDirectory()
	{
		FString RuntimeLibDirectory;
#if WITH_EDITOR
#ifdef VOLCENGINERTC_THIRDPARTY_BINARY_ABSOLUTEDIR
		RuntimeLibDirectory = TEXT(VOLCENGINERTC_THIRDPARTY_BINARY_ABSOLUTEDIR);
#endif
#endif
		if (RuntimeLibDirectory.IsEmpty())
		{
			RuntimeLibDirectory = FPaths::GetPath(FPlatformProcess::ExecutablePath());
		}

		return RuntimeLibDirectory;
	}
}

void FVoiceRecognitionVolcengineModule::StartupModule()
{
	LoadRuntimeLibraries();
	IModularFeatures::Get().RegisterModularFeature(IVoiceRecognitionServiceFeatureInterface::GetFeatureName(), &GVoiceRecognitionVolcengineProvider);
	UE_LOG(LogVoiceRecognition, Log, TEXT("VoiceRecognitionVolcengine startup."));
}

void FVoiceRecognitionVolcengineModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceRecognitionServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceRecognitionServiceFeatureInterface::GetFeatureName(), &GVoiceRecognitionVolcengineProvider);
	}

	UnloadRuntimeLibraries();
	UE_LOG(LogVoiceRecognition, Log, TEXT("VoiceRecognitionVolcengine shutdown."));
}

void FVoiceRecognitionVolcengineModule::LoadRuntimeLibraries()
{
	const FString RuntimeLibDirectory = GetRuntimeLibDirectory();
	const TArray<FString> RuntimeLibs = GetWhitelistedRuntimeLibs();
	if (RuntimeLibDirectory.IsEmpty() || RuntimeLibs.IsEmpty())
	{
		return;
	}

	FPlatformProcess::PushDllDirectory(*RuntimeLibDirectory);
	for (const FString& RuntimeLib : RuntimeLibs)
	{
		if (void* Handle = FPlatformProcess::GetDllHandle(*RuntimeLib))
		{
			RuntimeLibraries.Add(Handle);
		}
	}
	FPlatformProcess::PopDllDirectory(*RuntimeLibDirectory);
}

void FVoiceRecognitionVolcengineModule::UnloadRuntimeLibraries()
{
	for (void*& Handle : RuntimeLibraries)
	{
		if (Handle != nullptr)
		{
			FPlatformProcess::FreeDllHandle(Handle);
			Handle = nullptr;
		}
	}

	RuntimeLibraries.Empty();
}

IMPLEMENT_MODULE(FVoiceRecognitionVolcengineModule, VoiceRecognitionVolcengine)
