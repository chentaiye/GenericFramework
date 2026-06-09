#pragma once

#include "CoreMinimal.h"
#include "SlopeHeatmapTypes.generated.h"

/** 保存坡度热力图在某个世界位置的表面追踪结果，供蓝图读取坡度和热力值。 */
USTRUCT(BlueprintType)
struct SLOPEHEATMAPSYSTEM_API FSlopeHeatmapQueryResult
{
    GENERATED_BODY()

public:
    /** 标记查询是否在 Decal 体积内命中表面，无效时其他字段保持默认值。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlopeHeatmap")
    bool bValid=false;

    /** 命中点映射到 Decal Y/Z 平面的 1024 网格坐标，便于蓝图定位热力单元。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlopeHeatmap")
    FIntPoint CellCoord=FIntPoint::ZeroValue;

    /** 实际命中的世界位置，用于把查询结果和场景表面对齐。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlopeHeatmap")
    FVector WorldLocation=FVector::ZeroVector;

    /** 命中表面法线，子系统用它计算坡度角和归一化热力值。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlopeHeatmap")
    FVector SurfaceNormal=FVector::UpVector;

    /** 表面法线相对世界上方向的角度，0 为水平表面，90 为垂直表面。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlopeHeatmap")
    float SlopeDegrees=0.f;

    /** 坡度按 0 到 90 度归一化后的热力值，材质或蓝图可直接用于颜色映射。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlopeHeatmap")
    float NormalizedHeat=0.f;
};
