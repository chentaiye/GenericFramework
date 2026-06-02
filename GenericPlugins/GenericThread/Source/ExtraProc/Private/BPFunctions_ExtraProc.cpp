// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions_ExtraProc.h"

#include "ExtraProcSubsystem.h"
#include "ExtraProcType.h"
#include "BPFunctions_Thread.h"
#include "StaticFunctions_ExtraProc.h"

FString UBPFunctions_ExtraProc::GetExtraProcDir()
{
	return UExtraProcSubsystem::GetExtraProcPath();
}

bool UBPFunctions_ExtraProc::LaunchExtraProc(const FProcStartUpInfo& Info, FThreadHandle& ProcHandle)
{
	ProcHandle = FThreadHandle();

	FGuid ProcID;
	if (FStaticFunctions_ExtraProc::LaunchExtraProc(Info, ProcID))
	{
		ProcHandle = FThreadHandle(ProcID);
		return true;
	}

	return false;
}

bool UBPFunctions_ExtraProc::GetExtraProcResult(const FThreadHandle& ProcHandle, FThreadExecutionResult& Result)
{
	return UBPFunctions_Thread::GetThreadResult(ProcHandle, Result);
}

bool UBPFunctions_ExtraProc::GetExtraProcOutput(const FThreadHandle& ProcHandle, FString& Output)
{
	return UBPFunctions_Thread::GetThreadOutput(ProcHandle, Output);
}

bool UBPFunctions_ExtraProc::GetExtraProcReturnCode(const FThreadHandle& ProcHandle, int32& ReturnCode)
{
	ReturnCode = 0;

	FThreadExecutionResult Result;
	if (!GetExtraProcResult(ProcHandle, Result) || !Result.bHasExitCode)
	{
		return false;
	}

	ReturnCode = Result.ExitCode;
	return true;
}

void UBPFunctions_ExtraProc::TerminationExtraProc(FThreadHandle& ProcHandle, bool bKillTree)
{
	if (!ProcHandle.IsValid())
	{
		return;
	}

	FStaticFunctions_ExtraProc::TerminateExtraProc(ProcHandle.GetThreadGuid(), bKillTree);
	ProcHandle = FThreadHandle();
}
