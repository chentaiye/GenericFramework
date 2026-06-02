// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "K2Node_AsyncAction.h"
#include "K2Node_BroadcastGameplayMessage.generated.h"

class FBlueprintActionDatabaseRegistrar;

/** 在蓝图中提供专用的 GameplayMessage 广播节点，负责把任意结构体载荷写入运行时消息通道。 */
UCLASS(MinimalAPI)
class UK2Node_BroadcastGameplayMessage : public UK2Node_AsyncAction
{
	GENERATED_BODY()

public:
	GENERICMESSAGENODE_API virtual FText GetTooltipText() const override;
	GENERICMESSAGENODE_API virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& InActionRegistrar) const override;
	GENERICMESSAGENODE_API virtual FText GetMenuCategory() const override;
	GENERICMESSAGENODE_API virtual void AllocateDefaultPins() override;
	GENERICMESSAGENODE_API virtual FString GetPinMetaData(FName InPinName, FName InKey) override;
};
