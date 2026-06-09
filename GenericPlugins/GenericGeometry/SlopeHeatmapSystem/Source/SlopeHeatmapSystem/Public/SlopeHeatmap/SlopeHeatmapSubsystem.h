#pragma once

#include "CoreMinimal.h"
#include "GenericGeometryTypes.h"
#include "SlopeHeatmap/SlopeHeatmapTypes.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "SlopeHeatmapSubsystem.generated.h"

class USlopeHeatmapComponent;

/** 维护坡度热力图组件状态，负责刷新 Decal 输出并执行体积内坡度查询。 */
UCLASS(MinimalAPI)
class USlopeHeatmapSubsystem : public UGenericWorldSubsystem
{
    GENERATED_BODY()

public:
    static SLOPEHEATMAPSYSTEM_API USlopeHeatmapSubsystem* Get(const UObject* WorldContextObject);

    SLOPEHEATMAPSYSTEM_API virtual void Deinitialize() override;

    /** 为组件创建运行时统计状态，使后续构建和查询能按组件隔离。 */
    SLOPEHEATMAPSYSTEM_API void RegisterSlopeHeatmapComponent(USlopeHeatmapComponent* InComponent);

    /** 移除组件运行时状态，组件注销后不再保留构建统计。 */
    SLOPEHEATMAPSYSTEM_API void UnregisterSlopeHeatmapComponent(USlopeHeatmapComponent* InComponent);

    /** 构建请求入口，当前实现立即同步刷新 Decal。 */
    SLOPEHEATMAPSYSTEM_API void RequestSlopeHeatmapBuild(USlopeHeatmapComponent* InComponent);

    /** 刷新组件 Decal 材质和尺寸，写入本次构建状态后广播完成。 */
    SLOPEHEATMAPSYSTEM_API void RebuildSlopeHeatmap(USlopeHeatmapComponent* InComponent);

    /** 在组件 Decal 体积内追踪场景表面，计算坡度角、热力值和网格坐标。 */
    UFUNCTION(BlueprintPure, Category="SlopeHeatmap")
    SLOPEHEATMAPSYSTEM_API FSlopeHeatmapQueryResult QuerySlopeHeatmapAtWorldLocation(const USlopeHeatmapComponent* InComponent, const FVector& WorldLocation) const;

private:
    /** 保存单个坡度热力图组件最近一次构建状态。 */
    struct FSlopeHeatmapRuntimeState
    {
        /** Decal 刷新结果、输入输出数量和耗时信息。 */
        FGenericGeometryBuildStats BuildStats;
    };

private:
    virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

private:
    /** 以组件实例为键隔离运行时状态，支持同一世界内多个热力图组件。 */
    TMap<TObjectPtr<USlopeHeatmapComponent>, FSlopeHeatmapRuntimeState> RuntimeStates;
};
