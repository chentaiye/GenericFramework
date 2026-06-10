// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Action/GenericActionPanelContainer.h"
#include "GenericActionContainerStack.generated.h"

/** Panel-backed action container that treats added widgets as a LIFO stack. */
UCLASS(MinimalAPI)
class UGenericActionContainerStack : public UGenericActionPanelContainer
{
	GENERATED_BODY()

public:
	/** Pushes a widget to the top of the stack. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container|Stack")
	GENERICWIDGETFRAMEWORK_API bool PushWidget(UGenericWidget* InWidget);

	/** Removes and returns the top widget. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container|Stack")
	GENERICWIDGETFRAMEWORK_API UGenericWidget* PopWidget();

	/** Returns the top widget without removing it. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container|Stack")
	GENERICWIDGETFRAMEWORK_API UGenericWidget* PeekWidget() const;

	/** Returns the current top widget index, or INDEX_NONE when empty. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container|Stack")
	GENERICWIDGETFRAMEWORK_API int32 GetTopWidgetIndex() const;

protected:
	GENERICWIDGETFRAMEWORK_API virtual void RefreshContainerState() override;
};
