#include "BPFunctions/BPFunctions_FlyLine.h"

#include "FlyLine/FlyLineSubsystem.h"

void UBPFunctions_FlyLine::RegisterFlyLineConnection(const UObject* WorldContextObject, const FFlyLineConnection& Connection)
{
    if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(WorldContextObject))
    {
        FlyLineSubsystem->RegisterConnection(Connection);
    }
}

TArray<FName> UBPFunctions_FlyLine::ConnectOneToMany(const UObject* WorldContextObject, FName SourceEndpointId, const TArray<FName>& TargetEndpointIds, const FFlyLineStyle& Style, FName ConnectionPrefix)
{
    if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(WorldContextObject))
    {
        return FlyLineSubsystem->ConnectOneToMany(SourceEndpointId, TargetEndpointIds, Style, ConnectionPrefix);
    }
    return {};
}

TArray<FName> UBPFunctions_FlyLine::ConnectManyToMany(const UObject* WorldContextObject, const TArray<FName>& SourceEndpointIds, const TArray<FName>& TargetEndpointIds, const FFlyLineStyle& Style, FName ConnectionPrefix)
{
    if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(WorldContextObject))
    {
        return FlyLineSubsystem->ConnectManyToMany(SourceEndpointIds, TargetEndpointIds, Style, ConnectionPrefix);
    }
    return {};
}

void UBPFunctions_FlyLine::RebuildFlyLines(const UObject* WorldContextObject)
{
    if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(WorldContextObject))
    {
        FlyLineSubsystem->RebuildFlyLines();
    }
}
