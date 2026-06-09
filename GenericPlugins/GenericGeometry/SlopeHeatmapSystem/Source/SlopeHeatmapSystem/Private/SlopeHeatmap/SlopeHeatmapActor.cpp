#include "SlopeHeatmap/SlopeHeatmapActor.h"

#include "SlopeHeatmap/SlopeHeatmapComponent.h"

ASlopeHeatmapActor::ASlopeHeatmapActor()
{
    PrimaryActorTick.bCanEverTick = false;

    SlopeHeatmapComponent = CreateDefaultSubobject<USlopeHeatmapComponent>(TEXT("SlopeHeatmapComponent"));
    RootComponent = SlopeHeatmapComponent;
}
