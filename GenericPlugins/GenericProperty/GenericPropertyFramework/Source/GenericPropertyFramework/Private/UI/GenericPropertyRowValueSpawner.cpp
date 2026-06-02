#include "UI/GenericPropertyRowValueSpawner.h"

#include "Components/ContentWidget.h"
#include "Components/PanelWidget.h"
#include "Core/GenericProperty.h"
#include "Model/GenericPropertyProxy.h"
#include "UI/GenericPropertyValue.h"
#include "UI/GenericPropertyValueMappingAsset.h"

UGenericPropertyRowValueSpawner::UGenericPropertyRowValueSpawner(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericPropertyRowValueSpawner::NativeConstruct()
{
	Super::NativeConstruct();
	RebuildSpawnedValueWidget();
}

void UGenericPropertyRowValueSpawner::NativeDestruct()
{
	if (ValueHandle != nullptr)
	{
		ValueHandle->OnHandleChangedEvent.RemoveAll(this);
	}

	if (Property != nullptr)
	{
		Property->Delegate_OnViewModelChanged.RemoveAll(this);
	}

	if (SpawnedValueWidget != nullptr)
	{
		SpawnedValueWidget->SetValueHandle(nullptr);
	}

	Super::NativeDestruct();
}

UGenericProperty* UGenericPropertyRowValueSpawner::GetProperty() const
{
	return Property;
}

UGenericPropertyValueHandleBase* UGenericPropertyRowValueSpawner::GetValueHandle() const
{
	return ValueHandle;
}

void UGenericPropertyRowValueSpawner::SetProperty(UGenericProperty* InProperty)
{
	if (Property == InProperty)
	{
		if (ValueHandle != nullptr)
		{
			HandleValueHandleChanged(ValueHandle, true, false);
		}
		else
		{
			SyncWidgetPresentationFromProperty();
			RebuildSpawnedValueWidget();
		}
		return;
	}

	if (ValueHandle != nullptr)
	{
		ValueHandle->OnHandleChangedEvent.RemoveAll(this);
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
		Property->Delegate_OnViewModelChanged.AddUObject(this, &UGenericPropertyRowValueSpawner::HandlePropertyChanged);
		OnPropertySet(Property);
		OnPropertySetEvent.Broadcast(this, Property);
	}

	ValueHandle = (Property != nullptr && Property->OwningProxy != nullptr) ? Property->OwningProxy->CreateValueHandleForProperty(Property) : nullptr;
	if (ValueHandle != nullptr)
	{
		ValueHandle->OnHandleChangedEvent.AddDynamic(this, &UGenericPropertyRowValueSpawner::HandleValueHandleChanged);
		HandleValueHandleChanged(ValueHandle, true, true);
		return;
	}

	HandlePropertyChanged(Property, true);
}

void UGenericPropertyRowValueSpawner::SetValueHandle(UGenericPropertyValueHandleBase* InValueHandle)
{
	if (ValueHandle == InValueHandle)
	{
		if (ValueHandle != nullptr)
		{
			HandleValueHandleChanged(ValueHandle, true, false);
		}
		else
		{
			SyncWidgetPresentationFromProperty();
			RebuildSpawnedValueWidget();
		}
		return;
	}

	if (ValueHandle != nullptr)
	{
		ValueHandle->OnHandleChangedEvent.RemoveAll(this);
	}

	if (Property != nullptr)
	{
		Property->Delegate_OnViewModelChanged.RemoveAll(this);
	}

	Property = InValueHandle != nullptr ? InValueHandle->GetLegacyProperty() : nullptr;
	ValueHandle = InValueHandle;
	if (Property != nullptr)
	{
		Property->Delegate_OnViewModelChanged.AddUObject(this, &UGenericPropertyRowValueSpawner::HandlePropertyChanged);
	}

	if (ValueHandle != nullptr)
	{
		ValueHandle->OnHandleChangedEvent.AddDynamic(this, &UGenericPropertyRowValueSpawner::HandleValueHandleChanged);
		HandleValueHandleChanged(ValueHandle, true, true);
		return;
	}

	HandlePropertyChanged(Property, true);
}

UGenericPropertyValue* UGenericPropertyRowValueSpawner::GetSpawnedValueWidget() const
{
	return SpawnedValueWidget;
}

void UGenericPropertyRowValueSpawner::RebuildSpawnedValueWidget()
{
	if (PanelWidget_ValueContainer == nullptr)
	{
		return;
	}

	if (Property == nullptr && ValueHandle == nullptr)
	{
		if (SpawnedValueWidget != nullptr)
		{
			PanelWidget_ValueContainer->RemoveChild(SpawnedValueWidget);
			SpawnedValueWidget = nullptr;
		}

		return;
	}

	const TSubclassOf<UGenericPropertyValue> DesiredClass = ResolvePropertyValueWidgetClass();
	if (DesiredClass == nullptr)
	{
		return;
	}

	if (SpawnedValueWidget != nullptr && SpawnedValueWidget->IsA(DesiredClass))
	{
		SpawnedValueWidget->SetValueHandle(ValueHandle);
		return;
	}

	if (UGenericPropertyValue* NewWidget = SpawnPropertyValueWidget(DesiredClass))
	{
		ReplaceSpawnedValueWidget(NewWidget);
		NewWidget->SetValueHandle(ValueHandle);
	}
}

bool UGenericPropertyRowValueSpawner::CommitSerializedValueInternal(const FString& InValue)
{
	if (ValueHandle != nullptr)
	{
		return ValueHandle->CommitSerializedValueInternal(InValue);
	}

	if (Property == nullptr)
	{
		return false;
	}

	Property->CommitSerializedValueInternal(InValue);
	if (Property->bIsInvalid)
	{
		return false;
	}

	return true;
}

bool UGenericPropertyRowValueSpawner::ApplyPropertyValue()
{
	if (ValueHandle != nullptr)
	{
		return ValueHandle->Apply();
	}

	if (SpawnedValueWidget != nullptr)
	{
		return SpawnedValueWidget->ApplyPropertyValue();
	}

	return Property != nullptr && Property->Apply();
}

bool UGenericPropertyRowValueSpawner::ResetPropertyValue(const EGenericPropertyResetMode InMode)
{
	if (ValueHandle != nullptr)
	{
		return ValueHandle->Reset(InMode);
	}

	if (SpawnedValueWidget != nullptr)
	{
		return SpawnedValueWidget->ResetPropertyValue(InMode);
	}

	return Property != nullptr && Property->Reset(InMode);
}

void UGenericPropertyRowValueSpawner::OnPropertySet_Implementation(UGenericProperty* InProperty)
{
}

void UGenericPropertyRowValueSpawner::OnPropertyCleared_Implementation(UGenericProperty* InPreviousProperty)
{
}

void UGenericPropertyRowValueSpawner::OnPropertyChanged_Implementation(UGenericProperty* InProperty, bool bStructureChanged)
{
}

void UGenericPropertyRowValueSpawner::OnVisibilityChanged_Implementation(ESlateVisibility InVisibility)
{
	SetVisibility(InVisibility);
}

void UGenericPropertyRowValueSpawner::HandlePropertyChanged(UGenericProperty* InProperty, const bool bStructureChanged)
{
	if (InProperty != Property)
	{
		return;
	}

	if (ValueHandle != nullptr)
	{
		ValueHandle->Refresh();
		return;
	}

	SyncWidgetPresentationFromProperty();
	RebuildSpawnedValueWidget();
	OnPropertyChanged(InProperty, bStructureChanged);
	OnPropertyChangedEvent.Broadcast(this, InProperty, bStructureChanged);
}

void UGenericPropertyRowValueSpawner::HandleValueHandleChanged(UGenericPropertyValueHandleBase* InValueHandle, const bool bValueChanged, const bool bStructureChanged)
{
	if (InValueHandle != ValueHandle)
	{
		return;
	}

	Property = ValueHandle != nullptr ? ValueHandle->GetLegacyProperty() : nullptr;
	SyncWidgetPresentationFromProperty();
	RebuildSpawnedValueWidget();
	if (Property != nullptr)
	{
		OnPropertyChanged(Property, bStructureChanged);
		OnPropertyChangedEvent.Broadcast(this, Property, bStructureChanged);
	}
}

void UGenericPropertyRowValueSpawner::SyncWidgetPresentationFromProperty() const
{
	ESlateVisibility WidgetVisibility = ESlateVisibility::Collapsed;
	if (ValueHandle != nullptr)
	{
		WidgetVisibility = ValueHandle->IsVisible() ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed;
	}
	else if (Property != nullptr)
	{
		WidgetVisibility = Property->bIsVisible ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed;
	}

	UGenericPropertyRowValueSpawner* MutableThis = const_cast<UGenericPropertyRowValueSpawner*>(this);

	MutableThis->OnVisibilityChanged(WidgetVisibility);
}

TSubclassOf<UGenericPropertyValue> UGenericPropertyRowValueSpawner::ResolvePropertyValueWidgetClass() const
{
	if (PropertyValueMapping == nullptr)
	{
		return nullptr;
	}

	if (ValueHandle != nullptr)
	{
		return PropertyValueMapping->ResolveValueWidgetClassForHandle(ValueHandle);
	}

	return PropertyValueMapping->ResolveValueWidgetClass(Property);
}

UGenericPropertyValue* UGenericPropertyRowValueSpawner::SpawnPropertyValueWidget(const TSubclassOf<UGenericPropertyValue> InWidgetClass) const
{
	if (InWidgetClass == nullptr)
	{
		return nullptr;
	}

	if (APlayerController* OwningPlayer = GetOwningPlayer())
	{
		return CreateWidget<UGenericPropertyValue>(OwningPlayer, InWidgetClass);
	}

	if (UWorld* World = GetWorld())
	{
		return CreateWidget<UGenericPropertyValue>(World, InWidgetClass);
	}

	return nullptr;
}

void UGenericPropertyRowValueSpawner::ReplaceSpawnedValueWidget(UGenericPropertyValue* InNewWidget)
{
	if (PanelWidget_ValueContainer == nullptr || InNewWidget == nullptr)
	{
		return;
	}

	if (SpawnedValueWidget != nullptr)
	{
		SpawnedValueWidget->SetValueHandle(nullptr);
	}

	if (UContentWidget* ContentWidget = Cast<UContentWidget>(PanelWidget_ValueContainer))
	{
		ContentWidget->SetContent(InNewWidget);
	}
	else
	{
		PanelWidget_ValueContainer->ClearChildren();
		PanelWidget_ValueContainer->AddChild(InNewWidget);
	}

	SpawnedValueWidget = InNewWidget;
}
