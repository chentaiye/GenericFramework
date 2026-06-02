// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Character/ThirdPersonCharacter.h"

#include "Camera/CameraComponent.h"
#include "Component/PawnInputMovementComponent.h"
#include "Component/PawnSpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayType.h"

AThirdPersonCharacter::AThirdPersonCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<UPawnSpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->bDoCollisionTest = true;
	SpringArmComponent->TargetArmLength = 300.f;
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bEnableReassessmentFocus = false;
	SpringArmComponent->SetRelativeLocation(FVector(0.f, 0.f, GetCapsuleComponent()->GetScaledCapsuleHalfHeight() - 10.f));

	CameraComponent->FieldOfView = 85.f;

	if (USkeletalMeshComponent* MeshComponent = GetMesh())
	{
		MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
		MeshComponent->SetRelativeRotation(FRotator(0.f, 270.f, 0.f));
	}

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	if (InputMovementComponent)
	{
		InputMovementComponent->ActiveInputMovementTag = TAG_GameplayInput_Movement_ThirdPersonCharacter;
	}
}

void AThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AThirdPersonCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
