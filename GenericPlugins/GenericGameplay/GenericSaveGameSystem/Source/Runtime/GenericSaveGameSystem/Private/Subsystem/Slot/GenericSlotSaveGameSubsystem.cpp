// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/GenericSlotSaveGameSubsystem.h"

#include "Base/GenericSaveGameSlot.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameplayMessageSubsystem.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "SaveGameType.h"
#include "Subsystem/Base/GenericSaveGameSubsystem.h"
#include "Subsystems/SubsystemCollection.h"

namespace
{
	constexpr const TCHAR* SlotRootDirectoryName = TEXT("Slots");
	constexpr const TCHAR* SlotManifestFileName = TEXT("Manifest");

	struct FSaveGameSlotLoadState
	{
		int32 TotalCount = 0;
		TArray<FGuid> LoadedSlotGuids;
		TArray<FGuid> FailedSlotGuids;
	};

	void BroadcastSaveGameSlotLoadStartMessage(const UObject* WorldContextObject, const TArray<FGuid>& SlotGuids)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameSlotLoadStartMessage Message;
		Message.TotalCount = SlotGuids.Num();
		Message.SlotGuids = SlotGuids;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameSlotLoadStart, Message);
	}

	void BroadcastSaveGameSlotLoadOnceFinishMessage(const UObject* WorldContextObject, const FGuid& SlotGuid, UGenericSaveGameSlot* SaveGameSlot, const int32 CompletedCount, const int32 TotalCount)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameSlotLoadOnceFinishMessage Message;
		Message.SlotGuid = SlotGuid;
		Message.SaveGameSlot = SaveGameSlot;
		Message.CompletedCount = CompletedCount;
		Message.TotalCount = TotalCount;
		Message.bSuccess = SaveGameSlot != nullptr;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameSlotLoadOnceFinish, Message);
	}

	void BroadcastSaveGameSlotLoadFinishMessage(const UObject* WorldContextObject, const TArray<FGuid>& LoadedSlotGuids, const TArray<FGuid>& FailedSlotGuids)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameSlotLoadFinishMessage Message;
		Message.SuccessCount = LoadedSlotGuids.Num();
		Message.FailedCount = FailedSlotGuids.Num();
		Message.TotalCount = Message.SuccessCount + Message.FailedCount;
		Message.LoadedSlotGuids = LoadedSlotGuids;
		Message.FailedSlotGuids = FailedSlotGuids;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameSlotLoadFinish, Message);
	}

	void BroadcastSaveGameSlotEnterMessage(const UObject* WorldContextObject, const FGuid& SlotGuid, UGenericSaveGameSlot* SaveGameSlot)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameSlotEnterMessage Message;
		Message.SlotGuid = SlotGuid;
		Message.SaveGameSlot = SaveGameSlot;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameSlotEnter, Message);
	}

	void BroadcastSaveGameSlotLeaveMessage(const UObject* WorldContextObject, const FGuid& SlotGuid, UGenericSaveGameSlot* SaveGameSlot)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameSlotLeaveMessage Message;
		Message.SlotGuid = SlotGuid;
		Message.SaveGameSlot = SaveGameSlot;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameSlotLeave, Message);
	}

	void FinishSaveGameSlotLoadOnce(UGenericSlotSaveGameSubsystem* SlotSubsystem, const TSharedRef<FSaveGameSlotLoadState>& LoadState, const FGuid& SlotGuid, UGenericSaveGameSlot* SaveGameSlot)
	{
		if (SaveGameSlot && SlotSubsystem && SlotSubsystem->RegisterSaveGameSlot(SaveGameSlot))
		{
			LoadState->LoadedSlotGuids.Add(SlotGuid);
		}
		else
		{
			LoadState->FailedSlotGuids.Add(SlotGuid);
		}

		const int32 CompletedCount = LoadState->LoadedSlotGuids.Num() + LoadState->FailedSlotGuids.Num();
		BroadcastSaveGameSlotLoadOnceFinishMessage(SlotSubsystem, SlotGuid, SaveGameSlot, CompletedCount, LoadState->TotalCount);
		if (CompletedCount >= LoadState->TotalCount)
		{
			BroadcastSaveGameSlotLoadFinishMessage(SlotSubsystem, LoadState->LoadedSlotGuids, LoadState->FailedSlotGuids);
		}
	}
}

UGenericSlotSaveGameSubsystem* UGenericSlotSaveGameSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UGenericSlotSaveGameSubsystem>();
		}
	}

	return nullptr;
}

void UGenericSlotSaveGameSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Collection.InitializeDependency(UGenericSaveGameSubsystem::StaticClass());
	Super::Initialize(Collection);

	LoadLocalSaveGameSlots();
}

UGenericSaveGameSlot* UGenericSlotSaveGameSubsystem::CreateSaveGameSlot(const TSubclassOf<UGenericSaveGameSlot> SaveGameSlotClass)
{
	const FGuid SlotGuid = CreateUniqueSlotGuid();
	if (!SlotGuid.IsValid() || !EnsureSlotDirectory(SlotGuid))
	{
		return nullptr;
	}

	UClass* TargetClass = *SaveGameSlotClass ? SaveGameSlotClass.Get() : UGenericSaveGameSlot::StaticClass();
	UGenericSaveGameSlot* SaveGameSlot = NewObject<UGenericSaveGameSlot>(this, TargetClass);
	if (!SaveGameSlot)
	{
		return nullptr;
	}

	SaveGameSlot->SetSlotGuid(SlotGuid);

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem || !RegisterSaveGameSlot(SaveGameSlot))
	{
		IFileManager::Get().DeleteDirectory(*BuildSlotDirectory(SlotGuid), false, true);
		return nullptr;
	}

	FOnGenericSaveGameAsyncSaveComplete OnComplete;
	OnComplete.BindWeakLambda(this, [this, SlotGuid](const FString&, UGenericSaveGame*, const bool bSuccess)
	{
		if (!bSuccess)
		{
			UnregisterSaveGameSlot(SlotGuid);
			IFileManager::Get().DeleteDirectory(*BuildSlotDirectory(SlotGuid), false, true);
		}
	});

	FSaveGameParameter SaveSetting;
	SaveSetting.SlotName = BuildSlotSaveName(SlotGuid);
	SaveSetting.SaveGame = SaveGameSlot;
	SaveSetting.bOverwriteLocalFile = false;
	SaveSetting.bRefreshSaveGame = true;
	if (!SaveGameSubsystem->AsyncSaveGameToSlot(SaveSetting, OnComplete))
	{
		UnregisterSaveGameSlot(SlotGuid);
		IFileManager::Get().DeleteDirectory(*BuildSlotDirectory(SlotGuid), false, true);
		return nullptr;
	}

	return SaveGameSlot;
}

bool UGenericSlotSaveGameSubsystem::DeleteSaveGameSlot(const FGuid& SlotGuid)
{
	if (!SlotGuid.IsValid())
	{
		return false;
	}

	const FString SlotDirectory = BuildSlotDirectory(SlotGuid);
	const bool bDeletedDirectory = !IFileManager::Get().DirectoryExists(*SlotDirectory) || IFileManager::Get().DeleteDirectory(*SlotDirectory, false, true);
	if (bDeletedDirectory)
	{
		UnregisterSaveGameSlot(SlotGuid);
	}
	return bDeletedDirectory;
}

bool UGenericSlotSaveGameSubsystem::DeleteSaveGameSlot(UGenericSaveGameSlot* SaveGameSlot)
{
	return SaveGameSlot ? DeleteSaveGameSlot(SaveGameSlot->GetSlotGuid()) : false;
}

bool UGenericSlotSaveGameSubsystem::RegisterSaveGameSlot(UGenericSaveGameSlot* SaveGameSlot)
{
	if (!SaveGameSlot || !SaveGameSlot->GetSlotGuid().IsValid())
	{
		return false;
	}

	const FGuid SlotGuid = SaveGameSlot->GetSlotGuid();
	if (UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this))
	{
		if (!SaveGameSubsystem->RegisterSaveGame(BuildSlotSaveName(SlotGuid), SaveGameSlot))
		{
			return false;
		}
	}

	SaveGameSlots.Add(SlotGuid, SaveGameSlot);
	return true;
}

bool UGenericSlotSaveGameSubsystem::UnregisterSaveGameSlot(const FGuid& SlotGuid)
{
	if (!SlotGuid.IsValid())
	{
		return false;
	}

	if (ActiveSaveGameSlotGuid == SlotGuid)
	{
		LeaveSaveGameSlot();
	}

	const bool bHadRuntimeSlot = SaveGameSlots.Remove(SlotGuid) > 0;
	if (UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this))
	{
		SaveGameSubsystem->UnregisterSaveGame(BuildSlotSaveName(SlotGuid));
	}

	return bHadRuntimeSlot;
}

bool UGenericSlotSaveGameSubsystem::EnterSaveGameSlot(const FGuid& SlotGuid)
{
	if (!SlotGuid.IsValid())
	{
		return false;
	}

	UGenericSaveGameSlot* SaveGameSlot = GetSaveGameSlot(SlotGuid);
	if (!SaveGameSlot)
	{
		return false;
	}

	if (ActiveSaveGameSlotGuid == SlotGuid)
	{
		return true;
	}

	if (ActiveSaveGameSlotGuid.IsValid())
	{
		LeaveSaveGameSlot();
	}

	ActiveSaveGameSlotGuid = SlotGuid;
	BroadcastSaveGameSlotEnterMessage(this, SlotGuid, SaveGameSlot);
	return true;
}

bool UGenericSlotSaveGameSubsystem::LeaveSaveGameSlot()
{
	if (!ActiveSaveGameSlotGuid.IsValid())
	{
		return false;
	}

	const FGuid LeavingSlotGuid = ActiveSaveGameSlotGuid;
	UGenericSaveGameSlot* LeavingSaveGameSlot = GetSaveGameSlot(LeavingSlotGuid);
	ActiveSaveGameSlotGuid.Invalidate();
	BroadcastSaveGameSlotLeaveMessage(this, LeavingSlotGuid, LeavingSaveGameSlot);
	return true;
}

FGuid UGenericSlotSaveGameSubsystem::GetActiveSaveGameSlotGuid() const
{
	return ActiveSaveGameSlotGuid;
}

UGenericSaveGameSlot* UGenericSlotSaveGameSubsystem::GetSaveGameSlot(const FGuid& SlotGuid) const
{
	return SlotGuid.IsValid() ? SaveGameSlots.FindRef(SlotGuid) : nullptr;
}

TArray<UGenericSaveGameSlot*> UGenericSlotSaveGameSubsystem::GetSaveGameSlots() const
{
	TArray<UGenericSaveGameSlot*> Result;
	Result.Reserve(SaveGameSlots.Num());
	for (const TPair<FGuid, TObjectPtr<UGenericSaveGameSlot>>& Pair : SaveGameSlots)
	{
		Result.Add(Pair.Value);
	}
	return Result;
}

void UGenericSlotSaveGameSubsystem::LoadLocalSaveGameSlots()
{
	const FString SlotsRootDirectory = GetSlotsRootDirectory();
	TArray<FGuid> SlotGuids;
	if (IFileManager::Get().DirectoryExists(*SlotsRootDirectory))
	{
		TArray<FString> SlotDirectoryNames;
		IFileManager::Get().FindFiles(SlotDirectoryNames, *FPaths::Combine(SlotsRootDirectory, TEXT("*")), false, true);
		for (const FString& SlotDirectoryName : SlotDirectoryNames)
		{
			FGuid SlotGuid;
			if (FGuid::Parse(SlotDirectoryName, SlotGuid) && IFileManager::Get().FileExists(*FPaths::Combine(BuildSlotDirectory(SlotGuid), FString::Printf(TEXT("%s.sav"), SlotManifestFileName))))
			{
				SlotGuids.Add(SlotGuid);
			}
		}
	}

	BroadcastSaveGameSlotLoadStartMessage(this, SlotGuids);

	const TSharedRef<FSaveGameSlotLoadState> LoadState = MakeShared<FSaveGameSlotLoadState>();
	LoadState->TotalCount = SlotGuids.Num();
	if (LoadState->TotalCount == 0)
	{
		BroadcastSaveGameSlotLoadFinishMessage(this, LoadState->LoadedSlotGuids, LoadState->FailedSlotGuids);
		return;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	for (const FGuid& SlotGuid : SlotGuids)
	{
		FOnGenericSaveGameAsyncLoadComplete OnComplete;
		OnComplete.BindWeakLambda(this, [this, LoadState, SlotGuid](const FString&, UGenericSaveGame* LoadedSaveGame, const bool bSuccess)
		{
			UGenericSaveGameSlot* SaveGameSlot = bSuccess ? Cast<UGenericSaveGameSlot>(LoadedSaveGame) : nullptr;
			if (SaveGameSlot)
			{
				SaveGameSlot->SetSlotGuid(SlotGuid);
			}
			FinishSaveGameSlotLoadOnce(this, LoadState, SlotGuid, SaveGameSlot);
		});

		FLoadGameParameter LoadSetting;
		LoadSetting.SlotName = BuildSlotSaveName(SlotGuid);
		LoadSetting.SaveGameClass = UGenericSaveGameSlot::StaticClass();
		LoadSetting.bRefreshSaveGame = true;
		if (!SaveGameSubsystem || !SaveGameSubsystem->AsyncLoadGameFromSlot(LoadSetting, OnComplete))
		{
			FinishSaveGameSlotLoadOnce(this, LoadState, SlotGuid, nullptr);
		}
	}
}

FGuid UGenericSlotSaveGameSubsystem::CreateUniqueSlotGuid() const
{
	for (int32 TryIndex = 0; TryIndex < 64; ++TryIndex)
	{
		const FGuid SlotGuid = FGuid::NewGuid();
		if (!SaveGameSlots.Contains(SlotGuid) && !IFileManager::Get().DirectoryExists(*BuildSlotDirectory(SlotGuid)))
		{
			return SlotGuid;
		}
	}
	return FGuid();
}

FString UGenericSlotSaveGameSubsystem::BuildSlotSaveName(const FGuid& SlotGuid) const
{
	if (!SlotGuid.IsValid())
	{
		return FString();
	}

	return FString::Printf(TEXT("%s/%s/%s"), SlotRootDirectoryName, *SlotGuid.ToString(EGuidFormats::DigitsWithHyphens), SlotManifestFileName);
}

FString UGenericSlotSaveGameSubsystem::BuildSlotDirectory(const FGuid& SlotGuid) const
{
	return SlotGuid.IsValid() ? FPaths::Combine(GetSlotsRootDirectory(), SlotGuid.ToString(EGuidFormats::DigitsWithHyphens)) : FString();
}

FString UGenericSlotSaveGameSubsystem::GetSlotsRootDirectory() const
{
	return FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("SaveGames"), SlotRootDirectoryName);
}

bool UGenericSlotSaveGameSubsystem::EnsureSlotDirectory(const FGuid& SlotGuid) const
{
	const FString SlotDirectory = BuildSlotDirectory(SlotGuid);
	return !SlotDirectory.IsEmpty() && IFileManager::Get().MakeDirectory(*SlotDirectory, true);
}
