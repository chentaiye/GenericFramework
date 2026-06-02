#include "AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h"

#include "BPFunctions/BPFunctions_Android.h"
#include "Async/Async.h"

void UGetAndroidHardwareSnapshotAsyncAction::Activate()
{
	Super::Activate();

	TWeakObjectPtr<UGetAndroidHardwareSnapshotAsyncAction> WeakThis(this);
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [WeakThis]()
	{
		FAndroidHardwareSnapshot Snapshot;
		UBPFunctions_Android::GetHardwareSnapshot(Snapshot);

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

UGetAndroidHardwareSnapshotAsyncAction* UGetAndroidHardwareSnapshotAsyncAction::AsyncGetAndroidHardwareSnapshot()
{
	return NewObject<UGetAndroidHardwareSnapshotAsyncAction>();
}
