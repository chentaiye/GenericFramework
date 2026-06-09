#pragma once

#include "CoreMinimal.h"
#include "SkylineTypes.generated.h"

class AActor;

/** 保留天际线轮廓查询的数据结构；当前后期处理实现不再生成采样点时会返回空轮廓。 */
USTRUCT(BlueprintType)
struct SKYLINESYSTEM_API FSkylineContour
{
    GENERATED_BODY()

public:
    /** 标记轮廓是否来自有效采样；后期材质路径返回空轮廓时保持 false。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Skyline")
    bool bValid=false;

    /** 轮廓在屏幕空间的点集，供旧采样式实现或外部绘制逻辑读取。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Skyline")
    TArray<FVector2D> ScreenPoints;

    /** 参与形成轮廓的 Actor 列表，后期处理实现未采样时该列表为空。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Skyline")
    TArray<TObjectPtr<AActor>> ContributingActors;
};

/** 汇总 Skyline 最近一次刷新状态；后期材质路径主要用于报告激活状态而非采样数量。 */
USTRUCT(BlueprintType)
struct SKYLINESYSTEM_API FSkylineMetrics
{
    GENERATED_BODY()

public:
    /** 可见并参与选择的组件数量，当前实现未做轮廓采样时通常保持默认值。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Skyline")
    int32 VisibleComponentCount=0;

    /** 对轮廓有贡献的 Actor 数量，后期处理材质实现不会主动填充该值。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Skyline")
    int32 ContributingActorCount=0;

    /** 轮廓采样点数量，当前后期处理输出不生成采样点时为 0。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Skyline")
    int32 SampleCount=0;

    /** 采样轮廓使用的视口尺寸，后期材质路径保留该字段用于兼容查询接口。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Skyline")
    FVector2D ViewportSize=FVector2D::ZeroVector;
};

/** 配置 Skyline 后期处理材质参数，组件激活时会同步到动态材质实例。 */
USTRUCT(BlueprintType)
struct SKYLINESYSTEM_API FSkylineRenderConfig
{
    GENERATED_BODY()

public:
    /** 后期描边颜色，ApplySkylinePostProcessParameters 会写入 LineColor 参数。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skyline")
    FLinearColor LineColor=FLinearColor::White;

    /** 屏幕空间描边宽度，<=0 时组件会关闭后期处理输出。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skyline", meta=(ClampMin="1.0"))
    float LineThicknessPx=2.f;
};
