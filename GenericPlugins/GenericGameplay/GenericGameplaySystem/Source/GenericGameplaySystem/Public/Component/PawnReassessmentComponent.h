// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interface/PawnReassessmentInterface.h"
#include "PawnReassessmentComponent.generated.h"

/** 封装Pawn Reassessment设置。 */
USTRUCT(BlueprintType)
struct GENERICGAMEPLAYSYSTEM_API FPawnReassessmentSettings
{
	GENERATED_BODY()

public:
	/** 配置Trace渠道。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ThirdPerson Pawn")
	TEnumAsByte<ECollisionChannel> TraceChannel=ECC_Pawn;

	/** 配置焦点内边距。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ThirdPerson Pawn", meta=(ClampMin=0, UIMin=0))
	float FocusPadding=20.f;

	/** 配置最小Distance。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ThirdPerson Pawn", meta=(ClampMin=0, UIMin=0))
	float MinDistance=50.f;
};

/** 定义PawnReassessment组件能力契约，供模块在不同实现之间解耦调用。 */
UCLASS(MinimalAPI, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UPawnReassessmentComponent : public UActorComponent, public IPawnReassessmentInterface
{
	GENERATED_BODY()

public:
	GENERICGAMEPLAYSYSTEM_API virtual bool ReassessmentFocus_Implementation() override;

public:
	/** 记录Reassessment设置。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ThirdPerson Pawn|Camera")
	FPawnReassessmentSettings ReassessmentSettings;
};
