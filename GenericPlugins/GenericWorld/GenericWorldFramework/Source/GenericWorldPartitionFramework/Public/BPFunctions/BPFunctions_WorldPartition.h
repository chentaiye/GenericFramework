// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WorldPartition/DataLayer/DataLayerInstance.h"
#include "WorldPartitionType.h"
#include "BPFunctions_WorldPartition.generated.h"

class AActor;
class UDataLayerAsset;
class UWorldPartition;

DECLARE_DYNAMIC_DELEGATE(FHandleWorldPartitionOnceFinish);
DECLARE_DYNAMIC_DELEGATE(FHandleWorldPartitionFinish);

/** 暴露 World Partition Runtime Cell 与 DataLayer 操作给蓝图，内部统一转发到当前世界的子系统。 */
UCLASS(MinimalAPI)
class UBPFunctions_WorldPartition : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 提交单个 Runtime Cell 加载请求，完成回调在 Cell 达到 Loaded 或 Activated 后触发。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void LoadCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell, FHandleWorldPartitionFinish OnFinish);

	/** 按顺序加载多个 Runtime Cell，每个 Cell 完成时触发 OnceFinish，全部完成时触发 Finish。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void LoadCells(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish);

	/** 使用设置结构提交加载请求，适合蓝图先组装或复用一组 Cell 配置。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void LoadCellsBySetting(const UObject* WorldContextObject, TArray<FLoadWorldPartitionSetting> LoadWorldPartitionSettings, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish);

	/** 提交单个 Runtime Cell 卸载请求，子系统会过滤 AlwaysLoaded 和不可卸载目标。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void UnloadCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell, FHandleWorldPartitionFinish OnFinish);

	/** 按顺序卸载多个 Runtime Cell，并在每个 Cell 离开 Loaded 状态后触发 OnceFinish。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void UnloadCells(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish);

	/** 使用设置结构提交卸载请求，便于蓝图批量配置后交给子系统统一校验。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void UnloadCellsBySetting(const UObject* WorldContextObject, TArray<FUnloadWorldPartitionSetting> UnloadWorldPartitionSettings, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish);

	/** 激活或反激活单个 Runtime Cell，可见目标会进入 Activated，不可见目标会退出 Activated。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void SetCellVisibility(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell, bool bVisible, FHandleWorldPartitionFinish OnFinish);

	/** 对多个 Runtime Cell 应用同一个可见性目标，执行顺序和完成回调由句柄管理。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void SetCellsVisibility(const UObject* WorldContextObject, TArray<UWorldPartitionRuntimeCell*> Cells, bool bVisible, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish);

	/** 使用设置结构批量提交可见性请求，允许不同 Cell 拥有不同的目标可见性。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API void SetCellsVisibilityBySetting(const UObject* WorldContextObject, TArray<FSetWorldPartitionVisibilitySetting> SetWorldPartitionVisibilitySettings, FHandleWorldPartitionOnceFinish OnOnceFinish, FHandleWorldPartitionFinish OnFinish);

	/** 返回 WorldContext 所属世界的原生 WorldPartition 对象。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UWorldPartition* GetCurrentWorldPartition(const UObject* WorldContextObject);

	/** 返回当前 RuntimeHash 中的全部 Streaming Cell，结果已按名称排序。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API TArray<UWorldPartitionRuntimeCell*> GetCurrentWorldPartitionRuntimeCells(const UObject* WorldContextObject);

	/** 读取 Runtime Cell 当前流送状态，空引用按 Unloaded 返回。 */
	UFUNCTION(BlueprintPure, Category="World Partition")
	static GENERICWORLDPARTITIONFRAMEWORK_API EWorldPartitionRuntimeCellState GetCellState(UWorldPartitionRuntimeCell* Cell);

	/** 判断 Runtime Cell 是否至少处于 Loaded 状态。 */
	UFUNCTION(BlueprintPure, Category="World Partition")
	static GENERICWORLDPARTITIONFRAMEWORK_API bool IsCellLoaded(UWorldPartitionRuntimeCell* Cell);

	/** 判断 Runtime Cell 是否处于 Activated 状态。 */
	UFUNCTION(BlueprintPure, Category="World Partition")
	static GENERICWORLDPARTITIONFRAMEWORK_API bool IsCellVisible(UWorldPartitionRuntimeCell* Cell);

	/** 检查目标 Runtime Cell 是否属于当前世界，避免跨世界对象被误操作。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool IsCurrentWorldContainCell(const UObject* WorldContextObject, UWorldPartitionRuntimeCell* Cell);

	/** 查询当前世界的 World Partition 是否已经没有未完成的流送任务。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool IsStreamingCompleted(const UObject* WorldContextObject);

public:
	/** 枚举当前世界所有有效 DataLayerInstance。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API TArray<UDataLayerInstance*> GetDataLayerInstances(const UObject* WorldContextObject);

	/** 通过 DataLayerAsset 查找当前世界中的运行时 DataLayerInstance。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UDataLayerInstance* GetDataLayerInstanceFromAsset(const UObject* WorldContextObject, const UDataLayerAsset* DataLayerAsset);

	/** 通过实例名查找当前世界中的运行时 DataLayerInstance。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API UDataLayerInstance* GetDataLayerInstanceFromName(const UObject* WorldContextObject, FName DataLayerInstanceName);

	/** 对指定 DataLayerInstance 设置运行时状态，可递归影响其子层。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool SetDataLayerInstanceRuntimeState(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance, EDataLayerRuntimeState State, bool bIsRecursive);

	/** 通过 DataLayerAsset 设置运行时状态，适合用资产引用驱动世界初始化。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool SetDataLayerRuntimeStateByAsset(const UObject* WorldContextObject, const UDataLayerAsset* DataLayerAsset, EDataLayerRuntimeState State, bool bIsRecursive);

	/** 通过实例名设置运行时状态，适合只保存 DataLayer 名称的蓝图流程。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool SetDataLayerRuntimeStateByName(const UObject* WorldContextObject, FName DataLayerInstanceName, EDataLayerRuntimeState State, bool bIsRecursive);

	/** 将 DataLayerInstance 切到 Loaded，只加载该层内容但不激活可见性。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool LoadDataLayer(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance, bool bIsRecursive);

	/** 将 DataLayerInstance 切到 Activated，驱动该层内容加载并参与可见性。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool ActivateDataLayer(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance, bool bIsRecursive);

	/** 将 DataLayerInstance 切到 Unloaded，释放该层对应的 World Partition 内容。 */
	UFUNCTION(BlueprintCallable, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool UnloadDataLayer(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance, bool bIsRecursive);

	/** 读取 DataLayerInstance 显式运行时状态，不合并父层影响。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerInstanceRuntimeState(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance);

	/** 读取 DataLayerInstance 的有效运行时状态，用于判断最终加载或可见结果。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerInstanceEffectiveRuntimeState(const UObject* WorldContextObject, const UDataLayerInstance* DataLayerInstance);

	/** 通过 DataLayerAsset 读取显式运行时状态，找不到实例时返回 Unloaded。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerRuntimeStateByAsset(const UObject* WorldContextObject, const UDataLayerAsset* DataLayerAsset);

	/** 通过 DataLayerAsset 读取有效运行时状态，适合资产驱动的条件判断。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerEffectiveRuntimeStateByAsset(const UObject* WorldContextObject, const UDataLayerAsset* DataLayerAsset);

	/** 通过实例名读取显式运行时状态，找不到实例时返回 Unloaded。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerRuntimeStateByName(const UObject* WorldContextObject, FName DataLayerInstanceName);

	/** 通过实例名读取有效运行时状态，适合蓝图按名称轮询 DataLayer 结果。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerEffectiveRuntimeStateByName(const UObject* WorldContextObject, FName DataLayerInstanceName);

	/** 返回当前有效 Loaded 的 DataLayer 名称集合。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API TArray<FName> GetEffectiveLoadedDataLayerNames(const UObject* WorldContextObject);

	/** 返回当前有效 Activated 的 DataLayer 名称集合。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API TArray<FName> GetEffectiveActiveDataLayerNames(const UObject* WorldContextObject);

	/** 判断名称集合中是否至少有一个 DataLayer 达到指定有效状态。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool IsAnyDataLayerInEffectiveRuntimeState(const UObject* WorldContextObject, const TArray<FName>& DataLayerNames, EDataLayerRuntimeState State);

	/** 判断名称集合中的所有 DataLayer 是否都达到指定有效状态。 */
	UFUNCTION(BlueprintPure, Category="World Partition", meta=(WorldContext="WorldContextObject"))
	static GENERICWORLDPARTITIONFRAMEWORK_API bool IsAllDataLayerInEffectiveRuntimeState(const UObject* WorldContextObject, const TArray<FName>& DataLayerNames, EDataLayerRuntimeState State);

	/** 读取 Actor 所属的 DataLayerInstance，用于运行时反查 Actor 所在层。 */
	UFUNCTION(BlueprintPure, Category="World Partition")
	static GENERICWORLDPARTITIONFRAMEWORK_API TArray<UDataLayerInstance*> GetActorDataLayerInstances(const AActor* Actor);

	/** 读取 Actor 所属的 DataLayer 名称，编辑器与运行时路径由子系统兼容处理。 */
	UFUNCTION(BlueprintPure, Category="World Partition")
	static GENERICWORLDPARTITIONFRAMEWORK_API TArray<FName> GetActorDataLayerInstanceNames(const AActor* Actor);

	/** 读取 Runtime Cell 绑定的 DataLayerInstance，用于分析 Cell 来源层。 */
	UFUNCTION(BlueprintPure, Category="World Partition")
	static GENERICWORLDPARTITIONFRAMEWORK_API TArray<UDataLayerInstance*> GetCellDataLayerInstances(UWorldPartitionRuntimeCell* Cell);

	/** 读取 Runtime Cell 绑定的 DataLayer 名称，适合蓝图侧展示和比对。 */
	UFUNCTION(BlueprintPure, Category="World Partition")
	static GENERICWORLDPARTITIONFRAMEWORK_API TArray<FName> GetCellDataLayerInstanceNames(UWorldPartitionRuntimeCell* Cell);
};
