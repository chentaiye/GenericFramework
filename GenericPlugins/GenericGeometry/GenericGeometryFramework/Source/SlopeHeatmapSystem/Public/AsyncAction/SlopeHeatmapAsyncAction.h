#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SlopeHeatmapAsyncAction.generated.h"

class USlopeHeatmapComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlopeHeatmapAsyncCompletedSignature, USlopeHeatmapComponent*, Component);

/** 蓝图异步节点包装坡度热力图刷新，在下一帧重建 Decal 状态后广播完成。 */
UCLASS(MinimalAPI)
class USlopeHeatmapAsyncAction : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    SLOPEHEATMAPSYSTEM_API virtual void Activate() override;

    /** 创建异步动作并保存目标组件，Activate 时再调度实际 RebuildSlopeHeatmap。 */
    UFUNCTION(BlueprintCallable, Category="SlopeHeatmap", meta=(BlueprintInternalUseOnly="true"))
    static SLOPEHEATMAPSYSTEM_API USlopeHeatmapAsyncAction* BuildSlopeHeatmapAsync(USlopeHeatmapComponent* InComponent);

public:
    UPROPERTY(BlueprintAssignable, Category="SlopeHeatmap")
    FSlopeHeatmapAsyncCompletedSignature OnCompleted;

private:
    /** 需要在下一帧刷新的目标组件，完成回调也会把它传回蓝图。 */
    UPROPERTY()
    TObjectPtr<USlopeHeatmapComponent> Component=nullptr;
};
