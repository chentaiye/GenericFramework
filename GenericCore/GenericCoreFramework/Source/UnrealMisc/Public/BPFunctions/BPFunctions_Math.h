// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Math.generated.h"

/** 集中暴露Math蓝图函数库接口，让蓝图通过稳定入口访问Unreal 通用工具功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_Math : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/* Vector */
public:
	/** 计算两个方向向量的角度中值，返回以角度表示的结果供蓝图几何逻辑使用。 */
	UFUNCTION(BlueprintPure, Category="Math|Vector", meta=(DisplayName="Middle (Vector)(Degrees)", AdvancedDisplay="2"))
	static UNREALMISC_API FVector Vector_MiddleDegrees(const FVector& V1, const FVector& V2, float Alpha = .5f, float Degrees = 0.f);

	/** 计算两个方向向量的弧度中值，返回以弧度表示的结果供蓝图几何逻辑使用。 */
	UFUNCTION(BlueprintPure, Category="Math|Vector", meta=(DisplayName="Middle (Vector)(Radians)", AdvancedDisplay="2"))
	static UNREALMISC_API FVector Vector_MiddleRadians(const FVector& V1, const FVector& V2, float Alpha = .5f, float Radians = 0.f);

	/* Rotation*/
public:
	/** 规范化旋转值，避免蓝图侧在角度换算中收到异常姿态。 */
	UFUNCTION(BlueprintPure, Category="Math|Rotator", meta=(DisplayName="Get Safe Rotator", CompactNodeTitle="Safe"))
	static UNREALMISC_API FRotator Rotator_Safe(FRotator R);

	/* Vector2D */
public:
};
