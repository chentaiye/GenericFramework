// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericCoordinateConverter.h"
#include "UTMCoordinateConverter.generated.h"

/** UTM 投影坐标转换器，按带号和南北半球生成 EPSG CRS。 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class REALGEOREFERENCINGFRAMEWORK_API UUTMCoordinateConverter : public UGenericCoordinateConverter
{
	GENERATED_BODY()

public:
	virtual FGameplayTag GetCoordinateSystem() const override;
	virtual EGenericCoordinateFormat GetCoordinateFormat() const override;
	virtual bool RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const override;
	virtual bool ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const override;

	/** UTM 带号，北半球生成 EPSG:326xx，南半球生成 EPSG:327xx。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(ClampMin="1", ClampMax="60", UIMin="1", UIMax="60"))
	int32 Zone = 50;

	/** UTM 是否使用南半球 CRS。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	bool bSouthernHemisphere = false;
};
