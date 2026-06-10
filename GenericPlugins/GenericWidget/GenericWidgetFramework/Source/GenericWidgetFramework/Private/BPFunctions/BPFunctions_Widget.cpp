// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_Widget.h"

#include "Subsystem/GenericWidgetSubsystem.h"

UGenericWidgetSubsystem* UBPFunctions_Widget::GetGenericWidgetSubsystem(APlayerController* PlayerController)
{
	return UGenericWidgetSubsystem::Get(PlayerController);
}

bool UBPFunctions_Widget::RegisterWidget(APlayerController* PlayerController, UGenericWidget* InWidget, FGameplayTag InSlotTag, ESlateVisibility InVisibility)
{
	UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(PlayerController);
	return WidgetSubsystem ? WidgetSubsystem->RegisterWidget(InWidget, InSlotTag, InVisibility) : false;
}

UGenericWidget* UBPFunctions_Widget::RegisterWidgetByClass(APlayerController* PlayerController, TSubclassOf<UGenericWidget> InWidgetClass, FGameplayTag InSlotTag, ESlateVisibility InVisibility)
{
	UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(PlayerController);
	return WidgetSubsystem ? WidgetSubsystem->RegisterWidget(InWidgetClass, InSlotTag, InVisibility) : nullptr;
}

bool UBPFunctions_Widget::UnregisterWidget(APlayerController* PlayerController, UGenericWidget* InWidget, bool bClearSlot)
{
	UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(PlayerController);
	return WidgetSubsystem ? WidgetSubsystem->UnregisterWidget(InWidget, bClearSlot) : false;
}

bool UBPFunctions_Widget::UnregisterWidgetBySlotTag(APlayerController* PlayerController, FGameplayTag InSlotTag, bool bClearSlot)
{
	UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(PlayerController);
	return WidgetSubsystem ? WidgetSubsystem->UnregisterWidgetBySlotTag(InSlotTag, bClearSlot) : false;
}

UGenericWidget* UBPFunctions_Widget::GetWidget(APlayerController* PlayerController, FGameplayTag InSlotTag)
{
	const UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(PlayerController);
	return WidgetSubsystem ? WidgetSubsystem->GetWidget(InSlotTag) : nullptr;
}

bool UBPFunctions_Widget::HasWidget(APlayerController* PlayerController, FGameplayTag InSlotTag)
{
	const UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(PlayerController);
	return WidgetSubsystem ? WidgetSubsystem->HasWidget(InSlotTag) : false;
}

TArray<UGenericWidget*> UBPFunctions_Widget::GetAllWidgets(APlayerController* PlayerController)
{
	const UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(PlayerController);
	return WidgetSubsystem ? WidgetSubsystem->GetAllWidgets() : TArray<UGenericWidget*>();
}
