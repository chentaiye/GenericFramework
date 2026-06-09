#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkylineActor.generated.h"

class USceneComponent;
class USkylineComponent;

/** 可直接放入关卡的 Skyline 入口 Actor，默认挂载组件并由组件驱动后期描边。 */
UCLASS(MinimalAPI)
class ASkylineActor : public AActor
{
	GENERATED_BODY()

public:
	/** 创建 Skyline 组件，放置 Actor 后即可注册到子系统参与激活组件选择。 */
	SKYLINESYSTEM_API ASkylineActor();

public:
	/** 实际管理后期处理组件、材质参数和蓝图查询的 Skyline 组件。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<USkylineComponent> SkylineComponent=nullptr;
};
