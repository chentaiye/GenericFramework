#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayTagContainer.h"
#include "UObject/SoftObjectPath.h"
#include "Base/GenericWidget.h"
#include "Core/GenericPropertyTypes.h"
#include "Handle/GenericPropertyValueHandle.h"
#include "GenericPropertyValue.generated.h"

class UGenericProperty;
class UGenericPropertyValueHandleBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyValueChanged,
	UGenericPropertyValue*,
	Widget,
	UGenericProperty*,
	InProperty
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
	FOnGenericPropertyValuePresentationChanged,
	UGenericPropertyValue*,
	Widget,
	UGenericProperty*,
	InProperty,
	bool,
	bStructureChanged
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyValueOperationFailed,
	UGenericPropertyValue*,
	Widget,
	FText,
	InMessage
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyValueHandleAssigned,
	UGenericPropertyValue*,
	Widget,
	UGenericPropertyValueHandleBase*,
	InHandle
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
	FOnGenericPropertyValueHandlePresentationChanged,
	UGenericPropertyValue*,
	Widget,
	UGenericPropertyValueHandleBase*,
	InHandle,
	bool,
	bStructureChanged
);

/** 属性值控件基类，连接旧属性节点和值句柄，并向蓝图同步值文本、反馈和可见性。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyValue : public UGenericWidget
{
	GENERATED_BODY()

public:
	/** 构造值控件默认状态并保留通用控件初始化入口。 */
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValue(const FObjectInitializer& ObjectInitializer);

	GENERICPROPERTYFRAMEWORK_API virtual void NativeDestruct() override;

	/** 供旧属性节点驱动的 UI 查询当前绑定对象，便于与新值句柄路径保持兼容。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericProperty* GetProperty() const;

	/** 绑定旧属性节点，并从节点所属代理创建对应值句柄。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetProperty(UGenericProperty* InProperty);

	/** 返回值控件当前用于读取、校验和提交 UI 输入的值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* GetValueHandle() const;

	/** 直接绑定值句柄，适用于字段键直连 API 的 UI。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetValueHandle(UGenericPropertyValueHandleBase* InValueHandle);

	/** 为值控件展示提供文本，优先使用值句柄状态并兼容旧属性节点。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FText GetValueText() const;

	/** 为提示和失败广播提供反馈文本，优先使用值句柄 Issue。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FText GetFeedbackText() const;

	/** 根据属性节点或值句柄状态决定当前 UI 输入是否应启用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool IsValueEditable() const;

	/** 将当前编辑值写回目标对象。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ApplyPropertyValue();

	/** 按指定模式恢复当前值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ResetPropertyValue(EGenericPropertyResetMode InMode);

	/** 将 UI 输入的序列化文本提交给值句柄或旧属性节点。 */
	GENERICPROPERTYFRAMEWORK_API bool CommitSerializedValueInternal(const FString& InValue);

protected:
	/** 蓝图扩展点：旧属性节点绑定后同步显示文本并建立对应值句柄。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertySet(UGenericProperty* InProperty);

	/** 蓝图扩展点：旧属性节点解绑时清理显示状态和蓝图侧外部绑定。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCleared(UGenericProperty* InPreviousProperty);

	/** 蓝图扩展点：旧属性节点变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyChanged(UGenericProperty* InProperty, bool bStructureChanged);

	/** 蓝图扩展点：接收提交、应用或重置失败的反馈文本。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyOperationFailed(const FText& InMessage);

	/** 蓝图扩展点：值句柄绑定后同步 typed 值控件和显示状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnValueHandleSet(UGenericPropertyValueHandleBase* InValueHandle);

	/** 蓝图扩展点：值句柄解绑时清理 typed 控件状态和外部绑定。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnValueHandleCleared(UGenericPropertyValueHandleBase* InPreviousValueHandle);

	/** 蓝图扩展点：值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnValueHandleChanged(UGenericPropertyValueHandleBase* InValueHandle, bool bStructureChanged);

	/** 蓝图扩展点：接收主显示文本。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPrimaryNameChanged(const FText& InPrimaryName);

	/** 蓝图扩展点：接收值展示文本。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnSecondaryNameChanged(const FText& InSecondaryName);

	/** 蓝图扩展点：接收反馈或提示文本。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnTooltipTextChanged(const FText& InTooltipText);

	/** 蓝图扩展点：接收由属性或句柄状态转换出的可见性。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnVisibilityChanged(ESlateVisibility InVisibility);

	/** 从当前属性或值句柄同步展示文本、反馈和可见性。 */
	GENERICPROPERTYFRAMEWORK_API void SyncWidgetPresentationFromProperty() const;

	/** 旧属性节点变化入口：必要时刷新值句柄并广播 UI 事件。 */
	GENERICPROPERTYFRAMEWORK_API void HandlePropertyChanged(UGenericProperty* InProperty, bool bStructureChanged);

	/** 值句柄变化入口：刷新展示并触发 typed 值变化扩展点。 */
	UFUNCTION(Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void HandleValueHandleChanged(
		UGenericPropertyValueHandleBase* InValueHandle,
		bool bValueChanged,
		bool bStructureChanged);

	/** 向蓝图扩展点和事件监听者广播操作失败文本。 */
	GENERICPROPERTYFRAMEWORK_API void BroadcastPropertyOperationFailed(const FText& InMessage);

	/** typed 派生控件收到值句柄变化后的扩展点。 */
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged();

	/** 当前绑定的旧属性节点。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericProperty> Property=nullptr;

	/** 当前绑定或自动创建的值句柄。 */
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyValueHandleBase> ValueHandle=nullptr;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyValueChanged OnPropertySetEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyValueChanged OnPropertyClearedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyValuePresentationChanged OnPropertyChangedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyValueOperationFailed OnPropertyOperationFailedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyValueHandleAssigned OnValueHandleSetEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyValueHandleAssigned OnValueHandleClearedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyValueHandlePresentationChanged OnValueHandleChangedEvent;
};

/** 布尔属性值控件，封装 bool 句柄访问并向蓝图暴露布尔变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyBoolValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于布尔控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyBoolValueHandle* GetBoolHandle() const;

	/** 从句柄 CurrentValue 读取 bool。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentBoolValue(bool& OutValue) const;

	/** 从句柄 SourceValue 读取 bool。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceBoolValue(bool& OutValue) const;

	/** 从句柄 DefaultValue 读取 bool。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultBoolValue(bool& OutValue) const;

	/** 写入 bool 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentBoolValue(bool bInValue);

	/** 提交 bool 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentBoolValue(bool bInValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：布尔值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnBoolValueChanged();
};

/** 数值属性值控件基类，作为字节、整数和浮点控件的共享类型。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyNumericValue : public UGenericPropertyValue
{
	GENERATED_BODY()
};

/** 字节属性值控件，封装 uint8 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyByteValue : public UGenericPropertyNumericValue
{
	GENERATED_BODY()

public:
	/** 返回用于字节控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyByteValueHandle* GetByteHandle() const;

	/** 从句柄 CurrentValue 读取 uint8。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentByteValue(uint8& OutValue) const;

	/** 从句柄 SourceValue 读取 uint8。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceByteValue(uint8& OutValue) const;

	/** 从句柄 DefaultValue 读取 uint8。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultByteValue(uint8& OutValue) const;

	/** 写入 uint8 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentByteValue(uint8 InValue);

	/** 提交 uint8 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentByteValue(uint8 InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：字节值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnByteValueChanged();
};

/** 32 位整数属性值控件，封装 int32 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyIntegerValue : public UGenericPropertyNumericValue
{
	GENERATED_BODY()

public:
	/** 返回用于 int32 控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyIntegerValueHandle* GetIntegerHandle() const;

	/** 从句柄 CurrentValue 读取 int32。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentIntegerValue(int32& OutValue) const;

	/** 从句柄 SourceValue 读取 int32。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceIntegerValue(int32& OutValue) const;

	/** 从句柄 DefaultValue 读取 int32。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultIntegerValue(int32& OutValue) const;

	/** 写入 int32 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentIntegerValue(int32 InValue);

	/** 提交 int32 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentIntegerValue(int32 InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：int32 值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnIntegerValueChanged();
};

/** 64 位整数属性值控件，封装 int64 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyInteger64Value : public UGenericPropertyNumericValue
{
	GENERATED_BODY()

public:
	/** 返回用于 int64 控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyInteger64ValueHandle* GetInteger64Handle() const;

	/** 从句柄 CurrentValue 读取 int64。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentInteger64Value(int64& OutValue) const;

	/** 从句柄 SourceValue 读取 int64。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceInteger64Value(int64& OutValue) const;

	/** 从句柄 DefaultValue 读取 int64。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultInteger64Value(int64& OutValue) const;

	/** 写入 int64 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentInteger64Value(int64 InValue);

	/** 提交 int64 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentInteger64Value(int64 InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：int64 值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnInteger64ValueChanged();
};

/** 单精度浮点属性值控件，封装 float 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyFloatValue : public UGenericPropertyNumericValue
{
	GENERATED_BODY()

public:
	/** 返回用于 float 控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyFloatValueHandle* GetFloatHandle() const;

	/** 从句柄 CurrentValue 读取 float。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentFloatValue(float& OutValue) const;

	/** 从句柄 SourceValue 读取 float。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceFloatValue(float& OutValue) const;

	/** 从句柄 DefaultValue 读取 float。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultFloatValue(float& OutValue) const;

	/** 写入 float 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentFloatValue(float InValue);

	/** 提交 float 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentFloatValue(float InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：float 值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnFloatValueChanged();
};

/** 双精度浮点属性值控件，封装 double 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyDoubleValue : public UGenericPropertyNumericValue
{
	GENERATED_BODY()

public:
	/** 返回用于 double 控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyDoubleValueHandle* GetDoubleHandle() const;

	/** 从句柄 CurrentValue 读取 double。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentDoubleValue(double& OutValue) const;

	/** 从句柄 SourceValue 读取 double。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceDoubleValue(double& OutValue) const;

	/** 从句柄 DefaultValue 读取 double。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultDoubleValue(double& OutValue) const;

	/** 写入 double 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentDoubleValue(double InValue);

	/** 提交 double 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentDoubleValue(double InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：double 值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnDoubleValueChanged();
};

/** 文本属性值控件，封装 FText 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyTextValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于 FText 控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyTextValueHandle* GetTextHandle() const;

	/** 从句柄 CurrentValue 读取 FText。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentTextValue(FText& OutValue) const;

	/** 从句柄 SourceValue 读取 FText。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceTextValue(FText& OutValue) const;

	/** 从句柄 DefaultValue 读取 FText。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultTextValue(FText& OutValue) const;

	/** 写入 FText 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentTextValue(const FText& InValue);

	/** 提交 FText 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentTextValue(const FText& InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：FText 值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnTextValueChanged();
};

/** 字符串属性值控件，封装 FString 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyStringValue : public UGenericPropertyTextValue
{
	GENERATED_BODY()

public:
	/** 返回用于 FString 控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyStringValueHandle* GetStringHandle() const;

	/** 从句柄 CurrentValue 读取 FString。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentStringValue(FString& OutValue) const;

	/** 从句柄 SourceValue 读取 FString。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceStringValue(FString& OutValue) const;

	/** 从句柄 DefaultValue 读取 FString。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultStringValue(FString& OutValue) const;

	/** 写入 FString 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentStringValue(const FString& InValue);

	/** 提交 FString 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentStringValue(const FString& InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：FString 值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnStringValueChanged();
};

/** 名称属性值控件，封装 FName 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyNameValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于 FName 控件读写 CurrentValue 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyNameValueHandle* GetNameHandle() const;

	/** 从句柄 CurrentValue 读取 FName。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentNameValue(FName& OutValue) const;

	/** 从句柄 SourceValue 读取 FName。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceNameValue(FName& OutValue) const;

	/** 从句柄 DefaultValue 读取 FName。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultNameValue(FName& OutValue) const;

	/** 写入 FName 当前值并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentNameValue(FName InValue);

	/** 提交 FName 当前值并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentNameValue(FName InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：FName 值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnNameValueChanged();
};

/** 枚举属性值控件，以底层整数读写枚举并暴露枚举定义查询。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyEnumValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于枚举控件读写底层整数值并解析枚举定义的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyEnumValueHandle* GetEnumHandle() const;

	/** 从句柄 CurrentValue 读取枚举底层整数。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentEnumValue(int64& OutValue) const;

	/** 从句柄 SourceValue 读取枚举底层整数。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceEnumValue(int64& OutValue) const;

	/** 从句柄 DefaultValue 读取枚举底层整数。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultEnumValue(int64& OutValue) const;

	/** 写入枚举底层整数并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentEnumValue(int64 InValue);

	/** 提交枚举底层整数并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentEnumValue(int64 InValue);

	/** 返回句柄加载到的枚举定义，供 UI 生成选项。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UEnum* GetEnumDefinition() const;

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：枚举值句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnEnumValueChanged();
};

/** 对象引用属性值控件，封装 UObject 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyObjectValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于对象引用控件读写 UObject 当前值的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyObjectValueHandle* GetObjectHandle() const;

	/** 从句柄 CurrentValue 读取 UObject 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentObjectValue(UObject*& OutValue) const;

	/** 从句柄 SourceValue 读取 UObject 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceObjectValue(UObject*& OutValue) const;

	/** 从句柄 DefaultValue 读取 UObject 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultObjectValue(UObject*& OutValue) const;

	/** 写入 UObject 引用并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentObjectValue(UObject* InValue);

	/** 提交 UObject 引用并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentObjectValue(UObject* InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：对象引用句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnObjectValueChanged();
};

/** 类引用属性值控件，封装 UClass 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyClassValue : public UGenericPropertyObjectValue
{
	GENERATED_BODY()

public:
	/** 返回用于类引用控件读写 UClass 当前值的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyClassValueHandle* GetClassHandle() const;

	/** 从句柄 CurrentValue 读取 UClass 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentClassValue(UClass*& OutValue) const;

	/** 从句柄 SourceValue 读取 UClass 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceClassValue(UClass*& OutValue) const;

	/** 从句柄 DefaultValue 读取 UClass 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultClassValue(UClass*& OutValue) const;

	/** 写入 UClass 引用并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentClassValue(UClass* InValue);

	/** 提交 UClass 引用并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentClassValue(UClass* InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：类引用句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnClassValueChanged();
};

/** 软对象引用属性值控件，封装 FSoftObjectPath 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertySoftObjectValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于软对象引用控件读写 FSoftObjectPath 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertySoftObjectValueHandle* GetSoftObjectHandle() const;

	/** 从句柄 CurrentValue 读取 FSoftObjectPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentSoftObjectValue(FSoftObjectPath& OutValue) const;

	/** 从句柄 SourceValue 读取 FSoftObjectPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceSoftObjectValue(FSoftObjectPath& OutValue) const;

	/** 从句柄 DefaultValue 读取 FSoftObjectPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultSoftObjectValue(FSoftObjectPath& OutValue) const;

	/** 写入 FSoftObjectPath 并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentSoftObjectValue(const FSoftObjectPath& InValue);

	/** 提交 FSoftObjectPath 并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentSoftObjectValue(const FSoftObjectPath& InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：软对象引用句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnSoftObjectValueChanged();
};

/** 软类引用属性值控件，封装 FSoftClassPath 句柄访问并向蓝图暴露变化事件。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertySoftClassValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于软类引用控件读写 FSoftClassPath 的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertySoftClassValueHandle* GetSoftClassHandle() const;

	/** 从句柄 CurrentValue 读取 FSoftClassPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentSoftClassValue(FSoftClassPath& OutValue) const;

	/** 从句柄 SourceValue 读取 FSoftClassPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceSoftClassValue(FSoftClassPath& OutValue) const;

	/** 从句柄 DefaultValue 读取 FSoftClassPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultSoftClassValue(FSoftClassPath& OutValue) const;

	/** 写入 FSoftClassPath 并走句柄校验流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentSoftClassValue(const FSoftClassPath& InValue);

	/** 提交 FSoftClassPath 并触发句柄变化通知。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentSoftClassValue(const FSoftClassPath& InValue);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：软类引用句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnSoftClassValueChanged();
};

/** 结构体属性值控件，暴露结构体类型和字段子句柄访问。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyStructValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于结构体控件访问字段句柄和结构体类型的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyStructValueHandle* GetStructHandle() const;

	/** 供结构体值控件确定字段布局，类型来自当前值句柄的描述符解析结果。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UScriptStruct* GetStructType() const;

	/** 供结构体 UI 生成字段行，确保子句柄缓存已按描述符展开。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API TArray<UGenericPropertyValueHandleBase*> GetFieldHandles() const;

	/** 按字段名查找结构体字段子句柄。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* FindFieldHandle(FName InPropertyName) const;

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：结构体句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnStructValueChanged();
};

/** 容器属性值控件，提供元素数量和清空容器的通用入口。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyContainerValue : public UGenericPropertyValue
{
	GENERATED_BODY()

public:
	/** 返回用于容器控件读取元素数量并执行容器操作的 typed 值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyContainerValueHandle* GetContainerHandle() const;

	/** 供容器值控件显示元素数量，数据来自句柄子项或旧属性节点子项。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API int32 GetElementCount() const;

	/** 清空当前容器值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ClearContainerValue();

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyTypedValueChanged() override;

	/** 蓝图扩展点：容器句柄变化后通知派生 UI 更新。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnContainerValueChanged();
};

/** 警告属性值控件，用于展示不支持属性或异常节点的反馈文本。 */
UCLASS(MinimalAPI, Blueprintable)
class UGenericPropertyWarningValue : public UGenericPropertyValue
{
	GENERATED_BODY()
};
