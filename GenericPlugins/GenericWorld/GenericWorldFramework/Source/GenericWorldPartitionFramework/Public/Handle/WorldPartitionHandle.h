// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Obect/GenericObject.h"
#include "TimerManager.h"
#include "WorldPartition/WorldPartitionRuntimeCell.h"
#include "WorldPartitionHandle.generated.h"

class UWorldPartitionHandle;

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnWorldPartitionHandleOnceFinish, UWorldPartitionHandle*, UWorldPartitionRuntimeCell*);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnWorldPartitionHandleFinish, UWorldPartitionHandle*);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBPDelegate_OnWorldPartitionHandleOnceFinish, UWorldPartitionHandle*, InHandle, UWorldPartitionRuntimeCell*, InCell);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPDelegate_OnWorldPartitionHandleFinish, UWorldPartitionHandle*, InHandle);

/** 以队列方式轮询 Runtime Cell 状态的抽象句柄，子类只负责提交具体的 Load/Unload/Activate 操作。 */
UCLASS(Abstract, MinimalAPI)
class UWorldPartitionHandle : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 从当前索引启动执行；目标列表为空或全部执行完时直接触发整体完成。 */
	UFUNCTION(BlueprintCallable, Category="World Partition Handle|Handle")
	void Startup();

	/** 返回当前正在等待状态变化的 Cell 索引。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	int32 GetCellIndex() const;

	/** 返回句柄当前保留的 Cell 数量，可用于蓝图侧展示本批请求规模。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	int32 GetCellCount() const;

	/** 返回已经完成的 Cell 数量；运行中为当前索引，整批完成后为队列数量。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	int32 GetCompletedCellCount() const;

	/** 返回尚未完成的 Cell 数量；运行中包含当前正在等待状态变化的 Cell。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	int32 GetRemainingCellCount() const;

	/** 判断句柄是否已经进入执行流程且尚未广播整批完成。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	bool IsRunning() const;

	/** 判断本批请求是否已经广播整批完成；刚创建但未启动的句柄不会被视为完成。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	bool IsFinished() const;

	/** 判断当前索引是否仍指向一个等待处理或正在处理的 Cell。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	bool HasPendingCells() const;

	/** 判断索引能否在当前队列中解析出有效 Cell。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	bool IsValidCellIndex(int32 InIndex) const;

	/** 返回最近一次完成的 Cell；在单项完成事件和整批完成事件中可读取。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|State")
	UWorldPartitionRuntimeCell* GetLastFinishedCell() const;

	/** 按索引读取本句柄管理的 Cell，越界时返回空。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|Handle")
	UWorldPartitionRuntimeCell* GetCellByIndex(int32 InIndex) const;

	/** 查找 Cell 在本句柄目标列表中的位置，用于冲突合并时判断是否已经执行。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|Handle")
	int32 GetIndexByCell(UWorldPartitionRuntimeCell* InCell) const;

	/** 判断当前队列中是否包含指定 Cell。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|Handle")
	bool ContainsCell(UWorldPartitionRuntimeCell* InCell) const;

	/** 从尚未执行的目标列表中移除 Cell，防止旧请求覆盖同一帧提交的新请求。 */
	UFUNCTION(BlueprintCallable, Category="World Partition Handle|Handle")
	virtual void RemoveCell(UWorldPartitionRuntimeCell* InCell) PURE_VIRTUAL(UWorldPartitionHandle::RemoveCell, );

	/** 返回本句柄当前仍需要处理的 Cell 列表。 */
	UFUNCTION(BlueprintPure, Category="World Partition Handle|Handle")
	virtual TArray<UWorldPartitionRuntimeCell*> GetCells() const PURE_VIRTUAL(UWorldPartitionHandle::GetCells, return TArray<UWorldPartitionRuntimeCell*>(););

	/** 对指定索引的 Cell 提交子类操作，并在需要时启动状态轮询。 */
	virtual void ExecuteHandle(int32 Index) PURE_VIRTUAL(UWorldPartitionHandle::ExecuteHandle, );

public:
	UPROPERTY(BlueprintAssignable, DisplayName="On Once Finish", Category="Events")
	FBPDelegate_OnWorldPartitionHandleOnceFinish BPDelegate_OnOnceFinish;

	UPROPERTY(BlueprintAssignable, DisplayName="On Finish", Category="Events")
	FBPDelegate_OnWorldPartitionHandleFinish BPDelegate_OnFinish;

public:
	/** 返回单个 Cell 操作完成事件，子系统用它追踪句柄进度。 */
	FOnWorldPartitionHandleOnceFinish& GetHandleOnceFinishEvent();

	/** 返回整组 Cell 操作完成事件，子系统用它清理活动句柄。 */
	FOnWorldPartitionHandleFinish& GetHandleFinishEvent();

protected:
	/** 当前 Cell 达到目标状态后推进索引，并继续执行下一个 Cell。 */
	void OnOnceFinish();

	/** 子类扩展单个 Cell 完成后的业务回调。 */
	virtual void HandleOnOnceFinish();

	/** 所有目标处理完成后重置索引并触发整体完成回调。 */
	void OnFinish();

	/** 子类扩展整组 Cell 完成后的业务回调。 */
	virtual void HandleOnFinish();

	/** 在下一帧重新检查当前 Cell 状态，避免同步读取还未更新的流送结果。 */
	void StartWaitCurrentCell();

	/** 停止当前 Cell 的轮询定时器，防止完成后重复触发。 */
	void StopWaitCurrentCell();

	/** 判断当前 Cell 是否已经达到子类定义的目标状态。 */
	virtual bool IsCurrentCellOperationFinished() const PURE_VIRTUAL(UWorldPartitionHandle::IsCurrentCellOperationFinished, return false;);

	/** 广播单个 Cell 完成，携带刚完成的 Cell 供监听方识别。 */
	void BroadcastOnceFinish();

	/** 广播整组 Cell 完成，供子系统和调用方清理句柄。 */
	void BroadcastFinish();

private:
	/** 下一帧检查当前 Cell 是否达到目标状态，未完成则继续排队等待。 */
	void WaitCurrentCellNextTick();

private:
	/** 当前正在执行或等待完成的目标 Cell 索引。 */
	int32 CellIndex = 0;

	/** 标记句柄是否已启动且尚未完成，用于蓝图侧判断事件绑定后的实时状态。 */
	bool bIsRunning = false;

	/** 标记句柄是否已经完成过本批请求，区分未启动和已完成两种空闲状态。 */
	bool bIsFinished = false;

	/** 刚完成的 Cell，用于 OnceFinish 广播时传递给监听方。 */
	UPROPERTY()
	TObjectPtr<UWorldPartitionRuntimeCell> LastFinishedCell=nullptr;

	/** 单个 Cell 完成时触发的原生事件。 */
	FOnWorldPartitionHandleOnceFinish OnOnceFinishEvent;

	/** 整个句柄处理完全部 Cell 后触发的原生事件。 */
	FOnWorldPartitionHandleFinish OnFinishEvent;

	/** 当前 Cell 状态轮询使用的下一帧定时器。 */
	FTimerHandle WaitingTimerHandle;
};
