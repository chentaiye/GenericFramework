// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericInGameWindowHost.h"

#include "GenericWindowRuntimeState.h"
#include "GenericWindowWidget.h"
#include "Engine/World.h"
#include "Engine/GameViewportClient.h"
#include "UnrealClient.h"
#include "Widgets/Layout/SConstraintCanvas.h"

FGenericInGameWindowHost::FGenericInGameWindowHost(UGenericWindowWidget* InOwnerWidget)
	: OwnerWidget(InOwnerWidget)
{
}

FGenericInGameWindowHost::~FGenericInGameWindowHost()
{
	Close();
}

void FGenericInGameWindowHost::Open()
{
	if (bIsOpen)
	{
		return;
	}

	UGenericWindowWidget* WindowWidget = OwnerWidget.Get();
	UGameViewportClient* ViewportClient = ResolveViewportClient();
	if (!WindowWidget || !ViewportClient)
	{
		return;
	}

	SAssignNew(RootCanvas, SConstraintCanvas)
		.Visibility(EVisibility::SelfHitTestInvisible);

	RootCanvas->AddSlot()
		.Expose(WindowSlot)
		.Anchors(FAnchors(0.0f))
		.Alignment(FVector2D::ZeroVector)
		.AutoSize(false)
		.Offset(GetWindowOffset())
		.ZOrder(CurrentZOrder)
		[
			WindowWidget->TakeWidget()
		];

	CurrentZOrder = WindowWidget->GetWindowRuntimeState() ? WindowWidget->GetWindowRuntimeState()->ZOrder : 0;
	UpdateWindowSlot();
	ViewportClient->AddViewportWidgetContent(RootCanvas.ToSharedRef(), CurrentZOrder);
	bIsOpen = true;
}

void FGenericInGameWindowHost::Close()
{
	if (!bIsOpen || !RootCanvas.IsValid())
	{
		WindowSlot = nullptr;
		RootCanvas.Reset();
		bIsOpen = false;
		return;
	}

	if (UGameViewportClient* ViewportClient = ResolveViewportClient())
	{
		ViewportClient->RemoveViewportWidgetContent(RootCanvas.ToSharedRef());
	}

	WindowSlot = nullptr;
	RootCanvas.Reset();
	bIsOpen = false;
}

void FGenericInGameWindowHost::BringToFront(int32 InZOrder)
{
	CurrentZOrder = InZOrder;
	if (!bIsOpen || !RootCanvas.IsValid())
	{
		return;
	}

	if (UGameViewportClient* ViewportClient = ResolveViewportClient())
	{
		ViewportClient->RemoveViewportWidgetContent(RootCanvas.ToSharedRef());
		ViewportClient->AddViewportWidgetContent(RootCanvas.ToSharedRef(), CurrentZOrder);
	}
}

void FGenericInGameWindowHost::InvalidateLayout()
{
	if (RootCanvas.IsValid())
	{
		UpdateWindowSlot();
		RootCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
	}
}

bool FGenericInGameWindowHost::IsOpen() const
{
	return bIsOpen;
}

bool FGenericInGameWindowHost::UsesNativeWindow() const
{
	return false;
}

bool FGenericInGameWindowHost::ClipsToHostBounds() const
{
	return true;
}

FVector2D FGenericInGameWindowHost::GetViewportSize() const
{
	if (RootCanvas.IsValid())
	{
		const FVector2D CanvasSize = RootCanvas->GetCachedGeometry().GetLocalSize();
		if (!CanvasSize.IsNearlyZero())
		{
			return CanvasSize;
		}
	}

	if (UGameViewportClient* ViewportClient = ResolveViewportClient())
	{
		if (ViewportClient->Viewport)
		{
			const FIntPoint ViewportSize = ViewportClient->Viewport->GetSizeXY();
			return FVector2D(static_cast<float>(ViewportSize.X), static_cast<float>(ViewportSize.Y));
		}
	}

	return FVector2D::ZeroVector;
}

bool FGenericInGameWindowHost::TryConvertScreenToHostLocal(const FVector2D& InScreenSpacePosition, FVector2D& OutHostLocalPosition) const
{
	if (!RootCanvas.IsValid())
	{
		return false;
	}

	const FGeometry& RootGeometry = RootCanvas->GetCachedGeometry();
	if (RootGeometry.GetLocalSize().IsNearlyZero())
	{
		return false;
	}

	OutHostLocalPosition = RootGeometry.AbsoluteToLocal(InScreenSpacePosition);
	return true;
}

void FGenericInGameWindowHost::Minimize()
{
}

void FGenericInGameWindowHost::Maximize()
{
}

void FGenericInGameWindowHost::Restore()
{
}

void FGenericInGameWindowHost::SyncRuntimeState(UGenericWindowRuntimeState& InOutRuntimeState) const
{
}

UGameViewportClient* FGenericInGameWindowHost::ResolveViewportClient() const
{
	if (const UGenericWindowWidget* WindowWidget = OwnerWidget.Get())
	{
		if (UWorld* World = WindowWidget->GetWorld())
		{
			return World->GetGameViewport();
		}
	}

	return nullptr;
}

FMargin FGenericInGameWindowHost::GetWindowOffset() const
{
	if (const UGenericWindowWidget* WindowWidget = OwnerWidget.Get())
	{
		if (const UGenericWindowRuntimeState* RuntimeState = WindowWidget->GetWindowRuntimeState())
		{
			return FMargin(
				RuntimeState->CurrentLogicalPosition.X,
				RuntimeState->CurrentLogicalPosition.Y,
				RuntimeState->CurrentLogicalSize.X,
				RuntimeState->CurrentLogicalSize.Y);
		}
	}

	return FMargin(0.0f);
}

void FGenericInGameWindowHost::UpdateWindowSlot()
{
	if (WindowSlot == nullptr)
	{
		return;
	}

	WindowSlot->SetAnchors(FAnchors(0.0f));
	WindowSlot->SetAlignment(FVector2D::ZeroVector);
	WindowSlot->SetAutoSize(false);
	WindowSlot->SetOffset(GetWindowOffset());
}
