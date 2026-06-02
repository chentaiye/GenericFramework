// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Movement/SmartCityPawnInputMovement.h"

#include "BPFunctions/BPFunctions_Gameplay.h"
#include "Camera/CameraComponent.h"
#include "Component/PawnReassessmentComponent.h"
#include "Component/PawnSpringArmComponent.h"
#include "Interface/PawnInputMovementInterface.h"
#include "Pawn/ThirdPersonPawn.h"

USmartCityPawnInputMovement::USmartCityPawnInputMovement()
{
}

bool USmartCityPawnInputMovement::ReassessmentFocus_Implementation()
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	if (!IsValid(ThirdPersonPawn))
	{
		return false;
	}

	UPawnSpringArmComponent* SpringArmComponent = ThirdPersonPawn->SpringArmComponent;
	if (!IsValid(SpringArmComponent))
	{
		return false;
	}

	UPawnReassessmentComponent* ReassessmentComponent = ThirdPersonPawn->ReassessmentComponent;
	if (!IsValid(ReassessmentComponent))
	{
		return false;
	}

	UCameraComponent* CameraComponent = ThirdPersonPawn->CameraComponent;
	if (!IsValid(CameraComponent))
	{
		return false;
	}

	const bool bPreviousCollisionState = SpringArmComponent->bDoCollisionTest;
	SpringArmComponent->bDoCollisionTest = false;

	FHitResult HitResult;
	const bool bHasHit = UBPFunctions_Gameplay::GetComponentForwardHitResult(CameraComponent, HitResult, ReassessmentComponent->ReassessmentSettings.TraceChannel);
	SpringArmComponent->bDoCollisionTest = bPreviousCollisionState;

	if (!bHasHit)
	{
		return false;
	}

	if (bPreviousCollisionState)
	{
		const float SafeDistance = FMath::Max(ReassessmentComponent->ReassessmentSettings.MinDistance, HitResult.Distance - ReassessmentComponent->ReassessmentSettings.FocusPadding);
		IPawnInputMovementInterface::Execute_SetLocation(this, CameraComponent->GetComponentLocation() + (CameraComponent->GetForwardVector() * SafeDistance));
		IPawnInputMovementInterface::Execute_SetZoom(this, SafeDistance);
	}
	else
	{
		IPawnInputMovementInterface::Execute_SetLocation(this, HitResult.Location);
		IPawnInputMovementInterface::Execute_SetZoom(this, FMath::Max(ReassessmentComponent->ReassessmentSettings.MinDistance, HitResult.Distance));
	}

	return true;
}
