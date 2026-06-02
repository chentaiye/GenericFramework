#pragma once

#include "CoreMinimal.h"
#include "GenericGeometryTypes.h"
#include "Skyline/SkylineTypes.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "SkylineSubsystem.generated.h"

class USkylineComponent;
class FSubsystemCollectionBase;

/** 调度 Skyline 后期处理组件，负责选择当前生效组件、同步材质状态并维护查询缓存。 */
UCLASS(MinimalAPI)
class USkylineSubsystem : public UGenericWorldSubsystem
{
    GENERATED_BODY()

public:
    static SKYLINESYSTEM_API USkylineSubsystem* Get(const UObject* WorldContextObject);

    SKYLINESYSTEM_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    SKYLINESYSTEM_API virtual void Deinitialize() override;

    /** 注册 Skyline 组件并分配顺序号，使最后注册且可渲染的组件成为当前后期来源。 */
    SKYLINESYSTEM_API void RegisterSkylineComponent(USkylineComponent* InComponent);

    /** 注销组件并重新选择活动组件，必要时关闭失效组件的后期处理输出。 */
    SKYLINESYSTEM_API void UnregisterSkylineComponent(USkylineComponent* InComponent);

    /** 标记组件状态为脏并进入 Queued，下一次 Tick 会同步后期材质并广播。 */
    SKYLINESYSTEM_API void RequestSkylineBuild(USkylineComponent* InComponent);

    /** 立即处理一次 Skyline 刷新，用于蓝图手动重建后马上应用材质参数。 */
    SKYLINESYSTEM_API void RebuildSkyline(USkylineComponent* InComponent);

    /** 运行时 Tick 入口，持续选择活动组件并刷新其后期处理状态。 */
    SKYLINESYSTEM_API void TickRuntimeSkyline(USkylineComponent* InComponent);

    /** 编辑器 Tick 入口，使编辑器可见性和属性变化能即时影响预览。 */
    SKYLINESYSTEM_API void TickEditorSkyline(USkylineComponent* InComponent);

    /** 从已注册且可渲染的组件中选择注册顺序最新的活动 Skyline 组件。 */
    SKYLINESYSTEM_API USkylineComponent* FindActiveSkylineComponent() const;

    /** 返回最后一次轮廓结果；后期处理实现不再生成采样轮廓，因此通常为空。 */
    UFUNCTION(BlueprintPure, Category="Skyline")
    SKYLINESYSTEM_API FSkylineContour GetLastContour(const USkylineComponent* InComponent) const;

    /** 返回最后一次 Skyline 状态统计，反映子系统最近一次 Tick 的缓存结果。 */
    UFUNCTION(BlueprintPure, Category="Skyline")
    SKYLINESYSTEM_API FSkylineMetrics GetLastMetrics(const USkylineComponent* InComponent) const;

private:
    /** 保存单个 Skyline 组件的后期处理刷新状态和兼容查询缓存。 */
    struct FSkylineRuntimeState
    {
        /** 最近一次轮廓查询缓存，当前后期材质实现会在 Tick 时清空。 */
        FSkylineContour LastContour;

        /** 最近一次状态统计缓存，当前实现不生成采样时保持默认指标。 */
        FSkylineMetrics LastMetrics;

        /** 最近一次 Skyline 刷新的状态、输出数量和日志消息。 */
        FGenericGeometryBuildStats BuildStats;

        /** 组件注册顺序，FindActiveSkylineComponent 用它选择最新可见组件。 */
        int32 RegistrationOrder = 0;

        /** 标记材质参数或可见性需要广播刷新，Tick 后会复位。 */
        bool bDirty = true;
    };

private:
    virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

    /** 执行一次活动组件选择、后期启停和构建状态更新。 */
    void TickSkylinePostProcess(USkylineComponent* InComponent);

    /** 关闭非活动组件的后期处理输出，避免多个 Skyline 材质同时生效。 */
    void DisableInactiveComponents(USkylineComponent* ActiveComponent);

    /** 以组件实例为键保存运行时状态，支持同一世界多个 Skyline 组件竞争激活。 */
    TMap<TObjectPtr<USkylineComponent>, FSkylineRuntimeState> RuntimeStates;

    /** 下一个注册顺序号，用于稳定决定最新注册且可见的组件。 */
    int32 NextRegistrationOrder = 1;
};
