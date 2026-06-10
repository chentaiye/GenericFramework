// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayMessageSubsystem.h"
#include "StateTreeTaskBase.h"
#include "ListenForGameplayMessageTask.generated.h"

/** 保存 Gameplay Message 监听任务的运行时句柄和命中结果，供 StateTree Tick 判断任务状态。 */
struct FListenForGameplayMessageTaskRuntimeState
{
	/** 保存当前任务注册到消息子系统的所有监听句柄，退出状态时统一注销。 */
	TArray<FGameplayMessageListenerHandle> ListenerHandles;

	/** 记录最近一次触发成功或失败结果的实际消息频道。 */
	FGameplayTag LastMatchedChannel;

	/** 标记任务是否已经收到失败频道，失败结果优先于成功结果。 */
	bool bHasFailed = false;

	/** 标记任务是否已经收到成功频道。 */
	bool bHasSucceeded = false;
};

/** StateTree 实例数据记录消息监听任务最近一次命中的频道和运行时状态。 */
USTRUCT()
struct GENERICMESSAGEFRAMEWORK_API FListenForGameplayMessageTaskInstanceData
{
	GENERATED_BODY()

	/** 缓存最近一次触发任务结果的实际消息频道。 */
	FGameplayTag LastMatchedChannel;

	/** 记录当前任务是否已经收到失败频道。 */
	bool bHasFailed = false;

	/** 记录当前任务是否已经收到成功频道。 */
	bool bHasSucceeded = false;

	/** 保存监听句柄等运行时数据，状态退出时会被清理。 */
	TSharedPtr<FListenForGameplayMessageTaskRuntimeState> RuntimeState;
};

/** 进入状态后监听 Gameplay Message 频道，收到成功频道则完成，收到失败频道则失败。 */
USTRUCT(meta=(DisplayName="Listen For Gameplay Message", Category="Messaging"))
struct GENERICMESSAGEFRAMEWORK_API FListenForGameplayMessageTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FListenForGameplayMessageTask();

	using FInstanceDataType = FListenForGameplayMessageTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;

	/** 控制监听频道与实际广播频道之间的匹配规则。 */
	UPROPERTY(EditAnywhere, Category="Messaging")
	EGameplayMessageMatch MatchType = EGameplayMessageMatch::ExactMatch;

	/** 收到这些频道中的任意消息后任务返回成功，空列表不会主动结束任务。 */
	UPROPERTY(EditAnywhere, Category="Messaging", meta=(Categories="GameplayMessage.Channel"))
	TArray<FGameplayTag> SuccessChannels;

	/** 收到这些频道中的任意消息后任务返回失败，失败结果优先于成功结果。 */
	UPROPERTY(EditAnywhere, Category="Messaging", meta=(Categories="GameplayMessage.Channel"))
	TArray<FGameplayTag> FailureChannels;
};
