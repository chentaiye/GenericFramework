// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CompassActor.generated.h"

class UTextRenderComponent;
class UArrowComponent;

/** 作为CompassActor能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(NotBlueprintable, HideCategories=(Object,Collision,Physics,Networking,Input,LevelInstance,Cooking,LOD,HLOD,Replication), MinimalAPI)
class ACompassActor : public AActor
{
	GENERATED_BODY()

public:
	/** 初始化Compass Actor的默认运行状态。 */
	ACompassActor();
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	/** 获取玩家Forward Angle。 */
	UFUNCTION(BlueprintPure, Category="Compass Actor", meta=(WorldContext="WorldContextObject"))
	static GENERICGAMEPLAYSYSTEM_API bool GetPlayerForwardAngle(const UObject* WorldContextObject, int32 PlayerIndex, float& OutAngle);

public:
	/** 记录根场景组件。 */
	UPROPERTY()
	USceneComponent* SceneComponent=nullptr;

	/** 记录Arrow组件N。 */
	UPROPERTY()
	UArrowComponent* ArrowComponentN=nullptr;

	/** 记录文本RenderN。 */
	UPROPERTY()
	UTextRenderComponent* TextRenderN=nullptr;

	/** 记录Arrow组件S。 */
	UPROPERTY()
	UArrowComponent* ArrowComponentS=nullptr;

	/** 记录文本RenderS。 */
	UPROPERTY()
	UTextRenderComponent* TextRenderS=nullptr;

	/** 记录Arrow组件E。 */
	UPROPERTY()
	UArrowComponent* ArrowComponentE=nullptr;

	/** 记录文本RenderE。 */
	UPROPERTY()
	UTextRenderComponent* TextRenderE=nullptr;

	/** 记录Arrow组件W。 */
	UPROPERTY()
	UArrowComponent* ArrowComponentW=nullptr;

	/** 记录文本RenderW。 */
	UPROPERTY()
	UTextRenderComponent* TextRenderW=nullptr;

private:
	/** 执行文本。 */
	void SetupComponent(UArrowComponent*& InArrow, FName InArrowName, UTextRenderComponent*& InTextRender, FName InTextRenderName, float InArrowYaw = 0.f, FColor InArrowColor = FColor(255, 0, 0, 255), FString InText = TEXT("N"));

public:
	/** 记录Angle。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Compass Actor", meta=(ClampMin=-180.f, UIMin=-180.f, ClampMax=180.f, UIMax=180.f))
	float Angle=0.f;

public:
	/** 获取Direction North。 */
	UFUNCTION(BlueprintPure, Category="Compass Actor")
	GENERICGAMEPLAYSYSTEM_API FVector GetDirectionNorth() const;

	/** 获取Direction East。 */
	UFUNCTION(BlueprintPure, Category="Compass Actor")
	GENERICGAMEPLAYSYSTEM_API FVector GetDirectionEast() const;
};
