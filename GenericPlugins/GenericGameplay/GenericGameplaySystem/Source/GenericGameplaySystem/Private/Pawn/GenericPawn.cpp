// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Pawn/GenericPawn.h"

#include "Component/PawnInputMovementComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameplayType.h"

AGenericPawn::AGenericPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneComponent;

	InputMovementComponent = CreateDefaultSubobject<UPawnInputMovementComponent>("InputMovementComponent");
	InputMovementComponent->ActiveInputMovementTag = TAG_GameplayInput_Movement_Pawn;
}

/* ==================== IPawnInputMovementInterface ==================== */

void AGenericPawn::ConsumeLocationInput_Implementation(float DeltaSeconds)
{
	IPawnInputMovementInterface::Execute_ConsumeLocationInput(InputMovementComponent, DeltaSeconds);
}

void AGenericPawn::ConsumeRotationInput_Implementation(float DeltaSeconds)
{
	IPawnInputMovementInterface::Execute_ConsumeRotationInput(InputMovementComponent, DeltaSeconds);
}

float AGenericPawn::GetAdaptiveMovementSpeed_Implementation()
{
	return IPawnInputMovementInterface::Execute_GetAdaptiveMovementSpeed(InputMovementComponent);
}

float AGenericPawn::GetAdaptiveRotationSpeed_Implementation()
{
	return IPawnInputMovementInterface::Execute_GetAdaptiveRotationSpeed(InputMovementComponent);
}

void AGenericPawn::AddLocation_Implementation(const FVector2D InValue)
{
	IPawnInputMovementInterface::Execute_AddLocation(InputMovementComponent, InValue);
}

void AGenericPawn::AddRotation_Implementation(const FVector2D InValue)
{
	IPawnInputMovementInterface::Execute_AddRotation(InputMovementComponent, InValue);
}

void AGenericPawn::AddZoom_Implementation(float InValue)
{
	IPawnInputMovementInterface::Execute_AddZoom(InputMovementComponent, InValue);
}

void AGenericPawn::SetLocation_Implementation(const FVector InValue)
{
	IPawnInputMovementInterface::Execute_SetLocation(InputMovementComponent, InValue);
}

void AGenericPawn::SetRotation_Implementation(const FRotator InValue)
{
	IPawnInputMovementInterface::Execute_SetRotation(InputMovementComponent, InValue);
}

void AGenericPawn::SetZoom_Implementation(float InValue)
{
	IPawnInputMovementInterface::Execute_SetZoom(InputMovementComponent, InValue);
}

FVector AGenericPawn::GetLocation()
{
	return InputMovementComponent->GetLocation();
}

FRotator AGenericPawn::GetRotation()
{
	return InputMovementComponent->GetRotation();
}

float AGenericPawn::GetZoom()
{
	return InputMovementComponent->GetZoom();
}

float AGenericPawn::GetMovementBaseSpeed()
{
	return InputMovementComponent->GetMovementBaseSpeed();
}

float AGenericPawn::GetMovementSpeedRate()
{
	return InputMovementComponent->GetMovementSpeedRate();
}

float AGenericPawn::GetRotationSpeedRate()
{
	return InputMovementComponent->GetRotationSpeedRate();
}

float AGenericPawn::GetZoomSpeedRate()
{
	return InputMovementComponent->GetZoomSpeedRate();
}

FPawnLockState AGenericPawn::GetPawnLockState()
{
	return InputMovementComponent->GetPawnLockState();
}

bool AGenericPawn::CanMove(const FVector& TargetLocation) const
{
	return InputMovementComponent->CanMove(TargetLocation);
}

bool AGenericPawn::CanTurn(const FRotator& TargetRotation) const
{
	return InputMovementComponent->CanTurn(TargetRotation);
}

bool AGenericPawn::CanZoom(float TargetSpringArmLength) const
{
	return InputMovementComponent->CanZoom(TargetSpringArmLength);
}

FVector AGenericPawn::GetLimitLocation(const FVector& TargetLocation) const
{
	return InputMovementComponent->GetLimitLocation(TargetLocation);
}

FRotator AGenericPawn::GetLimitRotation(const FRotator& TargetRotation) const
{
	return InputMovementComponent->GetLimitRotation(TargetRotation);
}

float AGenericPawn::GetLimitSpringArmLength(float TargetSpringArmLength) const
{
	return InputMovementComponent->GetLimitSpringArmLength(TargetSpringArmLength);
}

void AGenericPawn::SetPawnLockState_Implementation(const FPawnLockState& InPawnLockState)
{
	IPawnInputMovementInterface::Execute_SetPawnLockState(InputMovementComponent, InPawnLockState);
}

void AGenericPawn::SetIsFullyLock_Implementation(bool InFullyLock)
{
	IPawnInputMovementInterface::Execute_SetIsFullyLock(InputMovementComponent, InFullyLock);
}

void AGenericPawn::SetIsLockLocation_Implementation(bool InLockLocation)
{
	IPawnInputMovementInterface::Execute_SetIsLockLocation(InputMovementComponent, InLockLocation);
}

void AGenericPawn::SetIsLockRotation_Implementation(bool InLockRotation)
{
	IPawnInputMovementInterface::Execute_SetIsLockRotation(InputMovementComponent, InLockRotation);
}

void AGenericPawn::SetIsLockSpringArm_Implementation(bool InLockSpringArm)
{
	IPawnInputMovementInterface::Execute_SetIsLockSpringArm(InputMovementComponent, InLockSpringArm);
}
