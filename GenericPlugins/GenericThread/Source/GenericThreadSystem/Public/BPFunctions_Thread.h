// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ThreadType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Thread.generated.h"

/** 将线程句柄查询能力暴露给蓝图，内部统一转发到线程子系统的活动映射或结果缓存。 */
UCLASS(MinimalAPI)
class UBPFunctions_Thread : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 通过结果查询判断句柄是否仍能在活动映射或终态缓存中解析。 */
	UFUNCTION(BlueprintPure, Category="Thread")
	static GENERICTHREADSYSTEM_API bool IsThreadValid(const FThreadHandle& ThreadHandle);

	/** 查询句柄对应结果并判断状态是否仍为 Running。 */
	UFUNCTION(BlueprintPure, Category="Thread")
	static GENERICTHREADSYSTEM_API bool IsThreadRunning(const FThreadHandle& ThreadHandle);

	/** 从结果快照中取回线程名，失败时保持输出字符串为空。 */
	UFUNCTION(BlueprintPure, Category="Thread")
	static GENERICTHREADSYSTEM_API bool GetThreadName(const FThreadHandle& ThreadHandle, FString& ThreadName);

	/** 从结果快照中取回当前或最终耗时，失败时返回零时长。 */
	UFUNCTION(BlueprintPure, Category="Thread")
	static GENERICTHREADSYSTEM_API bool GetThreadDuration(const FThreadHandle& ThreadHandle, FTimespan& Duration);

	/** 通过线程子系统读取输出缓存，兼容运行中线程和已注销的终态结果。 */
	UFUNCTION(BlueprintPure, Category="Thread")
	static GENERICTHREADSYSTEM_API bool GetThreadOutput(const FThreadHandle& ThreadHandle, FString& Output);

	/** 返回统一线程结果快照，是其他蓝图查询函数复用的基础入口。 */
	UFUNCTION(BlueprintPure, Category="Thread")
	static GENERICTHREADSYSTEM_API bool GetThreadResult(const FThreadHandle& ThreadHandle, FThreadExecutionResult& Result);

public:
	/** 为蓝图 == 节点比较两个句柄是否引用同一个线程 GUID。 */
	UFUNCTION(BlueprintPure, Category="Thread", meta=(CompactNodeTitle="==", ScriptMethod="Equals", ScriptOperator="==", Keywords="==equal"))
	static GENERICTHREADSYSTEM_API bool EqualEqual_ThreadHandle(const FThreadHandle& A, const FThreadHandle& B);

	/** 为蓝图 != 节点比较两个句柄是否引用不同线程 GUID。 */
	UFUNCTION(BlueprintPure, Category="Thread", meta=(CompactNodeTitle="!=", ScriptMethod="NotEqual", ScriptOperator="!=", Keywords="!=not equal"))
	static GENERICTHREADSYSTEM_API bool NotEqual_ThreadHandle(const FThreadHandle& A, const FThreadHandle& B);
};
