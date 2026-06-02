// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Movement/ThirdPersonPawnInputMovement.h"

#include "Component/PawnSpringArmComponent.h"
#include "Pawn/ThirdPersonPawn.h"

namespace
{
	FVector2D InterpVector2D(const FVector2D& Current, const FVector2D& Target, const float DeltaSeconds, const float InterpSpeed)
	{
		if (InterpSpeed <= 0.f)
		{
			return Target;
		}

		return FVector2D(
			FMath::FInterpTo(Current.X, Target.X, DeltaSeconds, InterpSpeed),
			FMath::FInterpTo(Current.Y, Target.Y, DeltaSeconds, InterpSpeed)
		);
	}
}

UThirdPersonPawnInputMovement::UThirdPersonPawnInputMovement()
{
	MovementAdaptiveRate.ArmLengthMultiplierRange = FVector2D(1.f, 2.4f);
	MovementAdaptiveRate.PitchMultiplierRange = FVector2D(1.f, 1.1f);

	RotationAdaptiveRate.ArmLengthMultiplierRange = FVector2D(0.85f, 1.3f);
	RotationAdaptiveRate.PitchMultiplierRange = FVector2D(0.95f, 1.05f);
}

void UThirdPersonPawnInputMovement::ConsumeLocationInput_Implementation(float DeltaSeconds)
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	if (!IsValid(ThirdPersonPawn) || !IsValid(ThirdPersonPawn->SpringArmComponent))
	{
		PendingLocationInput = FVector2D::ZeroVector;
		return;
	}

	SmoothedLocationInput = InterpVector2D(SmoothedLocationInput, PendingLocationInput, DeltaSeconds, InputSmoothing.MovementInterpSpeed);
	PendingLocationInput = FVector2D::ZeroVector;
	if (SmoothedLocationInput.IsNearlyZero(InputSmoothing.InputDeadZone))
	{
		SmoothedLocationInput = FVector2D::ZeroVector;
		return;
	}

	const float FrameScale = DeltaSeconds * FMath::Max(1.f, InputSmoothing.ReferenceFrameRate);
	const float MovementSpeed = IPawnInputMovementInterface::Execute_GetAdaptiveMovementSpeed(this);
	const FVector TargetLocation = GetLocation()
		+ (ThirdPersonPawn->GetActorRightVector() * SmoothedLocationInput.X * MovementSpeed * FrameScale)
		+ (ThirdPersonPawn->GetActorForwardVector() * SmoothedLocationInput.Y * MovementSpeed * FrameScale);

	IPawnInputMovementInterface::Execute_SetLocation(this, TargetLocation);
}

void UThirdPersonPawnInputMovement::ConsumeRotationInput_Implementation(float DeltaSeconds)
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	if (!IsValid(ThirdPersonPawn) || !IsValid(ThirdPersonPawn->SpringArmComponent))
	{
		PendingRotationInput = FVector2D::ZeroVector;
		return;
	}

	SmoothedRotationInput = InterpVector2D(SmoothedRotationInput, PendingRotationInput, DeltaSeconds, InputSmoothing.RotationInterpSpeed);
	PendingRotationInput = FVector2D::ZeroVector;
	if (SmoothedRotationInput.IsNearlyZero(InputSmoothing.InputDeadZone))
	{
		SmoothedRotationInput = FVector2D::ZeroVector;
		return;
	}

	const float FrameScale = DeltaSeconds * FMath::Max(1.f, InputSmoothing.ReferenceFrameRate);
	const float RotationSpeed = IPawnInputMovementInterface::Execute_GetAdaptiveRotationSpeed(this);
	const FRotator TargetRotation = GetRotation() + FRotator(
		SmoothedRotationInput.Y * RotationSpeed * FrameScale,
		SmoothedRotationInput.X * RotationSpeed * FrameScale,
		0.f
	);
	IPawnInputMovementInterface::Execute_SetRotation(this, TargetRotation);
}

float UThirdPersonPawnInputMovement::GetAdaptiveMovementSpeed_Implementation()
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	const float ArmLength = IsValid(ThirdPersonPawn) && IsValid(ThirdPersonPawn->SpringArmComponent) ? ThirdPersonPawn->SpringArmComponent->GetDesiredArmLength() : 0.f;
	const float Pitch = IsValid(ThirdPersonPawn) && IsValid(ThirdPersonPawn->SpringArmComponent) ? ThirdPersonPawn->SpringArmComponent->GetRelativeRotation().Pitch : 0.f;
	const float BaseSpeed = FMath::Max(0.f, GetMovementBaseSpeed() + GetMovementSpeedRate());
	return BaseSpeed * MovementAdaptiveRate.Evaluate(ArmLength, Pitch);
}

float UThirdPersonPawnInputMovement::GetAdaptiveRotationSpeed_Implementation()
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	const float ArmLength = IsValid(ThirdPersonPawn) && IsValid(ThirdPersonPawn->SpringArmComponent) ? ThirdPersonPawn->SpringArmComponent->GetDesiredArmLength() : 0.f;
	const float Pitch = IsValid(ThirdPersonPawn) && IsValid(ThirdPersonPawn->SpringArmComponent) ? ThirdPersonPawn->SpringArmComponent->GetRelativeRotation().Pitch : 0.f;
	return FMath::Max(0.f, GetRotationSpeedRate()) * RotationAdaptiveRate.Evaluate(ArmLength, Pitch);
}

void UThirdPersonPawnInputMovement::AddLocation_Implementation(FVector2D InValue)
{
	PendingLocationInput += InValue;
	if (PendingLocationInput.SizeSquared() > 1.f)
	{
		PendingLocationInput.Normalize();
	}
}

void UThirdPersonPawnInputMovement::AddRotation_Implementation(FVector2D InValue)
{
	PendingRotationInput += InValue;
}

void UThirdPersonPawnInputMovement::AddZoom_Implementation(float InValue)
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	if (!IsValid(ThirdPersonPawn) || !IsValid(ThirdPersonPawn->SpringArmComponent))
	{
		return;
	}

	const float TargetZoom = ThirdPersonPawn->SpringArmComponent->PreviewTargetArmLength(InValue);
	if (CanZoom(TargetZoom))
	{
		ThirdPersonPawn->SpringArmComponent->AddTargetArmLength(InValue);
	}
}

void UThirdPersonPawnInputMovement::SetLocation_Implementation(FVector InValue)
{
	if (CanMove(InValue))
	{
		if (AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn())
		{
			ThirdPersonPawn->SetActorLocation(InValue);
		}
	}
}

void UThirdPersonPawnInputMovement::SetRotation_Implementation(FRotator InValue)
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	if (CanTurn(InValue) && IsValid(ThirdPersonPawn) && IsValid(ThirdPersonPawn->SpringArmComponent))
	{
		ThirdPersonPawn->SetActorRotation(FRotator(0.f, InValue.Yaw, 0.f));
		ThirdPersonPawn->SpringArmComponent->SetRelativeRotation(FRotator(InValue.Pitch, 0.f, 0.f), true);
	}
}

void UThirdPersonPawnInputMovement::SetZoom_Implementation(float InValue)
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	if (CanZoom(InValue) && IsValid(ThirdPersonPawn) && IsValid(ThirdPersonPawn->SpringArmComponent))
	{
		ThirdPersonPawn->SpringArmComponent->SetTargetArmLength(InValue);
	}
}

FVector UThirdPersonPawnInputMovement::GetLocation()
{
	if (AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn())
	{
		return ThirdPersonPawn->GetActorLocation();
	}

	return FVector::ZeroVector;
}

FRotator UThirdPersonPawnInputMovement::GetRotation()
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	if (IsValid(ThirdPersonPawn) && IsValid(ThirdPersonPawn->SpringArmComponent))
	{
		return FRotator(ThirdPersonPawn->SpringArmComponent->GetRelativeRotation().Pitch, ThirdPersonPawn->GetActorRotation().Yaw, 0.f);
	}

	return Super::GetRotation();
}

float UThirdPersonPawnInputMovement::GetZoom()
{
	AThirdPersonPawn* ThirdPersonPawn = GetThirdPersonPawn();
	if (IsValid(ThirdPersonPawn) && IsValid(ThirdPersonPawn->SpringArmComponent))
	{
		return ThirdPersonPawn->SpringArmComponent->TargetArmLength;
	}

	return 0.f;
}

AThirdPersonPawn* UThirdPersonPawnInputMovement::GetThirdPersonPawn() const
{
	return Cast<AThirdPersonPawn>(GetOwnerPawn());
}
