#pragma once

#include "CoreMinimal.h"
#include "Skyline/SkylineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Skyline.generated.h"

class USkylineComponent;
class USkylineSubsystem;

/** 提供 Skyline 子系统的蓝图静态入口，用 WorldContext 转发重建和缓存查询。 */
UCLASS(MinimalAPI)
class UBPFunctions_Skyline : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** 立即同步指定组件的 Skyline 后期材质状态。 */
    UFUNCTION(BlueprintCallable, Category="Skyline", meta=(WorldContext="WorldContextObject"))
    static SKYLINESYSTEM_API void RebuildSkyline(const UObject* WorldContextObject, USkylineComponent* Component);

    /** 读取指定组件缓存的 Skyline 轮廓结果，后期处理路径通常返回空轮廓。 */
    UFUNCTION(BlueprintPure, Category="Skyline", meta=(WorldContext="WorldContextObject"))
    static SKYLINESYSTEM_API FSkylineContour GetSkylineContour(const UObject* WorldContextObject, USkylineComponent* Component);

    /** 读取指定组件最近一次 Skyline 刷新的统计缓存。 */
    UFUNCTION(BlueprintPure, Category="Skyline", meta=(WorldContext="WorldContextObject"))
    static SKYLINESYSTEM_API FSkylineMetrics GetSkylineMetrics(const UObject* WorldContextObject, USkylineComponent* Component);
};
