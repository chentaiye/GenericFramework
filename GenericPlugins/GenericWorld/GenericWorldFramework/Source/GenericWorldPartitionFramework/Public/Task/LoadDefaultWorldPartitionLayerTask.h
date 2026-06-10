// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "LoadDefaultWorldPartitionLayerTask.generated.h"

class UDataLayerAsset;

/** 提供默认 World Partition DataLayer 任务的 StateTree 实例数据，确保任务节点在编译时拥有有效实例值。 */
USTRUCT()
struct GENERICWORLDPARTITIONFRAMEWORK_API FLoadDefaultWorldPartitionLayerTaskInstanceData
{
	GENERATED_BODY()
};

/** 在 World Partition 世界中应用启动 DataLayer 状态，非分区世界或任一状态切换失败都会让任务失败。 */
USTRUCT(meta=(DisplayName="Load Default World Partition Layer", Category="Project"))
struct GENERICWORLDPARTITIONFRAMEWORK_API FLoadDefaultWorldPartitionLayerTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadDefaultWorldPartitionLayerTask();

	using FInstanceDataType = FLoadDefaultWorldPartitionLayerTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

	/** 是否先把当前世界的全部 DataLayer 实例切到 Loaded，用于预加载分区内容但不激活可见层。 */
	UPROPERTY(EditAnywhere, Category="Project")
	bool bLoadAllCurrentWorldDataLayers = false;

	/** 额外切到 Loaded 的 DataLayer 资产；无效项会被忽略，同层也在 VisibleDataLayers 中时最终会被激活。 */
	UPROPERTY(EditAnywhere, Category="Project")
	TArray<TObjectPtr<UDataLayerAsset>> LoadedDataLayers;

	/** 最后切到 Activated 的 DataLayer 资产；该列表在 LoadedDataLayers 之后执行，表示启动时需要可见的层。 */
	UPROPERTY(EditAnywhere, Category="Project")
	TArray<TObjectPtr<UDataLayerAsset>> VisibleDataLayers;
};
