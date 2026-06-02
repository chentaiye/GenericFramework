// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "Engine/CancellableAsyncAction.h"
#include "GameplayTagContainer.h"
#include "BroadcastGameplayMessageAsyncAction.generated.h"

#define UE_API GENERICMESSAGEFRAMEWORK_API

class UScriptStruct;
class UWorld;
struct FFrame;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBroadcastGameplayMessageAsyncDelegate);

/** 广播Gameplay消息异步操作类。 */
UCLASS(MinimalAPI, BlueprintType, meta=(HasDedicatedAsyncNode))
class UBroadcastGameplayMessageAsyncAction : public UCancellableAsyncAction
{
	GENERATED_BODY()

public:
	/** 广播Gameplay消息。 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Messaging", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true", CustomStructureParam="Message"))
	static UE_API UBroadcastGameplayMessageAsyncAction* BroadcastGameplayMessage(UObject* WorldContextObject, FGameplayTag Channel, const int32& Message);

	DECLARE_FUNCTION(execBroadcastGameplayMessage);

	UE_API virtual void Activate() override;
	UE_API virtual void SetReadyToDestroy() override;

public:
	/** 记录Completed。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FBroadcastGameplayMessageAsyncDelegate Completed;

private:
	/** 创建动作。 */
	static UBroadcastGameplayMessageAsyncAction* CreateAction(UObject* WorldContextObject, FGameplayTag Channel, const UScriptStruct* MessageStruct, const void* MessageBytes);

	/** 重置消息Payload。 */
	void ResetMessagePayload();

private:
	/** 缓存世界指针。 */
	TWeakObjectPtr<UWorld> WorldPtr;

	/** 记录频道目标Broadcast。 */
	FGameplayTag ChannelToBroadcast;

	/** 弱引用消息结构体类型，避免运行时回调延长对象生命周期。 */
	TWeakObjectPtr<UScriptStruct> MessageStructType = nullptr;

	/** 保存消息载荷列表，供Gameplay 消息批量处理。 */
	TArray<uint8> MessagePayload;
};

#undef UE_API
