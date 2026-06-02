#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlopeHeatmapActor.generated.h"

class USlopeHeatmapComponent;

/** 可直接放入关卡的坡度热力图 Actor，默认挂载 Decal 组件显示坡度覆盖层。 */
UCLASS(MinimalAPI)
class ASlopeHeatmapActor : public AActor
{
    GENERATED_BODY()

public:
    /** 创建坡度热力图组件并设为 RootComponent，使 Actor 变换直接控制 Decal 体积。 */
    SLOPEHEATMAPSYSTEM_API ASlopeHeatmapActor();

public:
    /** 实际刷新 Decal 材质、响应查询并注册到子系统的组件实例。 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SlopeHeatmap")
    TObjectPtr<USlopeHeatmapComponent> SlopeHeatmapComponent=nullptr;
};
