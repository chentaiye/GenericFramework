// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericSaveGame.h"
#include "GameplayMessageSubsystem.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "TimerManager.h"
#include "GenericAutoSaveSubsystem.generated.h"

/** 监听 SaveGame Dirty 消息，并按设置周期统一异步保存 Dirty 对象。 */
class APlayerController;
class ULocalPlayer;

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnAutoSaveStartMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Start Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Start Message")
	int32 TotalCount = 0;

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Start Message")
	TArray<TObjectPtr<UGenericSaveGame>> SaveGames;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnAutoSaveFinishMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Finish Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Finish Message")
	int32 SuccessCount = 0;

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Finish Message")
	int32 FailedCount = 0;

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Finish Message")
	int32 TotalCount = 0;

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Finish Message")
	TArray<TObjectPtr<UGenericSaveGame>> SavedSaveGames;

	UPROPERTY(BlueprintReadOnly, Category="AutoSave Finish Message")
	TArray<TObjectPtr<UGenericSaveGame>> FailedSaveGames;
};

UCLASS(MinimalAPI)
class UGenericAutoSaveSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	static GENERICSAVEGAMESYSTEM_API UGenericAutoSaveSubsystem* Get(const ULocalPlayer* LocalPlayer);
	static GENERICSAVEGAMESYSTEM_API UGenericAutoSaveSubsystem* Get(const APlayerController* PlayerController);
	static GENERICSAVEGAMESYSTEM_API UGenericAutoSaveSubsystem* Get(const UObject* WorldContextObject);

	GENERICSAVEGAMESYSTEM_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICSAVEGAMESYSTEM_API virtual void Deinitialize() override;

	/** 立刻提交当前缓存的 Dirty SaveGame；仍然使用异步保存，不阻塞游戏线程。 */
	GENERICSAVEGAMESYSTEM_API int32 FlushDirtySaveGames();

private:
	void HandleSaveGameDirty(FGameplayTag InChannel, const FOnSaveGameDirtyMessage& InMessage);
	void HandleAutoSaveTimer();
	void StartAutoSaveTimer();
	void StopAutoSaveTimer();
	APlayerController* GetLocalPlayerController() const;
	void RemoveSaveGameFromArray(TArray<TWeakObjectPtr<UGenericSaveGame>>& InArray, const UGenericSaveGame* SaveGame) const;
	bool IsSaveGameInArray(const TArray<TWeakObjectPtr<UGenericSaveGame>>& InArray, const UGenericSaveGame* SaveGame) const;

private:
	FGameplayMessageListenerHandle DirtyListenerHandle;
	FTimerHandle AutoSaveTimerHandle;
	TArray<TWeakObjectPtr<UGenericSaveGame>> DirtySaveGames;
	TArray<TWeakObjectPtr<UGenericSaveGame>> SavingSaveGames;
};
