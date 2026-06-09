#include "BPFunctions/BPFunctions_Aspect.h"

#include "Aspect/AspectComponent.h"
#include "Aspect/AspectSubsystem.h"

void UBPFunctions_Aspect::RebuildSlopeAspect(const UObject* WorldContextObject, UAspectComponent* Component)
{
    if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(WorldContextObject))
    {
        Subsystem->RebuildAspect(Component);
    }
}

FAspectTileResult UBPFunctions_Aspect::QueryAspectAtLocation(const UObject* WorldContextObject, UAspectComponent* Component, const FVector& WorldLocation)
{
    if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(WorldContextObject))
    {
        return Subsystem->QueryAtWorldLocation(Component, WorldLocation);
    }

    return {};
}

FAspectStatistics UBPFunctions_Aspect::GetAspectStatistics(const UObject* WorldContextObject, UAspectComponent* Component)
{
    if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(WorldContextObject))
    {
        return Subsystem->GetStatistics(Component);
    }

    return {};
}
