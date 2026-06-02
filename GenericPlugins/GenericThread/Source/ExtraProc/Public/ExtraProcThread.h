// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericSingleThread.h"
/** 将外部进程包装成 GenericSingleThread，复用线程注册、输出缓存和结果查询流程。 */
class FExtraProcThread : public FGenericSingleThread
{
	/* FExtraProcThread 自身接口 */
public:
	/** 初始化外部进程启动参数，并把通用线程配置调整为 ExtraProc 默认轮询设置。 */
	FExtraProcThread(const FString& InUrl, const FString& InParams, bool InRunInBackground, bool TerminateWithParentProc, bool InCreatePipe);

	virtual ~FExtraProcThread() override;

	/** 构造共享外部进程线程对象，供静态启动函数进入统一 Launch 流程。 */
	static TSharedPtr<FExtraProcThread> CreateThread(const FString& InUrl, const FString& InParams, bool InRunInBackground, bool TerminateWithParentProc, bool InCreatePipe)
	{
		return MakeShareable(new FExtraProcThread(InUrl, InParams, InRunInBackground, TerminateWithParentProc, InCreatePipe));
	}

public:
	/** 返回当前进程句柄，完成或终止清理后会被重置为空句柄。 */
	FProcHandle GetProcHandle() const { return ProcHandle; }

	/** 返回 CreateProc 写回的系统进程 ID，供日志或诊断使用。 */
	uint32 GetProcId() const { return ProcId; }

	/** 返回进程完成后缓存的返回码，只有 TryGetExitCode 成功时才应使用。 */
	int32 GetReturnCode() const { return ReturnCode; }

	/** 返回终止流程是否会递归结束子进程树。 */
	bool GetKillTree() const { return bKillTree; }

	/** 设置终止流程是否递归结束子进程树，TerminateExtraProc 会在终止前写入该值。 */
	void SetKillTree(const bool KillTree) { bKillTree = KillTree; }

	/** 返回将传给 CreateProc 的可执行文件绝对路径。 */
	FString GetUrl() const { return Url; }

	/** 设置可执行文件路径，需在 Launch 前完成以影响进程创建。 */
	void SetUrl(const FString& InUrl) { Url = InUrl; }

	/** 返回将传给外部进程的命令行参数字符串。 */
	FString GetParams() const { return Params; }

	/** 设置命令行参数，需在 Launch 前完成以影响进程创建。 */
	void SetParams(const FString& InParams) { Params = InParams; }

	/** 返回 CreateProc 使用的后台运行开关。 */
	bool GetRunInBackground() const { return bRunInBackground; }

	/** 设置进程是否后台或隐藏运行，需在 Launch 前配置。 */
	void SetRunInBackground(const bool RunInBackground) { bRunInBackground = RunInBackground; }

	/** 返回是否要求父进程退出时自动结束该外部进程。 */
	bool GetTerminateWithParentProc() const { return bTerminateWithParentProc; }

	/** 设置是否把外部进程绑定到父进程生命周期，Windows 下通过 Job 实现。 */
	void SetTerminateWithParentProc(const bool TerminateWithParentProc) { bTerminateWithParentProc = TerminateWithParentProc; }

	/** 拼接可执行路径和参数，用于启动成功日志展示实际命令行。 */
	FString GetCommandline() const { return FString::Printf(TEXT("%s %s"), *Url, *Params); }

	/* FGenericThread 钩子 */
protected:
	virtual void OnBeginLaunch() override;
	virtual bool OnThreadCreated(FRunnableThread* InThread) override;
	virtual bool IsThreadRunning() override;
	virtual void OnTerminated() override;
	virtual void OnCompleted() override;
	virtual bool TryGetExitCode(int32& OutExitCode) const override
	{
		if (!bHasReturnCode)
		{
			return false;
		}

		OutExitCode = ReturnCode;
		return true;
	}

	/* FExtraProcThread 状态字段 */
protected:
	/** FPlatformProcess 创建出的进程句柄，终态钩子负责关闭。 */
	FProcHandle ProcHandle;

	/** CreateProc 返回的系统进程 ID，保留给日志和诊断使用。 */
	uint32 ProcId;

	/** 进程完成后读取的返回码，蓝图通过结果快照访问。 */
	int32 ReturnCode;

	/** 标记 ReturnCode 是否已写入有效值或失败默认值。 */
	bool bHasReturnCode;

	/** 控制终止时是否递归杀掉子进程树，由 TerminateExtraProc 调用前设置。 */
	uint8 bKillTree : 1;

	/** 可执行文件绝对路径，OnThreadCreated 使用它创建进程。 */
	FString Url;

	/** 传给外部进程的命令行参数字符串。 */
	FString Params;

	/** 传给 CreateProc 的后台或隐藏运行开关。 */
	bool bRunInBackground;

	/** Windows 下把子进程加入 Job，确保父进程退出时一并结束。 */
	bool bTerminateWithParentProc;
};
