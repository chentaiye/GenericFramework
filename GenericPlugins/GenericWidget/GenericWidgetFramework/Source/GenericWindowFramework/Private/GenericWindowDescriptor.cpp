// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericWindowDescriptor.h"

#if WITH_EDITOR
#include "GenericWindowWidget.h"
#endif

UGenericWindowDescriptor::UGenericWindowDescriptor()
{
}

#if WITH_EDITOR
void UGenericWindowDescriptor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (UGenericWindowWidget* WindowWidget = GetTypedOuter<UGenericWindowWidget>())
	{
		WindowWidget->HandleWindowDescriptorChanged();
	}
}

void UGenericWindowDescriptor::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	Super::PostEditChangeChainProperty(PropertyChangedEvent);

	if (UGenericWindowWidget* WindowWidget = GetTypedOuter<UGenericWindowWidget>())
	{
		WindowWidget->HandleWindowDescriptorChanged();
	}
}
#endif
