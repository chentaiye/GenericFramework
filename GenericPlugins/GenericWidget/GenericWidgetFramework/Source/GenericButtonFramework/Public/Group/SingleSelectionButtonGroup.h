// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericButtonGroup.h"
#include "ButtonType.h"
#include "GameplayTagContainer.h"
#include "SingleSelectionButtonGroup.generated.h"

/** Manages a button group where at most one selectable button can be selected. */
UCLASS(MinimalAPI)
class USingleSelectionButtonGroup : public UGenericButtonGroup
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API UGenericButtonWidget* GetPreviousSelectedButton() const;

	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API UGenericButtonWidget* GetCurrentSelectedButton() const;

	/** Selects a button managed by this single selection group. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool SetSelectedButton(UGenericButtonWidget* InButton);

	/** Selects a button by its group index. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool SetSelectedButtonByIndex(int32 InIndex);

	/** Selects a button by its GameplayUI.Button tag. */
	UFUNCTION(BlueprintCallable, Category="Button|Group", meta=(Categories="GameplayUI.Button"))
	GENERICBUTTONFRAMEWORK_API bool SetSelectedButtonByTag(FGameplayTag InButtonTag);

	/** Returns the current selected button tag, or an empty tag when nothing is selected. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API FGameplayTag GetSelectedButtonTag() const;

	GENERICBUTTONFRAMEWORK_API virtual EGenericButtonGroupSelectionMode GetSelectionMode() const override;

	/** Selects the previous button without wrapping at the first button. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool SelectPreviousButton();

	/** Selects the next button without wrapping at the last button. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool SelectNextButton();

	/** Deselects the current selected button. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API void DeselectAll();

protected:
	GENERICBUTTONFRAMEWORK_API virtual void HandleButtonRemoved(UGenericButtonWidget* InButton) override;
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonSelectionChanged(UGenericButtonWidget* InButton, bool bSelected) override;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonWidget> PreviousSelectedButton = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonWidget> CurrentSelectedButton = nullptr;
};
