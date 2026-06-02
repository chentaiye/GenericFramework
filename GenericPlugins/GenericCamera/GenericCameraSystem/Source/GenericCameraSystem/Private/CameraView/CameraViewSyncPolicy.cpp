// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraView/CameraViewSyncPolicy.h"

#include "CameraView/SyncCameraViewComponent.h"
#include "GameFramework/SpringArmComponent.h"

namespace
{
	const FName SetTargetArmLengthFunctionName(TEXT("SetTargetArmLength"));

	struct FSetTargetArmLengthParameters
	{
		float InValue = 0.f;
	};
}

void UCameraViewSyncPolicy::InitializeCameraViewSyncPolicy(USyncCameraViewComponent* InOwnerComponent)
{
	OwnerComponent = InOwnerComponent;
}

void UCameraViewSyncPolicy::DeinitializeCameraViewSyncPolicy()
{
	OwnerComponent.Reset();
}

void UCameraViewSyncPolicy::TickCameraViewSyncPolicy(float)
{
}

void UCameraViewSyncPolicy::HandleCameraSwitchBeginMessage(FGameplayTag, const FOnHandleCameraSwitchMessage&)
{
}

void UCameraViewSyncPolicy::HandleCameraSwitchResetMessage(FGameplayTag, const FOnHandleCameraSwitchMessage&)
{
}

void UCameraViewSyncPolicy::HandleCameraSwitchFinishMessage(FGameplayTag, const FOnHandleCameraSwitchMessage&)
{
}

USyncCameraViewComponent* UCameraViewSyncPolicy::GetOwnerSyncCameraViewComponent() const
{
	return OwnerComponent.Get();
}

AActor* UCameraViewSyncPolicy::GetOwnerActor() const
{
	const USyncCameraViewComponent* SyncCameraViewComponent = GetOwnerSyncCameraViewComponent();
	return IsValid(SyncCameraViewComponent) ? SyncCameraViewComponent->GetOwner() : nullptr;
}

void UCameraViewSyncPolicy::SetSpringArmTargetArmLength(USpringArmComponent* InSpringArmComponent, const float InTargetArmLength) const
{
	if (!IsValid(InSpringArmComponent))
	{
		return;
	}

	if (UFunction* SetTargetArmLengthFunction = InSpringArmComponent->FindFunction(SetTargetArmLengthFunctionName))
	{
		FSetTargetArmLengthParameters Parameters;
		Parameters.InValue = InTargetArmLength;
		InSpringArmComponent->ProcessEvent(SetTargetArmLengthFunction, &Parameters);
		return;
	}

	InSpringArmComponent->TargetArmLength = InTargetArmLength;
}

void UCameraViewSyncPolicy::ResetSpringArmLagState(USpringArmComponent* InSpringArmComponent) const
{
	if (!IsValid(InSpringArmComponent))
	{
		return;
	}

	const FVector ArmOrigin = InSpringArmComponent->GetComponentLocation() + InSpringArmComponent->TargetOffset;
	InSpringArmComponent->PreviousArmOrigin = ArmOrigin;
	InSpringArmComponent->PreviousDesiredLoc = ArmOrigin;
	InSpringArmComponent->PreviousDesiredRot = InSpringArmComponent->GetTargetRotation();
}
