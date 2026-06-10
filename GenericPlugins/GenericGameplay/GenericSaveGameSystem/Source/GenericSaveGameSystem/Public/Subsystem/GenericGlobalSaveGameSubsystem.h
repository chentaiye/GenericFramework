// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "Subsystem/Base/GenericSaveGameSubsystem.h"
#include "GenericGlobalSaveGameSubsystem.generated.h"

/** 提供全局存档入口，把调用方传入的逻辑槽位固定映射到 Saved/SaveGames/Global 目录。 */
USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnGlobalSaveGameLoadStartMessage
{
	GENERATED_BODY()

	/** 本次启动时发现的全局存档槽位总数，监听方可用它初始化加载进度。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	int32 TotalCount = 0;

	/** 将要恢复到运行时注册表的 Global 槽位名列表。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	TArray<FString> SlotNames;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnGlobalSaveGameLoadOnceFinishMessage
{
	GENERATED_BODY()

	/** 当前完成加载尝试的 Global 槽位名。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	FString SlotName;

	/** 成功加载并刷新后的 SaveGame；加载失败时为空。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;

	/** 已经完成加载尝试的数量，成功和失败都会计入。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	int32 CompletedCount = 0;

	/** 本次启动时需要尝试加载的全局存档总数。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	int32 TotalCount = 0;

	/** 标识当前槽位是否成功恢复到中心 SaveGame 存储表。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	bool bSuccess = false;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnGlobalSaveGameLoadFinishMessage
{
	GENERATED_BODY()

	/** 本次启动时需要尝试加载的全局存档总数。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	int32 TotalCount = 0;

	/** 成功恢复到运行时注册表的全局存档数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	int32 SuccessCount = 0;

	/** 加载失败或无法恢复的全局存档数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	int32 FailedCount = 0;

	/** 已经成功加载的 Global 槽位名列表。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	TArray<FString> LoadedSlotNames;

	/** 加载失败的 Global 槽位名列表。 */
	UPROPERTY(BlueprintReadOnly, Category="Global SaveGame Load Message")
	TArray<FString> FailedSlotNames;
};

UCLASS(MinimalAPI)
class UGenericGlobalSaveGameSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICSAVEGAMESYSTEM_API UGenericGlobalSaveGameSubsystem* Get(const UObject* WorldContextObject);

	GENERICSAVEGAMESYSTEM_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** 在全局目录创建 SaveGame 文件，成功后登记到 Global/SlotName 运行时槽位。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame* CreateGlobalSaveGame(const FString& SlotName, TSubclassOf<UGenericSaveGame> SaveGameClass = nullptr);

	/** 删除 Global/SlotName 对应的本地 SaveGame 文件，并清理运行时登记。 */
	GENERICSAVEGAMESYSTEM_API bool DeleteGlobalSaveGame(const FString& SlotName);

	/** 把传入 SaveGame 异步写入全局目录，实际写入路径为 Saved/SaveGames/Global/SlotName。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncGlobalSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete = FOnGenericSaveGameAsyncSaveComplete());

	/** 从全局目录异步读取指定槽位，实际读取路径为 Saved/SaveGames/Global/SlotName。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncGlobalLoadGame(const FString& SlotName, TSubclassOf<UGenericSaveGame> SaveGameClass = nullptr, const FOnGenericSaveGameAsyncLoadComplete& OnComplete = FOnGenericSaveGameAsyncLoadComplete());

	/** 查找 Global/SlotName 下已经手动创建、加载或登记的全局存档实例。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame* GetGlobalSaveGame(const FString& SlotName) const;

	/** 返回当前已经恢复或创建的所有全局 SaveGame 实例。 */
	GENERICSAVEGAMESYSTEM_API TArray<UGenericSaveGame*> GetGlobalSaveGames() const;

private:
	/** 初始化时扫描 Saved/SaveGames/Global 下已有的 .sav 文件并恢复到中心存储表。 */
	void LoadLocalGlobalSaveGames();

	/** 将绝对 .sav 文件路径转换成 UE SaveGame 使用的槽位名，例如 Global/A.sav 转成 Global/A。 */
	FString BuildGlobalSlotNameFromSaveFile(const FString& SaveFilePath) const;

	/** 生成传给 UE SaveGame 系统的全局槽位名，保留调用方传入的子路径语义。 */
	FString BuildGlobalSlotName(const FString& SlotName) const;

	/** 确保全局存档目录存在，避免带子目录的槽位在首次保存时因目录缺失失败。 */
	bool EnsureGlobalSaveDirectory(const FString& GlobalSlotName) const;
};
