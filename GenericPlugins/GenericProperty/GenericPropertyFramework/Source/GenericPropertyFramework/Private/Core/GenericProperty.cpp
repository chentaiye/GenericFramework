#include "Core/GenericProperty.h"

#include "Data/GenericPropertyDataSourceCollection.h"
#include "Data/GenericPropertyValueUtilities.h"
#include "GameplayTagsManager.h"
#include "Model/GenericPropertyProxy.h"

namespace
{
	struct FNodeRefreshSnapshot
	{
		FGenericPropertyIssue Issue;
		EGenericPropertyValueType TypeName = EGenericPropertyValueType::Unknown;
		FName NativeTypeName = NAME_None;
		FString TypeObjectPath;
		EGenericPropertyNodeKind NodeKind = EGenericPropertyNodeKind::Value;
		FGenericPropertyNodeTextState TextState;
		int32 ChildCount = 0;
		bool bIsSupported = true;
		bool bCanExpand = false;
		bool bSupportsDirectEdit = false;
		bool bIsVisible = true;
		bool bMatchesSearch = true;
		bool bIsEditable = false;
		bool bIsEnabled = true;
		bool bIsAdvanced = false;
		bool bIsDirty = false;
		bool bIsInvalid = false;
		bool bHasMixedValues = false;
		bool bHasConflict = false;
		bool bSupportsAddElement = false;
		bool bSupportsRemoveElement = false;
		bool bSupportsDuplicateElement = false;
		bool bSupportsReorderElement = false;
		bool bSupportsClearChildren = false;
		bool bChildrenDirty = false;
	};

	FNodeRefreshSnapshot MakeSnapshot(const UGenericProperty& InNode)
	{
		FNodeRefreshSnapshot Snapshot;
		Snapshot.Issue = InNode.Issue;
		Snapshot.TypeName = InNode.TypeName;
		Snapshot.NativeTypeName = InNode.NativeTypeName;
		Snapshot.TypeObjectPath = InNode.TypeObjectPath;
		Snapshot.NodeKind = InNode.NodeKind;
		Snapshot.TextState = InNode.TextState;
		Snapshot.ChildCount = InNode.Children.Num();
		Snapshot.bIsSupported = InNode.bIsSupported;
		Snapshot.bCanExpand = InNode.bCanExpand;
		Snapshot.bSupportsDirectEdit = InNode.bSupportsDirectEdit;
		Snapshot.bIsVisible = InNode.bIsVisible;
		Snapshot.bMatchesSearch = InNode.bMatchesSearch;
		Snapshot.bIsEditable = InNode.bIsEditable;
		Snapshot.bIsEnabled = InNode.bIsEnabled;
		Snapshot.bIsAdvanced = InNode.bIsAdvanced;
		Snapshot.bIsDirty = InNode.bIsDirty;
		Snapshot.bIsInvalid = InNode.bIsInvalid;
		Snapshot.bHasMixedValues = InNode.bHasMixedValues;
		Snapshot.bHasConflict = InNode.bHasConflict;
		Snapshot.bSupportsAddElement = InNode.bSupportsAddElement;
		Snapshot.bSupportsRemoveElement = InNode.bSupportsRemoveElement;
		Snapshot.bSupportsDuplicateElement = InNode.bSupportsDuplicateElement;
		Snapshot.bSupportsReorderElement = InNode.bSupportsReorderElement;
		Snapshot.bSupportsClearChildren = InNode.bSupportsClearChildren;
		Snapshot.bChildrenDirty = InNode.bChildrenDirty;
		return Snapshot;
	}

	bool DidSnapshotChange(const FNodeRefreshSnapshot& Before, const UGenericProperty& After)
	{
		return Before.Issue.Severity != After.Issue.Severity
			|| Before.Issue.Type != After.Issue.Type
			|| !Before.Issue.Message.EqualTo(After.Issue.Message)
			|| Before.TypeName != After.TypeName
			|| Before.NativeTypeName != After.NativeTypeName
			|| Before.TypeObjectPath != After.TypeObjectPath
			|| Before.NodeKind != After.NodeKind
			|| Before.TextState.SourceValue != After.TextState.SourceValue
			|| Before.TextState.CurrentValue != After.TextState.CurrentValue
			|| Before.TextState.DefaultValue != After.TextState.DefaultValue
			|| Before.ChildCount != After.Children.Num()
			|| Before.bIsSupported != After.bIsSupported
			|| Before.bCanExpand != After.bCanExpand
			|| Before.bSupportsDirectEdit != After.bSupportsDirectEdit
			|| Before.bIsVisible != After.bIsVisible
			|| Before.bMatchesSearch != After.bMatchesSearch
			|| Before.bIsEditable != After.bIsEditable
			|| Before.bIsEnabled != After.bIsEnabled
			|| Before.bIsAdvanced != After.bIsAdvanced
			|| Before.bIsDirty != After.bIsDirty
			|| Before.bIsInvalid != After.bIsInvalid
			|| Before.bHasMixedValues != After.bHasMixedValues
			|| Before.bHasConflict != After.bHasConflict
			|| Before.bSupportsAddElement != After.bSupportsAddElement
			|| Before.bSupportsRemoveElement != After.bSupportsRemoveElement
			|| Before.bSupportsDuplicateElement != After.bSupportsDuplicateElement
			|| Before.bSupportsReorderElement != After.bSupportsReorderElement
			|| Before.bSupportsClearChildren != After.bSupportsClearChildren
			|| Before.bChildrenDirty != After.bChildrenDirty;
	}

	void AppendMetadataTags(const FName InKey, const FString& InValue, FGameplayTagContainer& OutTags)
	{
		static const TSet<FName> SupportedTagMetadataKeys = {
			TEXT("GenericPropertyTag"),
			TEXT("GenericPropertyTags"),
			TEXT("GameplayTagFilter")
		};

		if (!SupportedTagMetadataKeys.Contains(InKey) || InValue.IsEmpty())
		{
			return;
		}

		FString NormalizedValue = InValue;
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

	void PropagateStateToRoot(UGenericProperty* InNode)
	{
		for (UGenericProperty* Current = InNode; Current != nullptr; Current = Current->ParentNode)
		{
			Current->RecalculateState();
		}
	}

	void BroadcastStateChangeToRoot(UGenericProperty* InNode, const bool bStructureChangedSelf)
	{
		for (UGenericProperty* Current = InNode; Current != nullptr; Current = Current->ParentNode)
		{
			Current->BroadcastChanged(Current == InNode ? bStructureChangedSelf : false);
		}
	}

	bool DispatchPrimaryTargetPathChange(UGenericProperty& InNode, const FString& InPropertyPath, const bool bStructuralChange)
	{
		if (InNode.OwningProxy == nullptr)
		{
			return false;
		}

		const TArray<TWeakObjectPtr<UObject>>& Targets = InNode.OwningProxy->GetTargets();
		if (!Targets.IsEmpty() && Targets[0].IsValid())
		{
			return InNode.OwningProxy->DispatchPropertyPathChanged(Targets[0].Get(), InPropertyPath, bStructuralChange);
		}

		InNode.Refresh();
		return true;
	}
}

void UGenericProperty::Initialize(UGenericPropertyProxy* InProxy)
{
	OwningProxy = InProxy;
}

void UGenericProperty::CommitSerializedValueInternal(const FString& InValue)
{
	if (!bSupportsDirectEdit || OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr)
	{
		return;
	}

	TextState.CurrentValue = InValue;
	SetValidationState(GenericPropertyFramework::Private::ValidateNodeValue(*OwningProxy, *this, InValue));
	bIsDirty = !TextState.CurrentValue.Equals(TextState.SourceValue, ESearchCase::CaseSensitive);
	PropagateStateToRoot(this);
	BroadcastStateChangeToRoot(this, false);

	if (!bIsInvalid && OwningProxy->GetOptions().ApplyMode == EGenericPropertyApplyMode::Automatic)
	{
		Apply();
	}
}

bool UGenericProperty::Apply()
{
	if (OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr || !bSupportsDirectEdit || bIsInvalid)
	{
		return false;
	}

	const FGenericPropertyWriteResult Result = GenericPropertyFramework::Private::WriteNodeValue(*OwningProxy, *this, TextState.CurrentValue);
	if (!Result.bSuccess)
	{
		Issue.Severity = EGenericPropertyIssueSeverity::Error;
		Issue.Type = EGenericPropertyIssueType::OperationFailed;
		Issue.Message = Result.ErrorMessage;
		bIsInvalid = true;
		BroadcastStateChangeToRoot(this, false);
		return false;
	}

	return DispatchPrimaryTargetPathChange(*this, PropertyPath, false);
}

bool UGenericProperty::Reset(const EGenericPropertyResetMode InMode)
{
	if (OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr)
	{
		return false;
	}

	const bool bResetSucceeded = OwningProxy->GetDataSource()->ResetNode(*this, InMode);
	if (!bResetSucceeded)
	{
		return false;
	}

	if (InMode == EGenericPropertyResetMode::ClassDefault && OwningProxy->GetOptions().ApplyMode == EGenericPropertyApplyMode::Automatic)
	{
		return DispatchPrimaryTargetPathChange(*this, PropertyPath, false);
	}

	return true;
}

void UGenericProperty::Refresh()
{
	RefreshFromSource();
}

bool UGenericProperty::RefreshFromSource()
{
	if (OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr)
	{
		return false;
	}

	const FNodeRefreshSnapshot BeforeSnapshot = MakeSnapshot(*this);
	OwningProxy->GetDataSource()->RefreshNode(*this);
	PropagateStateToRoot(this);
	const bool bDidChange = DidSnapshotChange(BeforeSnapshot, *this);
	if (bDidChange)
	{
		const bool bStructureChanged = BeforeSnapshot.ChildCount != Children.Num();
		BroadcastStateChangeToRoot(this, bStructureChanged);
	}

	return bDidChange;
}

void UGenericProperty::SetExpanded(const bool bInExpanded)
{
	bIsExpanded = bInExpanded;
	if (bIsExpanded && OwningProxy != nullptr && OwningProxy->GetDataSource() != nullptr)
	{
		OwningProxy->GetDataSource()->RebuildNodeChildren(*this);
		bChildrenDirty = false;
		PropagateStateToRoot(this);
		BroadcastStateChangeToRoot(this, true);
	}
}

bool UGenericProperty::AddContainerElement()
{
	if (OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr || !bSupportsAddElement)
	{
		return false;
	}

	const FGenericPropertyWriteResult Result = OwningProxy->GetDataSource()->AddContainerElement(*this);
	if (!Result.bSuccess)
	{
		Issue.Severity = EGenericPropertyIssueSeverity::Error;
		Issue.Type = EGenericPropertyIssueType::OperationFailed;
		Issue.Message = Result.ErrorMessage;
		BroadcastStateChangeToRoot(this, false);
		return false;
	}

	return DispatchPrimaryTargetPathChange(*this, PropertyPath, true);
}

bool UGenericProperty::RemoveNode()
{
	if (OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr || !bSupportsRemoveElement)
	{
		return false;
	}

	const FGenericPropertyWriteResult Result = OwningProxy->GetDataSource()->RemoveNode(*this);
	if (!Result.bSuccess)
	{
		Issue.Severity = EGenericPropertyIssueSeverity::Error;
		Issue.Type = EGenericPropertyIssueType::OperationFailed;
		Issue.Message = Result.ErrorMessage;
		BroadcastStateChangeToRoot(this, false);
		return false;
	}

	if (ParentNode != nullptr)
	{
		return DispatchPrimaryTargetPathChange(*ParentNode, ParentNode->PropertyPath, true);
	}

	Refresh();
	return true;
}

bool UGenericProperty::DuplicateNode()
{
	if (OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr || !bSupportsDuplicateElement)
	{
		return false;
	}

	const FGenericPropertyWriteResult Result = OwningProxy->GetDataSource()->DuplicateNode(*this);
	if (!Result.bSuccess)
	{
		Issue.Severity = EGenericPropertyIssueSeverity::Error;
		Issue.Type = EGenericPropertyIssueType::OperationFailed;
		Issue.Message = Result.ErrorMessage;
		BroadcastStateChangeToRoot(this, false);
		return false;
	}

	if (ParentNode != nullptr)
	{
		return DispatchPrimaryTargetPathChange(*ParentNode, ParentNode->PropertyPath, true);
	}

	Refresh();
	return true;
}

bool UGenericProperty::MoveArrayElement(const int32 InNewIndex)
{
	if (OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr || !bSupportsReorderElement)
	{
		return false;
	}

	const FGenericPropertyWriteResult Result = OwningProxy->GetDataSource()->MoveNode(*this, InNewIndex);
	if (!Result.bSuccess)
	{
		Issue.Severity = EGenericPropertyIssueSeverity::Error;
		Issue.Type = EGenericPropertyIssueType::OperationFailed;
		Issue.Message = Result.ErrorMessage;
		BroadcastStateChangeToRoot(this, false);
		return false;
	}

	if (ParentNode != nullptr)
	{
		return DispatchPrimaryTargetPathChange(*ParentNode, ParentNode->PropertyPath, true);
	}

	Refresh();
	return true;
}

bool UGenericProperty::ClearContainer()
{
	if (OwningProxy == nullptr || OwningProxy->GetDataSource() == nullptr || !bSupportsClearChildren)
	{
		return false;
	}

	const FGenericPropertyWriteResult Result = OwningProxy->GetDataSource()->ClearNode(*this);
	if (!Result.bSuccess)
	{
		Issue.Severity = EGenericPropertyIssueSeverity::Error;
		Issue.Type = EGenericPropertyIssueType::OperationFailed;
		Issue.Message = Result.ErrorMessage;
		BroadcastStateChangeToRoot(this, false);
		return false;
	}

	return DispatchPrimaryTargetPathChange(*this, PropertyPath, true);
}

bool UGenericProperty::HasVisibleChildren() const
{
	for (const UGenericProperty* Child : Children)
	{
		if (Child != nullptr && Child->bIsVisible)
		{
			return true;
		}
	}

	return false;
}

bool UGenericProperty::IsContainerNode() const
{
	return NodeKind == EGenericPropertyNodeKind::Array
		|| NodeKind == EGenericPropertyNodeKind::Set
		|| NodeKind == EGenericPropertyNodeKind::Map;
}

bool UGenericProperty::HasVisualTag(const FGameplayTag InTag) const
{
	return InTag.IsValid() && VisualTags.HasTagExact(InTag);
}

void UGenericProperty::RecalculateState()
{
	const bool bOwnDirty = !TextState.CurrentValue.Equals(TextState.SourceValue, ESearchCase::CaseSensitive);
	const bool bOwnInvalid = Issue.IsError() && bIsInvalid;

	bool bAnyChildVisible = false;
	bool bAnyChildDirty = false;
	bool bAnyChildInvalid = false;

	for (UGenericProperty* Child : Children)
	{
		if (Child == nullptr)
		{
			continue;
		}

		bAnyChildVisible |= Child->bIsVisible;
		bAnyChildDirty |= Child->bIsDirty;
		bAnyChildInvalid |= Child->bIsInvalid;
	}

	if (Children.Num() > 0)
	{
		bIsDirty = bOwnDirty || bAnyChildDirty;
		bIsInvalid = bOwnInvalid || bAnyChildInvalid;
		bIsVisible &= bAnyChildVisible || bMatchesSearch;
	}
	else
	{
		bIsDirty = bOwnDirty;
		bIsInvalid = bOwnInvalid;
	}
}

void UGenericProperty::SetMetadata(TMap<FName, FString>&& InMetadata)
{
	Metadata = MoveTemp(InMetadata);
	MetadataKeys.Reset();
	VisualTags.Reset();
	InvalidateSearchableText();

	for (const TPair<FName, FString>& Pair : Metadata)
	{
		MetadataKeys.Add(Pair.Key);
		AppendMetadataTags(Pair.Key, Pair.Value, VisualTags);
	}
}

void UGenericProperty::SetAccessPath(const FGenericPropertyAccessPath& InPath)
{
	AccessPath = InPath;
	InvalidateSearchableText();
}

void UGenericProperty::SetInternalTypeName(const EGenericPropertyValueType InTypeName, const FName InNativeTypeName, FString InTypeObjectPath)
{
	TypeName = InTypeName;
	NativeTypeName = InNativeTypeName;
	TypeObjectPath = MoveTemp(InTypeObjectPath);
}

FString UGenericProperty::GetSearchableText() const
{
	if (!bSearchableTextDirty)
	{
		return CachedSearchableText;
	}

	TStringBuilder<512> Builder;
	Builder.Append(DisplayName.ToString());
	Builder.Append(TEXT(" "));
	Builder.Append(PropertyName.ToString());
	Builder.Append(TEXT(" "));
	Builder.Append(CategoryName.ToString());
	Builder.Append(TEXT(" "));
	Builder.Append(PropertyPath);

	for (const FName MetadataKey : MetadataKeys)
	{
		Builder.Append(TEXT(" "));
		Builder.Append(MetadataKey.ToString());
	}

	for (const TPair<FName, FString>& Pair : Metadata)
	{
		if (!Pair.Value.IsEmpty())
		{
			Builder.Append(TEXT(" "));
			Builder.Append(Pair.Value);
		}
	}

	TArray<FGameplayTag> TagArray;
	VisualTags.GetGameplayTagArray(TagArray);
	for (const FGameplayTag& Tag : TagArray)
	{
		Builder.Append(TEXT(" "));
		Builder.Append(Tag.ToString());
	}

	UGenericProperty* MutableThis = const_cast<UGenericProperty*>(this);
	MutableThis->CachedSearchableText = Builder.ToString();
	MutableThis->bSearchableTextDirty = false;
	return CachedSearchableText;
}

void UGenericProperty::InvalidateSearchableText()
{
	bSearchableTextDirty = true;
	CachedSearchableText.Reset();
}

void UGenericProperty::MarkUnsupported(const FText& InMessage, const EGenericPropertyIssueType InIssueType)
{
	bIsSupported = false;
	bIsEditable = false;
	bIsEnabled = false;
	bCanExpand = false;
	bSupportsAddElement = false;
	bSupportsRemoveElement = false;
	bSupportsDuplicateElement = false;
	bSupportsReorderElement = false;
	bSupportsClearChildren = false;
	NodeKind = EGenericPropertyNodeKind::Warning;
	Issue.Severity = EGenericPropertyIssueSeverity::Warning;
	Issue.Type = InIssueType;
	Issue.Message = InMessage;
}

void UGenericProperty::SetCurrentAndSourceValue(const FString& InValue)
{
	TextState.SourceValue = InValue;
	TextState.CurrentValue = InValue;
	bIsDirty = false;
	bIsInvalid = false;
	Issue.Reset();
	bHasConflict = false;
}

void UGenericProperty::SetDefaultValue(const FString& InValue)
{
	TextState.DefaultValue = InValue;
}

void UGenericProperty::SetValidationState(const FGenericPropertyValidationResult& InValidationResult)
{
	bIsInvalid = !InValidationResult.bSuccess;
	Issue.Severity = bIsInvalid ? EGenericPropertyIssueSeverity::Error : EGenericPropertyIssueSeverity::None;
	Issue.Type = bIsInvalid ? EGenericPropertyIssueType::Validation : EGenericPropertyIssueType::None;
	Issue.Message = InValidationResult.Message;
}

void UGenericProperty::UpdateVisibilityFromSearch(const FString& InSearchText, const bool bShowAdvanced)
{
	const FString TrimmedSearch = InSearchText.TrimStartAndEnd();

	if (!TrimmedSearch.IsEmpty()
		&& bCanExpand
		&& NodeKind != EGenericPropertyNodeKind::MapEntry
		&& OwningProxy != nullptr
		&& OwningProxy->GetDataSource() != nullptr
		&& (Children.IsEmpty() || bChildrenDirty))
	{
		OwningProxy->GetDataSource()->RebuildNodeChildren(*this);
		bChildrenDirty = false;
	}

	const bool bSelfMatches = TrimmedSearch.IsEmpty()
		|| GetSearchableText().Contains(TrimmedSearch, ESearchCase::IgnoreCase);

	bMatchesSearch = bSelfMatches;

	bool bAnyChildVisible = false;
	for (UGenericProperty* Child : Children)
	{
		if (Child == nullptr)
		{
			continue;
		}

		Child->UpdateVisibilityFromSearch(TrimmedSearch, bShowAdvanced);
		bAnyChildVisible |= Child->bIsVisible;
	}

	bIsVisible = (bSelfMatches || bAnyChildVisible) && (bShowAdvanced || !bIsAdvanced);
}

void UGenericProperty::BroadcastChanged(const bool bStructureChanged)
{
	Delegate_OnViewModelChanged.Broadcast(this, bStructureChanged);
	BPDelegate_OnViewModelChanged.Broadcast(this, bStructureChanged);
}
