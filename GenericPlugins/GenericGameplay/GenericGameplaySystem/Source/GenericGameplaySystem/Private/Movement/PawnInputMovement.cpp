// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Movement/PawnInputMovement.h"

#include "GameFramework/Pawn.h"

UPawnInputMovement::UPawnInputMovement()
{
}

void UPawnInputMovement::AddLocation_Implementation(FVector2D InValue)
{
	APawn* Pawn = GetOwnerPawn();
	if (!IsValid(Pawn))
	{
		return;
	}

	const FRotator MovementRotation(0.f, GetRotation().Yaw, 0.f);
	const FVector RightDirection = FRotationMatrix(MovementRotation).GetUnitAxis(EAxis::Y);
	const FVector ForwardDirection = FRotationMatrix(MovementRotation).GetUnitAxis(EAxis::X);
	const FVector TargetLocation = GetLocation()
		+ (RightDirection * InValue.X * GetMovementSpeedRate())
		+ (ForwardDirection * InValue.Y * GetMovementSpeedRate());

	if (CanMove(TargetLocation))
	{
		const FVector2D Movement = InValue * GetMovementSpeedRate();
		Pawn->AddMovementInput(RightDirection, Movement.X);
		Pawn->AddMovementInput(ForwardDirection, Movement.Y);
	}
}

void UPawnInputMovement::AddRotation_Implementation(FVector2D InValue)
{
	APawn* Pawn = GetOwnerPawn();
	if (!IsValid(Pawn))
	{
		return;
	}

	const FRotator TargetRotation = GetRotation() + FRotator(InValue.Y * GetRotationSpeedRate(), InValue.X * GetRotationSpeedRate(), 0.f);
	if (CanTurn(TargetRotation))
	{
		const FVector2D Rotation = InValue * GetRotationSpeedRate();
		Pawn->AddControllerYawInput(Rotation.X);
		Pawn->AddControllerPitchInput(Rotation.Y);
	}
}

void UPawnInputMovement::SetLocation_Implementation(FVector InValue)
{
	if (CanMove(InValue))
	{
		if (APawn* Pawn = GetOwnerPawn())
		{
			Pawn->SetActorLocation(InValue);
		}
	}
}

void UPawnInputMovement::SetRotation_Implementation(FRotator InValue)
{
	if (CanTurn(InValue))
	{
		if (APawn* Pawn = GetOwnerPawn())
		{
			Pawn->SetActorRotation(InValue);
		}
	}
}
