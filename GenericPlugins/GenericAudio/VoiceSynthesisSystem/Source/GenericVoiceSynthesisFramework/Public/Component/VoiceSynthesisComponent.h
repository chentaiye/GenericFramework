// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Config/VoiceProviderConfigDataAsset.h"
#include "Component/VoiceComponentBase.h"
#include "VoiceSynthesisTypes.h"
#include "VoiceSynthesisComponent.generated.h"

class IVoiceSynthesisServiceFeatureInterface;

/** 作为语音合成组件能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UVoiceSynthesisComponent : public UVoiceComponentBase
{
	GENERATED_BODY()

public:
	/** 初始化语音合成组件默认状态。 */
	GENERICVOICESYNTHESISFRAMEWORK_API UVoiceSynthesisComponent();

	/** 提交文本合成请求，可选择把生成音频写入指定文件路径。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Synthesis")
	GENERICVOICESYNTHESISFRAMEWORK_API bool SynthesizeText(const FString& InText, const FString& InOutputFilePath = TEXT(""));

	/** 判断是否可以cel合成。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Synthesis")
	GENERICVOICESYNTHESISFRAMEWORK_API void CancelSynthesis();

	/** 模拟合成已完成。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Synthesis")
	GENERICVOICESYNTHESISFRAMEWORK_API void SimulateSynthesisCompleted(const FString& InText, const FString& InAudioFilePath, const FString& InMessage = TEXT("Manual synthesis result."));

	/** 判断Synthesizing是否成立。 */
	UFUNCTION(BlueprintPure, Category="Voice|Synthesis")
	bool IsSynthesizing() const { return bIsSynthesizing; }

	/** 获取合成状态。 */
	UFUNCTION(BlueprintPure, Category="Voice|Synthesis")
	EVoiceSynthesisState GetSynthesisState() const { return SynthesisState; }

	/** 获取提供器Configs。 */
	const TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>>& GetProviderConfigs() const { return ProviderConfigs; }

	/** 通知提供器合成开始。 */
	GENERICVOICESYNTHESISFRAMEWORK_API void NotifyProviderSynthesisStarted(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage);

	/** 通知提供器合成已完成。 */
	GENERICVOICESYNTHESISFRAMEWORK_API void NotifyProviderSynthesisCompleted(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InText, const FString& InAudioFilePath, const FString& InMessage);

	/** 通知提供器合成Stopped。 */
	GENERICVOICESYNTHESISFRAMEWORK_API void NotifyProviderSynthesisStopped(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage);

	/** 通知提供器合成错误。 */
	GENERICVOICESYNTHESISFRAMEWORK_API void NotifyProviderSynthesisError(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InErrorMessage);

	UPROPERTY(BlueprintAssignable, Category="Voice|Synthesis")
	FVoiceSynthesisProviderEventSignature OnSynthesisInitialized;

	UPROPERTY(BlueprintAssignable, Category="Voice|Synthesis")
	FVoiceSynthesisProviderEventSignature OnSynthesisStarted;

	UPROPERTY(BlueprintAssignable, Category="Voice|Synthesis")
	FVoiceSynthesisResultSignature OnSynthesisCompletedEvent;

	UPROPERTY(BlueprintAssignable, Category="Voice|Synthesis")
	FVoiceSynthesisProviderEventSignature OnSynthesisStopped;

	UPROPERTY(BlueprintAssignable, Category="Voice|Synthesis")
	FVoiceSynthesisProviderEventSignature OnSynthesisError;

	UPROPERTY(BlueprintAssignable, Category="Voice|Synthesis")
	FVoiceSynthesisStateSignature OnSynthesisStateChanged;

	/** 记录路由策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis")
	EVoiceRoutePolicy RoutePolicy=EVoiceRoutePolicy::OnlineFirst;

	/** 在在线 Provider 名称时广播给蓝图或上层监听者。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis")
	FName OnlineProvider=TEXT("Volcengine");

	/** 离线提供器。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis")
	FName OfflineProvider=TEXT("SherpaOnnx");

	/** 记录语言。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis")
	EVoiceLanguage Language=EVoiceLanguage::Chinese;

	/** 记录语音Id。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis")
	FString VoiceId=TEXT("female_1");

	/** 记录Speech速率。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis", meta=(ClampMin="0.1"))
	float SpeechRate=1.0f;

	/** 记录Pitch。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis", meta=(ClampMin="0.0"))
	float Pitch=1.0f;

	/** 记录Volume。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis", meta=(ClampMin="0.0"))
	float Volume=1.0f;

	/** 启用在线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis")
	bool bEnableOnlineRoute=true;

	/** 启用离线路由。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis")
	bool bEnableOfflineRoute=true;

	/** 提供器Configs列表。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Voice|Synthesis|Provider")
	TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>> ProviderConfigs;

protected:
	GENERICVOICESYNTHESISFRAMEWORK_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
/** 构建请求，供语音服务请求发送复用。 */
	FVoiceSynthesisRequest BuildRequest(const FString& InText, const FString& InOutputFilePath) const;

	/** 尝试尝试启动带特性，失败时通过返回值或输出参数交还调用方处理。 */
	bool TryStartWithFeature(IVoiceSynthesisServiceFeatureInterface& InFeature, EVoiceRouteSource InRouteSource, const FVoiceSynthesisRequest& InRequest, FString& OutMessage);

	/** 设置合成状态。 */
	void SetSynthesisState(EVoiceSynthesisState InState);

	/** 转发转发状态目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardStateToOwner(EVoiceSynthesisState InState) const;

	/** 转发转发结果目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardResultToOwner(const FVoiceSynthesisResult& InResult) const;

	/** 转发转发Error目标Owner，让拥有者对象接收组件内部事件。 */
	void ForwardErrorToOwner(const FString& InMessage) const;

	/** 创建提供器事件。 */
	FVoiceSynthesisProviderEvent MakeProviderEvent(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InMessage) const;

private:
	/** 标记IsSynthesizing状态。 */
	UPROPERTY(Transient)
	bool bIsSynthesizing=false;

	/** 记录合成状态。 */
	UPROPERTY(Transient)
	EVoiceSynthesisState SynthesisState=EVoiceSynthesisState::Idle;
};
