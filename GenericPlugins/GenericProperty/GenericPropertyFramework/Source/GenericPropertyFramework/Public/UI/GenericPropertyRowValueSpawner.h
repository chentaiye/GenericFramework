#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Base/GenericWidget.h"
#include "Handle/GenericPropertyValueHandle.h"
#include "GenericPropertyRowValueSpawner.generated.h"

class UGenericProperty;
class UGenericPropertyValue;
class UGenericPropertyValueMappingAsset;
class UPanelWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyRowValueSpawnerChanged,
	UGenericPropertyRowValueSpawner*,
	Widget,
	UGenericProperty*,
	InProperty);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
	FOnGenericPropertyRowValueSpawnerPresentationChanged,
	UGenericPropertyRowValueSpawner*,
	Widget,
	UGenericProperty*,
	InProperty,
	bool,
	bStructureChanged);

/** 属性行值控件生成器，根据属性或值句柄解析合适的 UGenericPropertyValue 并放入容器。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyRowValueSpawner : public UGenericWidget
{
	GENERATED_BODY()

public:
	/** 构造值生成器默认状态并保留通用控件初始化入口。 */
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyRowValueSpawner(const FObjectInitializer& ObjectInitializer);

	GENERICPROPERTYFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICPROPERTYFRAMEWORK_API virtual void NativeDestruct() override;

	/** 供旧属性节点路径查询当前输入来源，随后由生成器选择匹配的值控件。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericProperty* GetProperty() const;

	/** 绑定属性节点并创建对应值句柄和值控件。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetProperty(UGenericProperty* InProperty);

	/** 返回生成器当前用于选择值控件和提交输入的值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* GetValueHandle() const;

	/** 直接绑定值句柄，适用于字段键直连 API 的 UI。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetValueHandle(UGenericPropertyValueHandleBase* InValueHandle);

	/** 返回当前动态创建并放入容器的值控件。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValue* GetSpawnedValueWidget() const;

	/** 根据映射规则重建或复用当前动态值控件。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void RebuildSpawnedValueWidget();

	/** 将序列化输入提交到当前值句柄或旧属性节点。 */
	GENERICPROPERTYFRAMEWORK_API bool CommitSerializedValueInternal(const FString& InValue);

	/** 应用当前值句柄、动态值控件或旧属性节点的编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ApplyPropertyValue();

	/** 按指定模式重置当前值句柄、动态值控件或旧属性节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ResetPropertyValue(EGenericPropertyResetMode InMode);

protected:
	/** 蓝图扩展点：属性节点绑定后根据节点创建句柄并准备动态值控件。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertySet(UGenericProperty* InProperty);

	/** 蓝图扩展点：属性节点解绑时清理动态值控件相关蓝图状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCleared(UGenericProperty* InPreviousProperty);

	/** 蓝图扩展点：属性节点变化后刷新可见性并重新确认动态值控件类型。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyChanged(UGenericProperty* InProperty, bool bStructureChanged);

	/** 蓝图扩展点：接收属性或句柄可见性转换出的 Slate 可见性。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnVisibilityChanged(ESlateVisibility InVisibility);

	/** 旧属性节点变化入口：刷新可见性和动态值控件。 */
	GENERICPROPERTYFRAMEWORK_API void HandlePropertyChanged(UGenericProperty* InProperty, bool bStructureChanged);

	/** 值句柄变化入口：刷新可见性并重新确认动态值控件类型。 */
	UFUNCTION(Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void HandleValueHandleChanged(
		UGenericPropertyValueHandleBase* InValueHandle,
		bool bValueChanged,
		bool bStructureChanged);

	/** 从当前属性或值句柄同步生成器自身可见性。 */
	GENERICPROPERTYFRAMEWORK_API void SyncWidgetPresentationFromProperty() const;

	/** 使用映射资产为当前属性或句柄解析目标值控件类。 */
	GENERICPROPERTYFRAMEWORK_API TSubclassOf<UGenericPropertyValue> ResolvePropertyValueWidgetClass() const;

	/** 在当前拥有者上下文中创建指定值控件类。 */
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValue* SpawnPropertyValueWidget(TSubclassOf<UGenericPropertyValue> InWidgetClass) const;

	/** 用新值控件替换容器内容，并解除旧控件句柄绑定。 */
	GENERICPROPERTYFRAMEWORK_API void ReplaceSpawnedValueWidget(UGenericPropertyValue* InNewWidget);

	/** 可选绑定的值控件容器，生成器会把动态值控件放入其中。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UPanelWidget> PanelWidget_ValueContainer=nullptr;

	/** 控件映射资产，决定不同属性类型使用哪个值控件。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyValueMappingAsset> PropertyValueMapping=nullptr;

	/** 当前绑定的旧属性节点。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericProperty> Property=nullptr;

	/** 当前绑定或从属性节点创建的值句柄。 */
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyValueHandleBase> ValueHandle=nullptr;

	/** 当前动态创建的值控件实例。 */
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyValue> SpawnedValueWidget=nullptr;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowValueSpawnerChanged OnPropertySetEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowValueSpawnerChanged OnPropertyClearedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyRowValueSpawnerPresentationChanged OnPropertyChangedEvent;
};
