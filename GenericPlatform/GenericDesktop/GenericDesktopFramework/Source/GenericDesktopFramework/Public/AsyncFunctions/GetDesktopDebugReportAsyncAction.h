#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GetDesktopDebugReportAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDesktopDebugReportReady, const FString&, DebugReport);

/** 提供获取桌面调试Report异步动作能力。 */
UCLASS(MinimalAPI)
class UGetDesktopDebugReportAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICDESKTOPFRAMEWORK_API virtual void Activate() override;

	/** 处理异步获取桌面调试Report。 */
	UFUNCTION(BlueprintCallable, Category="Window|Diagnostics|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UGetDesktopDebugReportAsyncAction* AsyncGetDesktopDebugReport();

	/** 保存On已完成。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnDesktopDebugReportReady OnCompleted;

private:
	/** 保存Report。 */
	FString Report;
};
