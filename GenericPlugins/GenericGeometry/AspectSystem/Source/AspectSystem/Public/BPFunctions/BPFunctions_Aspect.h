#pragma once

#include "CoreMinimal.h"
#include "Aspect/AspectTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Aspect.generated.h"

class UAspectComponent;
class UAspectSubsystem;

/** 提供 Aspect 子系统的蓝图静态入口，方便没有直接持有子系统的图表触发重建和查询。 */
UCLASS(MinimalAPI)
class UBPFunctions_Aspect : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** 通过 WorldContext 找到子系统并重建指定组件的箭头网格与坡度统计。 */
    UFUNCTION(BlueprintCallable, Category="Aspect", meta=(WorldContext="WorldContextObject"))
    static ASPECTSYSTEM_API void RebuildSlopeAspect(const UObject* WorldContextObject, UAspectComponent* Component);

    /** 在蓝图中对指定世界位置执行坡向查询，返回命中单元和派生坡度坡向。 */
    UFUNCTION(BlueprintPure, Category="Aspect", meta=(WorldContext="WorldContextObject"))
    static ASPECTSYSTEM_API FAspectTileResult QueryAspectAtLocation(const UObject* WorldContextObject, UAspectComponent* Component, const FVector& WorldLocation);

    /** 读取指定组件最近一次重建缓存的坡度统计结果。 */
    UFUNCTION(BlueprintPure, Category="Aspect", meta=(WorldContext="WorldContextObject"))
    static ASPECTSYSTEM_API FAspectStatistics GetAspectStatistics(const UObject* WorldContextObject, UAspectComponent* Component);
};
