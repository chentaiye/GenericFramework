// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_CallFunction.h"
#include "K2Node_TryGetJsonField.generated.h"

/** 提供编辑器蓝图节点，用于按引脚类型从 JSON 对象读取字段值。 */
UCLASS(MinimalAPI)
class UK2Node_TryGetJsonField : public UK2Node_CallFunction
{
	GENERATED_BODY()

public:
	/** 绑定运行时 GetJsonField CustomThunk，让节点引脚类型由蓝图连接决定。 */
	GENERICJSONNODE_API UK2Node_TryGetJsonField();
	GENERICJSONNODE_API virtual void AllocateDefaultPins() override;
	GENERICJSONNODE_API virtual FText GetTooltipText() const override;
	GENERICJSONNODE_API virtual bool IsNodePure() const override;
	GENERICJSONNODE_API virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& InActionRegistrar) const override;
	GENERICJSONNODE_API virtual FText GetMenuCategory() const override;
protected:
	/** 通配输出类型变化后标记蓝图和节点为已修改，触发编辑器刷新调用签名。 */
	GENERICJSONNODE_API void NotifyInputChanged() const;
};
