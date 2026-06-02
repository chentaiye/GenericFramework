// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "WorldPartition/DataLayer/DataLayerInstance.h"
#include "WorldPartitionType.h"
#include "GenericWorldPartitionSubsystem.generated.h"

class AActor;
class UDataLayerAsset;
class UDataLayerManager;
class UGenericWorldPartitionSubsystem;
class ULoadWorldPartitionHandle;
class USetWorldPartitionVisibilityHandle;
class UUnLoadWorldPartitionHandle;
class UWorldPartition;
class UWorldPartitionHandle;
class UWorldPartitionSubsystem;

/** 句柄进入加载调度队列时发送的消息，替代旧的子系统注册广播。 */
USTRUCT(BlueprintType)
struct GENERICWORLDPARTITIONFRAMEWORK_API FOnLoadWorldPartitionHandleRegisteredMessage
{
	GENERATED_BODY()

	/** 标识发出本次事件的 World Partition 子系统，监听方可据此区分 PIE 多世界上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Load World Partition Handle Registered Message")
	TObjectPtr<UGenericWorldPartitionSubsystem> GenericWorldPartitionSubsystem = nullptr;

	/** 指向刚进入调度队列的加载句柄，监听方可继续绑定单 Cell 或整批完成事件。 */
	UPROPERTY(BlueprintReadOnly, Category="Load World Partition Handle Registered Message")
	TObjectPtr<ULoadWorldPartitionHandle> Handle = nullptr;
};

/** 句柄进入卸载调度队列时发送的消息，监听方可按世界上下文过滤。 */
USTRUCT(BlueprintType)
struct GENERICWORLDPARTITIONFRAMEWORK_API FOnUnLoadWorldPartitionHandleRegisteredMessage
{
	GENERATED_BODY()

	/** 标识发出本次事件的 World Partition 子系统，监听方可据此区分 PIE 多世界上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Unload World Partition Handle Registered Message")
	TObjectPtr<UGenericWorldPartitionSubsystem> GenericWorldPartitionSubsystem = nullptr;

	/** 指向刚进入调度队列的卸载句柄，监听方可读取目标 Cell 集合或绑定句柄完成事件。 */
	UPROPERTY(BlueprintReadOnly, Category="Unload World Partition Handle Registered Message")
	TObjectPtr<UUnLoadWorldPartitionHandle> Handle = nullptr;
};

/** 句柄进入可见性调度队列时发送的消息，用于观察 Cell 激活或反激活请求。 */
USTRUCT(BlueprintType)
struct GENERICWORLDPARTITIONFRAMEWORK_API FOnSetWorldPartitionVisibilityHandleRegisteredMessage
{
	GENERATED_BODY()

	/** 标识发出本次事件的 World Partition 子系统，监听方可据此区分 PIE 多世界上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Set World Partition Visibility Handle Registered Message")
	TObjectPtr<UGenericWorldPartitionSubsystem> GenericWorldPartitionSubsystem = nullptr;

	/** 指向刚进入调度队列的可见性句柄，监听方可继续跟踪激活或反激活完成时机。 */
	UPROPERTY(BlueprintReadOnly, Category="Set World Partition Visibility Handle Registered Message")
	TObjectPtr<USetWorldPartitionVisibilityHandle> Handle = nullptr;
};

/** 记录同一 Runtime Cell 在同一调度批次内被多个句柄修改的冲突关系。 */
struct FWorldPartitionCellConflict
{
	/** 本轮需要去重处理的目标 Cell。 */
	TObjectPtr<UWorldPartitionRuntimeCell> Cell = nullptr;

	/** 竞争修改该 Cell 的句柄，后提交的句柄会覆盖先提交句柄中的同一 Cell。 */
	TArray<TObjectPtr<UWorldPartitionHandle>> ModifyHandles;
};

/** 只在 World Partition 地图中创建，统一调度 Runtime Cell 流送句柄和 DataLayer 运行时状态。 */
UCLASS(MinimalAPI)
class UGenericWorldPartitionSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	static GENERICWORLDPARTITIONFRAMEWORK_API UGenericWorldPartitionSubsystem* Get(const UObject* WorldContextObject);

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

public:
	/** 为单个 Runtime Cell 创建加载句柄，完成后触发总完成回调。 */
	GENERICWORLDPARTITIONFRAMEWORK_API ULoadWorldPartitionHandle* LoadCell(UWorldPartitionRuntimeCell* Cell, const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 将一组 Runtime Cell 转换为加载设置并按顺序提交，单个 Cell 完成时触发一次回调。 */
	GENERICWORLDPARTITIONFRAMEWORK_API ULoadWorldPartitionHandle* LoadCells(const TArray<UWorldPartitionRuntimeCell*>& Cells, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish = FOnHandleWorldPartitionOnceFinish(), const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 校验并去重加载设置，只把当前世界拥有的 Cell 放入下一帧调度队列。 */
	GENERICWORLDPARTITIONFRAMEWORK_API ULoadWorldPartitionHandle* LoadCellsBySetting(const TArray<FLoadWorldPartitionSetting>& InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish = FOnHandleWorldPartitionOnceFinish(), const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 为单个 Runtime Cell 创建卸载句柄，AlwaysLoaded 或不可卸载 Cell 会被过滤。 */
	GENERICWORLDPARTITIONFRAMEWORK_API UUnLoadWorldPartitionHandle* UnloadCell(UWorldPartitionRuntimeCell* Cell, const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 将一组 Runtime Cell 转换为卸载设置并按顺序提交，便于监听每个 Cell 的卸载完成。 */
	GENERICWORLDPARTITIONFRAMEWORK_API UUnLoadWorldPartitionHandle* UnloadCells(const TArray<UWorldPartitionRuntimeCell*>& Cells, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish = FOnHandleWorldPartitionOnceFinish(), const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 校验卸载设置并剔除不可卸载目标，只保留当前世界可安全卸载的 Cell。 */
	GENERICWORLDPARTITIONFRAMEWORK_API UUnLoadWorldPartitionHandle* UnloadCellsBySetting(const TArray<FUnloadWorldPartitionSetting>& InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish = FOnHandleWorldPartitionOnceFinish(), const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 为单个 Runtime Cell 创建激活或反激活句柄，用于控制已加载 Cell 是否可见。 */
	GENERICWORLDPARTITIONFRAMEWORK_API USetWorldPartitionVisibilityHandle* SetCellVisibility(UWorldPartitionRuntimeCell* Cell, bool bVisible, const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 将一组 Runtime Cell 转换为同一目标可见性的设置并按顺序提交。 */
	GENERICWORLDPARTITIONFRAMEWORK_API USetWorldPartitionVisibilityHandle* SetCellsVisibility(const TArray<UWorldPartitionRuntimeCell*>& Cells, bool bVisible, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish = FOnHandleWorldPartitionOnceFinish(), const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 校验可见性设置，避免隐藏 AlwaysLoaded Cell，并把有效请求放入调度队列。 */
	GENERICWORLDPARTITIONFRAMEWORK_API USetWorldPartitionVisibilityHandle* SetCellsVisibilityBySetting(const TArray<FSetWorldPartitionVisibilitySetting>& InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish = FOnHandleWorldPartitionOnceFinish(), const FOnHandleWorldPartitionFinish& OnFinish = FOnHandleWorldPartitionFinish());

	/** 返回当前世界绑定的原生 WorldPartition 对象，非分区世界不会创建本子系统。 */
	GENERICWORLDPARTITIONFRAMEWORK_API UWorldPartition* GetCurrentWorldPartition() const;

	/** 枚举 RuntimeHash 中的全部 Streaming Cell，并按名称排序便于调试和蓝图展示。 */
	GENERICWORLDPARTITIONFRAMEWORK_API TArray<UWorldPartitionRuntimeCell*> GetCurrentWorldPartitionRuntimeCells() const;

	/** 读取 Cell 当前流送状态，空目标按 Unloaded 处理以简化蓝图判断。 */
	GENERICWORLDPARTITIONFRAMEWORK_API EWorldPartitionRuntimeCellState GetCellState(UWorldPartitionRuntimeCell* Cell) const;

	/** 判断 Cell 是否至少进入 Loaded 状态，Activated 也视为已加载。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool IsCellLoaded(UWorldPartitionRuntimeCell* Cell) const;

	/** 判断 Cell 是否处于 Activated 状态，即已加载且可见。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool IsCellVisible(UWorldPartitionRuntimeCell* Cell) const;

	/** 在当前 RuntimeHash 中查找目标 Cell，防止跨世界 Cell 被提交到错误子系统。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool IsCurrentWorldContainCell(UWorldPartitionRuntimeCell* Cell) const;

	/** 查询 UE 原生 WorldPartitionSubsystem 是否已经完成当前所有流送任务。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool IsStreamingCompleted() const;

	/** 返回当前世界的 DataLayerManager，DataLayer 相关 API 都通过它落到 UE 原生流程。 */
	GENERICWORLDPARTITIONFRAMEWORK_API UDataLayerManager* GetDataLayerManager() const;

	/** 枚举当前世界已注册的 DataLayerInstance，过滤无效实例后返回给蓝图或世界设置。 */
	GENERICWORLDPARTITIONFRAMEWORK_API TArray<UDataLayerInstance*> GetDataLayerInstances() const;

	/** 通过 DataLayerAsset 定位当前世界中的运行时实例，用于资产驱动的状态切换。 */
	GENERICWORLDPARTITIONFRAMEWORK_API UDataLayerInstance* GetDataLayerInstanceFromAsset(const UDataLayerAsset* DataLayerAsset) const;

	/** 通过 DataLayer 实例名定位运行时实例，适配只保存名称的旧蓝图或配置。 */
	GENERICWORLDPARTITIONFRAMEWORK_API UDataLayerInstance* GetDataLayerInstanceFromName(FName DataLayerInstanceName) const;

	/** 直接设置 DataLayerInstance 的运行时状态，可选择递归影响子层。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool SetDataLayerInstanceRuntimeState(const UDataLayerInstance* DataLayerInstance, EDataLayerRuntimeState State, bool bIsRecursive = false) const;

	/** 通过 DataLayerAsset 设置运行时状态，适合世界设置中保存资产引用的场景。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool SetDataLayerRuntimeState(const UDataLayerAsset* DataLayerAsset, EDataLayerRuntimeState State, bool bIsRecursive = false) const;

	/** 通过实例名设置运行时状态，内部会先解析到当前世界的 DataLayerInstance。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool SetDataLayerRuntimeStateByName(FName DataLayerInstanceName, EDataLayerRuntimeState State, bool bIsRecursive = false) const;

	/** 读取 DataLayerInstance 自身的显式运行时状态，不合并父层影响。 */
	GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerInstanceRuntimeState(const UDataLayerInstance* DataLayerInstance) const;

	/** 读取 DataLayerInstance 的有效运行时状态，包含父层或层级递归带来的最终结果。 */
	GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerInstanceEffectiveRuntimeState(const UDataLayerInstance* DataLayerInstance) const;

	/** 通过 DataLayerAsset 读取显式运行时状态，找不到实例时返回 Unloaded。 */
	GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerRuntimeStateByAsset(const UDataLayerAsset* DataLayerAsset) const;

	/** 通过 DataLayerAsset 读取有效运行时状态，便于判断当前世界实际可见加载结果。 */
	GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerEffectiveRuntimeStateByAsset(const UDataLayerAsset* DataLayerAsset) const;

	/** 通过实例名读取显式运行时状态，适配按名称驱动的蓝图逻辑。 */
	GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerRuntimeStateByName(FName DataLayerInstanceName) const;

	/** 通过实例名读取有效运行时状态，返回值可直接用于运行时条件判断。 */
	GENERICWORLDPARTITIONFRAMEWORK_API EDataLayerRuntimeState GetDataLayerEffectiveRuntimeStateByName(FName DataLayerInstanceName) const;

	/** 返回当前有效 Loaded 的 DataLayer 名称集合，用于调试和批量状态判断。 */
	GENERICWORLDPARTITIONFRAMEWORK_API TArray<FName> GetEffectiveLoadedDataLayerNames() const;

	/** 返回当前有效 Activated 的 DataLayer 名称集合，代表已参与可见内容的层。 */
	GENERICWORLDPARTITIONFRAMEWORK_API TArray<FName> GetEffectiveActiveDataLayerNames() const;

	/** 判断给定名称中是否至少有一个 DataLayer 达到指定有效状态。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool IsAnyDataLayerInEffectiveRuntimeState(const TArray<FName>& DataLayerNames, EDataLayerRuntimeState State) const;

	/** 判断给定名称中的所有 DataLayer 是否都达到指定有效状态。 */
	GENERICWORLDPARTITIONFRAMEWORK_API bool IsAllDataLayerInEffectiveRuntimeState(const TArray<FName>& DataLayerNames, EDataLayerRuntimeState State) const;

	/** 读取 Actor 所属的 DataLayerInstance，运行时可用于反查 Actor 随哪些层流送。 */
	GENERICWORLDPARTITIONFRAMEWORK_API TArray<UDataLayerInstance*> GetActorDataLayerInstances(const AActor* Actor) const;

	/** 读取 Actor 所属 DataLayer 名称；编辑器下优先使用 Actor 记录的实例名。 */
	GENERICWORLDPARTITIONFRAMEWORK_API TArray<FName> GetActorDataLayerInstanceNames(const AActor* Actor) const;

	/** 读取 Runtime Cell 绑定的 DataLayerInstance，便于分析 Cell 来自哪些层。 */
	GENERICWORLDPARTITIONFRAMEWORK_API TArray<UDataLayerInstance*> GetCellDataLayerInstances(UWorldPartitionRuntimeCell* Cell) const;

	/** 读取 Runtime Cell 绑定的 DataLayer 名称，适合蓝图侧轻量展示或比对。 */
	GENERICWORLDPARTITIONFRAMEWORK_API TArray<FName> GetCellDataLayerInstanceNames(UWorldPartitionRuntimeCell* Cell) const;

private:
	/** 返回 UE 原生 WorldPartitionSubsystem，用于查询全局流送完成状态。 */
	UWorldPartitionSubsystem* GetNativeWorldPartitionSubsystem() const;

	/** 把本帧提交的句柄延后到下一帧统一执行，便于合并同一 Cell 的冲突请求。 */
	void ExecuteHandleNextTick();

	/** 解析待执行句柄的 Cell 冲突，保留最新请求后启动各个句柄。 */
	void ExecuteHandles();

	/** 预留单个 Cell 完成回调入口，供后续统计或 GameplayMessage 扩展。 */
	void OnHandleCellOnceFinish(UWorldPartitionHandle* InHandle, UWorldPartitionRuntimeCell* InCell);

	/** 句柄整体完成后解绑子系统监听，并从活动队列中移除。 */
	void OnHandleCellFinish(UWorldPartitionHandle* InHandle);

private:
	/** 合并本帧请求时使用的下一帧执行定时器。 */
	FTimerHandle NextTickTimerHandle;

	/** 已经启动且仍在等待 Cell 状态变化的活动句柄。 */
	UPROPERTY()
	TArray<TObjectPtr<UWorldPartitionHandle>> WorldPartitionHandles;

	/** 本帧刚提交、等待下一帧冲突合并后启动的句柄。 */
	UPROPERTY()
	TArray<TObjectPtr<UWorldPartitionHandle>> TargetWorldPartitionHandles;
};
