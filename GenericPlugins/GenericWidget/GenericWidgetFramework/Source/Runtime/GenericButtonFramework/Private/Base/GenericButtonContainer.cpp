// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericButtonContainer.h"

#include "Base/GenericButtonWidget.h"
#include "Components/PanelWidget.h"
#include "WidgetType.h"

bool UGenericButtonContainer::AddButton(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("AddButton failed because button is null. Container: %s"), *GetName());
		return false;
	}

	return OnButtonAdded(InButton);
}

void UGenericButtonContainer::AddButtons(const TArray<UGenericButtonWidget*>& InButtons)
{
	for (UGenericButtonWidget* Button : InButtons)
	{
		AddButton(Button);
	}
}

bool UGenericButtonContainer::RemoveButton(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RemoveButton failed because button is null. Container: %s"), *GetName());
		return false;
	}

	return OnButtonRemoved(InButton);
}

void UGenericButtonContainer::RemoveButtons(const TArray<UGenericButtonWidget*>& InButtons)
{
	for (UGenericButtonWidget* Button : InButtons)
	{
		RemoveButton(Button);
	}
}

bool UGenericButtonContainer::OnButtonAdded_Implementation(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnButtonAdded failed because button is null. Container: %s"), *GetName());
		return false;
	}

	if (!IsValid(Panel_Container))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnButtonAdded failed because Panel_Container is missing. Button: %s, Container: %s"), *InButton->GetName(), *GetName());
		return false;
	}

	if (!Panel_Container->AddChild(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnButtonAdded failed because AddChild returned null. Button: %s, Container: %s"), *InButton->GetName(), *GetName());
		return false;
	}

	return true;
}

bool UGenericButtonContainer::OnButtonRemoved_Implementation(UGenericButtonWidget* InButton)
{
	if (!IsValid(InButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnButtonRemoved failed because button is null. Container: %s"), *GetName());
		return false;
	}

	if (!IsValid(Panel_Container))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnButtonRemoved failed because Panel_Container is missing. Button: %s, Container: %s"), *InButton->GetName(), *GetName());
		return false;
	}

	if (InButton->GetParent() != Panel_Container)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnButtonRemoved failed because button '%s' is not a child of Panel_Container in container '%s'."), *InButton->GetName(), *GetName());
		return false;
	}

	InButton->RemoveFromParent();
	return true;
}
