#include "Core/GenericPropertyCollection.h"

#include "Core/GenericProperty.h"
#include "Core/GenericPropertyCategory.h"
#include "Model/GenericPropertyProxy.h"

namespace
{
	void GatherNodeStats(UGenericProperty* InNode, int32& OutDirtyCount, int32& OutInvalidCount, int32& OutConflictCount)
	{
		if (InNode == nullptr)
		{
			return;
		}

		if (InNode->bIsDirty)
		{
			++OutDirtyCount;
		}

		if (InNode->bIsInvalid)
		{
			++OutInvalidCount;
		}

		if (InNode->bHasConflict)
		{
			++OutConflictCount;
		}

		for (UGenericProperty* Child : InNode->Children)
		{
			GatherNodeStats(Child, OutDirtyCount, OutInvalidCount, OutConflictCount);
		}
	}
}

void UGenericPropertyCollection::Initialize(UGenericPropertyProxy* InProxy)
{
	Proxy = InProxy;
	bShowAdvancedProperties = Proxy != nullptr ? Proxy->GetOptions().bShowAdvancedProperties : true;

	if (Proxy != nullptr)
	{
		Proxy->SetCollection(this);
	}

	RebuildFromProxy();
}

void UGenericPropertyCollection::RebuildFromProxy()
{
	if (Proxy == nullptr)
	{
		DirtyCount = 0;
		InvalidCount = 0;
		ConflictCount = 0;
		Categories.Reset();
		BroadcastCollectionRebuilt();
		return;
	}

	TMap<FName, UGenericPropertyCategory*> ReusableListsByCategory;
	ReusableListsByCategory.Reserve(Categories.Num());
	for (UGenericPropertyCategory* ExistingList : Categories)
	{
		if (ExistingList == nullptr)
		{
			continue;
		}

		ExistingList->Properties.Reset();
		ReusableListsByCategory.Add(ExistingList->CategoryName, ExistingList);
	}

	TMap<FName, UGenericPropertyCategory*> ListsByCategory;
	ListsByCategory.Reserve(Proxy->GetRootNodes().Num());
	Categories.Reset();
	Categories.Reserve(ReusableListsByCategory.Num());

	for (UGenericProperty* Node : Proxy->GetRootNodes())
	{
		if (Node == nullptr)
		{
			continue;
		}

		UGenericPropertyCategory*& List = ListsByCategory.FindOrAdd(Node->CategoryName);
		if (List == nullptr)
		{
			if (UGenericPropertyCategory** ExistingList = ReusableListsByCategory.Find(Node->CategoryName))
			{
				List = *ExistingList;
			}
			else
			{
				List = NewObject<UGenericPropertyCategory>(this);
				List->CategoryName = Node->CategoryName;
				List->DisplayName = FText::FromName(Node->CategoryName);
			}

			Categories.Add(List);
		}

		List->Properties.Add(Node);
	}

	RefreshPresentation();
	BroadcastCollectionRebuilt();
}

void UGenericPropertyCollection::RefreshPresentation()
{
	DirtyCount = 0;
	InvalidCount = 0;
	ConflictCount = 0;

	for (UGenericPropertyCategory* List : Categories)
	{
		if (List != nullptr)
		{
			List->Properties.RemoveAll([](const UGenericProperty* Property)
			{
				return Property == nullptr;
			});
		}
	}

	for (UGenericPropertyCategory* List : Categories)
	{
		if (List == nullptr)
		{
			continue;
		}

		for (UGenericProperty* Node : List->Properties)
		{
			if (Node == nullptr)
			{
				continue;
			}

			Node->UpdateVisibilityFromSearch(SearchText, bShowAdvancedProperties);
			GatherNodeStats(Node, DirtyCount, InvalidCount, ConflictCount);
		}
	}

	for (UGenericPropertyCategory* List : Categories)
	{
		if (List != nullptr)
		{
			List->RecalculateVisibility();
			List->BroadcastListChanged();
		}
	}

	BroadcastCollectionPresentationChanged();
}

void UGenericPropertyCollection::SetSearchText(const FString& InSearchText)
{
	SearchText = InSearchText;
	RefreshPresentation();
}

void UGenericPropertyCollection::SetShowAdvancedProperties(const bool bInShowAdvancedProperties)
{
	bShowAdvancedProperties = bInShowAdvancedProperties;
	RefreshPresentation();
}

void UGenericPropertyCollection::Refresh()
{
	if (Proxy != nullptr)
	{
		Proxy->Refresh();
	}
}

bool UGenericPropertyCollection::Apply()
{
	return Proxy != nullptr && Proxy->ApplyAll();
}

bool UGenericPropertyCollection::Reset(const EGenericPropertyResetMode InMode)
{
	return Proxy != nullptr && Proxy->ResetAll(InMode);
}

void UGenericPropertyCollection::SetTargetObject(UObject* InTarget)
{
	TArray<UObject*> Targets;
	if (InTarget != nullptr)
	{
		Targets.Add(InTarget);
	}

	SetTargetObjects(Targets);
}

void UGenericPropertyCollection::SetTargetObjects(const TArray<UObject*>& InTargets)
{
	if (Proxy != nullptr)
	{
		Proxy->SetTargets(InTargets);
	}
}

void UGenericPropertyCollection::BroadcastCollectionRebuilt()
{
	Delegate_OnCollectionRebuilt.Broadcast(this);
	BPDelegate_OnCollectionRebuilt.Broadcast(this);
}

void UGenericPropertyCollection::BroadcastCollectionPresentationChanged()
{
	Delegate_OnCollectionPresentationChanged.Broadcast(this);
	BPDelegate_OnCollectionPresentationChanged.Broadcast(this);
}
