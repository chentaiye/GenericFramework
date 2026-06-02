// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VoiceRecognitionTypes.h"
#include "VoiceRecognitionInterface.generated.h"

/** 定义语音Recognition接口契约，供模块在不同实现之间解耦调用。 */
UINTERFACE(MinimalAPI, BlueprintType)
class UVoiceRecognitionInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义语音Recognition接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICERECOGNITIONFRAMEWORK_API IVoiceRecognitionInterface
{
	GENERATED_BODY()

public:
	/** 响应识别状态变化回调，并把外部事件转换为当前对象状态或委托通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Recognition")
	void OnRecognitionStateChanged(EVoiceRecognitionState InState);

	/** 响应Recognition Partial结果。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Recognition")
	void OnRecognitionPartialResult(const FVoiceRecognitionResult& InResult);

	/** 响应Recognition Final结果。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Recognition")
	void OnRecognitionFinalResult(const FVoiceRecognitionResult& InResult);

	/** 响应Recognition错误。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Recognition")
	void OnRecognitionError(const FString& InErrorMessage);
};
