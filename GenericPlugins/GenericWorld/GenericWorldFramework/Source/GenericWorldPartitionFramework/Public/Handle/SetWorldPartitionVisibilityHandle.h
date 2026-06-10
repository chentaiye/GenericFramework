// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Handle/WorldPartitionHandle.h"
#include "WorldPartitionType.h"
#include "SetWorldPartitionVisibilityHandle.generated.h"

/** 顺序执行 Runtime Cell 激活或反激活请求，用于把加载后的 Cell 切入或切出可见状态。 */
UCLASS(MinimalAPI)
class USetWorldPartitionVisibilityHandle : public UWorldPartitionHandle
{
	GENERATED_BODY()

public:
	/** 接收单个可见性目标，供子系统的 SetCellVisibility 便捷入口创建句柄。 */
	void Initialize(const FSetWorldPartitionVisibilitySetting& InSetting, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish);

	/** 接收批量可见性目标，过滤空 Cell 和重复 Cell 后记录完成回调。 */
	void Initialize(TArray<FSetWorldPartitionVisibilitySetting> InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish);

public:
	virtual void RemoveCell(UWorldPartitionRuntimeCell* InCell) override;
	virtual TArray<UWorldPartitionRuntimeCell*> GetCells() const override;
	virtual void ExecuteHandle(int32 Index) override;
	virtual void HandleOnOnceFinish() override;
	virtual void HandleOnFinish() override;

public:
	/** 返回可见性设置队列副本，蓝图可用它查看每个 Cell 的目标显示状态。 */
	UFUNCTION(BlueprintPure, DisplayName="Get Set World Partition Visibility Settings", Category="Set World Partition Visibility Handle|Setting")
	TArray<FSetWorldPartitionVisibilitySetting> GetSetWorldPartitionVisibilitySettingsCopy() const;

	/** 读取当前索引对应的可见性设置；索引已完成或队列被裁剪时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Set World Partition Visibility Handle|Setting")
	bool GetCurrentSetWorldPartitionVisibilitySetting(FSetWorldPartitionVisibilitySetting& OutSetting) const;

	/** 返回可见性设置队列，供 C++ 测试或调度层检查实际保留的请求项。 */
	TArray<FSetWorldPartitionVisibilitySetting>& GetSetWorldPartitionVisibilitySettings() { return SetWorldPartitionVisibilitySettings; }

private:
	virtual bool IsCurrentCellOperationFinished() const override;

private:
	/** 本句柄仍需要提交或等待完成的可见性目标列表。 */
	TArray<FSetWorldPartitionVisibilitySetting> SetWorldPartitionVisibilitySettings;

	/** 单个 Cell 达到目标可见性后回调给调用方。 */
	FOnHandleWorldPartitionOnceFinish OnSetWorldPartitionVisibilityOnceFinish;

	/** 全部可见性目标完成后回调给调用方。 */
	FOnHandleWorldPartitionFinish OnSetWorldPartitionVisibilityFinish;
};
