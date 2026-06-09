#pragma once

#include "CoreMinimal.h"
#include "SlopeHeatmap/SlopeHeatmapTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_SlopeHeatmap.generated.h"

class USlopeHeatmapComponent;
class USlopeHeatmapSubsystem;

/** 提供坡度热力图子系统的蓝图静态入口，用 WorldContext 转发刷新和查询。 */
UCLASS(MinimalAPI)
class UBPFunctions_SlopeHeatmap : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** 重建指定组件的 Decal 输出并更新构建统计。 */
    UFUNCTION(BlueprintCallable, Category="SlopeHeatmap", meta=(WorldContext="WorldContextObject"))
    static SLOPEHEATMAPSYSTEM_API void RebuildSlopeHeatmap(const UObject* WorldContextObject, USlopeHeatmapComponent* Component);

    /** 对指定世界位置执行坡度热力图查询，返回坡度角、热力值和网格坐标。 */
    UFUNCTION(BlueprintPure, Category="SlopeHeatmap", meta=(WorldContext="WorldContextObject"))
    static SLOPEHEATMAPSYSTEM_API FSlopeHeatmapQueryResult QuerySlopeHeatmapAtLocation(const UObject* WorldContextObject, USlopeHeatmapComponent* Component, const FVector& WorldLocation);
};
