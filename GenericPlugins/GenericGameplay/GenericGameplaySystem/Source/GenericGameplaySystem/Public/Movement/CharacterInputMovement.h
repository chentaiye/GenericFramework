// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Movement/PawnInputMovement.h"
#include "CharacterInputMovement.generated.h"

/** 为 Character 提供独立标签入口的输入移动策略。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UCharacterInputMovement : public UPawnInputMovement
{
	GENERATED_BODY()

public:
	/** 初始化 Character 输入移动策略的默认对象状态。 */
	GENERICGAMEPLAYSYSTEM_API UCharacterInputMovement();
};
