// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "Misc/EngineVersionComparison.h"
#include "MenuGraphSchema.generated.h"

class UMenuGraphNode;

USTRUCT()
struct FMenuGraphSchemaAction_NewNode : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY()

	FMenuGraphSchemaAction_NewNode();
	FMenuGraphSchemaAction_NewNode(FText InNodeCategory, FText InMenuDesc, FText InToolTip, int32 InGrouping, int32 InChildIndex);
#if UE_VERSION_OLDER_THAN(5, 6, 0)
	virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
#else
	virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2f& Location, bool bSelectNewNode = true) override;
#endif

	int32 ChildIndex = INDEX_NONE;
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
