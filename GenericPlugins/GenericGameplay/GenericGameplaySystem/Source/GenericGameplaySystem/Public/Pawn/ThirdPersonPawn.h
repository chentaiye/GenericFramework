// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/GenericPawn.h"
#include "ThirdPersonPawn.generated.h"

class UCameraComponent;
class UGenericCameraSwitchMethod;
class UPawnReassessmentComponent;
class UPawnSpringArmComponent;

/** 定义第三人称 Pawn 能力宿主，具体输入移动行为由 PawnInputMovementComponent 转发到策略对象。 */
UCLASS(MinimalAPI)
class AThirdPersonPawn : public AGenericPawn
{
	GENERATED_BODY()

public:
	/** 初始化 ThirdPersonPawn 的默认组件和输入移动标签。 */
	GENERICGAMEPLAYSYSTEM_API AThirdPersonPawn(const FObjectInitializer& ObjectInitializer);
	GENERICGAMEPLAYSYSTEM_API virtual void BeginPlay() override;
	GENERICGAMEPLAYSYSTEM_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	GENERICGAMEPLAYSYSTEM_API virtual void CalcCamera(float DeltaTime, FMinimalViewInfo& OutResult) override;

public:
	/** 持有第三人称相机摇臂组件。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ThirdPerson Pawn")
	TObjectPtr<UPawnSpringArmComponent> SpringArmComponent = nullptr;

	/** 持有第三人称相机组件。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ThirdPerson Pawn")
	TObjectPtr<UCameraComponent> CameraComponent = nullptr;

	/** 持有聚焦重评估组件。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ThirdPerson Pawn")
	TObjectPtr<UPawnReassessmentComponent> ReassessmentComponent = nullptr;
};
