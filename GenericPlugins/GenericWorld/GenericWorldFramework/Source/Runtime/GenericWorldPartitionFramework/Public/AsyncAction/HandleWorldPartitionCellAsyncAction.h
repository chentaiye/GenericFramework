// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "HandleWorldPartitionCellAsyncAction.generated.h"

/** 蓝图异步节点包装单个 Runtime Cell 请求，节点生命周期由句柄完成事件结束。 */
UCLASS(MinimalAPI)
class UHandleWorldPartitionCellAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建加载单个 Runtime Cell 的异步节点，完成时只广播一次 Finish。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cell|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellAsyncAction* AsyncLoadCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell);

	/** 创建卸载单个 Runtime Cell 的异步节点，完成时只广播一次 Finish。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cell|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellAsyncAction* AsyncUnloadCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell);

	/** 创建切换单个 Runtime Cell 可见性的异步节点，目标状态由 bVisible 决定。 */
	UFUNCTION(BlueprintCallable, Category="Handle World Partition Cell|Async Action", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UHandleWorldPartitionCellAsyncAction* AsyncSetCellVisibility(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell, bool bVisible);

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHandleCellFinish);

	/** 底层句柄整体完成后触发的蓝图输出引脚。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FHandleCellFinish OnFinish;

protected:
	/** 将子系统句柄完成事件转发到蓝图异步节点。 */
	GENERICWORLDPARTITIONFRAMEWORK_API void OnHandleFinish() const;
};
