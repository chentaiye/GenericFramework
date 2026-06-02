/* Fill out your copyright notice in the Description page of Project Settings. */
#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "GameplayType.generated.h"

GENERICGAMEPLAYSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogGameplay, Log, All);

USTRUCT(BlueprintType)
struct GENERICGAMEPLAYSYSTEM_API FPawnAdaptiveRateSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement", meta=(ClampMin=0, UIMin=0))
	FVector2D ArmLengthRange = FVector2D(300.f, 12000.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement", meta=(ClampMin=0, UIMin=0))
	FVector2D ArmLengthMultiplierRange = FVector2D(1.f, 2.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement", meta=(ClampMin=0, UIMin=0))
	FVector2D PitchMultiplierRange = FVector2D(1.f, 1.15f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement", meta=(ClampMin=0.1, UIMin=0.1))
	float ArmLengthExponent = 1.f;

	float Evaluate(float InArmLength, float InPitch) const
	{
		const float SafeMinArmLength = FMath::Min(ArmLengthRange.X, ArmLengthRange.Y);
		const float SafeMaxArmLength = FMath::Max(ArmLengthRange.X + KINDA_SMALL_NUMBER, ArmLengthRange.Y);
		const float ArmLengthAlpha = FMath::Pow(
			FMath::GetMappedRangeValueClamped(FVector2D(SafeMinArmLength, SafeMaxArmLength), FVector2D(0.f, 1.f), FMath::Max(InArmLength, 0.f)),
			ArmLengthExponent
		);
		const float ArmLengthMultiplier = FMath::Lerp(ArmLengthMultiplierRange.X, ArmLengthMultiplierRange.Y, ArmLengthAlpha);
		const float PitchAlpha = FMath::Clamp(FMath::Abs(InPitch) / 90.f, 0.f, 1.f);
		const float PitchMultiplier = FMath::Lerp(PitchMultiplierRange.X, PitchMultiplierRange.Y, PitchAlpha);
		return FMath::Max(0.f, ArmLengthMultiplier * PitchMultiplier);
	}
};

USTRUCT(BlueprintType)
struct GENERICGAMEPLAYSYSTEM_API FPawnInputSmoothingSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement", meta=(ClampMin=0, UIMin=0))
	float MovementInterpSpeed = 8.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement", meta=(ClampMin=0, UIMin=0))
	float RotationInterpSpeed = 12.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement", meta=(ClampMin=0, UIMin=0))
	float InputDeadZone = 0.01f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Input Movement", meta=(ClampMin=1, UIMin=1))
	float ReferenceFrameRate = 60.f;
};

GENERICGAMEPLAYSYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayInput_Movement);
GENERICGAMEPLAYSYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayInput_Movement_Pawn);
GENERICGAMEPLAYSYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayInput_Movement_ThirdPersonPawn);
GENERICGAMEPLAYSYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayInput_Movement_SmartCityPawn);
GENERICGAMEPLAYSYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayInput_Movement_GenericCharacter);
GENERICGAMEPLAYSYSTEM_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayInput_Movement_ThirdPersonCharacter);
