// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericButtonWidget.h"
#include "MenuWidget.generated.h"

class UMenuCollection;
class UMenuNode;

/** 表示由菜单节点生成的按钮控件，承接通用按钮行为和菜单生命周期回调。 */
UCLASS(BlueprintType, Blueprintable, MinimalAPI)
class UMenuWidget : public UGenericButtonWidget
{
	GENERATED_BODY()

public:
	/** 在按钮被加入运行时菜单层级后触发，供蓝图初始化节点相关显示。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Menu")
	GENERICMENUFRAMEWORK_API void OnMenuBuilt(UMenuCollection* InMenuCollection, UMenuNode* InMenuNode);

	/** 在按钮从运行时菜单层级移除前触发，供蓝图释放节点相关状态。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Menu")
	GENERICMENUFRAMEWORK_API void OnMenuDestroyed(UMenuCollection* InMenuCollection, UMenuNode* InMenuNode);
};
