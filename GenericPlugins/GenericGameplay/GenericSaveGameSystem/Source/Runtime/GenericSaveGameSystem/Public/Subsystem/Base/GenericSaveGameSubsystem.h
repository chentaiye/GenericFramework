// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "GenericSaveGameSubsystem.generated.h"

class UGenericSaveGame;
class APlayerController;

DECLARE_DELEGATE_ThreeParams(FOnGenericSaveGameAsyncSaveComplete, const FString& /*SlotName*/, UGenericSaveGame* /*SaveGame*/, bool /*bSuccess*/);
DECLARE_DELEGATE_ThreeParams(FOnGenericSaveGameAsyncLoadComplete, const FString& /*SlotName*/, UGenericSaveGame* /*SaveGame*/, bool /*bSuccess*/);

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameRegisteredMessage
{
	GENERATED_BODY()

	/** 标识本次登记使用的完整槽位名，包含 Global/World/Player 等上层入口拼出的路径前缀。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Registered Message")
	FString SlotName;

	/** 本次被写入运行时存储表的 SaveGame 对象。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Registered Message")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameUnregisteredMessage
{
	GENERATED_BODY()

	/** 标识本次移除的完整槽位名，监听方可用它同步清理自己的缓存索引。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Unregistered Message")
	FString SlotName;

	/** 被移出运行时存储表的 SaveGame 对象；若对象已失效则可能为空。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Unregistered Message")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;
};

/** SaveGame 元数据刷新后发送的消息，供监听方同步槽位缓存或界面状态。 */
USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameRefreshMessage
{
	GENERATED_BODY()

	/** 标识本次刷新对应的完整槽位名，监听方可用它同步更新自己的运行时索引。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Refresh Message")
	FString SlotName;

	/** 已经完成槽位名、路径、类包名和保存时间同步的 SaveGame 对象。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Refresh Message")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;
};

/** 异步保存槽位时使用的完整参数，调用方可控制是否允许覆盖已有本地文件以及是否同步元数据。 */
USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameSaveStartMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Start Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Start Message")
	FString SlotName;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Start Message")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Start Message")
	bool bOverwriteLocalFile = true;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Start Message")
	bool bRefreshSaveGame = true;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameSaveFinishMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Finish Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Finish Message")
	FString SlotName;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Finish Message")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Save Finish Message")
	bool bSuccess = false;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameLoadStartMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Load Start Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Load Start Message")
	FString SlotName;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Load Start Message")
	TSubclassOf<UGenericSaveGame> SaveGameClass;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Load Start Message")
	bool bRefreshSaveGame = true;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameLoadFinishMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Load Finish Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Load Finish Message")
	FString SlotName;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Load Finish Message")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="SaveGame Load Finish Message")
	bool bSuccess = false;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FSaveGameParameter
{
	GENERATED_BODY()

	/** UE SaveGame 系统使用的完整槽位名，可包含 Global/Slots/World 等上层入口前缀。 */
	UPROPERTY(BlueprintReadWrite, Category="SaveGame Parameter")
	FString SlotName;

	/** 将要写入槽位并登记到中心运行时表的 SaveGame 对象。 */
	UPROPERTY(BlueprintReadWrite, Category="SaveGame Parameter")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;

	/** 为 false 时若本地已存在同名 .sav 文件则拒绝提交保存，避免误覆盖已有存档。 */
	UPROPERTY(BlueprintReadWrite, Category="SaveGame Parameter")
	bool bOverwriteLocalFile = true;

	/** 为 true 时在对象登记后刷新槽位名、路径、类包名和保存时间。 */
	UPROPERTY(BlueprintReadWrite, Category="SaveGame Parameter")
	bool bRefreshSaveGame = true;

	/** 传给 UE SaveGame 系统的本地用户索引，PC 默认使用 0。 */
	UPROPERTY(BlueprintReadWrite, Category="SaveGame Parameter")
	TObjectPtr<APlayerController> PlayerController = nullptr;
};

/** 异步读取槽位时使用的完整参数，加载成功后会登记到中心运行时表。 */
USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FLoadGameParameter
{
	GENERATED_BODY()

	/** UE SaveGame 系统使用的完整槽位名，可包含 Global/Slots/World 等上层入口前缀。 */
	UPROPERTY(BlueprintReadWrite, Category="LoadGame Parameter")
	FString SlotName;

	/** 可选的类型校验；为空时只要求加载结果继承 UGenericSaveGame。 */
	UPROPERTY(BlueprintReadWrite, Category="LoadGame Parameter")
	TSubclassOf<UGenericSaveGame> SaveGameClass;

	/** 为 true 时在对象登记后刷新槽位名、路径、类包名和保存时间。 */
	UPROPERTY(BlueprintReadWrite, Category="LoadGame Parameter")
	bool bRefreshSaveGame = true;

	/** 传给 UE SaveGame 系统的本地用户索引，PC 默认使用 0。 */
	UPROPERTY(BlueprintReadWrite, Category="LoadGame Parameter")
	TObjectPtr<APlayerController> PlayerController = nullptr;
};

/** 作为 SaveGame 的中心存储表，统一处理本地槽位文件、元数据刷新和运行时对象登记。 */
UCLASS(MinimalAPI)
class UGenericSaveGameSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICSAVEGAMESYSTEM_API UGenericSaveGameSubsystem* Get(const UObject* WorldContextObject);

	/** 创建指定类型的本地 SaveGame 文件，写入成功后把运行时对象登记到同名槽位。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame* CreateSaveGame(const FString& SlotName, TSubclassOf<UGenericSaveGame> SaveGameClass = nullptr);

	/** 删除指定槽位的本地 SaveGame 文件，并清理同名运行时登记。 */
	GENERICSAVEGAMESYSTEM_API bool DeleteSaveGame(const FString& SlotName);

	/** 按槽位名手动登记 SaveGame；同对象重复登记直接成功，不刷新元数据。 */
	GENERICSAVEGAMESYSTEM_API bool RegisterSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame);

	/** 移除指定槽位的运行时登记，不触发磁盘删除。 */
	GENERICSAVEGAMESYSTEM_API bool UnregisterSaveGame(const FString& SlotName);

	/** 异步把传入对象写入槽位；提交前先登记对象，并按参数决定是否刷新元数据和覆盖本地文件。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncSaveGameToSlot(const FSaveGameParameter& Parameter, const FOnGenericSaveGameAsyncSaveComplete& OnComplete = FOnGenericSaveGameAsyncSaveComplete());

	/** 使用 SaveGame 自身保存的 SlotName 异步写入槽位。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncSaveGameToSlot(UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete = FOnGenericSaveGameAsyncSaveComplete());

	/** 异步从槽位读取 SaveGame；加载成功后登记对象，并按参数决定是否刷新元数据。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncLoadGameFromSlot(const FLoadGameParameter& Parameter, const FOnGenericSaveGameAsyncLoadComplete& OnComplete = FOnGenericSaveGameAsyncLoadComplete());

	/** 统一刷新 SaveGame 的槽位、路径、类包名和保存时间，避免各保存加载分支重复处理元数据。 */
	GENERICSAVEGAMESYSTEM_API bool RefreshSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame) const;

	/** 查找已经手动登记的 SaveGame，未登记或对象失效时返回空。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame* GetSaveGame(const FString& SlotName) const;

private:
	/** 确保带子路径的槽位能在 Saved/SaveGames 下正常落盘。 */
	bool EnsureSaveDirectory(const FString& SlotName) const;

	/** 注册前统一执行 SaveGame 版本缓存、校验和必要迁移，失败时不允许进入运行时表。 */
	bool ProcessSaveGameVersion(UGenericSaveGame* SaveGame) const;

	/** 由外部系统手动维护的 SaveGame 实例索引。 */
	UPROPERTY(Transient)
	TMap<FString, TObjectPtr<UGenericSaveGame>> RegisteredSaveGames;
};
