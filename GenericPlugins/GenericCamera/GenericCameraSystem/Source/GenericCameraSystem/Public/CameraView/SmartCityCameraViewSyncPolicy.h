// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraView/CameraViewSyncPolicy.h"
#include "SmartCityCameraViewSyncPolicy.generated.h"

class ACameraPointBase;
class APlayerController;
class UCameraComponent;
class UGenericCameraSwitchMethod;
class USpringArmComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class USmartCityCameraViewSyncPolicy : public UCameraViewSyncPolicy
{
	GENERATED_BODY()

	/* Camera Switch Message */
protected:
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchBeginMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage) override;
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchResetMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage) override;
	GENERICCAMERASYSTEM_API virtual void HandleCameraSwitchFinishMessage(FGameplayTag InChannel, const FOnHandleCameraSwitchMessage& InMessage) override;

private:
	void AlignCameraToCameraPoint(APlayerController* InPlayerController, ACameraPointBase* InCameraPoint, UGenericCameraSwitchMethod* InSwitchMethod) const;
	void CopyCameraComponentParameters(const UCameraComponent* InSourceCameraComponent, UCameraComponent* InTargetCameraComponent) const;
	APlayerController* GetOwnerPlayerController() const;
	UCameraComponent* GetTargetCameraComponent() const;
	USpringArmComponent* GetTargetSpringArmComponent() const;
};
