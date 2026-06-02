// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SessionAsyncActionBase.h"
#include "StartSessionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStartSessionSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStartSessionFail);

/** 蓝图启动会话异步节点，将指定会话推进到开始状态并等待 OnlineSession 完成回调。 */
UCLASS(MinimalAPI)
class UStartSessionAsyncAction : public USessionAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void Activate() override;

public:
	/** 创建启动会话节点并缓存目标会话名，Activate 会提交 StartSession 请求。 */
	UFUNCTION(BlueprintCallable, Category="Generic Session", meta=(WorldContext="InWorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICNETWORKFRAMEWORK_API UStartSessionAsyncAction* StartSession(UObject* InWorldContextObject, FName InSessionName);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FStartSessionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FStartSessionFail OnFail;

private:
	FOnStartSessionCompleteDelegate OnStartCompleteDelegate;

	/** 只处理与本节点目标会话名匹配的启动完成回调，并在清理代理后广播结果。 */
	void OnStartSessionComplete(FName InSessionName, bool bWasSuccessful);

	/** 保存需要启动的会话名，用于提交请求和过滤完成回调。 */
	UPROPERTY()
	FName SessionName=NAME_None;
};
