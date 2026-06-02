#include "Core/GenericPropertyReflection.h"

#include "GenericPropertyFramework.h"
#include "Core/GenericProperty.h"
#include "Model/GenericPropertyProxy.h"
#include "UObject/Class.h"
#include "UObject/Field.h"
#include "UObject/SoftObjectPath.h"
#include "UObject/UnrealType.h"

namespace GenericPropertyFramework::Private
{
	namespace
	{
		static const FName DefaultCategoryName(TEXT("Default"));

		TArray<FName> GetTrackedMetadataKeys()
		{
			return {
				TEXT("DisplayName"),
				TEXT("ToolTip"),
				TEXT("Category"),
				TEXT("AdvancedDisplay"),
				TEXT("EditCondition"),
				TEXT("ClampMin"),
				TEXT("ClampMax"),
				TEXT("UIMin"),
				TEXT("UIMax"),
				TEXT("Delta"),
				TEXT("Units"),
				TEXT("MultiLine"),
				TEXT("PasswordField"),
				TEXT("AllowedClasses"),
				TEXT("DisallowedClasses"),
				TEXT("ExactClass"),
				TEXT("TitleProperty"),
				TEXT("ShowOnlyInnerProperties"),
				TEXT("InlineEditConditionToggle"),
				TEXT("NoResetToDefault"),
				TEXT("Bitmask"),
				TEXT("BitmaskEnum")
			};
		}

		bool IsUsableNodeOwner(const UObject* InObject)
		{
			return IsValid(InObject) && !InObject->HasAnyFlags(RF_BeginDestroyed | RF_FinishDestroyed);
		}

		UGenericProperty* CreatePropertyNode()
		{
			return NewObject<UGenericProperty>(GetTransientPackage());
		}

		const FProperty* FindPropertyByName(const UStruct* InStruct, const FName InName)
		{
			if (InStruct == nullptr)
			{
				return nullptr;
			}

			for (TFieldIterator<FProperty> It(InStruct, EFieldIterationFlags::IncludeSuper); It; ++It)
			{
				if (It->GetFName() == InName)
				{
					return *It;
				}
			}

			return nullptr;
		}

		bool IsObjectLikeProperty(const FProperty& InProperty)
		{
			return CastField<const FObjectPropertyBase>(&InProperty) != nullptr
				|| CastField<const FSoftObjectProperty>(&InProperty) != nullptr
				|| CastField<const FWeakObjectProperty>(&InProperty) != nullptr
				|| CastField<const FLazyObjectProperty>(&InProperty) != nullptr
				|| CastField<const FClassProperty>(&InProperty) != nullptr
				|| CastField<const FSoftClassProperty>(&InProperty) != nullptr;
		}

		bool IsPropertyEditableByFlags(const FProperty& InProperty)
		{
			return !InProperty.HasAnyPropertyFlags(CPF_EditConst | CPF_DisableEditOnInstance);
		}

		bool HasFieldMetaData(const FField& InField, const FName InKey)
		{
#if WITH_METADATA
			return InField.HasMetaData(InKey);
#else
			return false;
#endif
		}

		FString GetFieldMetaData(const FField& InField, const FName InKey)
		{
#if WITH_METADATA
			return InField.GetMetaData(InKey);
#else
			return FString();
#endif
		}

		FText GetFieldDisplayName(const FField& InField)
		{
#if WITH_EDITORONLY_DATA
			return InField.GetDisplayNameText();
#else
			return FText::FromString(InField.GetAuthoredName());
#endif
		}

		FText GetFieldToolTip(const FField& InField)
		{
#if WITH_EDITORONLY_DATA
			return InField.GetToolTipText();
#else
			return FText::GetEmpty();
#endif
		}

		FName GetCategoryName(const FProperty& InProperty)
		{
			if (HasFieldMetaData(InProperty, TEXT("Category")))
			{
				return FName(GetFieldMetaData(InProperty, TEXT("Category")));
			}

			return DefaultCategoryName;
		}

		FText MakeDisplayNameForSegment(const EGenericPropertyAccessType InType, const int32 InIndex)
		{
			switch (InType)
			{
			case EGenericPropertyAccessType::ArrayElement:
				return FText::FromString(FString::Printf(TEXT("[%d]"), InIndex));

			case EGenericPropertyAccessType::SetElement:
				return FText::FromString(FString::Printf(TEXT("{%d}"), InIndex));

			case EGenericPropertyAccessType::MapKey:
				return FText::FromString(FString::Printf(TEXT("Key %d"), InIndex));

			case EGenericPropertyAccessType::MapValue:
				return FText::FromString(FString::Printf(TEXT("Value %d"), InIndex));

			default:
				return FText::GetEmpty();
			}
		}

		EGenericPropertyNodeKind GetNodeKindInternal(const FProperty& InProperty)
		{
			if (CastField<const FStructProperty>(&InProperty) != nullptr)
			{
				return EGenericPropertyNodeKind::Struct;
			}

			if (CastField<const FArrayProperty>(&InProperty) != nullptr)
			{
				return EGenericPropertyNodeKind::Array;
			}

			if (CastField<const FSetProperty>(&InProperty) != nullptr)
			{
				return EGenericPropertyNodeKind::Set;
			}

			if (CastField<const FMapProperty>(&InProperty) != nullptr)
			{
				return EGenericPropertyNodeKind::Map;
			}

			if (IsObjectLikeProperty(InProperty))
			{
				return EGenericPropertyNodeKind::Object;
			}

			return EGenericPropertyNodeKind::Value;
		}

		bool CanEverExpandProperty(const FProperty& InProperty)
		{
			const EGenericPropertyNodeKind NodeKind = GetNodeKindInternal(InProperty);
			return NodeKind == EGenericPropertyNodeKind::Struct
				|| NodeKind == EGenericPropertyNodeKind::Array
				|| NodeKind == EGenericPropertyNodeKind::Set
				|| NodeKind == EGenericPropertyNodeKind::Map
				|| NodeKind == EGenericPropertyNodeKind::Object;
		}

		bool IsExpansionEnabled(const EGenericPropertyNodeKind InNodeKind, const FGenericPropertyPanelOptions& InOptions)
		{
			switch (InNodeKind)
			{
			case EGenericPropertyNodeKind::Struct:
				return InOptions.bExpandStructProperties;

			case EGenericPropertyNodeKind::Array:
			case EGenericPropertyNodeKind::Set:
			case EGenericPropertyNodeKind::Map:
				return InOptions.bExpandContainerProperties;

			case EGenericPropertyNodeKind::Object:
				return InOptions.bExpandObjectProperties;

			default:
				return false;
			}
		}

		bool CanExpandProperty(const FProperty& InProperty, const FGenericPropertyPanelOptions& InOptions)
		{
			return IsExpansionEnabled(GetNodeKindInternal(InProperty), InOptions);
		}

		bool SupportsDirectEditInternal(const FProperty& InProperty)
		{
			return GetNodeKindInternal(InProperty) == EGenericPropertyNodeKind::Value;
		}

		bool ShouldEagerBuildChildren(const UGenericProperty& InNode)
		{
			return InNode.bCanExpand
				&& InNode.NodeKind != EGenericPropertyNodeKind::MapEntry
				&& InNode.NodeKind != EGenericPropertyNodeKind::Object;
		}

		FGenericPropertyAccessPath CombinePaths(const FGenericPropertyAccessPath& InPrefix, const FGenericPropertyAccessPath& InRelative)
		{
			FGenericPropertyAccessPath Result;
			Result.Segments = InPrefix.Segments;
			Result.Segments.Append(InRelative.Segments);
			return Result;
		}

		void CopyMetadata(const FProperty& InProperty, TMap<FName, FString>& OutMetadata)
		{
			for (const FName& Key : GetTrackedMetadataKeys())
			{
				if (HasFieldMetaData(InProperty, Key))
				{
					OutMetadata.Add(Key, GetFieldMetaData(InProperty, Key));
				}
			}
		}

		bool DescendIntoProperty(const FProperty& InProperty, void* InValuePtr, const FProperty*& OutProperty, void*& OutContainerPtr, const UStruct*& OutStruct)
		{
			OutProperty = &InProperty;
			OutContainerPtr = InValuePtr;
			OutStruct = nullptr;

			if (const FStructProperty* StructProperty = CastField<const FStructProperty>(&InProperty))
			{
				OutStruct = StructProperty->Struct;
				return true;
			}

			if (const FObjectPropertyBase* ObjectProperty = CastField<const FObjectPropertyBase>(&InProperty))
			{
				if (UObject* SubObject = ObjectProperty->GetObjectPropertyValue(InValuePtr))
				{
					OutContainerPtr = SubObject;
					OutStruct = SubObject->GetClass();
					return true;
				}

				return false;
			}

			return CastField<const FArrayProperty>(&InProperty) != nullptr
				|| CastField<const FSetProperty>(&InProperty) != nullptr
				|| CastField<const FMapProperty>(&InProperty) != nullptr;
		}

		void* AllocateReflectionPropertyValue(const FProperty& InProperty)
		{
			void* Buffer = FMemory::Malloc(InProperty.GetSize(), InProperty.GetMinAlignment());
			InProperty.InitializeValue(Buffer);
			return Buffer;
		}

		void FreeReflectionPropertyValue(const FProperty& InProperty, void* InBuffer)
		{
			if (InBuffer == nullptr)
			{
				return;
			}

			InProperty.DestroyValue(InBuffer);
			FMemory::Free(InBuffer);
		}

		FString MakeContainerSummary(const FProperty& InProperty, const void* InValuePtr)
		{
			if (const FArrayProperty* ArrayProperty = CastField<const FArrayProperty>(&InProperty))
			{
				FScriptArrayHelper Helper(ArrayProperty, InValuePtr);
				return FString::Printf(TEXT("Array (%d)"), Helper.Num());
			}

			if (const FSetProperty* SetProperty = CastField<const FSetProperty>(&InProperty))
			{
				FScriptSetHelper Helper(SetProperty, InValuePtr);
				return FString::Printf(TEXT("Set (%d)"), Helper.Num());
			}

			if (const FMapProperty* MapProperty = CastField<const FMapProperty>(&InProperty))
			{
				FScriptMapHelper Helper(MapProperty, InValuePtr);
				return FString::Printf(TEXT("Map (%d)"), Helper.Num());
			}

			if (const FStructProperty* StructProperty = CastField<const FStructProperty>(&InProperty))
			{
				return StructProperty->Struct != nullptr ? StructProperty->Struct->GetName() : TEXT("Struct");
			}

			return ExportValueToString(InProperty, InValuePtr);
		}

		bool AllTargetsResolve(const UGenericPropertyProxy& InProxy, const FGenericPropertyAccessPath& InPath)
		{
			const TArray<TWeakObjectPtr<UObject>>& Targets = InProxy.GetTargets();
			for (const TWeakObjectPtr<UObject>& Target : Targets)
			{
				FResolvedValue ResolvedValue;
				if (!Target.IsValid() || !ResolveValue(Target.Get(), InPath, ResolvedValue))
				{
					return false;
				}
			}

			return !Targets.IsEmpty();
		}

		const UClass* FindCommonBaseClass(const TArray<TWeakObjectPtr<UObject>>& InTargets)
		{
			if (InTargets.IsEmpty() || !InTargets[0].IsValid())
			{
				return nullptr;
			}

			const UClass* CommonClass = InTargets[0]->GetClass();
			while (CommonClass != nullptr)
			{
				bool bMatchesAll = true;
				for (const TWeakObjectPtr<UObject>& Target : InTargets)
				{
					if (!Target.IsValid() || !Target->IsA(CommonClass))
					{
						bMatchesAll = false;
						break;
					}
				}

				if (bMatchesAll)
				{
					return CommonClass;
				}

				CommonClass = CommonClass->GetSuperClass();
			}

			return nullptr;
		}

		bool ShouldIncludeRootDescriptorForClass(const FPropertyDescriptor& InDescriptor, const UClass* InTargetClass, const FGenericPropertyPanelOptions& InOptions)
		{
			if (InOptions.bIncludeSuperClassRootProperties || InTargetClass == nullptr)
			{
				return true;
			}

			const UClass* OwnerClass = Cast<UClass>(InDescriptor.OwnerStruct);
			if (OwnerClass == nullptr)
			{
				return true;
			}

			return OwnerClass->IsChildOf(InTargetClass);
		}

		const UClass* FindCommonBaseClass(const TArray<UObject*>& InTargets)
		{
			if (InTargets.IsEmpty() || InTargets[0] == nullptr)
			{
				return nullptr;
			}

			const UClass* CommonClass = InTargets[0]->GetClass();
			while (CommonClass != nullptr)
			{
				bool bMatchesAll = true;
				for (UObject* Target : InTargets)
				{
					if (Target == nullptr || !Target->IsA(CommonClass))
					{
						bMatchesAll = false;
						break;
					}
				}

				if (bMatchesAll)
				{
					return CommonClass;
				}

				CommonClass = CommonClass->GetSuperClass();
			}

			return nullptr;
		}

		void ResetCommandCapabilities(UGenericProperty& InNode)
		{
			InNode.bSupportsAddElement = false;
			InNode.bSupportsRemoveElement = false;
			InNode.bSupportsDuplicateElement = false;
			InNode.bSupportsReorderElement = false;
			InNode.bSupportsClearChildren = false;
		}

		void UpdateCommandCapabilities(UGenericProperty& InNode, const int32 InTargetCount)
		{
			ResetCommandCapabilities(InNode);

			if (InNode.NodeKind == EGenericPropertyNodeKind::Array)
			{
				InNode.bSupportsAddElement = true;
				InNode.bSupportsClearChildren = true;
			}
			else if (InNode.NodeKind == EGenericPropertyNodeKind::Set || InNode.NodeKind == EGenericPropertyNodeKind::Map)
			{
				InNode.bSupportsAddElement = InTargetCount == 1;
				InNode.bSupportsClearChildren = InTargetCount == 1;
			}

			if (InNode.ParentNode != nullptr && InNode.ContainerElementIndex != INDEX_NONE)
			{
				if (InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::Array)
				{
					InNode.bSupportsRemoveElement = true;
					InNode.bSupportsDuplicateElement = true;
					InNode.bSupportsReorderElement = true;
				}
				else if (InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::Set)
				{
					InNode.bSupportsRemoveElement = InTargetCount == 1;
				}
				else if (InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::Map)
				{
					InNode.bSupportsRemoveElement = InTargetCount == 1;
				}
			}
		}

		void SetWarningIfUnsupportedLeaf(UGenericProperty& InNode, const FProperty& InProperty)
		{
			if (!InNode.bIsSupported && !InNode.bCanExpand)
			{
				InNode.NodeKind = EGenericPropertyNodeKind::Warning;
				if (!InNode.Issue.IsSet())
				{
					InNode.Issue.Severity = EGenericPropertyIssueSeverity::Warning;
					InNode.Issue.Type = EGenericPropertyIssueType::UnsupportedType;
					InNode.Issue.Message = FText::FromString(FString::Printf(TEXT("Unsupported property type '%s'. Falling back to read-only display."), *InProperty.GetCPPType()));
				}
			}
		}
	}

	FReflectionCache& FReflectionCache::Get()
	{
		static FReflectionCache Instance;
		return Instance;
	}

	const TArray<TSharedPtr<FPropertyDescriptor>>& FReflectionCache::GetClassDescriptor(const UClass* InClass)
	{
		return BuildDescriptor(InClass);
	}

	const TArray<TSharedPtr<FPropertyDescriptor>>& FReflectionCache::GetStructDescriptor(const UStruct* InStruct)
	{
		return BuildDescriptor(InStruct);
	}

	const TArray<TSharedPtr<FPropertyDescriptor>>& FReflectionCache::BuildDescriptor(const UStruct* InStruct)
	{
		TArray<TSharedPtr<FPropertyDescriptor>>& CachedDescriptors = Cache.FindOrAdd(InStruct);
		if (!CachedDescriptors.IsEmpty() || InStruct == nullptr)
		{
			return CachedDescriptors;
		}

		BuildChildren(InStruct, FGenericPropertyAccessPath(), FString(), CachedDescriptors);
		return CachedDescriptors;
	}

	void FReflectionCache::BuildChildren(const UStruct* InStruct, const FGenericPropertyAccessPath& InParentPath, const FString& InParentPathString, TArray<TSharedPtr<FPropertyDescriptor>>& OutChildren)
	{
		if (InStruct == nullptr)
		{
			return;
		}

		int32 SortOrder = 0;
		for (TFieldIterator<FProperty> It(InStruct, EFieldIterationFlags::IncludeSuper); It; ++It)
		{
			if (const TSharedPtr<FPropertyDescriptor> Descriptor = BuildDescriptorForProperty(**It, InParentPath, InParentPathString, SortOrder++))
			{
				OutChildren.Add(Descriptor);
			}
		}
	}

	TSharedPtr<FPropertyDescriptor> FReflectionCache::BuildDescriptorForProperty(const FProperty& InProperty, const FGenericPropertyAccessPath& InParentPath, const FString& InParentPathString, const int32 InSortOrder)
	{
		if (InProperty.HasAnyPropertyFlags(CPF_Parm))
		{
			return nullptr;
		}

		TSharedPtr<FPropertyDescriptor> Descriptor = MakeShared<FPropertyDescriptor>();
		Descriptor->Property = &InProperty;
		Descriptor->OwnerStruct = InProperty.GetOwnerStruct();
		Descriptor->PropertyName = InProperty.GetFName();
		Descriptor->CategoryName = GetCategoryName(InProperty);
		Descriptor->TypeName = GetPropertyTypeName(InProperty);
		Descriptor->TypeObjectPath = GetPropertyTypeObjectPath(InProperty);
		Descriptor->DisplayName = GetFieldDisplayName(InProperty);
		Descriptor->ToolTip = GetFieldToolTip(InProperty);
		Descriptor->NodeKind = GetNodeKindInternal(InProperty);
		Descriptor->bCanExpand = CanEverExpandProperty(InProperty);
		Descriptor->bSupportsDirectEdit = SupportsDirectEditInternal(InProperty);
		Descriptor->bIsSupported = IsLeafPropertySupported(InProperty) || Descriptor->bCanExpand;
		Descriptor->bIsAdvanced = HasFieldMetaData(InProperty, TEXT("AdvancedDisplay"));
		Descriptor->bAllowObjectExpansion = HasFieldMetaData(InProperty, TEXT("ShowOnlyInnerProperties")) || InProperty.HasAnyPropertyFlags(CPF_InstancedReference);
		Descriptor->EditConditionExpression = HasFieldMetaData(InProperty, TEXT("EditCondition")) ? GetFieldMetaData(InProperty, TEXT("EditCondition")) : FString();
		Descriptor->SortOrder = InSortOrder;
		CopyMetadata(InProperty, Descriptor->Metadata);

		Descriptor->AccessPath = InParentPath;
		Descriptor->AccessPath.Segments.Add(FGenericPropertyAccessSegment(EGenericPropertyAccessType::Property, InProperty.GetFName()));
		Descriptor->PropertyPath = InParentPathString.IsEmpty()
			                           ? InProperty.GetName()
			                           : FString::Printf(TEXT("%s.%s"), *InParentPathString, *InProperty.GetName());

		if (const FStructProperty* StructProperty = CastField<const FStructProperty>(&InProperty))
		{
			BuildChildren(StructProperty->Struct, Descriptor->AccessPath, Descriptor->PropertyPath, Descriptor->Children);
		}

		return Descriptor;
	}

	bool ResolveValue(UObject* InTarget, const FGenericPropertyAccessPath& InPath, FResolvedValue& OutResolvedValue)
	{
		OutResolvedValue = FResolvedValue();
		if (InTarget == nullptr || InPath.Segments.IsEmpty())
		{
			OutResolvedValue.FailureReason = TEXT("Target or path is invalid.");
			return false;
		}

		const UStruct* CurrentStruct = InTarget->GetClass();
		void* CurrentContainer = InTarget;
		const FProperty* CurrentProperty = nullptr;
		void* CurrentValuePtr = nullptr;

		for (int32 SegmentIndex = 0; SegmentIndex < InPath.Segments.Num(); ++SegmentIndex)
		{
			const FGenericPropertyAccessSegment& Segment = InPath.Segments[SegmentIndex];
			const bool bIsLastSegment = SegmentIndex == InPath.Segments.Num() - 1;

			switch (Segment.Type)
			{
			case EGenericPropertyAccessType::Property:
				{
					CurrentProperty = FindPropertyByName(CurrentStruct, Segment.PropertyName);
					if (CurrentProperty == nullptr)
					{
						OutResolvedValue.FailureReason = FString::Printf(TEXT("Property '%s' was not found on '%s'."), *Segment.PropertyName.ToString(), *GetNameSafe(CurrentStruct));
						return false;
					}

					CurrentValuePtr = CurrentProperty->ContainerPtrToValuePtr<void>(CurrentContainer);
					if (bIsLastSegment)
					{
						break;
					}

					if (!DescendIntoProperty(*CurrentProperty, CurrentValuePtr, CurrentProperty, CurrentContainer, CurrentStruct))
					{
						OutResolvedValue.FailureReason = FString::Printf(TEXT("Property '%s' cannot be expanded."), *Segment.PropertyName.ToString());
						return false;
					}
					break;
				}

			case EGenericPropertyAccessType::ArrayElement:
				{
					const FArrayProperty* ArrayProperty = CastField<const FArrayProperty>(CurrentProperty);
					if (ArrayProperty == nullptr)
					{
						OutResolvedValue.FailureReason = TEXT("Array segment used on a non-array property.");
						return false;
					}

					FScriptArrayHelper ArrayHelper(ArrayProperty, CurrentValuePtr);
					if (!ArrayHelper.IsValidIndex(Segment.ElementIndex))
					{
						OutResolvedValue.FailureReason = FString::Printf(TEXT("Array index '%d' is invalid."), Segment.ElementIndex);
						return false;
					}

					CurrentProperty = ArrayProperty->Inner;
					CurrentValuePtr = ArrayHelper.GetRawPtr(Segment.ElementIndex);
					if (bIsLastSegment)
					{
						break;
					}

					if (!DescendIntoProperty(*CurrentProperty, CurrentValuePtr, CurrentProperty, CurrentContainer, CurrentStruct))
					{
						OutResolvedValue.FailureReason = TEXT("Array element cannot be expanded.");
						return false;
					}
					break;
				}

			case EGenericPropertyAccessType::SetElement:
				{
					const FSetProperty* SetProperty = CastField<const FSetProperty>(CurrentProperty);
					if (SetProperty == nullptr)
					{
						OutResolvedValue.FailureReason = TEXT("Set segment used on a non-set property.");
						return false;
					}

					FScriptSetHelper SetHelper(SetProperty, CurrentValuePtr);
					if (!SetHelper.IsValidIndex(Segment.ElementIndex))
					{
						OutResolvedValue.FailureReason = FString::Printf(TEXT("Set index '%d' is invalid."), Segment.ElementIndex);
						return false;
					}

					CurrentProperty = SetProperty->ElementProp;
					CurrentValuePtr = SetHelper.GetElementPtr(Segment.ElementIndex);
					if (bIsLastSegment)
					{
						break;
					}

					if (!DescendIntoProperty(*CurrentProperty, CurrentValuePtr, CurrentProperty, CurrentContainer, CurrentStruct))
					{
						OutResolvedValue.FailureReason = TEXT("Set element cannot be expanded.");
						return false;
					}
					break;
				}

			case EGenericPropertyAccessType::MapKey:
			case EGenericPropertyAccessType::MapValue:
				{
					const FMapProperty* MapProperty = CastField<const FMapProperty>(CurrentProperty);
					if (MapProperty == nullptr)
					{
						OutResolvedValue.FailureReason = TEXT("Map segment used on a non-map property.");
						return false;
					}

					FScriptMapHelper MapHelper(MapProperty, CurrentValuePtr);
					if (!MapHelper.IsValidIndex(Segment.ElementIndex))
					{
						OutResolvedValue.FailureReason = FString::Printf(TEXT("Map index '%d' is invalid."), Segment.ElementIndex);
						return false;
					}

					CurrentProperty = Segment.Type == EGenericPropertyAccessType::MapKey ? MapProperty->KeyProp : MapProperty->ValueProp;
					CurrentValuePtr = Segment.Type == EGenericPropertyAccessType::MapKey ? MapHelper.GetKeyPtr(Segment.ElementIndex) : MapHelper.GetValuePtr(Segment.ElementIndex);
					if (bIsLastSegment)
					{
						break;
					}

					if (!DescendIntoProperty(*CurrentProperty, CurrentValuePtr, CurrentProperty, CurrentContainer, CurrentStruct))
					{
						OutResolvedValue.FailureReason = TEXT("Map entry cannot be expanded.");
						return false;
					}
					break;
				}
			}
		}

		OutResolvedValue.Property = CurrentProperty;
		OutResolvedValue.ValuePtr = CurrentValuePtr;
		OutResolvedValue.ArrayProperty = CastField<const FArrayProperty>(CurrentProperty);
		OutResolvedValue.SetProperty = CastField<const FSetProperty>(CurrentProperty);
		OutResolvedValue.MapProperty = CastField<const FMapProperty>(CurrentProperty);
		OutResolvedValue.bSuccess = CurrentProperty != nullptr && CurrentValuePtr != nullptr;

		if (!OutResolvedValue.bSuccess)
		{
			OutResolvedValue.FailureReason = TEXT("Resolved property pointer was invalid.");
		}

		return OutResolvedValue.bSuccess;
	}

	bool ResolveDefaultValue(const UClass* InClass, const FGenericPropertyAccessPath& InPath, FResolvedValue& OutResolvedValue)
	{
		if (InClass == nullptr)
		{
			OutResolvedValue = FResolvedValue();
			OutResolvedValue.FailureReason = TEXT("Class is invalid.");
			return false;
		}

		return ResolveValue(InClass->GetDefaultObject(), InPath, OutResolvedValue);
	}

	EGenericPropertyValueType GetPropertyValueType(const FProperty& InProperty)
	{
		if (CastField<const FBoolProperty>(&InProperty) != nullptr)
		{
			return EGenericPropertyValueType::Boolean;
		}

		if (const FNumericProperty* NumericProperty = CastField<const FNumericProperty>(&InProperty))
		{
			return NumericProperty->IsFloatingPoint()
				       ? EGenericPropertyValueType::Float
				       : EGenericPropertyValueType::Integer;
		}

		if (CastField<const FEnumProperty>(&InProperty) != nullptr || CastField<const FByteProperty>(&InProperty) != nullptr)
		{
			return EGenericPropertyValueType::Enum;
		}

		if (CastField<const FStrProperty>(&InProperty) != nullptr)
		{
			return EGenericPropertyValueType::String;
		}

		if (CastField<const FNameProperty>(&InProperty) != nullptr)
		{
			return EGenericPropertyValueType::Name;
		}

		if (CastField<const FTextProperty>(&InProperty) != nullptr)
		{
			return EGenericPropertyValueType::Text;
		}

		switch (GetNodeKindInternal(InProperty))
		{
		case EGenericPropertyNodeKind::Struct:
			return EGenericPropertyValueType::Struct;
		case EGenericPropertyNodeKind::Object:
			return EGenericPropertyValueType::Object;
		case EGenericPropertyNodeKind::Array:
			return EGenericPropertyValueType::Array;
		case EGenericPropertyNodeKind::Set:
			return EGenericPropertyValueType::Set;
		case EGenericPropertyNodeKind::Map:
			return EGenericPropertyValueType::Map;
		case EGenericPropertyNodeKind::MapEntry:
			return EGenericPropertyValueType::MapEntry;
		case EGenericPropertyNodeKind::Warning:
			return EGenericPropertyValueType::Warning;
		default:
			return EGenericPropertyValueType::Unknown;
		}
	}

	FName GetPropertyTypeName(const FProperty& InProperty)
	{
		return FName(*InProperty.GetCPPType());
	}

	FString GetPropertyTypeObjectPath(const FProperty& InProperty)
	{
		if (const FEnumProperty* EnumProperty = CastField<const FEnumProperty>(&InProperty))
		{
			return GetPathNameSafe(EnumProperty->GetEnum());
		}

		if (const FByteProperty* ByteProperty = CastField<const FByteProperty>(&InProperty))
		{
			return GetPathNameSafe(ByteProperty->Enum);
		}

		if (const FStructProperty* StructProperty = CastField<const FStructProperty>(&InProperty))
		{
			return GetPathNameSafe(StructProperty->Struct);
		}

		return FString();
	}

	bool IsLeafPropertySupported(const FProperty& InProperty)
	{
		if (CastField<const FBoolProperty>(&InProperty) != nullptr
			|| CastField<const FNumericProperty>(&InProperty) != nullptr
			|| CastField<const FEnumProperty>(&InProperty) != nullptr
			|| CastField<const FByteProperty>(&InProperty) != nullptr
			|| CastField<const FStrProperty>(&InProperty) != nullptr
			|| CastField<const FNameProperty>(&InProperty) != nullptr
			|| CastField<const FTextProperty>(&InProperty) != nullptr)
		{
			return true;
		}

		if (IsObjectLikeProperty(InProperty))
		{
			return true;
		}

		if (const FStructProperty* StructProperty = CastField<const FStructProperty>(&InProperty))
		{
			const UScriptStruct* Struct = StructProperty->Struct;
			return Struct == TBaseStructure<FGameplayTag>::Get()
				|| Struct == TBaseStructure<FGameplayTagContainer>::Get()
				|| Struct == TBaseStructure<FSoftObjectPath>::Get()
				|| Struct == TBaseStructure<FSoftClassPath>::Get();
		}

		return false;
	}

	bool PassesFilters(const FPropertyDescriptor& InDescriptor, const FGenericPropertyFilterRules& InFilters)
	{
		if (InFilters.PropertyNameBlacklist.Contains(InDescriptor.PropertyName)
			|| InFilters.CategoryBlacklist.Contains(InDescriptor.CategoryName)
			|| InFilters.PathBlacklist.Contains(InDescriptor.PropertyPath)
			|| InFilters.TypeBlacklist.Contains(InDescriptor.TypeName))
		{
			return false;
		}

		for (const TPair<FName, FString>& Pair : InDescriptor.Metadata)
		{
			if (InFilters.MetadataBlacklist.Contains(Pair.Key))
			{
				return false;
			}
		}

		if (!InFilters.PropertyNameWhitelist.IsEmpty() && !InFilters.PropertyNameWhitelist.Contains(InDescriptor.PropertyName))
		{
			return false;
		}

		if (!InFilters.CategoryWhitelist.IsEmpty() && !InFilters.CategoryWhitelist.Contains(InDescriptor.CategoryName))
		{
			return false;
		}

		if (!InFilters.PathWhitelist.IsEmpty() && !InFilters.PathWhitelist.Contains(InDescriptor.PropertyPath))
		{
			return false;
		}

		if (!InFilters.TypeWhitelist.IsEmpty() && !InFilters.TypeWhitelist.Contains(InDescriptor.TypeName))
		{
			return false;
		}

		if (!InFilters.MetadataWhitelist.IsEmpty())
		{
			bool bMatchedMetadataWhitelist = false;
			for (const TPair<FName, FString>& Pair : InDescriptor.Metadata)
			{
				if (InFilters.MetadataWhitelist.Contains(Pair.Key))
				{
					bMatchedMetadataWhitelist = true;
					break;
				}
			}

			if (!bMatchedMetadataWhitelist)
			{
				return false;
			}
		}

		return true;
	}

	bool EvaluateEditCondition(const FString& InExpression, UObject* InTarget)
	{
		const FString Expression = InExpression.TrimStartAndEnd();
		if (Expression.IsEmpty() || InTarget == nullptr)
		{
			return true;
		}

		if (Expression.Equals(TEXT("true"), ESearchCase::IgnoreCase))
		{
			return true;
		}

		if (Expression.Equals(TEXT("false"), ESearchCase::IgnoreCase))
		{
			return false;
		}

		bool bNegate = false;
		FString PropertyNameString = Expression;
		if (PropertyNameString.StartsWith(TEXT("!")))
		{
			bNegate = true;
			PropertyNameString.RightChopInline(1);
			PropertyNameString = PropertyNameString.TrimStartAndEnd();
		}

		FGenericPropertyAccessPath Path;
		Path.Segments.Add(FGenericPropertyAccessSegment(EGenericPropertyAccessType::Property, FName(*PropertyNameString)));

		FResolvedValue ResolvedValue;
		if (!ResolveValue(InTarget, Path, ResolvedValue))
		{
			return true;
		}

		if (const FBoolProperty* BoolProperty = CastField<const FBoolProperty>(ResolvedValue.Property))
		{
			const bool bValue = BoolProperty->GetPropertyValue(ResolvedValue.ValuePtr);
			return bNegate ? !bValue : bValue;
		}

		return true;
	}

	FString ExportValueToString(const FProperty& InProperty, const void* InValuePtr)
	{
		if (InValuePtr == nullptr)
		{
			return FString();
		}

		FString Output;
		InProperty.ExportTextItem_Direct(Output, InValuePtr, nullptr, nullptr, PPF_None);
		return Output;
	}

	bool ImportValueFromString(const FProperty& InProperty, void* InValuePtr, const FString& InValue, FText& OutError)
	{
		if (InValuePtr == nullptr)
		{
			OutError = FText::FromString(TEXT("Target value pointer is invalid."));
			return false;
		}

		const TCHAR* ImportResult = InProperty.ImportText_Direct(*InValue, InValuePtr, nullptr, PPF_None);
		if (ImportResult == nullptr)
		{
			OutError = FText::FromString(FString::Printf(TEXT("Failed to import '%s' into '%s'."), *InValue, *InProperty.GetName()));
			return false;
		}

		return true;
	}

	FGenericPropertyValidationResult ValidateValueText(const FProperty& InProperty, const void* InCurrentValuePtr, const FString& InValue, const TMap<FName, FString>& InMetadata)
	{
		FGenericPropertyValidationResult Result;
		Result.bSuccess = true;

		void* ScratchValue = AllocateReflectionPropertyValue(InProperty);
		if (InCurrentValuePtr != nullptr)
		{
			InProperty.CopyCompleteValue(ScratchValue, InCurrentValuePtr);
		}

		FText ImportError;
		if (!ImportValueFromString(InProperty, ScratchValue, InValue, ImportError))
		{
			Result.bSuccess = false;
			Result.Message = ImportError;
			FreeReflectionPropertyValue(InProperty, ScratchValue);
			return Result;
		}

		if (const FNumericProperty* NumericProperty = CastField<const FNumericProperty>(&InProperty))
		{
			if (NumericProperty->IsFloatingPoint())
			{
				const double NumericValue = NumericProperty->GetFloatingPointPropertyValue(ScratchValue);
				if (const FString* ClampMin = InMetadata.Find(TEXT("ClampMin")))
				{
					double ClampMinValue = 0.0;
					if (LexTryParseString(ClampMinValue, **ClampMin) && NumericValue < ClampMinValue)
					{
						Result.bSuccess = false;
						Result.Message = FText::FromString(FString::Printf(TEXT("Value must be >= %s"), **ClampMin));
					}
				}

				if (Result.bSuccess)
				{
					if (const FString* ClampMax = InMetadata.Find(TEXT("ClampMax")))
					{
						double ClampMaxValue = 0.0;
						if (LexTryParseString(ClampMaxValue, **ClampMax) && NumericValue > ClampMaxValue)
						{
							Result.bSuccess = false;
							Result.Message = FText::FromString(FString::Printf(TEXT("Value must be <= %s"), **ClampMax));
						}
					}
				}
			}
			else if (NumericProperty->IsInteger())
			{
				const uint64 UnsignedValue = NumericProperty->GetUnsignedIntPropertyValue(ScratchValue);
				const int64 IntegerValue = static_cast<int64>(UnsignedValue);

				if (const FString* ClampMin = InMetadata.Find(TEXT("ClampMin")))
				{
					int64 ClampMinValue = 0;
					if (LexTryParseString(ClampMinValue, **ClampMin) && IntegerValue < ClampMinValue)
					{
						Result.bSuccess = false;
						Result.Message = FText::FromString(FString::Printf(TEXT("Value must be >= %s"), **ClampMin));
					}
				}

				if (Result.bSuccess)
				{
					if (const FString* ClampMax = InMetadata.Find(TEXT("ClampMax")))
					{
						int64 ClampMaxValue = 0;
						if (LexTryParseString(ClampMaxValue, **ClampMax) && IntegerValue > ClampMaxValue)
						{
							Result.bSuccess = false;
							Result.Message = FText::FromString(FString::Printf(TEXT("Value must be <= %s"), **ClampMax));
						}
					}
				}
			}
		}

		if (Result.bSuccess)
		{
			if (const FStructProperty* StructProperty = CastField<const FStructProperty>(&InProperty))
			{
				if (StructProperty->Struct == TBaseStructure<FGameplayTag>::Get())
				{
					const FGameplayTag& GameplayTag = *reinterpret_cast<const FGameplayTag*>(ScratchValue);
					if (!GameplayTag.IsValid())
					{
						Result.bSuccess = false;
						Result.Message = FText::FromString(TEXT("GameplayTag is invalid."));
					}
				}
			}
		}

		if (Result.bSuccess)
		{
			if (const FObjectPropertyBase* ObjectProperty = CastField<const FObjectPropertyBase>(&InProperty))
			{
				UObject* ObjectValue = ObjectProperty->GetObjectPropertyValue(ScratchValue);
				if (ObjectValue != nullptr)
				{
					if (const FString* AllowedClassesValue = InMetadata.Find(TEXT("AllowedClasses")))
					{
						if (const UClass* AllowedClass = FindObject<UClass>(nullptr, **AllowedClassesValue))
						{
							if (!ObjectValue->IsA(AllowedClass))
							{
								Result.bSuccess = false;
								Result.Message = FText::FromString(TEXT("Object class is not allowed."));
							}
						}
					}

					if (Result.bSuccess)
					{
						if (const FString* DisallowedClassesValue = InMetadata.Find(TEXT("DisallowedClasses")))
						{
							if (const UClass* DisallowedClass = FindObject<UClass>(nullptr, **DisallowedClassesValue))
							{
								if (ObjectValue->IsA(DisallowedClass))
								{
									Result.bSuccess = false;
									Result.Message = FText::FromString(TEXT("Object class is explicitly disallowed."));
								}
							}
						}
					}

					if (Result.bSuccess)
					{
						if (const FString* ExactClassValue = InMetadata.Find(TEXT("ExactClass")))
						{
							const bool bRequireExactClass = ExactClassValue->Equals(TEXT("true"), ESearchCase::IgnoreCase);
							if (bRequireExactClass)
							{
								if (const FString* AllowedClassesValue = InMetadata.Find(TEXT("AllowedClasses")))
								{
									if (const UClass* AllowedClass = FindObject<UClass>(nullptr, **AllowedClassesValue))
									{
										if (ObjectValue->GetClass() != AllowedClass)
										{
											Result.bSuccess = false;
											Result.Message = FText::FromString(TEXT("Object must match the exact allowed class."));
										}
									}
								}
							}
						}
					}
				}
			}
		}

		FreeReflectionPropertyValue(InProperty, ScratchValue);
		return Result;
	}

	void BuildRootNodes(UGenericPropertyProxy& InProxy, TArray<UGenericProperty*>& OutNodes)
	{
		OutNodes.Reset();

		const TArray<TWeakObjectPtr<UObject>>& Targets = InProxy.GetTargets();
		if (Targets.IsEmpty() || !Targets[0].IsValid())
		{
			return;
		}

		const UClass* CommonClass = FindCommonBaseClass(Targets);
		if (CommonClass == nullptr)
		{
			return;
		}

		const TArray<TSharedPtr<FPropertyDescriptor>>& Descriptors = FReflectionCache::Get().GetClassDescriptor(CommonClass);
		for (const TSharedPtr<FPropertyDescriptor>& Descriptor : Descriptors)
		{
			if (!Descriptor.IsValid()
				|| !ShouldIncludeRootDescriptorForClass(*Descriptor, CommonClass, InProxy.GetOptions())
				|| !PassesFilters(*Descriptor, InProxy.GetOptions().Filters))
			{
				continue;
			}

			if (!AllTargetsResolve(InProxy, Descriptor->AccessPath))
			{
				continue;
			}

			UGenericProperty* Node = CreatePropertyNode();
			if (Node == nullptr)
			{
				continue;
			}

			Node->Initialize(&InProxy);
			Node->PropertyName = Descriptor->PropertyName;
			Node->CategoryName = Descriptor->CategoryName;
			Node->DisplayName = Descriptor->DisplayName;
			Node->ToolTip = Descriptor->ToolTip;
			Node->NodeKind = Descriptor->NodeKind;
			Node->SetInternalTypeName(GetPropertyValueType(*Descriptor->Property), Descriptor->TypeName, Descriptor->TypeObjectPath);
			Node->bCanExpand = CanExpandProperty(*Descriptor->Property, InProxy.GetOptions());
			Node->bSupportsDirectEdit = Descriptor->bSupportsDirectEdit;
			Node->bIsSupported = IsLeafPropertySupported(*Descriptor->Property) || Node->bCanExpand;
			Node->bIsAdvanced = Descriptor->bIsAdvanced;
			Node->SetAccessPath(Descriptor->AccessPath);
			Node->PropertyPath = Descriptor->PropertyPath;
			Node->EditConditionExpression = Descriptor->EditConditionExpression;
			Node->SetMetadata(TMap<FName, FString>(Descriptor->Metadata));
			Node->InvalidateSearchableText();
			RefreshNodeState(*Node);
			OutNodes.Add(Node);
		}
	}

	void BuildDynamicChildren(UGenericProperty& InNode)
	{
		InNode.Children.Reset();
		InNode.bChildrenDirty = false;

		UGenericPropertyProxy* Proxy = InNode.OwningProxy.Get();
		if (!IsUsableNodeOwner(Proxy))
		{
			return;
		}

		Proxy->InvalidateNodeLookupCaches();

		const TArray<TWeakObjectPtr<UObject>>& Targets = Proxy->GetTargets();
		if (Targets.IsEmpty() || !Targets[0].IsValid())
		{
			return;
		}

		FResolvedValue ResolvedValue;
		if (!ResolveValue(Targets[0].Get(), InNode.GetAccessPath(), ResolvedValue))
		{
			return;
		}

		auto CreateNode = [&](const FProperty& InProperty, const FGenericPropertyAccessPath& InPath, const FText& InDisplayName, UGenericProperty* InParentNode)
		{
			UGenericProperty* ChildNode = CreatePropertyNode();
			if (ChildNode == nullptr)
			{
				return static_cast<UGenericProperty*>(nullptr);
			}

			ChildNode->Initialize(Proxy);
			ChildNode->PropertyName = InProperty.GetFName();
			ChildNode->CategoryName = InNode.CategoryName;
			ChildNode->DisplayName = InDisplayName;
			ChildNode->ToolTip = GetFieldToolTip(InProperty);
			ChildNode->NodeKind = GetNodeKindInternal(InProperty);
			ChildNode->SetInternalTypeName(GetPropertyValueType(InProperty), GetPropertyTypeName(InProperty), GetPropertyTypeObjectPath(InProperty));
			ChildNode->bCanExpand = CanExpandProperty(InProperty, Proxy->GetOptions());
			ChildNode->bSupportsDirectEdit = SupportsDirectEditInternal(InProperty);
			ChildNode->bIsSupported = IsLeafPropertySupported(InProperty) || ChildNode->bCanExpand;
			ChildNode->bIsAdvanced = HasFieldMetaData(InProperty, TEXT("AdvancedDisplay"));
			ChildNode->ParentNode = InParentNode;
			ChildNode->SetAccessPath(InPath);
			ChildNode->PropertyPath = InPath.ToString();
			ChildNode->EditConditionExpression = HasFieldMetaData(InProperty, TEXT("EditCondition")) ? GetFieldMetaData(InProperty, TEXT("EditCondition")) : FString();

			TMap<FName, FString> Metadata;
			CopyMetadata(InProperty, Metadata);
			ChildNode->SetMetadata(MoveTemp(Metadata));
			ChildNode->InvalidateSearchableText();
			RefreshNodeState(*ChildNode);
			return ChildNode;
		};

		if (InNode.NodeKind == EGenericPropertyNodeKind::Struct && Proxy->GetOptions().bExpandStructProperties)
		{
			const FStructProperty* StructProperty = CastField<const FStructProperty>(ResolvedValue.Property);
			if (StructProperty == nullptr)
			{
				return;
			}

			const TArray<TSharedPtr<FPropertyDescriptor>>& StructDescriptors = FReflectionCache::Get().GetStructDescriptor(StructProperty->Struct);
			for (const TSharedPtr<FPropertyDescriptor>& Descriptor : StructDescriptors)
			{
				if (!Descriptor.IsValid() || !PassesFilters(*Descriptor, Proxy->GetOptions().Filters))
				{
					continue;
				}

				FGenericPropertyAccessPath ChildPath = InNode.GetAccessPath();
				ChildPath.Segments.Append(Descriptor->AccessPath.Segments);
				if (!AllTargetsResolve(*Proxy, ChildPath))
				{
					continue;
				}

				if (UGenericProperty* ChildNode = CreateNode(*Descriptor->Property, ChildPath, Descriptor->DisplayName, &InNode))
				{
					InNode.Children.Add(ChildNode);
				}
			}

			return;
		}

		if (InNode.NodeKind == EGenericPropertyNodeKind::Object && Proxy->GetOptions().bExpandObjectProperties)
		{
			if (InNode.ObjectRecursionDepth >= Proxy->GetOptions().MaxObjectRecursionDepth)
			{
				InNode.Issue.Severity = EGenericPropertyIssueSeverity::Warning;
				InNode.Issue.Type = EGenericPropertyIssueType::RecursionLimit;
				InNode.Issue.Message = FText::FromString(TEXT("Object recursion depth limit reached."));
				return;
			}

			const FObjectPropertyBase* ObjectProperty = CastField<const FObjectPropertyBase>(ResolvedValue.Property);
			if (ObjectProperty == nullptr)
			{
				return;
			}

			TArray<UObject*> ReferencedObjects;
			ReferencedObjects.Reserve(Targets.Num());
			for (const TWeakObjectPtr<UObject>& Target : Targets)
			{
				FResolvedValue ObjectResolvedValue;
				if (!Target.IsValid() || !ResolveValue(Target.Get(), InNode.GetAccessPath(), ObjectResolvedValue))
				{
					return;
				}

				const FObjectPropertyBase* TargetObjectProperty = CastField<const FObjectPropertyBase>(ObjectResolvedValue.Property);
				if (TargetObjectProperty == nullptr)
				{
					return;
				}

				UObject* ReferencedObject = TargetObjectProperty->GetObjectPropertyValue(ObjectResolvedValue.ValuePtr);
				if (ReferencedObject == nullptr)
				{
					InNode.Issue.Severity = EGenericPropertyIssueSeverity::Warning;
					InNode.Issue.Type = EGenericPropertyIssueType::MultiObjectMismatch;
					InNode.Issue.Message = FText::FromString(TEXT("One or more selected objects do not have a valid sub-object reference."));
					return;
				}

				ReferencedObjects.Add(ReferencedObject);
			}

			const UClass* CommonObjectClass = FindCommonBaseClass(ReferencedObjects);
			if (CommonObjectClass == nullptr)
			{
				InNode.Issue.Severity = EGenericPropertyIssueSeverity::Warning;
				InNode.Issue.Type = EGenericPropertyIssueType::MultiObjectMismatch;
				InNode.Issue.Message = FText::FromString(TEXT("Referenced objects do not share a compatible common type."));
				return;
			}

			const TArray<TSharedPtr<FPropertyDescriptor>>& ObjectDescriptors = FReflectionCache::Get().GetClassDescriptor(CommonObjectClass);
			for (const TSharedPtr<FPropertyDescriptor>& Descriptor : ObjectDescriptors)
			{
				if (!Descriptor.IsValid() || !PassesFilters(*Descriptor, Proxy->GetOptions().Filters))
				{
					continue;
				}

				FGenericPropertyAccessPath ChildPath = InNode.GetAccessPath();
				ChildPath.Segments.Append(Descriptor->AccessPath.Segments);
				if (!AllTargetsResolve(*Proxy, ChildPath))
				{
					continue;
				}

				if (UGenericProperty* ChildNode = CreateNode(*Descriptor->Property, ChildPath, Descriptor->DisplayName, &InNode))
				{
					ChildNode->ObjectRecursionDepth = InNode.ObjectRecursionDepth + 1;
					InNode.Children.Add(ChildNode);
				}
			}

			return;
		}

		if (InNode.NodeKind == EGenericPropertyNodeKind::Array && Proxy->GetOptions().bExpandContainerProperties)
		{
			const FArrayProperty* ArrayProperty = CastField<const FArrayProperty>(ResolvedValue.Property);
			if (ArrayProperty == nullptr)
			{
				return;
			}

			int32 SharedCount = INDEX_NONE;
			for (const TWeakObjectPtr<UObject>& Target : Targets)
			{
				FResolvedValue TargetResolved;
				if (!Target.IsValid() || !ResolveValue(Target.Get(), InNode.GetAccessPath(), TargetResolved))
				{
					return;
				}

				FScriptArrayHelper Helper(ArrayProperty, TargetResolved.ValuePtr);
				if (SharedCount == INDEX_NONE)
				{
					SharedCount = Helper.Num();
				}
				else if (SharedCount != Helper.Num())
				{
					InNode.Issue.Severity = EGenericPropertyIssueSeverity::Warning;
					InNode.Issue.Type = EGenericPropertyIssueType::MultiObjectMismatch;
					InNode.Issue.Message = FText::FromString(TEXT("Array size differs across selected objects, switching to limited mode."));
					return;
				}
			}

			FScriptArrayHelper Helper(ArrayProperty, ResolvedValue.ValuePtr);
			for (int32 Index = 0; Index < Helper.Num(); ++Index)
			{
				FGenericPropertyAccessPath ChildPath = InNode.GetAccessPath();
				ChildPath.Segments.Add(FGenericPropertyAccessSegment(EGenericPropertyAccessType::ArrayElement, Index));
				if (UGenericProperty* ChildNode = CreateNode(*ArrayProperty->Inner, ChildPath, MakeDisplayNameForSegment(EGenericPropertyAccessType::ArrayElement, Index), &InNode))
				{
					ChildNode->ContainerElementIndex = Index;
					InNode.Children.Add(ChildNode);
				}
			}

			return;
		}

		if (InNode.NodeKind == EGenericPropertyNodeKind::Set && Proxy->GetOptions().bExpandContainerProperties)
		{
			if (Targets.Num() > 1)
			{
				InNode.Issue.Severity = EGenericPropertyIssueSeverity::Warning;
				InNode.Issue.Type = EGenericPropertyIssueType::ReadOnlyRestriction;
				InNode.Issue.Message = FText::FromString(TEXT("Multi-object Set editing is limited to read-only mode because element order cannot be aligned safely."));
				return;
			}

			const FSetProperty* SetProperty = CastField<const FSetProperty>(ResolvedValue.Property);
			if (SetProperty == nullptr)
			{
				return;
			}

			FScriptSetHelper Helper(SetProperty, ResolvedValue.ValuePtr);
			for (int32 Index = 0; Index < Helper.GetMaxIndex(); ++Index)
			{
				if (!Helper.IsValidIndex(Index))
				{
					continue;
				}

				FGenericPropertyAccessPath ChildPath = InNode.GetAccessPath();
				ChildPath.Segments.Add(FGenericPropertyAccessSegment(EGenericPropertyAccessType::SetElement, Index));
				if (UGenericProperty* ChildNode = CreateNode(*SetProperty->ElementProp, ChildPath, MakeDisplayNameForSegment(EGenericPropertyAccessType::SetElement, Index), &InNode))
				{
					ChildNode->ContainerElementIndex = Index;
					InNode.Children.Add(ChildNode);
				}
			}

			return;
		}

		if (InNode.NodeKind == EGenericPropertyNodeKind::Map && Proxy->GetOptions().bExpandContainerProperties)
		{
			if (Targets.Num() > 1)
			{
				InNode.Issue.Severity = EGenericPropertyIssueSeverity::Warning;
				InNode.Issue.Type = EGenericPropertyIssueType::ReadOnlyRestriction;
				InNode.Issue.Message = FText::FromString(TEXT("Multi-object Map editing is limited to read-only mode because key alignment cannot be guaranteed safely."));
				return;
			}

			const FMapProperty* MapProperty = CastField<const FMapProperty>(ResolvedValue.Property);
			if (MapProperty == nullptr)
			{
				return;
			}

			FScriptMapHelper Helper(MapProperty, ResolvedValue.ValuePtr);
			for (int32 Index = 0; Index < Helper.GetMaxIndex(); ++Index)
			{
				if (!Helper.IsValidIndex(Index))
				{
					continue;
				}

				UGenericProperty* PairNode = CreatePropertyNode();
				if (PairNode == nullptr)
				{
					continue;
				}

				PairNode->Initialize(Proxy);
				PairNode->DisplayName = FText::FromString(FString::Printf(TEXT("[%d]"), Index));
				PairNode->CategoryName = InNode.CategoryName;
				PairNode->NodeKind = EGenericPropertyNodeKind::MapEntry;
				PairNode->ParentNode = &InNode;
				PairNode->bIsSupported = true;
				PairNode->bCanExpand = true;
				PairNode->bIsEnabled = true;
				PairNode->PropertyPath = FString::Printf(TEXT("%s.<%d>"), *InNode.PropertyPath, Index);
				PairNode->ContainerElementIndex = Index;
				PairNode->bSupportsRemoveElement = !Proxy->GetOptions().bReadOnly;
				PairNode->InvalidateSearchableText();

				FGenericPropertyAccessPath KeyPath = InNode.GetAccessPath();
				KeyPath.Segments.Add(FGenericPropertyAccessSegment(EGenericPropertyAccessType::MapKey, Index));
				UGenericProperty* KeyNode = CreateNode(*MapProperty->KeyProp, KeyPath, FText::FromString(TEXT("Key")), PairNode);
				if (KeyNode == nullptr)
				{
					continue;
				}

				KeyNode->ContainerElementIndex = Index;
				PairNode->Children.Add(KeyNode);

				FGenericPropertyAccessPath ValuePath = InNode.GetAccessPath();
				ValuePath.Segments.Add(FGenericPropertyAccessSegment(EGenericPropertyAccessType::MapValue, Index));
				UGenericProperty* ValueNode = CreateNode(*MapProperty->ValueProp, ValuePath, FText::FromString(TEXT("Value")), PairNode);
				if (ValueNode == nullptr)
				{
					continue;
				}

				ValueNode->ContainerElementIndex = Index;
				PairNode->Children.Add(ValueNode);

				InNode.Children.Add(PairNode);
			}
		}
	}

	void RefreshNodeState(UGenericProperty& InNode)
	{
		UGenericPropertyProxy* Proxy = InNode.OwningProxy.Get();
		if (!IsUsableNodeOwner(Proxy))
		{
			return;
		}

		InNode.Issue.Reset();

		const TArray<TWeakObjectPtr<UObject>>& Targets = Proxy->GetTargets();
		if (Targets.IsEmpty())
		{
			InNode.MarkUnsupported(FText::FromString(TEXT("No targets are bound to this session.")));
			return;
		}

		TArray<FString> ExportedValues;
		ExportedValues.Reserve(Targets.Num());

		const FProperty* FirstProperty = nullptr;
		void* FirstValuePtr = nullptr;

		for (const TWeakObjectPtr<UObject>& Target : Targets)
		{
			FResolvedValue ResolvedValue;
			if (!Target.IsValid() || !ResolveValue(Target.Get(), InNode.GetAccessPath(), ResolvedValue))
			{
				InNode.MarkUnsupported(FText::FromString(ResolvedValue.FailureReason));
				return;
			}

			if (FirstProperty == nullptr)
			{
				FirstProperty = ResolvedValue.Property;
				FirstValuePtr = ResolvedValue.ValuePtr;
			}

			if (ResolvedValue.Property == nullptr || ResolvedValue.ValuePtr == nullptr)
			{
				InNode.MarkUnsupported(FText::FromString(TEXT("Property resolution returned an invalid value pointer.")));
				return;
			}

			ExportedValues.Add(CanExpandProperty(*ResolvedValue.Property, Proxy->GetOptions())
				                   ? MakeContainerSummary(*ResolvedValue.Property, ResolvedValue.ValuePtr)
				                   : ExportValueToString(*ResolvedValue.Property, ResolvedValue.ValuePtr)
			);
		}

		if (FirstProperty == nullptr || FirstValuePtr == nullptr)
		{
			InNode.MarkUnsupported(FText::FromString(TEXT("Property resolution failed.")));
			return;
		}

		InNode.SetInternalTypeName(GetPropertyValueType(*FirstProperty), GetPropertyTypeName(*FirstProperty), GetPropertyTypeObjectPath(*FirstProperty));
		InNode.bSupportsDirectEdit = SupportsDirectEditInternal(*FirstProperty);
		InNode.bCanExpand = CanExpandProperty(*FirstProperty, Proxy->GetOptions()) || InNode.NodeKind == EGenericPropertyNodeKind::MapEntry;
		InNode.bIsSupported = IsLeafPropertySupported(*FirstProperty) || InNode.bCanExpand || InNode.NodeKind == EGenericPropertyNodeKind::MapEntry;
		UpdateCommandCapabilities(InNode, Targets.Num());
		SetWarningIfUnsupportedLeaf(InNode, *FirstProperty);

		const FString NewSourceValue = ExportedValues[0];
		const FString PreviousSourceValue = InNode.TextState.SourceValue;
		const bool bHadSourceValue = !PreviousSourceValue.IsEmpty() || InNode.bHasMixedValues;

		InNode.bHasMixedValues = false;
		for (int32 Index = 1; Index < ExportedValues.Num(); ++Index)
		{
			if (!ExportedValues[Index].Equals(NewSourceValue, ESearchCase::CaseSensitive))
			{
				InNode.bHasMixedValues = true;
				break;
			}
		}

		InNode.TextState.SourceValue = NewSourceValue;
		if (!bHadSourceValue)
		{
			InNode.TextState.CurrentValue = NewSourceValue;
		}
		else if (InNode.bIsDirty && !PreviousSourceValue.Equals(NewSourceValue, ESearchCase::CaseSensitive))
		{
			switch (Proxy->GetOptions().ConflictPolicy)
			{
			case EGenericPropertyConflictPolicy::KeepLocalDirty:
				InNode.bHasConflict = false;
				break;

			case EGenericPropertyConflictPolicy::TakeExternalValue:
				InNode.TextState.CurrentValue = NewSourceValue;
				InNode.bHasConflict = false;
				break;

			case EGenericPropertyConflictPolicy::MarkConflict:
				InNode.bHasConflict = true;
				InNode.Issue.Severity = EGenericPropertyIssueSeverity::Warning;
				InNode.Issue.Type = EGenericPropertyIssueType::Conflict;
				InNode.Issue.Message = FText::FromString(TEXT("Source value changed outside the panel while this node was dirty."));
				break;
			}
		}
		else if (!InNode.bIsDirty)
		{
			InNode.TextState.CurrentValue = NewSourceValue;
			InNode.bHasConflict = false;
		}

		FResolvedValue DefaultResolvedValue;
		if (Targets[0].IsValid() && ResolveDefaultValue(Targets[0]->GetClass(), InNode.GetAccessPath(), DefaultResolvedValue))
		{
			InNode.TextState.DefaultValue = CanExpandProperty(*DefaultResolvedValue.Property, Proxy->GetOptions())
				                                ? MakeContainerSummary(*DefaultResolvedValue.Property, DefaultResolvedValue.ValuePtr)
				                                : ExportValueToString(*DefaultResolvedValue.Property, DefaultResolvedValue.ValuePtr);
		}
		else
		{
			InNode.TextState.DefaultValue.Reset();
		}

		InNode.bIsEditable = !Proxy->GetOptions().bReadOnly && IsPropertyEditableByFlags(*FirstProperty) && InNode.bSupportsDirectEdit;
		const bool bAllowStructuralCommands = !Proxy->GetOptions().bReadOnly;
		InNode.bSupportsAddElement &= bAllowStructuralCommands;
		InNode.bSupportsRemoveElement &= bAllowStructuralCommands;
		InNode.bSupportsDuplicateElement &= bAllowStructuralCommands;
		InNode.bSupportsReorderElement &= bAllowStructuralCommands;
		InNode.bSupportsClearChildren &= bAllowStructuralCommands;
		if (!InNode.EditConditionExpression.IsEmpty())
		{
			bool bAllEditable = true;
			for (const TWeakObjectPtr<UObject>& Target : Targets)
			{
				if (!Target.IsValid() || !EvaluateEditCondition(InNode.EditConditionExpression, Target.Get()))
				{
					bAllEditable = false;
					break;
				}
			}

			InNode.bIsEditable &= bAllEditable;
		}

		InNode.bIsEnabled = InNode.bIsEditable || InNode.bCanExpand;
		InNode.bIsDirty = !InNode.TextState.CurrentValue.Equals(InNode.TextState.SourceValue, ESearchCase::CaseSensitive);
		InNode.bIsInvalid = false;

		if (ShouldEagerBuildChildren(InNode))
		{
			BuildDynamicChildren(InNode);
			InNode.bChildrenDirty = false;
		}
		else if (InNode.bCanExpand && InNode.NodeKind != EGenericPropertyNodeKind::MapEntry)
		{
			if (InNode.bIsExpanded)
			{
				BuildDynamicChildren(InNode);
				InNode.bChildrenDirty = false;
			}
			else if (!InNode.Children.IsEmpty())
			{
				InNode.bChildrenDirty = true;
			}
		}

		InNode.RecalculateState();
	}
}
