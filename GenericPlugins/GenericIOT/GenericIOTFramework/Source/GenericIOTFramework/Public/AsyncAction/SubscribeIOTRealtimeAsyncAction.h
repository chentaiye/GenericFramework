// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SubscribeIOTRealtimeAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FIOTSubscribeRealtimeAsyncSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTSubscribeRealtimeAsyncFailure, FString, ErrorMessage);

/** 蓝图异步实时订阅节点，启动子系统实时通道并在订阅激活或连接失败时结束节点。 */
UCLASS(MinimalAPI)
class USubscribeIOTRealtimeAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建实时订阅异步动作，Activate 时会复用已有订阅或请求子系统建立实时通道。 */
	UFUNCTION(BlueprintCallable, Category="IOT", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static GENERICIOTFRAMEWORK_API USubscribeIOTRealtimeAsyncAction* SubscribeIOTRealtime(const UObject* WorldContextObject);

	GENERICIOTFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FIOTSubscribeRealtimeAsyncSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FIOTSubscribeRealtimeAsyncFailure OnError;

private:
	/** 监听子系统实时状态广播，通道激活后完成成功分支。 */
	UFUNCTION(Category="IOT|Async Action")
	GENERICIOTFRAMEWORK_API void HandleRealtimeStateChanged(bool bInRealtimeActive);

	/** 监听连接错误状态，订阅流程失败时转入错误分支。 */
	UFUNCTION(Category="IOT|Async Action")
	GENERICIOTFRAMEWORK_API void HandleConnectionStateChanged(EIOTConnectionState InConnectionState);

	/** 移除实时和连接状态监听，并广播实时订阅成功。 */
	void FinishSuccess();

	/** 移除实时和连接状态监听，并广播订阅失败原因。 */
	void FinishError(const FString& InErrorMessage);

private:
	/** 保存用于解析 UIOTSubsystem 的世界上下文对象，订阅请求和解绑都依赖它。 */
	UPROPERTY()
	TObjectPtr<UObject> WorldContextObject=nullptr;
};
