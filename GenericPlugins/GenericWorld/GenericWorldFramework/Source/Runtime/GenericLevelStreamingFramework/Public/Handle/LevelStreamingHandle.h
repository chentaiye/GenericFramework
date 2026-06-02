// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Obect/GenericObject.h"
#include "LevelStreamingHandle.generated.h"

class ULevelStreamingHandle;

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnLevelStreamingHandleOnceFinish, ULevelStreamingHandle*, TSoftObjectPtr<UWorld>)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnLevelStreamingHandleFinish, ULevelStreamingHandle*)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBPDelegate_OnLevelStreamingHandleOnceFinish, ULevelStreamingHandle*, InHandle, TSoftObjectPtr<UWorld>, InLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPDelegate_OnLevelStreamingHandleFinish, ULevelStreamingHandle*, InHandle);

/** 关卡流送请求的执行句柄，负责按队列推进单个流关卡操作，并把单项完成与整批完成同步给 C++ 和蓝图监听者。 */
UCLASS(Abstract, MinimalAPI)
class ULevelStreamingHandle : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 从当前队列索引开始执行；如果队列已经被冲突裁剪为空，会直接触发整批完成。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming Handle|Handle")
	void Startup();

	/** 返回当前正在处理的队列索引，派生句柄用它读取对应设置项。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	int32 GetLevelIndex() const;

	/** 返回句柄当前保留的流关卡数量，可用于蓝图侧展示本批请求规模。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	int32 GetLevelCount();

	/** 返回已经完成的关卡数量；运行中为当前索引，整批完成后为队列数量。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	int32 GetCompletedLevelCount();

	/** 返回尚未完成的关卡数量；运行中包含当前正在等待 UE latent 回调的关卡。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	int32 GetRemainingLevelCount();

	/** 判断句柄是否已经进入执行流程且尚未广播整批完成。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	bool IsRunning() const;

	/** 判断本批请求是否已经广播整批完成；刚创建但未启动的句柄不会被视为完成。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	bool IsFinished() const;

	/** 判断当前索引是否仍指向一个等待处理或正在处理的关卡。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	bool HasPendingLevels();

	/** 判断索引能否在当前队列中解析出有效关卡。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	bool IsValidLevelIndex(int32 InIndex);

	/** 返回最近一次完成的流关卡；在单项完成事件和整批完成事件中可读取。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|State")
	TSoftObjectPtr<UWorld> GetLastFinishedLevel() const;

	/** 按队列索引读取目标关卡；无效索引返回空软引用，避免蓝图侧额外保护。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|Handle")
	TSoftObjectPtr<UWorld> GetLevelByIndex(int32 InIndex);

	/** 查找目标关卡在当前队列中的位置，使用软引用路径比较，避免为了查询而同步加载地图资源。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|Handle")
	int32 GetIndexByLevel(const TSoftObjectPtr<UWorld>& InLevel);

	/** 判断当前队列中是否包含指定关卡。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|Handle")
	bool ContainsLevel(const TSoftObjectPtr<UWorld>& InLevel);

	/** 从派生句柄的设置队列中移除指定关卡，通常由子系统在同帧冲突裁剪时调用。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming Handle|Handle")
	virtual void RemoveLevel(const TSoftObjectPtr<UWorld>& InLevel) PURE_VIRTUAL(ULevelStreamingHandle::RemoveLevel, ;)

	/** 暴露当前句柄会触达的关卡列表，供蓝图或子系统建立关卡到句柄的映射。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming Handle|Handle")
	virtual TArray<TSoftObjectPtr<UWorld>> GetLevels() PURE_VIRTUAL(ULevelStreamingHandle::GetLevels, return TArray<TSoftObjectPtr<UWorld>>{};)

	/** 执行指定索引对应的单关卡操作，派生类负责调用具体加载、卸载或可见性接口。 */
	UFUNCTION(Category="Level Streaming Handle|Handle")
	virtual void ExecuteHandle(int32 Index) PURE_VIRTUAL(ULevelStreamingHandle::ExecuteHandle,)

public:
	UPROPERTY(BlueprintAssignable, DisplayName="On Once Finish", Category="Events")
	FBPDelegate_OnLevelStreamingHandleOnceFinish BPDelegate_OnOnceFinish;

	UPROPERTY(BlueprintAssignable, DisplayName="On Finish", Category="Events")
	FBPDelegate_OnLevelStreamingHandleFinish BPDelegate_OnFinish;

public:
	/** 返回子系统监听的单关卡完成事件，用于记录完成关卡并驱动句柄清理。 */
	FOnLevelStreamingHandleOnceFinish& GetHandleOnceFinishEvent();

	/** 返回子系统监听的整批完成事件，用于移除正在执行的句柄引用。 */
	FOnLevelStreamingHandleFinish& GetHandleFinishEvent();

protected:
	/** 单个关卡操作完成后推进索引，并决定继续处理下一项还是结束整批请求。 */
	UFUNCTION()
	void OnOnceFinish();

	/** 派生类在单关卡完成时转发调用者传入的 OnceFinish 回调。 */
	virtual void HandleOnOnceFinish();

	/** 整批请求完成后重置索引，并广播最终完成事件。 */
	UFUNCTION(Category="Level Streaming Handle|Handle")
	void OnFinish();

	/** 派生类在整批完成时转发调用者传入的 Finish 回调。 */
	virtual void HandleOnFinish();

	/** 将最近完成的关卡广播给子系统、C++ 监听者和蓝图监听者。 */
	void BroadcastOnceFinish();

	/** 广播整批完成，让子系统解除事件绑定并释放队列引用。 */
	void BroadcastFinish();

private:
	/** 当前正在执行的关卡队列位置。 */
	int32 LevelIndex = 0;

	/** 标记句柄是否已启动且尚未完成，用于蓝图侧判断事件绑定后的实时状态。 */
	bool bIsRunning = false;

	/** 标记句柄是否已经完成过本批请求，区分未启动和已完成两种空闲状态。 */
	bool bIsFinished = false;

	/** 单关卡完成广播前缓存本次完成的关卡引用。 */
	TSoftObjectPtr<UWorld> LastFinishedLevel = nullptr;

	FOnLevelStreamingHandleOnceFinish OnOnceFinishEvent;

	FOnLevelStreamingHandleFinish OnFinishEvent;
};
