// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/PawnInputMovementInterface.h"
#include "UObject/Object.h"
#include "GenericInputMovement.generated.h"

class APawn;
class UPawnInputMovementComponent;

/** 作为 Pawn 输入移动策略基类，持有通用移动参数、锁定状态和宿主访问能力。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UGenericInputMovement : public UObject, public IPawnInputMovementInterface
{
	GENERATED_BODY()

public:
	/** 初始化输入移动策略与宿主 Pawn、组件之间的运行时关联。 */
	GENERICGAMEPLAYSYSTEM_API virtual void InitializeInputMovement(APawn* InOwnerPawn, UPawnInputMovementComponent* InOwnerComponent);
	GENERICGAMEPLAYSYSTEM_API virtual void DeinitializeInputMovement();

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
	GENERICGAMEPLAYSYSTEM_API virtual float GetMovementBaseSpeed() override;
	GENERICGAMEPLAYSYSTEM_API virtual float GetMovementSpeedRate() override;
	GENERICGAMEPLAYSYSTEM_API virtual float GetRotationSpeedRate() override;
	GENERICGAMEPLAYSYSTEM_API virtual float GetZoomSpeedRate() override;
	GENERICGAMEPLAYSYSTEM_API virtual FPawnLockState GetPawnLockState() override;
	GENERICGAMEPLAYSYSTEM_API virtual bool CanMove(const FVector& TargetLocation) const override;
	GENERICGAMEPLAYSYSTEM_API virtual bool CanTurn(const FRotator& TargetRotation) const override;
	GENERICGAMEPLAYSYSTEM_API virtual bool CanZoom(float TargetSpringArmLength) const override;
	GENERICGAMEPLAYSYSTEM_API virtual FVector GetLimitLocation(const FVector& TargetLocation) const override;
	GENERICGAMEPLAYSYSTEM_API virtual FRotator GetLimitRotation(const FRotator& TargetRotation) const override;
	GENERICGAMEPLAYSYSTEM_API virtual float GetLimitSpringArmLength(float TargetSpringArmLength) const override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetPawnLockState_Implementation(const FPawnLockState& InPawnLockState) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetIsFullyLock_Implementation(bool InFullyLock) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetIsLockLocation_Implementation(bool InLockLocation) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetIsLockRotation_Implementation(bool InLockRotation) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetIsLockSpringArm_Implementation(bool InLockSpringArm) override;

public:
	/** 记录 Pawn 输入移动锁定状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Input Movement")
	FPawnLockState PawnLockState;

	/** 记录移动基础速度。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Input Movement", meta=(ClampMin=0, UIMin=0))
	float MovementBaseSpeed=50.f;

	/** 记录移动速度倍率。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Input Movement", meta=(ClampMin=0, UIMin=0))
	float MovementSpeedRate=1.f;

	/** 记录旋转速度倍率。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Input Movement", meta=(ClampMin=0, UIMin=0))
	float RotationSpeedRate=1.f;

	/** 记录缩放速度倍率。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Input Movement", meta=(ClampMin=0, UIMin=0))
	float ZoomSpeedRate=1.f;

protected: 
	/** 获取当前策略绑定的宿主 Pawn。 */
	GENERICGAMEPLAYSYSTEM_API APawn* GetOwnerPawn() const;

	/** 获取当前策略绑定的输入移动组件。 */
	GENERICGAMEPLAYSYSTEM_API UPawnInputMovementComponent* GetOwnerInputMovementComponent() const;

private:
	/** 弱引用宿主 Pawn，避免策略对象延长 Actor 生命周期。 */
	TWeakObjectPtr<APawn> OwnerPawn;

	/** 弱引用宿主输入移动组件，仅用于访问策略选择上下文。 */
	TWeakObjectPtr<UPawnInputMovementComponent> OwnerComponent;
};
