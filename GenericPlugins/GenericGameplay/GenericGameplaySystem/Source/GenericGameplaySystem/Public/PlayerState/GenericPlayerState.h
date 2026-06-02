// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "GenericPlayerState.generated.h"

/** 作为玩家状态能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class AGenericPlayerState : public APlayerState
{
	GENERATED_BODY()
};
