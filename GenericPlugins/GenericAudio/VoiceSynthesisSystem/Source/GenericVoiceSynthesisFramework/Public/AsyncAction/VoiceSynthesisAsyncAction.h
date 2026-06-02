// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceSynthesisTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "VoiceSynthesisAsyncAction.generated.h"

class UVoiceSynthesisComponent;

/** 封装语音合成异步动作能力蓝图异步节点，负责启动请求并广播完成结果。 */
UCLASS(MinimalAPI)
class UVoiceSynthesisAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 向语音合成服务提交Synthesize文本请求，并通过回调返回音频结果。 */
	UFUNCTION(BlueprintCallable, Category="Voice|Synthesis", meta=(BlueprintInternalUseOnly="true"))
	static GENERICVOICESYNTHESISFRAMEWORK_API UVoiceSynthesisAsyncAction* SynthesizeText(UVoiceSynthesisComponent* InSynthesisComponent, const FString& InText, const FString& InOutputFilePath);

	GENERICVOICESYNTHESISFRAMEWORK_API virtual void Activate() override;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceSynthesisProviderEventSignature OnStarted;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceSynthesisResultSignature OnCompleted;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FVoiceSynthesisProviderEventSignature OnError;

private:
	/** 执行句柄Started流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICESYNTHESISFRAMEWORK_API void HandleStarted(FVoiceSynthesisProviderEvent InEvent);

	/** 执行句柄Completed流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICESYNTHESISFRAMEWORK_API void HandleCompleted(FVoiceSynthesisResult InResult);

	/** 执行句柄Error流程，并把结果同步给语音系统相关状态。 */
	UFUNCTION(Category="Voice|Async Action")
	GENERICVOICESYNTHESISFRAMEWORK_API void HandleError(FVoiceSynthesisProviderEvent InEvent);

	/** 解绑，保持对象生命周期内的委托连接一致。 */
	void Unbind();

	/** 创建错误事件。 */
	static FVoiceSynthesisProviderEvent MakeErrorEvent(const FString& InMessage);

private:
	/** 缓存合成组件。 */
	UPROPERTY()
	TObjectPtr<UVoiceSynthesisComponent> SynthesisComponent=nullptr;

	/** 记录文本。 */
	FString Text;

	/** 记录输出文件路径。 */
	FString OutputFilePath;

	/** 标记Bound状态。 */
	bool bBound = false;
};
