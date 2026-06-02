#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GenericPropertyTypes.generated.h"

/** 描述属性节点在反射树中的结构形态，驱动子节点构建、值控件选择和容器操作入口。 */
UENUM(BlueprintType)
enum class EGenericPropertyNodeKind : uint8
{
	/** 可直接读写的叶子属性，通常由标量值句柄或基础值控件处理。 */
	Value,

	/** 结构体属性分支，可按成员描述符继续展开子节点。 */
	Struct,

	/** 对象引用分支，可在递归深度允许时展开被引用对象的属性。 */
	Object,

	/** 数组容器分支，支持按索引生成元素节点并执行增删移等结构操作。 */
	Array,

	/** Set 容器分支，单对象会话下按内部索引生成唯一元素节点。 */
	Set,

	/** Map 容器分支，单对象会话下按条目生成键值对子节点。 */
	Map,

	/** Map 运行时合成的条目节点，用于把 Key 和 Value 两个子节点归到同一行。 */
	MapEntry,

	/** 无法正常编辑或展开时的提示节点，用 Issue 消息替代普通值显示。 */
	Warning
};

/** 描述属性值的语义类型，用于会话核心选择值句柄、UI 映射和序列化转换路径。 */
UENUM(BlueprintType)
enum class EGenericPropertyValueType : uint8
{
	/** 未能从反射属性推断出具体类型时的兜底类型。 */
	Unknown,

	/** 布尔值属性，映射到 Bool 句柄和布尔值控件。 */
	Boolean,

	/** 整型数值属性，映射到整数或字节类句柄。 */
	Integer,

	/** 浮点数值属性，映射到 float 或 double 类句柄。 */
	Float,

	/** FString 属性，使用字符串序列化文本作为编辑值。 */
	String,

	/** FName 属性，使用名称文本参与搜索、显示和提交。 */
	Name,

	/** FText 属性，保留本地化文本的显示与提交入口。 */
	Text,

	/** 枚举属性，句柄以底层整数值读写并保留枚举定义路径。 */
	Enum,

	/** UObject 或对象引用类属性，交由对象值控件读写引用。 */
	Object,

	/** 结构体值，主要用于选择结构体句柄并暴露字段子句柄。 */
	Struct,

	/** 数组值，主要用于选择数组容器句柄和容器值控件。 */
	Array,

	/** Set 值，主要用于选择 Set 容器句柄和受限结构操作。 */
	Set,

	/** Map 值，主要用于选择 Map 容器句柄并暴露键值访问。 */
	Map,

	/** Map 条目值，供 UI 把键和值作为一个容器条目处理。 */
	MapEntry,

	/** 警告值，供值控件显示 Issue 文本而不是尝试普通提交。 */
	Warning
};

/** 区分属性节点当前问题的来源，供面板反馈、冲突处理和只读降级显示使用。 */
UENUM(BlueprintType)
enum class EGenericPropertyIssueType : uint8
{
	/** 节点当前没有需要展示或阻断编辑的问题。 */
	None,

	/** 反射属性类型不能安全编辑或展开时使用。 */
	UnsupportedType,

	/** 用户输入未通过属性元数据或类型校验时使用。 */
	Validation,

	/** 本地脏值和外部刷新值产生冲突且策略要求标记时使用。 */
	Conflict,

	/** 对象递归展开达到面板配置的最大深度时使用。 */
	RecursionLimit,

	/** 多对象编辑中结构或引用类型无法对齐时使用。 */
	MultiObjectMismatch,

	/** 只读会话或多对象容器限制阻止结构修改时使用。 */
	ReadOnlyRestriction,

	/** 应用、重置或容器变更等运行时操作失败时使用。 */
	OperationFailed
};

/** 描述属性问题对交互流程的影响级别，控制反馈展示和无效状态判断。 */
UENUM(BlueprintType)
enum class EGenericPropertyIssueSeverity : uint8
{
	/** 无反馈级别，节点按正常状态展示。 */
	None,

	/** 可展示但通常不阻断只读或降级显示的警告。 */
	Warning,

	/** 会标记节点无效并阻断提交的错误。 */
	Error
};

/** 控制编辑值写回目标对象的时机，影响节点和句柄的 Commit/Apply 行为。 */
UENUM(BlueprintType)
enum class EGenericPropertyApplyMode : uint8
{
	/** 用户提交只更新面板当前值，必须显式 Apply 才写回目标对象。 */
	Manual,

	/** 输入校验通过后立即尝试写回目标对象。 */
	Automatic
};

/** 指定重置操作回退到哪个来源值，供节点、集合和值控件共用。 */
UENUM(BlueprintType)
enum class EGenericPropertyResetMode : uint8
{
	/** 回到最近一次从目标对象读取到的源值。 */
	SourceValue,

	/** 回到目标类默认对象上解析到的默认值。 */
	ClassDefault
};

/** 控制外部属性变更同步到属性面板的策略。 */
UENUM(BlueprintType)
enum class EGenericPropertySyncMode : uint8
{
	/** 不自动刷新外部变化，等待显式刷新或手动分发。 */
	Manual,

	/** 属性变更通知到达时尽快同步，并保留兜底刷新间隔。 */
	Immediate,

	/** 把外部变化排队，在配置的间隔后批量刷新。 */
	Deferred
};

/** 定义本地脏值遇到外部源值变化时的解决策略。 */
UENUM(BlueprintType)
enum class EGenericPropertyConflictPolicy : uint8
{
	/** 保留当前本地编辑值，不用外部变化覆盖面板输入。 */
	KeepLocalDirty,

	/** 采用外部最新源值并清除本地脏状态。 */
	TakeExternalValue,

	/** 保留本地值并在节点状态中标记冲突反馈。 */
	MarkConflict
};

/** 表示访问路径中的单步寻址方式，供反射解析器定位属性、容器元素或 Map 键值。 */
UENUM(BlueprintType)
enum class EGenericPropertyAccessType : uint8
{
	/** 按 FProperty 名称进入结构体或对象字段。 */
	Property,

	/** 按索引进入数组元素。 */
	ArrayElement,

	/** 按内部索引进入 Set 元素，主要用于单对象会话。 */
	SetElement,

	/** 按条目索引进入 Map 的 Key 值。 */
	MapKey,

	/** 按条目索引进入 Map 的 Value 值。 */
	MapValue
};

/** 访问路径中的一个段，反射解析器按段依次进入属性或容器元素。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyAccessSegment
{
	GENERATED_BODY()

	/** 当前路径段的寻址方式，决定读取 PropertyName 还是 ElementIndex。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyAccessType Type = EGenericPropertyAccessType::Property;

	/** Type 为 Property 时使用的字段名，用于在 UStruct 上查找 FProperty。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FName PropertyName=NAME_None;

	/** Type 为容器元素或 Map 键值时使用的运行时索引。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	int32 ElementIndex=INDEX_NONE;

	/** 构造空属性段，供蓝图或代码逐步填充访问路径。 */
	FGenericPropertyAccessSegment()=default;

	/** 构造按属性名访问的路径段。 */
	FGenericPropertyAccessSegment(const EGenericPropertyAccessType InType, const FName InPropertyName)
		: Type(InType)
		, PropertyName(InPropertyName)
	{
	}

	/** 构造按容器索引访问的路径段。 */
	FGenericPropertyAccessSegment(const EGenericPropertyAccessType InType, const int32 InElementIndex)
		: Type(InType)
		, ElementIndex(InElementIndex)
	{
	}
};

/** 从目标对象根部到某个属性值的完整反射访问路径。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyAccessPath
{
	GENERATED_BODY()

	/** 按顺序保存访问段，ResolveValue 会依次解析这些段到最终值指针。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TArray<FGenericPropertyAccessSegment> Segments;

	/** 生成稳定可读的路径文本，用于调试、搜索和字段键生成。 */
	FString ToString() const;

	/** 判断路径是否没有任何访问段，避免对无效路径发起反射解析。 */
	bool IsEmpty() const { return Segments.IsEmpty(); }
};

/** 面板建树过滤规则，用于在反射描述符进入节点树前按名称、分类、路径、元数据和类型筛选。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyFilterRules
{
	GENERATED_BODY()

	/** 非空时只允许这些属性名进入面板。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FName> PropertyNameWhitelist;

	/** 排除这些属性名，优先阻止不应暴露的字段。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FName> PropertyNameBlacklist;

	/** 非空时只允许这些分类下的属性进入面板。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FName> CategoryWhitelist;

	/** 排除这些分类下的属性。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FName> CategoryBlacklist;

	/** 非空时只允许路径匹配的反射节点进入面板。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FString> PathWhitelist;

	/** 排除路径匹配的节点，适合隐藏结构体深层字段。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FString> PathBlacklist;

	/** 非空时只允许带有指定元数据键的属性进入面板。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FName> MetadataWhitelist;

	/** 排除带有指定元数据键的属性。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FName> MetadataBlacklist;

	/** 非空时只允许指定原生类型名的属性进入面板。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FName> TypeWhitelist;

	/** 排除指定原生类型名的属性。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSet<FName> TypeBlacklist;
};

/** 面板会话配置，决定反射树生成、编辑策略、同步节奏和过滤范围。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyPanelOptions
{
	GENERATED_BODY()

	/** 将整次会话降为只读，节点仍可展示但不会允许写回或结构变更。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bReadOnly=false;

	/** 控制 AdvancedDisplay 属性是否参与展示和搜索结果。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bShowAdvancedProperties=true;

	/** 允许对象引用节点按对象属性继续展开。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bExpandObjectProperties=false;

	/** 允许结构体节点在建树或展开时生成成员节点。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bExpandStructProperties=true;

	/** 允许数组、Set、Map 节点生成元素或条目子节点。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bExpandContainerProperties=true;

	/** 允许代理同时跟踪多个目标对象，并在节点状态中标记混合值。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bAllowMultiObjectEditing=true;

	/** 建根节点时是否包含父类声明的根属性。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bIncludeSuperClassRootProperties=false;

	/** 控制编辑值是手动应用还是校验通过后自动写回。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyApplyMode ApplyMode=EGenericPropertyApplyMode::Manual;

	/** UI 默认重置动作使用的回退来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyResetMode DefaultResetMode=EGenericPropertyResetMode::SourceValue;

	/** 控制外部属性变更如何同步到当前会话。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertySyncMode SyncMode=EGenericPropertySyncMode::Manual;

	/** 控制本地脏值遇到外部源值变化时的处理策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyConflictPolicy ConflictPolicy=EGenericPropertyConflictPolicy::KeepLocalDirty;

	/** Deferred 同步模式下批量刷新待处理变更的最小间隔。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property", meta=(ClampMin="0.01", UIMin="0.01", EditCondition="SyncMode==EGenericPropertySyncMode::Deferred", EditConditionHides))
	float DeferredSyncIntervalSeconds=0.25f;

	/** Immediate 模式下即使没有明确通知也触发兜底刷新的间隔。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property", meta=(ClampMin="0.0", UIMin="0.0", EditCondition="SyncMode==EGenericPropertySyncMode::Immediate", EditConditionHides))
	float ImmediateFallbackIntervalSeconds=0.5f;

	/** 对象引用递归展开的最大深度，避免自引用对象导致无限建树。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	int32 MaxObjectRecursionDepth=2;

	/** 反射描述符进入节点树前应用的过滤规则集合。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FGenericPropertyFilterRules Filters;
};

/** 属性输入校验的统一返回值，节点和句柄据此更新无效状态与反馈文本。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyValidationResult
{
	GENERATED_BODY()

	/** 为 false 时提交流程会停止并把 Message 写入 Issue。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bSuccess=true;

	/** 校验失败时给 UI 展示的错误说明。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FText Message;
};

/** 数据源读取属性文本值的统一返回值。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyReadResult
{
	GENERATED_BODY()

	/** 指示目标路径是否成功解析并导出值。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bSuccess=false;

	/** 成功读取后传回的序列化属性值。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FString Value;

	/** 读取失败时给调用方和 UI 使用的错误文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FText ErrorMessage;
};

/** 数据源写入、容器变更等修改操作的统一返回值。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyWriteResult
{
	GENERATED_BODY()

	/** 指示修改是否已经安全写入目标对象或容器。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	bool bSuccess=false;

	/** 修改失败时写入节点 Issue 的错误文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FText ErrorMessage;
};

/** 节点维护的三份文本值，用于比较脏状态、重置来源和默认值回退。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyNodeTextState
{
	GENERATED_BODY()

	/** 最近一次从目标对象读取到的序列化值。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FString SourceValue;

	/** 面板当前编辑中的序列化值，未必已经写回目标对象。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FString CurrentValue;

	/** 从类默认对象解析出的序列化值，供 ClassDefault 重置使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FString DefaultValue;
};

/** 节点或句柄的运行时反馈状态，统一承载警告、错误和冲突说明。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyIssue
{
	GENERATED_BODY()

	/** 问题严重级别，决定 UI 是警告展示还是错误阻断。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyIssueSeverity Severity=EGenericPropertyIssueSeverity::None;

	/** 问题来源分类，便于 UI 或上层逻辑区分校验、冲突和操作失败。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyIssueType Type=EGenericPropertyIssueType::None;

	/** 展示给用户或蓝图监听者的反馈文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FText Message;

	/** 判断当前 Issue 是否包含可展示的问题内容。 */
	bool IsSet() const { return Severity != EGenericPropertyIssueSeverity::None && Type != EGenericPropertyIssueType::None && !Message.IsEmpty(); }

	/** 判断当前 Issue 是否是会阻断提交的错误。 */
	bool IsError() const { return Severity == EGenericPropertyIssueSeverity::Error && IsSet(); }

	/** 判断当前 Issue 是否是可展示但不一定阻断流程的警告。 */
	bool IsWarning() const { return Severity == EGenericPropertyIssueSeverity::Warning && IsSet(); }

	/** 清空问题状态，供刷新、成功写入或重置后恢复正常展示。 */
	void Reset()
	{
		Severity = EGenericPropertyIssueSeverity::None;
		Type = EGenericPropertyIssueType::None;
		Message = FText::GetEmpty();
	}
};

/** 根据属性类型、名称、路径、元数据或标签选择专用显示控件的规则。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyVisualRule
{
	GENERATED_BODY()

	/** 规则匹配的值类型；为 Unknown 时不按类型过滤。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	EGenericPropertyValueType TypeName = EGenericPropertyValueType::Unknown;

	/** 规则匹配的属性名；为空时不按属性名过滤。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FName PropertyName=NAME_None;

	/** 属性路径需要包含的片段，用于细分同名或同类型字段。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FString PathContains;

	/** 属性描述符必须带有的元数据键。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FName RequiredMetadata=NAME_None;

	/** 属性节点必须带有的 GameplayTag。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	FGameplayTag RequiredTag;

	/** 多条规则命中时的排序权重。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	int32 Priority=0;

	/** 命中规则后返回给 UI 层创建的值控件类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Property")
	TSoftClassPtr<class UUserWidget> WidgetClass;
};
