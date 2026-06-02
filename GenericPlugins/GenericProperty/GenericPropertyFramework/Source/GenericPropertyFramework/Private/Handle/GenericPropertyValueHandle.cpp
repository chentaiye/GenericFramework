#include "Handle/GenericPropertyValueHandle.h"

#include "Core/GenericProperty.h"
#include "Core/GenericPropertyReflection.h"
#include "Data/GenericPropertyDataSourceCollection.h"
#include "Model/GenericPropertyProxy.h"
#include "Model/GenericPropertySessionCore.h"
#include "Templates/GenericPropertyValueTemplate.h"
#include "UObject/UnrealType.h"

namespace GenericPropertyValueHandlePrivate
{
	namespace
	{
		void* AllocateValueBuffer(const FProperty& InProperty)
		{
			void* Buffer = FMemory::Malloc(InProperty.GetSize(), InProperty.GetMinAlignment());
			InProperty.InitializeValue(Buffer);
			return Buffer;
		}

		void FreeValueBuffer(const FProperty& InProperty, void* InBuffer)
		{
			if (InBuffer == nullptr)
			{
				return;
			}

			InProperty.DestroyValue(InBuffer);
			FMemory::Free(InBuffer);
		}

		bool ImportSerializedValue(const FProperty& InProperty, const FString& InSerializedValue, void* InValueBuffer)
		{
			FText Error;
			return GenericPropertyFramework::Private::ImportValueFromString(InProperty, InValueBuffer, InSerializedValue, Error);
		}

		template<typename TValueType>
		bool SerializeTypedValue(const TValueType& InValue, FString& OutSerializedValue)
		{
			return GenericPropertyFramework::Templates::SerializeValue(InValue, OutSerializedValue);
		}

		bool TryReadBool(const FProperty& InProperty, const FString& InSerializedValue, bool& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FBoolProperty* BoolProperty = CastField<const FBoolProperty>(&InProperty))
				{
					OutValue = BoolProperty->GetPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadByte(const FProperty& InProperty, const FString& InSerializedValue, uint8& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FNumericProperty* NumericProperty = CastField<const FNumericProperty>(&InProperty); NumericProperty != nullptr && NumericProperty->IsInteger())
				{
					OutValue = static_cast<uint8>(NumericProperty->GetUnsignedIntPropertyValue(Buffer));
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadInt32(const FProperty& InProperty, const FString& InSerializedValue, int32& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FNumericProperty* NumericProperty = CastField<const FNumericProperty>(&InProperty); NumericProperty != nullptr && NumericProperty->IsInteger())
				{
					OutValue = static_cast<int32>(NumericProperty->GetSignedIntPropertyValue(Buffer));
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadInt64(const FProperty& InProperty, const FString& InSerializedValue, int64& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FNumericProperty* NumericProperty = CastField<const FNumericProperty>(&InProperty); NumericProperty != nullptr && NumericProperty->IsInteger())
				{
					OutValue = NumericProperty->GetSignedIntPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadFloat(const FProperty& InProperty, const FString& InSerializedValue, float& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FNumericProperty* NumericProperty = CastField<const FNumericProperty>(&InProperty); NumericProperty != nullptr && NumericProperty->IsFloatingPoint())
				{
					OutValue = static_cast<float>(NumericProperty->GetFloatingPointPropertyValue(Buffer));
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadDouble(const FProperty& InProperty, const FString& InSerializedValue, double& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FNumericProperty* NumericProperty = CastField<const FNumericProperty>(&InProperty); NumericProperty != nullptr && NumericProperty->IsFloatingPoint())
				{
					OutValue = NumericProperty->GetFloatingPointPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadString(const FProperty& InProperty, const FString& InSerializedValue, FString& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FStrProperty* StringProperty = CastField<const FStrProperty>(&InProperty))
				{
					OutValue = StringProperty->GetPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadText(const FProperty& InProperty, const FString& InSerializedValue, FText& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FTextProperty* TextProperty = CastField<const FTextProperty>(&InProperty))
				{
					OutValue = TextProperty->GetPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadName(const FProperty& InProperty, const FString& InSerializedValue, FName& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FNameProperty* NameProperty = CastField<const FNameProperty>(&InProperty))
				{
					OutValue = NameProperty->GetPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadObject(const FProperty& InProperty, const FString& InSerializedValue, UObject*& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FObjectPropertyBase* ObjectProperty = CastField<const FObjectPropertyBase>(&InProperty))
				{
					OutValue = ObjectProperty->GetObjectPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool TryReadClass(const FProperty& InProperty, const FString& InSerializedValue, UClass*& OutValue)
		{
			UObject* ObjectValue = nullptr;
			if (!TryReadObject(InProperty, InSerializedValue, ObjectValue))
			{
				return false;
			}

			OutValue = Cast<UClass>(ObjectValue);
			return OutValue != nullptr || ObjectValue == nullptr;
		}

		bool TryReadSoftObjectPath(const FProperty&, const FString& InSerializedValue, FSoftObjectPath& OutValue)
		{
			OutValue = FSoftObjectPath(InSerializedValue);
			return true;
		}

		bool TryReadSoftClassPath(const FProperty&, const FString& InSerializedValue, FSoftClassPath& OutValue)
		{
			OutValue = FSoftClassPath(InSerializedValue);
			return true;
		}

		bool TryReadEnum(const FProperty& InProperty, const FString& InSerializedValue, int64& OutValue)
		{
			void* Buffer = AllocateValueBuffer(InProperty);
			const bool bImported = ImportSerializedValue(InProperty, InSerializedValue, Buffer);
			if (bImported)
			{
				if (const FEnumProperty* EnumProperty = CastField<const FEnumProperty>(&InProperty))
				{
					OutValue = EnumProperty->GetUnderlyingProperty()->GetSignedIntPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}

				if (const FNumericProperty* NumericProperty = CastField<const FNumericProperty>(&InProperty); NumericProperty != nullptr && NumericProperty->IsInteger())
				{
					OutValue = NumericProperty->GetSignedIntPropertyValue(Buffer);
					FreeValueBuffer(InProperty, Buffer);
					return true;
				}
			}

			FreeValueBuffer(InProperty, Buffer);
			return false;
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, bool& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadBool(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, uint8& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadByte(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, int32& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadInt32(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, int64& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadInt64(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, float& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadFloat(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, double& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadDouble(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, FString& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadString(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, FText& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadText(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, FName& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadName(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, UObject*& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadObject(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, UClass*& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadClass(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, FSoftObjectPath& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadSoftObjectPath(*Property, InSerializedValue, OutValue);
		}

		bool DeserializeCurrentState(const UGenericPropertyValueHandleBase& InHandle, const FString& InSerializedValue, FSoftClassPath& OutValue)
		{
			const FProperty* Property = nullptr;
			return InHandle.ResolveRepresentativeProperty(Property) && Property != nullptr && TryReadSoftClassPath(*Property, InSerializedValue, OutValue);
		}
	}
}

UGenericPropertyProxy* UGenericPropertyValueHandleBase::GetOwningProxy() const
{
	return OwnerProxy.Get();
}

UGenericProperty* UGenericPropertyValueHandleBase::GetLegacyProperty() const
{
	return LegacyProperty.Get();
}

FGenericPropertyFieldKey UGenericPropertyValueHandleBase::GetFieldKey() const
{
	return Descriptor.FieldKey;
}

FText UGenericPropertyValueHandleBase::GetDisplayName() const
{
	return Descriptor.DisplayName;
}

FText UGenericPropertyValueHandleBase::GetTooltip() const
{
	return Descriptor.ToolTip;
}

FName UGenericPropertyValueHandleBase::GetStyleKey() const
{
	return Descriptor.StyleKey;
}

FGameplayTagContainer UGenericPropertyValueHandleBase::GetVisualTags() const
{
	return Descriptor.VisualTags;
}

FText UGenericPropertyValueHandleBase::GetValueText() const
{
	if (State.bHasMixedValues)
	{
		return FText::FromString(TEXT("<Multiple Values>"));
	}

	if (Descriptor.NodeKind == EGenericPropertyNodeKind::Warning && State.Issue.IsSet())
	{
		return State.Issue.Message;
	}

	return FText::FromString(CurrentValue);
}

FText UGenericPropertyValueHandleBase::GetFeedbackText() const
{
	return State.Issue.Message;
}

bool UGenericPropertyValueHandleBase::IsEditable() const
{
	return State.bIsEditable;
}

bool UGenericPropertyValueHandleBase::IsEnabled() const
{
	return State.bIsEnabled;
}

bool UGenericPropertyValueHandleBase::IsVisible() const
{
	return State.bIsVisible;
}

bool UGenericPropertyValueHandleBase::IsDirty() const
{
	return State.bIsDirty;
}

bool UGenericPropertyValueHandleBase::IsInvalid() const
{
	return State.bIsInvalid;
}

bool UGenericPropertyValueHandleBase::HasMixedValues() const
{
	return State.bHasMixedValues;
}

bool UGenericPropertyValueHandleBase::HasConflict() const
{
	return State.bHasConflict;
}

EGenericPropertyNodeKind UGenericPropertyValueHandleBase::GetNodeKind() const
{
	return Descriptor.NodeKind;
}

EGenericPropertyValueType UGenericPropertyValueHandleBase::GetValueType() const
{
	return Descriptor.ValueType;
}

void UGenericPropertyValueHandleBase::InitializeHandle(UGenericPropertyProxy* InOwnerProxy, const TSharedPtr<FGenericPropertySessionCore>& InSessionCore, const FGenericPropertyDescriptor& InDescriptor, UGenericProperty* InLegacyProperty)
{
	OwnerProxy = InOwnerProxy;
	SessionCore = InSessionCore;
	Descriptor = InDescriptor;
	LegacyProperty = InLegacyProperty;
	bChildrenInitialized = false;
	ChildHandles.Reset();

	if (LegacyProperty.IsValid())
	{
		SyncFromLegacyProperty();
	}
	else
	{
		State.bIsEditable = InDescriptor.bSupportsDirectEdit && InOwnerProxy != nullptr && !InOwnerProxy->GetOptions().bReadOnly;
		State.bIsEnabled = true;
		State.bIsVisible = true;
		State.bIsExpanded = false;
	}

	OnInitialized();
}

void UGenericPropertyValueHandleBase::OnInitialized()
{
}

void UGenericPropertyValueHandleBase::NotifyHandleChanged(const bool bValueChanged, const bool bStructureChanged)
{
	OnHandleChangedEvent.Broadcast(this, bValueChanged, bStructureChanged);
}

void UGenericPropertyValueHandleBase::Refresh()
{
	const FString PreviousCurrentValue = CurrentValue;
	if (LegacyProperty.IsValid())
	{
		LegacyProperty->Refresh();
		SyncFromLegacyProperty();
		NotifyHandleChanged(!CurrentValue.Equals(PreviousCurrentValue, ESearchCase::CaseSensitive), LegacyProperty->bChildrenDirty);
		return;
	}

	const bool bStructureChanged = RefreshDirect();
	NotifyHandleChanged(!CurrentValue.Equals(PreviousCurrentValue, ESearchCase::CaseSensitive), bStructureChanged);
}

bool UGenericPropertyValueHandleBase::Apply()
{
	if (LegacyProperty.IsValid())
	{
		const bool bResult = LegacyProperty->Apply();
		SyncFromLegacyProperty();
		NotifyHandleChanged(true, false);
		return bResult;
	}

	const bool bResult = ApplyDirect();
	NotifyHandleChanged(bResult, false);
	return bResult;
}

bool UGenericPropertyValueHandleBase::Reset(const EGenericPropertyResetMode InMode)
{
	if (LegacyProperty.IsValid())
	{
		const bool bResult = LegacyProperty->Reset(InMode);
		SyncFromLegacyProperty();
		NotifyHandleChanged(true, false);
		return bResult;
	}

	const bool bResult = ResetDirect(InMode);
	NotifyHandleChanged(bResult, false);
	return bResult;
}

bool UGenericPropertyValueHandleBase::CommitSerializedValueInternal(const FString& InValue)
{
	if (LegacyProperty.IsValid())
	{
		const FString PreviousCurrentValue = CurrentValue;
		CurrentValue = InValue;
		State.bIsDirty = !CurrentValue.Equals(SourceValue, ESearchCase::CaseSensitive);
		State.bHasConflict = false;
		LegacyProperty->CommitSerializedValueInternal(InValue);
		SyncFromLegacyProperty();
		NotifyHandleChanged(!CurrentValue.Equals(PreviousCurrentValue, ESearchCase::CaseSensitive), false);
		return !State.bIsInvalid;
	}

	FText ValidationError;
	const bool bValid = TryValidateSerializedValue(InValue, ValidationError);
	CurrentValue = InValue;
	State.bIsDirty = !CurrentValue.Equals(SourceValue, ESearchCase::CaseSensitive);
	State.bIsInvalid = !bValid;
	State.bHasConflict = false;
	State.Issue.Reset();
	if (!bValid)
	{
		State.Issue.Severity = EGenericPropertyIssueSeverity::Error;
		State.Issue.Type = EGenericPropertyIssueType::Validation;
		State.Issue.Message = ValidationError;
	}

	if (bValid && OwnerProxy.IsValid() && OwnerProxy->GetOptions().ApplyMode == EGenericPropertyApplyMode::Automatic)
	{
		return ApplyDirect();
	}

	return bValid;
}

const TArray<TObjectPtr<UGenericPropertyValueHandleBase>>& UGenericPropertyValueHandleBase::GetChildHandlesInternal()
{
	EnsureDirectChildren();
	return ChildHandles;
}

bool UGenericPropertyValueHandleBase::ResolveRepresentativeProperty(const FProperty*& OutProperty) const
{
	OutProperty = nullptr;

	const UGenericPropertyProxy* Proxy = OwnerProxy.Get();
	if (Proxy == nullptr)
	{
		return false;
	}

	for (const TWeakObjectPtr<UObject>& Target : Proxy->GetTargets())
	{
		if (!Target.IsValid())
		{
			continue;
		}

		GenericPropertyFramework::Private::FResolvedValue ResolvedValue;
		if (GenericPropertyFramework::Private::ResolveValue(Target.Get(), Descriptor.FieldKey.AccessPath, ResolvedValue))
		{
			OutProperty = ResolvedValue.Property;
			return OutProperty != nullptr;
		}
	}

	return false;
}

bool UGenericPropertyValueHandleBase::TryReadResolvedValue(const UObject* InTarget, FString& OutSerializedValue, const FProperty*& OutProperty, FText* OutError) const
{
	OutSerializedValue.Reset();
	OutProperty = nullptr;

	GenericPropertyFramework::Private::FResolvedValue ResolvedValue;
	if (!GenericPropertyFramework::Private::ResolveValue(const_cast<UObject*>(InTarget), Descriptor.FieldKey.AccessPath, ResolvedValue))
	{
		if (OutError != nullptr)
		{
			*OutError = FText::FromString(ResolvedValue.FailureReason);
		}
		return false;
	}

	OutProperty = ResolvedValue.Property;
	OutSerializedValue = GenericPropertyFramework::Private::ExportValueToString(*ResolvedValue.Property, ResolvedValue.ValuePtr);
	return true;
}

bool UGenericPropertyValueHandleBase::TryReadDefaultValue(FString& OutSerializedValue) const
{
	OutSerializedValue.Reset();

	const UGenericPropertyProxy* Proxy = OwnerProxy.Get();
	if (Proxy == nullptr)
	{
		return false;
	}

	for (const TWeakObjectPtr<UObject>& Target : Proxy->GetTargets())
	{
		if (!Target.IsValid())
		{
			continue;
		}

		GenericPropertyFramework::Private::FResolvedValue ResolvedValue;
		if (GenericPropertyFramework::Private::ResolveDefaultValue(Target->GetClass(), Descriptor.FieldKey.AccessPath, ResolvedValue))
		{
			OutSerializedValue = GenericPropertyFramework::Private::ExportValueToString(*ResolvedValue.Property, ResolvedValue.ValuePtr);
			return true;
		}
	}

	return false;
}

bool UGenericPropertyValueHandleBase::TryValidateSerializedValue(const FString& InValue, FText& OutError) const
{
	OutError = FText::GetEmpty();

	const UGenericPropertyProxy* Proxy = OwnerProxy.Get();
	if (Proxy == nullptr)
	{
		OutError = FText::FromString(TEXT("No owning proxy is available."));
		return false;
	}

	for (const TWeakObjectPtr<UObject>& Target : Proxy->GetTargets())
	{
		if (!Target.IsValid())
		{
			continue;
		}

		GenericPropertyFramework::Private::FResolvedValue ResolvedValue;
		if (!GenericPropertyFramework::Private::ResolveValue(Target.Get(), Descriptor.FieldKey.AccessPath, ResolvedValue))
		{
			OutError = FText::FromString(ResolvedValue.FailureReason);
			return false;
		}

		const FGenericPropertyValidationResult Validation = GenericPropertyFramework::Private::ValidateValueText(*ResolvedValue.Property, ResolvedValue.ValuePtr, InValue, Descriptor.Metadata);
		if (!Validation.bSuccess)
		{
			OutError = Validation.Message;
			return false;
		}

		return true;
	}

	OutError = FText::FromString(TEXT("No valid target is available."));
	return false;
}

bool UGenericPropertyValueHandleBase::TryWriteSerializedValue(const FString& InValue, FText& OutError)
{
	OutError = FText::GetEmpty();

	const UGenericPropertyProxy* Proxy = OwnerProxy.Get();
	if (Proxy == nullptr)
	{
		OutError = FText::FromString(TEXT("No owning proxy is available."));
		return false;
	}

	FText ValidationError;
	if (!TryValidateSerializedValue(InValue, ValidationError))
	{
		OutError = ValidationError;
		return false;
	}

	for (const TWeakObjectPtr<UObject>& Target : Proxy->GetTargets())
	{
		GenericPropertyFramework::Private::FResolvedValue ResolvedValue;
		if (!Target.IsValid() || !GenericPropertyFramework::Private::ResolveValue(Target.Get(), Descriptor.FieldKey.AccessPath, ResolvedValue))
		{
			OutError = FText::FromString(ResolvedValue.FailureReason);
			return false;
		}

		FText ImportError;
		if (!GenericPropertyFramework::Private::ImportValueFromString(*ResolvedValue.Property, ResolvedValue.ValuePtr, InValue, ImportError))
		{
			OutError = ImportError;
			return false;
		}
	}

	return true;
}

void UGenericPropertyValueHandleBase::SyncFromLegacyProperty()
{
	if (const UGenericProperty* Property = LegacyProperty.Get())
	{
		CurrentValue = Property->TextState.CurrentValue;
		SourceValue = Property->TextState.SourceValue;
		DefaultValue = Property->TextState.DefaultValue;
		State.bIsEditable = Property->bIsEditable && Property->bSupportsDirectEdit;
		State.bIsEnabled = Property->bIsEnabled;
		State.bIsVisible = Property->bIsVisible;
		State.bIsDirty = Property->bIsDirty;
		State.bIsInvalid = Property->bIsInvalid;
		State.bHasMixedValues = Property->bHasMixedValues;
		State.bHasConflict = Property->bHasConflict;
		State.bIsExpanded = Property->bIsExpanded;
		State.Issue = Property->Issue;
	}
}

void UGenericPropertyValueHandleBase::UpdateDirectState(const FString& InSourceValue, const FString& InDefaultValue, const FString& InCurrentValue, const bool bHadSuccessfulRead)
{
	SourceValue = InSourceValue;
	DefaultValue = InDefaultValue;
	CurrentValue = InCurrentValue;
	State.bIsDirty = !CurrentValue.Equals(SourceValue, ESearchCase::CaseSensitive);
	State.bIsInvalid = !bHadSuccessfulRead;
}

bool UGenericPropertyValueHandleBase::RefreshDirect()
{
	const UGenericPropertyProxy* Proxy = OwnerProxy.Get();
	if (Proxy == nullptr)
	{
		return false;
	}

	UObject* FirstTarget = nullptr;
	for (const TWeakObjectPtr<UObject>& Target : Proxy->GetTargets())
	{
		if (Target.IsValid())
		{
			FirstTarget = Target.Get();
			break;
		}
	}

	if (FirstTarget == nullptr)
	{
		State.Issue.Severity = EGenericPropertyIssueSeverity::Error;
		State.Issue.Type = EGenericPropertyIssueType::OperationFailed;
		State.Issue.Message = FText::FromString(TEXT("No valid target is available."));
		State.bIsInvalid = true;
		return false;
	}

	const FString PreviousSourceValue = SourceValue;
	FString NewSourceValue;
	const FProperty* ResolvedProperty = nullptr;
	FText ReadError;
	if (!TryReadResolvedValue(FirstTarget, NewSourceValue, ResolvedProperty, &ReadError))
	{
		State.Issue.Severity = EGenericPropertyIssueSeverity::Error;
		State.Issue.Type = EGenericPropertyIssueType::OperationFailed;
		State.Issue.Message = ReadError;
		State.bIsInvalid = true;
		return false;
	}

	bool bHasMixedValues = false;
	for (const TWeakObjectPtr<UObject>& Target : Proxy->GetTargets())
	{
		if (!Target.IsValid() || Target.Get() == FirstTarget)
		{
			continue;
		}

		FString ComparedValue;
		const FProperty* ComparedProperty = nullptr;
		if (!TryReadResolvedValue(Target.Get(), ComparedValue, ComparedProperty) || !ComparedValue.Equals(NewSourceValue, ESearchCase::CaseSensitive))
		{
			bHasMixedValues = true;
			break;
		}
	}

	FString NewDefaultValue;
	TryReadDefaultValue(NewDefaultValue);
	UpdateDirectState(NewSourceValue, NewDefaultValue, CurrentValue, true);
	State.bHasMixedValues = bHasMixedValues;
	State.bIsEditable = Descriptor.bSupportsDirectEdit && !Proxy->GetOptions().bReadOnly;
	State.bIsEnabled = true;
	State.bIsVisible = true;
	State.Issue.Reset();

	if (!State.bIsDirty || CurrentValue.Equals(PreviousSourceValue, ESearchCase::CaseSensitive))
	{
		CurrentValue = NewSourceValue;
		State.bIsDirty = false;
		State.bHasConflict = false;
	}
	else if (!CurrentValue.Equals(NewSourceValue, ESearchCase::CaseSensitive))
	{
		State.bHasConflict = Proxy->GetOptions().ConflictPolicy != EGenericPropertyConflictPolicy::TakeExternalValue;
		if (Proxy->GetOptions().ConflictPolicy == EGenericPropertyConflictPolicy::TakeExternalValue)
		{
			CurrentValue = NewSourceValue;
			State.bIsDirty = false;
			State.bHasConflict = false;
		}
	}

	if (!CurrentValue.IsEmpty())
	{
		FText ValidationError;
		State.bIsInvalid = !TryValidateSerializedValue(CurrentValue, ValidationError);
		if (State.bIsInvalid)
		{
			State.Issue.Severity = EGenericPropertyIssueSeverity::Error;
			State.Issue.Type = EGenericPropertyIssueType::Validation;
			State.Issue.Message = ValidationError;
		}
	}
	else
	{
		State.bIsInvalid = false;
	}

	return false;
}

bool UGenericPropertyValueHandleBase::ApplyDirect()
{
	FText Error;
	if (!TryWriteSerializedValue(CurrentValue, Error))
	{
		State.Issue.Severity = EGenericPropertyIssueSeverity::Error;
		State.Issue.Type = EGenericPropertyIssueType::OperationFailed;
		State.Issue.Message = Error;
		State.bIsInvalid = true;
		return false;
	}

	State.bHasConflict = false;
	State.bIsInvalid = false;
	State.Issue.Reset();
	RefreshDirect();
	return true;
}

bool UGenericPropertyValueHandleBase::ResetDirect(const EGenericPropertyResetMode InMode)
{
	switch (InMode)
	{
	case EGenericPropertyResetMode::SourceValue:
		CurrentValue = SourceValue;
		State.bIsDirty = false;
		State.bIsInvalid = false;
		State.bHasConflict = false;
		State.Issue.Reset();
		return true;

	case EGenericPropertyResetMode::ClassDefault:
		CurrentValue = DefaultValue;
		if (OwnerProxy.IsValid() && OwnerProxy->GetOptions().ApplyMode == EGenericPropertyApplyMode::Automatic)
		{
			return ApplyDirect();
		}

		State.bIsDirty = !CurrentValue.Equals(SourceValue, ESearchCase::CaseSensitive);
		State.bIsInvalid = false;
		State.bHasConflict = false;
		State.Issue.Reset();
		return true;
	}

	return false;
}

void UGenericPropertyValueHandleBase::EnsureDirectChildren()
{
	if (bChildrenInitialized)
	{
		return;
	}

	bChildrenInitialized = true;
	ChildHandles.Reset();

	if (UGenericProperty* Property = LegacyProperty.Get())
	{
		if (UGenericPropertyProxy* Proxy = OwnerProxy.Get(); Proxy != nullptr && Proxy->GetDataSource() != nullptr && Property->bCanExpand && (Property->Children.IsEmpty() || Property->bChildrenDirty))
		{
			Proxy->GetDataSource()->RebuildNodeChildren(*Property);
		}

		if (TSharedPtr<FGenericPropertySessionCore> Session = SessionCore.Pin())
		{
			for (UGenericProperty* Child : Property->Children)
			{
				if (UGenericPropertyValueHandleBase* ChildHandle = Session->CreateValueHandle(Child))
				{
					ChildHandles.Add(ChildHandle);
				}
			}
		}
	}
}

#define IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(HandleClassName, OutType, InType) \
bool HandleClassName::TryGetCurrentValue(OutType& OutValue) const \
{ \
	return GenericPropertyValueHandlePrivate::DeserializeCurrentState(*this, CurrentValue, OutValue); \
} \
bool HandleClassName::TryGetSourceValue(OutType& OutValue) const \
{ \
	return GenericPropertyValueHandlePrivate::DeserializeCurrentState(*this, SourceValue, OutValue); \
} \
bool HandleClassName::TryGetDefaultValue(OutType& OutValue) const \
{ \
	return GenericPropertyValueHandlePrivate::DeserializeCurrentState(*this, DefaultValue, OutValue); \
} \
bool HandleClassName::SetCurrentValue(InType InValue) \
{ \
	FString SerializedValue; \
	if (!GenericPropertyValueHandlePrivate::SerializeTypedValue(InValue, SerializedValue)) \
	{ \
		return false; \
	} \
	return CommitSerializedValueInternal(SerializedValue); \
} \
bool HandleClassName::CommitCurrentValue(InType InValue) \
{ \
	return SetCurrentValue(InValue); \
}

IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyBoolValueHandle, bool, bool)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyByteValueHandle, uint8, uint8)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyIntegerValueHandle, int32, int32)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyInteger64ValueHandle, int64, int64)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyFloatValueHandle, float, float)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyDoubleValueHandle, double, double)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyStringValueHandle, FString, const FString&)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyTextValueHandle, FText, const FText&)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyNameValueHandle, FName, FName)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyObjectValueHandle, UObject*, UObject*)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertyClassValueHandle, UClass*, UClass*)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertySoftObjectValueHandle, FSoftObjectPath, const FSoftObjectPath&)
IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE(UGenericPropertySoftClassValueHandle, FSoftClassPath, const FSoftClassPath&)

#undef IMPLEMENT_GENERIC_PROPERTY_SCALAR_HANDLE

bool UGenericPropertyEnumValueHandle::TryGetCurrentValue(int64& OutValue) const
{
	const FProperty* Property = nullptr;
	return ResolveRepresentativeProperty(Property) && Property != nullptr && GenericPropertyValueHandlePrivate::TryReadEnum(*Property, CurrentValue, OutValue);
}

bool UGenericPropertyEnumValueHandle::TryGetSourceValue(int64& OutValue) const
{
	const FProperty* Property = nullptr;
	return ResolveRepresentativeProperty(Property) && Property != nullptr && GenericPropertyValueHandlePrivate::TryReadEnum(*Property, SourceValue, OutValue);
}

bool UGenericPropertyEnumValueHandle::TryGetDefaultValue(int64& OutValue) const
{
	const FProperty* Property = nullptr;
	return ResolveRepresentativeProperty(Property) && Property != nullptr && GenericPropertyValueHandlePrivate::TryReadEnum(*Property, DefaultValue, OutValue);
}

bool UGenericPropertyEnumValueHandle::SetCurrentValue(const int64 InValue)
{
	FString SerializedValue;
	if (!GenericPropertyValueHandlePrivate::SerializeTypedValue(InValue, SerializedValue))
	{
		return false;
	}

	return CommitSerializedValueInternal(SerializedValue);
}

bool UGenericPropertyEnumValueHandle::CommitCurrentValue(const int64 InValue)
{
	return SetCurrentValue(InValue);
}

UEnum* UGenericPropertyEnumValueHandle::GetEnumDefinition() const
{
	return Descriptor.TypeObjectPath.IsEmpty() ? nullptr : LoadObject<UEnum>(nullptr, *Descriptor.TypeObjectPath);
}

UScriptStruct* UGenericPropertyStructValueHandle::GetStructType() const
{
	return Descriptor.TypeObjectPath.IsEmpty() ? nullptr : LoadObject<UScriptStruct>(nullptr, *Descriptor.TypeObjectPath);
}

TArray<UGenericPropertyValueHandleBase*> UGenericPropertyStructValueHandle::GetFieldHandles()
{
	EnsureDirectChildren();

	TArray<UGenericPropertyValueHandleBase*> Result;
	Result.Reserve(ChildHandles.Num());
	for (UGenericPropertyValueHandleBase* ChildHandle : ChildHandles)
	{
		if (ChildHandle != nullptr)
		{
			Result.Add(ChildHandle);
		}
	}

	return Result;
}

UGenericPropertyValueHandleBase* UGenericPropertyStructValueHandle::FindFieldHandle(const FName InPropertyName)
{
	EnsureDirectChildren();
	for (UGenericPropertyValueHandleBase* ChildHandle : ChildHandles)
	{
		if (ChildHandle != nullptr && ChildHandle->Descriptor.PropertyName == InPropertyName)
		{
			return ChildHandle;
		}
	}

	return nullptr;
}

void UGenericPropertyStructValueHandle::EnsureDirectChildren()
{
	if (bChildrenInitialized)
	{
		return;
	}

	Super::EnsureDirectChildren();
	if (!ChildHandles.IsEmpty() || LegacyProperty.IsValid())
	{
		return;
	}

	if (TSharedPtr<FGenericPropertySessionCore> Session = SessionCore.Pin())
	{
		TArray<FGenericPropertyDescriptor> ChildDescriptors;
		Session->GetChildDescriptors(Descriptor.FieldKey, ChildDescriptors);
		for (const FGenericPropertyDescriptor& ChildDescriptor : ChildDescriptors)
		{
			if (UGenericPropertyValueHandleBase* ChildHandle = Session->CreateValueHandle(ChildDescriptor.FieldKey))
			{
				ChildHandles.Add(ChildHandle);
			}
		}
	}
}

int32 UGenericPropertyContainerValueHandle::GetElementCount() const
{
	if (const UGenericProperty* Property = LegacyProperty.Get())
	{
		return Property->Children.Num();
	}

	return ChildHandles.Num();
}

bool UGenericPropertyContainerValueHandle::Clear()
{
	if (UGenericProperty* Property = LegacyProperty.Get())
	{
		const bool bResult = Property->ClearContainer();
		SyncFromLegacyProperty();
		return bResult;
	}

	return false;
}

void UGenericPropertyContainerValueHandle::EnsureDirectChildren()
{
	Super::EnsureDirectChildren();
}

UGenericPropertyValueHandleBase* UGenericPropertyArrayValueHandle::GetElementHandle(const int32 InIndex)
{
	EnsureDirectChildren();
	return ChildHandles.IsValidIndex(InIndex) ? ChildHandles[InIndex] : nullptr;
}

bool UGenericPropertyArrayValueHandle::AddElement()
{
	if (UGenericProperty* Property = LegacyProperty.Get())
	{
		const bool bResult = Property->AddContainerElement();
		SyncFromLegacyProperty();
		bChildrenInitialized = false;
		ChildHandles.Reset();
		return bResult;
	}

	return false;
}

bool UGenericPropertyArrayValueHandle::InsertElement(const int32 InIndex)
{
	if (!AddElement())
	{
		return false;
	}

	if (UGenericPropertyValueHandleBase* AddedHandle = GetElementHandle(GetElementCount() - 1); AddedHandle != nullptr)
	{
		if (UGenericProperty* AddedProperty = AddedHandle->GetLegacyProperty())
		{
			return AddedProperty->MoveArrayElement(InIndex);
		}
	}

	return false;
}

bool UGenericPropertyArrayValueHandle::DuplicateElement(const int32 InIndex)
{
	if (UGenericPropertyValueHandleBase* ElementHandle = GetElementHandle(InIndex); ElementHandle != nullptr)
	{
		if (UGenericProperty* ElementProperty = ElementHandle->GetLegacyProperty())
		{
			return ElementProperty->DuplicateNode();
		}
	}

	return false;
}

bool UGenericPropertyArrayValueHandle::RemoveElement(const int32 InIndex)
{
	if (UGenericPropertyValueHandleBase* ElementHandle = GetElementHandle(InIndex); ElementHandle != nullptr)
	{
		if (UGenericProperty* ElementProperty = ElementHandle->GetLegacyProperty())
		{
			return ElementProperty->RemoveNode();
		}
	}

	return false;
}

bool UGenericPropertyArrayValueHandle::MoveElement(const int32 InFromIndex, const int32 InToIndex)
{
	if (UGenericPropertyValueHandleBase* ElementHandle = GetElementHandle(InFromIndex); ElementHandle != nullptr)
	{
		if (UGenericProperty* ElementProperty = ElementHandle->GetLegacyProperty())
		{
			return ElementProperty->MoveArrayElement(InToIndex);
		}
	}

	return false;
}

UGenericPropertyValueHandleBase* UGenericPropertySetValueHandle::GetElementHandle(const int32 InIndex)
{
	EnsureDirectChildren();
	return ChildHandles.IsValidIndex(InIndex) ? ChildHandles[InIndex] : nullptr;
}

bool UGenericPropertySetValueHandle::AddElement()
{
	if (UGenericProperty* Property = LegacyProperty.Get())
	{
		return Property->AddContainerElement();
	}

	return false;
}

bool UGenericPropertySetValueHandle::RemoveElement(const int32 InIndex)
{
	if (UGenericPropertyValueHandleBase* ElementHandle = GetElementHandle(InIndex); ElementHandle != nullptr)
	{
		if (UGenericProperty* ElementProperty = ElementHandle->GetLegacyProperty())
		{
			return ElementProperty->RemoveNode();
		}
	}

	return false;
}

int32 UGenericPropertyMapValueHandle::GetEntryCount() const
{
	return GetElementCount();
}

UGenericPropertyValueHandleBase* UGenericPropertyMapValueHandle::GetKeyHandle(const int32 InIndex)
{
	EnsureDirectChildren();
	if (!ChildHandles.IsValidIndex(InIndex) || ChildHandles[InIndex] == nullptr)
	{
		return nullptr;
	}

	const TArray<TObjectPtr<UGenericPropertyValueHandleBase>>& EntryChildren = ChildHandles[InIndex]->GetChildHandlesInternal();
	return EntryChildren.IsValidIndex(0) ? EntryChildren[0] : nullptr;
}

UGenericPropertyValueHandleBase* UGenericPropertyMapValueHandle::GetValueHandle(const int32 InIndex)
{
	EnsureDirectChildren();
	if (!ChildHandles.IsValidIndex(InIndex) || ChildHandles[InIndex] == nullptr)
	{
		return nullptr;
	}

	const TArray<TObjectPtr<UGenericPropertyValueHandleBase>>& EntryChildren = ChildHandles[InIndex]->GetChildHandlesInternal();
	return EntryChildren.IsValidIndex(1) ? EntryChildren[1] : nullptr;
}

bool UGenericPropertyMapValueHandle::AddEntry()
{
	if (UGenericProperty* Property = LegacyProperty.Get())
	{
		return Property->AddContainerElement();
	}

	return false;
}

bool UGenericPropertyMapValueHandle::RemoveEntry(const int32 InIndex)
{
	EnsureDirectChildren();
	if (UGenericPropertyValueHandleBase* EntryHandle = ChildHandles.IsValidIndex(InIndex) ? ChildHandles[InIndex] : nullptr)
	{
		if (UGenericProperty* EntryProperty = EntryHandle->GetLegacyProperty())
		{
			return EntryProperty->RemoveNode();
		}
	}

	return false;
}
