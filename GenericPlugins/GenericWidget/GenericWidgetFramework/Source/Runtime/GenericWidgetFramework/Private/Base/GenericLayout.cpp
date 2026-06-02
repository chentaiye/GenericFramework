// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericLayout.h"

#include "Subsystem/GenericLayoutSubsystem.h"
#include "WidgetType.h"

FGameplayTag UGenericLayout::GetRouteTag_Implementation() const
{
	return TAG_GameplayUI_Route_Layout;
}

ULocalPlayer* UGenericLayout::GetRouteOwnerPlayer_Implementation() const
{
	return GetOwningLocalPlayer();
}

void UGenericLayout::NativeDestruct()
{
	if (!IsDesignTime())
	{
		if (UGenericLayoutSubsystem* LayoutSubsystem = UGenericLayoutSubsystem::Get(GetOwningLocalPlayer()))
		{
			if (LayoutSubsystem->GetLayout() == this)
			{
				LayoutSubsystem->UnregisterLayout(this);
			}
		}
	}

	Super::NativeDestruct();
}
