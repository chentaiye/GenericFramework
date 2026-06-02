// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericThreadSubsystem.h"

#include "GenericThread.h"
#include "ThreadType.h"
#include "Type/DebugType.h"

UGenericThreadSubsystem* UGenericThreadSubsystem::Get()
{
	return GEngine ? GEngine->GetEngineSubsystem<UGenericThreadSubsystem>() : nullptr;
}

void UGenericThreadSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

#if WITH_EDITOR
	FEditorDelegates::EndPIE.AddUObject(this, &UGenericThreadSubsystem::EndPIE);
#endif

	FGenericThread::OnThreadRegisterEvent.AddUObject(this, &UGenericThreadSubsystem::RegisterThread);
}

void UGenericThreadSubsystem::Deinitialize()
{
	KillAllThread();

#if WITH_EDITOR
	FEditorDelegates::EndPIE.RemoveAll(this);
#endif

	FGenericThread::OnThreadRegisterEvent.RemoveAll(this);
	ThreadResultMapping.Empty();
	Super::Deinitialize();
}

#if WITH_EDITOR

void UGenericThreadSubsystem::EndPIE(bool bIsSimulating)
{
	KillAllThread();
}

#endif

void UGenericThreadSubsystem::KillAllThread()
{
	TArray<FGuid> AllThreadGuid;
	ThreadMapping.GetKeys(AllThreadGuid);

	for (const FGuid ThreadGuid : AllThreadGuid)
	{
		TSharedPtr<FGenericThread> Thread = GetThreadByGuid(ThreadGuid);
		if (Thread.IsValid())
		{
			Thread->Terminate();
			ThreadResultMapping.Add(ThreadGuid, BuildThreadResult(Thread, EThreadExecutionState::Terminated));
		}
	}

	ThreadMapping.Empty();
}

void UGenericThreadSubsystem::RegisterThread(TSharedPtr<FGenericThread> Thread)
{
	if (!Thread.IsValid())
	{
		return;
	}

	ThreadResultMapping.Remove(Thread->GetThreadGuid());
	ThreadMapping.Emplace(Thread->GetThreadGuid(), Thread);
	GenericLOG(GenericLogThread, Log, TEXT("On Register : FGenericThread [Guid = %s]"), *Thread->GetThreadGuid().ToString())
	Thread->GetOnTerminated().RemoveAll(this);
	Thread->GetOnCompleted().RemoveAll(this);
	Thread->GetOnTerminated().AddUObject(this, &UGenericThreadSubsystem::OnThreadTerminated);
	Thread->GetOnCompleted().AddUObject(this, &UGenericThreadSubsystem::OnThreadCompleted);
}

void UGenericThreadSubsystem::UnRegisterThread(const TSharedPtr<FGenericThread>& Thread)
{
	if (!Thread.IsValid())
	{
		return;
	}

	Thread->GetOnTerminated().RemoveAll(this);
	Thread->GetOnCompleted().RemoveAll(this);
	ThreadResultMapping.Add(Thread->GetThreadGuid(), BuildThreadResult(Thread, Thread->WasCompleted() ? EThreadExecutionState::Completed : EThreadExecutionState::Terminated));
	ThreadMapping.Remove(Thread->GetThreadGuid());
	GenericLOG(GenericLogThread, Log, TEXT("On UnRegister : FGenericThread [Guid = %s]"), *Thread->GetThreadGuid().ToString())
}

void UGenericThreadSubsystem::OnThreadTerminated(FGuid ThreadGuid)
{
	TWeakObjectPtr<UGenericThreadSubsystem> WeakThis(this);
	auto Execute = [ThreadGuid, WeakThis]()
	{
		if (!WeakThis.IsValid())
		{
			return;
		}

		if (WeakThis->ThreadMapping.Contains(ThreadGuid))
		{
			TSharedPtr<FGenericThread> Thread = WeakThis->ThreadMapping.FindRef(ThreadGuid);
			if (Thread.IsValid())
			{
				WeakThis->UnRegisterThread(Thread);
			}
		}
	};

	AsyncTask(ENamedThreads::GameThread, MoveTemp(Execute));
}

void UGenericThreadSubsystem::OnThreadCompleted(FGuid ThreadGuid)
{
	TWeakObjectPtr<UGenericThreadSubsystem> WeakThis(this);
	auto Execute = [ThreadGuid, WeakThis]()
	{
		if (!WeakThis.IsValid())
		{
			return;
		}

		if (WeakThis->ThreadMapping.Contains(ThreadGuid))
		{
			TSharedPtr<FGenericThread> Thread = WeakThis->ThreadMapping.FindRef(ThreadGuid);
			if (Thread.IsValid())
			{
				WeakThis->UnRegisterThread(Thread);
			}
		}
	};

	AsyncTask(ENamedThreads::GameThread, MoveTemp(Execute));
}

TArray<FGuid> UGenericThreadSubsystem::GetAllThreadGuid() const
{
	TArray<FGuid> Result;
	ThreadMapping.GenerateKeyArray(Result);
	return Result;
}

TArray<TSharedPtr<FGenericThread>> UGenericThreadSubsystem::GetAllThreads() const
{
	TArray<TSharedPtr<FGenericThread>> Result;
	ThreadMapping.GenerateValueArray(Result);
	return Result;
}

TSharedPtr<FGenericThread> UGenericThreadSubsystem::GetThreadByGuid(const FGuid& ThreadGuid) const
{
	if (!ThreadMapping.Contains(ThreadGuid))
	{
		return nullptr;
	}
	return ThreadMapping[ThreadGuid];
}

bool UGenericThreadSubsystem::GetThreadResultByGuid(const FGuid& ThreadGuid, FThreadExecutionResult& OutResult) const
{
	OutResult = FThreadExecutionResult();

	if (!ThreadGuid.IsValid())
	{
		return false;
	}

	if (const TSharedPtr<FGenericThread> Thread = GetThreadByGuid(ThreadGuid); Thread.IsValid())
	{
		OutResult = BuildThreadResult(Thread, EThreadExecutionState::Running);
		return true;
	}

	if (const FThreadExecutionResult* CachedResult = ThreadResultMapping.Find(ThreadGuid))
	{
		OutResult = *CachedResult;
		return true;
	}

	return false;
}

FThreadExecutionResult UGenericThreadSubsystem::BuildThreadResult(const TSharedPtr<FGenericThread>& Thread, EThreadExecutionState State) const
{
	FThreadExecutionResult Result;
	if (!Thread.IsValid())
	{
		return Result;
	}

	Result.ThreadHandle = FThreadHandle(Thread->GetThreadGuid());
	Result.State = State;
	Result.ThreadName = Thread->GetThreadName();
	Result.Duration = Thread->GetDuration();
	Result.Output = Thread->GetOutput();
	Result.bHasExitCode = Thread->TryGetExitCode(Result.ExitCode);
	return Result;
}
