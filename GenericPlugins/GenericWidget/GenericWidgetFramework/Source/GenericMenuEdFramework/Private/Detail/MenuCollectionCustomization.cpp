// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Detail/MenuCollectionCustomization.h"

#include "Base/MenuAsset.h"
#include "Base/MenuNode.h"
#include "Node/MenuDataNode.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "EdGraph/EdGraph.h"
#include "EdGraphSchema_K2.h"
#include "Engine/Blueprint.h"
#include "Framework/Notifications/NotificationManager.h"
#include "K2Node_CustomEvent.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "ScopedTransaction.h"
#include "PropertyHandle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "FMenuCollectionCustomization"

TSharedRef<IDetailCustomization> FMenuCollectionCustomization::MakeInstance()
{
	return MakeShared<FMenuCollectionCustomization>();
}

void FMenuCollectionCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<TWeakObjectPtr<UObject>> CustomizedObjects;
	DetailBuilder.GetObjectsBeingCustomized(CustomizedObjects);

	MenuCollection = nullptr;
	MenuCollectionBlueprint = nullptr;
	if (CustomizedObjects.Num() == 1)
	{
		MenuCollection = Cast<UMenuCollection>(CustomizedObjects[0].Get());
		if (MenuCollection.IsValid())
		{
			MenuCollectionBlueprint = UBlueprint::GetBlueprintFromClass(MenuCollection->GetClass());
		}
	}

	TSharedRef<IPropertyHandle> CollectionNameHandle = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UMenuCollection, CollectionName));
	TSharedRef<IPropertyHandle> MenuAssetHandle = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UMenuCollection, MenuAsset));
	DetailBuilder.HideProperty(CollectionNameHandle);
	DetailBuilder.HideProperty(MenuAssetHandle);

	IDetailCategoryBuilder& MenuCategory = DetailBuilder.EditCategory(TEXT("Menu"));
	MenuCategory.AddCustomRow(LOCTEXT("MenuCollectionEventButtonsFilter", "Menu Collection Events"))
	.WholeRowContent()
	[
		BuildEventButtons()
	];
	MenuCategory.AddProperty(CollectionNameHandle);
	MenuCategory.AddProperty(MenuAssetHandle);
}

TSharedRef<SWidget> FMenuCollectionCustomization::BuildEventButtons()
{
	return SNew(SVerticalBox)
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0.0f, 0.0f, 0.0f, 4.0f)
	[
		BuildEventButtonRow(EGenericButtonEvent::OnPressed, EGenericButtonEvent::OnReleased)
	]
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0.0f, 0.0f, 0.0f, 4.0f)
	[
		BuildEventButtonRow(EGenericButtonEvent::OnHovered, EGenericButtonEvent::OnUnhovered)
	]
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0.0f, 0.0f, 0.0f, 4.0f)
	[
		BuildEventButtonRow(EGenericButtonEvent::OnClicked, EGenericButtonEvent::OnDoubleClicked)
	]
	+ SVerticalBox::Slot()
	.AutoHeight()
	[
		BuildEventButtonRow(EGenericButtonEvent::OnSelected, EGenericButtonEvent::OnDeSelected)
	];
}

TSharedRef<SWidget> FMenuCollectionCustomization::BuildEventButtonRow(EGenericButtonEvent LeftEventType, EGenericButtonEvent RightEventType)
{
	return SNew(SHorizontalBox)
	+ SHorizontalBox::Slot()
	.FillWidth(0.5f)
	.Padding(0.0f, 0.0f, 6.0f, 0.0f)
	[
		BuildEventButton(LeftEventType)
	]
	+ SHorizontalBox::Slot()
	.FillWidth(0.5f)
	.Padding(6.0f, 0.0f, 0.0f, 0.0f)
	[
		BuildEventButton(RightEventType)
	];
}

TSharedRef<SWidget> FMenuCollectionCustomization::BuildEventButton(EGenericButtonEvent EventType)
{
	return SNew(SButton)
	.IsEnabled(this, &FMenuCollectionCustomization::CanGenerateEventGraph)
	.ToolTipText(this, &FMenuCollectionCustomization::GetGenerateEventGraphTooltip, EventType)
	.OnClicked(this, &FMenuCollectionCustomization::HandleGenerateEventGraphClicked, EventType)
	.HAlign(HAlign_Center)
	[
		SNew(STextBlock)
		.Text(FText::FromString(UMenuCollection::GetMenuButtonEventTypeName(EventType)))
	];
}

FReply FMenuCollectionCustomization::HandleGenerateEventGraphClicked(EGenericButtonEvent EventType)
{
	GenerateEventGraph(EventType);
	return FReply::Handled();
}

bool FMenuCollectionCustomization::CanGenerateEventGraph() const
{
	return MenuCollection.IsValid() && MenuCollectionBlueprint.IsValid();
}

FText FMenuCollectionCustomization::GetGenerateEventGraphTooltip(EGenericButtonEvent EventType) const
{
	if (!MenuCollectionBlueprint.IsValid())
	{
		return LOCTEXT("MenuCollectionEventButtonDisabledTooltip", "Only UMenuCollection Blueprint classes can generate menu event graphs.");
	}

	return FText::Format(
		LOCTEXT("MenuCollectionEventButtonTooltip", "Create or update {0}Graph for this MenuCollection Blueprint."),
		FText::FromString(UMenuCollection::GetMenuButtonEventTypeName(EventType)));
}

void FMenuCollectionCustomization::GenerateEventGraph(EGenericButtonEvent EventType)
{
	UMenuCollection* Collection = MenuCollection.Get();
	UBlueprint* Blueprint = MenuCollectionBlueprint.Get();
	if (!IsValid(Collection) || !IsValid(Blueprint))
	{
		ShowNotification(LOCTEXT("MenuCollectionNoBlueprint", "Menu event graphs can only be generated from a UMenuCollection Blueprint."), SNotificationItem::CS_Fail);
		return;
	}

	UMenuAsset* MenuAsset = Collection->MenuAsset;
	if (!IsValid(MenuAsset))
	{
		ShowNotification(LOCTEXT("MenuCollectionNoMenuAsset", "Menu event graph generation failed because MenuAsset is missing."), SNotificationItem::CS_Fail);
		return;
	}

	MenuAsset->EnsureRootNode();
	if (!IsValid(MenuAsset->RootNode))
	{
		ShowNotification(LOCTEXT("MenuCollectionNoRootNode", "Menu event graph generation failed because the MenuAsset root node is missing."), SNotificationItem::CS_Fail);
		return;
	}

	TArray<UMenuNode*> MenuNodes;
	CollectMenuNodes(MenuAsset->RootNode, MenuNodes);
	if (MenuNodes.Num() == 0)
	{
		ShowNotification(LOCTEXT("MenuCollectionNoMenuNodes", "Menu event graph generation skipped because the MenuAsset has no non-root nodes."), SNotificationItem::CS_Fail);
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("GenerateMenuCollectionEventGraph", "Generate Menu Collection Event Graph"));
	Blueprint->Modify();
	UEdGraph* EventGraph = FindOrCreateEventGraph(Blueprint, UMenuCollection::MakeMenuButtonEventGraphName(EventType));
	if (!EventGraph)
	{
		ShowNotification(LOCTEXT("MenuCollectionGraphFailed", "Menu event graph generation failed because the graph could not be created."), SNotificationItem::CS_Fail);
		return;
	}

	EventGraph->Modify();
	int32 NextNodeY = 0;
	for (UEdGraphNode* ExistingNode : EventGraph->Nodes)
	{
		if (ExistingNode)
		{
			NextNodeY = FMath::Max(NextNodeY, ExistingNode->NodePosY + 180);
		}
	}

	int32 CreatedCount = 0;
	int32 SkippedEmptyMenuIDCount = 0;
	for (UMenuNode* MenuNode : MenuNodes)
	{
		if (!IsValid(MenuNode))
		{
			continue;
		}

		const UMenuDataNode* MenuDataNode = Cast<UMenuDataNode>(MenuNode);
		const FString MenuID = MenuDataNode ? MenuDataNode->MenuData.MenuID.GetResolvedMenuID().TrimStartAndEnd() : FString();
		const FName EventName = UMenuCollection::MakeMenuButtonEventFunctionName(EventType, MenuID);
		if (EventName.IsNone())
		{
			++SkippedEmptyMenuIDCount;
			continue;
		}

		if (DoesCustomEventExist(Blueprint, EventName))
		{
			continue;
		}

		CreateCustomEventNode(EventGraph, EventName, NextNodeY);
		++CreatedCount;
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);

	if (SkippedEmptyMenuIDCount > 0)
	{
		ShowNotification(
			FText::Format(LOCTEXT("MenuCollectionGeneratedWithSkippedNodes", "Generated {0} new events. Skipped {1} nodes with empty MenuID."),
				FText::AsNumber(CreatedCount),
				FText::AsNumber(SkippedEmptyMenuIDCount)),
			SNotificationItem::CS_Success);
		return;
	}

	ShowNotification(
		FText::Format(LOCTEXT("MenuCollectionGeneratedEvents", "Generated {0} new menu events."), FText::AsNumber(CreatedCount)),
		SNotificationItem::CS_Success);
}

void FMenuCollectionCustomization::CollectMenuNodes(UMenuNode* RootNode, TArray<UMenuNode*>& OutNodes) const
{
	if (!IsValid(RootNode))
	{
		return;
	}

	for (const TObjectPtr<UMenuNode>& ChildNode : RootNode->Children)
	{
		if (!IsValid(ChildNode))
		{
			continue;
		}

		OutNodes.Add(ChildNode);
		CollectMenuNodes(ChildNode, OutNodes);
	}
}

UEdGraph* FMenuCollectionCustomization::FindOrCreateEventGraph(UBlueprint* Blueprint, FName GraphName) const
{
	if (!IsValid(Blueprint) || GraphName.IsNone())
	{
		return nullptr;
	}

	for (UEdGraph* Graph : Blueprint->UbergraphPages)
	{
		if (Graph && Graph->GetFName() == GraphName)
		{
			return Graph;
		}
	}

	UEdGraph* NewGraph = FBlueprintEditorUtils::CreateNewGraph(Blueprint, GraphName, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
	if (NewGraph)
	{
		FBlueprintEditorUtils::AddUbergraphPage(Blueprint, NewGraph);
	}
	return NewGraph;
}

bool FMenuCollectionCustomization::DoesCustomEventExist(UBlueprint* Blueprint, FName EventName) const
{
	if (!IsValid(Blueprint) || EventName.IsNone())
	{
		return false;
	}

	for (UEdGraph* Graph : Blueprint->UbergraphPages)
	{
		if (!Graph)
		{
			continue;
		}

		for (UEdGraphNode* GraphNode : Graph->Nodes)
		{
			const UK2Node_CustomEvent* CustomEventNode = Cast<UK2Node_CustomEvent>(GraphNode);
			if (CustomEventNode && CustomEventNode->CustomFunctionName == EventName)
			{
				return true;
			}
		}
	}

	return false;
}

void FMenuCollectionCustomization::CreateCustomEventNode(UEdGraph* Graph, FName EventName, int32& NextNodeY) const
{
	if (!Graph || EventName.IsNone())
	{
		return;
	}

	UK2Node_CustomEvent* EventNode = NewObject<UK2Node_CustomEvent>(Graph);
	EventNode->CustomFunctionName = EventName;
	EventNode->NodePosX = 0;
	EventNode->NodePosY = NextNodeY;
	NextNodeY += 180;

	Graph->AddNode(EventNode, true, false);
	EventNode->CreateNewGuid();
	EventNode->PostPlacedNewNode();
	EventNode->AllocateDefaultPins();
}

void FMenuCollectionCustomization::ShowNotification(const FText& Message, SNotificationItem::ECompletionState CompletionState) const
{
	FNotificationInfo NotificationInfo(Message);
	NotificationInfo.ExpireDuration = 4.0f;
	NotificationInfo.bUseSuccessFailIcons = true;

	TSharedPtr<SNotificationItem> NotificationItem = FSlateNotificationManager::Get().AddNotification(NotificationInfo);
	if (NotificationItem.IsValid())
	{
		NotificationItem->SetCompletionState(CompletionState);
	}
}

#undef LOCTEXT_NAMESPACE
