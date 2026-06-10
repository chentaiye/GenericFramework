// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNodeUtils.h"
#include "GameplayTagContainer.h"
#include "Input/GenericActionInputTypes.h"
#include "K2Node.h"
#include "K2Node_GameplayUIAction.generated.h"

class FBlueprintActionDatabaseRegistrar;
class FKismetCompilerContext;
class UEdGraph;
class UEdGraphPin;

UCLASS(MinimalAPI)
class UK2Node_GameplayUIAction : public UK2Node
{
	GENERATED_BODY()

public:
	/** Gameplay UI action handled by this event node. Defaults from the owning GenericActionWidget Blueprint when possible. */
	UPROPERTY(EditAnywhere, Category="Action", meta=(Categories="GameplayUI.Action"))
	FGameplayTag ActionTag;

public:
	/** Create the visual event pins shown on the Blueprint node. */
	virtual void AllocateDefaultPins() override;

	/** Use the standard Blueprint event node color. */
	virtual FLinearColor GetNodeTitleColor() const override;

	/** Display the node as "GameplayUIAction <ActionTag>". */
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	/** Describe how this event dispatches the selected action. */
	virtual FText GetTooltipText() const override;

	/** Use the standard Blueprint event icon. */
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;

	/** Restrict this node to GenericActionWidget event graphs. */
	virtual bool IsCompatibleWithGraph(const UEdGraph* Graph) const override;

	virtual bool ShouldShowNodeProperties() const override { return true; }

	/** Validate ActionTag scope, owning Blueprint type, and duplicate ActionTag nodes. */
	virtual void ValidateNodeDuringCompilation(FCompilerResultsLog& MessageLog) const override;

	/** Expand to one hidden custom event and dispatch phase exec pins by TriggerEvent. */
	virtual void ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;

	/** Register the node in the Blueprint action menu. */
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;

	/** Group the node under input-related Blueprint actions. */
	virtual FText GetMenuCategory() const override;

private:
	/** Resolve the exec pin for a trigger phase. */
	UEdGraphPin* GetPhasePin(EGenericActionTriggerEvent TriggerEvent) const;

	/** Resolve payload pins exposed by the node. */
	UEdGraphPin* GetActionValuePin() const;
	UEdGraphPin* GetElapsedSecondsPin() const;
	UEdGraphPin* GetTriggeredSecondsPin() const;
	UEdGraphPin* GetActionTagPin() const;
	UEdGraphPin* GetKeyPin() const;

	/** Default ActionTag from the owning Blueprint CDO when this node has none. */
	void InitializeActionTagFromBlueprintDefault();

	/** Check whether a tag is under GameplayUI.Action. */
	bool IsValidActionTag(FGameplayTag InActionTag) const;

	/** Check whether the graph belongs to a GenericActionWidget Blueprint. */
	bool IsActionWidgetBlueprint(const UEdGraph* Graph) const;

private:
	FNodeTextCache CachedNodeTitle;
	FNodeTextCache CachedTooltip;
};
