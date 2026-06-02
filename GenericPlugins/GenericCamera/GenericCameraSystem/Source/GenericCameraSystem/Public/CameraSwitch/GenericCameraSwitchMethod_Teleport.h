// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraSwitch/GenericCameraSwitchMethod.h"
#include "GenericCameraSwitchMethod_Teleport.generated.h"

/** 立即把玩家视角切到目标相机点，不创建过渡计时器。 */
UCLASS(MinimalAPI)
class UGenericCameraSwitchMethod_Teleport : public UGenericCameraSwitchMethod
{
	GENERATED_BODY()

public:
	virtual bool HandleSwitchToCameraPoint_Implementation(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint) override;
	virtual void OnSwitchToCameraPointReset_Implementation() override;
	virtual void OnSwitchToCameraPointFinish_Implementation() override;

protected:
	/** 预留给派生实现的标记，表示切换完成后需要同步 Pawn 中心点。 */
	bool bUpdatePawnCenterPointAfterSwitchFinish = false;
};
