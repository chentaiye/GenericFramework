// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericActionSubsystem.h"

#include "Base/GenericActionWidget.h"
#include "Base/GenericLayer.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "Input/GenericInputActionDataAsset.h"
#include "Subsystem/GenericLayerSubsystem.h"
#include "Subsystem/GenericRouteSubsystem.h"
#include "WidgetType.h"

namespace
{
	bool IsPressedInputEvent(EInputEvent InInputEvent)
	{
		return InInputEvent == IE_Pressed || InInputEvent == IE_DoubleClick;
	}

	bool IsReleasedInputEvent(EInputEvent InInputEvent)
	{
		return InInputEvent == IE_Released;
	}

	FGenericActionViewportInputEvent MakeInputEvent(const FInputKeyEventArgs& EventArgs)
	{
		const bool bIsPressed = IsPressedInputEvent(EventArgs.Event);

		FGenericActionViewportInputEvent InputEvent;
		InputEvent.Key = EventArgs.Key;
		InputEvent.InputValue = FInputActionValue(bIsPressed);
		InputEvent.bIsPressed = bIsPressed;
		InputEvent.DeltaTime = EventArgs.DeltaTime;
		return InputEvent;
	}

	bool IsTouchPressed(ETouchType::Type Type)
	{
		return Type != ETouchType::Ended;
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

	float GetEventTriggeredTime(EGenericActionTriggerEvent TriggerEvent, const FGenericActionRuntimeTriggerState& RuntimeState, const FGenericInputTriggerContext& TriggerContext, EGenericInputTriggerState NewState)
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

	void BroadcastActionWidgetRegisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, UGenericActionWidget* ActionWidget)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnActionWidgetRegisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.ActionWidget = ActionWidget;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnActionWidgetRegister, Message);
	}

	void BroadcastActionWidgetUnregisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, UGenericActionWidget* ActionWidget)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnActionWidgetUnregisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.ActionWidget = ActionWidget;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnActionWidgetUnRegister, Message);
	}
}

UGenericActionSubsystem* UGenericActionSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<UGenericActionSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UGenericActionSubsystem* UGenericActionSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UGenericActionSubsystem>(LocalPlayer);
}

bool UGenericActionSubsystem::RegisterActionWidget(UGenericActionWidget* InWidget)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterActionWidget failed because widget is null."));
		return false;
	}

	if (!IsWidgetOwnedByThisSubsystem(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterActionWidget failed because widget '%s' does not belong to this local player."), *InWidget->GetName());
		return false;
	}

	if (ActionWidgetStack.Contains(InWidget))
	{
		return true;
	}

	ActionWidgetStack.Add(InWidget);
	BroadcastActionWidgetRegisteredMessage(this, GetPlayerController(), InWidget);
	return true;
}

bool UGenericActionSubsystem::UnregisterActionWidget(UGenericActionWidget* InWidget)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterActionWidget failed because widget is null."));
		return false;
	}

	if (!ActionWidgetStack.RemoveSingle(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterActionWidget failed because widget '%s' is not registered."), *InWidget->GetName());
		return false;
	}

	BroadcastActionWidgetUnregisteredMessage(this, GetPlayerController(), InWidget);
	return true;
}

TArray<UGenericActionWidget*> UGenericActionSubsystem::GetAllActionWidgets() const
{
	TArray<UGenericActionWidget*> Result;

	for (UGenericActionWidget* Widget : ActionWidgetStack)
	{
		if (IsValid(Widget))
		{
			Result.Add(Widget);
		}
	}

	return Result;
}

FDelegate_PostRouteViewportInput& UGenericActionSubsystem::GetPostRouteViewportInputDelegate()
{
	return Delegate_PostRouteViewportInput;
}

bool UGenericActionSubsystem::HandleViewportInputKey(const FInputKeyEventArgs& EventArgs)
{
	if (!EventArgs.Key.IsValid() || (!IsPressedInputEvent(EventArgs.Event) && !IsReleasedInputEvent(EventArgs.Event)))
	{
		return false;
	}

	return DispatchViewportInput(MakeInputEvent(EventArgs), true);
}

bool UGenericActionSubsystem::HandleViewportInputTouch(FViewport* Viewport, FInputDeviceId DeviceId, uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, uint32 TouchpadIndex, uint64 Timestamp)
{
	(void)Viewport;
	(void)DeviceId;
	(void)TouchLocation;
	(void)TouchpadIndex;
	(void)Timestamp;

	if (Handle >= static_cast<uint32>(ETouchIndex::CursorPointerIndex))
	{
		return false;
	}

	const bool bIsPressed = IsTouchPressed(Type);

	FGenericActionViewportInputEvent InputEvent;
	InputEvent.Key = EKeys::TouchKeys[Handle];
	InputEvent.InputValue = FInputActionValue(bIsPressed ? FMath::Max(Force, 1.0f) : 0.0f);
	InputEvent.bIsPressed = bIsPressed;
	InputEvent.DeltaTime = 0.0f;
	return DispatchViewportInput(InputEvent, true);
}

void UGenericActionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (!ActionInputTickerHandle.IsValid())
	{
		ActionInputTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UGenericActionSubsystem::TickActionInput));
	}
}

void UGenericActionSubsystem::Deinitialize()
{
	if (ActionInputTickerHandle.IsValid())
	{
		FTSTicker::RemoveTicker(ActionInputTickerHandle);
		ActionInputTickerHandle.Reset();
	}

	RuntimeTriggerStates.Reset();
	ActionWidgetStack.Reset();
	Super::Deinitialize();
}

bool UGenericActionSubsystem::IsWidgetOwnedByThisSubsystem(const UGenericActionWidget* InWidget) const
{
	const ULocalPlayer* WidgetLocalPlayer = InWidget ? InWidget->GetOwningLocalPlayer() : nullptr;
	return !WidgetLocalPlayer || WidgetLocalPlayer == GetLocalPlayer();
}

bool UGenericActionSubsystem::DispatchViewportInput(const FGenericActionViewportInputEvent& InputEvent, bool bCanConsumeInput)
{
	if (!InputEvent.Key.IsValid())
	{
		return false;
	}

	PruneRuntimeTriggerStates();

	UGenericLayerSubsystem* LayerSubsystem = UGenericLayerSubsystem::Get(GetLocalPlayer());
	const UGenericRouteSubsystem* RouteSubsystem = UGenericRouteSubsystem::Get(GetLocalPlayer());
	if (!LayerSubsystem || !RouteSubsystem)
	{
		bool bPostRouteConsumed = false;
		Delegate_PostRouteViewportInput.Broadcast(InputEvent, bPostRouteConsumed);
		return bPostRouteConsumed;
	}

	for (UGenericLayer* Layer : LayerSubsystem->GetAllLayersByPriority())
	{
		const TScriptInterface<IGenericRouteInterface> LayerRoute = UGenericRouteSubsystem::MakeRouteInterface(Layer);
		if (!IsValid(Layer) || !IsValid(Layer->InputActionDataAsset) || !RouteSubsystem->IsRouteActive(LayerRoute) || !Layer->IsVisible())
		{
			continue;
		}

		for (const FGenericInputActionKeyTriggerMapping& ActionMapping : Layer->InputActionDataAsset->ActionMappings)
		{
			if (!ActionMapping.ActionTag.IsValid())
			{
				continue;
			}

			for (const FGenericInputKeyTrigger& KeyTrigger : ActionMapping.KeyTriggers)
			{
				if (KeyTrigger.Key != InputEvent.Key || !IsValid(KeyTrigger.Trigger))
				{
					continue;
				}

				bool bShouldConsume = false;
				EvaluateLayerActionInput(Layer, ActionMapping, KeyTrigger, InputEvent, RouteSubsystem, bCanConsumeInput, bShouldConsume);
				if (bShouldConsume)
				{
					return true;
				}
			}
		}
	}

	bool bPostRouteConsumed = false;
	Delegate_PostRouteViewportInput.Broadcast(InputEvent, bPostRouteConsumed);
	return bPostRouteConsumed;
}

bool UGenericActionSubsystem::TickActionInput(float DeltaTime)
{
	PruneRuntimeTriggerStates();

	const UGenericRouteSubsystem* RouteSubsystem = UGenericRouteSubsystem::Get(GetLocalPlayer());
	if (!RouteSubsystem)
	{
		return true;
	}

	for (int32 Index = 0; Index < RuntimeTriggerStates.Num(); ++Index)
	{
		FGenericActionRuntimeTriggerState& RuntimeState = RuntimeTriggerStates[Index];
		if (!RuntimeState.bIsPressed && RuntimeState.LastTriggerState == EGenericInputTriggerState::None)
		{
			continue;
		}

		if (!IsValid(RuntimeState.Layer) || !IsValid(RuntimeState.RuntimeTrigger))
		{
			continue;
		}

		FGenericActionViewportInputEvent InputEvent;
		InputEvent.Key = RuntimeState.Key;
		InputEvent.InputValue = RuntimeState.LastInputValue;
		InputEvent.bIsPressed = RuntimeState.bIsPressed;
		InputEvent.DeltaTime = DeltaTime;

		const FGenericInputTriggerContext TriggerContext = BuildTriggerContext(RuntimeState, InputEvent);
		const EGenericInputTriggerState NewTriggerState = RuntimeState.RuntimeTrigger->UpdateState(TriggerContext);
		DispatchTriggerEventsToLayer(RuntimeState.Layer, RuntimeState.ActionTag, InputEvent, TriggerContext, RuntimeState, NewTriggerState, RouteSubsystem);
		UpdateRuntimeTriggerState(RuntimeState, TriggerContext, NewTriggerState);
	}

	PruneRuntimeTriggerStates();
	return true;
}

bool UGenericActionSubsystem::EvaluateLayerActionInput(UGenericLayer* InLayer, const FGenericInputActionKeyTriggerMapping& ActionMapping, const FGenericInputKeyTrigger& KeyTrigger, const FGenericActionViewportInputEvent& InputEvent, const UGenericRouteSubsystem* RouteSubsystem, bool bCanConsumeInput, bool& bOutShouldConsume)
{
	bOutShouldConsume = false;

	FGenericActionRuntimeTriggerState& RuntimeState = FindOrCreateRuntimeTriggerState(InLayer, ActionMapping.ActionTag, KeyTrigger);
	if (!IsValid(RuntimeState.RuntimeTrigger))
	{
		return false;
	}

	RuntimeState.LastInputValue = InputEvent.InputValue;

	const FGenericInputTriggerContext TriggerContext = BuildTriggerContext(RuntimeState, InputEvent);
	const EGenericInputTriggerState NewTriggerState = RuntimeState.RuntimeTrigger->UpdateState(TriggerContext);
	bool bHandled = DispatchTriggerEventsToLayer(InLayer, ActionMapping.ActionTag, InputEvent, TriggerContext, RuntimeState, NewTriggerState, RouteSubsystem);
	UpdateRuntimeTriggerState(RuntimeState, TriggerContext, NewTriggerState);

	if (!InputEvent.bIsPressed && NewTriggerState == EGenericInputTriggerState::Triggered)
	{
		bHandled |= DispatchTriggerEventsToLayer(InLayer, ActionMapping.ActionTag, InputEvent, TriggerContext, RuntimeState, EGenericInputTriggerState::None, RouteSubsystem);
		UpdateRuntimeTriggerState(RuntimeState, TriggerContext, EGenericInputTriggerState::None);
	}

	if (bHandled && bCanConsumeInput && ActionMapping.bConsumeInput)
	{
		bOutShouldConsume = true;
	}

	return bHandled;
}

FGenericActionRuntimeTriggerState& UGenericActionSubsystem::FindOrCreateRuntimeTriggerState(UGenericLayer* InLayer, FGameplayTag InActionTag, const FGenericInputKeyTrigger& InKeyTrigger)
{
	for (FGenericActionRuntimeTriggerState& RuntimeState : RuntimeTriggerStates)
	{
		if (RuntimeState.Layer == InLayer && RuntimeState.ActionTag.MatchesTagExact(InActionTag) && RuntimeState.Key == InKeyTrigger.Key && RuntimeState.TemplateTrigger == InKeyTrigger.Trigger)
		{
			if (!IsValid(RuntimeState.RuntimeTrigger) && IsValid(InKeyTrigger.Trigger))
			{
				RuntimeState.RuntimeTrigger = DuplicateObject<UGenericInputTrigger>(InKeyTrigger.Trigger, this);
			}

			return RuntimeState;
		}
	}

	FGenericActionRuntimeTriggerState& RuntimeState = RuntimeTriggerStates.AddDefaulted_GetRef();
	RuntimeState.Layer = InLayer;
	RuntimeState.ActionTag = InActionTag;
	RuntimeState.Key = InKeyTrigger.Key;
	RuntimeState.TemplateTrigger = InKeyTrigger.Trigger;
	RuntimeState.RuntimeTrigger = IsValid(InKeyTrigger.Trigger) ? DuplicateObject<UGenericInputTrigger>(InKeyTrigger.Trigger, this) : nullptr;
	return RuntimeState;
}

FGenericInputTriggerContext UGenericActionSubsystem::BuildTriggerContext(FGenericActionRuntimeTriggerState& RuntimeState, const FGenericActionViewportInputEvent& InputEvent) const
{
	const double CurrentTime = FPlatformTime::Seconds();
	const float DeltaTime = InputEvent.DeltaTime > 0.0f ? InputEvent.DeltaTime : RuntimeState.LastUpdateTime > 0.0 ? static_cast<float>(CurrentTime - RuntimeState.LastUpdateTime) : 0.0f;
	const bool bWasPressed = RuntimeState.bIsPressed;

	FGenericInputTriggerContext TriggerContext;
	TriggerContext.Key = InputEvent.Key;
	TriggerContext.InputValue = InputEvent.InputValue;
	TriggerContext.DeltaTime = FMath::Max(0.0f, DeltaTime);
	TriggerContext.bIsPressed = InputEvent.bIsPressed;
	TriggerContext.bWasPressed = bWasPressed;
	TriggerContext.CurrentTime = CurrentTime;
	TriggerContext.HeldDuration = InputEvent.bIsPressed ? (bWasPressed ? RuntimeState.HeldDuration + TriggerContext.DeltaTime : TriggerContext.DeltaTime) : RuntimeState.HeldDuration;
	TriggerContext.ReleasedDuration = InputEvent.bIsPressed ? 0.0f : (bWasPressed ? 0.0f : RuntimeState.ReleasedDuration + TriggerContext.DeltaTime);
	return TriggerContext;
}

void UGenericActionSubsystem::UpdateRuntimeTriggerState(FGenericActionRuntimeTriggerState& RuntimeState, const FGenericInputTriggerContext& TriggerContext, EGenericInputTriggerState NewTriggerState)
{
	RuntimeState.LastInputValue = TriggerContext.InputValue;
	RuntimeState.bIsPressed = TriggerContext.bIsPressed;
	RuntimeState.HeldDuration = TriggerContext.bIsPressed ? TriggerContext.HeldDuration : 0.0f;
	RuntimeState.ReleasedDuration = TriggerContext.bIsPressed ? 0.0f : TriggerContext.ReleasedDuration;
	RuntimeState.LastUpdateTime = TriggerContext.CurrentTime;

	if (NewTriggerState == EGenericInputTriggerState::Triggered)
	{
		RuntimeState.bHasTriggered = true;
		RuntimeState.TriggeredTime = RuntimeState.LastTriggerState == EGenericInputTriggerState::Triggered ? RuntimeState.TriggeredTime + TriggerContext.DeltaTime : TriggerContext.DeltaTime;
	}
	else if (NewTriggerState == EGenericInputTriggerState::None)
	{
		RuntimeState.TriggeredTime = 0.0f;
		RuntimeState.bHasTriggered = false;
		RuntimeState.bHasStarted = false;
	}

	RuntimeState.LastTriggerState = NewTriggerState;
}

bool UGenericActionSubsystem::DispatchTriggerEventsToLayer(UGenericLayer* InLayer, FGameplayTag InActionTag, const FGenericActionViewportInputEvent& InputEvent, const FGenericInputTriggerContext& TriggerContext, FGenericActionRuntimeTriggerState& RuntimeState, EGenericInputTriggerState NewTriggerState, const UGenericRouteSubsystem* RouteSubsystem)
{
	TArray<EGenericActionTriggerEvent, TInlineAllocator<2>> TriggerEvents;
	GetTriggerEvents(RuntimeState.LastTriggerState, NewTriggerState, RuntimeState.bHasTriggered, TriggerEvents);

	bool bHandled = false;
	for (EGenericActionTriggerEvent TriggerEvent : TriggerEvents)
	{
		if (TriggerEvent == EGenericActionTriggerEvent::Started)
		{
			if (RuntimeState.bHasStarted)
			{
				continue;
			}

			RuntimeState.bHasStarted = true;
		}

		FGenericActionInputEventData EventData;
		EventData.ActionTag = InActionTag;
		EventData.TriggerEvent = TriggerEvent;
		EventData.Key = InputEvent.Key;
		EventData.ActionValue = InputEvent.InputValue.GetMagnitude();
		EventData.ElapsedTime = TriggerContext.HeldDuration;
		EventData.TriggeredTime = GetEventTriggeredTime(TriggerEvent, RuntimeState, TriggerContext, NewTriggerState);

		bHandled |= DispatchActionEventToLayer(InLayer, InActionTag, EventData, RouteSubsystem);
	}

	return bHandled;
}

bool UGenericActionSubsystem::DispatchActionEventToLayer(UGenericLayer* InLayer, FGameplayTag InActionTag, const FGenericActionInputEventData& EventData, const UGenericRouteSubsystem* RouteSubsystem)
{
	for (int32 Index = ActionWidgetStack.Num() - 1; Index >= 0; --Index)
	{
		UGenericActionWidget* Widget = ActionWidgetStack[Index];
		if (!IsValid(Widget) || !Widget->IsVisible() || !Widget->ActionTag.MatchesTagExact(InActionTag) || !IsActionWidgetInLayerRoute(Widget, InLayer, RouteSubsystem))
		{
			continue;
		}

		if (Widget->ExecuteActionTagEvent(InActionTag, EventData.TriggerEvent, EventData))
		{
			return true;
		}
	}

	return false;
}

bool UGenericActionSubsystem::IsActionWidgetInLayerRoute(UGenericActionWidget* InWidget, UGenericLayer* InLayer, const UGenericRouteSubsystem* RouteSubsystem) const
{
	if (!IsValid(InWidget) || !IsValid(InLayer) || !RouteSubsystem)
	{
		return false;
	}

	const TScriptInterface<IGenericRouteInterface> WidgetRoute = UGenericRouteSubsystem::MakeRouteInterface(InWidget);
	const TScriptInterface<IGenericRouteInterface> LayerRoute = UGenericRouteSubsystem::MakeRouteInterface(InLayer);
	return RouteSubsystem->IsRouteActive(WidgetRoute) && RouteSubsystem->IsRouteDescendantOf(WidgetRoute, LayerRoute);
}

void UGenericActionSubsystem::PruneRuntimeTriggerStates()
{
	UGenericLayerSubsystem* LayerSubsystem = UGenericLayerSubsystem::Get(GetLocalPlayer());
	const UGenericRouteSubsystem* RouteSubsystem = UGenericRouteSubsystem::Get(GetLocalPlayer());
	if (!LayerSubsystem || !RouteSubsystem)
	{
		RuntimeTriggerStates.Reset();
		return;
	}

	for (int32 Index = RuntimeTriggerStates.Num() - 1; Index >= 0; --Index)
	{
		const FGenericActionRuntimeTriggerState& RuntimeState = RuntimeTriggerStates[Index];
		UGenericLayer* Layer = RuntimeState.Layer;
		const TScriptInterface<IGenericRouteInterface> LayerRoute = UGenericRouteSubsystem::MakeRouteInterface(Layer);
		const bool bFinished = !RuntimeState.bIsPressed && RuntimeState.LastTriggerState == EGenericInputTriggerState::None;

		if (bFinished || !IsValid(Layer) || !Layer->IsVisible() || !RouteSubsystem->IsRouteActive(LayerRoute) || LayerSubsystem->GetLayer(Layer->LayerTag) != Layer || !IsValid(RuntimeState.TemplateTrigger) || !IsValid(RuntimeState.RuntimeTrigger))
		{
			RuntimeTriggerStates.RemoveAtSwap(Index);
		}
	}
}
