// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include <atomic>

#include "Async/TaskGraphInterfaces.h"
#include "BPFunctions_Thread.h"
#include "GenericThread.h"
#include "GenericThreadSubsystem.h"

namespace GenericThreadTests
{
	static constexpr float WaitIntervalSeconds = 0.01f;
	static constexpr double DefaultTimeoutSeconds = 2.0;

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

	class FAutomationCompletionThread final : public FGenericThread
	{
	public:
		FAutomationCompletionThread()
			: FGenericThread(TEXT("AutomationCompletionThread"))
		{
			SetSleepInterval(0.001f);
		}

		static TSharedPtr<FAutomationCompletionThread> CreateThread()
		{
			return MakeShareable(new FAutomationCompletionThread());
		}

		bool DidComplete() const
		{
			return bCompleted.load();
		}

	protected:
		virtual bool OnThreadCreated(FRunnableThread* InThread) override
		{
			OutputBuffer = TEXT("completion-output");
			return true;
		}

		virtual bool IsThreadRunning() override
		{
			return PollCount.fetch_add(1) < 1;
		}

		virtual void OnCompleted() override
		{
			bCompleted.store(true);
		}

	private:
		std::atomic<int32> PollCount{0};
		std::atomic<bool> bCompleted{false};
	};

	class FAutomationFailureThread final : public FGenericThread
	{
	public:
		FAutomationFailureThread()
			: FGenericThread(TEXT("AutomationFailureThread"))
		{
			SetSleepInterval(0.001f);
		}

		static TSharedPtr<FAutomationFailureThread> CreateThread()
		{
			return MakeShareable(new FAutomationFailureThread());
		}

	protected:
		virtual bool OnThreadCreated(FRunnableThread* InThread) override
		{
			return false;
		}
	};

	class FAutomationTerminateThread final : public FGenericThread
	{
	public:
		FAutomationTerminateThread()
			: FGenericThread(TEXT("AutomationTerminateThread"))
		{
			SetSleepInterval(0.001f);
		}

		static TSharedPtr<FAutomationTerminateThread> CreateThread()
		{
			return MakeShareable(new FAutomationTerminateThread());
		}

		bool DidTerminate() const
		{
			return bTerminated.load();
		}

	protected:
		virtual bool OnThreadCreated(FRunnableThread* InThread) override
		{
			OutputBuffer = TEXT("terminated-output");
			return true;
		}

		virtual bool IsThreadRunning() override
		{
			return true;
		}

		virtual void OnTerminated() override
		{
			bTerminated.store(true);
		}

	private:
		std::atomic<bool> bTerminated{false};
	};
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericThreadCompletionAutomationTest,
	"GenericFramework.GenericThread.CompletionCachesResult",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FGenericThreadCompletionAutomationTest::RunTest(const FString& Parameters)
{
	using namespace GenericThreadTests;

	UGenericThreadSubsystem* ThreadSubsystem = UGenericThreadSubsystem::Get();
	TestNotNull(TEXT("Thread subsystem should exist"), ThreadSubsystem);
	if (!ThreadSubsystem)
	{
		return false;
	}

	const TSharedPtr<FAutomationCompletionThread> Thread = FAutomationCompletionThread::CreateThread();
	const FThreadHandle ThreadHandle(Thread->GetThreadGuid());

	TestTrue(TEXT("Thread launch should succeed"), Thread->Launch());
	TestTrue(TEXT("Thread should complete"), WaitUntil([&Thread]() { return Thread->DidComplete() && !Thread->GetIsRunning(); }));
	TestTrue(TEXT("Completed thread should be unregistered"), WaitUntil([&ThreadSubsystem, &ThreadHandle]() { return !ThreadSubsystem->GetThreadByGuid(ThreadHandle.GetThreadGuid()).IsValid(); }));

	FThreadExecutionResult Result;
	TestTrue(TEXT("Completed thread result should be cached"), UBPFunctions_Thread::GetThreadResult(ThreadHandle, Result));
	TestEqual(TEXT("Completed thread state"), Result.State, EThreadExecutionState::Completed);
	TestEqual(TEXT("Completed thread output"), Result.Output, FString(TEXT("completion-output")));
	TestTrue(TEXT("Completed thread handle should remain queryable"), UBPFunctions_Thread::IsThreadValid(ThreadHandle));
	TestFalse(TEXT("Completed thread should not be running"), UBPFunctions_Thread::IsThreadRunning(ThreadHandle));

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericThreadLaunchFailureAutomationTest,
	"GenericFramework.GenericThread.LaunchFailureDoesNotRegister",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FGenericThreadLaunchFailureAutomationTest::RunTest(const FString& Parameters)
{
	UGenericThreadSubsystem* ThreadSubsystem = UGenericThreadSubsystem::Get();
	TestNotNull(TEXT("Thread subsystem should exist"), ThreadSubsystem);
	if (!ThreadSubsystem)
	{
		return false;
	}

	const TSharedPtr<GenericThreadTests::FAutomationFailureThread> Thread = GenericThreadTests::FAutomationFailureThread::CreateThread();
	const FThreadHandle ThreadHandle(Thread->GetThreadGuid());

	TestFalse(TEXT("Thread launch should fail"), Thread->Launch());
	TestFalse(TEXT("Failed thread should not have a live registration"), ThreadSubsystem->GetThreadByGuid(ThreadHandle.GetThreadGuid()).IsValid());

	FThreadExecutionResult Result;
	TestFalse(TEXT("Failed thread should not have a cached result"), UBPFunctions_Thread::GetThreadResult(ThreadHandle, Result));
	TestFalse(TEXT("Failed thread handle should be invalid"), UBPFunctions_Thread::IsThreadValid(ThreadHandle));

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericThreadTerminateAutomationTest,
	"GenericFramework.GenericThread.TerminateCachesResult",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FGenericThreadTerminateAutomationTest::RunTest(const FString& Parameters)
{
	using namespace GenericThreadTests;

	UGenericThreadSubsystem* ThreadSubsystem = UGenericThreadSubsystem::Get();
	TestNotNull(TEXT("Thread subsystem should exist"), ThreadSubsystem);
	if (!ThreadSubsystem)
	{
		return false;
	}

	const TSharedPtr<FAutomationTerminateThread> Thread = FAutomationTerminateThread::CreateThread();
	const FThreadHandle ThreadHandle(Thread->GetThreadGuid());

	TestTrue(TEXT("Thread launch should succeed"), Thread->Launch());
	TestTrue(TEXT("Thread should register"), WaitUntil([&ThreadSubsystem, &ThreadHandle]() { return ThreadSubsystem->GetThreadByGuid(ThreadHandle.GetThreadGuid()).IsValid(); }));

	Thread->Terminate();

	TestTrue(TEXT("Thread should terminate"), WaitUntil([&Thread]() { return Thread->DidTerminate() && !Thread->GetIsRunning(); }));
	TestTrue(TEXT("Terminated thread should be unregistered"), WaitUntil([&ThreadSubsystem, &ThreadHandle]() { return !ThreadSubsystem->GetThreadByGuid(ThreadHandle.GetThreadGuid()).IsValid(); }));

	FThreadExecutionResult Result;
	TestTrue(TEXT("Terminated thread result should be cached"), UBPFunctions_Thread::GetThreadResult(ThreadHandle, Result));
	TestEqual(TEXT("Terminated thread state"), Result.State, EThreadExecutionState::Terminated);
	TestEqual(TEXT("Terminated thread output"), Result.Output, FString(TEXT("terminated-output")));
	TestFalse(TEXT("Terminated thread should not expose an exit code"), Result.bHasExitCode);

	return true;
}

#endif
