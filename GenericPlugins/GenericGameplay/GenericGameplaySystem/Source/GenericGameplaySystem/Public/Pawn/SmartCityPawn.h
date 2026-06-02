// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ThirdPersonPawn.h"
#include "SmartCityPawn.generated.h"

UCLASS(MinimalAPI)
class ASmartCityPawn : public AThirdPersonPawn
{
	GENERATED_BODY()

public:
	GENERICGAMEPLAYSYSTEM_API ASmartCityPawn(const FObjectInitializer& ObjectInitializer);
};
