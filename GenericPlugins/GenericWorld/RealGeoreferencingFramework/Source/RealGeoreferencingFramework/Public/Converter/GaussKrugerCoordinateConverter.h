// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericCoordinateConverter.h"
#include "GaussKrugerCoordinateConverter.generated.h"

/** 高斯-克吕格投影坐标转换器，使用可配置横轴墨卡托参数。 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class REALGEOREFERENCINGFRAMEWORK_API UGaussKrugerCoordinateConverter : public UGenericCoordinateConverter
{
	GENERATED_BODY()

public:
	virtual FGameplayTag GetCoordinateSystem() const override;
	virtual EGenericCoordinateFormat GetCoordinateFormat() const override;
	virtual bool RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const override;
	virtual bool ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const override;

	/** 是否按带号推导中央经线。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	bool bUseZoneNumber = false;

	/** 高斯-克吕格带号，仅在按带号推导中央经线时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(ClampMin="1", UIMin="1", EditCondition="bUseZoneNumber", EditConditionHides))
	int32 ZoneNumber = 39;

	/** 是否使用 6 度带；关闭时按 3 度带推导。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(EditCondition="bUseZoneNumber", EditConditionHides))
	bool bSixDegreeZone = false;

	/** 中央经线，未按带号推导时直接使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double CentralMeridian = 117.0;

	/** 假东偏移，厘米单位，调用 PROJ 时换算为米。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double FalseEasting = 50000000.0;

	/** 假北偏移，厘米单位，调用 PROJ 时换算为米。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double FalseNorthing = 0.0;

	/** 投影比例因子。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(ClampMin="0.000001", UIMin="0.000001"))
	double ScaleFactor = 1.0;
};
