// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Type/IOTTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ExecuteIOTCommandAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTExecuteCommandAsyncSuccess, FIOTCommandResult, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTExecuteCommandAsyncFailure, FIOTCommandResult, Result);

/** 蓝图异步命令节点，发起统一命令或原生服务后按 RequestId 等待子系统命令完成广播。 */
UCLASS(MinimalAPI)
class UExecuteIOTCommandAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建统一命令异步动作，Activate 时会把请求交给子系统补全 RequestId 并执行。 */
	UFUNCTION(BlueprintCallable, Category="IOT", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static GENERICIOTFRAMEWORK_API UExecuteIOTCommandAsyncAction* ExecuteIOTCommand(const UObject* WorldContextObject, FIOTCommandRequest InRequest);

	/** 创建原生服务异步动作，Activate 时会通过子系统 ExecuteRawService 派发平台服务。 */
	UFUNCTION(BlueprintCallable, Category="IOT", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject", AutoCreateRefTerm="Params"))
	static GENERICIOTFRAMEWORK_API UExecuteIOTCommandAsyncAction* ExecuteRawIOTService(const UObject* WorldContextObject, const FString& DeviceId, FName Domain, FName Service, const TMap<FString, FString>& Params);

	GENERICIOTFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FIOTExecuteCommandAsyncSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FIOTExecuteCommandAsyncFailure OnError;

private:
	/** 监听子系统命令完成事件，仅当 RequestId 与本节点请求匹配时结束异步动作。 */
	UFUNCTION(Category="IOT|Async Action")
	GENERICIOTFRAMEWORK_API void HandleCommandCompleted(FIOTCommandRequest InRequest, FIOTCommandResult InResult);

	/** 解除命令完成监听，并按结果成功标记广播成功或失败分支。 */
	void Finish(const FIOTCommandResult& InResult, bool bSucceeded);

private:
	/** 保存用于解析 UIOTSubsystem 的世界上下文对象，命令派发和解绑都通过它访问子系统。 */
	UPROPERTY()
	TObjectPtr<UObject> WorldContextObject=nullptr;

	/** 待执行的命令请求，同时缓存子系统返回的 RequestId 以过滤完成事件。 */
	FIOTCommandRequest Request;

	/** 标记节点是否走原生服务路径，决定 Activate 中调用 ExecuteCommand 还是 ExecuteRawService。 */
	bool bUseRawService = false;

	/** 原生服务的 Home Assistant 域名，原生服务路径会把它写入适配器调用参数。 */
	FName RawDomain;

	/** 原生服务名称，和 RawDomain 一起构成 Raw:domain.service 命令名称。 */
	FName RawService;

	/** 原生服务参数映射，透传给平台适配器而不经过统一能力参数转换。 */
	TMap<FString, FString> RawParams;
};
