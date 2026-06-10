// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericWindowAnchor.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Engine/GameViewportClient.h"
#include "GenericWindowDescriptor.h"
#include "GenericWindowRuntimeState.h"
#include "GenericWindowSlot.h"
#include "GenericWindowWidget.h"
#include "WidgetType.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SWindow.h"

#if WITH_EDITOR
#include "Editor/WidgetCompilerLog.h"
#endif

class SGenericWindowAnchorRoot : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGenericWindowAnchorRoot)
	{
	}
		SLATE_ARGUMENT(UGenericWindowAnchor*, OwnerAnchor)
		SLATE_DEFAULT_SLOT(FArguments, Content)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		OwnerAnchor = InArgs._OwnerAnchor;

		ChildSlot
		[
			InArgs._Content.Widget
		];
	}

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override
	{
		SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

		if (UGenericWindowAnchor* Anchor = OwnerAnchor.Get())
		{
			Anchor->HandleAnchorGeometryTick(AllottedGeometry);
		}
	}

private:
	TWeakObjectPtr<UGenericWindowAnchor> OwnerAnchor;
};

UGenericWindowAnchor::UGenericWindowAnchor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UGenericWindowWidget* UGenericWindowAnchor::GetHostedWindow() const
{
	return Cast<UGenericWindowWidget>(GetContent());
}

UGenericWindowSlot* UGenericWindowAnchor::SetHostedWindow(UGenericWindowWidget* InWindowWidget)
{
	return Cast<UGenericWindowSlot>(SetContent(InWindowWidget));
}

void UGenericWindowAnchor::RefreshHostedWindowLayout()
{
	UGenericWindowWidget* WindowWidget = GetHostedWindow();
	HostedWindowWidget = WindowWidget;

	if (!WindowWidget)
	{
		bHasActivatedRuntimeWindow = false;
		bHasObservedActivationPlacement = false;
		HostedWindowSlot = nullptr;
		if (AnchorCanvas.IsValid())
		{
			AnchorCanvas->ClearChildren();
			AnchorCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
		}
		return;
	}

	if (ShouldPreviewHostedWindowInAnchor())
	{
		WindowWidget->SetWindowAnchorHost(this);
	}
	else
	{
		WindowWidget->SetWindowAnchorHost(nullptr);
	}

	if (AnchorRootBox.IsValid())
	{
		const FVector2D HostedSize = GetHostedWindowSize();
		AnchorRootBox->SetWidthOverride(HostedSize.X);
		AnchorRootBox->SetHeightOverride(HostedSize.Y);
	}

	if (!AnchorCanvas.IsValid())
	{
		return;
	}

	if (!ShouldPreviewHostedWindowInAnchor())
	{
		AnchorCanvas->ClearChildren();
		HostedWindowSlot = nullptr;
		AnchorCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
		return;
	}

	if (HostedWindowSlot == nullptr)
	{
		RebuildHostedWindowSlot();
		return;
	}

	HostedWindowSlot->SetAnchors(FAnchors(0.0f));
	HostedWindowSlot->SetAlignment(GetHostedWindowAlignment());
	HostedWindowSlot->SetAutoSize(false);
	HostedWindowSlot->SetOffset(GetHostedWindowOffset());
	AnchorCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
}

UClass* UGenericWindowAnchor::GetSlotClass() const
{
	return UGenericWindowSlot::StaticClass();
}

void UGenericWindowAnchor::OnSlotAdded(UPanelSlot* InSlot)
{
	bHasActivatedRuntimeWindow = false;
	bHasObservedActivationPlacement = false;
	Super::OnSlotAdded(InSlot);
	RebuildHostedWindowSlot();
}

void UGenericWindowAnchor::OnSlotRemoved(UPanelSlot* InSlot)
{
	if (UGenericWindowWidget* WindowWidget = Cast<UGenericWindowWidget>(InSlot ? InSlot->Content : nullptr))
	{
		WindowWidget->SetWindowAnchorHost(nullptr);
	}

	HostedWindowWidget = nullptr;
	HostedWindowSlot = nullptr;
	bHasActivatedRuntimeWindow = false;
	bHasObservedActivationPlacement = false;

	if (AnchorCanvas.IsValid())
	{
		AnchorCanvas->ClearChildren();
		AnchorCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
	}

	Super::OnSlotRemoved(InSlot);
}

TSharedRef<SWidget> UGenericWindowAnchor::RebuildWidget()
{
	SAssignNew(AnchorCanvas, SConstraintCanvas)
		.Visibility(EVisibility::SelfHitTestInvisible);

	SAssignNew(AnchorRootBox, SBox)
		.WidthOverride(TAttribute<FOptionalSize>::CreateLambda([this]()
		{
			return FOptionalSize(GetHostedWindowSize().X);
		}))
		.HeightOverride(TAttribute<FOptionalSize>::CreateLambda([this]()
		{
			return FOptionalSize(GetHostedWindowSize().Y);
		}))
		[
			AnchorCanvas.ToSharedRef()
		];

	RebuildHostedWindowSlot();

	return SNew(SGenericWindowAnchorRoot)
		.OwnerAnchor(this)
		[
			AnchorRootBox.ToSharedRef()
		];
}

void UGenericWindowAnchor::ReleaseSlateResources(bool bReleaseChildren)
{
	AnchorRootBox.Reset();
	HostedWindowSlot = nullptr;
	AnchorCanvas.Reset();
	Super::ReleaseSlateResources(bReleaseChildren);
}

void UGenericWindowAnchor::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	RefreshHostedWindowLayout();
}

#if WITH_EDITOR
void UGenericWindowAnchor::ValidateCompiledDefaults(IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);

	if (GetChildrenCount() == 0)
	{
		return;
	}

	if (!GetHostedWindow())
	{
		CompileLog.Error(FText::FromString(TEXT("GenericWindowAnchor only accepts UGenericWindowWidget as its child content.")));
	}
}

const FText UGenericWindowAnchor::GetPaletteCategory()
{
	return NSLOCTEXT("GenericWindowFramework", "WindowAnchorPaletteCategory", "Generic Window");
}
#endif

void UGenericWindowAnchor::HandleAnchorGeometryTick(const FGeometry& InGeometry)
{
	if (ShouldPreviewHostedWindowInAnchor())
	{
		bHasObservedActivationPlacement = false;
		return;
	}

	RefreshHostedWindowLayout();
	TryOpenHostedWindowFromAnchor(InGeometry);
}

void UGenericWindowAnchor::TryOpenHostedWindowFromAnchor(const FGeometry& InGeometry)
{
	if (bHasActivatedRuntimeWindow)
	{
		return;
	}

	UGenericWindowWidget* WindowWidget = GetHostedWindow();
	if (!WindowWidget)
	{
		return;
	}

	if (WindowWidget->IsWindowOpen())
	{
		bHasActivatedRuntimeWindow = true;
		return;
	}

	const ESlateVisibility WindowVisibility = WindowWidget->GetVisibility();
	if (WindowVisibility == ESlateVisibility::Collapsed || WindowVisibility == ESlateVisibility::Hidden)
	{
		return;
	}

	WindowWidget->HandleWindowDescriptorChanged();

	UGenericWindowRuntimeState* RuntimeState = WindowWidget->GetWindowRuntimeState();
	UGenericWindowDescriptor* Descriptor = WindowWidget->GetWindowDescriptor();
	if (!RuntimeState || !Descriptor)
	{
		return;
	}

	const FVector2D WindowSize = GetHostedWindowSize();
	if (WindowSize.X <= 0.0f || WindowSize.Y <= 0.0f)
	{
		return;
	}

	const FVector2D WindowTopLeftOffset = GetHostedWindowTopLeftOffset();
	const FVector2D DesiredDesktopTopLeft = InGeometry.LocalToAbsolute(WindowTopLeftOffset);
	FVector2D UnusedPixelTopLeft = FVector2D::ZeroVector;
	FVector2D DesiredViewportTopLeft = FVector2D::ZeroVector;
	USlateBlueprintLibrary::LocalToViewport(this, InGeometry, WindowTopLeftOffset, UnusedPixelTopLeft, DesiredViewportTopLeft);

	const bool bHasStablePlacement =
		bHasObservedActivationPlacement
		&& LastObservedViewportTopLeft.Equals(DesiredViewportTopLeft, 0.5f)
		&& LastObservedDesktopTopLeft.Equals(DesiredDesktopTopLeft, 0.5f)
		&& LastObservedWindowSize.Equals(WindowSize, 0.5f);

	LastObservedViewportTopLeft = DesiredViewportTopLeft;
	LastObservedDesktopTopLeft = DesiredDesktopTopLeft;
	LastObservedWindowSize = WindowSize;
	bHasObservedActivationPlacement = true;

	if (!bHasStablePlacement)
	{
		return;
	}

	FVector2D InitialPosition = DesiredViewportTopLeft;
	if (Descriptor->DragPolicy == EGenericWindowDragPolicy::AllowOutOfViewport)
	{
		InitialPosition = DesiredDesktopTopLeft;
	}

	UE_LOG(
		GenericLogUI,
		Log,
		TEXT("GenericWindowAnchor opening window. Policy=%d AnchorTopLeftOffset=(%.2f, %.2f) ViewportTopLeft=(%.2f, %.2f) DesktopTopLeft=(%.2f, %.2f) Size=(%.2f, %.2f)"),
		static_cast<int32>(Descriptor->DragPolicy),
		WindowTopLeftOffset.X,
		WindowTopLeftOffset.Y,
		DesiredViewportTopLeft.X,
		DesiredViewportTopLeft.Y,
		DesiredDesktopTopLeft.X,
		DesiredDesktopTopLeft.Y,
		WindowSize.X,
		WindowSize.Y);

	RuntimeState->SetLogicalRect(InitialPosition, WindowSize);
	RuntimeState->LastNormalPosition = InitialPosition;
	RuntimeState->LastNormalSize = WindowSize;

	bHasObservedActivationPlacement = false;
	bHasActivatedRuntimeWindow = true;
	WindowWidget->OpenWindow();
}

void UGenericWindowAnchor::RebuildHostedWindowSlot()
{
	HostedWindowWidget = GetHostedWindow();
	HostedWindowSlot = nullptr;

	if (!AnchorCanvas.IsValid())
	{
		return;
	}

	AnchorCanvas->ClearChildren();

	UGenericWindowWidget* WindowWidget = HostedWindowWidget.Get();
	if (!WindowWidget)
	{
		AnchorCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
		return;
	}

	if (!ShouldPreviewHostedWindowInAnchor())
	{
		WindowWidget->SetWindowAnchorHost(nullptr);
		AnchorCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
		return;
	}

	WindowWidget->SetWindowAnchorHost(this);

	AnchorCanvas->AddSlot()
		.Expose(HostedWindowSlot)
		.Anchors(FAnchors(0.0f))
		.Alignment(GetHostedWindowAlignment())
		.AutoSize(false)
		.Offset(GetHostedWindowOffset())
		[
			WindowWidget->TakeWidget()
		];

	AnchorCanvas->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
}

FVector2D UGenericWindowAnchor::GetHostedWindowSize() const
{
	if (const UGenericWindowWidget* WindowWidget = HostedWindowWidget.Get())
	{
		if (const UGenericWindowDescriptor* Descriptor = WindowWidget->GetWindowDescriptor())
		{
			return Descriptor->InitialRect.Size;
		}

		if (const UGenericWindowRuntimeState* RuntimeState = WindowWidget->GetWindowRuntimeState())
		{
			return RuntimeState->CurrentLogicalSize;
		}
	}

	return FVector2D(1.0f, 1.0f);
}

FMargin UGenericWindowAnchor::GetHostedWindowOffset() const
{
	const FVector2D Size = GetHostedWindowSize();
	return FMargin(0.0f, 0.0f, Size.X, Size.Y);
}

FVector2D UGenericWindowAnchor::GetHostedWindowTopLeftOffset() const
{
	const FVector2D Alignment = GetHostedWindowAlignment();
	const FVector2D Size = GetHostedWindowSize();
	return FVector2D(-Size.X * Alignment.X, -Size.Y * Alignment.Y);
}

FVector2D UGenericWindowAnchor::GetHostedWindowAlignment() const
{
	if (const UGenericWindowSlot* WindowSlot = GetGenericWindowSlot())
	{
		return WindowSlot->GetWindowAnchor();
	}

	return FVector2D::ZeroVector;
}

UGenericWindowSlot* UGenericWindowAnchor::GetGenericWindowSlot() const
{
	return Cast<UGenericWindowSlot>(GetContentSlot());
}

bool UGenericWindowAnchor::ShouldPreviewHostedWindowInAnchor() const
{
	const UWorld* World = GetWorld();
	return IsDesignTime() || World == nullptr || !World->IsGameWorld();
}
