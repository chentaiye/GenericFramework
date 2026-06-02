

#include "Subsystem/GenericTickableWorldSubsystem.h"
#include "Misc/EngineVersionComparison.h"

void UGenericTickableWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Refresh the tick type after initialization
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	SetTickableTickType(GetTickableTickType());
#endif
}

void UGenericTickableWorldSubsystem::Deinitialize()
{
	Super::Deinitialize();

	// Always cancel tick as this is about to be destroyed
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	SetTickableTickType(ETickableTickType::Never);
#endif
}

UWorld* UGenericTickableWorldSubsystem::GetTickableGameObjectWorld() const
{
	return GetWorld();
}

ETickableTickType UGenericTickableWorldSubsystem::GetTickableTickType() const
{
	// If this is a template or has not been initialized yet, set to never tick and it will be enabled when it is initialized
	if (IsTemplate() || !IsInitialized())
	{
		return ETickableTickType::Never;
	}

	// Otherwise default to conditional
	return ETickableTickType::Conditional;
}

void UGenericTickableWorldSubsystem::Tick(float DeltaTime)
{
}

bool UGenericTickableWorldSubsystem::IsTickable() const
{
	return IsInitialized();
}

bool UGenericTickableWorldSubsystem::IsTickableInEditor() const
{
	return FTickableGameObject::IsTickableInEditor();
}

bool UGenericTickableWorldSubsystem::IsTickableWhenPaused() const
{
	return FTickableGameObject::IsTickableWhenPaused();
}

TStatId UGenericTickableWorldSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UGenericTickableWorldSubsystem, STATGROUP_Tickables);
}
