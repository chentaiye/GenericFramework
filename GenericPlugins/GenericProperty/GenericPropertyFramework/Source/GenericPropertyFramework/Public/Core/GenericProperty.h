#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"
#include "UObject/Object.h"
#include "GenericProperty.generated.h"

class UGenericPropertyProxy;
class UGenericProperty;
class UEnum;
class UScriptStruct;

DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegate_OnGenericPropertyViewModelChanged, UGenericProperty*, bool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBPDelegate_OnGenericPropertyViewModelChanged, UGenericProperty*, InViewModel, bool, bStructureChanged);

/** 属性树中的单个节点，保存反射字段状态并把数据源读写、搜索、展开和 UI 通知串联起来。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericProperty : public UObject
{
	GENERATED_BODY()

public:
	/** 反射字段名或容器元素名，用于搜索、路径索引和节点缓存。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FName PropertyName=NAME_None;

	/** 节点所属分类，集合重建时按该值归入 UGenericPropertyCategory。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FName CategoryName=NAME_None;

	/** 面板可读路径，代理按路径刷新变更时用于精确命中节点。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FString PropertyPath;

	/** 行名称控件展示的本地化名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FText DisplayName;

	/** 行名称和值控件同步到 Tooltip 的说明文本。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FText ToolTip;

	/** 当前节点的警告或错误状态，失败操作和校验结果都会写入这里。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FGenericPropertyIssue Issue;

	/** 属性值语义类型，用于值控件映射和句柄选择。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	EGenericPropertyValueType TypeName=EGenericPropertyValueType::Unknown;

	/** 反射属性的原生 C++ 类型名，供搜索、样式和内置值控件匹配。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FName NativeTypeName=NAME_None;

	/** 枚举或结构体等类型对象路径，供句柄延迟加载类型定义。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FString TypeObjectPath;

	/** 节点结构形态，决定是否可展开、如何生成子节点以及可执行哪些容器命令。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	EGenericPropertyNodeKind NodeKind=EGenericPropertyNodeKind::Value;

	/** 源值、当前值和默认值的序列化文本状态，用于提交、重置和脏状态比较。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FGenericPropertyNodeTextState TextState;

	/** 反射字段是否被框架支持；不支持时会降级为 Warning 节点。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsSupported=true;

	/** 节点是否可以通过数据源构建子节点。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bCanExpand=false;

	/** 节点是否支持通过序列化文本直接编辑目标属性。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bSupportsDirectEdit=false;

	/** 节点当前是否通过搜索、高级属性和子节点可见性筛选。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsVisible=true;

	/** 节点自身文本是否匹配当前集合搜索词，父节点可据此保留可见链路。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bMatchesSearch=true;

	/** 当前节点是否允许用户编辑，受只读配置、EditCondition 和属性标志共同影响。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsEditable=false;

	/** 当前节点在 UI 中是否启用；可展开分支即使不可直接编辑也可保持启用。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsEnabled=true;

	/** 节点是否来自 AdvancedDisplay 属性，集合展示时可被高级开关隐藏。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsAdvanced=false;

	/** 当前值或任一子节点是否与源值不一致。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsDirty=false;

	/** 当前值或任一子节点是否存在阻断提交的错误。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsInvalid=false;

	/** 多对象会话中该节点解析出的源值是否不一致。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bHasMixedValues=false;

	/** 外部源值变化与本地脏值是否发生冲突。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bHasConflict=false;

	/** 节点在 UI 中是否展开，展开时数据源会按需构建子节点。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsExpanded=false;

	/** 当前节点是否允许新增容器元素。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bSupportsAddElement=false;

	/** 当前节点或容器元素是否允许从父容器移除。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bSupportsRemoveElement=false;

	/** 当前数组元素是否允许复制到同一父数组中。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bSupportsDuplicateElement=false;

	/** 当前数组元素是否允许在父数组中重新排序。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bSupportsReorderElement=false;

	/** 当前容器节点是否允许清空所有子元素。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bSupportsClearChildren=false;

	/** 节点在父容器中的运行时索引，结构操作会用它定位元素。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	int32 ContainerElementIndex=INDEX_NONE;

	/** 元数据键缓存，用于搜索文本构建和蓝图快速展示。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	TArray<FName> MetadataKeys;

	/** 从元数据解析出的视觉标签，供映射规则和 UI 逻辑匹配。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FGameplayTagContainer VisualTags;

	/** 当前展开或预构建出的子属性节点。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	TArray<TObjectPtr<UGenericProperty>> Children;

	/** 父节点引用，用于状态向上汇总和容器结构操作刷新父路径。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericProperty> ParentNode;

	/** 所属代理，节点通过它访问数据源、选项和目标对象集合。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyProxy> OwningProxy;

	/** 将当前序列化值通过数据源写回目标对象，并触发路径刷新。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool Apply();

	/** 按指定模式把当前值回退到源值或类默认值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool Reset(EGenericPropertyResetMode InMode);

	/** 从数据源重新读取该节点并同步展示状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void Refresh();

	/** 更新展开状态，并在展开时按需重建子节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetExpanded(const bool bInExpanded);

	/** 向当前容器追加元素，并通过代理刷新受影响的属性路径。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool AddContainerElement();

	/** 从父容器移除当前元素节点，并刷新父节点结构。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool RemoveNode();

	/** 复制当前数组元素到相邻位置，并刷新父数组结构。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool DuplicateNode();

	/** 将当前数组元素移动到新索引，并刷新父数组结构。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool MoveArrayElement(const int32 InNewIndex);

	/** 清空当前容器值，并刷新该节点的子节点结构。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ClearContainer();

	/** 判断该分支是否至少有一个可见子节点，供父级可见性汇总。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool HasVisibleChildren() const;

	/** 判断该节点是否是支持结构操作的顶层容器节点。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool IsContainerNode() const;

	/** 判断节点视觉标签中是否包含指定精确标签。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool HasVisualTag(FGameplayTag InTag) const;

	/** 绑定所属代理，后续刷新和写入都会通过该代理访问数据源。 */
	GENERICPROPERTYFRAMEWORK_API void Initialize(UGenericPropertyProxy* InProxy);

	/** 重新汇总自身和子节点的脏、无效、可见状态。 */
	GENERICPROPERTYFRAMEWORK_API void RecalculateState();

	/** 从数据源刷新节点值和状态，并在变化时向父链广播。 */
	GENERICPROPERTYFRAMEWORK_API bool RefreshFromSource();

	/** 使搜索文本缓存失效，下一次搜索匹配时重新构建。 */
	GENERICPROPERTYFRAMEWORK_API void InvalidateSearchableText();

	/** 向原生和蓝图监听者广播节点值或结构变化。 */
	GENERICPROPERTYFRAMEWORK_API void BroadcastChanged(const bool bStructureChanged);

	/** 返回结构化访问路径，供反射解析和字段键构建复用。 */
	const FGenericPropertyAccessPath& GetAccessPath() const { return AccessPath; }

	/** 返回元数据映射，供校验、搜索和值句柄描述符构建使用。 */
	const TMap<FName, FString>& GetMetadata() const { return Metadata; }

	/** 更新元数据缓存，并同步 MetadataKeys、VisualTags 与搜索文本缓存。 */
	void SetMetadata(TMap<FName, FString>&& InMetadata);

	/** 更新结构化访问路径，并使搜索文本缓存失效。 */
	GENERICPROPERTYFRAMEWORK_API void SetAccessPath(const FGenericPropertyAccessPath& InPath);

	/** 同步值类型、原生类型名和类型对象路径，供 UI 映射和值句柄读取。 */
	GENERICPROPERTYFRAMEWORK_API void SetInternalTypeName(EGenericPropertyValueType InTypeName, FName InNativeTypeName, FString InTypeObjectPath = FString());

	/** 接收 UI 输入的序列化值，执行校验、脏状态更新，并在自动模式下尝试应用。 */
	GENERICPROPERTYFRAMEWORK_API void CommitSerializedValueInternal(const FString& InValue);

	/** 构建或返回缓存的搜索文本，集合刷新展示时用它匹配搜索词。 */
	GENERICPROPERTYFRAMEWORK_API FString GetSearchableText() const;

	/** 标记属性当前不可编辑，并记录面板需要展示的问题原因。 */
	GENERICPROPERTYFRAMEWORK_API void MarkUnsupported(const FText& InMessage, EGenericPropertyIssueType InIssueType = EGenericPropertyIssueType::UnsupportedType);

	/** 同时更新当前值和源值，用于成功写回后清除脏状态。 */
	GENERICPROPERTYFRAMEWORK_API void SetCurrentAndSourceValue(const FString& InValue);

	/** 写入类默认值缓存，供 ClassDefault 重置模式使用。 */
	GENERICPROPERTYFRAMEWORK_API void SetDefaultValue(const FString& InValue);

	/** 把校验结果转换为节点无效状态和 Issue 内容。 */
	GENERICPROPERTYFRAMEWORK_API void SetValidationState(const FGenericPropertyValidationResult& InValidationResult);

	/** 根据搜索词和高级属性开关递归更新节点可见性。 */
	GENERICPROPERTYFRAMEWORK_API void UpdateVisibilityFromSearch(const FString& InSearchText, const bool bShowAdvanced);

	/** 完整元数据映射，供校验、标签解析和搜索缓存构建使用。 */
	TMap<FName, FString> Metadata;

	/** 结构化反射访问路径，数据源读写目标值时使用。 */
	FGenericPropertyAccessPath AccessPath;

	/** 反射元数据中的编辑条件表达式，刷新节点时用于计算可编辑状态。 */
	FString EditConditionExpression;

	/** 对象引用展开深度，配合面板选项阻止无限递归。 */
	int32 ObjectRecursionDepth=0;

	/** 标记已构建子节点需要重新从数据源生成。 */
	bool bChildrenDirty=false;

	/** 标记搜索文本缓存需要重建。 */
	bool bSearchableTextDirty=true;

	/** 缓存由名称、路径、元数据和标签拼接出的搜索文本。 */
	FString CachedSearchableText;

	FDelegate_OnGenericPropertyViewModelChanged Delegate_OnViewModelChanged;
	UPROPERTY(BlueprintAssignable, Category="Events")
	FBPDelegate_OnGenericPropertyViewModelChanged BPDelegate_OnViewModelChanged;
};
