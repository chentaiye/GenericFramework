// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "Subsystem/Base/GenericSaveGameSubsystem.h"
#include "SlotPlayerSaveGameSubsystem.generated.h"

class APlayerController;
class ULocalPlayer;

/** 提供当前进度槽位下的本地玩家存档入口，把数据固定写入激活槽位的 Player 目录。 */
UCLASS(MinimalAPI)
class USlotPlayerSaveGameSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	static GENERICSAVEGAMESYSTEM_API USlotPlayerSaveGameSubsystem* Get(const ULocalPlayer* LocalPlayer);
	static GENERICSAVEGAMESYSTEM_API USlotPlayerSaveGameSubsystem* Get(const APlayerController* PlayerController);

	/** 在当前激活进度槽位的 Player 目录下创建 SaveGame 文件；未进入槽位或玩家无有效标识时不会创建对象。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame* CreateSlotPlayerSaveGame(const FString& SlotName, TSubclassOf<UGenericSaveGame> SaveGameClass = nullptr);

	/** 删除当前激活进度槽位 Player 目录下的指定存档，并清理中心运行时登记。 */
	GENERICSAVEGAMESYSTEM_API bool DeleteSlotPlayerSaveGame(const FString& SlotName);

	/** 根据存档对象的槽位名删除当前激活进度槽位下的 Player 存档。 */
	GENERICSAVEGAMESYSTEM_API bool DeleteSlotPlayerSaveGame(UGenericSaveGame* SaveGame);

	/** 异步保存到当前激活进度槽位的 Player 目录；未进入槽位时直接拒绝提交。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncSlotPlayerSaveGame(const FString& SlotName, UGenericSaveGame* SaveGame, const FOnGenericSaveGameAsyncSaveComplete& OnComplete = FOnGenericSaveGameAsyncSaveComplete());

	/** 异步读取当前激活进度槽位 Player 目录下的存档，并交给中心子系统登记。 */
	GENERICSAVEGAMESYSTEM_API bool AsyncSlotPlayerLoadGame(const FString& SlotName, TSubclassOf<UGenericSaveGame> SaveGameClass = nullptr, const FOnGenericSaveGameAsyncLoadComplete& OnComplete = FOnGenericSaveGameAsyncLoadComplete());

	/** 查找当前激活进度槽位 Player 目录下已经登记的存档对象。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame* GetSlotPlayerSaveGame(const FString& SlotName) const;

private:
	/** 使用当前激活槽位 GUID 和玩家标识生成中心 SaveGameSubsystem 使用的完整槽位名。 */
	FString BuildSlotPlayerSlotName(const FString& SlotName) const;

	/** 读取当前 LocalPlayer 的稳定标识；优先使用平台用户 id，并用本地玩家索引区分同一平台用户下的多个玩家。 */
	FString GetPlayerIdentifier() const;

	/** 读取当前正在游玩的进度槽位；无效 GUID 表示该入口当前不可用。 */
	FGuid GetActiveSlotGuid() const;
};
