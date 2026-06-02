// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericSaveGame.h"
#include "SaveGame_Game.generated.h"

/** 作为存档系统保存游戏游戏能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class USaveGame_Game : public UGenericSaveGame
{
	GENERATED_BODY()

public:
	/** 记录当前Culture。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Game")
	FString CurrentCulture;

	/** 标记SubtitlesEnabled状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Game")
	bool bSubtitlesEnabled=false;

	/** 记录ApplicationScale。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Game")
	float ApplicationScale=1.0f;
};
