#include "Data/GenericPropertyValueUtilities.h"

#include "Core/GenericProperty.h"
#include "Core/GenericPropertyReflection.h"
#include "Model/GenericPropertyProxy.h"
#include "UObject/UnrealType.h"

namespace GenericPropertyFramework::Private
{
	namespace
	{
		FGenericPropertyAccessPath GetParentPath(const FGenericPropertyAccessPath& InPath)
		{
			FGenericPropertyAccessPath ParentPath = InPath;
			if (!ParentPath.Segments.IsEmpty())
			{
				ParentPath.Segments.RemoveAt(ParentPath.Segments.Num() - 1);
			}

			return ParentPath;
		}

		void RehashOwningContainer(UObject* InTarget, const FGenericPropertyAccessPath& InPath)
		{
			if (InTarget == nullptr || InPath.Segments.IsEmpty())
			{
				return;
			}

			const EGenericPropertyAccessType LastSegmentType = InPath.Segments.Last().Type;
			if (LastSegmentType != EGenericPropertyAccessType::SetElement && LastSegmentType != EGenericPropertyAccessType::MapKey)
			{
				return;
			}

			FResolvedValue ParentResolvedValue;
			if (!ResolveValue(InTarget, GetParentPath(InPath), ParentResolvedValue))
			{
				return;
			}

			if (const FSetProperty* SetProperty = CastField<const FSetProperty>(ParentResolvedValue.Property))
			{
				FScriptSetHelper Helper(SetProperty, ParentResolvedValue.ValuePtr);
				Helper.Rehash();
			}
			else if (const FMapProperty* MapProperty = CastField<const FMapProperty>(ParentResolvedValue.Property))
			{
				FScriptMapHelper Helper(MapProperty, ParentResolvedValue.ValuePtr);
				Helper.Rehash();
			}
		}

		FGenericPropertyWriteResult MakeFailureResult(const FText& InError)
		{
			FGenericPropertyWriteResult Result;
			Result.bSuccess = false;
			Result.ErrorMessage = InError;
			return Result;
		}

		void* AllocateMutationPropertyValue(const FProperty& InProperty)
		{
			void* Buffer = FMemory::Malloc(InProperty.GetSize(), InProperty.GetMinAlignment());
			InProperty.InitializeValue(Buffer);
			return Buffer;
		}

		void FreeMutationPropertyValue(const FProperty& InProperty, void* InBuffer)
		{
			if (InBuffer == nullptr)
			{
				return;
			}

			InProperty.DestroyValue(InBuffer);
			FMemory::Free(InBuffer);
		}

		bool RequiresSingleTargetContainerMutation(const UGenericProperty& InNode)
		{
			if (InNode.NodeKind == EGenericPropertyNodeKind::Set
				|| InNode.NodeKind == EGenericPropertyNodeKind::Map
				|| InNode.NodeKind == EGenericPropertyNodeKind::MapEntry)
			{
				return true;
			}

			if (InNode.ParentNode != nullptr)
			{
				return InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::Set
					|| InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::Map
					|| InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::MapEntry;
			}

			return false;
		}

		FGenericPropertyWriteResult ValidateStructuralMutation(const UGenericPropertyProxy& InProxy, const UGenericProperty& InNode)
		{
			if (InProxy.GetOptions().bReadOnly)
			{
				return MakeFailureResult(FText::FromString(TEXT("This session is read-only.")));
			}

			if (InProxy.GetTargets().IsEmpty())
			{
				return MakeFailureResult(FText::FromString(TEXT("No valid target is available.")));
			}

			if (RequiresSingleTargetContainerMutation(InNode) && InProxy.GetTargets().Num() > 1)
			{
				return MakeFailureResult(FText::FromString(TEXT("This structural operation is only supported in single-object sessions.")));
			}

			FGenericPropertyWriteResult Result;
			Result.bSuccess = true;
			return Result;
		}

		bool ResolveOwningContainer(const UGenericProperty& InNode, FGenericPropertyAccessPath& OutContainerPath, EGenericPropertyNodeKind& OutContainerKind, int32& OutElementIndex)
		{
			OutContainerPath = InNode.GetAccessPath();
			OutContainerKind = InNode.NodeKind;
			OutElementIndex = InNode.ContainerElementIndex;

			if (InNode.NodeKind == EGenericPropertyNodeKind::Array
				|| InNode.NodeKind == EGenericPropertyNodeKind::Set
				|| InNode.NodeKind == EGenericPropertyNodeKind::Map)
			{
				return true;
			}

			if (InNode.NodeKind == EGenericPropertyNodeKind::MapEntry && InNode.ParentNode != nullptr)
			{
				OutContainerPath = InNode.ParentNode->GetAccessPath();
				OutContainerKind = InNode.ParentNode->NodeKind;
				return true;
			}

			if (InNode.ParentNode != nullptr)
			{
				if (InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::Array
					|| InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::Set
					|| InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::Map)
				{
					OutContainerPath = InNode.ParentNode->GetAccessPath();
					OutContainerKind = InNode.ParentNode->NodeKind;
					return true;
				}

				if (InNode.ParentNode->NodeKind == EGenericPropertyNodeKind::MapEntry && InNode.ParentNode->ParentNode != nullptr)
				{
					OutContainerPath = InNode.ParentNode->ParentNode->GetAccessPath();
					OutContainerKind = InNode.ParentNode->ParentNode->NodeKind;
					OutElementIndex = InNode.ParentNode->ContainerElementIndex;
					return true;
				}
			}

			return false;
		}
	}

	FGenericPropertyReadResult ReadNodeValue(const UGenericPropertyProxy& InProxy, const UGenericProperty& InNode)
	{
		FGenericPropertyReadResult Result;
		const TArray<TWeakObjectPtr<UObject>>& Targets = InProxy.GetTargets();
		if (Targets.IsEmpty() || !Targets[0].IsValid())
		{
			Result.ErrorMessage = FText::FromString(TEXT("No valid target is available."));
			return Result;
		}

		FResolvedValue ResolvedValue;
		if (!ResolveValue(Targets[0].Get(), InNode.GetAccessPath(), ResolvedValue))
		{
			Result.ErrorMessage = FText::FromString(ResolvedValue.FailureReason);
			return Result;
		}

		Result.bSuccess = true;
		Result.Value = ExportValueToString(*ResolvedValue.Property, ResolvedValue.ValuePtr);
		return Result;
	}

	FGenericPropertyValidationResult ValidateNodeValue(const UGenericPropertyProxy& InProxy, const UGenericProperty& InNode, const FString& InValue)
	{
		const TArray<TWeakObjectPtr<UObject>>& Targets = InProxy.GetTargets();
		if (Targets.IsEmpty() || !Targets[0].IsValid())
		{
			FGenericPropertyValidationResult Result;
			Result.bSuccess = false;
			Result.Message = FText::FromString(TEXT("No valid target is available."));
			return Result;
		}

		FResolvedValue ResolvedValue;
		if (!ResolveValue(Targets[0].Get(), InNode.GetAccessPath(), ResolvedValue))
		{
			FGenericPropertyValidationResult Result;
			Result.bSuccess = false;
			Result.Message = FText::FromString(ResolvedValue.FailureReason);
			return Result;
		}

		return ValidateValueText(*ResolvedValue.Property, ResolvedValue.ValuePtr, InValue, InNode.GetMetadata());
	}

	FGenericPropertyWriteResult WriteNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode, const FString& InValue)
	{
		FGenericPropertyWriteResult Result;

		FGenericPropertyValidationResult ValidationResult = ValidateNodeValue(InProxy, InNode, InValue);
		if (!ValidationResult.bSuccess)
		{
			Result.ErrorMessage = ValidationResult.Message;
			return Result;
		}

		for (const TWeakObjectPtr<UObject>& Target : InProxy.GetTargets())
		{
			FResolvedValue ResolvedValue;
			if (!Target.IsValid() || !ResolveValue(Target.Get(), InNode.GetAccessPath(), ResolvedValue))
			{
				Result.ErrorMessage = FText::FromString(ResolvedValue.FailureReason);
				return Result;
			}

			FText ImportError;
			if (!ImportValueFromString(*ResolvedValue.Property, ResolvedValue.ValuePtr, InValue, ImportError))
			{
				Result.ErrorMessage = ImportError;
				return Result;
			}

			RehashOwningContainer(Target.Get(), InNode.GetAccessPath());
		}

		InNode.SetCurrentAndSourceValue(InValue);
		Result.bSuccess = true;
		return Result;
	}

	bool ResetNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode, EGenericPropertyResetMode InMode)
	{
		switch (InMode)
		{
		case EGenericPropertyResetMode::SourceValue:
			InNode.CommitSerializedValueInternal(InNode.TextState.SourceValue);
			return !InNode.bIsInvalid;

		case EGenericPropertyResetMode::ClassDefault:
			if (InNode.TextState.DefaultValue.IsEmpty())
			{
				return false;
			}

			if (InProxy.GetOptions().ApplyMode == EGenericPropertyApplyMode::Automatic)
			{
				return WriteNodeValue(InProxy, InNode, InNode.TextState.DefaultValue).bSuccess;
			}

			InNode.CommitSerializedValueInternal(InNode.TextState.DefaultValue);
			return !InNode.bIsInvalid;
		}

		return false;
	}

	FGenericPropertyWriteResult AddContainerNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode)
	{
		if (const FGenericPropertyWriteResult Validation = ValidateStructuralMutation(InProxy, InNode); !Validation.bSuccess)
		{
			return Validation;
		}

		if (!InNode.IsContainerNode())
		{
			return MakeFailureResult(FText::FromString(TEXT("AddContainerElement can only be used on a container node.")));
		}

		for (const TWeakObjectPtr<UObject>& Target : InProxy.GetTargets())
		{
			FResolvedValue ResolvedValue;
			if (!Target.IsValid() || !ResolveValue(Target.Get(), InNode.GetAccessPath(), ResolvedValue))
			{
				return MakeFailureResult(FText::FromString(ResolvedValue.FailureReason));
			}

			if (const FArrayProperty* ArrayProperty = CastField<const FArrayProperty>(ResolvedValue.Property))
			{
				FScriptArrayHelper Helper(ArrayProperty, ResolvedValue.ValuePtr);
				Helper.AddValue();
			}
			else if (const FSetProperty* SetProperty = CastField<const FSetProperty>(ResolvedValue.Property))
			{
				FScriptSetHelper Helper(SetProperty, ResolvedValue.ValuePtr);
				void* DefaultValue = AllocateMutationPropertyValue(*SetProperty->ElementProp);
				const int32 OldNum = Helper.Num();
				Helper.AddElement(DefaultValue);
				const bool bAdded = Helper.Num() != OldNum;
				FreeMutationPropertyValue(*SetProperty->ElementProp, DefaultValue);
				if (!bAdded)
				{
					return MakeFailureResult(FText::FromString(TEXT("Default Set element already exists.")));
				}
			}
			else if (const FMapProperty* MapProperty = CastField<const FMapProperty>(ResolvedValue.Property))
			{
				FScriptMapHelper Helper(MapProperty, ResolvedValue.ValuePtr);
				void* DefaultKey = AllocateMutationPropertyValue(*MapProperty->KeyProp);
				void* DefaultValue = AllocateMutationPropertyValue(*MapProperty->ValueProp);

				const bool bKeyExists = Helper.FindMapPairPtrFromHash(DefaultKey) != nullptr;
				if (bKeyExists)
				{
					FreeMutationPropertyValue(*MapProperty->KeyProp, DefaultKey);
					FreeMutationPropertyValue(*MapProperty->ValueProp, DefaultValue);
					return MakeFailureResult(FText::FromString(TEXT("Default Map key already exists, cannot add a new entry safely.")));
				}

				Helper.AddPair(DefaultKey, DefaultValue);
				FreeMutationPropertyValue(*MapProperty->KeyProp, DefaultKey);
				FreeMutationPropertyValue(*MapProperty->ValueProp, DefaultValue);
			}
			else
			{
				return MakeFailureResult(FText::FromString(TEXT("Target node is not backed by a supported container property.")));
			}
		}

		FGenericPropertyWriteResult Result;
		Result.bSuccess = true;
		return Result;
	}

	FGenericPropertyWriteResult RemoveNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode)
	{
		if (const FGenericPropertyWriteResult Validation = ValidateStructuralMutation(InProxy, InNode); !Validation.bSuccess)
		{
			return Validation;
		}

		FGenericPropertyAccessPath ContainerPath;
		EGenericPropertyNodeKind ContainerKind = EGenericPropertyNodeKind::Value;
		int32 ElementIndex = INDEX_NONE;
		if (!ResolveOwningContainer(InNode, ContainerPath, ContainerKind, ElementIndex) || ElementIndex == INDEX_NONE)
		{
			return MakeFailureResult(FText::FromString(TEXT("RemoveNode requires a concrete container element node.")));
		}

		for (const TWeakObjectPtr<UObject>& Target : InProxy.GetTargets())
		{
			FResolvedValue ResolvedValue;
			if (!Target.IsValid() || !ResolveValue(Target.Get(), ContainerPath, ResolvedValue))
			{
				return MakeFailureResult(FText::FromString(ResolvedValue.FailureReason));
			}

			if (const FArrayProperty* ArrayProperty = CastField<const FArrayProperty>(ResolvedValue.Property))
			{
				FScriptArrayHelper Helper(ArrayProperty, ResolvedValue.ValuePtr);
				if (!Helper.IsValidIndex(ElementIndex))
				{
					return MakeFailureResult(FText::FromString(TEXT("Array element index is invalid.")));
				}

				Helper.RemoveValues(ElementIndex, 1);
			}
			else if (const FSetProperty* SetProperty = CastField<const FSetProperty>(ResolvedValue.Property))
			{
				FScriptSetHelper Helper(SetProperty, ResolvedValue.ValuePtr);
				if (!Helper.IsValidIndex(ElementIndex))
				{
					return MakeFailureResult(FText::FromString(TEXT("Set element index is invalid.")));
				}

				Helper.RemoveAt(ElementIndex, 1);
			}
			else if (const FMapProperty* MapProperty = CastField<const FMapProperty>(ResolvedValue.Property))
			{
				FScriptMapHelper Helper(MapProperty, ResolvedValue.ValuePtr);
				if (!Helper.IsValidIndex(ElementIndex))
				{
					return MakeFailureResult(FText::FromString(TEXT("Map element index is invalid.")));
				}

				Helper.RemoveAt(ElementIndex, 1);
			}
			else
			{
				return MakeFailureResult(FText::FromString(TEXT("Parent node is not backed by a supported container property.")));
			}
		}

		FGenericPropertyWriteResult Result;
		Result.bSuccess = true;
		return Result;
	}

	FGenericPropertyWriteResult DuplicateNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode)
	{
		if (const FGenericPropertyWriteResult Validation = ValidateStructuralMutation(InProxy, InNode); !Validation.bSuccess)
		{
			return Validation;
		}

		if (InNode.ParentNode == nullptr || InNode.ParentNode->NodeKind != EGenericPropertyNodeKind::Array || InNode.ContainerElementIndex == INDEX_NONE)
		{
			return MakeFailureResult(FText::FromString(TEXT("DuplicateNode is only supported for array element nodes.")));
		}

		for (const TWeakObjectPtr<UObject>& Target : InProxy.GetTargets())
		{
			FResolvedValue ResolvedValue;
			if (!Target.IsValid() || !ResolveValue(Target.Get(), InNode.ParentNode->GetAccessPath(), ResolvedValue))
			{
				return MakeFailureResult(FText::FromString(ResolvedValue.FailureReason));
			}

			const FArrayProperty* ArrayProperty = CastField<const FArrayProperty>(ResolvedValue.Property);
			if (ArrayProperty == nullptr)
			{
				return MakeFailureResult(FText::FromString(TEXT("Parent node is not backed by an array property.")));
			}

			FScriptArrayHelper Helper(ArrayProperty, ResolvedValue.ValuePtr);
			if (!Helper.IsValidIndex(InNode.ContainerElementIndex))
			{
				return MakeFailureResult(FText::FromString(TEXT("Array element index is invalid.")));
			}

			Helper.InsertValues(InNode.ContainerElementIndex + 1, 1);
			ArrayProperty->Inner->CopyCompleteValue(Helper.GetRawPtr(InNode.ContainerElementIndex + 1), Helper.GetRawPtr(InNode.ContainerElementIndex));
		}

		FGenericPropertyWriteResult Result;
		Result.bSuccess = true;
		return Result;
	}

	FGenericPropertyWriteResult MoveNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode, const int32 InNewIndex)
	{
		if (const FGenericPropertyWriteResult Validation = ValidateStructuralMutation(InProxy, InNode); !Validation.bSuccess)
		{
			return Validation;
		}

		if (InNode.ParentNode == nullptr || InNode.ParentNode->NodeKind != EGenericPropertyNodeKind::Array || InNode.ContainerElementIndex == INDEX_NONE)
		{
			return MakeFailureResult(FText::FromString(TEXT("MoveNode is only supported for array element nodes.")));
		}

		for (const TWeakObjectPtr<UObject>& Target : InProxy.GetTargets())
		{
			FResolvedValue ResolvedValue;
			if (!Target.IsValid() || !ResolveValue(Target.Get(), InNode.ParentNode->GetAccessPath(), ResolvedValue))
			{
				return MakeFailureResult(FText::FromString(ResolvedValue.FailureReason));
			}

			const FArrayProperty* ArrayProperty = CastField<const FArrayProperty>(ResolvedValue.Property);
			if (ArrayProperty == nullptr)
			{
				return MakeFailureResult(FText::FromString(TEXT("Parent node is not backed by an array property.")));
			}

			FScriptArrayHelper Helper(ArrayProperty, ResolvedValue.ValuePtr);
			if (!Helper.IsValidIndex(InNode.ContainerElementIndex) || !Helper.IsValidIndex(InNewIndex))
			{
				return MakeFailureResult(FText::FromString(TEXT("Array reorder target is invalid.")));
			}

			if (InNewIndex > InNode.ContainerElementIndex)
			{
				for (int32 Index = InNode.ContainerElementIndex; Index < InNewIndex; ++Index)
				{
					Helper.SwapValues(Index, Index + 1);
				}
			}
			else if (InNewIndex < InNode.ContainerElementIndex)
			{
				for (int32 Index = InNode.ContainerElementIndex; Index > InNewIndex; --Index)
				{
					Helper.SwapValues(Index, Index - 1);
				}
			}
		}

		FGenericPropertyWriteResult Result;
		Result.bSuccess = true;
		return Result;
	}

	FGenericPropertyWriteResult ClearNodeValue(UGenericPropertyProxy& InProxy, UGenericProperty& InNode)
	{
		if (const FGenericPropertyWriteResult Validation = ValidateStructuralMutation(InProxy, InNode); !Validation.bSuccess)
		{
			return Validation;
		}

		if (!InNode.IsContainerNode())
		{
			return MakeFailureResult(FText::FromString(TEXT("ClearNode can only be used on a container node.")));
		}

		for (const TWeakObjectPtr<UObject>& Target : InProxy.GetTargets())
		{
			FResolvedValue ResolvedValue;
			if (!Target.IsValid() || !ResolveValue(Target.Get(), InNode.GetAccessPath(), ResolvedValue))
			{
				return MakeFailureResult(FText::FromString(ResolvedValue.FailureReason));
			}

			if (const FArrayProperty* ArrayProperty = CastField<const FArrayProperty>(ResolvedValue.Property))
			{
				FScriptArrayHelper Helper(ArrayProperty, ResolvedValue.ValuePtr);
				Helper.EmptyValues();
			}
			else if (const FSetProperty* SetProperty = CastField<const FSetProperty>(ResolvedValue.Property))
			{
				FScriptSetHelper Helper(SetProperty, ResolvedValue.ValuePtr);
				Helper.EmptyElements();
			}
			else if (const FMapProperty* MapProperty = CastField<const FMapProperty>(ResolvedValue.Property))
			{
				FScriptMapHelper Helper(MapProperty, ResolvedValue.ValuePtr);
				Helper.EmptyValues();
			}
			else
			{
				return MakeFailureResult(FText::FromString(TEXT("Target node is not backed by a supported container property.")));
			}
		}

		FGenericPropertyWriteResult Result;
		Result.bSuccess = true;
		return Result;
	}
}
