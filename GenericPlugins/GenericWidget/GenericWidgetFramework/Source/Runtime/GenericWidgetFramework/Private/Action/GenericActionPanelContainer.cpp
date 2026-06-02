// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Action/GenericActionPanelContainer.h"

#include "Base/GenericWidget.h"
#include "Components/PanelWidget.h"
#include "WidgetType.h"

bool UGenericActionPanelContainer::OnWidgetAdded_Implementation(UGenericWidget* InWidget)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetAdded failed because widget is null. Container: %s"), *GetName());
		return false;
	}

	if (!IsValid(Panel_Container))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetAdded failed because Panel_Container is missing. Widget: %s, Container: %s"), *InWidget->GetName(), *GetName());
		return false;
	}

	if (!Panel_Container->AddChild(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetAdded failed because AddChild returned null. Widget: %s, Container: %s"), *InWidget->GetName(), *GetName());
		return false;
	}

	return true;
}

bool UGenericActionPanelContainer::OnWidgetRemoved_Implementation(UGenericWidget* InWidget)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetRemoved failed because widget is null. Container: %s"), *GetName());
		return false;
	}

	if (!IsValid(Panel_Container))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetRemoved failed because Panel_Container is missing. Widget: %s, Container: %s"), *InWidget->GetName(), *GetName());
		return false;
	}

	if (InWidget->GetParent() != Panel_Container)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetRemoved failed because widget '%s' is not a child of Panel_Container in container '%s'."), *InWidget->GetName(), *GetName());
		return false;
	}

	InWidget->RemoveFromParent();
	return true;
}

void UGenericActionPanelContainer::RefreshActiveWidgetByIndex(int32 InActiveIndex)
{
	for (int32 Index = 0; Index < GetWidgetCount(); ++Index)
	{
		if (UGenericWidget* Widget = GetWidgetByIndex(Index))
		{
			Widget->SetVisibility(Index == InActiveIndex ? ActiveVisibility : InactiveVisibility);
		}
	}
}
