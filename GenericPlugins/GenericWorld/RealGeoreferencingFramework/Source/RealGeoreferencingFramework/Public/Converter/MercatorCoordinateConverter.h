// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericCoordinateConverter.h"
#include "MercatorCoordinateConverter.generated.h"

/** Web Mercator 投影坐标转换器，默认使用 EPSG:3857。 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class REALGEOREFERENCINGFRAMEWORK_API UMercatorCoordinateConverter : public UGenericCoordinateConverter
{
	GENERATED_BODY()

public:
	virtual FGameplayTag GetCoordinateSystem() const override;
	virtual EGenericCoordinateFormat GetCoordinateFormat() const override;
	virtual bool RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const override;
	virtual bool ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const override;
};
