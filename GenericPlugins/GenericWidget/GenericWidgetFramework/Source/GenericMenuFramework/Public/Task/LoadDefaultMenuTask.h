// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "LoadDefaultMenuTask.generated.h"

class UMenuCollection;

/** StateTree 实例数据记录本任务注册出的菜单集，供后续节点或绑定读取。 */
USTRUCT()
struct GENERICMENUFRAMEWORK_API FLoadDefaultMenuTaskInstanceData
{
	GENERATED_BODY()

	TArray<TWeakObjectPtr<UMenuCollection>> CreatedMenuCollections;
	bool bIsFinished = false;
};

/** 通过每个本地玩家的 MenuSubsystem 注册默认菜单集，进入状态时直接返回成功或失败。 */
USTRUCT(meta=(DisplayName="Load Default Menu", Category="Project"))
struct GENERICMENUFRAMEWORK_API FLoadDefaultMenuTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadDefaultMenuTask();

	using FInstanceDataType = FLoadDefaultMenuTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

	/** 需要随世界启动注册的菜单集类型；空列表或没有本地玩家时任务直接成功。 */
	UPROPERTY(EditAnywhere, Category="Project", meta=(AllowAbstract="false"))
	TArray<TSubclassOf<UMenuCollection>> MenuCollectionClasses;
};
