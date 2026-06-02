// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnInputMovementInterface.generated.h"

/** 描述 Pawn 可移动的世界位置边界。 */
USTRUCT(BlueprintType)
struct GENERICGAMEPLAYSYSTEM_API FPawnLocationLimit
{
	GENERATED_BODY()

public:
	/** 标记是否限制世界 X 轴位置。 */
	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bLimitLocationX=false;

	/** 记录世界 X 轴允许范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditCondition="bLimitLocationX"))
	FVector2D LocationXRange=FVector2D::Zero();

	/** 标记是否限制世界 Y 轴位置。 */
	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bLimitLocationY=false;

	/** 记录世界 Y 轴允许范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditCondition="bLimitLocationY"))
	FVector2D LocationYRange=FVector2D::Zero();

	/** 标记是否限制世界 Z 轴位置。 */
	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bLimitLocationZ=false;

	/** 记录世界 Z 轴允许范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditCondition="bLimitLocationZ"))
	FVector2D LocationZRange=FVector2D::Zero();

public:
	/** 判断目标位置是否仍在允许范围内。 */
	bool CanMove(const FVector& TargetLocation) const;
};

/** 描述 Pawn 可旋转的角度边界。 */
USTRUCT(BlueprintType)
struct GENERICGAMEPLAYSYSTEM_API FPawnRotationLimit
{
	GENERATED_BODY()

public:
	/** 标记是否限制俯仰角。 */
	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bLimitPitch=true;

	/** 记录俯仰角允许范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditCondition="bLimitPitch", ClampMin="-90", UIMin="-90", ClampMax="90", UIMax="90"))
	FVector2D PitchRange=FVector2D(-90.f, 10.f);

	/** 标记是否限制偏航角。 */
	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bLimitYaw=false;

	/** 记录偏航角允许范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditCondition="bLimitYaw", ClampMin="0", UIMin="0", ClampMax="360", UIMax="360"))
	FVector2D YawRange=FVector2D::Zero();

	/** 标记是否限制滚转角。 */
	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bLimitRoll=false;

	/** 记录滚转角允许范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditCondition="bLimitRoll", ClampMin="0", UIMin="0", ClampMax="360", UIMax="360"))
	FVector2D RollRange=FVector2D::Zero();

public:
	/** 判断目标旋转是否仍在允许范围内。 */
	bool CanTurn(const FRotator& TargetRotation) const;
};

/** 描述 Pawn 相机摇臂可缩放的长度边界。 */
USTRUCT(BlueprintType)
struct GENERICGAMEPLAYSYSTEM_API FSpringArmLimit
{
	GENERATED_BODY()

public:
	/** 标记是否限制摇臂长度。 */
	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bLimitSpringArmLength=true;

	/** 记录摇臂长度允许范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditCondition="bLimitSpringArmLength", ClampMin="0", UIMin="0"))
	FVector2D SpringArmLengthRange=FVector2D(0.f, 100000000.f);

public:
	/** 判断目标摇臂长度是否仍在允许范围内。 */
	bool CanZoom(float TargetSpringArmLength) const;
};

/** 汇总 Pawn 输入移动使用的锁定和限制状态。 */
USTRUCT(BlueprintType)
struct GENERICGAMEPLAYSYSTEM_API FPawnLockState
{
	GENERATED_BODY()

public:
	/** 标记是否完全锁定位置、旋转和缩放。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface")
	bool bFullyLock=false;

	/** 标记是否锁定位置变更。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditConditionHides, EditCondition="!bFullyLock"))
	bool bLockLocation=false;

	/** 标记是否锁定旋转变更。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditConditionHides, EditCondition="!bFullyLock"))
	bool bLockRotation=false;

	/** 标记是否锁定摇臂缩放。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface", meta=(EditConditionHides, EditCondition="!bFullyLock"))
	bool bLockSpringArm=false;

public:
	/** 记录 Pawn 位置限制。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface")
	FPawnLocationLimit PawnLocationLimit;

	/** 记录 Pawn 旋转限制。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface")
	FPawnRotationLimit PawnRotationLimit;

	/** 记录相机摇臂限制。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement Interface")
	FSpringArmLimit SpringArmLimit;
};

/** 定义 Pawn 输入移动能力接口，供 Pawn、Character、组件和策略对象解耦调用。 */
UINTERFACE()
class UPawnInputMovementInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义 Pawn 输入移动能力接口，供 Pawn、Character、组件和策略对象解耦调用。 */
class GENERICGAMEPLAYSYSTEM_API IPawnInputMovementInterface
{
	GENERATED_BODY()

public:
	/** 消费位置输入缓存。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void ConsumeLocationInput(float DeltaSeconds);

	/** 消费旋转输入缓存。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void ConsumeRotationInput(float DeltaSeconds);

	/** 获取当前视角和缩放下的自适应移动速度。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	float GetAdaptiveMovementSpeed();

	/** 获取当前视角和缩放下的自适应旋转速度。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	float GetAdaptiveRotationSpeed();

public:
	/** 添加位置输入或位置增量。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void AddLocation(FVector2D InValue);

	/** 添加旋转输入或旋转增量。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void AddRotation(FVector2D InValue);

	/** 添加缩放输入。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void AddZoom(float InValue);

	/** 设置最终位置。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void SetLocation(FVector InValue);

	/** 设置最终旋转。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void SetRotation(FRotator InValue);

	/** 设置最终缩放。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void SetZoom(float InValue);

public:
	/** 获取当前位置。 */
	virtual FVector GetLocation() { return FVector::ZeroVector; }

	/** 获取当前旋转。 */
	virtual FRotator GetRotation() { return FRotator::ZeroRotator; }

	/** 获取当前缩放。 */
	virtual float GetZoom() { return 0.f; }

public:
	/** 获取移动基础速度。 */
	virtual float GetMovementBaseSpeed() { return 0.f; }

	/** 获取移动速度倍率。 */
	virtual float GetMovementSpeedRate() { return 0.f; }

	/** 获取旋转速度倍率。 */
	virtual float GetRotationSpeedRate() { return 0.f; }

	/** 获取缩放速度倍率。 */
	virtual float GetZoomSpeedRate() { return 0.f; }

public:
	/** 获取 Pawn 输入移动锁定状态。 */
	virtual FPawnLockState GetPawnLockState() { return FPawnLockState(); }

	/** 判断目标位置是否允许应用。 */
	virtual bool CanMove(const FVector& TargetLocation) const { return true; }

	/** 判断目标旋转是否允许应用。 */
	virtual bool CanTurn(const FRotator& TargetRotation) const { return true; }

	/** 判断目标缩放是否允许应用。 */
	virtual bool CanZoom(float TargetSpringArmLength) const { return true; }

	/** 根据锁定状态裁剪目标位置。 */
	virtual FVector GetLimitLocation(const FVector& TargetLocation) const { return TargetLocation; }

	/** 根据锁定状态裁剪目标旋转。 */
	virtual FRotator GetLimitRotation(const FRotator& TargetRotation) const { return TargetRotation; }

	/** 根据锁定状态裁剪目标摇臂长度。 */
	virtual float GetLimitSpringArmLength(float TargetSpringArmLength) const { return TargetSpringArmLength; }

	/** 设置 Pawn 输入移动锁定状态。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void SetPawnLockState(const FPawnLockState& InPawnLockState);

	/** 设置是否完全锁定输入移动。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void SetIsFullyLock(bool InFullyLock);

	/** 设置是否锁定位置输入移动。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void SetIsLockLocation(bool InLockLocation);

	/** 设置是否锁定旋转输入移动。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void SetIsLockRotation(bool InLockRotation);

	/** 设置是否锁定摇臂缩放。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	void SetIsLockSpringArm(bool InLockSpringArm);
};
