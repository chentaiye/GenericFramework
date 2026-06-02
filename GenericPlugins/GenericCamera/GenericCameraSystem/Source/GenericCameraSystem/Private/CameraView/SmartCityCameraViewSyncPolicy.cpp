// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraView/SmartCityCameraViewSyncPolicy.h"

#include "Camera/CameraComponent.h"
#include "CameraPoint/CameraPointBase.h"
#include "CameraSwitch/GenericCameraSwitchMethod.h"
#include "CineCameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/PlayerCameraManager.h"

void USmartCityCameraViewSyncPolicy::HandleCameraSwitchBeginMessage(FGameplayTag, const FOnHandleCameraSwitchMessage&)
{
}

void USmartCityCameraViewSyncPolicy::HandleCameraSwitchResetMessage(FGameplayTag, const FOnHandleCameraSwitchMessage&)
{
}

void USmartCityCameraViewSyncPolicy::HandleCameraSwitchFinishMessage(FGameplayTag, const FOnHandleCameraSwitchMessage& InMessage)
{
	APlayerController* PlayerController = GetOwnerPlayerController();
	if (!IsValid(PlayerController) || InMessage.PlayerController != PlayerController)
	{
		return;
	}

	AlignCameraToCameraPoint(PlayerController, InMessage.CameraPoint, InMessage.SwitchMethod);
}

void USmartCityCameraViewSyncPolicy::AlignCameraToCameraPoint(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint, UGenericCameraSwitchMethod* InSwitchMethod) const
{
	AActor* TargetActor = GetOwnerActor();
	if (!IsValid(InPlayerController) || !IsValid(TargetActor) || !IsValid(InCameraPoint))
	{
		return;
	}

	USpringArmComponent* TargetSpringArmComponent = GetTargetSpringArmComponent();
	UCameraComponent* TargetCameraComponent = GetTargetCameraComponent();
	const UCameraComponent* SourceCameraComponent = InCameraPoint->GetCameraComponent();
	if (!IsValid(TargetSpringArmComponent) || !IsValid(TargetCameraComponent) || !IsValid(SourceCameraComponent))
	{
		return;
	}

	const USpringArmComponent* SourceSpringArmComponent = InCameraPoint->SpringArmComponent;
	const FVector TargetActorLocation = IsValid(SourceSpringArmComponent) ? InCameraPoint->GetActorLocation() : SourceCameraComponent->GetComponentLocation();
	const FRotator TargetArmRotation = IsValid(SourceSpringArmComponent) ? SourceSpringArmComponent->GetComponentRotation() : SourceCameraComponent->GetComponentRotation();
	FVector TargetCameraLocation = SourceCameraComponent->GetComponentLocation();
	FRotator TargetCameraRotation = SourceCameraComponent->GetComponentRotation();
	const float TargetArmLength = IsValid(SourceSpringArmComponent) ? SourceSpringArmComponent->TargetArmLength : 0.f;

	if (IsValid(InPlayerController->PlayerCameraManager) && IsValid(InSwitchMethod) && InSwitchMethod->GetSwitchDuration() > 0.f)
	{
		const FMinimalViewInfo& CurrentCameraView = InPlayerController->PlayerCameraManager->GetCameraCacheView();
		TargetCameraLocation = CurrentCameraView.Location;
		TargetCameraRotation = CurrentCameraView.Rotation;
	}

	if (IsValid(SourceSpringArmComponent))
	{
		TargetSpringArmComponent->TargetOffset = SourceSpringArmComponent->TargetOffset;
		TargetSpringArmComponent->SocketOffset = SourceSpringArmComponent->SocketOffset;
		TargetSpringArmComponent->bDoCollisionTest = SourceSpringArmComponent->bDoCollisionTest;
		TargetSpringArmComponent->ProbeSize = SourceSpringArmComponent->ProbeSize;
		TargetSpringArmComponent->ProbeChannel = SourceSpringArmComponent->ProbeChannel;
		TargetSpringArmComponent->bUsePawnControlRotation = SourceSpringArmComponent->bUsePawnControlRotation;
		TargetSpringArmComponent->bInheritPitch = SourceSpringArmComponent->bInheritPitch;
		TargetSpringArmComponent->bInheritYaw = SourceSpringArmComponent->bInheritYaw;
		TargetSpringArmComponent->bInheritRoll = SourceSpringArmComponent->bInheritRoll;
		TargetSpringArmComponent->bEnableCameraLag = SourceSpringArmComponent->bEnableCameraLag;
		TargetSpringArmComponent->bEnableCameraRotationLag = SourceSpringArmComponent->bEnableCameraRotationLag;
		TargetSpringArmComponent->bUseCameraLagSubstepping = SourceSpringArmComponent->bUseCameraLagSubstepping;
		TargetSpringArmComponent->bDrawDebugLagMarkers = SourceSpringArmComponent->bDrawDebugLagMarkers;
		TargetSpringArmComponent->bClampToMaxPhysicsDeltaTime = SourceSpringArmComponent->bClampToMaxPhysicsDeltaTime;
		TargetSpringArmComponent->CameraLagSpeed = SourceSpringArmComponent->CameraLagSpeed;
		TargetSpringArmComponent->CameraRotationLagSpeed = SourceSpringArmComponent->CameraRotationLagSpeed;
		TargetSpringArmComponent->CameraLagMaxTimeStep = SourceSpringArmComponent->CameraLagMaxTimeStep;
		TargetSpringArmComponent->CameraLagMaxDistance = SourceSpringArmComponent->CameraLagMaxDistance;
		TargetSpringArmComponent->SetRelativeLocation(SourceSpringArmComponent->GetRelativeLocation(), false, nullptr, ETeleportType::TeleportPhysics);
	}

	CopyCameraComponentParameters(SourceCameraComponent, TargetCameraComponent);
	TargetCameraComponent->SetRelativeLocation(SourceCameraComponent->GetRelativeLocation(), false, nullptr, ETeleportType::TeleportPhysics);
	TargetCameraComponent->SetRelativeRotation(SourceCameraComponent->GetRelativeRotation(), false, nullptr, ETeleportType::TeleportPhysics);

	TargetActor->SetActorLocation(TargetActorLocation, false, nullptr, ETeleportType::TeleportPhysics);
	TargetActor->SetActorRotation(FRotator(0.f, TargetArmRotation.Yaw, 0.f), ETeleportType::TeleportPhysics);
	TargetSpringArmComponent->SetRelativeRotation(FRotator(TargetArmRotation.Pitch, 0.f, 0.f), false, nullptr, ETeleportType::TeleportPhysics);
	SetSpringArmTargetArmLength(TargetSpringArmComponent, TargetArmLength);

	TargetSpringArmComponent->UpdateComponentToWorld();
	ResetSpringArmLagState(TargetSpringArmComponent);
	TargetCameraComponent->SetWorldLocationAndRotation(TargetCameraLocation, TargetCameraRotation, false, nullptr, ETeleportType::TeleportPhysics);
	TargetCameraComponent->UpdateComponentToWorld();

	InPlayerController->SetControlRotation(TargetCameraRotation);
	InPlayerController->SetViewTarget(TargetActor);
}

void USmartCityCameraViewSyncPolicy::CopyCameraComponentParameters(const UCameraComponent* InSourceCameraComponent, UCameraComponent* InTargetCameraComponent) const
{
	if (!IsValid(InSourceCameraComponent) || !IsValid(InTargetCameraComponent))
	{
		return;
	}

	InTargetCameraComponent->SetProjectionMode(InSourceCameraComponent->ProjectionMode);
	InTargetCameraComponent->SetFieldOfView(InSourceCameraComponent->FieldOfView);
	InTargetCameraComponent->SetAspectRatio(InSourceCameraComponent->AspectRatio);
	InTargetCameraComponent->SetConstraintAspectRatio(InSourceCameraComponent->bConstrainAspectRatio);
	InTargetCameraComponent->bUsePawnControlRotation = InSourceCameraComponent->bUsePawnControlRotation;
	InTargetCameraComponent->SetPostProcessBlendWeight(InSourceCameraComponent->PostProcessBlendWeight);
	InTargetCameraComponent->SetAspectRatioAxisConstraint(InSourceCameraComponent->AspectRatioAxisConstraint);
	InTargetCameraComponent->bOverrideAspectRatioAxisConstraint = InSourceCameraComponent->bOverrideAspectRatioAxisConstraint;
	InTargetCameraComponent->bLockToHmd = InSourceCameraComponent->bLockToHmd;
	InTargetCameraComponent->SetUseFieldOfViewForLOD(InSourceCameraComponent->bUseFieldOfViewForLOD);
	InTargetCameraComponent->SetOrthoWidth(InSourceCameraComponent->OrthoWidth);
	InTargetCameraComponent->PostProcessSettings = InSourceCameraComponent->PostProcessSettings;

	const UCineCameraComponent* SourceCineCameraComponent = Cast<UCineCameraComponent>(InSourceCameraComponent);
	UCineCameraComponent* TargetCineCameraComponent = Cast<UCineCameraComponent>(InTargetCameraComponent);
	if (IsValid(SourceCineCameraComponent) && IsValid(TargetCineCameraComponent))
	{
		TargetCineCameraComponent->SetFilmback(SourceCineCameraComponent->Filmback);
		TargetCineCameraComponent->SetLensSettings(SourceCineCameraComponent->LensSettings);
		TargetCineCameraComponent->SetFocusSettings(SourceCineCameraComponent->FocusSettings);
		TargetCineCameraComponent->SetCropSettings(SourceCineCameraComponent->CropSettings);
		TargetCineCameraComponent->SetCurrentFocalLength(SourceCineCameraComponent->CurrentFocalLength);
		TargetCineCameraComponent->SetCurrentAperture(SourceCineCameraComponent->CurrentAperture);
		TargetCineCameraComponent->SetFieldOfView(SourceCineCameraComponent->FieldOfView);
		TargetCineCameraComponent->SetCustomNearClippingPlane(SourceCineCameraComponent->CustomNearClippingPlane);
	}
}

APlayerController* USmartCityCameraViewSyncPolicy::GetOwnerPlayerController() const
{
	const APawn* OwnerPawn = Cast<APawn>(GetOwnerActor());
	return IsValid(OwnerPawn) ? Cast<APlayerController>(OwnerPawn->GetController()) : nullptr;
}

UCameraComponent* USmartCityCameraViewSyncPolicy::GetTargetCameraComponent() const
{
	const AActor* OwnerActor = GetOwnerActor();
	return IsValid(OwnerActor) ? OwnerActor->FindComponentByClass<UCameraComponent>() : nullptr;
}

USpringArmComponent* USmartCityCameraViewSyncPolicy::GetTargetSpringArmComponent() const
{
	const AActor* OwnerActor = GetOwnerActor();
	return IsValid(OwnerActor) ? OwnerActor->FindComponentByClass<USpringArmComponent>() : nullptr;
}
