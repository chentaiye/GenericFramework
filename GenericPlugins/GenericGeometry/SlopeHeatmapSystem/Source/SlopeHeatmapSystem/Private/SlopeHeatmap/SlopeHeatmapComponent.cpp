#include "SlopeHeatmap/SlopeHeatmapComponent.h"

#include "SlopeHeatmap/SlopeHeatmapSubsystem.h"
#include "MaterialDomain.h"
#include "Materials/Material.h"
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

    UMaterialInterface* LoadDefaultSlopeHeatmapMaterial()
    {
        if (UMaterialInterface* Material = LoadObject<UMaterialInterface>(
                nullptr,
                TEXT("/SlopeHeatmapSystem/Material/M_SlopeHeatmap_Decal.M_SlopeHeatmap_Decal")))
        {
            return Material;
        }

        return UMaterial::GetDefaultMaterial(MD_DeferredDecal);
    }
}

USlopeHeatmapComponent::USlopeHeatmapComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    bTickInEditor = true;

    DecalSize = FVector(512.f, 2000.f, 2000.f);
    SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));
    SetHiddenInGame(false);
    SetVisibility(true);
    SetCanEverAffectNavigation(false);
    SetFadeScreenSize(0.0f);
    SetSortOrder(10);
}

void USlopeHeatmapComponent::OnRegister()
{
    Super::OnRegister();

#if WITH_EDITOR
    SetComponentTickEnabled(IsEditorPreviewWorld());
#endif

    RefreshRenderDecal();

    if (USlopeHeatmapSubsystem* SlopeHeatmapSubsystem = USlopeHeatmapSubsystem::Get(this))
    {
        SlopeHeatmapSubsystem->RegisterSlopeHeatmapComponent(this);
        SlopeHeatmapSubsystem->RequestSlopeHeatmapBuild(this);
    }

#if WITH_EDITOR
    CachedEditorPreviewHash = BuildEditorPreviewHash();
#endif
}

void USlopeHeatmapComponent::OnUnregister()
{
#if WITH_EDITOR
    SetComponentTickEnabled(false);
    CachedEditorPreviewHash = 0;
#endif

    if (USlopeHeatmapSubsystem* SlopeHeatmapSubsystem = USlopeHeatmapSubsystem::Get(this))
    {
        SlopeHeatmapSubsystem->UnregisterSlopeHeatmapComponent(this);
    }

    Super::OnUnregister();
}

void USlopeHeatmapComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
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
        RequestSlopeHeatmapBuild();
    }
#endif
}

void USlopeHeatmapComponent::RequestSlopeHeatmapBuild()
{
    if (USlopeHeatmapSubsystem* SlopeHeatmapSubsystem = USlopeHeatmapSubsystem::Get(this))
    {
        SlopeHeatmapSubsystem->RequestSlopeHeatmapBuild(this);
    }
}

FSlopeHeatmapQueryResult USlopeHeatmapComponent::QueryAtWorldLocation(const FVector& WorldLocation) const
{
    if (USlopeHeatmapSubsystem* SlopeHeatmapSubsystem = USlopeHeatmapSubsystem::Get(this))
    {
        return SlopeHeatmapSubsystem->QuerySlopeHeatmapAtWorldLocation(this, WorldLocation);
    }

    return {};
}

void USlopeHeatmapComponent::RefreshRenderDecal()
{
    UMaterialInterface* Material = GetDecalMaterial();
    if (!IsValid(Material))
    {
        Material = LoadDefaultSlopeHeatmapMaterial();
        SetDecalMaterial(Material);
    }

    DecalSize.X = FMath::Max(DecalSize.X, 1.f);
    DecalSize.Y = FMath::Max(DecalSize.Y, 1.f);
    DecalSize.Z = FMath::Max(DecalSize.Z, 1.f);
    SetFadeScreenSize(0.0f);
    SetSortOrder(10);
    MarkRenderStateDirty();
}

#if WITH_EDITOR
void USlopeHeatmapComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    SetComponentTickEnabled(IsEditorPreviewWorld());

    if (IsEditorPreviewWorld())
    {
        CachedEditorPreviewHash = BuildEditorPreviewHash();
        RequestSlopeHeatmapBuild();
    }
    else
    {
        CachedEditorPreviewHash = 0;
    }
}

uint32 USlopeHeatmapComponent::BuildEditorPreviewHash() const
{
    uint32 Hash = 0;
    Hash = HashCombine(Hash, PointerHash(GetDecalMaterial()));
    HashTransform(Hash, GetComponentTransform());
    HashVector(Hash, DecalSize);
    return Hash;
}

bool USlopeHeatmapComponent::IsEditorPreviewWorld() const
{
    if (IsTemplate())
    {
        return false;
    }

    const UWorld* World = GetWorld();
    return IsValid(World) && (World->WorldType == EWorldType::Editor || World->WorldType == EWorldType::EditorPreview);
}
#endif
