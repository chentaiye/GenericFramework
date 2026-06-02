// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SessionAsyncActionBase.h"
#include "CancelFindSessionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCancelFindSessionSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCancelFindSessionFail);

/** 蓝图取消搜索异步节点，用于把当前 OnlineSession 搜索任务的取消结果转成成功或失败广播。 */
UCLASS(MinimalAPI)
class UCancelFindSessionAsyncAction : public USessionAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void Activate() override;

public:
	/** 创建取消搜索节点，Activate 会请求 UGenericSessionSubsystem 取消当前 FindSessions。 */
	UFUNCTION(BlueprintCallable, Category="Generic Session", meta=(WorldContext="InWorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICNETWORKFRAMEWORK_API UCancelFindSessionAsyncAction* CancelFindSession(UObject* InWorldContextObject);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FCancelFindSessionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FCancelFindSessionFail OnFail;

private:
	FOnCancelFindSessionsCompleteDelegate OnCancelFindSessionsCompleteDelegate;

	/** 清理取消搜索代理，并根据 OnlineSession 返回值广播取消成功或失败。 */
	void OnCancelFindSessionsComplete(bool bWasSuccessful);
};
