// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "MenuGraphNode.generated.h"

class UMenuNode;

/** Editor graph node that visualizes one runtime menu node. */
UCLASS()
class GENERICMENUEDFRAMEWORK_API UMenuGraphNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	static const FName Pin_Parent;
	static const FName Pin_Child;
	static const FName Pin_ChildAdd;
	static const FName PinCategory_Menu;

	static FName MakeChildPinName(int32 InChildIndex);
	static bool IsChildPin(const UEdGraphPin* InPin);
	static bool IsAddChildPin(const UEdGraphPin* InPin);
	static int32 GetChildPinIndex(const UEdGraphPin* InPin);

	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual bool CanUserDeleteNode() const override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditUndo() override;
#endif

	UEdGraphPin* GetParentPin() const;
	UEdGraphPin* GetChildPin(int32 InChildIndex) const;
	UEdGraphPin* GetAddChildPin() const;
	bool IsRootGraphNode() const;
	void SyncPositionToMenuNode() const;

public:
	/** Runtime menu node represented by this editor node. */
	UPROPERTY()
	TObjectPtr<UMenuNode> MenuNode = nullptr;
};
