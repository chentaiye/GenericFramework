// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Async/TaskGraphInterfaces.h"
#include "BPFunctions_ExtraProc.h"
#include "ExtraProcThread.h"
#include "HAL/PlatformMisc.h"
#include "Misc/Paths.h"

namespace ExtraProcTests
{
	static constexpr float WaitIntervalSeconds = 0.01f;
	static constexpr double DefaultTimeoutSeconds = 5.0;

	static bool WaitUntil(const TFunctionRef<bool()>& Predicate, const double TimeoutSeconds = DefaultTimeoutSeconds)
	{
		const double Deadline = FPlatformTime::Seconds() + TimeoutSeconds;
		while (FPlatformTime::Seconds() < Deadline)
		{
			FTaskGraphInterface::Get().ProcessThreadUntilIdle(ENamedThreads::GameThread);
			if (Predicate())
			{
				return true;
			}

			FPlatformProcess::Sleep(WaitIntervalSeconds);
		}

		FTaskGraphInterface::Get().ProcessThreadUntilIdle(ENamedThreads::GameThread);
		return Predicate();
	}
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FExtraProcCompletionAutomationTest,
	"GenericFramework.ExtraProc.CompletionCachesOutputAndReturnCode",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FExtraProcCompletionAutomationTest::RunTest(const FString& Parameters)
{
	using namespace ExtraProcTests;

	const FString ShellPath = FPlatformMisc::GetEnvironmentVariable(TEXT("ComSpec"));
	TestFalse(TEXT("ComSpec should resolve to a command shell"), ShellPath.IsEmpty());
	TestTrue(TEXT("Resolved shell path should exist"), FPaths::FileExists(ShellPath));
	if (ShellPath.IsEmpty() || !FPaths::FileExists(ShellPath))
	{
		return false;
	}

	const FString CommandLine = TEXT("/d /c \"echo extra-proc-output && exit /b 7\"");
	const TSharedPtr<FExtraProcThread> Thread = FExtraProcThread::CreateThread(ShellPath, CommandLine, true, false, true);
	const FThreadHandle ThreadHandle(Thread->GetThreadGuid());

	TestTrue(TEXT("Extra proc launch should succeed"), Thread->Launch());
	TestTrue(TEXT("Extra proc should finish and cache its result"), WaitUntil([&ThreadHandle]()
	{
		FThreadExecutionResult Result;
		return UBPFunctions_ExtraProc::GetExtraProcResult(ThreadHandle, Result) && Result.State == EThreadExecutionState::Completed;
	}));

	FThreadExecutionResult Result;
	TestTrue(TEXT("Extra proc result should be available"), UBPFunctions_ExtraProc::GetExtraProcResult(ThreadHandle, Result));
	TestEqual(TEXT("Extra proc state"), Result.State, EThreadExecutionState::Completed);
	TestTrue(TEXT("Extra proc should expose exit code"), Result.bHasExitCode);
	TestEqual(TEXT("Extra proc exit code"), Result.ExitCode, 7);
	TestTrue(TEXT("Extra proc output should contain the echoed text"), Result.Output.Contains(TEXT("extra-proc-output")));

	FString Output;
	TestTrue(TEXT("Blueprint helper should return extra proc output"), UBPFunctions_ExtraProc::GetExtraProcOutput(ThreadHandle, Output));
	TestTrue(TEXT("Blueprint output should contain the echoed text"), Output.Contains(TEXT("extra-proc-output")));

	int32 ReturnCode = 0;
	TestTrue(TEXT("Blueprint helper should return extra proc exit code"), UBPFunctions_ExtraProc::GetExtraProcReturnCode(ThreadHandle, ReturnCode));
	TestEqual(TEXT("Blueprint helper exit code"), ReturnCode, 7);

	return true;
}

#endif
