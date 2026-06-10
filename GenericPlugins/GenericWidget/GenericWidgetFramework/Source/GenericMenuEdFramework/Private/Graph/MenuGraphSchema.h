// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "Templates/SubclassOf.h"
#include "MenuGraphSchema.generated.h"

class UMenuGraphNode;
class UMenuNode;

USTRUCT()
struct FMenuGraphSchemaAction_NewNode : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY()

	FMenuGraphSchemaAction_NewNode();
	FMenuGraphSchemaAction_NewNode(FText InNodeCategory, FText InMenuDesc, FText InToolTip, int32 InGrouping, int32 InChildIndex, TSubclassOf<UMenuNode> InNodeClass);
	virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2f& Location, bool bSelectNewNode = true) override;

	int32 ChildIndex = INDEX_NONE;
	UPROPERTY()
	TSubclassOf<UMenuNode> NodeClass;
};

/** Schema controlling menu tree graph connections and node creation. */
UCLASS()
class GENERICMENUEDFRAMEWORK_API UMenuGraphSchema : public UEdGraphSchema
{
	GENERATED_BODY()

public:
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
	virtual bool TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const override;
	virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override;

private:
	static bool NormalizePins(const UEdGraphPin* A, const UEdGraphPin* B, const UEdGraphPin*& OutOutputPin, const UEdGraphPin*& OutInputPin);
	static int32 GetTargetChildIndex(const UMenuGraphNode* InSourceGraphNode, const UEdGraphPin* InOutputPin);
};
