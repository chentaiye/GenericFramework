// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
/* #include "WindowsExtraProcHelper.generated.h" */
#if PLATFORM_WINDOWS

/** 封装 Windows Job 绑定逻辑，让外部进程可随当前父进程退出而自动结束。 */
class FWindowsExtraProcHelper
{
public:
	/** 将进程句柄加入全局 Job 对象，供 TerminateWithParentProc 语义生效。 */
	static bool SetProcEndWithCurrentProcTermination(const FProcHandle& InProc);
};

#endif
