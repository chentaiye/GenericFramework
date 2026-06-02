// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Startup/AuthorizationStartupGuard.h"

#include "Framework/Application/SlateApplication.h"
#include "HAL/PlatformMisc.h"
#include "Misc/CoreDelegates.h"
#include "Settings/AuthorizationSettings.h"
#include "Storage/AuthorizationLicenseStore.h"
#include "Support/AuthorizationUiProcessState.h"
#include "Subsystem/GenericAuthorizationSubsystem.h"
#include "Transport/AuthorizationCodec.h"
#include "UI/SAuthorizationActivationDialog.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/UObjectIterator.h"
#include "Verify/AuthorizationClockGuard.h"
#include "Verify/AuthorizationVerifier.h"
#include "Widgets/SWindow.h"

namespace AuthorizationStartupGuardPrivate
{
	bool IsBaseGrantAuthorized(const FAuthorizationLicenseToken& LicenseToken, const UAuthorizationSettings* Settings, FString& OutMessage)
	{
		const FAuthorizationGrant* BaseGrant = LicenseToken.FindGrant(Settings->BaseScopeId);
		if (BaseGrant == nullptr)
		{
			OutMessage = TEXT("基础包授权不存在。");
			return false;
		}

		if (BaseGrant->bRevoked)
		{
			OutMessage = TEXT("基础包授权已被撤销。");
			return false;
		}

		if (BaseGrant->IsExpired(FAuthorizationVerifier::GetCurrentUnixTimestamp(), Settings->GracePeriodSeconds))
		{
			OutMessage = TEXT("基础包授权已过期。");
			return false;
		}

		OutMessage.Empty();
		return true;
	}

	void ReloadExistingAuthorizationSubsystems()
	{
		for (TObjectIterator<UGenericAuthorizationSubsystem> It; It; ++It)
		{
			if (!IsValid(*It))
			{
				continue;
			}

			FString ReloadMessage;
			It->LoadAuthorizationState();
		}
	}

	void MarkExistingAuthorizationSubsystemsForExit()
	{
		for (TObjectIterator<UGenericAuthorizationSubsystem> It; It; ++It)
		{
			if (!IsValid(*It))
			{
				continue;
			}

			It->PrepareForAuthorizationExit();
		}
	}
}

void FAuthorizationStartupGuard::Startup()
{
	RegisterDelegates();
}

void FAuthorizationStartupGuard::Shutdown()
{
	CancelSlateWait();
	UnregisterDelegates();
}

void FAuthorizationStartupGuard::RegisterDelegates()
{
	PostEngineInitHandle = FCoreDelegates::OnPostEngineInit.AddRaw(this, &FAuthorizationStartupGuard::HandlePostEngineInit);
	PreLoadMapHandle = FCoreUObjectDelegates::PreLoadMap.AddRaw(this, &FAuthorizationStartupGuard::HandlePreLoadMap);
}

void FAuthorizationStartupGuard::UnregisterDelegates()
{
	if (PostEngineInitHandle.IsValid())
	{
		FCoreDelegates::OnPostEngineInit.Remove(PostEngineInitHandle);
		PostEngineInitHandle.Reset();
	}

	if (PreLoadMapHandle.IsValid())
	{
		FCoreUObjectDelegates::PreLoadMap.Remove(PreLoadMapHandle);
		PreLoadMapHandle.Reset();
	}
}

bool FAuthorizationStartupGuard::ShouldRunStartupGuard() const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	if (!Settings->bEnableAuthorization
		|| !Settings->bInterceptBeforeStartupMap
		|| !Settings->bAutoPromptForAuthorization
		|| IsRunningCommandlet()
		|| IsEngineExitRequested()
		|| bExitRequested
		|| AuthorizationUiProcessState::IsProcessExitRequested())
	{
		return false;
	}

#if WITH_EDITOR
	if (GIsEditor)
	{
		return false;
	}
#endif

	return true;
}

void FAuthorizationStartupGuard::HandlePostEngineInit()
{
	EnsureAuthorizedBeforeStartup(TEXT("PostEngineInit"));
}

void FAuthorizationStartupGuard::HandlePreLoadMap(const FString& MapName)
{
	UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization startup guard received PreLoadMap: %s"), *MapName);
	EnsureAuthorizedBeforeStartup(TEXT("PreLoadMap"));
}

bool FAuthorizationStartupGuard::TickWaitForSlate(const float DeltaTime)
{
	if (!ShouldRunStartupGuard() || bStartupCheckCompleted)
	{
		CancelSlateWait();
		return false;
	}

	if (!FSlateApplication::IsInitialized())
	{
		return true;
	}

	CancelSlateWait();
	EnsureAuthorizedBeforeStartup(TEXT("WaitForSlate"));
	return false;
}

bool FAuthorizationStartupGuard::EnsureAuthorizedBeforeStartup(const TCHAR* TriggerReason)
{
	if (!ShouldRunStartupGuard() || bStartupCheckCompleted || bPromptVisible)
	{
		return true;
	}

	FResolvedAuthorizationState State;
	FString Message;
	if (TryLoadAuthorization(State, Message))
	{
		bStartupCheckCompleted = true;
		AuthorizationUiProcessState::SetStartupPromptVisible(false);
		AuthorizationStartupGuardPrivate::ReloadExistingAuthorizationSubsystems();
		UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization startup guard accepted current package authorization. Trigger=%s Source=%d"), TriggerReason, static_cast<int32>(State.Source));
		return true;
	}

	UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization startup guard requires interactive authorization. Trigger=%s Message=%s"), TriggerReason, *Message);
	if (!FSlateApplication::IsInitialized())
	{
		ScheduleSlateWait();
		return false;
	}

	if (ShowBlockingAuthorizationPrompt())
	{
		bStartupCheckCompleted = true;
		AuthorizationUiProcessState::SetStartupPromptVisible(false);
		AuthorizationStartupGuardPrivate::ReloadExistingAuthorizationSubsystems();
		UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization startup guard completed interactive authorization. Trigger=%s"), TriggerReason);
		return true;
	}

	bStartupCheckCompleted = true;
	RequestProcessExit(TEXT("Authorization was cancelled before startup."));
	return false;
}

bool FAuthorizationStartupGuard::TryLoadAuthorization(FResolvedAuthorizationState& OutState, FString& OutMessage) const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	FAuthorizationManifest ProjectManifest;
	const FAuthorizationManifest* ProjectManifestPtr = LoadProjectManifest(ProjectManifest) ? &ProjectManifest : nullptr;

	TArray<EAuthorizationSourceType> SourcePriority;
	if (Settings->bPreferOnlineAuthorization)
	{
		SourcePriority.Add(EAuthorizationSourceType::Online);
		SourcePriority.Add(EAuthorizationSourceType::Offline);
	}
	else
	{
		SourcePriority.Add(EAuthorizationSourceType::Offline);
		SourcePriority.Add(EAuthorizationSourceType::Online);
	}

	for (const EAuthorizationSourceType Source : SourcePriority)
	{
		if (Source == EAuthorizationSourceType::Online)
		{
			if (Settings->bEnableOnlineAuthorization && Settings->bAutoLoadOnlineAuthorizationCache && TryLoadPersistedAuthorization(Source, ProjectManifestPtr, OutState, OutMessage))
			{
				return true;
			}
		}
		else
		{
			if (!Settings->bEnableOfflineAuthorization)
			{
				continue;
			}

			if (Settings->bAutoLoadOfflineAuthorizationCache && TryLoadPersistedAuthorization(Source, ProjectManifestPtr, OutState, OutMessage))
			{
				return true;
			}

			if (Settings->bAutoLoadOfflineLocalFiles && TryLoadBundledOfflineAuthorization(ProjectManifestPtr, OutState, OutMessage))
			{
				return true;
			}
		}
	}

	return false;
}

bool FAuthorizationStartupGuard::TryLoadPersistedAuthorization(const EAuthorizationSourceType Source, const FAuthorizationManifest* ProjectManifest, FResolvedAuthorizationState& OutState, FString& OutMessage) const
{
	OutState = FResolvedAuthorizationState();
	OutState.DeviceId = FAuthorizationVerifier::BuildCurrentDeviceId();
	OutState.PackageFingerprint = FAuthorizationVerifier::BuildCurrentPackageFingerprint();
	OutState.Source = Source;
	OutState.RuntimeState.CurrentDeviceId = OutState.DeviceId;
	OutState.RuntimeState.CurrentPackageFingerprint = OutState.PackageFingerprint;

	if (!FAuthorizationLicenseStore::LoadLicenseToken(OutState.LicenseToken, OutMessage, Source, UAuthorizationSettings::Get()))
	{
		return false;
	}

	FString RuntimeLoadError;
	if (FAuthorizationLicenseStore::LoadRuntimeState(OutState.RuntimeState, RuntimeLoadError, Source, UAuthorizationSettings::Get()))
	{
		OutState.RuntimeState.CurrentDeviceId = OutState.DeviceId;
		OutState.RuntimeState.CurrentPackageFingerprint = OutState.PackageFingerprint;
	}

	FString ManifestLoadError;
	if (FAuthorizationLicenseStore::LoadManifest(OutState.Manifest, ManifestLoadError, Source, UAuthorizationSettings::Get()))
	{
		OutState.bHasManifest = true;
	}
	else if (ProjectManifest != nullptr)
	{
		OutState.Manifest = *ProjectManifest;
		OutState.bHasManifest = true;
	}

	if (!ValidateResolvedAuthorization(OutState, OutMessage))
	{
		return false;
	}

	FString SaveRuntimeError;
	if (!FAuthorizationLicenseStore::SaveRuntimeState(OutState.RuntimeState, SaveRuntimeError, Source, UAuthorizationSettings::Get()))
	{
		UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization startup guard failed to save runtime state: %s"), *SaveRuntimeError);
	}

	return true;
}

bool FAuthorizationStartupGuard::TryLoadBundledOfflineAuthorization(const FAuthorizationManifest* ProjectManifest, FResolvedAuthorizationState& OutState, FString& OutMessage) const
{
	OutState = FResolvedAuthorizationState();
	OutState.DeviceId = FAuthorizationVerifier::BuildCurrentDeviceId();
	OutState.PackageFingerprint = FAuthorizationVerifier::BuildCurrentPackageFingerprint();
	OutState.Source = EAuthorizationSourceType::Offline;
	OutState.RuntimeState.CurrentDeviceId = OutState.DeviceId;
	OutState.RuntimeState.CurrentPackageFingerprint = OutState.PackageFingerprint;

	if (!FAuthorizationLicenseStore::LoadBundledOfflineLicenseToken(OutState.LicenseToken, OutMessage, UAuthorizationSettings::Get()))
	{
		return false;
	}

	FString RuntimeLoadError;
	if (FAuthorizationLicenseStore::LoadRuntimeState(OutState.RuntimeState, RuntimeLoadError, EAuthorizationSourceType::Offline, UAuthorizationSettings::Get()))
	{
		OutState.RuntimeState.CurrentDeviceId = OutState.DeviceId;
		OutState.RuntimeState.CurrentPackageFingerprint = OutState.PackageFingerprint;
	}

	FString ManifestLoadError;
	if (FAuthorizationLicenseStore::LoadBundledOfflineManifest(OutState.Manifest, ManifestLoadError, UAuthorizationSettings::Get()))
	{
		OutState.bHasManifest = true;
	}
	else if (ProjectManifest != nullptr)
	{
		OutState.Manifest = *ProjectManifest;
		OutState.bHasManifest = true;
	}

	if (!ValidateResolvedAuthorization(OutState, OutMessage))
	{
		return false;
	}

	if (UAuthorizationSettings::Get()->bPersistOfflineAuthorization)
	{
		PersistResolvedAuthorization(OutState, OutState.bHasManifest);
	}

	return true;
}

bool FAuthorizationStartupGuard::LoadProjectManifest(FAuthorizationManifest& OutManifest) const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	if (!Settings->bAutoLoadProjectManifest)
	{
		return false;
	}

	FString LoadError;
	if (!FAuthorizationLicenseStore::LoadProjectManifest(OutManifest, LoadError, Settings))
	{
		UE_LOG(GenericLogAuthorization, Verbose, TEXT("Authorization startup guard project manifest not loaded: %s"), *LoadError);
		return false;
	}

	return true;
}

bool FAuthorizationStartupGuard::ValidateResolvedAuthorization(FResolvedAuthorizationState& InOutState, FString& OutMessage) const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	if (InOutState.LicenseToken.IsEmpty())
	{
		OutMessage = TEXT("授权信息为空。");
		return false;
	}

	if (Settings->bEnableClockRollbackProtection && FAuthorizationClockGuard::IsClockRollbackDetected(FAuthorizationVerifier::GetCurrentUnixTimestamp(), InOutState.RuntimeState.LastTrustedUnixSeconds, Settings->AllowedClockRollbackSeconds))
	{
		OutMessage = TEXT("检测到本地时间回拨。");
		return false;
	}

	EAuthorizationState ValidationState = EAuthorizationState::Unauthorized;
	if (!FAuthorizationVerifier::VerifyLicenseToken(
		InOutState.LicenseToken,
		FAuthorizationVerifier::ResolveProductId(Settings),
		InOutState.DeviceId,
		InOutState.PackageFingerprint,
		Settings->VerificationKey,
		Settings->bRequireDeviceBinding,
		Settings->bRequirePackageBinding,
		ValidationState,
		OutMessage))
	{
		return false;
	}

	if (InOutState.bHasManifest)
	{
		EAuthorizationState ManifestState = EAuthorizationState::MissingManifest;
		if (!FAuthorizationVerifier::VerifyManifest(InOutState.Manifest, FAuthorizationVerifier::ResolveProductId(Settings), Settings->VerificationKey, Settings->bRequireManifestSignature, ManifestState, OutMessage))
		{
			return false;
		}
	}

	const FAuthorizationGrant* BaseGrant = InOutState.LicenseToken.FindGrant(Settings->BaseScopeId);
	if (BaseGrant == nullptr)
	{
		OutMessage = TEXT("Base authorization grant does not exist.");
		return false;
	}

	if (BaseGrant->bRevoked)
	{
		OutMessage = TEXT("Base authorization grant has been revoked.");
		return false;
	}

	if (!AuthorizationStartupGuardPrivate::IsBaseGrantAuthorized(InOutState.LicenseToken, Settings, OutMessage))
	{
		return false;
	}

	InOutState.RuntimeState.CurrentDeviceId = InOutState.DeviceId;
	InOutState.RuntimeState.CurrentPackageFingerprint = InOutState.PackageFingerprint;
	InOutState.RuntimeState.LastTrustedUnixSeconds = FAuthorizationClockGuard::UpdateTrustedUnixSeconds(FAuthorizationVerifier::GetCurrentUnixTimestamp(), InOutState.RuntimeState.LastTrustedUnixSeconds);
	OutMessage = TEXT("授权有效。");
	return true;
}

bool FAuthorizationStartupGuard::PersistResolvedAuthorization(const FResolvedAuthorizationState& State, const bool bPersistManifest) const
{
	FString PersistError;
	if (!FAuthorizationLicenseStore::SaveLicenseToken(State.LicenseToken, PersistError, State.Source, UAuthorizationSettings::Get()))
	{
		UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization startup guard failed to save license token: %s"), *PersistError);
		return false;
	}

	if (bPersistManifest && State.bHasManifest && !FAuthorizationLicenseStore::SaveManifest(State.Manifest, PersistError, State.Source, UAuthorizationSettings::Get()))
	{
		UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization startup guard failed to save manifest: %s"), *PersistError);
		return false;
	}

	if (!FAuthorizationLicenseStore::SaveRuntimeState(State.RuntimeState, PersistError, State.Source, UAuthorizationSettings::Get()))
	{
		UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization startup guard failed to save runtime state: %s"), *PersistError);
		return false;
	}

	return true;
}

bool FAuthorizationStartupGuard::ShowBlockingAuthorizationPrompt()
{
	if (!FSlateApplication::IsInitialized() || bPromptVisible)
	{
		return false;
	}

	bPromptVisible = true;
	AuthorizationUiProcessState::SetStartupPromptVisible(true);
	UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization startup guard shows blocking prompt."));
	const TSharedRef<SAuthorizationActivationDialog> DialogContent = SNew(SAuthorizationActivationDialog)
		.OnGetAuthorizationRequestCode(FAuthorizationRequestCodeGetter::CreateRaw(this, &FAuthorizationStartupGuard::BuildAuthorizationRequestCode))
		.OnSubmitLicenseCode(FAuthorizationLicenseSubmitter::CreateRaw(this, &FAuthorizationStartupGuard::SubmitLicenseCode));

	const TSharedRef<SWindow> DialogWindow = SNew(SWindow)
		.Title(FText::FromString(TEXT("授权验证")))
		.ClientSize(FVector2D(640.0f, 480.0f))
		.SupportsMinimize(false)
		.SupportsMaximize(false)
		.IsTopmostWindow(true)
		.FocusWhenFirstShown(true);

	DialogContent->SetOwnerWindow(DialogWindow);
	DialogWindow->SetContent(DialogContent);
	FSlateApplication::Get().AddModalWindow(DialogWindow, TSharedPtr<SWindow>(), false);
	bPromptVisible = false;
	AuthorizationUiProcessState::SetStartupPromptVisible(false);
	UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization startup guard prompt closed. Authorized=%d"), DialogContent->WasAuthorized() ? 1 : 0);

	return DialogContent->WasAuthorized();
}

FString FAuthorizationStartupGuard::BuildAuthorizationRequestCode() const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	return FAuthorizationCodec::BuildAuthorizationRequestCode(
		FAuthorizationVerifier::ResolveProductId(Settings),
		FAuthorizationVerifier::BuildCurrentDeviceId(),
		FAuthorizationVerifier::BuildCurrentPackageFingerprint(),
		Settings->VerificationKey);
}

bool FAuthorizationStartupGuard::SubmitLicenseCode(const FString& LicenseCode, FString& OutMessage)
{
	FString DecodedLicenseTokenText;
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	if (!FAuthorizationCodec::TryDecodeLicenseTokenInput(LicenseCode, Settings->VerificationKey, DecodedLicenseTokenText, OutMessage))
	{
		return false;
	}

	FResolvedAuthorizationState State;
	State.DeviceId = FAuthorizationVerifier::BuildCurrentDeviceId();
	State.PackageFingerprint = FAuthorizationVerifier::BuildCurrentPackageFingerprint();
	State.Source = EAuthorizationSourceType::Offline;
	State.RuntimeState.CurrentDeviceId = State.DeviceId;
	State.RuntimeState.CurrentPackageFingerprint = State.PackageFingerprint;

	if (!FAuthorizationVerifier::ParseLicenseToken(DecodedLicenseTokenText, State.LicenseToken, OutMessage))
	{
		return false;
	}

	FAuthorizationManifest ProjectManifest;
	if (LoadProjectManifest(ProjectManifest))
	{
		State.Manifest = ProjectManifest;
		State.bHasManifest = true;
	}

	if (!ValidateResolvedAuthorization(State, OutMessage))
	{
		return false;
	}

	if (!PersistResolvedAuthorization(State, false))
	{
		OutMessage = TEXT("授权已校验通过，但保存本地缓存失败。");
		return false;
	}

	OutMessage = TEXT("授权成功。");
	return true;
}

void FAuthorizationStartupGuard::ScheduleSlateWait()
{
	if (bSlateWaitScheduled)
	{
		return;
	}

	bSlateWaitScheduled = true;
	SlateWaitTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateRaw(this, &FAuthorizationStartupGuard::TickWaitForSlate), 0.0f);
}

void FAuthorizationStartupGuard::CancelSlateWait()
{
	if (!bSlateWaitScheduled)
	{
		return;
	}

	FTSTicker::GetCoreTicker().RemoveTicker(SlateWaitTickerHandle);
	SlateWaitTickerHandle.Reset();
	bSlateWaitScheduled = false;
}

void FAuthorizationStartupGuard::RequestProcessExit(const TCHAR* Reason)
{
	bExitRequested = true;
	bStartupCheckCompleted = true;
	bPromptVisible = false;
	CancelSlateWait();
	UnregisterDelegates();
	AuthorizationUiProcessState::SetStartupPromptVisible(false);
	AuthorizationUiProcessState::RequestProcessExit();
	AuthorizationStartupGuardPrivate::MarkExistingAuthorizationSubsystemsForExit();
	UE_LOG(GenericLogAuthorization, Warning, TEXT("%s"), Reason);
	FPlatformMisc::RequestExit(false);
}
