// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericCoordinateConverter.h"
#include "RealGeoreferencingType.h"
#include "Templates/SubclassOf.h"
#include "WorldSettings/GenericWorldSettings.h"
#include "RealGeoreferencingWorldSettings.generated.h"

/** 当前世界的真实地理参考设置，游戏开始后应用到 RealGeoreferencingSubsystem。 */
UCLASS(MinimalAPI)
class URealGeoreferencingWorldSettings : public UGenericWorldSettings
{
	GENERATED_BODY()

public:
	/** 初始化世界地理参考默认值，并把内置坐标转换器加入可注册列表。 */
	REALGEOREFERENCINGFRAMEWORK_API URealGeoreferencingWorldSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** 坐标缩放比例，运行时小于等于 0 时会钳制为 0.000001，避免 UE/投影坐标互转时除零。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing", meta=(ClampMin="0.000001", UIMin="0.000001"))
	double CoordinateScale = 1.0;

	/** UE X/Y 原点对应的真实地理中心点，经纬度为角度，高度为厘米。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	FGenericCoordinate CenterCoordinate;

	/** 中心点使用的真实坐标系统，避免强制所有业务中心点都写成 WGS84。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	FGameplayTag CenterCoordinateSystem = TAG_GameplayGeoreferencing_CoordinateSystem_WGS84;

	/** UE 平面世界使用的投影 CRS 设置，X/Y 来自投影东西向和南北向，单位在模块中统一为厘米。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	FGenericProjectionSettings UnrealProjectionSettings;

	/** 当前世界默认激活的坐标转换策略；为空时只注册可用转换器，不设置默认激活项。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	TSubclassOf<UGenericCoordinateConverter> GenericCoordinateConverterClass;

	/** 当前世界可注册的坐标转换策略列表，默认包含模块内置转换器。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Georeferencing")
	TArray<TSubclassOf<UGenericCoordinateConverter>> GenericCoordinateConverterClasses;

protected:
#if WITH_EDITOR
	virtual FName GetSettingsCategory_Implementation() const override;
#endif
	virtual void OnWorldSettingsBeginPlay_Implementation(UWorld* World) override;
};
