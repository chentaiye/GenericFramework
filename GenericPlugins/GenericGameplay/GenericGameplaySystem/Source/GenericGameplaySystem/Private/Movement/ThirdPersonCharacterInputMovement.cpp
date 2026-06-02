// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Movement/ThirdPersonCharacterInputMovement.h"

#include "Character/ThirdPersonCharacter.h"
#include "Component/PawnSpringArmComponent.h"

UThirdPersonCharacterInputMovement::UThirdPersonCharacterInputMovement()
{
}

void UThirdPersonCharacterInputMovement::AddZoom_Implementation(float InValue)
{
	AThirdPersonCharacter* ThirdPersonCharacter = GetThirdPersonCharacter();
	if (!IsValid(ThirdPersonCharacter) || !IsValid(ThirdPersonCharacter->SpringArmComponent))
	{
		return;
	}

	const float TargetZoom = GetZoom() + InValue * GetZoomSpeedRate();
	if (CanZoom(TargetZoom))
	{
		ThirdPersonCharacter->SpringArmComponent->AddTargetArmLength(InValue * GetZoomSpeedRate());
	}
}

void UThirdPersonCharacterInputMovement::SetLocation_Implementation(FVector InValue)
{
	if (CanMove(InValue))
	{
		if (AThirdPersonCharacter* ThirdPersonCharacter = GetThirdPersonCharacter())
		{
			ThirdPersonCharacter->SetActorLocation(InValue);
		}
	}
}

void UThirdPersonCharacterInputMovement::SetRotation_Implementation(FRotator InValue)
{
	AThirdPersonCharacter* ThirdPersonCharacter = GetThirdPersonCharacter();
	if (CanTurn(InValue) && IsValid(ThirdPersonCharacter) && IsValid(ThirdPersonCharacter->SpringArmComponent))
	{
		ThirdPersonCharacter->SetActorRotation(FRotator(0.f, InValue.Yaw, 0.f));
		ThirdPersonCharacter->SpringArmComponent->SetRelativeRotation(FRotator(InValue.Pitch, 0.f, 0.f), true);
	}
}

void UThirdPersonCharacterInputMovement::SetZoom_Implementation(float InValue)
{
	AThirdPersonCharacter* ThirdPersonCharacter = GetThirdPersonCharacter();
	if (CanZoom(InValue) && IsValid(ThirdPersonCharacter) && IsValid(ThirdPersonCharacter->SpringArmComponent))
	{
		ThirdPersonCharacter->SpringArmComponent->SetTargetArmLength(InValue);
	}
}

FVector UThirdPersonCharacterInputMovement::GetLocation()
{
	if (AThirdPersonCharacter* ThirdPersonCharacter = GetThirdPersonCharacter())
	{
		return ThirdPersonCharacter->GetActorLocation();
	}

	return FVector::ZeroVector;
}

FRotator UThirdPersonCharacterInputMovement::GetRotation()
{
	if (AThirdPersonCharacter* ThirdPersonCharacter = GetThirdPersonCharacter())
	{
		return ThirdPersonCharacter->GetControlRotation();
	}

	return FRotator::ZeroRotator;
}

float UThirdPersonCharacterInputMovement::GetZoom()
{
	AThirdPersonCharacter* ThirdPersonCharacter = GetThirdPersonCharacter();
	if (IsValid(ThirdPersonCharacter) && IsValid(ThirdPersonCharacter->SpringArmComponent))
	{
		return ThirdPersonCharacter->SpringArmComponent->TargetArmLength;
	}

	return 0.f;
}

AThirdPersonCharacter* UThirdPersonCharacterInputMovement::GetThirdPersonCharacter() const
{
	return Cast<AThirdPersonCharacter>(GetOwnerPawn());
}
