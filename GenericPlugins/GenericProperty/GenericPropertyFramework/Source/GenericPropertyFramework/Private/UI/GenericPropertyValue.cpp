#include "UI/GenericPropertyValue.h"

#include "Core/GenericProperty.h"
#include "Model/GenericPropertyProxy.h"

namespace
{
	template<typename TStructType>
	FString ExportStructValue(const TStructType& InValue)
	{
		FString ExportedValue;
		if (const UScriptStruct* ScriptStruct = TBaseStructure<TStructType>::Get())
		{
			ScriptStruct->ExportText(ExportedValue, &InValue, nullptr, nullptr, PPF_None, nullptr);
		}
		return ExportedValue;
	}
}

UGenericPropertyValue::UGenericPropertyValue(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericPropertyValue::NativeDestruct()
{
	if (ValueHandle != nullptr)
	{
		ValueHandle->OnHandleChangedEvent.RemoveAll(this);
	}

	if (Property != nullptr)
	{
		Property->Delegate_OnViewModelChanged.RemoveAll(this);
	}

	Super::NativeDestruct();
}

UGenericProperty* UGenericPropertyValue::GetProperty() const
{
	return Property;
}

UGenericPropertyValueHandleBase* UGenericPropertyValue::GetValueHandle() const
{
	return ValueHandle;
}

void UGenericPropertyValue::SetProperty(UGenericProperty* InProperty)
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
		Property->Delegate_OnViewModelChanged.AddUObject(this, &UGenericPropertyValue::HandlePropertyChanged);
		OnPropertySet(Property);
		OnPropertySetEvent.Broadcast(this, Property);
	}

	UGenericPropertyValueHandleBase* NewHandle = nullptr;
	if (Property != nullptr && Property->OwningProxy != nullptr)
	{
		NewHandle = Property->OwningProxy->CreateValueHandleForProperty(Property);
	}

	ValueHandle = NewHandle;
	if (ValueHandle != nullptr)
	{
		ValueHandle->OnHandleChangedEvent.AddDynamic(this, &UGenericPropertyValue::HandleValueHandleChanged);
		OnValueHandleSet(ValueHandle);
		OnValueHandleSetEvent.Broadcast(this, ValueHandle);
		HandleValueHandleChanged(ValueHandle, true, true);
		return;
	}

	HandlePropertyChanged(Property, true);
}

void UGenericPropertyValue::SetValueHandle(UGenericPropertyValueHandleBase* InValueHandle)
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
		}
		return;
	}

	if (UGenericPropertyValueHandleBase* PreviousValueHandle = ValueHandle)
	{
		PreviousValueHandle->OnHandleChangedEvent.RemoveAll(this);
		OnValueHandleCleared(PreviousValueHandle);
		OnValueHandleClearedEvent.Broadcast(this, PreviousValueHandle);
	}

	if (Property != nullptr)
	{
		Property->Delegate_OnViewModelChanged.RemoveAll(this);
	}

	UGenericProperty* PreviousProperty = Property;
	ValueHandle = InValueHandle;
	Property = ValueHandle != nullptr ? ValueHandle->GetLegacyProperty() : nullptr;

	if (PreviousProperty != nullptr && PreviousProperty != Property)
	{
		OnPropertyCleared(PreviousProperty);
		OnPropertyClearedEvent.Broadcast(this, PreviousProperty);
	}

	if (Property != nullptr)
	{
		Property->Delegate_OnViewModelChanged.AddUObject(this, &UGenericPropertyValue::HandlePropertyChanged);
		if (PreviousProperty != Property)
		{
			OnPropertySet(Property);
			OnPropertySetEvent.Broadcast(this, Property);
		}
	}

	if (ValueHandle != nullptr)
	{
		ValueHandle->OnHandleChangedEvent.AddDynamic(this, &UGenericPropertyValue::HandleValueHandleChanged);
		OnValueHandleSet(ValueHandle);
		OnValueHandleSetEvent.Broadcast(this, ValueHandle);
		HandleValueHandleChanged(ValueHandle, true, true);
		return;
	}

	HandlePropertyChanged(Property, true);
}

FText UGenericPropertyValue::GetValueText() const
{
	if (ValueHandle != nullptr)
	{
		return ValueHandle->GetValueText();
	}

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

FText UGenericPropertyValue::GetFeedbackText() const
{
	if (ValueHandle != nullptr)
	{
		return ValueHandle->GetFeedbackText();
	}

	if (Property == nullptr)
	{
		return FText::GetEmpty();
	}

	if (Property->Issue.IsSet())
	{
		return Property->Issue.Message;
	}

	return FText::GetEmpty();
}

bool UGenericPropertyValue::IsValueEditable() const
{
	return ValueHandle != nullptr ? ValueHandle->IsEditable() : (Property != nullptr && Property->bIsEditable && Property->bSupportsDirectEdit);
}

bool UGenericPropertyValue::ApplyPropertyValue()
{
	if (ValueHandle != nullptr)
	{
		const bool bResult = ValueHandle->Apply();
		if (!bResult)
		{
			BroadcastPropertyOperationFailed(ValueHandle->GetFeedbackText());
		}

		return bResult;
	}

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

bool UGenericPropertyValue::ResetPropertyValue(const EGenericPropertyResetMode InMode)
{
	if (ValueHandle != nullptr)
	{
		const bool bResult = ValueHandle->Reset(InMode);
		if (!bResult)
		{
			BroadcastPropertyOperationFailed(ValueHandle->GetFeedbackText());
		}

		return bResult;
	}

	if (Property == nullptr)
	{
		return false;
	}

	const bool bResult = Property->Reset(InMode);
	if (!bResult)
	{
		BroadcastPropertyOperationFailed(GetFeedbackText());
	}

	return bResult;
}

bool UGenericPropertyValue::CommitSerializedValueInternal(const FString& InValue)
{
	if (ValueHandle != nullptr)
	{
		const bool bResult = ValueHandle->CommitSerializedValueInternal(InValue);
		if (!bResult)
		{
			BroadcastPropertyOperationFailed(ValueHandle->GetFeedbackText());
		}

		return bResult;
	}

	if (Property == nullptr)
	{
		return false;
	}

	Property->CommitSerializedValueInternal(InValue);
	if (Property->bIsInvalid)
	{
		BroadcastPropertyOperationFailed(Property->Issue.Message);
		return false;
	}

	return true;
}

void UGenericPropertyValue::OnPropertySet_Implementation(UGenericProperty* InProperty)
{
}

void UGenericPropertyValue::OnPropertyCleared_Implementation(UGenericProperty* InPreviousProperty)
{
}

void UGenericPropertyValue::OnPropertyChanged_Implementation(UGenericProperty* InProperty, bool bStructureChanged)
{
}

void UGenericPropertyValue::OnPropertyOperationFailed_Implementation(const FText& InMessage)
{
}

void UGenericPropertyValue::OnValueHandleSet_Implementation(UGenericPropertyValueHandleBase* InValueHandle)
{
}

void UGenericPropertyValue::OnValueHandleCleared_Implementation(UGenericPropertyValueHandleBase* InPreviousValueHandle)
{
}

void UGenericPropertyValue::OnValueHandleChanged_Implementation(UGenericPropertyValueHandleBase* InValueHandle, bool bStructureChanged)
{
}

void UGenericPropertyValue::OnPrimaryNameChanged_Implementation(const FText& InPrimaryName)
{
}

void UGenericPropertyValue::OnSecondaryNameChanged_Implementation(const FText& InSecondaryName)
{
}

void UGenericPropertyValue::OnTooltipTextChanged_Implementation(const FText& InTooltipText)
{
	if (!InTooltipText.IsEmpty())
	{
		SetToolTipText(InTooltipText);
	}
}

void UGenericPropertyValue::OnVisibilityChanged_Implementation(ESlateVisibility InVisibility)
{
	SetVisibility(InVisibility);
}

void UGenericPropertyValue::SyncWidgetPresentationFromProperty() const
{
	FText SecondaryName = FText::GetEmpty();
	FText TooltipText = FText::GetEmpty();
	ESlateVisibility WidgetVisibility = ESlateVisibility::Collapsed;

	if (ValueHandle != nullptr)
	{
		SecondaryName = ValueHandle->GetValueText();
		TooltipText = ValueHandle->GetFeedbackText();
		WidgetVisibility = ValueHandle->IsVisible() ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed;
	}
	else if (Property != nullptr)
	{
		SecondaryName = GetValueText();
		TooltipText = GetFeedbackText();
		WidgetVisibility = Property->bIsVisible ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed;
	}

	UGenericPropertyValue* MutableThis = const_cast<UGenericPropertyValue*>(this);

	MutableThis->OnPrimaryNameChanged(FText::GetEmpty());
	MutableThis->OnSecondaryNameChanged(SecondaryName);
	MutableThis->OnTooltipTextChanged(TooltipText);
	MutableThis->OnVisibilityChanged(WidgetVisibility);
}

void UGenericPropertyValue::HandlePropertyChanged(UGenericProperty* InProperty, const bool bStructureChanged)
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
	OnPropertyChanged(InProperty, bStructureChanged);
	OnPropertyChangedEvent.Broadcast(this, InProperty, bStructureChanged);
}

void UGenericPropertyValue::HandleValueHandleChanged(UGenericPropertyValueHandleBase* InValueHandle, const bool bValueChanged, const bool bStructureChanged)
{
	if (InValueHandle != ValueHandle)
	{
		return;
	}

	Property = ValueHandle != nullptr ? ValueHandle->GetLegacyProperty() : nullptr;
	SyncWidgetPresentationFromProperty();
	NotifyTypedValueChanged();
	OnValueHandleChanged(InValueHandle, bStructureChanged);
	OnValueHandleChangedEvent.Broadcast(this, InValueHandle, bStructureChanged);

	if (Property != nullptr)
	{
		OnPropertyChanged(Property, bStructureChanged);
		OnPropertyChangedEvent.Broadcast(this, Property, bStructureChanged);
	}
}

void UGenericPropertyValue::BroadcastPropertyOperationFailed(const FText& InMessage)
{
	if (InMessage.IsEmpty())
	{
		return;
	}

	OnPropertyOperationFailed(InMessage);
	OnPropertyOperationFailedEvent.Broadcast(this, InMessage);
}

void UGenericPropertyValue::NotifyTypedValueChanged()
{
}

#define IMPLEMENT_GENERIC_PROPERTY_WIDGET(WidgetClassName, HandleClassName, OutType, InType, HandleGetterName, TryCurrentName, TrySourceName, TryDefaultName, SetName, CommitName, EventName) \
HandleClassName* WidgetClassName::HandleGetterName() const \
{ \
	return Cast<HandleClassName>(ValueHandle); \
} \
bool WidgetClassName::TryCurrentName(OutType& OutValue) const \
{ \
	if (const HandleClassName* TypedHandle = HandleGetterName()) \
	{ \
		return TypedHandle->TryGetCurrentValue(OutValue); \
	} \
	return false; \
} \
bool WidgetClassName::TrySourceName(OutType& OutValue) const \
{ \
	if (const HandleClassName* TypedHandle = HandleGetterName()) \
	{ \
		return TypedHandle->TryGetSourceValue(OutValue); \
	} \
	return false; \
} \
bool WidgetClassName::TryDefaultName(OutType& OutValue) const \
{ \
	if (const HandleClassName* TypedHandle = HandleGetterName()) \
	{ \
		return TypedHandle->TryGetDefaultValue(OutValue); \
	} \
	return false; \
} \
bool WidgetClassName::SetName(InType InValue) \
{ \
	if (HandleClassName* TypedHandle = HandleGetterName()) \
	{ \
		return TypedHandle->SetCurrentValue(InValue); \
	} \
	return false; \
} \
bool WidgetClassName::CommitName(InType InValue) \
{ \
	if (HandleClassName* TypedHandle = HandleGetterName()) \
	{ \
		return TypedHandle->CommitCurrentValue(InValue); \
	} \
	return false; \
} \
void WidgetClassName::NotifyTypedValueChanged() \
{ \
	Super::NotifyTypedValueChanged(); \
	EventName(); \
}

IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyBoolValue, UGenericPropertyBoolValueHandle, bool, bool, GetBoolHandle, TryGetCurrentBoolValue, TryGetSourceBoolValue, TryGetDefaultBoolValue, SetCurrentBoolValue, CommitCurrentBoolValue, OnBoolValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyByteValue, UGenericPropertyByteValueHandle, uint8, uint8, GetByteHandle, TryGetCurrentByteValue, TryGetSourceByteValue, TryGetDefaultByteValue, SetCurrentByteValue, CommitCurrentByteValue, OnByteValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyIntegerValue, UGenericPropertyIntegerValueHandle, int32, int32, GetIntegerHandle, TryGetCurrentIntegerValue, TryGetSourceIntegerValue, TryGetDefaultIntegerValue, SetCurrentIntegerValue, CommitCurrentIntegerValue, OnIntegerValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyInteger64Value, UGenericPropertyInteger64ValueHandle, int64, int64, GetInteger64Handle, TryGetCurrentInteger64Value, TryGetSourceInteger64Value, TryGetDefaultInteger64Value, SetCurrentInteger64Value, CommitCurrentInteger64Value, OnInteger64ValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyFloatValue, UGenericPropertyFloatValueHandle, float, float, GetFloatHandle, TryGetCurrentFloatValue, TryGetSourceFloatValue, TryGetDefaultFloatValue, SetCurrentFloatValue, CommitCurrentFloatValue, OnFloatValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyDoubleValue, UGenericPropertyDoubleValueHandle, double, double, GetDoubleHandle, TryGetCurrentDoubleValue, TryGetSourceDoubleValue, TryGetDefaultDoubleValue, SetCurrentDoubleValue, CommitCurrentDoubleValue, OnDoubleValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyTextValue, UGenericPropertyTextValueHandle, FText, const FText&, GetTextHandle, TryGetCurrentTextValue, TryGetSourceTextValue, TryGetDefaultTextValue, SetCurrentTextValue, CommitCurrentTextValue, OnTextValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyStringValue, UGenericPropertyStringValueHandle, FString, const FString&, GetStringHandle, TryGetCurrentStringValue, TryGetSourceStringValue, TryGetDefaultStringValue, SetCurrentStringValue, CommitCurrentStringValue, OnStringValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyNameValue, UGenericPropertyNameValueHandle, FName, FName, GetNameHandle, TryGetCurrentNameValue, TryGetSourceNameValue, TryGetDefaultNameValue, SetCurrentNameValue, CommitCurrentNameValue, OnNameValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyObjectValue, UGenericPropertyObjectValueHandle, UObject*, UObject*, GetObjectHandle, TryGetCurrentObjectValue, TryGetSourceObjectValue, TryGetDefaultObjectValue, SetCurrentObjectValue, CommitCurrentObjectValue, OnObjectValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertyClassValue, UGenericPropertyClassValueHandle, UClass*, UClass*, GetClassHandle, TryGetCurrentClassValue, TryGetSourceClassValue, TryGetDefaultClassValue, SetCurrentClassValue, CommitCurrentClassValue, OnClassValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertySoftObjectValue, UGenericPropertySoftObjectValueHandle, FSoftObjectPath, const FSoftObjectPath&, GetSoftObjectHandle, TryGetCurrentSoftObjectValue, TryGetSourceSoftObjectValue, TryGetDefaultSoftObjectValue, SetCurrentSoftObjectValue, CommitCurrentSoftObjectValue, OnSoftObjectValueChanged)
IMPLEMENT_GENERIC_PROPERTY_WIDGET(UGenericPropertySoftClassValue, UGenericPropertySoftClassValueHandle, FSoftClassPath, const FSoftClassPath&, GetSoftClassHandle, TryGetCurrentSoftClassValue, TryGetSourceSoftClassValue, TryGetDefaultSoftClassValue, SetCurrentSoftClassValue, CommitCurrentSoftClassValue, OnSoftClassValueChanged)

#undef IMPLEMENT_GENERIC_PROPERTY_WIDGET

UGenericPropertyEnumValueHandle* UGenericPropertyEnumValue::GetEnumHandle() const
{
	return Cast<UGenericPropertyEnumValueHandle>(ValueHandle);
}

bool UGenericPropertyEnumValue::TryGetCurrentEnumValue(int64& OutValue) const
{
	if (const UGenericPropertyEnumValueHandle* TypedHandle = GetEnumHandle())
	{
		return TypedHandle->TryGetCurrentValue(OutValue);
	}

	return false;
}

bool UGenericPropertyEnumValue::TryGetSourceEnumValue(int64& OutValue) const
{
	if (const UGenericPropertyEnumValueHandle* TypedHandle = GetEnumHandle())
	{
		return TypedHandle->TryGetSourceValue(OutValue);
	}

	return false;
}

bool UGenericPropertyEnumValue::TryGetDefaultEnumValue(int64& OutValue) const
{
	if (const UGenericPropertyEnumValueHandle* TypedHandle = GetEnumHandle())
	{
		return TypedHandle->TryGetDefaultValue(OutValue);
	}

	return false;
}

bool UGenericPropertyEnumValue::SetCurrentEnumValue(const int64 InValue)
{
	if (UGenericPropertyEnumValueHandle* TypedHandle = GetEnumHandle())
	{
		return TypedHandle->SetCurrentValue(InValue);
	}

	return false;
}

bool UGenericPropertyEnumValue::CommitCurrentEnumValue(const int64 InValue)
{
	if (UGenericPropertyEnumValueHandle* TypedHandle = GetEnumHandle())
	{
		return TypedHandle->CommitCurrentValue(InValue);
	}

	return false;
}

UEnum* UGenericPropertyEnumValue::GetEnumDefinition() const
{
	return GetEnumHandle() != nullptr ? GetEnumHandle()->GetEnumDefinition() : nullptr;
}

void UGenericPropertyEnumValue::NotifyTypedValueChanged()
{
	Super::NotifyTypedValueChanged();
	OnEnumValueChanged();
}

UGenericPropertyStructValueHandle* UGenericPropertyStructValue::GetStructHandle() const
{
	return Cast<UGenericPropertyStructValueHandle>(ValueHandle);
}

UScriptStruct* UGenericPropertyStructValue::GetStructType() const
{
	return GetStructHandle() != nullptr ? GetStructHandle()->GetStructType() : nullptr;
}

TArray<UGenericPropertyValueHandleBase*> UGenericPropertyStructValue::GetFieldHandles() const
{
	return GetStructHandle() != nullptr ? const_cast<UGenericPropertyStructValueHandle*>(GetStructHandle())->GetFieldHandles() : TArray<UGenericPropertyValueHandleBase*>();
}

UGenericPropertyValueHandleBase* UGenericPropertyStructValue::FindFieldHandle(const FName InPropertyName) const
{
	return GetStructHandle() != nullptr ? const_cast<UGenericPropertyStructValueHandle*>(GetStructHandle())->FindFieldHandle(InPropertyName) : nullptr;
}

void UGenericPropertyStructValue::NotifyTypedValueChanged()
{
	Super::NotifyTypedValueChanged();
	OnStructValueChanged();
}

UGenericPropertyContainerValueHandle* UGenericPropertyContainerValue::GetContainerHandle() const
{
	return Cast<UGenericPropertyContainerValueHandle>(ValueHandle);
}

int32 UGenericPropertyContainerValue::GetElementCount() const
{
	return GetContainerHandle() != nullptr ? GetContainerHandle()->GetElementCount() : 0;
}

bool UGenericPropertyContainerValue::ClearContainerValue()
{
	return GetContainerHandle() != nullptr && GetContainerHandle()->Clear();
}

void UGenericPropertyContainerValue::NotifyTypedValueChanged()
{
	Super::NotifyTypedValueChanged();
	OnContainerValueChanged();
}
