#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GenericGeometryTypes.h"
#include "Skyline/SkylineTypes.h"
#include "SkylineComponent.generated.h"

struct FPropertyChangedEvent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UPostProcessComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSkylineBuildFinishedSignature, FGenericGeometryBuildStats, BuildStats);

/** 挂在场景对象上的 Skyline 控制组件，负责创建后期处理组件并把状态同步给子系统。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class USkylineComponent : public UActorComponent
{
    GENERATED_BODY()

    friend class USkylineSubsystem;

public:
    /** 初始化运行时和编辑器 Tick，使后期材质参数能在激活组件上持续同步。 */
    SKYLINESYSTEM_API USkylineComponent();

    SKYLINESYSTEM_API virtual void OnRegister() override;
    SKYLINESYSTEM_API virtual void OnUnregister() override;
    SKYLINESYSTEM_API virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#if WITH_EDITOR
    SKYLINESYSTEM_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    /** 标记当前 Skyline 状态需要刷新，子系统会在 Tick 中同步后期材质。 */
    UFUNCTION(BlueprintCallable, CallInEditor, Category="Skyline")
    SKYLINESYSTEM_API void RequestSkylineBuild();

    /** 返回子系统缓存的上次轮廓结果；当前后期处理路径通常返回空轮廓。 */
    UFUNCTION(BlueprintPure, Category="Skyline")
    SKYLINESYSTEM_API FSkylineContour GetLastContour() const;

    /** 返回子系统缓存的上次刷新统计，用于蓝图确认 Skyline 输出状态。 */
    UFUNCTION(BlueprintPure, Category="Skyline")
    SKYLINESYSTEM_API FSkylineMetrics GetLastMetrics() const;

public:
    /** 后期描边颜色和宽度配置，组件激活时会写入动态材质实例。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skyline")
    FSkylineRenderConfig RenderConfig;

    UPROPERTY(BlueprintAssignable, Category="Skyline")
    FSkylineBuildFinishedSignature OnSkylineBuildFinished;

private:
    /** 根据当前组件是否为活动组件启停后期处理，并维护 WeightedBlendables。 */
    void UpdateSkylinePostProcessState(bool bShouldRender);

    /** 销毁组件创建的瞬态 PostProcessComponent，并清空动态材质引用。 */
    void DestroySkylinePostProcess();

    /** 确保拥有者 Actor 下存在已注册的后期处理组件，供激活时写入材质。 */
    void EnsureSkylinePostProcess();

    /** 懒加载 Skyline 后期材质并创建 MID，失败时返回空指针让调用方跳过同步。 */
    UMaterialInstanceDynamic* GetOrCreateSkylinePostProcessMID();

    /** 将 RenderConfig 中的颜色和线宽同步到 Skyline 后期处理 MID。 */
    void ApplySkylinePostProcessParameters();

private:
    /** 组件运行时创建的后期处理组件，只在当前 Skyline 组件激活时启用。 */
    UPROPERTY(Transient)
    TObjectPtr<UPostProcessComponent> SkylinePostProcessComponent = nullptr;

    /** 插件默认 Skyline 后期处理材质资源，首次创建 MID 时按路径加载。 */
    UPROPERTY(Transient)
    TObjectPtr<UMaterialInterface> SkylinePostProcessMaterial = nullptr;

    /** 动态材质实例，承载 LineColor 和 LineThicknessPx 参数。 */
    UPROPERTY(Transient)
    TObjectPtr<UMaterialInstanceDynamic> SkylinePostProcessMID = nullptr;
};
