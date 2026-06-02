// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RealGeoreferencingType.h"
#include "GenericCoordinateConverter.generated.h"

/**
 * 单一真实坐标系到 ECEF 的转换策略。
 * Subsystem 负责注册、投影到 UE 平面，以及不同坐标系之间的桥接。
 */
UCLASS(Abstract, BlueprintType, EditInlineNew, DefaultToInstanced, MinimalAPI)
class UGenericCoordinateConverter : public UObject
{
	GENERATED_BODY()

public:
	/** 创建坐标转换策略实例，实例通常由世界设置或 Subsystem 注册流程持有。 */
	REALGEOREFERENCINGFRAMEWORK_API UGenericCoordinateConverter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** 返回该 Converter 支持的坐标系统 Tag。 */
	virtual FGameplayTag GetCoordinateSystem() const PURE_VIRTUAL(UGenericCoordinateConverter::GetCoordinateSystem, return FGameplayTag(););

	/** 返回该 Converter 的主要坐标表达格式，用于编辑器和蓝图理解默认输入形态。 */
	virtual EGenericCoordinateFormat GetCoordinateFormat() const PURE_VIRTUAL(UGenericCoordinateConverter::GetCoordinateFormat, return EGenericCoordinateFormat::Geographic;);

	/** 将真实坐标转换到 ECEF，模块接口层的 ECEF 单位固定为厘米。 */
	virtual bool RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const PURE_VIRTUAL(UGenericCoordinateConverter::RealCoordinateToECEF, return false;);

	/** 将厘米单位 ECEF 转回该坐标系统，可按目标格式输出地理或投影坐标。 */
	virtual bool ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const PURE_VIRTUAL(UGenericCoordinateConverter::ECEFToRealCoordinate, return false;);
};
