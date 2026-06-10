// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Handle/WorldPartitionHandle.h"
#include "WorldPartitionType.h"
#include "UnLoadWorldPartitionHandle.generated.h"

/** 顺序执行 Runtime Cell 卸载请求，并等待每个 Cell 回到 Unloaded 状态后再处理下一个。 */
UCLASS(MinimalAPI)
class UUnLoadWorldPartitionHandle : public UWorldPartitionHandle
{
	GENERATED_BODY()

public:
	/** 接收单个卸载目标，供子系统的 UnloadCell 便捷入口创建句柄。 */
	void Initialize(const FUnloadWorldPartitionSetting& InSetting, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish);

	/** 接收批量卸载目标，过滤空 Cell 和重复 Cell 后记录完成回调。 */
	void Initialize(TArray<FUnloadWorldPartitionSetting> InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish);

public:
	virtual void RemoveCell(UWorldPartitionRuntimeCell* InCell) override;
	virtual TArray<UWorldPartitionRuntimeCell*> GetCells() const override;
	virtual void ExecuteHandle(int32 Index) override;
	virtual void HandleOnOnceFinish() override;
	virtual void HandleOnFinish() override;

public:
	/** 返回卸载设置队列副本，蓝图可用它查看本句柄实际保留的目标 Cell。 */
	UFUNCTION(BlueprintPure, DisplayName="Get Unload World Partition Settings", Category="Unload World Partition Handle|Setting")
	TArray<FUnloadWorldPartitionSetting> GetUnLoadWorldPartitionSettingsCopy() const;

	/** 读取当前索引对应的卸载设置；索引已完成或队列被裁剪时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Unload World Partition Handle|Setting")
	bool GetCurrentUnLoadWorldPartitionSetting(FUnloadWorldPartitionSetting& OutSetting) const;

	/** 返回卸载设置队列，供 C++ 测试或调度层检查实际保留的请求项。 */
	TArray<FUnloadWorldPartitionSetting>& GetUnLoadWorldPartitionSettings() { return UnLoadWorldPartitionSettings; }

private:
	virtual bool IsCurrentCellOperationFinished() const override;

private:
	/** 本句柄仍需要提交或等待完成的卸载目标列表。 */
	TArray<FUnloadWorldPartitionSetting> UnLoadWorldPartitionSettings;

	/** 单个 Cell 达到 Unloaded 后回调给调用方。 */
	FOnHandleWorldPartitionOnceFinish OnUnLoadWorldPartitionOnceFinish;

	/** 全部卸载目标完成后回调给调用方。 */
	FOnHandleWorldPartitionFinish OnUnLoadWorldPartitionFinish;
};
