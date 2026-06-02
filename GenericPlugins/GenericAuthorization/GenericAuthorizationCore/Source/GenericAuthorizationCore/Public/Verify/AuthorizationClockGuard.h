// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** 封装本地时间回拨检测逻辑，子系统用它保护基于 Unix 时间的授权过期判断。 */
class GENERICAUTHORIZATIONCORE_API FAuthorizationClockGuard
{
public:
	/** 比较当前时间与已保存可信时间，超过允许回拨窗口时返回 ClockRollback 判定依据。 */
	static bool IsClockRollbackDetected(int64 CurrentUnixSeconds, int64 LastTrustedUnixSeconds, int32 AllowedRollbackSeconds);

	/** 保存当前时间和历史可信时间中的较大值，避免授权成功后降低防回拨基线。 */
	static int64 UpdateTrustedUnixSeconds(int64 CurrentUnixSeconds, int64 LastTrustedUnixSeconds);
};
