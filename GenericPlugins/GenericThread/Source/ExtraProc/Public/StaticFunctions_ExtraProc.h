// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExtraProcType.h"
/** 提供外部进程的静态启动和终止入口，负责把配置转换为 ExtraProc 线程操作。 */
class EXTRAPROC_API FStaticFunctions_ExtraProc
{
public:
	/** 按配置结构校验 Extras 下的文件并拼接参数，然后创建进程线程。 */
	static bool LaunchExtraProc(const FProcStartUpInfo& Info, FGuid& ProcId);

	/** 用已解析的路径和命令行创建 FExtraProcThread，启动成功后返回线程 GUID。 */
	static bool LaunchExtraProc(const FString& Urls, const FString& Params, bool RunInBackground, bool CreatePipe, bool TerminateWithParentProc, FGuid& OutProcId);

	/** 按 GUID 找到活动 ExtraProc 线程，设置杀进程树选项后触发终止。 */
	static void TerminateExtraProc(FGuid ProcId, bool bKillTree = false);
};
