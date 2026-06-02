// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericEngineSubsystem.h"
#include "ThreadType.h"
#include "GenericThreadSubsystem.generated.h"

class FGenericThread;

/** 维护已启动 GenericThread 的活动注册表和结果缓存，是句柄查询线程状态的中心入口。 */
UCLASS(MinimalAPI)
class UGenericThreadSubsystem : public UGenericEngineSubsystem
{
	GENERATED_BODY()

public:
	static GENERICTHREADSYSTEM_API UGenericThreadSubsystem* Get();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:
#if WITH_EDITOR
	/** PIE 结束时终止所有仍在运行的线程，避免编辑器残留后台任务。 */
	void EndPIE(bool bIsSimulating);
#endif

	/** 遍历活动注册表终止线程，并把终止结果写入缓存后清空映射。 */
	void KillAllThread();

private:
	/** 接收 FGenericThread 的注册广播，把线程加入活动映射并绑定终态回调。 */
	void RegisterThread(TSharedPtr<FGenericThread> Thread);

	/** 在终态回调回到游戏线程后移除活动映射，并按完成或终止状态缓存快照。 */
	void UnRegisterThread(const TSharedPtr<FGenericThread>& Thread);

	/** 响应线程终止广播，把注销工作切回游戏线程执行以安全访问子系统状态。 */
	void OnThreadTerminated(FGuid ThreadGuid);

	/** 响应线程完成广播，把注销工作切回游戏线程执行以缓存最终结果。 */
	void OnThreadCompleted(FGuid ThreadGuid);

public:
	/** 返回当前仍在活动注册表中的所有线程 GUID。 */
	GENERICTHREADSYSTEM_API TArray<FGuid> GetAllThreadGuid() const;

	/** 返回当前仍在运行管理中的线程对象列表。 */
	GENERICTHREADSYSTEM_API TArray<TSharedPtr<FGenericThread>> GetAllThreads() const;

	/** 返回活动线程映射的副本，供调试或批量查询当前注册状态。 */
	GENERICTHREADSYSTEM_API TMap<FGuid, TSharedPtr<FGenericThread>> GetThreadMapping() const { return ThreadMapping; }

	/** 按句柄 GUID 查询活动线程，已完成或终止线程不会从这里返回。 */
	GENERICTHREADSYSTEM_API TSharedPtr<FGenericThread> GetThreadByGuid(const FGuid& ThreadGuid) const;

	/** 优先构建运行中实时结果，找不到活动线程时返回已缓存终态。 */
	GENERICTHREADSYSTEM_API bool GetThreadResultByGuid(const FGuid& ThreadGuid, FThreadExecutionResult& OutResult) const;

	/** 按 GUID 取出活动线程并转换为具体派生类型，ExtraProc 终止流程用它访问专用接口。 */
	template <typename T>
	TSharedPtr<T> GetThread(const FGuid& ThreadGuid) { return StaticCastSharedPtr<T>(GetThreadByGuid(ThreadGuid)); }

private:
	/** 从线程对象采集句柄、状态、耗时、输出和退出码，生成查询接口返回的统一快照。 */
	FThreadExecutionResult BuildThreadResult(const TSharedPtr<FGenericThread>& Thread, EThreadExecutionState State) const;

	/** 活动线程映射，注册后用于按 GUID 快速定位仍在运行的线程对象。 */
	TMap<FGuid, TSharedPtr<FGenericThread>> ThreadMapping;

	/** 终态结果缓存，线程注销后仍允许蓝图通过旧句柄查询最后结果。 */
	TMap<FGuid, FThreadExecutionResult> ThreadResultMapping;
};
