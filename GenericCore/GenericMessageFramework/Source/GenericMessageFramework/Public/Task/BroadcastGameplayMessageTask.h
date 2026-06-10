// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayMessageSubsystem.h"
#include "Misc/EngineVersionComparison.h"
#include "StateTreeTaskBase.h"
#if UE_VERSION_OLDER_THAN(5, 5, 0)
#include "InstancedStruct.h"
#else
#include "StructUtils/InstancedStruct.h"
#endif
#include "BroadcastGameplayMessageTask.generated.h"

/** 提供广播 Gameplay Message 任务的 StateTree 实例数据，确保任务节点在编译时拥有有效实例值。 */
USTRUCT()
struct GENERICMESSAGEFRAMEWORK_API FBroadcastGameplayMessageTaskInstanceData
{
	GENERATED_BODY()
};

/** 进入状态时广播一个 Gameplay Message 频道，并可选携带结构体消息载荷。 */
USTRUCT(meta=(DisplayName="Broadcast Gameplay Message", Category="Messaging"))
struct GENERICMESSAGEFRAMEWORK_API FBroadcastGameplayMessageTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FBroadcastGameplayMessageTask();

	using FInstanceDataType = FBroadcastGameplayMessageTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

	/** 进入状态时要广播的唯一消息频道，频道无效时任务失败。 */
	UPROPERTY(EditAnywhere, Category="Messaging", meta=(Categories="GameplayMessage.Channel"))
	FGameplayTag Channel;

	/** 进入状态时随频道一并广播的可选结构体消息，未配置时会发送空频道载荷以保持兼容行为。 */
	UPROPERTY(EditAnywhere, Category="Messaging")
	FInstancedStruct Message;
};
