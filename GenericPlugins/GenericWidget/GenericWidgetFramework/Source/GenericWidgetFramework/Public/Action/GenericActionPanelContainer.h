// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericActionContainer.h"
#include "Components/SlateWrapperTypes.h"
#include "GenericActionPanelContainer.generated.h"

class UPanelWidget;

/** Panel-backed action container base shared by stack and queue containers. */
UCLASS(Abstract, MinimalAPI)
class UGenericActionPanelContainer : public UGenericActionContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Action Container")
	ESlateVisibility ActiveVisibility = ESlateVisibility::SelfHitTestInvisible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Action Container")
	ESlateVisibility InactiveVisibility = ESlateVisibility::Collapsed;

protected:
	GENERICWIDGETFRAMEWORK_API virtual bool OnWidgetAdded_Implementation(UGenericWidget* InWidget) override;
	GENERICWIDGETFRAMEWORK_API virtual bool OnWidgetRemoved_Implementation(UGenericWidget* InWidget) override;

	GENERICWIDGETFRAMEWORK_API void RefreshActiveWidgetByIndex(int32 InActiveIndex);

protected:
	UPROPERTY(BlueprintReadOnly, Category="Generic Action Container", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UPanelWidget> Panel_Container = nullptr;
};
