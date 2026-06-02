// Copyright ChenTaiye 2025,. All Rights Reserved.

#include "K2Node_ExternalData.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "BPFunctions_ExternalData.h"
#include "EdGraphSchema_K2.h"
#include "ExternalData.h"
#include "KismetCompiler.h"

namespace ExternalDataNodePrivate
{
	const FName DataPinName(TEXT("Data"));
	const FName ValuePinName(TEXT("Value"));
}

void UK2Node_ExternalData::PinDefaultValueChanged(UEdGraphPin* Pin)
{
	Super::PinDefaultValueChanged(Pin);

	if (Pin == GetDataPin() && GetGraph() != nullptr)
	{
		GetGraph()->NotifyGraphChanged();
	}
}

void UK2Node_ExternalData::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	Super::GetMenuActions(ActionRegistrar);

	const UClass* Action = GetClass();
	if (ActionRegistrar.IsOpenForRegistration(Action))
	{
		auto CustomizeLambda = [](UEdGraphNode* NewNode, bool bIsTemplateNode, const FName FunctionName)
		{
			UK2Node_ExternalData* Node = CastChecked<UK2Node_ExternalData>(NewNode);
			const UFunction* Function = UBPFunctions_ExternalData::StaticClass()->FindFunctionByName(FunctionName);
			check(Function);
			Node->SetFromFunction(Function);
		};

		UBlueprintNodeSpawner* GetDataNodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
		check(GetDataNodeSpawner != nullptr);
		GetDataNodeSpawner->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateStatic(CustomizeLambda, GET_FUNCTION_NAME_CHECKED(UBPFunctions_ExternalData, GetData));
		ActionRegistrar.AddBlueprintAction(Action, GetDataNodeSpawner);
	}
}

void UK2Node_ExternalData::ValidateNodeDuringCompilation(FCompilerResultsLog& MessageLog) const
{
	Super::ValidateNodeDuringCompilation(MessageLog);

	const UEdGraphPin* ValuePin = GetValuePin();
	const UExternalData* ExternalData = GetSelectedExternalData();
	const UScriptStruct* ExpectedStruct = GetExpectedValueStruct();

	if (ValuePin == nullptr || ExternalData == nullptr || ExpectedStruct == nullptr)
	{
		return;
	}

	if (ValuePin->PinType.PinCategory == UEdGraphSchema_K2::PC_Struct &&
		ValuePin->PinType.PinSubCategoryObject.Get() != ExpectedStruct)
	{
		MessageLog.Error(
			*FString::Printf(
				TEXT("@@ Value pin must use struct '%s' defined by ExternalData '%s'."),
				*ExpectedStruct->GetName(),
				*GetNameSafe(ExternalData)
			),
			this
		);
	}
}

bool UK2Node_ExternalData::IsConnectionDisallowed(const UEdGraphPin* MyPin, const UEdGraphPin* OtherPin, FString& OutReason) const
{
	const UEdGraphPin* ValuePin = GetValuePin();
	if (ValuePin == nullptr)
	{
		return Super::IsConnectionDisallowed(MyPin, OtherPin, OutReason);
	}

	if (MyPin == ValuePin || OtherPin == ValuePin)
	{
		const UEdGraphPin* CandidatePin = MyPin == ValuePin ? OtherPin : MyPin;
		if (CandidatePin->PinType.PinCategory != UEdGraphSchema_K2::PC_Struct)
		{
			OutReason = TEXT("Value must be a struct.");
			return true;
		}

		if (const UScriptStruct* ExpectedStruct = GetExpectedValueStruct())
		{
			if (CandidatePin->PinType.PinSubCategoryObject.Get() != ExpectedStruct)
			{
				OutReason = FString::Printf(TEXT("Value must use struct '%s' defined by the selected ExternalData asset."), *ExpectedStruct->GetName());
				return true;
			}
		}
	}

	return Super::IsConnectionDisallowed(MyPin, OtherPin, OutReason);
}

const UEdGraphPin* UK2Node_ExternalData::GetDataPin() const
{
	return FindPin(ExternalDataNodePrivate::DataPinName);
}

const UEdGraphPin* UK2Node_ExternalData::GetValuePin() const
{
	return FindPin(ExternalDataNodePrivate::ValuePinName);
}

const UExternalData* UK2Node_ExternalData::GetSelectedExternalData() const
{
	const UEdGraphPin* DataPin = GetDataPin();
	return DataPin != nullptr ? Cast<UExternalData>(DataPin->DefaultObject) : nullptr;
}

const UScriptStruct* UK2Node_ExternalData::GetExpectedValueStruct() const
{
	const UExternalData* ExternalData = GetSelectedExternalData();
	return ExternalData != nullptr ? ExternalData->GetRowScriptStruct() : nullptr;
}
