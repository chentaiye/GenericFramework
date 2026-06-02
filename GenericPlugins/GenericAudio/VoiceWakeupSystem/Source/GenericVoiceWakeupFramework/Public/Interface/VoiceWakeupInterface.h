// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VoiceWakeupTypes.h"
#include "VoiceWakeupInterface.generated.h"

/** 定义语音唤醒接口契约，供模块在不同实现之间解耦调用。 */
UINTERFACE(MinimalAPI, BlueprintType)
class UVoiceWakeupInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义语音唤醒接口契约，供模块在不同实现之间解耦调用。 */
class GENERICVOICEWAKEUPFRAMEWORK_API IVoiceWakeupInterface
{
	GENERATED_BODY()

public:
	/** 响应唤醒状态变化回调，并把外部事件转换为当前对象状态或委托通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Wakeup")
	void OnWakeupStateChanged(EVoiceWakeupState InState);

	/** 响应唤醒Detected。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Wakeup")
	void OnWakeupDetected(const FVoiceWakeupResult& InResult);

	/** 响应唤醒错误。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Voice|Wakeup")
	void OnWakeupError(const FString& InErrorMessage);
};
