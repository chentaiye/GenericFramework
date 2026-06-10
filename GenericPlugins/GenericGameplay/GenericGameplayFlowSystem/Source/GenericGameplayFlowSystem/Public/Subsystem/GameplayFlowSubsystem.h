// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeExecutionTypes.h"
#include "StateTreeInstanceData.h"
#include "Subsystem/GenericTickableWorldSubsystem.h"
#include "GameplayFlowSubsystem.generated.h"

class UGameplayFlowWorldSettings;
class UStateTree;
struct FStateTreeExecutionContext;
struct FStateTreeDataView;
struct FStateTreeExternalDataDesc;

/** 负责在运行时持有并推进 Gameplay Flow 状态树，使 Linked Asset 子流程完成后父流程可以继续执行。 */
UCLASS(MinimalAPI)
class UGameplayFlowSubsystem : public UGenericTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	/** 通过世界上下文取得 Gameplay Flow 运行时子系统，便于配置对象和其他 C++ 调用统一入口。 */
	static GENERICGAMEPLAYFLOWSYSTEM_API UGameplayFlowSubsystem* Get(const UObject* WorldContextObject);

	/** 使用指定 StateTree 启动主 Gameplay Flow，已运行的流程会先被停止。 */
	GENERICGAMEPLAYFLOWSYSTEM_API bool StartGameplayFlow(UStateTree* StateTree);

	/** 停止当前正在运行的 Gameplay Flow，并清理持有的 StateTree 实例数据。 */
	GENERICGAMEPLAYFLOWSYSTEM_API void StopGameplayFlow(EStateTreeRunStatus CompletionStatus = EStateTreeRunStatus::Stopped);

	/** 返回当前世界是否仍有 Gameplay Flow 状态树在运行。 */
	bool IsGameplayFlowRunning() const { return bIsGameplayFlowRunning; }

protected:
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual void OnWorldBeginTearDown(UWorld* InWorld) override;
	virtual void Deinitialize() override;

private:
	/** 校验主状态树是否存在、已编译，并且使用 Gameplay Flow 专用 Schema。 */
	bool ValidateStateTree(const UStateTree* StateTree) const;

	/** 为当前执行上下文绑定 Schema 要求的 World 和 WorldSettings 数据。 */
	bool SetContextRequirements(FStateTreeExecutionContext& Context) const;

	/** 从当前世界设置集合中解析 Gameplay Flow 设置实例，仅在上下文绑定时临时使用。 */
	UGameplayFlowWorldSettings* ResolveWorldSettings() const;

	/** 为 StateTree 节点解析额外外部数据，支持 Linked Asset 子树重复收集。 */
	bool CollectExternalData(const FStateTreeExecutionContext& Context, const UStateTree* StateTree, TArrayView<const FStateTreeExternalDataDesc> Descs, TArrayView<FStateTreeDataView> OutDataViews) const;

	/** 结束当前 Gameplay Flow 运行时记录，仅保留日志状态，不再触发额外 Stop。 */
	void FinishGameplayFlow(EStateTreeRunStatus CompletionStatus);

private:
	/** 当前主 Gameplay Flow StateTree 资产，用于每帧重新构造执行上下文。 */
	UPROPERTY(Transient)
	TObjectPtr<UStateTree> ActiveStateTree = nullptr;

	/** StateTree 的持久运行时实例数据，保存活动状态、Linked Asset 子树和任务状态。 */
	FStateTreeInstanceData StateTreeInstanceData;

	/** 标记当前世界是否有 Gameplay Flow 正在等待后续 Tick 推进。 */
	bool bIsGameplayFlowRunning = false;
};
