// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "WorldWidgetType.generated.h"

class APlayerController;
class UWorldWidgetComponent;

USTRUCT(BlueprintType)
struct GENERICWORLDWIDGETFRAMEWORK_API FOnWorldWidgetRegisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="World Widget Registered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="World Widget Registered Message")
	TObjectPtr<UWorldWidgetComponent> WorldWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICWORLDWIDGETFRAMEWORK_API FOnWorldWidgetUnregisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="World Widget Unregistered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="World Widget Unregistered Message")
	TObjectPtr<UWorldWidgetComponent> WorldWidget = nullptr;
};

GENERICWORLDWIDGETFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnWorldWidget);
GENERICWORLDWIDGETFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnWorldWidgetRegister);
GENERICWORLDWIDGETFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnWorldWidgetUnRegister);
