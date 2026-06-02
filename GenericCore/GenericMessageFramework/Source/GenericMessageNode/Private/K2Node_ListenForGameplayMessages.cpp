// Copyright Epic Games, Inc. All Rights Reserved.

#include "K2Node_ListenForGameplayMessages.h"

#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintFunctionNodeSpawner.h"
#include "EdGraph/EdGraph.h"
#include "K2Node_AssignmentStatement.h"
#include "K2Node_AsyncAction.h"
#include "K2Node_CallFunction.h"
#include "K2Node_TemporaryVariable.h"
#include "KismetCompiler.h"
#include "AsyncAction/ListenForGameplayMessagesAsyncAction.h"
#include "UObject/Class.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(K2Node_ListenForGameplayMessages)

#define LOCTEXT_NAMESPACE "GenericMessageNode"

namespace UK2Node_ListenForGameplayMessagesHelper
{
	static const FName ActualChannelPinName(TEXT("ActualChannel"));
	static const FName ChannelPinName(TEXT("Channel"));
	static const FName CategoriesMetaKey(TEXT("Categories"));
	static const FName GameplayTagFilterMetaKey(TEXT("GameplayTagFilter"));
	static const FName PayloadPinName(TEXT("Payload"));
	static const FName PayloadTypePinName(TEXT("PayloadType"));
	static const FName DelegateProxyPinName(TEXT("ProxyObject"));
	static const FString GameplayMessageChannelRoot(TEXT("GameplayMessage.Channel"));
}

void UK2Node_ListenForGameplayMessages::PostReconstructNode()
{
	Super::PostReconstructNode();

	RefreshOutputPayloadType();
}

void UK2Node_ListenForGameplayMessages::PinDefaultValueChanged(UEdGraphPin* ChangedPin)
{
	Super::PinDefaultValueChanged(ChangedPin);

	if (ChangedPin == GetPayloadTypePin())
	{
		if (ChangedPin->LinkedTo.Num() == 0)
		{
			if (RefreshOutputPayloadType())
			{
				if (UEdGraph* Graph = GetGraph())
				{
					Graph->NotifyNodeChanged(this);
				}
			}
		}
	}
}

void UK2Node_ListenForGameplayMessages::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
	Super::GetPinHoverText(Pin, HoverTextOut);
	if (Pin.PinName == UK2Node_ListenForGameplayMessagesHelper::PayloadPinName)
	{
		HoverTextOut = HoverTextOut + LOCTEXT("PayloadOutTooltip", "\n\nThe message structure that we received").ToString();
	}
}

FString UK2Node_ListenForGameplayMessages::GetPinMetaData(FName InPinName, FName InKey)
{
	if (InPinName == UK2Node_ListenForGameplayMessagesHelper::ChannelPinName &&
		(InKey == UK2Node_ListenForGameplayMessagesHelper::CategoriesMetaKey || InKey == UK2Node_ListenForGameplayMessagesHelper::GameplayTagFilterMetaKey))
	{
		return UK2Node_ListenForGameplayMessagesHelper::GameplayMessageChannelRoot;
	}

	return Super::GetPinMetaData(InPinName, InKey);
}

void UK2Node_ListenForGameplayMessages::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	struct GetMenuActions_Utils
	{
		static void SetNodeFunc(UEdGraphNode* NewNode, bool /*bIsTemplateNode*/, TWeakObjectPtr<UFunction> FunctionPtr)
		{
			UK2Node_ListenForGameplayMessages* AsyncTaskNode = CastChecked<UK2Node_ListenForGameplayMessages>(NewNode);
			if (FunctionPtr.IsValid())
			{
				UFunction* Func = FunctionPtr.Get();
				FObjectProperty* ReturnProp = CastFieldChecked<FObjectProperty>(Func->GetReturnProperty());

				AsyncTaskNode->ProxyFactoryFunctionName = Func->GetFName();
				AsyncTaskNode->ProxyFactoryClass = Func->GetOuterUClass();
				AsyncTaskNode->ProxyClass = ReturnProp->PropertyClass;
			}
		}
	};

	UClass* NodeClass = GetClass();
	ActionRegistrar.RegisterClassFactoryActions<UListenForGameplayMessagesAsyncAction>(FBlueprintActionDatabaseRegistrar::FMakeFuncSpawnerDelegate::CreateLambda([NodeClass](const UFunction* FactoryFunc) -> UBlueprintNodeSpawner*
	{
		UBlueprintNodeSpawner* NodeSpawner = UBlueprintFunctionNodeSpawner::Create(FactoryFunc);
		check(NodeSpawner != nullptr);
		NodeSpawner->NodeClass = NodeClass;

		TWeakObjectPtr<UFunction> FunctionPtr = MakeWeakObjectPtr(const_cast<UFunction*>(FactoryFunc));
		NodeSpawner->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateStatic(GetMenuActions_Utils::SetNodeFunc, FunctionPtr);

		return NodeSpawner;
	}));
}

void UK2Node_ListenForGameplayMessages::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	/** 监听节点只向蓝图暴露消息事件、实际频道和强类型 Payload，不暴露异步动作代理对象。 */
	if (UEdGraphPin* AsyncActionPin = FindPin(FBaseAsyncTaskHelper::GetAsyncTaskProxyName()))
	{
		AsyncActionPin->bHidden = true;
	}

	/** 代理对象只服务于编译展开后的 GetPayload 调用，蓝图侧只需要看到强类型 Payload 输出。 */
	UEdGraphPin* DelegateProxyPin = FindPin(UK2Node_ListenForGameplayMessagesHelper::DelegateProxyPinName);
	if (ensure(DelegateProxyPin))
	{
		DelegateProxyPin->bHidden = true;
	}

	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Wildcard, UK2Node_ListenForGameplayMessagesHelper::PayloadPinName);
}

bool UK2Node_ListenForGameplayMessages::HandleDelegates(const TArray<FBaseAsyncTaskHelper::FOutputPinAndLocalVariable>& VariableOutputs, UEdGraphPin* ProxyObjectPin, UEdGraphPin*& InOutLastThenPin, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext)
{
	bool bIsErrorFree = true;

	if (VariableOutputs.Num() != 3)
	{
		ensureMsgf(false, TEXT("UK2Node_ListenForGameplayMessages::HandleDelegates - Variable output array not valid. Output delegates must only have the single proxy object output and than must have pin for payload."));
		return false;
	}

	for (TFieldIterator<FMulticastDelegateProperty> PropertyIt(ProxyClass); PropertyIt && bIsErrorFree; ++PropertyIt)
	{
		UEdGraphPin* LastActivatedThenPin = nullptr;
		bIsErrorFree &= FBaseAsyncTaskHelper::HandleDelegateImplementation(*PropertyIt, VariableOutputs, ProxyObjectPin, InOutLastThenPin, LastActivatedThenPin, this, SourceGraph, CompilerContext);

		bIsErrorFree &= HandlePayloadImplementation(*PropertyIt, VariableOutputs[0], VariableOutputs[2], VariableOutputs[1], LastActivatedThenPin, SourceGraph, CompilerContext);
	}

	return bIsErrorFree;
}

bool UK2Node_ListenForGameplayMessages::HandlePayloadImplementation(FMulticastDelegateProperty* CurrentProperty, const FBaseAsyncTaskHelper::FOutputPinAndLocalVariable& ProxyObjectVar, const FBaseAsyncTaskHelper::FOutputPinAndLocalVariable& PayloadVar, const FBaseAsyncTaskHelper::FOutputPinAndLocalVariable& ActualChannelVar, UEdGraphPin*& InOutLastActivatedThenPin, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext)
{
	bool bIsErrorFree = true;
	const UEdGraphPin* PayloadPin = GetPayloadPin();
	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();

	check(CurrentProperty && SourceGraph && Schema);

	const FEdGraphPinType& PinType = PayloadPin->PinType;

	if (PinType.PinCategory == UEdGraphSchema_K2::PC_Wildcard)
	{
		if (PayloadPin->LinkedTo.Num() == 0)
		{
			/** 未指定 PayloadType 且蓝图没有使用 Payload 输出时，监听节点可以只暴露执行流和频道。 */
			return true;
		}
		else
		{
			return false;
		}
	}

	UK2Node_TemporaryVariable* TempVarOutput = CompilerContext.SpawnInternalVariable(
		this, PinType.PinCategory, PinType.PinSubCategory, PinType.PinSubCategoryObject.Get(), PinType.ContainerType, PinType.PinValueType);

	UK2Node_CallFunction* const CallGetPayloadNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallGetPayloadNode->FunctionReference.SetExternalMember(TEXT("GetPayload"), CurrentProperty->GetOwnerClass());
	CallGetPayloadNode->AllocateDefaultPins();

	/** 将隐藏的代理对象接到 GetPayload 上，运行时从监听回调缓存中取出本次消息体。 */
	UEdGraphPin* GetPayloadCallSelfPin = Schema->FindSelfPin(*CallGetPayloadNode, EGPD_Input);
	if (GetPayloadCallSelfPin)
	{
		bIsErrorFree &= Schema->TryCreateConnection(GetPayloadCallSelfPin, ProxyObjectVar.TempVar->GetVariablePin());

		/** GetPayload 必须插在委托触发后的执行链上，确保复制的是当前回调携带的 Payload。 */
		UEdGraphPin* GetPayloadExecPin = CallGetPayloadNode->FindPinChecked(UEdGraphSchema_K2::PN_Execute);
		UEdGraphPin* GetPayloadThenPin = CallGetPayloadNode->FindPinChecked(UEdGraphSchema_K2::PN_Then);
		UEdGraphPin* GetPayloadPin = CallGetPayloadNode->FindPinChecked(TEXT("OutPayload"));
		bIsErrorFree &= Schema->TryCreateConnection(TempVarOutput->GetVariablePin(), GetPayloadPin);

		UK2Node_AssignmentStatement* AssignNode = CompilerContext.SpawnIntermediateNode<UK2Node_AssignmentStatement>(this, SourceGraph);
		AssignNode->AllocateDefaultPins();
		bIsErrorFree &= Schema->TryCreateConnection(GetPayloadThenPin, AssignNode->GetExecPin());
		bIsErrorFree &= Schema->TryCreateConnection(PayloadVar.TempVar->GetVariablePin(), AssignNode->GetVariablePin());
		AssignNode->NotifyPinConnectionListChanged(AssignNode->GetVariablePin());
		bIsErrorFree &= Schema->TryCreateConnection(AssignNode->GetValuePin(), TempVarOutput->GetVariablePin());
		AssignNode->NotifyPinConnectionListChanged(AssignNode->GetValuePin());

		bIsErrorFree &= CompilerContext.MovePinLinksToIntermediate(*InOutLastActivatedThenPin, *AssignNode->GetThenPin()).CanSafeConnect();
		bIsErrorFree &= Schema->TryCreateConnection(InOutLastActivatedThenPin, GetPayloadExecPin);

		/** ActualChannel 来自运行时路由结果，PartialMatch 时用于告诉蓝图真正命中的子频道。 */
		UEdGraphPin* OutActualChannelPin = GetOutputChannelPin();
		bIsErrorFree &= CompilerContext.MovePinLinksToIntermediate(*OutActualChannelPin, *ActualChannelVar.TempVar->GetVariablePin()).CanSafeConnect();
	}

	return bIsErrorFree;
}

bool UK2Node_ListenForGameplayMessages::RefreshOutputPayloadType()
{
	UEdGraphPin* PayloadPin = GetPayloadPin();
	UEdGraphPin* PayloadTypePin = GetPayloadTypePin();
	UScriptStruct* PayloadStruct = Cast<UScriptStruct>(PayloadTypePin->DefaultObject);

	if (PayloadStruct != PayloadPin->PinType.PinSubCategoryObject)
	{
		if (PayloadPin->SubPins.Num() > 0)
		{
			GetSchema()->RecombinePin(PayloadPin);
		}

		PayloadPin->Modify();
		PayloadPin->PinType.PinSubCategoryObject = PayloadStruct;
		PayloadPin->PinType.PinCategory = (PayloadStruct == nullptr) ? UEdGraphSchema_K2::PC_Wildcard : UEdGraphSchema_K2::PC_Struct;
		return true;
	}

	return false;
}

UEdGraphPin* UK2Node_ListenForGameplayMessages::GetPayloadPin() const
{
	UEdGraphPin* Pin = FindPinChecked(UK2Node_ListenForGameplayMessagesHelper::PayloadPinName);
	check(Pin->Direction == EGPD_Output);
	return Pin;
}

UEdGraphPin* UK2Node_ListenForGameplayMessages::GetPayloadTypePin() const
{
	UEdGraphPin* Pin = FindPinChecked(UK2Node_ListenForGameplayMessagesHelper::PayloadTypePinName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_ListenForGameplayMessages::GetOutputChannelPin() const
{
	UEdGraphPin* Pin = FindPinChecked(UK2Node_ListenForGameplayMessagesHelper::ActualChannelPinName);
	check(Pin->Direction == EGPD_Output);
	return Pin;
}

#undef LOCTEXT_NAMESPACE
