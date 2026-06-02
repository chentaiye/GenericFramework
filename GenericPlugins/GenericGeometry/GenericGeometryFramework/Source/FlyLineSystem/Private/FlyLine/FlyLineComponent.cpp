#include "FlyLine/FlyLineComponent.h"

#include "Engine/DataTable.h"
#include "FlyLine/FlyLineSubsystem.h"
#include "UObject/UnrealType.h"

namespace
{
#if WITH_EDITOR
    bool IsFlyLineEditorPreviewEnabled(const UFlyLineComponent* InComponent)
    {
        if (!IsValid(InComponent) || InComponent->IsTemplate())
        {
            return false;
        }

        const UWorld* World = InComponent->GetWorld();
        return IsValid(World) && (World->WorldType == EWorldType::Editor || World->WorldType == EWorldType::EditorPreview);
    }
#endif
}

UFlyLineComponent::UFlyLineComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UFlyLineComponent::OnRegister()
{
    Super::OnRegister();

    if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(this))
    {
        FlyLineSubsystem->RegisterEndpointComponent(this);
    }
}

void UFlyLineComponent::OnUnregister()
{
    if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(this))
    {
        FlyLineSubsystem->UnregisterEndpointComponent(this);
    }

    Super::OnUnregister();
}

void UFlyLineComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
    Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

    if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(this))
    {
        FlyLineSubsystem->NotifyEndpointUpdated(this);
    }
}

#if WITH_EDITOR
void UFlyLineComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    if (IsFlyLineEditorPreviewEnabled(this))
    {
        if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(this))
        {
            FlyLineSubsystem->NotifyEndpointUpdated(this);
        }
    }
}

void UFlyLineComponent::PostEditComponentMove(bool bFinished)
{
    Super::PostEditComponentMove(bFinished);

    if (IsFlyLineEditorPreviewEnabled(this))
    {
        if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(this))
        {
            FlyLineSubsystem->NotifyEndpointUpdated(this);
        }
    }
}
#endif

FName UFlyLineComponent::GetResolvedEndpointId() const
{
    FString ResolvedName = EndpointName;
    ResolvedName.TrimStartAndEndInline();
    if (!ResolvedName.IsEmpty())
    {
        return FName(*ResolvedName);
    }

    return *GetPathNameSafe(this);
}

FFlyLineEndpoint UFlyLineComponent::BuildEndpoint() const
{
    FFlyLineEndpoint Endpoint;
    Endpoint.EndpointId = GetResolvedEndpointId();
    Endpoint.WorldTransform = GetComponentTransform();
    Endpoint.EndpointTag = EndpointTag;
    Endpoint.GroupNames = GroupNames;
    return Endpoint;
}

void UFlyLineComponent::RefreshFlyLines()
{
    if (UFlyLineSubsystem* FlyLineSubsystem = UFlyLineSubsystem::Get(this))
    {
        FlyLineSubsystem->NotifyEndpointUpdated(this);
    }
}

bool UFlyLineComponent::TryResolveGroupStyle(FName GroupName, FFlyLineStyle& OutStyle) const
{
    if (!IsValid(GroupStyleTable) || GroupName == NAME_None)
    {
        return false;
    }

    const TArray<FName> RowNames = GroupStyleTable->GetRowNames();
    for (const FName& RowName : RowNames)
    {
        const FFlyLineGroupStyleRow* Row = GroupStyleTable->FindRow<FFlyLineGroupStyleRow>(RowName, TEXT("FlyLineGroupStyleLookup"));
        if (Row == nullptr)
        {
            continue;
        }

        const FName ResolvedGroupName = Row->GroupName != NAME_None ? Row->GroupName : RowName;
        if (ResolvedGroupName != GroupName)
        {
            continue;
        }

        OutStyle.StyleId = RowName;
        OutStyle.LineMesh = Row->LineMesh;
        OutStyle.Width = Row->Width;
        OutStyle.HeightOffset = Row->HeightOffset;
        OutStyle.SegmentCount = Row->SegmentCount;
        return true;
    }

    return false;
}
