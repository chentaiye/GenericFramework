#include "AsyncAction/SkylineAsyncAction.h"

#include "Engine/World.h"
#include "Skyline/SkylineComponent.h"
#include "Skyline/SkylineSubsystem.h"
#include "TimerManager.h"

USkylineAsyncAction* USkylineAsyncAction::BuildSkylineAsync(USkylineComponent* InComponent)
{
    USkylineAsyncAction* Action = NewObject<USkylineAsyncAction>();
    Action->Component = InComponent;
    return Action;
}

void USkylineAsyncAction::Activate()
{
    if (!IsValid(Component) || !IsValid(Component->GetWorld()))
    {
        OnCompleted.Broadcast(Component);
        return;
    }

    Component->GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateWeakLambda(this, [this]()
        {
            if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(Component))
            {
                Subsystem->RebuildSkyline(Component);
            }
            OnCompleted.Broadcast(Component);
        }));
}
