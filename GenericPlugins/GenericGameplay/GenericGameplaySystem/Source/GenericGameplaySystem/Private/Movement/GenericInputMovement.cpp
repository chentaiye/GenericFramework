// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Movement/GenericInputMovement.h"

#include "Component/PawnInputMovementComponent.h"
#include "GameFramework/Pawn.h"

void UGenericInputMovement::InitializeInputMovement(APawn* InOwnerPawn, UPawnInputMovementComponent* InOwnerComponent)
{
	OwnerPawn = InOwnerPawn;
	OwnerComponent = InOwnerComponent;
}

void UGenericInputMovement::DeinitializeInputMovement()
{
	OwnerPawn.Reset();
	OwnerComponent.Reset();
}

void UGenericInputMovement::ConsumeLocationInput_Implementation(float DeltaSeconds)
{
}

void UGenericInputMovement::ConsumeRotationInput_Implementation(float DeltaSeconds)
{
}

float UGenericInputMovement::GetAdaptiveMovementSpeed_Implementation()
{
	return FMath::Max(0.f, GetMovementBaseSpeed() + GetMovementSpeedRate());
}

float UGenericInputMovement::GetAdaptiveRotationSpeed_Implementation()
{
	return FMath::Max(0.f, GetRotationSpeedRate());
}

void UGenericInputMovement::AddLocation_Implementation(FVector2D InValue)
{
}

void UGenericInputMovement::AddRotation_Implementation(FVector2D InValue)
{
}

void UGenericInputMovement::AddZoom_Implementation(float InValue)
{
}

void UGenericInputMovement::SetLocation_Implementation(FVector InValue)
{
	if (CanMove(InValue))
	{
		if (APawn* Pawn = GetOwnerPawn())
		{
			Pawn->SetActorLocation(InValue);
		}
	}
}

void UGenericInputMovement::SetRotation_Implementation(FRotator InValue)
{
	if (CanTurn(InValue))
	{
		if (APawn* Pawn = GetOwnerPawn())
		{
			Pawn->SetActorRotation(InValue);
		}
	}
}

void UGenericInputMovement::SetZoom_Implementation(float InValue)
{
}

FVector UGenericInputMovement::GetLocation()
{
	if (APawn* Pawn = GetOwnerPawn())
	{
		return Pawn->GetActorLocation();
	}

	return FVector::ZeroVector;
}

FRotator UGenericInputMovement::GetRotation()
{
	if (APawn* Pawn = GetOwnerPawn())
	{
		return Pawn->GetActorRotation();
	}

	return FRotator::ZeroRotator;
}

float UGenericInputMovement::GetZoom()
{
	return 0.f;
}

float UGenericInputMovement::GetMovementBaseSpeed()
{
	return MovementBaseSpeed;
}

float UGenericInputMovement::GetMovementSpeedRate()
{
	return MovementSpeedRate;
}

float UGenericInputMovement::GetRotationSpeedRate()
{
	return RotationSpeedRate;
}

float UGenericInputMovement::GetZoomSpeedRate()
{
	return ZoomSpeedRate;
}

FPawnLockState UGenericInputMovement::GetPawnLockState()
{
	return PawnLockState;
}

bool UGenericInputMovement::CanMove(const FVector& TargetLocation) const
{
	if (PawnLockState.bFullyLock || PawnLockState.bLockLocation)
	{
		return false;
	}

	return PawnLockState.PawnLocationLimit.CanMove(TargetLocation);
}

bool UGenericInputMovement::CanTurn(const FRotator& TargetRotation) const
{
	if (PawnLockState.bFullyLock || PawnLockState.bLockRotation)
	{
		return false;
	}

	return PawnLockState.PawnRotationLimit.CanTurn(TargetRotation);
}

bool UGenericInputMovement::CanZoom(float TargetSpringArmLength) const
{
	if (PawnLockState.bFullyLock || PawnLockState.bLockSpringArm)
	{
		return false;
	}

	return PawnLockState.SpringArmLimit.CanZoom(TargetSpringArmLength);
}

FVector UGenericInputMovement::GetLimitLocation(const FVector& TargetLocation) const
{
	const FPawnLocationLimit PawnLocationLimit = PawnLockState.PawnLocationLimit;
	FVector Result = TargetLocation;

	if (PawnLocationLimit.bLimitLocationX)
	{
		Result.X = FMath::Clamp(Result.X, PawnLocationLimit.LocationXRange.X, PawnLocationLimit.LocationXRange.Y);
	}

	if (PawnLocationLimit.bLimitLocationY)
	{
		Result.Y = FMath::Clamp(Result.Y, PawnLocationLimit.LocationYRange.X, PawnLocationLimit.LocationYRange.Y);
	}

	if (PawnLocationLimit.bLimitLocationZ)
	{
		Result.Z = FMath::Clamp(Result.Z, PawnLocationLimit.LocationZRange.X, PawnLocationLimit.LocationZRange.Y);
	}

	return Result;
}

FRotator UGenericInputMovement::GetLimitRotation(const FRotator& TargetRotation) const
{
	const FPawnRotationLimit PawnRotationLimit = PawnLockState.PawnRotationLimit;
	FRotator Result = TargetRotation;

	if (PawnRotationLimit.bLimitPitch)
	{
		Result.Pitch = FMath::Clamp(Result.Pitch, PawnRotationLimit.PitchRange.X, PawnRotationLimit.PitchRange.Y);
	}

	if (PawnRotationLimit.bLimitYaw)
	{
		Result.Yaw = FMath::Clamp(Result.Yaw, PawnRotationLimit.YawRange.X, PawnRotationLimit.YawRange.Y);
	}

	if (PawnRotationLimit.bLimitRoll)
	{
		Result.Roll = FMath::Clamp(Result.Roll, PawnRotationLimit.RollRange.X, PawnRotationLimit.RollRange.Y);
	}

	return Result;
}

float UGenericInputMovement::GetLimitSpringArmLength(float TargetSpringArmLength) const
{
	const FSpringArmLimit SpringArmLimit = PawnLockState.SpringArmLimit;

	if (SpringArmLimit.bLimitSpringArmLength)
	{
		return FMath::Clamp(TargetSpringArmLength, SpringArmLimit.SpringArmLengthRange.X, SpringArmLimit.SpringArmLengthRange.Y);
	}

	return TargetSpringArmLength;
}

void UGenericInputMovement::SetPawnLockState_Implementation(const FPawnLockState& InPawnLockState)
{
	PawnLockState = InPawnLockState;
}

void UGenericInputMovement::SetIsFullyLock_Implementation(bool InFullyLock)
{
	PawnLockState.bFullyLock = InFullyLock;
}

void UGenericInputMovement::SetIsLockLocation_Implementation(bool InLockLocation)
{
	PawnLockState.bLockLocation = InLockLocation;
}

void UGenericInputMovement::SetIsLockRotation_Implementation(bool InLockRotation)
{
	PawnLockState.bLockRotation = InLockRotation;
}

void UGenericInputMovement::SetIsLockSpringArm_Implementation(bool InLockSpringArm)
{
	PawnLockState.bLockSpringArm = InLockSpringArm;
}

APawn* UGenericInputMovement::GetOwnerPawn() const
{
	return OwnerPawn.Get();
}

UPawnInputMovementComponent* UGenericInputMovement::GetOwnerInputMovementComponent() const
{
	return OwnerComponent.Get();
}
