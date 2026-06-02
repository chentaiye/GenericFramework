// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/GenericAuthorizationSubsystem.h"

#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Framework/Application/IInputProcessor.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Notifications/NotificationManager.h"
#include "HAL/PlatformTime.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FileHelper.h"
#include "Provider/AuthorizationServiceFeature.h"
#include "Settings/AuthorizationSettings.h"
#include "Storage/AuthorizationLicenseStore.h"
#include "Support/AuthorizationUiProcessState.h"
#include "Transport/AuthorizationCodec.h"
#include "UI/SAuthorizationActivationDialog.h"
#include "Verify/AuthorizationClockGuard.h"
#include "Verify/AuthorizationVerifier.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/SWindow.h"

namespace
{
	constexpr int64 ShortAuthorizationDurationSeconds = 30 * 60;
	constexpr int64 MediumAuthorizationDurationSeconds = 2 * 60 * 60;
	constexpr int64 LongAuthorizationDurationSeconds = 24 * 60 * 60;

	int64 ResolveExpirationWarningLeadSeconds(const int64 GrantDurationSeconds, const UAuthorizationSettings* Settings)
	{
		if (GrantDurationSeconds <= ShortAuthorizationDurationSeconds)
		{
			return 0;
		}

		if (GrantDurationSeconds <= MediumAuthorizationDurationSeconds)
		{
			return ShortAuthorizationDurationSeconds;
		}

		if (GrantDurationSeconds <= LongAuthorizationDurationSeconds)
		{
			return MediumAuthorizationDurationSeconds;
		}

		return FMath::Max<int64>(0, Settings->ExpirationWarningLeadSeconds);
	}

	/** 监听授权到期通知的快捷键输入，把 Y/N 按键转发到续期或忽略回调。 */
	class FAuthorizationNotificationInputProcessor : public IInputProcessor
	{
	public:
		/** 保存通知按钮对应的处理回调，注册到 Slate 输入预处理链后由按键事件触发。 */
		FAuthorizationNotificationInputProcessor(TFunction<void()> InOnAccept, TFunction<void()> InOnDismiss)
			: OnAccept(MoveTemp(InOnAccept))
			, OnDismiss(MoveTemp(InOnDismiss))
		{
		}

		virtual void Tick(const float DeltaTime, FSlateApplication& SlateApplication, TSharedRef<ICursor> Cursor) override
		{
		}

		virtual bool HandleKeyDownEvent(FSlateApplication& SlateApplication, const FKeyEvent& InKeyEvent) override
		{
			if (InKeyEvent.GetKey() == EKeys::Y)
			{
				if (OnAccept)
				{
					OnAccept();
				}

				return true;
			}

			if (InKeyEvent.GetKey() == EKeys::N)
			{
				if (OnDismiss)
				{
					OnDismiss();
				}

				return true;
			}

			return false;
		}

	private:
		/** 授权到期提醒被接受时执行的回调，通常会打开重新授权窗口。 */
		TFunction<void()> OnAccept;

		/** 授权到期提醒被忽略时执行的回调，用于关闭通知并把本次提醒视为已处理。 */
		TFunction<void()> OnDismiss;
	};
}

UGenericAuthorizationSubsystem* UGenericAuthorizationSubsystem::Get(const UObject* WorldContextObject)
{
	if (WorldContextObject == nullptr)
	{
		return nullptr;
	}

	if (const UGameInstance* GameInstance = WorldContextObject->GetTypedOuter<UGameInstance>())
	{
		return GameInstance->GetSubsystem<UGenericAuthorizationSubsystem>();
	}

	if (GEngine == nullptr)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UGenericAuthorizationSubsystem>();
		}
	}

	return nullptr;
}

void UGenericAuthorizationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	CurrentDeviceId = FAuthorizationVerifier::BuildCurrentDeviceId();
	CurrentPackageFingerprint = FAuthorizationVerifier::BuildCurrentPackageFingerprint();
	RuntimeState.CurrentDeviceId = CurrentDeviceId;
	RuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
	UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization subsystem initialize. Device=%s Package=%s"), *CurrentDeviceId, *CurrentPackageFingerprint);
	LoadAuthorizationState();
	ScheduleAuthorizationMonitor();
	EvaluateAuthorizationLifecycle();
}

void UGenericAuthorizationSubsystem::Deinitialize()
{
	CancelScheduledAuthorizationPrompt();
	CancelAuthorizationMonitor();
	DismissExpirationWarningNotification(false);
	CloseReauthorizationWindow(false);
	SetAuthorizationPauseState(false);
	Super::Deinitialize();
}

void UGenericAuthorizationSubsystem::PrepareForAuthorizationExit()
{
	AuthorizationUiProcessState::RequestProcessExit();
	bAuthorizationExitPending = true;
	CancelScheduledAuthorizationPrompt();
	DismissExpirationWarningNotification(false);
	CloseReauthorizationWindow(false);
	SetAuthorizationPauseState(false);
	UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization subsystem prepared for process exit."));
}

bool UGenericAuthorizationSubsystem::LoadAuthorizationState()
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	ResetCurrentAuthorizationState(Settings->bAutoLoadProjectManifest);
	UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization load start. Enabled=%d PreferOnline=%d"), Settings->bEnableAuthorization ? 1 : 0, Settings->bPreferOnlineAuthorization ? 1 : 0);

	if (!Settings->bEnableAuthorization)
	{
		UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization disabled by settings."));
		return true;
	}

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
		FString LoadMessage;

		if (Source == EAuthorizationSourceType::Online)
		{
			if (Settings->bEnableOnlineAuthorization && Settings->bAutoLoadOnlineAuthorizationCache && TryLoadPersistedAuthorization(Source, LoadMessage))
			{
				UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization loaded from online cache."));
				return true;
			}
		}
		else if (Source == EAuthorizationSourceType::Offline && Settings->bEnableOfflineAuthorization)
		{
			if (Settings->bAutoLoadOfflineAuthorizationCache && TryLoadPersistedAuthorization(Source, LoadMessage))
			{
				UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization loaded from offline cache."));
				return true;
			}

			if (Settings->bAutoLoadOfflineLocalFiles && TryLoadBundledOfflineAuthorization(LoadMessage))
			{
				UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization loaded from offline bundled files."));
				return true;
			}
		}
	}

	if (ShouldPromptForAuthorization())
	{
		if (ShouldDeferAuthorizationPromptToStartupGuard())
		{
			UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization prompt is deferred to startup guard."));
		}
		else if (FSlateApplication::IsInitialized())
		{
			UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization missing. Show blocking prompt immediately."));
			ShowBlockingAuthorizationPrompt();
		}
		else
		{
			UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization missing. Slate not ready, schedule blocking prompt."));
			ScheduleAuthorizationPromptIfNeeded();
		}
	}

	EvaluateAuthorizationLifecycle();

	return true;
}

bool UGenericAuthorizationSubsystem::ImportLicenseTokenText(const FString& LicenseTokenText, FString& OutMessage, const bool bPersist)
{
	return ImportLicenseTokenTextInternal(LicenseTokenText, OutMessage, bPersist, EAuthorizationSourceType::Offline);
}

FString UGenericAuthorizationSubsystem::GetCurrentAuthorizationRequestCode() const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	return FAuthorizationCodec::BuildAuthorizationRequestCode(FAuthorizationVerifier::ResolveProductId(Settings), CurrentDeviceId, CurrentPackageFingerprint, Settings->VerificationKey);
}

bool UGenericAuthorizationSubsystem::ImportLicenseTokenFile(const FString& LicenseTokenFilePath, FString& OutMessage, const bool bPersist)
{
	return ImportLicenseTokenFileInternal(LicenseTokenFilePath, OutMessage, bPersist, EAuthorizationSourceType::Offline);
}

bool UGenericAuthorizationSubsystem::ImportManifestText(const FString& ManifestText, FString& OutMessage, const bool bPersist)
{
	return ImportManifestTextInternal(ManifestText, OutMessage, bPersist, EAuthorizationSourceType::Offline);
}

bool UGenericAuthorizationSubsystem::ImportManifestFile(const FString& ManifestFilePath, FString& OutMessage, const bool bPersist)
{
	return ImportManifestFileInternal(ManifestFilePath, OutMessage, bPersist, EAuthorizationSourceType::Offline);
}

bool UGenericAuthorizationSubsystem::ActivateWithProvider(FName ProviderName, const FString& AuthorizationCode, const FString& UserId, const FName RequestedScopeId, FString& OutMessage)
{
	IAuthorizationServiceFeatureInterface* Provider = ResolveProvider(ProviderName, true);
	if (Provider == nullptr)
	{
		OutMessage = TEXT("No authorization provider is available.");
		return false;
	}

	if (!Provider->SupportsActivation())
	{
		OutMessage = TEXT("The selected authorization provider does not support activation.");
		return false;
	}

	FAuthorizationActivationRequest Request;
	Request.ProductId = FAuthorizationVerifier::ResolveProductId(UAuthorizationSettings::Get());
	Request.DeviceId = CurrentDeviceId;
	Request.RequestedScopeId = RequestedScopeId;
	Request.AuthorizationCode = AuthorizationCode;
	Request.UserId = UserId;

	FAuthorizationServiceResponse Response;
	if (!Provider->Activate(Request, Response) || !Response.bSuccessful)
	{
		OutMessage = Response.Message.IsEmpty() ? TEXT("Authorization activation failed.") : Response.Message;
		return false;
	}

	const EAuthorizationSourceType Source = Provider->IsOnlineService() ? EAuthorizationSourceType::Online : EAuthorizationSourceType::Offline;

	FAuthorizationManifest ParsedManifest;
	FAuthorizationManifest* ParsedManifestPtr = nullptr;
	if (!Response.ManifestText.IsEmpty())
	{
		if (!FAuthorizationVerifier::ParseManifest(Response.ManifestText, ParsedManifest, OutMessage))
		{
			return false;
		}

		EAuthorizationState ManifestState = EAuthorizationState::MissingManifest;
		if (!FAuthorizationVerifier::VerifyManifest(ParsedManifest, FAuthorizationVerifier::ResolveProductId(UAuthorizationSettings::Get()), UAuthorizationSettings::Get()->VerificationKey, UAuthorizationSettings::Get()->bRequireManifestSignature, ManifestState, OutMessage))
		{
			return false;
		}

		ParsedManifestPtr = &ParsedManifest;
	}

	FAuthorizationLicenseToken ParsedToken;
	if (!FAuthorizationVerifier::ParseLicenseToken(Response.LicenseTokenText, ParsedToken, OutMessage))
	{
		return false;
	}

	FAuthorizationRuntimeState CandidateRuntimeState = RuntimeState;
	CandidateRuntimeState.CurrentDeviceId = CurrentDeviceId;
	CandidateRuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
	return ApplyAuthorizationState(ParsedToken, ParsedManifestPtr, CandidateRuntimeState, Source, OutMessage, Source == EAuthorizationSourceType::Online ? UAuthorizationSettings::Get()->bPersistOnlineAuthorization : UAuthorizationSettings::Get()->bPersistOfflineAuthorization, ParsedManifestPtr != nullptr, true);
}

bool UGenericAuthorizationSubsystem::RefreshAuthorization(FName ProviderName, FString& OutMessage)
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	IAuthorizationServiceFeatureInterface* Provider = ResolveProvider(ProviderName, true);

	if (Provider != nullptr && Provider->SupportsRefresh())
	{
		FAuthorizationRefreshRequest Request;
		Request.ProductId = FAuthorizationVerifier::ResolveProductId(Settings);
		Request.DeviceId = CurrentDeviceId;
		Request.CurrentLicenseToken = CurrentLicenseToken;
		Request.CurrentManifest = CurrentManifest;

		FAuthorizationServiceResponse Response;
		if (!Provider->Refresh(Request, Response) || !Response.bSuccessful)
		{
			OutMessage = Response.Message.IsEmpty() ? TEXT("Authorization refresh failed.") : Response.Message;
			return false;
		}

		FAuthorizationManifest ParsedManifest;
		FAuthorizationManifest* ParsedManifestPtr = nullptr;
		if (!Response.ManifestText.IsEmpty())
		{
			if (!FAuthorizationVerifier::ParseManifest(Response.ManifestText, ParsedManifest, OutMessage))
			{
				return false;
			}

			EAuthorizationState ManifestState = EAuthorizationState::MissingManifest;
			if (!FAuthorizationVerifier::VerifyManifest(ParsedManifest, FAuthorizationVerifier::ResolveProductId(Settings), Settings->VerificationKey, Settings->bRequireManifestSignature, ManifestState, OutMessage))
			{
				return false;
			}

			ParsedManifestPtr = &ParsedManifest;
		}

		FAuthorizationLicenseToken ParsedToken = CurrentLicenseToken;
		if (!Response.LicenseTokenText.IsEmpty())
		{
			if (!FAuthorizationVerifier::ParseLicenseToken(Response.LicenseTokenText, ParsedToken, OutMessage))
			{
				return false;
			}
		}

		FAuthorizationRuntimeState CandidateRuntimeState = RuntimeState;
		CandidateRuntimeState.CurrentDeviceId = CurrentDeviceId;
		CandidateRuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
		const EAuthorizationSourceType Source = Provider->IsOnlineService() ? EAuthorizationSourceType::Online : EAuthorizationSourceType::Offline;
		const bool bPersistSource = Source == EAuthorizationSourceType::Online ? Settings->bPersistOnlineAuthorization : Settings->bPersistOfflineAuthorization;

		if (!ApplyAuthorizationState(ParsedToken, ParsedManifestPtr, CandidateRuntimeState, Source, OutMessage, bPersistSource, ParsedManifestPtr != nullptr, true))
		{
			return false;
		}
	}

	const EAuthorizationState BaseState = GetBaseAppState();
	if (BaseState != EAuthorizationState::Authorized)
	{
		OutMessage = TEXT("Authorization cache is not currently valid.");
		return false;
	}

	RuntimeState.LastSuccessfulRefreshUnixSeconds = FAuthorizationVerifier::GetCurrentUnixTimestamp();
	UpdateTrustedClock();

	FString PersistError;
	if (CurrentAuthorizationSource != EAuthorizationSourceType::None && !FAuthorizationLicenseStore::SaveRuntimeState(RuntimeState, PersistError, CurrentAuthorizationSource, Settings))
	{
		OutMessage = PersistError;
		return false;
	}

	OutMessage = TEXT("Authorization refresh completed successfully.");
	return true;
}

bool UGenericAuthorizationSubsystem::ClearAuthorization(FString& OutMessage)
{
	ResetCurrentAuthorizationState(UAuthorizationSettings::Get()->bAutoLoadProjectManifest);

	FString DeleteError;
	if (!FAuthorizationLicenseStore::DeleteAllPersistedAuthorization(DeleteError, UAuthorizationSettings::Get()))
	{
		OutMessage = DeleteError;
		return false;
	}

	BroadcastLicenseStateChanges();
	BroadcastManifestChanged();
	DismissExpirationWarningNotification(false);
	CloseReauthorizationWindow(false);

	if (ShouldPromptForAuthorization())
	{
		if (FSlateApplication::IsInitialized())
		{
			ShowBlockingAuthorizationPrompt();
		}
		else
		{
			ScheduleAuthorizationPromptIfNeeded();
		}
	}

	OutMessage = TEXT("Authorization cache was cleared.");
	return true;
}

bool UGenericAuthorizationSubsystem::IsBaseAppAuthorized() const
{
	return GetBaseAppState() == EAuthorizationState::Authorized;
}

EAuthorizationState UGenericAuthorizationSubsystem::GetBaseAppState() const
{
	return GetScopeState(UAuthorizationSettings::Get()->BaseScopeId);
}

bool UGenericAuthorizationSubsystem::IsScopeAuthorized(const FName ScopeId) const
{
	return GetScopeState(ScopeId) == EAuthorizationState::Authorized;
}

EAuthorizationState UGenericAuthorizationSubsystem::GetScopeState(const FName ScopeId) const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	if (!Settings->bEnableAuthorization)
	{
		return EAuthorizationState::Authorized;
	}

	const EAuthorizationState GlobalState = GetGlobalAuthorizationState();
	if (GlobalState != EAuthorizationState::Authorized)
	{
		return GlobalState;
	}

	const FAuthorizationGrant* Grant = CurrentLicenseToken.FindGrant(ScopeId);
	if (Grant == nullptr)
	{
		return EAuthorizationState::Unauthorized;
	}

	if (Grant->bRevoked)
	{
		return EAuthorizationState::Revoked;
	}

	if (Grant->IsExpired(FAuthorizationVerifier::GetCurrentUnixTimestamp(), Settings->GracePeriodSeconds))
	{
		return EAuthorizationState::Expired;
	}

	return EAuthorizationState::Authorized;
}

bool UGenericAuthorizationSubsystem::NeedsReauthorization(const FName ScopeId) const
{
	const EAuthorizationState State = GetScopeState(ScopeId);
	return State == EAuthorizationState::Expired || State == EAuthorizationState::Unauthorized || State == EAuthorizationState::Revoked;
}

bool UGenericAuthorizationSubsystem::CanMountPakFile(const FString& PakFilePath, FName& OutScopeId, EAuthorizationState& OutState) const
{
	OutScopeId = NAME_None;
	OutState = EAuthorizationState::MissingManifest;

	if (!UAuthorizationSettings::Get()->bEnableAuthorization)
	{
		OutState = EAuthorizationState::Authorized;
		return true;
	}

	if (CurrentManifest.IsEmpty())
	{
		return false;
	}

	for (const FAuthorizationManifestScope& Scope : CurrentManifest.Scopes)
	{
		for (const FString& DeclaredPakFile : Scope.PakFiles)
		{
			if (FAuthorizationVerifier::MatchesContentPath(DeclaredPakFile, PakFilePath))
			{
				OutScopeId = Scope.ScopeId;
				OutState = Scope.bRequiresAuthorization ? GetScopeState(Scope.ScopeId) : EAuthorizationState::Authorized;
				return OutState == EAuthorizationState::Authorized;
			}
		}
	}

	OutState = EAuthorizationState::Unauthorized;
	return false;
}

bool UGenericAuthorizationSubsystem::ApplyAuthorizationState(const FAuthorizationLicenseToken& InLicenseToken, const FAuthorizationManifest* InManifest, const FAuthorizationRuntimeState& InRuntimeState, const EAuthorizationSourceType InSource, FString& OutMessage, const bool bPersistToken, const bool bPersistManifest, const bool bPersistRuntime)
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	const FAuthorizationLicenseToken PreviousLicenseToken = CurrentLicenseToken;
	const FAuthorizationManifest PreviousManifest = CurrentManifest;
	const FAuthorizationRuntimeState PreviousRuntimeState = RuntimeState;
	const EAuthorizationSourceType PreviousSource = CurrentAuthorizationSource;

	RuntimeState = InRuntimeState;
	RuntimeState.CurrentDeviceId = CurrentDeviceId;
	RuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
	CurrentLicenseToken = InLicenseToken;
	CurrentAuthorizationSource = InSource;

	if (InManifest != nullptr && !InManifest->IsEmpty())
	{
		CurrentManifest = *InManifest;
	}

	const EAuthorizationState ValidationState = GetGlobalAuthorizationState(&OutMessage);
	if (ValidationState != EAuthorizationState::Authorized)
	{
		CurrentLicenseToken = PreviousLicenseToken;
		CurrentManifest = PreviousManifest;
		RuntimeState = PreviousRuntimeState;
		CurrentAuthorizationSource = PreviousSource;
		return false;
	}

	UpdateTrustedClock();

	if (bPersistToken && InSource != EAuthorizationSourceType::None)
	{
		FString PersistError;
		if (!FAuthorizationLicenseStore::SaveLicenseToken(CurrentLicenseToken, PersistError, InSource, Settings))
		{
			OutMessage = PersistError;
			CurrentLicenseToken = PreviousLicenseToken;
			CurrentManifest = PreviousManifest;
			RuntimeState = PreviousRuntimeState;
			CurrentAuthorizationSource = PreviousSource;
			return false;
		}
	}

	if (bPersistManifest && InSource != EAuthorizationSourceType::None && !CurrentManifest.IsEmpty())
	{
		FString PersistError;
		if (!FAuthorizationLicenseStore::SaveManifest(CurrentManifest, PersistError, InSource, Settings))
		{
			OutMessage = PersistError;
			CurrentLicenseToken = PreviousLicenseToken;
			CurrentManifest = PreviousManifest;
			RuntimeState = PreviousRuntimeState;
			CurrentAuthorizationSource = PreviousSource;
			return false;
		}
	}

	if (bPersistRuntime && InSource != EAuthorizationSourceType::None)
	{
		FString PersistError;
		if (!FAuthorizationLicenseStore::SaveRuntimeState(RuntimeState, PersistError, InSource, Settings))
		{
			OutMessage = PersistError;
			CurrentLicenseToken = PreviousLicenseToken;
			CurrentManifest = PreviousManifest;
			RuntimeState = PreviousRuntimeState;
			CurrentAuthorizationSource = PreviousSource;
			return false;
		}
	}

	BroadcastLicenseStateChanges();
	BroadcastManifestChanged();
	EvaluateAuthorizationLifecycle();
	OutMessage = TEXT("Authorization state was applied successfully.");
	return true;
}

bool UGenericAuthorizationSubsystem::ImportLicenseTokenTextInternal(const FString& LicenseTokenText, FString& OutMessage, const bool bPersist, const EAuthorizationSourceType InSource)
{
	FString DecodedLicenseTokenText;
	if (!FAuthorizationCodec::TryDecodeLicenseTokenInput(LicenseTokenText, UAuthorizationSettings::Get()->VerificationKey, DecodedLicenseTokenText, OutMessage))
	{
		return false;
	}

	FAuthorizationLicenseToken ParsedToken;
	if (!FAuthorizationVerifier::ParseLicenseToken(DecodedLicenseTokenText, ParsedToken, OutMessage))
	{
		return false;
	}

	FAuthorizationRuntimeState CandidateRuntimeState = RuntimeState;
	CandidateRuntimeState.CurrentDeviceId = CurrentDeviceId;
	CandidateRuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
	return ApplyAuthorizationState(ParsedToken, nullptr, CandidateRuntimeState, InSource, OutMessage, bPersist, false, bPersist);
}

bool UGenericAuthorizationSubsystem::ImportLicenseTokenFileInternal(const FString& LicenseTokenFilePath, FString& OutMessage, const bool bPersist, const EAuthorizationSourceType InSource)
{
	FString FileText;
	if (!FFileHelper::LoadFileToString(FileText, *LicenseTokenFilePath))
	{
		OutMessage = FString::Printf(TEXT("Failed to load authorization license token file: %s"), *LicenseTokenFilePath);
		return false;
	}

	return ImportLicenseTokenTextInternal(FileText, OutMessage, bPersist, InSource);
}

bool UGenericAuthorizationSubsystem::ImportManifestTextInternal(const FString& ManifestText, FString& OutMessage, const bool bPersist, const EAuthorizationSourceType InSource)
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();

	FAuthorizationManifest ParsedManifest;
	if (!FAuthorizationVerifier::ParseManifest(ManifestText, ParsedManifest, OutMessage))
	{
		return false;
	}

	EAuthorizationState ValidationState = EAuthorizationState::MissingManifest;
	if (!FAuthorizationVerifier::VerifyManifest(ParsedManifest, FAuthorizationVerifier::ResolveProductId(Settings), Settings->VerificationKey, Settings->bRequireManifestSignature, ValidationState, OutMessage))
	{
		return false;
	}

	CurrentManifest = ParsedManifest;

	if (bPersist && InSource != EAuthorizationSourceType::None)
	{
		FString PersistError;
		if (!FAuthorizationLicenseStore::SaveManifest(CurrentManifest, PersistError, InSource, Settings))
		{
			OutMessage = PersistError;
			return false;
		}
	}

	BroadcastManifestChanged();
	OutMessage = TEXT("Authorization manifest imported successfully.");
	return true;
}

bool UGenericAuthorizationSubsystem::ImportManifestFileInternal(const FString& ManifestFilePath, FString& OutMessage, const bool bPersist, const EAuthorizationSourceType InSource)
{
	FString FileText;
	if (!FFileHelper::LoadFileToString(FileText, *ManifestFilePath))
	{
		OutMessage = FString::Printf(TEXT("Failed to load authorization manifest file: %s"), *ManifestFilePath);
		return false;
	}

	return ImportManifestTextInternal(FileText, OutMessage, bPersist, InSource);
}

bool UGenericAuthorizationSubsystem::TryLoadPersistedAuthorization(const EAuthorizationSourceType InSource, FString& OutMessage)
{
	FAuthorizationLicenseToken LoadedToken;
	if (!FAuthorizationLicenseStore::LoadLicenseToken(LoadedToken, OutMessage, InSource, UAuthorizationSettings::Get()))
	{
		return false;
	}

	FAuthorizationRuntimeState LoadedRuntimeState = RuntimeState;
	FString RuntimeLoadError;
	if (FAuthorizationLicenseStore::LoadRuntimeState(LoadedRuntimeState, RuntimeLoadError, InSource, UAuthorizationSettings::Get()))
	{
		LoadedRuntimeState.CurrentDeviceId = CurrentDeviceId;
		LoadedRuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
	}
	else
	{
		LoadedRuntimeState = RuntimeState;
	}

	FAuthorizationManifest LoadedManifest;
	FAuthorizationManifest* LoadedManifestPtr = nullptr;
	FString ManifestLoadError;
	if (FAuthorizationLicenseStore::LoadManifest(LoadedManifest, ManifestLoadError, InSource, UAuthorizationSettings::Get()))
	{
		LoadedManifestPtr = &LoadedManifest;
	}

	return ApplyAuthorizationState(LoadedToken, LoadedManifestPtr, LoadedRuntimeState, InSource, OutMessage, false, false, true);
}

bool UGenericAuthorizationSubsystem::TryLoadBundledOfflineAuthorization(FString& OutMessage)
{
	FAuthorizationLicenseToken LoadedToken;
	if (!FAuthorizationLicenseStore::LoadBundledOfflineLicenseToken(LoadedToken, OutMessage, UAuthorizationSettings::Get()))
	{
		return false;
	}

	FAuthorizationRuntimeState LoadedRuntimeState = RuntimeState;
	FString RuntimeLoadError;
	if (FAuthorizationLicenseStore::LoadRuntimeState(LoadedRuntimeState, RuntimeLoadError, EAuthorizationSourceType::Offline, UAuthorizationSettings::Get()))
	{
		LoadedRuntimeState.CurrentDeviceId = CurrentDeviceId;
		LoadedRuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
	}
	else
	{
		LoadedRuntimeState = RuntimeState;
	}

	FAuthorizationManifest LoadedManifest;
	FAuthorizationManifest* LoadedManifestPtr = nullptr;
	FString ManifestLoadError;
	if (FAuthorizationLicenseStore::LoadBundledOfflineManifest(LoadedManifest, ManifestLoadError, UAuthorizationSettings::Get()))
	{
		LoadedManifestPtr = &LoadedManifest;
	}

	const bool bPersistOfflineAuthorization = UAuthorizationSettings::Get()->bPersistOfflineAuthorization;
	return ApplyAuthorizationState(LoadedToken, LoadedManifestPtr, LoadedRuntimeState, EAuthorizationSourceType::Offline, OutMessage, bPersistOfflineAuthorization, bPersistOfflineAuthorization && LoadedManifestPtr != nullptr, true);
}

bool UGenericAuthorizationSubsystem::IsAuthorizationSourceEnabled(const EAuthorizationSourceType InSource) const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();

	switch (InSource)
	{
	case EAuthorizationSourceType::Online:
		return Settings->bEnableAuthorization && Settings->bEnableOnlineAuthorization;

	case EAuthorizationSourceType::Offline:
		return Settings->bEnableAuthorization && Settings->bEnableOfflineAuthorization;

	default:
		return Settings->bEnableAuthorization;
	}
}

bool UGenericAuthorizationSubsystem::ShouldPromptForAuthorization() const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	if (!Settings->bEnableAuthorization || !Settings->bAutoPromptForAuthorization || ShouldSuppressAuthorizationUi())
	{
		return false;
	}

#if WITH_EDITOR
	if (GIsEditor)
	{
		if (const UGameInstance* ResolvedGameInstance = Cast<UGameInstance>(GetOuter()))
		{
			if (const UWorld* World = ResolvedGameInstance->GetWorld())
			{
				if (World->WorldType == EWorldType::PIE || World->WorldType == EWorldType::EditorPreview)
				{
					return false;
				}
			}
		}
	}
#endif

	const EAuthorizationState BaseState = GetBaseAppState();
	return BaseState != EAuthorizationState::Authorized;
}

bool UGenericAuthorizationSubsystem::TickDeferredAuthorizationPrompt(const float DeltaTime)
{
	if (!ShouldPromptForAuthorization())
	{
		CancelScheduledAuthorizationPrompt();
		return false;
	}

	if (!FSlateApplication::IsInitialized())
	{
		return true;
	}

	CancelScheduledAuthorizationPrompt();
	ShowBlockingAuthorizationPrompt();
	return false;
}

void UGenericAuthorizationSubsystem::ScheduleAuthorizationPromptIfNeeded()
{
	if (!ShouldPromptForAuthorization() || bAuthorizationPromptScheduled)
	{
		return;
	}

	bAuthorizationPromptScheduled = true;
	AuthorizationPromptTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UGenericAuthorizationSubsystem::TickDeferredAuthorizationPrompt), 0.0f);
}

void UGenericAuthorizationSubsystem::CancelScheduledAuthorizationPrompt()
{
	if (bAuthorizationPromptScheduled)
	{
		FTSTicker::GetCoreTicker().RemoveTicker(AuthorizationPromptTickerHandle);
		bAuthorizationPromptScheduled = false;
		AuthorizationPromptTickerHandle = FTSTicker::FDelegateHandle();
	}
}

void UGenericAuthorizationSubsystem::ShowBlockingAuthorizationPrompt()
{
	if (!ShouldPromptForAuthorization() || !FSlateApplication::IsInitialized() || ShouldSuppressAuthorizationUi())
	{
		return;
	}

	const TSharedRef<SAuthorizationActivationDialog> DialogContent = SNew(SAuthorizationActivationDialog)
		.OnGetAuthorizationRequestCode(FAuthorizationRequestCodeGetter::CreateUObject(this, &UGenericAuthorizationSubsystem::GetCurrentAuthorizationRequestCode))
		.OnSubmitLicenseCode(FAuthorizationLicenseSubmitter::CreateUObject(this, &UGenericAuthorizationSubsystem::SubmitLicenseCodeFromPrompt));

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

	if (!DialogContent->WasAuthorized() && ShouldPromptForAuthorization() && UAuthorizationSettings::Get()->bExitIfAuthorizationPromptCancelled)
	{
		PrepareForAuthorizationExit();
		UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization prompt cancelled. Request exit."));
		FPlatformMisc::RequestExit(false);
	}
}

bool UGenericAuthorizationSubsystem::ShouldDeferAuthorizationPromptToStartupGuard() const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	if (!Settings->bInterceptBeforeStartupMap || IsRunningCommandlet())
	{
		return false;
	}

#if WITH_EDITOR
	if (GIsEditor)
	{
		return false;
	}
#endif

	const UWorld* World = GetActiveAuthorizationWorld();
	return World == nullptr || !World->HasBegunPlay();
}

bool UGenericAuthorizationSubsystem::ShouldSuppressAuthorizationUi() const
{
	return bAuthorizationExitPending
		|| AuthorizationUiProcessState::IsProcessExitRequested()
		|| AuthorizationUiProcessState::IsStartupPromptVisible()
		|| IsEngineExitRequested();
}

void UGenericAuthorizationSubsystem::ResetCurrentAuthorizationState(const bool bLoadProjectManifest)
{
	CurrentDeviceId = FAuthorizationVerifier::BuildCurrentDeviceId();
	CurrentPackageFingerprint = FAuthorizationVerifier::BuildCurrentPackageFingerprint();
	RuntimeState = FAuthorizationRuntimeState();
	RuntimeState.CurrentDeviceId = CurrentDeviceId;
	RuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
	CurrentLicenseToken.Reset();
	CurrentManifest.Reset();
	CurrentAuthorizationSource = EAuthorizationSourceType::None;

	if (bLoadProjectManifest)
	{
		FString LoadError;
		FAuthorizationManifest ProjectManifest;
		if (FAuthorizationLicenseStore::LoadProjectManifest(ProjectManifest, LoadError, UAuthorizationSettings::Get()))
		{
			CurrentManifest = ProjectManifest;
		}
	}
}

EAuthorizationState UGenericAuthorizationSubsystem::GetGlobalAuthorizationState(FString* OutMessage) const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();

	if (!Settings->bEnableAuthorization)
	{
		if (OutMessage != nullptr)
		{
			OutMessage->Empty();
		}

		return EAuthorizationState::Authorized;
	}

	if (CurrentLicenseToken.IsEmpty())
	{
		if (OutMessage != nullptr)
		{
			*OutMessage = TEXT("Authorization license token is not loaded.");
		}

		return EAuthorizationState::Unauthorized;
	}

	if (Settings->bEnableClockRollbackProtection && FAuthorizationClockGuard::IsClockRollbackDetected(FAuthorizationVerifier::GetCurrentUnixTimestamp(), RuntimeState.LastTrustedUnixSeconds, Settings->AllowedClockRollbackSeconds))
	{
		if (OutMessage != nullptr)
		{
			*OutMessage = TEXT("Local clock rollback was detected.");
		}

		return EAuthorizationState::ClockRollback;
	}

	EAuthorizationState ValidationState = EAuthorizationState::Unauthorized;
	FString ValidationMessage;
	if (!FAuthorizationVerifier::VerifyLicenseToken(CurrentLicenseToken, FAuthorizationVerifier::ResolveProductId(Settings), CurrentDeviceId, CurrentPackageFingerprint, Settings->VerificationKey, Settings->bRequireDeviceBinding, Settings->bRequirePackageBinding, ValidationState, ValidationMessage))
	{
		if (OutMessage != nullptr)
		{
			*OutMessage = ValidationMessage;
		}

		return ValidationState;
	}

	if (!CurrentManifest.IsEmpty())
	{
		EAuthorizationState ManifestState = EAuthorizationState::MissingManifest;
		FString ManifestMessage;
		if (!FAuthorizationVerifier::VerifyManifest(CurrentManifest, FAuthorizationVerifier::ResolveProductId(Settings), Settings->VerificationKey, Settings->bRequireManifestSignature, ManifestState, ManifestMessage))
		{
			if (OutMessage != nullptr)
			{
				*OutMessage = ManifestMessage;
			}

			return ManifestState;
		}
	}

	if (OutMessage != nullptr)
	{
		OutMessage->Empty();
	}

	return EAuthorizationState::Authorized;
}

IAuthorizationServiceFeatureInterface* UGenericAuthorizationSubsystem::ResolveProvider(FName ProviderName, const bool bPreferOnline) const
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	FName ResolvedProviderName = ProviderName;

	if (ResolvedProviderName.IsNone())
	{
		const TArray<FName> CandidateProviderNames =
		{
			bPreferOnline ? Settings->PreferredOnlineProvider : Settings->PreferredOfflineProvider,
			bPreferOnline ? Settings->PreferredOfflineProvider : Settings->PreferredOnlineProvider
		};

		for (const FName CandidateProviderName : CandidateProviderNames)
		{
			if (CandidateProviderName.IsNone())
			{
				continue;
			}

			if (IAuthorizationServiceFeatureInterface* Feature = IAuthorizationServiceFeatureInterface::FindFeatureByName(CandidateProviderName))
			{
				if (!Feature->IsOnlineService() && !IsAuthorizationSourceEnabled(EAuthorizationSourceType::Offline))
				{
					continue;
				}

				if (Feature->IsOnlineService() && !IsAuthorizationSourceEnabled(EAuthorizationSourceType::Online))
				{
					continue;
				}

				return Feature;
			}
		}
	}
	else
	{
		if (IAuthorizationServiceFeatureInterface* Feature = IAuthorizationServiceFeatureInterface::FindFeatureByName(ResolvedProviderName))
		{
			if (Feature->IsOnlineService() && !IsAuthorizationSourceEnabled(EAuthorizationSourceType::Online))
			{
				return nullptr;
			}

			if (!Feature->IsOnlineService() && !IsAuthorizationSourceEnabled(EAuthorizationSourceType::Offline))
			{
				return nullptr;
			}

			return Feature;
		}

		return nullptr;
	}

	for (IAuthorizationServiceFeatureInterface* Feature : IAuthorizationServiceFeatureInterface::GetAvailableFeatures())
	{
		if (Feature == nullptr || Feature->IsOnlineService() != bPreferOnline)
		{
			continue;
		}

		if (Feature->IsOnlineService() && !IsAuthorizationSourceEnabled(EAuthorizationSourceType::Online))
		{
			continue;
		}

		if (!Feature->IsOnlineService() && !IsAuthorizationSourceEnabled(EAuthorizationSourceType::Offline))
		{
			continue;
		}

		return Feature;
	}

	for (IAuthorizationServiceFeatureInterface* Feature : IAuthorizationServiceFeatureInterface::GetAvailableFeatures())
	{
		if (Feature == nullptr || Feature->IsOnlineService() == bPreferOnline)
		{
			continue;
		}

		if (Feature->IsOnlineService() && !IsAuthorizationSourceEnabled(EAuthorizationSourceType::Online))
		{
			continue;
		}

		if (!Feature->IsOnlineService() && !IsAuthorizationSourceEnabled(EAuthorizationSourceType::Offline))
		{
			continue;
		}

		return Feature;
	}

	return nullptr;
}

const FAuthorizationGrant* UGenericAuthorizationSubsystem::GetBaseGrant() const
{
	return CurrentLicenseToken.FindGrant(UAuthorizationSettings::Get()->BaseScopeId);
}

FString UGenericAuthorizationSubsystem::BuildBaseGrantTrackingKey() const
{
	const FAuthorizationGrant* BaseGrant = GetBaseGrant();
	if (BaseGrant == nullptr)
	{
		return FString();
	}

	return CurrentLicenseToken.LicenseId
		+ TEXT("|")
		+ BaseGrant->ScopeId.ToString()
		+ TEXT("|")
		+ LexToString(BaseGrant->ExpireAtUnixSeconds)
		+ TEXT("|")
		+ LexToString(static_cast<uint8>(BaseGrant->GrantType));
}

int64 UGenericAuthorizationSubsystem::GetBaseGrantRemainingSeconds() const
{
	const FAuthorizationGrant* BaseGrant = GetBaseGrant();
	if (BaseGrant == nullptr)
	{
		return 0;
	}

	if (BaseGrant->IsPermanent())
	{
		return MAX_int64;
	}

	return BaseGrant->ExpireAtUnixSeconds - FAuthorizationVerifier::GetCurrentUnixTimestamp();
}

bool UGenericAuthorizationSubsystem::TickAuthorizationMonitor(const float DeltaTime)
{
	if (ShouldSuppressAuthorizationUi())
	{
		DismissExpirationWarningNotification(false);
		CloseReauthorizationWindow(false);
		SetAuthorizationPauseState(false);
		return true;
	}

	if (!UAuthorizationSettings::Get()->bEnableAuthorization)
	{
		return true;
	}

	if (ExpirationWarningNotification.IsValid() && ExpirationWarningDismissAtSeconds > 0.0 && FPlatformTime::Seconds() >= ExpirationWarningDismissAtSeconds)
	{
		DismissExpirationWarningNotification(true);
	}

	EvaluateAuthorizationLifecycle();
	return true;
}

void UGenericAuthorizationSubsystem::ScheduleAuthorizationMonitor()
{
	if (bAuthorizationMonitorScheduled)
	{
		return;
	}

	bAuthorizationMonitorScheduled = true;
	AuthorizationMonitorTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UGenericAuthorizationSubsystem::TickAuthorizationMonitor), 1.0f);
}

void UGenericAuthorizationSubsystem::CancelAuthorizationMonitor()
{
	if (!bAuthorizationMonitorScheduled)
	{
		return;
	}

	FTSTicker::GetCoreTicker().RemoveTicker(AuthorizationMonitorTickerHandle);
	AuthorizationMonitorTickerHandle.Reset();
	bAuthorizationMonitorScheduled = false;
}

void UGenericAuthorizationSubsystem::EvaluateAuthorizationLifecycle()
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	if (ShouldSuppressAuthorizationUi())
	{
		DismissExpirationWarningNotification(false);
		CloseReauthorizationWindow(false);
		SetAuthorizationPauseState(false);
		return;
	}

	if (!Settings->bEnableAuthorization)
	{
		DismissExpirationWarningNotification(false);
		CloseReauthorizationWindow(false);
		SetAuthorizationPauseState(false);
		return;
	}

	const EAuthorizationState BaseState = GetBaseAppState();
	if (BaseState == EAuthorizationState::Authorized)
	{
		bAuthorizationExitPending = false;
		SetAuthorizationPauseState(false);

		if (bReauthorizationWindowVisible && !bReauthorizationWindowOpenedWhileAuthorized)
		{
			CloseReauthorizationWindow(false);
		}

		if (!Settings->bEnableExpirationWarning)
		{
			DismissExpirationWarningNotification(false);
			return;
		}

		const FAuthorizationGrant* BaseGrant = GetBaseGrant();
		if (BaseGrant == nullptr || BaseGrant->IsPermanent())
		{
			DismissExpirationWarningNotification(false);
			LastExpirationWarningGrantKey.Empty();
			return;
		}

		const int64 GrantDurationSeconds = FMath::Max<int64>(0, BaseGrant->ExpireAtUnixSeconds - BaseGrant->IssuedAtUnixSeconds);
		const int64 WarningLeadSeconds = ResolveExpirationWarningLeadSeconds(GrantDurationSeconds, Settings);
		if (WarningLeadSeconds <= 0)
		{
			DismissExpirationWarningNotification(false);
			LastExpirationWarningGrantKey.Empty();
			return;
		}

		const int64 RemainingSeconds = GetBaseGrantRemainingSeconds();
		if (RemainingSeconds > 0 && RemainingSeconds <= WarningLeadSeconds)
		{
			const FString GrantTrackingKey = BuildBaseGrantTrackingKey();
			if (!GrantTrackingKey.IsEmpty() && !GrantTrackingKey.Equals(LastExpirationWarningGrantKey, ESearchCase::CaseSensitive))
			{
				ShowExpirationWarningNotification(RemainingSeconds);
			}
		}
		else
		{
			DismissExpirationWarningNotification(false);
			if (RemainingSeconds > WarningLeadSeconds)
			{
				LastExpirationWarningGrantKey.Empty();
			}
		}

		return;
	}

	DismissExpirationWarningNotification(true);

	if (BaseState == EAuthorizationState::Expired)
	{
		if (ShouldDeferAuthorizationPromptToStartupGuard())
		{
			SetAuthorizationPauseState(false);
			return;
		}

		const bool bPauseGameplay = CanPauseGameplayForExpiredAuthorization();
		SetAuthorizationPauseState(bPauseGameplay);
		UE_LOG(
			GenericLogAuthorization,
			Log,
			TEXT("Authorization expired. PauseGameplay=%d ReauthorizationWindowWillExitIfClosed=1"),
			bPauseGameplay ? 1 : 0);
		ShowReauthorizationWindow(true);
		return;
	}

	SetAuthorizationPauseState(false);

	if (BaseState != EAuthorizationState::Authorized)
	{
		CloseReauthorizationWindow(false);
	}
}

FString UGenericAuthorizationSubsystem::FormatRemainingLifetime(const int64 RemainingSeconds) const
{
	if (RemainingSeconds <= 0)
	{
		return TEXT("不到 1 分钟");
	}

	int64 Remaining = RemainingSeconds;
	const int64 Days = Remaining / 86400;
	Remaining %= 86400;
	const int64 Hours = Remaining / 3600;
	Remaining %= 3600;
	const int64 Minutes = Remaining / 60;

	TArray<FString> Segments;
	if (Days > 0)
	{
		Segments.Add(FString::Printf(TEXT("%lld天"), Days));
	}

	if (Hours > 0)
	{
		Segments.Add(FString::Printf(TEXT("%lld小时"), Hours));
	}

	if (Minutes > 0)
	{
		Segments.Add(FString::Printf(TEXT("%lld分钟"), Minutes));
	}

	if (Segments.IsEmpty())
	{
		return TEXT("不到 1 分钟");
	}

	return FString::Join(Segments, TEXT(""));
}

void UGenericAuthorizationSubsystem::ShowExpirationWarningNotification(const int64 RemainingSeconds)
{
	if (!FSlateApplication::IsInitialized())
	{
		return;
	}

	DismissExpirationWarningNotification(false);

	const FString GrantTrackingKey = BuildBaseGrantTrackingKey();
	if (GrantTrackingKey.IsEmpty())
	{
		return;
	}

	const FString WarningMessage = FString::Printf(TEXT("当前授权将在 %s 后过期。按 Y 立即续期，按 N 暂时忽略。"), *FormatRemainingLifetime(RemainingSeconds));
	FNotificationInfo Info(FText::FromString(WarningMessage));
	Info.bFireAndForget = false;
	Info.ExpireDuration = 60.0f;
	Info.FadeOutDuration = 0.2f;
	Info.bUseSuccessFailIcons = false;
	Info.ButtonDetails.Add(FNotificationButtonInfo(
		FText::FromString(TEXT("立即续期 (Y)")),
		FText::FromString(TEXT("打开授权窗口")),
		FSimpleDelegate::CreateUObject(this, &UGenericAuthorizationSubsystem::HandleExpirationWarningAccepted)));
	Info.ButtonDetails.Add(FNotificationButtonInfo(
		FText::FromString(TEXT("忽略 (N)")),
		FText::FromString(TEXT("关闭本次提醒")),
		FSimpleDelegate::CreateUObject(this, &UGenericAuthorizationSubsystem::HandleExpirationWarningDismissed)));

	ExpirationWarningNotification = FSlateNotificationManager::Get().AddNotification(Info);
	if (ExpirationWarningNotification.IsValid())
	{
		ExpirationWarningNotification->SetCompletionState(SNotificationItem::CS_Pending);
		ExpirationWarningDismissAtSeconds = FPlatformTime::Seconds() + 60.0;
	}

	LastExpirationWarningGrantKey = GrantTrackingKey;

	if (!ExpirationWarningInputProcessor.IsValid())
	{
		TWeakObjectPtr<UGenericAuthorizationSubsystem> WeakThis(this);
		ExpirationWarningInputProcessor = MakeShared<FAuthorizationNotificationInputProcessor>(
			[WeakThis]()
			{
				if (UGenericAuthorizationSubsystem* Subsystem = WeakThis.Get())
				{
					Subsystem->HandleExpirationWarningAccepted();
				}
			},
			[WeakThis]()
			{
				if (UGenericAuthorizationSubsystem* Subsystem = WeakThis.Get())
				{
					Subsystem->HandleExpirationWarningDismissed();
				}
			});

		FSlateApplication::Get().RegisterInputPreProcessor(ExpirationWarningInputProcessor);
	}
}

void UGenericAuthorizationSubsystem::DismissExpirationWarningNotification(const bool bRememberDismissal)
{
	if (ExpirationWarningNotification.IsValid())
	{
		ExpirationWarningNotification->SetCompletionState(SNotificationItem::CS_None);
		ExpirationWarningNotification->SetExpireDuration(0.0f);
		ExpirationWarningNotification->SetFadeOutDuration(0.0f);
		ExpirationWarningNotification->ExpireAndFadeout();
		ExpirationWarningNotification->Fadeout();
		ExpirationWarningNotification->ExpireAndFadeout();
		ExpirationWarningNotification.Reset();
	}

	if (ExpirationWarningInputProcessor.IsValid() && FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(ExpirationWarningInputProcessor);
		ExpirationWarningInputProcessor.Reset();
	}

	ExpirationWarningDismissAtSeconds = 0.0;
	if (!bRememberDismissal)
	{
		return;
	}

	if (LastExpirationWarningGrantKey.IsEmpty())
	{
		LastExpirationWarningGrantKey = BuildBaseGrantTrackingKey();
	}
}

void UGenericAuthorizationSubsystem::HandleExpirationWarningAccepted()
{
	DismissExpirationWarningNotification(true);

	if (ShouldSuppressAuthorizationUi())
	{
		UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization expiration warning accepted, but authorization UI is currently suppressed."));
		return;
	}

	UE_LOG(GenericLogAuthorization, Log, TEXT("Authorization expiration warning accepted. Opening reauthorization window."));
	ShowReauthorizationWindow(false);
}

void UGenericAuthorizationSubsystem::HandleExpirationWarningDismissed()
{
	DismissExpirationWarningNotification(true);
}

void UGenericAuthorizationSubsystem::ShowReauthorizationWindow(const bool bExitIfClosedWithoutAuthorization)
{
	if (!FSlateApplication::IsInitialized() || ShouldSuppressAuthorizationUi())
	{
		UE_LOG(GenericLogAuthorization, Log, TEXT("Skip showing reauthorization window. SlateReady=%d Suppressed=%d"), FSlateApplication::IsInitialized() ? 1 : 0, ShouldSuppressAuthorizationUi() ? 1 : 0);
		return;
	}

	bExitIfReauthorizationWindowClosedWithoutAuthorization = bExitIfReauthorizationWindowClosedWithoutAuthorization || bExitIfClosedWithoutAuthorization;

	if (bReauthorizationWindowVisible)
	{
		UE_LOG(GenericLogAuthorization, Log, TEXT("Reauthorization window is already visible. ExitIfClosed=%d"), bExitIfReauthorizationWindowClosedWithoutAuthorization ? 1 : 0);
		return;
	}

	const TSharedRef<SAuthorizationActivationDialog> DialogContent = SNew(SAuthorizationActivationDialog)
		.OnGetAuthorizationRequestCode(FAuthorizationRequestCodeGetter::CreateUObject(this, &UGenericAuthorizationSubsystem::GetCurrentAuthorizationRequestCode))
		.OnSubmitLicenseCode(FAuthorizationLicenseSubmitter::CreateUObject(this, &UGenericAuthorizationSubsystem::SubmitLicenseCodeFromPrompt));

	const FString WindowTitle = bExitIfReauthorizationWindowClosedWithoutAuthorization ? TEXT("授权已过期，请重新授权") : TEXT("授权即将过期，可提前续期");
	const TSharedRef<SWindow> DialogWindow = SNew(SWindow)
		.Title(FText::FromString(WindowTitle))
		.ClientSize(FVector2D(640.0f, 480.0f))
		.SupportsMinimize(false)
		.SupportsMaximize(false)
		.IsTopmostWindow(true)
		.FocusWhenFirstShown(true);

	DialogContent->SetOwnerWindow(DialogWindow);
	DialogWindow->SetContent(DialogContent);
	DialogWindow->SetOnWindowClosed(FOnWindowClosed::CreateUObject(this, &UGenericAuthorizationSubsystem::HandleReauthorizationWindowClosed));

	ReauthorizationDialogContent = DialogContent;
	ReauthorizationWindow = DialogWindow;
	bReauthorizationWindowVisible = true;
	bReauthorizationWindowOpenedWhileAuthorized = GetBaseAppState() == EAuthorizationState::Authorized;
	UE_LOG(
		GenericLogAuthorization,
		Log,
		TEXT("Show reauthorization window. ExitIfClosed=%d OpenedWhileAuthorized=%d State=%d"),
		bExitIfReauthorizationWindowClosedWithoutAuthorization ? 1 : 0,
		bReauthorizationWindowOpenedWhileAuthorized ? 1 : 0,
		static_cast<int32>(GetBaseAppState()));
	FSlateApplication::Get().AddWindow(DialogWindow, true);
}

void UGenericAuthorizationSubsystem::CloseReauthorizationWindow(const bool bRequestExitIfStillUnauthorized)
{
	bExitIfReauthorizationWindowClosedWithoutAuthorization = bRequestExitIfStillUnauthorized;
	UE_LOG(
		GenericLogAuthorization,
		Log,
		TEXT("Close reauthorization window requested. Visible=%d ExitIfStillUnauthorized=%d"),
		bReauthorizationWindowVisible ? 1 : 0,
		bRequestExitIfStillUnauthorized ? 1 : 0);

	if (const TSharedPtr<SWindow> ExistingWindow = ReauthorizationWindow.Pin())
	{
		ExistingWindow->RequestDestroyWindow();
	}
}

void UGenericAuthorizationSubsystem::HandleReauthorizationWindowClosed(const TSharedRef<SWindow>& ClosedWindow)
{
	const bool bWasAuthorized = ReauthorizationDialogContent.Pin().IsValid() && ReauthorizationDialogContent.Pin()->WasAuthorized();
	ReauthorizationDialogContent.Reset();
	ReauthorizationWindow.Reset();
	bReauthorizationWindowVisible = false;
	bReauthorizationWindowOpenedWhileAuthorized = false;

	if (bWasAuthorized)
	{
		SetAuthorizationPauseState(false);
	}

	const bool bShouldExit = bExitIfReauthorizationWindowClosedWithoutAuthorization
		&& !bWasAuthorized
		&& GetBaseAppState() == EAuthorizationState::Expired
		&& !bAuthorizationExitPending;

	UE_LOG(
		GenericLogAuthorization,
		Log,
		TEXT("Reauthorization window closed. WasAuthorized=%d ShouldExit=%d State=%d ExitPending=%d"),
		bWasAuthorized ? 1 : 0,
		bShouldExit ? 1 : 0,
		static_cast<int32>(GetBaseAppState()),
		bAuthorizationExitPending ? 1 : 0);

	bExitIfReauthorizationWindowClosedWithoutAuthorization = false;

	if (bShouldExit)
	{
		PrepareForAuthorizationExit();
		UE_LOG(GenericLogAuthorization, Warning, TEXT("Authorization expired and reauthorization was dismissed. Request exit."));
		FPlatformMisc::RequestExit(false);
	}
}

UWorld* UGenericAuthorizationSubsystem::GetActiveAuthorizationWorld() const
{
	if (const UGameInstance* GameInstance = Cast<UGameInstance>(GetOuter()))
	{
		return GameInstance->GetWorld();
	}

	return nullptr;
}

bool UGenericAuthorizationSubsystem::CanPauseGameplayForExpiredAuthorization() const
{
	const UWorld* World = GetActiveAuthorizationWorld();
	return World != nullptr && World->IsGameWorld() && World->HasBegunPlay();
}

void UGenericAuthorizationSubsystem::SetAuthorizationPauseState(const bool bShouldPause)
{
	UWorld* World = GetActiveAuthorizationWorld();
	if (World == nullptr)
	{
		if (!bShouldPause)
		{
			bAuthorizationPauseApplied = false;
		}

		return;
	}

	if (bShouldPause)
	{
		if (bAuthorizationPauseApplied || World->IsPaused())
		{
			return;
		}

		if (UGameplayStatics::SetGamePaused(World, true))
		{
			bAuthorizationPauseApplied = true;
		}

		return;
	}

	if (!bAuthorizationPauseApplied)
	{
		return;
	}

	UGameplayStatics::SetGamePaused(World, false);
	bAuthorizationPauseApplied = false;
}

void UGenericAuthorizationSubsystem::UpdateTrustedClock()
{
	RuntimeState.CurrentDeviceId = CurrentDeviceId;
	RuntimeState.CurrentPackageFingerprint = CurrentPackageFingerprint;
	RuntimeState.LastTrustedUnixSeconds = FAuthorizationClockGuard::UpdateTrustedUnixSeconds(FAuthorizationVerifier::GetCurrentUnixTimestamp(), RuntimeState.LastTrustedUnixSeconds);
}

bool UGenericAuthorizationSubsystem::SubmitLicenseCodeFromPrompt(const FString& LicenseTokenText, FString& OutMessage)
{
	return ImportLicenseTokenText(LicenseTokenText, OutMessage, true);
}

void UGenericAuthorizationSubsystem::BroadcastLicenseStateChanges()
{
	BPDelegate_OnAuthorizationScopeStateChanged.Broadcast(UAuthorizationSettings::Get()->BaseScopeId, GetBaseAppState());

	for (const FAuthorizationGrant& Grant : CurrentLicenseToken.Grants)
	{
		BPDelegate_OnAuthorizationScopeStateChanged.Broadcast(Grant.ScopeId, GetScopeState(Grant.ScopeId));
	}
}

void UGenericAuthorizationSubsystem::BroadcastManifestChanged()
{
	BPDelegate_OnAuthorizationManifestChanged.Broadcast();
}
