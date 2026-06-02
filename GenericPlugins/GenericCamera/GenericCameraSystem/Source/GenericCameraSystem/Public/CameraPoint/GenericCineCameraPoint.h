// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CameraPointBase.h"
#include "GenericCineCameraPoint.generated.h"

class UCineCameraComponent;

/** 提供 CineCameraComponent 版本的相机点，保留电影机镜头、胶片和对焦参数。 */
UCLASS(MinimalAPI)
class AGenericCineCameraPoint : public ACameraPointBase
{
	GENERATED_BODY()

public:
	/** 创建默认 CineCameraComponent 并挂到基类弹簧臂，让电影机镜头也能走统一切换流程。 */
	AGenericCineCameraPoint(const FObjectInitializer& ObjectInitializer);

	/* ACameraPointBase */
public:
	GENERICCAMERASYSTEM_API virtual UCameraComponent* GetCameraComponent_Implementation() override;
	GENERICCAMERASYSTEM_API virtual void SetCameraComponent_Implementation(UCameraComponent* InCameraComponent) override;

	/* ACineCameraPoint */
public:
	/** 实际传给 PlayerCameraManager 的电影机组件，额外接收 UCineCameraComponent 的专属镜头参数。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Generic Cine Camera Point")
	UCineCameraComponent* CineCameraComponent=nullptr;
};
