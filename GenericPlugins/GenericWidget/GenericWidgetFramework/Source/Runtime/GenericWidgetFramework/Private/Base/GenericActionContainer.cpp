// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericActionContainer.h"

#include "Base/GenericWidget.h"
#include "WidgetType.h"

bool UGenericActionContainer::AddWidget(UGenericWidget* InWidget)
{
	return AddWidgetInternal(InWidget);
}

bool UGenericActionContainer::RemoveWidget(UGenericWidget* InWidget)
{
	return RemoveWidgetInternal(InWidget);
}

bool UGenericActionContainer::RemoveWidgetByIndex(int32 InIndex)
{
	UGenericWidget* Widget = GetWidgetByIndex(InIndex);
	if (!IsValid(Widget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RemoveWidgetByIndex failed because index %d is invalid. Container: %s"), InIndex, *GetName());
		return false;
	}

	return RemoveWidgetInternal(Widget);
}

void UGenericActionContainer::ClearWidgets()
{
	TArray<UGenericWidget*> WidgetsToRemove = GetWidgets();
	for (UGenericWidget* Widget : WidgetsToRemove)
	{
		RemoveWidgetInternal(Widget);
	}
}

TArray<UGenericWidget*> UGenericActionContainer::GetWidgets() const
{
	TArray<UGenericWidget*> Result;
	Result.Reserve(Widgets.Num());

	for (UGenericWidget* Widget : Widgets)
	{
		if (IsValid(Widget))
		{
			Result.Add(Widget);
		}
	}

	return Result;
}

int32 UGenericActionContainer::GetWidgetCount() const
{
	return Widgets.Num();
}

UGenericWidget* UGenericActionContainer::GetWidgetByIndex(int32 InIndex) const
{
	return Widgets.IsValidIndex(InIndex) ? Widgets[InIndex].Get() : nullptr;
}

int32 UGenericActionContainer::FindWidgetIndex(UGenericWidget* InWidget) const
{
	if (!IsValid(InWidget))
	{
		return INDEX_NONE;
	}

	for (int32 Index = 0; Index < Widgets.Num(); ++Index)
	{
		if (Widgets[Index].Get() == InWidget)
		{
			return Index;
		}
	}

	return INDEX_NONE;
}

bool UGenericActionContainer::ContainsWidget(UGenericWidget* InWidget) const
{
	return FindWidgetIndex(InWidget) != INDEX_NONE;
}

bool UGenericActionContainer::AddWidgetInternal(UGenericWidget* InWidget)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("AddWidget failed because widget is null. Container: %s"), *GetName());
		return false;
	}

	if (ContainsWidget(InWidget))
	{
		return true;
	}

	if (!OnWidgetAdded(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("AddWidget failed because OnWidgetAdded returned false. Widget: %s, Container: %s"), *InWidget->GetName(), *GetName());
		return false;
	}

	Widgets.Add(InWidget);
	RefreshContainerState();
	return true;
}

bool UGenericActionContainer::RemoveWidgetInternal(UGenericWidget* InWidget)
{
	if (!IsValid(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RemoveWidget failed because widget is null. Container: %s"), *GetName());
		return false;
	}

	const int32 WidgetIndex = FindWidgetIndex(InWidget);
	if (WidgetIndex == INDEX_NONE)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RemoveWidget failed because widget '%s' is not tracked by container '%s'."), *InWidget->GetName(), *GetName());
		return false;
	}

	if (!OnWidgetRemoved(InWidget))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RemoveWidget failed because OnWidgetRemoved returned false. Widget: %s, Container: %s"), *InWidget->GetName(), *GetName());
		return false;
	}

	Widgets.RemoveAt(WidgetIndex);
	RefreshContainerState();
	return true;
}

void UGenericActionContainer::RefreshContainerState()
{
}

bool UGenericActionContainer::OnWidgetAdded_Implementation(UGenericWidget* InWidget)
{
	return true;
}

bool UGenericActionContainer::OnWidgetRemoved_Implementation(UGenericWidget* InWidget)
{
	return true;
}
