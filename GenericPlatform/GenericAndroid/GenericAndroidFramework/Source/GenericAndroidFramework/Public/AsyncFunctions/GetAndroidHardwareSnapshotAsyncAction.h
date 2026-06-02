#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Type/AndroidType.h"
#include "GetAndroidHardwareSnapshotAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAndroidHardwareSnapshotReady, const FAndroidHardwareSnapshot&, Snapshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAndroidHardwareSnapshotFailed, const FString&, ErrorMessage);

/** 提供获取Android硬件Snapshot异步动作能力。 */
UCLASS(MinimalAPI)
class UGetAndroidHardwareSnapshotAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICANDROIDFRAMEWORK_API virtual void Activate() override;

	/** 处理异步获取Android硬件Snapshot。 */
	UFUNCTION(BlueprintCallable, Category="Android|Diagnostics|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICANDROIDFRAMEWORK_API UGetAndroidHardwareSnapshotAsyncAction* AsyncGetAndroidHardwareSnapshot();

	/** 保存On成功。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnAndroidHardwareSnapshotReady OnSuccess;

	/** 保存On失败。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnAndroidHardwareSnapshotFailed OnFail;
};
