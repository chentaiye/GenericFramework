// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "VoiceTypes.h"
#include "VoiceComponentBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FVoiceComponentStateChangedSignature, UActorComponent*, Component, EVoiceComponentState, PreviousState, EVoiceComponentState, CurrentState);

/** 作为Actor组件承载语音组件基础能力状态与事件转发，便于挂接到场景对象。 */
UCLASS(MinimalAPI, Blueprintable, Abstract, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UVoiceComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	/** 初始化语音组件基础的默认运行状态。 */
	GENERICVOICEFRAMEWORK_API UVoiceComponentBase();

	/** 获取语音组件状态。 */
	UFUNCTION(BlueprintPure, Category="Voice")
	EVoiceComponentState GetVoiceComponentState() const { return VoiceComponentState; }

	/** 获取已选中提供器名称。 */
	UFUNCTION(BlueprintPure, Category="Voice")
	FName GetSelectedProviderName() const { return SelectedProviderName; }

	/** 获取已选中路由来源。 */
	UFUNCTION(BlueprintPure, Category="Voice")
	EVoiceRouteSource GetSelectedRouteSource() const { return SelectedRouteSource; }

	/** 获取上次错误消息。 */
	UFUNCTION(BlueprintPure, Category="Voice")
	FString GetLastErrorMessage() const { return LastErrorMessage; }

	/** 获取上次状态消息。 */
	UFUNCTION(BlueprintPure, Category="Voice")
	FString GetLastStatusMessage() const { return LastStatusMessage; }

	UPROPERTY(BlueprintAssignable, Category="Voice")
	FVoiceComponentStateChangedSignature OnVoiceComponentStateChanged;

protected:
	/** 设置语音组件状态。 */
	GENERICVOICEFRAMEWORK_API void SetVoiceComponentState(EVoiceComponentState InState);

	/** 设置语音路由信息。 */
	GENERICVOICEFRAMEWORK_API void SetVoiceRouteInfo(FName InProviderName, EVoiceRouteSource InRouteSource, const FString& InStatusMessage);

	/** 设置语音错误。 */
	GENERICVOICEFRAMEWORK_API void SetVoiceError(const FString& InErrorMessage);

protected:
	/** 记录语音组件状态。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Voice")
	EVoiceComponentState VoiceComponentState=EVoiceComponentState::Uninitialized;

	/** 已选中提供器名称。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Voice")
	FName SelectedProviderName=NAME_None;

	/** 记录Selected路由来源。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Voice")
	EVoiceRouteSource SelectedRouteSource=EVoiceRouteSource::None;

	/** 记录LastError消息。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Voice")
	FString LastErrorMessage;

	/** 记录Last状态消息。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Voice")
	FString LastStatusMessage;
};
