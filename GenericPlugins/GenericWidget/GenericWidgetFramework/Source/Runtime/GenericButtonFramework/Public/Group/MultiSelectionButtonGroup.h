// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericButtonGroup.h"
#include "MultiSelectionButtonGroup.generated.h"

/** Manages a button group where multiple selectable buttons can be selected. */
UCLASS(MinimalAPI)
class UMultiSelectionButtonGroup : public UGenericButtonGroup
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API TArray<UGenericButtonWidget*> GetSelectedButtons() const;

	GENERICBUTTONFRAMEWORK_API virtual EGenericButtonGroupSelectionMode GetSelectionMode() const override;

	/** 写入集合ButtonSelected并同步通用 UI内部状态。 */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool SetButtonSelected(UGenericButtonWidget* InButton, bool bInSelected);

	/** 写入集合ButtonSelectedByIndex并同步通用 UI内部状态。 */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool SetButtonSelectedByIndex(int32 InIndex, bool bInSelected);

	/** Selects every managed button in the input array. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API void AddSelectedButtons(const TArray<UGenericButtonWidget*>& InButtons);

	/** Deselects every managed button in the input array. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API void RemoveSelectedButtons(const TArray<UGenericButtonWidget*>& InButtons);

	/** Deselects every currently selected button. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API void DeselectAll();

	/** Returns the number of currently selected buttons. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API int32 GetSelectedButtonCount() const;

	/** Returns a selected button by selected-list index. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API UGenericButtonWidget* GetSelectedButtonByIndex(int32 InSelectedIndex) const;

	/** Returns the selected-list index of the given button, or INDEX_NONE when missing. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API int32 FindSelectedButtonIndex(UGenericButtonWidget* InButton) const;

	/** Returns whether the given button is currently selected in this group. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool ContainsSelectedButton(UGenericButtonWidget* InButton) const;

	/** Returns whether the given button is the first selected button. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool IsFirstSelectedButton(UGenericButtonWidget* InButton) const;

	/** Returns whether the given button is the last selected button. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool IsLastSelectedButton(UGenericButtonWidget* InButton) const;

protected:
	GENERICBUTTONFRAMEWORK_API virtual void HandleButtonRemoved(UGenericButtonWidget* InButton) override;
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonSelectionChanged(UGenericButtonWidget* InButton, bool bSelected) override;

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UGenericButtonWidget>> SelectedButtons;
};
