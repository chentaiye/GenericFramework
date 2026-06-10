// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SlateWrapperTypes.h"
#include "Interface/GenericRouteInterface.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "UObject/ScriptInterface.h"
#include "GenericWidgetSubsystem.generated.h"

class UGenericWidget;
class APlayerController;

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnWidgetRegisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Widget Registered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Widget Registered Message")
	FGameplayTag SlotTag;

	UPROPERTY(BlueprintReadOnly, Category="Widget Registered Message")
	TObjectPtr<UGenericWidget> Widget = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Widget Registered Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnWidgetUnregisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Widget Unregistered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Widget Unregistered Message")
	FGameplayTag SlotTag;

	UPROPERTY(BlueprintReadOnly, Category="Widget Unregistered Message")
	TObjectPtr<UGenericWidget> Widget = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Widget Unregistered Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnWidgetRegisteredToOwnerMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Widget Registered To Owner Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Widget Registered To Owner Message")
	FGameplayTag SlotTag;

	UPROPERTY(BlueprintReadOnly, Category="Widget Registered To Owner Message")
	TObjectPtr<UGenericWidget> Widget = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Widget Registered To Owner Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnWidgetUnregisteredFromOwnerMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Widget Unregistered From Owner Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Widget Unregistered From Owner Message")
	FGameplayTag SlotTag;

	UPROPERTY(BlueprintReadOnly, Category="Widget Unregistered From Owner Message")
	TObjectPtr<UGenericWidget> Widget = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Widget Unregistered From Owner Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

/** 保存通用 UI流程中的通用Registered控件数据，供运行时传递和蓝图访问。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FGenericRegisteredWidget
{
	GENERATED_BODY()

	/** 持有控件实例，供通用 UI运行时复用。 */
	UPROPERTY()
	TObjectPtr<UGenericWidget> Widget = nullptr;
};

/** 封装本地玩家业务UI控件的创建、槽位登记、查询和移除能力。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FGenericOwnerRegisteredWidget
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UGenericWidget> Widget = nullptr;

	UPROPERTY()
	TScriptInterface<IGenericRouteInterface> Owner;
};

UCLASS(MinimalAPI)
class UGenericWidgetSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API static UGenericWidgetSubsystem* Get(const APlayerController* PlayerController);
	GENERICWIDGETFRAMEWORK_API static UGenericWidgetSubsystem* Get(const ULocalPlayer* LocalPlayer);

public:
	/** 登记已存在的业务UI控件并放入指定槽位。 */
	GENERICWIDGETFRAMEWORK_API bool RegisterWidget(UGenericWidget* InWidget, FGameplayTag InSlotTag, ESlateVisibility InVisibility = ESlateVisibility::SelfHitTestInvisible);

	GENERICWIDGETFRAMEWORK_API bool RegisterWidget(UGenericWidget* InWidget, TScriptInterface<IGenericRouteInterface> InOwner, ESlateVisibility InVisibility = ESlateVisibility::SelfHitTestInvisible);

	/** 创建指定类型的业务UI控件并放入指定槽位。 */
	GENERICWIDGETFRAMEWORK_API UGenericWidget* RegisterWidget(TSubclassOf<UGenericWidget> InWidgetClass, FGameplayTag InSlotTag, ESlateVisibility InVisibility = ESlateVisibility::SelfHitTestInvisible);

	/** 注销指定业务UI控件的槽位登记。 */
	GENERICWIDGETFRAMEWORK_API bool UnregisterWidget(UGenericWidget* InWidget, bool bClearSlot = true);

	/** 注销指定槽位标签对应的业务UI控件登记。 */
	GENERICWIDGETFRAMEWORK_API bool UnregisterWidgetBySlotTag(FGameplayTag InSlotTag, bool bClearSlot = true);

	/** 获取指定槽位标签当前登记的业务UI控件。 */
	GENERICWIDGETFRAMEWORK_API UGenericWidget* GetWidget(FGameplayTag InSlotTag) const;

	/** 检查指定槽位标签是否存在有效业务UI控件登记。 */
	GENERICWIDGETFRAMEWORK_API bool HasWidget(FGameplayTag InSlotTag) const;

	/** 获取所有仍然有效的业务UI控件登记。 */
	GENERICWIDGETFRAMEWORK_API TArray<UGenericWidget*> GetAllWidgets() const;

public:
	GENERICWIDGETFRAMEWORK_API virtual void Deinitialize() override;

private:
	/** 检查业务UI控件是否属于当前本地玩家。 */
	bool IsWidgetOwnedByThisSubsystem(const UGenericWidget* InWidget) const;

	/** 检查槽位标签是否可用于业务UI控件登记。 */
	bool IsValidSlotTag(FGameplayTag InSlotTag) const;

	bool IsValidOwnerRoute(TScriptInterface<IGenericRouteInterface> InOwner) const;
	int32 FindOwnerRegisteredWidgetIndex(const UGenericWidget* InWidget) const;
	FGameplayTag FindRegisteredSlotTag(const UGenericWidget* InWidget) const;

	/** 执行槽位标签对应的业务UI控件注销流程。 */
	bool UnregisterWidgetInternal(FGameplayTag InSlotTag, bool bClearSlot);
	bool UnregisterOwnerWidgetInternal(int32 InOwnerWidgetIndex);

private:
	/** 维护RegisteredWidgets映射。 */
	UPROPERTY()
	TMap<FGameplayTag, FGenericRegisteredWidget> RegisteredWidgets;

	UPROPERTY()
	TArray<FGenericOwnerRegisteredWidget> OwnerRegisteredWidgets;
};
