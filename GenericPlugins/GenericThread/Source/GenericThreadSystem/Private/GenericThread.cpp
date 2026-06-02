// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericThread.h"

#include "Misc/EngineVersionComparison.h"

FGenericThread::FGenericThread(const FString& InThreadName, const uint32 InThreadSize, const EThreadPriority InThreadPriority)
	: ThreadName(InThreadName),
	  ThreadSize(InThreadSize),
	  ThreadPriority(InThreadPriority),
	  Thread(nullptr),
	  bCreatePipe(false),
	  ReadPipe(nullptr),
	  WritePipe(nullptr),
	  bWorkerActive(false),
	  bIsRunning(false),
	  bIsStopping(false),
	  FinalizeState(EFinalizeState::None),
	  SleepInterval(0.01f)
{
	ThreadGuid = FGuid::NewGuid();
}

FGenericThread::~FGenericThread()
{
	if (Thread != nullptr || bWorkerActive.load() || bIsRunning.load())
	{
		Terminate();
	}
}

bool FGenericThread::Launch()
{
	if (Thread != nullptr || bWorkerActive.load() || bIsRunning.load())
	{
		return false;
	}

	bWorkerActive.store(false);
	bIsRunning.store(false);
	bIsStopping.store(false);
	FinalizeState.store(EFinalizeState::None);
	StartTime = FDateTime::UtcNow();
	EndTime = StartTime;

	{
		FScopeLock Lock(&OutputBufferCriticalSection);
		OutputBuffer.Reset();
	}

	OnBeginLaunch();

	if (bCreatePipe && !FPlatformProcess::CreatePipe(ReadPipe, WritePipe))
	{
		return false;
	}

	bWorkerActive.store(true);

	static std::atomic<uint32> ThreadNameIndex{0};
	Thread = FRunnableThread::Create(this, *FString::Printf(TEXT("%s_%d"), *ThreadName, ThreadNameIndex.fetch_add(1)), ThreadSize, ThreadPriority);
	if (Thread == nullptr)
	{
		bWorkerActive.store(false);
		ClosePipeHandles();
		return false;
	}

	if (!OnThreadCreated(Thread))
	{
		bWorkerActive.store(false);
		Thread->WaitForCompletion();
		delete Thread;
		Thread = nullptr;
		ClosePipeHandles();
		return false;
	}

	StartTime = FDateTime::UtcNow();
	TSharedPtr<FGenericThread> Self = AsShared();
	OnThreadRegisterEvent.Broadcast(Self);
	bIsRunning.store(true);

	return true;
}

void FGenericThread::Update()
{
	if (!FPlatformProcess::SupportsMultithreading())
	{
		FPlatformProcess::Sleep(SleepInterval);

		if (bIsRunning.load())
		{
			RunInternal();
		}
	}
}

void FGenericThread::Cancel()
{
	StopInternal();
}

void FGenericThread::Terminate()
{
	if (Thread == nullptr && !bWorkerActive.load() && !bIsRunning.load())
	{
		return;
	}

	StopInternal();

	if (!FPlatformProcess::SupportsMultithreading())
	{
		if (bIsRunning.load())
		{
			RunInternal();
		}
		else
		{
			bWorkerActive.store(false);
		}
	}

	if (Thread != nullptr)
	{
		Thread->WaitForCompletion();
		delete Thread;
		Thread = nullptr;
	}

	ClosePipeHandles();
	if (FinalizeState.load() == EFinalizeState::None)
	{
		NotifyTerminated();
	}

	bWorkerActive.store(false);
	bIsRunning.store(false);
	bIsStopping.store(false);
}

bool FGenericThread::Init()
{
	return FRunnable::Init();
}

uint32 FGenericThread::Run()
{
	while (bWorkerActive.load())
	{
		FPlatformProcess::Sleep(SleepInterval);

		if (bIsRunning.load())
		{
			RunInternal();
		}
	}

	return 0;
}

void FGenericThread::Stop()
{
	FRunnable::Stop();
	StopInternal();
}

void FGenericThread::Exit()
{
	FRunnable::Exit();
}

void FGenericThread::RunInternal()
{
	if (bCreatePipe && ReadPipe != nullptr)
	{
		ProcessOutput(FPlatformProcess::ReadPipe(ReadPipe));
	}

	if (bIsStopping.load())
	{
		NotifyTerminated();
		bIsRunning.store(false);
		bIsStopping.store(false);
		bWorkerActive.store(false);
	}
	else
	{
		if (!IsThreadRunning())
		{
			CompleteInternal();
		}
	}
}

void FGenericThread::StopInternal()
{
	EndTime = FDateTime::UtcNow();
	bIsStopping.store(true);
}

void FGenericThread::CompleteInternal()
{
	EndTime = FDateTime::UtcNow();
	ClosePipeHandles();

	if (!bIsStopping.load())
	{
		NotifyCompleted();
	}

	bWorkerActive.store(false);
	bIsRunning.store(false);
	bIsStopping.store(false);
}

void FGenericThread::ProcessOutput(const FString& Output)
{
	TArray<FString> CompletedLines;

	{
		FScopeLock Lock(&OutputBufferCriticalSection);
		OutputBuffer += Output;

		// 没有输出监听者时保留完整缓存，后续结果查询会从 OutputBuffer 读取。
		if (!OnOutputEvent.IsBound())
		{
			return;
		}

		// 已经形成完整行时逐行收集，稍后在锁外广播。
		int32 LineStartIdx = 0;
		for (int32 Idx = 0; Idx < OutputBuffer.Len(); Idx++)
		{
			if (OutputBuffer[Idx] == '\r' || OutputBuffer[Idx] == '\n')
			{
				CompletedLines.Add(OutputBuffer.Mid(LineStartIdx, Idx - LineStartIdx));

				if (OutputBuffer[Idx] == '\r' && Idx + 1 < OutputBuffer.Len() && OutputBuffer[Idx + 1] == '\n')
				{
					Idx++;
				}

				LineStartIdx = Idx + 1;
			}
		}

		// 从缓存中移除已广播的完整行，只保留未结束的半行。
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
		OutputBuffer.MidInline(LineStartIdx, MAX_int32, EAllowShrinking::No);
#else
		OutputBuffer.MidInline(LineStartIdx, MAX_int32, false);
#endif
	}

	for (const FString& Line : CompletedLines)
	{
		OnOutputEvent.Broadcast(Line);
	}
}

FTimespan FGenericThread::GetDuration() const
{
	if (bIsRunning.load())
	{
		return FDateTime::UtcNow() - StartTime;
	}

	return EndTime - StartTime;
}

void FGenericThread::NotifyTerminated()
{
	EFinalizeState Expected = EFinalizeState::None;
	if (!FinalizeState.compare_exchange_strong(Expected, EFinalizeState::Terminated))
	{
		return;
	}

	OnTerminated();
	OnTerminatedEvent.Broadcast(ThreadGuid);
}

void FGenericThread::NotifyCompleted()
{
	EFinalizeState Expected = EFinalizeState::None;
	if (!FinalizeState.compare_exchange_strong(Expected, EFinalizeState::Completed))
	{
		return;
	}

	OnCompleted();
	OnCompletedEvent.Broadcast(ThreadGuid);
}

void FGenericThread::ClosePipeHandles()
{
	if (ReadPipe == nullptr && WritePipe == nullptr)
	{
		return;
	}

	FPlatformProcess::ClosePipe(ReadPipe, WritePipe);
	ReadPipe = nullptr;
	WritePipe = nullptr;
}
