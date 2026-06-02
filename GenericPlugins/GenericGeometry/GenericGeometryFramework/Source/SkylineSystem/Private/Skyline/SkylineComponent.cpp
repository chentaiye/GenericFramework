#include "Skyline/SkylineComponent.h"

#include "Components/PostProcessComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Skyline/SkylineSubsystem.h"

namespace
{
    constexpr TCHAR SkylinePostProcessMaterialPath[] = TEXT("/GenericGeometryFramework/Materials/Skyline/M_Skyline_PostProcess.M_Skyline_PostProcess");
    constexpr float SkylinePostProcessPriority = 10000.0f;
    const FName SkylineLineColorParameterName(TEXT("LineColor"));
    const FName SkylineLineThicknessParameterName(TEXT("LineThicknessPx"));
}

USkylineComponent::USkylineComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    PrimaryComponentTick.TickGroup = TG_PostUpdateWork;
    bAutoActivate = true;
    bTickInEditor = true;
}

void USkylineComponent::OnRegister()
{
    Super::OnRegister();
    SetAutoActivate(true);
    Activate(true);
    SetComponentTickEnabled(true);
    EnsureSkylinePostProcess();

    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(this))
    {
        Subsystem->RegisterSkylineComponent(this);
        Subsystem->RequestSkylineBuild(this);
        UpdateSkylinePostProcessState(Subsystem->FindActiveSkylineComponent() == this);
    }
}

void USkylineComponent::OnUnregister()
{
    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(this))
    {
        Subsystem->UnregisterSkylineComponent(this);
    }

    DestroySkylinePostProcess();
    Super::OnUnregister();
}

void USkylineComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    const UWorld* World = GetWorld();
    if (!IsValid(World))
    {
        return;
    }

    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(this))
    {
        if (World->WorldType == EWorldType::Game || World->WorldType == EWorldType::PIE)
        {
            Subsystem->TickRuntimeSkyline(this);
        }
        else if (World->WorldType == EWorldType::Editor || World->WorldType == EWorldType::EditorPreview)
        {
            Subsystem->TickEditorSkyline(this);
        }
    }
}

void USkylineComponent::RequestSkylineBuild()
{
    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(this))
    {
        Subsystem->RequestSkylineBuild(this);
    }
}

FSkylineContour USkylineComponent::GetLastContour() const
{
    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(this))
    {
        return Subsystem->GetLastContour(this);
    }

    return {};
}

FSkylineMetrics USkylineComponent::GetLastMetrics() const
{
    if (USkylineSubsystem* Subsystem = USkylineSubsystem::Get(this))
    {
        return Subsystem->GetLastMetrics(this);
    }

    return {};
}

#if WITH_EDITOR
void USkylineComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    ApplySkylinePostProcessParameters();
    RequestSkylineBuild();
}
#endif

void USkylineComponent::UpdateSkylinePostProcessState(bool bShouldRender)
{
    if (!bShouldRender || RenderConfig.LineThicknessPx <= 0.0f)
    {
        if (IsValid(SkylinePostProcessComponent))
        {
            SkylinePostProcessComponent->BlendWeight = 0.0f;
            SkylinePostProcessComponent->bEnabled = false;
            SkylinePostProcessComponent->Deactivate();
            SkylinePostProcessComponent->Settings.WeightedBlendables.Array.Reset();
            SkylinePostProcessComponent->MarkRenderStateDirty();
        }
        return;
    }

    EnsureSkylinePostProcess();
    UMaterialInstanceDynamic* SkylineMID = GetOrCreateSkylinePostProcessMID();
    if (!IsValid(SkylinePostProcessComponent) || !IsValid(SkylineMID))
    {
        return;
    }

    ApplySkylinePostProcessParameters();

    SkylinePostProcessComponent->bUnbound = true;
    SkylinePostProcessComponent->Priority = SkylinePostProcessPriority;
    SkylinePostProcessComponent->BlendRadius = 0.0f;
    SkylinePostProcessComponent->BlendWeight = 1.0f;
    SkylinePostProcessComponent->bEnabled = true;
    SkylinePostProcessComponent->Activate(true);
    SkylinePostProcessComponent->Settings.WeightedBlendables.Array.Reset();
    SkylinePostProcessComponent->Settings.WeightedBlendables.Array.Emplace(1.0f, SkylineMID);
    SkylinePostProcessComponent->MarkRenderStateDirty();
}

void USkylineComponent::DestroySkylinePostProcess()
{
    if (IsValid(SkylinePostProcessComponent))
    {
        SkylinePostProcessComponent->DestroyComponent();
    }

    SkylinePostProcessComponent = nullptr;
    SkylinePostProcessMID = nullptr;
}

void USkylineComponent::EnsureSkylinePostProcess()
{
    AActor* OwnerActor = GetOwner();
    if (!IsValid(OwnerActor))
    {
        return;
    }

    if (!IsValid(SkylinePostProcessComponent))
    {
        SkylinePostProcessComponent = NewObject<UPostProcessComponent>(OwnerActor, TEXT("SkylinePostProcessComponent"), RF_Transient);
        SkylinePostProcessComponent->CreationMethod = EComponentCreationMethod::Instance;
        OwnerActor->AddOwnedComponent(SkylinePostProcessComponent);
        SkylinePostProcessComponent->SetAutoActivate(true);
        SkylinePostProcessComponent->bUnbound = true;
        SkylinePostProcessComponent->Priority = SkylinePostProcessPriority;
        SkylinePostProcessComponent->BlendRadius = 0.0f;
        SkylinePostProcessComponent->BlendWeight = 0.0f;
        SkylinePostProcessComponent->bEnabled = false;

        if (USceneComponent* RootComponent = OwnerActor->GetRootComponent())
        {
            SkylinePostProcessComponent->SetupAttachment(RootComponent);
        }
    }

    if (!SkylinePostProcessComponent->IsRegistered() && IsValid(OwnerActor->GetWorld()))
    {
        SkylinePostProcessComponent->RegisterComponent();
    }
}

UMaterialInstanceDynamic* USkylineComponent::GetOrCreateSkylinePostProcessMID()
{
    if (!IsValid(SkylinePostProcessMID))
    {
        if (!IsValid(SkylinePostProcessMaterial))
        {
            SkylinePostProcessMaterial = LoadObject<UMaterialInterface>(nullptr, SkylinePostProcessMaterialPath);
        }

        if (!IsValid(SkylinePostProcessMaterial))
        {
            return nullptr;
        }

        SkylinePostProcessMID = UMaterialInstanceDynamic::Create(SkylinePostProcessMaterial, this, TEXT("SkylinePostProcessMID"));
    }

    return SkylinePostProcessMID;
}

void USkylineComponent::ApplySkylinePostProcessParameters()
{
    UMaterialInstanceDynamic* SkylineMID = GetOrCreateSkylinePostProcessMID();
    if (!IsValid(SkylineMID))
    {
        return;
    }

    SkylineMID->SetVectorParameterValue(SkylineLineColorParameterName, RenderConfig.LineColor);
    SkylineMID->SetScalarParameterValue(SkylineLineThicknessParameterName, FMath::Max(RenderConfig.LineThicknessPx, 0.0f));
}
