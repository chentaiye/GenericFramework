// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericActionWidget.h"
#include "GenericButtonContainer.generated.h"

class UGenericButtonWidget;
class UPanelWidget;

/** Provides a visual container surface for adding and removing generic button widgets. */
UCLASS(MinimalAPI)
class UGenericButtonContainer : public UGenericActionWidget
{
	GENERATED_BODY()

public:
	/** Adds a button through the container extension path. */
	UFUNCTION(BlueprintCallable, Category="Generic Button Container")
	GENERICBUTTONFRAMEWORK_API bool AddButton(UGenericButtonWidget* InButton);

	/** Adds multiple buttons through the same path as AddButton. */
	UFUNCTION(BlueprintCallable, Category="Generic Button Container")
	GENERICBUTTONFRAMEWORK_API void AddButtons(const TArray<UGenericButtonWidget*>& InButtons);

	/** Removes a button through the container extension path. */
	UFUNCTION(BlueprintCallable, Category="Generic Button Container")
	GENERICBUTTONFRAMEWORK_API bool RemoveButton(UGenericButtonWidget* InButton);

	/** Removes multiple buttons through the same path as RemoveButton. */
	UFUNCTION(BlueprintCallable, Category="Generic Button Container")
	GENERICBUTTONFRAMEWORK_API void RemoveButtons(const TArray<UGenericButtonWidget*>& InButtons);

protected:
	/** Handles adding a button to the underlying visual container. */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Button Container")
	GENERICBUTTONFRAMEWORK_API bool OnButtonAdded(UGenericButtonWidget* InButton);

	/** Handles removing a button from the underlying visual container. */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Button Container")
	GENERICBUTTONFRAMEWORK_API bool OnButtonRemoved(UGenericButtonWidget* InButton);

private:
	UPROPERTY(BlueprintReadOnly, Category="Generic Button Container", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UPanelWidget> Panel_Container = nullptr;
};
