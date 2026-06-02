// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GenericGameMode.generated.h"

class IPlayerIdentityInterface;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnPlayerLogin, APlayerController*);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnPlayerLogout, APlayerController*);

/** 承载游戏模式职责，衔接上层调用与模块内部实现。 */
UCLASS(MinimalAPI)
class AGenericGameMode : public AGameModeBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICGAMEPLAYSYSTEM_API virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	GENERICGAMEPLAYSYSTEM_API virtual void Logout(AController* Exiting) override;

public:
	/** 获取Players。 */
	GENERICGAMEPLAYSYSTEM_API TArray<APlayerController*> GetPlayers() { return Players; }

	/** 获取On玩家Login。 */
	static GENERICGAMEPLAYSYSTEM_API FOnPlayerLogin& GetOnPlayerLogin() { return OnPlayerLoginEvent; }

	/** 获取On玩家Logout。 */
	static GENERICGAMEPLAYSYSTEM_API FOnPlayerLogout& GetOnPlayerLogout() { return OnPlayerLogoutEvent; }

private:
	/** 持有Players实例，供当前模块运行时复用。 */
	UPROPERTY(Transient)
	TArray<TObjectPtr<APlayerController>> Players;

	/** 在玩家Login事件时广播给蓝图或上层监听者。 */
	inline static FOnPlayerLogin OnPlayerLoginEvent;

	/** 在玩家Logout事件时广播给蓝图或上层监听者。 */
	inline static FOnPlayerLogout OnPlayerLogoutEvent;
};
