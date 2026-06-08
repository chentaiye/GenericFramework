// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Graph/MenuGraphSchema.h"

#include "Graph/MenuGraph.h"
#include "Graph/MenuGraphNode.h"
#include "Base/MenuAsset.h"
#include "Base/MenuNode.h"
#include "Node/RootMenuDataNode.h"
#include "UObject/UObjectIterator.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "MenuGraphSchema"

FMenuGraphSchemaAction_NewNode::FMenuGraphSchemaAction_NewNode()
	: FEdGraphSchemaAction()
{
}

FMenuGraphSchemaAction_NewNode::FMenuGraphSchemaAction_NewNode(FText InNodeCategory, FText InMenuDesc, FText InToolTip, int32 InGrouping, int32 InChildIndex, TSubclassOf<UMenuNode> InNodeClass)
	: FEdGraphSchemaAction(MoveTemp(InNodeCategory), MoveTemp(InMenuDesc), MoveTemp(InToolTip), InGrouping)
	  , ChildIndex(InChildIndex)
	  , NodeClass(InNodeClass)
{
}

UEdGraphNode* FMenuGraphSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2f& Location, bool bSelectNewNode)
{
	UMenuGraph* MenuGraph = Cast<UMenuGraph>(ParentGraph);
	UMenuGraphNode* SourceGraphNode = FromPin ? Cast<UMenuGraphNode>(FromPin->GetOwningNode()) : nullptr;

	if (!MenuGraph || !MenuGraph->MenuAsset || !SourceGraphNode || !SourceGraphNode->MenuNode)
	{
		return nullptr;
	}

	const FScopedTransaction Transaction(LOCTEXT("CreateMenuNode", "Create Menu Node"));
	MenuGraph->SyncNodePositionsToAsset();
	MenuGraph->MenuAsset->Modify();

	const int32 TargetChildIndex = ChildIndex == INDEX_NONE ? SourceGraphNode->MenuNode->Children.Num() : ChildIndex;
	UMenuNode* NewMenuNode = MenuGraph->MenuAsset->CreateChildNodeAtIndex(SourceGraphNode->MenuNode, NodeClass, TargetChildIndex, FVector2D(Location));

	if (!NewMenuNode)
	{
		return nullptr;
	}

	MenuGraph->RebuildGraph();
	UMenuGraphNode* NewGraphNode = MenuGraph->FindGraphNode(NewMenuNode);
	if (bSelectNewNode && NewGraphNode)
	{
		TSet<const UEdGraphNode*> NodeSelection;
		NodeSelection.Add(NewGraphNode);
		MenuGraph->SelectNodeSet(MoveTemp(NodeSelection), true);
	}

	return NewGraphNode;
}

void UMenuGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	const UEdGraphPin* FromPin = ContextMenuBuilder.FromPin;
	const UMenuGraphNode* SourceGraphNode = FromPin ? Cast<UMenuGraphNode>(FromPin->GetOwningNode()) : nullptr;

	if (!FromPin || FromPin->Direction != EGPD_Output || !SourceGraphNode)
	{
		return;
	}

	if (UMenuGraphNode::IsAddChildPin(FromPin))
	{
		for (TObjectIterator<UClass> ClassIt; ClassIt; ++ClassIt)
		{
			UClass* NodeClass = *ClassIt;
			if (!NodeClass
				|| NodeClass == UMenuNode::StaticClass()
				|| !NodeClass->IsChildOf(UMenuNode::StaticClass())
				|| NodeClass->IsChildOf(URootMenuDataNode::StaticClass())
				|| NodeClass->HasAnyClassFlags(CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists))
			{
				continue;
			}

			const FString NodeClassName = NodeClass->GetName();
			ContextMenuBuilder.AddAction(MakeShared<FMenuGraphSchemaAction_NewNode>(
				LOCTEXT("MenuNodeCategory", "Menu"),
				FText::FromString(FString::Printf(TEXT("Add %s"), *NodeClassName)),
				FText::Format(LOCTEXT("AddTypedNodeTooltip", "Create a {0} under this menu node."), FText::FromString(NodeClassName)),
				0,
				SourceGraphNode->MenuNode ? SourceGraphNode->MenuNode->Children.Num() : INDEX_NONE,
				NodeClass));
		}
	}
}

const FPinConnectionResponse UMenuGraphSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
	const UEdGraphPin* OutputPin = nullptr;
	const UEdGraphPin* InputPin = nullptr;

	if (!NormalizePins(A, B, OutputPin, InputPin))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Menu links require one output pin and one input pin."));
	}

	const UMenuGraphNode* SourceGraphNode = OutputPin ? Cast<UMenuGraphNode>(OutputPin->GetOwningNode()) : nullptr;
	const UMenuGraphNode* TargetGraphNode = InputPin ? Cast<UMenuGraphNode>(InputPin->GetOwningNode()) : nullptr;
	const UMenuGraph* MenuGraph = SourceGraphNode ? Cast<UMenuGraph>(SourceGraphNode->GetGraph()) : nullptr;

	if (!SourceGraphNode || !TargetGraphNode || !MenuGraph || !MenuGraph->MenuAsset)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Invalid menu graph nodes."));
	}

	if (TargetGraphNode->IsRootGraphNode())
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Root cannot be reparented."));
	}

	if (!MenuGraph->MenuAsset->CanReparentNode(TargetGraphNode->MenuNode, SourceGraphNode->MenuNode))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("This connection would break the menu tree."));
	}

	return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT(""));
}

bool UMenuGraphSchema::TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const
{
	const UEdGraphPin* ConstOutputPin = nullptr;
	const UEdGraphPin* ConstInputPin = nullptr;

	if (!NormalizePins(A, B, ConstOutputPin, ConstInputPin))
	{
		return false;
	}

	UEdGraphPin* OutputPin = const_cast<UEdGraphPin*>(ConstOutputPin);
	UEdGraphPin* InputPin = const_cast<UEdGraphPin*>(ConstInputPin);
	UMenuGraphNode* SourceGraphNode = OutputPin ? Cast<UMenuGraphNode>(OutputPin->GetOwningNode()) : nullptr;
	UMenuGraphNode* TargetGraphNode = InputPin ? Cast<UMenuGraphNode>(InputPin->GetOwningNode()) : nullptr;
	UMenuGraph* MenuGraph = SourceGraphNode ? Cast<UMenuGraph>(SourceGraphNode->GetGraph()) : nullptr;

	if (!SourceGraphNode || !TargetGraphNode || !MenuGraph || !MenuGraph->MenuAsset)
	{
		return false;
	}

	if (!MenuGraph->MenuAsset->CanReparentNode(TargetGraphNode->MenuNode, SourceGraphNode->MenuNode))
	{
		return false;
	}

	const FScopedTransaction Transaction(LOCTEXT("ReparentMenuNode", "Reparent Menu Node"));
	MenuGraph->SyncNodePositionsToAsset();
	MenuGraph->MenuAsset->Modify();

	if (!MenuGraph->MenuAsset->ReparentNodeAtIndex(TargetGraphNode->MenuNode, SourceGraphNode->MenuNode, GetTargetChildIndex(SourceGraphNode, OutputPin)))
	{
		return false;
	}

	MenuGraph->RebuildGraph();
	return true;
}

FLinearColor UMenuGraphSchema::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
	return FLinearColor(0.25f, 0.55f, 1.0f);
}

bool UMenuGraphSchema::NormalizePins(const UEdGraphPin* A, const UEdGraphPin* B, const UEdGraphPin*& OutOutputPin, const UEdGraphPin*& OutInputPin)
{
	OutOutputPin = nullptr;
	OutInputPin = nullptr;

	if (!A || !B || A == B || A->Direction == B->Direction)
	{
		return false;
	}

	OutOutputPin = A->Direction == EGPD_Output ? A : B;
	OutInputPin = A->Direction == EGPD_Input ? A : B;

	if (!OutOutputPin || !OutInputPin)
	{
		return false;
	}

	return OutOutputPin->PinType.PinCategory == UMenuGraphNode::PinCategory_Menu
		&& OutInputPin->PinType.PinCategory == UMenuGraphNode::PinCategory_Menu
		&& OutInputPin->PinName == UMenuGraphNode::Pin_Parent
		&& (UMenuGraphNode::IsChildPin(OutOutputPin) || UMenuGraphNode::IsAddChildPin(OutOutputPin));
}

int32 UMenuGraphSchema::GetTargetChildIndex(const UMenuGraphNode* InSourceGraphNode, const UEdGraphPin* InOutputPin)
{
	if (!InSourceGraphNode || !InSourceGraphNode->MenuNode || !InOutputPin)
	{
		return INDEX_NONE;
	}

	if (UMenuGraphNode::IsAddChildPin(InOutputPin))
	{
		return InSourceGraphNode->MenuNode->Children.Num();
	}

	return UMenuGraphNode::GetChildPinIndex(InOutputPin);
}

#undef LOCTEXT_NAMESPACE
