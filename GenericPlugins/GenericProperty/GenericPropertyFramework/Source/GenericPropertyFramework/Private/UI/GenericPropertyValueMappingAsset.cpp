#include "UI/GenericPropertyValueMappingAsset.h"

#include "Core/GenericProperty.h"
#include "Handle/GenericPropertyValueHandle.h"
#include "UI/GenericPropertyValue.h"

namespace
{
	bool NativeTypeEquals(const UGenericProperty& InProperty, const TCHAR* InExpected)
	{
		return InProperty.NativeTypeName == FName(InExpected);
	}

	bool NativeTypeContains(const UGenericProperty& InProperty, const TCHAR* InExpected)
	{
		return InProperty.NativeTypeName.ToString().Contains(InExpected);
	}

	bool NativeTypeEquals(const FGenericPropertyDescriptor& InDescriptor, const TCHAR* InExpected)
	{
		return InDescriptor.NativeTypeName == FName(InExpected);
	}

	bool NativeTypeContains(const FGenericPropertyDescriptor& InDescriptor, const TCHAR* InExpected)
	{
		return InDescriptor.NativeTypeName.ToString().Contains(InExpected);
	}

	TSubclassOf<UGenericPropertyValue> ResolveBuiltInValueWidgetClass(const UGenericProperty& InProperty)
	{
		if (NativeTypeEquals(InProperty, TEXT("bool")))
		{
			return UGenericPropertyBoolValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("uint8")) || NativeTypeEquals(InProperty, TEXT("int8")))
		{
			return UGenericPropertyByteValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("int64")) || NativeTypeEquals(InProperty, TEXT("uint64")))
		{
			return UGenericPropertyInteger64Value::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("int16"))
			|| NativeTypeEquals(InProperty, TEXT("uint16"))
			|| NativeTypeEquals(InProperty, TEXT("int32"))
			|| NativeTypeEquals(InProperty, TEXT("uint32"))
			|| NativeTypeEquals(InProperty, TEXT("int")))
		{
			return UGenericPropertyIntegerValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("float")))
		{
			return UGenericPropertyFloatValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("double")))
		{
			return UGenericPropertyDoubleValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("FString")))
		{
			return UGenericPropertyStringValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("FText")))
		{
			return UGenericPropertyTextValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("FName")))
		{
			return UGenericPropertyNameValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("FSoftObjectPath")) || NativeTypeContains(InProperty, TEXT("TSoftObjectPtr<")))
		{
			return UGenericPropertySoftObjectValue::StaticClass();
		}

		if (NativeTypeEquals(InProperty, TEXT("FSoftClassPath")) || NativeTypeContains(InProperty, TEXT("TSoftClassPtr<")))
		{
			return UGenericPropertySoftClassValue::StaticClass();
		}

		if (NativeTypeContains(InProperty, TEXT("TSubclassOf<")) || NativeTypeContains(InProperty, TEXT("TNonNullSubclassOf<")))
		{
			return UGenericPropertyClassValue::StaticClass();
		}

		switch (InProperty.TypeName)
		{
		case EGenericPropertyValueType::Warning:
			return UGenericPropertyWarningValue::StaticClass();

		case EGenericPropertyValueType::Struct:
			return UGenericPropertyStructValue::StaticClass();

		case EGenericPropertyValueType::Array:
		case EGenericPropertyValueType::Set:
		case EGenericPropertyValueType::Map:
		case EGenericPropertyValueType::MapEntry:
			return UGenericPropertyContainerValue::StaticClass();

		case EGenericPropertyValueType::Object:
			return UGenericPropertyObjectValue::StaticClass();

		case EGenericPropertyValueType::Boolean:
			return UGenericPropertyBoolValue::StaticClass();

		case EGenericPropertyValueType::Integer:
			return UGenericPropertyIntegerValue::StaticClass();

		case EGenericPropertyValueType::Float:
			return UGenericPropertyFloatValue::StaticClass();

		case EGenericPropertyValueType::Name:
			return UGenericPropertyNameValue::StaticClass();

		case EGenericPropertyValueType::String:
			return UGenericPropertyStringValue::StaticClass();

		case EGenericPropertyValueType::Text:
			return UGenericPropertyTextValue::StaticClass();

		case EGenericPropertyValueType::Enum:
			return UGenericPropertyEnumValue::StaticClass();

		case EGenericPropertyValueType::Unknown:
		default:
			return UGenericPropertyValue::StaticClass();
		}
	}

	TSubclassOf<UGenericPropertyValue> ResolveBuiltInValueWidgetClass(const FGenericPropertyDescriptor& InDescriptor)
	{
		if (NativeTypeEquals(InDescriptor, TEXT("bool")))
		{
			return UGenericPropertyBoolValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("uint8")) || NativeTypeEquals(InDescriptor, TEXT("int8")))
		{
			return UGenericPropertyByteValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("int64")) || NativeTypeEquals(InDescriptor, TEXT("uint64")))
		{
			return UGenericPropertyInteger64Value::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("int16"))
			|| NativeTypeEquals(InDescriptor, TEXT("uint16"))
			|| NativeTypeEquals(InDescriptor, TEXT("int32"))
			|| NativeTypeEquals(InDescriptor, TEXT("uint32"))
			|| NativeTypeEquals(InDescriptor, TEXT("int")))
		{
			return UGenericPropertyIntegerValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("float")))
		{
			return UGenericPropertyFloatValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("double")))
		{
			return UGenericPropertyDoubleValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("FString")))
		{
			return UGenericPropertyStringValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("FText")))
		{
			return UGenericPropertyTextValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("FName")))
		{
			return UGenericPropertyNameValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("FSoftObjectPath")) || NativeTypeContains(InDescriptor, TEXT("TSoftObjectPtr<")))
		{
			return UGenericPropertySoftObjectValue::StaticClass();
		}

		if (NativeTypeEquals(InDescriptor, TEXT("FSoftClassPath")) || NativeTypeContains(InDescriptor, TEXT("TSoftClassPtr<")))
		{
			return UGenericPropertySoftClassValue::StaticClass();
		}

		if (NativeTypeContains(InDescriptor, TEXT("TSubclassOf<")) || NativeTypeContains(InDescriptor, TEXT("TNonNullSubclassOf<")))
		{
			return UGenericPropertyClassValue::StaticClass();
		}

		switch (InDescriptor.ValueType)
		{
		case EGenericPropertyValueType::Warning:
			return UGenericPropertyWarningValue::StaticClass();
		case EGenericPropertyValueType::Struct:
			return UGenericPropertyStructValue::StaticClass();
		case EGenericPropertyValueType::Array:
		case EGenericPropertyValueType::Set:
		case EGenericPropertyValueType::Map:
		case EGenericPropertyValueType::MapEntry:
			return UGenericPropertyContainerValue::StaticClass();
		case EGenericPropertyValueType::Object:
			return UGenericPropertyObjectValue::StaticClass();
		case EGenericPropertyValueType::Boolean:
			return UGenericPropertyBoolValue::StaticClass();
		case EGenericPropertyValueType::Integer:
			return UGenericPropertyIntegerValue::StaticClass();
		case EGenericPropertyValueType::Float:
			return UGenericPropertyFloatValue::StaticClass();
		case EGenericPropertyValueType::Name:
			return UGenericPropertyNameValue::StaticClass();
		case EGenericPropertyValueType::String:
			return UGenericPropertyStringValue::StaticClass();
		case EGenericPropertyValueType::Text:
			return UGenericPropertyTextValue::StaticClass();
		case EGenericPropertyValueType::Enum:
			return UGenericPropertyEnumValue::StaticClass();
		case EGenericPropertyValueType::Unknown:
		default:
			return UGenericPropertyValue::StaticClass();
		}
	}

	int32 ScoreRule(const FGenericPropertyValueClassRule& InRule, const UGenericProperty& InProperty)
	{
		int32 Score = InRule.Priority;

		if (InRule.bMatchNodeKind)
		{
			if (InRule.NodeKind != InProperty.NodeKind)
			{
				return INDEX_NONE;
			}

			Score += 16;
		}

		if (InRule.TypeName != EGenericPropertyValueType::Unknown)
		{
			if (InRule.TypeName != InProperty.TypeName)
			{
				return INDEX_NONE;
			}

			Score += 8;
		}

		if (!InRule.NativeTypeContains.IsEmpty())
		{
			if (!InProperty.NativeTypeName.ToString().Contains(InRule.NativeTypeContains))
			{
				return INDEX_NONE;
			}

			Score += 6;
		}

		if (InRule.PropertyName != NAME_None)
		{
			if (InRule.PropertyName != InProperty.PropertyName)
			{
				return INDEX_NONE;
			}

			Score += 4;
		}

		if (!InRule.PathContains.IsEmpty())
		{
			if (!InProperty.PropertyPath.Contains(InRule.PathContains))
			{
				return INDEX_NONE;
			}

			Score += 2;
		}

		return Score;
	}
}

TSubclassOf<UGenericPropertyValue> UGenericPropertyValueMappingAsset::ResolveValueWidgetClass(const UGenericProperty* InProperty) const
{
	if (InProperty == nullptr)
	{
		return nullptr;
	}

	int32 BestScore = INDEX_NONE;
	TSubclassOf<UGenericPropertyValue> BestClass = nullptr;

	for (const FGenericPropertyValueClassRule& Rule : Rules)
	{
		const int32 RuleScore = ScoreRule(Rule, *InProperty);
		if (RuleScore == INDEX_NONE)
		{
			continue;
		}

		if (TSubclassOf<UGenericPropertyValue> RuleClass = Rule.WidgetClass.LoadSynchronous())
		{
			if (RuleScore > BestScore)
			{
				BestScore = RuleScore;
				BestClass = RuleClass;
			}
		}
	}

	if (BestClass != nullptr)
	{
		return BestClass;
	}

	if (TSubclassOf<UGenericPropertyValue> DefaultClass = DefaultWidgetClass.LoadSynchronous())
	{
		return DefaultClass;
	}

	return ResolveBuiltInValueWidgetClass(*InProperty);
}

TSubclassOf<UGenericPropertyValue> UGenericPropertyValueMappingAsset::ResolveValueWidgetClassForHandle(const UGenericPropertyValueHandleBase* InValueHandle) const
{
	return InValueHandle != nullptr ? ResolveValueWidgetClassForDescriptor(InValueHandle->Descriptor) : nullptr;
}

TSubclassOf<UGenericPropertyValue> UGenericPropertyValueMappingAsset::ResolveValueWidgetClassForDescriptor(const FGenericPropertyDescriptor& InDescriptor) const
{
	int32 BestScore = INDEX_NONE;
	TSubclassOf<UGenericPropertyValue> BestClass = nullptr;

	for (const FGenericPropertyValueClassRule& Rule : Rules)
	{
		int32 Score = Rule.Priority;

		if (Rule.bMatchNodeKind)
		{
			if (Rule.NodeKind != InDescriptor.NodeKind)
			{
				continue;
			}

			Score += 16;
		}

		if (Rule.TypeName != EGenericPropertyValueType::Unknown)
		{
			if (Rule.TypeName != InDescriptor.ValueType)
			{
				continue;
			}

			Score += 8;
		}

		if (!Rule.NativeTypeContains.IsEmpty())
		{
			if (!InDescriptor.NativeTypeName.ToString().Contains(Rule.NativeTypeContains))
			{
				continue;
			}

			Score += 6;
		}

		if (Rule.PropertyName != NAME_None)
		{
			if (Rule.PropertyName != InDescriptor.PropertyName)
			{
				continue;
			}

			Score += 4;
		}

		if (!Rule.PathContains.IsEmpty())
		{
			if (!InDescriptor.FieldKey.PropertyPath.Contains(Rule.PathContains))
			{
				continue;
			}

			Score += 2;
		}

		if (TSubclassOf<UGenericPropertyValue> RuleClass = Rule.WidgetClass.LoadSynchronous())
		{
			if (Score > BestScore)
			{
				BestScore = Score;
				BestClass = RuleClass;
			}
		}
	}

	if (BestClass != nullptr)
	{
		return BestClass;
	}

	if (TSubclassOf<UGenericPropertyValue> DefaultClass = DefaultWidgetClass.LoadSynchronous())
	{
		return DefaultClass;
	}

	return ResolveBuiltInValueWidgetClass(InDescriptor);
}
