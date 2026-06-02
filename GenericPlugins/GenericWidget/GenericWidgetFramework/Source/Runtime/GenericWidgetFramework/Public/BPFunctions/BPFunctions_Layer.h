// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Layer.generated.h"

class APlayerController;
class UGenericLayer;
class UGenericLayerSubsystem;

/** 提供UI层级系统的蓝图访问函数。 */
UCLASS(MinimalAPI)
class UBPFunctions_Layer : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 获取本地玩家层级子系统。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Layer|Subsystem")
	static GENERICWIDGETFRAMEWORK_API UGenericLayerSubsystem* GetGenericLayerSubsystem(APlayerController* PlayerController);

	/** 获取指定标签对应的UI层。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Layer|Layer", meta=(Categories="GameplayUI.Layer"))
	static GENERICWIDGETFRAMEWORK_API UGenericLayer* GetLayer(APlayerController* PlayerController, FGameplayTag InLayerTag);

	/** 检查指定标签是否存在有效UI层。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Layer|Layer", meta=(Categories="GameplayUI.Layer"))
	static GENERICWIDGETFRAMEWORK_API bool HasLayer(APlayerController* PlayerController, FGameplayTag InLayerTag);

	/** 设置指定标签对应UI层的可见性。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Layer|Layer", meta=(Categories="GameplayUI.Layer"))
	static GENERICWIDGETFRAMEWORK_API bool SetLayerVisibility(APlayerController* PlayerController, FGameplayTag InLayerTag, ESlateVisibility InVisibility);

	/** 获取所有仍然有效的UI层。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Layer|Layer")
	static GENERICWIDGETFRAMEWORK_API TArray<UGenericLayer*> GetAllLayers(APlayerController* PlayerController);
};
