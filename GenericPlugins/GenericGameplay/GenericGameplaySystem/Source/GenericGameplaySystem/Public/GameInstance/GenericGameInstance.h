// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GenericGameInstance.generated.h"

/** 作为游戏实例能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class UGenericGameInstance : public UGameInstance
{
	GENERATED_BODY()
};
