#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "FlyLineTypes.generated.h"

class UMaterialInterface;
class UStaticMesh;

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeometry_FlyLine);

/** 描述飞线连接的拓扑来源，子系统会据此区分显式连接和批量生成的连接。 */
UENUM(BlueprintType)
enum class EFlyLineConnectionMode : uint8
{
    /** 一个源端点连接一个目标端点，适合手动注册的精确飞线。 */
    OneToOne,

    /** 一个源端点批量连接多个目标端点，由 ConnectOneToMany 生成连接 ID。 */
    OneToMany,

    /** 多个源端点与多个目标端点成对连接，也用于同组端点自动连线。 */
    ManyToMany
};

/** 定义飞线渲染样式，重建时会解析默认 Mesh/材质并把参数写入实例数据。 */
USTRUCT(BlueprintType)
struct FLYLINESYSTEM_API FFlyLineStyle
{
    GENERATED_BODY()

public:
    /** 样式来源标识，按组样式表解析时通常写入 DataTable 行名。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    FName StyleId = NAME_None;

    /** 飞线每个线段实例使用的 StaticMesh；为空时子系统回退到默认 Cube。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    TObjectPtr<UStaticMesh> LineMesh=nullptr;

    /** 飞线实例使用的材质；为空时子系统回退到基础形状材质。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    TObjectPtr<UMaterialInterface> LineMaterial=nullptr;

    /** 线段实例的可视宽度，会参与 BuildLineTransform 的缩放计算。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine", meta=(ClampMin="1.0"))
    float Width=10.f;

    /** 抛物线中点相对起止点的高度偏移，用于控制飞线弧度。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    float HeightOffset=120.f;

    /** 抛物线拆分段数，段数越高飞线越平滑但实例数量也越多。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine", meta=(ClampMin="1"))
    int32 SegmentCount=6;
};

/** DataTable 行结构，用组件组名查找自动飞线样式并转写到 FFlyLineStyle。 */
USTRUCT(BlueprintType)
struct FLYLINESYSTEM_API FFlyLineGroupStyleRow : public FTableRowBase
{
    GENERATED_BODY()

public:
    /** 绑定的端点组名；为空时查找逻辑使用 DataTable 行名作为组名。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    FName GroupName=NAME_None;

    /** 自动组连接使用的线段 Mesh，解析失败时仍会走默认 Mesh 回退。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    TObjectPtr<UStaticMesh> LineMesh=nullptr;

    /** 自动组连接的线宽，会复制到最终 FFlyLineStyle。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine", meta=(ClampMin="1.0"))
    float Width=10.f;

    /** 自动组连接的抛物线高度偏移，控制同组端点之间的弧线高度。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    float HeightOffset=120.f;

    /** 自动组连接的曲线分段数，影响生成的线段实例数量。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine", meta=(ClampMin="1"))
    int32 SegmentCount=6;
};

/** 飞线端点在子系统中的注册快照，由组件构建后参与连接解析。 */
USTRUCT(BlueprintType)
struct FLYLINESYSTEM_API FFlyLineEndpoint
{
    GENERATED_BODY()

public:
    /** 端点唯一 ID，显式连接通过该值查找源组件和目标组件。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    FName EndpointId=NAME_None;

    /** 端点注册时的世界变换，保留给外部查询或后续扩展使用。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    FTransform WorldTransform=FTransform::Identity;

    /** GameplayTag 分类，可用于蓝图侧筛选或描述飞线端点语义。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine", meta=(Categories="GameplayGeometry.FlyLine"))
    FGameplayTag EndpointTag;

    /** 端点参与的自动连接组名，BuildActiveConnections 会同组两两生成连接。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    TArray<FName> GroupNames;
};

/** 描述一条待渲染飞线的端点关系和样式，显式连接会缓存到子系统映射中。 */
USTRUCT(BlueprintType)
struct FLYLINESYSTEM_API FFlyLineConnection
{
    GENERATED_BODY()

public:
    /** 连接唯一 ID；为空注册时子系统会根据端点和序号生成。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    FName ConnectionId=NAME_None;

    /** 源端点 ID，重建时用于从 EndpointComponents 映射查找起点组件。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    FName SourceEndpointId=NAME_None;

    /** 目标端点 ID，重建时用于查找终点组件并生成抛物线。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    FName TargetEndpointId=NAME_None;

    /** 连接来源模式，便于调用方区分手动、单对多或多对多生成的飞线。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    EFlyLineConnectionMode ConnectionMode=EFlyLineConnectionMode::OneToOne;

    /** 连接启用标记会随连接快照传递，供蓝图或后续过滤规则表达配置状态。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    bool bEnabled=true;

    /** 本连接请求的渲染样式，重建前会通过 ResolveStyle 补齐默认资源。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    FFlyLineStyle Style;
};

/** 用 Mesh 和材质组合标识同批次飞线，子系统据此复用 InstancedStaticMeshComponent。 */
USTRUCT(BlueprintType)
struct FLYLINESYSTEM_API FFlyLineBatchKey
{
    GENERATED_BODY()

public:
    /** 批次使用的线段 Mesh，相同 Mesh 和材质会合并实例。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    TObjectPtr<UStaticMesh> LineMesh=nullptr;

    /** 批次使用的材质，和 Mesh 一起决定 ISM 组件键。 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
    TObjectPtr<UMaterialInterface> LineMaterial=nullptr;

    bool operator==(const FFlyLineBatchKey& Other) const { return LineMesh == Other.LineMesh && LineMaterial == Other.LineMaterial; }
};

FORCEINLINE uint32 GetTypeHash(const FFlyLineBatchKey& Key) { return HashCombine(GetTypeHash(Key.LineMesh), GetTypeHash(Key.LineMaterial)); }
