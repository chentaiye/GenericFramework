// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/GenericAutoSaveSubsystem.h"

#include "Engine/Engine.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "SaveGameType.h"
#include "Settings/GenericSaveGameSettings.h"
#include "Subsystem/Base/GenericSaveGameSubsystem.h"
#include "TimerManager.h"

namespace
{
	struct FAutoSaveFlushState
	{
		int32 TotalCount = 0;
		int32 SuccessCount = 0;
		int32 FailedCount = 0;
		TArray<TWeakObjectPtr<UGenericSaveGame>> SavedSaveGames;
		TArray<TWeakObjectPtr<UGenericSaveGame>> FailedSaveGames;
	};

	TArray<TObjectPtr<UGenericSaveGame>> ToMessageSaveGameArray(const TArray<TWeakObjectPtr<UGenericSaveGame>>& InSaveGames)
	{
		TArray<TObjectPtr<UGenericSaveGame>> Result;
		Result.Reserve(InSaveGames.Num());
		for (const TWeakObjectPtr<UGenericSaveGame>& SaveGame : InSaveGames)
		{
			if (UGenericSaveGame* StrongSaveGame = SaveGame.Get())
			{
				Result.Add(StrongSaveGame);
			}
		}
		return Result;
	}

	void BroadcastAutoSaveStartMessage(const UObject* WorldContextObject, APlayerController* PlayerController, const TArray<TWeakObjectPtr<UGenericSaveGame>>& SaveGames)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnAutoSaveStartMessage Message;
		Message.PlayerController = PlayerController;
		Message.TotalCount = SaveGames.Num();
		Message.SaveGames = ToMessageSaveGameArray(SaveGames);
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnAutoSaveStart, Message);
	}

	void BroadcastAutoSaveFinishMessage(const UObject* WorldContextObject, APlayerController* PlayerController, const FAutoSaveFlushState& FlushState)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnAutoSaveFinishMessage Message;
		Message.PlayerController = PlayerController;
		Message.SuccessCount = FlushState.SuccessCount;
		Message.FailedCount = FlushState.FailedCount;
		Message.TotalCount = FlushState.TotalCount;
		Message.SavedSaveGames = ToMessageSaveGameArray(FlushState.SavedSaveGames);
		Message.FailedSaveGames = ToMessageSaveGameArray(FlushState.FailedSaveGames);
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnAutoSaveFinish, Message);
	}

	void FinishAutoSaveOnce(const UObject* WorldContextObject, const TSharedRef<FAutoSaveFlushState>& FlushState, APlayerController* PlayerController, UGenericSaveGame* SaveGame, const bool bSuccess)
	{
		if (bSuccess)
		{
			++FlushState->SuccessCount;
			FlushState->SavedSaveGames.Add(SaveGame);
		}
		else
		{
			++FlushState->FailedCount;
			FlushState->FailedSaveGames.Add(SaveGame);
		}

		if (FlushState->SuccessCount + FlushState->FailedCount >= FlushState->TotalCount)
		{
			BroadcastAutoSaveFinishMessage(WorldContextObject, PlayerController, *FlushState);
		}
	}
}

UGenericAutoSaveSubsystem* UGenericAutoSaveSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UGenericAutoSaveSubsystem>(LocalPlayer);
}

UGenericAutoSaveSubsystem* UGenericAutoSaveSubsystem::Get(const APlayerController* PlayerController)
{
	return PlayerController ? ULocalPlayer::GetSubsystem<UGenericAutoSaveSubsystem>(PlayerController->GetLocalPlayer()) : nullptr;
}

UGenericAutoSaveSubsystem* UGenericAutoSaveSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(WorldContextObject))
	{
		return Get(LocalPlayer);
	}

	if (const APlayerController* PlayerController = Cast<APlayerController>(WorldContextObject))
	{
		return Get(PlayerController);
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (APlayerController* PlayerController = World->GetFirstPlayerController())
		{
			return Get(PlayerController);
		}
	}

	return nullptr;
}

void UGenericAutoSaveSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (UGameplayMessageSubsystem::HasInstance(this))
	{
		DirtyListenerHandle = UGameplayMessageSubsystem::Get(this).RegisterListener<FOnSaveGameDirtyMessage>(
			TAG_GameplayMessage_Channel_SaveGame_OnSaveGameDirty,
			this,
			&UGenericAutoSaveSubsystem::HandleSaveGameDirty);
	}

	StartAutoSaveTimer();
}

void UGenericAutoSaveSubsystem::Deinitialize()
{
	StopAutoSaveTimer();
	DirtyListenerHandle.Unregister();
	DirtySaveGames.Reset();
	SavingSaveGames.Reset();
	Super::Deinitialize();
}

int32 UGenericAutoSaveSubsystem::FlushDirtySaveGames()
{
	const UGenericSaveGameSettings* SaveGameSettings = UGenericSaveGameSettings::Get();
	if (!SaveGameSettings || !SaveGameSettings->bEnableAutoSave)
	{
		return 0;
	}

	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	if (!SaveGameSubsystem)
	{
		return 0;
	}

	TArray<TWeakObjectPtr<UGenericSaveGame>> PendingSaveGames = DirtySaveGames;
	TArray<TWeakObjectPtr<UGenericSaveGame>> SaveGamesToSubmit;
	for (const TWeakObjectPtr<UGenericSaveGame>& WeakSaveGame : PendingSaveGames)
	{
		UGenericSaveGame* SaveGame = WeakSaveGame.Get();
		if (!SaveGame || !SaveGame->GetIsDirty())
		{
			RemoveSaveGameFromArray(DirtySaveGames, SaveGame);
			continue;
		}

		if (SaveGame->GetSlotName().IsEmpty() || IsSaveGameInArray(SavingSaveGames, SaveGame))
		{
			continue;
		}

		SaveGamesToSubmit.Add(SaveGame);
	}

	if (SaveGamesToSubmit.IsEmpty())
	{
		return 0;
	}

	APlayerController* PlayerController = GetLocalPlayerController();
	BroadcastAutoSaveStartMessage(this, PlayerController, SaveGamesToSubmit);

	int32 SubmittedCount = 0;
	const TSharedRef<FAutoSaveFlushState> FlushState = MakeShared<FAutoSaveFlushState>();
	FlushState->TotalCount = SaveGamesToSubmit.Num();
	for (const TWeakObjectPtr<UGenericSaveGame>& WeakSaveGame : SaveGamesToSubmit)
	{
		UGenericSaveGame* SaveGame = WeakSaveGame.Get();
		if (!SaveGame)
		{
			FinishAutoSaveOnce(this, FlushState, PlayerController, nullptr, false);
			continue;
		}

		const int32 DirtySerial = SaveGame->GetDirtySerial();
		FSaveGameParameter SaveParameter;
		SaveParameter.SlotName = SaveGame->GetSlotName();
		SaveParameter.SaveGame = SaveGame;
		SaveParameter.bOverwriteLocalFile = true;
		SaveParameter.bRefreshSaveGame = true;
		SaveParameter.PlayerController = PlayerController;

		FOnGenericSaveGameAsyncSaveComplete OnComplete;
		OnComplete.BindWeakLambda(this, [this, WeakSaveGame, DirtySerial, FlushState, PlayerController](const FString&, UGenericSaveGame*, const bool bSuccess)
		{
			UGenericSaveGame* CompletedSaveGame = WeakSaveGame.Get();
			RemoveSaveGameFromArray(SavingSaveGames, CompletedSaveGame);
			if (!CompletedSaveGame)
			{
				FinishAutoSaveOnce(this, FlushState, PlayerController, nullptr, false);
				return;
			}

			if (bSuccess && CompletedSaveGame->GetIsDirty())
			{
				CompletedSaveGame->ClearDirty(DirtySerial);
			}

			if (CompletedSaveGame->GetIsDirty())
			{
				DirtySaveGames.AddUnique(CompletedSaveGame);
			}

			FinishAutoSaveOnce(this, FlushState, PlayerController, CompletedSaveGame, bSuccess);
		});

		if (SaveGameSubsystem->AsyncSaveGameToSlot(SaveParameter, OnComplete))
		{
			SavingSaveGames.AddUnique(SaveGame);
			++SubmittedCount;
			continue;
		}

		FinishAutoSaveOnce(this, FlushState, PlayerController, SaveGame, false);
	}

	return SubmittedCount;
}

void UGenericAutoSaveSubsystem::HandleSaveGameDirty(FGameplayTag InChannel, const FOnSaveGameDirtyMessage& InMessage)
{
	(void)InChannel;

	UGenericSaveGame* SaveGame = InMessage.SaveGame;
	if (!SaveGame)
	{
		return;
	}

	if (InMessage.bIsDirty)
	{
		DirtySaveGames.AddUnique(SaveGame);
		return;
	}

	RemoveSaveGameFromArray(DirtySaveGames, SaveGame);
}

void UGenericAutoSaveSubsystem::HandleAutoSaveTimer()
{
	FlushDirtySaveGames();
}

void UGenericAutoSaveSubsystem::StartAutoSaveTimer()
{
	const UGenericSaveGameSettings* SaveGameSettings = UGenericSaveGameSettings::Get();
	UWorld* World = GetWorld();
	if (!SaveGameSettings || !SaveGameSettings->bEnableAutoSave || !World)
	{
		return;
	}

	const float AutoSaveInterval = FMath::Max(0.1f, SaveGameSettings->AutoSaveInterval);
	World->GetTimerManager().SetTimer(AutoSaveTimerHandle, this, &UGenericAutoSaveSubsystem::HandleAutoSaveTimer, AutoSaveInterval, true);
}

void UGenericAutoSaveSubsystem::StopAutoSaveTimer()
{
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(AutoSaveTimerHandle);
	}
}

APlayerController* UGenericAutoSaveSubsystem::GetLocalPlayerController() const
{
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer)
	{
		return nullptr;
	}

	return LocalPlayer->GetPlayerController(GetWorld());
}

void UGenericAutoSaveSubsystem::RemoveSaveGameFromArray(TArray<TWeakObjectPtr<UGenericSaveGame>>& InArray, const UGenericSaveGame* SaveGame) const
{
	InArray.RemoveAll(
		[SaveGame](const TWeakObjectPtr<UGenericSaveGame>& WeakSaveGame)
		{
			return !WeakSaveGame.IsValid() || WeakSaveGame.Get() == SaveGame;
		});
}

bool UGenericAutoSaveSubsystem::IsSaveGameInArray(const TArray<TWeakObjectPtr<UGenericSaveGame>>& InArray, const UGenericSaveGame* SaveGame) const
{
	for (const TWeakObjectPtr<UGenericSaveGame>& WeakSaveGame : InArray)
	{
		if (WeakSaveGame.Get() == SaveGame)
		{
			return true;
		}
	}
	return false;
}
