// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericCoordinateConverter.h"
#include "RealGeoreferencingType.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "Templates/SubclassOf.h"
#include "RealGeoreferencingSubsystem.generated.h"

class URealGeoreferencingWorldSettings;

/** 真实地理参考运行时子系统，维护 Converter 注册表并提供坐标转换入口。 */
UCLASS(MinimalAPI)
class URealGeoreferencingSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** 从任意 WorldContext 查找当前 GameInstance 上的地理参考子系统。 */
	static REALGEOREFERENCINGFRAMEWORK_API URealGeoreferencingSubsystem* Get(const UObject* WorldContextObject);

	/** 应用世界地理参考设置，注册转换器并初始化 UE 平面投影中心。 */
	REALGEOREFERENCINGFRAMEWORK_API void ApplyWorldSettings(const URealGeoreferencingWorldSettings* Settings);

	/** 注册单个坐标转换器类，相同坐标系统后注册者覆盖旧实例。 */
	REALGEOREFERENCINGFRAMEWORK_API bool RegisterConverter(TSubclassOf<UGenericCoordinateConverter> ConverterClass);

	/** 批量注册坐标转换器类，忽略无效或抽象类。 */
	REALGEOREFERENCINGFRAMEWORK_API void RegisterConverters(const TArray<TSubclassOf<UGenericCoordinateConverter>>& ConverterClasses);

	/** 注销指定坐标系统的转换器。 */
	REALGEOREFERENCINGFRAMEWORK_API bool UnregisterConverter(FGameplayTag CoordinateSystem);

	/** 查找指定坐标系统的已注册转换器。 */
	REALGEOREFERENCINGFRAMEWORK_API UGenericCoordinateConverter* GetConverter(FGameplayTag CoordinateSystem) const;

	/** 获取当前激活转换器；为空表示世界设置未指定默认 Converter。 */
	REALGEOREFERENCINGFRAMEWORK_API UGenericCoordinateConverter* GetActiveConverter() const;

	/** 注册并激活指定转换器类。 */
	REALGEOREFERENCINGFRAMEWORK_API bool SetActiveConverter(TSubclassOf<UGenericCoordinateConverter> ConverterClass);

	/** 获取当前激活坐标系统。 */
	REALGEOREFERENCINGFRAMEWORK_API FGameplayTag GetActiveCoordinateSystem() const;

	/** 激活指定坐标系统的已注册转换器。 */
	REALGEOREFERENCINGFRAMEWORK_API bool SetActiveCoordinateSystem(FGameplayTag CoordinateSystem);

	/** 获取运行时安全钳制后的坐标缩放比例。 */
	REALGEOREFERENCINGFRAMEWORK_API double GetActiveCoordinateScale() const;

	/** 获取中心点坐标系统。 */
	REALGEOREFERENCINGFRAMEWORK_API FGameplayTag GetActiveCenterCoordinateSystem() const;

	/** 获取中心点经纬高坐标。 */
	REALGEOREFERENCINGFRAMEWORK_API const FGenericCoordinate& GetActiveCenterCoordinate() const;

	/** 获取 UE 平面世界投影设置。 */
	REALGEOREFERENCINGFRAMEWORK_API const FGenericProjectionSettings& GetActiveUnrealProjectionSettings() const;

	/** 将任意真实坐标转换为 UE 世界坐标，UE X/Y 以中心投影点为原点，Z 为海拔厘米。 */
	REALGEOREFERENCINGFRAMEWORK_API bool RealCoordinateToUnreal(const FGenericRealCoordinate& InCoordinate, FVector& OutLocation) const;

	/** 将 UE 世界坐标转换为目标真实坐标系统和格式。 */
	REALGEOREFERENCINGFRAMEWORK_API bool UnrealToRealCoordinate(FGameplayTag TargetCoordinateSystem, EGenericCoordinateFormat TargetFormat, const FVector& InLocation, FGenericRealCoordinate& OutCoordinate) const;

	/** 通过 ECEF 桥接，将一个真实坐标系统转换到另一个真实坐标系统。 */
	REALGEOREFERENCINGFRAMEWORK_API bool RealCoordinateToRealCoordinate(const FGenericRealCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const;

	/** 兼容旧接口，将地理格式真实坐标转换为 UE 世界坐标。 */
	REALGEOREFERENCINGFRAMEWORK_API bool RealCoordinateToUnreal(FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FVector& OutLocation) const;

	/** 兼容旧接口，将 UE 世界坐标转换为目标地理坐标。 */
	REALGEOREFERENCINGFRAMEWORK_API bool UnrealToRealCoordinate(FGameplayTag TargetCoordinateSystem, const FVector& InLocation, FGenericCoordinate& OutCoordinate) const;

	/** 兼容旧接口，在两个地理坐标系统之间转换。 */
	REALGEOREFERENCINGFRAMEWORK_API bool RealCoordinateToRealCoordinate(FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericCoordinate& OutCoordinate) const;

private:
	/** 运行时已注册的坐标转换器实例表。 */
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UGenericCoordinateConverter>> RegisteredConverters;

	/** 当前激活转换器实例。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericCoordinateConverter> ActiveConverter = nullptr;

	/** 当前激活坐标系统。 */
	FGameplayTag ActiveCoordinateSystem;

	/** 运行时安全钳制后的坐标缩放比例。 */
	double ActiveCoordinateScale = 1.0;

	/** 中心点坐标系统。 */
	FGameplayTag ActiveCenterCoordinateSystem = TAG_GameplayGeoreferencing_CoordinateSystem_WGS84;

	/** 中心点经纬高坐标。 */
	FGenericCoordinate ActiveCenterCoordinate;

	/** UE 平面世界使用的投影设置。 */
	FGenericProjectionSettings ActiveUnrealProjectionSettings;

	/** 中心点在 UE 投影 CRS 下的投影坐标，厘米单位。 */
	FGenericProjectedCoordinate ActiveUnrealProjectionCenter;

	/** 是否已经成功根据中心点和投影设置计算出 UE 投影中心。 */
	bool bHasValidUnrealProjectionCenter = false;
};
