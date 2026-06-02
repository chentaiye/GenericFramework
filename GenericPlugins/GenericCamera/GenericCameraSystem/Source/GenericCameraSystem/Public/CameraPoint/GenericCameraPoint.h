// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraPointBase.h"
#include "GameFramework/Actor.h"
#include "GenericCameraPoint.generated.h"

class UGenericCameraSwitchMethod;
class UCameraComponent;

/** 提供普通 UCameraComponent 版本的相机点，用于默认透视或正交镜头切换。 */
UCLASS(MinimalAPI)
class AGenericCameraPoint : public ACameraPointBase
{
	GENERATED_BODY()

public:
	/** 创建默认 CameraComponent 并挂到基类弹簧臂，焦点距离由基类统一控制。 */
	AGenericCameraPoint(const FObjectInitializer& ObjectInitializer);

	/* ACameraPointBase */
public:
	GENERICCAMERASYSTEM_API virtual UCameraComponent* GetCameraComponent_Implementation() override;
	GENERICCAMERASYSTEM_API virtual void SetCameraComponent_Implementation(UCameraComponent* InCameraComponent) override;

	/* ACameraPoint */
public:
	/** 实际传给 PlayerCameraManager 的普通相机组件，接收外部 UCameraComponent 的可复用参数。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Camera Point")
	UCameraComponent* CameraComponent=nullptr;
};
