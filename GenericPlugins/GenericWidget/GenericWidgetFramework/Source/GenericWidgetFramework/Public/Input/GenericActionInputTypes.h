// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "GenericActionInputTypes.generated.h"

UENUM(BlueprintType)
enum class EGenericActionTriggerEvent : uint8
{
	Started,
	Ongoing,
	Triggered,
	Completed,
	Canceled
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FGenericActionInputEventData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Action", meta=(Categories="GameplayUI.Action"))
	FGameplayTag ActionTag;

	UPROPERTY(BlueprintReadOnly, Category="Action")
	EGenericActionTriggerEvent TriggerEvent = EGenericActionTriggerEvent::Started;

	UPROPERTY(BlueprintReadOnly, Category="Action")
	FKey Key;

	UPROPERTY(BlueprintReadOnly, Category="Action")
	float ActionValue = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category="Action")
	float ElapsedTime = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category="Action")
	float TriggeredTime = 0.0f;
};
