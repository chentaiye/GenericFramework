#include "Aspect/AspectSubsystem.h"

#include "GameFramework/Actor.h"
#include "GenericGeometryUtilities.h"
#include "Materials/MaterialInterface.h"
#include "ProceduralMeshComponent.h"
#include "Aspect/AspectComponent.h"

namespace
{
    constexpr float AspectSampleSpacingMin = 80.f;
    constexpr int32 AspectTargetSamplesPerAxis = 24;
    // 箭头略高于地表，避免远距离深度精度不足时被地形吞掉。
    constexpr float AspectSurfaceOffset = 8.f;

    UMaterialInterface* LoadDefaultAspectMaterial()
    {
        if (UMaterialInterface* Material = LoadObject<UMaterialInterface>(
                nullptr,
                TEXT("/AspectSystem/Material/M_Aspect_Decal.M_Aspect_Decal")))
        {
            return Material;
        }

        return nullptr;
    }

    FVector CalculateDownhillDirection(const FVector& SurfaceNormal)
    {
        FVector Downhill = FVector::VectorPlaneProject(FVector::DownVector, SurfaceNormal.GetSafeNormal()).GetSafeNormal();
        if (Downhill.IsNearlyZero())
        {
            const FVector ReferenceAxis = FMath::Abs(SurfaceNormal.Z) > 0.95f ? FVector::ForwardVector : FVector::UpVector;
            Downhill = FVector::CrossProduct(ReferenceAxis, SurfaceNormal.GetSafeNormal()).GetSafeNormal();
        }
        return Downhill.IsNearlyZero() ? FVector::ForwardVector : Downhill;
    }

    float CalculateSlopeDegrees(const FVector& SurfaceNormal)
    {
        return FMath::RadiansToDegrees(
            FMath::Acos(FMath::Clamp(FVector::DotProduct(SurfaceNormal.GetSafeNormal(), FVector::UpVector), -1.f, 1.f)));
    }

    float CalculateAspectDegrees(const FVector& DownhillDirection)
    {
        const FVector HorizontalDirection(DownhillDirection.X, DownhillDirection.Y, 0.f);
        const FVector SafeDirection = HorizontalDirection.GetSafeNormal();
        if (SafeDirection.IsNearlyZero())
        {
            return 0.f;
        }

        const float Angle = FMath::RadiansToDegrees(FMath::Atan2(SafeDirection.Y, SafeDirection.X));
        return FMath::Fmod(Angle + 360.f, 360.f);
    }

    FColor BuildAspectColor(float AspectDegrees, float SlopeDegrees)
    {
        const uint8 Hue = static_cast<uint8>(FMath::RoundToInt((FMath::Fmod(AspectDegrees, 360.f) / 360.f) * 255.f));
        const uint8 Saturation = 210;
        const uint8 Value = static_cast<uint8>(FMath::RoundToInt(FMath::GetMappedRangeValueClamped(FVector2f(0.f, 60.f), FVector2f(160.f, 255.f), SlopeDegrees)));
        return FLinearColor::MakeFromHSV8(Hue, Saturation, Value).ToFColor(true);
    }

    void ConfigureAspectVisibility(UAspectComponent* InComponent, UProceduralMeshComponent* RenderMesh)
    {
        if (IsValid(InComponent))
        {
            InComponent->SetCullDistance(0.f);
            InComponent->MinDrawDistance = 0.f;
            InComponent->LDMaxDrawDistance = 0.f;
            InComponent->bNeverDistanceCull = true;
            InComponent->bAllowCullDistanceVolume = false;
            InComponent->SetBoundsScale(FMath::Max(InComponent->BoundsScale, 10000.f));
            InComponent->MarkRenderTransformDirty();
            InComponent->MarkRenderStateDirty();
        }

        if (IsValid(RenderMesh))
        {
            RenderMesh->SetVisibility(true, true);
            RenderMesh->SetHiddenInGame(false);
            RenderMesh->SetCullDistance(0.f);
            RenderMesh->MinDrawDistance = 0.f;
            RenderMesh->LDMaxDrawDistance = 0.f;
            RenderMesh->bNeverDistanceCull = true;
            RenderMesh->bAllowCullDistanceVolume = false;
            RenderMesh->bUseAsOccluder = false;
            RenderMesh->bVisibleInRayTracing = false;
            RenderMesh->bUseAttachParentBound = true;
            RenderMesh->SetBoundsScale(FMath::Max(RenderMesh->BoundsScale, 10000.f));
            RenderMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
            RenderMesh->SetCastShadow(false);
            RenderMesh->UpdateBounds();
            RenderMesh->MarkRenderTransformDirty();
            RenderMesh->MarkRenderDynamicDataDirty();
            RenderMesh->MarkRenderStateDirty();
        }
    }

    bool IsInsideAspectBox(const UAspectComponent* InComponent, const FVector& WorldLocation, FVector& OutLocalLocation)
    {
        if (!IsValid(InComponent))
        {
            return false;
        }

        OutLocalLocation = InComponent->GetComponentTransform().InverseTransformPosition(WorldLocation);
        const FVector Extent = InComponent->GetScaledBoxExtent();
        return FMath::Abs(OutLocalLocation.X) <= Extent.X
            && FMath::Abs(OutLocalLocation.Y) <= Extent.Y
            && FMath::Abs(OutLocalLocation.Z) <= Extent.Z;
    }

    bool TraceAspectSurface(const UAspectComponent* InComponent, const FVector& WorldLocation, FHitResult& OutHit)
    {
        if (!IsValid(InComponent) || !IsValid(InComponent->GetWorld()))
        {
            return false;
        }

        FVector LocalLocation = FVector::ZeroVector;
        if (!IsInsideAspectBox(InComponent, WorldLocation, LocalLocation))
        {
            return false;
        }

        const FVector Extent = InComponent->GetScaledBoxExtent();
        const FTransform ComponentTransform = InComponent->GetComponentTransform();
        const FVector LocalTraceStart(LocalLocation.X, LocalLocation.Y, Extent.Z);
        const FVector LocalTraceEnd(LocalLocation.X, LocalLocation.Y, -Extent.Z);
        const FVector TraceStart = ComponentTransform.TransformPosition(LocalTraceStart);
        const FVector TraceEnd = ComponentTransform.TransformPosition(LocalTraceEnd);

        FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(GenericAspectTrace), true);
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

    FAspectTileResult BuildTileResult(const UAspectComponent* InComponent, const FHitResult& HitResult)
    {
        FAspectTileResult TileResult;
        TileResult.Sample.bValid = true;
        TileResult.Sample.WorldLocation = HitResult.ImpactPoint;
        TileResult.Sample.SurfaceNormal = HitResult.ImpactNormal.GetSafeNormal();
        TileResult.Sample.SlopeDegrees = CalculateSlopeDegrees(TileResult.Sample.SurfaceNormal);
        TileResult.Sample.AspectDegrees = CalculateAspectDegrees(CalculateDownhillDirection(TileResult.Sample.SurfaceNormal));

        const FVector LocalLocation = InComponent->GetComponentTransform().InverseTransformPosition(HitResult.ImpactPoint);
        const FVector Extent = InComponent->GetScaledBoxExtent();
        const FVector2D NormalizedLocal(
            Extent.X > KINDA_SMALL_NUMBER ? (LocalLocation.X + Extent.X) / (Extent.X * 2.f) : 0.f,
            Extent.Y > KINDA_SMALL_NUMBER ? (LocalLocation.Y + Extent.Y) / (Extent.Y * 2.f) : 0.f);
        TileResult.CellCoord = FIntPoint(
            FMath::Clamp(FMath::FloorToInt(NormalizedLocal.X * 1024.f), 0, 1023),
            FMath::Clamp(FMath::FloorToInt(NormalizedLocal.Y * 1024.f), 0, 1023));
        return TileResult;
    }

    void AppendArrowGeometry(
        const FTransform& ComponentTransform,
        const FVector& WorldPosition,
        const FVector& SurfaceNormal,
        const FVector& DownhillDirection,
        const FColor& ArrowColor,
        float ArrowLength,
        float ArrowWidth,
        TArray<FVector>& Vertices,
        TArray<int32>& Triangles,
        TArray<FVector>& Normals,
        TArray<FVector2D>& UVs,
        TArray<FColor>& VertexColors,
        TArray<FProcMeshTangent>& Tangents)
    {
        const FVector SurfaceUp = SurfaceNormal.GetSafeNormal();
        const FVector Forward = DownhillDirection.GetSafeNormal();
        FVector Right = FVector::CrossProduct(SurfaceUp, Forward).GetSafeNormal();
        if (Right.IsNearlyZero())
        {
            Right = FVector::RightVector;
        }

        const FVector Center = WorldPosition + SurfaceUp * AspectSurfaceOffset;
        const float ShaftLength = ArrowLength * 0.55f;
        const float HeadLength = ArrowLength * 0.45f;
        const float ShaftHalfWidth = ArrowWidth * 0.22f;
        const float HeadHalfWidth = ArrowWidth * 0.5f;

        const FVector TailCenter = Center - Forward * (ArrowLength * 0.5f);
        const FVector HeadBaseCenter = TailCenter + Forward * ShaftLength;
        const FVector Tip = HeadBaseCenter + Forward * HeadLength;

        const FVector TailLeft = TailCenter - Right * ShaftHalfWidth;
        const FVector TailRight = TailCenter + Right * ShaftHalfWidth;
        const FVector ShaftLeft = HeadBaseCenter - Right * ShaftHalfWidth;
        const FVector ShaftRight = HeadBaseCenter + Right * ShaftHalfWidth;
        const FVector HeadLeft = HeadBaseCenter - Right * HeadHalfWidth;
        const FVector HeadRight = HeadBaseCenter + Right * HeadHalfWidth;

        const int32 BaseIndex = Vertices.Num();
        const auto AddVertex = [&](const FVector& WorldVertex, const FVector2D& UV)
        {
            Vertices.Add(ComponentTransform.InverseTransformPosition(WorldVertex));
            Normals.Add(ComponentTransform.InverseTransformVectorNoScale(SurfaceUp).GetSafeNormal());
            UVs.Add(UV);
            VertexColors.Add(ArrowColor);
            Tangents.Add(FProcMeshTangent(ComponentTransform.InverseTransformVectorNoScale(Forward).GetSafeNormal(), false));
        };

        AddVertex(TailLeft, FVector2D(0.f, 0.f));
        AddVertex(TailRight, FVector2D(0.f, 1.f));
        AddVertex(ShaftLeft, FVector2D(0.55f, 0.f));
        AddVertex(ShaftRight, FVector2D(0.55f, 1.f));
        AddVertex(HeadLeft, FVector2D(0.55f, 0.f));
        AddVertex(HeadRight, FVector2D(0.55f, 1.f));
        AddVertex(Tip, FVector2D(1.f, 0.5f));

        Triangles.Add(BaseIndex + 0);
        Triangles.Add(BaseIndex + 1);
        Triangles.Add(BaseIndex + 3);
        Triangles.Add(BaseIndex + 0);
        Triangles.Add(BaseIndex + 3);
        Triangles.Add(BaseIndex + 2);

        Triangles.Add(BaseIndex + 4);
        Triangles.Add(BaseIndex + 5);
        Triangles.Add(BaseIndex + 6);
    }

    FName BuildAspectMeshComponentName(const UAspectComponent* InComponent)
    {
        return FName(*FString::Printf(TEXT("AspectMesh_%u"), IsValid(InComponent) ? InComponent->GetUniqueID() : 0u));
    }
}

UAspectSubsystem* UAspectSubsystem::Get(const UObject* WorldContextObject)
{
    if (!IsValid(WorldContextObject) || !IsValid(GEngine))
    {
        return nullptr;
    }

    if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
    {
        return World->GetSubsystem<UAspectSubsystem>();
    }
    return nullptr;
}

bool UAspectSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
    return WorldType == EWorldType::Game
        || WorldType == EWorldType::PIE
        || WorldType == EWorldType::Editor
        || WorldType == EWorldType::EditorPreview;
}

void UAspectSubsystem::Deinitialize()
{
    for (TPair<TObjectPtr<UAspectComponent>, FAspectRuntimeState>& Pair : RuntimeStates)
    {
        for (TPair<FName, TObjectPtr<UProceduralMeshComponent>>& MeshPair : Pair.Value.RenderMeshes)
        {
            if (IsValid(MeshPair.Value))
            {
                MeshPair.Value->DestroyComponent();
            }
        }

        Pair.Value.RenderMeshes.Reset();
    }

    RuntimeStates.Reset();
    Super::Deinitialize();
}

void UAspectSubsystem::RegisterAspectComponent(UAspectComponent* InComponent)
{
    if (IsValid(InComponent))
    {
        RuntimeStates.FindOrAdd(InComponent);
    }
}

void UAspectSubsystem::UnregisterAspectComponent(UAspectComponent* InComponent)
{
    if (FAspectRuntimeState* RuntimeState = RuntimeStates.Find(InComponent))
    {
        for (TPair<FName, TObjectPtr<UProceduralMeshComponent>>& MeshPair : RuntimeState->RenderMeshes)
        {
            if (IsValid(MeshPair.Value))
            {
                MeshPair.Value->DestroyComponent();
            }
        }

        RuntimeState->RenderMeshes.Reset();
    }

    RuntimeStates.Remove(InComponent);
}

void UAspectSubsystem::RequestAspectBuild(UAspectComponent* InComponent)
{
    RebuildAspect(InComponent);
}

void UAspectSubsystem::RebuildAspect(UAspectComponent* InComponent)
{
    if (!IsValid(InComponent) || !IsValid(InComponent->GetWorld()))
    {
        return;
    }

    AActor* OwnerActor = InComponent->GetOwner();
    if (!IsValid(OwnerActor))
    {
        return;
    }

    FAspectRuntimeState& RuntimeState = RuntimeStates.FindOrAdd(InComponent);
    RuntimeState.BuildStats.BuildState = EGeometryBuildState::Building;
    const double StartTime = FPlatformTime::Seconds();

    UProceduralMeshComponent* RenderMesh = GenericGeometryUtilities::EnsureProceduralMeshComponent(
        OwnerActor,
        RuntimeState.RenderMeshes,
        BuildAspectMeshComponentName(InComponent),
        IsValid(InComponent->ArrowMaterial) ? InComponent->ArrowMaterial.Get() : LoadDefaultAspectMaterial());
    if (!IsValid(RenderMesh))
    {
        return;
    }

    if (RenderMesh->GetAttachParent() != InComponent)
    {
        RenderMesh->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
        RenderMesh->SetupAttachment(InComponent);
    }

    RenderMesh->SetRelativeTransform(FTransform::Identity);
    ConfigureAspectVisibility(InComponent, RenderMesh);

    RuntimeState.Statistics = {};

    const FVector Extent = InComponent->GetScaledBoxExtent();
    const float StepX = FMath::Max(AspectSampleSpacingMin, (Extent.X * 2.f) / static_cast<float>(AspectTargetSamplesPerAxis));
    const float StepY = FMath::Max(AspectSampleSpacingMin, (Extent.Y * 2.f) / static_cast<float>(AspectTargetSamplesPerAxis));
    const float ArrowLength = FMath::Clamp(FMath::Min(StepX, StepY) * 0.32f, 30.f, 90.f);
    const float ArrowWidth = FMath::Clamp(ArrowLength * 0.48f, 14.f, 42.f);

    TArray<FVector> Vertices;
    TArray<int32> Triangles;
    TArray<FVector> Normals;
    TArray<FVector2D> UVs;
    TArray<FColor> VertexColors;
    TArray<FProcMeshTangent> Tangents;

    float SumSlope = 0.f;
    float MinSlope = TNumericLimits<float>::Max();
    float MaxSlope = TNumericLimits<float>::Lowest();
    int32 EvaluatedSamples = 0;

    for (float LocalX = -Extent.X; LocalX <= Extent.X; LocalX += StepX)
    {
        for (float LocalY = -Extent.Y; LocalY <= Extent.Y; LocalY += StepY)
        {
            ++EvaluatedSamples;

            const FVector WorldPoint = InComponent->GetComponentTransform().TransformPosition(FVector(LocalX, LocalY, 0.f));
            FHitResult HitResult;
            if (!TraceAspectSurface(InComponent, WorldPoint, HitResult))
            {
                continue;
            }

            const FAspectTileResult TileResult = BuildTileResult(InComponent, HitResult);
            if (!TileResult.Sample.bValid)
            {
                continue;
            }

            ++RuntimeState.Statistics.SampleCount;
            SumSlope += TileResult.Sample.SlopeDegrees;
            MinSlope = FMath::Min(MinSlope, TileResult.Sample.SlopeDegrees);
            MaxSlope = FMath::Max(MaxSlope, TileResult.Sample.SlopeDegrees);
            const FColor ArrowColor = BuildAspectColor(TileResult.Sample.AspectDegrees, TileResult.Sample.SlopeDegrees);

            AppendArrowGeometry(
                InComponent->GetComponentTransform(),
                TileResult.Sample.WorldLocation,
                TileResult.Sample.SurfaceNormal,
                CalculateDownhillDirection(TileResult.Sample.SurfaceNormal),
                ArrowColor,
                ArrowLength,
                ArrowWidth,
                Vertices,
                Triangles,
                Normals,
                UVs,
                VertexColors,
                Tangents);
        }
    }

    RenderMesh->ClearAllMeshSections();
    if (Vertices.Num() > 0 && Triangles.Num() > 0)
    {
        RenderMesh->CreateMeshSection(
            0,
            Vertices,
            Triangles,
            Normals,
            UVs,
            VertexColors,
            Tangents,
            false);
        RenderMesh->SetRelativeTransform(FTransform::Identity);
        ConfigureAspectVisibility(InComponent, RenderMesh);
    }
    else
    {
        RenderMesh->SetVisibility(false);
    }

    RuntimeState.Statistics.AverageSlopeDegrees = RuntimeState.Statistics.SampleCount > 0
        ? SumSlope / static_cast<float>(RuntimeState.Statistics.SampleCount)
        : 0.f;
    RuntimeState.Statistics.MinSlopeDegrees = RuntimeState.Statistics.SampleCount > 0 ? MinSlope : 0.f;
    RuntimeState.Statistics.MaxSlopeDegrees = RuntimeState.Statistics.SampleCount > 0 ? MaxSlope : 0.f;

    RuntimeState.BuildStats.BuildCount++;
    RuntimeState.BuildStats.BuildState = EGeometryBuildState::Ready;
    RuntimeState.BuildStats.NumInputs = EvaluatedSamples;
    RuntimeState.BuildStats.NumOutputs = RuntimeState.Statistics.SampleCount;
    RuntimeState.BuildStats.LastBuildDurationMs = static_cast<float>((FPlatformTime::Seconds() - StartTime) * 1000.0);
    RuntimeState.BuildStats.LastMessage = FString::Printf(TEXT("Aspect mesh rebuilt with %d arrows."), RuntimeState.Statistics.SampleCount);

    UE_LOG(LogAspect, Verbose, TEXT("%s"), *RuntimeState.BuildStats.LastMessage);
    InComponent->OnAspectBuildFinished.Broadcast(RuntimeState.BuildStats);
}

FAspectTileResult UAspectSubsystem::QueryAtWorldLocation(const UAspectComponent* InComponent, const FVector& WorldLocation) const
{
    FHitResult HitResult;
    if (!TraceAspectSurface(InComponent, WorldLocation, HitResult))
    {
        return {};
    }

    return BuildTileResult(InComponent, HitResult);
}

FAspectStatistics UAspectSubsystem::GetStatistics(const UAspectComponent* InComponent) const
{
    if (const FAspectRuntimeState* RuntimeState = RuntimeStates.Find(InComponent))
    {
        return RuntimeState->Statistics;
    }
    return {};
}
