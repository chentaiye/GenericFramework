// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameSession/GenericGameSession.h"
#include "NetworkGameSession.generated.h"

class USessionSettingViewModel;
class USessionCreateComponent;

/** 网络游戏会话类型，保留给本模块扩展玩家注册和会话名同步等 GameSession 行为。 */
UCLASS(MinimalAPI, Blueprintable)
class ANetworkGameSession : public AGenericGameSession
{
	GENERATED_BODY()

public:
	/** 构造网络会话 Actor，当前沿用父类默认行为并为后续注册逻辑保留扩展点。 */
	NETWORKAPPLICATION_API ANetworkGameSession();
};
