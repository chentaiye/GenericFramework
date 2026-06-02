// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VoiceSynthesisTypes.h"
#include "VoiceSynthesisInterface.generated.h"

/** 定义语音合成接口契约，供模块在不同实现之间解耦调用。 */
UINTERFACE(MinimalAPI, BlueprintType)
class UVoiceSynthesisInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义语音合成接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICESYNTHESISFRAMEWORK_API IVoiceSynthesisInterface
{
	GENERATED_BODY()

public:
	/** 响应合成状态变化回调，并把外部事件转换为当前对象状态或委托通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Synthesis")
	void OnSynthesisStateChanged(EVoiceSynthesisState InState);

	/** 响应合成已完成。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Synthesis")
	void OnSynthesisCompleted(const FVoiceSynthesisResult& InResult);

	/** 响应合成错误。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Synthesis")
	void OnSynthesisError(const FString& InErrorMessage);
};
