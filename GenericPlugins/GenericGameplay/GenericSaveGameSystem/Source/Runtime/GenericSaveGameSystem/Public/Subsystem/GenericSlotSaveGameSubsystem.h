// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "GenericSlotSaveGameSubsystem.generated.h"

class UGenericSaveGameSlot;

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameSlotLoadStartMessage
{
	GENERATED_BODY()

	/** 本次启动时发现的槽位 Manifest 总数，监听方可用它初始化进度。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	int32 TotalCount = 0;

	/** 将要恢复的槽位 GUID 列表。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	TArray<FGuid> SlotGuids;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameSlotLoadOnceFinishMessage
{
	GENERATED_BODY()

	/** 当前完成加载尝试的槽位 GUID。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	FGuid SlotGuid;

	/** 成功加载并注册后的槽位 Manifest；加载失败时为空。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	TObjectPtr<UGenericSaveGameSlot> SaveGameSlot = nullptr;

	/** 已经完成加载尝试的数量，成功和失败都会计入。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	int32 CompletedCount = 0;

	/** 本次启动时需要尝试加载的槽位 Manifest 总数。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	int32 TotalCount = 0;

	/** 标识当前 Manifest 是否成功恢复到槽位表。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	bool bSuccess = false;
};

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameSlotLoadFinishMessage
{
	GENERATED_BODY()

	/** 本次启动时需要尝试加载的槽位 Manifest 总数。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	int32 TotalCount = 0;

	/** 成功恢复到运行时槽位表的数量。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	int32 SuccessCount = 0;

	/** 加载失败或无法恢复的槽位数量。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	int32 FailedCount = 0;

	/** 已经成功加载的槽位 GUID 列表。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	TArray<FGuid> LoadedSlotGuids;

	/** 加载失败的槽位 GUID 列表。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Load Message")
	TArray<FGuid> FailedSlotGuids;
};

/** 存档槽被设为当前游玩进度时发出的消息，便于其他系统切换到槽位上下文。 */
USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameSlotEnterMessage
{
	GENERATED_BODY()

	/** 当前激活的槽位 GUID，对应 Saved/SaveGames/Slots/{Guid} 目录。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Message")
	FGuid SlotGuid;

	/** 被设为当前游玩进度的 Manifest 对象，监听方可从这里读取槽位展示或规则数据。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Message")
	TObjectPtr<UGenericSaveGameSlot> SaveGameSlot = nullptr;
};

/** 当前游玩进度被退出时发出的消息，便于依赖槽位上下文的系统清理缓存。 */
USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameSlotLeaveMessage
{
	GENERATED_BODY()

	/** 刚刚退出的槽位 GUID，广播后子系统的激活槽位会变为空。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Message")
	FGuid SlotGuid;

	/** 被退出的 Manifest 对象；如果槽位已被外部移除，该字段可能为空。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Slot Message")
	TObjectPtr<UGenericSaveGameSlot> SaveGameSlot = nullptr;
};

/** 管理游戏进度槽位，只负责 Slots/{Guid}/Manifest.sav 的创建、删除和启动恢复。 */
UCLASS(MinimalAPI)
class UGenericSlotSaveGameSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICSAVEGAMESYSTEM_API UGenericSlotSaveGameSubsystem* Get(const UObject* WorldContextObject);

	GENERICSAVEGAMESYSTEM_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** 创建新的游戏进度槽位，生成 GUID 并异步写入 Saved/SaveGames/Slots/{Guid}/Manifest.sav。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGameSlot* CreateSaveGameSlot(TSubclassOf<UGenericSaveGameSlot> SaveGameSlotClass = nullptr);

	/** 删除指定游戏进度槽位，包括运行时登记和 Saved/SaveGames/Slots/{Guid} 下的所有文件。 */
	GENERICSAVEGAMESYSTEM_API bool DeleteSaveGameSlot(const FGuid& SlotGuid);

	/** 删除传入槽位对象对应的游戏进度槽位。 */
	GENERICSAVEGAMESYSTEM_API bool DeleteSaveGameSlot(UGenericSaveGameSlot* SaveGameSlot);

	/** 把已存在的槽位 Manifest 纳入运行时表，并同步登记到底层 SaveGameSubsystem。 */
	GENERICSAVEGAMESYSTEM_API bool RegisterSaveGameSlot(UGenericSaveGameSlot* SaveGameSlot);

	/** 只移除运行时槽位登记，不删除本地槽位目录。 */
	GENERICSAVEGAMESYSTEM_API bool UnregisterSaveGameSlot(const FGuid& SlotGuid);

	/** 将指定槽位设为当前正在游玩的进度；只有已注册的 Manifest 才能被进入。 */
	GENERICSAVEGAMESYSTEM_API bool EnterSaveGameSlot(const FGuid& SlotGuid);

	/** 退出当前正在游玩的进度，并把激活槽位 GUID 清空。 */
	GENERICSAVEGAMESYSTEM_API bool LeaveSaveGameSlot();

	/** 返回当前激活的槽位 GUID；未进入任何槽位时返回无效 GUID。 */
	GENERICSAVEGAMESYSTEM_API FGuid GetActiveSaveGameSlotGuid() const;

	/** 按 GUID 查找已经恢复或创建的槽位 Manifest。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGameSlot* GetSaveGameSlot(const FGuid& SlotGuid) const;

	/** 返回当前运行时已知的所有游戏进度槽位。 */
	GENERICSAVEGAMESYSTEM_API TArray<UGenericSaveGameSlot*> GetSaveGameSlots() const;

private:
	/** 启动时扫描 Saved/SaveGames/Slots 下的 Manifest.sav，并异步恢复到槽位表。 */
	void LoadLocalSaveGameSlots();

	/** 生成未被运行时登记和本地目录占用的槽位 GUID。 */
	FGuid CreateUniqueSlotGuid() const;

	/** 将槽位 GUID 转为 UE SaveGame 槽位名，实际文件为 Saved/SaveGames/Slots/{Guid}/Manifest.sav。 */
	FString BuildSlotSaveName(const FGuid& SlotGuid) const;

	/** 返回槽位本地目录 Saved/SaveGames/Slots/{Guid}。 */
	FString BuildSlotDirectory(const FGuid& SlotGuid) const;

	/** 返回所有游戏进度槽位的根目录 Saved/SaveGames/Slots。 */
	FString GetSlotsRootDirectory() const;

	/** 确保单个槽位目录存在。 */
	bool EnsureSlotDirectory(const FGuid& SlotGuid) const;

	/** 以 GUID 作为索引，保存当前运行时可访问的槽位 Manifest。 */
	UPROPERTY(Transient)
	TMap<FGuid, TObjectPtr<UGenericSaveGameSlot>> SaveGameSlots;

	/** 当前正在游玩的进度槽位；为空表示尚未进入任何槽位。 */
	UPROPERTY(Transient)
	FGuid ActiveSaveGameSlotGuid;
};
