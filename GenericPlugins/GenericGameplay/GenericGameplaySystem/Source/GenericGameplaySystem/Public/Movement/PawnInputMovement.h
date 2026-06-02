// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Movement/GenericInputMovement.h"
#include "PawnInputMovement.generated.h"

/** 使用 APawn 输入接口执行基础位置和旋转移动。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UPawnInputMovement : public UGenericInputMovement
{
	GENERATED_BODY()

public:
	/** 初始化 Pawn 输入移动策略的默认对象状态。 */
	GENERICGAMEPLAYSYSTEM_API UPawnInputMovement();

	/* IPawnInputMovementInterface */
public:
	GENERICGAMEPLAYSYSTEM_API virtual void AddLocation_Implementation(FVector2D InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void AddRotation_Implementation(FVector2D InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetLocation_Implementation(FVector InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetRotation_Implementation(FRotator InValue) override;
};
