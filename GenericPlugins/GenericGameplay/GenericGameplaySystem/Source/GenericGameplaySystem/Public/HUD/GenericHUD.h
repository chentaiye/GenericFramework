// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GenericHUD.generated.h"

/** 承载HUD职责，衔接上层调用与模块内部实现。 */
UCLASS(MinimalAPI)
class AGenericHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

public:
	GENERICGAMEPLAYSYSTEM_API virtual void DrawHUD() override;
};
