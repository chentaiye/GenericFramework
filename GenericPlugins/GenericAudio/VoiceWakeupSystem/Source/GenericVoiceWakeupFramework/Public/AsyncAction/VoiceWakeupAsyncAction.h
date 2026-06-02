// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceWakeupTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "VoiceWakeupAsyncAction.generated.h"

class UVoiceWakeupComponent;

/** 封装语音唤醒异步动作能力蓝图异步节点，负责启动请求并广播完成结果。 */
UCLASS(MinimalAPI)
class UVoiceWakeupAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 驱动启动唤醒对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Wakeup", meta=(BlueprintInternalUseOnly="true"))
	static GENERICVOICEWAKEUPFRAMEWORK_API UVoiceWakeupAsyncAction* StartWakeup(UVoiceWakeupComponent* InWakeupComponent);

	GENERICVOICEWAKEUPFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceWakeupProviderEventSignature OnStarted;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceWakeupResultSignature OnDetected;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceWakeupProviderEventSignature OnError;

private:
	/** 执行句柄Started流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICEWAKEUPFRAMEWORK_API void HandleStarted(FVoiceWakeupProviderEvent InEvent);

	/** 执行句柄Detected流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICEWAKEUPFRAMEWORK_API void HandleDetected(FVoiceWakeupResult InResult);

	/** 执行句柄Error流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICEWAKEUPFRAMEWORK_API void HandleError(FVoiceWakeupProviderEvent InEvent);

	/** 解绑，保持对象生命周期内的委托连接一致。 */
	void Unbind();

	/** 创建错误事件。 */
	static FVoiceWakeupProviderEvent MakeErrorEvent(const FString& InMessage);

private:
	/** 缓存唤醒组件。 */
	UPROPERTY()
	TObjectPtr<UVoiceWakeupComponent> WakeupComponent=nullptr;

	/** 标记Bound状态。 */
	bool bBound = false;
};
