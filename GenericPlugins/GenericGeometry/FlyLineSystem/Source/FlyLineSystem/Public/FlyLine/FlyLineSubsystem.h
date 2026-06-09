#pragma once

#include "CoreMinimal.h"
#include "GenericGeometryTypes.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "FlyLine/FlyLineTypes.h"
#include "FlyLineSubsystem.generated.h"

class AActor;
class UInstancedStaticMeshComponent;
class UFlyLineComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFlyLineBuildFinishedSignature, FGenericGeometryBuildStats, BuildStats);

/** 管理飞线端点和显式连接，并把解析后的连接批量渲染为 ISM 抛物线段。 */
UCLASS(MinimalAPI)
class UFlyLineSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	static FLYLINESYSTEM_API UFlyLineSubsystem* Get(const UObject* WorldContextObject);

	FLYLINESYSTEM_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	FLYLINESYSTEM_API virtual void Deinitialize() override;

	/** 注册端点组件并按解析后的 ID 更新映射，随后重建所有飞线。 */
	FLYLINESYSTEM_API void RegisterEndpointComponent(UFlyLineComponent* InComponent);

	/** 移除端点组件对应的所有 ID 映射，并重建以清理失效连接。 */
	FLYLINESYSTEM_API void UnregisterEndpointComponent(UFlyLineComponent* InComponent);

	/** 端点变换或属性变化后刷新 ID 映射，并让现有连接跟随新位置。 */
	FLYLINESYSTEM_API void NotifyEndpointUpdated(UFlyLineComponent* InComponent);

	/** 添加或覆盖一条显式连接，缺省 ID 会按端点和当前数量生成。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine")
	FLYLINESYSTEM_API void RegisterConnection(const FFlyLineConnection& InConnection);

	/** 批量注册显式连接，每条连接都会进入 ExplicitConnections 后触发重建。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine")
	FLYLINESYSTEM_API void RegisterConnections(const TArray<FFlyLineConnection>& InConnections);

	/** 按连接 ID 删除显式连接，并重新生成剩余飞线实例。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine")
	FLYLINESYSTEM_API void RemoveConnection(FName InConnectionId);

	/** 清空所有显式连接，保留端点注册但移除手动飞线输出。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine")
	FLYLINESYSTEM_API void ClearConnections();

	/** 解析显式和自动组连接，按 Mesh/材质批次重建飞线 ISM 实例。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine")
	FLYLINESYSTEM_API void RebuildFlyLines();

	/** 返回当前显式连接快照，不包含按组自动生成的临时连接。 */
	UFUNCTION(BlueprintPure, Category="FlyLine")
	FLYLINESYSTEM_API TArray<FFlyLineConnection> GetConnections() const;

	/** 从一个源端点创建到多个目标端点的显式连接，并返回注册后的连接 ID。 */
	FLYLINESYSTEM_API TArray<FName> ConnectOneToMany(FName SourceEndpointId, const TArray<FName>& TargetEndpointIds, const FFlyLineStyle& InStyle, FName ConnectionPrefix = TEXT("OneToMany"));

	/** 为多个源端点和多个目标端点成对创建连接，跳过源目标相同的组合。 */
	FLYLINESYSTEM_API TArray<FName> ConnectManyToMany(const TArray<FName>& SourceEndpointIds, const TArray<FName>& TargetEndpointIds, const FFlyLineStyle& InStyle, FName ConnectionPrefix = TEXT("ManyToMany"));

	/** 返回最近一次 RebuildFlyLines 生成的构建状态，供 C++ 调试或 UI 展示使用。 */
	const FGenericGeometryBuildStats& GetBuildStats() const { return BuildStats; }

public:
	UPROPERTY(BlueprintAssignable, Category="FlyLine")
	FFlyLineBuildFinishedSignature OnFlyLinesRebuilt;

protected:
	FLYLINESYSTEM_API virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

	/** 合并显式连接和同组端点自动连接，生成本次重建实际参与渲染的连接列表。 */
	FLYLINESYSTEM_API TArray<FFlyLineConnection> BuildActiveConnections() const;

	/** 补齐请求样式中的默认 Mesh、材质、宽度和分段参数，保证渲染阶段有可用资源。 */
	FLYLINESYSTEM_API FFlyLineStyle ResolveStyle(const FFlyLineStyle& RequestedStyle) const;

	/** 优先从源端点再从目标端点的组样式表解析自动连线样式。 */
	FLYLINESYSTEM_API FFlyLineStyle ResolveAutoGroupStyle(const UFlyLineComponent* SourceComponent, const UFlyLineComponent* TargetComponent, FName GroupName) const;

	/** 按前缀、端点和序号生成稳定连接名，用于批量注册和自动组连接。 */
	FLYLINESYSTEM_API FName MakeConnectionId(FName Prefix, FName SourceEndpointId, FName TargetEndpointId, int32 Index) const;

protected:
	/** 端点 ID 到组件实例的映射，飞线重建用它解析连接两端的位置。 */
	UPROPERTY(Transient)
	TMap<FName, TObjectPtr<UFlyLineComponent>> EndpointComponents;

	/** 手动注册的连接缓存，Register/Remove/Clear 系列函数只修改该集合。 */
	UPROPERTY(Transient)
	TMap<FName, FFlyLineConnection> ExplicitConnections;

	/** 最近一次飞线重建的输入端点数、输出连接数和耗时。 */
	UPROPERTY(Transient)
	FGenericGeometryBuildStats BuildStats;

	/** 按批次名缓存 ISM 组件，使相同 Mesh/材质的线段复用同一渲染组件。 */
	UPROPERTY(Transient)
	TMap<FName, TObjectPtr<UInstancedStaticMeshComponent>> BatchComponents;

	/** 承载所有飞线批次组件的瞬态 Actor，子系统反初始化时会销毁。 */
	TWeakObjectPtr<AActor> RenderActor;
};
