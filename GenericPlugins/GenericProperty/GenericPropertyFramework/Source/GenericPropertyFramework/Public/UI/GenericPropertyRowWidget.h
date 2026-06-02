#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Core/GenericPropertyTypes.h"
#include "Base/GenericWidget.h"
#include "GenericPropertyRowWidget.generated.h"

class UGenericPropertyCategoryWidget;
class UGenericPropertyPanelWidget;
class UGenericProperty;
class UGenericPropertyRowWidget;
class UGenericPropertyRowName;
class UGenericPropertyRowValueSpawner;
class UListView;
class UUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyRowChanged,
	UGenericPropertyRowWidget*,
	Widget,
	UGenericProperty*,
	InViewModel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
	FOnGenericPropertyRowPresentationChanged,
	UGenericPropertyRowWidget*,
	Widget,
	UGenericProperty*,
	InViewModel,
	bool,
	bStructureChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyRowOperationFailed,
	UGenericPropertyRowWidget*,
	Widget,
	FText,
	InMessage);

/** 属性节点行控件，绑定一个 UGenericProperty 并协调名称、值控件和子属性列表。 */
UCLASS(MinimalAPI, Abstract, Blueprintable)
class UGenericPropertyRowWidget : public UGenericWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	/** 构造属性行默认状态并保留通用控件初始化入口。 */
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyRowWidget(const FObjectInitializer& ObjectInitializer);

	GENERICPROPERTYFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICPROPERTYFRAMEWORK_API virtual void NativeDestruct() override;

	/** 供行内名称、值控件和子属性列表共享当前绑定的属性节点。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericProperty* GetProperty() const;

	/** 替换绑定属性节点，管理节点委托并同步名称和值子控件。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetProperty(UGenericProperty* InProperty);

	/** 供行控件把刷新、失败广播和子行创建继续路由到顶层属性面板。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyPanelWidget* GetOwningPropertyPanelWidget() const;

	/** 注入所属面板引用，并在需要时刷新子属性行。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetOwningPropertyPanelWidget(UGenericPropertyPanelWidget* InOwningPanelWidget);

	/** 返回所属分类控件，根属性行可能为空。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCategoryWidget* GetOwningPropertyCategoryWidget() const;

	/** 注入所属分类引用，并在需要时刷新子属性行。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetOwningPropertyCategoryWidget(UGenericPropertyCategoryWidget* InOwningCategoryWidget);

public:
	/** 返回展开状态下当前可见的子属性节点。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API TArray<UGenericProperty*> GetVisibleChildPropertyViewModels() const;

	/** 返回行内值展示文本，混合值和 Warning 节点会走特殊显示。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FText GetPropertyDisplayValueText() const;

	/** 返回属性 Issue 文本，操作失败时用于广播错误。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FText GetPropertyFeedbackText() const;

	/** 将当前属性节点的编辑值写回目标对象。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ApplyPropertyValue();

	/** 按指定模式重置当前属性节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ResetPropertyValue(EGenericPropertyResetMode InMode);

	/** 使用行默认重置模式重置当前属性节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ResetPropertyValueToDefault();

	/** 设置属性节点展开状态，并触发节点按需建子项。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetPropertyExpanded(bool bInExpanded);

	/** 切换属性Expanded，同步窗口宿主和运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void TogglePropertyExpanded();

	/** 向当前容器属性添加元素。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool AddPropertyContainerElement();

	/** 从父容器中移除当前属性节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool RemovePropertyNode();

	/** 复制当前数组元素属性节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool DuplicatePropertyNode();

	/** 将当前数组元素属性节点移动到目标索引。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool MovePropertyArrayElement(int32 InNewIndex);

	/** 清空当前容器属性的所有元素。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ClearPropertyContainer();

	/** 用可见子属性节点重新填充子属性 ListView。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void RebuildGeneratedChildren();

	/** 清空子属性 ListView 的生成项。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void ClearGeneratedChildren();

	/** 供蓝图或行刷新逻辑访问名称子控件，以同步显示名和状态样式。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyRowName* GetGenericPropertyRowName() const;

	/** 返回绑定到该行的值生成器子控件。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyRowValueSpawner* GetGenericPropertyValue() const;

	/** 要求值生成器根据当前属性重新选择并创建值控件。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void RebuildPropertyValueWidget();

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	GENERICPROPERTYFRAMEWORK_API virtual void NativeOnEntryReleased() override;

	/** 蓝图扩展点：属性节点绑定后同步名称、值生成器和子属性行状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertySet(UGenericProperty* InPropertyViewModel);

	/** 蓝图扩展点：属性节点解绑时清理行内子控件和蓝图侧状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCleared(UGenericProperty* InPreviousViewModel);

	/** 蓝图扩展点：属性节点值或结构变化后刷新整行展示。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyChanged(UGenericProperty* InPropertyViewModel, bool bStructureChanged);

	/** 蓝图扩展点：属性应用、重置或容器操作失败后展示反馈文本。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyOperationFailed(const FText& InMessage);

private:
	/** 属性节点变化入口：同步子控件、广播事件并按结构变化重建子列表。 */
	void HandlePropertyChanged(UGenericProperty* InProperty, bool bStructureChanged);

	/** 广播属性操作失败文本给蓝图扩展点和事件监听者。 */
	void BroadcastPropertyOperationFailed(const FText& InMessage);

	/** 在子属性行控件生成后注入所属面板和分类。 */
	void HandleChildPropertyEntryWidgetGenerated(UUserWidget& InWidget);

	/** 将当前属性节点同步给绑定的名称和值子控件。 */
	void SyncBoundPropertyWidgets();

protected:
	/** 属性结构变化时是否自动重建子属性 ListView。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	bool bAutoRebuildChildrenOnPropertyChanged=true;

	/** 可选绑定的名称子控件。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UGenericPropertyRowName> GenericPropertyRowName=nullptr;

	/** 可选绑定的值生成器子控件。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UGenericPropertyRowValueSpawner> GenericPropertyValue=nullptr;

	/** 可选绑定的子属性 ListView。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UListView> ListView_ChildProperties=nullptr;

	/** ResetPropertyValueToDefault 使用的重置模式。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	EGenericPropertyResetMode DefaultResetMode=EGenericPropertyResetMode::SourceValue;

	/** 当前行绑定的属性节点。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericProperty> Property=nullptr;

	/** 所属顶层属性面板。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyPanelWidget> OwningPropertyPanelWidget=nullptr;

	/** 所属分类控件，子属性行会继承父行的分类引用。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyCategoryWidget> OwningPropertyCategoryWidget=nullptr;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowChanged OnPropertyViewModelSetEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowChanged OnPropertyViewModelClearedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowPresentationChanged OnPropertyViewModelChangedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowOperationFailed OnPropertyOperationFailedEvent;
};
