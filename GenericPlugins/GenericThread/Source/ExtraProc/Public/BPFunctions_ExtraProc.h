// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExtraProcType.h"
#include "ThreadType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_ExtraProc.generated.h"

/** 将外部进程启动、查询和终止能力暴露给蓝图，内部复用 GenericThread 的句柄结果体系。 */
UCLASS(MinimalAPI)
class UBPFunctions_ExtraProc : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 返回项目 Extras/Proc 目录，供蓝图展示或放置外部工具。 */
	UFUNCTION(BlueprintPure, Category="Extra Proc")
	static EXTRAPROC_API FString GetExtraProcDir();

	/** 按配置启动外部进程，并把线程 GUID 包装为蓝图可持有的句柄。 */
	UFUNCTION(BlueprintCallable, Category="Extra Proc")
	static EXTRAPROC_API bool LaunchExtraProc(const FProcStartUpInfo& Info, FThreadHandle& ProcHandle);

	/** 通过通用线程结果查询返回外部进程的状态、耗时、输出和退出码信息。 */
	UFUNCTION(BlueprintPure, Category="Extra Proc")
	static EXTRAPROC_API bool GetExtraProcResult(const FThreadHandle& ProcHandle, FThreadExecutionResult& Result);

	/** 通过通用线程输出查询读取外部进程当前或最终缓存输出。 */
	UFUNCTION(BlueprintPure, Category="Extra Proc")
	static EXTRAPROC_API bool GetExtraProcOutput(const FThreadHandle& ProcHandle, FString& Output);

	/** 从外部进程结果快照中读取返回码，只有进程完成并写入退出码后返回 true。 */
	UFUNCTION(BlueprintPure, Category="Extra Proc")
	static EXTRAPROC_API bool GetExtraProcReturnCode(const FThreadHandle& ProcHandle, int32& ReturnCode);

	/** 终止句柄对应的外部进程，并将传入句柄复位以避免后续误用。 */
	UFUNCTION(BlueprintCallable, Category="Extra Proc")
	static EXTRAPROC_API void TerminationExtraProc(FThreadHandle& ProcHandle, bool bKillTree = false);
};
