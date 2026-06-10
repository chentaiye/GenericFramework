// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/CancellableAsyncAction.h"
#include "GameplayMessageSubsystem.h"
#include "GameplayMessageType.h"
#include "ListenForGameplayMessagesAsyncAction.generated.h"

class UScriptStruct;
class UWorld;
struct FFrame;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAsyncGameplayMessageDelegate, UListenForGameplayMessagesAsyncAction*, ProxyObject, FGameplayTag, ActualChannel);

/** 作为Listen用于GameplayMessages异步动作能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI, BlueprintType, meta=(HasDedicatedAsyncNode))
class UListenForGameplayMessagesAsyncAction : public UCancellableAsyncAction
{
	GENERATED_BODY()

public:
	/** 创建Gameplay消息监听异步动作，在指定频道收到匹配Payload时广播给蓝图。 */
	UFUNCTION(BlueprintCallable, Category="Messaging", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICMESSAGEFRAMEWORK_API UListenForGameplayMessagesAsyncAction* ListenForGameplayMessages(UObject* WorldContextObject, FGameplayTag Channel, UScriptStruct* PayloadType, EGameplayMessageMatch MatchType = EGameplayMessageMatch::ExactMatch);

	/** 获取Payload。 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Messaging", meta=(CustomStructureParam="OutPayload"))
	GENERICMESSAGEFRAMEWORK_API bool GetPayload(UPARAM(ref) int32& OutPayload);

	DECLARE_FUNCTION(execGetPayload);

	GENERICMESSAGEFRAMEWORK_API virtual void Activate() override;
	GENERICMESSAGEFRAMEWORK_API virtual void SetReadyToDestroy() override;

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FAsyncGameplayMessageDelegate OnMessageReceived;

private:
	/** 执行句柄消息Received流程，并把结果同步给Gameplay 消息相关状态。 */
	void HandleMessageReceived(FGameplayTag Channel, const UScriptStruct* StructType, const void* Payload);

private:
	/** 缓存收到消息Payload指针。 */
	const void* ReceivedMessagePayloadPtr = nullptr;

	/** 缓存世界指针。 */
	TWeakObjectPtr<UWorld> WorldPtr;

	/** 记录频道目标注册。 */
	FGameplayTag ChannelToRegister;

	/** 弱引用消息结构体类型，避免运行时回调延长对象生命周期。 */
	TWeakObjectPtr<UScriptStruct> MessageStructType = nullptr;

	/** 记录消息匹配类型。 */
	EGameplayMessageMatch MessageMatchType = EGameplayMessageMatch::ExactMatch;

	/** 记录监听器句柄。 */
	FGameplayMessageListenerHandle ListenerHandle;
};
