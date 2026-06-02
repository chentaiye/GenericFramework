// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExternalData.h"
#include "ExternalDataSmokeTestTypes.generated.h"

/** 自动化 smoke test 使用的最小行结构，用于验证整型和字符串字段能完整经过 RowStruct、JSON 保存和重新加载。 */
USTRUCT()
struct FExternalDataSmokeRow
{
	GENERATED_BODY()

	/** 用于断言 JSON 往返后数值字段没有被默认值或临时修改覆盖。 */
	UPROPERTY()
	int32 Number=0;

	/** 用于断言字符串字段同样参与序列化，覆盖仅测试数值类型时遗漏的文本路径。 */
	UPROPERTY()
	FString Label;
};

/** 测试专用资产类型，暴露受控的 RowStruct 写入和读取入口，让自动化用临时对象验证 UExternalData 的保存加载流程。 */
UCLASS(MinimalAPI)
class UExternalDataSmokeTestAsset : public UExternalData
{
	GENERATED_BODY()

public:
	/** 将测试行写入继承来的 RowStruct，模拟编辑器资产已经配置好具体行结构和值。 */
	void SetRowValue(const FExternalDataSmokeRow& InRow)
	{
		RowStruct.InitializeAs<FExternalDataSmokeRow>(InRow);
	}

	/** 直接读取当前 RowStruct 内容，供测试在 LoadData 后比较磁盘 JSON 恢复出的行数据。 */
	const FExternalDataSmokeRow& GetRowValue() const { return RowStruct.Get<FExternalDataSmokeRow>(); }
};
