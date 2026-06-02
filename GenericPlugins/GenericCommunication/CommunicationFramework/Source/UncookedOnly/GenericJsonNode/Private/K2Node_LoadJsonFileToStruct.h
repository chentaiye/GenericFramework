// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_CallFunction.h"
#include "K2Node_LoadJsonFileToStruct.generated.h"

/** 提供从 JSON 文件加载任意结构体的编辑器节点，并限制 Value 通配引脚只能连接结构体。 */
UCLASS(MinimalAPI)
class UK2Node_LoadJsonFileToStruct : public UK2Node_CallFunction
{
	GENERATED_BODY()

	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual bool IsConnectionDisallowed(const UEdGraphPin* MyPin, const UEdGraphPin* OtherPin, FString& OutReason) const override;
};
