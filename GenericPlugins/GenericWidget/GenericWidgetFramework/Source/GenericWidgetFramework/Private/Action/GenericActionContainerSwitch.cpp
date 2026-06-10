// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Action/GenericActionContainerSwitch.h"

#include "Base/GenericWidget.h"
#include "Components/WidgetSwitcher.h"
#include "WidgetType.h"

bool UGenericActionContainerSwitch::SetActiveWidgetIndex(int32 InIndex)
{
	if (!GetWidgetByIndex(InIndex))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetActiveWidgetIndex failed because index %d is invalid. Container: %s"), InIndex, *GetName());
		return false;
	}

	if (!IsValid(Switcher_Container))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetActiveWidgetIndex failed because Switcher_Container is missing. Container: %s"), *GetName());
		return false;
	}

	ActiveWidgetIndex = InIndex;
	Switcher_Container->SetActiveWidgetIndex(ActiveWidgetIndex);
	return true;
}

int32 UGenericActionContainerSwitch::GetActiveWidgetIndex() const
{
	return ActiveWidgetIndex;
}

UGenericWidget* UGenericActionContainerSwitch::GetActiveWidget() const
{
	return GetWidgetByIndex(ActiveWidgetIndex);
}

bool UGenericActionContainerSwitch::SelectPreviousWidget()
{
	const int32 WidgetCount = GetWidgetCount();
	if (WidgetCount <= 0 || ActiveWidgetIndex == INDEX_NONE)
	{
		return false;
	}

	if (ActiveWidgetIndex > 0)
	{
		return SetActiveWidgetIndex(ActiveWidgetIndex - 1);
	}

	return bLoopSelection ? SetActiveWidgetIndex(WidgetCount - 1) : false;
}

bool UGenericActionContainerSwitch::SelectNextWidget()
{
	const int32 WidgetCount = GetWidgetCount();
	if (WidgetCount <= 0 || ActiveWidgetIndex == INDEX_NONE)
	{
		return false;
	}

	if (ActiveWidgetIndex < WidgetCount - 1)
	{
		return SetActiveWidgetIndex(ActiveWidgetIndex + 1);
	}

	return bLoopSelection ? SetActiveWidgetIndex(0) : false;
}

bool UGenericActionContainerSwitch::OnWidgetAdded_Implementation(UGenericWidget* InWidget)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetAdded failed because widget is null. Container: %s"), *GetName());
		return false;
	}

	if (!IsValid(Switcher_Container))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetAdded failed because Switcher_Container is missing. Widget: %s, Container: %s"), *InWidget->GetName(), *GetName());
		return false;
	}

	if (!Switcher_Container->AddChild(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetAdded failed because AddChild returned null. Widget: %s, Container: %s"), *InWidget->GetName(), *GetName());
		return false;
	}

	return true;
}

bool UGenericActionContainerSwitch::OnWidgetRemoved_Implementation(UGenericWidget* InWidget)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetRemoved failed because widget is null. Container: %s"), *GetName());
		return false;
	}

	if (!IsValid(Switcher_Container))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetRemoved failed because Switcher_Container is missing. Widget: %s, Container: %s"), *InWidget->GetName(), *GetName());
		return false;
	}

	if (InWidget->GetParent() != Switcher_Container)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("OnWidgetRemoved failed because widget '%s' is not a child of Switcher_Container in container '%s'."), *InWidget->GetName(), *GetName());
		return false;
	}

	InWidget->RemoveFromParent();
	return true;
}

void UGenericActionContainerSwitch::RefreshContainerState()
{
	const int32 WidgetCount = GetWidgetCount();
	if (WidgetCount <= 0)
	{
		ActiveWidgetIndex = INDEX_NONE;
		return;
	}

	if (!GetWidgetByIndex(ActiveWidgetIndex))
	{
		ActiveWidgetIndex = FMath::Clamp(ActiveWidgetIndex, 0, WidgetCount - 1);
	}

	if (IsValid(Switcher_Container))
	{
		Switcher_Container->SetActiveWidgetIndex(ActiveWidgetIndex);
	}
}
