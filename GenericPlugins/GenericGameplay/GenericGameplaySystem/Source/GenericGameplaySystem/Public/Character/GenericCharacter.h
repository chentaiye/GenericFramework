// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/PawnInputMovementInterface.h"
#include "GenericCharacter.generated.h"

class UPawnInputMovementComponent;

/** 定义通用 Character 能力宿主，输入移动行为由 PawnInputMovementComponent 选择策略执行。 */
UCLASS(MinimalAPI)
class AGenericCharacter : public ACharacter, public IPawnInputMovementInterface
{
	GENERATED_BODY()

public:
	/** 初始化通用 Character 的默认组件和输入移动标签。 */
	GENERICGAMEPLAYSYSTEM_API AGenericCharacter();
	GENERICGAMEPLAYSYSTEM_API virtual void SetupPlayerInputComponent(UInputComponent* PlayerInput) override;

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

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual FVector GetLocation() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual FRotator GetRotation() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual float GetZoom() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual float GetMovementBaseSpeed() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual float GetMovementSpeedRate() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual float GetRotationSpeedRate() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual float GetZoomSpeedRate() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual FPawnLockState GetPawnLockState() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual bool CanMove(const FVector& TargetLocation) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual bool CanTurn(const FRotator& TargetRotation) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual bool CanZoom(float TargetSpringArmLength) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual FVector GetLimitLocation(const FVector& TargetLocation) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual FRotator GetLimitRotation(const FRotator& TargetRotation) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement")
	GENERICGAMEPLAYSYSTEM_API virtual float GetLimitSpringArmLength(float TargetSpringArmLength) const override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetPawnLockState_Implementation(const FPawnLockState& InPawnLockState) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetIsFullyLock_Implementation(bool InFullyLock) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetIsLockLocation_Implementation(bool InLockLocation) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetIsLockRotation_Implementation(bool InLockRotation) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetIsLockSpringArm_Implementation(bool InLockSpringArm) override;

public:
	/** 持有输入移动组件和锁定状态。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pawn Input Movement")
	TObjectPtr<UPawnInputMovementComponent> InputMovementComponent = nullptr;
};
