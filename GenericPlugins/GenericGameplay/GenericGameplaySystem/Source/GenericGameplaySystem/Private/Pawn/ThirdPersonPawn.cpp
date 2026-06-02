// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Pawn/ThirdPersonPawn.h"

#include "Camera/CameraComponent.h"
#include "CameraPoint/CameraPointBase.h"
#include "Component/PawnInputMovementComponent.h"
#include "Component/PawnReassessmentComponent.h"
#include "Component/PawnSpringArmComponent.h"
#include "GameplayType.h"

AThirdPersonPawn::AThirdPersonPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SpringArmComponent = CreateDefaultSubobject<UPawnSpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	ReassessmentComponent = CreateDefaultSubobject<UPawnReassessmentComponent>("ReassessmentComponent");

	if (InputMovementComponent)
	{
		InputMovementComponent->ActiveInputMovementTag = TAG_GameplayInput_Movement_ThirdPersonPawn;
	}
}

void AThirdPersonPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AThirdPersonPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AThirdPersonPawn::CalcCamera(float DeltaTime, FMinimalViewInfo& OutResult)
{
	Super::CalcCamera(DeltaTime, OutResult);
}
