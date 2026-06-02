// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions_Thread.h"

#include "GenericThread.h"
#include "GenericThreadSubsystem.h"

bool UBPFunctions_Thread::IsThreadValid(const FThreadHandle& ThreadHandle)
{
	FThreadExecutionResult Result;
	return GetThreadResult(ThreadHandle, Result);
}

bool UBPFunctions_Thread::IsThreadRunning(const FThreadHandle& ThreadHandle)
{
	FThreadExecutionResult Result;
	return GetThreadResult(ThreadHandle, Result) && Result.State == EThreadExecutionState::Running;
}

bool UBPFunctions_Thread::GetThreadName(const FThreadHandle& ThreadHandle, FString& ThreadName)
{
	ThreadName.Reset();

	if (!ThreadHandle.IsValid())
	{
		return false;
	}

	FThreadExecutionResult Result;
	if (!GetThreadResult(ThreadHandle, Result))
	{
		return false;
	}

	ThreadName = Result.ThreadName;
	return true;
}

bool UBPFunctions_Thread::GetThreadDuration(const FThreadHandle& ThreadHandle, FTimespan& Duration)
{
	Duration = FTimespan::Zero();

	if (!ThreadHandle.IsValid())
	{
		return false;
	}

	FThreadExecutionResult Result;
	if (!GetThreadResult(ThreadHandle, Result))
	{
		return false;
	}

	Duration = Result.Duration;
	return true;
}

bool UBPFunctions_Thread::GetThreadOutput(const FThreadHandle& ThreadHandle, FString& Output)
{
	Output.Reset();

	if (!ThreadHandle.IsValid())
	{
		return false;
	}

	if (UGenericThreadSubsystem* ThreadManager = UGenericThreadSubsystem::Get())
	{
		FThreadExecutionResult Result;
		if (!ThreadManager->GetThreadResultByGuid(ThreadHandle.GetThreadGuid(), Result))
		{
			return false;
		}

		Output = Result.Output;
		return true;
	}

	return false;
}

bool UBPFunctions_Thread::GetThreadResult(const FThreadHandle& ThreadHandle, FThreadExecutionResult& Result)
{
	Result = FThreadExecutionResult();

	if (!ThreadHandle.IsValid())
	{
		return false;
	}

	if (UGenericThreadSubsystem* ThreadManager = UGenericThreadSubsystem::Get())
	{
		return ThreadManager->GetThreadResultByGuid(ThreadHandle.GetThreadGuid(), Result);
	}

	return false;
}

bool UBPFunctions_Thread::EqualEqual_ThreadHandle(const FThreadHandle& A, const FThreadHandle& B)
{
	return A == B;
}

bool UBPFunctions_Thread::NotEqual_ThreadHandle(const FThreadHandle& A, const FThreadHandle& B)
{
	return A != B;
}
