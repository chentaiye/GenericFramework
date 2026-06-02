#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GenericGeometryTypes.h"
#include "Aspect/AspectTypes.h"
#include "AspectComponent.generated.h"

class UMaterialInterface;
class UAspectSubsystem;
struct FPropertyChangedEvent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAspectBuildFinishedSignature, FGenericGeometryBuildStats, BuildStats);

/** 用 Box 组件定义坡向采样体积，注册后由 Aspect 子系统追踪地表并生成下坡箭头网格。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UAspectComponent : public UBoxComponent
{
    GENERATED_BODY()

public:
    /** 初始化编辑器 Tick、采样盒尺寸、无碰撞设置和可视化颜色。 */
    ASPECTSYSTEM_API UAspectComponent();

    ASPECTSYSTEM_API virtual void OnRegister() override;
    ASPECTSYSTEM_API virtual void OnUnregister() override;
    ASPECTSYSTEM_API virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#if WITH_EDITOR
    ASPECTSYSTEM_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    /** 请求子系统重建当前采样盒内的坡度坡向箭头和统计数据。 */
    UFUNCTION(BlueprintCallable, CallInEditor, Category="Aspect")
    ASPECTSYSTEM_API void RequestAspectBuild();

    /** 在当前采样盒内对世界位置做一次表面追踪并返回该点坡向结果。 */
    UFUNCTION(BlueprintPure, Category="Aspect")
    ASPECTSYSTEM_API FAspectTileResult QueryAtWorldLocation(const FVector& WorldLocation) const;

    /** 重新触发箭头 ProceduralMesh 构建，供编辑器按钮或属性变化复用。 */
    ASPECTSYSTEM_API void RefreshRenderMesh();

public:
    /** 箭头网格使用的材质；为空时子系统会加载插件内默认 Aspect 材质。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Aspect")
    TObjectPtr<UMaterialInterface> ArrowMaterial=nullptr;

    UPROPERTY(BlueprintAssignable, Category="Aspect")
    FAspectBuildFinishedSignature OnAspectBuildFinished;

private:
#if WITH_EDITOR
    /** 对材质、组件变换和盒体范围生成哈希，用于编辑器 Tick 判断是否需要重建预览。 */
    uint32 BuildEditorPreviewHash() const;

    /** 仅允许 Editor 和 EditorPreview 世界启用预览 Tick，避免运行时重复编辑器检测。 */
    bool IsEditorPreviewWorld() const;
#endif

private:
#if WITH_EDITORONLY_DATA
    /** 缓存上一次编辑器预览哈希，变化时触发 RequestAspectBuild。 */
    uint32 CachedEditorPreviewHash = 0;
#endif
};
