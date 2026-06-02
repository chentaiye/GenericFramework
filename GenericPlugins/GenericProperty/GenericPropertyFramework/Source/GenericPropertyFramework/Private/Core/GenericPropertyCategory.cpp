#include "Core/GenericPropertyCategory.h"

#include "Core/GenericProperty.h"

bool UGenericPropertyCategory::HasVisibleProperties() const
{
	for (const UGenericProperty* Property : Properties)
	{
		if (Property != nullptr && Property->bIsVisible)
		{
			return true;
		}
	}

	return false;
}

void UGenericPropertyCategory::RecalculateVisibility()
{
	bIsVisible = HasVisibleProperties();
}

void UGenericPropertyCategory::BroadcastListChanged()
{
	Delegate_OnListChanged.Broadcast(this);
	BPDelegate_OnListChanged.Broadcast(this);
}
