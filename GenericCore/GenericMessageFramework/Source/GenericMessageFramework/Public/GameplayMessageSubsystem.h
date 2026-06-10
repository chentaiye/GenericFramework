// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameplayMessageType.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayMessageSubsystem.generated.h"

class UGameplayMessageSubsystem;
struct FFrame;

GENERICMESSAGEFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogGameplayMessageSubsystem, Log, All);

class UListenForGameplayMessagesAsyncAction;

/** 保存消息监听器的注册位置，使调用方可以在之后取消监听。 */
USTRUCT(BlueprintType)
struct FGameplayMessageListenerHandle
{
public:
	GENERATED_BODY()

	/** 创建一个尚未绑定任何监听器的空句柄。 */
	FGameplayMessageListenerHandle()
	{
	}

	/** 从消息子系统中取消当前句柄对应的监听器。 */
	GENERICMESSAGEFRAMEWORK_API void Unregister();

	/** 判断当前句柄是否仍指向已注册的监听器。 */
	bool IsValid() const { return ID != 0; }

private:
	/** 缓存子系统。 */
	UPROPERTY(Transient)
	TWeakObjectPtr<UGameplayMessageSubsystem> Subsystem;

	/** 记录频道。 */
	UPROPERTY(Transient)
	FGameplayTag Channel;

	/** 记录ID。 */
	UPROPERTY(Transient)
	int32 ID = 0;

	/** 保存状态清理委托句柄，用于解绑对应委托。 */
	FDelegateHandle StateClearedHandle;

	friend UGameplayMessageSubsystem;

	FGameplayMessageListenerHandle(UGameplayMessageSubsystem* InSubsystem, FGameplayTag InChannel, int32 InID) : Subsystem(InSubsystem), Channel(InChannel), ID(InID)
	{
	}
};

/** 保存Gameplay 消息中的Gameplay 消息监听器数据，用于在运行时流程和蓝图之间传递。 */
USTRUCT()
struct FGameplayMessageListenerData
{
	GENERATED_BODY()

	/** 接收匹配频道消息后执行的类型擦除回调。 */
	TFunction<void(FGameplayTag, const UScriptStruct*, const void*)> ReceivedCallback;

	/** 记录监听器句柄 ID。 */
	int32 HandleID;

	/** 记录匹配类型。 */
	EGameplayMessageMatch MatchType;

	/** 弱引用监听器期望的消息结构体类型，避免运行时回调延长对象生命周期。 */
	TWeakObjectPtr<const UScriptStruct> ListenerStructType = nullptr;

	/** 标记是否曾绑定有效消息类型状态。 */
	bool bHadValidType = false;
};

/** 调度Gameplay消息子系统运行。 */
UCLASS(MinimalAPI)
class UGameplayMessageSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	friend UListenForGameplayMessagesAsyncAction;

public:
	static GENERICMESSAGEFRAMEWORK_API UGameplayMessageSubsystem& Get(const UObject* WorldContextObject);

	/** 判断是否包含实例。 */
	static GENERICMESSAGEFRAMEWORK_API bool HasInstance(const UObject* WorldContextObject);

	//~USubsystem interface
	GENERICMESSAGEFRAMEWORK_API virtual void Deinitialize() override;
	//~End of USubsystem interface

	/** 向指定频道广播不携带业务载荷的消息。 */
	GENERICMESSAGEFRAMEWORK_API void BroadcastMessage(FGameplayTag Channel);

	/** 执行广播消息。 */
	template <typename FMessageStructType>
	void BroadcastMessage(FGameplayTag Channel, const FMessageStructType& Message)
	{
		const UScriptStruct* StructType = TBaseStructure<FMessageStructType>::Get();
		BroadcastMessageInternal(Channel, StructType, &Message);
	}

	/** 向指定频道广播类型擦除后的消息。 */
	void BroadcastMessageStruct(FGameplayTag Channel, const UScriptStruct* StructType, const void* MessageBytes);

	/** 注册只关心频道命中的监听器，适合不需要读取消息载荷的运行时流程。 */
	FGameplayMessageListenerHandle RegisterListener(FGameplayTag Channel, TFunction<void(FGameplayTag)>&& Callback, EGameplayMessageMatch MatchType = EGameplayMessageMatch::ExactMatch)
	{
		FGameplayMessageListenerHandle Handle;

		if (Callback)
		{
			auto ThunkCallback = [InnerCallback = MoveTemp(Callback)](FGameplayTag ActualTag, const UScriptStruct* SenderStructType, const void* SenderPayload)
			{
				InnerCallback(ActualTag);
			};

			Handle = RegisterListenerInternal(Channel, ThunkCallback, nullptr, MatchType);
		}

		return Handle;
	}

	/** 注册Listener。 */
	template <typename FMessageStructType>
	FGameplayMessageListenerHandle RegisterListener(FGameplayTag Channel, TFunction<void(FGameplayTag, const FMessageStructType&)>&& Callback, EGameplayMessageMatch MatchType = EGameplayMessageMatch::ExactMatch)
	{
		auto ThunkCallback = [InnerCallback = MoveTemp(Callback)](FGameplayTag ActualTag, const UScriptStruct* SenderStructType, const void* SenderPayload)
		{
			InnerCallback(ActualTag, *reinterpret_cast<const FMessageStructType*>(SenderPayload));
		};

		const UScriptStruct* StructType = TBaseStructure<FMessageStructType>::Get();
		return RegisterListenerInternal(Channel, ThunkCallback, StructType, MatchType);
	}

	/** 注册对象成员函数作为频道监听器，回调时自动校验对象弱引用。 */
	template <typename FMessageStructType, typename TOwner = UObject>
	FGameplayMessageListenerHandle RegisterListener(FGameplayTag Channel, TOwner* Object, void (TOwner::*Function)(FGameplayTag, const FMessageStructType&))
	{
		TWeakObjectPtr<TOwner> WeakObject(Object);
		return RegisterListener<FMessageStructType>
		(
			Channel,
			[WeakObject, Function](FGameplayTag Channel, const FMessageStructType& Payload)
			{
				if (TOwner* StrongObject = WeakObject.Get()) { (StrongObject->*Function)(Channel, Payload); }
			}
		);
	}

	/** 按参数对象注册频道监听器，未提供回调时返回空句柄。 */
	template <typename FMessageStructType>
	FGameplayMessageListenerHandle RegisterListener(FGameplayTag Channel, FGameplayMessageListenerParams<FMessageStructType>& Params)
	{
		FGameplayMessageListenerHandle Handle;

		/** 仅在调用方提供回调时注册监听，避免生成无法消费消息的句柄。 */
		if (Params.OnMessageReceivedCallback)
		{
			auto ThunkCallback = [InnerCallback = Params.OnMessageReceivedCallback](FGameplayTag ActualTag, const UScriptStruct* SenderStructType, const void* SenderPayload)
			{
				InnerCallback(ActualTag, *reinterpret_cast<const FMessageStructType*>(SenderPayload));
			};

			const UScriptStruct* StructType = TBaseStructure<FMessageStructType>::Get();
			Handle = RegisterListenerInternal(Channel, ThunkCallback, StructType, Params.MatchType);
		}

		return Handle;
	}

	/** 维护注销监听器在Gameplay 消息中的注册关系。 */
	GENERICMESSAGEFRAMEWORK_API void UnregisterListener(FGameplayMessageListenerHandle Handle);

protected:
	/** 蓝图入口：按频道广播任意结构体消息。 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Messaging", meta=(CustomStructureParam="Message", AllowAbstract="false", DisplayName="Broadcast Message"))
	GENERICMESSAGEFRAMEWORK_API void K2_BroadcastMessage(FGameplayTag Channel, const int32& Message);

	DECLARE_FUNCTION(execK2_BroadcastMessage);

private:
	/** 把类型擦除后的消息载荷分发给所有匹配监听器。 */
	GENERICMESSAGEFRAMEWORK_API void BroadcastMessageInternal(FGameplayTag Channel, const UScriptStruct* StructType, const void* MessageBytes);

	/** 注册类型擦除后的消息监听器，并记录频道、结构体类型和匹配规则。 */
	GENERICMESSAGEFRAMEWORK_API FGameplayMessageListenerHandle RegisterListenerInternal(
		FGameplayTag Channel,
		TFunction<void(FGameplayTag, const UScriptStruct*, const void*)>&& Callback,
		const UScriptStruct* StructType,
		EGameplayMessageMatch MatchType);

	/** 维护注销监听器Internal在Gameplay 消息中的注册关系。 */
	GENERICMESSAGEFRAMEWORK_API void UnregisterListenerInternal(FGameplayTag Channel, int32 HandleID);

private:
	/** 保存Gameplay 消息流程中的频道监听器列表数据，供运行时传递和蓝图访问。 */
	struct FChannelListenerList
	{
		/** 保存监听器集合列表，供Gameplay 消息批量处理。 */
		TArray<FGameplayMessageListenerData> Listeners;

		/** 记录监听器句柄 ID。 */
		int32 HandleID = 0;
	};

private:
	/** 保存按频道索引的消息监听器表映射，供Gameplay 消息按键快速查找。 */
	TMap<FGameplayTag, FChannelListenerList> ListenerMap;
};
