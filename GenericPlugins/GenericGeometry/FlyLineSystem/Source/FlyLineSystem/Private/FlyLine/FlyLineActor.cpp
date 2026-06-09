#include "FlyLine/FlyLineActor.h"

#include "FlyLine/FlyLineComponent.h"

AFlyLineActor::AFlyLineActor()
{
    PrimaryActorTick.bCanEverTick = false;

    FlyLineComponent = CreateDefaultSubobject<UFlyLineComponent>(TEXT("FlyLineComponent"));
    RootComponent = FlyLineComponent;
}
