// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Ticker.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "Base/WorldWidgetShared.h"
#include "WorldWidgetSubsystem.generated.h"

class APlayerController;
class UWorldWidgetComponent;

/** Local-player manager for runtime WorldWidget components and post-route input. */
UCLASS(MinimalAPI)
class UWorldWidgetSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICWORLDWIDGETFRAMEWORK_API static UWorldWidgetSubsystem* Get(const APlayerController* PlayerController);
	GENERICWORLDWIDGETFRAMEWORK_API static UWorldWidgetSubsystem* Get(const ULocalPlayer* LocalPlayer);

public:
	/** Register a WorldWidget component with this local player. */
	GENERICWORLDWIDGETFRAMEWORK_API bool RegisterWorldWidget(UWorldWidgetComponent* InComponent);

	/** Unregister a WorldWidget component from this local player. */
	GENERICWORLDWIDGETFRAMEWORK_API bool UnregisterWorldWidget(UWorldWidgetComponent* InComponent);

	/** Return all live WorldWidget components registered with this local player. */
	GENERICWORLDWIDGETFRAMEWORK_API TArray<UWorldWidgetComponent*> GetAllWorldWidgets() const;

	/** Return all live WorldWidget components using the requested widget space. */
	GENERICWORLDWIDGETFRAMEWORK_API TArray<UWorldWidgetComponent*> GetWorldWidgetsBySpace(EWidgetSpace InWidgetSpace) const;

public:
	GENERICWORLDWIDGETFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICWORLDWIDGETFRAMEWORK_API virtual void Deinitialize() override;

private:
	void BindActionSubsystem();
	void UnbindActionSubsystem();
	void RegisterExistingWorldWidgets();
	void BindWorldWidgetComponents();
	void UnbindWorldWidgetComponents();
	void HandleComponentRegistered(UWorldWidgetComponent* InComponent);
	void HandleComponentUnregistered(UWorldWidgetComponent* InComponent);
	void HandleComponentChanged(UWorldWidgetComponent* InComponent);
	void HandlePostRouteViewportInput(const struct FGenericActionViewportInputEvent& InInputEvent, bool& bOutConsumed);
	bool TickWorldWidgetInput(float InDeltaTime);
	bool IsComponentOwnedByWorld(UWorldWidgetComponent* InComponent) const;

private:
	UPROPERTY()
	TArray<TObjectPtr<UWorldWidgetComponent>> RegisteredComponents;

	UPROPERTY()
	TArray<FWorldWidgetRuntimeTriggerState> RuntimeTriggerStates;

	FWorldWidgetInputDispatcher InputDispatcher;
	FTSTicker::FDelegateHandle WorldWidgetInputTickerHandle;
	FDelegateHandle PostRouteInputHandle;
};
