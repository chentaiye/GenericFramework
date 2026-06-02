// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/PawnReassessmentInterface.h"
#include "Movement/ThirdPersonPawnInputMovement.h"
#include "SmartCityPawnInputMovement.generated.h"

/** 为 SmartCityPawn 提供输入移动和聚焦重评估逻辑，视角同步由 SyncCameraViewComponent 承担。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class USmartCityPawnInputMovement : public UThirdPersonPawnInputMovement, public IPawnReassessmentInterface
{
	GENERATED_BODY()

public:
	/** 初始化 SmartCityPawn 输入移动策略默认状态。 */
	GENERICGAMEPLAYSYSTEM_API USmartCityPawnInputMovement();

	/* IPawnReassessmentInterface */
public:
	GENERICGAMEPLAYSYSTEM_API virtual bool ReassessmentFocus_Implementation() override;
};
