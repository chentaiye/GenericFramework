// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericNativeWindowHost.h"

#include "GenericWindowDescriptor.h"
#include "GenericWindowRuntimeState.h"
#include "GenericWindowWidget.h"
#include "Engine/GameViewportClient.h"
#include "Engine/World.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SWindow.h"

FGenericNativeWindowHost::FGenericNativeWindowHost(UGenericWindowWidget* InOwnerWidget)
	: OwnerWidget(InOwnerWidget)
{
}

FGenericNativeWindowHost::~FGenericNativeWindowHost()
{
	Close();
}

void FGenericNativeWindowHost::Open()
{
	if (bIsOpen || NativeWindow.IsValid() || !FSlateApplication::IsInitialized())
	{
		return;
	}

	UGenericWindowWidget* WindowWidget = OwnerWidget.Get();
	const UGenericWindowRuntimeState* RuntimeState = WindowWidget ? WindowWidget->GetWindowRuntimeState() : nullptr;
	const UGenericWindowDescriptor* Descriptor = WindowWidget ? WindowWidget->GetWindowDescriptor() : nullptr;
	if (!WindowWidget || !RuntimeState || !Descriptor)
	{
		return;
	}

	const FVector2f InitialPosition(RuntimeState->CurrentLogicalPosition);
	const FVector2f InitialSize(RuntimeState->CurrentLogicalSize);

	TSharedRef<SWindow> NewWindow = SNew(SWindow)
		.Type(EWindowType::Normal)
		.SizingRule(Descriptor->bCanResizeWindow ? ESizingRule::UserSized : ESizingRule::FixedSize)
		.AutoCenter(EAutoCenter::None)
		.ScreenPosition(InitialPosition)
		.ClientSize(InitialSize)
		.AdjustInitialSizeAndPositionForDPIScale(false)
		.CreateTitleBar(false)
		.UseOSWindowBorder(false)
		.HasCloseButton(false)
		.SupportsMaximize(Descriptor->bCanMaximizeWindow)
		.SupportsMinimize(Descriptor->bCanMinimizeWindow)
		.UserResizeBorder(FMargin(0.0f))
		.FocusWhenFirstShown(Descriptor->bFocusOnOpen)
		.ActivationPolicy(Descriptor->bFocusOnOpen ? EWindowActivationPolicy::Always : EWindowActivationPolicy::Never)
		[
			WindowWidget->TakeWidget()
		];

	NativeWindow = NewWindow;
	NativeWindow->SetOnWindowClosed(FOnWindowClosed::CreateSP(SharedThis(this), &FGenericNativeWindowHost::HandleSlateWindowClosed));
	NativeWindow->SetOnWindowMoved(FOnWindowMoved::CreateSP(SharedThis(this), &FGenericNativeWindowHost::HandleSlateWindowMoved));

	if (const TSharedPtr<SWindow> ParentWindow = ResolveParentWindow())
	{
		FSlateApplication::Get().AddWindowAsNativeChild(NewWindow, ParentWindow.ToSharedRef(), true);
	}
	else
	{
		FSlateApplication::Get().AddWindow(NewWindow, true);
	}

	bIsOpen = true;

	ApplyRuntimeStateToNativeWindow();
	if (Descriptor->bFocusOnOpen)
	{
		NativeWindow->BringToFront(true);
	}
}

void FGenericNativeWindowHost::Close()
{
	if (!NativeWindow.IsValid())
	{
		bIsOpen = false;
		return;
	}

	TSharedPtr<SWindow> WindowToClose = NativeWindow;
	NativeWindow.Reset();
	bIsOpen = false;
	bCloseRequestedByOwner = true;

	if (FSlateApplication::IsInitialized())
	{
		WindowToClose->RequestDestroyWindow();
	}
	else
	{
		WindowToClose->DestroyWindowImmediately();
	}
}

void FGenericNativeWindowHost::BringToFront(int32 InZOrder)
{
	if (NativeWindow.IsValid())
	{
		NativeWindow->BringToFront(true);
	}
}

void FGenericNativeWindowHost::InvalidateLayout()
{
	ApplyRuntimeStateToNativeWindow();
}

bool FGenericNativeWindowHost::IsOpen() const
{
	return bIsOpen && NativeWindow.IsValid();
}

FVector2D FGenericNativeWindowHost::GetViewportSize() const
{
	if (NativeWindow.IsValid())
	{
		return FVector2D(NativeWindow->GetClientSizeInScreen());
	}

	return FVector2D::ZeroVector;
}

bool FGenericNativeWindowHost::TryConvertScreenToHostLocal(const FVector2D& InScreenSpacePosition, FVector2D& OutHostLocalPosition) const
{
	OutHostLocalPosition = InScreenSpacePosition;
	return true;
}

bool FGenericNativeWindowHost::UsesNativeWindow() const
{
	return true;
}

TSharedPtr<SWindow> FGenericNativeWindowHost::ResolveParentWindow() const
{
	if (const UGenericWindowWidget* WindowWidget = OwnerWidget.Get())
	{
		if (const UWorld* World = WindowWidget->GetWorld())
		{
			if (UGameViewportClient* ViewportClient = World->GetGameViewport())
			{
				return ViewportClient->GetWindow();
			}
		}
	}

	return nullptr;
}

bool FGenericNativeWindowHost::ClipsToHostBounds() const
{
	return false;
}

void FGenericNativeWindowHost::Minimize()
{
	if (NativeWindow.IsValid())
	{
		NativeWindow->Minimize();
	}
}

void FGenericNativeWindowHost::Maximize()
{
	if (NativeWindow.IsValid())
	{
		NativeWindow->Maximize();
	}
}

void FGenericNativeWindowHost::Restore()
{
	if (NativeWindow.IsValid())
	{
		NativeWindow->Restore();
	}
}

void FGenericNativeWindowHost::SyncRuntimeState(UGenericWindowRuntimeState& InOutRuntimeState) const
{
	if (!NativeWindow.IsValid())
	{
		return;
	}

	const FVector2D CurrentPosition(NativeWindow->GetPositionInScreen());
	const FVector2D CurrentSize(NativeWindow->GetClientSizeInScreen());

	InOutRuntimeState.CurrentLogicalPosition = CurrentPosition;
	InOutRuntimeState.CurrentLogicalSize = CurrentSize;
	InOutRuntimeState.CurrentVisiblePosition = CurrentPosition;
	InOutRuntimeState.CurrentVisibleSize = CurrentSize;
	InOutRuntimeState.bIsMaximized = NativeWindow->IsWindowMaximized();

	if (!InOutRuntimeState.bIsMaximized)
	{
		InOutRuntimeState.LastNormalPosition = CurrentPosition;
		InOutRuntimeState.LastNormalSize = CurrentSize;
	}
}

void FGenericNativeWindowHost::ApplyRuntimeStateToNativeWindow() const
{
	if (!NativeWindow.IsValid())
	{
		return;
	}

	const UGenericWindowWidget* WindowWidget = OwnerWidget.Get();
	const UGenericWindowRuntimeState* RuntimeState = WindowWidget ? WindowWidget->GetWindowRuntimeState() : nullptr;
	if (!RuntimeState)
	{
		return;
	}

	if (NativeWindow->IsWindowMinimized())
	{
		return;
	}

	if (RuntimeState->bIsMaximized)
	{
		if (!NativeWindow->IsWindowMaximized())
		{
			NativeWindow->Maximize();
		}

		if (UGenericWindowRuntimeState* MutableState = WindowWidget ? WindowWidget->GetWindowRuntimeState() : nullptr)
		{
			SyncRuntimeState(*MutableState);
		}

		return;
	}

	if (NativeWindow->IsWindowMaximized())
	{
		NativeWindow->Restore();
	}

	const FVector2D TargetPosition = RuntimeState->CurrentLogicalPosition;
	const FVector2D TargetSize = RuntimeState->CurrentLogicalSize;
	bApplyingRuntimeState = true;

	NativeWindow->MoveWindowTo(TargetPosition);

	const FVector2D CurrentClientSize = FVector2D(NativeWindow->GetClientSizeInScreen());
	if (!CurrentClientSize.Equals(TargetSize, 0.5f))
	{
		NativeWindow->Resize(TargetSize);
	}

	bApplyingRuntimeState = false;
}

void FGenericNativeWindowHost::HandleSlateWindowClosed(const TSharedRef<SWindow>& ClosedWindow)
{
	bIsOpen = false;
	NativeWindow.Reset();

	if (!bCloseRequestedByOwner)
	{
		if (UGenericWindowWidget* WindowWidget = OwnerWidget.Get())
		{
			WindowWidget->HandleExternalHostWindowClosed();
		}
	}

	bCloseRequestedByOwner = false;
}

void FGenericNativeWindowHost::HandleSlateWindowMoved(const TSharedRef<SWindow>& MovedWindow)
{
	if (bApplyingRuntimeState)
	{
		return;
	}

	if (UGenericWindowWidget* WindowWidget = OwnerWidget.Get())
	{
		if (UGenericWindowRuntimeState* RuntimeState = WindowWidget->GetWindowRuntimeState())
		{
			const FVector2D CurrentPosition(MovedWindow->GetPositionInScreen());
			RuntimeState->CurrentLogicalPosition = CurrentPosition;
			RuntimeState->CurrentVisiblePosition = CurrentPosition;

			if (!RuntimeState->bIsMaximized)
			{
				RuntimeState->LastNormalPosition = CurrentPosition;
			}
		}
	}
}
