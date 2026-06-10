// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Action/GenericActionContainerStack.h"

#include "Base/GenericWidget.h"

bool UGenericActionContainerStack::PushWidget(UGenericWidget* InWidget)
{
	return AddWidgetInternal(InWidget);
}

UGenericWidget* UGenericActionContainerStack::PopWidget()
{
	UGenericWidget* TopWidget = PeekWidget();
	if (!IsValid(TopWidget))
	{
		return nullptr;
	}

	return RemoveWidgetInternal(TopWidget) ? TopWidget : nullptr;
}

UGenericWidget* UGenericActionContainerStack::PeekWidget() const
{
	return GetWidgetByIndex(GetTopWidgetIndex());
}

int32 UGenericActionContainerStack::GetTopWidgetIndex() const
{
	return GetWidgetCount() > 0 ? GetWidgetCount() - 1 : INDEX_NONE;
}

void UGenericActionContainerStack::RefreshContainerState()
{
	RefreshActiveWidgetByIndex(GetTopWidgetIndex());
}
