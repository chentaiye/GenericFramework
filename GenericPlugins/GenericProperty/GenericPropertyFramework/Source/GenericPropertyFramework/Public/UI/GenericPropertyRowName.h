#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Base/GenericWidget.h"
#include "GenericPropertyRowName.generated.h"

class UGenericProperty;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyRowNameChanged,
	UGenericPropertyRowName*,
	Widget,
	UGenericProperty*,
	InProperty);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
	FOnGenericPropertyRowNamePresentationChanged,
	UGenericPropertyRowName*,
	Widget,
	UGenericProperty*,
	InProperty,
	bool,
	bStructureChanged);

/** 属性行名称子控件，监听属性节点变化并同步显示名、提示和可见性。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyRowName : public UGenericWidget
{
	GENERATED_BODY()

public:
	/** 构造名称控件默认状态并保留通用控件初始化入口。 */
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyRowName(const FObjectInitializer& ObjectInitializer);

	GENERICPROPERTYFRAMEWORK_API virtual void NativeDestruct() override;

	/** 返回当前名称控件绑定的属性节点。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericProperty* GetProperty() const;

	/** 替换绑定属性节点，管理节点委托并立即同步展示。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetProperty(UGenericProperty* InProperty);

protected:
	/** 蓝图扩展点：属性节点绑定后同步名称、提示和可见性显示。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertySet(UGenericProperty* InProperty);

	/** 蓝图扩展点：属性节点解绑时清理名称侧蓝图状态或外部绑定。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCleared(UGenericProperty* InPreviousProperty);

	/** 蓝图扩展点：属性节点状态变化后刷新名称、提示和可见性。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyChanged(UGenericProperty* InProperty, bool bStructureChanged);

	/** 蓝图扩展点：接收属性 DisplayName。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPrimaryNameChanged(const FText& InPrimaryName);

	/** 蓝图扩展点：名称控件当前不使用辅助文本，保持接口和通用值控件一致。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnSecondaryNameChanged(const FText& InSecondaryName);

	/** 蓝图扩展点：接收属性 ToolTip 文本并可同步到 Widget Tooltip。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnTooltipTextChanged(const FText& InTooltipText);

	/** 蓝图扩展点：接收由属性可见状态转换出的 Slate 可见性。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnVisibilityChanged(ESlateVisibility InVisibility);

	/** 从当前属性节点同步名称、提示和可见性到蓝图扩展点。 */
	GENERICPROPERTYFRAMEWORK_API void SyncWidgetPresentationFromProperty() const;

	/** 属性节点变化入口：刷新名称侧展示并广播变更事件。 */
	GENERICPROPERTYFRAMEWORK_API void HandlePropertyChanged(UGenericProperty* InProperty, bool bStructureChanged);

	/** 当前绑定的属性节点。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericProperty> Property=nullptr;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowNameChanged OnPropertySetEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowNameChanged OnPropertyClearedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowNamePresentationChanged OnPropertyChangedEvent;
};
