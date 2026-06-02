#include "SlopeHeatmap/SlopeHeatmapSubsystem.h"

#include "Components/DecalComponent.h"
#include "SlopeHeatmap/SlopeHeatmapComponent.h"

namespace
{
    FVector GetSlopeHeatmapExtents(const USlopeHeatmapComponent* InComponent)
    {
        return IsValid(InComponent) ? InComponent->DecalSize : FVector::ZeroVector;
    }

    float CalculateSlopeDegrees(const FVector& SurfaceNormal)
    {
        return FMath::RadiansToDegrees(
            FMath::Acos(FMath::Clamp(FVector::DotProduct(SurfaceNormal.GetSafeNormal(), FVector::UpVector), -1.f, 1.f)));
    }

    bool IsInsideSlopeHeatmapVolume(const USlopeHeatmapComponent* InComponent, const FVector& WorldLocation, FVector& OutLocalLocation)
    {
        if (!IsValid(InComponent))
        {
            return false;
        }

        OutLocalLocation = InComponent->GetComponentTransform().InverseTransformPosition(WorldLocation);
        const FVector Extent = GetSlopeHeatmapExtents(InComponent);
        return FMath::Abs(OutLocalLocation.X) <= Extent.X
            && FMath::Abs(OutLocalLocation.Y) <= Extent.Y
            && FMath::Abs(OutLocalLocation.Z) <= Extent.Z;
    }

    bool TraceSlopeHeatmapSurface(const USlopeHeatmapComponent* InComponent, const FVector& WorldLocation, FHitResult& OutHit)
    {
        if (!IsValid(InComponent) || !IsValid(InComponent->GetWorld()))
        {
            return false;
        }

        FVector LocalLocation = FVector::ZeroVector;
        if (!IsInsideSlopeHeatmapVolume(InComponent, WorldLocation, LocalLocation))
        {
            return false;
        }

        const FVector Extent = GetSlopeHeatmapExtents(InComponent);
        const FTransform ComponentTransform = InComponent->GetComponentTransform();
        const FVector LocalTraceStart(Extent.X, LocalLocation.Y, LocalLocation.Z);
        const FVector LocalTraceEnd(-Extent.X, LocalLocation.Y, LocalLocation.Z);
        const FVector TraceStart = ComponentTransform.TransformPosition(LocalTraceStart);
        const FVector TraceEnd = ComponentTransform.TransformPosition(LocalTraceEnd);

        FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(GenericSlopeHeatmapTrace), true);
        QueryParams.bTraceComplex = true;
        if (IsValid(InComponent->GetOwner()))
        {
            QueryParams.AddIgnoredActor(InComponent->GetOwner());
        }

        FCollisionObjectQueryParams ObjectQueryParams;
        ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
        ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

        return InComponent->GetWorld()->LineTraceSingleByObjectType(OutHit, TraceStart, TraceEnd, ObjectQueryParams, QueryParams);
    }
}

USlopeHeatmapSubsystem* USlopeHeatmapSubsystem::Get(const UObject* WorldContextObject)
{
    if (!IsValid(WorldContextObject) || !IsValid(GEngine))
    {
        return nullptr;
    }

    if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
    {
        return World->GetSubsystem<USlopeHeatmapSubsystem>();
    }

    return nullptr;
}

bool USlopeHeatmapSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
    return WorldType == EWorldType::Game
        || WorldType == EWorldType::PIE
        || WorldType == EWorldType::Editor
        || WorldType == EWorldType::EditorPreview;
}

void USlopeHeatmapSubsystem::Deinitialize()
{
    RuntimeStates.Reset();
    Super::Deinitialize();
}

void USlopeHeatmapSubsystem::RegisterSlopeHeatmapComponent(USlopeHeatmapComponent* InComponent)
{
    if (IsValid(InComponent))
    {
        RuntimeStates.FindOrAdd(InComponent);
    }
}

void USlopeHeatmapSubsystem::UnregisterSlopeHeatmapComponent(USlopeHeatmapComponent* InComponent)
{
    RuntimeStates.Remove(InComponent);
}

void USlopeHeatmapSubsystem::RequestSlopeHeatmapBuild(USlopeHeatmapComponent* InComponent)
{
    RebuildSlopeHeatmap(InComponent);
}

void USlopeHeatmapSubsystem::RebuildSlopeHeatmap(USlopeHeatmapComponent* InComponent)
{
    if (!IsValid(InComponent))
    {
        return;
    }

    FSlopeHeatmapRuntimeState& RuntimeState = RuntimeStates.FindOrAdd(InComponent);
    RuntimeState.BuildStats.BuildState = EGeometryBuildState::Building;
    const double StartTime = FPlatformTime::Seconds();

    InComponent->RefreshRenderDecal();

    RuntimeState.BuildStats.BuildCount++;
    RuntimeState.BuildStats.BuildState = EGeometryBuildState::Ready;
    RuntimeState.BuildStats.NumInputs = 1;
    RuntimeState.BuildStats.NumOutputs = IsValid(InComponent->GetDecalMaterial()) ? 1 : 0;
    RuntimeState.BuildStats.LastBuildDurationMs = static_cast<float>((FPlatformTime::Seconds() - StartTime) * 1000.0);
    RuntimeState.BuildStats.LastMessage = IsValid(InComponent->GetDecalMaterial())
        ? TEXT("Slope heatmap decal refreshed.")
        : TEXT("Slope heatmap decal refresh failed.");

    UE_LOG(LogSlopeHeatmap, Verbose, TEXT("%s"), *RuntimeState.BuildStats.LastMessage);
    InComponent->OnSlopeHeatmapBuildFinished.Broadcast(RuntimeState.BuildStats);
}

FSlopeHeatmapQueryResult USlopeHeatmapSubsystem::QuerySlopeHeatmapAtWorldLocation(const USlopeHeatmapComponent* InComponent, const FVector& WorldLocation) const
{
    FSlopeHeatmapQueryResult QueryResult;
    QueryResult.bValid = false;

    FHitResult HitResult;
    if (!TraceSlopeHeatmapSurface(InComponent, WorldLocation, HitResult))
    {
        return QueryResult;
    }

    QueryResult.bValid = true;
    QueryResult.WorldLocation = HitResult.ImpactPoint;
    QueryResult.SurfaceNormal = HitResult.ImpactNormal.GetSafeNormal();
    QueryResult.SlopeDegrees = CalculateSlopeDegrees(QueryResult.SurfaceNormal);
    QueryResult.NormalizedHeat = FMath::Clamp(QueryResult.SlopeDegrees / 90.f, 0.f, 1.f);

    const FVector LocalLocation = InComponent->GetComponentTransform().InverseTransformPosition(HitResult.ImpactPoint);
    const FVector Extent = GetSlopeHeatmapExtents(InComponent);
    const FVector2D NormalizedLocal(
        Extent.Y > KINDA_SMALL_NUMBER ? (LocalLocation.Y + Extent.Y) / (Extent.Y * 2.f) : 0.f,
        Extent.Z > KINDA_SMALL_NUMBER ? (LocalLocation.Z + Extent.Z) / (Extent.Z * 2.f) : 0.f);
    QueryResult.CellCoord = FIntPoint(
        FMath::Clamp(FMath::FloorToInt(NormalizedLocal.X * 1024.f), 0, 1023),
        FMath::Clamp(FMath::FloorToInt(NormalizedLocal.Y * 1024.f), 0, 1023));

    return QueryResult;
}
