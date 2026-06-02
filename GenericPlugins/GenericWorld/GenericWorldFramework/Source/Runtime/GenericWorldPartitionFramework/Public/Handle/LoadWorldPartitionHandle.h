// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Handle/WorldPartitionHandle.h"
#include "WorldPartitionType.h"
#include "LoadWorldPartitionHandle.generated.h"

/** 顺序执行 Runtime Cell 加载请求，并等待每个 Cell 至少进入 Loaded 状态后再处理下一个。 */
UCLASS(MinimalAPI)
class ULoadWorldPartitionHandle : public UWorldPartitionHandle
{
	GENERATED_BODY()

public:
	/** 接收单个加载目标，供子系统的 LoadCell 便捷入口创建句柄。 */
	void Initialize(const FLoadWorldPartitionSetting& InSetting, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish);

	/** 接收批量加载目标，过滤空 Cell 和重复 Cell 后记录完成回调。 */
	void Initialize(TArray<FLoadWorldPartitionSetting> InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish);

public:
	virtual void RemoveCell(UWorldPartitionRuntimeCell* InCell) override;
	virtual TArray<UWorldPartitionRuntimeCell*> GetCells() const override;
	virtual void ExecuteHandle(int32 Index) override;
	virtual void HandleOnOnceFinish() override;
	virtual void HandleOnFinish() override;

public:
	/** 返回加载设置队列副本，蓝图可用它查看本句柄实际保留的目标 Cell。 */
	UFUNCTION(BlueprintPure, DisplayName="Get Load World Partition Settings", Category="Load World Partition Handle|Setting")
	TArray<FLoadWorldPartitionSetting> GetLoadWorldPartitionSettingsCopy() const;

	/** 读取当前索引对应的加载设置；索引已完成或队列被裁剪时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Load World Partition Handle|Setting")
	bool GetCurrentLoadWorldPartitionSetting(FLoadWorldPartitionSetting& OutSetting) const;

	/** 返回加载设置队列，供 C++ 测试或调度层检查实际保留的请求项。 */
	TArray<FLoadWorldPartitionSetting>& GetLoadWorldPartitionSettings() { return LoadWorldPartitionSettings; }

private:
	virtual bool IsCurrentCellOperationFinished() const override;

private:
	/** 本句柄仍需要提交或等待完成的加载目标列表。 */
	TArray<FLoadWorldPartitionSetting> LoadWorldPartitionSettings;

	/** 单个 Cell 达到 Loaded 后回调给调用方。 */
	FOnHandleWorldPartitionOnceFinish OnLoadWorldPartitionOnceFinish;

	/** 全部加载目标完成后回调给调用方。 */
	FOnHandleWorldPartitionFinish OnLoadWorldPartitionFinish;
};
