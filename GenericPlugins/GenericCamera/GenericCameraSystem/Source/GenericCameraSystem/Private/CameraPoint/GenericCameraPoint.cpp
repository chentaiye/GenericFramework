// Copyright ChenTaiye 2025. All Rights Reserved.

#include "CameraPoint/GenericCameraPoint.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGenericCameraPoint::AGenericCameraPoint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

UCameraComponent* AGenericCameraPoint::GetCameraComponent_Implementation()
{
	return CameraComponent;
}

void AGenericCameraPoint::SetCameraComponent_Implementation(UCameraComponent* InCameraComponent)
{
	Super::SetCameraComponent_Implementation(InCameraComponent);

	if (IsValid(InCameraComponent))
	{
		/** 相机点保留构造期创建的 CameraComponent，只复制外部镜头参数，避免运行时替换子对象。 */
		CopyCameraComponentProperties(InCameraComponent, CameraComponent);
	}
}
