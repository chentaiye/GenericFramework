// Copyright ChenTaiye 2025. All Rights Reserved.

#include "K2Node_HandleLevelStreaming.h"

#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "BPFunctions/BPFunctions_LevelStreaming.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraphSchema_K2.h"
#include "EditorCategoryUtils.h"
#include "Engine/World.h"
#include "K2Node_AssignmentStatement.h"
#include "K2Node_CallFunction.h"
#include "K2Node_CreateDelegate.h"
#include "K2Node_CustomEvent.h"
#include "K2Node_MakeArray.h"
#include "K2Node_Self.h"
#include "K2Node_TemporaryVariable.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"
#include "KismetCompiler.h"
#include "ScopedTransaction.h"
#include "Styling/AppStyle.h"
#include "ToolMenu.h"
#include "ToolMenuSection.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(K2Node_HandleLevelStreaming)

#define LOCTEXT_NAMESPACE "K2Node_HandleLevelStreaming"

namespace
{
	static const FName Pin_Levels(TEXT("Levels"));
	static const FName Pin_OnceFinish(TEXT("OnOnceFinish"));
	static const FName Pin_Finish(TEXT("OnFinish"));
	static const FName Pin_CompletedLevel(TEXT("CompletedLevel"));
	static const FName Pin_WorldContextObject(TEXT("WorldContextObject"));
	static const FName Pin_MakeVisibleAfterLoad(TEXT("bMakeVisibleAfterLoad"));
	static const FName Pin_ShouldBlockOnLoad(TEXT("bShouldBlockOnLoad"));
	static const FName Pin_ShouldBlockOnUnload(TEXT("bShouldBlockOnUnload"));
	static const FName Pin_Visible(TEXT("bVisible"));

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

	bool CopyEventSignature(UK2Node_CustomEvent* CustomEventNode, UFunction* Function, const UEdGraphSchema_K2* Schema)
	{
		check(CustomEventNode && Function && Schema);

		bool bResult = true;
		for (TFieldIterator<FProperty> PropIt(Function); PropIt && (PropIt->PropertyFlags & CPF_Parm); ++PropIt)
		{
			const FProperty* Param = *PropIt;
			if (!Param->HasAnyPropertyFlags(CPF_OutParm) || Param->HasAnyPropertyFlags(CPF_ReferenceParm))
			{
				FEdGraphPinType PinType;
				bResult &= Schema->ConvertPropertyToPinType(Param, PinType);
				bResult &= (CustomEventNode->CreateUserDefinedPin(Param->GetFName(), PinType, EGPD_Output) != nullptr);
			}
		}
		return bResult;
	}

	bool CreateDelegateForCustomEvent(UEdGraphPin* DelegateInputPin, UK2Node_CustomEvent* CustomEventNode, UK2Node* SourceNode, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext)
	{
		const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
		check(DelegateInputPin && CustomEventNode && SourceNode && SourceGraph && Schema);

		UK2Node_Self* SelfNode = CompilerContext.SpawnIntermediateNode<UK2Node_Self>(SourceNode, SourceGraph);
		SelfNode->AllocateDefaultPins();

		UK2Node_CreateDelegate* CreateDelegateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CreateDelegate>(SourceNode, SourceGraph);
		CreateDelegateNode->AllocateDefaultPins();

		bool bResult = true;
		bResult &= Schema->TryCreateConnection(DelegateInputPin, CreateDelegateNode->GetDelegateOutPin());
		bResult &= Schema->TryCreateConnection(SelfNode->FindPinChecked(UEdGraphSchema_K2::PN_Self), CreateDelegateNode->GetObjectInPin());
		CreateDelegateNode->SetFunction(CustomEventNode->GetFunctionName());
		bResult &= CopyEventSignature(CustomEventNode, CreateDelegateNode->GetDelegateSignature(), Schema);

		return bResult;
	}
}

void UK2Node_HandleLevelStreaming::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute);

	UEdGraphPin* ThenPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);
	ThenPin->PinFriendlyName = LOCTEXT("DefaultPin", "默认");

	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, Pin_OnceFinish)->PinFriendlyName = LOCTEXT("OnceFinishPin", "一次完成时");
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, Pin_Finish)->PinFriendlyName = LOCTEXT("FinishPin", "全部完成时");

	UEdGraphPin* CompletedLevelPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_SoftObject, UWorld::StaticClass(), Pin_CompletedLevel);
	CompletedLevelPin->PinFriendlyName = LOCTEXT("CompletedLevelPin", "完成的关卡");
	CompletedLevelPin->PinToolTip = TEXT("The streaming level that just finished in the Once Finish branch.");

	NumLevelPins = FMath::Max(1, NumLevelPins);
	for (int32 Index = 0; Index < NumLevelPins; ++Index)
	{
		CreateLevelPin(Index);
	}

	CreateOperationPins();

	Super::AllocateDefaultPins();
}

FText UK2Node_HandleLevelStreaming::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return GetOperationNodeTitle();
}

FText UK2Node_HandleLevelStreaming::GetTooltipText() const
{
	return GetOperationTooltip();
}

FSlateIcon UK2Node_HandleLevelStreaming::GetIconAndTint(FLinearColor& OutColor) const
{
	static FSlateIcon Icon(FAppStyle::GetAppStyleSetName(), "GraphEditor.Latent_16x");
	return Icon;
}

FText UK2Node_HandleLevelStreaming::GetMenuCategory() const
{
	return LOCTEXT("MenuCategory", "Generic Framework|Level Streaming");
}

void UK2Node_HandleLevelStreaming::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	UClass* ActionKey = GetClass();
	if (!ActionRegistrar.IsOpenForRegistration(ActionKey))
	{
		return;
	}

	struct FGenericLevelStreamingNodeAction
	{
		static UBlueprintNodeSpawner* CreateSpawner(UClass* NodeClass, ELevelStreamingK2NodeOperation InOperation, const FText& MenuName, const FText& Tooltip, const FText& Category)
		{
			UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(NodeClass);
			check(NodeSpawner);

			NodeSpawner->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateLambda([InOperation](UEdGraphNode* NewNode, bool)
			{
				UK2Node_HandleLevelStreaming* GenericLevelStreamingNode = CastChecked<UK2Node_HandleLevelStreaming>(NewNode);
				GenericLevelStreamingNode->Operation = InOperation;
			});

			NodeSpawner->DefaultMenuSignature.MenuName = MenuName;
			NodeSpawner->DefaultMenuSignature.Tooltip = Tooltip;
			NodeSpawner->DefaultMenuSignature.Category = Category;
			return NodeSpawner;
		}
	};

	const FText Category = GetMenuCategory();
	ActionRegistrar.AddBlueprintAction(ActionKey, FGenericLevelStreamingNodeAction::CreateSpawner(ActionKey, ELevelStreamingK2NodeOperation::Load, LOCTEXT("LoadMenuName", "Load Streaming Levels"), LOCTEXT("LoadMenuTooltip", "Loads one or more streaming levels and exposes per-level and final completion branches."), Category));
	ActionRegistrar.AddBlueprintAction(ActionKey, FGenericLevelStreamingNodeAction::CreateSpawner(ActionKey, ELevelStreamingK2NodeOperation::Unload, LOCTEXT("UnloadMenuName", "Unload Streaming Levels"), LOCTEXT("UnloadMenuTooltip", "Unloads one or more streaming levels and exposes per-level and final completion branches."), Category));
	ActionRegistrar.AddBlueprintAction(ActionKey, FGenericLevelStreamingNodeAction::CreateSpawner(ActionKey, ELevelStreamingK2NodeOperation::SetVisibility, LOCTEXT("VisibilityMenuName", "Set Streaming Levels Visibility"), LOCTEXT("VisibilityMenuTooltip", "Sets visibility for one or more streaming levels and exposes per-level and final completion branches."), Category));
}

void UK2Node_HandleLevelStreaming::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	Super::GetNodeContextMenuActions(Menu, Context);

	if (!Context || Context->bIsDebugging)
	{
		return;
	}

	FToolMenuSection& Section = Menu->AddSection(TEXT("LevelStreamingLevels"), LOCTEXT("LevelStreamingLevelsSection", "Level Streaming"));

	if (Context->Pin && IsLevelPinName(Context->Pin->PinName))
	{
		if (CanInsertInputPinBefore(Context->Pin))
		{
			Section.AddMenuEntry(
				TEXT("InsertLevelPin"),
				LOCTEXT("InsertLevelPin", "Insert Level pin before"),
				LOCTEXT("InsertLevelPinTooltip", "Insert a streaming level input before this pin."),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateUObject(const_cast<UK2Node_HandleLevelStreaming*>(this), &UK2Node_HandleLevelStreaming::InsertInputPinBefore, const_cast<UEdGraphPin*>(Context->Pin)))
			);
		}

		if (CanRemovePin(Context->Pin))
		{
			Section.AddMenuEntry(
				TEXT("RemoveLevelPin"),
				LOCTEXT("RemoveLevelPin", "Remove Level pin"),
				LOCTEXT("RemoveLevelPinTooltip", "Remove this streaming level input pin."),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateUObject(const_cast<UK2Node_HandleLevelStreaming*>(this), &UK2Node_HandleLevelStreaming::RemoveInputPin, const_cast<UEdGraphPin*>(Context->Pin)))
			);
		}
	}
	else if (!Context->Pin && CanAddPin())
	{
		Section.AddMenuEntry(
			TEXT("AddLevelPin"),
			LOCTEXT("AddLevelPin", "Add Level pin"),
			LOCTEXT("AddLevelPinTooltip", "Add another streaming level input pin."),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateUObject(const_cast<UK2Node_HandleLevelStreaming*>(this), &UK2Node_HandleLevelStreaming::AddInputPin))
		);
	}
}

void UK2Node_HandleLevelStreaming::ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	check(Schema);

	const TArray<UEdGraphPin*> LevelPins = GetLevelPins();
	if (LevelPins.IsEmpty())
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("MissingLevelPins_Error", "HandleLevelStreaming node @@ must have at least one Level pin.").ToString(), this);
		BreakAllNodeLinks();
		return;
	}

	UK2Node_CallFunction* CallNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallNode->FunctionReference.SetExternalMember(GetOperationFunctionName(), UBPFunctions_LevelStreaming::StaticClass());
	CallNode->AllocateDefaultPins();

	CompilerContext.MovePinLinksToIntermediate(*GetExecPin(), *CallNode->GetExecPin());
	CompilerContext.MovePinLinksToIntermediate(*GetThenPin(), *CallNode->GetThenPin());

	if (UEdGraphPin* WorldContextPin = CallNode->FindPin(Pin_WorldContextObject))
	{
		UK2Node_Self* SelfNode = CompilerContext.SpawnIntermediateNode<UK2Node_Self>(this, SourceGraph);
		SelfNode->AllocateDefaultPins();
		Schema->TryCreateConnection(WorldContextPin, SelfNode->FindPinChecked(UEdGraphSchema_K2::PN_Self));
	}

	UK2Node_MakeArray* MakeArrayNode = CompilerContext.SpawnIntermediateNode<UK2Node_MakeArray>(this, SourceGraph);
	MakeArrayNode->NumInputs = LevelPins.Num();
	MakeArrayNode->AllocateDefaultPins();
	Schema->TryCreateConnection(MakeArrayNode->GetOutputPin(), CallNode->FindPinChecked(Pin_Levels));
	MakeArrayNode->PostReconstructNode();

	for (int32 Index = 0; Index < LevelPins.Num(); ++Index)
	{
		CopyPinLinksOrDefaults(Schema, LevelPins[Index], MakeArrayNode->FindPinChecked(MakeArrayNode->GetPinName(Index)));
	}

	CopyPinLinksOrDefaults(Schema, FindPin(Pin_MakeVisibleAfterLoad), CallNode->FindPin(Pin_MakeVisibleAfterLoad));
	CopyPinLinksOrDefaults(Schema, FindPin(Pin_ShouldBlockOnLoad), CallNode->FindPin(Pin_ShouldBlockOnLoad));
	CopyPinLinksOrDefaults(Schema, FindPin(Pin_ShouldBlockOnUnload), CallNode->FindPin(Pin_ShouldBlockOnUnload));
	CopyPinLinksOrDefaults(Schema, FindPin(Pin_Visible), CallNode->FindPin(Pin_Visible));

	UK2Node_CustomEvent* OnceEventNode = CompilerContext.SpawnIntermediateNode<UK2Node_CustomEvent>(this, SourceGraph);
	OnceEventNode->CustomFunctionName = *FString::Printf(TEXT("LevelStreamingOnceFinish_%s"), *CompilerContext.GetGuid(this));
	OnceEventNode->AllocateDefaultPins();

	UK2Node_TemporaryVariable* CompletedLevelVar = CompilerContext.SpawnInternalVariable(this, UEdGraphSchema_K2::PC_SoftObject, NAME_None, UWorld::StaticClass());
	CompilerContext.MovePinLinksToIntermediate(*GetCompletedLevelPin(), *CompletedLevelVar->GetVariablePin());

	UK2Node_AssignmentStatement* AssignCompletedLevelNode = CompilerContext.SpawnIntermediateNode<UK2Node_AssignmentStatement>(this, SourceGraph);
	AssignCompletedLevelNode->AllocateDefaultPins();

	bool bIsErrorFree = true;
	bIsErrorFree &= CreateDelegateForCustomEvent(CallNode->FindPinChecked(Pin_OnceFinish), OnceEventNode, this, SourceGraph, CompilerContext);
	bIsErrorFree &= Schema->TryCreateConnection(OnceEventNode->FindPinChecked(UEdGraphSchema_K2::PN_Then), AssignCompletedLevelNode->GetExecPin());
	bIsErrorFree &= Schema->TryCreateConnection(CompletedLevelVar->GetVariablePin(), AssignCompletedLevelNode->GetVariablePin());
	AssignCompletedLevelNode->NotifyPinConnectionListChanged(AssignCompletedLevelNode->GetVariablePin());
	bIsErrorFree &= Schema->TryCreateConnection(AssignCompletedLevelNode->GetValuePin(), OnceEventNode->FindPinChecked(Pin_CompletedLevel));
	AssignCompletedLevelNode->NotifyPinConnectionListChanged(AssignCompletedLevelNode->GetValuePin());
	bIsErrorFree &= CompilerContext.MovePinLinksToIntermediate(*GetOnceFinishPin(), *AssignCompletedLevelNode->GetThenPin()).CanSafeConnect();

	UK2Node_CustomEvent* FinishEventNode = CompilerContext.SpawnIntermediateNode<UK2Node_CustomEvent>(this, SourceGraph);
	FinishEventNode->CustomFunctionName = *FString::Printf(TEXT("LevelStreamingFinish_%s"), *CompilerContext.GetGuid(this));
	FinishEventNode->AllocateDefaultPins();

	bIsErrorFree &= CreateDelegateForCustomEvent(CallNode->FindPinChecked(Pin_Finish), FinishEventNode, this, SourceGraph, CompilerContext);
	bIsErrorFree &= CompilerContext.MovePinLinksToIntermediate(*GetFinishPin(), *FinishEventNode->FindPinChecked(UEdGraphSchema_K2::PN_Then)).CanSafeConnect();

	if (!bIsErrorFree)
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("ExpandNode_Error", "HandleLevelStreaming node @@ failed to expand delegate bindings.").ToString(), this);
	}

	BreakAllNodeLinks();
}

void UK2Node_HandleLevelStreaming::AddInputPin()
{
	if (!CanAddPin())
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("AddLevelPinTransaction", "Add Level Pin"));
	Modify();

	CreateLevelPin(NumLevelPins);
	++NumLevelPins;

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GetBlueprint());
}

bool UK2Node_HandleLevelStreaming::CanAddPin() const
{
	return NumLevelPins < IK2Node_AddPinInterface::GetMaxInputPinsNum();
}

void UK2Node_HandleLevelStreaming::RemoveInputPin(UEdGraphPin* Pin)
{
	if (!CanRemovePin(Pin))
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("RemoveLevelPinTransaction", "Remove Level Pin"));
	Modify();

	Pin->BreakAllPinLinks();
	if (RemovePin(Pin))
	{
		--NumLevelPins;
		RenameLevelPinsByCurrentOrder();
		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GetBlueprint());
	}
}

bool UK2Node_HandleLevelStreaming::CanRemovePin(const UEdGraphPin* Pin) const
{
	return NumLevelPins > 1 && Pin && IsLevelPinName(Pin->PinName);
}

FName UK2Node_HandleLevelStreaming::MakeLevelPinName(int32 PinIndex)
{
	return *FString::Printf(TEXT("Level_%d"), PinIndex);
}

bool UK2Node_HandleLevelStreaming::IsLevelPinName(FName PinName)
{
	int32 UnusedIndex = INDEX_NONE;
	return TryGetLevelPinIndex(PinName, UnusedIndex);
}

bool UK2Node_HandleLevelStreaming::TryGetLevelPinIndex(FName PinName, int32& OutIndex)
{
	FString PinNameString = PinName.ToString();
	if (!PinNameString.RemoveFromStart(TEXT("Level_")))
	{
		return false;
	}

	return LexTryParseString(OutIndex, *PinNameString);
}

UEdGraphPin* UK2Node_HandleLevelStreaming::CreateLevelPin(int32 PinIndex)
{
	UEdGraphPin* LevelPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_SoftObject, UWorld::StaticClass(), MakeLevelPinName(PinIndex));
	LevelPin->PinFriendlyName = FText::Format(LOCTEXT("LevelPinFriendlyName", "Level {0}"), FText::AsNumber(PinIndex));
	LevelPin->PinToolTip = TEXT("Streaming level asset handled by this request.");
	return LevelPin;
}

UEdGraphPin* UK2Node_HandleLevelStreaming::GetThenPin() const
{
	return FindPin(UEdGraphSchema_K2::PN_Then);
}

UEdGraphPin* UK2Node_HandleLevelStreaming::GetOnceFinishPin() const
{
	return FindPin(Pin_OnceFinish);
}

UEdGraphPin* UK2Node_HandleLevelStreaming::GetFinishPin() const
{
	return FindPin(Pin_Finish);
}

UEdGraphPin* UK2Node_HandleLevelStreaming::GetCompletedLevelPin() const
{
	return FindPin(Pin_CompletedLevel);
}

TArray<UEdGraphPin*> UK2Node_HandleLevelStreaming::GetLevelPins() const
{
	TArray<UEdGraphPin*> LevelPins;
	for (UEdGraphPin* Pin : Pins)
	{
		if (Pin && Pin->Direction == EGPD_Input && IsLevelPinName(Pin->PinName))
		{
			LevelPins.Add(Pin);
		}
	}

	LevelPins.Sort([](const UEdGraphPin& Left, const UEdGraphPin& Right)
	{
		int32 LeftIndex = INDEX_NONE;
		int32 RightIndex = INDEX_NONE;
		TryGetLevelPinIndex(Left.PinName, LeftIndex);
		TryGetLevelPinIndex(Right.PinName, RightIndex);
		return LeftIndex < RightIndex;
	});

	return LevelPins;
}

void UK2Node_HandleLevelStreaming::CreateOperationPins()
{
	if (Operation == ELevelStreamingK2NodeOperation::Load)
	{
		CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Boolean, Pin_MakeVisibleAfterLoad)->PinToolTip = TEXT("Whether the level becomes visible immediately after load finishes.");
		CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Boolean, Pin_ShouldBlockOnLoad)->PinToolTip = TEXT("Whether the streaming load should block the game thread.");
	}
	else if (Operation == ELevelStreamingK2NodeOperation::Unload)
	{
		CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Boolean, Pin_ShouldBlockOnUnload)->PinToolTip = TEXT("Whether the streaming unload should block the game thread.");
	}
	else
	{
		UEdGraphPin* VisiblePin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Boolean, Pin_Visible);
		VisiblePin->DefaultValue = TEXT("true");
		VisiblePin->PinToolTip = TEXT("Target visibility state for every level handled by this node.");
	}
}

void UK2Node_HandleLevelStreaming::InsertInputPinBefore(UEdGraphPin* Pin)
{
	if (!CanInsertInputPinBefore(Pin))
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("InsertLevelPinTransaction", "Insert Level Pin"));
	Modify();

	const int32 TargetPinIndex = Pins.IndexOfByKey(Pin);
	UEdGraphPin* NewPin = CreateLevelPin(NumLevelPins);
	Pins.Remove(NewPin);
	Pins.Insert(NewPin, TargetPinIndex);
	++NumLevelPins;

	RenameLevelPinsByCurrentOrder();
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GetBlueprint());
}

bool UK2Node_HandleLevelStreaming::CanInsertInputPinBefore(const UEdGraphPin* Pin) const
{
	return CanAddPin() && Pin && IsLevelPinName(Pin->PinName);
}

void UK2Node_HandleLevelStreaming::RenameLevelPinsByCurrentOrder()
{
	int32 LevelIndex = 0;
	for (UEdGraphPin* Pin : Pins)
	{
		if (Pin && Pin->Direction == EGPD_Input && IsLevelPinName(Pin->PinName))
		{
			Pin->Modify();
			Pin->PinName = MakeLevelPinName(LevelIndex);
			Pin->PinFriendlyName = FText::Format(LOCTEXT("LevelPinFriendlyName", "Level {0}"), FText::AsNumber(LevelIndex));
			++LevelIndex;
		}
	}

	NumLevelPins = FMath::Max(1, LevelIndex);
}

FName UK2Node_HandleLevelStreaming::GetOperationFunctionName() const
{
	switch (Operation)
	{
	case ELevelStreamingK2NodeOperation::Load:
		return GET_FUNCTION_NAME_CHECKED(UBPFunctions_LevelStreaming, K2Node_LoadLevels);
	case ELevelStreamingK2NodeOperation::Unload:
		return GET_FUNCTION_NAME_CHECKED(UBPFunctions_LevelStreaming, K2Node_UnloadLevels);
	case ELevelStreamingK2NodeOperation::SetVisibility:
		return GET_FUNCTION_NAME_CHECKED(UBPFunctions_LevelStreaming, K2Node_SetLevelsVisibility);
	default:
		return GET_FUNCTION_NAME_CHECKED(UBPFunctions_LevelStreaming, K2Node_LoadLevels);
	}
}

FText UK2Node_HandleLevelStreaming::GetOperationNodeTitle() const
{
	switch (Operation)
	{
	case ELevelStreamingK2NodeOperation::Load:
		return LOCTEXT("LoadNodeTitle", "Load Streaming Levels");
	case ELevelStreamingK2NodeOperation::Unload:
		return LOCTEXT("UnloadNodeTitle", "Unload Streaming Levels");
	case ELevelStreamingK2NodeOperation::SetVisibility:
		return LOCTEXT("VisibilityNodeTitle", "Set Streaming Levels Visibility");
	default:
		return LOCTEXT("DefaultNodeTitle", "Handle Streaming Levels");
	}
}

FText UK2Node_HandleLevelStreaming::GetOperationTooltip() const
{
	switch (Operation)
	{
	case ELevelStreamingK2NodeOperation::Load:
		return LOCTEXT("LoadNodeTooltip", "Loads one or more TSoftObjectPtr<UWorld> streaming levels through GenericLevelStreamingSubsystem.");
	case ELevelStreamingK2NodeOperation::Unload:
		return LOCTEXT("UnloadNodeTooltip", "Unloads one or more TSoftObjectPtr<UWorld> streaming levels through GenericLevelStreamingSubsystem.");
	case ELevelStreamingK2NodeOperation::SetVisibility:
		return LOCTEXT("VisibilityNodeTooltip", "Sets visibility for one or more TSoftObjectPtr<UWorld> streaming levels through GenericLevelStreamingSubsystem.");
	default:
		return LOCTEXT("DefaultNodeTooltip", "Handles one or more streaming levels through GenericLevelStreamingSubsystem.");
	}
}

#undef LOCTEXT_NAMESPACE
