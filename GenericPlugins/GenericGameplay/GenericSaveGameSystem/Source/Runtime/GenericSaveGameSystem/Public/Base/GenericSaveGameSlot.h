// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericSaveGame.h"
#include "GenericSaveGameSlot.generated.h"

/** 表示一场游戏进度的槽位 Manifest，槽位 GUID 同时作为 Saved/SaveGames/Slots 下的目录名。 */
UCLASS(MinimalAPI)
class UGenericSaveGameSlot : public UGenericSaveGame
{
	GENERATED_BODY()

public:
	/** 创建槽位 Manifest 对象；GUID 由槽位管理子系统在创建或异步恢复时写入。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGameSlot(const FObjectInitializer& ObjectInitializer);

	/** 返回槽位的稳定 GUID，蓝图侧只读取，目录创建和恢复由槽位子系统控制。 */
	UFUNCTION(BlueprintPure, Category="SaveGame|Slot")
	GENERICSAVEGAMESYSTEM_API FGuid GetSlotGuid() const;

	/** 由槽位管理子系统在创建或恢复 Manifest 时写入，确保目录标识和对象元数据一致。 */
	GENERICSAVEGAMESYSTEM_API void SetSlotGuid(const FGuid& InSlotGuid);

	/** 返回用于目录名的 GUID 字符串，无效槽位返回空字符串。 */
	GENERICSAVEGAMESYSTEM_API FString GetSlotGuidString() const;

protected:
	/** 该游戏进度的稳定标识，对应 Saved/SaveGames/Slots/{SlotGuid}。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SaveGame|Slot")
	FGuid SlotGuid;
};
