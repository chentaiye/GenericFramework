// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Component/PawnInputMovementComponent.h"

#include "GameFramework/Pawn.h"
#include "GameplayType.h"
#include "Movement/CharacterInputMovement.h"
#include "Movement/GenericInputMovement.h"
#include "Movement/PawnInputMovement.h"
#include "Movement/SmartCityPawnInputMovement.h"
#include "Movement/ThirdPersonCharacterInputMovement.h"
#include "Movement/ThirdPersonPawnInputMovement.h"

UPawnInputMovementComponent::UPawnInputMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	ActiveInputMovementTag = TAG_GameplayInput_Movement;
	InputMovementClasses.Add(TAG_GameplayInput_Movement, UGenericInputMovement::StaticClass());
	InputMovementClasses.Add(TAG_GameplayInput_Movement_Pawn, UPawnInputMovement::StaticClass());
	InputMovementClasses.Add(TAG_GameplayInput_Movement_ThirdPersonPawn, UThirdPersonPawnInputMovement::StaticClass());
	InputMovementClasses.Add(TAG_GameplayInput_Movement_SmartCityPawn, USmartCityPawnInputMovement::StaticClass());
	InputMovementClasses.Add(TAG_GameplayInput_Movement_GenericCharacter, UCharacterInputMovement::StaticClass());
	InputMovementClasses.Add(TAG_GameplayInput_Movement_ThirdPersonCharacter, UThirdPersonCharacterInputMovement::StaticClass());
}

void UPawnInputMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	GetActiveInputMovement();
}

void UPawnInputMovementComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	FGameplayTag ResolvedTag;
	ResolveInputMovementClass(ResolvedTag);
	if (const TObjectPtr<UGenericInputMovement>* ActiveInputMovement = InputMovementInstances.Find(ResolvedTag))
	{
		if (IsValid(*ActiveInputMovement))
		{
			(*ActiveInputMovement)->DeinitializeInputMovement();
		}
	}

	InputMovementInstances.Reset();

	Super::EndPlay(EndPlayReason);
}

void UPawnInputMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	IPawnInputMovementInterface::Execute_ConsumeLocationInput(this, DeltaTime);
	IPawnInputMovementInterface::Execute_ConsumeRotationInput(this, DeltaTime);
}

void UPawnInputMovementComponent::ConsumeLocationInput_Implementation(float DeltaSeconds)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_ConsumeLocationInput(Movement, DeltaSeconds);
	}
}

void UPawnInputMovementComponent::ConsumeRotationInput_Implementation(float DeltaSeconds)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_ConsumeRotationInput(Movement, DeltaSeconds);
	}
}

float UPawnInputMovementComponent::GetAdaptiveMovementSpeed_Implementation()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return IPawnInputMovementInterface::Execute_GetAdaptiveMovementSpeed(Movement);
	}

	return 0.f;
}

float UPawnInputMovementComponent::GetAdaptiveRotationSpeed_Implementation()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return IPawnInputMovementInterface::Execute_GetAdaptiveRotationSpeed(Movement);
	}

	return 0.f;
}

void UPawnInputMovementComponent::AddLocation_Implementation(FVector2D InValue)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_AddLocation(Movement, InValue);
	}
}

void UPawnInputMovementComponent::AddRotation_Implementation(FVector2D InValue)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_AddRotation(Movement, InValue);
	}
}

void UPawnInputMovementComponent::AddZoom_Implementation(float InValue)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_AddZoom(Movement, InValue);
	}
}

void UPawnInputMovementComponent::SetLocation_Implementation(FVector InValue)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_SetLocation(Movement, InValue);
	}
}

void UPawnInputMovementComponent::SetRotation_Implementation(FRotator InValue)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_SetRotation(Movement, InValue);
	}
}

void UPawnInputMovementComponent::SetZoom_Implementation(float InValue)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_SetZoom(Movement, InValue);
	}
}

FVector UPawnInputMovementComponent::GetLocation()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return Movement->GetLocation();
	}

	return IsValid(GetOwner()) ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
}

FRotator UPawnInputMovementComponent::GetRotation()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return Movement->GetRotation();
	}

	return IsValid(GetOwner()) ? GetOwner()->GetActorRotation() : FRotator::ZeroRotator;
}

float UPawnInputMovementComponent::GetZoom()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return Movement->GetZoom();
	}

	return 0.f;
}

float UPawnInputMovementComponent::GetMovementBaseSpeed()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return Movement->GetMovementBaseSpeed();
	}

	return 0.f;
}

float UPawnInputMovementComponent::GetMovementSpeedRate()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return Movement->GetMovementSpeedRate();
	}

	return 0.f;
}

float UPawnInputMovementComponent::GetRotationSpeedRate()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return Movement->GetRotationSpeedRate();
	}

	return 0.f;
}

float UPawnInputMovementComponent::GetZoomSpeedRate()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return Movement->GetZoomSpeedRate();
	}

	return 0.f;
}

FPawnLockState UPawnInputMovementComponent::GetPawnLockState()
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		return Movement->GetPawnLockState();
	}

	return FPawnLockState();
}

bool UPawnInputMovementComponent::CanMove(const FVector& TargetLocation) const
{
	if (const UGenericInputMovement* Movement = const_cast<UPawnInputMovementComponent*>(this)->GetActiveInputMovement())
	{
		return Movement->CanMove(TargetLocation);
	}

	return true;
}

bool UPawnInputMovementComponent::CanTurn(const FRotator& TargetRotation) const
{
	if (const UGenericInputMovement* Movement = const_cast<UPawnInputMovementComponent*>(this)->GetActiveInputMovement())
	{
		return Movement->CanTurn(TargetRotation);
	}

	return true;
}

bool UPawnInputMovementComponent::CanZoom(float TargetSpringArmLength) const
{
	if (const UGenericInputMovement* Movement = const_cast<UPawnInputMovementComponent*>(this)->GetActiveInputMovement())
	{
		return Movement->CanZoom(TargetSpringArmLength);
	}

	return true;
}

FVector UPawnInputMovementComponent::GetLimitLocation(const FVector& TargetLocation) const
{
	if (const UGenericInputMovement* Movement = const_cast<UPawnInputMovementComponent*>(this)->GetActiveInputMovement())
	{
		return Movement->GetLimitLocation(TargetLocation);
	}

	return TargetLocation;
}

FRotator UPawnInputMovementComponent::GetLimitRotation(const FRotator& TargetRotation) const
{
	if (const UGenericInputMovement* Movement = const_cast<UPawnInputMovementComponent*>(this)->GetActiveInputMovement())
	{
		return Movement->GetLimitRotation(TargetRotation);
	}

	return TargetRotation;
}

float UPawnInputMovementComponent::GetLimitSpringArmLength(float TargetSpringArmLength) const
{
	if (const UGenericInputMovement* Movement = const_cast<UPawnInputMovementComponent*>(this)->GetActiveInputMovement())
	{
		return Movement->GetLimitSpringArmLength(TargetSpringArmLength);
	}

	return TargetSpringArmLength;
}

void UPawnInputMovementComponent::SetPawnLockState_Implementation(const FPawnLockState& InPawnLockState)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_SetPawnLockState(Movement, InPawnLockState);
	}
}

void UPawnInputMovementComponent::SetIsFullyLock_Implementation(bool InFullyLock)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_SetIsFullyLock(Movement, InFullyLock);
	}
}

void UPawnInputMovementComponent::SetIsLockLocation_Implementation(bool InLockLocation)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_SetIsLockLocation(Movement, InLockLocation);
	}
}

void UPawnInputMovementComponent::SetIsLockRotation_Implementation(bool InLockRotation)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_SetIsLockRotation(Movement, InLockRotation);
	}
}

void UPawnInputMovementComponent::SetIsLockSpringArm_Implementation(bool InLockSpringArm)
{
	if (UGenericInputMovement* Movement = GetActiveInputMovement())
	{
		IPawnInputMovementInterface::Execute_SetIsLockSpringArm(Movement, InLockSpringArm);
	}
}

UGenericInputMovement* UPawnInputMovementComponent::GetActiveInputMovement()
{
	FGameplayTag ResolvedTag;
	const TSubclassOf<UGenericInputMovement> MovementClass = ResolveInputMovementClass(ResolvedTag);
	if (!MovementClass)
	{
		return nullptr;
	}

	TObjectPtr<UGenericInputMovement>& Movement = InputMovementInstances.FindOrAdd(ResolvedTag);
	if (!IsValid(Movement) || Movement->GetClass() != MovementClass)
	{
		if (IsValid(Movement))
		{
			Movement->DeinitializeInputMovement();
		}

		Movement = NewObject<UGenericInputMovement>(this, MovementClass);
		Movement->InitializeInputMovement(Cast<APawn>(GetOwner()), this);
	}

	return Movement;
}

TSubclassOf<UGenericInputMovement> UPawnInputMovementComponent::ResolveInputMovementClass(FGameplayTag& OutResolvedTag) const
{
	if (ActiveInputMovementTag.IsValid())
	{
		if (const TSubclassOf<UGenericInputMovement>* MovementClass = InputMovementClasses.Find(ActiveInputMovementTag))
		{
			if (*MovementClass)
			{
				OutResolvedTag = ActiveInputMovementTag;
				return *MovementClass;
			}
		}
	}

	if (const TSubclassOf<UGenericInputMovement>* MovementClass = InputMovementClasses.Find(TAG_GameplayInput_Movement))
	{
		if (*MovementClass)
		{
			OutResolvedTag = TAG_GameplayInput_Movement;
			return *MovementClass;
		}
	}

	OutResolvedTag = TAG_GameplayInput_Movement;
	return UGenericInputMovement::StaticClass();
}
