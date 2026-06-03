// Copyright ChenTaiye 2025. All Rights Reserved.

#include "K2Node_GameplayUIAction.h"

#include "Base/GenericActionWidget.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraphSchema_K2.h"
#include "EditorCategoryUtils.h"
#include "Engine/Blueprint.h"
#include "GraphEditorSettings.h"
#include "K2Node_CustomEvent.h"
#include "K2Node_SwitchEnum.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"
#include "KismetCompiler.h"
#include "Misc/EngineVersionComparison.h"
#include "Styling/AppStyle.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(K2Node_GameplayUIAction)

#define LOCTEXT_NAMESPACE "K2Node_GameplayUIAction"

namespace
{
	static const FName Pin_Triggered(TEXT("Triggered"));
	static const FName Pin_Started(TEXT("Started"));
	static const FName Pin_Ongoing(TEXT("Ongoing"));
	static const FName Pin_Canceled(TEXT("Canceled"));
	static const FName Pin_Completed(TEXT("Completed"));
	static const FName Pin_ActionValue(TEXT("Action Value"));
	static const FName Pin_ElapsedSeconds(TEXT("Elapsed Seconds"));
	static const FName Pin_TriggeredSeconds(TEXT("Triggered Seconds"));
	static const FName Pin_ActionTag(TEXT("Action Tag"));
	static const FName Pin_Key(TEXT("Key"));

	static const FName EventPin_TriggerEvent(TEXT("TriggerEvent"));
	static const FName EventPin_ActionTag(TEXT("ActionTag"));
	static const FName EventPin_Key(TEXT("Key"));
	static const FName EventPin_ActionValue(TEXT("ActionValue"));
	static const FName EventPin_ElapsedTime(TEXT("ElapsedTime"));
	static const FName EventPin_TriggeredTime(TEXT("TriggeredTime"));

	FName GetPhasePinName(EGenericActionTriggerEvent TriggerEvent)
	{
		switch (TriggerEvent)
		{
		case EGenericActionTriggerEvent::Triggered:
			return Pin_Triggered;
		case EGenericActionTriggerEvent::Started:
			return Pin_Started;
		case EGenericActionTriggerEvent::Ongoing:
			return Pin_Ongoing;
		case EGenericActionTriggerEvent::Canceled:
			return Pin_Canceled;
		case EGenericActionTriggerEvent::Completed:
			return Pin_Completed;
		default:
			return NAME_None;
		}
	}

	TArray<EGenericActionTriggerEvent, TInlineAllocator<5>> GetOrderedTriggerEvents()
	{
		return
		{
			EGenericActionTriggerEvent::Triggered,
			EGenericActionTriggerEvent::Started,
			EGenericActionTriggerEvent::Ongoing,
			EGenericActionTriggerEvent::Canceled,
			EGenericActionTriggerEvent::Completed
		};
	}

	FEdGraphPinType MakeStructPinType(UScriptStruct* InStruct)
	{
		FEdGraphPinType PinType;
		PinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
		PinType.PinSubCategoryObject = InStruct;
		return PinType;
	}

	FEdGraphPinType MakeEnumPinType()
	{
		FEdGraphPinType PinType;
		PinType.PinCategory = UEdGraphSchema_K2::PC_Byte;
		PinType.PinSubCategoryObject = StaticEnum<EGenericActionTriggerEvent>();
		return PinType;
	}

	FEdGraphPinType MakeRealPinType()
	{
		FEdGraphPinType PinType;
		PinType.PinCategory = UEdGraphSchema_K2::PC_Real;
		PinType.PinSubCategory = UEdGraphSchema_K2::PC_Float;
		return PinType;
	}

	FGameplayTag GetGenericActionRootTag()
	{
		return FGameplayTag::RequestGameplayTag(TEXT("GameplayUI.Action"), false);
	}

	FString SanitizeActionTag(FGameplayTag InActionTag)
	{
		FString SanitizedTag = InActionTag.ToString();
		for (TCHAR& Character : SanitizedTag)
		{
			if (!FChar::IsAlnum(Character) && Character != TEXT('_'))
			{
				Character = TEXT('_');
			}
		}

		return SanitizedTag;
	}

	void AddEventDataPins(UK2Node_CustomEvent* CustomEventNode)
	{
		CustomEventNode->CreateUserDefinedPin(EventPin_TriggerEvent, MakeEnumPinType(), EGPD_Output);
		CustomEventNode->CreateUserDefinedPin(EventPin_ActionTag, MakeStructPinType(FGameplayTag::StaticStruct()), EGPD_Output);
		CustomEventNode->CreateUserDefinedPin(EventPin_Key, MakeStructPinType(FKey::StaticStruct()), EGPD_Output);
		CustomEventNode->CreateUserDefinedPin(EventPin_ActionValue, MakeRealPinType(), EGPD_Output);
		CustomEventNode->CreateUserDefinedPin(EventPin_ElapsedTime, MakeRealPinType(), EGPD_Output);
		CustomEventNode->CreateUserDefinedPin(EventPin_TriggeredTime, MakeRealPinType(), EGPD_Output);
	}

	UEdGraphPin* FindSwitchCasePin(UK2Node_SwitchEnum* SwitchNode, EGenericActionTriggerEvent TriggerEvent)
	{
		if (!SwitchNode)
		{
			return nullptr;
		}

		return SwitchNode->FindPin(GetPhasePinName(TriggerEvent));
	}

	bool IsNodeInBlueprintUbergraph(const UK2Node_GameplayUIAction* Node, const UBlueprint* Blueprint)
	{
		const UEdGraph* NodeGraph = Node ? Node->GetGraph() : nullptr;
		if (!NodeGraph || !Blueprint)
		{
			return false;
		}

		for (const UEdGraph* UbergraphPage : Blueprint->UbergraphPages)
		{
			if (NodeGraph == UbergraphPage)
			{
				return true;
			}
		}

		return false;
	}

	void GetGameplayUIActionNodesFromUbergraphs(const UBlueprint* Blueprint, TArray<const UK2Node_GameplayUIAction*>& OutNodes)
	{
		if (!Blueprint)
		{
			return;
		}

		for (const UEdGraph* UbergraphPage : Blueprint->UbergraphPages)
		{
			if (!UbergraphPage)
			{
				continue;
			}

			for (const UEdGraphNode* GraphNode : UbergraphPage->Nodes)
			{
				if (const UK2Node_GameplayUIAction* ActionNode = Cast<UK2Node_GameplayUIAction>(GraphNode))
				{
					OutNodes.Add(ActionNode);
				}
			}
		}
	}
}

void UK2Node_GameplayUIAction::AllocateDefaultPins()
{
	InitializeActionTagFromBlueprintDefault();

	UEdGraphPin* TriggeredPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, Pin_Triggered);
	TriggeredPin->PinToolTip = TEXT("Executes when the action trigger reports Triggered.");
	UEdGraphPin* StartedPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, Pin_Started);
	StartedPin->PinToolTip = TEXT("Executes when the action moves from inactive to active.");
	UEdGraphPin* OngoingPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, Pin_Ongoing);
	OngoingPin->PinToolTip = TEXT("Executes while the action is active but not yet triggered.");
	UEdGraphPin* CanceledPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, Pin_Canceled);
	CanceledPin->PinToolTip = TEXT("Executes when an ongoing action is released before triggering.");
	UEdGraphPin* CompletedPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, Pin_Completed);
	CompletedPin->PinToolTip = TEXT("Executes when a triggered action finishes.");

	UEdGraphPin* ActionValuePin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Real, UEdGraphSchema_K2::PC_Float, Pin_ActionValue);
	ActionValuePin->PinToolTip = TEXT("Float value for the key or touch input. Digital keys use 1.0 when pressed and 0.0 when released.");
	UEdGraphPin* ElapsedSecondsPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Real, UEdGraphSchema_K2::PC_Float, Pin_ElapsedSeconds);
	ElapsedSecondsPin->PinToolTip = TEXT("Seconds elapsed since the current input became active.");
	UEdGraphPin* TriggeredSecondsPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Real, UEdGraphSchema_K2::PC_Float, Pin_TriggeredSeconds);
	TriggeredSecondsPin->PinToolTip = TEXT("Seconds elapsed while the current input has been triggered.");
	UEdGraphPin* ActionTagPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Struct, FGameplayTag::StaticStruct(), Pin_ActionTag);
	ActionTagPin->PinToolTip = TEXT("GameplayUI.Action tag that produced this event.");
	UEdGraphPin* KeyPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Struct, FKey::StaticStruct(), Pin_Key);
	KeyPin->PinToolTip = TEXT("Physical key or touch key that produced this event.");

	Super::AllocateDefaultPins();
}

FLinearColor UK2Node_GameplayUIAction::GetNodeTitleColor() const
{
	return GetDefault<UGraphEditorSettings>()->EventNodeTitleColor;
}

FText UK2Node_GameplayUIAction::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (CachedNodeTitle.IsOutOfDate(this))
	{
		const FString ActionTagText = ActionTag.IsValid() ? SanitizeActionTag(ActionTag) : FString(TEXT("unset"));
		CachedNodeTitle.SetCachedText(FText::Format(LOCTEXT("NodeTitle", "GameplayUIAction {0}"), FText::FromString(ActionTagText)), this);
	}

	return CachedNodeTitle;
}

FText UK2Node_GameplayUIAction::GetTooltipText() const
{
	if (CachedTooltip.IsOutOfDate(this))
	{
		CachedTooltip.SetCachedText(LOCTEXT("NodeTooltip", "Dispatches the owning GenericActionWidget default ActionTag, or the explicitly selected GameplayUI.Action tag, into Enhanced Input style phase outputs."), this);
	}

	return CachedTooltip;
}

FSlateIcon UK2Node_GameplayUIAction::GetIconAndTint(FLinearColor& OutColor) const
{
	static FSlateIcon Icon(FAppStyle::GetAppStyleSetName(), "GraphEditor.Event_16x");
	return Icon;
}

bool UK2Node_GameplayUIAction::IsCompatibleWithGraph(const UEdGraph* Graph) const
{
	if (!Graph || !Super::IsCompatibleWithGraph(Graph))
	{
		return false;
	}

	const UEdGraphSchema_K2* K2Schema = Cast<UEdGraphSchema_K2>(Graph->GetSchema());
	const bool bIsConstructionScript = K2Schema ? UEdGraphSchema_K2::IsConstructionScript(Graph) : false;
	return Graph->GetSchema()->GetGraphType(Graph) == EGraphType::GT_Ubergraph && !bIsConstructionScript && IsActionWidgetBlueprint(Graph);
}

void UK2Node_GameplayUIAction::ValidateNodeDuringCompilation(FCompilerResultsLog& MessageLog) const
{
	Super::ValidateNodeDuringCompilation(MessageLog);

	if (!IsValidActionTag(ActionTag))
	{
		MessageLog.Error(*LOCTEXT("InvalidActionTag", "GameplayUIAction requires an ActionTag under GameplayUI.Action for @@").ToString(), this);
		return;
	}

	UBlueprint* Blueprint = GetBlueprint();
	if (!Blueprint || !Blueprint->ParentClass || !Blueprint->ParentClass->IsChildOf(UGenericActionWidget::StaticClass()))
	{
		MessageLog.Error(*LOCTEXT("InvalidBlueprintClass", "GameplayUIAction can only be used in GenericActionWidget Blueprints for @@").ToString(), this);
		return;
	}

	if (!IsNodeInBlueprintUbergraph(this, Blueprint))
	{
		return;
	}

	TArray<const UK2Node_GameplayUIAction*> Nodes;
	GetGameplayUIActionNodesFromUbergraphs(Blueprint, Nodes);
	for (const UK2Node_GameplayUIAction* Node : Nodes)
	{
		if (Node && Node != this && Node->NodeGuid != NodeGuid && Node->ActionTag.IsValid() && Node->ActionTag.MatchesTagExact(ActionTag))
		{
			MessageLog.Error(*FText::Format(LOCTEXT("DuplicateActionTag", "Duplicate GameplayUIAction node for ActionTag {0} in @@"), FText::FromString(ActionTag.ToString())).ToString(), this);
			break;
		}
	}
}

void UK2Node_GameplayUIAction::ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	if (!ActionTag.IsValid())
	{
		BreakAllNodeLinks();
		return;
	}

	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	check(Schema);

	bool bHasLinkedPhasePin = false;
	for (EGenericActionTriggerEvent TriggerEvent : GetOrderedTriggerEvents())
	{
		const UEdGraphPin* PhasePin = GetPhasePin(TriggerEvent);
		if (PhasePin && PhasePin->LinkedTo.Num() > 0)
		{
			bHasLinkedPhasePin = true;
			break;
		}
	}

	if (!bHasLinkedPhasePin)
	{
		BreakAllNodeLinks();
		return;
	}

	UK2Node_CustomEvent* CustomEventNode = CompilerContext.SpawnIntermediateNode<UK2Node_CustomEvent>(this, SourceGraph);
	CustomEventNode->CustomFunctionName = UGenericActionWidget::MakeActionTagEventFunctionName(ActionTag);
	CustomEventNode->bInternalEvent = true;
	CustomEventNode->AllocateDefaultPins();
	AddEventDataPins(CustomEventNode);

	UK2Node_SwitchEnum* SwitchNode = CompilerContext.SpawnIntermediateNode<UK2Node_SwitchEnum>(this, SourceGraph);
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	SwitchNode->Enum = StaticEnum<EGenericActionTriggerEvent>();
#else
	SwitchNode->SetEnum(StaticEnum<EGenericActionTriggerEvent>());
#endif
	SwitchNode->AllocateDefaultPins();

	Schema->TryCreateConnection(CustomEventNode->FindPinChecked(UEdGraphSchema_K2::PN_Then), SwitchNode->FindPinChecked(UEdGraphSchema_K2::PN_Execute));
	Schema->TryCreateConnection(CustomEventNode->FindPinChecked(EventPin_TriggerEvent), SwitchNode->GetSelectionPin());

	for (EGenericActionTriggerEvent TriggerEvent : GetOrderedTriggerEvents())
	{
		UEdGraphPin* PhasePin = GetPhasePin(TriggerEvent);
		UEdGraphPin* SwitchCasePin = FindSwitchCasePin(SwitchNode, TriggerEvent);
		if (PhasePin && SwitchCasePin && PhasePin->LinkedTo.Num() > 0)
		{
			CompilerContext.MovePinLinksToIntermediate(*PhasePin, *SwitchCasePin);
		}
	}

	if (UEdGraphPin* Pin = GetActionValuePin())
	{
		CompilerContext.MovePinLinksToIntermediate(*Pin, *CustomEventNode->FindPinChecked(EventPin_ActionValue));
	}
	if (UEdGraphPin* Pin = GetElapsedSecondsPin())
	{
		CompilerContext.MovePinLinksToIntermediate(*Pin, *CustomEventNode->FindPinChecked(EventPin_ElapsedTime));
	}
	if (UEdGraphPin* Pin = GetTriggeredSecondsPin())
	{
		CompilerContext.MovePinLinksToIntermediate(*Pin, *CustomEventNode->FindPinChecked(EventPin_TriggeredTime));
	}
	if (UEdGraphPin* Pin = GetActionTagPin())
	{
		CompilerContext.MovePinLinksToIntermediate(*Pin, *CustomEventNode->FindPinChecked(EventPin_ActionTag));
	}
	if (UEdGraphPin* Pin = GetKeyPin())
	{
		CompilerContext.MovePinLinksToIntermediate(*Pin, *CustomEventNode->FindPinChecked(EventPin_Key));
	}

	BreakAllNodeLinks();
}

void UK2Node_GameplayUIAction::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	UClass* ActionKey = GetClass();
	if (ActionRegistrar.IsOpenForRegistration(ActionKey))
	{
		UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
		check(NodeSpawner);
		ActionRegistrar.AddBlueprintAction(ActionKey, NodeSpawner);
	}
}

FText UK2Node_GameplayUIAction::GetMenuCategory() const
{
	return FEditorCategoryUtils::BuildCategoryString(FCommonEditorCategory::Input, LOCTEXT("ActionMenuCategory", "GameplayUI Action Events"));
}

UEdGraphPin* UK2Node_GameplayUIAction::GetPhasePin(EGenericActionTriggerEvent TriggerEvent) const
{
	return FindPin(GetPhasePinName(TriggerEvent));
}

UEdGraphPin* UK2Node_GameplayUIAction::GetActionValuePin() const
{
	return FindPin(Pin_ActionValue);
}

UEdGraphPin* UK2Node_GameplayUIAction::GetElapsedSecondsPin() const
{
	return FindPin(Pin_ElapsedSeconds);
}

UEdGraphPin* UK2Node_GameplayUIAction::GetTriggeredSecondsPin() const
{
	return FindPin(Pin_TriggeredSeconds);
}

UEdGraphPin* UK2Node_GameplayUIAction::GetActionTagPin() const
{
	return FindPin(Pin_ActionTag);
}

UEdGraphPin* UK2Node_GameplayUIAction::GetKeyPin() const
{
	return FindPin(Pin_Key);
}

void UK2Node_GameplayUIAction::InitializeActionTagFromBlueprintDefault()
{
	if (ActionTag.IsValid())
	{
		return;
	}

	const UBlueprint* Blueprint = GetBlueprint();
	const UClass* GeneratedClass = Blueprint ? Blueprint->GeneratedClass : nullptr;
	const UGenericActionWidget* DefaultActionWidget = GeneratedClass ? Cast<UGenericActionWidget>(GeneratedClass->GetDefaultObject(false)) : nullptr;
	if (DefaultActionWidget && IsValidActionTag(DefaultActionWidget->ActionTag))
	{
		ActionTag = DefaultActionWidget->ActionTag;
		CachedNodeTitle.MarkDirty();
	}
}

bool UK2Node_GameplayUIAction::IsValidActionTag(FGameplayTag InActionTag) const
{
	const FGameplayTag ActionRootTag = GetGenericActionRootTag();
	return InActionTag.IsValid() && ActionRootTag.IsValid() && InActionTag.MatchesTag(ActionRootTag);
}

bool UK2Node_GameplayUIAction::IsActionWidgetBlueprint(const UEdGraph* Graph) const
{
	const UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForGraph(Graph);
	return Blueprint && Blueprint->ParentClass && Blueprint->ParentClass->IsChildOf(UGenericActionWidget::StaticClass());
}

#undef LOCTEXT_NAMESPACE
