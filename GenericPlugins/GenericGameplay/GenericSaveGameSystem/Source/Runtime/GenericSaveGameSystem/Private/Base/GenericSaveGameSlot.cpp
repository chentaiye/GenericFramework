// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Base/GenericSaveGameSlot.h"

UGenericSaveGameSlot::UGenericSaveGameSlot(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FGuid UGenericSaveGameSlot::GetSlotGuid() const
{
	return SlotGuid;
}

void UGenericSaveGameSlot::SetSlotGuid(const FGuid& InSlotGuid)
{
	SlotGuid = InSlotGuid;
}

FString UGenericSaveGameSlot::GetSlotGuidString() const
{
	return SlotGuid.IsValid() ? SlotGuid.ToString(EGuidFormats::DigitsWithHyphens) : FString();
}
