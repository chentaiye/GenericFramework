// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericWidgetSubsystem.h"

#include "Base/GenericWidget.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "Subsystem/GenericSlotSubsystem.h"
#include "WidgetType.h"

namespace
{
	void BroadcastWidgetRegisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, FGameplayTag SlotTag, UGenericWidget* Widget)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnWidgetRegisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.SlotTag = SlotTag;
		Message.Widget = Widget;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnWidgetRegister, Message);
	}

	void BroadcastWidgetUnregisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, FGameplayTag SlotTag, UGenericWidget* Widget)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnWidgetUnregisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.SlotTag = SlotTag;
		Message.Widget = Widget;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnWidgetUnRegister, Message);
	}

	void BroadcastWidgetRegisteredToOwnerMessage(const UObject* WorldContextObject, APlayerController* PlayerController, UGenericWidget* Widget, TScriptInterface<IGenericRouteInterface> Owner)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnWidgetRegisteredToOwnerMessage Message;
		Message.PlayerController = PlayerController;
		Message.Widget = Widget;
		Message.Owner = Owner;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnWidgetRegisterToOwner, Message);
	}

	void BroadcastWidgetUnregisteredFromOwnerMessage(const UObject* WorldContextObject, APlayerController* PlayerController, UGenericWidget* Widget, TScriptInterface<IGenericRouteInterface> Owner)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnWidgetUnregisteredFromOwnerMessage Message;
		Message.PlayerController = PlayerController;
		Message.Widget = Widget;
		Message.Owner = Owner;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnWidgetUnRegisterFromOwner, Message);
	}
}

UGenericWidgetSubsystem* UGenericWidgetSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<UGenericWidgetSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UGenericWidgetSubsystem* UGenericWidgetSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UGenericWidgetSubsystem>(LocalPlayer);
}

bool UGenericWidgetSubsystem::RegisterWidget(UGenericWidget* InWidget, FGameplayTag InSlotTag, ESlateVisibility InVisibility)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget failed because widget is null. SlotTag: %s"), *InSlotTag.ToString());
		return false;
	}

	if (!IsWidgetOwnedByThisSubsystem(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget failed because widget '%s' does not belong to this local player. SlotTag: %s"), *InWidget->GetName(), *InSlotTag.ToString());
		return false;
	}

	if (!IsValidSlotTag(InSlotTag))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget failed because slot tag is invalid. SlotTag: %s"), *InSlotTag.ToString());
		return false;
	}

	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(GetLocalPlayer());
	if (!SlotSubsystem)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget failed because GenericSlotSubsystem is missing. Widget: %s, SlotTag: %s"), *InWidget->GetName(), *InSlotTag.ToString());
		return false;
	}

	if (!SlotSubsystem->HasSlot(InSlotTag))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget failed because slot is not registered. Widget: %s, SlotTag: %s"), *InWidget->GetName(), *InSlotTag.ToString());
		return false;
	}

	if (FGenericRegisteredWidget* ExistingRegisteredWidget = RegisteredWidgets.Find(InSlotTag))
	{
		UGenericWidget* ExistingWidget = ExistingRegisteredWidget->Widget;

		if (ExistingWidget == InWidget)
		{
			InWidget->SetVisibility(InVisibility);
			if (SlotSubsystem->GetSlotContent(InSlotTag) == InWidget || SlotSubsystem->SetSlotContent(InSlotTag, InWidget))
			{
				return true;
			}

			UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget failed to refresh existing slot content. Widget: %s, SlotTag: %s"), *InWidget->GetName(), *InSlotTag.ToString());
			return false;
		}

		if (IsValid(ExistingWidget))
		{
			UE_LOG(GenericLogUI, Verbose, TEXT("RegisterWidget is replacing widget '%s' with '%s'. SlotTag: %s"), *ExistingWidget->GetName(), *InWidget->GetName(), *InSlotTag.ToString());
			InWidget->SetVisibility(InVisibility);
			if (!SlotSubsystem->SetSlotContent(InSlotTag, InWidget))
			{
				UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget failed to replace slot content. Widget: %s, SlotTag: %s"), *InWidget->GetName(), *InSlotTag.ToString());
				return false;
			}

			UnregisterWidgetInternal(InSlotTag, false);
		}
		else
		{
			RegisteredWidgets.Remove(InSlotTag);
		}
	}

	InWidget->SetVisibility(InVisibility);

	if (!SlotSubsystem->SetSlotContent(InSlotTag, InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget failed to set slot content. Widget: %s, SlotTag: %s"), *InWidget->GetName(), *InSlotTag.ToString());
		return false;
	}

	FGenericRegisteredWidget& RegisteredWidget = RegisteredWidgets.Add(InSlotTag);
	RegisteredWidget.Widget = InWidget;

	BroadcastWidgetRegisteredMessage(this, GetPlayerController(), InSlotTag, InWidget);
	return true;
}

bool UGenericWidgetSubsystem::RegisterWidget(UGenericWidget* InWidget, TScriptInterface<IGenericRouteInterface> InOwner, ESlateVisibility InVisibility)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget to owner failed because widget is null."));
		return false;
	}

	if (!IsWidgetOwnedByThisSubsystem(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget to owner failed because widget '%s' does not belong to this local player."), *InWidget->GetName());
		return false;
	}

	if (!IsValidOwnerRoute(InOwner))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget to owner failed because owner route is invalid. Widget: %s"), *InWidget->GetName());
		return false;
	}

	const FGameplayTag RegisteredSlotTag = FindRegisteredSlotTag(InWidget);
	if (RegisteredSlotTag.IsValid())
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget to owner failed because widget '%s' is already registered to slot '%s'."), *InWidget->GetName(), *RegisteredSlotTag.ToString());
		return false;
	}

	InWidget->SetVisibility(InVisibility);

	const int32 ExistingIndex = FindOwnerRegisteredWidgetIndex(InWidget);
	if (ExistingIndex != INDEX_NONE)
	{
		FGenericOwnerRegisteredWidget& ExistingRegisteredWidget = OwnerRegisteredWidgets[ExistingIndex];
		if (ExistingRegisteredWidget.Owner.GetObject() == InOwner.GetObject())
		{
			return true;
		}

		ExistingRegisteredWidget.Owner = InOwner;
		BroadcastWidgetRegisteredToOwnerMessage(this, GetPlayerController(), InWidget, InOwner);
		return true;
	}

	FGenericOwnerRegisteredWidget& RegisteredWidget = OwnerRegisteredWidgets.AddDefaulted_GetRef();
	RegisteredWidget.Widget = InWidget;
	RegisteredWidget.Owner = InOwner;

	BroadcastWidgetRegisteredToOwnerMessage(this, GetPlayerController(), InWidget, InOwner);
	return true;
}

UGenericWidget* UGenericWidgetSubsystem::RegisterWidget(TSubclassOf<UGenericWidget> InWidgetClass, FGameplayTag InSlotTag, ESlateVisibility InVisibility)
{
	if (!InWidgetClass)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget class failed because widget class is null. SlotTag: %s"), *InSlotTag.ToString());
		return nullptr;
	}

	if (!IsValidSlotTag(InSlotTag))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget class failed because slot tag is invalid. SlotTag: %s"), *InSlotTag.ToString());
		return nullptr;
	}

	APlayerController* PlayerController = GetPlayerController();
	if (!PlayerController)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget class failed because player controller is missing. SlotTag: %s"), *InSlotTag.ToString());
		return nullptr;
	}

	UGenericWidget* Widget = CreateWidget<UGenericWidget>(PlayerController, InWidgetClass);
	if (!Widget)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWidget class failed to create widget. Class: %s, SlotTag: %s"), *InWidgetClass->GetName(), *InSlotTag.ToString());
		return nullptr;
	}

	if (!RegisterWidget(Widget, InSlotTag, InVisibility))
	{
		return nullptr;
	}

	return Widget;
}

bool UGenericWidgetSubsystem::UnregisterWidget(UGenericWidget* InWidget, bool bClearSlot)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterWidget failed because widget is null."));
		return false;
	}

	for (const TPair<FGameplayTag, FGenericRegisteredWidget>& RegisteredWidgetPair : RegisteredWidgets)
	{
		if (RegisteredWidgetPair.Value.Widget == InWidget)
		{
			return UnregisterWidgetInternal(RegisteredWidgetPair.Key, bClearSlot);
		}
	}

	const int32 OwnerRegisteredWidgetIndex = FindOwnerRegisteredWidgetIndex(InWidget);
	if (OwnerRegisteredWidgetIndex != INDEX_NONE)
	{
		return UnregisterOwnerWidgetInternal(OwnerRegisteredWidgetIndex);
	}

	UE_LOG(GenericLogUI, Warning, TEXT("UnregisterWidget failed because widget '%s' is not registered."), *InWidget->GetName());
	return false;
}

bool UGenericWidgetSubsystem::UnregisterWidgetBySlotTag(FGameplayTag InSlotTag, bool bClearSlot)
{
	return UnregisterWidgetInternal(InSlotTag, bClearSlot);
}

UGenericWidget* UGenericWidgetSubsystem::GetWidget(FGameplayTag InSlotTag) const
{
	const FGenericRegisteredWidget* RegisteredWidget = RegisteredWidgets.Find(InSlotTag);
	return RegisteredWidget && IsValid(RegisteredWidget->Widget) ? RegisteredWidget->Widget : nullptr;
}

bool UGenericWidgetSubsystem::HasWidget(FGameplayTag InSlotTag) const
{
	return GetWidget(InSlotTag) != nullptr;
}

TArray<UGenericWidget*> UGenericWidgetSubsystem::GetAllWidgets() const
{
	TArray<UGenericWidget*> Widgets;

	for (const TPair<FGameplayTag, FGenericRegisteredWidget>& RegisteredWidgetPair : RegisteredWidgets)
	{
		if (UGenericWidget* Widget = RegisteredWidgetPair.Value.Widget)
		{
			if (IsValid(Widget))
			{
				Widgets.Add(Widget);
			}
		}
	}

	for (const FGenericOwnerRegisteredWidget& RegisteredWidget : OwnerRegisteredWidgets)
	{
		if (UGenericWidget* Widget = RegisteredWidget.Widget)
		{
			if (IsValid(Widget))
			{
				Widgets.Add(Widget);
			}
		}
	}

	return Widgets;
}

void UGenericWidgetSubsystem::Deinitialize()
{
	TArray<FGameplayTag> SlotTags;
	RegisteredWidgets.GenerateKeyArray(SlotTags);

	for (const FGameplayTag& SlotTag : SlotTags)
	{
		UnregisterWidgetInternal(SlotTag, true);
	}

	while (OwnerRegisteredWidgets.Num() > 0)
	{
		UnregisterOwnerWidgetInternal(OwnerRegisteredWidgets.Num() - 1);
	}

	Super::Deinitialize();
}

bool UGenericWidgetSubsystem::IsWidgetOwnedByThisSubsystem(const UGenericWidget* InWidget) const
{
	const ULocalPlayer* WidgetLocalPlayer = InWidget ? InWidget->GetOwningLocalPlayer() : nullptr;
	return !WidgetLocalPlayer || WidgetLocalPlayer == GetLocalPlayer();
}

bool UGenericWidgetSubsystem::IsValidSlotTag(FGameplayTag InSlotTag) const
{
	return InSlotTag.IsValid() && InSlotTag.MatchesTag(TAG_GameplayUI_Slot);
}

bool UGenericWidgetSubsystem::IsValidOwnerRoute(TScriptInterface<IGenericRouteInterface> InOwner) const
{
	UObject* OwnerObject = InOwner.GetObject();
	return IsValid(OwnerObject) && OwnerObject->GetClass()->ImplementsInterface(UGenericRouteInterface::StaticClass());
}

int32 UGenericWidgetSubsystem::FindOwnerRegisteredWidgetIndex(const UGenericWidget* InWidget) const
{
	for (int32 WidgetIndex = 0; WidgetIndex < OwnerRegisteredWidgets.Num(); ++WidgetIndex)
	{
		if (OwnerRegisteredWidgets[WidgetIndex].Widget == InWidget)
		{
			return WidgetIndex;
		}
	}

	return INDEX_NONE;
}

FGameplayTag UGenericWidgetSubsystem::FindRegisteredSlotTag(const UGenericWidget* InWidget) const
{
	for (const TPair<FGameplayTag, FGenericRegisteredWidget>& RegisteredWidgetPair : RegisteredWidgets)
	{
		if (RegisteredWidgetPair.Value.Widget == InWidget)
		{
			return RegisteredWidgetPair.Key;
		}
	}

	return FGameplayTag();
}

bool UGenericWidgetSubsystem::UnregisterWidgetInternal(FGameplayTag InSlotTag, bool bClearSlot)
{
	FGenericRegisteredWidget RegisteredWidget;

	if (!RegisteredWidgets.RemoveAndCopyValue(InSlotTag, RegisteredWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterWidget failed because slot tag is not registered. SlotTag: %s"), *InSlotTag.ToString());
		return false;
	}

	UGenericWidget* Widget = RegisteredWidget.Widget;
	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(GetLocalPlayer());

	if (IsValid(Widget) && bClearSlot && SlotSubsystem && SlotSubsystem->GetSlotContent(InSlotTag) == Widget)
	{
		if (!SlotSubsystem->ClearSlotContent(InSlotTag))
		{
			UE_LOG(GenericLogUI, Warning, TEXT("UnregisterWidget failed to clear slot content. Widget: %s, SlotTag: %s"), *Widget->GetName(), *InSlotTag.ToString());
		}
	}
	else if (IsValid(Widget) && bClearSlot && !SlotSubsystem)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterWidget could not clear slot content because GenericSlotSubsystem is missing. Widget: %s, SlotTag: %s"), *Widget->GetName(), *InSlotTag.ToString());
	}

	BroadcastWidgetUnregisteredMessage(this, GetPlayerController(), InSlotTag, Widget);
	return true;
}

bool UGenericWidgetSubsystem::UnregisterOwnerWidgetInternal(int32 InOwnerWidgetIndex)
{
	if (!OwnerRegisteredWidgets.IsValidIndex(InOwnerWidgetIndex))
	{
		return false;
	}

	FGenericOwnerRegisteredWidget RegisteredWidget = OwnerRegisteredWidgets[InOwnerWidgetIndex];
	OwnerRegisteredWidgets.RemoveAt(InOwnerWidgetIndex);

	BroadcastWidgetUnregisteredFromOwnerMessage(this, GetPlayerController(), RegisteredWidget.Widget, RegisteredWidget.Owner);
	return true;
}
