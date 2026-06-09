#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SkylineAsyncAction.generated.h"

class USkylineComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSkylineAsyncCompletedSignature, USkylineComponent*, Component);

/** 蓝图异步节点包装 Skyline 刷新，在下一帧同步后期处理状态并广播完成。 */
UCLASS(MinimalAPI)
class USkylineAsyncAction : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    SKYLINESYSTEM_API virtual void Activate() override;

    /** 创建异步动作并保存目标组件，Activate 时再调度实际 RebuildSkyline。 */
    UFUNCTION(BlueprintCallable, Category="Skyline", meta=(BlueprintInternalUseOnly="true"))
    static SKYLINESYSTEM_API USkylineAsyncAction* BuildSkylineAsync(USkylineComponent* InComponent);

public:
    UPROPERTY(BlueprintAssignable, Category="Skyline")
    FSkylineAsyncCompletedSignature OnCompleted;

private:
    /** 需要在下一帧刷新的目标组件，完成回调也会把它传回蓝图。 */
    UPROPERTY()
    TObjectPtr<USkylineComponent> Component=nullptr;
};
