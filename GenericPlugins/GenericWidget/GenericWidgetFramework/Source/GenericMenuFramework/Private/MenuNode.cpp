// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/MenuNode.h"

UMenuNode::UMenuNode()
{
	EnsureNodeGuid();
}

bool UMenuNode::IsRootNode() const
{
	return Parent == nullptr;
}

void UMenuNode::EnsureNodeGuid()
{
	if (!NodeGuid.IsValid())
	{
		NodeGuid = FGuid::NewGuid();
	}
}

void UMenuNode::SetParent(UMenuNode* InParent)
{
	Parent = InParent;
}

void UMenuNode::AddChild(UMenuNode* InChild)
{
	if (InChild)
	{
		Children.AddUnique(InChild);
	}
}

void UMenuNode::InsertChild(UMenuNode* InChild, int32 InChildIndex)
{
	if (!InChild)
	{
		return;
	}

	Children.Remove(InChild);
	Children.Insert(InChild, FMath::Clamp(InChildIndex, 0, Children.Num()));
}

void UMenuNode::RemoveChild(UMenuNode* InChild)
{
	Children.Remove(InChild);
}

void UMenuNode::PostLoad()
{
	Super::PostLoad();

	EnsureNodeGuid();
}
