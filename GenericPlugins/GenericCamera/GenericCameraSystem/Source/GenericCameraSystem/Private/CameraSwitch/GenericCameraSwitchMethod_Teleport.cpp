// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraSwitch/GenericCameraSwitchMethod_Teleport.h"

#include "CameraPoint/CameraPointBase.h"

bool UGenericCameraSwitchMethod_Teleport::HandleSwitchToCameraPoint_Implementation(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint)
{
	if (Super::HandleSwitchToCameraPoint_Implementation(InPlayerController, InCameraPoint))
	{
		if (!IsValid(InPlayerController) || !IsValid(InPlayerController->PlayerCameraManager))
		{
			NativeOnSwitchToCameraPointReset();
			return false;
		}

		InPlayerController->PlayerCameraManager->SetViewTarget(InCameraPoint);
		NativeOnSwitchToCameraPointFinish();
		return true;
	}

	return false;
}

void UGenericCameraSwitchMethod_Teleport::OnSwitchToCameraPointReset_Implementation()
{
	Super::OnSwitchToCameraPointReset_Implementation();
}

void UGenericCameraSwitchMethod_Teleport::OnSwitchToCameraPointFinish_Implementation()
{
	Super::OnSwitchToCameraPointFinish_Implementation();
}
