#include "AsyncAction/SlopeHeatmapAsyncAction.h"

#include "Engine/World.h"
#include "SlopeHeatmap/SlopeHeatmapComponent.h"
#include "SlopeHeatmap/SlopeHeatmapSubsystem.h"
#include "TimerManager.h"

USlopeHeatmapAsyncAction* USlopeHeatmapAsyncAction::BuildSlopeHeatmapAsync(USlopeHeatmapComponent* InComponent)
{
    USlopeHeatmapAsyncAction* Action = NewObject<USlopeHeatmapAsyncAction>();
    Action->Component = InComponent;
    return Action;
}

void USlopeHeatmapAsyncAction::Activate()
{
    if (!IsValid(Component) || !IsValid(Component->GetWorld()))
    {
        OnCompleted.Broadcast(Component);
        return;
    }

    Component->GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateWeakLambda(this, [this]()
        {
            if (USlopeHeatmapSubsystem* SlopeHeatmapSubsystem = USlopeHeatmapSubsystem::Get(Component))
            {
                SlopeHeatmapSubsystem->RebuildSlopeHeatmap(Component);
            }
            OnCompleted.Broadcast(Component);
        }));
}
