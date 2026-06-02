// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericButtonGroup.h"

#include "Base/GenericButtonWidget.h"
#include "WidgetType.h"

bool UGenericButtonGroup::AddButton(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("AddButton failed because button is null. Group: %s"), *GetName());
		return false;
	}

	if (ContainsButton(InButton))
	{
		return true;
	}

	FGenericButtonGroupEntry& Entry = ButtonEntries.AddDefaulted_GetRef();
	Entry.Button = InButton;
	BindButtonEvents(InButton);
	HandleButtonAdded(InButton);
	return true;
}

void UGenericButtonGroup::AddButtons(const TArray<UGenericButtonWidget*>& InButtons)
{
	for (UGenericButtonWidget* Button : InButtons)
	{
		AddButton(Button);
	}
}

bool UGenericButtonGroup::RemoveButton(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RemoveButton failed because button is null. Group: %s"), *GetName());
		return false;
	}

	const int32 EntryIndex = FindButtonEntryIndex(InButton);
	if (EntryIndex == INDEX_NONE)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RemoveButton failed because button '%s' is not managed by group '%s'."), *InButton->GetName(), *GetName());
		return false;
	}

	UnbindButtonEvents(InButton);
	ButtonEntries.RemoveAt(EntryIndex);
	HandleButtonRemoved(InButton);
	return true;
}

void UGenericButtonGroup::RemoveButtons(const TArray<UGenericButtonWidget*>& InButtons)
{
	for (UGenericButtonWidget* Button : InButtons)
	{
		RemoveButton(Button);
	}
}

bool UGenericButtonGroup::RemoveButtonByIndex(int32 InIndex)
{
	UGenericButtonWidget* Button = GetButtonByIndex(InIndex);
	if (!IsValid(Button))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RemoveButtonByIndex failed because index %d is invalid. Group: %s"), InIndex, *GetName());
		return false;
	}

	return RemoveButton(Button);
}

void UGenericButtonGroup::ClearButtons()
{
	TArray<UGenericButtonWidget*> ButtonsToRemove = GetButtons();
	for (UGenericButtonWidget* Button : ButtonsToRemove)
	{
		RemoveButton(Button);
	}
}

TArray<UGenericButtonWidget*> UGenericButtonGroup::GetButtons() const
{
	TArray<UGenericButtonWidget*> Result;
	Result.Reserve(ButtonEntries.Num());

	for (const FGenericButtonGroupEntry& Entry : ButtonEntries)
	{
		UGenericButtonWidget* Button = Entry.Button.Get();
		if (IsValid(Button))
		{
			Result.Add(Button);
		}
	}

	return Result;
}

int32 UGenericButtonGroup::GetButtonCount() const
{
	return ButtonEntries.Num();
}

UGenericButtonWidget* UGenericButtonGroup::GetButtonByIndex(int32 InIndex) const
{
	if (!ButtonEntries.IsValidIndex(InIndex))
	{
		return nullptr;
	}

	return ButtonEntries[InIndex].Button.Get();
}

int32 UGenericButtonGroup::FindButtonIndex(UGenericButtonWidget* InButton) const
{
	return FindButtonEntryIndex(InButton);
}

bool UGenericButtonGroup::ContainsButton(UGenericButtonWidget* InButton) const
{
	return FindButtonEntryIndex(InButton) != INDEX_NONE;
}

bool UGenericButtonGroup::IsFirstButton(UGenericButtonWidget* InButton) const
{
	return FindButtonEntryIndex(InButton) == 0;
}

bool UGenericButtonGroup::IsLastButton(UGenericButtonWidget* InButton) const
{
	const int32 EntryIndex = FindButtonEntryIndex(InButton);
	return EntryIndex != INDEX_NONE && EntryIndex == ButtonEntries.Num() - 1;
}

EGenericButtonGroupSelectionMode UGenericButtonGroup::GetSelectionMode() const
{
	return EGenericButtonGroupSelectionMode::Single;
}

void UGenericButtonGroup::HandleButtonAdded(UGenericButtonWidget* InButton)
{
}

void UGenericButtonGroup::HandleButtonRemoved(UGenericButtonWidget* InButton)
{
}

void UGenericButtonGroup::NativeOnGroupButtonEnabled(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonEnabled(InButton);
}

void UGenericButtonGroup::NativeOnGroupButtonDisabled(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonDisabled(InButton);
}

void UGenericButtonGroup::NativeOnGroupButtonPressed(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonPressed(InButton);
}

void UGenericButtonGroup::NativeOnGroupButtonReleased(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonReleased(InButton);
}

void UGenericButtonGroup::NativeOnGroupButtonHovered(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonHovered(InButton);
}

void UGenericButtonGroup::NativeOnGroupButtonUnhovered(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonUnhovered(InButton);
}

void UGenericButtonGroup::NativeOnGroupButtonClicked(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonClicked(InButton);
}

void UGenericButtonGroup::NativeOnGroupButtonDoubleClicked(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonDoubleClicked(InButton);
}

void UGenericButtonGroup::NativeOnGroupButtonSelectionChanged(UGenericButtonWidget* InButton, bool bSelected)
{
	HandleOnGroupButtonSelectionChanged(InButton, bSelected);
}

void UGenericButtonGroup::NativeOnGroupButtonStyleChanged(UGenericButtonWidget* InButton)
{
	HandleOnGroupButtonStyleChanged(InButton);
}

void UGenericButtonGroup::BindButtonEvents(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		return;
	}

	FGenericButtonGroupEntry* Entry = FindButtonEntry(InButton);
	if (!Entry)
	{
		return;
	}

	FGenericButtonGroupDelegateHandles& Handles = Entry->DelegateHandles;
	Handles.OnButtonEnabledHandle = InButton->Delegate_OnButtonEnabledEvent.AddUObject(this, &ThisClass::HandleOnButtonEnabledInternal, InButton);
	Handles.OnButtonDisabledHandle = InButton->Delegate_OnButtonDisabledEvent.AddUObject(this, &ThisClass::HandleOnButtonDisabledInternal, InButton);
	Handles.OnButtonPressedHandle = InButton->Delegate_OnButtonPressedEvent.AddUObject(this, &ThisClass::HandleOnButtonPressedInternal, InButton);
	Handles.OnButtonReleasedHandle = InButton->Delegate_OnButtonReleasedEvent.AddUObject(this, &ThisClass::HandleOnButtonReleasedInternal, InButton);
	Handles.OnButtonHoveredHandle = InButton->Delegate_OnButtonHoveredEvent.AddUObject(this, &ThisClass::HandleOnButtonHoveredInternal, InButton);
	Handles.OnButtonUnhoveredHandle = InButton->Delegate_OnButtonUnhoveredEvent.AddUObject(this, &ThisClass::HandleOnButtonUnhoveredInternal, InButton);
	Handles.OnButtonClickedHandle = InButton->Delegate_OnButtonClickedEvent.AddUObject(this, &ThisClass::HandleOnButtonClickedInternal, InButton);
	Handles.OnButtonDoubleClickedHandle = InButton->Delegate_OnButtonDoubleClickedEvent.AddUObject(this, &ThisClass::HandleOnButtonDoubleClickedInternal, InButton);
	Handles.OnButtonSelectionChangedHandle = InButton->Delegate_OnButtonSelectionChangedEvent.AddUObject(this, &ThisClass::HandleOnButtonSelectionChangedInternal, InButton);
	Handles.OnButtonStyleChangedHandle = InButton->Delegate_OnButtonStyleChangedEvent.AddUObject(this, &ThisClass::HandleOnButtonStyleChangedInternal, InButton);
}

void UGenericButtonGroup::UnbindButtonEvents(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		return;
	}

	if (FGenericButtonGroupEntry* Entry = FindButtonEntry(InButton))
	{
		const FGenericButtonGroupDelegateHandles& Handles = Entry->DelegateHandles;
		InButton->Delegate_OnButtonEnabledEvent.Remove(Handles.OnButtonEnabledHandle);
		InButton->Delegate_OnButtonDisabledEvent.Remove(Handles.OnButtonDisabledHandle);
		InButton->Delegate_OnButtonPressedEvent.Remove(Handles.OnButtonPressedHandle);
		InButton->Delegate_OnButtonReleasedEvent.Remove(Handles.OnButtonReleasedHandle);
		InButton->Delegate_OnButtonHoveredEvent.Remove(Handles.OnButtonHoveredHandle);
		InButton->Delegate_OnButtonUnhoveredEvent.Remove(Handles.OnButtonUnhoveredHandle);
		InButton->Delegate_OnButtonClickedEvent.Remove(Handles.OnButtonClickedHandle);
		InButton->Delegate_OnButtonDoubleClickedEvent.Remove(Handles.OnButtonDoubleClickedHandle);
		InButton->Delegate_OnButtonSelectionChangedEvent.Remove(Handles.OnButtonSelectionChangedHandle);
		InButton->Delegate_OnButtonStyleChangedEvent.Remove(Handles.OnButtonStyleChangedHandle);
	}
}

int32 UGenericButtonGroup::FindButtonEntryIndex(UGenericButtonWidget* InButton) const
{
	if (!IsValid(InButton))
	{
		return INDEX_NONE;
	}

	for (int32 Index = 0; Index < ButtonEntries.Num(); ++Index)
	{
		if (ButtonEntries[Index].Button.Get() == InButton)
		{
			return Index;
		}
	}

	return INDEX_NONE;
}

FGenericButtonGroupEntry* UGenericButtonGroup::FindButtonEntry(UGenericButtonWidget* InButton)
{
	const int32 EntryIndex = FindButtonEntryIndex(InButton);
	return EntryIndex != INDEX_NONE ? &ButtonEntries[EntryIndex] : nullptr;
}

void UGenericButtonGroup::HandleOnButtonEnabledInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonEnabled(InButton);
}

void UGenericButtonGroup::HandleOnButtonDisabledInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonDisabled(InButton);
}

void UGenericButtonGroup::HandleOnButtonPressedInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonPressed(InButton);
}

void UGenericButtonGroup::HandleOnButtonReleasedInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonReleased(InButton);
}

void UGenericButtonGroup::HandleOnButtonHoveredInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonHovered(InButton);
}

void UGenericButtonGroup::HandleOnButtonUnhoveredInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonUnhovered(InButton);
}

void UGenericButtonGroup::HandleOnButtonClickedInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonClicked(InButton);
}

void UGenericButtonGroup::HandleOnButtonDoubleClickedInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonDoubleClicked(InButton);
}

void UGenericButtonGroup::HandleOnButtonSelectionChangedInternal(bool bSelected, UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonSelectionChanged(InButton, bSelected);
}

void UGenericButtonGroup::HandleOnButtonStyleChangedInternal(UGenericButtonWidget* InButton)
{
	NativeOnGroupButtonStyleChanged(InButton);
}
