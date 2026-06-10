// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericActionContainer.h"
#include "GenericActionContainerSwitch.generated.h"

class UWidgetSwitcher;

/** Action container that displays one tracked widget through a widget switcher. */
UCLASS(MinimalAPI)
class UGenericActionContainerSwitch : public UGenericActionContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Action Container")
	bool bLoopSelection = false;

public:
	/** 写入集合Active控件Index并同步通用 UI内部状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container|Switch")
	GENERICWIDGETFRAMEWORK_API bool SetActiveWidgetIndex(int32 InIndex);

	/** Returns the active widget index, or INDEX_NONE when empty. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container|Switch")
	GENERICWIDGETFRAMEWORK_API int32 GetActiveWidgetIndex() const;

	/** Returns the active widget, or nullptr when empty. */
	UFUNCTION(BlueprintPure, Category="Generic Action Container|Switch")
	GENERICWIDGETFRAMEWORK_API UGenericWidget* GetActiveWidget() const;

	/** Selects the previous widget, optionally wrapping when bLoopSelection is true. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container|Switch")
	GENERICWIDGETFRAMEWORK_API bool SelectPreviousWidget();

	/** Selects the next widget, optionally wrapping when bLoopSelection is true. */
	UFUNCTION(BlueprintCallable, Category="Generic Action Container|Switch")
	GENERICWIDGETFRAMEWORK_API bool SelectNextWidget();

protected:
	GENERICWIDGETFRAMEWORK_API virtual bool OnWidgetAdded_Implementation(UGenericWidget* InWidget) override;
	GENERICWIDGETFRAMEWORK_API virtual bool OnWidgetRemoved_Implementation(UGenericWidget* InWidget) override;
	GENERICWIDGETFRAMEWORK_API virtual void RefreshContainerState() override;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Generic Action Container", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UWidgetSwitcher> Switcher_Container = nullptr;

	UPROPERTY(Transient)
	int32 ActiveWidgetIndex = INDEX_NONE;
};
