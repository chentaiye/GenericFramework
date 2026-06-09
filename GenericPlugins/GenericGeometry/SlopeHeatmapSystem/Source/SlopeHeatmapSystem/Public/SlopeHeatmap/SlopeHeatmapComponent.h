#pragma once

#include "Components/DecalComponent.h"
#include "CoreMinimal.h"
#include "GenericGeometryTypes.h"
#include "SlopeHeatmap/SlopeHeatmapTypes.h"
#include "SlopeHeatmapComponent.generated.h"

class USlopeHeatmapSubsystem;
struct FPropertyChangedEvent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlopeHeatmapBuildFinishedSignature, FGenericGeometryBuildStats, BuildStats);

/** 以 Decal 体积投射坡度热力图，并把查询和刷新请求转发给 SlopeHeatmap 子系统。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class USlopeHeatmapComponent : public UDecalComponent
{
    GENERATED_BODY()

public:
    /** 初始化编辑器 Tick、默认 Decal 尺寸、投射朝向和渲染优先级。 */
    SLOPEHEATMAPSYSTEM_API USlopeHeatmapComponent();

    SLOPEHEATMAPSYSTEM_API virtual void OnRegister() override;
    SLOPEHEATMAPSYSTEM_API virtual void OnUnregister() override;
    SLOPEHEATMAPSYSTEM_API virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#if WITH_EDITOR
    SLOPEHEATMAPSYSTEM_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    /** 请求子系统刷新 Decal 材质状态并更新构建统计。 */
    UFUNCTION(BlueprintCallable, CallInEditor, Category="SlopeHeatmap")
    SLOPEHEATMAPSYSTEM_API void RequestSlopeHeatmapBuild();

    /** 在 Decal 体积内对指定世界位置做表面追踪，返回坡度热力查询结果。 */
    UFUNCTION(BlueprintPure, Category="SlopeHeatmap")
    SLOPEHEATMAPSYSTEM_API FSlopeHeatmapQueryResult QueryAtWorldLocation(const FVector& WorldLocation) const;

    /** 确保 Decal 材质和尺寸可用，并标记渲染状态刷新。 */
    SLOPEHEATMAPSYSTEM_API void RefreshRenderDecal();

public:
    UPROPERTY(BlueprintAssignable, Category="SlopeHeatmap")
    FSlopeHeatmapBuildFinishedSignature OnSlopeHeatmapBuildFinished;

private:
#if WITH_EDITOR
    /** 对材质、组件变换和 DecalSize 生成哈希，用于编辑器预览自动重建。 */
    uint32 BuildEditorPreviewHash() const;

    /** 仅在 Editor 或 EditorPreview 世界启用预览 Tick，避免运行时额外检测。 */
    bool IsEditorPreviewWorld() const;
#endif

private:
#if WITH_EDITORONLY_DATA
    /** 缓存上一帧编辑器预览哈希，变化时触发 RequestSlopeHeatmapBuild。 */
    uint32 CachedEditorPreviewHash = 0;
#endif
};
