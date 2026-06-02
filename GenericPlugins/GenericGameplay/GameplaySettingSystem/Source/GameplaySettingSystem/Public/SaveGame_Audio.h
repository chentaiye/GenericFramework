// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericSaveGame.h"
#include "SaveGame_Audio.generated.h"

/** 作为存档系统保存游戏音频能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class USaveGame_Audio : public UGenericSaveGame
{
	GENERATED_BODY()

public:
	/** 记录音频Quality关卡。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Audio")
	int32 AudioQualityLevel=0;
};
