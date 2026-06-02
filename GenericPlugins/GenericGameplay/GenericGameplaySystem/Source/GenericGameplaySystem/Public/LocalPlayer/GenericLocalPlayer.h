// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LocalPlayer.h"
#include "GenericLocalPlayer.generated.h"

/** 承载本地玩家职责，衔接上层调用与模块内部实现。 */
UCLASS(MinimalAPI)
class UGenericLocalPlayer : public ULocalPlayer
{
	GENERATED_BODY()
};
