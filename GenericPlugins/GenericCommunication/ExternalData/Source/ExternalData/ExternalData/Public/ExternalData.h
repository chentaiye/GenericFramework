/* Copyright ChenTaiye 2025,. All Rights Reserved. */
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Misc/EngineVersionComparison.h"
#if UE_VERSION_OLDER_THAN(5, 5, 0)
#include "InstancedStruct.h"
#else
#include "StructUtils/InstancedStruct.h"
#endif
#include "ExternalData.generated.h"

class FObjectPostSaveRootContext;

/** 以数据资产保存一行外部结构数据，运行时从 Config/ExternalData 下的同名 JSON 载入到 RowStruct，编辑器保存时再把结构内存同步回 JSON。 */
UCLASS(MinimalAPI, BlueprintType)
class UExternalData : public UDataAsset
{
	GENERATED_BODY()

public:
	/** 保持 DataAsset 默认构造流程，具体行类型由资产或测试派生类初始化到 RowStruct 后再参与加载、保存和校验。 */
	UExternalData();
	virtual void PostLoad() override;

#if WITH_EDITOR
	virtual void PostSaveRoot(FObjectPostSaveRootContext ObjectSaveContext) override;
#endif
	/* End UObject Interface. */
#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
#endif

	/** 按调用方声明的结构类型读取当前行数据；默认会先重新从 JSON 装载，保证蓝图或 C++ 读取到外部文件的最新内容。 */
	template <typename T>
	const T& GetData(bool bReload = true)
	{
		if (bReload)
		{
			ensureAlways(LoadData());
		}

		return RowStruct.Get<T>();
	}

	/** 根据资产名生成持久化 JSON 路径，保存、加载、编辑器删除同步和 smoke test 都依赖该路径定位同一份外部文件。 */
	EXTERNALDATA_API FString GetJsonFilePath() const;

	/** 暴露 RowStruct 当前绑定的 UScriptStruct，让 K2 节点在编译和连线阶段验证 Value 引脚必须使用同一行结构。 */
	EXTERNALDATA_API const UScriptStruct* GetRowScriptStruct() const;

	/** 将 JSON 文件反序列化到 RowStruct 的可写内存；结构未初始化时返回失败，避免对未知行类型写入数据。 */
	EXTERNALDATA_API bool LoadData();

	/** 确保外部数据目录存在后把 RowStruct 序列化为 JSON，供资产保存、资产新增回调和自动化测试落盘验证复用。 */
	EXTERNALDATA_API bool SaveData();

protected:
	/** 编辑器按钮入口，允许设计时手动把磁盘 JSON 重新灌入 RowStruct，用于检查外部文件修改后的资产状态。 */
	UFUNCTION(CallInEditor, Category="External Data")
	void Reload();

	/** 保存行结构类型和实例内存，是 JSON 读写、数据校验、蓝图 CustomThunk 复制输出以及测试派生类注入数据的共同数据源。 */
	UPROPERTY(EditAnywhere, Category="External Data")
	FInstancedStruct RowStruct;

	/** 允许蓝图 CustomThunk 在校验结构类型后直接读取 RowStruct 内存，把外部 JSON 数据复制到通配 Value 参数。 */
	friend class UBPFunctions_ExternalData;
};
