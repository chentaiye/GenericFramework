#include "AsyncFunctions/DesktopDialogAsyncAction.h"

#include "Async/Async.h"
#include "BPFunctions/BPFunctions_Desktop.h"

void UDesktopDialogAsyncAction::Activate()
{
	Super::Activate();

	TWeakObjectPtr<UDesktopDialogAsyncAction> WeakThis(this);
	const EDialogMode LocalMode = DialogMode;
	const FString LocalFileName = CachedFileName;
	const FString LocalFileType = CachedFileType;

	Async(EAsyncExecution::Thread, [WeakThis, LocalMode, LocalFileName, LocalFileType]()
	{
		FDesktopDialogResult Result;

		switch (LocalMode)
		{
		case EDialogMode::OpenDirectory:
			Result.bSuccess = UBPFunctions_Desktop::OpenDirectoryDialog(Result.Directory);
			if (!Result.bSuccess)
			{
				Result.ErrorMessage = TEXT("目录选择已取消或执行失败。");
			}
			break;

		case EDialogMode::OpenFile:
			Result.bSuccess = UBPFunctions_Desktop::OpenFileDialog(LocalFileType, Result.FilePaths);
			if (!Result.bSuccess)
			{
				Result.ErrorMessage = TEXT("文件选择已取消或执行失败。");
			}
			break;

		case EDialogMode::SaveFile:
			Result.bSuccess = UBPFunctions_Desktop::SaveFileDialog(LocalFileName, LocalFileType, Result.FilePaths);
			if (!Result.bSuccess)
			{
				Result.ErrorMessage = TEXT("保存对话框已取消或执行失败。");
			}
			break;
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

UDesktopDialogAsyncAction* UDesktopDialogAsyncAction::AsyncOpenDirectoryDialog()
{
	UDesktopDialogAsyncAction* Action = NewObject<UDesktopDialogAsyncAction>();
	Action->DialogMode = EDialogMode::OpenDirectory;
	return Action;
}

UDesktopDialogAsyncAction* UDesktopDialogAsyncAction::AsyncOpenFileDialog(const FString& FileType)
{
	UDesktopDialogAsyncAction* Action = NewObject<UDesktopDialogAsyncAction>();
	Action->DialogMode = EDialogMode::OpenFile;
	Action->CachedFileType = FileType;
	return Action;
}

UDesktopDialogAsyncAction* UDesktopDialogAsyncAction::AsyncSaveFileDialog(const FString& FileName, const FString& FileType)
{
	UDesktopDialogAsyncAction* Action = NewObject<UDesktopDialogAsyncAction>();
	Action->DialogMode = EDialogMode::SaveFile;
	Action->CachedFileName = FileName;
	Action->CachedFileType = FileType;
	return Action;
}

