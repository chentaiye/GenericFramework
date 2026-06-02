// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Graph/MenuGraph.h"

#include "Graph/MenuGraphNode.h"
#include "Graph/MenuGraphSchema.h"
#include "Base/MenuAsset.h"
#include "Base/MenuNode.h"

void UMenuGraph::Initialize(UMenuAsset* InMenuAsset)
{
	MenuAsset = InMenuAsset;
	Schema = UMenuGraphSchema::StaticClass();
	RebuildGraph();
}

void UMenuGraph::RebuildGraph()
{
	Modify();
	Nodes.Reset();
	NodeMap.Reset();

	if (!MenuAsset)
	{
		return;
	}

	MenuAsset->EnsureRootNode();

	for (const TObjectPtr<UMenuNode>& MenuNode : MenuAsset->AllNodes)
	{
		if (MenuNode)
		{
			CreateGraphNode(MenuNode);
		}
	}

	for (const TObjectPtr<UMenuNode>& MenuNode : MenuAsset->AllNodes)
	{
		if (!MenuNode)
		{
			continue;
		}

		UMenuGraphNode* ParentGraphNode = FindGraphNode(MenuNode);
		if (!ParentGraphNode)
		{
			continue;
		}

		for (int32 ChildIndex = 0; ChildIndex < MenuNode->Children.Num(); ++ChildIndex)
		{
			const TObjectPtr<UMenuNode>& ChildNode = MenuNode->Children[ChildIndex];
			UMenuGraphNode* ChildGraphNode = FindGraphNode(ChildNode);
			if (ChildGraphNode && ParentGraphNode->GetChildPin(ChildIndex) && ChildGraphNode->GetParentPin())
			{
				ParentGraphNode->GetChildPin(ChildIndex)->MakeLinkTo(ChildGraphNode->GetParentPin());
			}
		}
	}

	NotifyGraphChanged();
}

UMenuGraphNode* UMenuGraph::FindGraphNode(UMenuNode* InMenuNode) const
{
	if (!InMenuNode)
	{
		return nullptr;
	}

	if (UMenuGraphNode* const* FoundNode = NodeMap.Find(InMenuNode))
	{
		return *FoundNode;
	}

	return nullptr;
}

UMenuGraphNode* UMenuGraph::CreateGraphNode(UMenuNode* InMenuNode)
{
	if (!InMenuNode)
	{
		return nullptr;
	}

	UMenuGraphNode* GraphNode = NewObject<UMenuGraphNode>(this, NAME_None, RF_Transactional);
	GraphNode->MenuNode = InMenuNode;
	GraphNode->MenuData = InMenuNode->MenuData;
	GraphNode->NodePosX = static_cast<int32>(InMenuNode->GraphPosition.X);
	GraphNode->NodePosY = static_cast<int32>(InMenuNode->GraphPosition.Y);
	GraphNode->CreateNewGuid();
	GraphNode->AllocateDefaultPins();
	AddNode(GraphNode, false, false);
	NodeMap.Add(InMenuNode, GraphNode);
	return GraphNode;
}

void UMenuGraph::SyncNodePositionsToAsset() const
{
	for (UEdGraphNode* Node : Nodes)
	{
		if (const UMenuGraphNode* MenuGraphNode = Cast<UMenuGraphNode>(Node))
		{
			MenuGraphNode->SyncPositionToMenuNode();
		}
	}
}
