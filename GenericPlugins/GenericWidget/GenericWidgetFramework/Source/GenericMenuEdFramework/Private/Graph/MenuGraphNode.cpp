// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Graph/MenuGraphNode.h"

#include "Base/MenuNode.h"
#include "Node/MenuDataNode.h"
#include "Node/RootMenuDataNode.h"

const FName UMenuGraphNode::Pin_Parent(TEXT("Parent"));
const FName UMenuGraphNode::Pin_Child(TEXT("Child"));
const FName UMenuGraphNode::Pin_ChildAdd(TEXT("Child +"));
const FName UMenuGraphNode::PinCategory_Menu(TEXT("Menu"));

FName UMenuGraphNode::MakeChildPinName(int32 InChildIndex)
{
	return FName(*FString::Printf(TEXT("Child %d"), InChildIndex));
}

bool UMenuGraphNode::IsChildPin(const UEdGraphPin* InPin)
{
	return GetChildPinIndex(InPin) != INDEX_NONE;
}

bool UMenuGraphNode::IsAddChildPin(const UEdGraphPin* InPin)
{
	return InPin && InPin->PinName == Pin_ChildAdd;
}

int32 UMenuGraphNode::GetChildPinIndex(const UEdGraphPin* InPin)
{
	if (!InPin)
	{
		return INDEX_NONE;
	}

	const FString PinName = InPin->PinName.ToString();
	const FString Prefix = TEXT("Child ");
	if (!PinName.StartsWith(Prefix) || PinName == Pin_ChildAdd.ToString())
	{
		return INDEX_NONE;
	}

	const FString IndexString = PinName.RightChop(Prefix.Len());
	return IndexString.IsNumeric() ? FCString::Atoi(*IndexString) : INDEX_NONE;
}

void UMenuGraphNode::AllocateDefaultPins()
{
	if (!IsRootGraphNode())
	{
		CreatePin(EGPD_Input, PinCategory_Menu, Pin_Parent);
	}

	const int32 ChildCount = MenuNode ? MenuNode->Children.Num() : 0;
	for (int32 ChildIndex = 0; ChildIndex < ChildCount; ++ChildIndex)
	{
		CreatePin(EGPD_Output, PinCategory_Menu, MakeChildPinName(ChildIndex));
	}

	CreatePin(EGPD_Output, PinCategory_Menu, Pin_ChildAdd);
}

FText UMenuGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (!MenuNode)
	{
		return INVTEXT("Invalid Menu Node");
	}

	const URootMenuDataNode* RootMenuDataNode = Cast<URootMenuDataNode>(MenuNode);
	const UMenuDataNode* MenuDataNode = Cast<UMenuDataNode>(MenuNode);
	FString MenuID = RootMenuDataNode ? RootMenuDataNode->MenuID.GetResolvedMenuID().TrimStartAndEnd() : FString();
	if (MenuID.IsEmpty())
	{
		MenuID = MenuDataNode ? MenuDataNode->MenuData.MenuID.GetResolvedMenuID().TrimStartAndEnd() : FString();
	}
	if (MenuID.IsEmpty())
	{
		MenuID = MenuNode->GetName();
	}

	FString MenuName = MenuDataNode ? MenuDataNode->MenuData.Description.PrimaryName.ToString().TrimStartAndEnd() : FString();
	if (MenuName.IsEmpty() && RootMenuDataNode)
	{
		MenuName = TEXT("Root");
	}
	if (MenuName.IsEmpty())
	{
		MenuName = TEXT("None");
	}

	return FText::FromString(FString::Printf(TEXT("MenuID : %s\nMenuName : %s"), *MenuID, *MenuName));
}

FLinearColor UMenuGraphNode::GetNodeTitleColor() const
{
	return IsRootGraphNode() ? FLinearColor(0.08f, 0.42f, 0.22f) : FLinearColor(0.1f, 0.25f, 0.55f);
}

bool UMenuGraphNode::CanUserDeleteNode() const
{
	return !IsRootGraphNode();
}

#if WITH_EDITOR
void UMenuGraphNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	SyncPositionToMenuNode();
}

void UMenuGraphNode::PostEditUndo()
{
	Super::PostEditUndo();
	SyncPositionToMenuNode();
}
#endif

UEdGraphPin* UMenuGraphNode::GetParentPin() const
{
	return FindPin(Pin_Parent, EGPD_Input);
}

UEdGraphPin* UMenuGraphNode::GetChildPin(int32 InChildIndex) const
{
	return FindPin(MakeChildPinName(InChildIndex), EGPD_Output);
}

UEdGraphPin* UMenuGraphNode::GetAddChildPin() const
{
	return FindPin(Pin_ChildAdd, EGPD_Output);
}

bool UMenuGraphNode::IsRootGraphNode() const
{
	return MenuNode && MenuNode->IsRootNode();
}

void UMenuGraphNode::SyncPositionToMenuNode() const
{
	if (MenuNode)
	{
		MenuNode->GraphPosition = FVector2D(NodePosX, NodePosY);
	}
}
