#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "WorldPartition/WorldPartitionRuntimeCell.h"
#include "WorldPartitionType.generated.h"

GENERICWORLDPARTITIONFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogWorldPartition, Log, All);

GENERICWORLDPARTITIONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_WorldPartition);
GENERICWORLDPARTITIONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_WorldPartition_OnLoadWorldPartitionHandleRegister);
GENERICWORLDPARTITIONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_WorldPartition_OnUnLoadWorldPartitionHandleRegister);
GENERICWORLDPARTITIONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_WorldPartition_OnSetWorldPartitionVisibilityHandleRegister);

DECLARE_DELEGATE(FOnHandleWorldPartitionOnceFinish);
DECLARE_DELEGATE(FOnHandleWorldPartitionFinish);

/** 描述一次运行时 Cell 加载请求，供蓝图和子系统统一传递目标 Cell。 */
USTRUCT(BlueprintType)
struct FLoadWorldPartitionSetting
{
	GENERATED_BODY()

public:
	/** 需要切到 Loaded 状态的 World Partition 运行时 Cell。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="World Partition Type")
	TObjectPtr<UWorldPartitionRuntimeCell> Cell=nullptr;

public:
	/** 构造空请求，便于蓝图数组先创建元素再填入目标 Cell。 */
	FLoadWorldPartitionSetting() = default;

	/** 从目标 Cell 构造加载请求，后续由子系统在入队前做有效性和归属检查。 */
	explicit FLoadWorldPartitionSetting(UWorldPartitionRuntimeCell* InCell)
		: Cell(InCell)
	{
	}

	/** 判断请求是否具备可提交给加载句柄的目标 Cell。 */
	bool IsValid() const { return ::IsValid(Cell.Get()); }

	bool operator==(const FLoadWorldPartitionSetting& Other) const { return Cell == Other.Cell; }
	bool operator==(const UWorldPartitionRuntimeCell* Other) const { return Cell == Other; }
	bool operator!=(const FLoadWorldPartitionSetting& Other) const { return !(*this == Other); }
	bool operator!=(const UWorldPartitionRuntimeCell* Other) const { return !(*this == Other); }
};

/** 描述一次运行时 Cell 卸载请求，供子系统过滤不可卸载 Cell 后交给卸载句柄执行。 */
USTRUCT(BlueprintType)
struct FUnloadWorldPartitionSetting
{
	GENERATED_BODY()

public:
	/** 需要切到 Unloaded 状态的 World Partition 运行时 Cell。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="World Partition Type")
	TObjectPtr<UWorldPartitionRuntimeCell> Cell=nullptr;

public:
	/** 构造空请求，便于蓝图数组先创建元素再填入目标 Cell。 */
	FUnloadWorldPartitionSetting() = default;

	/** 从目标 Cell 构造卸载请求，AlwaysLoaded 或不可卸载 Cell 会在子系统入队前被拒绝。 */
	explicit FUnloadWorldPartitionSetting(UWorldPartitionRuntimeCell* InCell)
		: Cell(InCell)
	{
	}

	/** 判断请求是否具备可提交给卸载句柄的目标 Cell。 */
	bool IsValid() const { return ::IsValid(Cell.Get()); }

	bool operator==(const FUnloadWorldPartitionSetting& Other) const { return Cell == Other.Cell; }
	bool operator==(const UWorldPartitionRuntimeCell* Other) const { return Cell == Other; }
	bool operator!=(const FUnloadWorldPartitionSetting& Other) const { return !(*this == Other); }
	bool operator!=(const UWorldPartitionRuntimeCell* Other) const { return !(*this == Other); }
};

/** 描述一次运行时 Cell 可见性切换请求，加载状态由 UE 的 Cell Activate/Deactivate 流程承接。 */
USTRUCT(BlueprintType)
struct FSetWorldPartitionVisibilitySetting
{
	GENERATED_BODY()

public:
	/** 需要切换激活状态的 World Partition 运行时 Cell。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="World Partition Type")
	TObjectPtr<UWorldPartitionRuntimeCell> Cell=nullptr;

	/** 为 true 时激活 Cell，为 false 时仅退出 Activated 状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="World Partition Type")
	bool bVisible=false;

public:
	/** 构造空请求，便于蓝图数组先创建元素再填入目标 Cell 和目标可见性。 */
	FSetWorldPartitionVisibilitySetting() = default;

	/** 从目标 Cell 和可见性构造请求，AlwaysLoaded Cell 隐藏会在子系统入队前被拒绝。 */
	FSetWorldPartitionVisibilitySetting(UWorldPartitionRuntimeCell* InCell, bool bInVisible)
		: Cell(InCell)
		, bVisible(bInVisible)
	{
	}

	/** 判断请求是否具备可提交给可见性句柄的目标 Cell。 */
	bool IsValid() const { return ::IsValid(Cell.Get()); }

	bool operator==(const FSetWorldPartitionVisibilitySetting& Other) const { return Cell == Other.Cell; }
	bool operator==(const UWorldPartitionRuntimeCell* Other) const { return Cell == Other; }
	bool operator!=(const FSetWorldPartitionVisibilitySetting& Other) const { return !(*this == Other); }
	bool operator!=(const UWorldPartitionRuntimeCell* Other) const { return !(*this == Other); }
};
