#include "AsyncFunctions/GetDesktopDebugReportAsyncAction.h"

#include "Async/Async.h"
#include "BPFunctions/BPFunctions_Desktop.h"

void UGetDesktopDebugReportAsyncAction::Activate()
{
	Super::Activate();

	TWeakObjectPtr<UGetDesktopDebugReportAsyncAction> WeakThis(this);
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [WeakThis]()
	{
		const FString LocalReport = UBPFunctions_Desktop::GetWindowDebugReport();

		AsyncTask(ENamedThreads::GameThread, [WeakThis, LocalReport]()
		{
			if (!WeakThis.IsValid())
			{
				return;
			}

			WeakThis->OnCompleted.Broadcast(LocalReport);
		});
	});
}

UGetDesktopDebugReportAsyncAction* UGetDesktopDebugReportAsyncAction::AsyncGetDesktopDebugReport()
{
	return NewObject<UGetDesktopDebugReportAsyncAction>();
}

