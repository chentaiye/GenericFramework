// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerState/GenericPlayerState.h"
#include "NetworkPlayerState.generated.h"

/** 网络玩家状态类型，重写会话注册流程以从 UGenericSessionSubsystem 同步当前会话名。 */
UCLASS(MinimalAPI)
class ANetworkPlayerState : public AGenericPlayerState
{
	GENERATED_BODY()

public:
	NETWORKAPPLICATION_API virtual void BeginPlay() override;
	NETWORKAPPLICATION_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	NETWORKAPPLICATION_API virtual void RegisterPlayerWithSession(bool bWasFromInvite) override;
	NETWORKAPPLICATION_API virtual void UnregisterPlayerWithSession() override;
};
