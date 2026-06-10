// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "LoadDefaultCameraTask.generated.h"

class UGenericCameraSwitchMethod;

/** 提供默认相机加载任务的 StateTree 实例数据，确保任务节点在编译时拥有有效实例值。 */
USTRUCT()
struct GENERICCAMERASYSTEM_API FLoadDefaultCameraTaskInstanceData
{
	GENERATED_BODY()
};

/** StateTree 状态进入时，把每个本地玩家的相机子系统切到指定 CameraPoint。 */
USTRUCT(meta=(DisplayName="Load Default Camera", Category="Project"))
struct GENERICCAMERASYSTEM_API FLoadDefaultCameraTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	FLoadDefaultCameraTask();

	using FInstanceDataType = FLoadDefaultCameraTaskInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

	/** 要切换到的 CameraPoint 标签；标签无效时不执行切换并直接让当前状态成功。 */
	UPROPERTY(EditAnywhere, Category="Project", meta=(Categories="GameplayCamera"))
	FGameplayTag DefaultCameraTag;

	/** 切换时复制到玩家 CameraSubsystem 的方法模板；为空时为该玩家创建 Teleport 方法实例。 */
	UPROPERTY(EditAnywhere, Instanced, Category="Project")
	TObjectPtr<UGenericCameraSwitchMethod> DefaultCameraSwitchMethod = nullptr;
};
