#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Base/GenericWidget.h"
#include "GenericPropertyCategoryWidget.generated.h"

class UGenericPropertyCategory;
class UGenericPropertyPanelWidget;
class UGenericProperty;
class UGenericPropertyCategoryWidget;
class UListView;
class UUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyCategoryChanged,
	UGenericPropertyCategoryWidget*,
	Widget,
	UGenericPropertyCategory*,
	InList);

/** 分类列表条目控件，绑定一个属性分类并把可见属性节点填入内部 ListView。 */
UCLASS(MinimalAPI, Abstract, Blueprintable)
class UGenericPropertyCategoryWidget : public UGenericWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	/** 构造分类条目默认状态并保留通用控件初始化入口。 */
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCategoryWidget(const FObjectInitializer& ObjectInitializer);

	GENERICPROPERTYFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICPROPERTYFRAMEWORK_API virtual void NativeDestruct() override;

	/** 供分类条目刷新内部属性行列表，并把分类委托变化转发给面板。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCategory* GetPropertyCategory() const;

	/** 替换绑定分类，管理分类委托并刷新属性行列表。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetPropertyCategory(UGenericPropertyCategory* InPropertyCategory);

	/** 返回生成该分类条目的顶层属性面板。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyPanelWidget* GetOwningPropertyPanelWidget() const;

	/** 注入所属面板引用，后续生成属性行时继续向下传递。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetOwningPropertyPanelWidget(UGenericPropertyPanelWidget* InOwningPanelWidget);

	/** 返回当前分类下通过可见性过滤的属性节点。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API TArray<UGenericProperty*> GetVisiblePropertyViewModels() const;

	/** 用可见属性节点重新填充内部属性 ListView。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void RebuildGeneratedChildren();

	/** 清空内部属性 ListView 的生成项。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void ClearGeneratedChildren();

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	GENERICPROPERTYFRAMEWORK_API virtual void NativeOnEntryReleased() override;

	/** 蓝图扩展点：分类绑定完成后同步标题、展开状态或外部状态，并准备属性行展示。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCategorySet(UGenericPropertyCategory* InPropertyCategory);

	/** 蓝图扩展点：分类解绑时清理标题和属性行相关蓝图状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCategoryCleared(UGenericPropertyCategory* InPreviousCategory);

	/** 蓝图扩展点：分类内部属性列表变化后同步展示，原生处理会按配置重建属性行。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCategoryChanged(UGenericPropertyCategory* InPropertyCategory);

	/** 响应分类列表变化，广播蓝图事件并按配置重建属性行。 */
	GENERICPROPERTYFRAMEWORK_API void HandlePropertyCategoryChanged(UGenericPropertyCategory* InPropertyCategory);

	/** 在属性行控件生成后注入所属面板和分类，并触发子行重建。 */
	GENERICPROPERTYFRAMEWORK_API void HandlePropertyEntryWidgetGenerated(UUserWidget& InWidget);

	/** 分类属性列表变化时是否自动重建内部 ListView。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	bool bAutoRebuildChildrenOnListChanged=true;

	/** 可选绑定的属性 ListView，分类控件会向其中写入可见属性节点。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UListView> ListView_Properties=nullptr;

	/** 当前绑定的属性分类数据。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyCategory> PropertyCategory=nullptr;

	/** 所属顶层属性面板，生成属性行时继续传递。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyPanelWidget> OwningPropertyPanelWidget=nullptr;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyCategoryChanged OnPropertyListSetEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyCategoryChanged OnPropertyListClearedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyCategoryChanged OnPropertyListChangedEvent;
};
