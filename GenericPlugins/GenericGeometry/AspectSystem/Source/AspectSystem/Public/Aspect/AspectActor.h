#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AspectActor.generated.h"

class UAspectComponent;

/** 可直接放入关卡的坡向分析 Actor，默认用根组件定义采样盒并驱动箭头生成。 */
UCLASS(MinimalAPI)
class AAspectActor : public AActor
{
    GENERATED_BODY()

public:
    /** 创建坡向组件并设为 RootComponent，使放置 Actor 后即可注册到 Aspect 子系统。 */
    ASPECTSYSTEM_API AAspectActor();

public:
    /** 实际执行采样、查询和箭头网格刷新的组件实例。 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Aspect")
    TObjectPtr<UAspectComponent> AspectComponent=nullptr;
};
