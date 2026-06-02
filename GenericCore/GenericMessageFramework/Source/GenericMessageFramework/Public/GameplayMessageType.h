// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeGameplayTags.h"
#include "GameplayMessageType.generated.h"

class UGameplayMessageRouter;

GENERICMESSAGEFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel);

/** 定义消息监听器匹配频道时使用的规则。 */
UENUM(BlueprintType)
enum class EGameplayMessageMatch : uint8
{
	/** 只接收与注册频道完全一致的消息。 */
	ExactMatch,

	/** 接收注册频道及其子频道上的消息。 */
	PartialMatch
};

/** 封装Gameplay消息Listener Params。 */
template<typename FMessageStructType>
struct FGameplayMessageListenerParams
{
	/** 记录匹配类型。 */
	EGameplayMessageMatch MatchType = EGameplayMessageMatch::ExactMatch;

	/** 收到匹配频道消息时执行的强类型回调。 */
	TFunction<void(FGameplayTag, const FMessageStructType&)> OnMessageReceivedCallback;

	/** 绑定对象成员函数作为消息回调，并通过弱引用避免延长对象生命周期。 */
	template<typename TOwner = UObject>
	void SetMessageReceivedCallback(TOwner* Object, void(TOwner::* Function)(FGameplayTag, const FMessageStructType&))
	{
		TWeakObjectPtr<TOwner> WeakObject(Object);
		OnMessageReceivedCallback = [WeakObject, Function](FGameplayTag Channel, const FMessageStructType& Payload)
		{
			if (TOwner* StrongObject = WeakObject.Get()) { (StrongObject->*Function)(Channel, Payload); }
		};
	}
};
