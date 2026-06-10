// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"
#include "MenuGraph.generated.h"

class UMenuAsset;
class UMenuGraphNode;
class UMenuNode;

/** Transient editor graph generated from a menu asset tree. */
UCLASS()
class GENERICMENUEDFRAMEWORK_API UMenuGraph : public UEdGraph
{
	GENERATED_BODY()

public:
	void Initialize(UMenuAsset* InMenuAsset);
	void RebuildGraph();
	UMenuGraphNode* FindGraphNode(UMenuNode* InMenuNode) const;
	UMenuGraphNode* CreateGraphNode(UMenuNode* InMenuNode);
	void SyncNodePositionsToAsset() const;

public:
	/** Menu asset edited by this transient graph. */
	UPROPERTY()
	TObjectPtr<UMenuAsset> MenuAsset = nullptr;

private:
	TMap<UMenuNode*, UMenuGraphNode*> NodeMap;
};
