// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Layout.generated.h"

class APlayerController;
class UGenericLayout;
class UGenericLayoutSubsystem;

/** Blueprint accessors for the Generic Layout subsystem. */
UCLASS(MinimalAPI)
class UBPFunctions_Layout : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="BPFunctions_Layout|Subsystem")
	static GENERICWIDGETFRAMEWORK_API UGenericLayoutSubsystem* GetGenericLayoutSubsystem(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="BPFunctions_Layout|Layout")
	static GENERICWIDGETFRAMEWORK_API bool RegisterLayout(APlayerController* PlayerController, UGenericLayout* InLayout);

	UFUNCTION(BlueprintCallable, Category="BPFunctions_Layout|Layout", meta=(DeterminesOutputType="InLayoutClass"))
	static GENERICWIDGETFRAMEWORK_API UGenericLayout* RegisterLayoutByClass(APlayerController* PlayerController, TSubclassOf<UGenericLayout> InLayoutClass, bool bAddToScreen = true, ESlateVisibility InVisibility = ESlateVisibility::SelfHitTestInvisible, int32 ZOrder = 0);

	UFUNCTION(BlueprintCallable, Category="BPFunctions_Layout|Layout")
	static GENERICWIDGETFRAMEWORK_API bool UnregisterLayout(APlayerController* PlayerController, UGenericLayout* InLayout);

	UFUNCTION(BlueprintPure, Category="BPFunctions_Layout|Layout")
	static GENERICWIDGETFRAMEWORK_API UGenericLayout* GetLayout(APlayerController* PlayerController);

	UFUNCTION(BlueprintPure, Category="BPFunctions_Layout|Layout")
	static GENERICWIDGETFRAMEWORK_API bool HasLayout(APlayerController* PlayerController);
};
