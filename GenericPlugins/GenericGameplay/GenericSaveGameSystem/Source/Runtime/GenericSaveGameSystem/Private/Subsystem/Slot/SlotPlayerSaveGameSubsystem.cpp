// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/Slot/SlotPlayerSaveGameSubsystem.h"

#include "Base/GenericSaveGame.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "Misc/Paths.h"
#include "Subsystem/GenericSlotSaveGameSubsystem.h"

namespace
{
	constexpr const TCHAR* SlotPlayerRootDirectoryName = TEXT("Slots");
	constexpr const TCHAR* SlotPlayerDirectoryName = TEXT("Player");
}

USlotPlayerSaveGameSubsystem* USlotPlayerSaveGameSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<USlotPlayerSaveGameSubsystem>(LocalPlayer);
}

USlotPlayerSaveGameSubsystem* USlotPlayerSaveGameSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<USlotPlayerSaveGameSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UGenericSaveGame* USlotPlayerSaveGameSubsystem::CreateSlotPlayerSaveGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass)
{
	const FString PlayerSlotName = BuildSlotPlayerSlotName(SlotName);
	if (PlayerSlotName.IsEmpty())
	{
		return nullptr;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->CreateSaveGame(PlayerSlotName, SaveGameClass) : nullptr;
}

bool USlotPlayerSaveGameSubsystem::DeleteSlotPlayerSaveGame(const FString& SlotName)
{
	const FString PlayerSlotName = BuildSlotPlayerSlotName(SlotName);
	if (PlayerSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->DeleteSaveGame(PlayerSlotName) : false;
}

bool USlotPlayerSaveGameSubsystem::DeleteSlotPlayerSaveGame(UGenericSaveGame* SaveGame)
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
	return DeleteSlotPlayerSaveGame(SlotName);
}

bool USlotPlayerSaveGameSubsystem::AsyncSlotPlayerSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete)
{
	if (!SaveGame)
	{
		return false;
	}

	const FString PlayerSlotName = BuildSlotPlayerSlotName(SlotName);
	if (PlayerSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return false;
	}

	FSaveGameParameter SaveSetting;
	SaveSetting.SlotName = PlayerSlotName;
	SaveSetting.SaveGame = SaveGame;
	SaveSetting.bOverwriteLocalFile = true;
	SaveSetting.bRefreshSaveGame = true;
	SaveSetting.PlayerController = GetLocalPlayer() ? GetLocalPlayer()->GetPlayerController(GetWorld()) : nullptr;
	return SaveGameSubsystem->AsyncSaveGameToSlot(SaveSetting, OnComplete);
}

bool USlotPlayerSaveGameSubsystem::AsyncSlotPlayerLoadGame(const FString& SlotName, const TSubclassOf<UGenericSaveGame> SaveGameClass, const FOnGenericSaveGameAsyncLoadComplete& OnComplete)
{
	const FString PlayerSlotName = BuildSlotPlayerSlotName(SlotName);
	if (PlayerSlotName.IsEmpty())
	{
		return false;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return false;
	}

	FLoadGameParameter LoadSetting;
	LoadSetting.SlotName = PlayerSlotName;
	LoadSetting.SaveGameClass = SaveGameClass;
	LoadSetting.bRefreshSaveGame = true;
	LoadSetting.PlayerController = GetLocalPlayer() ? GetLocalPlayer()->GetPlayerController(GetWorld()) : nullptr;
	return SaveGameSubsystem->AsyncLoadGameFromSlot(LoadSetting, OnComplete);
}

UGenericSaveGame* USlotPlayerSaveGameSubsystem::GetSlotPlayerSaveGame(const FString& SlotName) const
{
	const FString PlayerSlotName = BuildSlotPlayerSlotName(SlotName);
	if (PlayerSlotName.IsEmpty())
	{
		return nullptr;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem ? SaveGameSubsystem->GetSaveGame(PlayerSlotName) : nullptr;
}

FString USlotPlayerSaveGameSubsystem::BuildSlotPlayerSlotName(const FString& SlotName) const
{
	const FGuid ActiveSlotGuid = GetActiveSlotGuid();
	const FString PlayerIdentifier = GetPlayerIdentifier();
	if (!ActiveSlotGuid.IsValid() || PlayerIdentifier.IsEmpty() || SlotName.IsEmpty())
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

	return FString::Printf(TEXT("%s/%s/%s/%s/%s"), SlotPlayerRootDirectoryName, *ActiveSlotGuid.ToString(EGuidFormats::DigitsWithHyphens), SlotPlayerDirectoryName, *PlayerIdentifier, *NormalizedSlotName);
}

FString USlotPlayerSaveGameSubsystem::GetPlayerIdentifier() const
{
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer)
	{
		return FString();
	}

	const FPlatformUserId PlatformUserId = LocalPlayer->GetPlatformUserId();
	const int32 PlatformUserIndex = PlatformUserId.IsValid() ? PlatformUserId.GetInternalId() : LocalPlayer->GetPlatformUserIndex();
	const int32 LocalPlayerIndex = LocalPlayer->GetLocalPlayerIndex();
	const int32 StableLocalPlayerIndex = LocalPlayerIndex >= 0 ? LocalPlayerIndex : LocalPlayer->GetControllerId();
	return FString::Printf(TEXT("PlatformUser_%d_LocalPlayer_%d"), PlatformUserIndex, StableLocalPlayerIndex);
}

FGuid USlotPlayerSaveGameSubsystem::GetActiveSlotGuid() const
{
	const UGenericSlotSaveGameSubsystem* SlotSubsystem = UGenericSlotSaveGameSubsystem::Get(this);
	return SlotSubsystem ? SlotSubsystem->GetActiveSaveGameSlotGuid() : FGuid();
}
