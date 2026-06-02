// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Pawn/SmartCityPawn.h"

#include "Component/PawnInputMovementComponent.h"
#include "GameplayType.h"
#include "PlayerInputIdleActionComponent.h"

ASmartCityPawn::ASmartCityPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	if (InputMovementComponent)
	{
		InputMovementComponent->ActiveInputMovementTag = TAG_GameplayInput_Movement_SmartCityPawn;
	}
}
