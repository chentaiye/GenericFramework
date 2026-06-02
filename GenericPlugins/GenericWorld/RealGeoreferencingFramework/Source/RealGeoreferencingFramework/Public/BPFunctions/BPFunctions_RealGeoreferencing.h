// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RealGeoreferencingType.h"
#include "BPFunctions_RealGeoreferencing.generated.h"

/** 真实地理参考蓝图函数库，负责把蓝图调用转发到当前世界的 RealGeoreferencingSubsystem。 */
UCLASS(MinimalAPI)
class UBPFunctions_RealGeoreferencing : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 将带坐标系和格式的真实坐标转换为 UE 世界坐标，完整使用 Real -> ECEF -> UE 投影链路。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool RealCoordinateToUnreal(const UObject* WorldContextObject, const FGenericRealCoordinate& InRealCoordinate, FVector& OutLocation);

	/** 将 UE 世界坐标转换为目标真实坐标系，目标格式决定输出经纬高或投影平面坐标。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool UnrealToRealCoordinate(const UObject* WorldContextObject, FGameplayTag TargetCoordinateSystem, EGenericCoordinateFormat TargetFormat, const FVector& InLocation, FGenericRealCoordinate& OutRealCoordinate);

	/** 在两个真实坐标系统之间转换，不经过 UE 平面偏移，只通过 ECEF 作为中间桥。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool RealCoordinateToRealCoordinate(const UObject* WorldContextObject, const FGenericRealCoordinate& InRealCoordinate, FGameplayTag TargetCoordinateSystem, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutRealCoordinate);

	/** 便捷函数：将经纬高真实坐标转换为 UE 世界坐标，避免蓝图手动填写泛化坐标结构。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool GeographicCoordinateToUnreal(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FVector& OutLocation);

	/** 便捷函数：将投影平面真实坐标转换为 UE 世界坐标，输入 X/Y/Z 均为厘米。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool ProjectedCoordinateToUnreal(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericProjectedCoordinate& InCoordinate, FVector& OutLocation);

	/** 便捷函数：将 UE 世界坐标转换为目标坐标系下的经纬高坐标。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool UnrealToGeographicCoordinate(const UObject* WorldContextObject, FGameplayTag TargetCoordinateSystem, const FVector& InLocation, FGenericCoordinate& OutCoordinate);

	/** 便捷函数：将 UE 世界坐标转换为目标坐标系下的投影平面坐标，输出 X/Y/Z 均为厘米。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool UnrealToProjectedCoordinate(const UObject* WorldContextObject, FGameplayTag TargetCoordinateSystem, const FVector& InLocation, FGenericProjectedCoordinate& OutCoordinate);

	/** 便捷函数：经纬高真实坐标转目标经纬高真实坐标。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool GeographicCoordinateToGeographicCoordinate(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericCoordinate& OutCoordinate);

	/** 便捷函数：经纬高真实坐标转目标投影平面真实坐标。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool GeographicCoordinateToProjectedCoordinate(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericProjectedCoordinate& OutCoordinate);

	/** 便捷函数：投影平面真实坐标转目标经纬高真实坐标。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool ProjectedCoordinateToGeographicCoordinate(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericProjectedCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericCoordinate& OutCoordinate);

	/** 便捷函数：投影平面真实坐标转目标投影平面真实坐标。 */
	UFUNCTION(BlueprintCallable, Category="Real Georeferencing", meta=(WorldContext="WorldContextObject"))
	static REALGEOREFERENCINGFRAMEWORK_API bool ProjectedCoordinateToProjectedCoordinate(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericProjectedCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericProjectedCoordinate& OutCoordinate);
};
