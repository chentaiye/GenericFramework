#include "Model/GenericPropertySessionCore.h"

#include "Core/GenericProperty.h"
#include "Core/GenericPropertyReflection.h"
#include "GameplayTagsManager.h"
#include "Handle/GenericPropertyValueHandle.h"
#include "Model/GenericPropertyProxy.h"

namespace GenericPropertyFramework::Private
{
	namespace
	{
		void AppendMetadataTags(const TMap<FName, FString>& InMetadata, FGameplayTagContainer& OutTags)
		{
			static const TSet<FName> SupportedTagMetadataKeys = {
				TEXT("GenericPropertyTag"),
				TEXT("GenericPropertyTags"),
				TEXT("GameplayTagFilter")
			};

			for (const TPair<FName, FString>& Pair : InMetadata)
			{
				if (!SupportedTagMetadataKeys.Contains(Pair.Key) || Pair.Value.IsEmpty())
				{
					continue;
				}

				FString NormalizedValue = Pair.Value;
				NormalizedValue.ReplaceInline(TEXT(";"), TEXT(","));
				NormalizedValue.ReplaceInline(TEXT("|"), TEXT(","));

				TArray<FString> TagStrings;
				NormalizedValue.ParseIntoArray(TagStrings, TEXT(","), true);
				for (FString& TagString : TagStrings)
				{
					TagString.TrimStartAndEndInline();
					if (TagString.IsEmpty())
					{
						continue;
					}

					const FGameplayTag Tag = UGameplayTagsManager::Get().RequestGameplayTag(FName(*TagString), false);
					if (Tag.IsValid())
					{
						OutTags.AddTagFast(Tag);
					}
				}
			}
		}

		FName ResolveStyleKey(const FPropertyDescriptor& InDescriptor)
		{
			if (const FString* StyleKeyValue = InDescriptor.Metadata.Find(TEXT("GenericPropertyStyle")); StyleKeyValue != nullptr && !StyleKeyValue->IsEmpty())
			{
				return FName(**StyleKeyValue);
			}

			if (InDescriptor.TypeName != NAME_None)
			{
				return InDescriptor.TypeName;
			}

			return InDescriptor.PropertyName;
		}

		FGenericPropertyDescriptor MakePublicDescriptor(const FPropertyDescriptor& InDescriptor)
		{
			FGenericPropertyDescriptor PublicDescriptor;
			PublicDescriptor.FieldKey = FGenericPropertyFieldKey::FromAccessPath(InDescriptor.AccessPath);
			PublicDescriptor.FieldKey.PropertyPath = InDescriptor.PropertyPath;
			PublicDescriptor.PropertyName = InDescriptor.PropertyName;
			PublicDescriptor.CategoryName = InDescriptor.CategoryName;
			PublicDescriptor.DisplayName = InDescriptor.DisplayName;
			PublicDescriptor.ToolTip = InDescriptor.ToolTip;
			PublicDescriptor.StyleKey = ResolveStyleKey(InDescriptor);
			PublicDescriptor.NodeKind = InDescriptor.NodeKind;
			PublicDescriptor.ValueType = InDescriptor.Property != nullptr ? GetPropertyValueType(*InDescriptor.Property) : EGenericPropertyValueType::Unknown;
			PublicDescriptor.NativeTypeName = InDescriptor.TypeName;
			PublicDescriptor.TypeObjectPath = InDescriptor.TypeObjectPath;
			PublicDescriptor.bSupportsDirectEdit = InDescriptor.bSupportsDirectEdit;
			PublicDescriptor.bCanExpand = InDescriptor.bCanExpand;
			PublicDescriptor.bIsSupported = InDescriptor.bIsSupported;
			PublicDescriptor.Metadata = InDescriptor.Metadata;
			PublicDescriptor.EditConditionExpression = InDescriptor.EditConditionExpression;
			AppendMetadataTags(InDescriptor.Metadata, PublicDescriptor.VisualTags);
			return PublicDescriptor;
		}

		void CacheDescriptorRecursive(const FPropertyDescriptor& InDescriptor, TMap<FString, FGenericPropertyDescriptor>& OutDescriptorsByKey, TMap<FString, TArray<FGenericPropertyDescriptor>>& OutChildDescriptorsByKey)
		{
			const FGenericPropertyDescriptor PublicDescriptor = MakePublicDescriptor(InDescriptor);
			const FString StableKey = PublicDescriptor.FieldKey.ToStableKey();

			if (!StableKey.IsEmpty())
			{
				OutDescriptorsByKey.FindOrAdd(StableKey) = PublicDescriptor;

				TArray<FGenericPropertyDescriptor>& ChildDescriptors = OutChildDescriptorsByKey.FindOrAdd(StableKey);
				ChildDescriptors.Reset();
				for (const TSharedPtr<FPropertyDescriptor>& Child : InDescriptor.Children)
				{
					if (!Child.IsValid())
					{
						continue;
					}

					const FGenericPropertyDescriptor PublicChildDescriptor = MakePublicDescriptor(*Child);
					ChildDescriptors.Add(PublicChildDescriptor);
					CacheDescriptorRecursive(*Child, OutDescriptorsByKey, OutChildDescriptorsByKey);
				}
			}
		}

		bool NativeTypeEquals(const FGenericPropertyDescriptor& InDescriptor, const TCHAR* InExpected)
		{
			return InDescriptor.NativeTypeName == FName(InExpected);
		}

		bool NativeTypeContains(const FGenericPropertyDescriptor& InDescriptor, const TCHAR* InExpected)
		{
			return InDescriptor.NativeTypeName.ToString().Contains(InExpected);
		}
	}
}

FGenericPropertySessionCore::FGenericPropertySessionCore(UGenericPropertyProxy& InOwnerProxy)
	: OwnerProxy(&InOwnerProxy)
{
}

void FGenericPropertySessionCore::InvalidateDescriptorCache()
{
	CachedStructs.Reset();
	DescriptorsByKey.Reset();
	ChildDescriptorsByKey.Reset();
	HandlesByKey.Reset();
}

bool FGenericPropertySessionCore::ResolveField(const UClass* InObjectClass, const FString& InFieldPath, FGenericPropertyFieldKey& OutFieldKey, FGenericPropertyDescriptor* OutDescriptor)
{
	OutFieldKey = FGenericPropertyFieldKey();
	if (InObjectClass == nullptr)
	{
		return false;
	}

	EnsureDescriptorsForClass(InObjectClass);
	const FString TrimmedFieldPath = InFieldPath.TrimStartAndEnd();
	if (TrimmedFieldPath.IsEmpty())
	{
		return false;
	}

	for (const TPair<FString, FGenericPropertyDescriptor>& Pair : DescriptorsByKey)
	{
		if (Pair.Value.FieldKey.PropertyPath.Equals(TrimmedFieldPath, ESearchCase::CaseSensitive)
			|| Pair.Value.FieldKey.AccessPath.ToString().Equals(TrimmedFieldPath, ESearchCase::CaseSensitive))
		{
			OutFieldKey = Pair.Value.FieldKey;
			if (OutDescriptor != nullptr)
			{
				*OutDescriptor = Pair.Value;
			}
			return true;
		}
	}

	return false;
}

bool FGenericPropertySessionCore::ResolveDescriptor(const FGenericPropertyFieldKey& InFieldKey, FGenericPropertyDescriptor& OutDescriptor)
{
	if (!InFieldKey.IsValid())
	{
		return false;
	}

	if (UGenericPropertyProxy* Proxy = OwnerProxy.Get())
	{
		for (const TWeakObjectPtr<UObject>& Target : Proxy->GetTargets())
		{
			if (Target.IsValid())
			{
				EnsureDescriptorsForClass(Target->GetClass());
			}
		}
	}

	if (const FGenericPropertyDescriptor* CachedDescriptor = DescriptorsByKey.Find(InFieldKey.ToStableKey()))
	{
		OutDescriptor = *CachedDescriptor;
		return true;
	}

	return false;
}

void FGenericPropertySessionCore::GetChildDescriptors(const FGenericPropertyFieldKey& InFieldKey, TArray<FGenericPropertyDescriptor>& OutDescriptors)
{
	OutDescriptors.Reset();

	FGenericPropertyDescriptor ParentDescriptor;
	if (!ResolveDescriptor(InFieldKey, ParentDescriptor))
	{
		return;
	}

	if (const TArray<FGenericPropertyDescriptor>* CachedChildren = ChildDescriptorsByKey.Find(ParentDescriptor.FieldKey.ToStableKey()))
	{
		OutDescriptors = *CachedChildren;
	}
}

FGenericPropertyDescriptor FGenericPropertySessionCore::BuildDescriptorFromProperty(const UGenericProperty& InProperty) const
{
	FGenericPropertyDescriptor Descriptor;
	Descriptor.FieldKey.AccessPath = InProperty.GetAccessPath();
	Descriptor.FieldKey.PropertyPath = InProperty.PropertyPath;
	Descriptor.PropertyName = InProperty.PropertyName;
	Descriptor.CategoryName = InProperty.CategoryName;
	Descriptor.DisplayName = InProperty.DisplayName;
	Descriptor.ToolTip = InProperty.ToolTip;
	Descriptor.StyleKey = InProperty.NativeTypeName != NAME_None ? InProperty.NativeTypeName : InProperty.PropertyName;
	Descriptor.VisualTags = InProperty.VisualTags;
	Descriptor.NodeKind = InProperty.NodeKind;
	Descriptor.ValueType = InProperty.TypeName;
	Descriptor.NativeTypeName = InProperty.NativeTypeName;
	Descriptor.TypeObjectPath = InProperty.TypeObjectPath;
	Descriptor.bSupportsDirectEdit = InProperty.bSupportsDirectEdit;
	Descriptor.bCanExpand = InProperty.bCanExpand;
	Descriptor.bIsSupported = InProperty.bIsSupported;
	Descriptor.Metadata = InProperty.GetMetadata();
	Descriptor.EditConditionExpression = InProperty.EditConditionExpression;
	return Descriptor;
}

UGenericPropertyValueHandleBase* FGenericPropertySessionCore::CreateValueHandle(UGenericProperty* InProperty)
{
	if (InProperty == nullptr)
	{
		return nullptr;
	}

	const FGenericPropertyDescriptor Descriptor = BuildDescriptorFromProperty(*InProperty);
	return CreateValueHandleInternal(Descriptor, InProperty, FString::Printf(TEXT("Property:%s"), *InProperty->GetPathName()));
}

UGenericPropertyValueHandleBase* FGenericPropertySessionCore::CreateValueHandle(const FGenericPropertyFieldKey& InFieldKey)
{
	FGenericPropertyDescriptor Descriptor;
	if (!ResolveDescriptor(InFieldKey, Descriptor))
	{
		return nullptr;
	}

	return CreateValueHandleInternal(Descriptor, nullptr, FString::Printf(TEXT("Field:%s"), *Descriptor.FieldKey.ToStableKey()));
}

void FGenericPropertySessionCore::EnsureDescriptorsForClass(const UClass* InObjectClass)
{
	if (InObjectClass == nullptr || CachedStructs.Contains(TObjectKey<const UStruct>(InObjectClass)))
	{
		return;
	}

	CachedStructs.Add(TObjectKey<const UStruct>(InObjectClass));
	const TArray<TSharedPtr<GenericPropertyFramework::Private::FPropertyDescriptor>>& RootDescriptors = GenericPropertyFramework::Private::FReflectionCache::Get().GetClassDescriptor(InObjectClass);
	for (const TSharedPtr<GenericPropertyFramework::Private::FPropertyDescriptor>& Descriptor : RootDescriptors)
	{
		if (Descriptor.IsValid())
		{
			GenericPropertyFramework::Private::CacheDescriptorRecursive(*Descriptor, DescriptorsByKey, ChildDescriptorsByKey);
		}
	}
}

UGenericPropertyValueHandleBase* FGenericPropertySessionCore::CreateValueHandleInternal(const FGenericPropertyDescriptor& InDescriptor, UGenericProperty* InLegacyProperty, const FString& InCacheKey)
{
	if (UGenericPropertyValueHandleBase* ExistingHandle = HandlesByKey.FindRef(InCacheKey).Get())
	{
		ExistingHandle->InitializeHandle(OwnerProxy.Get(), AsShared(), InDescriptor, InLegacyProperty);
		ExistingHandle->Refresh();
		return ExistingHandle;
	}

	UGenericPropertyProxy* Proxy = OwnerProxy.Get();
	if (Proxy == nullptr)
	{
		return nullptr;
	}

	UClass* HandleClass = ResolveHandleClass(InDescriptor);
	if (HandleClass == nullptr)
	{
		HandleClass = UGenericPropertyValueHandleBase::StaticClass();
	}

	UGenericPropertyValueHandleBase* NewHandle = NewObject<UGenericPropertyValueHandleBase>(Proxy, HandleClass);
	if (NewHandle == nullptr)
	{
		return nullptr;
	}

	NewHandle->InitializeHandle(Proxy, AsShared(), InDescriptor, InLegacyProperty);
	NewHandle->Refresh();
	Proxy->RegisterValueHandle(NewHandle);
	HandlesByKey.Add(InCacheKey, NewHandle);
	return NewHandle;
}

UClass* FGenericPropertySessionCore::ResolveHandleClass(const FGenericPropertyDescriptor& InDescriptor) const
{
	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("bool")))
	{
		return UGenericPropertyBoolValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("uint8")) || GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("int8")))
	{
		return UGenericPropertyByteValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("int64")) || GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("uint64")))
	{
		return UGenericPropertyInteger64ValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("int16"))
		|| GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("uint16"))
		|| GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("int32"))
		|| GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("uint32"))
		|| GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("int")))
	{
		return UGenericPropertyIntegerValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("float")))
	{
		return UGenericPropertyFloatValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("double")))
	{
		return UGenericPropertyDoubleValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("FString")))
	{
		return UGenericPropertyStringValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("FText")))
	{
		return UGenericPropertyTextValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("FName")))
	{
		return UGenericPropertyNameValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("FSoftObjectPath")) || GenericPropertyFramework::Private::NativeTypeContains(InDescriptor, TEXT("TSoftObjectPtr<")))
	{
		return UGenericPropertySoftObjectValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeEquals(InDescriptor, TEXT("FSoftClassPath")) || GenericPropertyFramework::Private::NativeTypeContains(InDescriptor, TEXT("TSoftClassPtr<")))
	{
		return UGenericPropertySoftClassValueHandle::StaticClass();
	}

	if (GenericPropertyFramework::Private::NativeTypeContains(InDescriptor, TEXT("TSubclassOf<")) || GenericPropertyFramework::Private::NativeTypeContains(InDescriptor, TEXT("TNonNullSubclassOf<")))
	{
		return UGenericPropertyClassValueHandle::StaticClass();
	}

	switch (InDescriptor.NodeKind)
	{
	case EGenericPropertyNodeKind::Struct:
		return UGenericPropertyStructValueHandle::StaticClass();

	case EGenericPropertyNodeKind::Array:
		return UGenericPropertyArrayValueHandle::StaticClass();

	case EGenericPropertyNodeKind::Set:
		return UGenericPropertySetValueHandle::StaticClass();

	case EGenericPropertyNodeKind::Map:
		return UGenericPropertyMapValueHandle::StaticClass();

	case EGenericPropertyNodeKind::Warning:
		return UGenericPropertyWarningValueHandle::StaticClass();

	default:
		break;
	}

	switch (InDescriptor.ValueType)
	{
	case EGenericPropertyValueType::Boolean:
		return UGenericPropertyBoolValueHandle::StaticClass();

	case EGenericPropertyValueType::Integer:
		return UGenericPropertyIntegerValueHandle::StaticClass();

	case EGenericPropertyValueType::Float:
		return UGenericPropertyFloatValueHandle::StaticClass();

	case EGenericPropertyValueType::String:
		return UGenericPropertyStringValueHandle::StaticClass();

	case EGenericPropertyValueType::Text:
		return UGenericPropertyTextValueHandle::StaticClass();

	case EGenericPropertyValueType::Name:
		return UGenericPropertyNameValueHandle::StaticClass();

	case EGenericPropertyValueType::Enum:
		return UGenericPropertyEnumValueHandle::StaticClass();

	case EGenericPropertyValueType::Object:
		return UGenericPropertyObjectValueHandle::StaticClass();

	case EGenericPropertyValueType::Struct:
		return UGenericPropertyStructValueHandle::StaticClass();

	case EGenericPropertyValueType::Array:
		return UGenericPropertyArrayValueHandle::StaticClass();

	case EGenericPropertyValueType::Set:
		return UGenericPropertySetValueHandle::StaticClass();

	case EGenericPropertyValueType::Map:
	case EGenericPropertyValueType::MapEntry:
		return UGenericPropertyMapValueHandle::StaticClass();

	case EGenericPropertyValueType::Warning:
		return UGenericPropertyWarningValueHandle::StaticClass();

	case EGenericPropertyValueType::Unknown:
	default:
		return UGenericPropertyValueHandleBase::StaticClass();
	}
}
