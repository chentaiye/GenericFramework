// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayType.h"
#include "Movement/PawnInputMovement.h"
#include "ThirdPersonPawnInputMovement.generated.h"

class AThirdPersonPawn;

/** 使用第三人称摇臂视角执行 Pawn 平滑移动、旋转和缩放。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UThirdPersonPawnInputMovement : public UPawnInputMovement
{
	GENERATED_BODY()

public:
	/** 初始化第三人称 Pawn 输入移动策略的默认参数。 */
	GENERICGAMEPLAYSYSTEM_API UThirdPersonPawnInputMovement();

	/* IPawnInputMovementInterface */
public:
	GENERICGAMEPLAYSYSTEM_API virtual void ConsumeLocationInput_Implementation(float DeltaSeconds) override;
	GENERICGAMEPLAYSYSTEM_API virtual void ConsumeRotationInput_Implementation(float DeltaSeconds) override;
	GENERICGAMEPLAYSYSTEM_API virtual float GetAdaptiveMovementSpeed_Implementation() override;
	GENERICGAMEPLAYSYSTEM_API virtual float GetAdaptiveRotationSpeed_Implementation() override;
	GENERICGAMEPLAYSYSTEM_API virtual void AddLocation_Implementation(FVector2D InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void AddRotation_Implementation(FVector2D InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void AddZoom_Implementation(float InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetLocation_Implementation(FVector InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetRotation_Implementation(FRotator InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetZoom_Implementation(float InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual FVector GetLocation() override;
	GENERICGAMEPLAYSYSTEM_API virtual FRotator GetRotation() override;
	GENERICGAMEPLAYSYSTEM_API virtual float GetZoom() override;

protected:
	/** 获取当前策略绑定的第三人称 Pawn。 */
	GENERICGAMEPLAYSYSTEM_API AThirdPersonPawn* GetThirdPersonPawn() const;

public:
	/** 记录移动自适应倍率设置。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ThirdPerson Pawn Input Movement")
	FPawnAdaptiveRateSettings MovementAdaptiveRate;

	/** 记录旋转自适应倍率设置。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ThirdPerson Pawn Input Movement")
	FPawnAdaptiveRateSettings RotationAdaptiveRate;

	/** 记录输入平滑设置。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ThirdPerson Pawn Input Movement")
	FPawnInputSmoothingSettings InputSmoothing;

private:
	/** 记录等待消费的位置输入。 */
	FVector2D PendingLocationInput=FVector2D::ZeroVector;

	/** 记录已平滑的位置输入。 */
	FVector2D SmoothedLocationInput=FVector2D::ZeroVector;

	/** 记录等待消费的旋转输入。 */
	FVector2D PendingRotationInput=FVector2D::ZeroVector;

	/** 记录已平滑的旋转输入。 */
	FVector2D SmoothedRotationInput=FVector2D::ZeroVector;
};
