// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "Interface/GenericRouteInterface.h"
#include "GenericLayout.generated.h"

/** 表示本地玩家 UI 路由树中的布局根节点，注册由外部显式调用完成。 */
UCLASS(MinimalAPI)
class UGenericLayout : public UUserWidget, public IGenericRouteInterface
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API virtual FGameplayTag GetRouteTag_Implementation() const override;
	GENERICWIDGETFRAMEWORK_API virtual ULocalPlayer* GetRouteOwnerPlayer_Implementation() const override;

protected:
	GENERICWIDGETFRAMEWORK_API virtual void NativeDestruct() override;
};
