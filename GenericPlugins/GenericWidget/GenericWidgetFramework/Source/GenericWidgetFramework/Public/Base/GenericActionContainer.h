// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericActionWidget.h"
#include "GenericActionContainer.generated.h"

class UGenericWidget;

/** Base class for action-aware containers that manage a logical widget list. */
UCLASS(Abstract, MinimalAPI)
class UGenericActionContainer : public UGenericActionWidget
{
	GENERATED_BODY()

public:
	/** Adds a widget to this container. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API bool AddWidget(UGenericWidget* InWidget);

	/** Removes a widget from this container. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API bool RemoveWidget(UGenericWidget* InWidget);

	/** Removes a widget by logical container index. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API bool RemoveWidgetByIndex(int32 InIndex);

	/** Removes every widget from this container. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API void ClearWidgets();

	/** Returns every valid widget currently tracked by this container. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API TArray<UGenericWidget*> GetWidgets() const;

	/** Returns the number of logical widget entries tracked by this container. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API int32 GetWidgetCount() const;

	/** Returns a widget by logical container index. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API UGenericWidget* GetWidgetByIndex(int32 InIndex) const;

	/** Returns a widget's logical index, or INDEX_NONE when missing. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API int32 FindWidgetIndex(UGenericWidget* InWidget) const;

	/** Returns whether the widget is tracked by this container. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API bool ContainsWidget(UGenericWidget* InWidget) const;

protected:
	GENERICWIDGETFRAMEWORK_API bool AddWidgetInternal(UGenericWidget* InWidget);
	GENERICWIDGETFRAMEWORK_API bool RemoveWidgetInternal(UGenericWidget* InWidget);
	GENERICWIDGETFRAMEWORK_API virtual void RefreshContainerState();

	/** Handles adding a widget to the concrete container surface. */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API bool OnWidgetAdded(UGenericWidget* InWidget);

	/** Handles removing a widget from the concrete container surface. */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Action Container")
	GENERICWIDGETFRAMEWORK_API bool OnWidgetRemoved(UGenericWidget* InWidget);

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UGenericWidget>> Widgets;
};
