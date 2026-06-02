// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SlateWrapperTypes.h"
#include "Interface/GenericRouteInterface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/ScriptInterface.h"
#include "BPFunctions_Slot.generated.h"

class UGenericSlotSubsystem;
class UGameplayTagSlot;
class APlayerController;
class UWidget;

/** 提供Gameplay标签槽位系统的蓝图访问函数。 */
UCLASS(MinimalAPI)
class UBPFunctions_Slot : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 获取本地玩家槽位子系统。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slot|Subsystem")
	static GENERICWIDGETFRAMEWORK_API UGenericSlotSubsystem* GetGenericSlotSubsystem(APlayerController* PlayerController);

	/** 注册已存在的Gameplay标签槽位。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Slot|Slot")
	static GENERICWIDGETFRAMEWORK_API bool RegisterSlot(APlayerController* PlayerController, UGameplayTagSlot* InSlot, TScriptInterface<IGenericRouteInterface> InOwner);

	/** 注销指定Gameplay标签槽位。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Slot|Slot")
	static GENERICWIDGETFRAMEWORK_API bool UnregisterSlot(APlayerController* PlayerController, UGameplayTagSlot* InSlot);

	/** 注销指定标签对应的Gameplay标签槽位。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Slot|Slot", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API bool UnregisterSlotByTag(APlayerController* PlayerController, FGameplayTag InSlotTag);

	/** 获取指定标签对应的Gameplay标签槽位。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slot|Slot", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API UGameplayTagSlot* GetSlot(APlayerController* PlayerController, FGameplayTag InSlotTag);

	/** 检查指定标签是否存在有效Gameplay标签槽位。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slot|Slot", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API bool HasSlot(APlayerController* PlayerController, FGameplayTag InSlotTag);

	/** 设置指定标签槽位的Slate可视性。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Slot|Slot", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API bool SetSlotVisibility(APlayerController* PlayerController, FGameplayTag InSlotTag, ESlateVisibility InVisibility);

	/** 设置指定标签槽位的内容控件。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Slot|Slot", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API bool SetSlotContent(APlayerController* PlayerController, FGameplayTag InSlotTag, UWidget* InContent);

	/** 获取指定标签槽位当前承载的内容控件。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slot|Slot", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API UWidget* GetSlotContent(APlayerController* PlayerController, FGameplayTag InSlotTag);

	/** 清空指定标签槽位当前承载的内容控件。 */
	UFUNCTION(BlueprintCallable, Category="BPFunctions_Slot|Slot", meta=(Categories="GameplayUI.Slot"))
	static GENERICWIDGETFRAMEWORK_API bool ClearSlotContent(APlayerController* PlayerController, FGameplayTag InSlotTag);

	/** 获取所有仍然有效的Gameplay标签槽位。 */
	UFUNCTION(BlueprintPure, Category="BPFunctions_Slot|Slot")
	static GENERICWIDGETFRAMEWORK_API TArray<UGameplayTagSlot*> GetAllSlots(APlayerController* PlayerController);
};
