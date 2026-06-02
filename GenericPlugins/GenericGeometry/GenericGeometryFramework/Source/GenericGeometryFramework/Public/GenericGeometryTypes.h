#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "GenericGeometryTypes.generated.h"

GENERICGEOMETRYFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogGeometryFramework, Log, All);
GENERICGEOMETRYFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogFlyLine, Log, All);
GENERICGEOMETRYFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogSlopeHeatmap, Log, All);
GENERICGEOMETRYFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogAspect, Log, All);
GENERICGEOMETRYFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogSkyline, Log, All);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeometry);

/** 描述几何可视化构建请求在子系统中的生命周期，用于 BuildStats 对外报告当前阶段。 */
UENUM(BlueprintType)
enum class EGeometryBuildState : uint8
{
    /** 当前没有待处理或正在执行的构建，组件注册前和状态重置后使用。 */
    Idle,

    /** 请求已登记但尚未同步到渲染数据，Skyline 等延迟刷新流程会先进入该状态。 */
    Queued,

    /** 子系统正在刷新材质、网格或实例数据，构建耗时从该阶段开始统计。 */
    Building,

    /** 最近一次构建已完成，查询函数和完成回调可读取最新结果。 */
    Ready,

    /** 构建所需运行时资源创建失败，失败原因会写入 LastMessage。 */
    Failed
};

/** 约定几何组件何时触发重建，供后续组件选择手动、注册、属性变化或 Tick 驱动的刷新时机。 */
UENUM(BlueprintType)
enum class EGeometryRefreshPolicy : uint8
{
    /** 仅在调用方显式请求时刷新，适合昂贵或批量控制的构建。 */
    Manual,

    /** 组件注册进世界后立即刷新，用于保证新放置对象拥有初始可视化。 */
    OnRegister,

    /** 编辑器属性、变换或输入数据变化时刷新，保持预览结果跟随配置。 */
    OnChange,

    /** 每帧检查并刷新动态状态，适合依赖可见性或运行时目标变化的效果。 */
    OnTick
};

/** 定义表面查询范围的二维边界形状，工具函数会用它判断局部坐标是否在有效区域内。 */
UENUM(BlueprintType)
enum class EGeometryRangeShape : uint8
{
    /** 使用半径 Extent 构成圆形查询区域，适合径向热区或影响范围。 */
    Sphere,

    /** 使用 Extent 作为 X/Y 半宽构成方形查询区域，适合网格化采样。 */
    Box
};

/** 定义组件周围用于表面追踪、坐标转换和范围判断的通用二维采样区域。 */
USTRUCT(BlueprintType)
struct GENERICGEOMETRYFRAMEWORK_API FGeometrySurfaceRange
{
    GENERATED_BODY()

public:
    /** 决定 IsLocalPointInsideSurfaceRange 使用圆形距离还是方形边界过滤采样点。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geometry")
    EGeometryRangeShape Shape = EGeometryRangeShape::Sphere;

    /** 采样区域半径或半宽，追踪和局部坐标转换会以它作为有效范围上限。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geometry", meta=(ClampMin="50.0"))
    float Extent=1000.f;

    /** 为 true 时范围局部坐标跟随组件 Yaw 旋转，便于旋转后的 Box 范围仍按本地轴判定。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Geometry")
    bool bUseComponentYaw=true;
};

/** 汇总各几何子系统最近一次构建结果，供蓝图回调、调试日志和状态查询共享。 */
USTRUCT(BlueprintType)
struct GENERICGEOMETRYFRAMEWORK_API FGenericGeometryBuildStats
{
    GENERATED_BODY()

public:
    /** 标记当前构建阶段，调用方可据此判断是否可读取输出或需要展示失败信息。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Geometry")
    EGeometryBuildState BuildState=EGeometryBuildState::Idle;

    /** 成功进入构建流程的累计次数，用于判断组件是否已经刷新过。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Geometry")
    int32 BuildCount=0;

    /** 本次构建处理的输入数量，例如端点数、采样点数或待刷新的组件数。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Geometry")
    int32 NumInputs=0;

    /** 本次构建产生的输出数量，例如有效连接、采样命中或渲染资源数。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Geometry")
    int32 NumOutputs=0;

    /** 最近一次构建耗时，子系统在重建结束时写入用于性能观察。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Geometry")
    float LastBuildDurationMs=0.f;

    /** 最近一次构建的摘要或失败原因，会同步到日志和蓝图完成回调。 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Geometry")
    FString LastMessage;
};
