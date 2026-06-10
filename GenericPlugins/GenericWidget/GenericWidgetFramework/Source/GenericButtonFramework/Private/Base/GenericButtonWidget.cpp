// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericButtonWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/PanelWidget.h"
#include "GameplayMessageSubsystem.h"
#include "Slate/GenericButton.h"
#include "Slate/GenericButtonStyle.h"
#include "Type/GenericType.h"

namespace
{
	template <typename MessageType>
	void FillButtonMessage(UGenericButtonWidget* ButtonWidget, MessageType& Message)
	{
		Message.PlayerController = ButtonWidget ? ButtonWidget->GetOwningPlayer() : nullptr;
		Message.ButtonTag = ButtonWidget ? ButtonWidget->GetButtonTag() : FGameplayTag();
		Message.ButtonWidget = ButtonWidget;
	}

	template <typename MessageType>
	void BroadcastButtonMessage(UGenericButtonWidget* ButtonWidget, FGameplayTag Channel, MessageType& Message)
	{
		if (!ButtonWidget || !UGameplayMessageSubsystem::HasInstance(ButtonWidget))
		{
			return;
		}

		UGameplayMessageSubsystem::Get(ButtonWidget).BroadcastMessage(Channel, Message);
	}
}

UGenericButtonWidget::UGenericButtonWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericButtonWidget::SetButtonTag(FGameplayTag InButtonTag)
{
	ButtonTag = InButtonTag;
}

FGameplayTag UGenericButtonWidget::GetButtonTag() const
{
	return ButtonTag;
}

void UGenericButtonWidget::SetButtonEnabled(bool bInButtonEnabled)
{
	if (bButtonEnabled == bInButtonEnabled)
	{
		return;
	}

	bButtonEnabled = bInButtonEnabled;
	RefreshButtonState();

	if (bButtonEnabled)
	{
		SetOnButtonEnabledInternal();
	}
	else
	{
		SetOnButtonDisabledInternal();
	}
}

bool UGenericButtonWidget::GetButtonEnabled() const
{
	return bButtonEnabled;
}

void UGenericButtonWidget::SetButtonInteractionEnabled(bool bInInteractionEnabled)
{
	bInteractionEnabled = bInInteractionEnabled;
}

bool UGenericButtonWidget::GetButtonInteractionEnabled() const
{
	return bInteractionEnabled;
}

void UGenericButtonWidget::SetButtonSelectable(bool bInSelectable)
{
	bSelectable = bInSelectable;
}

bool UGenericButtonWidget::GetButtonSelectable() const
{
	return bSelectable;
}

void UGenericButtonWidget::SetButtonToggleable(bool bInToggleable)
{
	bToggleable = bInToggleable;
}

bool UGenericButtonWidget::GetButtonToggleable() const
{
	return bToggleable;
}

void UGenericButtonWidget::SetButtonDefaultSelected(bool bInDefaultSelected)
{
	bDefaultSelected = bInDefaultSelected;
}

bool UGenericButtonWidget::GetButtonDefaultSelected() const
{
	return bDefaultSelected;
}

void UGenericButtonWidget::SetButtonSelected(bool bInSelected)
{
	if (bSelected == bInSelected)
	{
		return;
	}

	bSelected = bInSelected;
	RefreshButtonState();

	if (CanExecuteButtonInteraction())
	{
		SetOnButtonSelectionChangedInternal(bSelected);
	}
}

bool UGenericButtonWidget::GetButtonSelected() const
{
	return bSelected;
}

UGenericButton* UGenericButtonWidget::GetWrappedButton() const
{
	return WrappedButton;
}

TSharedRef<SWidget> UGenericButtonWidget::RebuildWidget()
{
	EnsureGenericButtonWrapper();
	return Super::RebuildWidget();
}

void UGenericButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	EnsureGenericButtonWrapper();
	InitializeSelectionState();
	RefreshButtonState();
}

void UGenericButtonWidget::NativePreConstruct()
{
	EnsureGenericButtonWrapper();
	InitializeSelectionState();
	RefreshButtonState();

	Super::NativePreConstruct();
}

void UGenericButtonWidget::NativeConstruct()
{
	EnsureGenericButtonWrapper();
	InitializeSelectionState();
	BindWrappedButtonEvents();
	RefreshButtonState();

	Super::NativeConstruct();
}

void UGenericButtonWidget::NativeDestruct()
{
	UnbindWrappedButtonEvents();
	Super::NativeDestruct();
}

#if WITH_EDITOR
void UGenericButtonWidget::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	EnsureGenericButtonWrapper();
	InitializeSelectionState();
	RefreshButtonState();
}
#endif

void UGenericButtonWidget::SimulateButtonPressed()
{
	HandleOnButtonPressedInternal();
}

void UGenericButtonWidget::SimulateButtonReleased()
{
	HandleOnButtonReleasedInternal();
}

void UGenericButtonWidget::SimulateButtonClick()
{
	HandleOnButtonClickedInternal();
}

void UGenericButtonWidget::SimulateButtonDoubleClick()
{
	SimulateButtonClick();

	if (CanExecuteButtonInteraction())
	{
		HandleOnButtonDoubleClickedInternal();
	}
}

void UGenericButtonWidget::HandleOnButtonPressedInternal()
{
	RefreshButtonState();
	SetOnButtonPressedInternal();
}

void UGenericButtonWidget::HandleOnButtonReleasedInternal()
{
	RefreshButtonState();
	SetOnButtonReleasedInternal();
}

void UGenericButtonWidget::HandleOnButtonHoveredInternal()
{
	RefreshButtonState();
	SetOnButtonHoveredInternal();
}

void UGenericButtonWidget::HandleOnButtonUnhoveredInternal()
{
	RefreshButtonState();
	SetOnButtonUnhoveredInternal();
}

void UGenericButtonWidget::HandleOnButtonClickedInternal()
{
	SetOnButtonClickedInternal();
}

void UGenericButtonWidget::HandleOnButtonDoubleClickedInternal()
{
	SetOnButtonDoubleClickedInternal();
}

void UGenericButtonWidget::SetOnButtonEnabledInternal()
{
	NativeOnButtonEnabled();
}

void UGenericButtonWidget::SetOnButtonDisabledInternal()
{
	NativeOnButtonDisabled();
}

void UGenericButtonWidget::SetOnButtonPressedInternal()
{
	if (CanExecuteButtonInteraction())
	{
		NativeOnButtonPressed();
	}
}

void UGenericButtonWidget::SetOnButtonReleasedInternal()
{
	if (CanExecuteButtonInteraction())
	{
		NativeOnButtonReleased();
	}
}

void UGenericButtonWidget::SetOnButtonHoveredInternal()
{
	if (CanExecuteButtonHover())
	{
		NativeOnButtonHovered();
	}
}

void UGenericButtonWidget::SetOnButtonUnhoveredInternal()
{
	if (CanExecuteButtonHover())
	{
		NativeOnButtonUnhovered();
	}
}

void UGenericButtonWidget::SetOnButtonClickedInternal()
{
	if (!CanExecuteButtonInteraction())
	{
		return;
	}

	if (bSelectable)
	{
		if (!bSelected)
		{
			SetButtonSelected(true);
		}
		else if (bToggleable)
		{
			SetButtonSelected(false);
		}
	}

	NativeOnButtonClicked();
}

void UGenericButtonWidget::SetOnButtonDoubleClickedInternal()
{
	if (CanExecuteButtonInteraction())
	{
		NativeOnButtonDoubleClicked();
	}
}

void UGenericButtonWidget::SetOnButtonSelectionChangedInternal(bool bInSelected)
{
	if (CanExecuteButtonInteraction())
	{
		NativeOnButtonSelectionChanged(bInSelected);
	}
}

void UGenericButtonWidget::SetOnButtonStyleChangedInternal()
{
	NativeOnButtonStyleChanged();
}

void UGenericButtonWidget::NativeOnButtonEnabled()
{
	HandleOnButtonEnabled();

	FOnButtonEnabledMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonEnabled, Message);
	Delegate_OnButtonEnabledEvent.Broadcast();
}

void UGenericButtonWidget::NativeOnButtonDisabled()
{
	HandleOnButtonDisabled();

	FOnButtonDisabledMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonDisabled, Message);
	Delegate_OnButtonDisabledEvent.Broadcast();
}

void UGenericButtonWidget::NativeOnButtonPressed()
{
	HandleOnButtonPressed();

	FOnButtonPressedMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonPressed, Message);
	Delegate_OnButtonPressedEvent.Broadcast();
}

void UGenericButtonWidget::NativeOnButtonReleased()
{
	HandleOnButtonReleased();

	FOnButtonReleasedMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonReleased, Message);
	Delegate_OnButtonReleasedEvent.Broadcast();
}

void UGenericButtonWidget::NativeOnButtonHovered()
{
	HandleOnButtonHovered();

	FOnButtonHoveredMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonHovered, Message);
	Delegate_OnButtonHoveredEvent.Broadcast();
}

void UGenericButtonWidget::NativeOnButtonUnhovered()
{
	HandleOnButtonUnhovered();

	FOnButtonUnhoveredMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonUnhovered, Message);
	Delegate_OnButtonUnhoveredEvent.Broadcast();
}

void UGenericButtonWidget::NativeOnButtonClicked()
{
	HandleOnButtonClicked();

	FOnButtonClickedMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonClicked, Message);
	Delegate_OnButtonClickedEvent.Broadcast();
}

void UGenericButtonWidget::NativeOnButtonDoubleClicked()
{
	HandleOnButtonDoubleClicked();

	FOnButtonDoubleClickedMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonDoubleClicked, Message);
	Delegate_OnButtonDoubleClickedEvent.Broadcast();
}

void UGenericButtonWidget::NativeOnButtonSelectionChanged(bool bInSelected)
{
	HandleOnButtonSelectionChanged(bInSelected);

	FOnButtonSelectionChangedMessage Message;
	FillButtonMessage(this, Message);
	Message.bSelected = bInSelected;
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonSelectionChanged, Message);
	Delegate_OnButtonSelectionChangedEvent.Broadcast(bInSelected);
}

void UGenericButtonWidget::NativeOnButtonStyleChanged()
{
	HandleOnButtonStyleChanged();

	FOnButtonStyleChangedMessage Message;
	FillButtonMessage(this, Message);
	BroadcastButtonMessage(this, TAG_GameplayMessage_Channel_UI_OnButtonStyleChanged, Message);
	Delegate_OnButtonStyleChangedEvent.Broadcast();
}

void UGenericButtonWidget::EnsureGenericButtonWrapper()
{
	if (!WidgetTree)
	{
		return;
	}

	if (WrappedButton && WidgetTree->RootWidget == WrappedButton)
	{
		return;
	}

	if (UGenericButton* ExistingRootButton = Cast<UGenericButton>(WidgetTree->RootWidget))
	{
		WrappedButton = ExistingRootButton;
		return;
	}

	UWidget* OriginalRoot = WidgetTree->RootWidget;
	UGenericButton* NewButton = WidgetTree->ConstructWidget<UGenericButton>(
		UGenericButton::StaticClass(),
		MakeUniqueObjectName(WidgetTree, UGenericButton::StaticClass(), TEXT("GenericButton"))
	);

	if (!NewButton)
	{
		return;
	}

	if (OriginalRoot)
	{
		int32 ChildIndex = INDEX_NONE;
		if (UPanelWidget* ParentWidget = UWidgetTree::FindWidgetParent(OriginalRoot, ChildIndex))
		{
			ParentWidget->RemoveChild(OriginalRoot);
		}

		NewButton->SetContent(OriginalRoot);
	}

	WidgetTree->RootWidget = NewButton;
	WrappedButton = NewButton;
}

void UGenericButtonWidget::BindWrappedButtonEvents()
{
	if (!WrappedButton)
	{
		return;
	}

	UnbindWrappedButtonEvents();

	WrappedButton->OnPressed.AddDynamic(this, &ThisClass::HandleOnButtonPressedInternal);
	WrappedButton->OnReleased.AddDynamic(this, &ThisClass::HandleOnButtonReleasedInternal);
	WrappedButton->OnHovered.AddDynamic(this, &ThisClass::HandleOnButtonHoveredInternal);
	WrappedButton->OnUnhovered.AddDynamic(this, &ThisClass::HandleOnButtonUnhoveredInternal);
	WrappedButton->OnClicked.AddDynamic(this, &ThisClass::HandleOnButtonClickedInternal);
	WrappedButton->OnDoubleClickedEvent.AddDynamic(this, &ThisClass::HandleOnButtonDoubleClickedInternal);
}

void UGenericButtonWidget::UnbindWrappedButtonEvents()
{
	if (!WrappedButton)
	{
		return;
	}

	WrappedButton->OnPressed.RemoveDynamic(this, &ThisClass::HandleOnButtonPressedInternal);
	WrappedButton->OnReleased.RemoveDynamic(this, &ThisClass::HandleOnButtonReleasedInternal);
	WrappedButton->OnHovered.RemoveDynamic(this, &ThisClass::HandleOnButtonHoveredInternal);
	WrappedButton->OnUnhovered.RemoveDynamic(this, &ThisClass::HandleOnButtonUnhoveredInternal);
	WrappedButton->OnClicked.RemoveDynamic(this, &ThisClass::HandleOnButtonClickedInternal);
	WrappedButton->OnDoubleClickedEvent.RemoveDynamic(this, &ThisClass::HandleOnButtonDoubleClickedInternal);
}

void UGenericButtonWidget::InitializeSelectionState()
{
	if (IsDesignTime())
	{
		bSelected = bDefaultSelected;
		return;
	}

	if (!bSelectionInitialized)
	{
		bSelected = bDefaultSelected;
		bSelectionInitialized = true;
	}
}

void UGenericButtonWidget::RefreshButtonState(bool bForceStyleChangedEvent)
{
	if (!WrappedButton)
	{
		return;
	}

	WrappedButton->SetInteractionEnabled(true);

	const UGenericButtonStyle* CurrentStyle = GetCurrentStyle();
	const bool bCanBroadcastStyleChanged = !IsTemplate();
	const bool bShouldBroadcastStyleChanged = bCanBroadcastStyleChanged
		&& bHasAppliedButtonStyle
		&& (bForceStyleChangedEvent || AppliedButtonStyle.Get() != CurrentStyle);

	WrappedButton->SetStyle(CurrentStyle ? CurrentStyle->ToButtonStyle() : UGenericButtonStyle::MakeTransparentButtonStyle());
	WrappedButton->SynchronizeProperties();
	WrappedButton->InvalidateLayoutAndVolatility();

	if (bShouldBroadcastStyleChanged)
	{
		SetOnButtonStyleChangedInternal();
	}

	AppliedButtonStyle = const_cast<UGenericButtonStyle*>(CurrentStyle);
	bHasAppliedButtonStyle = true;
}

bool UGenericButtonWidget::CanExecuteButtonInteraction() const
{
	return bButtonEnabled && bInteractionEnabled;
}

bool UGenericButtonWidget::CanExecuteButtonHover() const
{
	return bInteractionEnabled;
}

const UGenericButtonStyle* UGenericButtonWidget::GetCurrentStyle() const
{
#if WITH_EDITORONLY_DATA
	if (IsDesignTime())
	{
		switch (DesiredButtonStyle)
		{
		case EGenericButtonDesiredStyle::Disabled:
			return DisabledStyle;
		case EGenericButtonDesiredStyle::Selected:
			return SelectedStyle;
		case EGenericButtonDesiredStyle::Normal:
		default:
			return NormalStyle;
		}
	}
#endif

	if (!bButtonEnabled)
	{
		return DisabledStyle;
	}

	if (bSelected)
	{
		return SelectedStyle;
	}

	return NormalStyle;
}
