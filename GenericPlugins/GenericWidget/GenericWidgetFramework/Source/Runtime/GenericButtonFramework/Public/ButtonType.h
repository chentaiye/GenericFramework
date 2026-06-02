// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "ButtonType.generated.h"

class APlayerController;
class UGenericButtonWidget;

/** 表示通用按钮在运行时可被菜单、按钮组或消息系统统一分发的交互事件。 */
UENUM(BlueprintType)
enum class EGenericButtonEvent : uint8
{
	/** 按钮按下时触发。 */
	OnPressed,

	/** 按钮释放时触发。 */
	OnReleased,

	/** 指针悬停到按钮上时触发。 */
	OnHovered,

	/** 指针离开按钮时触发。 */
	OnUnhovered,

	/** 按钮完成一次点击时触发。 */
	OnClicked,

	/** 按钮完成一次双击时触发。 */
	OnDoubleClicked,

	/** 按钮进入选中状态时触发。 */
	OnSelected,

	/** 按钮退出选中状态时触发。 */
	OnDeSelected
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonEnabledMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Enabled Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Enabled Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Enabled Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonDisabledMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Disabled Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Disabled Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Disabled Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonPressedMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Pressed Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Pressed Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Pressed Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonReleasedMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Released Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Released Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Released Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonHoveredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Hovered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Hovered Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Hovered Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonUnhoveredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Unhovered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Unhovered Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Unhovered Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonClickedMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Clicked Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Clicked Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Clicked Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonDoubleClickedMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Double Clicked Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Double Clicked Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Double Clicked Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonSelectionChangedMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Selection Changed Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Selection Changed Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Selection Changed Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Selection Changed Message")
	bool bSelected = false;
};

USTRUCT(BlueprintType)
struct GENERICBUTTONFRAMEWORK_API FOnButtonStyleChangedMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Button Style Changed Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Button Style Changed Message")
	FGameplayTag ButtonTag;

	UPROPERTY(BlueprintReadOnly, Category="Button Style Changed Message")
	TObjectPtr<UGenericButtonWidget> ButtonWidget = nullptr;
};

GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Button);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonEnabled);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonDisabled);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonPressed);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonReleased);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonHovered);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonUnhovered);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonClicked);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonDoubleClicked);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonSelectionChanged);
GENERICBUTTONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnButtonStyleChanged);
