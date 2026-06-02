// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "RealGeoreferencingType.generated.h"

REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing);
REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing_CoordinateSystem);
REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing_CoordinateSystem_WGS84);
REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing_CoordinateSystem_GCJ02);
REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing_CoordinateSystem_BD09);
REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing_CoordinateSystem_CGCS2000);
REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing_CoordinateSystem_UTM);
REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing_CoordinateSystem_Mercator);
REALGEOREFERENCINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayGeoreferencing_CoordinateSystem_GaussKruger);

/** 真实坐标值的表达格式，用于区分经纬高坐标和投影平面坐标。 */
UENUM(BlueprintType)
enum class EGenericCoordinateFormat : uint8
{
	/** 经纬高坐标，经纬度使用角度，高度使用厘米。 */
	Geographic,

	/** 投影平面坐标，东西向、南北向、高度均使用厘米。 */
	Projected
};

/** UE 平面世界使用的投影坐标参考系统类型。 */
UENUM(BlueprintType)
enum class EGenericProjectedCrsType : uint8
{
	/** UTM 投影，按带号和南北半球生成 EPSG CRS。 */
	UTM,

	/** Web Mercator 投影，对应 EPSG:3857。 */
	Mercator,

	/** 高斯-克吕格横轴墨卡托投影，参数由设置显式控制。 */
	GaussKruger,

	/** 自定义 CRS 或 PROJ 字符串，由 PROJ 直接解析。 */
	Custom
};

/** 真实地理经纬高坐标，经纬度使用角度，高度统一使用厘米。 */
USTRUCT(BlueprintType)
struct REALGEOREFERENCINGFRAMEWORK_API FGenericCoordinate
{
	GENERATED_BODY()

	/** 纬度，角度单位，表示真实地理位置的南北方向。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double CoordinateLat = 39.908823;

	/** 经度，角度单位，表示真实地理位置的东西方向。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double CoordinateLon = 116.397470;

	/** 海拔高度，厘米单位，海拔 0 对应 UE Z 轴零高度。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double CoordinateAlt = 0.0;
};

/** 真实投影平面坐标，所有线性分量统一使用厘米。 */
USTRUCT(BlueprintType)
struct REALGEOREFERENCINGFRAMEWORK_API FGenericProjectedCoordinate
{
	GENERATED_BODY()

	/** 投影东西向坐标，厘米单位。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double CoordinateX = 0.0;

	/** 投影南北向坐标，厘米单位。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double CoordinateY = 0.0;

	/** 投影高度坐标，厘米单位，海拔 0 对应 UE Z 轴零高度。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	double CoordinateZ = 0.0;
};

/** 带坐标系统标识的真实坐标，允许在同一接口中传递地理或投影格式。 */
USTRUCT(BlueprintType)
struct REALGEOREFERENCINGFRAMEWORK_API FGenericRealCoordinate
{
	GENERATED_BODY()

	/** 坐标系统 GameplayTag，应位于 GameplayGeoreferencing.CoordinateSystem 下。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	FGameplayTag CoordinateSystem = TAG_GameplayGeoreferencing_CoordinateSystem_WGS84;

	/** 当前坐标值使用的格式。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	EGenericCoordinateFormat CoordinateFormat = EGenericCoordinateFormat::Geographic;

	/** 地理格式下使用的经纬高坐标。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	FGenericCoordinate GeographicCoordinate;

	/** 投影格式下使用的平面坐标。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	FGenericProjectedCoordinate ProjectedCoordinate;
};

/** UE 平面世界使用的投影 CRS 参数，投影结果在本模块接口中统一换算为厘米。 */
USTRUCT(BlueprintType)
struct REALGEOREFERENCINGFRAMEWORK_API FGenericProjectionSettings
{
	GENERATED_BODY()

	/** 投影 CRS 类型，决定如何生成传给 PROJ 的 CRS 描述。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	EGenericProjectedCrsType ProjectedCrsType = EGenericProjectedCrsType::UTM;

	/** UTM 带号，北半球生成 EPSG:326xx，南半球生成 EPSG:327xx。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(ClampMin="1", ClampMax="60", UIMin="1", UIMax="60", EditCondition="ProjectedCrsType==EGenericProjectedCrsType::UTM", EditConditionHides))
	int32 UTMZone = 50;

	/** UTM 是否使用南半球 CRS。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(EditCondition="ProjectedCrsType==EGenericProjectedCrsType::UTM", EditConditionHides))
	bool bUTMSouthernHemisphere = false;

	/** 高斯-克吕格是否按带号推导中央经线。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(EditCondition="ProjectedCrsType==EGenericProjectedCrsType::GaussKruger", EditConditionHides))
	bool bGaussKrugerUseZoneNumber = false;

	/** 高斯-克吕格带号，仅在按带号推导中央经线时使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(ClampMin="1", UIMin="1", EditCondition="ProjectedCrsType==EGenericProjectedCrsType::GaussKruger && bGaussKrugerUseZoneNumber", EditConditionHides))
	int32 GaussKrugerZoneNumber = 39;

	/** 高斯-克吕格是否使用 6 度带；关闭时按 3 度带推导。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(EditCondition="ProjectedCrsType==EGenericProjectedCrsType::GaussKruger && bGaussKrugerUseZoneNumber", EditConditionHides))
	bool bGaussKrugerSixDegreeZone = false;

	/** 高斯-克吕格中央经线，未按带号推导时直接使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(EditCondition="ProjectedCrsType==EGenericProjectedCrsType::GaussKruger", EditConditionHides))
	double GaussKrugerCentralMeridian = 117.0;

	/** 高斯-克吕格假东偏移，厘米单位，调用 PROJ 时换算为米。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(EditCondition="ProjectedCrsType==EGenericProjectedCrsType::GaussKruger", EditConditionHides))
	double GaussKrugerFalseEasting = 50000000.0;

	/** 高斯-克吕格假北偏移，厘米单位，调用 PROJ 时换算为米。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(EditCondition="ProjectedCrsType==EGenericProjectedCrsType::GaussKruger", EditConditionHides))
	double GaussKrugerFalseNorthing = 0.0;

	/** 高斯-克吕格比例因子。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(ClampMin="0.000001", UIMin="0.000001", EditCondition="ProjectedCrsType==EGenericProjectedCrsType::GaussKruger", EditConditionHides))
	double GaussKrugerScaleFactor = 1.0;

	/** 自定义 CRS 或 PROJ 字符串，类型为 Custom 时由 PROJ 直接解析。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(EditCondition="ProjectedCrsType==EGenericProjectedCrsType::Custom", EditConditionHides))
	FString CustomCrsString;
};
