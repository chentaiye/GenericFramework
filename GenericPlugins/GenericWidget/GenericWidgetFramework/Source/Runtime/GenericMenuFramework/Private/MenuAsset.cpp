// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/MenuAsset.h"

#include "Base/MenuNode.h"
#include "UObject/ObjectSaveContext.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

#define LOCTEXT_NAMESPACE "MenuAsset"

UMenuAsset::UMenuAsset()
{
}

void UMenuAsset::EnsureRootNode()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}

	if (!RootNode)
	{
		RootNode = NewObject<UMenuNode>(this, NAME_None, RF_Transactional);
		RootNode->MenuData.MenuID.MenuID = TEXT("Root");
		RootNode->GraphPosition = FVector2D::ZeroVector;
	}

	RootNode->EnsureNodeGuid();
	RootNode->SetParent(nullptr);
	AllNodes.AddUnique(RootNode);
}

UMenuNode* UMenuAsset::CreateChildNode(UMenuNode* InParentNode, FVector2D InGraphPosition)
{
	return CreateNodeInternal(InParentNode, InGraphPosition, INDEX_NONE);
}

UMenuNode* UMenuAsset::CreateChildNodeAtIndex(UMenuNode* InParentNode, int32 InChildIndex, FVector2D InGraphPosition)
{
	return CreateNodeInternal(InParentNode, InGraphPosition, InChildIndex);
}

UMenuNode* UMenuAsset::CreateSiblingNode(UMenuNode* InSourceNode, FVector2D InGraphPosition)
{
	if (!InSourceNode || IsRootNode(InSourceNode))
	{
		return nullptr;
	}

	const int32 SourceIndex = InSourceNode->Parent ? InSourceNode->Parent->Children.IndexOfByKey(InSourceNode) : INDEX_NONE;
	return CreateNodeInternal(InSourceNode->Parent, InGraphPosition, SourceIndex == INDEX_NONE ? INDEX_NONE : SourceIndex + 1);
}

bool UMenuAsset::DeleteNode(UMenuNode* InNode)
{
	if (!InNode || IsRootNode(InNode) || !ContainsNode(InNode))
	{
		return false;
	}

	Modify();

	if (InNode->Parent)
	{
		InNode->Parent->Modify();
		InNode->Parent->RemoveChild(InNode);
	}

	TArray<UMenuNode*> NodesToDelete;
	CollectSubtree(InNode, NodesToDelete);

	for (UMenuNode* NodeToDelete : NodesToDelete)
	{
		if (!NodeToDelete)
		{
			continue;
		}

		NodeToDelete->Modify();
		NodeToDelete->Children.Reset();
		NodeToDelete->SetParent(nullptr);
		AllNodes.Remove(NodeToDelete);
	}

	MarkPackageDirty();
	return true;
}

bool UMenuAsset::ReparentNode(UMenuNode* InNode, UMenuNode* InNewParent)
{
	return ReparentNodeAtIndex(InNode, InNewParent, INDEX_NONE);
}

bool UMenuAsset::ReparentNodeAtIndex(UMenuNode* InNode, UMenuNode* InNewParent, int32 InChildIndex)
{
	if (!CanReparentNode(InNode, InNewParent))
	{
		return false;
	}

	Modify();
	InNode->Modify();
	InNewParent->Modify();

	if (InNode->Parent)
	{
		InNode->Parent->Modify();
		InNode->Parent->RemoveChild(InNode);
	}

	InNode->SetParent(InNewParent);
	if (InChildIndex == INDEX_NONE)
	{
		InNewParent->AddChild(InNode);
	}
	else
	{
		InNewParent->InsertChild(InNode, InChildIndex);
	}
	MarkPackageDirty();
	return true;
}

bool UMenuAsset::CanReparentNode(UMenuNode* InNode, UMenuNode* InNewParent) const
{
	if (!InNode || !InNewParent || InNode == InNewParent)
	{
		return false;
	}

	if (IsRootNode(InNode) || !ContainsNode(InNode) || !ContainsNode(InNewParent))
	{
		return false;
	}

	return !IsDescendantOf(InNewParent, InNode);
}

bool UMenuAsset::ContainsNode(UMenuNode* InNode) const
{
	return InNode && AllNodes.Contains(InNode);
}

bool UMenuAsset::IsRootNode(UMenuNode* InNode) const
{
	return InNode && InNode == RootNode;
}

bool UMenuAsset::IsDescendantOf(UMenuNode* InCandidateNode, UMenuNode* InPotentialParent) const
{
	if (!InCandidateNode || !InPotentialParent)
	{
		return false;
	}

	for (const TObjectPtr<UMenuNode>& Child : InPotentialParent->Children)
	{
		if (Child == InCandidateNode || IsDescendantOf(InCandidateNode, Child))
		{
			return true;
		}
	}

	return false;
}

void UMenuAsset::PostLoad()
{
	Super::PostLoad();

	EnsureRootNode();

	for (const TObjectPtr<UMenuNode>& Node : AllNodes)
	{
		if (Node)
		{
			Node->EnsureNodeGuid();
		}
	}
}

void UMenuAsset::PreSave(FObjectPreSaveContext SaveContext)
{
	Super::PreSave(SaveContext);

	EnsureRootNode();
}

#if WITH_EDITOR
EDataValidationResult UMenuAsset::IsDataValid(FDataValidationContext& Context) const
{
	EDataValidationResult Result = Super::IsDataValid(Context);

	if (!RootNode)
	{
		Context.AddError(LOCTEXT("MissingRootNode", "Menu asset must have a root node."));
		Result = EDataValidationResult::Invalid;
	}

	TSet<FGuid> NodeGuids;
	TSet<FString> MenuIDs;

	for (const TObjectPtr<UMenuNode>& Node : AllNodes)
	{
		if (!Node)
		{
			Context.AddError(LOCTEXT("NullNode", "Menu asset contains a null node entry."));
			Result = EDataValidationResult::Invalid;
			continue;
		}

		if (!Node->NodeGuid.IsValid())
		{
			Context.AddError(FText::Format(LOCTEXT("InvalidNodeGuid", "Menu node '{0}' has an invalid NodeGuid."), FText::FromString(Node->GetName())));
			Result = EDataValidationResult::Invalid;
		}
		else if (NodeGuids.Contains(Node->NodeGuid))
		{
			Context.AddError(FText::Format(LOCTEXT("DuplicateNodeGuid", "Menu node '{0}' has a duplicate NodeGuid."), FText::FromString(Node->GetName())));
			Result = EDataValidationResult::Invalid;
		}
		else
		{
			NodeGuids.Add(Node->NodeGuid);
		}

		if (Node != RootNode)
		{
			if (!Node->Parent)
			{
				Context.AddError(FText::Format(LOCTEXT("MissingParent", "Menu node '{0}' must have a parent."), FText::FromString(Node->GetName())));
				Result = EDataValidationResult::Invalid;
			}
			else
			{
				if (!ContainsNode(Node->Parent))
				{
					Context.AddError(FText::Format(LOCTEXT("ParentNotInAsset", "Menu node '{0}' has a parent outside this asset."), FText::FromString(Node->GetName())));
					Result = EDataValidationResult::Invalid;
				}

				if (!Node->Parent->Children.Contains(Node))
				{
					Context.AddError(FText::Format(LOCTEXT("ParentMissingChild", "Menu node '{0}' is not listed by its parent."), FText::FromString(Node->GetName())));
					Result = EDataValidationResult::Invalid;
				}
			}
		}

		for (const TObjectPtr<UMenuNode>& Child : Node->Children)
		{
			if (!Child || !ContainsNode(Child))
			{
				Context.AddError(FText::Format(LOCTEXT("ChildNotInAsset", "Menu node '{0}' references a child outside this asset."), FText::FromString(Node->GetName())));
				Result = EDataValidationResult::Invalid;
			}
			else if (Child->Parent != Node)
			{
				Context.AddError(FText::Format(LOCTEXT("ChildParentMismatch", "Menu node '{0}' has a child with mismatched parent."), FText::FromString(Node->GetName())));
				Result = EDataValidationResult::Invalid;
			}
		}

		if (Node->MenuData.IsDataValid(Context) == EDataValidationResult::Invalid)
		{
			Result = EDataValidationResult::Invalid;
		}

		const FString MenuID = Node->MenuData.MenuID.GetResolvedMenuID().TrimStartAndEnd();
		if (!MenuID.IsEmpty())
		{
			if (MenuIDs.Contains(MenuID))
			{
				Context.AddError(FText::Format(LOCTEXT("DuplicateMenuID", "MenuID '{0}' is duplicated in this menu asset."), FText::FromString(MenuID)));
				Result = EDataValidationResult::Invalid;
			}
			else
			{
				MenuIDs.Add(MenuID);
			}
		}
	}

	TSet<const UMenuNode*> Visiting;
	TSet<const UMenuNode*> Visited;
	if (RootNode && HasCycle(RootNode, Visiting, Visited))
	{
		Context.AddError(LOCTEXT("MenuTreeCycle", "Menu asset contains a cycle."));
		Result = EDataValidationResult::Invalid;
	}

	return Result;
}
#endif

UMenuNode* UMenuAsset::CreateNodeInternal(UMenuNode* InParentNode, FVector2D InGraphPosition, int32 InChildIndex)
{
	if (!InParentNode || !ContainsNode(InParentNode))
	{
		return nullptr;
	}

	Modify();
	InParentNode->Modify();

	UMenuNode* NewNode = NewObject<UMenuNode>(this, NAME_None, RF_Transactional);
	NewNode->SetParent(InParentNode);
	NewNode->GraphPosition = InGraphPosition;
	NewNode->MenuData.MenuID.MenuID = MakeUniqueMenuID(TEXT("Menu"));

	if (InChildIndex == INDEX_NONE)
	{
		InParentNode->AddChild(NewNode);
	}
	else
	{
		InParentNode->InsertChild(NewNode, InChildIndex);
	}
	AllNodes.Add(NewNode);
	MarkPackageDirty();
	return NewNode;
}

void UMenuAsset::CollectSubtree(UMenuNode* InNode, TArray<UMenuNode*>& OutNodes) const
{
	if (!InNode)
	{
		return;
	}

	OutNodes.Add(InNode);

	for (const TObjectPtr<UMenuNode>& Child : InNode->Children)
	{
		CollectSubtree(Child, OutNodes);
	}
}

bool UMenuAsset::HasCycle(UMenuNode* InNode, TSet<const UMenuNode*>& Visiting, TSet<const UMenuNode*>& Visited) const
{
	if (!InNode)
	{
		return false;
	}

	if (Visiting.Contains(InNode))
	{
		return true;
	}

	if (Visited.Contains(InNode))
	{
		return false;
	}

	Visiting.Add(InNode);

	for (const TObjectPtr<UMenuNode>& Child : InNode->Children)
	{
		if (HasCycle(Child, Visiting, Visited))
		{
			return true;
		}
	}

	Visiting.Remove(InNode);
	Visited.Add(InNode);
	return false;
}

FString UMenuAsset::MakeUniqueMenuID(const FString& InBaseMenuID) const
{
	TSet<FString> UsedIDs;

	for (const TObjectPtr<UMenuNode>& Node : AllNodes)
	{
		if (Node)
		{
			const FString ExistingID = Node->MenuData.MenuID.GetResolvedMenuID().TrimStartAndEnd();
			if (!ExistingID.IsEmpty())
			{
				UsedIDs.Add(ExistingID);
			}
		}
	}

	FString Candidate = InBaseMenuID;
	int32 Index = 1;

	while (UsedIDs.Contains(Candidate))
	{
		Candidate = FString::Printf(TEXT("%s_%d"), *InBaseMenuID, Index++);
	}

	return Candidate;
}

#undef LOCTEXT_NAMESPACE
