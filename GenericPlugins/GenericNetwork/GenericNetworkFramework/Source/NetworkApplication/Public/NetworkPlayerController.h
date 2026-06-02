// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerController/GenericPlayerController.h"
#include "NetworkPlayerController.generated.h"

/** 网络玩家控制器类型，作为 ANetworkGameMode 的默认 PlayerController 并保留网络交互扩展点。 */
UCLASS(MinimalAPI)
class ANetworkPlayerController : public AGenericPlayerController
{
	GENERATED_BODY()

public:
	/** 构造网络玩家控制器，当前沿用父类行为并为模块默认控制器类型提供显式入口。 */
	NETWORKAPPLICATION_API ANetworkPlayerController();
};
