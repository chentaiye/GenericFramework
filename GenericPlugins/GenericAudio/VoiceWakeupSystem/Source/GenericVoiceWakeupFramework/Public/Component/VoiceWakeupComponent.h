// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Config/VoiceProviderConfigDataAsset.h"
#include "Component/VoiceComponentBase.h"
#include "VoiceWakeupTypes.h"
#include "VoiceWakeupComponent.generated.h"

class IVoiceWakeupServiceFeatureInterface;

/** 承载语音唤醒组件能力组件职责，衔接拥有者对象与模块内部实现。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UVoiceWakeupComponent : public UVoiceComponentBase
{
	GENERATED_BODY()

public:
	/** 初始化语音唤醒组件默认状态。 */
	GENERICVOICEWAKEUPFRAMEWORK_API UVoiceWakeupComponent();

	/** 驱动启动Listening对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Wakeup")
	GENERICVOICEWAKEUPFRAMEWORK_API bool StartListening();

	/** 驱动停止Listening对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Wakeup")
	GENERICVOICEWAKEUPFRAMEWORK_API void StopListening();

	/** 重新启动RestartListening，恢复语音服务的监听状态。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Wakeup")
	GENERICVOICEWAKEUPFRAMEWORK_API void RestartListening();

	/** 模拟唤醒。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Wakeup")
	GENERICVOICEWAKEUPFRAMEWORK_API void SimulateWakeup(const FString& InKeyword, float InConfidence = 1.0f, const FString& InMessage = TEXT("Manual wakeup simulation."));

	/** 判断Listening是否成立。 */
	UFUNCTION(BlueprintPure, Category="Voice|Wakeup")
	bool IsListening() const { return bIsListening; }

	/** 获取唤醒状态。 */
	UFUNCTION(BlueprintPure, Category="Voice|Wakeup")
	EVoiceWakeupState GetWakeupState() const { return WakeupState; }

	/** 获取提供器Configs。 */
	const TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>>& GetProviderConfigs() const { return ProviderConfigs; }

	/** 通知提供器Listening开始。 */
	GENERICVOICEWAKEUPFRAMEWORK_API void NotifyProviderListeningStarted(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage);

	/** 通知提供器Stopped。 */
	GENERICVOICEWAKEUPFRAMEWORK_API void NotifyProviderStopped(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage);

	/** 通知提供器错误。 */
	GENERICVOICEWAKEUPFRAMEWORK_API void NotifyProviderError(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InErrorMessage);

	/** 通知唤醒Detected。 */
	GENERICVOICEWAKEUPFRAMEWORK_API void NotifyWakeupDetected(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InKeyword, float InConfidence, const FString& InMessage);

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupInitialized;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupStarted;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupListening;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupResultSignature OnWakeupDetectedEvent;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupResultSignature OnWakeupRejected;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupCooldownStarted;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupCooldownFinished;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupProviderChanged;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupRouteChanged;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupFallbackTriggered;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupStopped;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupProviderEventSignature OnWakeupError;

	UPROPERTY(BlueprintAssignable, Category="Voice|Wakeup")
	FVoiceWakeupStateSignature OnWakeupStateChanged;

	/** 记录路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup")
	EVoiceRoutePolicy RoutePolicy=EVoiceRoutePolicy::OnlineFirst;

	/** 在在线 Provider 名称时广播给蓝图或上层监听者。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup")
	FName OnlineProvider=TEXT("Xfyun");

	/** 离线提供器。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup")
	FName OfflineProvider=TEXT("SherpaOnnx");

	/** 记录语言。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup")
	EVoiceLanguage Language=EVoiceLanguage::Chinese;

	/** 启用在线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup")
	bool bEnableOnlineRoute=true;

	/** 启用离线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup")
	bool bEnableOfflineRoute=true;

	/** 保存唤醒词列表，供语音系统批量处理。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup")
	TArray<FString> Keywords={ TEXT("ni hao xiao zhu shou"), TEXT("hello assistant") };

	/** 记录灵敏度。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup", meta=(ClampMin="0.0", ClampMax="1.0"))
	float Sensitivity=0.5f;

	/** 记录冷却秒。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup", meta=(ClampMin="0.0"))
	float CooldownSeconds=1.0f;

	/** 提供器Configs列表。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Wakeup|Provider")
	TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>> ProviderConfigs;

protected:
	GENERICVOICEWAKEUPFRAMEWORK_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
/** 构建启动请求，供语音服务请求发送复用。 */
	FVoiceWakeupStartRequest BuildStartRequest() const;

	/** 尝试尝试启动带特性，失败时通过返回值或输出参数交还调用方处理。 */
	bool TryStartWithFeature(IVoiceWakeupServiceFeatureInterface& InFeature, EVoiceRouteSource InRouteSource, const FVoiceWakeupStartRequest& InRequest, FString& OutMessage);

	/** 设置唤醒状态。 */
	void SetWakeupState(EVoiceWakeupState InState);

	/** 切换Enter冷却，维护语音流程的冷却状态。 */
	void EnterCooldown(const FVoiceWakeupResult& InResult);

	/** 切换Leave冷却，维护语音流程的冷却状态。 */
	void LeaveCooldown();

	/** 转发转发唤醒目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardWakeupToOwner(const FVoiceWakeupResult& InResult) const;

	/** 转发转发唤醒Error目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardWakeupErrorToOwner(const FString& InMessage) const;

	/** 转发转发唤醒状态目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardWakeupStateToOwner(EVoiceWakeupState InState) const;

	/** 创建提供器事件。 */
	FVoiceWakeupProviderEvent MakeProviderEvent(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage) const;

private:
	/** 标记IsListening状态。 */
	UPROPERTY(Transient)
	bool bIsListening=false;

	/** 标记IsCoolingDown状态。 */
	UPROPERTY(Transient)
	bool bIsCoolingDown=false;

	/** 记录唤醒状态。 */
	UPROPERTY(Transient)
	EVoiceWakeupState WakeupState=EVoiceWakeupState::Idle;

	/** 记录冷却Timer句柄。 */
	FTimerHandle CooldownTimerHandle;
};
