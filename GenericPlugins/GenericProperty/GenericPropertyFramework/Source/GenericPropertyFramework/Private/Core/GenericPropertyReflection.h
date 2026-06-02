#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"

class UGenericPropertyProxy;
class UGenericProperty;

namespace GenericPropertyFramework::Private
{
	/** 反射缓存内部使用的属性描述，保留 FProperty 指针和构建节点所需的元数据。 */
	struct FPropertyDescriptor : public TSharedFromThis<FPropertyDescriptor>
	{
		/** 反射属性名，用于节点命名和字段键生成。 */
		FName PropertyName = NAME_None;

		/** 从 Category 元数据解析出的分类名。 */
		FName CategoryName = NAME_None;

		/** 反射属性 C++ 类型名。 */
		FName TypeName = NAME_None;

		/** 枚举、结构体等类型对象路径。 */
		FString TypeObjectPath;

		/** 从反射字段解析出的显示名。 */
		FText DisplayName;

		/** 从反射字段解析出的提示文本。 */
		FText ToolTip;

		/** 以点号和容器标记拼接的属性路径。 */
		FString PropertyPath;

		/** 原始 EditCondition 表达式。 */
		FString EditConditionExpression;

		/** 根据属性种类推断出的节点结构类型。 */
		EGenericPropertyNodeKind NodeKind = EGenericPropertyNodeKind::Value;

		/** 解析到该属性所需的结构化访问路径。 */
		FGenericPropertyAccessPath AccessPath;

		/** 结构体属性预构建出的子属性描述。 */
		TArray<TSharedPtr<FPropertyDescriptor>> Children;

		/** 复制出的受支持元数据键值。 */
		TMap<FName, FString> Metadata;

		/** 指向原始反射属性，节点刷新和值解析依赖它。 */
		const FProperty* Property = nullptr;

		/** 声明该属性的结构体或类，用于根属性过滤。 */
		const UStruct* OwnerStruct = nullptr;

		/** 该属性是否带 AdvancedDisplay 元数据。 */
		bool bIsAdvanced = false;

		/** 该属性是否理论上可展开为子节点。 */
		bool bCanExpand = false;

		/** 该属性是否支持序列化文本直接写回。 */
		bool bSupportsDirectEdit = false;

		/** 框架是否支持展示或编辑该属性。 */
		bool bIsSupported = true;

		/** 对象属性是否允许展开内部对象字段。 */
		bool bAllowObjectExpansion = false;

		/** 反射遍历顺序，用于保持属性展示稳定。 */
		int32 SortOrder = 0;
	};

	/** 访问路径解析后的目标值位置和容器上下文。 */
	struct FResolvedValue
	{
		/** 最终解析到的反射属性。 */
		const FProperty* Property = nullptr;

		/** 最终解析到的值内存指针。 */
		void* ValuePtr = nullptr;

		/** 路径解析过程中命中的数组属性上下文。 */
		const FArrayProperty* ArrayProperty = nullptr;

		/** 路径解析过程中命中的 Set 属性上下文。 */
		const FSetProperty* SetProperty = nullptr;

		/** 路径解析过程中命中的 Map 属性上下文。 */
		const FMapProperty* MapProperty = nullptr;

		/** 解析是否成功。 */
		bool bSuccess = false;

		/** 解析失败时写给节点 Issue 或调用方的原因。 */
		FString FailureReason;
	};

	/** 按 UStruct 缓存反射描述符，避免每次建树都重新遍历属性元数据。 */
	class FReflectionCache
	{
	public:
		static FReflectionCache& Get();

		/** 按 UClass 取得根属性描述符缓存，供代理首次建树时复用反射结果。 */
		const TArray<TSharedPtr<FPropertyDescriptor>>& GetClassDescriptor(const UClass* InClass);

		/** 按 UStruct 取得成员属性描述符缓存，供结构体字段句柄展开子节点。 */
		const TArray<TSharedPtr<FPropertyDescriptor>>& GetStructDescriptor(const UStruct* InStruct);

	private:
		/** 构建或返回指定结构体的属性描述符缓存。 */
		const TArray<TSharedPtr<FPropertyDescriptor>>& BuildDescriptor(const UStruct* InStruct);

		/** 遍历结构体属性并生成子描述符列表。 */
		void BuildChildren(const UStruct* InStruct, const FGenericPropertyAccessPath& InParentPath, const FString& InParentPathString, TArray<TSharedPtr<FPropertyDescriptor>>& OutChildren);

		/** 将单个 FProperty 转换为内部描述符并递归处理结构体成员。 */
		TSharedPtr<FPropertyDescriptor> BuildDescriptorForProperty(const FProperty& InProperty, const FGenericPropertyAccessPath& InParentPath, const FString& InParentPathString, int32 InSortOrder);

		/** 以结构体对象键索引的描述符缓存。 */
		TMap<TObjectKey<const UStruct>, TArray<TSharedPtr<FPropertyDescriptor>>> Cache;
	};

	/** 按访问路径在目标对象上解析到具体属性和值指针。 */
	bool ResolveValue(UObject* InTarget, const FGenericPropertyAccessPath& InPath, FResolvedValue& OutResolvedValue);

	/** 按访问路径在类默认对象上解析默认值。 */
	bool ResolveDefaultValue(const UClass* InClass, const FGenericPropertyAccessPath& InPath, FResolvedValue& OutResolvedValue);

	/** 将 FProperty 类型映射到框架值类型。 */
	EGenericPropertyValueType GetPropertyValueType(const FProperty& InProperty);

	/** 提取反射属性的原生类型名。 */
	FName GetPropertyTypeName(const FProperty& InProperty);

	/** 提取反射属性关联的枚举、结构体或类路径。 */
	FString GetPropertyTypeObjectPath(const FProperty& InProperty);

	/** 判断叶子属性是否可被框架安全序列化和编辑。 */
	bool IsLeafPropertySupported(const FProperty& InProperty);

	/** 判断描述符是否通过面板过滤规则。 */
	bool PassesFilters(const FPropertyDescriptor& InDescriptor, const FGenericPropertyFilterRules& InFilters);

	/** 评估简单 EditCondition 表达式以决定节点可编辑状态。 */
	bool EvaluateEditCondition(const FString& InExpression, UObject* InTarget);

	/** 将反射值导出为面板内部使用的序列化文本。 */
	FString ExportValueToString(const FProperty& InProperty, const void* InValuePtr);

	/** 将序列化文本导入反射值内存，并返回导入错误。 */
	bool ImportValueFromString(const FProperty& InProperty, void* InValuePtr, const FString& InValue, FText& OutError);

	/** 根据属性类型和元数据校验序列化文本。 */
	FGenericPropertyValidationResult ValidateValueText(const FProperty& InProperty, const void* InCurrentValuePtr, const FString& InValue, const TMap<FName, FString>& InMetadata);

	/** 从代理目标对象构建根属性节点。 */
	void BuildRootNodes(UGenericPropertyProxy& InProxy, TArray<UGenericProperty*>& OutNodes);

	/** 根据节点类型动态构建结构体、对象或容器子节点。 */
	void BuildDynamicChildren(UGenericProperty& InNode);

	/** 从目标对象重新读取节点状态、能力标志和文本值。 */
	void RefreshNodeState(UGenericProperty& InNode);
}
