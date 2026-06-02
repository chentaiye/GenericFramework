#include "BPFunctions/BPFunctions_Skyline.h"

#include "Skyline/SkylineComponent.h"
#include "Skyline/SkylineSubsystem.h"

void UBPFunctions_Skyline::RebuildSkyline(const UObject* WorldContextObject, USkylineComponent* Component)
{
    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(WorldContextObject))
    {
        Subsystem->RebuildSkyline(Component);
    }
}

FSkylineContour UBPFunctions_Skyline::GetSkylineContour(const UObject* WorldContextObject, USkylineComponent* Component)
{
    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(WorldContextObject))
    {
        return Subsystem->GetLastContour(Component);
    }
    return {};
}

FSkylineMetrics UBPFunctions_Skyline::GetSkylineMetrics(const UObject* WorldContextObject, USkylineComponent* Component)
{
    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(WorldContextObject))
    {
        return Subsystem->GetLastMetrics(Component);
    }
    return {};
}
