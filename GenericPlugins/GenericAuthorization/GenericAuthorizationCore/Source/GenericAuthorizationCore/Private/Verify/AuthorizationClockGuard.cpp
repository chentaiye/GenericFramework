// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Verify/AuthorizationClockGuard.h"

bool FAuthorizationClockGuard::IsClockRollbackDetected(const int64 CurrentUnixSeconds, const int64 LastTrustedUnixSeconds, const int32 AllowedRollbackSeconds)
{
	if (LastTrustedUnixSeconds <= 0)
	{
		return false;
	}

	return CurrentUnixSeconds + FMath::Max(0, AllowedRollbackSeconds) < LastTrustedUnixSeconds;
}

int64 FAuthorizationClockGuard::UpdateTrustedUnixSeconds(const int64 CurrentUnixSeconds, const int64 LastTrustedUnixSeconds)
{
	return FMath::Max(CurrentUnixSeconds, LastTrustedUnixSeconds);
}
