#include "Aspect/AspectActor.h"

#include "Aspect/AspectComponent.h"

AAspectActor::AAspectActor()
{
    PrimaryActorTick.bCanEverTick = false;

    AspectComponent = CreateDefaultSubobject<UAspectComponent>(TEXT("AspectComponent"));
    RootComponent = AspectComponent;
}
