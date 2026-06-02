#include "UI/GenericPropertyRowName.h"

#include "Core/GenericProperty.h"

UGenericPropertyRowName::UGenericPropertyRowName(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericPropertyRowName::NativeDestruct()
{
	if (Property != nullptr)
	{
		Property->Delegate_OnViewModelChanged.RemoveAll(this);
	}

	Super::NativeDestruct();
}

UGenericProperty* UGenericPropertyRowName::GetProperty() const
{
	return Property;
}

void UGenericPropertyRowName::SetProperty(UGenericProperty* InProperty)
{
	if (Property == InProperty)
	{
		SyncWidgetPresentationFromProperty();
		return;
	}

	if (UGenericProperty* PreviousProperty = Property)
	{
		PreviousProperty->Delegate_OnViewModelChanged.RemoveAll(this);
		OnPropertyCleared(PreviousProperty);
		OnPropertyClearedEvent.Broadcast(this, PreviousProperty);
	}

	Property = InProperty;

	if (Property != nullptr)
	{
		Property->Delegate_OnViewModelChanged.AddUObject(this, &UGenericPropertyRowName::HandlePropertyChanged);
		OnPropertySet(Property);
		OnPropertySetEvent.Broadcast(this, Property);
	}

	HandlePropertyChanged(Property, true);
}

void UGenericPropertyRowName::OnPropertySet_Implementation(UGenericProperty* InProperty)
{
}

void UGenericPropertyRowName::OnPropertyCleared_Implementation(UGenericProperty* InPreviousProperty)
{
}

void UGenericPropertyRowName::OnPropertyChanged_Implementation(UGenericProperty* InProperty, bool bStructureChanged)
{
}

void UGenericPropertyRowName::OnPrimaryNameChanged_Implementation(const FText& InPrimaryName)
{
}

void UGenericPropertyRowName::OnSecondaryNameChanged_Implementation(const FText& InSecondaryName)
{
}

void UGenericPropertyRowName::OnTooltipTextChanged_Implementation(const FText& InTooltipText)
{
	if (!InTooltipText.IsEmpty())
	{
		SetToolTipText(InTooltipText);
	}
}

void UGenericPropertyRowName::OnVisibilityChanged_Implementation(ESlateVisibility InVisibility)
{
	SetVisibility(InVisibility);
}

void UGenericPropertyRowName::SyncWidgetPresentationFromProperty() const
{
	FText PrimaryName = FText::GetEmpty();
	FText TooltipText = FText::GetEmpty();
	ESlateVisibility WidgetVisibility = ESlateVisibility::Collapsed;

	if (Property != nullptr)
	{
		PrimaryName = Property->DisplayName;
		TooltipText = Property->ToolTip;
		WidgetVisibility = Property->bIsVisible ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed;
	}

	UGenericPropertyRowName* MutableThis = const_cast<UGenericPropertyRowName*>(this);

	MutableThis->OnPrimaryNameChanged(PrimaryName);
	MutableThis->OnSecondaryNameChanged(FText::GetEmpty());
	MutableThis->OnTooltipTextChanged(TooltipText);
	MutableThis->OnVisibilityChanged(WidgetVisibility);
}

void UGenericPropertyRowName::HandlePropertyChanged(UGenericProperty* InProperty, const bool bStructureChanged)
{
	if (InProperty != Property)
	{
		return;
	}

	SyncWidgetPresentationFromProperty();
	OnPropertyChanged(InProperty, bStructureChanged);
	OnPropertyChangedEvent.Broadcast(this, InProperty, bStructureChanged);
}
