#pragma once

#include "CoreMinimal.h"
#include "GenericGeometryTypes.h"
#include "Aspect/AspectTypes.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "AspectSubsystem.generated.h"

class UAspectComponent;
class AActor;
class UProceduralMeshComponent;

/** 维护 Aspect 组件运行时状态，负责地表采样、箭头网格生成、统计缓存和查询转发。 */
UCLASS(MinimalAPI)
class UAspectSubsystem : public UGenericWorldSubsystem
{
    GENERATED_BODY()

public:
    static ASPECTSYSTEM_API UAspectSubsystem* Get(const UObject* WorldContextObject);

    ASPECTSYSTEM_API virtual void Deinitialize() override;

    /** 为组件创建运行时状态，使后续构建可以复用统计和渲染 Mesh 缓存。 */
    ASPECTSYSTEM_API void RegisterAspectComponent(UAspectComponent* InComponent);

    /** 注销组件并销毁它持有的 ProceduralMeshComponent，防止编辑器残留预览网格。 */
    ASPECTSYSTEM_API void UnregisterAspectComponent(UAspectComponent* InComponent);

    /** 构建请求入口，当前实现会立即调用 RebuildAspect 同步刷新。 */
    ASPECTSYSTEM_API void RequestAspectBuild(UAspectComponent* InComponent);

    /** 按采样盒网格追踪地表，生成下坡箭头几何、更新统计并广播完成状态。 */
    ASPECTSYSTEM_API void RebuildAspect(UAspectComponent* InComponent);

    /** 对指定世界位置做一次独立追踪，不依赖已生成网格即可返回坡向单元结果。 */
    UFUNCTION(BlueprintPure, Category="Aspect")
    ASPECTSYSTEM_API FAspectTileResult QueryAtWorldLocation(const UAspectComponent* InComponent, const FVector& WorldLocation) const;

    /** 读取组件最近一次 RebuildAspect 生成的坡度统计缓存。 */
    UFUNCTION(BlueprintPure, Category="Aspect")
    ASPECTSYSTEM_API FAspectStatistics GetStatistics(const UAspectComponent* InComponent) const;

private:
    /** 保存单个 Aspect 组件的构建结果和动态渲染资源。 */
    struct FAspectRuntimeState
    {
        /** 最近一次有效样本的坡度统计，蓝图查询函数直接返回该缓存。 */
        FAspectStatistics Statistics;

        /** 最近一次重建的状态、输入输出数量和耗时信息。 */
        FGenericGeometryBuildStats BuildStats;

        /** 按组件名缓存箭头 ProceduralMesh，重建时复用并在注销时销毁。 */
        TMap<FName, TObjectPtr<UProceduralMeshComponent>> RenderMeshes;
    };

private:
    virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

private:
    /** 以组件实例为键保存运行时状态，支持多个采样盒在同一世界中独立重建。 */
    TMap<TObjectPtr<UAspectComponent>, FAspectRuntimeState> RuntimeStates;
};
