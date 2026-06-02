// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelStreamingType.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "GenericLevelStreamingSubsystem.generated.h"

class USetLevelStreamingVisibilityHandle;
class UUnLoadLevelStreamingHandle;
class ULoadLevelStreamingHandle;
class ULevelStreamingHandle;
class UGenericLevelStreamingSubsystem;
class ULevelStreaming;
class UWorld;

USTRUCT(BlueprintType)
struct GENERICLEVELSTREAMINGFRAMEWORK_API FOnLoadLevelStreamingHandleRegisteredMessage
{
	GENERATED_BODY()

	/** 标识发出本次事件的世界级流送子系统，监听方可据此区分 PIE 多世界或多地图上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Load Level Streaming Handle Registered Message")
	TObjectPtr<UGenericLevelStreamingSubsystem> GenericLevelStreamingSubsystem = nullptr;

	/** 指向刚进入目标队列的加载句柄，后续单项完成和整批完成仍由句柄自身事件驱动。 */
	UPROPERTY(BlueprintReadOnly, Category="Load Level Streaming Handle Registered Message")
	TObjectPtr<ULoadLevelStreamingHandle> Handle = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICLEVELSTREAMINGFRAMEWORK_API FOnUnLoadLevelStreamingHandleRegisteredMessage
{
	GENERATED_BODY()

	/** 标识发出本次事件的世界级流送子系统，监听方可据此区分 PIE 多世界或多地图上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Unload Level Streaming Handle Registered Message")
	TObjectPtr<UGenericLevelStreamingSubsystem> GenericLevelStreamingSubsystem = nullptr;

	/** 指向刚进入目标队列的卸载句柄，监听方可读取其目标关卡集合或绑定句柄完成事件。 */
	UPROPERTY(BlueprintReadOnly, Category="Unload Level Streaming Handle Registered Message")
	TObjectPtr<UUnLoadLevelStreamingHandle> Handle = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICLEVELSTREAMINGFRAMEWORK_API FOnSetLevelStreamingVisibilityHandleRegisteredMessage
{
	GENERATED_BODY()

	/** 标识发出本次事件的世界级流送子系统，监听方可据此区分 PIE 多世界或多地图上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Set Level Streaming Visibility Handle Registered Message")
	TObjectPtr<UGenericLevelStreamingSubsystem> GenericLevelStreamingSubsystem = nullptr;

	/** 指向刚进入目标队列的可见性句柄，监听方可继续跟踪实际显示或隐藏完成时机。 */
	UPROPERTY(BlueprintReadOnly, Category="Set Level Streaming Visibility Handle Registered Message")
	TObjectPtr<USetLevelStreamingVisibilityHandle> Handle = nullptr;
};

/** 记录同一帧内某个流关卡被哪些句柄修改，供子系统在真正执行前裁剪冲突请求。 */
USTRUCT()
struct FLevelStreamConflict
{
	GENERATED_BODY()

public:
	/** 默认保持空目标和未加载状态，等待 ExecuteHandles 按当前世界快照填充。 */
	FLevelStreamConflict() { return; }

	bool operator==(const FLevelStreamConflict& Other) const { return Level == Other.Level; }
	bool operator==(const TSoftObjectPtr<UWorld>& Other) const { return Level == Other; }
	bool operator!=(const FLevelStreamConflict& Other) const { return !(*this == Other); }
	bool operator!=(const TSoftObjectPtr<UWorld>& Other) const { return !(*this == Other); }

public:
	/** 当前冲突桶对应的流关卡资产。 */
	UPROPERTY()
	TSoftObjectPtr<UWorld> Level;

	/** 子系统调度前采集的加载状态快照，用于后续扩展冲突策略。 */
	UPROPERTY()
	bool bIsLevelLoaded = false;

	/** 子系统调度前采集的可见状态快照，用于判断请求是否已经满足。 */
	UPROPERTY()
	bool bIsLevelVisible = false;

	/** 本帧所有准备修改该关卡的句柄，顺序与目标句柄队列一致。 */
	UPROPERTY()
	TArray<TObjectPtr<ULevelStreamingHandle>> ModifyHandles;
};

/** 非 World Partition 世界使用的流关卡调度中心，负责校验关卡、创建句柄、合并同帧冲突并转发完成事件。 */
UCLASS(MinimalAPI)
class UGenericLevelStreamingSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	static GENERICLEVELSTREAMINGFRAMEWORK_API UGenericLevelStreamingSubsystem* Get(const UObject* WorldContextObject);

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

public:
	/** 为单个关卡创建加载句柄；实际执行会推迟到下一帧统一处理冲突。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API ULoadLevelStreamingHandle* LoadLevel(const TSoftObjectPtr<UWorld>& Level, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 为关卡列表创建统一加载策略的句柄，并按列表顺序触发单项完成回调。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API ULoadLevelStreamingHandle* LoadLevels(const TArray<TSoftObjectPtr<UWorld>>& Levels, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish = FOnHandleLevelStreamingOnceFinish(), const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 校验加载设置并加入目标句柄队列；同帧内后提交的同关卡请求会覆盖更早请求。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API ULoadLevelStreamingHandle* LoadLevelsBySetting(const TArray<FLoadLevelStreamingSetting>& InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish = FOnHandleLevelStreamingOnceFinish(), const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 为单个关卡创建卸载句柄，适合蓝图或 C++ 触发局部区域清理。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API UUnLoadLevelStreamingHandle* UnloadLevel(const TSoftObjectPtr<UWorld>& Level, bool bShouldBlockOnUnload, const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 为关卡列表创建统一卸载策略的句柄，并在每个关卡卸载后通知调用方。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API UUnLoadLevelStreamingHandle* UnloadLevels(const TArray<TSoftObjectPtr<UWorld>>&, bool bShouldBlockOnUnload, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish = FOnHandleLevelStreamingOnceFinish(), const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 校验卸载设置并排队执行，避免不存在于当前世界的关卡进入 UE latent 卸载流程。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API UUnLoadLevelStreamingHandle* UnloadLevelsBySetting(const TArray<FUnloadLevelStreamingSetting>& InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish = FOnHandleLevelStreamingOnceFinish(), const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 为单个关卡创建可见性句柄；显示未加载关卡时句柄会先发起加载。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API USetLevelStreamingVisibilityHandle* SetLevelVisibility(const TSoftObjectPtr<UWorld>& Level, bool bVisible, const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 为关卡列表创建统一目标状态的可见性句柄。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API USetLevelStreamingVisibilityHandle* SetLevelsVisibility(const TArray<TSoftObjectPtr<UWorld>>& Levels, bool bVisible, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish = FOnHandleLevelStreamingOnceFinish(), const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 校验可见性设置并排队执行，让显示、隐藏请求与加载、卸载请求共享同一套冲突裁剪。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API USetLevelStreamingVisibilityHandle* SetLevelsVisibilityBySetting(const TArray<FSetLevelStreamingVisibilitySetting>& InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish = FOnHandleLevelStreamingOnceFinish(), const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 收集当前世界中未加载且可手动控制的流关卡，排除已加载、已可见和 AlwaysLoaded 关卡。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API TArray<TSoftObjectPtr<UWorld>> GetCurrentWorldLevelStreamingList() const;

	/** 将当前世界可手动控制的未加载流关卡作为隐藏预加载请求提交。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API ULoadLevelStreamingHandle* LoadCurrentWorldLevelStreaming(const FOnHandleLevelStreamingOnceFinish& OnOnceFinish = FOnHandleLevelStreamingOnceFinish(), const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 将当前世界已加载且可手动控制的流关卡提交为批量卸载请求。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API UUnLoadLevelStreamingHandle* UnLoadCurrentWorldLevelStreaming(const FOnHandleLevelStreamingOnceFinish& OnOnceFinish = FOnHandleLevelStreamingOnceFinish(), const FOnHandleLevelStreamingFinish& OnFinish = FOnHandleLevelStreamingFinish());

	/** 用软引用路径查找当前世界中的 ULevelStreaming 实例，供句柄读取实时加载和可见状态。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API ULevelStreaming* GetLevelStreaming(const TSoftObjectPtr<UWorld>& Level) const;

	/** 按包名判断目标软引用是否属于当前 Persistent World 的 StreamingLevels。 */
	GENERICLEVELSTREAMINGFRAMEWORK_API bool IsCurrentWorldContainLevel(const TSoftObjectPtr<UWorld>& Level) const;

#if WITH_DEV_AUTOMATION_TESTS

	/** 暴露下一帧调度句柄，供自动化测试确认请求是否被合并到同一轮执行。 */
	FTimerHandle& GetNextTickTimerHandleForTests() { return NextTickTimerHandle; }

	/** 暴露正在执行的句柄列表，供自动化测试检查完成清理。 */
	TArray<TObjectPtr<ULevelStreamingHandle>>& GetLevelStreamingHandlesForTests() { return LevelStreamingHandles; }

	/** 暴露下一帧待执行的句柄列表，供自动化测试检查冲突裁剪前状态。 */
	TArray<TObjectPtr<ULevelStreamingHandle>>& GetTargetLevelStreamingHandlesForTests() { return TargetLevelStreamingHandles; }

#endif

private:
	/** 用下一帧定时器把同一帧提交的多个请求合并到一次冲突处理。 */
	FTimerHandle NextTickTimerHandle;

	/** 刷新下一帧执行入口，确保最新一批目标句柄在同一轮统一处理。 */
	void ExecuteHandleNextTick();

	/** 为当前世界建立流关卡快照，裁剪同关卡重复请求，并启动保留下来的句柄。 */
	void ExecuteHandles();

	/** 接收句柄单关卡完成事件，当前保留扩展点用于后续统计或调试。 */
	void OnHandleLevelOnceFinish(ULevelStreamingHandle* InHandle, TSoftObjectPtr<UWorld> InLevel);

	/** 句柄整批完成后解绑事件并从运行队列移除，避免已完成请求继续持有子系统引用。 */
	void OnHandleLevelFinish(ULevelStreamingHandle* InHandle);

private:
	/** 正在执行的句柄集合，用于保持对象生命周期并在完成时清理。 */
	UPROPERTY()
	TArray<TObjectPtr<ULevelStreamingHandle>> LevelStreamingHandles;

	/** 当前帧新提交、等待下一帧冲突裁剪和启动的句柄集合。 */
	UPROPERTY()
	TArray<TObjectPtr<ULevelStreamingHandle>> TargetLevelStreamingHandles;
};
