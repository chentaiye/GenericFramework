#include "UI/GenericPropertyPanelWidget.h"

#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "Core/GenericProperty.h"
#include "Core/GenericPropertyCategory.h"
#include "Core/GenericPropertyCollection.h"
#include "Engine/Engine.h"
#include "Data/GenericPropertyDataSourceCollection.h"
#include "Model/GenericPropertyProxy.h"
#include "Model/GenericPropertySubsystem.h"
#include "UI/GenericPropertyCategoryWidget.h"
#include "UI/GenericPropertyRowWidget.h"

UGenericPropertyPanelWidget::UGenericPropertyPanelWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericPropertyPanelWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ListView_Categories != nullptr)
	{
		ListView_Categories->OnEntryWidgetGenerated().AddUObject(this, &UGenericPropertyPanelWidget::HandleCategoryEntryWidgetGenerated);
	}

	if (PropertyCollection != nullptr && bAutoRebuildChildrenOnCollectionChanged)
	{
		RebuildGeneratedChildren();
	}
}

void UGenericPropertyPanelWidget::NativeDestruct()
{
	if (ListView_Categories != nullptr)
	{
		ListView_Categories->OnEntryWidgetGenerated().RemoveAll(this);
	}

	ClearGeneratedChildren();

	if (bDestroyOwnedCollectionOnDestruct)
	{
		ClearPropertyCollection(true);
	}
	else
	{
		ClearPropertyCollection(false);
	}

	Super::NativeDestruct();
}

UGenericPropertyCollection* UGenericPropertyPanelWidget::GetPropertyCollection() const
{
	return PropertyCollection;
}

void UGenericPropertyPanelWidget::SetPropertyCollection(UGenericPropertyCollection* InCollection)
{
	if (PropertyCollection == InCollection)
	{
		return;
	}

	UGenericPropertyCollection* PreviousCollection = PropertyCollection;
	const bool bDestroyPreviousCollection = PreviousCollection != nullptr && bOwnsPropertyCollection;

	if (PreviousCollection != nullptr)
	{
		PreviousCollection->Delegate_OnCollectionRebuilt.RemoveAll(this);
		PreviousCollection->Delegate_OnCollectionPresentationChanged.RemoveAll(this);

		OnPropertyCollectionCleared(PreviousCollection);
		OnPropertyCollectionClearedEvent.Broadcast(this, PreviousCollection);
	}

	ClearGeneratedChildren();

	PropertyCollection = InCollection;
	bOwnsPropertyCollection = false;

	if (PropertyCollection != nullptr)
	{
		PropertyCollection->Delegate_OnCollectionRebuilt.AddUObject(this, &UGenericPropertyPanelWidget::HandlePropertyCollectionRebuilt);
		PropertyCollection->Delegate_OnCollectionPresentationChanged.AddUObject(this, &UGenericPropertyPanelWidget::HandlePropertyCollectionPresentationChanged);

		OnPropertyCollectionSet(PropertyCollection);
		OnPropertyCollectionSetEvent.Broadcast(this, PropertyCollection);
		HandlePropertyCollectionRebuilt(PropertyCollection);
	}

	if (bDestroyPreviousCollection && GEngine != nullptr)
	{
		if (UGenericPropertySubsystem* PropertySubsystem = GEngine->GetEngineSubsystem<UGenericPropertySubsystem>())
		{
			PropertySubsystem->DestroyPropertyCollection(PreviousCollection);
		}
	}
}

UGenericPropertyCollection* UGenericPropertyPanelWidget::InitializePropertyCollectionForObject(UObject* InTarget, const FGenericPropertyPanelOptions& InOptions, TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass)
{
	TArray<UObject*> Targets;
	if (InTarget != nullptr)
	{
		Targets.Add(InTarget);
	}

	return InitializePropertyCollectionForObjects(Targets, InOptions, InDataSourceClass);
}

UGenericPropertyCollection* UGenericPropertyPanelWidget::InitializePropertyCollectionForObjects(const TArray<UObject*>& InTargets, const FGenericPropertyPanelOptions& InOptions, TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass)
{
	if (GEngine == nullptr)
	{
		return nullptr;
	}

	if (bDestroyOwnedCollectionOnDestruct)
	{
		ClearPropertyCollection(true);
	}
	else
	{
		ClearPropertyCollection(false);
	}

	if (UGenericPropertySubsystem* PropertySubsystem = GEngine->GetEngineSubsystem<UGenericPropertySubsystem>())
	{
		UGenericPropertyCollection* NewCollection = PropertySubsystem->CreatePropertyCollectionForObjects(InTargets, InOptions, InDataSourceClass);
		SetPropertyCollection(NewCollection);
		bOwnsPropertyCollection = NewCollection != nullptr;
		return NewCollection;
	}

	return nullptr;
}

void UGenericPropertyPanelWidget::ClearPropertyCollection(const bool bDestroyCollection)
{
	UGenericPropertyCollection* PreviousCollection = PropertyCollection;
	if (!PreviousCollection)
	{
		return;
	}

	PreviousCollection->Delegate_OnCollectionRebuilt.RemoveAll(this);
	PreviousCollection->Delegate_OnCollectionPresentationChanged.RemoveAll(this);

	ClearGeneratedChildren();
	PropertyCollection = nullptr;

	const bool bShouldDestroyCollection = bDestroyCollection && bOwnsPropertyCollection;
	bOwnsPropertyCollection = false;

	OnPropertyCollectionCleared(PreviousCollection);
	OnPropertyCollectionClearedEvent.Broadcast(this, PreviousCollection);

	if (bShouldDestroyCollection && GEngine != nullptr)
	{
		if (UGenericPropertySubsystem* PropertySubsystem = GEngine->GetEngineSubsystem<UGenericPropertySubsystem>())
		{
			PropertySubsystem->DestroyPropertyCollection(PreviousCollection);
		}
	}
}

void UGenericPropertyPanelWidget::RefreshPropertyCollection()
{
	if (PropertyCollection != nullptr)
	{
		PropertyCollection->Refresh();
	}
}

bool UGenericPropertyPanelWidget::ApplyPropertyCollection()
{
	return PropertyCollection != nullptr && PropertyCollection->Apply();
}

bool UGenericPropertyPanelWidget::ResetPropertyCollection(const EGenericPropertyResetMode InMode)
{
	return PropertyCollection != nullptr && PropertyCollection->Reset(InMode);
}

void UGenericPropertyPanelWidget::SetCollectionSearchText(const FString& InSearchText)
{
	if (PropertyCollection != nullptr)
	{
		PropertyCollection->SetSearchText(InSearchText);
	}
}

void UGenericPropertyPanelWidget::SetCollectionShowAdvancedProperties(const bool bInShowAdvancedProperties)
{
	if (PropertyCollection != nullptr)
	{
		PropertyCollection->SetShowAdvancedProperties(bInShowAdvancedProperties);
	}
}

void UGenericPropertyPanelWidget::SetCollectionTargetObject(UObject* InTarget)
{
	if (PropertyCollection != nullptr)
	{
		PropertyCollection->SetTargetObject(InTarget);
	}
}

void UGenericPropertyPanelWidget::SetCollectionTargetObjects(const TArray<UObject*>& InTargets)
{
	if (PropertyCollection != nullptr)
	{
		PropertyCollection->SetTargetObjects(InTargets);
	}
}

TArray<UGenericPropertyCategory*> UGenericPropertyPanelWidget::GetVisibleCategories() const
{
	TArray<UGenericPropertyCategory*> VisibleCategories;
	if (PropertyCollection == nullptr)
	{
		return VisibleCategories;
	}

	for (UGenericPropertyCategory* Category : PropertyCollection->Categories)
	{
		if (Category != nullptr && Category->bIsVisible)
		{
			VisibleCategories.Add(Category);
		}
	}

	return VisibleCategories;
}

void UGenericPropertyPanelWidget::RebuildGeneratedChildren()
{
	ClearGeneratedChildren();

	TArray<UObject*> CategoryItems;
	for (UGenericPropertyCategory* Category : GetVisibleCategories())
	{
		CategoryItems.Add(Category);
	}

	if (ListView_Categories != nullptr)
	{
		ListView_Categories->SetListItems(CategoryItems);
	}

	if (PropertyCollection != nullptr && PropertyCollection->Proxy != nullptr)
	{
		TArray<UObject*> RootPropertyItems;
		for (UGenericProperty* ViewModel : PropertyCollection->Proxy->GetRootNodes())
		{
			if (ViewModel != nullptr && ViewModel->bIsVisible)
			{
				RootPropertyItems.Add(ViewModel);
			}
		}
	}
}

void UGenericPropertyPanelWidget::ClearGeneratedChildren()
{
	if (ListView_Categories != nullptr)
	{
		ListView_Categories->ClearListItems();
	}

}

void UGenericPropertyPanelWidget::OnPropertyCollectionSet_Implementation(UGenericPropertyCollection* InCollection)
{
}

void UGenericPropertyPanelWidget::OnPropertyCollectionCleared_Implementation(UGenericPropertyCollection* InPreviousCollection)
{
}

void UGenericPropertyPanelWidget::OnPropertyCollectionRebuilt_Implementation(UGenericPropertyCollection* InCollection)
{
}

void UGenericPropertyPanelWidget::OnPropertyCollectionPresentationChanged_Implementation(UGenericPropertyCollection* InCollection)
{
}

void UGenericPropertyPanelWidget::OnPropertyCollectionCountsChanged_Implementation(int32 InDirtyCount, int32 InInvalidCount, int32 InConflictCount)
{
}

void UGenericPropertyPanelWidget::HandlePropertyCollectionRebuilt(UGenericPropertyCollection* InCollection)
{
	if (InCollection != PropertyCollection)
	{
		return;
	}

	OnPropertyCollectionRebuilt(InCollection);
	OnPropertyCollectionRebuiltEvent.Broadcast(this, InCollection);
	OnPropertyCollectionCountsChanged(InCollection->DirtyCount, InCollection->InvalidCount, InCollection->ConflictCount);
	OnPropertyCollectionCountsChangedEvent.Broadcast(this, InCollection->DirtyCount, InCollection->InvalidCount, InCollection->ConflictCount);

	if (bAutoRebuildChildrenOnCollectionChanged)
	{
		RebuildGeneratedChildren();
	}
}

void UGenericPropertyPanelWidget::HandlePropertyCollectionPresentationChanged(UGenericPropertyCollection* InCollection)
{
	if (InCollection != PropertyCollection)
	{
		return;
	}

	OnPropertyCollectionPresentationChanged(InCollection);
	OnPropertyCollectionPresentationChangedEvent.Broadcast(this, InCollection);
	OnPropertyCollectionCountsChanged(InCollection->DirtyCount, InCollection->InvalidCount, InCollection->ConflictCount);
	OnPropertyCollectionCountsChangedEvent.Broadcast(this, InCollection->DirtyCount, InCollection->InvalidCount, InCollection->ConflictCount);

	if (bAutoRebuildChildrenOnCollectionChanged)
	{
		RebuildGeneratedChildren();
	}
}

void UGenericPropertyPanelWidget::HandleCategoryEntryWidgetGenerated(UUserWidget& InWidget)
{
	if (UGenericPropertyCategoryWidget* CategoryWidget = Cast<UGenericPropertyCategoryWidget>(&InWidget))
	{
		CategoryWidget->SetOwningPropertyPanelWidget(this);

		if (CategoryWidget->GetPropertyCategory() != nullptr)
		{
			CategoryWidget->RebuildGeneratedChildren();
		}
	}
}

void UGenericPropertyPanelWidget::HandleRootPropertyEntryWidgetGenerated(UUserWidget& InWidget)
{
	if (UGenericPropertyRowWidget* RowWidget = Cast<UGenericPropertyRowWidget>(&InWidget))
	{
		RowWidget->SetOwningPropertyPanelWidget(this);
		RowWidget->SetOwningPropertyCategoryWidget(nullptr);

		if (RowWidget->GetProperty() != nullptr)
		{
			RowWidget->RebuildGeneratedChildren();
		}
	}
}
