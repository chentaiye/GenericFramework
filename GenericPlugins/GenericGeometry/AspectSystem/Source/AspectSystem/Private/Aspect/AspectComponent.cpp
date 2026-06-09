#include "Aspect/AspectComponent.h"

#include "Aspect/AspectSubsystem.h"
#include "UObject/UnrealType.h"

namespace
{
#if WITH_EDITOR
    void HashFloat(uint32& Hash, float Value)
    {
        Hash = HashCombine(Hash, GetTypeHash(Value));
    }

    void HashVector(uint32& Hash, const FVector& Value)
    {
        HashFloat(Hash, Value.X);
        HashFloat(Hash, Value.Y);
        HashFloat(Hash, Value.Z);
    }

    void HashTransform(uint32& Hash, const FTransform& Transform)
    {
        HashVector(Hash, Transform.GetLocation());
        HashFloat(Hash, Transform.GetRotation().X);
        HashFloat(Hash, Transform.GetRotation().Y);
        HashFloat(Hash, Transform.GetRotation().Z);
        HashFloat(Hash, Transform.GetRotation().W);
        HashVector(Hash, Transform.GetScale3D());
    }
#endif
}

UAspectComponent::UAspectComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    bTickInEditor = true;

    InitBoxExtent(FVector(1000.f, 1000.f, 1000.f));
    SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SetGenerateOverlapEvents(false);
    SetHiddenInGame(true);
    SetCanEverAffectNavigation(false);
    ShapeColor = FColor(0, 180, 255);
}

void UAspectComponent::OnRegister()
{
    Super::OnRegister();

#if WITH_EDITOR
    SetComponentTickEnabled(IsEditorPreviewWorld());
#endif

    if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(this))
    {
        Subsystem->RegisterAspectComponent(this);
        Subsystem->RequestAspectBuild(this);
    }

#if WITH_EDITOR
    CachedEditorPreviewHash = BuildEditorPreviewHash();
#endif
}

void UAspectComponent::OnUnregister()
{
#if WITH_EDITOR
    SetComponentTickEnabled(false);
    CachedEditorPreviewHash = 0;
#endif

    if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(this))
    {
        Subsystem->UnregisterAspectComponent(this);
    }

    Super::OnUnregister();
}

void UAspectComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

#if WITH_EDITOR
    if (!IsEditorPreviewWorld())
    {
        return;
    }

    const uint32 NewPreviewHash = BuildEditorPreviewHash();
    if (NewPreviewHash != CachedEditorPreviewHash)
    {
        CachedEditorPreviewHash = NewPreviewHash;
        RequestAspectBuild();
    }
#endif
}

void UAspectComponent::RequestAspectBuild()
{
    if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(this))
    {
        Subsystem->RequestAspectBuild(this);
    }
}

FAspectTileResult UAspectComponent::QueryAtWorldLocation(const FVector& WorldLocation) const
{
    if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(this))
    {
        return Subsystem->QueryAtWorldLocation(this, WorldLocation);
    }
    return {};
}

void UAspectComponent::RefreshRenderMesh()
{
    if (UAspectSubsystem* Subsystem = UAspectSubsystem::Get(this))
    {
        Subsystem->RequestAspectBuild(this);
    }
}

#if WITH_EDITOR
void UAspectComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    SetComponentTickEnabled(IsEditorPreviewWorld());

    if (IsEditorPreviewWorld())
    {
        CachedEditorPreviewHash = BuildEditorPreviewHash();
        RequestAspectBuild();
    }
    else
    {
        CachedEditorPreviewHash = 0;
    }
}

uint32 UAspectComponent::BuildEditorPreviewHash() const
{
    uint32 Hash = 0;
    Hash = HashCombine(Hash, PointerHash(ArrowMaterial.Get()));
    HashTransform(Hash, GetComponentTransform());
    HashVector(Hash, GetScaledBoxExtent());
    return Hash;
}

bool UAspectComponent::IsEditorPreviewWorld() const
{
    if (IsTemplate())
    {
        return false;
    }

    const UWorld* World = GetWorld();
    return IsValid(World) && (World->WorldType == EWorldType::Editor || World->WorldType == EWorldType::EditorPreview);
}
#endif
