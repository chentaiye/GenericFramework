// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_ConstructObjectFromClass.h"
#include "K2Node_CreateGenericWidget.generated.h"

class UEdGraphPin;

/** Creates a GenericWidget and registers it into a GameplayUI slot. */
UCLASS(MinimalAPI)
class UK2Node_CreateGenericWidget : public UK2Node_ConstructObjectFromClass
{
	GENERATED_BODY()

public:
	UK2Node_CreateGenericWidget(const FObjectInitializer& ObjectInitializer);

public:
	virtual void AllocateDefaultPins() override;
	virtual void ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual FText GetMenuCategory() const override;
	virtual FName GetCornerIcon() const override;
	virtual FString GetPinMetaData(FName InPinName, FName InKey) override;

protected:
	virtual FText GetBaseNodeTitle() const override;
	virtual FText GetNodeTitleFormat() const override;
	virtual UClass* GetClassPinBaseClass() const override;
	virtual bool IsSpawnVarPin(UEdGraphPin* Pin) const override;

private:
	UEdGraphPin* GetPlayerControllerPin() const;
	UEdGraphPin* GetSlotTagPin() const;
	UEdGraphPin* GetVisibilityPin() const;
};
