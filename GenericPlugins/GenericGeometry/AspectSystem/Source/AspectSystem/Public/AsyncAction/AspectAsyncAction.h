#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AspectAsyncAction.generated.h"

class UAspectComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAspectAsyncCompletedSignature, UAspectComponent*, Component);

/** 蓝图异步节点包装 Aspect 重建请求，在下一帧执行子系统构建并广播完成。 */
UCLASS(MinimalAPI)
class UAspectAsyncAction : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    ASPECTSYSTEM_API virtual void Activate() override;

    /** 创建异步动作并保存目标组件，Activate 时再调度实际 RebuildAspect。 */
    UFUNCTION(BlueprintCallable, Category="Aspect", meta=(BlueprintInternalUseOnly="true"))
    static ASPECTSYSTEM_API UAspectAsyncAction* BuildAspectAsync(UAspectComponent* InComponent);

public:
    UPROPERTY(BlueprintAssignable, Category="Aspect")
    FAspectAsyncCompletedSignature OnCompleted;

private:
    /** 需要在下一帧重建的目标组件，完成回调也会把它传回蓝图。 */
    UPROPERTY()
    TObjectPtr<UAspectComponent> Component=nullptr;
};
