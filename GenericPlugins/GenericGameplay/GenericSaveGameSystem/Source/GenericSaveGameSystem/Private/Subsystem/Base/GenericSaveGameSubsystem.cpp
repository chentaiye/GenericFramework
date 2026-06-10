// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/Base/GenericSaveGameSubsystem.h"

#include "Base/GenericSaveGame.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "HAL/FileManager.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/Paths.h"
#include "SaveGameType.h"
#include "Subsystem/GenericVersionDataSubsystem.h"
#include "Subsystem/GenericVersionMigrationSubsystem.h"
#include "Subsystem/GenericVersionValidationSubsystem.h"
#include "Types/GenericVersionTypes.h"

namespace
{
	FGenericVersionDefinition MakeDefaultSaveGameVersionDefinition()
	{
		FGenericVersionDefinition Definition;
		Definition.VersionKey = TAG_GameplayVersion_SaveGame;
		Definition.Version = FGenericVersionInfo(1, 0, 0);
		Definition.MinimumSupportedVersion = FGenericVersionInfo(1, 0, 0);
		Definition.SourceName = TEXT("SaveGame");
		return Definition;
	}

	bool EnsureSaveGameVersionDefinition(UGenericVersionDataSubsystem* VersionDataSubsystem)
	{
		if (!VersionDataSubsystem)
		{
			return false;
		}

		FGenericVersionDefinition ExistingDefinition;
		if (VersionDataSubsystem->GetVersionDefinition(TAG_GameplayVersion_SaveGame, ExistingDefinition))
		{
			return true;
		}

		return VersionDataSubsystem->SetVersionDefinition(MakeDefaultSaveGameVersionDefinition());
	}

	FString GetSaveGameClassSourceName(const UGenericSaveGame* SaveGame)
	{
		return SaveGame && SaveGame->GetClass() ? SaveGame->GetClass()->GetName() : TEXT("SaveGame");
	}

	void BroadcastSaveGameRegisteredMessage(const UObject* WorldContextObject, const FString& SlotName, UGenericSaveGame* SaveGame)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameRegisteredMessage Message;
		Message.SlotName = SlotName;
		Message.SaveGame = SaveGame;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameRegister, Message);
	}

	void BroadcastSaveGameUnregisteredMessage(const UObject* WorldContextObject, const FString& SlotName, UGenericSaveGame* SaveGame)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameUnregisteredMessage Message;
		Message.SlotName = SlotName;
		Message.SaveGame = SaveGame;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameUnRegister, Message);
	}

	void BroadcastSaveGameRefreshMessage(const UObject* WorldContextObject, const FString& SlotName, UGenericSaveGame* SaveGame)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameRefreshMessage Message;
		Message.SlotName = SlotName;
		Message.SaveGame = SaveGame;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameRefresh, Message);
	}

	int32 GetSaveGameUserIndex(const APlayerController* PlayerController)
	{
		const ULocalPlayer* LocalPlayer = PlayerController ? PlayerController->GetLocalPlayer() : nullptr;
		if (!LocalPlayer)
		{
			return 0;
		}

		const FPlatformUserId PlatformUserId = LocalPlayer->GetPlatformUserId();
		return PlatformUserId.IsValid() ? PlatformUserId.GetInternalId() : LocalPlayer->GetPlatformUserIndex();
	}

	void BroadcastSaveGameSaveStartMessage(const UObject* WorldContextObject, const FSaveGameParameter& Parameter)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameSaveStartMessage Message;
		Message.PlayerController = Parameter.PlayerController;
		Message.SlotName = Parameter.SlotName;
		Message.SaveGame = Parameter.SaveGame;
		Message.bOverwriteLocalFile = Parameter.bOverwriteLocalFile;
		Message.bRefreshSaveGame = Parameter.bRefreshSaveGame;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameSaveStart, Message);
	}

	void BroadcastSaveGameSaveFinishMessage(const UObject* WorldContextObject, APlayerController* PlayerController, const FString& SlotName, UGenericSaveGame* SaveGame, const bool bSuccess)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameSaveFinishMessage Message;
		Message.PlayerController = PlayerController;
		Message.SlotName = SlotName;
		Message.SaveGame = SaveGame;
		Message.bSuccess = bSuccess;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameSaveFinish, Message);
	}

	void BroadcastSaveGameLoadStartMessage(const UObject* WorldContextObject, const FLoadGameParameter& Parameter)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameLoadStartMessage Message;
		Message.PlayerController = Parameter.PlayerController;
		Message.SlotName = Parameter.SlotName;
		Message.SaveGameClass = Parameter.SaveGameClass;
		Message.bRefreshSaveGame = Parameter.bRefreshSaveGame;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameLoadStart, Message);
	}

	void BroadcastSaveGameLoadFinishMessage(const UObject* WorldContextObject, APlayerController* PlayerController, const FString& SlotName, UGenericSaveGame* SaveGame, const bool bSuccess)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameLoadFinishMessage Message;
		Message.PlayerController = PlayerController;
		Message.SlotName = SlotName;
		Message.SaveGame = SaveGame;
		Message.bSuccess = bSuccess;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameLoadFinish, Message);
	}
}

UGenericSaveGameSubsystem* UGenericSaveGameSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UGenericSaveGameSubsystem>();
		}
	}

	return nullptr;
}

UGenericSaveGame* UGenericSaveGameSubsystem::CreateSaveGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass)
{
	if (SlotName.IsEmpty())
	{
		return nullptr;
	}

	if (!EnsureSaveDirectory(SlotName))
	{
		return nullptr;
	}

	UClass* TargetClass = *SaveGameClass ? SaveGameClass.Get() : UGenericSaveGame::StaticClass();
	UGenericSaveGame* SaveGame = NewObject<UGenericSaveGame>(this, TargetClass);
	if (!SaveGame)
	{
		return nullptr;
	}

	FSaveGameParameter SaveSetting;
	SaveSetting.SlotName = SlotName;
	SaveSetting.SaveGame = SaveGame;
	SaveSetting.bOverwriteLocalFile = false;
	SaveSetting.bRefreshSaveGame = true;

	FOnGenericSaveGameAsyncSaveComplete OnComplete;
	OnComplete.BindWeakLambda(this, [this](const FString& SavedSlotName, UGenericSaveGame*, const bool bSuccess)
	{
		if (!bSuccess)
		{
			UnregisterSaveGame(SavedSlotName);
		}
	});

	if (!AsyncSaveGameToSlot(SaveSetting, OnComplete))
	{
		return nullptr;
	}

	return SaveGame;
}

bool UGenericSaveGameSubsystem::DeleteSaveGame(const FString& SlotName)
{
	if (SlotName.IsEmpty())
	{
		return false;
	}

	constexpr int32 UserIndex = 0;
	const bool bDeleted = UGameplayStatics::DeleteGameInSlot(SlotName, UserIndex);
	if (bDeleted)
	{
		UnregisterSaveGame(SlotName);
	}
	return bDeleted;
}

bool UGenericSaveGameSubsystem::RegisterSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame)
{
	if (SlotName.IsEmpty() || !SaveGame)
	{
		return false;
	}

	if (UGenericSaveGame* ExistingSaveGame = RegisteredSaveGames.FindRef(SlotName))
	{
		if (ExistingSaveGame == SaveGame)
		{
			return true;
		}
	}

	if (!ProcessSaveGameVersion(SaveGame))
	{
		return false;
	}

	if (RegisteredSaveGames.Contains(SlotName))
	{
		UnregisterSaveGame(SlotName);
	}

	RegisteredSaveGames.Add(SlotName, SaveGame);
	SaveGame->OnInitialized();
	BroadcastSaveGameRegisteredMessage(this, SlotName, SaveGame);
	return true;
}

bool UGenericSaveGameSubsystem::UnregisterSaveGame(const FString& SlotName)
{
	if (SlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGame* SaveGame = RegisteredSaveGames.FindRef(SlotName);
	if (!SaveGame)
	{
		return false;
	}

	RegisteredSaveGames.Remove(SlotName);
	if (UGenericVersionDataSubsystem* VersionDataSubsystem = UGenericVersionDataSubsystem::Get(this))
	{
		VersionDataSubsystem->RemoveVersionData(static_cast<FGenericVersionObject*>(SaveGame));
	}
	SaveGame->OnDeinitialized();
	BroadcastSaveGameUnregisteredMessage(this, SlotName, SaveGame);
	return true;
}

bool UGenericSaveGameSubsystem::AsyncSaveGameToSlot(const FSaveGameParameter& Parameter, const FOnGenericSaveGameAsyncSaveComplete& OnComplete)
{
	UGenericSaveGame* SaveGame = Parameter.SaveGame;
	if (Parameter.SlotName.IsEmpty() || !SaveGame)
	{
		return false;
	}

	const int32 UserIndex = GetSaveGameUserIndex(Parameter.PlayerController);
	BroadcastSaveGameSaveStartMessage(this, Parameter);

	if (!EnsureSaveDirectory(Parameter.SlotName))
	{
		BroadcastSaveGameSaveFinishMessage(this, Parameter.PlayerController, Parameter.SlotName, SaveGame, false);
		return false;
	}

	if (!Parameter.bOverwriteLocalFile && UGameplayStatics::DoesSaveGameExist(Parameter.SlotName, UserIndex))
	{
		BroadcastSaveGameSaveFinishMessage(this, Parameter.PlayerController, Parameter.SlotName, SaveGame, false);
		return false;
	}

	if (!RegisterSaveGame(Parameter.SlotName, SaveGame))
	{
		BroadcastSaveGameSaveFinishMessage(this, Parameter.PlayerController, Parameter.SlotName, SaveGame, false);
		return false;
	}

	if (Parameter.bRefreshSaveGame && !RefreshSaveGame(Parameter.SlotName, SaveGame))
	{
		BroadcastSaveGameSaveFinishMessage(this, Parameter.PlayerController, Parameter.SlotName, SaveGame, false);
		return false;
	}

	const bool bWasDirty = SaveGame->GetIsDirty();
	const int32 DirtySerial = SaveGame->GetDirtySerial();
	const TWeakObjectPtr<APlayerController> WeakPlayerController(Parameter.PlayerController);
	FAsyncSaveGameToSlotDelegate SavedDelegate;
	SavedDelegate.BindWeakLambda(this, [this, OnComplete, SaveGame, bWasDirty, DirtySerial, WeakPlayerController](const FString& SavedSlotName, const int32, const bool bSuccess)
	{
		if (bSuccess && bWasDirty && SaveGame)
		{
			SaveGame->ClearDirty(DirtySerial);
		}
		BroadcastSaveGameSaveFinishMessage(this, WeakPlayerController.Get(), SavedSlotName, SaveGame, bSuccess);
		OnComplete.ExecuteIfBound(SavedSlotName, SaveGame, bSuccess);
	});

	UGameplayStatics::AsyncSaveGameToSlot(SaveGame, Parameter.SlotName, UserIndex, SavedDelegate);
	return true;
}

bool UGenericSaveGameSubsystem::AsyncSaveGameToSlot(UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete)
{
	if (!SaveGame || SaveGame->GetSlotName().IsEmpty())
	{
		return false;
	}

	FSaveGameParameter Parameter;
	Parameter.SlotName = SaveGame->GetSlotName();
	Parameter.SaveGame = SaveGame;
	Parameter.bOverwriteLocalFile = true;
	Parameter.bRefreshSaveGame = true;
	return AsyncSaveGameToSlot(Parameter, OnComplete);
}

bool UGenericSaveGameSubsystem::AsyncLoadGameFromSlot(const FLoadGameParameter& Parameter, const FOnGenericSaveGameAsyncLoadComplete& OnComplete)
{
	if (Parameter.SlotName.IsEmpty())
	{
		return false;
	}

	const int32 UserIndex = GetSaveGameUserIndex(Parameter.PlayerController);
	const TWeakObjectPtr<APlayerController> WeakPlayerController(Parameter.PlayerController);
	BroadcastSaveGameLoadStartMessage(this, Parameter);

	FAsyncLoadGameFromSlotDelegate LoadedDelegate;
	LoadedDelegate.BindWeakLambda(this, [this, Parameter, OnComplete, WeakPlayerController](const FString& LoadedSlotName, const int32, USaveGame* LoadedObject)
	{
		UGenericSaveGame* LoadedSaveGame = Cast<UGenericSaveGame>(LoadedObject);
		const bool bMatchesClass = LoadedSaveGame && (!*Parameter.SaveGameClass || LoadedSaveGame->IsA(Parameter.SaveGameClass));
		bool bSuccess = bMatchesClass && RegisterSaveGame(LoadedSlotName, LoadedSaveGame);
		if (bSuccess && Parameter.bRefreshSaveGame)
		{
			bSuccess = RefreshSaveGame(LoadedSlotName, LoadedSaveGame);
		}
		BroadcastSaveGameLoadFinishMessage(this, WeakPlayerController.Get(), LoadedSlotName, bSuccess ? LoadedSaveGame : nullptr, bSuccess);
		OnComplete.ExecuteIfBound(LoadedSlotName, bSuccess ? LoadedSaveGame : nullptr, bSuccess);
	});

	UGameplayStatics::AsyncLoadGameFromSlot(Parameter.SlotName, UserIndex, LoadedDelegate);
	return true;
}

bool UGenericSaveGameSubsystem::RefreshSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame) const
{
	if (SlotName.IsEmpty() || !SaveGame)
	{
		return false;
	}

	FString NormalizedSlotName = SlotName;
	NormalizedSlotName.ReplaceInline(TEXT("\\"), TEXT("/"));
	NormalizedSlotName.RemoveFromStart(TEXT("/"));
	NormalizedSlotName.RemoveFromEnd(TEXT(".sav"), ESearchCase::IgnoreCase);

	SaveGame->SetSlotName(FPaths::GetBaseFilename(NormalizedSlotName));
	SaveGame->SetPathName(FString::Printf(TEXT("/%s.sav"), *NormalizedSlotName));
	SaveGame->SetClassPackageName(SaveGame->GetClass()->GetPackage() ? SaveGame->GetClass()->GetPackage()->GetName() : FString());
	SaveGame->SetSaveTime(FDateTime::Now());
	SaveGame->SetPropertySchemaSignature(SaveGame->BuildCurrentPropertySchemaSignature());
	BroadcastSaveGameRefreshMessage(this, SlotName, SaveGame);
	SaveGame->OnRefresh();
	return true;
}

UGenericSaveGame* UGenericSaveGameSubsystem::GetSaveGame(const FString& SlotName) const
{
	if (SlotName.IsEmpty())
	{
		return nullptr;
	}

	return RegisteredSaveGames.FindRef(SlotName);
}

bool UGenericSaveGameSubsystem::ProcessSaveGameVersion(UGenericSaveGame* SaveGame) const
{
	if (!SaveGame)
	{
		return false;
	}

	UGenericVersionDataSubsystem* VersionDataSubsystem = UGenericVersionDataSubsystem::Get(this);
	UGenericVersionValidationSubsystem* VersionValidationSubsystem = UGenericVersionValidationSubsystem::Get(this);
	UGenericVersionMigrationSubsystem* VersionMigrationSubsystem = UGenericVersionMigrationSubsystem::Get(this);
	if (!VersionDataSubsystem || !VersionValidationSubsystem || !VersionMigrationSubsystem)
	{
		UE_LOG(GenericLogSaveGame, Warning, TEXT("RegisterSaveGame failed because GenericVersionFramework subsystems are unavailable."));
		return false;
	}

	if (!EnsureSaveGameVersionDefinition(VersionDataSubsystem))
	{
		UE_LOG(GenericLogSaveGame, Warning, TEXT("RegisterSaveGame failed because GameplayVersion.SaveGame has no valid version definition."));
		return false;
	}

	FGenericVersionData VersionData = SaveGame->GetVersion();
	if (!VersionData.VersionKey.IsValid() || VersionData.VersionKey == TAG_GameplayVersion)
	{
		VersionData.VersionKey = TAG_GameplayVersion_SaveGame;
	}
	if (VersionData.SourceName.IsEmpty())
	{
		VersionData.SourceName = GetSaveGameClassSourceName(SaveGame);
	}
	SaveGame->SetVersion(VersionData);

	if (!VersionData.VersionKey.MatchesTag(TAG_GameplayVersion_SaveGame))
	{
		UE_LOG(GenericLogSaveGame, Warning, TEXT("RegisterSaveGame failed because version key '%s' is not under GameplayVersion.SaveGame."), *VersionData.VersionKey.ToString());
		return false;
	}

	FGenericVersionData ResolvedVersionData;
	if (!VersionDataSubsystem->RefreshVersionData(static_cast<FGenericVersionObject*>(SaveGame), VersionData, ResolvedVersionData))
	{
		UE_LOG(GenericLogSaveGame, Warning, TEXT("RegisterSaveGame failed because version data '%s' has no valid central definition."), *VersionData.VersionKey.ToString());
		return false;
	}
	SaveGame->SetVersion(ResolvedVersionData);

	UObject* ContextObject = const_cast<UGenericSaveGameSubsystem*>(this);
	FGenericVersionValidationResult ValidationResult = VersionValidationSubsystem->ValidateObject(SaveGame, ContextObject);
	if (ValidationResult.IsFailed())
	{
		VersionDataSubsystem->RemoveVersionData(static_cast<FGenericVersionObject*>(SaveGame));
		UE_LOG(GenericLogSaveGame, Warning, TEXT("RegisterSaveGame version validation failed: %s"), *ValidationResult.Message.ToString());
		return false;
	}

	if (ValidationResult.IsWarning())
	{
		const FGenericVersionMigrationResult MigrationResult = VersionMigrationSubsystem->MigrateObject(SaveGame, ContextObject);
		if (!MigrationResult.bSuccess)
		{
			VersionDataSubsystem->RemoveVersionData(static_cast<FGenericVersionObject*>(SaveGame));
			UE_LOG(GenericLogSaveGame, Warning, TEXT("RegisterSaveGame version migration failed: %s"), *MigrationResult.Message.ToString());
			return false;
		}

		if (!VersionDataSubsystem->RefreshVersionData(static_cast<FGenericVersionObject*>(SaveGame), SaveGame->GetVersion(), ResolvedVersionData))
		{
			VersionDataSubsystem->RemoveVersionData(static_cast<FGenericVersionObject*>(SaveGame));
			UE_LOG(GenericLogSaveGame, Warning, TEXT("RegisterSaveGame failed because migrated version data is invalid."));
			return false;
		}
		SaveGame->SetVersion(ResolvedVersionData);

		ValidationResult = VersionValidationSubsystem->ValidateObject(SaveGame, ContextObject);
		if (!ValidationResult.IsSuccess())
		{
			VersionDataSubsystem->RemoveVersionData(static_cast<FGenericVersionObject*>(SaveGame));
			UE_LOG(GenericLogSaveGame, Warning, TEXT("RegisterSaveGame validation failed after migration: %s"), *ValidationResult.Message.ToString());
			return false;
		}
	}

	return true;
}

bool UGenericSaveGameSubsystem::EnsureSaveDirectory(const FString& SlotName) const
{
	const FString SaveFilePath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("SaveGames"), SlotName);
	const FString SaveDirectory = FPaths::GetPath(SaveFilePath);
	return IFileManager::Get().MakeDirectory(*SaveDirectory, true);
}
