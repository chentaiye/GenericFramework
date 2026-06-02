#include "UI/GenericPropertyRowWidget.h"

#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "Core/GenericProperty.h"
#include "UI/GenericPropertyCategoryWidget.h"
#include "UI/GenericPropertyRowName.h"
#include "UI/GenericPropertyRowValueSpawner.h"

UGenericPropertyRowWidget::UGenericPropertyRowWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericPropertyRowWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ListView_ChildProperties)
	{
		ListView_ChildProperties->OnEntryWidgetGenerated().AddUObject(this, &UGenericPropertyRowWidget::HandleChildPropertyEntryWidgetGenerated);
	}

	if (Property && bAutoRebuildChildrenOnPropertyChanged)
	{
		RebuildGeneratedChildren();
	}

	SyncBoundPropertyWidgets();
}

void UGenericPropertyRowWidget::NativeDestruct()
{
	if (ListView_ChildProperties)
	{
		ListView_ChildProperties->OnEntryWidgetGenerated().RemoveAll(this);
	}

	if (Property)
	{
		Property->Delegate_OnViewModelChanged.RemoveAll(this);
	}

	if (GenericPropertyRowName)
	{
		GenericPropertyRowName->SetProperty(nullptr);
	}

	if (GenericPropertyValue)
	{
		GenericPropertyValue->SetProperty(nullptr);
	}

	ClearGeneratedChildren();

	Super::NativeDestruct();
}

void UGenericPropertyRowWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	SetProperty(Cast<UGenericProperty>(ListItemObject));
}

void UGenericPropertyRowWidget::NativeOnEntryReleased()
{
	SetProperty(nullptr);
}

UGenericProperty* UGenericPropertyRowWidget::GetProperty() const
{
	return Property;
}

void UGenericPropertyRowWidget::SetProperty(UGenericProperty* InProperty)
{
	if (Property == InProperty)
	{
		SyncBoundPropertyWidgets();
		return;
	}

	if (UGenericProperty* PreviousViewModel = Property)
	{
		PreviousViewModel->Delegate_OnViewModelChanged.RemoveAll(this);
		OnPropertyCleared(PreviousViewModel);
		OnPropertyViewModelClearedEvent.Broadcast(this, PreviousViewModel);
	}

	Property = InProperty;

	ClearGeneratedChildren();
	SyncBoundPropertyWidgets();

	if (Property)
	{
		Property->Delegate_OnViewModelChanged.AddUObject(this, &UGenericPropertyRowWidget::HandlePropertyChanged);

		OnPropertySet(Property);
		OnPropertyViewModelSetEvent.Broadcast(this, Property);
		HandlePropertyChanged(Property, true);
	}
}

UGenericPropertyPanelWidget* UGenericPropertyRowWidget::GetOwningPropertyPanelWidget() const
{
	return OwningPropertyPanelWidget;
}

void UGenericPropertyRowWidget::SetOwningPropertyPanelWidget(UGenericPropertyPanelWidget* InOwningPanelWidget)
{
	OwningPropertyPanelWidget = InOwningPanelWidget;

	if (Property && bAutoRebuildChildrenOnPropertyChanged)
	{
		RebuildGeneratedChildren();
	}
}

UGenericPropertyCategoryWidget* UGenericPropertyRowWidget::GetOwningPropertyCategoryWidget() const
{
	return OwningPropertyCategoryWidget;
}

void UGenericPropertyRowWidget::SetOwningPropertyCategoryWidget(UGenericPropertyCategoryWidget* InOwningCategoryWidget)
{
	OwningPropertyCategoryWidget = InOwningCategoryWidget;

	if (Property && bAutoRebuildChildrenOnPropertyChanged)
	{
		RebuildGeneratedChildren();
	}
}

TArray<UGenericProperty*> UGenericPropertyRowWidget::GetVisibleChildPropertyViewModels() const
{
	TArray<UGenericProperty*> VisibleChildren;
	if (Property == nullptr || !Property->bCanExpand || !Property->bIsExpanded)
	{
		return VisibleChildren;
	}

	for (UGenericProperty* ChildViewModel : Property->Children)
	{
		if (ChildViewModel && ChildViewModel->bIsVisible)
		{
			VisibleChildren.Add(ChildViewModel);
		}
	}

	return VisibleChildren;
}

FText UGenericPropertyRowWidget::GetPropertyDisplayValueText() const
{
	if (Property == nullptr)
	{
		return FText::GetEmpty();
	}

	if (Property->bHasMixedValues)
	{
		return FText::FromString(TEXT("<Multiple Values>"));
	}

	if (Property->NodeKind == EGenericPropertyNodeKind::Warning && Property->Issue.IsSet())
	{
		return Property->Issue.Message;
	}

	return FText::FromString(Property->TextState.CurrentValue);
}

FText UGenericPropertyRowWidget::GetPropertyFeedbackText() const
{
	if (Property == nullptr)
	{
		return FText::FromString(TEXT("!!! Property Is InValid !!!"));
	}

	if (Property->Issue.IsSet())
	{
		return Property->Issue.Message;
	}

	return FText::GetEmpty();
}

bool UGenericPropertyRowWidget::ApplyPropertyValue()
{
	if (Property == nullptr)
	{
		return false;
	}

	const bool bResult = Property->Apply();
	if (!bResult)
	{
		BroadcastPropertyOperationFailed(Property->Issue.Message);
	}

	return bResult;
}

bool UGenericPropertyRowWidget::ResetPropertyValue(const EGenericPropertyResetMode InMode)
{
	if (Property == nullptr)
	{
		return false;
	}

	const bool bResult = Property->Reset(InMode);
	if (!bResult)
	{
		BroadcastPropertyOperationFailed(GetPropertyFeedbackText());
	}

	return bResult;
}

bool UGenericPropertyRowWidget::ResetPropertyValueToDefault()
{
	return ResetPropertyValue(DefaultResetMode);
}

void UGenericPropertyRowWidget::SetPropertyExpanded(const bool bInExpanded)
{
	if (Property)
	{
		Property->SetExpanded(bInExpanded);
	}
}

void UGenericPropertyRowWidget::TogglePropertyExpanded()
{
	if (Property)
	{
		Property->SetExpanded(!Property->bIsExpanded);
	}
}

bool UGenericPropertyRowWidget::AddPropertyContainerElement()
{
	if (Property == nullptr)
	{
		return false;
	}

	const bool bResult = Property->AddContainerElement();
	if (!bResult)
	{
		BroadcastPropertyOperationFailed(GetPropertyFeedbackText());
	}

	return bResult;
}

bool UGenericPropertyRowWidget::RemovePropertyNode()
{
	if (Property == nullptr)
	{
		return false;
	}

	const bool bResult = Property->RemoveNode();
	if (!bResult)
	{
		BroadcastPropertyOperationFailed(GetPropertyFeedbackText());
	}

	return bResult;
}

bool UGenericPropertyRowWidget::DuplicatePropertyNode()
{
	if (Property == nullptr)
	{
		return false;
	}

	const bool bResult = Property->DuplicateNode();
	if (!bResult)
	{
		BroadcastPropertyOperationFailed(GetPropertyFeedbackText());
	}

	return bResult;
}

bool UGenericPropertyRowWidget::MovePropertyArrayElement(const int32 InNewIndex)
{
	if (Property == nullptr)
	{
		return false;
	}

	const bool bResult = Property->MoveArrayElement(InNewIndex);
	if (!bResult)
	{
		BroadcastPropertyOperationFailed(GetPropertyFeedbackText());
	}

	return bResult;
}

bool UGenericPropertyRowWidget::ClearPropertyContainer()
{
	if (Property == nullptr)
	{
		return false;
	}

	const bool bResult = Property->ClearContainer();
	if (!bResult)
	{
		BroadcastPropertyOperationFailed(GetPropertyFeedbackText());
	}

	return bResult;
}

void UGenericPropertyRowWidget::RebuildGeneratedChildren()
{
	ClearGeneratedChildren();

	TArray<UObject*> ChildItems;
	for (UGenericProperty* ChildViewModel : GetVisibleChildPropertyViewModels())
	{
		ChildItems.Add(ChildViewModel);
	}

	if (ListView_ChildProperties)
	{
		ListView_ChildProperties->SetListItems(ChildItems);
	}
}

void UGenericPropertyRowWidget::ClearGeneratedChildren()
{
	if (ListView_ChildProperties)
	{
		ListView_ChildProperties->ClearListItems();
	}
}

UGenericPropertyRowName* UGenericPropertyRowWidget::GetGenericPropertyRowName() const
{
	return GenericPropertyRowName;
}

UGenericPropertyRowValueSpawner* UGenericPropertyRowWidget::GetGenericPropertyValue() const
{
	return GenericPropertyValue;
}

void UGenericPropertyRowWidget::RebuildPropertyValueWidget()
{
	if (GenericPropertyValue)
	{
		GenericPropertyValue->RebuildSpawnedValueWidget();
	}
}

void UGenericPropertyRowWidget::OnPropertySet_Implementation(UGenericProperty* InPropertyViewModel)
{
}

void UGenericPropertyRowWidget::OnPropertyCleared_Implementation(UGenericProperty* InPreviousViewModel)
{
}

void UGenericPropertyRowWidget::OnPropertyChanged_Implementation(UGenericProperty* InPropertyViewModel, bool bStructureChanged)
{
}

void UGenericPropertyRowWidget::OnPropertyOperationFailed_Implementation(const FText& InMessage)
{
}

void UGenericPropertyRowWidget::HandlePropertyChanged(UGenericProperty* InProperty, const bool bStructureChanged)
{
	if (InProperty != Property)
	{
		return;
	}

	SyncBoundPropertyWidgets();
	OnPropertyChanged(InProperty, bStructureChanged);
	OnPropertyViewModelChangedEvent.Broadcast(this, InProperty, bStructureChanged);

	if (bAutoRebuildChildrenOnPropertyChanged && bStructureChanged)
	{
		RebuildGeneratedChildren();
	}
}

void UGenericPropertyRowWidget::BroadcastPropertyOperationFailed(const FText& InMessage)
{
	if (InMessage.IsEmpty())
	{
		return;
	}

	OnPropertyOperationFailed(InMessage);
	OnPropertyOperationFailedEvent.Broadcast(this, InMessage);
}

void UGenericPropertyRowWidget::HandleChildPropertyEntryWidgetGenerated(UUserWidget& InWidget)
{
	if (UGenericPropertyRowWidget* RowWidget = Cast<UGenericPropertyRowWidget>(&InWidget))
	{
		RowWidget->SetOwningPropertyPanelWidget(OwningPropertyPanelWidget);
		RowWidget->SetOwningPropertyCategoryWidget(OwningPropertyCategoryWidget);

		if (RowWidget->GetProperty())
		{
			RowWidget->RebuildGeneratedChildren();
		}
	}
}

void UGenericPropertyRowWidget::SyncBoundPropertyWidgets()
{
	if (GenericPropertyRowName)
	{
		GenericPropertyRowName->SetProperty(Property);
	}

	if (GenericPropertyValue)
	{
		GenericPropertyValue->SetProperty(Property);
	}
}
