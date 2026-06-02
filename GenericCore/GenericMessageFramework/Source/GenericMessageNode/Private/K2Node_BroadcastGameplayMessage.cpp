// Copyright ChenTaiye 2025. All Rights Reserved.

#include "K2Node_BroadcastGameplayMessage.h"

#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintFunctionNodeSpawner.h"
#include "EdGraph/EdGraphPin.h"
#include "AsyncAction/BroadcastGameplayMessageAsyncAction.h"

#define LOCTEXT_NAMESPACE "GenericMessageNode"

namespace UE::GenericGameplayMessage::Editor
{
	static const FName ChannelPinName(TEXT("Channel"));
	static const FName CategoriesMetaKey(TEXT("Categories"));
	static const FName GameplayTagFilterMetaKey(TEXT("GameplayTagFilter"));
	static const FString GameplayMessageChannelRoot(TEXT("GameplayMessage.Channel"));
}

FText UK2Node_BroadcastGameplayMessage::GetTooltipText() const
{
	return LOCTEXT("BroadcastGameplayMessageTooltip", "Broadcast a gameplay message on the supplied channel using the connected struct payload.");
}

void UK2Node_BroadcastGameplayMessage::GetMenuActions(FBlueprintActionDatabaseRegistrar& InActionRegistrar) const
{
	struct GetMenuActions_Utils
	{
		static void SetNodeFunc(UEdGraphNode* NewNode, bool /*bIsTemplateNode*/, TWeakObjectPtr<UFunction> FunctionPtr)
		{
			UK2Node_BroadcastGameplayMessage* AsyncTaskNode = CastChecked<UK2Node_BroadcastGameplayMessage>(NewNode);
			if (FunctionPtr.IsValid())
			{
				UFunction* Func = FunctionPtr.Get();
				FObjectProperty* ReturnProp = CastFieldChecked<FObjectProperty>(Func->GetReturnProperty());

				AsyncTaskNode->ProxyFactoryFunctionName = Func->GetFName();
				AsyncTaskNode->ProxyFactoryClass = Func->GetOuterUClass();
				AsyncTaskNode->ProxyClass = ReturnProp->PropertyClass;
			}
		};
	};

	UClass* NodeClass = GetClass();
	InActionRegistrar.RegisterClassFactoryActions<UBroadcastGameplayMessageAsyncAction>(FBlueprintActionDatabaseRegistrar::FMakeFuncSpawnerDelegate::CreateLambda([NodeClass](const UFunction* FactoryFunc) -> UBlueprintNodeSpawner*
	{
		UBlueprintNodeSpawner* NodeSpawner = UBlueprintFunctionNodeSpawner::Create(FactoryFunc);
		check(NodeSpawner != nullptr);
		NodeSpawner->NodeClass = NodeClass;

		TWeakObjectPtr<UFunction> FunctionPtr = MakeWeakObjectPtr(const_cast<UFunction*>(FactoryFunc));
		NodeSpawner->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateStatic(GetMenuActions_Utils::SetNodeFunc, FunctionPtr);

		return NodeSpawner;
	}));
}

FText UK2Node_BroadcastGameplayMessage::GetMenuCategory() const
{
	return LOCTEXT("BroadcastGameplayMessageCategory", "Messaging");
}

void UK2Node_BroadcastGameplayMessage::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	/** 广播节点内部仍需要异步代理完成编译展开，蓝图表面不暴露可取消代理对象。 */
	if (UEdGraphPin* AsyncActionPin = FindPin(FBaseAsyncTaskHelper::GetAsyncTaskProxyName()))
	{
		AsyncActionPin->bHidden = true;
	}
}

FString UK2Node_BroadcastGameplayMessage::GetPinMetaData(FName InPinName, FName InKey)
{
	if (InPinName == UE::GenericGameplayMessage::Editor::ChannelPinName &&
		(InKey == UE::GenericGameplayMessage::Editor::CategoriesMetaKey || InKey == UE::GenericGameplayMessage::Editor::GameplayTagFilterMetaKey))
	{
		return UE::GenericGameplayMessage::Editor::GameplayMessageChannelRoot;
	}

	return Super::GetPinMetaData(InPinName, InKey);
}

#undef LOCTEXT_NAMESPACE
