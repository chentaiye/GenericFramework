// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraPoint/GenericCineCameraPoint.h"

#include "CineCameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGenericCineCameraPoint::AGenericCineCameraPoint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CineCameraComponent = CreateDefaultSubobject<UCineCameraComponent>("CineCamera");
	CineCameraComponent->SetupAttachment(SpringArmComponent);
}

UCameraComponent* AGenericCineCameraPoint::GetCameraComponent_Implementation()
{
	return CineCameraComponent;
}

void AGenericCineCameraPoint::SetCameraComponent_Implementation(UCameraComponent* InCameraComponent)
{
	Super::SetCameraComponent_Implementation(InCameraComponent);

	if (IsValid(InCameraComponent))
	{
		CopyCameraComponentProperties(InCameraComponent, CineCameraComponent);

		if (UCineCameraComponent* CastComponent = Cast<UCineCameraComponent>(InCameraComponent))
		{
			/** 普通相机参数由基类复制，电影机专属的胶片、镜头和对焦参数需要额外同步。 */
			CineCameraComponent->SetFilmback(CastComponent->Filmback);
			CineCameraComponent->SetLensSettings(CastComponent->LensSettings);
			CineCameraComponent->SetFocusSettings(CastComponent->FocusSettings);
			CineCameraComponent->SetCropSettings(CastComponent->CropSettings);
			CineCameraComponent->SetCurrentFocalLength(CastComponent->CurrentFocalLength);
			CineCameraComponent->SetCurrentAperture(CastComponent->CurrentAperture);
			CineCameraComponent->SetFieldOfView(CastComponent->FieldOfView);
			CineCameraComponent->SetCustomNearClippingPlane(CastComponent->CustomNearClippingPlane);
		}
	}
}
