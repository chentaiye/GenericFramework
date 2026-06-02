// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Config/VoiceProviderConfigDataAsset.h"
#include "Component/VoiceComponentBase.h"
#include "VoiceRecognitionTypes.h"
#include "VoiceRecognitionComponent.generated.h"

class IVoiceRecognitionServiceFeatureInterface;

/** 承载语音Recognition组件能力组件职责，衔接拥有者对象与模块内部实现。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UVoiceRecognitionComponent : public UVoiceComponentBase
{
	GENERATED_BODY()

public:
	/** 初始化语音Recognition组件默认状态。 */
	GENERICVOICERECOGNITIONFRAMEWORK_API UVoiceRecognitionComponent();

	/** 驱动启动识别对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Recognition")
	GENERICVOICERECOGNITIONFRAMEWORK_API bool StartRecognition();

	/** 驱动停止识别对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Recognition")
	GENERICVOICERECOGNITIONFRAMEWORK_API void StopRecognition();

	/** 重新启动Restart识别，恢复语音服务的监听状态。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Recognition")
	GENERICVOICERECOGNITIONFRAMEWORK_API void RestartRecognition();

	/** 执行Submit音频Pcm16Bytes流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Recognition")
	GENERICVOICERECOGNITIONFRAMEWORK_API bool SubmitAudioPcm16Bytes(const TArray<uint8>& InAudioPcm16Bytes, int32 InSampleRate = 16000, int32 InNumChannels = 1);

	/** 提交音频文件识别请求，并通过语音识别回调返回文本结果。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Recognition")
	GENERICVOICERECOGNITIONFRAMEWORK_API bool RecognizeAudioFile(const FString& InAudioFilePath);

	/** 模拟Partial结果。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Recognition")
	GENERICVOICERECOGNITIONFRAMEWORK_API void SimulatePartialResult(const FString& InText, float InConfidence = 1.0f, const FString& InMessage = TEXT("Manual recognition partial result."));

	/** 模拟Final结果。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Recognition")
	GENERICVOICERECOGNITIONFRAMEWORK_API void SimulateFinalResult(const FString& InText, float InConfidence = 1.0f, const FString& InMessage = TEXT("Manual recognition final result."));

	/** 判断Recognizing是否成立。 */
	UFUNCTION(BlueprintPure, Category="Voice|Recognition")
	bool IsRecognizing() const { return bIsRecognizing; }

	/** 获取Recognition状态。 */
	UFUNCTION(BlueprintPure, Category="Voice|Recognition")
	EVoiceRecognitionState GetRecognitionState() const { return RecognitionState; }

	/** 获取提供器Configs。 */
	const TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>>& GetProviderConfigs() const { return ProviderConfigs; }

	/** 通知提供器Recognition开始。 */
	GENERICVOICERECOGNITIONFRAMEWORK_API void NotifyProviderRecognitionStarted(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage);

	/** 通知提供器Recognition Stopped。 */
	GENERICVOICERECOGNITIONFRAMEWORK_API void NotifyProviderRecognitionStopped(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage);

	/** 通知提供器Recognition错误。 */
	GENERICVOICERECOGNITIONFRAMEWORK_API void NotifyProviderRecognitionError(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InErrorMessage);

	/** 通知Recognition Partial。 */
	GENERICVOICERECOGNITIONFRAMEWORK_API void NotifyRecognitionPartial(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InText, float InConfidence, const FString& InMessage);

	/** 通知Recognition Final。 */
	GENERICVOICERECOGNITIONFRAMEWORK_API void NotifyRecognitionFinal(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InText, float InConfidence, const FString& InMessage);

	UPROPERTY(BlueprintAssignable, Category="Voice|Recognition")
	FVoiceRecognitionProviderEventSignature OnRecognitionInitialized;

	UPROPERTY(BlueprintAssignable, Category="Voice|Recognition")
	FVoiceRecognitionProviderEventSignature OnRecognitionStarted;

	UPROPERTY(BlueprintAssignable, Category="Voice|Recognition")
	FVoiceRecognitionResultSignature OnRecognitionPartial;

	UPROPERTY(BlueprintAssignable, Category="Voice|Recognition")
	FVoiceRecognitionResultSignature OnRecognitionFinal;

	UPROPERTY(BlueprintAssignable, Category="Voice|Recognition")
	FVoiceRecognitionProviderEventSignature OnRecognitionStopped;

	UPROPERTY(BlueprintAssignable, Category="Voice|Recognition")
	FVoiceRecognitionProviderEventSignature OnRecognitionError;

	UPROPERTY(BlueprintAssignable, Category="Voice|Recognition")
	FVoiceRecognitionStateSignature OnRecognitionStateChanged;

	/** 记录路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition")
	EVoiceRoutePolicy RoutePolicy=EVoiceRoutePolicy::OnlineFirst;

	/** 在在线 Provider 名称时广播给蓝图或上层监听者。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition")
	FName OnlineProvider=TEXT("Volcengine");

	/** 离线提供器。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition")
	FName OfflineProvider=TEXT("SherpaOnnx");

	/** 记录语言。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition")
	EVoiceLanguage Language=EVoiceLanguage::Chinese;

	/** 记录Sample速率。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition", meta=(ClampMin="8000"))
	int32 SampleRate=16000;

	/** 启用Vad。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition")
	bool bEnableVad=true;

	/** 启用Punctuation。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition")
	bool bEnablePunctuation=true;

	/** 启用在线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition")
	bool bEnableOnlineRoute=true;

	/** 启用离线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition")
	bool bEnableOfflineRoute=true;

	/** 提供器Configs列表。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Recognition|Provider")
	TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>> ProviderConfigs;

protected:
	GENERICVOICERECOGNITIONFRAMEWORK_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
/** 构建启动请求，供语音服务请求发送复用。 */
	FVoiceRecognitionStartRequest BuildStartRequest() const;

	/** 尝试尝试启动带特性，失败时通过返回值或输出参数交还调用方处理。 */
	bool TryStartWithFeature(IVoiceRecognitionServiceFeatureInterface& InFeature, EVoiceRouteSource InRouteSource, const FVoiceRecognitionStartRequest& InRequest, FString& OutMessage);

	/** 设置Recognition状态。 */
	void SetRecognitionState(EVoiceRecognitionState InState);

	/** 转发转发状态目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardStateToOwner(EVoiceRecognitionState InState) const;

	/** 转发转发部分目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardPartialToOwner(const FVoiceRecognitionResult& InResult) const;

	/** 转发转发Final目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardFinalToOwner(const FVoiceRecognitionResult& InResult) const;

	/** 转发转发Error目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardErrorToOwner(const FString& InMessage) const;

	/** 创建提供器事件。 */
	FVoiceRecognitionProviderEvent MakeProviderEvent(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage) const;

private:
	/** 标记IsRecognizing状态。 */
	UPROPERTY(Transient)
	bool bIsRecognizing=false;

	/** 记录识别状态。 */
	UPROPERTY(Transient)
	EVoiceRecognitionState RecognitionState=EVoiceRecognitionState::Idle;
};
