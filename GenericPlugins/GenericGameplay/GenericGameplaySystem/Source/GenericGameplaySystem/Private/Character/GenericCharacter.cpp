// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Character/GenericCharacter.h"

#include "Component/PawnInputMovementComponent.h"
#include "GameplayType.h"

AGenericCharacter::AGenericCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	InputMovementComponent = CreateDefaultSubobject<UPawnInputMovementComponent>("InputMovementComponent");
	InputMovementComponent->ActiveInputMovementTag = TAG_GameplayInput_Movement_GenericCharacter;
}

void AGenericCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInput)
{
	Super::SetupPlayerInputComponent(PlayerInput);
}

/* ==================== IPawnInputMovementInterface ==================== */

void AGenericCharacter::ConsumeLocationInput_Implementation(float DeltaSeconds)
{
	IPawnInputMovementInterface::Execute_ConsumeLocationInput(InputMovementComponent, DeltaSeconds);
}

void AGenericCharacter::ConsumeRotationInput_Implementation(float DeltaSeconds)
{
	IPawnInputMovementInterface::Execute_ConsumeRotationInput(InputMovementComponent, DeltaSeconds);
}

float AGenericCharacter::GetAdaptiveMovementSpeed_Implementation()
{
	return IPawnInputMovementInterface::Execute_GetAdaptiveMovementSpeed(InputMovementComponent);
}

float AGenericCharacter::GetAdaptiveRotationSpeed_Implementation()
{
	return IPawnInputMovementInterface::Execute_GetAdaptiveRotationSpeed(InputMovementComponent);
}

void AGenericCharacter::AddLocation_Implementation(const FVector2D InValue)
{
	IPawnInputMovementInterface::Execute_AddLocation(InputMovementComponent, InValue);
}

void AGenericCharacter::AddRotation_Implementation(const FVector2D InValue)
{
	IPawnInputMovementInterface::Execute_AddRotation(InputMovementComponent, InValue);
}

void AGenericCharacter::AddZoom_Implementation(float InValue)
{
	IPawnInputMovementInterface::Execute_AddZoom(InputMovementComponent, InValue);
}

void AGenericCharacter::SetLocation_Implementation(const FVector InValue)
{
	IPawnInputMovementInterface::Execute_SetLocation(InputMovementComponent, InValue);
}

void AGenericCharacter::SetRotation_Implementation(const FRotator InValue)
{
	IPawnInputMovementInterface::Execute_SetRotation(InputMovementComponent, InValue);
}

void AGenericCharacter::SetZoom_Implementation(float InValue)
{
	IPawnInputMovementInterface::Execute_SetZoom(InputMovementComponent, InValue);
}

FVector AGenericCharacter::GetLocation()
{
	return InputMovementComponent->GetLocation();
}

FRotator AGenericCharacter::GetRotation()
{
	return InputMovementComponent->GetRotation();
}

float AGenericCharacter::GetZoom()
{
	return InputMovementComponent->GetZoom();
}

float AGenericCharacter::GetMovementBaseSpeed()
{
	return InputMovementComponent->GetMovementBaseSpeed();
}

float AGenericCharacter::GetMovementSpeedRate()
{
	return InputMovementComponent->GetMovementSpeedRate();
}

float AGenericCharacter::GetRotationSpeedRate()
{
	return InputMovementComponent->GetRotationSpeedRate();
}

float AGenericCharacter::GetZoomSpeedRate()
{
	return InputMovementComponent->GetZoomSpeedRate();
}

FPawnLockState AGenericCharacter::GetPawnLockState()
{
	return InputMovementComponent->GetPawnLockState();
}

bool AGenericCharacter::CanMove(const FVector& TargetLocation) const
{
	return InputMovementComponent->CanMove(TargetLocation);
}

bool AGenericCharacter::CanTurn(const FRotator& TargetRotation) const
{
	return InputMovementComponent->CanTurn(TargetRotation);
}

bool AGenericCharacter::CanZoom(float TargetSpringArmLength) const
{
	return InputMovementComponent->CanZoom(TargetSpringArmLength);
}

FVector AGenericCharacter::GetLimitLocation(const FVector& TargetLocation) const
{
	return InputMovementComponent->GetLimitLocation(TargetLocation);
}

FRotator AGenericCharacter::GetLimitRotation(const FRotator& TargetRotation) const
{
	return InputMovementComponent->GetLimitRotation(TargetRotation);
}

float AGenericCharacter::GetLimitSpringArmLength(float TargetSpringArmLength) const
{
	return InputMovementComponent->GetLimitSpringArmLength(TargetSpringArmLength);
}

void AGenericCharacter::SetPawnLockState_Implementation(const FPawnLockState& InPawnLockState)
{
	IPawnInputMovementInterface::Execute_SetPawnLockState(InputMovementComponent, InPawnLockState);
}

void AGenericCharacter::SetIsFullyLock_Implementation(bool InFullyLock)
{
	IPawnInputMovementInterface::Execute_SetIsFullyLock(InputMovementComponent, InFullyLock);
}

void AGenericCharacter::SetIsLockLocation_Implementation(bool InLockLocation)
{
	IPawnInputMovementInterface::Execute_SetIsLockLocation(InputMovementComponent, InLockLocation);
}

void AGenericCharacter::SetIsLockRotation_Implementation(bool InLockRotation)
{
	IPawnInputMovementInterface::Execute_SetIsLockRotation(InputMovementComponent, InLockRotation);
}

void AGenericCharacter::SetIsLockSpringArm_Implementation(bool InLockSpringArm)
{
	IPawnInputMovementInterface::Execute_SetIsLockSpringArm(InputMovementComponent, InLockSpringArm);
}
