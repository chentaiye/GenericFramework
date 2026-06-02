#pragma once

#include "CoreMinimal.h"
#include "K2Node_CallFunction.h"
#include "K2Node_CommitPropertyValue.generated.h"

/** 编辑器专用 K2 节点，把旧版通配符提交函数包装成蓝图菜单中的属性提交节点。 */
UCLASS(MinimalAPI)
class UK2Node_CommitPropertyValue : public UK2Node_CallFunction
{
	GENERATED_BODY()

public:
	/** 初始化提交属性值的K2节点，绑定默认函数名和节点展示行为。 */
	GENERICPROPERTYNODE_API UK2Node_CommitPropertyValue();

	GENERICPROPERTYNODE_API virtual FText GetTooltipText() const override;
	GENERICPROPERTYNODE_API virtual bool IsNodePure() const override;
	GENERICPROPERTYNODE_API virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& InActionRegistrar) const override;
	GENERICPROPERTYNODE_API virtual FText GetMenuCategory() const override;
};
