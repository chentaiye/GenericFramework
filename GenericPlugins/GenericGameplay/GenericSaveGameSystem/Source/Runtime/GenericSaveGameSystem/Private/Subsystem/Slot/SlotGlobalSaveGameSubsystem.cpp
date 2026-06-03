// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/Slot/SlotGlobalSaveGameSubsystem.h"

#include "Base/GenericSaveGame.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Misc/Paths.h"
#include "Subsystem/GenericSlotSaveGameSubsystem.h"

namespace
{
	constexpr const TCHAR* SlotGlobalRootDirectoryName = TEXT("Slots");
	constexpr const TCHAR* SlotGlobalDirectoryName = TEXT("Global");
}

USlotGlobalSaveGameSubsystem* USlotGlobalSaveGameSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<USlotGlobalSaveGameSubsystem>();
		}
	}

	return nullptr;
}

UGenericSaveGame* USlotGlobalSaveGameSubsystem::CreateSlotGlobalSaveGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass)
{
	const FString SlotGlobalSlotName = BuildSlotGlobalSlotName(SlotName);
	if (SlotGlobalSlotName.IsEmpty())
	{
		return nullptr;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->CreateSaveGame(SlotGlobalSlotName, SaveGameClass) : nullptr;
}

bool USlotGlobalSaveGameSubsystem::DeleteSlotGlobalSaveGame(const FString& SlotName)
{
	const FString SlotGlobalSlotName = BuildSlotGlobalSlotName(SlotName);
	if (SlotGlobalSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->DeleteSaveGame(SlotGlobalSlotName) : false;
}

bool USlotGlobalSaveGameSubsystem::DeleteSlotGlobalSaveGame(UGenericSaveGame* SaveGame)
{
	if (!SaveGame)
	{
		return false;
	}

	FString SlotName = SaveGame->GetSlotName();
	if (SlotName.IsEmpty() && !SaveGame->GetPathName().IsEmpty())
	{
		SlotName = FPaths::GetBaseFilename(SaveGame->GetPathName());
	}
	return DeleteSlotGlobalSaveGame(SlotName);
}

bool USlotGlobalSaveGameSubsystem::AsyncSlotGlobalSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete)
{
	if (!SaveGame)
	{
		return false;
	}

	const FString SlotGlobalSlotName = BuildSlotGlobalSlotName(SlotName);
	if (SlotGlobalSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return false;
	}

	FSaveGameParameter SaveSetting;
	SaveSetting.SlotName = SlotGlobalSlotName;
	SaveSetting.SaveGame = SaveGame;
	SaveSetting.bOverwriteLocalFile = true;
	SaveSetting.bRefreshSaveGame = true;
	return SaveGameSubsystem->AsyncSaveGameToSlot(SaveSetting, OnComplete);
}

bool USlotGlobalSaveGameSubsystem::AsyncSlotGlobalLoadGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass, const FOnGenericSaveGameAsyncLoadComplete& OnComplete)
{
	const FString SlotGlobalSlotName = BuildSlotGlobalSlotName(SlotName);
	if (SlotGlobalSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return false;
	}

	FLoadGameParameter LoadSetting;
	LoadSetting.SlotName = SlotGlobalSlotName;
	LoadSetting.SaveGameClass = SaveGameClass;
	LoadSetting.bRefreshSaveGame = true;
	return SaveGameSubsystem->AsyncLoadGameFromSlot(LoadSetting, OnComplete);
}

UGenericSaveGame* USlotGlobalSaveGameSubsystem::GetSlotGlobalSaveGame(const FString& SlotName) const
{
	const FString SlotGlobalSlotName = BuildSlotGlobalSlotName(SlotName);
	if (SlotGlobalSlotName.IsEmpty())
	{
		return nullptr;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->GetSaveGame(SlotGlobalSlotName) : nullptr;
}

FString USlotGlobalSaveGameSubsystem::BuildSlotGlobalSlotName(const FString& SlotName) const
{
	const FGuid ActiveSlotGuid = GetActiveSlotGuid();
	if (!ActiveSlotGuid.IsValid() || SlotName.IsEmpty())
	{
		return FString();
	}

	FString NormalizedSlotName = SlotName;
	NormalizedSlotName.ReplaceInline(TEXT("\\"), TEXT("/"));
	NormalizedSlotName.RemoveFromStart(TEXT("/"));
	NormalizedSlotName.RemoveFromEnd(TEXT(".sav"), ESearchCase::IgnoreCase);
	if (NormalizedSlotName.IsEmpty())
	{
		return FString();
	}

	return FString::Printf(TEXT("%s/%s/%s/%s"), SlotGlobalRootDirectoryName, *ActiveSlotGuid.ToString(EGuidFormats::DigitsWithHyphens), SlotGlobalDirectoryName, *NormalizedSlotName);
}

FGuid USlotGlobalSaveGameSubsystem::GetActiveSlotGuid() const
{
	const UGenericSlotSaveGameSubsystem* SlotSubsystem = UGenericSlotSaveGameSubsystem::Get(this);
	return SlotSubsystem ? SlotSubsystem->GetActiveSaveGameSlotGuid() : FGuid();
}
