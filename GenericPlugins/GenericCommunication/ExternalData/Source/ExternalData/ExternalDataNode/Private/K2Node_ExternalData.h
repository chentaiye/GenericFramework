/* Copyright ChenTaiye 2025,. All Rights Reserved. */
#pragma once

#include "K2Node_CallFunction.h"
#include "K2Node_ExternalData.generated.h"

class UEdGraphPin;
class FBlueprintActionDatabaseRegistrar;

/** 自定义 GetData 蓝图节点，绑定 UBPFunctions_ExternalData::GetData 并根据所选 UExternalData 的行结构约束 Value 引脚。 */
UCLASS(MinimalAPI)
class UK2Node_ExternalData : public UK2Node_CallFunction
{
	GENERATED_BODY()

	virtual void PinDefaultValueChanged(UEdGraphPin* Pin) override;
	virtual void ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual bool IsConnectionDisallowed(const UEdGraphPin* MyPin, const UEdGraphPin* OtherPin, FString& OutReason) const override;
private:
	/** 定位 Data 输入引脚，节点通过它读取默认选择的 UExternalData 资产并触发图刷新。 */
	const UEdGraphPin* GetDataPin() const;

	/** 定位通配 Value 引脚，编译校验和连线拦截都以它为目标确认结构类型是否匹配。 */
	const UEdGraphPin* GetValuePin() const;

	/** 从 Data 引脚的默认对象解析当前资产，为 Value 引脚推导期望结构以及错误信息提供上下文。 */
	const class UExternalData* GetSelectedExternalData() const;

	/** 返回所选资产 RowStruct 绑定的结构类型，作为编译报错和连线拒绝逻辑的唯一类型依据。 */
	const class UScriptStruct* GetExpectedValueStruct() const;
};
