// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericSaveGame.h"
#include "SaveGame_Controller.generated.h"

/** 作为存档系统保存游戏Controller能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class USaveGame_Controller : public UGenericSaveGame
{
	GENERATED_BODY()
};
