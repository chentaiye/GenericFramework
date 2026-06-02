#include "K2Node_CommitPropertyValue.h"

#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "GenericPropertyFramework/Public/BPFunctions/BPFunctions_Property.h"

#define LOCTEXT_NAMESPACE "GenericPropertyNode"

UK2Node_CommitPropertyValue::UK2Node_CommitPropertyValue()
{
	FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UBPFunctions_Property, CommitPropertyValue), UBPFunctions_Property::StaticClass());
}

FText UK2Node_CommitPropertyValue::GetTooltipText() const
{
	return LOCTEXT("CommitPropertyValueTooltip", "Commit a generic property value from a wildcard blueprint pin.");
}

bool UK2Node_CommitPropertyValue::IsNodePure() const
{
	return false;
}

void UK2Node_CommitPropertyValue::GetMenuActions(FBlueprintActionDatabaseRegistrar& InActionRegistrar) const
{
	Super::GetMenuActions(InActionRegistrar);

	const UClass* ActionKey = GetClass();
	if (InActionRegistrar.IsOpenForRegistration(ActionKey))
	{
		auto CustomizeLambda = [](UEdGraphNode* NewNode, bool bIsTemplateNode, const FName FunctionName)
		{
			UK2Node_CommitPropertyValue* Node = CastChecked<UK2Node_CommitPropertyValue>(NewNode);
			const UFunction* Function = UBPFunctions_Property::StaticClass()->FindFunctionByName(FunctionName);
			check(Function != nullptr);
			Node->SetFromFunction(Function);
		};

		UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
		check(NodeSpawner != nullptr);
		NodeSpawner->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateStatic(CustomizeLambda, GET_FUNCTION_NAME_CHECKED(UBPFunctions_Property, CommitPropertyValue));
		InActionRegistrar.AddBlueprintAction(ActionKey, NodeSpawner);
	}
}

FText UK2Node_CommitPropertyValue::GetMenuCategory() const
{
	return LOCTEXT("CommitPropertyValueCategory", "Generic Property");
}

#undef LOCTEXT_NAMESPACE
