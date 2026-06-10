// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/Base/GenericSaveGameSubsystem.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "SlotWorldSaveGameSubsystem.generated.h"

/** 提供当前进度槽位下的世界存档入口，把数据固定写入激活槽位的 World 目录。 */
UCLASS(MinimalAPI)
class USlotWorldSaveGameSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	static GENERICSAVEGAMESYSTEM_API USlotWorldSaveGameSubsystem* Get(const UObject* WorldContextObject);

	/** 在当前激活进度槽位的 World 目录下创建 SaveGame 文件；未进入槽位或世界无有效标识时不会创建对象。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame* CreateSlotWorldSaveGame(const FString& SlotName, TSubclassOf<UGenericSaveGame> SaveGameClass = nullptr);

	/** 删除当前激活进度槽位 World 目录下的指定存档，并清理中心运行时登记。 */
	GENERICSAVEGAMESYSTEM_API bool DeleteSlotWorldSaveGame(const FString& SlotName);

	/** 根据存档对象的槽位名删除当前激活进度槽位下的 World 存档。 */
	GENERICSAVEGAMESYSTEM_API bool DeleteSlotWorldSaveGame(UGenericSaveGame* SaveGame);

	/** 异步保存到当前激活进度槽位的 World 目录；未进入槽位时直接拒绝提交。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncSlotWorldSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete = FOnGenericSaveGameAsyncSaveComplete());

	/** 异步读取当前激活进度槽位 World 目录下的存档，并交给中心子系统登记。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncSlotWorldLoadGame(const FString& SlotName, TSubclassOf<UGenericSaveGame> SaveGameClass = nullptr, const FOnGenericSaveGameAsyncLoadComplete& OnComplete = FOnGenericSaveGameAsyncLoadComplete());

	/** 查找当前激活进度槽位 World 目录下已经登记的存档对象。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame* GetSlotWorldSaveGame(const FString& SlotName) const;

private:
	/** 使用当前激活槽位 GUID 和世界标识生成中心 SaveGameSubsystem 使用的完整槽位名。 */
	FString BuildSlotWorldSlotName(const FString& SlotName) const;

	/** 读取当前世界的稳定标识；有效地图使用长包路径，PIE 世界会先还原为原始地图路径。 */
	FString GetWorldIdentifier() const;

	/** 读取当前正在游玩的进度槽位；无效 GUID 表示该入口当前不可用。 */
	FGuid GetActiveSlotGuid() const;
};
