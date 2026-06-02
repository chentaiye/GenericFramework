// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericCoordinateConverter.h"
#include "GCJ02CoordinateConverter.generated.h"

/** GCJ-02 地理坐标转换器，中国范围外按 WGS84 透传。 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class REALGEOREFERENCINGFRAMEWORK_API UGCJ02CoordinateConverter : public UGenericCoordinateConverter
{
	GENERATED_BODY()

public:
	virtual FGameplayTag GetCoordinateSystem() const override;
	virtual EGenericCoordinateFormat GetCoordinateFormat() const override;
	virtual bool RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const override;
	virtual bool ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const override;
};
