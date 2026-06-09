#pragma once

#include "CoreMinimal.h"
#include "AspectTypes.generated.h"

/** 保存一次坡向采样的命中信息，查询接口和箭头网格构建都会读取这些派生结果。 */
USTRUCT(BlueprintType)
struct ASPECTSYSTEM_API FSlopeAspectSample
{
    GENERATED_BODY()

public:
    /** 标记本次追踪是否命中表面，无效样本不会参与统计或箭头生成。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    bool bValid=false;

    /** 表面命中点的世界坐标，箭头顶点会以它为中心贴合地表。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    FVector WorldLocation=FVector::ZeroVector;

    /** 命中表面法线，用于计算坡度、下坡方向以及箭头朝向。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    FVector SurfaceNormal=FVector::UpVector;

    /** 表面法线与世界上方向的夹角，统计平均值和箭头颜色亮度都基于该值。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    float SlopeDegrees=0.f;

    /** 下坡方向投影到水平面的方位角，Aspect 渲染用它映射箭头颜色色相。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    float AspectDegrees=0.f;
};

/** 承载世界位置查询或网格采样得到的坡向单元结果。 */
USTRUCT(BlueprintType)
struct ASPECTSYSTEM_API FAspectTileResult
{
    GENERATED_BODY()

public:
    /** 命中点映射到组件采样盒内的 1024 网格坐标，便于蓝图对齐查询结果。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    FIntPoint CellCoord=FIntPoint::ZeroValue;

    /** 该单元对应的坡度、坡向和表面命中数据。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    FSlopeAspectSample Sample;
};

/** 汇总 Aspect 重建时所有有效样本的坡度统计，供调试面板和蓝图查询读取。 */
USTRUCT(BlueprintType)
struct ASPECTSYSTEM_API FAspectStatistics
{
    GENERATED_BODY()

public:
    /** 成功命中的样本数量，也是生成箭头实例的数量。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    int32 SampleCount=0;

    /** 所有有效样本的平均坡度，用于快速评估当前采样区域整体陡缓。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    float AverageSlopeDegrees=0.f;

    /** 有效样本中的最小坡度，未命中任何样本时保持为 0。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    float MinSlopeDegrees=0.f;

    /** 有效样本中的最大坡度，用于识别采样盒内最陡方向区域。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aspect")
    float MaxSlopeDegrees=0.f;
};
