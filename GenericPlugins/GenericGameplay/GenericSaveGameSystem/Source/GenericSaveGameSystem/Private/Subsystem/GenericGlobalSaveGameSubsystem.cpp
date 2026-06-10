// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/GenericGlobalSaveGameSubsystem.h"

#include "Base/GenericSaveGame.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameplayMessageSubsystem.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "SaveGameType.h"
#include "Subsystems/SubsystemCollection.h"

namespace
{
	struct FGlobalSaveGameLoadState
	{
		int32 TotalCount = 0;
		TArray<FString> LoadedSlotNames;
		TArray<FString> FailedSlotNames;
	};

	void BroadcastGlobalSaveGameLoadStartMessage(const UObject* WorldContextObject, const TArray<FString>& SlotNames)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnGlobalSaveGameLoadStartMessage Message;
		Message.TotalCount = SlotNames.Num();
		Message.SlotNames = SlotNames;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnGlobalSaveGameLoadStart, Message);
	}

	void BroadcastGlobalSaveGameLoadOnceFinishMessage(const UObject* WorldContextObject, const FString& SlotName, UGenericSaveGame* SaveGame, const int32 CompletedCount, const int32 TotalCount)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnGlobalSaveGameLoadOnceFinishMessage Message;
		Message.SlotName = SlotName;
		Message.SaveGame = SaveGame;
		Message.CompletedCount = CompletedCount;
		Message.TotalCount = TotalCount;
		Message.bSuccess = SaveGame != nullptr;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnGlobalSaveGameLoadOnceFinish, Message);
	}

	void BroadcastGlobalSaveGameLoadFinishMessage(const UObject* WorldContextObject, const TArray<FString>& LoadedSlotNames, const TArray<FString>& FailedSlotNames)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnGlobalSaveGameLoadFinishMessage Message;
		Message.SuccessCount = LoadedSlotNames.Num();
		Message.FailedCount = FailedSlotNames.Num();
		Message.TotalCount = Message.SuccessCount + Message.FailedCount;
		Message.LoadedSlotNames = LoadedSlotNames;
		Message.FailedSlotNames = FailedSlotNames;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnGlobalSaveGameLoadFinish, Message);
	}

	void FinishGlobalSaveGameLoadOnce(UGenericGlobalSaveGameSubsystem* GlobalSaveGameSubsystem, const TSharedRef<FGlobalSaveGameLoadState>& LoadState, const FString& SlotName, UGenericSaveGame* LoadedSaveGame)
	{
		if (LoadedSaveGame)
		{
			LoadState->LoadedSlotNames.Add(SlotName);
		}
		else
		{
			LoadState->FailedSlotNames.Add(SlotName);
		}

		const int32 CompletedCount = LoadState->LoadedSlotNames.Num() + LoadState->FailedSlotNames.Num();
		BroadcastGlobalSaveGameLoadOnceFinishMessage(GlobalSaveGameSubsystem, SlotName, LoadedSaveGame, CompletedCount, LoadState->TotalCount);
		if (CompletedCount >= LoadState->TotalCount)
		{
			BroadcastGlobalSaveGameLoadFinishMessage(GlobalSaveGameSubsystem, LoadState->LoadedSlotNames, LoadState->FailedSlotNames);
		}
	}
}

UGenericGlobalSaveGameSubsystem* UGenericGlobalSaveGameSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UGenericGlobalSaveGameSubsystem>();
		}
	}

	return nullptr;
}

void UGenericGlobalSaveGameSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Collection.InitializeDependency(UGenericSaveGameSubsystem::StaticClass());
	Super::Initialize(Collection);

	LoadLocalGlobalSaveGames();
}

UGenericSaveGame* UGenericGlobalSaveGameSubsystem::CreateGlobalSaveGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass)
{
	if (SlotName.IsEmpty())
	{
		return nullptr;
	}

	const FString GlobalSlotName = BuildGlobalSlotName(SlotName);
	if (!EnsureGlobalSaveDirectory(GlobalSlotName))
	{
		return nullptr;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return nullptr;
	}

	UClass* TargetClass = *SaveGameClass ? SaveGameClass.Get() : UGenericSaveGame::StaticClass();
	UGenericSaveGame* SaveGame = NewObject<UGenericSaveGame>(this, TargetClass);
	if (!SaveGame)
	{
		return nullptr;
	}

	FOnGenericSaveGameAsyncSaveComplete OnComplete;
	OnComplete.BindWeakLambda(this, [SaveGameSubsystem](const FString& SavedSlotName, UGenericSaveGame*, const bool bSuccess)
	{
		if (!bSuccess && SaveGameSubsystem)
		{
			SaveGameSubsystem->UnregisterSaveGame(SavedSlotName);
		}
	});

	FSaveGameParameter SaveSetting;
	SaveSetting.SlotName = GlobalSlotName;
	SaveSetting.SaveGame = SaveGame;
	SaveSetting.bOverwriteLocalFile = false;
	SaveSetting.bRefreshSaveGame = true;
	if (!SaveGameSubsystem->AsyncSaveGameToSlot(SaveSetting, OnComplete))
	{
		SaveGameSubsystem->UnregisterSaveGame(GlobalSlotName);
		return nullptr;
	}

	return SaveGame;
}

bool UGenericGlobalSaveGameSubsystem::DeleteGlobalSaveGame(const FString& SlotName)
{
	if (SlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->DeleteSaveGame(BuildGlobalSlotName(SlotName)) : false;
}

bool UGenericGlobalSaveGameSubsystem::AsyncGlobalSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete)
{
	if (SlotName.IsEmpty() || !SaveGame)
	{
		return false;
	}

	const FString GlobalSlotName = BuildGlobalSlotName(SlotName);
	if (!EnsureGlobalSaveDirectory(GlobalSlotName))
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return false;
	}

	FSaveGameParameter SaveSetting;
	SaveSetting.SlotName = GlobalSlotName;
	SaveSetting.SaveGame = SaveGame;
	SaveSetting.bOverwriteLocalFile = true;
	SaveSetting.bRefreshSaveGame = true;
	return SaveGameSubsystem->AsyncSaveGameToSlot(SaveSetting, OnComplete);
}

bool UGenericGlobalSaveGameSubsystem::AsyncGlobalLoadGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass, const FOnGenericSaveGameAsyncLoadComplete& OnComplete)
{
	if (SlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return false;
	}

	FLoadGameParameter LoadSetting;
	LoadSetting.SlotName = BuildGlobalSlotName(SlotName);
	LoadSetting.SaveGameClass = SaveGameClass;
	LoadSetting.bRefreshSaveGame = true;
	return SaveGameSubsystem->AsyncLoadGameFromSlot(LoadSetting, OnComplete);
}

UGenericSaveGame* UGenericGlobalSaveGameSubsystem::GetGlobalSaveGame(const FString& SlotName) const
{
	if (SlotName.IsEmpty())
	{
		return nullptr;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->GetSaveGame(BuildGlobalSlotName(SlotName)) : nullptr;
}

TArray<UGenericSaveGame*> UGenericGlobalSaveGameSubsystem::GetGlobalSaveGames() const
{
	TArray<UGenericSaveGame*> Result;
	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return Result;
	}

	const FString SaveGamesRoot = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("SaveGames"));
	const FString GlobalSaveDirectory = FPaths::Combine(SaveGamesRoot, TEXT("Global"));
	if (!IFileManager::Get().DirectoryExists(*GlobalSaveDirectory))
	{
		return Result;
	}

	TArray<FString> SaveFiles;
	IFileManager::Get().FindFilesRecursive(SaveFiles, *GlobalSaveDirectory, TEXT("*.sav"), true, false);
	for (const FString& SaveFile : SaveFiles)
	{
		const FString GlobalSlotName = BuildGlobalSlotNameFromSaveFile(SaveFile);
		if (UGenericSaveGame* SaveGame = GlobalSlotName.IsEmpty() ? nullptr : SaveGameSubsystem->GetSaveGame(GlobalSlotName))
		{
			Result.Add(SaveGame);
		}
	}
	return Result;
}

void UGenericGlobalSaveGameSubsystem::LoadLocalGlobalSaveGames()
{
	TArray<FString> GlobalSlotNames;
	const FString SaveGamesRoot = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("SaveGames"));
	const FString GlobalSaveDirectory = FPaths::Combine(SaveGamesRoot, TEXT("Global"));
	if (IFileManager::Get().DirectoryExists(*GlobalSaveDirectory))
	{
		TArray<FString> SaveFiles;
		IFileManager::Get().FindFilesRecursive(SaveFiles, *GlobalSaveDirectory, TEXT("*.sav"), true, false);
		for (const FString& SaveFile : SaveFiles)
		{
			const FString GlobalSlotName = BuildGlobalSlotNameFromSaveFile(SaveFile);
			if (!GlobalSlotName.IsEmpty())
			{
				GlobalSlotNames.AddUnique(GlobalSlotName);
			}
		}
	}

	BroadcastGlobalSaveGameLoadStartMessage(this, GlobalSlotNames);

	const TSharedRef<FGlobalSaveGameLoadState> LoadState = MakeShared<FGlobalSaveGameLoadState>();
	LoadState->TotalCount = GlobalSlotNames.Num();
	if (LoadState->TotalCount == 0)
	{
		BroadcastGlobalSaveGameLoadFinishMessage(this, LoadState->LoadedSlotNames, LoadState->FailedSlotNames);
		return;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	for (const FString& GlobalSlotName : GlobalSlotNames)
	{
		FOnGenericSaveGameAsyncLoadComplete OnComplete;
		OnComplete.BindWeakLambda(this, [this, LoadState](const FString& LoadedSlotName, UGenericSaveGame* LoadedSaveGame, const bool bSuccess)
		{
			FinishGlobalSaveGameLoadOnce(this, LoadState, LoadedSlotName, bSuccess ? LoadedSaveGame : nullptr);
		});

		FLoadGameParameter LoadSetting;
		LoadSetting.SlotName = GlobalSlotName;
		LoadSetting.bRefreshSaveGame = true;
		if (!SaveGameSubsystem || !SaveGameSubsystem->AsyncLoadGameFromSlot(LoadSetting, OnComplete))
		{
			FinishGlobalSaveGameLoadOnce(this, LoadState, GlobalSlotName, nullptr);
		}
	}
}

FString UGenericGlobalSaveGameSubsystem::BuildGlobalSlotNameFromSaveFile(const FString& SaveFilePath) const
{
	FString SaveGamesRoot = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("SaveGames")));
	FPaths::NormalizeDirectoryName(SaveGamesRoot);
	if (!SaveGamesRoot.EndsWith(TEXT("/")))
	{
		SaveGamesRoot += TEXT("/");
	}

	FString RelativeFilePath = SaveFilePath;
	RelativeFilePath = FPaths::ConvertRelativePathToFull(RelativeFilePath);
	FPaths::NormalizeFilename(RelativeFilePath);
	if (!FPaths::MakePathRelativeTo(RelativeFilePath, *SaveGamesRoot))
	{
		return FString();
	}

	RelativeFilePath.ReplaceInline(TEXT("\\"), TEXT("/"));
	RelativeFilePath.RemoveFromStart(TEXT("/"));
	RelativeFilePath.RemoveFromEnd(TEXT(".sav"), ESearchCase::IgnoreCase);
	return RelativeFilePath.StartsWith(TEXT("Global/")) ? RelativeFilePath : FString();
}

FString UGenericGlobalSaveGameSubsystem::BuildGlobalSlotName(const FString& SlotName) const
{
	FString NormalizedSlotName = SlotName;
	NormalizedSlotName.ReplaceInline(TEXT("\\"), TEXT("/"));
	NormalizedSlotName.RemoveFromStart(TEXT("/"));
	NormalizedSlotName.RemoveFromStart(TEXT("Global/"));
	NormalizedSlotName.RemoveFromEnd(TEXT(".sav"), ESearchCase::IgnoreCase);
	return FString::Printf(TEXT("Global/%s"), *NormalizedSlotName);
}

bool UGenericGlobalSaveGameSubsystem::EnsureGlobalSaveDirectory(const FString& GlobalSlotName) const
{
	const FString SaveFilePath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("SaveGames"), GlobalSlotName);
	const FString SaveDirectory = FPaths::GetPath(SaveFilePath);
	return IFileManager::Get().MakeDirectory(*SaveDirectory, true);
}
