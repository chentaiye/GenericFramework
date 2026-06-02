// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericWindowTitleBar.h"

#include "Components/Widget.h"
#include "Base/GenericButtonWidget.h"
#include "GenericWindowDescriptor.h"
#include "GenericWindowRuntimeState.h"
#include "GenericWindowWidget.h"
#include "Input/Events.h"
#include "Input/Reply.h"
#include "InputCoreTypes.h"

UGenericWindowTitleBar::UGenericWindowTitleBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericWindowTitleBar::NativeConstruct()
{
	Super::NativeConstruct();
	SynchronizeFromWindow();
}

FReply UGenericWindowTitleBar::NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UGenericWindowTitleBar::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnMouseMove(InGeometry, InMouseEvent);
}

FReply UGenericWindowTitleBar::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);
}

FReply UGenericWindowTitleBar::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return Super::NativeOnMouseButtonDoubleClick(InGeometry, InMouseEvent);
}

void UGenericWindowTitleBar::SetOwningGenericWindow_Implementation(UGenericWindowWidget* InWindowWidget)
{
	OwningGenericWindow = InWindowWidget;
	HandleOwningGenericWindowChanged(InWindowWidget);
	SynchronizeFromWindow();
}

UGenericWindowWidget* UGenericWindowTitleBar::GetOwningGenericWindow() const
{
	return OwningGenericWindow;
}

void UGenericWindowTitleBar::SynchronizeFromWindow()
{
	const UGenericWindowDescriptor* Descriptor = OwningGenericWindow ? OwningGenericWindow->GetWindowDescriptor() : nullptr;
	const bool bUsesNativeWindow = Descriptor && Descriptor->DragPolicy == EGenericWindowDragPolicy::AllowOutOfViewport;
	const bool bCanRestoreFromMaximized = OwningGenericWindow && OwningGenericWindow->IsWindowMaximized();
	const bool bIsCollapsedToTitleBar = OwningGenericWindow && OwningGenericWindow->IsWindowCollapsedToTitleBar();

	SetVisibility(ESlateVisibility::Visible);

	auto ApplyVisibility = [](UWidget* InWidget, const bool bShouldBeVisible)
	{
		if (IsValid(InWidget))
		{
			InWidget->SetVisibility(bShouldBeVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
		}
	};

	ApplyVisibility(WindowMinimizeButton, Descriptor && Descriptor->bCanMinimizeWindow && Descriptor->bShowMinimizeButton);
	ApplyVisibility(WindowMaximizeButton, Descriptor && Descriptor->bCanMaximizeWindow && Descriptor->bShowMaximizeButton);
	ApplyVisibility(WindowCloseButton, Descriptor && Descriptor->bCanCloseWindow && Descriptor->bShowCloseButton);

	if (IsValid(WindowMinimizeButton))
	{
		WindowMinimizeButton->SetButtonInteractionEnabled(bUsesNativeWindow || bCanRestoreFromMaximized);
	}

	if (IsValid(WindowExpandButton))
	{
		WindowExpandButton->SetButtonSelectable(true);
		WindowExpandButton->SetButtonToggleable(true);
		WindowExpandButton->SetButtonSelected(bIsCollapsedToTitleBar);
	}

	HandleWindowStateSynchronized();
}

UGenericButtonWidget* UGenericWindowTitleBar::GetMinimizeButtonWidget() const
{
	return WindowMinimizeButton;
}

UGenericButtonWidget* UGenericWindowTitleBar::GetMaximizeButtonWidget() const
{
	return WindowMaximizeButton;
}

UGenericButtonWidget* UGenericWindowTitleBar::GetCloseButtonWidget() const
{
	return WindowCloseButton;
}

UGenericButtonWidget* UGenericWindowTitleBar::GetExpandButtonWidget() const
{
	return WindowExpandButton;
}

bool UGenericWindowTitleBar::IsOverControlButton(const FVector2D& InScreenSpacePosition) const
{
	const auto IsWidgetHit = [&InScreenSpacePosition](const UWidget* InWidget) -> bool
	{
		if (!IsValid(InWidget))
		{
			return false;
		}

		const ESlateVisibility Visibility = InWidget->GetVisibility();
		if (Visibility == ESlateVisibility::Collapsed || Visibility == ESlateVisibility::Hidden)
		{
			return false;
		}

		const FGeometry& CachedGeometry = InWidget->GetCachedGeometry();
		return CachedGeometry.GetLocalSize().X > 0.0f
			&& CachedGeometry.GetLocalSize().Y > 0.0f
			&& CachedGeometry.IsUnderLocation(InScreenSpacePosition);
	};

	return IsWidgetHit(WindowMinimizeButton)
		|| IsWidgetHit(WindowMaximizeButton)
		|| IsWidgetHit(WindowCloseButton)
		|| IsWidgetHit(WindowExpandButton);
}

EGenericWindowResizeHandle UGenericWindowTitleBar::DetectResizeHandle(const FGeometry& InGeometry, const FVector2D& InScreenSpacePosition) const
{
	(void)InGeometry;
	(void)InScreenSpacePosition;
	return EGenericWindowResizeHandle::None;
}
