#include "AsyncAction/AspectAsyncAction.h"

#include "Engine/World.h"
#include "Aspect/AspectComponent.h"
#include "Aspect/AspectSubsystem.h"
#include "TimerManager.h"

UAspectAsyncAction* UAspectAsyncAction::BuildAspectAsync(UAspectComponent* InComponent)
{
    UAspectAsyncAction* Action = NewObject<UAspectAsyncAction>();
    Action->Component = InComponent;
    return Action;
}

void UAspectAsyncAction::Activate()
{
    if (!IsValid(Component) || !IsValid(Component->GetWorld()))
    {
        OnCompleted.Broadcast(Component);
        return;
    }

    Component->GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateWeakLambda(this, [this]()
        {
            if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(Component))
            {
                Subsystem->RebuildAspect(Component);
            }
            OnCompleted.Broadcast(Component);
        }));
}
