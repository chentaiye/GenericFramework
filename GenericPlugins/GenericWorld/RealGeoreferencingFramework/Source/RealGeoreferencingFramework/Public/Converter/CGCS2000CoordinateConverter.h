// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericCoordinateConverter.h"
#include "CGCS2000CoordinateConverter.generated.h"

/** CGCS2000 地理坐标转换器，使用 EPSG:4490，v1 按常见业务近似与 WGS84 兼容。 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class REALGEOREFERENCINGFRAMEWORK_API UCGCS2000CoordinateConverter : public UGenericCoordinateConverter
{
	GENERATED_BODY()

public:
	virtual FGameplayTag GetCoordinateSystem() const override;
	virtual EGenericCoordinateFormat GetCoordinateFormat() const override;
	virtual bool RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const override;
	virtual bool ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const override;
};
