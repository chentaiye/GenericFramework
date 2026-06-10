// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_Slot.h"

#include "Subsystem/GenericSlotSubsystem.h"

UGenericSlotSubsystem* UBPFunctions_Slot::GetGenericSlotSubsystem(APlayerController* PlayerController)
{
	return UGenericSlotSubsystem::Get(PlayerController);
}

bool UBPFunctions_Slot::RegisterSlot(APlayerController* PlayerController, UGameplayTagSlot* InSlot, TScriptInterface<IGenericRouteInterface> InOwner)
{
	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->RegisterSlot(InSlot, InOwner) : false;
}

bool UBPFunctions_Slot::UnregisterSlot(APlayerController* PlayerController, UGameplayTagSlot* InSlot)
{
	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->UnregisterSlot(InSlot) : false;
}

bool UBPFunctions_Slot::UnregisterSlotByTag(APlayerController* PlayerController, FGameplayTag InSlotTag)
{
	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->UnregisterSlotByTag(InSlotTag) : false;
}

UGameplayTagSlot* UBPFunctions_Slot::GetSlot(APlayerController* PlayerController, FGameplayTag InSlotTag)
{
	const UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->GetSlot(InSlotTag) : nullptr;
}

bool UBPFunctions_Slot::HasSlot(APlayerController* PlayerController, FGameplayTag InSlotTag)
{
	const UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->HasSlot(InSlotTag) : false;
}

bool UBPFunctions_Slot::SetSlotVisibility(APlayerController* PlayerController, FGameplayTag InSlotTag, ESlateVisibility InVisibility)
{
	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->SetSlotVisibility(InSlotTag, InVisibility) : false;
}

bool UBPFunctions_Slot::SetSlotContent(APlayerController* PlayerController, FGameplayTag InSlotTag, UWidget* InContent)
{
	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->SetSlotContent(InSlotTag, InContent) : false;
}

UWidget* UBPFunctions_Slot::GetSlotContent(APlayerController* PlayerController, FGameplayTag InSlotTag)
{
	const UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->GetSlotContent(InSlotTag) : nullptr;
}

bool UBPFunctions_Slot::ClearSlotContent(APlayerController* PlayerController, FGameplayTag InSlotTag)
{
	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->ClearSlotContent(InSlotTag) : false;
}

TArray<UGameplayTagSlot*> UBPFunctions_Slot::GetAllSlots(APlayerController* PlayerController)
{
	const UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(PlayerController);
	return SlotSubsystem ? SlotSubsystem->GetAllSlots() : TArray<UGameplayTagSlot*>();
}
