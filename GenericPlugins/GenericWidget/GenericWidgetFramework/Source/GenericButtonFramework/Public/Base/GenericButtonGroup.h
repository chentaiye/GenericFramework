// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GenericButtonGroup.generated.h"

class UGenericButtonWidget;

UENUM(BlueprintType)
enum class EGenericButtonGroupSelectionMode : uint8
{
	Single,
	Multi
};

/** Stores delegate handles for a button registered in a generic button group. */
struct FGenericButtonGroupDelegateHandles
{
	FDelegateHandle OnButtonEnabledHandle;
	FDelegateHandle OnButtonDisabledHandle;
	FDelegateHandle OnButtonPressedHandle;
	FDelegateHandle OnButtonReleasedHandle;
	FDelegateHandle OnButtonHoveredHandle;
	FDelegateHandle OnButtonUnhoveredHandle;
	FDelegateHandle OnButtonClickedHandle;
	FDelegateHandle OnButtonDoubleClickedHandle;
	FDelegateHandle OnButtonSelectionChangedHandle;
	FDelegateHandle OnButtonStyleChangedHandle;
};

/** Stores a managed button and its bound native delegate handles. */
USTRUCT()
struct FGenericButtonGroupEntry
{
	GENERATED_BODY()

	UPROPERTY(Transient)
	TObjectPtr<UGenericButtonWidget> Button = nullptr;

	FGenericButtonGroupDelegateHandles DelegateHandles;
};

/** Manually manages a group of generic button widgets and listens to every button event. */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced, MinimalAPI)
class UGenericButtonGroup : public UObject
{
	GENERATED_BODY()

public:
	/** Adds a button to this group and binds all button events. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API virtual bool AddButton(UGenericButtonWidget* InButton);

	/** Adds every button in the input array to this group. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API void AddButtons(const TArray<UGenericButtonWidget*>& InButtons);

	/** Removes a button from this group and unbinds all button events. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API virtual bool RemoveButton(UGenericButtonWidget* InButton);

	/** Removes every button in the input array from this group. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API void RemoveButtons(const TArray<UGenericButtonWidget*>& InButtons);

	/** Removes the button at the given group index. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool RemoveButtonByIndex(int32 InIndex);

	/** Removes all buttons from this group. */
	UFUNCTION(BlueprintCallable, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API void ClearButtons();

	/** Returns every button currently managed by this group. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API TArray<UGenericButtonWidget*> GetButtons() const;

	/** Returns the number of button entries currently managed by this group. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API int32 GetButtonCount() const;

	/** Returns the button at the given group index. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API UGenericButtonWidget* GetButtonByIndex(int32 InIndex) const;

	/** Returns the group index of the given button, or INDEX_NONE when missing. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API int32 FindButtonIndex(UGenericButtonWidget* InButton) const;

	/** Returns whether the button is currently managed by this group. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool ContainsButton(UGenericButtonWidget* InButton) const;

	/** Returns whether the button is the first managed button. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool IsFirstButton(UGenericButtonWidget* InButton) const;

	/** Returns whether the button is the last managed button. */
	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API bool IsLastButton(UGenericButtonWidget* InButton) const;

	UFUNCTION(BlueprintPure, Category="Button|Group")
	GENERICBUTTONFRAMEWORK_API virtual EGenericButtonGroupSelectionMode GetSelectionMode() const;

protected:
	GENERICBUTTONFRAMEWORK_API virtual void HandleButtonAdded(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void HandleButtonRemoved(UGenericButtonWidget* InButton);

	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonEnabled(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonDisabled(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonPressed(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonReleased(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonHovered(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonUnhovered(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonClicked(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonDoubleClicked(UGenericButtonWidget* InButton);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonSelectionChanged(UGenericButtonWidget* InButton, bool bSelected);
	GENERICBUTTONFRAMEWORK_API virtual void NativeOnGroupButtonStyleChanged(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonEnabled(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonDisabled(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonPressed(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonReleased(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonHovered(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonUnhovered(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonClicked(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonDoubleClicked(UGenericButtonWidget* InButton);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonSelectionChanged(UGenericButtonWidget* InButton, bool bSelected);

	UFUNCTION(BlueprintImplementableEvent, Category="Button|Group|Event")
	void HandleOnGroupButtonStyleChanged(UGenericButtonWidget* InButton);

protected:
	UPROPERTY(Transient)
	TArray<FGenericButtonGroupEntry> ButtonEntries;

private:
	void BindButtonEvents(UGenericButtonWidget* InButton);
	void UnbindButtonEvents(UGenericButtonWidget* InButton);
	int32 FindButtonEntryIndex(UGenericButtonWidget* InButton) const;
	FGenericButtonGroupEntry* FindButtonEntry(UGenericButtonWidget* InButton);

	void HandleOnButtonEnabledInternal(UGenericButtonWidget* InButton);
	void HandleOnButtonDisabledInternal(UGenericButtonWidget* InButton);
	void HandleOnButtonPressedInternal(UGenericButtonWidget* InButton);
	void HandleOnButtonReleasedInternal(UGenericButtonWidget* InButton);
	void HandleOnButtonHoveredInternal(UGenericButtonWidget* InButton);
	void HandleOnButtonUnhoveredInternal(UGenericButtonWidget* InButton);
	void HandleOnButtonClickedInternal(UGenericButtonWidget* InButton);
	void HandleOnButtonDoubleClickedInternal(UGenericButtonWidget* InButton);
	void HandleOnButtonSelectionChangedInternal(bool bSelected, UGenericButtonWidget* InButton);
	void HandleOnButtonStyleChangedInternal(UGenericButtonWidget* InButton);
};
