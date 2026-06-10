// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "LoadDefaultLayoutTask.generated.h"

class UGenericLayout;

/** StateTree 实例数据记录默认 Layout 注册任务是否已经在进入状态时完成。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FLoadDefaultLayoutTaskInstanceData
{
	GENERATED_BODY()

	bool bIsFinished = false;
};

/** 为每个本地玩家注册 UI 根布局，进入状态时直接返回成功或失败。 */
USTRUCT(meta=(DisplayName="Load Default Layout", Category="Project"))
struct GENERICWIDGETFRAMEWORK_API FLoadDefaultLayoutTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadDefaultLayoutTask();

	using FInstanceDataType = FLoadDefaultLayoutTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

	/** 要注册到本地玩家 LayoutSubsystem 的根布局类；为空、没有本地玩家或玩家已有 Layout 时不会创建新布局。 */
	UPROPERTY(EditAnywhere, Category="Project")
	TSubclassOf<UGenericLayout> LayoutClass;
};
