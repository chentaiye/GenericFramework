// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "Base/MenuCollection.h"
#include "IDetailCustomization.h"
#include "Widgets/Notifications/SNotificationList.h"

class UBlueprint;
class UEdGraph;
class UMenuNode;

class FMenuCollectionCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	TSharedRef<SWidget> BuildEventButtons();
	TSharedRef<SWidget> BuildEventButtonRow(EGenericButtonEvent LeftEventType, EGenericButtonEvent RightEventType);
	TSharedRef<SWidget> BuildEventButton(EGenericButtonEvent EventType);
	FReply HandleGenerateEventGraphClicked(EGenericButtonEvent EventType);
	bool CanGenerateEventGraph() const;
	FText GetGenerateEventGraphTooltip(EGenericButtonEvent EventType) const;

	void GenerateEventGraph(EGenericButtonEvent EventType);
	void CollectMenuNodes(UMenuNode* RootNode, TArray<UMenuNode*>& OutNodes) const;
	UEdGraph* FindOrCreateEventGraph(UBlueprint* Blueprint, FName GraphName) const;
	bool DoesCustomEventExist(UBlueprint* Blueprint, FName EventName) const;
	void CreateCustomEventNode(UEdGraph* Graph, FName EventName, int32& NextNodeY) const;
	void ShowNotification(const FText& Message, SNotificationItem::ECompletionState CompletionState) const;

private:
	TWeakObjectPtr<UMenuCollection> MenuCollection;
	TWeakObjectPtr<UBlueprint> MenuCollectionBlueprint;
};
