// Copyright ChenTaiye 2025. All Rights Reserved.

#include "K2Node_CreateGenericWidget.h"

#include "Base/GenericWidget.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "BPFunctions/BPFunctions_Widget.h"
#include "Components/SlateWrapperTypes.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraphSchema_K2.h"
#include "EditorCategoryUtils.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "K2Node_CallFunction.h"
#include "Kismet/KismetMathLibrary.h"
#include "KismetCompiler.h"
#include "KismetCompilerMisc.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(K2Node_CreateGenericWidget)

#define LOCTEXT_NAMESPACE "K2Node_CreateGenericWidget"

namespace
{
	static const FName Pin_PlayerController(TEXT("PlayerController"));
	static const FName Pin_SlotTag(TEXT("SlotTag"));
	static const FName Pin_Visibility(TEXT("InVisibility"));

	static const FName Create_FunctionName = GET_FUNCTION_NAME_CHECKED(UWidgetBlueprintLibrary, Create);
	static const FName Register_FunctionName = GET_FUNCTION_NAME_CHECKED(UBPFunctions_Widget, RegisterWidget);
	static const FName SelectObject_FunctionName = GET_FUNCTION_NAME_CHECKED(UKismetMathLibrary, SelectObject);

	static const FName Create_WorldContextObject(TEXT("WorldContextObject"));
	static const FName Create_WidgetType(TEXT("WidgetType"));
	static const FName Create_OwningPlayer(TEXT("OwningPlayer"));

	static const FName Register_PlayerController(TEXT("PlayerController"));
	static const FName Register_InWidget(TEXT("InWidget"));
	static const FName Register_InSlotTag(TEXT("InSlotTag"));
	static const FName Register_InVisibility(TEXT("InVisibility"));

	static const FName Select_A(TEXT("A"));
	static const FName Select_B(TEXT("B"));
	static const FName Select_bSelectA(TEXT("bSelectA"));

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

UK2Node_CreateGenericWidget::UK2Node_CreateGenericWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NodeTooltip = LOCTEXT("NodeTooltip", "Creates a GenericWidget and registers it into a GameplayUI slot.");
}

void UK2Node_CreateGenericWidget::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	UEdGraphPin* PlayerControllerPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, APlayerController::StaticClass(), Pin_PlayerController);
	SetPinToolTip(*PlayerControllerPin, LOCTEXT("PlayerControllerPinTooltip", "The player controller that owns the created widget."));

	UEdGraphPin* SlotTagPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Struct, FGameplayTag::StaticStruct(), Pin_SlotTag);
	SetPinToolTip(*SlotTagPin, LOCTEXT("SlotTagPinTooltip", "GameplayUI.Slot tag that receives the created widget."));

	UEdGraphPin* VisibilityPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Byte, StaticEnum<ESlateVisibility>(), Pin_Visibility);
	VisibilityPin->DefaultValue = StaticEnum<ESlateVisibility>()->GetNameStringByValue(static_cast<int64>(ESlateVisibility::SelfHitTestInvisible));
	SetPinToolTip(*VisibilityPin, LOCTEXT("VisibilityPinTooltip", "Initial visibility applied before the widget is registered into the slot."));
}

void UK2Node_CreateGenericWidget::ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	check(Schema);

	UEdGraphPin* SpawnNodeExec = GetExecPin();
	UEdGraphPin* SpawnWorldContextPin = GetWorldContextPin();
	UEdGraphPin* SpawnClassPin = GetClassPin();
	UEdGraphPin* SpawnNodeThen = GetThenPin();
	UEdGraphPin* SpawnNodeResult = GetResultPin();
	UEdGraphPin* SpawnPlayerControllerPin = GetPlayerControllerPin();
	UEdGraphPin* SpawnSlotTagPin = GetSlotTagPin();
	UEdGraphPin* SpawnVisibilityPin = GetVisibilityPin();

	UClass* SpawnClass = SpawnClassPin ? Cast<UClass>(SpawnClassPin->DefaultObject) : nullptr;
	if (!SpawnClassPin || (SpawnClassPin->LinkedTo.Num() == 0 && !SpawnClass))
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("MissingClass_Error", "CreateGenericWidget node @@ must have a widget class specified.").ToString(), this);
		BreakAllNodeLinks();
		return;
	}

	UClass* ClassToSpawn = GetClassToSpawn();

	UK2Node_CallFunction* CallCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallCreateNode->FunctionReference.SetExternalMember(Create_FunctionName, UWidgetBlueprintLibrary::StaticClass());
	CallCreateNode->AllocateDefaultPins();

	UEdGraphPin* CallCreateExec = CallCreateNode->GetExecPin();
	UEdGraphPin* CallCreateThen = CallCreateNode->GetThenPin();
	UEdGraphPin* CallCreateWorldContextPin = CallCreateNode->FindPinChecked(Create_WorldContextObject);
	UEdGraphPin* CallCreateWidgetTypePin = CallCreateNode->FindPinChecked(Create_WidgetType);
	UEdGraphPin* CallCreateOwningPlayerPin = CallCreateNode->FindPinChecked(Create_OwningPlayer);
	UEdGraphPin* CallCreateResultPin = CallCreateNode->GetReturnValuePin();
	CallCreateResultPin->PinType = SpawnNodeResult->PinType;

	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeExec, *CallCreateExec);
	CopyPinLinksOrDefaults(Schema, SpawnClassPin, CallCreateWidgetTypePin);
	CopyPinLinksOrDefaults(Schema, SpawnPlayerControllerPin, CallCreateOwningPlayerPin);

	if (SpawnWorldContextPin)
	{
		CopyPinLinksOrDefaults(Schema, SpawnWorldContextPin, CallCreateWorldContextPin);
	}

	UEdGraphPin* LastThen = FKismetCompilerUtilities::GenerateAssignmentNodes(CompilerContext, SourceGraph, CallCreateNode, this, CallCreateResultPin, ClassToSpawn, CallCreateWidgetTypePin);

	UK2Node_CallFunction* CallRegisterNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallRegisterNode->FunctionReference.SetExternalMember(Register_FunctionName, UBPFunctions_Widget::StaticClass());
	CallRegisterNode->AllocateDefaultPins();

	Schema->TryCreateConnection(LastThen ? LastThen : CallCreateThen, CallRegisterNode->GetExecPin());
	CopyPinLinksOrDefaults(Schema, SpawnPlayerControllerPin, CallRegisterNode->FindPinChecked(Register_PlayerController));
	CopyPinLinksOrDefaults(Schema, SpawnSlotTagPin, CallRegisterNode->FindPinChecked(Register_InSlotTag));
	CopyPinLinksOrDefaults(Schema, SpawnVisibilityPin, CallRegisterNode->FindPinChecked(Register_InVisibility));
	Schema->TryCreateConnection(CallCreateResultPin, CallRegisterNode->FindPinChecked(Register_InWidget));

	UK2Node_CallFunction* SelectResultNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	SelectResultNode->FunctionReference.SetExternalMember(SelectObject_FunctionName, UKismetMathLibrary::StaticClass());
	SelectResultNode->AllocateDefaultPins();

	UEdGraphPin* SelectAPin = SelectResultNode->FindPinChecked(Select_A);
	UEdGraphPin* SelectBPin = SelectResultNode->FindPinChecked(Select_B);
	UEdGraphPin* SelectReturnPin = SelectResultNode->GetReturnValuePin();
	SelectAPin->PinType = SpawnNodeResult->PinType;
	SelectBPin->PinType = SpawnNodeResult->PinType;
	SelectReturnPin->PinType = SpawnNodeResult->PinType;

	Schema->TryCreateConnection(CallCreateResultPin, SelectAPin);
	Schema->TryCreateConnection(CallRegisterNode->GetReturnValuePin(), SelectResultNode->FindPinChecked(Select_bSelectA));

	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeResult, *SelectReturnPin);
	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeThen, *CallRegisterNode->GetThenPin());

	BreakAllNodeLinks();
}

FText UK2Node_CreateGenericWidget::GetMenuCategory() const
{
	return FEditorCategoryUtils::GetCommonCategory(FCommonEditorCategory::UserInterface);
}

FName UK2Node_CreateGenericWidget::GetCornerIcon() const
{
	return TEXT("Graph.Replication.ClientEvent");
}

FString UK2Node_CreateGenericWidget::GetPinMetaData(FName InPinName, FName InKey)
{
	if (InPinName == Pin_SlotTag && InKey == TEXT("Categories"))
	{
		return TEXT("GameplayUI.Slot");
	}

	return Super::GetPinMetaData(InPinName, InKey);
}

FText UK2Node_CreateGenericWidget::GetBaseNodeTitle() const
{
	return LOCTEXT("BaseNodeTitle", "Create Generic Widget");
}

FText UK2Node_CreateGenericWidget::GetNodeTitleFormat() const
{
	return LOCTEXT("NodeTitleFormat", "Create {ClassName} Generic Widget");
}

UClass* UK2Node_CreateGenericWidget::GetClassPinBaseClass() const
{
	return UGenericWidget::StaticClass();
}

bool UK2Node_CreateGenericWidget::IsSpawnVarPin(UEdGraphPin* Pin) const
{
	return Super::IsSpawnVarPin(Pin)
		&& Pin->PinName != Pin_PlayerController
		&& Pin->PinName != Pin_SlotTag
		&& Pin->PinName != Pin_Visibility;
}

UEdGraphPin* UK2Node_CreateGenericWidget::GetPlayerControllerPin() const
{
	return FindPin(Pin_PlayerController);
}

UEdGraphPin* UK2Node_CreateGenericWidget::GetSlotTagPin() const
{
	return FindPin(Pin_SlotTag);
}

UEdGraphPin* UK2Node_CreateGenericWidget::GetVisibilityPin() const
{
	return FindPin(Pin_Visibility);
}

#undef LOCTEXT_NAMESPACE
