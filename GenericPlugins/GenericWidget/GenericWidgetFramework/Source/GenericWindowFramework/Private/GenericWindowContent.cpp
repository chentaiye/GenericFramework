// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericWindowContent.h"

#include "GenericWindowDescriptor.h"
#include "GenericWindowRuntimeState.h"
#include "GenericWindowWidget.h"
#include "Input/Events.h"
#include "Input/Reply.h"
#include "InputCoreTypes.h"

UGenericWindowContent::UGenericWindowContent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericWindowContent::NativeConstruct()
{
	Super::NativeConstruct();
	SynchronizeFromWindow();
}

FReply UGenericWindowContent::NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UGenericWindowContent::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnMouseMove(InGeometry, InMouseEvent);
}

FReply UGenericWindowContent::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);
}

void UGenericWindowContent::SetOwningGenericWindow_Implementation(UGenericWindowWidget* InWindowWidget)
{
	OwningGenericWindow = InWindowWidget;
	HandleOwningGenericWindowChanged(InWindowWidget);
	SynchronizeFromWindow();
}

UGenericWindowWidget* UGenericWindowContent::GetOwningGenericWindow() const
{
	return OwningGenericWindow;
}

void UGenericWindowContent::SynchronizeFromWindow()
{
	SetVisibility(ESlateVisibility::Visible);
	HandleWindowStateSynchronized();
}

EGenericWindowResizeHandle UGenericWindowContent::DetectResizeHandle(const FGeometry& InGeometry, const FVector2D& InScreenSpacePosition) const
{
	(void)InGeometry;
	(void)InScreenSpacePosition;
	return EGenericWindowResizeHandle::None;
}
