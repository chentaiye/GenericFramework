// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Type/IOTTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ConnectIOTPlatformAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTConnectPlatformAsyncSuccess, FIOTPlatformEndpointConfig, EndpointConfig);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTAsyncFailure, FString, ErrorMessage);

/** 蓝图异步连接节点，应用可选 Endpoint 配置后监听子系统连接状态并在成功或失败时结束节点。 */
UCLASS(MinimalAPI)
class UConnectIOTPlatformAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建连接平台异步动作，参数会在 Activate 中写入子系统并启动 Home Assistant 连接流程。 */
	UFUNCTION(BlueprintCallable, Category="IOT", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static GENERICIOTFRAMEWORK_API UConnectIOTPlatformAsyncAction* ConnectIOTPlatform(const UObject* WorldContextObject, FIOTPlatformEndpointConfig InEndpointConfig, bool bApplyEndpointConfig = true);

	GENERICIOTFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FIOTConnectPlatformAsyncSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FIOTAsyncFailure OnError;

private:
	/** 监听子系统连接状态，只在 Connected 或 Error 状态到达时完成异步节点。 */
	UFUNCTION(Category="IOT|Async Action")
	GENERICIOTFRAMEWORK_API void HandleConnectionStateChanged(EIOTConnectionState InConnectionState);

	/** 解除连接状态监听并把最终 Endpoint 配置广播到成功分支。 */
	void FinishSuccess();

	/** 解除连接状态监听并把失败原因广播到错误分支。 */
	void FinishError(const FString& InErrorMessage);

private:
	/** 保存用于解析 UIOTSubsystem 的世界上下文对象，节点生命周期内都通过它访问子系统。 */
	UPROPERTY()
	TObjectPtr<UObject> WorldContextObject=nullptr;

	/** 节点传入的 Endpoint 配置，Activate 时可写入子系统并作为失败兜底回传。 */
	FIOTPlatformEndpointConfig EndpointConfig;

	/** 控制 Activate 是否先调用 SetEndpointConfig，允许只复用子系统已有配置发起连接。 */
	bool bShouldApplyEndpointConfig = true;
};
