#include "Model/GenericPropertyProxy.h"

#include "Core/GenericProperty.h"
#include "Core/GenericPropertyCollection.h"
#include "Data/GenericPropertyAutoDataSourceCollection.h"
#include "Data/GenericPropertyDataSourceCollection.h"
#include "Handle/GenericPropertyValueHandle.h"
#include "Model/GenericPropertySessionCore.h"

namespace
{
	void GatherNodesRecursive(UGenericProperty* InNode, TArray<UGenericProperty*>& OutNodes)
	{
		if (InNode == nullptr)
		{
			return;
		}

		OutNodes.Add(InNode);
		for (UGenericProperty* Child : InNode->Children)
		{
			GatherNodesRecursive(Child, OutNodes);
		}
	}

	void FilterTargets(const TArray<UObject*>& InTargets, const FGenericPropertyPanelOptions& InOptions, TArray<TWeakObjectPtr<UObject>>& OutTargets)
	{
		OutTargets.Reset();
		for (UObject* Target : InTargets)
		{
			if (Target == nullptr)
			{
				continue;
			}

			if (!InOptions.bAllowMultiObjectEditing && !OutTargets.IsEmpty())
			{
				break;
			}

			OutTargets.Add(Target);
		}
	}

	FName ExtractTopLevelPropertyNameFromPath(const FString& InPropertyPath)
	{
		const FString TrimmedPath = InPropertyPath.TrimStartAndEnd();
		if (TrimmedPath.IsEmpty())
		{
			return NAME_None;
		}

		int32 EndIndex = TrimmedPath.Len();
		for (const TCHAR Delimiter : { TEXT('.'), TEXT('['), TEXT('{'), TEXT('<') })
		{
			int32 FoundIndex = INDEX_NONE;
			if (TrimmedPath.FindChar(Delimiter, FoundIndex))
			{
				EndIndex = FMath::Min(EndIndex, FoundIndex);
			}
		}

		return EndIndex > 0 ? FName(*TrimmedPath.Left(EndIndex)) : NAME_None;
	}

	FName ExtractSimpleEditConditionDependency(const FString& InExpression)
	{
		FString PropertyNameString = InExpression.TrimStartAndEnd();
		if (PropertyNameString.IsEmpty())
		{
			return NAME_None;
		}

		if (PropertyNameString.StartsWith(TEXT("!")))
		{
			PropertyNameString.RightChopInline(1);
			PropertyNameString = PropertyNameString.TrimStartAndEnd();
		}

		if (PropertyNameString.IsEmpty()
			|| PropertyNameString.Contains(TEXT(" "))
			|| PropertyNameString.Contains(TEXT("&"))
			|| PropertyNameString.Contains(TEXT("|"))
			|| PropertyNameString.Contains(TEXT("("))
			|| PropertyNameString.Contains(TEXT(")"))
			|| PropertyNameString.Contains(TEXT("="))
			|| PropertyNameString.Contains(TEXT("<"))
			|| PropertyNameString.Contains(TEXT(">")))
		{
			return NAME_None;
		}

		return FName(*PropertyNameString);
	}

	FName GetTopLevelPropertyNameForNode(const UGenericProperty& InNode)
	{
		for (const FGenericPropertyAccessSegment& Segment : InNode.GetAccessPath().Segments)
		{
			if (Segment.Type == EGenericPropertyAccessType::Property && Segment.PropertyName != NAME_None)
			{
				return Segment.PropertyName;
			}
		}

		if (InNode.ParentNode != nullptr)
		{
			return GetTopLevelPropertyNameForNode(*InNode.ParentNode);
		}

		return InNode.PropertyName;
	}

	void AddIndexedNode(TMap<FName, TArray<TWeakObjectPtr<UGenericProperty>>>& InIndex, const FName InKey, UGenericProperty& InNode)
	{
		if (InKey == NAME_None)
		{
			return;
		}

		InIndex.FindOrAdd(InKey).Add(&InNode);
	}

	void IndexNodeRecursive(UGenericProperty& InNode, TMap<FName, TArray<TWeakObjectPtr<UGenericProperty>>>& OutNodesByTopLevelProperty, TMap<FName, TArray<TWeakObjectPtr<UGenericProperty>>>& OutNodesByEditConditionDependency, TMap<FString, TWeakObjectPtr<UGenericProperty>>& OutNodesByExactPropertyPath)
	{
		const FName TopLevelPropertyName = GetTopLevelPropertyNameForNode(InNode);
		AddIndexedNode(OutNodesByTopLevelProperty, TopLevelPropertyName, InNode);

		const FName DependencyPropertyName = ExtractSimpleEditConditionDependency(InNode.EditConditionExpression);
		AddIndexedNode(OutNodesByEditConditionDependency, DependencyPropertyName, InNode);

		if (!InNode.PropertyPath.IsEmpty())
		{
			OutNodesByExactPropertyPath.Add(InNode.PropertyPath, &InNode);
		}

		for (UGenericProperty* Child : InNode.Children)
		{
			if (Child != nullptr)
			{
				IndexNodeRecursive(*Child, OutNodesByTopLevelProperty, OutNodesByEditConditionDependency, OutNodesByExactPropertyPath);
			}
		}
	}

	bool HasSelectedAncestor(const UGenericProperty* InNode, const TSet<const UGenericProperty*>& InSelectedNodes)
	{
		for (const UGenericProperty* Parent = InNode != nullptr ? InNode->ParentNode.Get() : nullptr; Parent != nullptr; Parent = Parent->ParentNode.Get())
		{
			if (InSelectedNodes.Contains(Parent))
			{
				return true;
			}
		}

		return false;
	}

	FString GetParentPropertyPath(const FString& InPropertyPath)
	{
		int32 DotIndex = INDEX_NONE;
		if (!InPropertyPath.FindLastChar(TEXT('.'), DotIndex) || DotIndex <= 0)
		{
			return FString();
		}

		return InPropertyPath.Left(DotIndex);
	}

	bool IsPropertyPathPrefix(const FString& InPrefix, const FString& InPath)
	{
		return InPath.Equals(InPrefix, ESearchCase::CaseSensitive)
			|| InPath.StartsWith(InPrefix + TEXT("."), ESearchCase::CaseSensitive)
			|| InPath.StartsWith(InPrefix + TEXT("["), ESearchCase::CaseSensitive)
			|| InPath.StartsWith(InPrefix + TEXT("{"), ESearchCase::CaseSensitive)
			|| InPath.StartsWith(InPrefix + TEXT("<"), ESearchCase::CaseSensitive);
	}

	template<typename THandleType>
	THandleType* CreateTypedHandleForField(UGenericPropertyProxy& InProxy, const FGenericPropertyFieldKey& InFieldKey)
	{
		return Cast<THandleType>(InProxy.CreateValueHandleForField(InFieldKey));
	}
}

void UGenericPropertyProxy::Initialize(const TArray<UObject*>& InTargets, const FGenericPropertyPanelOptions& InOptions, TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass)
{
	Options = InOptions;
	DataSourceClass = InDataSourceClass;

	if (DataSourceClass == nullptr)
	{
		DataSourceClass = UGenericPropertyAutoDataSourceCollection::StaticClass();
	}

	SetTargets(InTargets);
}

void UGenericPropertyProxy::SetTargets(const TArray<UObject*>& InTargets)
{
	FilterTargets(InTargets, Options, Targets);
	SessionCore = MakeShared<FGenericPropertySessionCore>(*this);
	RegisteredValueHandles.Reset();

	DataSource = nullptr;
	if (!Targets.IsEmpty() && DataSourceClass != nullptr)
	{
		DataSource = NewObject<UGenericPropertyDataSourceCollection>(this, DataSourceClass);
	}

	if (DataSource != nullptr)
	{
		DataSource->Initialize(this, Options);
	}

	bInitialized = DataSource != nullptr && !Targets.IsEmpty();
	LastRefreshTimeSeconds = FPlatformTime::Seconds();
	InvalidateNodeLookupCaches();
	ClearPendingPropertyChanges();
	Rebuild();
}

void UGenericPropertyProxy::Rebuild()
{
	RootNodes.Reset();
	InvalidateNodeLookupCaches();
	if (!bInitialized || DataSource == nullptr)
	{
		return;
	}

	TArray<UGenericProperty*> BuiltNodes;
	DataSource->BuildRootNodes(BuiltNodes);

	for (UGenericProperty* Node : BuiltNodes)
	{
		if (Node != nullptr)
		{
			RootNodes.Add(Node);
		}
	}

	if (Collection != nullptr)
	{
		Collection->RebuildFromProxy();
	}

	ClearPendingPropertyChanges();
	LastRefreshTimeSeconds = FPlatformTime::Seconds();
}

void UGenericPropertyProxy::Refresh()
{
	bool bAnyNodeChanged = false;
	for (UGenericProperty* Node : RootNodes)
	{
		if (Node != nullptr)
		{
			bAnyNodeChanged |= Node->RefreshFromSource();
		}
	}

	if (Collection != nullptr && bAnyNodeChanged)
	{
		Collection->RefreshPresentation();
	}

	ClearPendingPropertyChanges();
	LastRefreshTimeSeconds = FPlatformTime::Seconds();
}

bool UGenericPropertyProxy::ApplyAll()
{
	bool bAllSucceeded = true;
	bool bAttemptedApply = false;
	TArray<UGenericProperty*> AllNodes;
	for (UGenericProperty* Node : RootNodes)
	{
		GatherNodesRecursive(Node, AllNodes);
	}

	BeginMutationBatch();
	for (UGenericProperty* Node : AllNodes)
	{
		if (Node != nullptr && Node->bSupportsDirectEdit && Node->bIsDirty)
		{
			bAttemptedApply = true;
			bAllSucceeded &= Node->Apply();
		}
	}
	const bool bFlushedQueuedChanges = EndMutationBatch();

	if (bAttemptedApply && !bFlushedQueuedChanges && Collection != nullptr)
	{
		Collection->RefreshPresentation();
	}

	return bAllSucceeded;
}

bool UGenericPropertyProxy::ResetAll(const EGenericPropertyResetMode InMode)
{
	bool bAllSucceeded = true;
	bool bAttemptedReset = false;
	TArray<UGenericProperty*> AllNodes;
	for (UGenericProperty* Node : RootNodes)
	{
		GatherNodesRecursive(Node, AllNodes);
	}

	BeginMutationBatch();
	for (UGenericProperty* Node : AllNodes)
	{
		if (Node != nullptr && Node->bSupportsDirectEdit)
		{
			bAttemptedReset = true;
			bAllSucceeded &= Node->Reset(InMode);
		}
	}
	const bool bFlushedQueuedChanges = EndMutationBatch();

	if (bAttemptedReset && !bFlushedQueuedChanges && Collection != nullptr)
	{
		Collection->RefreshPresentation();
	}

	return bAllSucceeded;
}

UGenericPropertyCollection* UGenericPropertyProxy::CreateCollection()
{
	if (Collection == nullptr)
	{
		Collection = NewObject<UGenericPropertyCollection>(this);
		Collection->Initialize(this);
	}

	return Collection;
}

bool UGenericPropertyProxy::ResolveField(UClass* InObjectClass, const FString& InFieldPath, FGenericPropertyFieldKey& OutFieldKey)
{
	if (!SessionCore.IsValid())
	{
		SessionCore = MakeShared<FGenericPropertySessionCore>(*this);
	}

	return SessionCore.IsValid() && SessionCore->ResolveField(InObjectClass, InFieldPath, OutFieldKey);
}

bool UGenericPropertyProxy::ResolveFieldForTargets(const FString& InFieldPath, FGenericPropertyFieldKey& OutFieldKey)
{
	OutFieldKey = FGenericPropertyFieldKey();

	for (const TWeakObjectPtr<UObject>& Target : Targets)
	{
		if (Target.IsValid() && ResolveField(Target->GetClass(), InFieldPath, OutFieldKey))
		{
			return true;
		}
	}

	return false;
}

UGenericPropertyValueHandleBase* UGenericPropertyProxy::CreateValueHandleForProperty(UGenericProperty* InProperty)
{
	if (InProperty == nullptr)
	{
		return nullptr;
	}

	if (!SessionCore.IsValid())
	{
		SessionCore = MakeShared<FGenericPropertySessionCore>(*this);
	}

	return SessionCore.IsValid() ? SessionCore->CreateValueHandle(InProperty) : nullptr;
}

UGenericPropertyValueHandleBase* UGenericPropertyProxy::CreateValueHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	if (!SessionCore.IsValid())
	{
		SessionCore = MakeShared<FGenericPropertySessionCore>(*this);
	}

	return SessionCore.IsValid() ? SessionCore->CreateValueHandle(InFieldKey) : nullptr;
}

UGenericPropertyValueHandleBase* UGenericPropertyProxy::CreateValueHandleForPath(const FString& InFieldPath)
{
	FGenericPropertyFieldKey FieldKey;
	return ResolveFieldForTargets(InFieldPath, FieldKey) ? CreateValueHandleForField(FieldKey) : nullptr;
}

UGenericPropertyBoolValueHandle* UGenericPropertyProxy::CreateBoolHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyBoolValueHandle>(*this, InFieldKey);
}

UGenericPropertyByteValueHandle* UGenericPropertyProxy::CreateByteHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyByteValueHandle>(*this, InFieldKey);
}

UGenericPropertyIntegerValueHandle* UGenericPropertyProxy::CreateIntegerHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyIntegerValueHandle>(*this, InFieldKey);
}

UGenericPropertyInteger64ValueHandle* UGenericPropertyProxy::CreateInteger64HandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyInteger64ValueHandle>(*this, InFieldKey);
}

UGenericPropertyFloatValueHandle* UGenericPropertyProxy::CreateFloatHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyFloatValueHandle>(*this, InFieldKey);
}

UGenericPropertyDoubleValueHandle* UGenericPropertyProxy::CreateDoubleHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyDoubleValueHandle>(*this, InFieldKey);
}

UGenericPropertyStringValueHandle* UGenericPropertyProxy::CreateStringHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyStringValueHandle>(*this, InFieldKey);
}

UGenericPropertyTextValueHandle* UGenericPropertyProxy::CreateTextHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyTextValueHandle>(*this, InFieldKey);
}

UGenericPropertyNameValueHandle* UGenericPropertyProxy::CreateNameHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyNameValueHandle>(*this, InFieldKey);
}

UGenericPropertyEnumValueHandle* UGenericPropertyProxy::CreateEnumHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyEnumValueHandle>(*this, InFieldKey);
}

UGenericPropertyObjectValueHandle* UGenericPropertyProxy::CreateObjectHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyObjectValueHandle>(*this, InFieldKey);
}

UGenericPropertyClassValueHandle* UGenericPropertyProxy::CreateClassHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyClassValueHandle>(*this, InFieldKey);
}

UGenericPropertySoftObjectValueHandle* UGenericPropertyProxy::CreateSoftObjectHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertySoftObjectValueHandle>(*this, InFieldKey);
}

UGenericPropertySoftClassValueHandle* UGenericPropertyProxy::CreateSoftClassHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertySoftClassValueHandle>(*this, InFieldKey);
}

UGenericPropertyStructValueHandle* UGenericPropertyProxy::CreateStructHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyStructValueHandle>(*this, InFieldKey);
}

UGenericPropertyArrayValueHandle* UGenericPropertyProxy::CreateArrayHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyArrayValueHandle>(*this, InFieldKey);
}

UGenericPropertySetValueHandle* UGenericPropertyProxy::CreateSetHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertySetValueHandle>(*this, InFieldKey);
}

UGenericPropertyMapValueHandle* UGenericPropertyProxy::CreateMapHandleForField(const FGenericPropertyFieldKey& InFieldKey)
{
	return CreateTypedHandleForField<UGenericPropertyMapValueHandle>(*this, InFieldKey);
}

void UGenericPropertyProxy::SetCollection(UGenericPropertyCollection* InCollection)
{
	Collection = InCollection;
}

void UGenericPropertyProxy::RegisterValueHandle(UGenericPropertyValueHandleBase* InValueHandle)
{
	if (InValueHandle != nullptr)
	{
		RegisteredValueHandles.AddUnique(InValueHandle);
	}
}

bool UGenericPropertyProxy::HasAnyTrackedTargets() const
{
	return !Targets.IsEmpty();
}

bool UGenericPropertyProxy::TracksTargetObject(const UObject* InObject) const
{
	if (InObject == nullptr)
	{
		return false;
	}

	for (const TWeakObjectPtr<UObject>& Target : Targets)
	{
		if (Target.Get() == InObject)
		{
			return true;
		}
	}

	return false;
}

bool UGenericPropertyProxy::HasPendingPropertyChanges() const
{
	for (const TPair<TObjectKey<UObject>, FGenericPropertyPendingTargetChanges>& Pair : PendingChangesByTarget)
	{
		if (Pair.Value.Target.IsValid() && Pair.Value.HasPendingChanges())
		{
			return true;
		}
	}

	return false;
}

bool UGenericPropertyProxy::HasAnyValidTargets() const
{
	for (const TWeakObjectPtr<UObject>& Target : Targets)
	{
		if (Target.IsValid())
		{
			return true;
		}
	}

	return false;
}

bool UGenericPropertyProxy::NotifyObjectPropertyChanged(UObject* InObject, const FName InMemberPropertyName, const FName InLeafPropertyName, const bool bStructuralChange)
{
	return ProcessObjectPropertyChanged(InObject, InMemberPropertyName, InLeafPropertyName, bStructuralChange, true);
}

bool UGenericPropertyProxy::NotifyPropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange)
{
	return ProcessPropertyPathChanged(InObject, InPropertyPath, bStructuralChange, true);
}

bool UGenericPropertyProxy::DispatchObjectPropertyChanged(UObject* InObject, const FName InMemberPropertyName, const FName InLeafPropertyName, const bool bStructuralChange)
{
	if (MutationBatchDepth > 0)
	{
		return EnqueueObjectPropertyChanged(InObject, InMemberPropertyName, InLeafPropertyName, bStructuralChange, true);
	}

	return ProcessObjectPropertyChanged(InObject, InMemberPropertyName, InLeafPropertyName, bStructuralChange, true);
}

bool UGenericPropertyProxy::DispatchPropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange)
{
	if (MutationBatchDepth > 0)
	{
		const FName RootPropertyName = ExtractTopLevelPropertyNameFromPath(InPropertyPath);
		if (RootPropertyName != NAME_None)
		{
			return EnqueueObjectPropertyChanged(InObject, RootPropertyName, RootPropertyName, bStructuralChange, true);
		}

		return EnqueuePropertyPathChanged(InObject, InPropertyPath, bStructuralChange, true);
	}

	return ProcessPropertyPathChanged(InObject, InPropertyPath, bStructuralChange, true);
}

bool UGenericPropertyProxy::QueueObjectPropertyChanged(UObject* InObject, const FName InMemberPropertyName, const FName InLeafPropertyName, const bool bStructuralChange)
{
	return EnqueueObjectPropertyChanged(InObject, InMemberPropertyName, InLeafPropertyName, bStructuralChange, false);
}

bool UGenericPropertyProxy::QueuePropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange)
{
	return EnqueuePropertyPathChanged(InObject, InPropertyPath, bStructuralChange, false);
}

void UGenericPropertyProxy::BeginMutationBatch()
{
	++MutationBatchDepth;
}

bool UGenericPropertyProxy::EndMutationBatch()
{
	if (MutationBatchDepth <= 0)
	{
		return false;
	}

	--MutationBatchDepth;
	if (MutationBatchDepth > 0)
	{
		return false;
	}

	return FlushPendingPropertyChanges();
}

bool UGenericPropertyProxy::EnqueueObjectPropertyChanged(UObject* InObject, const FName InMemberPropertyName, const FName InLeafPropertyName, const bool bStructuralChange, const bool bAllowManualSync)
{
	if (!TracksTargetObject(InObject))
	{
		return false;
	}

	if (!bAllowManualSync && Options.SyncMode == EGenericPropertySyncMode::Manual)
	{
		return false;
	}

	FGenericPropertyPendingTargetChanges& PendingChanges = PendingChangesByTarget.FindOrAdd(TObjectKey<UObject>(InObject));
	PendingChanges.Target = InObject;

	if (InMemberPropertyName == NAME_None && InLeafPropertyName == NAME_None)
	{
		PendingChanges.bRefreshWholeObject = true;
		PendingChanges.DirtyMemberProperties.Reset();
		PendingChanges.DirtyPropertyPaths.Reset();
		return true;
	}

	const FName DrivingPropertyName = InMemberPropertyName != NAME_None ? InMemberPropertyName : InLeafPropertyName;
	bool& bStoredStructuralChange = PendingChanges.DirtyMemberProperties.FindOrAdd(DrivingPropertyName);
	bStoredStructuralChange |= bStructuralChange;
	if (!PendingChanges.DirtyPropertyPaths.IsEmpty())
	{
		for (auto It = PendingChanges.DirtyPropertyPaths.CreateIterator(); It; ++It)
		{
			if (ExtractTopLevelPropertyNameFromPath(It.Key()) == DrivingPropertyName)
			{
				It.RemoveCurrent();
			}
		}
	}

	return true;
}

bool UGenericPropertyProxy::EnqueuePropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange, const bool bAllowManualSync)
{
	if (!TracksTargetObject(InObject))
	{
		return false;
	}

	if (!bAllowManualSync && Options.SyncMode == EGenericPropertySyncMode::Manual)
	{
		return false;
	}

	FGenericPropertyPendingTargetChanges& PendingChanges = PendingChangesByTarget.FindOrAdd(TObjectKey<UObject>(InObject));
	PendingChanges.Target = InObject;

	const FString TrimmedPath = InPropertyPath.TrimStartAndEnd();
	if (TrimmedPath.IsEmpty())
	{
		PendingChanges.bRefreshWholeObject = true;
		PendingChanges.DirtyMemberProperties.Reset();
		PendingChanges.DirtyPropertyPaths.Reset();
		return true;
	}

	const FName RootPropertyName = ExtractTopLevelPropertyNameFromPath(TrimmedPath);
	if (RootPropertyName != NAME_None)
	{
		if (bool* bExistingStructuralChange = PendingChanges.DirtyMemberProperties.Find(RootPropertyName))
		{
			*bExistingStructuralChange |= bStructuralChange;
			return true;
		}
	}

	for (auto It = PendingChanges.DirtyPropertyPaths.CreateIterator(); It; ++It)
	{
		if (IsPropertyPathPrefix(It.Key(), TrimmedPath))
		{
			It.Value() |= bStructuralChange;
			return true;
		}

		if (IsPropertyPathPrefix(TrimmedPath, It.Key()))
		{
			It.RemoveCurrent();
		}
	}

	bool& bStoredStructuralChange = PendingChanges.DirtyPropertyPaths.FindOrAdd(TrimmedPath);
	bStoredStructuralChange |= bStructuralChange;
	return true;
}

bool UGenericPropertyProxy::FlushPendingPropertyChanges()
{
	if (PendingChangesByTarget.IsEmpty())
	{
		return false;
	}

	for (const TPair<TObjectKey<UObject>, FGenericPropertyPendingTargetChanges>& Pair : PendingChangesByTarget)
	{
		if (Pair.Value.Target.IsValid() && Pair.Value.bRefreshWholeObject)
		{
			Refresh();
			return true;
		}
	}

	bool bAnyNodeChanged = false;
	for (const TPair<TObjectKey<UObject>, FGenericPropertyPendingTargetChanges>& Pair : PendingChangesByTarget)
	{
		const FGenericPropertyPendingTargetChanges& PendingChanges = Pair.Value;
		UObject* TargetObject = PendingChanges.Target.Get();
		if (TargetObject == nullptr)
		{
			continue;
		}

		for (const TPair<FName, bool>& DirtyMember : PendingChanges.DirtyMemberProperties)
		{
			bAnyNodeChanged |= ProcessObjectPropertyChanged(TargetObject, DirtyMember.Key, DirtyMember.Key, DirtyMember.Value, false);
		}

		for (const TPair<FString, bool>& DirtyPath : PendingChanges.DirtyPropertyPaths)
		{
			bAnyNodeChanged |= ProcessPropertyPathChanged(TargetObject, DirtyPath.Key, DirtyPath.Value, false);
		}
	}

	ClearPendingPropertyChanges();
	if (bAnyNodeChanged && Collection != nullptr)
	{
		Collection->RefreshPresentation();
	}

	LastRefreshTimeSeconds = FPlatformTime::Seconds();
	return bAnyNodeChanged;
}

void UGenericPropertyProxy::ClearPendingPropertyChanges()
{
	PendingChangesByTarget.Reset();
}

bool UGenericPropertyProxy::ProcessObjectPropertyChanged(UObject* InObject, const FName InMemberPropertyName, const FName InLeafPropertyName, const bool bStructuralChange, const bool bRefreshPresentation)
{
	if (!TracksTargetObject(InObject))
	{
		return false;
	}

	if (InMemberPropertyName == NAME_None && InLeafPropertyName == NAME_None)
	{
		Refresh();
		return true;
	}

	EnsureNodeLookupCaches();

	TArray<UGenericProperty*> CandidateNodes;
	const FName DrivingPropertyName = InMemberPropertyName != NAME_None ? InMemberPropertyName : InLeafPropertyName;
	if (const TArray<TWeakObjectPtr<UGenericProperty>>* IndexedNodes = NodesByTopLevelProperty.Find(DrivingPropertyName))
	{
		for (const TWeakObjectPtr<UGenericProperty>& IndexedNode : *IndexedNodes)
		{
			if (UGenericProperty* Node = IndexedNode.Get())
			{
				CandidateNodes.Add(Node);
			}
		}
	}

	if (const TArray<TWeakObjectPtr<UGenericProperty>>* IndexedNodes = NodesByEditConditionDependency.Find(DrivingPropertyName))
	{
		for (const TWeakObjectPtr<UGenericProperty>& IndexedNode : *IndexedNodes)
		{
			if (UGenericProperty* Node = IndexedNode.Get())
			{
				CandidateNodes.Add(Node);
			}
		}
	}

	if (CandidateNodes.IsEmpty())
	{
		return false;
	}

	TSet<const UGenericProperty*> UniqueNodes;
	for (UGenericProperty* Node : CandidateNodes)
	{
		if (Node != nullptr)
		{
			UniqueNodes.Add(Node);
		}
	}

	bool bAnyNodeChanged = false;
	for (UGenericProperty* Node : CandidateNodes)
	{
		if (Node == nullptr || !UniqueNodes.Contains(Node) || HasSelectedAncestor(Node, UniqueNodes))
		{
			continue;
		}

		UGenericProperty* RefreshNode = Node;
		if (bStructuralChange && Node->ParentNode != nullptr && Node->ContainerElementIndex != INDEX_NONE)
		{
			RefreshNode = Node->ParentNode;
		}

		bAnyNodeChanged |= RefreshNode->RefreshFromSource();
	}

	if (bAnyNodeChanged && Collection != nullptr && bRefreshPresentation)
	{
		Collection->RefreshPresentation();
	}

	LastRefreshTimeSeconds = FPlatformTime::Seconds();
	return bAnyNodeChanged;
}

bool UGenericPropertyProxy::ProcessPropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange, const bool bRefreshPresentation)
{
	if (!TracksTargetObject(InObject))
	{
		return false;
	}

	const FString TrimmedPath = InPropertyPath.TrimStartAndEnd();
	if (TrimmedPath.IsEmpty())
	{
		Refresh();
		return true;
	}

	EnsureNodeLookupCaches();

	TArray<UGenericProperty*> CandidateNodes;
	const FName RootPropertyName = ExtractTopLevelPropertyNameFromPath(TrimmedPath);
	if (const TWeakObjectPtr<UGenericProperty>* ExactNode = NodesByExactPropertyPath.Find(TrimmedPath))
	{
		if (UGenericProperty* Node = ExactNode->Get())
		{
			CandidateNodes.Add(Node);
		}
	}

	for (FString ParentPath = GetParentPropertyPath(TrimmedPath); CandidateNodes.IsEmpty() && !ParentPath.IsEmpty(); ParentPath = GetParentPropertyPath(ParentPath))
	{
		if (const TWeakObjectPtr<UGenericProperty>* ParentNode = NodesByExactPropertyPath.Find(ParentPath))
		{
			if (UGenericProperty* Node = ParentNode->Get())
			{
				CandidateNodes.Add(Node);
				break;
			}
		}
	}

	if (RootPropertyName != NAME_None)
	{
		if (const TArray<TWeakObjectPtr<UGenericProperty>>* IndexedNodes = NodesByEditConditionDependency.Find(RootPropertyName))
		{
			for (const TWeakObjectPtr<UGenericProperty>& IndexedNode : *IndexedNodes)
			{
				if (UGenericProperty* Node = IndexedNode.Get())
				{
					CandidateNodes.Add(Node);
				}
			}
		}
	}

	if (CandidateNodes.IsEmpty())
	{
		return ProcessObjectPropertyChanged(InObject, RootPropertyName, RootPropertyName, bStructuralChange, bRefreshPresentation);
	}

	TSet<const UGenericProperty*> UniqueNodes;
	for (UGenericProperty* Node : CandidateNodes)
	{
		if (Node != nullptr)
		{
			UniqueNodes.Add(Node);
		}
	}

	bool bAnyNodeChanged = false;
	for (UGenericProperty* Node : CandidateNodes)
	{
		if (Node == nullptr || !UniqueNodes.Contains(Node) || HasSelectedAncestor(Node, UniqueNodes))
		{
			continue;
		}

		UGenericProperty* RefreshNode = Node;
		if (bStructuralChange && Node->ParentNode != nullptr)
		{
			RefreshNode = Node->ParentNode;
		}

		bAnyNodeChanged |= RefreshNode->RefreshFromSource();
	}

	if (bAnyNodeChanged && Collection != nullptr && bRefreshPresentation)
	{
		Collection->RefreshPresentation();
	}

	LastRefreshTimeSeconds = FPlatformTime::Seconds();
	return bAnyNodeChanged;
}

bool UGenericPropertyProxy::ShouldAutoRefresh(const double InCurrentTimeSeconds) const
{
	if (!bInitialized || DataSource == nullptr || Targets.IsEmpty())
	{
		return false;
	}

	switch (Options.SyncMode)
	{
	case EGenericPropertySyncMode::Manual:
		return false;

	case EGenericPropertySyncMode::Immediate:
		return Options.ImmediateFallbackIntervalSeconds > 0.0f
			&& InCurrentTimeSeconds - LastRefreshTimeSeconds >= FMath::Max<double>(Options.ImmediateFallbackIntervalSeconds, 0.01);

	case EGenericPropertySyncMode::Deferred:
		return InCurrentTimeSeconds - LastRefreshTimeSeconds >= FMath::Max<double>(Options.DeferredSyncIntervalSeconds, 0.01);
	}

	return false;
}

void UGenericPropertyProxy::InvalidateNodeLookupCaches()
{
	bNodeLookupDirty = true;
}

void UGenericPropertyProxy::EnsureNodeLookupCaches()
{
	if (!bNodeLookupDirty)
	{
		return;
	}

	NodesByTopLevelProperty.Reset();
	NodesByEditConditionDependency.Reset();
	NodesByExactPropertyPath.Reset();

	for (UGenericProperty* RootNode : RootNodes)
	{
		if (RootNode != nullptr)
		{
			IndexNodeRecursive(*RootNode, NodesByTopLevelProperty, NodesByEditConditionDependency, NodesByExactPropertyPath);
		}
	}

	bNodeLookupDirty = false;
}
