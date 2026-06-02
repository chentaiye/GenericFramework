// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/GenericGameMode.h"
#include "NetworkGameMode.generated.h"

/** 网络专用游戏模式，构造时把默认 GameState、PlayerController 和 PlayerState 切换为本模块实现。 */
UCLASS(MinimalAPI)
class ANetworkGameMode : public AGenericGameMode
{
	GENERATED_UCLASS_BODY()

public:
	NETWORKAPPLICATION_API virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	NETWORKAPPLICATION_API virtual void PostLogin(APlayerController* NewPlayer) override;
};
