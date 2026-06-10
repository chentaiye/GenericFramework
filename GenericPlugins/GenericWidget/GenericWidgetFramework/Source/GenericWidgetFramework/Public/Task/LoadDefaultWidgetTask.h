// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "LoadDefaultWidgetTask.generated.h"

class UGenericWidget;

/** StateTree 实例数据记录本任务创建出的 Widget，供后续节点或绑定读取。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FLoadDefaultWidgetTaskInstanceData
{
	GENERATED_BODY()

	TArray<TWeakObjectPtr<UGenericWidget>> CreatedWidgets;
	bool bIsFinished = false;
};

/** 为每个本地玩家创建业务 Widget 并加入 PlayerScreen，进入状态时直接返回成功或失败。 */
USTRUCT(meta=(DisplayName="Load Default Widget", Category="Project"))
struct GENERICWIDGETFRAMEWORK_API FLoadDefaultWidgetTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadDefaultWidgetTask();

	using FInstanceDataType = FLoadDefaultWidgetTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

	/** 需要随世界启动创建的业务 Widget 类；空列表或没有本地玩家时任务直接成功。 */
	UPROPERTY(EditAnywhere, Category="Project")
	TArray<TSubclassOf<UGenericWidget>> GenericWidgetClasses;
};
