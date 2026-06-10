// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldWidgetPoint.generated.h"

class UWorldWidgetComponent;

/** Actor point that owns one WorldWidgetComponent. */
UCLASS(MinimalAPI)
class AWorldWidgetPoint : public AActor
{
	GENERATED_BODY()

public:
	GENERICWORLDWIDGETFRAMEWORK_API AWorldWidgetPoint(const FObjectInitializer& ObjectInitializer);

public:
	/** WorldWidget component used by this point actor. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Default)
	TObjectPtr<UWorldWidgetComponent> WorldWidgetComponent = nullptr;
};
