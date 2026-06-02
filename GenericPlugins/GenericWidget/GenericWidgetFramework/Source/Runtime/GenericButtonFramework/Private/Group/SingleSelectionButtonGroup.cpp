// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Group/SingleSelectionButtonGroup.h"

#include "Base/GenericButtonWidget.h"
#include "WidgetType.h"

UGenericButtonWidget* USingleSelectionButtonGroup::GetPreviousSelectedButton() const
{
	return PreviousSelectedButton;
}

UGenericButtonWidget* USingleSelectionButtonGroup::GetCurrentSelectedButton() const
{
	return CurrentSelectedButton;
}

bool USingleSelectionButtonGroup::SetSelectedButton(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSelectedButton failed because button is null. Group: %s"), *GetName());
		return false;
	}

	if (!ContainsButton(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSelectedButton failed because button '%s' is not managed by group '%s'."), *InButton->GetName(), *GetName());
		return false;
	}

	InButton->SetButtonSelected(true);
	return InButton->GetButtonSelected();
}

bool USingleSelectionButtonGroup::SetSelectedButtonByIndex(int32 InIndex)
{
	UGenericButtonWidget* Button = GetButtonByIndex(InIndex);
	if (!IsValid(Button))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSelectedButtonByIndex failed because index %d is invalid. Group: %s"), InIndex, *GetName());
		return false;
	}

	return SetSelectedButton(Button);
}

bool USingleSelectionButtonGroup::SetSelectedButtonByTag(FGameplayTag InButtonTag)
{
	if (!InButtonTag.IsValid())
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSelectedButtonByTag failed because button tag is invalid. Group: %s"), *GetName());
		return false;
	}

	UGenericButtonWidget* MatchedButton = nullptr;
	int32 MatchCount = 0;
	for (int32 Index = 0; Index < GetButtonCount(); ++Index)
	{
		UGenericButtonWidget* Button = GetButtonByIndex(Index);
		if (IsValid(Button) && Button->GetButtonTag() == InButtonTag)
		{
			MatchedButton = Button;
			++MatchCount;
		}
	}

	if (MatchCount == 0)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSelectedButtonByTag failed because button tag '%s' is not managed by group '%s'."), *InButtonTag.ToString(), *GetName());
		return false;
	}

	if (MatchCount > 1)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSelectedButtonByTag failed because button tag '%s' is duplicated in group '%s'."), *InButtonTag.ToString(), *GetName());
		return false;
	}

	return SetSelectedButton(MatchedButton);
}

FGameplayTag USingleSelectionButtonGroup::GetSelectedButtonTag() const
{
	return IsValid(CurrentSelectedButton) ? CurrentSelectedButton->GetButtonTag() : FGameplayTag();
}

EGenericButtonGroupSelectionMode USingleSelectionButtonGroup::GetSelectionMode() const
{
	return EGenericButtonGroupSelectionMode::Single;
}

bool USingleSelectionButtonGroup::SelectPreviousButton()
{
	const int32 CurrentIndex = FindButtonIndex(CurrentSelectedButton);
	if (CurrentIndex == INDEX_NONE || CurrentIndex <= 0)
	{
		return false;
	}

	return SetSelectedButtonByIndex(CurrentIndex - 1);
}

bool USingleSelectionButtonGroup::SelectNextButton()
{
	const int32 CurrentIndex = FindButtonIndex(CurrentSelectedButton);
	if (CurrentIndex == INDEX_NONE || CurrentIndex >= GetButtonCount() - 1)
	{
		return false;
	}

	return SetSelectedButtonByIndex(CurrentIndex + 1);
}

void USingleSelectionButtonGroup::DeselectAll()
{
	if (IsValid(CurrentSelectedButton))
	{
		CurrentSelectedButton->SetButtonSelected(false);
		return;
	}

	PreviousSelectedButton = nullptr;
	CurrentSelectedButton = nullptr;
}

void USingleSelectionButtonGroup::HandleButtonRemoved(UGenericButtonWidget* InButton)
{
	if (PreviousSelectedButton.Get() == InButton)
	{
		PreviousSelectedButton = nullptr;
	}

	if (CurrentSelectedButton.Get() == InButton)
	{
		CurrentSelectedButton = nullptr;
	}

	Super::HandleButtonRemoved(InButton);
}

void USingleSelectionButtonGroup::NativeOnGroupButtonSelectionChanged(UGenericButtonWidget* InButton, bool bSelected)
{
	if (IsValid(InButton))
	{
		if (bSelected)
		{
			PreviousSelectedButton = CurrentSelectedButton;
			CurrentSelectedButton = InButton;

			if (IsValid(PreviousSelectedButton) && PreviousSelectedButton != CurrentSelectedButton)
			{
				PreviousSelectedButton->SetButtonSelected(false);
			}
		}
		else if (CurrentSelectedButton.Get() == InButton)
		{
			PreviousSelectedButton = CurrentSelectedButton;
			CurrentSelectedButton = nullptr;
		}
	}

	Super::NativeOnGroupButtonSelectionChanged(InButton, bSelected);
}
