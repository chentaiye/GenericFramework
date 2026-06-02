#include "Skyline/SkylineSubsystem.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Skyline/SkylineComponent.h"
#include "Subsystems/SubsystemCollection.h"

namespace
{
    bool IsSkylineComponentRenderable(const USkylineComponent* InComponent)
    {
        if (!IsValid(InComponent) || !InComponent->IsRegistered() || !InComponent->IsActive())
        {
            return false;
        }

        const AActor* OwnerActor = InComponent->GetOwner();
        if (!IsValid(OwnerActor) || OwnerActor->IsActorBeingDestroyed() || OwnerActor->IsHidden())
        {
            return false;
        }

#if WITH_EDITOR
        if (OwnerActor->IsHiddenEd() || OwnerActor->IsTemporarilyHiddenInEditor(true))
        {
            return false;
        }
#endif

        return true;
    }
}

USkylineSubsystem* USkylineSubsystem::Get(const UObject* WorldContextObject)
{
    if (!IsValid(WorldContextObject) || !IsValid(GEngine))
    {
        return nullptr;
    }

    if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
    {
        return World->GetSubsystem<USkylineSubsystem>();
    }

    return nullptr;
}

void USkylineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
}

void USkylineSubsystem::Deinitialize()
{
    DisableInactiveComponents(nullptr);
    RuntimeStates.Reset();
    Super::Deinitialize();
}

bool USkylineSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
    return WorldType == EWorldType::Game
        || WorldType == EWorldType::PIE
        || WorldType == EWorldType::Editor
        || WorldType == EWorldType::EditorPreview;
}

void USkylineSubsystem::RegisterSkylineComponent(USkylineComponent* InComponent)
{
    if (!IsValid(InComponent))
    {
        return;
    }

    FSkylineRuntimeState& RuntimeState = RuntimeStates.FindOrAdd(InComponent);
    RuntimeState.RegistrationOrder = NextRegistrationOrder++;
    RuntimeState.bDirty = true;
    TickSkylinePostProcess(InComponent);
}

void USkylineSubsystem::UnregisterSkylineComponent(USkylineComponent* InComponent)
{
    RuntimeStates.Remove(InComponent);
    DisableInactiveComponents(FindActiveSkylineComponent());
}

void USkylineSubsystem::RequestSkylineBuild(USkylineComponent* InComponent)
{
    if (!IsValid(InComponent))
    {
        return;
    }

    FSkylineRuntimeState& RuntimeState = RuntimeStates.FindOrAdd(InComponent);
    RuntimeState.bDirty = true;
    RuntimeState.BuildStats.BuildState = EGeometryBuildState::Queued;
    RuntimeState.BuildStats.LastMessage = TEXT("Skyline post process refresh queued.");
}

void USkylineSubsystem::RebuildSkyline(USkylineComponent* InComponent)
{
    RequestSkylineBuild(InComponent);
    TickSkylinePostProcess(InComponent);
}

void USkylineSubsystem::TickRuntimeSkyline(USkylineComponent* InComponent)
{
    TickSkylinePostProcess(InComponent);
}

void USkylineSubsystem::TickEditorSkyline(USkylineComponent* InComponent)
{
    TickSkylinePostProcess(InComponent);
}

FSkylineContour USkylineSubsystem::GetLastContour(const USkylineComponent* InComponent) const
{
    if (const FSkylineRuntimeState* RuntimeState = RuntimeStates.Find(InComponent))
    {
        return RuntimeState->LastContour;
    }

    return {};
}

FSkylineMetrics USkylineSubsystem::GetLastMetrics(const USkylineComponent* InComponent) const
{
    if (const FSkylineRuntimeState* RuntimeState = RuntimeStates.Find(InComponent))
    {
        return RuntimeState->LastMetrics;
    }

    return {};
}

USkylineComponent* USkylineSubsystem::FindActiveSkylineComponent() const
{
    USkylineComponent* BestComponent = nullptr;
    int32 BestRegistrationOrder = TNumericLimits<int32>::Lowest();

    for (const TPair<TObjectPtr<USkylineComponent>, FSkylineRuntimeState>& Pair : RuntimeStates)
    {
        USkylineComponent* SkylineComponent = Pair.Key.Get();
        if (!IsSkylineComponentRenderable(SkylineComponent))
        {
            continue;
        }

        if (Pair.Value.RegistrationOrder >= BestRegistrationOrder)
        {
            BestComponent = SkylineComponent;
            BestRegistrationOrder = Pair.Value.RegistrationOrder;
        }
    }

    return BestComponent;
}

void USkylineSubsystem::TickSkylinePostProcess(USkylineComponent* InComponent)
{
    if (!IsValid(InComponent))
    {
        DisableInactiveComponents(nullptr);
        return;
    }

    USkylineComponent* ActiveComponent = FindActiveSkylineComponent();
    DisableInactiveComponents(ActiveComponent);

    FSkylineRuntimeState& RuntimeState = RuntimeStates.FindOrAdd(InComponent);
    const bool bShouldRender = InComponent == ActiveComponent;
    InComponent->UpdateSkylinePostProcessState(bShouldRender);

    if (!bShouldRender)
    {
        RuntimeState.LastContour = {};
        RuntimeState.LastMetrics = {};
        RuntimeState.BuildStats.BuildState = EGeometryBuildState::Ready;
        RuntimeState.BuildStats.NumInputs = 0;
        RuntimeState.BuildStats.NumOutputs = 0;
        RuntimeState.BuildStats.LastBuildDurationMs = 0.0f;
        RuntimeState.BuildStats.LastMessage = TEXT("Skyline post process disabled because another component is active or this component is hidden.");
        RuntimeState.bDirty = false;
        return;
    }

    const bool bShouldBroadcast = RuntimeState.bDirty;
    RuntimeState.LastContour = {};
    RuntimeState.LastMetrics = {};
    RuntimeState.BuildStats.BuildCount++;
    RuntimeState.BuildStats.BuildState = EGeometryBuildState::Ready;
    RuntimeState.BuildStats.NumInputs = 0;
    RuntimeState.BuildStats.NumOutputs = 0;
    RuntimeState.BuildStats.LastBuildDurationMs = 0.0f;
    RuntimeState.BuildStats.LastMessage = TEXT("Skyline rendered by post process material.");
    RuntimeState.bDirty = false;

    if (bShouldBroadcast)
    {
        InComponent->OnSkylineBuildFinished.Broadcast(RuntimeState.BuildStats);
    }
}

void USkylineSubsystem::DisableInactiveComponents(USkylineComponent* ActiveComponent)
{
    for (const TPair<TObjectPtr<USkylineComponent>, FSkylineRuntimeState>& Pair : RuntimeStates)
    {
        USkylineComponent* SkylineComponent = Pair.Key.Get();
        if (IsValid(SkylineComponent) && SkylineComponent != ActiveComponent)
        {
            SkylineComponent->UpdateSkylinePostProcessState(false);
        }
    }
}
