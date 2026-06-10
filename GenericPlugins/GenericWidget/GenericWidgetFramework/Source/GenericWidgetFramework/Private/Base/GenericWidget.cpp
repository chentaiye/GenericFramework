// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericWidget.h"

#include "WidgetType.h"

FGameplayTag UGenericWidget::GetRouteTag_Implementation() const
{
	return TAG_GameplayUI_Route_Widget;
}

ULocalPlayer* UGenericWidget::GetRouteOwnerPlayer_Implementation() const
{
	return GetOwningLocalPlayer();
}
