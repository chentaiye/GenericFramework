#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyDescriptor.h"
#include "UObject/Object.h"
#include "UObject/SoftObjectPath.h"
#include "GenericPropertyValueHandle.generated.h"

class FProperty;
class UEnum;
class UGenericProperty;
class UGenericPropertyProxy;
class UScriptStruct;
class UGenericPropertyValueHandleBase;
class UGenericPropertyBoolValueHandle;
class UGenericPropertyByteValueHandle;
class UGenericPropertyIntegerValueHandle;
class UGenericPropertyInteger64ValueHandle;
class UGenericPropertyFloatValueHandle;
class UGenericPropertyDoubleValueHandle;
class UGenericPropertyStringValueHandle;
class UGenericPropertyTextValueHandle;
class UGenericPropertyNameValueHandle;
class UGenericPropertyEnumValueHandle;
class UGenericPropertyObjectValueHandle;
class UGenericPropertyClassValueHandle;
class UGenericPropertySoftObjectValueHandle;
class UGenericPropertySoftClassValueHandle;
class UGenericPropertyStructValueHandle;
class UGenericPropertyContainerValueHandle;
class UGenericPropertyArrayValueHandle;
class UGenericPropertySetValueHandle;
class UGenericPropertyMapValueHandle;
class FGenericPropertySessionCore;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGenericPropertyValueHandleChanged, UGenericPropertyValueHandleBase*, Handle, bool, bValueChanged, bool, bStructureChanged);

/** 属性值句柄基类，封装描述符、状态缓存、序列化读写和子句柄懒加载。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyValueHandleBase : public UObject
{
	GENERATED_BODY()

public:
	/** 返回拥有者代理，句柄通过它访问目标对象、数据源和面板选项。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyProxy* GetOwningProxy() const;

	/** 返回兼容旧节点 UI 的属性节点；字段直连句柄可能为空。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericProperty* GetLegacyProperty() const;

	/** 返回句柄对应字段的稳定键，供蓝图或外部系统再次定位。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FGenericPropertyFieldKey GetFieldKey() const;

	/** 返回描述符中的显示名称，供值控件同步主标签。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FText GetDisplayName() const;

	/** 返回描述符中的提示文本，供值控件同步 Tooltip。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FText GetTooltip() const;

	/** 返回描述符样式键，供 UI 选择样式或控件变体。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FName GetStyleKey() const;

	/** 返回描述符视觉标签，供规则匹配和蓝图逻辑使用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FGameplayTagContainer GetVisualTags() const;

	/** 返回当前展示文本，混合值和 Warning 节点会使用特殊反馈文本。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FText GetValueText() const;

	/** 返回当前 Issue 文本，供 UI 展示校验或操作失败原因。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API FText GetFeedbackText() const;

	/** 判断当前状态是否允许用户编辑。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool IsEditable() const;

	/** 判断控件是否应保持启用状态。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool IsEnabled() const;

	/** 判断控件是否应显示在当前过滤结果中。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool IsVisible() const;

	/** 判断当前值是否与源值不同。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool IsDirty() const;

	/** 判断当前值是否存在阻断提交的错误。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool IsInvalid() const;

	/** 判断多对象会话中该字段是否存在不同源值。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool HasMixedValues() const;

	/** 判断外部源值变化是否与本地脏值冲突。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool HasConflict() const;

	/** 返回描述符节点类型，供 UI 判断值或容器分支。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API EGenericPropertyNodeKind GetNodeKind() const;

	/** 返回描述符值类型，供 typed 值控件匹配。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API EGenericPropertyValueType GetValueType() const;

	/** 从旧节点或反射路径重新读取源值并广播句柄变化。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API virtual void Refresh();

	/** 将 CurrentValue 写回目标对象或旧属性节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API virtual bool Apply();

	/** 按重置模式恢复 CurrentValue 并同步句柄状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API virtual bool Reset(EGenericPropertyResetMode InMode);

	/** 接收 UI 序列化输入，校验并更新 CurrentValue、脏状态和 Issue。 */
	GENERICPROPERTYFRAMEWORK_API virtual bool CommitSerializedValueInternal(const FString& InValue);

	/** 在当前目标集合中解析一个代表性 FProperty，typed getter 用它反序列化缓存文本。 */
	GENERICPROPERTYFRAMEWORK_API bool ResolveRepresentativeProperty(const FProperty*& OutProperty) const;

	/** 懒加载并返回子值句柄列表，结构体和容器句柄会复用它。 */
	GENERICPROPERTYFRAMEWORK_API const TArray<TObjectPtr<UGenericPropertyValueHandleBase>>& GetChildHandlesInternal();

	/** 初始化句柄，使运行时状态与输入配置保持一致。 */
	GENERICPROPERTYFRAMEWORK_API void InitializeHandle(UGenericPropertyProxy* InOwnerProxy, const TSharedPtr<FGenericPropertySessionCore>& InSessionCore, const FGenericPropertyDescriptor& InDescriptor, UGenericProperty* InLegacyProperty);

	/** 公共属性描述符，决定句柄类型、显示文本和反射路径。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	FGenericPropertyDescriptor Descriptor;

	/** 当前句柄状态，供值控件查询可见、可编辑、脏和错误标志。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	FGenericPropertyState State;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyValueHandleChanged OnHandleChangedEvent;

protected:
	/** 初始化完成后的扩展点，派生句柄可在此准备额外状态。 */
	GENERICPROPERTYFRAMEWORK_API virtual void OnInitialized();

	/** 广播值变化或结构变化，驱动值控件刷新。 */
	GENERICPROPERTYFRAMEWORK_API virtual void NotifyHandleChanged(bool bValueChanged, bool bStructureChanged);

	/** 通过反射路径直接刷新源值，不依赖旧属性节点。 */
	GENERICPROPERTYFRAMEWORK_API virtual bool RefreshDirect();

	/** 通过反射路径把 CurrentValue 直接写入目标对象。 */
	GENERICPROPERTYFRAMEWORK_API virtual bool ApplyDirect();

	/** 在直接反射模式下恢复源值或默认值。 */
	GENERICPROPERTYFRAMEWORK_API virtual bool ResetDirect(EGenericPropertyResetMode InMode);

	/** 确保直接反射模式下的子句柄已经生成。 */
	GENERICPROPERTYFRAMEWORK_API virtual void EnsureDirectChildren();

	/** 尝试从指定目标解析并导出该字段的序列化值。 */
	GENERICPROPERTYFRAMEWORK_API bool TryReadResolvedValue(const UObject* InTarget, FString& OutSerializedValue, const FProperty*& OutProperty, FText* OutError = nullptr) const;

	/** 尝试从类默认对象读取该字段的默认序列化值。 */
	GENERICPROPERTYFRAMEWORK_API bool TryReadDefaultValue(FString& OutSerializedValue) const;

	/** 尝试用反射属性和元数据校验序列化输入。 */
	GENERICPROPERTYFRAMEWORK_API bool TryValidateSerializedValue(const FString& InValue, FText& OutError) const;

	/** 尝试把序列化输入写入所有有效目标对象。 */
	GENERICPROPERTYFRAMEWORK_API bool TryWriteSerializedValue(const FString& InValue, FText& OutError);

	/** 从旧属性节点同步文本值和状态，保证旧节点 UI 与句柄 API 一致。 */
	GENERICPROPERTYFRAMEWORK_API void SyncFromLegacyProperty();

	/** 更新直接反射模式的源值、默认值、当前值和无效标志。 */
	GENERICPROPERTYFRAMEWORK_API void UpdateDirectState(const FString& InSourceValue, const FString& InDefaultValue, const FString& InCurrentValue, bool bHadSuccessfulRead);

	/** 句柄当前编辑中的序列化值。 */
	FString CurrentValue;

	/** 最近一次从目标对象读取的序列化源值。 */
	FString SourceValue;

	/** 从类默认对象读取的序列化默认值。 */
	FString DefaultValue;

	/** 拥有者代理弱引用，避免句柄延长会话生命周期。 */
	TWeakObjectPtr<UGenericPropertyProxy> OwnerProxy;

	/** 弱引用Legacy属性，避免运行时回调延长对象生命周期。 */
	TWeakObjectPtr<UGenericProperty> LegacyProperty;

	/** 创建该句柄的会话核心弱引用，用于创建子句柄。 */
	TWeakPtr<FGenericPropertySessionCore> SessionCore;

	/** 子值句柄缓存，结构体字段和容器元素会按需写入。 */
	UPROPERTY(Transient)
	TArray<TObjectPtr<UGenericPropertyValueHandleBase>> ChildHandles;

	/** 子句柄是否已经完成懒加载。 */
	bool bChildrenInitialized=false;
};

/** 布尔值句柄，将序列化文本缓存和 bool 输入输出互转。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyBoolValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 bool。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(bool& OutValue) const;

	/** 将 SourceValue 反序列化为 bool。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(bool& OutValue) const;

	/** 将 DefaultValue 反序列化为 bool。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(bool& OutValue) const;

	/** 序列化 bool 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(bool InValue);

	/** 提交 bool 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(bool InValue);
};

/** 字节值句柄，将 uint8 与底层整型反射属性的序列化文本互转。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyByteValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 uint8。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(uint8& OutValue) const;

	/** 将 SourceValue 反序列化为 uint8。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(uint8& OutValue) const;

	/** 将 DefaultValue 反序列化为 uint8。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(uint8& OutValue) const;

	/** 序列化 uint8 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(uint8 InValue);

	/** 提交 uint8 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(uint8 InValue);
};

/** 32 位整数值句柄，将 int32 输入输出转换为属性面板序列化文本。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyIntegerValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 int32。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(int32& OutValue) const;

	/** 将 SourceValue 反序列化为 int32。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(int32& OutValue) const;

	/** 将 DefaultValue 反序列化为 int32。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(int32& OutValue) const;

	/** 序列化 int32 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(int32 InValue);

	/** 提交 int32 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(int32 InValue);
};

/** 64 位整数值句柄，将 int64 输入输出转换为属性面板序列化文本。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyInteger64ValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 int64。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(int64& OutValue) const;

	/** 将 SourceValue 反序列化为 int64。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(int64& OutValue) const;

	/** 将 DefaultValue 反序列化为 int64。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(int64& OutValue) const;

	/** 序列化 int64 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(int64 InValue);

	/** 提交 int64 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(int64 InValue);
};

/** 单精度浮点值句柄，将 float 输入输出转换为属性面板序列化文本。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyFloatValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 float。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(float& OutValue) const;

	/** 将 SourceValue 反序列化为 float。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(float& OutValue) const;

	/** 将 DefaultValue 反序列化为 float。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(float& OutValue) const;

	/** 序列化 float 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(float InValue);

	/** 提交 float 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(float InValue);
};

/** 双精度浮点值句柄，将 double 输入输出转换为属性面板序列化文本。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyDoubleValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 double。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(double& OutValue) const;

	/** 将 SourceValue 反序列化为 double。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(double& OutValue) const;

	/** 将 DefaultValue 反序列化为 double。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(double& OutValue) const;

	/** 序列化 double 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(double InValue);

	/** 提交 double 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(double InValue);
};

/** 字符串值句柄，直接把 FString 与面板序列化文本互通。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyStringValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 FString。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(FString& OutValue) const;

	/** 将 SourceValue 反序列化为 FString。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(FString& OutValue) const;

	/** 将 DefaultValue 反序列化为 FString。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(FString& OutValue) const;

	/** 序列化 FString 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(const FString& InValue);

	/** 提交 FString 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(const FString& InValue);
};

/** 本地化文本值句柄，将 FText 输入输出转换为面板序列化文本。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyTextValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 FText。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(FText& OutValue) const;

	/** 将 SourceValue 反序列化为 FText。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(FText& OutValue) const;

	/** 将 DefaultValue 反序列化为 FText。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(FText& OutValue) const;

	/** 序列化 FText 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(const FText& InValue);

	/** 提交 FText 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(const FText& InValue);
};

/** 名称值句柄，将 FName 输入输出转换为面板序列化文本。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyNameValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 FName。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(FName& OutValue) const;

	/** 将 SourceValue 反序列化为 FName。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(FName& OutValue) const;

	/** 将 DefaultValue 反序列化为 FName。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(FName& OutValue) const;

	/** 序列化 FName 输入并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(FName InValue);

	/** 提交 FName 输入到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(FName InValue);
};

/** 对象引用值句柄，将 UObject 引用和反射属性序列化文本互转。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyObjectValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 UObject 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(UObject*& OutValue) const;

	/** 将 SourceValue 反序列化为 UObject 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(UObject*& OutValue) const;

	/** 将 DefaultValue 反序列化为 UObject 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(UObject*& OutValue) const;

	/** 序列化 UObject 引用并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(UObject* InValue);

	/** 提交 UObject 引用到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(UObject* InValue);
};

/** 类引用值句柄，在对象引用读取基础上约束输出为 UClass。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyClassValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为 UClass 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(UClass*& OutValue) const;

	/** 将 SourceValue 反序列化为 UClass 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(UClass*& OutValue) const;

	/** 将 DefaultValue 反序列化为 UClass 引用。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(UClass*& OutValue) const;

	/** 序列化 UClass 引用并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(UClass* InValue);

	/** 提交 UClass 引用到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(UClass* InValue);
};

/** 软对象引用值句柄，将 FSoftObjectPath 文本作为可提交的属性值。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertySoftObjectValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 转换为 FSoftObjectPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(FSoftObjectPath& OutValue) const;

	/** 将 SourceValue 转换为 FSoftObjectPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(FSoftObjectPath& OutValue) const;

	/** 将 DefaultValue 转换为 FSoftObjectPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(FSoftObjectPath& OutValue) const;

	/** 序列化 FSoftObjectPath 并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(const FSoftObjectPath& InValue);

	/** 提交 FSoftObjectPath 到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(const FSoftObjectPath& InValue);
};

/** 软类引用值句柄，将 FSoftClassPath 文本作为可提交的属性值。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertySoftClassValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 转换为 FSoftClassPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(FSoftClassPath& OutValue) const;

	/** 将 SourceValue 转换为 FSoftClassPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(FSoftClassPath& OutValue) const;

	/** 将 DefaultValue 转换为 FSoftClassPath。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(FSoftClassPath& OutValue) const;

	/** 序列化 FSoftClassPath 并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(const FSoftClassPath& InValue);

	/** 提交 FSoftClassPath 到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(const FSoftClassPath& InValue);
};

/** 枚举值句柄，以底层整数读写枚举并保留枚举定义查询入口。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyEnumValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 将 CurrentValue 反序列化为枚举底层整数。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetCurrentValue(int64& OutValue) const;

	/** 将 SourceValue 反序列化为枚举底层整数。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetSourceValue(int64& OutValue) const;

	/** 将 DefaultValue 反序列化为枚举底层整数。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool TryGetDefaultValue(int64& OutValue) const;

	/** 序列化枚举底层整数并更新当前编辑值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool SetCurrentValue(int64 InValue);

	/** 提交枚举底层整数到句柄当前值，沿用统一校验和自动应用流程。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool CommitCurrentValue(int64 InValue);

	/** 从描述符类型路径加载枚举定义，供 UI 构建选项。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UEnum* GetEnumDefinition() const;
};

/** 结构体值句柄，按描述符子字段生成字段句柄并暴露结构体类型信息。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyStructValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 从描述符类型路径加载当前结构体类型。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UScriptStruct* GetStructType() const;

	/** 为结构体 UI 构建字段行，调用前会确保子值句柄已由描述符展开。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API TArray<UGenericPropertyValueHandleBase*> GetFieldHandles();

	/** 按字段名在结构体子句柄中查找对应句柄。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* FindFieldHandle(FName InPropertyName);

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void EnsureDirectChildren() override;
};

/** 容器值句柄基类，统一数组、Set 和 Map 的元素数量与清空入口。 */
UCLASS(MinimalAPI, BlueprintType, Abstract, Transient)
class UGenericPropertyContainerValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()

public:
	/** 为容器 UI 提供元素数量，优先使用句柄子项，兼容旧属性节点子项。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API int32 GetElementCount() const;

	/** 清空旧节点对应的容器值并同步句柄状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool Clear();

protected:
	GENERICPROPERTYFRAMEWORK_API virtual void EnsureDirectChildren() override;
};

/** 数组值句柄，提供数组元素访问、添加、插入、复制、删除和移动操作。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyArrayValueHandle : public UGenericPropertyContainerValueHandle
{
	GENERATED_BODY()

public:
	/** 为数组 UI 定位指定元素的值句柄，供编辑、复制、删除和移动操作复用。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* GetElementHandle(int32 InIndex);

	/** 向数组末尾添加默认元素并刷新子句柄缓存。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool AddElement();

	/** 添加元素后移动到指定索引，实现插入语义。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool InsertElement(int32 InIndex);

	/** 复制指定索引的数组元素。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool DuplicateElement(int32 InIndex);

	/** 移除指定索引的数组元素。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool RemoveElement(int32 InIndex);

	/** 将数组元素从一个索引移动到另一个索引。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool MoveElement(int32 InFromIndex, int32 InToIndex);
};

/** Set 值句柄，提供单对象 Set 元素访问、添加和删除操作。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertySetValueHandle : public UGenericPropertyContainerValueHandle
{
	GENERATED_BODY()

public:
	/** 返回指定索引的 Set 元素句柄。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* GetElementHandle(int32 InIndex);

	/** 向 Set 添加默认元素。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool AddElement();

	/** 移除指定索引的 Set 元素。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool RemoveElement(int32 InIndex);
};

/** Map 值句柄，提供条目数量、键值子句柄访问和单对象条目增删操作。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyMapValueHandle : public UGenericPropertyContainerValueHandle
{
	GENERATED_BODY()

public:
	/** 为 Map UI 显示条目总数，并与键值子句柄列表保持同步。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API int32 GetEntryCount() const;

	/** 返回指定条目的 Key 子句柄。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* GetKeyHandle(int32 InIndex);

	/** 返回指定条目的 Value 子句柄。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* GetValueHandle(int32 InIndex);

	/** 向 Map 添加默认键值对条目。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool AddEntry();

	/** 移除指定索引的 Map 条目。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool RemoveEntry(int32 InIndex);
};

/** 警告值句柄，用于把不支持或异常属性作为只读反馈展示。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyWarningValueHandle : public UGenericPropertyValueHandleBase
{
	GENERATED_BODY()
};
