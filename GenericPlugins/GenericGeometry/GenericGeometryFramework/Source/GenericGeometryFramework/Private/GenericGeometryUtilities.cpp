#include "GenericGeometryUtilities.h"

#include "Components/InstancedStaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"

namespace
{
    float GetMeshLengthX(const UStaticMesh* Mesh)
    {
        if (!IsValid(Mesh))
        {
            return 100.f;
        }

        const float MeshLength = Mesh->GetBounds().BoxExtent.X * 2.f;
        return FMath::Max(MeshLength, 1.f);
    }

    float Cross2D(const FVector2D& A, const FVector2D& B, const FVector2D& C)
    {
        return (B.X - A.X) * (C.Y - A.Y) - (B.Y - A.Y) * (C.X - A.X);
    }

    void ConfigureVisualizationPrimitive(UPrimitiveComponent* Component)
    {
        if (!IsValid(Component))
        {
            return;
        }

        Component->SetVisibility(true);
        Component->SetHiddenInGame(false);
        Component->SetCullDistance(0.f);
        Component->bNeverDistanceCull = true;
        Component->bAllowCullDistanceVolume = false;
        Component->bUseAsOccluder = false;
        Component->bVisibleInRayTracing = false;
        Component->bUseAttachParentBound = false;
        Component->MinDrawDistance = 0.f;
        Component->LDMaxDrawDistance = 0.f;
        Component->SetBoundsScale(FMath::Max(Component->BoundsScale, 100.f));
        Component->MarkRenderStateDirty();
    }
}

AActor* GenericGeometryUtilities::EnsureRenderActor(UWorld* World, TWeakObjectPtr<AActor>& InOutActor, const FString& ActorName)
{
    if (!IsValid(World))
    {
        return nullptr;
    }

    if (InOutActor.IsValid())
    {
        return InOutActor.Get();
    }

    FActorSpawnParameters SpawnParameters;
    SpawnParameters.Name = *ActorName;
    SpawnParameters.ObjectFlags |= RF_Transient;
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    AActor* RenderActor = World->SpawnActor<AActor>(SpawnParameters);
    if (!IsValid(RenderActor))
    {
        return nullptr;
    }

    RenderActor->SetActorHiddenInGame(false);
    RenderActor->SetCanBeDamaged(false);
    RenderActor->SetReplicates(false);
    RenderActor->SetActorEnableCollision(false);

    USceneComponent* RootComponent = NewObject<USceneComponent>(RenderActor, TEXT("GeometryRoot"));
    RootComponent->Mobility = EComponentMobility::Movable;
    RootComponent->RegisterComponent();
    RenderActor->SetRootComponent(RootComponent);

    InOutActor = RenderActor;
    return RenderActor;
}

UInstancedStaticMeshComponent* GenericGeometryUtilities::EnsureInstancedMeshComponent(
    AActor* OwnerActor,
    TMap<FName, TObjectPtr<UInstancedStaticMeshComponent>>& InOutComponents,
    const FName ComponentName,
    UStaticMesh* Mesh,
    UMaterialInterface* Material,
    int32 NumCustomDataFloats)
{
    if (!IsValid(OwnerActor))
    {
        return nullptr;
    }

    if (TObjectPtr<UInstancedStaticMeshComponent>* ExistingComponent = InOutComponents.Find(ComponentName))
    {
        if (IsValid(*ExistingComponent))
        {
            UInstancedStaticMeshComponent* Component = ExistingComponent->Get();
            if (Component->GetStaticMesh() != Mesh)
            {
                Component->SetStaticMesh(Mesh);
            }
            if (IsValid(Material))
            {
                Component->SetMaterial(0, Material);
            }
            Component->NumCustomDataFloats = NumCustomDataFloats;
            ConfigureVisualizationPrimitive(Component);
            return Component;
        }
    }

    UInstancedStaticMeshComponent* Component = NewObject<UInstancedStaticMeshComponent>(OwnerActor, ComponentName);
    if (!IsValid(Component))
    {
        return nullptr;
    }

    Component->SetupAttachment(OwnerActor->GetRootComponent());
    Component->SetMobility(EComponentMobility::Movable);
    Component->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Component->SetCanEverAffectNavigation(false);
    Component->NumCustomDataFloats = NumCustomDataFloats;
    Component->SetStaticMesh(Mesh);
    if (IsValid(Material))
    {
        Component->SetMaterial(0, Material);
    }
    ConfigureVisualizationPrimitive(Component);
    Component->RegisterComponent();

    InOutComponents.Add(ComponentName, Component);
    return Component;
}

UProceduralMeshComponent* GenericGeometryUtilities::EnsureProceduralMeshComponent(
    AActor* OwnerActor,
    TMap<FName, TObjectPtr<UProceduralMeshComponent>>& InOutComponents,
    const FName ComponentName,
    UMaterialInterface* Material)
{
    if (!IsValid(OwnerActor))
    {
        return nullptr;
    }

    if (TObjectPtr<UProceduralMeshComponent>* ExistingComponent = InOutComponents.Find(ComponentName))
    {
        if (IsValid(*ExistingComponent))
        {
            UProceduralMeshComponent* Component = ExistingComponent->Get();
            if (IsValid(Material))
            {
                Component->SetMaterial(0, Material);
            }
            ConfigureVisualizationPrimitive(Component);
            return Component;
        }
    }

    UProceduralMeshComponent* Component = NewObject<UProceduralMeshComponent>(OwnerActor, ComponentName);
    if (!IsValid(Component))
    {
        return nullptr;
    }

    Component->SetupAttachment(OwnerActor->GetRootComponent());
    Component->SetMobility(EComponentMobility::Movable);
    Component->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Component->SetCanEverAffectNavigation(false);
    Component->bUseComplexAsSimpleCollision = false;
    Component->SetCastShadow(false);
    Component->bUseAttachParentBound = false;
    if (IsValid(Material))
    {
        Component->SetMaterial(0, Material);
    }
    ConfigureVisualizationPrimitive(Component);
    Component->RegisterComponent();

    InOutComponents.Add(ComponentName, Component);
    return Component;
}

UPrimitiveComponent* GenericGeometryUtilities::ResolvePrimitiveComponent(const AActor* OwnerActor, UPrimitiveComponent* ExplicitComponent)
{
    if (IsValid(ExplicitComponent))
    {
        return ExplicitComponent;
    }

    if (!IsValid(OwnerActor))
    {
        return nullptr;
    }

    return OwnerActor->FindComponentByClass<UPrimitiveComponent>();
}

bool GenericGeometryUtilities::TracePrimitiveSurface(UPrimitiveComponent* TargetComponent, const FVector& Start, const FVector& End, FHitResult& OutHit)
{
    if (!IsValid(TargetComponent))
    {
        return false;
    }

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(GenericGeometryTrace), true);
    QueryParams.bTraceComplex = true;
    return TargetComponent->LineTraceComponent(OutHit, Start, End, QueryParams);
}

bool GenericGeometryUtilities::TraceSurfaceAtXY(UPrimitiveComponent* TargetComponent, const FBox& Bounds, const FVector2D& XY, FHitResult& OutHit)
{
    const FVector Start(XY.X, XY.Y, Bounds.Max.Z);
    const FVector End(XY.X, XY.Y, Bounds.Min.Z);
    return TracePrimitiveSurface(TargetComponent, Start, End, OutHit);
}

bool GenericGeometryUtilities::TraceWorldSurfaceAtXY(UWorld* World, const AActor* IgnoredActor, const FVector& TraceCenter, const FVector& TraceExtent, const FVector2D& XY, FHitResult& OutHit)
{
    if (!IsValid(World))
    {
        return false;
    }

    const FVector Start(XY.X, XY.Y, TraceCenter.Z + TraceExtent.Z);
    const FVector End(XY.X, XY.Y, TraceCenter.Z - TraceExtent.Z);

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(GenericGeometryWorldTrace), true);
    QueryParams.bTraceComplex = true;
    if (IsValid(IgnoredActor))
    {
        QueryParams.AddIgnoredActor(IgnoredActor);
    }

    FCollisionObjectQueryParams ObjectQueryParams;
    ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
    ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

    return World->LineTraceSingleByObjectType(OutHit, Start, End, ObjectQueryParams, QueryParams);
}

FTransform GenericGeometryUtilities::BuildLineTransform(const FVector& Start, const FVector& End, const UStaticMesh* Mesh, float Width)
{
    const FVector Delta = End - Start;
    const float Distance = FMath::Max(Delta.Size(), 1.f);
    const FVector Direction = Delta / Distance;
    const FVector MidPoint = (Start + End) * 0.5f;
    const float MeshLength = GetMeshLengthX(Mesh);
    const float SafeWidth = FMath::Max(Width, 1.f);

    return FTransform(
        FRotationMatrix::MakeFromX(Direction).ToQuat(),
        MidPoint,
        FVector(Distance / MeshLength, SafeWidth / MeshLength, SafeWidth / MeshLength));
}

FQuat GenericGeometryUtilities::MakeSurfaceRotation(const FVector& Normal)
{
    FVector UpVector = Normal.GetSafeNormal();
    if (UpVector.IsNearlyZero())
    {
        UpVector = FVector::UpVector;
    }
    FVector Tangent = FVector::CrossProduct(FVector::ForwardVector, UpVector);
    if (Tangent.IsNearlyZero())
    {
        Tangent = FVector::RightVector;
    }
    return FRotationMatrix::MakeFromZX(UpVector, Tangent.GetSafeNormal()).ToQuat();
}

float GenericGeometryUtilities::GetSurfaceRangeYawDegrees(const USceneComponent* RangeOwner, const FGeometrySurfaceRange& Range)
{
    return Range.bUseComponentYaw && IsValid(RangeOwner)
        ? RangeOwner->GetComponentRotation().Yaw
        : 0.f;
}

FVector2D GenericGeometryUtilities::WorldToRangeLocalXY(const FVector& RangeCenter, float RangeYawDegrees, const FVector& WorldLocation)
{
    const FVector Delta = WorldLocation - RangeCenter;
    return FVector2D(Delta.X, Delta.Y).GetRotated(-RangeYawDegrees);
}

FVector2D GenericGeometryUtilities::WorldToRangeLocalXY(const USceneComponent* RangeOwner, const FGeometrySurfaceRange& Range, const FVector& WorldLocation)
{
    const FVector RangeCenter = IsValid(RangeOwner) ? RangeOwner->GetComponentLocation() : FVector::ZeroVector;
    return WorldToRangeLocalXY(RangeCenter, GetSurfaceRangeYawDegrees(RangeOwner, Range), WorldLocation);
}

FVector GenericGeometryUtilities::RangeLocalToWorld(const FVector& RangeCenter, float RangeYawDegrees, const FVector2D& LocalXY, float WorldZ)
{
    const FVector2D RotatedXY = LocalXY.GetRotated(RangeYawDegrees);
    return FVector(RangeCenter.X + RotatedXY.X, RangeCenter.Y + RotatedXY.Y, WorldZ);
}

FVector GenericGeometryUtilities::RangeLocalToWorld(const USceneComponent* RangeOwner, const FGeometrySurfaceRange& Range, const FVector2D& LocalXY, float WorldZ)
{
    const FVector RangeCenter = IsValid(RangeOwner) ? RangeOwner->GetComponentLocation() : FVector::ZeroVector;
    return RangeLocalToWorld(RangeCenter, GetSurfaceRangeYawDegrees(RangeOwner, Range), LocalXY, WorldZ);
}

bool GenericGeometryUtilities::IsLocalPointInsideSurfaceRange(const FVector2D& LocalXY, const FGeometrySurfaceRange& Range)
{
    const float SafeExtent = FMath::Max(Range.Extent, 0.f);
    if (Range.Shape == EGeometryRangeShape::Box)
    {
        return FMath::Abs(LocalXY.X) <= SafeExtent && FMath::Abs(LocalXY.Y) <= SafeExtent;
    }

    return LocalXY.SizeSquared() <= FMath::Square(SafeExtent);
}

bool GenericGeometryUtilities::IsWorldPointInsideSurfaceRange(const USceneComponent* RangeOwner, const FGeometrySurfaceRange& Range, const FVector& WorldLocation, FVector2D* OutLocalXY)
{
    const FVector2D LocalXY = WorldToRangeLocalXY(RangeOwner, Range, WorldLocation);
    if (OutLocalXY != nullptr)
    {
        *OutLocalXY = LocalXY;
    }

    return IsLocalPointInsideSurfaceRange(LocalXY, Range);
}

float GenericGeometryUtilities::NormalizeClamped(float Value, float MinValue, float MaxValue)
{
    if (FMath::IsNearlyEqual(MinValue, MaxValue))
    {
        return 0.f;
    }

    return FMath::Clamp((Value - MinValue) / (MaxValue - MinValue), 0.f, 1.f);
}

TArray<FVector> GenericGeometryUtilities::BuildParabolaPoints(const FVector& Start, const FVector& End, float HeightOffset, int32 SegmentCount)
{
    TArray<FVector> Points;
    const int32 NumSegments = FMath::Max(SegmentCount, 1);
    Points.Reserve(NumSegments + 1);

    for (int32 Index = 0; Index <= NumSegments; ++Index)
    {
        const float Alpha = static_cast<float>(Index) / static_cast<float>(NumSegments);
        FVector Point = FMath::Lerp(Start, End, Alpha);
        Point.Z += FMath::Sin(Alpha * PI) * HeightOffset;
        Points.Add(Point);
    }

    return Points;
}

TArray<FVector2D> GenericGeometryUtilities::BuildConvexHull(const TArray<FVector2D>& Points)
{
    TArray<FVector2D> SortedPoints = Points;
    SortedPoints.Sort([](const FVector2D& A, const FVector2D& B)
        {
            return A.X == B.X ? A.Y < B.Y : A.X < B.X;
        });

    if (SortedPoints.Num() <= 3)
    {
        return SortedPoints;
    }

    TArray<FVector2D> LowerHull;
    for (const FVector2D& Point : SortedPoints)
    {
        while (LowerHull.Num() >= 2 && Cross2D(LowerHull[LowerHull.Num() - 2], LowerHull.Last(), Point) <= 0.f)
        {
            LowerHull.Pop();
        }
        LowerHull.Add(Point);
    }

    TArray<FVector2D> UpperHull;
    for (int32 Index = SortedPoints.Num() - 1; Index >= 0; --Index)
    {
        const FVector2D& Point = SortedPoints[Index];
        while (UpperHull.Num() >= 2 && Cross2D(UpperHull[UpperHull.Num() - 2], UpperHull.Last(), Point) <= 0.f)
        {
            UpperHull.Pop();
        }
        UpperHull.Add(Point);
    }

    LowerHull.Pop();
    UpperHull.Pop();
    LowerHull.Append(UpperHull);
    return LowerHull;
}
