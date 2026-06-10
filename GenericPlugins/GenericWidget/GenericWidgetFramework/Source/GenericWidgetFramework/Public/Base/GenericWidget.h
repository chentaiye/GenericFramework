// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interface/GenericRouteInterface.h"
#include "GenericWidget.generated.h"

/** 表示可由GenericWidgetSubsystem统一管理的业务UI控件。 */
UCLASS(MinimalAPI)
class UGenericWidget : public UUserWidget, public IGenericRouteInterface
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API virtual FGameplayTag GetRouteTag_Implementation() const override;
	GENERICWIDGETFRAMEWORK_API virtual ULocalPlayer* GetRouteOwnerPlayer_Implementation() const override;
};
