// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"
#include "K2Node_AddPinInterface.h"
#include "K2Node_RemoveGenericWidget.generated.h"

class FBlueprintActionDatabaseRegistrar;
class FKismetCompilerContext;
class UEdGraph;
class UEdGraphPin;
class UGraphNodeContextMenuContext;
class UToolMenu;

/** Removes GenericWidgets from one or more GameplayUI slots. */
UCLASS(MinimalAPI)
class UK2Node_RemoveGenericWidget : public UK2Node, public IK2Node_AddPinInterface
{
	GENERATED_BODY()

public:
	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	virtual void ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FText GetMenuCategory() const override;
	virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;
	virtual FString GetPinMetaData(FName InPinName, FName InKey) override;

public:
	virtual void AddInputPin() override;
	virtual bool CanAddPin() const override;
	virtual void RemoveInputPin(UEdGraphPin* Pin) override;
	virtual bool CanRemovePin(const UEdGraphPin* Pin) const override;

private:
	static FName MakeSlotTagPinName(int32 PinIndex);
	static bool IsSlotTagPinName(FName PinName);
	UEdGraphPin* CreateSlotTagPin(int32 PinIndex);
	UEdGraphPin* GetPlayerControllerPin() const;
	TArray<UEdGraphPin*> GetSlotTagPins() const;

private:
	UPROPERTY()
	int32 NumSlotTagPins = 1;
};
