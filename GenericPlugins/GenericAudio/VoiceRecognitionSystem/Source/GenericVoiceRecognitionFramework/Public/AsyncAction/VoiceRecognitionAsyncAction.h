// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceRecognitionTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "VoiceRecognitionAsyncAction.generated.h"

class UVoiceRecognitionComponent;

/** 封装语音Recognition异步动作能力蓝图异步节点，负责启动请求并广播完成结果。 */
UCLASS(MinimalAPI)
class UVoiceRecognitionAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 驱动启动识别对应的语音系统生命周期或播放流程。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Recognition", meta=(BlueprintInternalUseOnly="true"))
	static GENERICVOICERECOGNITIONFRAMEWORK_API UVoiceRecognitionAsyncAction* StartRecognition(UVoiceRecognitionComponent* InRecognitionComponent, const FString& InAudioFilePath);

	GENERICVOICERECOGNITIONFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceRecognitionProviderEventSignature OnStarted;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceRecognitionResultSignature OnPartial;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceRecognitionResultSignature OnFinal;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceRecognitionProviderEventSignature OnError;

private:
	/** 执行句柄Started流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICERECOGNITIONFRAMEWORK_API void HandleStarted(FVoiceRecognitionProviderEvent InEvent);

	/** 执行句柄部分流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICERECOGNITIONFRAMEWORK_API void HandlePartial(FVoiceRecognitionResult InResult);

	/** 执行句柄Final流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICERECOGNITIONFRAMEWORK_API void HandleFinal(FVoiceRecognitionResult InResult);

	/** 执行句柄Error流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICERECOGNITIONFRAMEWORK_API void HandleError(FVoiceRecognitionProviderEvent InEvent);

	/** 解绑，保持对象生命周期内的委托连接一致。 */
	void Unbind();

	/** 创建错误事件。 */
	static FVoiceRecognitionProviderEvent MakeErrorEvent(const FString& InMessage);

private:
	/** 持有识别组件实例，供语音系统运行时复用。 */
	UPROPERTY()
	TObjectPtr<UVoiceRecognitionComponent> RecognitionComponent=nullptr;

	/** 记录音频文件路径。 */
	FString AudioFilePath;

	/** 标记Bound状态。 */
	bool bBound = false;

	/** 标记音频Submitted。 */
	bool bAudioSubmitted = false;
};
