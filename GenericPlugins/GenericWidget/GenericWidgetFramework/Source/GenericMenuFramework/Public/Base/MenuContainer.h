// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericButtonContainer.h"
#include "MenuContainer.generated.h"

class UMenuCollection;
class UMenuNode;

/** 表示菜单树一个层级生成的按钮容器，负责承载该层级的菜单按钮。 */
UCLASS(BlueprintType, Blueprintable, MinimalAPI)
class UMenuContainer : public UGenericButtonContainer
{
	GENERATED_BODY()

public:
	/** 在容器完成运行时菜单层级构建后触发，供蓝图初始化层级外观。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Menu")
	GENERICMENUFRAMEWORK_API void OnMenuBuilt(UMenuCollection* InMenuCollection, UMenuNode* InMenuNode);

	/** 在容器从运行时菜单层级移除前触发，供蓝图释放层级状态。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Menu")
	GENERICMENUFRAMEWORK_API void OnMenuDestroyed(UMenuCollection* InMenuCollection, UMenuNode* InMenuNode);
};
