// Copyright ChenTaiye 2025. All Rights Reserved.

#include "SGenericWindowFrame.h"

#include "Components/Widget.h"
#include "Base/GenericButtonWidget.h"
#include "GenericWindowDescriptor.h"
#include "GenericWindowRuntimeState.h"
#include "GenericWindowTitleBar.h"
#include "GenericWindowWidget.h"
#include "Input/CursorReply.h"
#include "InputCoreTypes.h"
#include "Styling/StyleDefaults.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"

void SGenericWindowFrame::Construct(const FArguments& InArgs)
{
	OwnerWindowWidget = InArgs._OwnerWindowWidget;

	SAssignNew(TitleBarBox, SBox);
	SAssignNew(WindowContentBox, SBox);

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SAssignNew(TitleBarRegionBox, SBox)
			[
				SNew(SBorder)
				.BorderImage(FStyleDefaults::GetNoBrush())
				.Padding(TAttribute<FMargin>::CreateLambda([this]()
				{
					if (const UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get())
					{
						if (const UGenericWindowDescriptor* Descriptor = WindowWidget->GetWindowDescriptor())
						{
							return Descriptor->TitleBarPadding;
						}
					}

					return FMargin(8.0f, 6.0f);
				}))
				[
					TitleBarBox.ToSharedRef()
				]
			]
		]
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SNew(SBox)
			.Visibility(this, &SGenericWindowFrame::GetClientAreaVisibility)
			[
				SNew(SBorder)
				.BorderImage(FStyleDefaults::GetNoBrush())
				.Padding(TAttribute<FMargin>::CreateLambda([this]()
				{
					if (const UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get())
					{
						if (const UGenericWindowDescriptor* Descriptor = WindowWidget->GetWindowDescriptor())
						{
							return Descriptor->ClientAreaPadding;
						}
					}

					return FMargin(8.0f);
				}))
				[
					WindowContentBox.ToSharedRef()
				]
			]
		]
	];

	RefreshFromOwner();
}

void SGenericWindowFrame::RefreshFromOwner()
{
	UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get();
	if (!WindowWidget)
	{
		return;
	}

	TitleBarBox->SetContent(WindowWidget->BuildWindowTitleBarWidget());
	WindowContentBox->SetContent(WindowWidget->BuildWindowContentWidget());
}

float SGenericWindowFrame::GetMeasuredTitleBarHeight() const
{
	if (TitleBarRegionBox.IsValid())
	{
		const float CachedHeight = TitleBarRegionBox->GetCachedGeometry().GetLocalSize().Y;
		if (CachedHeight > 0.0f)
		{
			return CachedHeight;
		}

		const float DesiredHeight = TitleBarRegionBox->GetDesiredSize().Y;
		if (DesiredHeight > 0.0f)
		{
			return DesiredHeight;
		}
	}

	return 0.0f;
}

FReply SGenericWindowFrame::TryBeginWindowInteraction(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get();
	if (!WindowWidget || MouseEvent.GetEffectingButton() != EKeys::LeftMouseButton)
	{
		return FReply::Unhandled();
	}

	if (bIsDragging || bIsResizing)
	{
		return FReply::Handled();
	}

	const UGenericWindowDescriptor* Descriptor = WindowWidget->GetWindowDescriptor();
	const UGenericWindowRuntimeState* RuntimeState = WindowWidget->GetWindowRuntimeState();
	if (!Descriptor || !RuntimeState)
	{
		return FReply::Unhandled();
	}

	if (IsOverTitleBarButton(MouseEvent.GetScreenSpacePosition()))
	{
		return FReply::Unhandled();
	}

	const FVector2D ScreenMousePosition = MouseEvent.GetScreenSpacePosition();
	FVector2D HostMousePosition = ScreenMousePosition;
	const bool bUseHostCoordinates = WindowWidget->TryConvertScreenToWindowHostPosition(ScreenMousePosition, HostMousePosition);

	const EGenericWindowResizeHandle DetectedHandle = DetectResizeHandle(MyGeometry, MouseEvent.GetScreenSpacePosition());
	if (Descriptor->bCanResizeWindow && DetectedHandle != EGenericWindowResizeHandle::None)
	{
		if (Descriptor->bAutoBringToFrontOnActivate)
		{
			WindowWidget->BringToFront();
		}

		InteractionStartHostPosition = HostMousePosition;
		InteractionPreviousHostPosition = HostMousePosition;
		InteractionStartFallbackScreenPosition = ScreenMousePosition;
		InteractionPreviousFallbackScreenPosition = ScreenMousePosition;
		InteractionStartWindowPosition = RuntimeState->CurrentLogicalPosition;
		InteractionStartWindowSize = RuntimeState->CurrentLogicalSize;
		bInteractionUsesHostCoordinates = bUseHostCoordinates;
		bIsResizing = true;
		ActiveResizeHandle = DetectedHandle;
		WindowWidget->NotifyInteractionStarted(true);
		return FReply::Handled()
			.CaptureMouse(SharedThis(this))
			.SetUserFocus(SharedThis(this), EFocusCause::Mouse)
			.PreventThrottling();
	}

	const bool bIsWithinTitleBar = IsWithinTitleBar(MyGeometry, MouseEvent.GetScreenSpacePosition());
	if (bIsWithinTitleBar && Descriptor->bCanDragWindow && !RuntimeState->bIsMaximized)
	{
		if (Descriptor->bAutoBringToFrontOnActivate)
		{
			WindowWidget->BringToFront();
		}

		InteractionStartHostPosition = HostMousePosition;
		InteractionPreviousHostPosition = HostMousePosition;
		InteractionStartFallbackScreenPosition = ScreenMousePosition;
		InteractionPreviousFallbackScreenPosition = ScreenMousePosition;
		InteractionStartWindowPosition = RuntimeState->CurrentLogicalPosition;
		InteractionStartWindowSize = RuntimeState->CurrentLogicalSize;
		bInteractionUsesHostCoordinates = bUseHostCoordinates;
		bIsDragging = true;
		WindowWidget->NotifyInteractionStarted(false);
		return FReply::Handled()
			.CaptureMouse(SharedThis(this))
			.SetUserFocus(SharedThis(this), EFocusCause::Mouse)
			.PreventThrottling();
	}

	if (bIsWithinTitleBar)
	{
		if (Descriptor->bAutoBringToFrontOnActivate)
		{
			WindowWidget->BringToFront();
		}

		return FReply::Handled()
			.SetUserFocus(SharedThis(this), EFocusCause::Mouse)
			.PreventThrottling();
	}

	return FReply::Unhandled();
}

FReply SGenericWindowFrame::OnPreviewMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return TryBeginWindowInteraction(MyGeometry, MouseEvent);
}

FReply SGenericWindowFrame::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return TryBeginWindowInteraction(MyGeometry, MouseEvent);
}

FReply SGenericWindowFrame::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() != EKeys::LeftMouseButton)
	{
		return FReply::Unhandled();
	}

	if (bIsDragging || bIsResizing)
	{
		bIsDragging = false;
		bIsResizing = false;
		bInteractionUsesHostCoordinates = false;
		ActiveResizeHandle = EGenericWindowResizeHandle::None;

		if (UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get())
		{
			WindowWidget->NotifyInteractionEnded();
		}

		return FReply::Handled().ReleaseMouseCapture();
	}

	return FReply::Unhandled();
}

FReply SGenericWindowFrame::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get();
	if (!WindowWidget)
	{
		return FReply::Unhandled();
	}

	if (bIsDragging || bIsResizing)
	{
		const FVector2D ScreenMousePosition = MouseEvent.GetScreenSpacePosition();
		FVector2D HostMousePosition = ScreenMousePosition;
		if (bInteractionUsesHostCoordinates)
		{
			if (!WindowWidget->TryConvertScreenToWindowHostPosition(ScreenMousePosition, HostMousePosition))
			{
				HostMousePosition = InteractionPreviousHostPosition + (ScreenMousePosition - InteractionPreviousFallbackScreenPosition);
			}
		}
		const FVector2D Delta = HostMousePosition - InteractionStartHostPosition;
		const FVector2D IncrementalDelta = HostMousePosition - InteractionPreviousHostPosition;

		if (bIsDragging)
		{
			if (const UGenericWindowRuntimeState* RuntimeState = WindowWidget->GetWindowRuntimeState())
			{
				WindowWidget->RequestWindowMove(RuntimeState->CurrentLogicalPosition + IncrementalDelta);
			}
		}
		else if (bIsResizing)
		{
			WindowWidget->RequestWindowResize(ActiveResizeHandle, InteractionStartWindowPosition, InteractionStartWindowSize, Delta);
		}

		InteractionPreviousHostPosition = HostMousePosition;
		InteractionPreviousFallbackScreenPosition = ScreenMousePosition;

		return FReply::Handled().PreventThrottling();
	}

	HoveredResizeHandle = IsOverTitleBarButton(MouseEvent.GetScreenSpacePosition())
		? EGenericWindowResizeHandle::None
		: DetectResizeHandle(MyGeometry, MouseEvent.GetScreenSpacePosition());
	return FReply::Unhandled();
}

void SGenericWindowFrame::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	SCompoundWidget::OnMouseLeave(MouseEvent);
	HoveredResizeHandle = EGenericWindowResizeHandle::None;
}

FReply SGenericWindowFrame::OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent)
{
	UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get();
	if (!WindowWidget || InMouseEvent.GetEffectingButton() != EKeys::LeftMouseButton)
	{
		return FReply::Unhandled();
	}

		if (const UGenericWindowDescriptor* Descriptor = WindowWidget->GetWindowDescriptor())
		{
			if (Descriptor->bDoubleClickTitleBarToToggleMaximize
				&& IsWithinTitleBar(InMyGeometry, InMouseEvent.GetScreenSpacePosition())
				&& !IsOverTitleBarButton(InMouseEvent.GetScreenSpacePosition()))
			{
				WindowWidget->ToggleWindowMaximize();
				return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

void SGenericWindowFrame::OnMouseCaptureLost(const FCaptureLostEvent& CaptureLostEvent)
{
	SCompoundWidget::OnMouseCaptureLost(CaptureLostEvent);

	bIsDragging = false;
	bIsResizing = false;
	bInteractionUsesHostCoordinates = false;
	ActiveResizeHandle = EGenericWindowResizeHandle::None;

	if (UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get())
	{
		WindowWidget->NotifyInteractionEnded();
	}
}

FCursorReply SGenericWindowFrame::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	if (const UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get())
	{
		if (const UGenericWindowDescriptor* Descriptor = WindowWidget->GetWindowDescriptor())
		{
			if (Descriptor->bCanResizeWindow && !IsOverTitleBarButton(CursorEvent.GetScreenSpacePosition()))
			{
				switch (DetectResizeHandle(MyGeometry, CursorEvent.GetScreenSpacePosition()))
				{
				case EGenericWindowResizeHandle::Left:
				case EGenericWindowResizeHandle::Right:
					return FCursorReply::Cursor(EMouseCursor::ResizeLeftRight);
				case EGenericWindowResizeHandle::Top:
				case EGenericWindowResizeHandle::Bottom:
					return FCursorReply::Cursor(EMouseCursor::ResizeUpDown);
				case EGenericWindowResizeHandle::TopLeft:
				case EGenericWindowResizeHandle::BottomRight:
					return FCursorReply::Cursor(EMouseCursor::ResizeSouthEast);
				case EGenericWindowResizeHandle::TopRight:
				case EGenericWindowResizeHandle::BottomLeft:
					return FCursorReply::Cursor(EMouseCursor::ResizeSouthWest);
				default:
					break;
				}
			}
		}
	}

	return SCompoundWidget::OnCursorQuery(MyGeometry, CursorEvent);
}

EGenericWindowResizeHandle SGenericWindowFrame::DetectResizeHandle(const FGeometry& MyGeometry, const FVector2D& ScreenSpacePosition) const
{
	const UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get();
	const UGenericWindowDescriptor* Descriptor = WindowWidget ? WindowWidget->GetWindowDescriptor() : nullptr;
	if (!Descriptor || !Descriptor->bCanResizeWindow)
	{
		return EGenericWindowResizeHandle::None;
	}

	const FVector2D LocalPosition = MyGeometry.AbsoluteToLocal(ScreenSpacePosition);
	const FVector2D LocalSize = MyGeometry.GetLocalSize();
	const float BorderThickness = FMath::Max(Descriptor->ResizeBorderThickness, 0.0f);
	if (BorderThickness <= 0.0f
		|| LocalSize.X <= 0.0f
		|| LocalSize.Y <= 0.0f
		|| LocalPosition.X < 0.0f
		|| LocalPosition.Y < 0.0f
		|| LocalPosition.X > LocalSize.X
		|| LocalPosition.Y > LocalSize.Y)
	{
		return EGenericWindowResizeHandle::None;
	}

	const bool bLeft = LocalPosition.X <= BorderThickness;
	const bool bRight = LocalPosition.X >= LocalSize.X - BorderThickness;
	const bool bTop = LocalPosition.Y <= BorderThickness;
	const bool bBottom = LocalPosition.Y >= LocalSize.Y - BorderThickness;

	if (bLeft && bTop)
	{
		return EGenericWindowResizeHandle::TopLeft;
	}
	if (bRight && bTop)
	{
		return EGenericWindowResizeHandle::TopRight;
	}
	if (bLeft && bBottom)
	{
		return EGenericWindowResizeHandle::BottomLeft;
	}
	if (bRight && bBottom)
	{
		return EGenericWindowResizeHandle::BottomRight;
	}
	if (bLeft)
	{
		return EGenericWindowResizeHandle::Left;
	}
	if (bRight)
	{
		return EGenericWindowResizeHandle::Right;
	}
	if (bTop)
	{
		return EGenericWindowResizeHandle::Top;
	}
	if (bBottom)
	{
		return EGenericWindowResizeHandle::Bottom;
	}

	return EGenericWindowResizeHandle::None;
}

bool SGenericWindowFrame::IsWithinTitleBar(const FGeometry& MyGeometry, const FVector2D& ScreenSpacePosition) const
{
	if (TitleBarRegionBox.IsValid())
	{
		const FGeometry& TitleBarGeometry = TitleBarRegionBox->GetCachedGeometry();
		const FVector2D TitleBarSize = TitleBarGeometry.GetLocalSize();
		if (TitleBarSize.X > 0.0f && TitleBarSize.Y > 0.0f)
		{
			return TitleBarGeometry.IsUnderLocation(ScreenSpacePosition);
		}
	}

	const FVector2D LocalPosition = MyGeometry.AbsoluteToLocal(ScreenSpacePosition);
	const FVector2D LocalSize = MyGeometry.GetLocalSize();
	return LocalPosition.X >= 0.0f
		&& LocalPosition.X <= LocalSize.X
		&& LocalPosition.Y >= 0.0f
		&& LocalPosition.Y <= GetMeasuredTitleBarHeight();
}

bool SGenericWindowFrame::IsOverTitleBarButton(const FVector2D& ScreenSpacePosition) const
{
	const UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get();
	const UGenericWindowTitleBar* TitleBarWidget = WindowWidget ? WindowWidget->GetWindowTitleBarWidget() : nullptr;
	if (!TitleBarWidget)
	{
		return false;
	}

	const auto IsWidgetHit = [&ScreenSpacePosition](const UWidget* InWidget) -> bool
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
			&& CachedGeometry.IsUnderLocation(ScreenSpacePosition);
	};

	return IsWidgetHit(TitleBarWidget->GetMinimizeButtonWidget())
		|| IsWidgetHit(TitleBarWidget->GetMaximizeButtonWidget())
		|| IsWidgetHit(TitleBarWidget->GetCloseButtonWidget())
		|| IsWidgetHit(TitleBarWidget->GetExpandButtonWidget());
}

EVisibility SGenericWindowFrame::GetClientAreaVisibility() const
{
	if (const UGenericWindowWidget* WindowWidget = OwnerWindowWidget.Get())
	{
		if (const UGenericWindowRuntimeState* RuntimeState = WindowWidget->GetWindowRuntimeState())
		{
			return RuntimeState->DisplayState == EGenericInGameWindowDisplayState::CollapsedToTitleBar ? EVisibility::Collapsed : EVisibility::Visible;
		}
	}

	return EVisibility::Visible;
}
