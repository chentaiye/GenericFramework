#pragma once

#include "CoreMinimal.h"
#include "GenericGeometryTypes.h"

class AActor;
class UInstancedStaticMeshComponent;
class UProceduralMeshComponent;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMesh;
class UMaterialInterface;
class UWorld;

namespace GenericGeometryUtilities
{
    /** 确保子系统拥有一个瞬态渲染 Actor，FlyLine 等批量组件会挂到该 Actor 下统一管理。 */
    GENERICGEOMETRYFRAMEWORK_API AActor* EnsureRenderActor(UWorld* World, TWeakObjectPtr<AActor>& InOutActor, const FString& ActorName);

    /** 按批次名复用或创建 ISM 组件，并同步 Mesh、材质和自定义数据通道供飞线实例渲染。 */
    GENERICGEOMETRYFRAMEWORK_API UInstancedStaticMeshComponent* EnsureInstancedMeshComponent(
        AActor* OwnerActor,
        TMap<FName, TObjectPtr<UInstancedStaticMeshComponent>>& InOutComponents,
        const FName ComponentName,
        UStaticMesh* Mesh,
        UMaterialInterface* Material,
        int32 NumCustomDataFloats = 4);

    /** 按名称复用或创建 ProceduralMeshComponent，Aspect 子系统用它承载动态箭头网格。 */
    GENERICGEOMETRYFRAMEWORK_API UProceduralMeshComponent* EnsureProceduralMeshComponent(
        AActor* OwnerActor,
        TMap<FName, TObjectPtr<UProceduralMeshComponent>>& InOutComponents,
        const FName ComponentName,
        UMaterialInterface* Material);

    /** 优先使用显式组件，缺省时从拥有者查找 PrimitiveComponent 作为表面追踪目标。 */
    GENERICGEOMETRYFRAMEWORK_API UPrimitiveComponent* ResolvePrimitiveComponent(const AActor* OwnerActor, UPrimitiveComponent* ExplicitComponent);

    /** 在指定 Primitive 上执行复杂线追踪，供坡度、坡向等表面采样逻辑读取命中信息。 */
    GENERICGEOMETRYFRAMEWORK_API bool TracePrimitiveSurface(UPrimitiveComponent* TargetComponent, const FVector& Start, const FVector& End, FHitResult& OutHit);

    /** 使用组件包围盒的 Z 范围在指定 XY 处上下追踪，返回局部网格采样命中的表面。 */
    GENERICGEOMETRYFRAMEWORK_API bool TraceSurfaceAtXY(UPrimitiveComponent* TargetComponent, const FBox& Bounds, const FVector2D& XY, FHitResult& OutHit);

    /** 在世界对象通道上按 XY 做竖向追踪，适合没有显式 Primitive 时采样地形或场景几何。 */
    GENERICGEOMETRYFRAMEWORK_API bool TraceWorldSurfaceAtXY(UWorld* World, const AActor* IgnoredActor, const FVector& TraceCenter, const FVector& TraceExtent, const FVector2D& XY, FHitResult& OutHit);

    /** 根据起止点生成沿 X 轴拉伸的线段实例变换，FlyLine 用它把网格片段铺到抛物线上。 */
    GENERICGEOMETRYFRAMEWORK_API FTransform BuildLineTransform(const FVector& Start, const FVector& End, const UStaticMesh* Mesh, float Width);

    /** 根据表面法线构造朝向四元数，使可视化元素贴合命中表面的上方向。 */
    GENERICGEOMETRYFRAMEWORK_API FQuat MakeSurfaceRotation(const FVector& Normal);

    /** 按范围设置决定是否读取组件 Yaw，保证范围坐标与组件旋转策略一致。 */
    GENERICGEOMETRYFRAMEWORK_API float GetSurfaceRangeYawDegrees(const USceneComponent* RangeOwner, const FGeometrySurfaceRange& Range);

    /** 把世界位置转换成指定中心和 Yaw 下的范围局部 XY，后续用于形状过滤和网格采样。 */
    GENERICGEOMETRYFRAMEWORK_API FVector2D WorldToRangeLocalXY(const FVector& RangeCenter, float RangeYawDegrees, const FVector& WorldLocation);

    /** 以组件位置和范围旋转策略为基准，把世界位置转换为范围局部 XY。 */
    GENERICGEOMETRYFRAMEWORK_API FVector2D WorldToRangeLocalXY(const USceneComponent* RangeOwner, const FGeometrySurfaceRange& Range, const FVector& WorldLocation);

    /** 把范围局部 XY 还原到世界坐标，按调用方提供的 Z 值落在指定高度面上。 */
    GENERICGEOMETRYFRAMEWORK_API FVector RangeLocalToWorld(const FVector& RangeCenter, float RangeYawDegrees, const FVector2D& LocalXY, float WorldZ = 0.f);

    /** 以组件位置和范围旋转策略为基准，把范围局部 XY 转回世界坐标。 */
    GENERICGEOMETRYFRAMEWORK_API FVector RangeLocalToWorld(const USceneComponent* RangeOwner, const FGeometrySurfaceRange& Range, const FVector2D& LocalXY, float WorldZ = 0.f);

    /** 按 Range.Shape 和 Extent 判断局部 XY 是否仍在有效采样范围内。 */
    GENERICGEOMETRYFRAMEWORK_API bool IsLocalPointInsideSurfaceRange(const FVector2D& LocalXY, const FGeometrySurfaceRange& Range);

    /** 先转换世界位置到范围局部 XY，再判断是否命中范围，可选返回局部坐标给查询结果使用。 */
    GENERICGEOMETRYFRAMEWORK_API bool IsWorldPointInsideSurfaceRange(const USceneComponent* RangeOwner, const FGeometrySurfaceRange& Range, const FVector& WorldLocation, FVector2D* OutLocalXY = nullptr);

    /** 将数值映射到 0 到 1 区间并夹紧，坡度热力和实例自定义数据复用该归一化规则。 */
    GENERICGEOMETRYFRAMEWORK_API float NormalizeClamped(float Value, float MinValue, float MaxValue);

    /** 在起止点之间生成带高度偏移的抛物线点列，FlyLine 用相邻点生成多段线实例。 */
    GENERICGEOMETRYFRAMEWORK_API TArray<FVector> BuildParabolaPoints(const FVector& Start, const FVector& End, float HeightOffset, int32 SegmentCount);

    /** 对二维点集生成凸包边界，供需要从采样点提取外轮廓的几何流程复用。 */
    GENERICGEOMETRYFRAMEWORK_API TArray<FVector2D> BuildConvexHull(const TArray<FVector2D>& Points);
}
