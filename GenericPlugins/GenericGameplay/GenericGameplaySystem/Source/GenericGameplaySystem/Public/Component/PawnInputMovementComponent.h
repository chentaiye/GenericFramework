// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Interface/PawnInputMovementInterface.h"
#include "PawnInputMovementComponent.generated.h"

class UGenericInputMovement;

/** 持有 Pawn 输入移动策略选择状态，并把接口调用转发给当前激活的策略对象。 */
UCLASS(MinimalAPI, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UPawnInputMovementComponent : public UActorComponent, public IPawnInputMovementInterface
{
	GENERATED_BODY()

public:
	/** 初始化 Pawn 输入移动组件的默认运行状态。 */
	UPawnInputMovementComponent();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/* IPawnInputMovementInterface */
public:
	virtual void ConsumeLocationInput_Implementation(float DeltaSeconds) override;
	virtual void ConsumeRotationInput_Implementation(float DeltaSeconds) override;
	virtual float GetAdaptiveMovementSpeed_Implementation() override;
	virtual float GetAdaptiveRotationSpeed_Implementation() override;
	virtual void AddLocation_Implementation(FVector2D InValue) override;
	virtual void AddRotation_Implementation(FVector2D InValue) override;
	virtual void AddZoom_Implementation(float InValue) override;
	virtual void SetLocation_Implementation(FVector InValue) override;
	virtual void SetRotation_Implementation(FRotator InValue) override;
	virtual void SetZoom_Implementation(float InValue) override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual FVector GetLocation() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual FRotator GetRotation() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual float GetZoom() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual float GetMovementBaseSpeed() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual float GetMovementSpeedRate() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual float GetRotationSpeedRate() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual float GetZoomSpeedRate() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual FPawnLockState GetPawnLockState() override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual bool CanMove(const FVector& TargetLocation) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual bool CanTurn(const FRotator& TargetRotation) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual bool CanZoom(float TargetSpringArmLength) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual FVector GetLimitLocation(const FVector& TargetLocation) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual FRotator GetLimitRotation(const FRotator& TargetRotation) const override;

	UFUNCTION(BlueprintPure, Category="Pawn Input Movement Component")
	virtual float GetLimitSpringArmLength(float TargetSpringArmLength) const override;
	virtual void SetPawnLockState_Implementation(const FPawnLockState& InPawnLockState) override;
	virtual void SetIsFullyLock_Implementation(bool InFullyLock) override;
	virtual void SetIsLockLocation_Implementation(bool InLockLocation) override;
	virtual void SetIsLockRotation_Implementation(bool InLockRotation) override;
	virtual void SetIsLockSpringArm_Implementation(bool InLockSpringArm) override;

public:
	/** 获取当前激活标签对应的输入移动策略对象。 */
	UFUNCTION(BlueprintCallable, Category="Pawn Input Movement Component")
	GENERICGAMEPLAYSYSTEM_API UGenericInputMovement* GetActiveInputMovement();

protected:
	/** 根据当前标签和映射表解析可用的输入移动策略类。 */
	TSubclassOf<UGenericInputMovement> ResolveInputMovementClass(FGameplayTag& OutResolvedTag) const;

public:
	/** 选择当前需要启用的输入移动策略标签。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Component", meta=(GameplayTagFilter="GameplayInput.Movement"))
	FGameplayTag ActiveInputMovementTag;

	/** 记录输入移动标签到策略类的映射。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Component")
	TMap<FGameplayTag, TSubclassOf<UGenericInputMovement>> InputMovementClasses;

private:
	/** 缓存按标签创建的输入移动策略实例。 */
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UGenericInputMovement>> InputMovementInstances;
};
