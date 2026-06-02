// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericWindowWidget.h"

#include "Base/GenericButtonWidget.h"
#include "GenericWindowAnchor.h"
#include "GenericInGameWindowHost.h"
#include "GenericNativeWindowHost.h"
#include "GenericWindowContent.h"
#include "GenericWindowDescriptor.h"
#include "GenericWindowHost.h"
#include "GenericWindowPartInterface.h"
#include "GenericWindowRuntimeState.h"
#include "GenericWindowSubsystem.h"
#include "GenericWindowTitleBar.h"
#include "SGenericWindowFrame.h"
#include "Blueprint/UserWidget.h"
#include "Engine/GameViewportClient.h"
#include "UnrealClient.h"
#include "Widgets/SNullWidget.h"

#if WITH_EDITOR
#include "Editor/WidgetCompilerLog.h"
#endif

UGenericWindowWidget::UGenericWindowWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericWindowWidget::InitializeWindow(APlayerController* /*InOwningPlayer*/, UGenericWindowDescriptor* InDescriptor)
{
	SetWindowDescriptor(InDescriptor);
	EnsureRuntimeState();
	EnsureRuntimeStateInitialized();
}

void UGenericWindowWidget::OpenWindow()
{
	EnsureDescriptor();
	EnsureRuntimeState();
	EnsureRuntimeStateInitialized();
	ApplyRuntimeStateConstraints();

	if (IsHostedByWindowAnchor())
	{
		SetVisibility(ESlateVisibility::Visible);
		WindowRuntimeState->bIsOpen = true;
		WindowRuntimeState->bIsActive = true;
		UpdateVisibleRect();
		RefreshWindowParts();
		return;
	}

	EnsureHost();

	if (UGenericWindowSubsystem* WindowSubsystem = UGenericWindowSubsystem::Get(this))
	{
		WindowSubsystem->RegisterWindow(this);
	}

	WindowRuntimeState->bIsOpen = true;
	WindowRuntimeState->bIsActive = true;
	UpdateVisibleRect();

	if (WindowHost.IsValid())
	{
		bWindowHostOpenInProgress = true;
		WindowHost->Open();
		bWindowHostOpenInProgress = false;
		if (WindowDescriptor->bAutoBringToFrontOnActivate)
		{
			BringToFront();
		}
	}

	RefreshWindowParts();
}

void UGenericWindowWidget::CloseWindow()
{
	UWorld* World = GetWorld();
	if (!IsValid(World) || !World->IsGameWorld())
	{
		return;
	}

	if (IsHostedByWindowAnchor())
	{
		SetVisibility(ESlateVisibility::Collapsed);

		if (WindowRuntimeState)
		{
			WindowRuntimeState->bIsOpen = false;
			WindowRuntimeState->bIsActive = false;
			WindowRuntimeState->bIsDragging = false;
			WindowRuntimeState->bIsResizing = false;
		}

		if (WindowAnchorHost.IsValid())
		{
			WindowAnchorHost->RefreshHostedWindowLayout();
		}

		return;
	}

	UnbindButtonDelegates();

	if (WindowHost.IsValid())
	{
		WindowHost->Close();
	}

	if (WindowRuntimeState)
	{
		WindowRuntimeState->bIsOpen = false;
		WindowRuntimeState->bIsActive = false;
		WindowRuntimeState->bIsDragging = false;
		WindowRuntimeState->bIsResizing = false;
	}

	if (UGenericWindowSubsystem* WindowSubsystem = UGenericWindowSubsystem::Get(this))
	{
		WindowSubsystem->UnregisterWindow(this);
	}
}

void UGenericWindowWidget::MinimizeWindow()
{
	EnsureRuntimeState();

	if (WindowHost.IsValid() && WindowHost->UsesNativeWindow())
	{
		WindowRuntimeState->DisplayState = EGenericInGameWindowDisplayState::Expanded;
		WindowRuntimeState->bIsMaximized = false;
		WindowHost->Minimize();
		UpdateVisibleRect();
		RefreshWindowState();
		return;
	}

	if (WindowRuntimeState->bIsMaximized)
	{
		RestoreWindow();
	}
}

void UGenericWindowWidget::MaximizeWindow()
{
	EnsureDescriptor();
	EnsureRuntimeState();

	if (WindowRuntimeState->DisplayState == EGenericInGameWindowDisplayState::CollapsedToTitleBar
		&& WindowRuntimeState->bHasCollapseRestoreRect)
	{
		WindowRuntimeState->SetLogicalRect(WindowRuntimeState->CollapseRestorePosition, WindowRuntimeState->CollapseRestoreSize);
		WindowRuntimeState->DisplayState = EGenericInGameWindowDisplayState::Expanded;
		WindowRuntimeState->bHasCollapseRestoreRect = false;
		WindowRuntimeState->bWasMaximizedBeforeCollapse = false;
	}

	if (!WindowRuntimeState->bIsMaximized)
	{
		WindowRuntimeState->LastNormalPosition = WindowRuntimeState->CurrentLogicalPosition;
		WindowRuntimeState->LastNormalSize = WindowRuntimeState->CurrentLogicalSize;
	}

	if (WindowHost.IsValid() && WindowHost->UsesNativeWindow())
	{
		WindowRuntimeState->DisplayState = EGenericInGameWindowDisplayState::Expanded;
		WindowRuntimeState->bIsMaximized = true;
		WindowHost->Maximize();
		UpdateVisibleRect();
		RefreshWindowState();
		return;
	}

	const FVector2D ViewportSize = GetViewportSize();
	if (!ViewportSize.IsNearlyZero())
	{
		WindowRuntimeState->SetLogicalRect(FVector2D::ZeroVector, ViewportSize);
	}

	WindowRuntimeState->DisplayState = EGenericInGameWindowDisplayState::Expanded;
	WindowRuntimeState->bIsMaximized = true;
	UpdateVisibleRect();
	RefreshWindowState();
}

void UGenericWindowWidget::RestoreWindow()
{
	EnsureRuntimeState();

	if (WindowHost.IsValid() && WindowHost->UsesNativeWindow())
	{
		if (WindowRuntimeState->bIsMaximized)
		{
			WindowRuntimeState->SetLogicalRect(WindowRuntimeState->LastNormalPosition, WindowRuntimeState->LastNormalSize);
			WindowRuntimeState->bIsMaximized = false;
		}

		WindowRuntimeState->DisplayState = EGenericInGameWindowDisplayState::Expanded;
		WindowHost->Restore();
		UpdateVisibleRect();
		RefreshWindowState();
		return;
	}

	if (WindowRuntimeState->bIsMaximized)
	{
		WindowRuntimeState->SetLogicalRect(WindowRuntimeState->LastNormalPosition, WindowRuntimeState->LastNormalSize);
		WindowRuntimeState->bIsMaximized = false;
	}

	WindowRuntimeState->DisplayState = EGenericInGameWindowDisplayState::Expanded;
	UpdateVisibleRect();
	RefreshWindowState();
}

void UGenericWindowWidget::ToggleWindowMaximize()
{
	if (IsWindowMaximized())
	{
		RestoreWindow();
	}
	else
	{
		MaximizeWindow();
	}
}

void UGenericWindowWidget::ToggleWindowMinimize()
{
	if (WindowHost.IsValid() && WindowHost->UsesNativeWindow())
	{
		MinimizeWindow();
		return;
	}

	MinimizeWindow();
}

void UGenericWindowWidget::CollapseWindowToTitleBar()
{
	EnsureRuntimeState();

	if (WindowRuntimeState->DisplayState == EGenericInGameWindowDisplayState::CollapsedToTitleBar)
	{
		return;
	}

	WindowRuntimeState->CollapseRestorePosition = WindowRuntimeState->CurrentLogicalPosition;
	WindowRuntimeState->CollapseRestoreSize = WindowRuntimeState->CurrentLogicalSize;
	WindowRuntimeState->bHasCollapseRestoreRect = true;
	WindowRuntimeState->bWasMaximizedBeforeCollapse = WindowRuntimeState->bIsMaximized;
	WindowRuntimeState->bIsMaximized = false;
	WindowRuntimeState->DisplayState = EGenericInGameWindowDisplayState::CollapsedToTitleBar;
	WindowRuntimeState->SetLogicalRect(
		WindowRuntimeState->CurrentLogicalPosition,
		FVector2D(WindowRuntimeState->CurrentLogicalSize.X, GetCollapsedWindowHeight()));
	ApplyRuntimeStateConstraints();
	UpdateVisibleRect();
	RefreshWindowState();
}

void UGenericWindowWidget::ExpandWindowFromTitleBar()
{
	EnsureRuntimeState();

	if (WindowRuntimeState->DisplayState != EGenericInGameWindowDisplayState::CollapsedToTitleBar)
	{
		return;
	}

	const FVector2D RestorePosition = WindowRuntimeState->bHasCollapseRestoreRect
		? WindowRuntimeState->CollapseRestorePosition
		: WindowRuntimeState->CurrentLogicalPosition;
	const FVector2D RestoreSize = WindowRuntimeState->bHasCollapseRestoreRect
		? WindowRuntimeState->CollapseRestoreSize
		: WindowRuntimeState->CurrentLogicalSize;
	const bool bRestoreMaximized = WindowRuntimeState->bHasCollapseRestoreRect && WindowRuntimeState->bWasMaximizedBeforeCollapse;

	WindowRuntimeState->DisplayState = EGenericInGameWindowDisplayState::Expanded;
	WindowRuntimeState->SetLogicalRect(RestorePosition, RestoreSize);
	WindowRuntimeState->bIsMaximized = bRestoreMaximized;
	WindowRuntimeState->bHasCollapseRestoreRect = false;
	WindowRuntimeState->bWasMaximizedBeforeCollapse = false;
	ApplyRuntimeStateConstraints();
	UpdateVisibleRect();
	RefreshWindowState();
}

void UGenericWindowWidget::ToggleWindowCollapseToTitleBar()
{
	if (IsWindowCollapsedToTitleBar())
	{
		ExpandWindowFromTitleBar();
	}
	else
	{
		CollapseWindowToTitleBar();
	}
}

void UGenericWindowWidget::BringToFront()
{
	if (IsHostedByWindowAnchor())
	{
		if (WindowRuntimeState)
		{
			WindowRuntimeState->bIsActive = true;
		}
		return;
	}

	if (UGenericWindowSubsystem* WindowSubsystem = UGenericWindowSubsystem::Get(this))
	{
		if (WindowSubsystem->BringWindowToFront(this) && WindowHost.IsValid() && WindowRuntimeState)
		{
			WindowHost->BringToFront(WindowRuntimeState->ZOrder);
		}
	}
}

void UGenericWindowWidget::SetWindowDescriptor(UGenericWindowDescriptor* InDescriptor)
{
	WindowDescriptor = InDescriptor;
	HandleWindowDescriptorChanged();
}

UGenericWindowDescriptor* UGenericWindowWidget::GetWindowDescriptor() const
{
	return WindowDescriptor;
}

UGenericWindowRuntimeState* UGenericWindowWidget::GetWindowRuntimeState() const
{
	return WindowRuntimeState;
}

APlayerController* UGenericWindowWidget::GetOwnerPlayer() const
{
	return GetOwningPlayer();
}

APlayerController* UGenericWindowWidget::GetOwningPlayer() const
{
	if (APlayerController* PlayerController = Super::GetOwningPlayer())
	{
		return PlayerController;
	}

	if (APlayerController* PlayerController = GetTypedOuter<APlayerController>())
	{
		return PlayerController;
	}

	if (const UUserWidget* ParentUserWidget = GetTypedOuter<UUserWidget>())
	{
		if (APlayerController* PlayerController = ParentUserWidget->GetOwningPlayer())
		{
			return PlayerController;
		}
	}

	if (const UWorld* World = GetWorld())
	{
		return World->GetFirstPlayerController();
	}

	return nullptr;
}

bool UGenericWindowWidget::IsWindowOpen() const
{
	if (IsHostedByWindowAnchor())
	{
		const ESlateVisibility WidgetVisibility = GetVisibility();
		return WidgetVisibility != ESlateVisibility::Collapsed && WidgetVisibility != ESlateVisibility::Hidden;
	}

	return WindowHost.IsValid() && WindowHost->IsOpen();
}

bool UGenericWindowWidget::IsWindowMaximized() const
{
	return WindowRuntimeState && WindowRuntimeState->bIsMaximized;
}

bool UGenericWindowWidget::IsWindowCollapsedToTitleBar() const
{
	return WindowRuntimeState && WindowRuntimeState->DisplayState == EGenericInGameWindowDisplayState::CollapsedToTitleBar;
}

EGenericInGameWindowDisplayState UGenericWindowWidget::GetWindowDisplayState() const
{
	return WindowRuntimeState ? WindowRuntimeState->DisplayState : EGenericInGameWindowDisplayState::Expanded;
}

UGenericWindowTitleBar* UGenericWindowWidget::GetWindowTitleBarWidget() const
{
	return WindowTitleBarWidgetInstance;
}

UGenericWindowContent* UGenericWindowWidget::GetWindowContentWidget() const
{
	return WindowContentWidgetInstance;
}

void UGenericWindowWidget::RefreshWindowParts()
{
	EnsureDescriptor();
	SyncWindowPartWidgets();
	BindButtonDelegates();

	if (WindowFrame.IsValid())
	{
		WindowFrame->RefreshFromOwner();
	}

	RefreshWindowLayout();
}

void UGenericWindowWidget::RefreshWindowLayout()
{
	ApplyRuntimeStateConstraints();
	UpdateVisibleRect();

	if (WindowFrame.IsValid())
	{
		WindowFrame->Invalidate(EInvalidateWidgetReason::Layout);
	}

	if (WindowAnchorHost.IsValid())
	{
		WindowAnchorHost->RefreshHostedWindowLayout();
	}

	if (WindowHost.IsValid())
	{
		WindowHost->InvalidateLayout();
	}
}

void UGenericWindowWidget::RefreshWindowState()
{
	EnsureDescriptor();
	SyncWindowPartWidgets();
	RefreshWindowLayout();
	InvalidateLayoutAndVolatility();
}

void UGenericWindowWidget::RequestWindowMove(const FVector2D& InNewPosition)
{
	EnsureDescriptor();
	EnsureRuntimeState();

	if (!WindowDescriptor->bCanDragWindow || WindowRuntimeState->bIsMaximized)
	{
		return;
	}

	FVector2D TargetPosition = InNewPosition;
	FVector2D TargetSize = WindowRuntimeState->CurrentLogicalSize;
	ClampRectToDescriptor(TargetPosition, TargetSize);
	WindowRuntimeState->SetLogicalRect(TargetPosition, TargetSize);
	WindowRuntimeState->LastNormalPosition = TargetPosition;
	WindowRuntimeState->LastNormalSize = TargetSize;
	UpdateCollapseRestoreRectAfterLayoutChange(TargetPosition, TargetSize);
	UpdateVisibleRect();
	RefreshWindowLayout();
}

void UGenericWindowWidget::RequestWindowResize(EGenericWindowResizeHandle InHandle, const FVector2D& InStartPosition, const FVector2D& InStartSize, const FVector2D& InDelta)
{
	EnsureDescriptor();
	EnsureRuntimeState();

	if (!WindowDescriptor->bCanResizeWindow || InHandle == EGenericWindowResizeHandle::None)
	{
		return;
	}

	FVector2D Position = InStartPosition;
	FVector2D Size = InStartSize;
	const FVector2D StartMax = InStartPosition + InStartSize;

	switch (InHandle)
	{
	case EGenericWindowResizeHandle::Left:
		Position.X = InStartPosition.X + InDelta.X;
		Size.X = StartMax.X - Position.X;
		break;
	case EGenericWindowResizeHandle::Right:
		Size.X = InStartSize.X + InDelta.X;
		break;
	case EGenericWindowResizeHandle::Top:
		Position.Y = InStartPosition.Y + InDelta.Y;
		Size.Y = StartMax.Y - Position.Y;
		break;
	case EGenericWindowResizeHandle::Bottom:
		Size.Y = InStartSize.Y + InDelta.Y;
		break;
	case EGenericWindowResizeHandle::TopLeft:
		Position = InStartPosition + InDelta;
		Size = StartMax - Position;
		break;
	case EGenericWindowResizeHandle::TopRight:
		Position.Y = InStartPosition.Y + InDelta.Y;
		Size.Y = StartMax.Y - Position.Y;
		Size.X = InStartSize.X + InDelta.X;
		break;
	case EGenericWindowResizeHandle::BottomLeft:
		Position.X = InStartPosition.X + InDelta.X;
		Size.X = StartMax.X - Position.X;
		Size.Y = InStartSize.Y + InDelta.Y;
		break;
	case EGenericWindowResizeHandle::BottomRight:
		Size = InStartSize + InDelta;
		break;
	default:
		break;
	}

	const bool bCollapsedToTitleBar = WindowRuntimeState->DisplayState == EGenericInGameWindowDisplayState::CollapsedToTitleBar;
	const float MinWidth = FMath::Max(WindowDescriptor->MinWindowWidth, 1.0f);
	const float MinHeight = bCollapsedToTitleBar ? GetCollapsedWindowHeight() : GetMinimumWindowHeight();
	const float MaxWidth = FMath::Max(MinWidth, WindowDescriptor->MaxWindowWidth);
	const float MaxHeight = bCollapsedToTitleBar ? MinHeight : FMath::Max(MinHeight, WindowDescriptor->MaxWindowHeight);

	if (InHandle == EGenericWindowResizeHandle::Left || InHandle == EGenericWindowResizeHandle::TopLeft || InHandle == EGenericWindowResizeHandle::BottomLeft)
	{
		const float Right = Position.X + Size.X;
		Size.X = FMath::Clamp(Size.X, MinWidth, MaxWidth);
		Position.X = Right - Size.X;
	}
	else
	{
		Size.X = FMath::Clamp(Size.X, MinWidth, MaxWidth);
	}

	if (InHandle == EGenericWindowResizeHandle::Top || InHandle == EGenericWindowResizeHandle::TopLeft || InHandle == EGenericWindowResizeHandle::TopRight)
	{
		const float Bottom = Position.Y + Size.Y;
		Size.Y = FMath::Clamp(Size.Y, MinHeight, MaxHeight);
		Position.Y = Bottom - Size.Y;
	}
	else
	{
		Size.Y = FMath::Clamp(Size.Y, MinHeight, MaxHeight);
	}

	ClampRectToDescriptor(Position, Size);
	WindowRuntimeState->SetLogicalRect(Position, Size);
	WindowRuntimeState->LastNormalPosition = Position;
	WindowRuntimeState->LastNormalSize = Size;
	WindowRuntimeState->bIsMaximized = false;
	UpdateCollapseRestoreRectAfterLayoutChange(Position, Size);
	UpdateVisibleRect();
	RefreshWindowLayout();
}

void UGenericWindowWidget::NotifyInteractionStarted(bool bIsResizeOperation)
{
	EnsureRuntimeState();
	WindowRuntimeState->bIsDragging = !bIsResizeOperation;
	WindowRuntimeState->bIsResizing = bIsResizeOperation;
	WindowRuntimeState->bIsActive = true;
}

void UGenericWindowWidget::NotifyInteractionEnded()
{
	if (WindowRuntimeState)
	{
		WindowRuntimeState->bIsDragging = false;
		WindowRuntimeState->bIsResizing = false;
	}
}

FVector2D UGenericWindowWidget::GetViewportSize() const
{
	if (WindowHost.IsValid())
	{
		const FVector2D ViewportSize = WindowHost->GetViewportSize();
		if (!ViewportSize.IsNearlyZero())
		{
			return ViewportSize;
		}
	}

	if (UWorld* World = GetWorld())
	{
		if (UGameViewportClient* ViewportClient = World->GetGameViewport())
		{
			if (ViewportClient->Viewport)
			{
				const FIntPoint Size = ViewportClient->Viewport->GetSizeXY();
				return FVector2D(static_cast<float>(Size.X), static_cast<float>(Size.Y));
			}
		}
	}

	return FVector2D::ZeroVector;
}

float UGenericWindowWidget::GetMinimumWindowHeight() const
{
	const float DescriptorMinHeight = WindowDescriptor ? FMath::Max(WindowDescriptor->MinWindowHeight, 1.0f) : 1.0f;
	const float TitleBarMinHeight = WindowFrame.IsValid() ? WindowFrame->GetMeasuredTitleBarHeight() : 0.0f;
	return FMath::Max(DescriptorMinHeight, TitleBarMinHeight);
}

float UGenericWindowWidget::GetCollapsedWindowHeight() const
{
	const float TitleBarHeight = WindowFrame.IsValid() ? WindowFrame->GetMeasuredTitleBarHeight() : 0.0f;
	return FMath::Max(TitleBarHeight, 1.0f);
}

TSharedRef<SWidget> UGenericWindowWidget::BuildWindowTitleBarWidget()
{
	return ResolveWindowTitleBarSlate();
}

TSharedRef<SWidget> UGenericWindowWidget::BuildWindowContentWidget()
{
	return ResolveWindowContentSlate();
}

void UGenericWindowWidget::SetWindowAnchorHost(UGenericWindowAnchor* InAnchorHost)
{
	if (WindowAnchorHost.Get() == InAnchorHost)
	{
		return;
	}

	if (InAnchorHost && WindowHost.IsValid())
	{
		WindowHost->Close();
		WindowHost.Reset();
	}

	WindowAnchorHost = InAnchorHost;

	if (WindowAnchorHost.IsValid())
	{
		EnsureDescriptor();
		EnsureRuntimeState();
		EnsureRuntimeStateInitialized();
		WindowRuntimeState->bIsOpen = GetVisibility() != ESlateVisibility::Collapsed && GetVisibility() != ESlateVisibility::Hidden;
		WindowRuntimeState->bIsActive = WindowRuntimeState->bIsOpen;
		UpdateVisibleRect();
	}
}

UGenericWindowAnchor* UGenericWindowWidget::GetWindowAnchorHost() const
{
	return WindowAnchorHost.Get();
}

bool UGenericWindowWidget::IsHostedByWindowAnchor() const
{
	return WindowAnchorHost.IsValid();
}

void UGenericWindowWidget::HandleWindowDescriptorChanged()
{
	EnsureDescriptor();

	if (ShouldApplyLockedDragPolicy())
	{
		WindowDescriptor->DragPolicy = LockedDragPolicy;
	}

	const bool bHasLiveHost =
		IsHostedByWindowAnchor()
		|| bWindowHostOpenInProgress
		|| (WindowHost.IsValid() && WindowHost->IsOpen());

	const bool bShouldReinitializeRuntimeState =
		IsDesignTime()
		|| WindowRuntimeState == nullptr
		|| !bHasLiveHost;

	if (bShouldReinitializeRuntimeState)
	{
		bRuntimeStateInitialized = false;
		EnsureRuntimeState();
		EnsureRuntimeStateInitialized();
	}
	else
	{
		ApplyRuntimeStateConstraints();
		UpdateVisibleRect();
	}

	RefreshWindowParts();
	InvalidateLayoutAndVolatility();
}

void UGenericWindowWidget::HandleExternalHostWindowClosed()
{
	UnbindButtonDelegates();

	if (WindowRuntimeState)
	{
		WindowRuntimeState->bIsOpen = false;
		WindowRuntimeState->bIsActive = false;
		WindowRuntimeState->bIsDragging = false;
		WindowRuntimeState->bIsResizing = false;
		WindowRuntimeState->bIsMaximized = false;
	}

	if (UGenericWindowSubsystem* WindowSubsystem = UGenericWindowSubsystem::Get(this))
	{
		WindowSubsystem->UnregisterWindow(this);
	}
}

void UGenericWindowWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	CloseWindow();
	WindowFrame.Reset();
	WindowHost.Reset();
	Super::ReleaseSlateResources(bReleaseChildren);
}

TSharedRef<SWidget> UGenericWindowWidget::RebuildWidget()
{
	EnsureDescriptor();
	EnsureRuntimeState();
	EnsureRuntimeStateInitialized();

	SAssignNew(WindowFrame, SGenericWindowFrame)
		.OwnerWindowWidget(this);

	return WindowFrame.ToSharedRef();
}

void UGenericWindowWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	HandleWindowDescriptorChanged();
}

#if WITH_EDITOR
void UGenericWindowWidget::ValidateCompiledDefaults(IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);

	if (GetParent() != nullptr && !GetParent()->IsA<UGenericWindowAnchor>())
	{
		CompileLog.Error(FText::FromString(TEXT("UGenericWindowWidget cannot be placed directly in a UMG tree. Place it inside a GenericWindowAnchor or create it with CreateWindow.")));
	}
}

const FText UGenericWindowWidget::GetPaletteCategory()
{
	return NSLOCTEXT("GenericWindowFramework", "PaletteCategory", "Generic Window");
}
#endif

void UGenericWindowWidget::BeginDestroy()
{
	CloseWindow();
	Super::BeginDestroy();
}

void UGenericWindowWidget::EnsureDescriptor()
{
	if (!WindowDescriptor)
	{
		WindowDescriptor = NewObject<UGenericWindowDescriptor>(this, UGenericWindowDescriptor::StaticClass());
	}

	if (ShouldApplyLockedDragPolicy())
	{
		WindowDescriptor->DragPolicy = LockedDragPolicy;
	}
}

void UGenericWindowWidget::EnsureRuntimeState()
{
	if (!WindowRuntimeState)
	{
		WindowRuntimeState = NewObject<UGenericWindowRuntimeState>(this, UGenericWindowRuntimeState::StaticClass());
	}
}

void UGenericWindowWidget::EnsureRuntimeStateInitialized()
{
	EnsureDescriptor();
	EnsureRuntimeState();

	if (IsRuntimeWindowInstance())
	{
		EnsureDragPolicyLocked();
	}
	else
	{
		bDragPolicyLocked = false;
	}

	if (!bRuntimeStateInitialized)
	{
		WindowRuntimeState->InitializeFromDescriptor(WindowDescriptor);
		ApplyRuntimeStateConstraints();
		bRuntimeStateInitialized = true;
		UpdateVisibleRect();
	}
}

void UGenericWindowWidget::EnsureDragPolicyLocked()
{
	EnsureDescriptor();

	if (!IsRuntimeWindowInstance())
	{
		bDragPolicyLocked = false;
		return;
	}

	if (!bDragPolicyLocked)
	{
		LockedDragPolicy = WindowDescriptor->DragPolicy;
		bDragPolicyLocked = true;
	}

	WindowDescriptor->DragPolicy = LockedDragPolicy;
}

void UGenericWindowWidget::EnsureHost()
{
	const bool bNeedsNativeWindowHost = UsesNativeWindowHost();
	if (WindowHost.IsValid() && WindowHost->UsesNativeWindow() != bNeedsNativeWindowHost)
	{
		WindowHost->Close();
		WindowHost.Reset();
	}

	if (!WindowHost.IsValid())
	{
		WindowHost = bNeedsNativeWindowHost
			? TSharedPtr<IGenericWindowHostInterface>(MakeShared<FGenericNativeWindowHost>(this))
			: TSharedPtr<IGenericWindowHostInterface>(MakeShared<FGenericInGameWindowHost>(this));
	}
}

void UGenericWindowWidget::ApplyRuntimeStateConstraints()
{
	if (!WindowRuntimeState)
	{
		return;
	}

	FVector2D ConstrainedPosition = WindowRuntimeState->CurrentLogicalPosition;
	FVector2D ConstrainedSize = WindowRuntimeState->CurrentLogicalSize;
	ClampRectToDescriptor(ConstrainedPosition, ConstrainedSize);
	WindowRuntimeState->SetLogicalRect(ConstrainedPosition, ConstrainedSize);

	if (!WindowRuntimeState->bIsMaximized)
	{
		if (WindowRuntimeState->DisplayState != EGenericInGameWindowDisplayState::CollapsedToTitleBar)
		{
			WindowRuntimeState->LastNormalPosition = ConstrainedPosition;
			WindowRuntimeState->LastNormalSize = ConstrainedSize;
		}
	}
}

void UGenericWindowWidget::UpdateCollapseRestoreRectAfterLayoutChange(const FVector2D& InPosition, const FVector2D& InSize)
{
	if (!WindowRuntimeState || WindowRuntimeState->DisplayState != EGenericInGameWindowDisplayState::CollapsedToTitleBar || !WindowRuntimeState->bHasCollapseRestoreRect)
	{
		return;
	}

	WindowRuntimeState->CollapseRestorePosition = InPosition;
	WindowRuntimeState->CollapseRestoreSize.X = InSize.X;
	WindowRuntimeState->bWasMaximizedBeforeCollapse = false;
}

void UGenericWindowWidget::UpdateVisibleRect()
{
	if (!WindowRuntimeState)
	{
		return;
	}

	if ((WindowHost.IsValid() && !WindowHost->ClipsToHostBounds()) || (!WindowHost.IsValid() && UsesNativeWindowHost()))
	{
		WindowRuntimeState->SetVisibleRect(WindowRuntimeState->CurrentLogicalPosition, WindowRuntimeState->CurrentLogicalSize);
		return;
	}

	const FVector2D ViewportSize = GetViewportSize();
	if (ViewportSize.IsNearlyZero())
	{
		WindowRuntimeState->SetVisibleRect(WindowRuntimeState->CurrentLogicalPosition, WindowRuntimeState->CurrentLogicalSize);
		return;
	}

	const FVector2D LogicalMin = WindowRuntimeState->CurrentLogicalPosition;
	const FVector2D LogicalMax = LogicalMin + WindowRuntimeState->CurrentLogicalSize;
	const FVector2D VisibleMin(FMath::Clamp(LogicalMin.X, 0.0f, ViewportSize.X), FMath::Clamp(LogicalMin.Y, 0.0f, ViewportSize.Y));
	const FVector2D VisibleMax(FMath::Clamp(LogicalMax.X, 0.0f, ViewportSize.X), FMath::Clamp(LogicalMax.Y, 0.0f, ViewportSize.Y));

	WindowRuntimeState->SetVisibleRect(
		VisibleMin,
		FVector2D(FMath::Max(0.0f, VisibleMax.X - VisibleMin.X), FMath::Max(0.0f, VisibleMax.Y - VisibleMin.Y))
	);
}

bool UGenericWindowWidget::IsRuntimeWindowInstance() const
{
	const UWorld* World = GetWorld();
	return World != nullptr && World->IsGameWorld() && !IsDesignTime();
}

bool UGenericWindowWidget::ShouldApplyLockedDragPolicy() const
{
	return bDragPolicyLocked && IsRuntimeWindowInstance();
}

bool UGenericWindowWidget::UsesNativeWindowHost() const
{
	return !IsHostedByWindowAnchor() && GetEffectiveDragPolicy() == EGenericWindowDragPolicy::AllowOutOfViewport;
}

void UGenericWindowWidget::ClampRectToDescriptor(FVector2D& InOutPosition, FVector2D& InOutSize) const
{
	if (!WindowDescriptor)
	{
		return;
	}

	const bool bCollapsedToTitleBar = WindowRuntimeState && WindowRuntimeState->DisplayState == EGenericInGameWindowDisplayState::CollapsedToTitleBar;
	const float MinHeight = bCollapsedToTitleBar ? GetCollapsedWindowHeight() : GetMinimumWindowHeight();
	const float MaxHeight = bCollapsedToTitleBar
		? MinHeight
		: FMath::Max(WindowDescriptor->MaxWindowHeight, WindowDescriptor->MinWindowHeight);

	InOutSize.X = FMath::Clamp(InOutSize.X, FMath::Max(WindowDescriptor->MinWindowWidth, 1.0f), FMath::Max(WindowDescriptor->MaxWindowWidth, WindowDescriptor->MinWindowWidth));
	InOutSize.Y = FMath::Clamp(InOutSize.Y, MinHeight, MaxHeight);

	if (GetEffectiveDragPolicy() == EGenericWindowDragPolicy::InViewportOnly)
	{
		const FVector2D ViewportSize = GetViewportSize();
		if (!ViewportSize.IsNearlyZero())
		{
			InOutSize.X = FMath::Min(InOutSize.X, ViewportSize.X);
			InOutSize.Y = FMath::Min(InOutSize.Y, ViewportSize.Y);
			InOutPosition.X = FMath::Clamp(InOutPosition.X, 0.0f, FMath::Max(0.0f, ViewportSize.X - InOutSize.X));
			InOutPosition.Y = FMath::Clamp(InOutPosition.Y, 0.0f, FMath::Max(0.0f, ViewportSize.Y - InOutSize.Y));
		}
	}
}

EGenericWindowDragPolicy UGenericWindowWidget::GetEffectiveDragPolicy() const
{
	return ShouldApplyLockedDragPolicy()
		? LockedDragPolicy
		: (WindowDescriptor ? WindowDescriptor->DragPolicy : EGenericWindowDragPolicy::InViewportOnly);
}

bool UGenericWindowWidget::TryConvertScreenToWindowHostPosition(const FVector2D& InScreenSpacePosition, FVector2D& OutHostPosition) const
{
	if (WindowHost.IsValid() && WindowHost->TryConvertScreenToHostLocal(InScreenSpacePosition, OutHostPosition))
	{
		return true;
	}

	if (UsesNativeWindowHost())
	{
		OutHostPosition = InScreenSpacePosition;
		return true;
	}

	return false;
}

void UGenericWindowWidget::ApplyWindowPartContext(UWidget* InWidget) const
{
	if (IsValid(InWidget) && InWidget->GetClass()->ImplementsInterface(UGenericWindowPartInterface::StaticClass()))
	{
		IGenericWindowPartInterface::Execute_SetOwningGenericWindow(InWidget, const_cast<UGenericWindowWidget*>(this));
	}
}

void UGenericWindowWidget::SyncWindowPartWidgets()
{
	if (UGenericWindowTitleBar* TitleBarWidget = ResolveWindowTitleBarWidget())
	{
		TitleBarWidget->SynchronizeFromWindow();
	}

	if (UGenericWindowContent* ContentWidget = ResolveWindowContentWidget())
	{
		ContentWidget->SynchronizeFromWindow();
	}
}

UGenericWindowTitleBar* UGenericWindowWidget::ResolveWindowTitleBarWidget()
{
	const TSubclassOf<UGenericWindowTitleBar> TitleBarClass = WindowDescriptor ? WindowDescriptor->WindowTitleBarClass : nullptr;
	if (!TitleBarClass)
	{
		WindowTitleBarWidgetInstance = nullptr;
		return nullptr;
	}

	if (!IsValid(WindowTitleBarWidgetInstance) || WindowTitleBarWidgetInstance->GetClass() != TitleBarClass)
	{
		if (APlayerController* PlayerController = GetOwningPlayer())
		{
			WindowTitleBarWidgetInstance = CreateWidget<UGenericWindowTitleBar>(PlayerController, TitleBarClass);
		}
		else if (UWorld* World = GetWorld())
		{
			WindowTitleBarWidgetInstance = CreateWidget<UGenericWindowTitleBar>(World, TitleBarClass);
		}
	}

	ApplyWindowPartContext(WindowTitleBarWidgetInstance);
	return WindowTitleBarWidgetInstance;
}

UGenericWindowContent* UGenericWindowWidget::ResolveWindowContentWidget()
{
	const TSubclassOf<UGenericWindowContent> ContentClass = WindowDescriptor ? WindowDescriptor->WindowContentClass : nullptr;
	if (!ContentClass)
	{
		WindowContentWidgetInstance = nullptr;
		return nullptr;
	}

	if (!IsValid(WindowContentWidgetInstance) || WindowContentWidgetInstance->GetClass() != ContentClass)
	{
		if (APlayerController* PlayerController = GetOwningPlayer())
		{
			WindowContentWidgetInstance = CreateWidget<UGenericWindowContent>(PlayerController, ContentClass);
		}
		else if (UWorld* World = GetWorld())
		{
			WindowContentWidgetInstance = CreateWidget<UGenericWindowContent>(World, ContentClass);
		}
	}

	ApplyWindowPartContext(WindowContentWidgetInstance);
	return WindowContentWidgetInstance;
}

TSharedRef<SWidget> UGenericWindowWidget::ResolveWindowTitleBarSlate()
{
	if (UGenericWindowTitleBar* TitleBarWidget = ResolveWindowTitleBarWidget())
	{
		TitleBarWidget->SynchronizeFromWindow();
		return TitleBarWidget->TakeWidget();
	}

	return SNullWidget::NullWidget;
}

TSharedRef<SWidget> UGenericWindowWidget::ResolveWindowContentSlate()
{
	if (UGenericWindowContent* ContentWidget = ResolveWindowContentWidget())
	{
		ContentWidget->SynchronizeFromWindow();
		return ContentWidget->TakeWidget();
	}

	return SNullWidget::NullWidget;
}

void UGenericWindowWidget::BindButtonDelegates()
{
	UnbindButtonDelegates();

	MinimizeButtonWidgetInstance = nullptr;
	MaximizeButtonWidgetInstance = nullptr;
	CloseButtonWidgetInstance = nullptr;
	ExpandButtonWidgetInstance = nullptr;

	if (UGenericWindowTitleBar* TitleBarWidget = ResolveWindowTitleBarWidget())
	{
		TitleBarWidget->SynchronizeFromWindow();
		MinimizeButtonWidgetInstance = TitleBarWidget->GetMinimizeButtonWidget();
		MaximizeButtonWidgetInstance = TitleBarWidget->GetMaximizeButtonWidget();
		CloseButtonWidgetInstance = TitleBarWidget->GetCloseButtonWidget();
		ExpandButtonWidgetInstance = TitleBarWidget->GetExpandButtonWidget();
	}

	if (IsValid(MinimizeButtonWidgetInstance))
	{
		MinimizeButtonWidgetInstance->Delegate_OnButtonClickedEvent.AddUObject(this, &UGenericWindowWidget::HandleMinimizeButtonClicked);
	}

	if (IsValid(MaximizeButtonWidgetInstance))
	{
		MaximizeButtonWidgetInstance->Delegate_OnButtonClickedEvent.AddUObject(this, &UGenericWindowWidget::HandleMaximizeButtonClicked);
	}

	if (IsValid(CloseButtonWidgetInstance))
	{
		CloseButtonWidgetInstance->Delegate_OnButtonClickedEvent.AddUObject(this, &UGenericWindowWidget::HandleCloseButtonClicked);
	}

	if (IsValid(ExpandButtonWidgetInstance))
	{
		ExpandButtonWidgetInstance->Delegate_OnButtonClickedEvent.AddUObject(this, &UGenericWindowWidget::HandleExpandButtonClicked);
	}
}

void UGenericWindowWidget::UnbindButtonDelegates()
{
	if (IsValid(MinimizeButtonWidgetInstance))
	{
		MinimizeButtonWidgetInstance->Delegate_OnButtonClickedEvent.RemoveAll(this);
	}

	if (IsValid(MaximizeButtonWidgetInstance))
	{
		MaximizeButtonWidgetInstance->Delegate_OnButtonClickedEvent.RemoveAll(this);
	}

	if (IsValid(CloseButtonWidgetInstance))
	{
		CloseButtonWidgetInstance->Delegate_OnButtonClickedEvent.RemoveAll(this);
	}

	if (IsValid(ExpandButtonWidgetInstance))
	{
		ExpandButtonWidgetInstance->Delegate_OnButtonClickedEvent.RemoveAll(this);
	}
}

void UGenericWindowWidget::HandleMinimizeButtonClicked()
{
	ToggleWindowMinimize();
}

void UGenericWindowWidget::HandleMaximizeButtonClicked()
{
	ToggleWindowMaximize();
}

void UGenericWindowWidget::HandleCloseButtonClicked()
{
	CloseWindow();
}

void UGenericWindowWidget::HandleExpandButtonClicked()
{
	ToggleWindowCollapseToTitleBar();
}
