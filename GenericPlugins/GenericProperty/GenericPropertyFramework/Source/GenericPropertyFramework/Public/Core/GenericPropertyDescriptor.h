#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Core/GenericPropertyTypes.h"
#include "GenericPropertyDescriptor.generated.h"

/** 标识一个可解析字段的稳定键，供代理、会话核心和值句柄跨 UI 生命周期复用同一属性位置。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyFieldKey
{
	GENERATED_BODY()

	/** 反射解析用的结构化访问路径。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FGenericPropertyAccessPath AccessPath;

	/** 可读的属性路径文本，用于蓝图输入、搜索和稳定键展示。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FString PropertyPath;

	/** 根据属性访问路径构造描述符，供属性系统定位反射字段。 */
	static FGenericPropertyFieldKey FromAccessPath(const FGenericPropertyAccessPath& InAccessPath);

	/** 生成用于描述符缓存和值句柄缓存的稳定字符串键。 */
	FString ToStableKey() const;

	/** 判断字段键是否至少包含一种可定位信息。 */
	bool IsValid() const { return !AccessPath.IsEmpty() || !PropertyPath.IsEmpty(); }
};

/** 面向公共 API 的属性描述符，连接底层反射信息、值句柄工厂和 UI 映射规则。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyDescriptor
{
	GENERATED_BODY()

	/** 指向反射字段的稳定键，后续创建句柄或查找子描述符都依赖它。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FGenericPropertyFieldKey FieldKey;

	/** 反射字段的原始名称，用于索引、搜索和规则匹配。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FName PropertyName=NAME_None;

	/** 反射字段的分类名，集合重建时按该值聚合属性分类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FName CategoryName=NAME_None;

	/** UI 行名称显示的本地化文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FText DisplayName;

	/** UI 行和值控件展示的提示文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FText ToolTip;

	/** 从元数据或类型推导出的样式键，供值控件选择视觉呈现。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FName StyleKey=NAME_None;

	/** 从元数据解析出的视觉标签集合，供 UI 映射和蓝图逻辑判断。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FGameplayTagContainer VisualTags;

	/** 节点在属性树中的结构形态，决定是否可展开以及使用哪类容器句柄。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyNodeKind NodeKind=EGenericPropertyNodeKind::Value;

	/** 属性值的语义类型，驱动值句柄类和值控件类选择。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyValueType ValueType=EGenericPropertyValueType::Unknown;

	/** 反射属性的 C++ 类型名，用于内置句柄和自定义规则精确匹配。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FName NativeTypeName=NAME_None;

	/** 枚举、结构体等类型对象路径，用于值句柄延迟加载类型定义。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FString TypeObjectPath;

	/** 指示该字段是否可通过序列化文本直接提交，而不是只作为分支展示。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bSupportsDirectEdit=false;

	/** 指示该字段是否可构建子描述符或动态子节点。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bCanExpand=false;

	/** 指示属性框架是否能安全展示或编辑该字段。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bIsSupported=true;

	/** 缓存反射元数据，供校验、样式、搜索和视觉标签解析使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TMap<FName, FString> Metadata;

	/** 原始 EditCondition 表达式，刷新状态时用于判断节点是否可编辑。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FString EditConditionExpression;

	/** 判断描述符是否代表无需展开的直接值节点。 */
	bool IsLeafValue() const { return NodeKind == EGenericPropertyNodeKind::Value; }

	/** 判断描述符是否代表容器或容器条目，供 UI 选择容器交互控件。 */
	bool IsContainerValue() const
	{
		return NodeKind == EGenericPropertyNodeKind::Array
			|| NodeKind == EGenericPropertyNodeKind::Set
			|| NodeKind == EGenericPropertyNodeKind::Map
			|| NodeKind == EGenericPropertyNodeKind::MapEntry;
	}
};

/** 值句柄对 UI 暴露的运行时状态快照，由刷新、校验、提交和冲突处理持续更新。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyState
{
	GENERATED_BODY()

	/** 当前值是否允许用户编辑并提交。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bIsEditable = false;

	/** 当前 UI 是否应保持可交互状态，分支节点即使不可编辑也可能启用以允许展开。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bIsEnabled=false;

	/** 当前节点是否通过搜索、高级属性和父子可见性筛选。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bIsVisible=true;

	/** 当前值是否与最近一次源值不同。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bIsDirty=false;

	/** 当前值是否因校验或操作失败处于无效状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bIsInvalid=false;

	/** 多对象会话中各目标解析到的源值是否不一致。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bHasMixedValues=false;

	/** 本地脏值与外部刷新源值是否存在冲突。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bHasConflict=false;

	/** 分支节点在 UI 中是否处于展开状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bIsExpanded=false;

	/** 当前状态对应的警告或错误反馈。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FGenericPropertyIssue Issue;
};
