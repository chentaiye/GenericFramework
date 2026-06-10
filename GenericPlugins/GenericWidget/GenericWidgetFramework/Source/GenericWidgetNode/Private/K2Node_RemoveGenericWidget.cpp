// Copyright ChenTaiye 2025. All Rights Reserved.

#include "K2Node_RemoveGenericWidget.h"

#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "BPFunctions/BPFunctions_Widget.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraphSchema_K2.h"
#include "EditorCategoryUtils.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "K2Node_CallFunction.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"
#include "KismetCompiler.h"
#include "ScopedTransaction.h"
#include "Styling/AppStyle.h"
#include "ToolMenu.h"
#include "ToolMenuSection.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(K2Node_RemoveGenericWidget)

#define LOCTEXT_NAMESPACE "K2Node_RemoveGenericWidget"

namespace
{
	static const FName Pin_PlayerController(TEXT("PlayerController"));

	static const FName Unregister_FunctionName = GET_FUNCTION_NAME_CHECKED(UBPFunctions_Widget, UnregisterWidgetBySlotTag);
	static const FName Unregister_PlayerController(TEXT("PlayerController"));
	static const FName Unregister_InSlotTag(TEXT("InSlotTag"));
	static const FName Unregister_bClearSlot(TEXT("bClearSlot"));

	void CopyPinLinksOrDefaults(const UEdGraphSchema_K2* Schema, UEdGraphPin* SourcePin, UEdGraphPin* TargetPin)
	{
		if (!SourcePin || !TargetPin)
		{
			return;
		}

		if (SourcePin->LinkedTo.Num() > 0)
		{
			for (UEdGraphPin* LinkedPin : SourcePin->LinkedTo)
			{
				Schema->TryCreateConnection(LinkedPin, TargetPin);
			}
		}
		else
		{
			TargetPin->DefaultObject = SourcePin->DefaultObject;
			TargetPin->DefaultValue = SourcePin->DefaultValue;
			TargetPin->DefaultTextValue = SourcePin->DefaultTextValue;
		}
	}
}

void UK2Node_RemoveGenericWidget::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute);
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);

	UEdGraphPin* PlayerControllerPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, APlayerController::StaticClass(), Pin_PlayerController);
	PlayerControllerPin->PinToolTip = TEXT("Player controller that owns the GenericWidget subsystem.");

	NumSlotTagPins = FMath::Max(1, NumSlotTagPins);
	for (int32 Index = 0; Index < NumSlotTagPins; ++Index)
	{
		CreateSlotTagPin(Index);
	}

	Super::AllocateDefaultPins();
}

FText UK2Node_RemoveGenericWidget::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("NodeTitle", "Remove Generic Widget");
}

FText UK2Node_RemoveGenericWidget::GetTooltipText() const
{
	return LOCTEXT("NodeTooltip", "Unregisters GenericWidgets from one or more GameplayUI slots.");
}

FSlateIcon UK2Node_RemoveGenericWidget::GetIconAndTint(FLinearColor& OutColor) const
{
	static FSlateIcon Icon(FAppStyle::GetAppStyleSetName(), "GraphEditor.Function_16x");
	return Icon;
}

void UK2Node_RemoveGenericWidget::ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	check(Schema);

	const TArray<UEdGraphPin*> SlotTagPins = GetSlotTagPins();
	if (SlotTagPins.Num() == 0)
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("MissingSlotPins_Error", "RemoveGenericWidget node @@ must have at least one SlotTag pin.").ToString(), this);
		BreakAllNodeLinks();
		return;
	}

	UEdGraphPin* PreviousThenPin = nullptr;

	for (int32 Index = 0; Index < SlotTagPins.Num(); ++Index)
	{
		UK2Node_CallFunction* CallUnregisterNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
		CallUnregisterNode->FunctionReference.SetExternalMember(Unregister_FunctionName, UBPFunctions_Widget::StaticClass());
		CallUnregisterNode->AllocateDefaultPins();

		if (Index == 0)
		{
			CompilerContext.MovePinLinksToIntermediate(*GetExecPin(), *CallUnregisterNode->GetExecPin());
		}
		else if (PreviousThenPin)
		{
			Schema->TryCreateConnection(PreviousThenPin, CallUnregisterNode->GetExecPin());
		}

		CopyPinLinksOrDefaults(Schema, GetPlayerControllerPin(), CallUnregisterNode->FindPinChecked(Unregister_PlayerController));
		CopyPinLinksOrDefaults(Schema, SlotTagPins[Index], CallUnregisterNode->FindPinChecked(Unregister_InSlotTag));
		CallUnregisterNode->FindPinChecked(Unregister_bClearSlot)->DefaultValue = TEXT("true");

		PreviousThenPin = CallUnregisterNode->GetThenPin();
	}

	if (PreviousThenPin)
	{
		CompilerContext.MovePinLinksToIntermediate(*GetThenPin(), *PreviousThenPin);
	}

	BreakAllNodeLinks();
}

void UK2Node_RemoveGenericWidget::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	UClass* ActionKey = GetClass();
	if (ActionRegistrar.IsOpenForRegistration(ActionKey))
	{
		UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
		check(NodeSpawner);
		ActionRegistrar.AddBlueprintAction(ActionKey, NodeSpawner);
	}
}

FText UK2Node_RemoveGenericWidget::GetMenuCategory() const
{
	return FEditorCategoryUtils::GetCommonCategory(FCommonEditorCategory::UserInterface);
}

void UK2Node_RemoveGenericWidget::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	Super::GetNodeContextMenuActions(Menu, Context);

	if (Context->bIsDebugging)
	{
		return;
	}

	FToolMenuSection& Section = Menu->AddSection(TEXT("GenericWidget"), LOCTEXT("GenericWidgetSection", "Generic Widget"));

	if (Context->Pin && CanRemovePin(Context->Pin))
	{
		Section.AddMenuEntry(
			TEXT("RemoveSlotTagPin"),
			LOCTEXT("RemoveSlotTagPin", "Remove SlotTag pin"),
			LOCTEXT("RemoveSlotTagPinTooltip", "Remove this SlotTag input pin."),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateUObject(const_cast<UK2Node_RemoveGenericWidget*>(this), &UK2Node_RemoveGenericWidget::RemoveInputPin, const_cast<UEdGraphPin*>(Context->Pin)))
		);
	}
	else if (!Context->Pin && CanAddPin())
	{
		Section.AddMenuEntry(
			TEXT("AddSlotTagPin"),
			LOCTEXT("AddSlotTagPin", "Add SlotTag pin"),
			LOCTEXT("AddSlotTagPinTooltip", "Add another SlotTag input pin."),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateUObject(const_cast<UK2Node_RemoveGenericWidget*>(this), &UK2Node_RemoveGenericWidget::AddInputPin))
		);
	}
}

FString UK2Node_RemoveGenericWidget::GetPinMetaData(FName InPinName, FName InKey)
{
	if (IsSlotTagPinName(InPinName) && InKey == TEXT("Categories"))
	{
		return TEXT("GameplayUI.Slot");
	}

	return Super::GetPinMetaData(InPinName, InKey);
}

void UK2Node_RemoveGenericWidget::AddInputPin()
{
	if (!CanAddPin())
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("AddSlotTagPinTransaction", "Add SlotTag Pin"));
	Modify();

	CreateSlotTagPin(NumSlotTagPins);
	++NumSlotTagPins;

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GetBlueprint());
}

bool UK2Node_RemoveGenericWidget::CanAddPin() const
{
	return NumSlotTagPins < IK2Node_AddPinInterface::GetMaxInputPinsNum();
}

void UK2Node_RemoveGenericWidget::RemoveInputPin(UEdGraphPin* Pin)
{
	if (!CanRemovePin(Pin))
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("RemoveSlotTagPinTransaction", "Remove SlotTag Pin"));
	Modify();

	if (RemovePin(Pin))
	{
		--NumSlotTagPins;

		int32 SlotIndex = 0;
		for (UEdGraphPin* LocalPin : Pins)
		{
			if (LocalPin && IsSlotTagPinName(LocalPin->PinName))
			{
				LocalPin->Modify();
				LocalPin->PinName = MakeSlotTagPinName(SlotIndex);
				LocalPin->PinFriendlyName = FText::Format(LOCTEXT("SlotTagPinFriendlyName", "SlotTag {0}"), FText::AsNumber(SlotIndex));
				++SlotIndex;
			}
		}

		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GetBlueprint());
	}
}

bool UK2Node_RemoveGenericWidget::CanRemovePin(const UEdGraphPin* Pin) const
{
	return NumSlotTagPins > 1 && Pin && IsSlotTagPinName(Pin->PinName);
}

FName UK2Node_RemoveGenericWidget::MakeSlotTagPinName(int32 PinIndex)
{
	return *FString::Printf(TEXT("SlotTag_%d"), PinIndex);
}

bool UK2Node_RemoveGenericWidget::IsSlotTagPinName(FName PinName)
{
	return PinName.ToString().StartsWith(TEXT("SlotTag_"));
}

UEdGraphPin* UK2Node_RemoveGenericWidget::CreateSlotTagPin(int32 PinIndex)
{
	UEdGraphPin* SlotTagPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Struct, FGameplayTag::StaticStruct(), MakeSlotTagPinName(PinIndex));
	SlotTagPin->PinFriendlyName = FText::Format(LOCTEXT("SlotTagPinFriendlyName", "SlotTag {0}"), FText::AsNumber(PinIndex));
	SlotTagPin->PinToolTip = TEXT("GameplayUI.Slot tag to remove.");
	return SlotTagPin;
}

UEdGraphPin* UK2Node_RemoveGenericWidget::GetPlayerControllerPin() const
{
	return FindPin(Pin_PlayerController);
}

TArray<UEdGraphPin*> UK2Node_RemoveGenericWidget::GetSlotTagPins() const
{
	TArray<UEdGraphPin*> SlotTagPins;

	for (UEdGraphPin* Pin : Pins)
	{
		if (Pin && Pin->Direction == EGPD_Input && IsSlotTagPinName(Pin->PinName))
		{
			SlotTagPins.Add(Pin);
		}
	}

	return SlotTagPins;
}

#undef LOCTEXT_NAMESPACE
