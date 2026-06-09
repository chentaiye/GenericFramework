#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlyLineActor.generated.h"

class UFlyLineComponent;

/** 可直接放入关卡的飞线端点 Actor，默认挂载 FlyLineComponent 参与子系统连线。 */
UCLASS(MinimalAPI)
class AFlyLineActor : public AActor
{
    GENERATED_BODY()

public:
    /** 创建飞线端点组件并设为 RootComponent，使 Actor 位置直接作为端点位置。 */
    FLYLINESYSTEM_API AFlyLineActor();

public:
    /** 实际注册端点、暴露组名并触发飞线重建的组件实例。 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FlyLine")
    TObjectPtr<UFlyLineComponent> FlyLineComponent=nullptr;
};
