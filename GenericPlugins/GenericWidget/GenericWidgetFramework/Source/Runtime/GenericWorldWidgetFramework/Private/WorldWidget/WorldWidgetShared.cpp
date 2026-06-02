// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/WorldWidgetShared.h"

#include "Base/GenericActionWidget.h"
#include "Base/WorldWidgetComponent.h"
#include "Blueprint/WidgetTree.h"
#include "Input/GenericInputTrigger.h"
#include "Subsystem/GenericActionSubsystem.h"

namespace
{
	bool IsValidInputComponent(const UWorldWidgetComponent* InComponent)
	{
		return IsValid(InComponent)
			&& InComponent->IsRegistered()
			&& InComponent->IsVisible()
			&& IsValid(InComponent->InputActionDataAsset);
	}

	bool IsPressedInputEvent(const FGenericActionViewportInputEvent& InInputEvent)
	{
		return InInputEvent.bIsPressed;
	}

	void GetTriggerEvents(EGenericInputTriggerState PreviousState, EGenericInputTriggerState NewState, bool bHasTriggered, TArray<EGenericActionTriggerEvent, TInlineAllocator<2>>& OutEvents)
	{
		OutEvents.Reset();

		if (PreviousState == EGenericInputTriggerState::None)
		{
			if (NewState == EGenericInputTriggerState::Ongoing)
			{
				OutEvents.Add(EGenericActionTriggerEvent::Started);
				OutEvents.Add(EGenericActionTriggerEvent::Ongoing);
			}
			else if (NewState == EGenericInputTriggerState::Triggered)
			{
				OutEvents.Add(EGenericActionTriggerEvent::Started);
				OutEvents.Add(EGenericActionTriggerEvent::Triggered);
			}

			return;
		}

		if (PreviousState == EGenericInputTriggerState::Ongoing)
		{
			if (NewState == EGenericInputTriggerState::Ongoing)
			{
				if (!bHasTriggered)
				{
					OutEvents.Add(EGenericActionTriggerEvent::Ongoing);
				}
			}
			else if (NewState == EGenericInputTriggerState::Triggered)
			{
				OutEvents.Add(EGenericActionTriggerEvent::Triggered);
			}
			else if (NewState == EGenericInputTriggerState::None)
			{
				OutEvents.Add(bHasTriggered ? EGenericActionTriggerEvent::Completed : EGenericActionTriggerEvent::Canceled);
			}

			return;
		}

		if (PreviousState == EGenericInputTriggerState::Triggered)
		{
			if (NewState == EGenericInputTriggerState::Triggered)
			{
				OutEvents.Add(EGenericActionTriggerEvent::Triggered);
			}
			else if (NewState == EGenericInputTriggerState::Ongoing)
			{
				if (!bHasTriggered)
				{
					OutEvents.Add(EGenericActionTriggerEvent::Ongoing);
				}
			}
			else if (NewState == EGenericInputTriggerState::None)
			{
				OutEvents.Add(EGenericActionTriggerEvent::Completed);
			}
		}
	}

	float GetEventTriggeredTime(EGenericActionTriggerEvent TriggerEvent, const FWorldWidgetRuntimeTriggerState& RuntimeState, const FGenericInputTriggerContext& TriggerContext, EGenericInputTriggerState NewState)
	{
		if (TriggerEvent == EGenericActionTriggerEvent::Completed)
		{
			return RuntimeState.TriggeredTime;
		}

		if (TriggerEvent != EGenericActionTriggerEvent::Triggered)
		{
			return 0.0f;
		}

		return RuntimeState.LastTriggerState == EGenericInputTriggerState::Triggered && NewState == EGenericInputTriggerState::Triggered
			? RuntimeState.TriggeredTime + TriggerContext.DeltaTime
			: TriggerContext.DeltaTime;
	}
}

bool FWorldWidgetRegistry::AddComponent(TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, UWorldWidgetComponent* InComponent)
{
	if (!IsValid(InComponent))
	{
		return false;
	}

	if (InComponents.Contains(InComponent))
	{
		return true;
	}

	InComponents.Add(InComponent);
	return true;
}

bool FWorldWidgetRegistry::RemoveComponent(TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, UWorldWidgetComponent* InComponent)
{
	return InComponents.RemoveSingle(InComponent) > 0;
}

TArray<UWorldWidgetComponent*> FWorldWidgetRegistry::GetAllComponents(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents)
{
	TArray<UWorldWidgetComponent*> Result;
	for (UWorldWidgetComponent* Component : InComponents)
	{
		if (IsValid(Component))
		{
			Result.Add(Component);
		}
	}

	return Result;
}

TArray<UWorldWidgetComponent*> FWorldWidgetRegistry::GetComponentsBySpace(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, EWidgetSpace InWidgetSpace)
{
	TArray<UWorldWidgetComponent*> Result;
	for (UWorldWidgetComponent* Component : InComponents)
	{
		if (IsValid(Component) && Component->GetWidgetSpace() == InWidgetSpace)
		{
			Result.Add(Component);
		}
	}

	return Result;
}

TArray<UWorldWidgetComponent*> FWorldWidgetRegistry::GetInputComponentsByPriority(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents)
{
	struct FWorldWidgetPriorityEntry
	{
		UWorldWidgetComponent* Component = nullptr;
		int32 Index = INDEX_NONE;
	};

	TArray<FWorldWidgetPriorityEntry> Entries;
	for (int32 Index = 0; Index < InComponents.Num(); ++Index)
	{
		UWorldWidgetComponent* Component = InComponents[Index];
		if (IsValidInputComponent(Component))
		{
			Entries.Add({ Component, Index });
		}
	}

	Entries.Sort([](const FWorldWidgetPriorityEntry& Left, const FWorldWidgetPriorityEntry& Right)
	{
		if (Left.Component->GetInputPriority() == Right.Component->GetInputPriority())
		{
			return Left.Index > Right.Index;
		}

		return Left.Component->GetInputPriority() > Right.Component->GetInputPriority();
	});

	TArray<UWorldWidgetComponent*> Result;
	for (const FWorldWidgetPriorityEntry& Entry : Entries)
	{
		Result.Add(Entry.Component);
	}

	return Result;
}

bool FWorldWidgetInputDispatcher::DispatchViewportInput(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, const FGenericActionViewportInputEvent& InInputEvent, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates, UObject* InDuplicateOuter, bool bCanConsumeInput)
{
	if (!InInputEvent.Key.IsValid() || !InDuplicateOuter)
	{
		return false;
	}

	PruneRuntimeTriggerStates(InComponents, InOutRuntimeStates);

	for (UWorldWidgetComponent* Component : FWorldWidgetRegistry::GetInputComponentsByPriority(InComponents))
	{
		if (!IsValid(Component) || !IsValid(Component->InputActionDataAsset))
		{
			continue;
		}

		for (const FGenericInputActionKeyTriggerMapping& ActionMapping : Component->InputActionDataAsset->ActionMappings)
		{
			if (!ActionMapping.ActionTag.IsValid())
			{
				continue;
			}

			for (const FGenericInputKeyTrigger& KeyTrigger : ActionMapping.KeyTriggers)
			{
				if (KeyTrigger.Key != InInputEvent.Key || !IsValid(KeyTrigger.Trigger))
				{
					continue;
				}

				bool bShouldConsume = false;
				EvaluateComponentActionInput(Component, ActionMapping, KeyTrigger, InInputEvent, InOutRuntimeStates, InDuplicateOuter, bCanConsumeInput, bShouldConsume);
				if (bShouldConsume)
				{
					return true;
				}
			}
		}
	}

	return false;
}

void FWorldWidgetInputDispatcher::TickViewportInput(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates, UObject* InDuplicateOuter, float InDeltaTime)
{
	if (!InDuplicateOuter)
	{
		return;
	}

	PruneRuntimeTriggerStates(InComponents, InOutRuntimeStates);

	for (FWorldWidgetRuntimeTriggerState& RuntimeState : InOutRuntimeStates)
	{
		if (!RuntimeState.bIsPressed && RuntimeState.LastTriggerState == EGenericInputTriggerState::None)
		{
			continue;
		}

		if (!IsValid(RuntimeState.Component) || !IsValid(RuntimeState.RuntimeTrigger))
		{
			continue;
		}

		FGenericActionViewportInputEvent InputEvent;
		InputEvent.Key = RuntimeState.Key;
		InputEvent.InputValue = RuntimeState.LastInputValue;
		InputEvent.bIsPressed = RuntimeState.bIsPressed;
		InputEvent.DeltaTime = InDeltaTime;

		const FGenericInputTriggerContext TriggerContext = BuildTriggerContext(RuntimeState, InputEvent);
		const EGenericInputTriggerState NewTriggerState = RuntimeState.RuntimeTrigger->UpdateState(TriggerContext);
		DispatchTriggerEventsToComponent(RuntimeState.Component, RuntimeState.ActionTag, InputEvent, TriggerContext, RuntimeState, NewTriggerState);
		UpdateRuntimeTriggerState(RuntimeState, TriggerContext, NewTriggerState);
	}

	PruneRuntimeTriggerStates(InComponents, InOutRuntimeStates);
}

void FWorldWidgetInputDispatcher::PruneRuntimeTriggerStates(const TArray<TObjectPtr<UWorldWidgetComponent>>& InComponents, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates)
{
	for (int32 Index = InOutRuntimeStates.Num() - 1; Index >= 0; --Index)
	{
		const FWorldWidgetRuntimeTriggerState& RuntimeState = InOutRuntimeStates[Index];
		const bool bFinished = !RuntimeState.bIsPressed && RuntimeState.LastTriggerState == EGenericInputTriggerState::None;
		const bool bRegistered = InComponents.Contains(RuntimeState.Component);

		if (bFinished || !bRegistered || !IsValidInputComponent(RuntimeState.Component) || !IsValid(RuntimeState.TemplateTrigger) || !IsValid(RuntimeState.RuntimeTrigger))
		{
			InOutRuntimeStates.RemoveAtSwap(Index);
		}
	}
}

bool FWorldWidgetInputDispatcher::EvaluateComponentActionInput(UWorldWidgetComponent* InComponent, const FGenericInputActionKeyTriggerMapping& InActionMapping, const FGenericInputKeyTrigger& InKeyTrigger, const FGenericActionViewportInputEvent& InInputEvent, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates, UObject* InDuplicateOuter, bool bCanConsumeInput, bool& bOutShouldConsume)
{
	bOutShouldConsume = false;

	FWorldWidgetRuntimeTriggerState& RuntimeState = FindOrCreateRuntimeTriggerState(InComponent, InActionMapping.ActionTag, InKeyTrigger, InOutRuntimeStates, InDuplicateOuter);
	if (!IsValid(RuntimeState.RuntimeTrigger))
	{
		return false;
	}

	RuntimeState.LastInputValue = InInputEvent.InputValue;

	const FGenericInputTriggerContext TriggerContext = BuildTriggerContext(RuntimeState, InInputEvent);
	const EGenericInputTriggerState NewTriggerState = RuntimeState.RuntimeTrigger->UpdateState(TriggerContext);
	bool bHandled = DispatchTriggerEventsToComponent(InComponent, InActionMapping.ActionTag, InInputEvent, TriggerContext, RuntimeState, NewTriggerState);
	UpdateRuntimeTriggerState(RuntimeState, TriggerContext, NewTriggerState);

	if (!IsPressedInputEvent(InInputEvent) && NewTriggerState == EGenericInputTriggerState::Triggered)
	{
		bHandled |= DispatchTriggerEventsToComponent(InComponent, InActionMapping.ActionTag, InInputEvent, TriggerContext, RuntimeState, EGenericInputTriggerState::None);
		UpdateRuntimeTriggerState(RuntimeState, TriggerContext, EGenericInputTriggerState::None);
	}

	if (bHandled && bCanConsumeInput && InActionMapping.bConsumeInput)
	{
		bOutShouldConsume = true;
	}

	return bHandled;
}

FWorldWidgetRuntimeTriggerState& FWorldWidgetInputDispatcher::FindOrCreateRuntimeTriggerState(UWorldWidgetComponent* InComponent, FGameplayTag InActionTag, const FGenericInputKeyTrigger& InKeyTrigger, TArray<FWorldWidgetRuntimeTriggerState>& InOutRuntimeStates, UObject* InDuplicateOuter)
{
	for (FWorldWidgetRuntimeTriggerState& RuntimeState : InOutRuntimeStates)
	{
		if (RuntimeState.Component == InComponent && RuntimeState.ActionTag.MatchesTagExact(InActionTag) && RuntimeState.Key == InKeyTrigger.Key && RuntimeState.TemplateTrigger == InKeyTrigger.Trigger)
		{
			if (!IsValid(RuntimeState.RuntimeTrigger) && IsValid(InKeyTrigger.Trigger))
			{
				RuntimeState.RuntimeTrigger = DuplicateObject<UGenericInputTrigger>(InKeyTrigger.Trigger, InDuplicateOuter);
			}

			return RuntimeState;
		}
	}

	FWorldWidgetRuntimeTriggerState& RuntimeState = InOutRuntimeStates.AddDefaulted_GetRef();
	RuntimeState.Component = InComponent;
	RuntimeState.ActionTag = InActionTag;
	RuntimeState.Key = InKeyTrigger.Key;
	RuntimeState.TemplateTrigger = InKeyTrigger.Trigger;
	RuntimeState.RuntimeTrigger = IsValid(InKeyTrigger.Trigger) ? DuplicateObject<UGenericInputTrigger>(InKeyTrigger.Trigger, InDuplicateOuter) : nullptr;
	return RuntimeState;
}

FGenericInputTriggerContext FWorldWidgetInputDispatcher::BuildTriggerContext(FWorldWidgetRuntimeTriggerState& InRuntimeState, const FGenericActionViewportInputEvent& InInputEvent) const
{
	const double CurrentTime = FPlatformTime::Seconds();
	const float DeltaTime = InInputEvent.DeltaTime > 0.0f ? InInputEvent.DeltaTime : InRuntimeState.LastUpdateTime > 0.0 ? static_cast<float>(CurrentTime - InRuntimeState.LastUpdateTime) : 0.0f;
	const bool bWasPressed = InRuntimeState.bIsPressed;

	FGenericInputTriggerContext TriggerContext;
	TriggerContext.Key = InInputEvent.Key;
	TriggerContext.InputValue = InInputEvent.InputValue;
	TriggerContext.DeltaTime = FMath::Max(0.0f, DeltaTime);
	TriggerContext.bIsPressed = InInputEvent.bIsPressed;
	TriggerContext.bWasPressed = bWasPressed;
	TriggerContext.CurrentTime = CurrentTime;
	TriggerContext.HeldDuration = InInputEvent.bIsPressed ? (bWasPressed ? InRuntimeState.HeldDuration + TriggerContext.DeltaTime : TriggerContext.DeltaTime) : InRuntimeState.HeldDuration;
	TriggerContext.ReleasedDuration = InInputEvent.bIsPressed ? 0.0f : (bWasPressed ? 0.0f : InRuntimeState.ReleasedDuration + TriggerContext.DeltaTime);
	return TriggerContext;
}

void FWorldWidgetInputDispatcher::UpdateRuntimeTriggerState(FWorldWidgetRuntimeTriggerState& InRuntimeState, const FGenericInputTriggerContext& InTriggerContext, EGenericInputTriggerState InNewTriggerState)
{
	InRuntimeState.LastInputValue = InTriggerContext.InputValue;
	InRuntimeState.bIsPressed = InTriggerContext.bIsPressed;
	InRuntimeState.HeldDuration = InTriggerContext.bIsPressed ? InTriggerContext.HeldDuration : 0.0f;
	InRuntimeState.ReleasedDuration = InTriggerContext.bIsPressed ? 0.0f : InRuntimeState.ReleasedDuration;
	InRuntimeState.LastUpdateTime = InTriggerContext.CurrentTime;

	if (InNewTriggerState == EGenericInputTriggerState::Triggered)
	{
		InRuntimeState.bHasTriggered = true;
		InRuntimeState.TriggeredTime = InRuntimeState.LastTriggerState == EGenericInputTriggerState::Triggered ? InRuntimeState.TriggeredTime + InTriggerContext.DeltaTime : InTriggerContext.DeltaTime;
	}
	else if (InNewTriggerState == EGenericInputTriggerState::None)
	{
		InRuntimeState.TriggeredTime = 0.0f;
		InRuntimeState.bHasTriggered = false;
		InRuntimeState.bHasStarted = false;
	}

	InRuntimeState.LastTriggerState = InNewTriggerState;
}

bool FWorldWidgetInputDispatcher::DispatchTriggerEventsToComponent(UWorldWidgetComponent* InComponent, FGameplayTag InActionTag, const FGenericActionViewportInputEvent& InInputEvent, const FGenericInputTriggerContext& InTriggerContext, FWorldWidgetRuntimeTriggerState& InRuntimeState, EGenericInputTriggerState InNewTriggerState)
{
	TArray<EGenericActionTriggerEvent, TInlineAllocator<2>> TriggerEvents;
	GetTriggerEvents(InRuntimeState.LastTriggerState, InNewTriggerState, InRuntimeState.bHasTriggered, TriggerEvents);

	bool bHandled = false;
	for (EGenericActionTriggerEvent TriggerEvent : TriggerEvents)
	{
		if (TriggerEvent == EGenericActionTriggerEvent::Started)
		{
			if (InRuntimeState.bHasStarted)
			{
				continue;
			}

			InRuntimeState.bHasStarted = true;
		}

		FGenericActionInputEventData EventData;
		EventData.ActionTag = InActionTag;
		EventData.TriggerEvent = TriggerEvent;
		EventData.Key = InInputEvent.Key;
		EventData.ActionValue = InInputEvent.InputValue.GetMagnitude();
		EventData.ElapsedTime = InTriggerContext.HeldDuration;
		EventData.TriggeredTime = GetEventTriggeredTime(TriggerEvent, InRuntimeState, InTriggerContext, InNewTriggerState);

		bHandled |= DispatchActionEventToComponent(InComponent, InActionTag, EventData);
	}

	return bHandled;
}

bool FWorldWidgetInputDispatcher::DispatchActionEventToComponent(UWorldWidgetComponent* InComponent, FGameplayTag InActionTag, const FGenericActionInputEventData& InEventData)
{
	UGenericWidget* RootWidget = IsValid(InComponent) ? InComponent->GetWorldWidget() : nullptr;
	if (!IsValid(RootWidget) || !RootWidget->IsVisible())
	{
		return false;
	}

	if (UGenericActionWidget* ActionRoot = Cast<UGenericActionWidget>(RootWidget))
	{
		if (ActionRoot->ActionTag.MatchesTagExact(InActionTag) && ActionRoot->ExecuteActionTagEvent(InActionTag, InEventData.TriggerEvent, InEventData))
		{
			return true;
		}
	}

	UWidgetTree* WidgetTree = RootWidget->WidgetTree;
	if (!WidgetTree)
	{
		return false;
	}

	bool bHandled = false;
	WidgetTree->ForEachWidgetAndDescendants([&](UWidget* Widget)
	{
		if (bHandled)
		{
			return;
		}

		UGenericActionWidget* ActionWidget = Cast<UGenericActionWidget>(Widget);
		if (IsValid(ActionWidget) && ActionWidget != RootWidget && ActionWidget->IsVisible() && ActionWidget->ActionTag.MatchesTagExact(InActionTag))
		{
			bHandled = ActionWidget->ExecuteActionTagEvent(InActionTag, InEventData.TriggerEvent, InEventData);
		}
	});

	return bHandled;
}
