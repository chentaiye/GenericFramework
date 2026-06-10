// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Action/GenericActionContainerQueue.h"

#include "Base/GenericWidget.h"

bool UGenericActionContainerQueue::EnqueueWidget(UGenericWidget* InWidget)
{
	return AddWidgetInternal(InWidget);
}

UGenericWidget* UGenericActionContainerQueue::DequeueWidget()
{
	UGenericWidget* FrontWidget = PeekWidget();
	if (!IsValid(FrontWidget))
	{
		return nullptr;
	}

	return RemoveWidgetInternal(FrontWidget) ? FrontWidget : nullptr;
}

UGenericWidget* UGenericActionContainerQueue::PeekWidget() const
{
	return GetWidgetByIndex(GetFrontWidgetIndex());
}

int32 UGenericActionContainerQueue::GetFrontWidgetIndex() const
{
	return GetWidgetCount() > 0 ? 0 : INDEX_NONE;
}

void UGenericActionContainerQueue::RefreshContainerState()
{
	RefreshActiveWidgetByIndex(GetFrontWidgetIndex());
}
