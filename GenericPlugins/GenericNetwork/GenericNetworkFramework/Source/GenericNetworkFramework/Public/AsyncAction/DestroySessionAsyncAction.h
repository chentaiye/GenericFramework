// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SessionAsyncActionBase.h"
#include "DestroySessionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDestroySessionSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDestroySessionFail);

/** 蓝图销毁会话异步节点，用于请求 OnlineSession 移除指定会话并广播销毁结果。 */
UCLASS(MinimalAPI)
class UDestroySessionAsyncAction : public USessionAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void Activate() override;

public:
	/** 创建销毁会话节点并缓存目标会话名，Activate 会提交 DestroySession 请求。 */
	UFUNCTION(BlueprintCallable, Category="Generic Session", meta=(WorldContext="InWorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICNETWORKFRAMEWORK_API UDestroySessionAsyncAction* DestroySession(UObject* InWorldContextObject, FName InSessionName);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FDestroySessionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FDestroySessionFail OnFail;

private:
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;

	/** 只处理与本节点目标会话名匹配的销毁完成回调，并据此广播成功或失败。 */
	void OnDestroySessionComplete(FName InSessionName, bool bWasSuccessful);

	/** 保存需要销毁的会话名，用于提交请求和过滤完成回调。 */
	UPROPERTY()
	FName SessionName=NAME_None;
};
