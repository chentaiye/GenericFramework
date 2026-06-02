// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceWakeupXfyun.h"

#include "Async/Async.h"
#include "Config/VoiceWakeupXfyunConfigDataAsset.h"
#include "Component/VoiceWakeupComponent.h"
#include "Features/IModularFeatures.h"
#include "VoiceTypes.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Provider/VoiceWakeupServiceFeature.h"

#if PLATFORM_WINDOWS
#include "Windows/WindowsHWrapper.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include <mmsystem.h>
extern "C"
{
#include "msp_cmn.h"
#include "msp_errors.h"
#include "msp_types.h"
#include "qivw.h"
}
#include "Windows/HideWindowsPlatformTypes.h"
#endif

namespace
{
	constexpr int32 VoiceXfyunWakeupChunkBytes = 10 * 640;
	constexpr uint32 VoiceXfyunCaptureBufferBytes = 512 * 1024;

	FString GetXfyunResourceFile(const UXfyunWakeupConfigDataAsset& InConfig)
	{
		if (!InConfig.XfyunWakeupResourceFile.FilePath.IsEmpty())
		{
			return FPaths::ConvertRelativePathToFull(InConfig.XfyunWakeupResourceFile.FilePath);
		}

		const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("VoiceWakeupSystem"));
		if (!Plugin.IsValid())
		{
			return FString();
		}

		return FPaths::Combine(
			Plugin->GetBaseDir(),
			TEXT("Source"),
			TEXT("Online"),
			TEXT("ThirdParty"),
			TEXT("VoiceWakeupSdk"),
			TEXT("res"),
			TEXT("wakeupresource.jet"));
	}

	class FVoiceWakeupXfyunProvider final : public IVoiceWakeupServiceFeatureInterface
	{
	private:
		struct FXfyunWakeupSession : public TSharedFromThis<FXfyunWakeupSession, ESPMode::ThreadSafe>
		{
			TWeakObjectPtr<UVoiceWakeupComponent> Component;
			FVoiceWakeupStartRequest Request;
			FString XfyunAppId;
			FString XfyunResourceFile;
			TFuture<void> Future;
			FThreadSafeBool bStopRequested = false;
			bool bListeningStarted = false;

			void DispatchStarted(const FString& InMessage)
			{
				Dispatch([InMessage](UVoiceWakeupComponent& InComponent)
				{
					InComponent.NotifyProviderListeningStarted(TEXT("Xfyun"), EVoiceRouteSource::Online, InMessage);
				});
			}

			void DispatchStopped(const FString& InMessage)
			{
				Dispatch([InMessage](UVoiceWakeupComponent& InComponent)
				{
					InComponent.NotifyProviderStopped(TEXT("Xfyun"), EVoiceRouteSource::Online, InMessage);
				});
			}

			void DispatchError(const FString& InMessage)
			{
				Dispatch([InMessage](UVoiceWakeupComponent& InComponent)
				{
					InComponent.NotifyProviderError(TEXT("Xfyun"), EVoiceRouteSource::Online, InMessage);
				});
			}

			void DispatchWakeup(const FString& InKeyword, const float InConfidence, const FString& InMessage)
			{
				Dispatch([InKeyword, InConfidence, InMessage](UVoiceWakeupComponent& InComponent)
				{
					InComponent.NotifyWakeupDetected(TEXT("Xfyun"), EVoiceRouteSource::Online, InKeyword, InConfidence, InMessage);
				});
			}

		private:
			template <typename TCallback>
			void Dispatch(TCallback&& InCallback)
			{
				TWeakObjectPtr<UVoiceWakeupComponent> WeakComponent = Component;
				AsyncTask(ENamedThreads::GameThread, [WeakComponent, Callback = Forward<TCallback>(InCallback)]() mutable
				{
					if (WeakComponent.IsValid())
					{
						Callback(*WeakComponent.Get());
					}
				});
			}
		};

	public:
		virtual FName GetProviderName() const override
		{
			static const FName ProviderName(TEXT("Xfyun"));
			return ProviderName;
		}

		virtual bool IsOnlineService() const override
		{
			return true;
		}

		virtual bool StartListening(UVoiceWakeupComponent& InComponent, const FVoiceWakeupStartRequest& InRequest, FString& OutMessage) override
		{
			if (ActiveSession.IsValid())
			{
				OutMessage = TEXT("Xfyun wakeup does not allow concurrent listening sessions.");
				return false;
			}

			FString ConfigMessage;
			const UXfyunWakeupConfigDataAsset* Config = UVoiceProviderConfigDataAsset::FindFirstValidTypedConfig<UXfyunWakeupConfigDataAsset>(
				InComponent.GetProviderConfigs(),
				GetProviderName(),
				EVoiceRouteSource::Online,
				ConfigMessage);
			if (Config == nullptr)
			{
				OutMessage = ConfigMessage;
				return false;
			}

			const FString ResourceFile = GetXfyunResourceFile(*Config);
			if (ResourceFile.IsEmpty() || !FPaths::FileExists(ResourceFile))
			{
				OutMessage = FString::Printf(TEXT("Xfyun wakeup resource file is missing: %s"), *ResourceFile);
				return false;
			}

			ActiveSession = MakeShared<FXfyunWakeupSession, ESPMode::ThreadSafe>();
			ActiveSession->Component = &InComponent;
			ActiveSession->Request = InRequest;
			ActiveSession->XfyunAppId = Config->XfyunAppId;
			ActiveSession->XfyunResourceFile = ResourceFile;
			ActiveSession->Future = Async(EAsyncExecution::Thread, [this, Session = ActiveSession]()
			{
				RunSession(Session.ToSharedRef());
			});

			OutMessage = TEXT("Xfyun wakeup session is starting.");
			UE_LOG(LogVoiceWakeup, Log, TEXT("Xfyun wakeup session created. KeywordCount=%d Sensitivity=%.2f"),
				InRequest.Keywords.Num(),
				InRequest.Sensitivity);
			return true;
		}

		virtual void StopListening(UVoiceWakeupComponent& InComponent) override
		{
			TSharedPtr<FXfyunWakeupSession, ESPMode::ThreadSafe> Session = ActiveSession;
			if (!Session.IsValid())
			{
				InComponent.NotifyProviderStopped(TEXT("Xfyun"), EVoiceRouteSource::Online, TEXT("Xfyun wakeup session already stopped."));
				return;
			}

			Session->bStopRequested = true;
			if (Session->Future.IsValid())
			{
				Session->Future.Wait();
			}

			ActiveSession.Reset();
		}

	private:
		void RunSession(const TSharedRef<FXfyunWakeupSession, ESPMode::ThreadSafe>& Session)
		{
#if !PLATFORM_WINDOWS
			Session->DispatchError(TEXT("Xfyun wakeup SDK is currently implemented for Win64 only."));
			return;
#else
			const FString ResourceFile = Session->XfyunResourceFile;
			const FString LoginParams = FString::Printf(TEXT("appid = %s, work_dir = ."), *Session->XfyunAppId);
			const FTCHARToUTF8 LoginParamsUtf8(*LoginParams);
			const int32 LoginResult = MSPLogin(nullptr, nullptr, LoginParamsUtf8.Get());
			if (LoginResult != MSP_SUCCESS)
			{
				Session->DispatchError(FString::Printf(TEXT("Xfyun wakeup login failed. Error=%d"), LoginResult));
				return;
			}

			const int32 Threshold = FMath::Clamp(FMath::RoundToInt(FMath::Lerp(1800.0f, 800.0f, FMath::Clamp(Session->Request.Sensitivity, 0.0f, 1.0f))), 500, 2000);
			const FString SessionParams = FString::Printf(
				TEXT("ivw_threshold=0:%d,sst=wakeup,ivw_res_path=fo|%s"),
				Threshold,
				*ResourceFile.Replace(TEXT("/"), TEXT("\\")));
			const FTCHARToUTF8 SessionParamsUtf8(*SessionParams);

			int32 ErrorCode = MSP_SUCCESS;
			const char* SessionId = QIVWSessionBegin(nullptr, SessionParamsUtf8.Get(), &ErrorCode);
			if (ErrorCode != MSP_SUCCESS || SessionId == nullptr)
			{
				MSPLogout();
				Session->DispatchError(FString::Printf(TEXT("QIVWSessionBegin failed. Error=%d"), ErrorCode));
				return;
			}

			ErrorCode = QIVWRegisterNotify(SessionId, &FVoiceWakeupXfyunProvider::HandleWakeupNotify, &Session.Get());
			if (ErrorCode != MSP_SUCCESS)
			{
				QIVWSessionEnd(SessionId, "register notify failed");
				MSPLogout();
				Session->DispatchError(FString::Printf(TEXT("QIVWRegisterNotify failed. Error=%d"), ErrorCode));
				return;
			}

			HWAVEIN WaveInput = nullptr;
			WAVEFORMATEX WaveFormat = {};
			WaveFormat.wFormatTag = WAVE_FORMAT_PCM;
			WaveFormat.nSamplesPerSec = 16000;
			WaveFormat.wBitsPerSample = 16;
			WaveFormat.nChannels = 1;
			WaveFormat.nBlockAlign = 2;
			WaveFormat.nAvgBytesPerSec = WaveFormat.nSamplesPerSec * WaveFormat.nBlockAlign;

			const MMRESULT OpenResult = waveInOpen(&WaveInput, WAVE_MAPPER, &WaveFormat, 0, 0, CALLBACK_NULL);
			if (OpenResult != MMSYSERR_NOERROR || WaveInput == nullptr)
			{
				QIVWSessionEnd(SessionId, "waveInOpen failed");
				MSPLogout();
				Session->DispatchError(FString::Printf(TEXT("waveInOpen failed. Error=%u"), static_cast<uint32>(OpenResult)));
				return;
			}

			TArray<uint8> CaptureBuffer;
			CaptureBuffer.SetNumZeroed(VoiceXfyunCaptureBufferBytes);

			WAVEHDR WaveHeader = {};
			WaveHeader.lpData = reinterpret_cast<LPSTR>(CaptureBuffer.GetData());
			WaveHeader.dwBufferLength = CaptureBuffer.Num();

			auto RestartCapture = [&]() -> bool
			{
				waveInReset(WaveInput);
				waveInUnprepareHeader(WaveInput, &WaveHeader, sizeof(WAVEHDR));
				FMemory::Memzero(CaptureBuffer.GetData(), CaptureBuffer.Num());
				FMemory::Memzero(&WaveHeader, sizeof(WAVEHDR));
				WaveHeader.lpData = reinterpret_cast<LPSTR>(CaptureBuffer.GetData());
				WaveHeader.dwBufferLength = CaptureBuffer.Num();
				return waveInPrepareHeader(WaveInput, &WaveHeader, sizeof(WAVEHDR)) == MMSYSERR_NOERROR
					&& waveInAddBuffer(WaveInput, &WaveHeader, sizeof(WAVEHDR)) == MMSYSERR_NOERROR
					&& waveInStart(WaveInput) == MMSYSERR_NOERROR;
			};

			if (!RestartCapture())
			{
				waveInClose(WaveInput);
				QIVWSessionEnd(SessionId, "capture prepare failed");
				MSPLogout();
				Session->DispatchError(TEXT("Failed to prepare Xfyun wakeup capture device."));
				return;
			}

			Session->bListeningStarted = true;
			Session->DispatchStarted(TEXT("Xfyun wakeup listening started."));

			uint32 AudioOffset = 0;
			while (!Session->bStopRequested)
			{
				FPlatformProcess::Sleep(0.05f);

				if (WaveHeader.dwBytesRecorded <= AudioOffset)
				{
					continue;
				}

				const uint32 AvailableBytes = WaveHeader.dwBytesRecorded - AudioOffset;
				const uint32 ChunkBytes = FMath::Min<uint32>(AvailableBytes, VoiceXfyunWakeupChunkBytes);
				const int32 AudioState = AudioOffset == 0 ? MSP_AUDIO_SAMPLE_FIRST : MSP_AUDIO_SAMPLE_CONTINUE;
				ErrorCode = QIVWAudioWrite(SessionId, CaptureBuffer.GetData() + AudioOffset, static_cast<unsigned int>(ChunkBytes), AudioState);
				if (ErrorCode != MSP_SUCCESS)
				{
					Session->DispatchError(FString::Printf(TEXT("QIVWAudioWrite failed. Error=%d"), ErrorCode));
					break;
				}

				AudioOffset += ChunkBytes;
				if (AudioOffset >= WaveHeader.dwBytesRecorded)
				{
					AudioOffset = 0;
					if (!RestartCapture())
					{
						Session->DispatchError(TEXT("Failed to recycle Xfyun wakeup capture buffer."));
						break;
					}
				}
			}

			waveInStop(WaveInput);
			waveInReset(WaveInput);
			waveInUnprepareHeader(WaveInput, &WaveHeader, sizeof(WAVEHDR));
			waveInClose(WaveInput);
			QIVWSessionEnd(SessionId, Session->bStopRequested ? "stop requested" : "session ended");
			MSPLogout();

			if (Session->bListeningStarted)
			{
				Session->DispatchStopped(TEXT("Xfyun wakeup session stopped."));
			}
#endif
		}

		static int HandleWakeupNotify(const char* InSessionId, const int InMessage, int InParam1, int InParam2, const void* InInfo, void* InUserData)
		{
			UE_LOG(LogVoiceWakeup, Verbose, TEXT("Xfyun wakeup callback received. Session=%hs Message=%d Param1=%d Param2=%d"),
				InSessionId != nullptr ? InSessionId : "",
				InMessage,
				InParam1,
				InParam2);

			FXfyunWakeupSession* Session = static_cast<FXfyunWakeupSession*>(InUserData);
			if (Session == nullptr)
			{
				return 0;
			}

			if (InMessage == MSP_IVW_MSG_WAKEUP)
			{
				const FString InfoMessage = InInfo != nullptr ? ANSI_TO_TCHAR(static_cast<const char*>(InInfo)) : TEXT("Xfyun wakeup detected.");
				const FString Keyword = Session->Request.Keywords.IsEmpty() ? TEXT("Wakeup") : Session->Request.Keywords[0];
				Session->DispatchWakeup(Keyword, 1.0f, InfoMessage);
			}

			return 0;
		}

	private:
		TSharedPtr<FXfyunWakeupSession, ESPMode::ThreadSafe> ActiveSession;
	};

	FVoiceWakeupXfyunProvider GVoiceWakeupXfyunProvider;

	TArray<FString> GetWhitelistedRuntimeLibs()
	{
		TArray<FString> WhitelistedLibs;
#ifdef VOICEWAKEUP_WHITELISTED_BINARIES
		const FString WhitelistedLibsDef(VOICEWAKEUP_WHITELISTED_BINARIES);
		WhitelistedLibsDef.ParseIntoArray(WhitelistedLibs, TEXT(";"));
#endif
		return WhitelistedLibs;
	}

	FString GetRuntimeLibDirectory()
	{
#if WITH_EDITOR
#ifdef VOICEWAKEUP_THIRDPARTY_BINARY_SUBDIR
		const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("VoiceWakeupSystem"));
		if (Plugin.IsValid())
		{
			return FPaths::Combine(
				Plugin->GetBaseDir(),
				TEXT("Source"),
				TEXT("Online"),
				TEXT("ThirdParty"),
				TEXT("VoiceWakeupSdk"),
				TEXT(VOICEWAKEUP_THIRDPARTY_BINARY_SUBDIR));
		}
#endif
#endif
		return FPaths::GetPath(FPlatformProcess::ExecutablePath());
	}
}

void FVoiceWakeupXfyunModule::StartupModule()
{
	LoadRuntimeLibraries();
	IModularFeatures::Get().RegisterModularFeature(IVoiceWakeupServiceFeatureInterface::GetFeatureName(), &GVoiceWakeupXfyunProvider);
	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupXfyun startup."));
}

void FVoiceWakeupXfyunModule::ShutdownModule()
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(IVoiceWakeupServiceFeatureInterface::GetFeatureName()))
	{
		IModularFeatures::Get().UnregisterModularFeature(IVoiceWakeupServiceFeatureInterface::GetFeatureName(), &GVoiceWakeupXfyunProvider);
	}

	UnloadRuntimeLibraries();
	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupXfyun shutdown."));
}

void FVoiceWakeupXfyunModule::LoadRuntimeLibraries()
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
			UE_LOG(LogVoiceWakeup, Verbose, TEXT("Loaded Xfyun runtime library: %s"), *RuntimeLib);
		}
		else
		{
			UE_LOG(LogVoiceWakeup, Warning, TEXT("Failed to load Xfyun runtime library: %s"), *FPaths::Combine(RuntimeLibDirectory, RuntimeLib));
		}
	}
	FPlatformProcess::PopDllDirectory(*RuntimeLibDirectory);
}

void FVoiceWakeupXfyunModule::UnloadRuntimeLibraries()
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

IMPLEMENT_MODULE(FVoiceWakeupXfyunModule, VoiceWakeupXfyun)
