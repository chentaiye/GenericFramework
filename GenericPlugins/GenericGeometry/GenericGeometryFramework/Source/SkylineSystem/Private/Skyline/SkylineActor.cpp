#include "Skyline/SkylineActor.h"

#include "Components/SceneComponent.h"
#include "Skyline/SkylineComponent.h"

ASkylineActor::ASkylineActor()
{
    PrimaryActorTick.bCanEverTick = false;

    SkylineComponent = CreateDefaultSubobject<USkylineComponent>(TEXT("SkylineComponent"));
}
