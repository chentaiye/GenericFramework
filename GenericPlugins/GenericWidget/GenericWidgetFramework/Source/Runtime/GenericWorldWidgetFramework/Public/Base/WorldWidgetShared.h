// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Input/GenericActionInputTypes.h"
#include "Input/GenericInputActionDataAsset.h"
#include "InputActionValue.h"
#include "WorldWidgetShared.generated.h"

class UWorldWidgetComponent;

/** Runtime trigger state for one WorldWidget component/action/key mapping. */
USTRUCT()
struct GENERICWORLDWIDGETFRAMEWORK_API FWorldWidgetRuntimeTriggerState
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UWorldWidgetComponent> Component = nullptr;

	UPROPERTY()
	FGameplayTag ActionTag;

	UPROPERTY()
	FKey Key;

	UPROPERTY()
	TObjectPtr<UGenericInputTrigger> TemplateTrigger = nullptr;

	UPROPERTY()
	TObjectPtr<UGenericInputTrigger> RuntimeTrigger = nullptr;

	UPROPERTY()
	FInputActionValue LastInputValue;

	UPROPERTY()
	EGenericInputTriggerState LastTriggerState = EGenericInputTriggerState::None;

	UPROPERTY()
	bool bIsPressed = false;

	UPROPERTY()
	float HeldDuration = 0.0f;

	UPROPERTY()
	float ReleasedDuration = 0.0f;

	UPROPERTY()
	float TriggeredTime = 0.0f;

	UPROPERTY()
	bool bHasTriggered = false;

	UPROPERTY()
	bool bHasStarted = false;

	UPROPERTY()
	double LastUpdateTime = 0.0;
};

/** Shared registry helpers used by runtime and editor WorldWidget subsystems. */
class GENERICWORLDWIDGETFRAMEWORK_API FWorldWidgetRegistry
{
public:
	static bool AddComponent(TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, UWorldWidgetComponent* InComponent);
	static bool RemoveComponent(TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, UWorldWidgetComponent* InComponent);
	static TArray<UWorldWidgetComponent*> GetAllComponents(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents);
	static TArray<UWorldWidgetComponent*> GetComponentsBySpace(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, EWidgetSpace InWidgetSpace);
	static TArray<UWorldWidgetComponent*> GetInputComponentsByPriority(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents);
};

/** Shared post-route input dispatcher for WorldWidget action handling. */
class GENERICWORLDWIDGETFRAMEWORK_API FWorldWidgetInputDispatcher
{
public:
	bool DispatchViewportInput(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, const struct FGenericActionViewportInputEvent& InInputEvent, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates, UObject* InDuplicateOuter, bool bCanConsumeInput);
	void TickViewportInput(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates, UObject* InDuplicateOuter, float InDeltaTime);
	void PruneRuntimeTriggerStates(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates);

private:
	bool EvaluateComponentActionInput(UWorldWidgetComponent* InComponent, const FGenericInputActionKeyTriggerMapping& InActionMapping, const FGenericInputKeyTrigger& InKeyTrigger, const struct FGenericActionViewportInputEvent& InInputEvent, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates, UObject* InDuplicateOuter, bool bCanConsumeInput, bool& bOutShouldConsume);
	FWorldWidgetRuntimeTriggerState& FindOrCreateRuntimeTriggerState(UWorldWidgetComponent* InComponent, FGameplayTag InActionTag, const FGenericInputKeyTrigger& InKeyTrigger, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates, UObject* InDuplicateOuter);
	FGenericInputTriggerContext BuildTriggerContext(FWorldWidgetRuntimeTriggerState& InRuntimeState, const struct FGenericActionViewportInputEvent& InInputEvent) const;
	void UpdateRuntimeTriggerState(FWorldWidgetRuntimeTriggerState& InRuntimeState, const FGenericInputTriggerContext& InTriggerContext, EGenericInputTriggerState InNewTriggerState);
	bool DispatchTriggerEventsToComponent(UWorldWidgetComponent* InComponent, FGameplayTag InActionTag, const struct FGenericActionViewportInputEvent& InInputEvent, const FGenericInputTriggerContext& InTriggerContext, FWorldWidgetRuntimeTriggerState& InRuntimeState, EGenericInputTriggerState InNewTriggerState);
	bool DispatchActionEventToComponent(UWorldWidgetComponent* InComponent, FGameplayTag InActionTag, const FGenericActionInputEventData& InEventData);
};
