// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/Slot/SlotWorldSaveGameSubsystem.h"

#include "Base/GenericSaveGame.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Misc/Paths.h"
#include "Subsystem/GenericSlotSaveGameSubsystem.h"

namespace
{
	constexpr const TCHAR* SlotWorldRootDirectoryName = TEXT("Slots");
	constexpr const TCHAR* SlotWorldDirectoryName = TEXT("World");
}

USlotWorldSaveGameSubsystem* USlotWorldSaveGameSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		return World->GetSubsystem<USlotWorldSaveGameSubsystem>();
	}

	return nullptr;
}

UGenericSaveGame* USlotWorldSaveGameSubsystem::CreateSlotWorldSaveGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass)
{
	const FString WorldSlotName = BuildSlotWorldSlotName(SlotName);
	if (WorldSlotName.IsEmpty())
	{
		return nullptr;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->CreateSaveGame(WorldSlotName, SaveGameClass) : nullptr;
}

bool USlotWorldSaveGameSubsystem::DeleteSlotWorldSaveGame(const FString& SlotName)
{
	const FString WorldSlotName = BuildSlotWorldSlotName(SlotName);
	if (WorldSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->DeleteSaveGame(WorldSlotName) : false;
}

bool USlotWorldSaveGameSubsystem::DeleteSlotWorldSaveGame(UGenericSaveGame* SaveGame)
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
	return DeleteSlotWorldSaveGame(SlotName);
}

bool USlotWorldSaveGameSubsystem::AsyncSlotWorldSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete)
{
	if (!SaveGame)
	{
		return false;
	}

	const FString WorldSlotName = BuildSlotWorldSlotName(SlotName);
	if (WorldSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return false;
	}

	FSaveGameParameter SaveSetting;
	SaveSetting.SlotName = WorldSlotName;
	SaveSetting.SaveGame = SaveGame;
	SaveSetting.bOverwriteLocalFile = true;
	SaveSetting.bRefreshSaveGame = true;
	return SaveGameSubsystem->AsyncSaveGameToSlot(SaveSetting, OnComplete);
}

bool USlotWorldSaveGameSubsystem::AsyncSlotWorldLoadGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass, const FOnGenericSaveGameAsyncLoadComplete& OnComplete)
{
	const FString WorldSlotName = BuildSlotWorldSlotName(SlotName);
	if (WorldSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return false;
	}

	FLoadGameParameter LoadSetting;
	LoadSetting.SlotName = WorldSlotName;
	LoadSetting.SaveGameClass = SaveGameClass;
	LoadSetting.bRefreshSaveGame = true;
	return SaveGameSubsystem->AsyncLoadGameFromSlot(LoadSetting, OnComplete);
}

UGenericSaveGame* USlotWorldSaveGameSubsystem::GetSlotWorldSaveGame(const FString& SlotName) const
{
	const FString WorldSlotName = BuildSlotWorldSlotName(SlotName);
	if (WorldSlotName.IsEmpty())
	{
		return nullptr;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->GetSaveGame(WorldSlotName) : nullptr;
}

FString USlotWorldSaveGameSubsystem::BuildSlotWorldSlotName(const FString& SlotName) const
{
	const FGuid ActiveSlotGuid = GetActiveSlotGuid();
	const FString WorldIdentifier = GetWorldIdentifier();
	if (!ActiveSlotGuid.IsValid() || WorldIdentifier.IsEmpty() || SlotName.IsEmpty())
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

	return FString::Printf(TEXT("%s/%s/%s/%s/%s"), SlotWorldRootDirectoryName, *ActiveSlotGuid.ToString(EGuidFormats::DigitsWithHyphens), SlotWorldDirectoryName, *WorldIdentifier, *NormalizedSlotName);
}

FString USlotWorldSaveGameSubsystem::GetWorldIdentifier() const
{
	const UWorld* World = GetWorld();
	if (!World)
	{
		return FString();
	}

	FString PackageName = World->GetPackage() ? World->GetPackage()->GetName() : FString();
	PackageName = UWorld::RemovePIEPrefix(PackageName);
	PackageName.ReplaceInline(TEXT("\\"), TEXT("/"));
	PackageName.RemoveFromStart(TEXT("/"));
	PackageName.RemoveFromEnd(TEXT("/"));
	return PackageName;
}

FGuid USlotWorldSaveGameSubsystem::GetActiveSlotGuid() const
{
	const UGenericSlotSaveGameSubsystem* SlotSubsystem = UGenericSlotSaveGameSubsystem::Get(this);
	return SlotSubsystem ? SlotSubsystem->GetActiveSaveGameSlotGuid() : FGuid();
}
