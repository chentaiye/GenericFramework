// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "GenericRouteInterface.generated.h"

class ULocalPlayer;

/** 标记对象可作为通用UI路由树中的节点。 */
UINTERFACE(MinimalAPI, BlueprintType)
class UGenericRouteInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义UI路由节点识别能力契约，供模块在不同实现之间解耦调用。 */
class GENERICWIDGETFRAMEWORK_API IGenericRouteInterface
{
	GENERATED_BODY()

public:
	/** 获取当前对象在通用UI路由标签树中的类型。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Generic Route")
	FGameplayTag GetRouteTag() const;

	/** 获取当前路由节点所属的本地玩家。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Generic Route")
	ULocalPlayer* GetRouteOwnerPlayer() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Generic Route")
	void HandleRouteActivated();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Generic Route")
	void HandleRouteDeactivated();
};
