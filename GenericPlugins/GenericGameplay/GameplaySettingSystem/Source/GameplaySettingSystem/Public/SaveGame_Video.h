// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericSaveGame.h"
#include "SaveGame_Video.generated.h"

/** 作为存档系统保存游戏Video能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI)
class USaveGame_Video : public UGenericSaveGame
{
	GENERATED_BODY()

public:
	/** 记录ScreenResolution。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	FIntPoint ScreenResolution=FIntPoint::ZeroValue;

	/** 记录Fullscreen模式。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 FullscreenMode=0;

	/** 标记VSyncEnabled状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	bool bVSyncEnabled=false;

	/** 启用Dynamic Resolution。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	bool bUseDynamicResolution=false;

	/** 记录Frame速率Limit。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	float FrameRateLimit=0.0f;

	/** 记录ResolutionScale值。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	float ResolutionScaleValue=100.0f;

	/** 记录OverallScalability关卡。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 OverallScalabilityLevel=0;

	/** 记录视图DistanceQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 ViewDistanceQuality=0;

	/** 记录反AliasingQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 AntiAliasingQuality=0;

	/** 记录ShadowQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 ShadowQuality=0;

	/** 记录全局IlluminationQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 GlobalIlluminationQuality=0;

	/** 记录ReflectionQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 ReflectionQuality=0;

	/** 记录PostProcessingQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 PostProcessingQuality=0;

	/** 记录TextureQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 TextureQuality=0;

	/** 记录VisualEffectQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 VisualEffectQuality=0;

	/** 记录FoliageQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 FoliageQuality=0;

	/** 记录ShadingQuality。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 ShadingQuality=0;

	/** 启用HDR显示输出。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	bool bUseHDRDisplayOutput=false;

	/** 记录HDRDisplay输出Nits。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Gameplay Setting|Video")
	int32 HDRDisplayOutputNits=1000;
};
