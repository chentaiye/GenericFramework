// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericWindowSlot.h"

#include "GenericWindowAnchor.h"

void UGenericWindowSlot::SetWindowAnchor(const FVector2D& InWindowAnchor)
{
	WindowAnchor = FVector2D(
		FMath::Clamp(InWindowAnchor.X, 0.0f, 1.0f),
		FMath::Clamp(InWindowAnchor.Y, 0.0f, 1.0f));

	if (UGenericWindowAnchor* WindowAnchorWidget = Cast<UGenericWindowAnchor>(Parent))
	{
		WindowAnchorWidget->RefreshHostedWindowLayout();
	}
}

FVector2D UGenericWindowSlot::GetWindowAnchor() const
{
	return GetClampedWindowAnchor();
}

FVector2D UGenericWindowSlot::GetClampedWindowAnchor() const
{
	return FVector2D(
		FMath::Clamp(WindowAnchor.X, 0.0f, 1.0f),
		FMath::Clamp(WindowAnchor.Y, 0.0f, 1.0f));
}
