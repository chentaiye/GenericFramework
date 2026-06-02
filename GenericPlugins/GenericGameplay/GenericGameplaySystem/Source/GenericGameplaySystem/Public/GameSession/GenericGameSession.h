// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "GenericGameSession.generated.h"

/** 作为游戏会话能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class AGenericGameSession : public AGameSession
{
	GENERATED_BODY()
};
