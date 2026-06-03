// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Slate/GenericButton.h"

#include "Components/ButtonSlot.h"
#include "Input/Events.h"
#include "InputCoreTypes.h"
#include "Misc/EngineVersionComparison.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBackgroundBlur.h"
#include "Widgets/Layout/SBox.h"

namespace UE::GenericButtonFramework::Private
{
void ResetButtonSlotLayout(UButtonSlot& ButtonSlot)
{
	ButtonSlot.SetPadding(FMargin());
	ButtonSlot.SetHorizontalAlignment(HAlign_Fill);
	ButtonSlot.SetVerticalAlignment(VAlign_Fill);
}

class SGenericButton : public SButton
{
public:
	SGenericButton() = default;

	void SetDoubleClickedDelegate(FOnClicked InDoubleClickedDelegate)
	{
		DoubleClickedDelegate = MoveTemp(InDoubleClickedDelegate);
	}

	virtual FReply OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent) override
	{
		if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && DoubleClickedDelegate.IsBound())
		{
			return DoubleClickedDelegate.Execute();
		}

		return SButton::OnMouseButtonDoubleClick(InMyGeometry, InMouseEvent);
	}

private:
	FOnClicked DoubleClickedDelegate;
};
}

UGenericButton::UGenericButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericButton::SetBlurStrength(float InBlurStrength)
{
	BlurStrength = FMath::Max(0.0f, InBlurStrength);
	ApplyGenericButtonProperties();
}

void UGenericButton::SetBlurRadius(int32 InBlurRadius)
{
	BlurRadius = FMath::Max(0, InBlurRadius);
	ApplyGenericButtonProperties();
}

void UGenericButton::SetMinWidth(float InMinWidth)
{
	MinWidth = FMath::Max(0.0f, InMinWidth);
	ApplyGenericButtonProperties();
}

void UGenericButton::SetMinHeight(float InMinHeight)
{
	MinHeight = FMath::Max(0.0f, InMinHeight);
	ApplyGenericButtonProperties();
}

void UGenericButton::SetInteractionEnabled(bool bInInteractionEnabled)
{
	bInteractionEnabled = bInInteractionEnabled;
}

void UGenericButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	ApplyGenericButtonProperties();
}

void UGenericButton::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MySizeBox.Reset();
	MyBackgroundBlur.Reset();
}

TSharedRef<SWidget> UGenericButton::RebuildWidget()
{
	TSharedRef<UE::GenericButtonFramework::Private::SGenericButton> GenericButton = MakeShared<UE::GenericButtonFramework::Private::SGenericButton>();

	SButton::FArguments ButtonArguments;
	ButtonArguments
		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleGenericClicked))
		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressed))
		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleReleased))
		.OnHovered_UObject(this, &ThisClass::SlateHandleHovered)
		.OnUnhovered_UObject(this, &ThisClass::SlateHandleUnhovered)
#if !UE_VERSION_OLDER_THAN(5, 7, 0)
		.OnReceivedFocus_UObject(this, &ThisClass::SlateHandleOnReceivedFocus)
		.OnLostFocus_UObject(this, &ThisClass::SlateHandleOnLostFocus)
		.OnSlateButtonDragDetected(BIND_UOBJECT_DELEGATE(FOnDragDetected, SlateHandleDragDetected))
		.OnSlateButtonDragEnter(BIND_UOBJECT_DELEGATE(FOnDragEnter, SlateHandleDragEnter))
		.OnSlateButtonDragLeave(BIND_UOBJECT_DELEGATE(FOnDragLeave, SlateHandleDragLeave))
		.OnSlateButtonDragOver(BIND_UOBJECT_DELEGATE(FOnDragOver, SlateHandleDragOver))
		.OnSlateButtonDrop(BIND_UOBJECT_DELEGATE(FOnDrop, SlateHandleDrop))
#endif
		.ButtonStyle(&GetStyle())
		.ContentPadding(FMargin())
#if !UE_VERSION_OLDER_THAN(5, 7, 0)
		.NormalPaddingOverride(FMargin())
		.PressedPaddingOverride(FMargin())
#endif
		.ClickMethod(GetClickMethod())
		.TouchMethod(GetTouchMethod())
		.PressMethod(GetPressMethod())
		.IsFocusable(GetIsFocusable());
#if !UE_VERSION_OLDER_THAN(5, 7, 0)
	ButtonArguments
		.AllowDragDrop(bAllowDragDrop)
		;
#endif

	GenericButton->Construct(ButtonArguments);
	GenericButton->SetDoubleClickedDelegate(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleGenericDoubleClicked));

	MyButton = GenericButton;

	if (GetChildrenCount() > 0)
	{
		if (UButtonSlot* ButtonSlot = Cast<UButtonSlot>(GetContentSlot()))
		{
			UE::GenericButtonFramework::Private::ResetButtonSlotLayout(*ButtonSlot);
			ButtonSlot->BuildSlot(MyButton.ToSharedRef());
		}
	}

	TSharedRef<SWidget> ButtonWidget = MyButton.ToSharedRef();
	SAssignNew(MyBackgroundBlur, SBackgroundBlur)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin())
	[
		ButtonWidget
	];

	SAssignNew(MySizeBox, SBox)
	[
		MyBackgroundBlur.ToSharedRef()
	];

	ApplyGenericButtonProperties();
	return MySizeBox.ToSharedRef();
}

void UGenericButton::OnSlotAdded(UPanelSlot* InSlot)
{
	if (UButtonSlot* ButtonSlot = Cast<UButtonSlot>(InSlot))
	{
		UE::GenericButtonFramework::Private::ResetButtonSlotLayout(*ButtonSlot);
	}

	Super::OnSlotAdded(InSlot);
}

#if WITH_EDITOR
void UGenericButton::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	ApplyGenericButtonProperties();
	InvalidateLayoutAndVolatility();
}
#endif

FReply UGenericButton::SlateHandleGenericClicked()
{
	if (!bInteractionEnabled)
	{
		return FReply::Handled();
	}

	return SlateHandleClicked();
}

FReply UGenericButton::SlateHandleGenericDoubleClicked()
{
	if (!bInteractionEnabled)
	{
		return FReply::Handled();
	}

	OnDoubleClickedEvent.Broadcast();
	return FReply::Handled();
}

void UGenericButton::ApplyGenericButtonProperties()
{
	if (MySizeBox.IsValid())
	{
		MySizeBox->SetMinDesiredWidth(MinWidth > 0.0f ? FOptionalSize(MinWidth) : FOptionalSize());
		MySizeBox->SetMinDesiredHeight(MinHeight > 0.0f ? FOptionalSize(MinHeight) : FOptionalSize());
	}

	if (MyBackgroundBlur.IsValid())
	{
		MyBackgroundBlur->SetHAlign(HAlign_Fill);
		MyBackgroundBlur->SetVAlign(VAlign_Fill);
		MyBackgroundBlur->SetPadding(FMargin());
		MyBackgroundBlur->SetBlurStrength(BlurStrength);
		MyBackgroundBlur->SetBlurRadius(BlurRadius > 0 ? TOptional<int32>(BlurRadius) : TOptional<int32>());
	}
}
