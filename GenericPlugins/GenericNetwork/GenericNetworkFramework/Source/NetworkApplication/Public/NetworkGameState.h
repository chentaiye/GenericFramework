// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameState/GenericGameState.h"
#include "NetworkGameState.generated.h"

/** 网络游戏状态类型，配合 ANetworkGameMode 作为本模块默认 GameState 承载复制状态扩展。 */
UCLASS(MinimalAPI)
class ANetworkGameState : public AGenericGameState
{
	GENERATED_BODY()
};
