#include "UI/GenericPropertyCategoryWidget.h"

#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "Core/GenericProperty.h"
#include "Core/GenericPropertyCategory.h"
#include "UI/GenericPropertyPanelWidget.h"
#include "UI/GenericPropertyRowWidget.h"

UGenericPropertyCategoryWidget::UGenericPropertyCategoryWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericPropertyCategoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ListView_Properties)
	{
		ListView_Properties->OnEntryWidgetGenerated().AddUObject(this, &UGenericPropertyCategoryWidget::HandlePropertyEntryWidgetGenerated);
	}

	if (PropertyCategory && bAutoRebuildChildrenOnListChanged)
	{
		RebuildGeneratedChildren();
	}
}

void UGenericPropertyCategoryWidget::NativeDestruct()
{
	if (ListView_Properties)
	{
		ListView_Properties->OnEntryWidgetGenerated().RemoveAll(this);
	}

	ClearGeneratedChildren();

	if (PropertyCategory)
	{
		PropertyCategory->Delegate_OnListChanged.RemoveAll(this);
	}

	Super::NativeDestruct();
}

void UGenericPropertyCategoryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	SetPropertyCategory(Cast<UGenericPropertyCategory>(ListItemObject));
}

void UGenericPropertyCategoryWidget::NativeOnEntryReleased()
{
	SetPropertyCategory(nullptr);
}

UGenericPropertyCategory* UGenericPropertyCategoryWidget::GetPropertyCategory() const
{
	return PropertyCategory;
}

void UGenericPropertyCategoryWidget::SetPropertyCategory(UGenericPropertyCategory* InPropertyCategory)
{
	if (PropertyCategory == InPropertyCategory)
	{
		return;
	}

	if (UGenericPropertyCategory* PreviousList = PropertyCategory)
	{
		PreviousList->Delegate_OnListChanged.RemoveAll(this);
		OnPropertyCategoryCleared(PreviousList);
		OnPropertyListClearedEvent.Broadcast(this, PreviousList);
	}

	PropertyCategory = InPropertyCategory;

	ClearGeneratedChildren();

	if (PropertyCategory)
	{
		PropertyCategory->Delegate_OnListChanged.AddUObject(this, &UGenericPropertyCategoryWidget::HandlePropertyCategoryChanged);

		OnPropertyCategorySet(PropertyCategory);
		OnPropertyListSetEvent.Broadcast(this, PropertyCategory);
		HandlePropertyCategoryChanged(PropertyCategory);
	}
}

UGenericPropertyPanelWidget* UGenericPropertyCategoryWidget::GetOwningPropertyPanelWidget() const
{
	return OwningPropertyPanelWidget;
}

void UGenericPropertyCategoryWidget::SetOwningPropertyPanelWidget(UGenericPropertyPanelWidget* InOwningPanelWidget)
{
	OwningPropertyPanelWidget = InOwningPanelWidget;

	if (PropertyCategory && bAutoRebuildChildrenOnListChanged)
	{
		RebuildGeneratedChildren();
	}
}

TArray<UGenericProperty*> UGenericPropertyCategoryWidget::GetVisiblePropertyViewModels() const
{
	TArray<UGenericProperty*> VisibleViewModels;
	if (PropertyCategory == nullptr)
	{
		return VisibleViewModels;
	}

	for (UGenericProperty* ViewModel : PropertyCategory->Properties)
	{
		if (IsValid(ViewModel) && ViewModel->bIsVisible)
		{
			VisibleViewModels.Add(ViewModel);
		}
	}

	return VisibleViewModels;
}

void UGenericPropertyCategoryWidget::RebuildGeneratedChildren()
{
	ClearGeneratedChildren();

	TArray<UObject*> PropertyItems;
	for (UGenericProperty* ViewModel : GetVisiblePropertyViewModels())
	{
		PropertyItems.Add(ViewModel);
	}

	if (ListView_Properties)
	{
		ListView_Properties->SetListItems(PropertyItems);
	}
}

void UGenericPropertyCategoryWidget::ClearGeneratedChildren()
{
	if (ListView_Properties)
	{
		ListView_Properties->ClearListItems();
	}

}

void UGenericPropertyCategoryWidget::OnPropertyCategorySet_Implementation(UGenericPropertyCategory* InPropertyCategory)
{
}

void UGenericPropertyCategoryWidget::OnPropertyCategoryCleared_Implementation(UGenericPropertyCategory* InPreviousCategory)
{
}

void UGenericPropertyCategoryWidget::OnPropertyCategoryChanged_Implementation(UGenericPropertyCategory* InPropertyCategory)
{
}

void UGenericPropertyCategoryWidget::HandlePropertyCategoryChanged(UGenericPropertyCategory* InPropertyCategory)
{
	if (InPropertyCategory != PropertyCategory)
	{
		return;
	}

	OnPropertyCategoryChanged(InPropertyCategory);
	OnPropertyListChangedEvent.Broadcast(this, InPropertyCategory);

	if (bAutoRebuildChildrenOnListChanged)
	{
		RebuildGeneratedChildren();
	}
}

void UGenericPropertyCategoryWidget::HandlePropertyEntryWidgetGenerated(UUserWidget& InWidget)
{
	if (UGenericPropertyRowWidget* RowWidget = Cast<UGenericPropertyRowWidget>(&InWidget))
	{
		RowWidget->SetOwningPropertyPanelWidget(OwningPropertyPanelWidget);
		RowWidget->SetOwningPropertyCategoryWidget(this);

		if (IsValid(RowWidget->GetProperty()))
		{
			RowWidget->RebuildGeneratedChildren();
		}
	}
}
