#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Type/DesktopType.h"
#include "GetDesktopHardwareSnapshotAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDesktopHardwareSnapshotReady, const FDesktopHardwareSnapshot&, Snapshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDesktopHardwareSnapshotFailed, const FString&, ErrorMessage);

/** 提供获取桌面硬件Snapshot异步动作能力。 */
UCLASS(MinimalAPI)
class UGetDesktopHardwareSnapshotAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICDESKTOPFRAMEWORK_API virtual void Activate() override;

	/** 处理异步获取桌面硬件Snapshot。 */
	UFUNCTION(BlueprintCallable, Category="Window|Diagnostics|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UGetDesktopHardwareSnapshotAsyncAction* AsyncGetDesktopHardwareSnapshot();

	/** 保存On成功。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnDesktopHardwareSnapshotReady OnSuccess;

	/** 保存On失败。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnDesktopHardwareSnapshotFailed OnFail;
};
