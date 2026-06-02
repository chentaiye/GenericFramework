// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SessionAsyncActionBase.h"
#include "EndSessionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndSessionSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndSessionFail);

/** 蓝图结束会话异步节点，用于停止指定会话的活动状态但保留会话对象。 */
UCLASS(MinimalAPI)
class UEndSessionAsyncAction : public USessionAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void Activate() override;

public:
	/** 创建结束会话节点并缓存目标会话名，Activate 会提交 EndSession 请求。 */
	UFUNCTION(BlueprintCallable, Category="Generic Session", meta=(WorldContext="InWorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICNETWORKFRAMEWORK_API UEndSessionAsyncAction* EndSession(UObject* InWorldContextObject, FName InSessionName);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FEndSessionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FEndSessionFail OnFail;

private:
	FOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate;

	/** 只处理与本节点目标会话名匹配的结束完成回调，并在清理代理后广播结果。 */
	void OnEndSessionComplete(FName InSessionName, bool bWasSuccessful);

	/** 保存需要结束的会话名，用于提交请求和过滤完成回调。 */
	UPROPERTY()
	FName SessionName=NAME_None;
};
