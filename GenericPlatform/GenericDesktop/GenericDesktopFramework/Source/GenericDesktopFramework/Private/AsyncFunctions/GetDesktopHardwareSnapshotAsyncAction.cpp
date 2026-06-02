#include "AsyncFunctions/GetDesktopHardwareSnapshotAsyncAction.h"

#include "Async/Async.h"
#include "BPFunctions/BPFunctions_Desktop.h"

void UGetDesktopHardwareSnapshotAsyncAction::Activate()
{
	Super::Activate();

	TWeakObjectPtr<UGetDesktopHardwareSnapshotAsyncAction> WeakThis(this);
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [WeakThis]()
	{
		FDesktopHardwareSnapshot Snapshot;
		UBPFunctions_Desktop::GetHardwareSnapshot(Snapshot);

		AsyncTask(ENamedThreads::GameThread, [WeakThis, Snapshot]()
		{
			if (!WeakThis.IsValid())
			{
				return;
			}

			WeakThis->OnSuccess.Broadcast(Snapshot);
		});
	});
}

UGetDesktopHardwareSnapshotAsyncAction* UGetDesktopHardwareSnapshotAsyncAction::AsyncGetDesktopHardwareSnapshot()
{
	return NewObject<UGetDesktopHardwareSnapshotAsyncAction>();
}

