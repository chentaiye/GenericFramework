// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Group/MultiSelectionButtonGroup.h"

#include "Base/GenericButtonWidget.h"
#include "WidgetType.h"

TArray<UGenericButtonWidget*> UMultiSelectionButtonGroup::GetSelectedButtons() const
{
	TArray<UGenericButtonWidget*> Result;
	Result.Reserve(SelectedButtons.Num());

	for (UGenericButtonWidget* Button : SelectedButtons)
	{
		if (IsValid(Button))
		{
			Result.Add(Button);
		}
	}

	return Result;
}

EGenericButtonGroupSelectionMode UMultiSelectionButtonGroup::GetSelectionMode() const
{
	return EGenericButtonGroupSelectionMode::Multi;
}

bool UMultiSelectionButtonGroup::SetButtonSelected(UGenericButtonWidget* InButton, bool bInSelected)
{
	if (!IsValid(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetButtonSelected failed because button is null. Group: %s"), *GetName());
		return false;
	}

	if (!ContainsButton(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetButtonSelected failed because button '%s' is not managed by group '%s'."), *InButton->GetName(), *GetName());
		return false;
	}

	InButton->SetButtonSelected(bInSelected);
	return InButton->GetButtonSelected() == bInSelected;
}

bool UMultiSelectionButtonGroup::SetButtonSelectedByIndex(int32 InIndex, bool bInSelected)
{
	UGenericButtonWidget* Button = GetButtonByIndex(InIndex);
	if (!IsValid(Button))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetButtonSelectedByIndex failed because index %d is invalid. Group: %s"), InIndex, *GetName());
		return false;
	}

	return SetButtonSelected(Button, bInSelected);
}

void UMultiSelectionButtonGroup::AddSelectedButtons(const TArray<UGenericButtonWidget*>& InButtons)
{
	for (UGenericButtonWidget* Button : InButtons)
	{
		SetButtonSelected(Button, true);
	}
}

void UMultiSelectionButtonGroup::RemoveSelectedButtons(const TArray<UGenericButtonWidget*>& InButtons)
{
	for (UGenericButtonWidget* Button : InButtons)
	{
		SetButtonSelected(Button, false);
	}
}

void UMultiSelectionButtonGroup::DeselectAll()
{
	TArray<UGenericButtonWidget*> ButtonsToDeselect = GetSelectedButtons();
	for (UGenericButtonWidget* Button : ButtonsToDeselect)
	{
		SetButtonSelected(Button, false);
	}
}

int32 UMultiSelectionButtonGroup::GetSelectedButtonCount() const
{
	return GetSelectedButtons().Num();
}

UGenericButtonWidget* UMultiSelectionButtonGroup::GetSelectedButtonByIndex(int32 InSelectedIndex) const
{
	const TArray<UGenericButtonWidget*> CurrentSelectedButtons = GetSelectedButtons();
	return CurrentSelectedButtons.IsValidIndex(InSelectedIndex) ? CurrentSelectedButtons[InSelectedIndex] : nullptr;
}

int32 UMultiSelectionButtonGroup::FindSelectedButtonIndex(UGenericButtonWidget* InButton) const
{
	if (!IsValid(InButton))
	{
		return INDEX_NONE;
	}

	const TArray<UGenericButtonWidget*> CurrentSelectedButtons = GetSelectedButtons();
	for (int32 Index = 0; Index < CurrentSelectedButtons.Num(); ++Index)
	{
		if (CurrentSelectedButtons[Index] == InButton)
		{
			return Index;
		}
	}

	return INDEX_NONE;
}

bool UMultiSelectionButtonGroup::ContainsSelectedButton(UGenericButtonWidget* InButton) const
{
	return FindSelectedButtonIndex(InButton) != INDEX_NONE;
}

bool UMultiSelectionButtonGroup::IsFirstSelectedButton(UGenericButtonWidget* InButton) const
{
	return FindSelectedButtonIndex(InButton) == 0;
}

bool UMultiSelectionButtonGroup::IsLastSelectedButton(UGenericButtonWidget* InButton) const
{
	const int32 SelectedIndex = FindSelectedButtonIndex(InButton);
	return SelectedIndex != INDEX_NONE && SelectedIndex == GetSelectedButtonCount() - 1;
}

void UMultiSelectionButtonGroup::HandleButtonRemoved(UGenericButtonWidget* InButton)
{
	SelectedButtons.Remove(InButton);
	Super::HandleButtonRemoved(InButton);
}

void UMultiSelectionButtonGroup::NativeOnGroupButtonSelectionChanged(UGenericButtonWidget* InButton, bool bSelected)
{
	if (IsValid(InButton))
	{
		if (bSelected)
		{
			SelectedButtons.AddUnique(InButton);
		}
		else
		{
			SelectedButtons.Remove(InButton);
		}
	}

	Super::NativeOnGroupButtonSelectionChanged(InButton, bSelected);
}
