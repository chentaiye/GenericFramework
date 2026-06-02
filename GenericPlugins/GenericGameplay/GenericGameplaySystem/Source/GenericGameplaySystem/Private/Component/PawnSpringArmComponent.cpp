// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Component/PawnSpringArmComponent.h"

#include "Component/PawnInputMovementComponent.h"
#include "Interface/PawnInputMovementInterface.h"
#include "Interface/PawnReassessmentInterface.h"
#include "Movement/GenericInputMovement.h"

UPawnSpringArmComponent::UPawnSpringArmComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	bDoCollisionTest = false;
	bEnableCameraLag = true;
	bEnableCameraRotationLag = true;

	TargetArmLength = 3000.f;
}

void UPawnSpringArmComponent::BeginPlay()
{
	Super::BeginPlay();

	DesiredArmLength = TargetArmLength;
}

void UPawnSpringArmComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateTargetArmLength(DeltaTime);
}

void UPawnSpringArmComponent::AddTargetArmLength(const float InValue)
{
	if (!GetOwner())
	{
		return;
	}

	DesiredArmLength = PreviewTargetArmLength(InValue);

	if (GetOwner()->GetClass()->ImplementsInterface(UPawnInputMovementInterface::StaticClass()))
	{
		/* Gather New Spring Arm Length When Current Spring Arm Length Is Smaller Than ReassessmentFocus */
		if (NeedReassessment() && !bLastReassessmentResult)
		{
			if (UPawnInputMovementComponent* InputMovementComponent = GetOwner()->FindComponentByClass<UPawnInputMovementComponent>())
			{
				if (UGenericInputMovement* ActiveInputMovement = InputMovementComponent->GetActiveInputMovement())
				{
					if (ActiveInputMovement->GetClass()->ImplementsInterface(UPawnReassessmentInterface::StaticClass()))
					{
						bLastReassessmentResult = IPawnReassessmentInterface::Execute_ReassessmentFocus(ActiveInputMovement);
					}
				}
			}
		}
	}

	/* Check If We Can Reassessment */
	if (DesiredArmLength > ReassessmentFocus + ReassessmentFocusRange)
	{
		bLastReassessmentResult = false;
	}
}

void UPawnSpringArmComponent::SetTargetArmLength(const float InValue)
{
	TargetArmLength = DesiredArmLength = InValue;
	UpdateDesiredArmLocation(false, false, false, 0.f);
}

float UPawnSpringArmComponent::GetDesiredArmLength() const
{
	return DesiredArmLength;
}

float UPawnSpringArmComponent::PreviewTargetArmLength(const float InValue) const
{
	float PreviewArmLength = DesiredArmLength + CalculateArmLengthDelta(InValue);

	if (GetOwner() && GetOwner()->GetClass()->ImplementsInterface(UPawnInputMovementInterface::StaticClass()))
	{
		if (IPawnInputMovementInterface* PawnInputMovementInterface = Cast<IPawnInputMovementInterface>(GetOwner()))
		{
			PreviewArmLength = PawnInputMovementInterface->GetLimitSpringArmLength(PreviewArmLength);
		}
	}

	return PreviewArmLength;
}

bool UPawnSpringArmComponent::NeedReassessment() const
{
	return DesiredArmLength < ReassessmentFocus && bEnableReassessmentFocus;
}

float UPawnSpringArmComponent::CalculateArmLengthDelta(const float InValue) const
{
	if (!GetOwner() || FMath::IsNearlyZero(InValue))
	{
		return 0.f;
	}

	float ZoomSpeedRate = 1.f;
	FRotator Rotation = GetRelativeRotation();

	if (GetOwner()->GetClass()->ImplementsInterface(UPawnInputMovementInterface::StaticClass()))
	{
		if (IPawnInputMovementInterface* PawnInputMovementInterface = Cast<IPawnInputMovementInterface>(GetOwner()))
		{
			ZoomSpeedRate = PawnInputMovementInterface->GetZoomSpeedRate();
			Rotation = PawnInputMovementInterface->GetRotation();
		}
	}

	const float SafeMinArmLength = FMath::Min(ZoomArmLengthRange.X, ZoomArmLengthRange.Y);
	const float SafeMaxArmLength = FMath::Max(ZoomArmLengthRange.X + KINDA_SMALL_NUMBER, ZoomArmLengthRange.Y);
	const float ArmLengthAlpha = FMath::Pow(
		FMath::GetMappedRangeValueClamped(FVector2D(SafeMinArmLength, SafeMaxArmLength), FVector2D(0.f, 1.f), FMath::Max(DesiredArmLength, 0.f)),
		ZoomArmLengthExponent
	);
	const float ArmLengthMultiplier = FMath::Lerp(ZoomArmLengthMultiplierRange.X, ZoomArmLengthMultiplierRange.Y, ArmLengthAlpha);
	const float PitchAlpha = FMath::Clamp(FMath::Abs(Rotation.Pitch) / 90.f, 0.f, 1.f);
	const float PitchMultiplier = FMath::Lerp(ZoomPitchMultiplierRange.X, ZoomPitchMultiplierRange.Y, PitchAlpha);
	return InValue * ZoomBaseStep * ZoomSpeedRate * ArmLengthMultiplier * PitchMultiplier;
}

void UPawnSpringArmComponent::UpdateTargetArmLength(float DeltaTime)
{
	TargetArmLength = FMath::FInterpTo(TargetArmLength, DesiredArmLength, DeltaTime, SpringArmLag);
}
