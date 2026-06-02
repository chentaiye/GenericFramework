// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraSwitch/GenericCameraSwitchMethod.h"
#include "GenericCameraSwitchMethod_Transition.generated.h"

/** 使用 PlayerCameraManager 的 ViewTarget 过渡参数执行平滑镜头切换。 */
UCLASS(MinimalAPI)
class UGenericCameraSwitchMethod_Transition : public UGenericCameraSwitchMethod
{
	GENERATED_BODY()

public:
	/** 初始化默认一秒三次曲线过渡，作为世界设置和蓝图节点的基础镜头切换方式。 */
	UGenericCameraSwitchMethod_Transition(const FObjectInitializer& ObjectInitializer);

	virtual bool HandleSwitchToCameraPoint_Implementation(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint) override;
	virtual void OnSwitchToCameraPointReset_Implementation() override;
	virtual void OnSwitchToCameraPointFinish_Implementation() override;
	virtual float GetSwitchDuration_Implementation() override;

public:
	/** 传给 PlayerCameraManager::SetViewTarget 的过渡参数，决定混合时间、曲线和出镜锁定行为。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Camera Switch Method Transition")
	FViewTargetTransitionParams ViewTargetTransitionParams;

protected:
	/** 跟随 BlendTime 等待切换完成；重置或完成时必须清理，避免旧回调结束新切换。 */
	FTimerHandle TimerHandle;
};
