#include "AsyncFunctions/DesktopStringFileAsyncAction.h"

#include "Async/Async.h"
#include "BPFunctions/BPFunctions_Desktop.h"

void UDesktopStringFileAsyncAction::Activate()
{
	Super::Activate();

	TWeakObjectPtr<UDesktopStringFileAsyncAction> WeakThis(this);
	const EStringFileMode LocalMode = FileMode;
	const FString LocalFileName = CachedFileName;
	const FString LocalData = CachedData;
	const EDesktopTextEncodingOptions LocalEncoding = CachedEncodingOptions;

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [WeakThis, LocalMode, LocalFileName, LocalData, LocalEncoding]()
	{
		FDesktopStringResult Result;
		Result.FileName = LocalFileName;

		if (LocalMode == EStringFileMode::Read)
		{
			Result.bSuccess = UBPFunctions_Desktop::ReadStringFromFile(LocalFileName, Result.Data);
			if (!Result.bSuccess)
			{
				Result.ErrorMessage = TEXT("读取字符串文件失败。");
			}
		}
		else
		{
			Result.Data = LocalData;
			Result.bSuccess = UBPFunctions_Desktop::WriteStringToFile(LocalData, LocalFileName, LocalEncoding);
			if (!Result.bSuccess)
			{
				Result.ErrorMessage = TEXT("写入字符串文件失败。");
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

UDesktopStringFileAsyncAction* UDesktopStringFileAsyncAction::AsyncReadStringFromFile(const FString& FileName)
{
	UDesktopStringFileAsyncAction* Action = NewObject<UDesktopStringFileAsyncAction>();
	Action->FileMode = EStringFileMode::Read;
	Action->CachedFileName = FileName;
	return Action;
}

UDesktopStringFileAsyncAction* UDesktopStringFileAsyncAction::AsyncWriteStringToFile(const FString& Data, const FString& FileName, EDesktopTextEncodingOptions EncodingOptions)
{
	UDesktopStringFileAsyncAction* Action = NewObject<UDesktopStringFileAsyncAction>();
	Action->FileMode = EStringFileMode::Write;
	Action->CachedData = Data;
	Action->CachedFileName = FileName;
	Action->CachedEncodingOptions = EncodingOptions;
	return Action;
}

