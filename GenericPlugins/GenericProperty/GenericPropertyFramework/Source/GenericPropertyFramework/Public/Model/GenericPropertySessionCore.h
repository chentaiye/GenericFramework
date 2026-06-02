#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyDescriptor.h"

class UGenericProperty;
class UGenericPropertyProxy;
class UGenericPropertyValueHandleBase;
class UClass;
class UStruct;

/** 代理内部的会话核心，缓存公共描述符并按字段类型创建可复用的值句柄。 */
class GENERICPROPERTYFRAMEWORK_API FGenericPropertySessionCore : public TSharedFromThis<FGenericPropertySessionCore>
{
public:
	/** 绑定拥有者代理，后续解析字段和值句柄都从该代理读取目标对象和选项。 */
	explicit FGenericPropertySessionCore(UGenericPropertyProxy& InOwnerProxy);

	/** 清空描述符、子描述符和值句柄缓存，供目标类变化后重新解析。 */
	void InvalidateDescriptorCache();

	/** 在指定对象类的描述符缓存中解析字段路径，并可选返回完整描述符。 */
	bool ResolveField(const UClass* InObjectClass, const FString& InFieldPath, FGenericPropertyFieldKey& OutFieldKey, FGenericPropertyDescriptor* OutDescriptor = nullptr);

	/** 使用字段键查找公共描述符，必要时先为当前目标类构建缓存。 */
	bool ResolveDescriptor(const FGenericPropertyFieldKey& InFieldKey, FGenericPropertyDescriptor& OutDescriptor);

	/** 返回指定字段的直接子描述符，用于结构体值句柄懒加载字段句柄。 */
	void GetChildDescriptors(const FGenericPropertyFieldKey& InFieldKey, TArray<FGenericPropertyDescriptor>& OutDescriptors);

	/** 从旧版属性节点构建公共描述符，保持节点 UI 和新值句柄 API 一致。 */
	FGenericPropertyDescriptor BuildDescriptorFromProperty(const UGenericProperty& InProperty) const;

	/** 为属性节点创建或复用值句柄，并同步旧版节点状态。 */
	UGenericPropertyValueHandleBase* CreateValueHandle(UGenericProperty* InProperty);

	/** 为字段键创建或复用值句柄，直接通过反射路径读写目标值。 */
	UGenericPropertyValueHandleBase* CreateValueHandle(const FGenericPropertyFieldKey& InFieldKey);

private:
	/** 确保指定类的反射描述符已经转换到公共描述符缓存。 */
	void EnsureDescriptorsForClass(const UClass* InObjectClass);

	/** 按缓存键创建或复用具体值句柄类，并完成初始化和刷新。 */
	UGenericPropertyValueHandleBase* CreateValueHandleInternal(const FGenericPropertyDescriptor& InDescriptor, UGenericProperty* InLegacyProperty, const FString& InCacheKey);

	/** 根据描述符的原生类型、节点类型和值类型选择最合适的句柄类。 */
	UClass* ResolveHandleClass(const FGenericPropertyDescriptor& InDescriptor) const;

	/** 拥有者代理弱引用，避免会话核心延长代理生命周期。 */
	TWeakObjectPtr<UGenericPropertyProxy> OwnerProxy;

	/** 已构建描述符缓存的结构体或类集合。 */
	TSet<TObjectKey<const UStruct>> CachedStructs;

	/** 以字段稳定键索引的公共描述符缓存。 */
	TMap<FString, FGenericPropertyDescriptor> DescriptorsByKey;

	/** 以父字段稳定键索引的直接子描述符缓存。 */
	TMap<FString, TArray<FGenericPropertyDescriptor>> ChildDescriptorsByKey;

	/** 以属性节点或字段键索引的值句柄弱缓存。 */
	TMap<FString, TWeakObjectPtr<UGenericPropertyValueHandleBase>> HandlesByKey;
};
