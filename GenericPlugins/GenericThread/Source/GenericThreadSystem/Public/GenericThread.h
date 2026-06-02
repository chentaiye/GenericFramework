// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include <atomic>
#include "CoreMinimal.h"
#include "HAL/CriticalSection.h"
#include "Misc/ScopeLock.h"
/* #include "GenericThreadRaw.generated.h" */
class FGenericThread;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnThreadRegister, TSharedPtr<FGenericThread>)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnThreadTerminated, FGuid)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnThreadCompleted, FGuid)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnThreadOutput, FString)

/** 提供通用线程生命周期骨架，负责启动 FRunnableThread、轮询输出并把终态同步给子系统。 */
class GENERICTHREADSYSTEM_API FGenericThread : public FRunnable, public TSharedFromThis<FGenericThread>
{
public:
	/** 初始化线程名称、栈大小和优先级，构造时生成供子系统注册使用的唯一 GUID。 */
	FGenericThread(const FString& InThreadName = TEXT("GenericThread"), uint32 InThreadSize = 0, EThreadPriority InThreadPriority = EThreadPriority::TPri_Normal);

	virtual ~FGenericThread() override;

	inline static FOnThreadRegister OnThreadRegisterEvent;

	/** 构造共享线程实例，供模板工厂和上层代码统一进入 Launch 流程。 */
	static TSharedPtr<FGenericThread> CreateThread(const FString& InThreadName, uint32 InThreadSize = 0, EThreadPriority InThreadPriority = EThreadPriority::TPri_Normal)
	{
		return MakeShareable(new FGenericThread(InThreadName, InThreadSize, InThreadPriority));
	}

public:
	/** 重置运行状态、创建可选管道、启动 FRunnableThread，并广播注册事件给线程子系统。 */
	bool Launch();

	/** 在不支持多线程的平台由外部 Tick 调用，模拟 Run 循环推进任务状态。 */
	void Update();

	/** 请求停止当前任务但不主动等待线程回收，供上层发出取消信号。 */
	void Cancel();

	/** 请求停止、等待线程结束、关闭管道，并在尚未终结时写入终止状态。 */
	void Terminate();

private:
	/** 记录完成或终止的唯一终态，避免清理路径重复广播结果。 */
	enum class EFinalizeState : uint8
	{
		/** 尚未完成或终止，运行循环仍可决定最终结果。 */
		None,

		/** 停止请求已经落定，子系统应按终止状态缓存结果。 */
		Terminated,

		/** 任务自然结束，子系统应按完成状态缓存结果。 */
		Completed
	};

	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;

protected:
	/** 执行一次状态推进，统一处理管道输出、停止请求和派生任务是否结束的轮询。 */
	void RunInternal();

	/** 记录结束时间并置停止标记，后续 RunInternal 会触发终止通知。 */
	void StopInternal();

	/** 在线程自然结束时关闭资源、广播完成事件并清除运行标志。 */
	void CompleteInternal();

protected:
	/** Launch 重置状态后调用，允许派生类在创建线程或进程前补齐参数。 */
	virtual void OnBeginLaunch() { return; }

	/** FRunnableThread 创建成功后调用，派生类可在此创建外部资源；返回 false 会让 Launch 回滚。 */
	virtual bool OnThreadCreated(FRunnableThread* InThread) { return true; }

	/** 由 RunInternal 轮询，用于判定派生任务是否仍在执行。 */
	virtual bool IsThreadRunning() { return true; }

	/** 终止通知落定前调用，派生类在此关闭进程句柄等资源。 */
	virtual void OnTerminated() { return; }

	/** 完成通知落定前调用，派生类在此读取退出码并释放资源。 */
	virtual void OnCompleted() { return; }

private:
	/** 读取管道增量输出，写入缓存并在存在监听者时按完整行广播。 */
	void ProcessOutput(const FString& Output);

	/** 以原子终态保证终止只广播一次，并调用派生清理钩子。 */
	void NotifyTerminated();

	/** 以原子终态保证完成只广播一次，并调用派生完成钩子。 */
	void NotifyCompleted();

	/** 关闭 Launch 创建的读写管道，避免完成或终止路径泄漏系统句柄。 */
	void ClosePipeHandles();

public:
	/** 返回线程子系统活动映射和结果缓存使用的唯一标识。 */
	FGuid GetThreadGuid() const { return ThreadGuid; }

	/** 返回基础线程名，用于创建实际 FRunnableThread 名称和结果快照。 */
	FString GetThreadName() { return ThreadName; }

	/** 设置基础线程名，Launch 时会附加递增索引生成实际线程名。 */
	void SetThreadName(const FString& InThreadName) { ThreadName = InThreadName; }

	/** 返回创建 FRunnableThread 时传入的栈大小。 */
	uint32 GetThreadSize() const { return ThreadSize; }

	/** 设置线程栈大小，需在 Launch 前配置。 */
	void SetThreadSize(const uint32 InThreadSize) { ThreadSize = InThreadSize; }

	/** 返回创建 FRunnableThread 时使用的调度优先级。 */
	EThreadPriority GetThreadPriority() const { return ThreadPriority; }

	/** 设置线程优先级，派生线程通常在构造阶段完成配置。 */
	void SetThreadPriority(const EThreadPriority InThreadPriority) { ThreadPriority = InThreadPriority; }

	/** 返回 Launch 是否会创建输出管道，用于判断 RunInternal 是否需要读取输出。 */
	bool GetIsCreatePipe() const { return bCreatePipe; }

	/** 配置 Launch 是否创建读写管道，ExtraProc 用它捕获外部进程输出。 */
	void SetIsCreatePipe(const bool CreatePipe) { bCreatePipe = CreatePipe; }

	/** 返回任务最后一次成功启动的 UTC 时间。 */
	FDateTime GetStartTime() const { return StartTime; }

	/** 返回任务完成、终止或停止请求写入的 UTC 时间。 */
	FDateTime GetEndTime() const { return EndTime; }

	/** 根据当前运行状态计算实时耗时或返回已记录的结束耗时。 */
	FTimespan GetDuration() const;

	/** 判断终结状态是否为自然完成，子系统注销时据此缓存结果。 */
	bool WasCompleted() const { return FinalizeState.load() == EFinalizeState::Completed; }

	/** 判断终结状态是否为终止，子系统注销时据此缓存结果。 */
	bool WasTerminated() const { return FinalizeState.load() == EFinalizeState::Terminated; }

	/** 返回当前对外可见运行状态，蓝图查询和单线程 Tick 都依赖它。 */
	bool GetIsRunning() const { return bIsRunning.load(); }

	/** 返回 Run 和单线程 Update 每轮轮询之间的休眠间隔。 */
	float GetSleepInterval() const { return SleepInterval; }

	/** 设置轮询休眠间隔，用于测试或派生任务调整响应速度。 */
	void SetSleepInterval(const float InSleepInterval) { SleepInterval = InSleepInterval; }

	/** 暴露终止事件给线程子系统注册注销回调。 */
	FOnThreadTerminated& GetOnTerminated() { return OnTerminatedEvent; }

	/** 暴露完成事件给线程子系统注册注销回调。 */
	FOnThreadCompleted& GetOnCompleted() { return OnCompletedEvent; }

	/** 在线程安全锁保护下返回当前输出缓存，供子系统构建结果快照。 */
	FString GetOutput()
	{
		FScopeLock Lock(&OutputBufferCriticalSection);
		return OutputBuffer;
	}

public:
	/** 允许派生实现向结果快照提供退出码，基础线程默认没有退出码。 */
	virtual bool TryGetExitCode(int32& OutExitCode) const { return false; }

	/** 暴露输出行事件，ProcessOutput 在收到完整行时广播。 */
	FOnThreadOutput& GetOnOutput() { return OnOutputEvent; }

protected:
	/** 线程子系统映射的键，构造时生成并贯穿结果缓存。 */
	FGuid ThreadGuid;

	/** 线程的基础名称，Launch 会用它生成实际 FRunnableThread 名称。 */
	FString ThreadName;

	/** 创建底层线程时使用的栈大小配置。 */
	uint32 ThreadSize;

	/** 创建底层线程时使用的调度优先级。 */
	EThreadPriority ThreadPriority;

	/** Launch 创建出的底层线程指针，Terminate 负责等待并删除。 */
	FRunnableThread* Thread;

	/** 控制 Launch 是否创建 ReadPipe 和 WritePipe。 */
	uint8 bCreatePipe : 1;

	/** 读端管道，RunInternal 从这里读取外部进程输出。 */
	void* ReadPipe;

	/** 写端管道，传给 CreateProc 作为子进程输出重定向端。 */
	void* WritePipe;

	/** 记录本次任务真正进入运行状态的 UTC 时间。 */
	FDateTime StartTime;

	/** 记录完成、终止或停止请求发生时的 UTC 时间。 */
	FDateTime EndTime;

	/** 控制 Run 循环是否继续轮询，是线程生命周期的底层活跃标志。 */
	std::atomic<bool> bWorkerActive;

	/** 标记任务对外可见运行状态，蓝图查询和单线程 Tick 依赖它。 */
	std::atomic<bool> bIsRunning;

	/** 标记外部停止请求，RunInternal 据此进入终止分支。 */
	std::atomic<bool> bIsStopping;

	/** 记录唯一终态，避免完成和终止回调重复写入结果。 */
	std::atomic<EFinalizeState> FinalizeState;

	/** Run 和 Update 每轮休眠间隔，用于降低轮询管道和状态的 CPU 占用。 */
	float SleepInterval;

	FOnThreadTerminated OnTerminatedEvent;
	FOnThreadCompleted OnCompletedEvent;

	/** 保护输出缓存的跨线程访问，ProcessOutput 和 GetOutput 共用这把锁。 */
	mutable FCriticalSection OutputBufferCriticalSection;

	/** 累积管道输出；没有输出监听者时保留完整内容，供结果查询返回。 */
	FString OutputBuffer;

	FOnThreadOutput OnOutputEvent;
};
