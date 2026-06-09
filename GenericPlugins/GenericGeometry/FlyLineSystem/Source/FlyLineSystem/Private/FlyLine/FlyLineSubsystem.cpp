#include "FlyLine/FlyLineSubsystem.h"

#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "FlyLine/FlyLineComponent.h"
#include "GameFramework/Actor.h"
#include "GenericGeometryUtilities.h"
#include "Materials/MaterialInterface.h"

namespace
{
    void RemoveEndpointMappings(TMap<FName, TObjectPtr<UFlyLineComponent>>& EndpointMap, const UFlyLineComponent* InComponent)
    {
        TArray<FName> KeysToRemove;
        for (const TPair<FName, TObjectPtr<UFlyLineComponent>>& Pair : EndpointMap)
        {
            if (Pair.Value == InComponent)
            {
                KeysToRemove.Add(Pair.Key);
            }
        }

        for (const FName& Key : KeysToRemove)
        {
            EndpointMap.Remove(Key);
        }
    }

    struct FFlyLineSegmentBuildData
    {
        TObjectPtr<UStaticMesh> Mesh = nullptr;
        TObjectPtr<UMaterialInterface> Material = nullptr;
        TArray<FTransform> Transforms;
        TArray<FVector4f> CustomData;
    };

    UStaticMesh* LoadDefaultFlyLineMesh()
    {
        return LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    }

    UMaterialInterface* LoadDefaultFlyLineMaterial()
    {
        return LoadObject<UMaterialInterface>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
    }
}

UFlyLineSubsystem* UFlyLineSubsystem::Get(const UObject* WorldContextObject)
{
    if (!IsValid(WorldContextObject) || !IsValid(GEngine))
    {
        return nullptr;
    }

    if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
    {
        return World->GetSubsystem<UFlyLineSubsystem>();
    }
    return nullptr;
}

bool UFlyLineSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
    return WorldType == EWorldType::Game
        || WorldType == EWorldType::PIE
        || WorldType == EWorldType::Editor
        || WorldType == EWorldType::EditorPreview;
}

void UFlyLineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    BuildStats.BuildState = EGeometryBuildState::Idle;
}

void UFlyLineSubsystem::Deinitialize()
{
    EndpointComponents.Reset();
    ExplicitConnections.Reset();
    BatchComponents.Reset();

    if (RenderActor.IsValid())
    {
        RenderActor->Destroy();
        RenderActor.Reset();
    }

    Super::Deinitialize();
}

void UFlyLineSubsystem::RegisterEndpointComponent(UFlyLineComponent* InComponent)
{
    if (!IsValid(InComponent))
    {
        return;
    }

    RemoveEndpointMappings(EndpointComponents, InComponent);
    EndpointComponents.FindOrAdd(InComponent->GetResolvedEndpointId()) = InComponent;
    RebuildFlyLines();
}

void UFlyLineSubsystem::UnregisterEndpointComponent(UFlyLineComponent* InComponent)
{
    if (!IsValid(InComponent))
    {
        return;
    }

    RemoveEndpointMappings(EndpointComponents, InComponent);
    RebuildFlyLines();
}

void UFlyLineSubsystem::NotifyEndpointUpdated(UFlyLineComponent* InComponent)
{
    if (IsValid(InComponent))
    {
        RemoveEndpointMappings(EndpointComponents, InComponent);
        EndpointComponents.FindOrAdd(InComponent->GetResolvedEndpointId()) = InComponent;
        RebuildFlyLines();
    }
}

void UFlyLineSubsystem::RegisterConnection(const FFlyLineConnection& InConnection)
{
    FFlyLineConnection Connection = InConnection;
    if (Connection.ConnectionId == NAME_None)
    {
        Connection.ConnectionId = MakeConnectionId(TEXT("FlyLine"), Connection.SourceEndpointId, Connection.TargetEndpointId, ExplicitConnections.Num());
    }

    ExplicitConnections.FindOrAdd(Connection.ConnectionId) = Connection;
    RebuildFlyLines();
}

void UFlyLineSubsystem::RegisterConnections(const TArray<FFlyLineConnection>& InConnections)
{
    for (const FFlyLineConnection& Connection : InConnections)
    {
        RegisterConnection(Connection);
    }
}

void UFlyLineSubsystem::RemoveConnection(FName InConnectionId)
{
    ExplicitConnections.Remove(InConnectionId);
    RebuildFlyLines();
}

void UFlyLineSubsystem::ClearConnections()
{
    ExplicitConnections.Reset();
    RebuildFlyLines();
}

TArray<FFlyLineConnection> UFlyLineSubsystem::GetConnections() const
{
    TArray<FFlyLineConnection> Result;
    ExplicitConnections.GenerateValueArray(Result);
    return Result;
}

TArray<FName> UFlyLineSubsystem::ConnectOneToMany(FName SourceEndpointId, const TArray<FName>& TargetEndpointIds, const FFlyLineStyle& InStyle, FName ConnectionPrefix)
{
    TArray<FName> RegisteredIds;
    int32 Index = 0;

    for (const FName& TargetEndpointId : TargetEndpointIds)
    {
        FFlyLineConnection Connection;
        Connection.ConnectionId = MakeConnectionId(ConnectionPrefix, SourceEndpointId, TargetEndpointId, Index++);
        Connection.SourceEndpointId = SourceEndpointId;
        Connection.TargetEndpointId = TargetEndpointId;
        Connection.ConnectionMode = EFlyLineConnectionMode::OneToMany;
        Connection.Style = InStyle;
        ExplicitConnections.FindOrAdd(Connection.ConnectionId) = Connection;
        RegisteredIds.Add(Connection.ConnectionId);
    }

    RebuildFlyLines();
    return RegisteredIds;
}

TArray<FName> UFlyLineSubsystem::ConnectManyToMany(const TArray<FName>& SourceEndpointIds, const TArray<FName>& TargetEndpointIds, const FFlyLineStyle& InStyle, FName ConnectionPrefix)
{
    TArray<FName> RegisteredIds;
    int32 Index = 0;

    for (const FName& SourceEndpointId : SourceEndpointIds)
    {
        for (const FName& TargetEndpointId : TargetEndpointIds)
        {
            if (SourceEndpointId == TargetEndpointId)
            {
                continue;
            }

            FFlyLineConnection Connection;
            Connection.ConnectionId = MakeConnectionId(ConnectionPrefix, SourceEndpointId, TargetEndpointId, Index++);
            Connection.SourceEndpointId = SourceEndpointId;
            Connection.TargetEndpointId = TargetEndpointId;
            Connection.ConnectionMode = EFlyLineConnectionMode::ManyToMany;
            Connection.Style = InStyle;
            ExplicitConnections.FindOrAdd(Connection.ConnectionId) = Connection;
            RegisteredIds.Add(Connection.ConnectionId);
        }
    }

    RebuildFlyLines();
    return RegisteredIds;
}

void UFlyLineSubsystem::RebuildFlyLines()
{
    BuildStats.BuildState = EGeometryBuildState::Building;
    const double StartTime = FPlatformTime::Seconds();

    AActor* BatchActor = GenericGeometryUtilities::EnsureRenderActor(GetWorld(), RenderActor, TEXT("FlyLineRenderActor"));
    if (!IsValid(BatchActor))
    {
        BuildStats.BuildState = EGeometryBuildState::Failed;
        BuildStats.LastMessage = TEXT("Failed to create FlyLine render actor.");
        return;
    }

    TMap<FName, FFlyLineSegmentBuildData> BatchBuildMap;
    const TArray<FFlyLineConnection> ActiveConnections = BuildActiveConnections();

    for (const FFlyLineConnection& Connection : ActiveConnections)
    {
        const TObjectPtr<UFlyLineComponent>* SourceComponent = EndpointComponents.Find(Connection.SourceEndpointId);
        const TObjectPtr<UFlyLineComponent>* TargetComponent = EndpointComponents.Find(Connection.TargetEndpointId);
        if (!SourceComponent || !TargetComponent || !IsValid(*SourceComponent) || !IsValid(*TargetComponent))
        {
            continue;
        }

        UFlyLineComponent* SourceFlyLineComponent = SourceComponent->Get();
        UFlyLineComponent* TargetFlyLineComponent = TargetComponent->Get();
        if (!IsValid(SourceFlyLineComponent) || !IsValid(TargetFlyLineComponent))
        {
            continue;
        }

        const FFlyLineStyle Style = ResolveStyle(Connection.Style);
        if (!IsValid(Style.LineMesh))
        {
            continue;
        }

        const FFlyLineBatchKey BatchKey{ Style.LineMesh, Style.LineMaterial };
        const FName BatchName = *FString::Printf(
            TEXT("FlyLineBatch_%s_%s"),
            *GetNameSafe(BatchKey.LineMesh),
            *GetNameSafe(BatchKey.LineMaterial));

        FFlyLineSegmentBuildData& BatchData = BatchBuildMap.FindOrAdd(BatchName);
        BatchData.Mesh = Style.LineMesh;
        BatchData.Material = Style.LineMaterial;

        const TArray<FVector> Points = GenericGeometryUtilities::BuildParabolaPoints(
            SourceFlyLineComponent->GetComponentLocation(),
            TargetFlyLineComponent->GetComponentLocation(),
            Style.HeightOffset,
            Style.SegmentCount);

        for (int32 SegmentIndex = 0; SegmentIndex + 1 < Points.Num(); ++SegmentIndex)
        {
            BatchData.Transforms.Add(GenericGeometryUtilities::BuildLineTransform(Points[SegmentIndex], Points[SegmentIndex + 1], Style.LineMesh, Style.Width));
            BatchData.CustomData.Add(FVector4f(
                GenericGeometryUtilities::NormalizeClamped(static_cast<float>(SegmentIndex), 0.f, static_cast<float>(FMath::Max(Points.Num() - 2, 1))),
                Style.Width,
                static_cast<float>(SegmentIndex),
                Style.HeightOffset));
        }
    }

    TSet<FName> ActiveBatchNames;
    for (const TPair<FName, FFlyLineSegmentBuildData>& Pair : BatchBuildMap)
    {
        ActiveBatchNames.Add(Pair.Key);

        UInstancedStaticMeshComponent* BatchComponent = GenericGeometryUtilities::EnsureInstancedMeshComponent(
            BatchActor,
            BatchComponents,
            Pair.Key,
            Pair.Value.Mesh,
            Pair.Value.Material,
            4);

        if (!IsValid(BatchComponent))
        {
            continue;
        }

        BatchComponent->ClearInstances();
        for (int32 Index = 0; Index < Pair.Value.Transforms.Num(); ++Index)
        {
            const int32 InstanceIndex = BatchComponent->AddInstance(Pair.Value.Transforms[Index], false);
            const FVector4f& CustomData = Pair.Value.CustomData[Index];
            BatchComponent->SetCustomDataValue(InstanceIndex, 0, CustomData.X, false);
            BatchComponent->SetCustomDataValue(InstanceIndex, 1, CustomData.Y, false);
            BatchComponent->SetCustomDataValue(InstanceIndex, 2, CustomData.Z, false);
            BatchComponent->SetCustomDataValue(InstanceIndex, 3, CustomData.W, Index == Pair.Value.Transforms.Num() - 1);
        }
    }

    TArray<FName> BatchNamesToRemove;
    for (const TPair<FName, TObjectPtr<UInstancedStaticMeshComponent>>& Pair : BatchComponents)
    {
        if (!ActiveBatchNames.Contains(Pair.Key) && IsValid(Pair.Value))
        {
            Pair.Value->DestroyComponent();
            BatchNamesToRemove.Add(Pair.Key);
        }
    }

    for (const FName& BatchName : BatchNamesToRemove)
    {
        BatchComponents.Remove(BatchName);
    }

    BuildStats.BuildCount++;
    BuildStats.BuildState = EGeometryBuildState::Ready;
    BuildStats.NumInputs = EndpointComponents.Num();
    BuildStats.NumOutputs = ActiveConnections.Num();
    BuildStats.LastBuildDurationMs = static_cast<float>((FPlatformTime::Seconds() - StartTime) * 1000.0);
    BuildStats.LastMessage = FString::Printf(TEXT("Rebuilt %d active FlyLine connections."), ActiveConnections.Num());

    UE_LOG(LogFlyLine, Verbose, TEXT("%s"), *BuildStats.LastMessage);
    OnFlyLinesRebuilt.Broadcast(BuildStats);
}

TArray<FFlyLineConnection> UFlyLineSubsystem::BuildActiveConnections() const
{
    TArray<FFlyLineConnection> Connections;
    ExplicitConnections.GenerateValueArray(Connections);

    TMap<FName, TArray<UFlyLineComponent*>> GroupEndpoints;
    for (const TPair<FName, TObjectPtr<UFlyLineComponent>>& Pair : EndpointComponents)
    {
        UFlyLineComponent* Component = Pair.Value.Get();
        if (!IsValid(Component))
        {
            continue;
        }

        for (const FName& GroupName : Component->GroupNames)
        {
            GroupEndpoints.FindOrAdd(GroupName).Add(Component);
        }
    }

    for (const TPair<FName, TArray<UFlyLineComponent*>>& Pair : GroupEndpoints)
    {
        const TArray<UFlyLineComponent*>& Components = Pair.Value;
        for (int32 SourceIndex = 0; SourceIndex < Components.Num(); ++SourceIndex)
        {
            for (int32 TargetIndex = SourceIndex + 1; TargetIndex < Components.Num(); ++TargetIndex)
            {
                if (!IsValid(Components[SourceIndex]) || !IsValid(Components[TargetIndex]))
                {
                    continue;
                }

                FFlyLineConnection Connection;
                Connection.ConnectionId = MakeConnectionId(*FString::Printf(TEXT("Auto_%s"), *Pair.Key.ToString()), Components[SourceIndex]->GetResolvedEndpointId(), Components[TargetIndex]->GetResolvedEndpointId(), TargetIndex);
                Connection.SourceEndpointId = Components[SourceIndex]->GetResolvedEndpointId();
                Connection.TargetEndpointId = Components[TargetIndex]->GetResolvedEndpointId();
                Connection.ConnectionMode = EFlyLineConnectionMode::ManyToMany;
                Connection.Style = ResolveAutoGroupStyle(Components[SourceIndex], Components[TargetIndex], Pair.Key);
                Connections.Add(Connection);
            }
        }
    }

    return Connections;
}

FFlyLineStyle UFlyLineSubsystem::ResolveStyle(const FFlyLineStyle& RequestedStyle) const
{
    FFlyLineStyle Style = RequestedStyle;

    if (!IsValid(Style.LineMesh))
    {
        Style.LineMesh = LoadDefaultFlyLineMesh();
    }
    if (!IsValid(Style.LineMaterial))
    {
        Style.LineMaterial = LoadDefaultFlyLineMaterial();
    }

    if (Style.Width <= 0.f)
    {
        Style.Width = 10.f;
    }
    if (Style.SegmentCount <= 0)
    {
        Style.SegmentCount = 6;
    }
    if (FMath::IsNearlyZero(Style.HeightOffset))
    {
        Style.HeightOffset = 120.f;
    }

    return Style;
}

FFlyLineStyle UFlyLineSubsystem::ResolveAutoGroupStyle(const UFlyLineComponent* SourceComponent, const UFlyLineComponent* TargetComponent, FName GroupName) const
{
    FFlyLineStyle Style;
    if (IsValid(SourceComponent) && SourceComponent->TryResolveGroupStyle(GroupName, Style))
    {
        return Style;
    }

    if (IsValid(TargetComponent) && TargetComponent->TryResolveGroupStyle(GroupName, Style))
    {
        return Style;
    }

    return Style;
}

FName UFlyLineSubsystem::MakeConnectionId(FName Prefix, FName SourceEndpointId, FName TargetEndpointId, int32 Index) const
{
    return *FString::Printf(TEXT("%s_%s_%s_%d"), *Prefix.ToString(), *SourceEndpointId.ToString(), *TargetEndpointId.ToString(), Index);
}
