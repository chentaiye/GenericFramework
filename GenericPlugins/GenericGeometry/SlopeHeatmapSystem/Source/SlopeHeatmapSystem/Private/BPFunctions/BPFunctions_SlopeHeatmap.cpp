#include "BPFunctions/BPFunctions_SlopeHeatmap.h"

#include "SlopeHeatmap/SlopeHeatmapComponent.h"
#include "SlopeHeatmap/SlopeHeatmapSubsystem.h"

void UBPFunctions_SlopeHeatmap::RebuildSlopeHeatmap(const UObject* WorldContextObject, USlopeHeatmapComponent* Component)
{
    if (USlopeHeatmapSubsystem* SlopeHeatmapSubsystem = USlopeHeatmapSubsystem::Get(WorldContextObject))
    {
        SlopeHeatmapSubsystem->RebuildSlopeHeatmap(Component);
    }
}

FSlopeHeatmapQueryResult UBPFunctions_SlopeHeatmap::QuerySlopeHeatmapAtLocation(const UObject* WorldContextObject, USlopeHeatmapComponent* Component, const FVector& WorldLocation)
{
    if (USlopeHeatmapSubsystem* SlopeHeatmapSubsystem = USlopeHeatmapSubsystem::Get(WorldContextObject))
    {
        return SlopeHeatmapSubsystem->QuerySlopeHeatmapAtWorldLocation(Component, WorldLocation);
    }
    return {};
}
