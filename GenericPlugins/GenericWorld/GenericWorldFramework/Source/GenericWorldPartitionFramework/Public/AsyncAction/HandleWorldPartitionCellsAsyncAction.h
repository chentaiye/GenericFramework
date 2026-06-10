// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "WorldPartitionType.h"
#include "HandleWorldPartitionCellsAsyncAction.generated.h"

/** 蓝图异步节点包装批量 Runtime Cell 请求，分别暴露单项完成和整体完成输出。 */
UCLASS(MinimalAPI)
class UHandleWorldPartitionCellsAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建批量加载 Runtime Cell 的异步节点，按句柄顺序逐个等待 Loaded。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cells|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellsAsyncAction* AsyncLoadCells(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells);

	/** 创建基于加载设置的批量异步节点，适合蓝图复用已组装的设置数组。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cells|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellsAsyncAction* AsyncLoadCellsBySetting(const UObject* WorldContextObject, TArray<FLoadWorldPartitionSetting> LoadWorldPartitionSettings);

	/** 创建批量卸载 Runtime Cell 的异步节点，按句柄顺序逐个等待 Unloaded。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cells|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellsAsyncAction* AsyncUnloadCells(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells);

	/** 创建基于卸载设置的批量异步节点，提交前由子系统过滤不可卸载 Cell。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cells|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellsAsyncAction* AsyncUnloadCellsBySetting(const UObject* WorldContextObject, TArray<FUnloadWorldPartitionSetting> UnloadWorldPartitionSettings);

	/** 创建批量可见性切换异步节点，对所有 Cell 应用同一个目标可见性。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cells|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellsAsyncAction* AsyncSetCellsVisibility(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells, bool bVisible);

	/** 创建基于可见性设置的批量异步节点，允许每个 Cell 拥有不同目标状态。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cells|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellsAsyncAction* AsyncSetCellsVisibilityBySetting(const UObject* WorldContextObject, TArray<FSetWorldPartitionVisibilitySetting> SetWorldPartitionVisibilitySettings);

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHandleCellOnceFinish);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHandleCellFinish);

	/** 底层句柄每完成一个 Cell 后触发的蓝图输出引脚。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FHandleCellOnceFinish OnOnceFinish;

	/** 底层句柄完成全部 Cell 后触发的蓝图输出引脚。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FHandleCellFinish OnFinish;

protected:
	/** 将单个 Cell 完成事件转发到蓝图异步节点。 */
	GENERICWORLDPARTITIONFRAMEWORK_API void OnHandleOnceFinish() const;

	/** 将整组 Cell 完成事件转发到蓝图异步节点。 */
	GENERICWORLDPARTITIONFRAMEWORK_API void OnHandleFinish() const;
};
