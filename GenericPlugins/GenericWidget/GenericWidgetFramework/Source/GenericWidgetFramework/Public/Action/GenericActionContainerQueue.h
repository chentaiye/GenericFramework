// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Action/GenericActionPanelContainer.h"
#include "GenericActionContainerQueue.generated.h"

/** Panel-backed action container that treats added widgets as a FIFO queue. */
UCLASS(MinimalAPI)
class UGenericActionContainerQueue : public UGenericActionPanelContainer
{
	GENERATED_BODY()

public:
	/** Adds a widget to the back of the queue. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container|Queue")
	GENERICWIDGETFRAMEWORK_API bool EnqueueWidget(UGenericWidget* InWidget);

	/** Removes and returns the front widget. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container|Queue")
	GENERICWIDGETFRAMEWORK_API UGenericWidget* DequeueWidget();

	/** Returns the front widget without removing it. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container|Queue")
	GENERICWIDGETFRAMEWORK_API UGenericWidget* PeekWidget() const;

	/** Returns the current front widget index, or INDEX_NONE when empty. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container|Queue")
	GENERICWIDGETFRAMEWORK_API int32 GetFrontWidgetIndex() const;

protected:
	GENERICWIDGETFRAMEWORK_API virtual void RefreshContainerState() override;
};
