// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SlateWrapperTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Widget.generated.h"

class UGenericWidget;
class UGenericWidgetSubsystem;
class APlayerController;

/** 提供业务UI控件系统的蓝图访问函数。 */
UCLASS(MinimalAPI)
class UBPFunctions_Widget : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 获取本地玩家业务UI控件子系统。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Widget|Subsystem")
	static GENERICWIDGETFRAMEWORK_API UGenericWidgetSubsystem* GetGenericWidgetSubsystem(APlayerController* PlayerController);

	/** 登记已存在的业务UI控件并放入指定槽位。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Widget|Widget", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API bool RegisterWidget(APlayerController* PlayerController, UGenericWidget* InWidget, FGameplayTag InSlotTag, ESlateVisibility InVisibility = ESlateVisibility::SelfHitTestInvisible);

	/** 创建指定类型的业务UI控件并放入指定槽位。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Widget|Widget", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API UGenericWidget* RegisterWidgetByClass(APlayerController* PlayerController, TSubclassOf<UGenericWidget> InWidgetClass, FGameplayTag InSlotTag, ESlateVisibility InVisibility = ESlateVisibility::SelfHitTestInvisible);

	/** 注销指定业务UI控件的槽位登记。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Widget|Widget")
	static GENERICWIDGETFRAMEWORK_API bool UnregisterWidget(APlayerController* PlayerController, UGenericWidget* InWidget, bool bClearSlot = true);

	/** 注销指定槽位标签对应的业务UI控件登记。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Widget|Widget", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API bool UnregisterWidgetBySlotTag(APlayerController* PlayerController, FGameplayTag InSlotTag, bool bClearSlot = true);

	/** 获取指定槽位标签当前登记的业务UI控件。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Widget|Widget", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API UGenericWidget* GetWidget(APlayerController* PlayerController, FGameplayTag InSlotTag);

	/** 检查指定槽位标签是否存在有效业务UI控件登记。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Widget|Widget", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API bool HasWidget(APlayerController* PlayerController, FGameplayTag InSlotTag);

	/** 获取所有仍然有效的业务UI控件登记。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Widget|Widget")
	static GENERICWIDGETFRAMEWORK_API TArray<UGenericWidget*> GetAllWidgets(APlayerController* PlayerController);
};
