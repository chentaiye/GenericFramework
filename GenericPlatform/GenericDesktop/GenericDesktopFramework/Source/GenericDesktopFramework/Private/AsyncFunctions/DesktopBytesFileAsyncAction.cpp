#include "AsyncFunctions/DesktopBytesFileAsyncAction.h"

#include "Async/Async.h"
#include "BPFunctions/BPFunctions_Desktop.h"

void UDesktopBytesFileAsyncAction::Activate()
{
	Super::Activate();

	TWeakObjectPtr<UDesktopBytesFileAsyncAction> WeakThis(this);
	const EBytesFileMode LocalMode = FileMode;
	const FString LocalFileName = CachedFileName;
	const TArray<uint8> LocalData = CachedData;

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [WeakThis, LocalMode, LocalFileName, LocalData]()
	{
		FDesktopBytesResult Result;
		Result.FileName = LocalFileName;

		if (LocalMode == EBytesFileMode::Read)
		{
			Result.bSuccess = UBPFunctions_Desktop::ReadBytesFromFile(LocalFileName, Result.Data);
			if (!Result.bSuccess)
			{
				Result.ErrorMessage = TEXT("读取字节文件失败。");
			}
		}
		else
		{
			Result.Data = LocalData;
			Result.bSuccess = UBPFunctions_Desktop::SaveBytesToFile(LocalFileName, LocalData);
			if (!Result.bSuccess)
			{
				Result.ErrorMessage = TEXT("写入字节文件失败。");
			}
		}

		AsyncTask(ENamedThreads::GameThread, [WeakThis, Result]()
		{
			if (!WeakThis.IsValid())
			{
				return;
			}

			WeakThis->OnCompleted.Broadcast(Result);
		});
	});
}

UDesktopBytesFileAsyncAction* UDesktopBytesFileAsyncAction::AsyncReadBytesFromFile(const FString& FileName)
{
	UDesktopBytesFileAsyncAction* Action = NewObject<UDesktopBytesFileAsyncAction>();
	Action->FileMode = EBytesFileMode::Read;
	Action->CachedFileName = FileName;
	return Action;
}

UDesktopBytesFileAsyncAction* UDesktopBytesFileAsyncAction::AsyncWriteBytesToFile(const FString& FileName, const TArray<uint8>& Data)
{
	UDesktopBytesFileAsyncAction* Action = NewObject<UDesktopBytesFileAsyncAction>();
	Action->FileMode = EBytesFileMode::Write;
	Action->CachedFileName = FileName;
	Action->CachedData = Data;
	return Action;
}

