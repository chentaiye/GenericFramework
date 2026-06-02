// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericCoordinateConverter.h"
#include "BD09CoordinateConverter.generated.h"

/** BD-09 地理坐标转换器，通过 GCJ-02 再桥接到 WGS84/ECEF。 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class REALGEOREFERENCINGFRAMEWORK_API UBD09CoordinateConverter : public UGenericCoordinateConverter
{
	GENERATED_BODY()

public:
	virtual FGameplayTag GetCoordinateSystem() const override;
	virtual EGenericCoordinateFormat GetCoordinateFormat() const override;
	virtual bool RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const override;
	virtual bool ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const override;
};
