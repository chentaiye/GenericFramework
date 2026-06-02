/* Copyright ChenTaiye 2025,. All Rights Reserved. */
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_ExternalData.generated.h"

class UExternalData;

/** 定义 GetData 自定义蓝图节点的执行分支，execGetData 根据结构匹配、资产有效性和 JSON 加载结果选择后续流程。 */
UENUM()
enum class EExternalDataResult : uint8
{
	/** 数据资产存在、RowStruct 类型与 Value 引脚一致且 JSON 成功加载后，蓝图继续执行成功分支。 */
	Valid,

	/** 资产为空、结构未初始化、Value 类型不匹配或加载失败时使用该分支，避免向蓝图输出错误结构数据。 */
	NotValid,
};

/** 为外部数据提供蓝图可调用入口；实际读取由 CustomThunk 完成，以便把任意 UScriptStruct 行数据复制到通配 Value 参数。 */
UCLASS(MinimalAPI)
class UBPFunctions_ExternalData : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 蓝图节点声明入口，由 UK2Node_ExternalData 绑定并隐藏内部实现；execGetData 会读取 Data 的 RowStruct 并写入 Value。 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Json Data", meta=(CustomStructureParam="Value", ExpandEnumAsExecs="ExecResult", BlueprintInternalUseOnly="true"))
	static EXTERNALDATA_API void GetData(EExternalDataResult& ExecResult, UPARAM(ref) const UExternalData* Data, int32& Value);

private:
	/** 解析 CustomThunk 栈中的通配结构参数，完成类型校验、JSON 重载和结构内存复制，是 GetData 蓝图节点的真实执行体。 */
	DECLARE_FUNCTION(execGetData);
};
