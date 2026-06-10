// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericWindowRuntimeState.h"

#include "GenericWindowDescriptor.h"

UGenericWindowRuntimeState::UGenericWindowRuntimeState()
{
}

void UGenericWindowRuntimeState::InitializeFromDescriptor(const UGenericWindowDescriptor* InDescriptor)
{
	if (!InDescriptor)
	{
		return;
	}

	CurrentLogicalPosition = InDescriptor->InitialRect.Position;
	CurrentLogicalSize = InDescriptor->InitialRect.Size;
	CurrentVisiblePosition = InDescriptor->InitialRect.Position;
	CurrentVisibleSize = InDescriptor->InitialRect.Size;
	LastNormalPosition = InDescriptor->InitialRect.Position;
	LastNormalSize = InDescriptor->InitialRect.Size;
	CollapseRestorePosition = InDescriptor->InitialRect.Position;
	CollapseRestoreSize = InDescriptor->InitialRect.Size;
	ZOrder = InDescriptor->InitialZOrder;
	DisplayState = InDescriptor->InitialDisplayState;
	bIsOpen = false;
	bIsActive = false;
	bIsHovered = false;
	bIsDragging = false;
	bIsResizing = false;
	bIsMaximized = false;
	bHasCollapseRestoreRect = false;
	bWasMaximizedBeforeCollapse = false;
}

void UGenericWindowRuntimeState::SetLogicalRect(const FVector2D& InPosition, const FVector2D& InSize)
{
	CurrentLogicalPosition = InPosition;
	CurrentLogicalSize = InSize;
}

void UGenericWindowRuntimeState::SetVisibleRect(const FVector2D& InPosition, const FVector2D& InSize)
{
	CurrentVisiblePosition = InPosition;
	CurrentVisibleSize = InSize;
}
