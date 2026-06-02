// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "RefreshIOTDevicesAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTRefreshDevicesAsyncSuccess, int32, DeviceCount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTRefreshDevicesAsyncFailure, FString, ErrorMessage);

/** 蓝图异步刷新设备节点，启动子系统刷新并监听刷新完成或连接错误事件来结束节点。 */
UCLASS(MinimalAPI)
class URefreshIOTDevicesAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 创建刷新设备异步动作，Activate 时会请求子系统重新拉取设备快照。 */
	UFUNCTION(BlueprintCallable, Category="IOT", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static GENERICIOTFRAMEWORK_API URefreshIOTDevicesAsyncAction* RefreshIOTDevices(const UObject* WorldContextObject);

	GENERICIOTFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FIOTRefreshDevicesAsyncSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FIOTRefreshDevicesAsyncFailure OnError;

private:
	/** 接收子系统设备刷新完成事件，并把刷新后的设备数量传给成功分支。 */
	UFUNCTION(Category="IOT|Async Action")
	GENERICIOTFRAMEWORK_API void HandleDevicesRefreshed(int32 InDeviceCount);

	/** 监听连接错误状态，刷新过程中平台失败时转入错误分支。 */
	UFUNCTION(Category="IOT|Async Action")
	GENERICIOTFRAMEWORK_API void HandleConnectionStateChanged(EIOTConnectionState InConnectionState);

	/** 移除刷新和连接状态监听，并广播成功返回的设备数量。 */
	void FinishSuccess(int32 InDeviceCount);

	/** 移除刷新和连接状态监听，并广播失败原因。 */
	void FinishError(const FString& InErrorMessage);

private:
	/** 保存用于解析 UIOTSubsystem 的世界上下文对象，刷新请求和解绑都依赖它。 */
	UPROPERTY()
	TObjectPtr<UObject> WorldContextObject=nullptr;
};
