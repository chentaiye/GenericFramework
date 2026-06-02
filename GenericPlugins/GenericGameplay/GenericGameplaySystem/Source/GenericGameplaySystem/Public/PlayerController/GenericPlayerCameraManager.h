// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "GenericPlayerCameraManager.generated.h"

/** 承载玩家相机管理器职责，衔接上层调用与模块内部实现。 */
UCLASS(MinimalAPI)
class AGenericPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
};
