#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyDescriptor.h"
#include "Core/GenericPropertyTypes.h"
#include "UObject/ObjectKey.h"
#include "UObject/Object.h"
#include "GenericPropertyProxy.generated.h"

class UGenericPropertyCollection;
class UGenericPropertyDataSourceCollection;
class UGenericProperty;
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
class UGenericPropertyArrayValueHandle;
class UGenericPropertySetValueHandle;
class UGenericPropertyMapValueHandle;
class FGenericPropertySessionCore;

/** 单个目标对象积累的待同步变更，代理按对象合并通知后再批量刷新受影响节点。 */
struct FGenericPropertyPendingTargetChanges
{
	/** 发生变更的目标对象弱引用，避免队列延长对象生命周期。 */
	TWeakObjectPtr<UObject> Target;

	/** 为 true 时忽略细粒度路径并刷新整个目标对象的属性树。 */
	bool bRefreshWholeObject = false;

	/** 按顶级成员名合并的变更，布尔值表示是否需要结构刷新。 */
	TMap<FName, bool> DirtyMemberProperties;

	/** 按精确属性路径合并的变更，布尔值表示是否需要结构刷新。 */
	TMap<FString, bool> DirtyPropertyPaths;

	bool HasPendingChanges() const { return bRefreshWholeObject || !DirtyMemberProperties.IsEmpty() || !DirtyPropertyPaths.IsEmpty(); }

	/** 清空已合并的变更，供代理完成刷新后复用队列项。 */
	void Reset()
	{
		bRefreshWholeObject = false;
		DirtyMemberProperties.Reset();
		DirtyPropertyPaths.Reset();
	}
};

/** 属性面板会话代理，负责目标对象跟踪、数据源建树、变更同步和值句柄创建。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyProxy : public UObject
{
	GENERATED_BODY()

public:
	/** 配置目标对象、面板选项和数据源类，并立即构建初始属性树。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void Initialize(const TArray<UObject*>& InTargets, const FGenericPropertyPanelOptions& InOptions, TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass);

	/** 替换当前目标对象集合，重建数据源、会话核心、节点树和待处理变更。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetTargets(const TArray<UObject*>& InTargets);

	/** 通过数据源重新生成根节点，并通知已绑定集合重建分类展示。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void Rebuild();

	/** 刷新当前根节点的源值和展示状态，并在需要时刷新集合展示。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void Refresh();

	/** 批量应用所有可直接编辑且已变脏的节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ApplyAll();

	/** 批量重置所有可直接编辑节点，并在批处理结束时刷新变更队列。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ResetAll(EGenericPropertyResetMode InMode);

	/** 创建或返回绑定到该代理的属性集合对象。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCollection* CreateCollection();

	/** 在指定类上解析字段路径，得到后续值句柄可使用的稳定字段键。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ResolveField(UClass* InObjectClass, const FString& InFieldPath, FGenericPropertyFieldKey& OutFieldKey);

	/** 在当前目标集合中查找第一个可解析字段路径，并返回字段键。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ResolveFieldForTargets(const FString& InFieldPath, FGenericPropertyFieldKey& OutFieldKey);

	/** 为已有属性节点创建或复用值句柄，供 UMG 值控件读写该节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* CreateValueHandleForProperty(UGenericProperty* InProperty);

	/** 基于字段类型生成通用值句柄，供属性面板读写对应数据。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* CreateValueHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 先从当前目标解析字段路径，再创建对应值句柄。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyValueHandleBase* CreateValueHandleForPath(const FString& InFieldPath);

	/** 为指定字段创建布尔值句柄，供属性面板读写布尔属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyBoolValueHandle* CreateBoolHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建字节值句柄，供属性面板读写字节或枚举底层值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyByteValueHandle* CreateByteHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建整数值句柄，供属性面板读写 32 位整数属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyIntegerValueHandle* CreateIntegerHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建 64 位整数值句柄，供属性面板读写长整型属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyInteger64ValueHandle* CreateInteger64HandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建浮点值句柄，供属性面板读写单精度属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyFloatValueHandle* CreateFloatHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建双精度值句柄，供属性面板读写双精度属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyDoubleValueHandle* CreateDoubleHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建字符串值句柄，供属性面板读写字符串属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyStringValueHandle* CreateStringHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建文本值句柄，供属性面板读写本地化文本属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyTextValueHandle* CreateTextHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建名称值句柄，供属性面板读写 FName 属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyNameValueHandle* CreateNameHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建枚举值句柄，供属性面板读写枚举属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyEnumValueHandle* CreateEnumHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建对象引用句柄，供属性面板读写 UObject 属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyObjectValueHandle* CreateObjectHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建类引用句柄，供属性面板读写 UClass 属性。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyClassValueHandle* CreateClassHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建软对象引用句柄，供属性面板读写异步对象引用。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertySoftObjectValueHandle* CreateSoftObjectHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建软类引用句柄，供属性面板读写异步类引用。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertySoftClassValueHandle* CreateSoftClassHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建结构体值句柄，供属性面板展开并读写结构体成员。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyStructValueHandle* CreateStructHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建数组值句柄，供属性面板管理容器元素。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyArrayValueHandle* CreateArrayHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建 Set 容器句柄，供属性面板管理唯一元素集合。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertySetValueHandle* CreateSetHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 为指定字段创建 Map 容器句柄，供属性面板管理键值对元素。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyMapValueHandle* CreateMapHandleForField(const FGenericPropertyFieldKey& InFieldKey);

	/** 返回当前反射树根节点，集合按这些节点重建分类。 */
	const TArray<TObjectPtr<UGenericProperty>>& GetRootNodes() const { return RootNodes; }

	/** 返回代理当前跟踪的目标对象弱引用列表。 */
	const TArray<TWeakObjectPtr<UObject>>& GetTargets() const { return Targets; }

	/** 供节点创建和提交逻辑读取本次面板会话的过滤、编辑和显示策略。 */
	const FGenericPropertyPanelOptions& GetOptions() const { return Options; }

	/** 返回当前数据源实例，节点通过它读写和构建子节点。 */
	UGenericPropertyDataSourceCollection* GetDataSource() const { return DataSource; }

	/** 判断代理是否已经拥有有效数据源和目标对象。 */
	bool IsReady() const { return bInitialized; }

	/** 判断Tracks目标对象是否仍由代理跟踪，避免对无效对象继续同步。 */
	bool TracksTargetObject(const UObject* InObject) const;

	/** 判断代理是否仍保留任何目标引用，即使目标可能已经失效。 */
	GENERICPROPERTYFRAMEWORK_API bool HasAnyTrackedTargets() const;

	/** 判断目标集合中是否至少有一个仍然有效的 UObject。 */
	GENERICPROPERTYFRAMEWORK_API bool HasAnyValidTargets() const;

	/** 判断变更队列中是否存在需要同步到节点树的有效目标变更。 */
	GENERICPROPERTYFRAMEWORK_API bool HasPendingPropertyChanges() const;

	/** 根据同步模式和上次刷新时间判断是否触发自动刷新。 */
	GENERICPROPERTYFRAMEWORK_API bool ShouldAutoRefresh(const double InCurrentTimeSeconds) const;

	/** 分发对象属性变更；批处理中进入队列，否则立即刷新受影响节点。 */
	GENERICPROPERTYFRAMEWORK_API bool DispatchObjectPropertyChanged(UObject* InObject, FName InMemberPropertyName, FName InLeafPropertyName, const bool bStructuralChange);

	/** 分发属性路径变更；批处理中按路径合并，否则立即刷新受影响节点。 */
	GENERICPROPERTYFRAMEWORK_API bool DispatchPropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange);

	/** 立即处理对象属性变更并刷新集合展示。 */
	GENERICPROPERTYFRAMEWORK_API bool NotifyObjectPropertyChanged(UObject* InObject, FName InMemberPropertyName, FName InLeafPropertyName, const bool bStructuralChange);

	/** 立即处理属性路径变更并刷新集合展示。 */
	GENERICPROPERTYFRAMEWORK_API bool NotifyPropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange);

	/** 在同步策略允许时把对象属性变更加入待处理队列。 */
	GENERICPROPERTYFRAMEWORK_API bool QueueObjectPropertyChanged(UObject* InObject, FName InMemberPropertyName, FName InLeafPropertyName, const bool bStructuralChange);

	/** 在同步策略允许时把属性路径变更加入待处理队列。 */
	GENERICPROPERTYFRAMEWORK_API bool QueuePropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange);

	/** 消费待处理变更队列，按合并后的成员名或路径刷新节点。 */
	GENERICPROPERTYFRAMEWORK_API bool FlushPendingPropertyChanges();

	/** 清空待处理变更队列。 */
	GENERICPROPERTYFRAMEWORK_API void ClearPendingPropertyChanges();

	/** 开始一段批量修改，期间分发的变更会先进入队列。 */
	GENERICPROPERTYFRAMEWORK_API void BeginMutationBatch();

	/** 结束一层批量修改，并在最外层结束时刷新队列。 */
	GENERICPROPERTYFRAMEWORK_API bool EndMutationBatch();

	/** 绑定集合对象，代理刷新后会通知该集合同步展示。 */
	GENERICPROPERTYFRAMEWORK_API void SetCollection(UGenericPropertyCollection* InCollection);

	/** 标记节点查找索引失效，下一次属性变更处理前会重建。 */
	GENERICPROPERTYFRAMEWORK_API void InvalidateNodeLookupCaches();

	/** 保存已创建值句柄，避免会话中句柄被垃圾回收。 */
	GENERICPROPERTYFRAMEWORK_API void RegisterValueHandle(UGenericPropertyValueHandleBase* InValueHandle);

	/** 返回会话核心对象，供高级代码访问描述符和值句柄缓存。 */
	TSharedPtr<FGenericPropertySessionCore> GetSessionCore() const { return SessionCore; }

protected:
	/** 在处理变更前按根节点递归构建属性名、EditCondition 和精确路径索引。 */
	void EnsureNodeLookupCaches();

	/** 将对象属性变更写入待同步队列，并按同步策略决定是否接受手动模式下的入队。 */
	GENERICPROPERTYFRAMEWORK_API bool EnqueueObjectPropertyChanged(UObject* InObject, FName InMemberPropertyName, FName InLeafPropertyName, const bool bStructuralChange, const bool bAllowManualSync);

	/** 将属性路径变更写入待同步队列，并合并父子路径以减少重复刷新。 */
	GENERICPROPERTYFRAMEWORK_API bool EnqueuePropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange, const bool bAllowManualSync);

	/** 使用节点索引刷新成员属性或编辑条件依赖命中的节点。 */
	GENERICPROPERTYFRAMEWORK_API bool ProcessObjectPropertyChanged(UObject* InObject, FName InMemberPropertyName, FName InLeafPropertyName, const bool bStructuralChange, const bool bRefreshPresentation);

	/** 使用精确路径和父路径回退刷新受路径变更影响的节点。 */
	GENERICPROPERTYFRAMEWORK_API bool ProcessPropertyPathChanged(UObject* InObject, const FString& InPropertyPath, const bool bStructuralChange, const bool bRefreshPresentation);

	/** 弱引用目标对象集合，避免运行时回调延长对象生命周期。 */
	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UObject>> Targets;

	/** 当前会话的数据源实例，负责实际反射建树和值读写。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericPropertyDataSourceCollection> DataSource;

	/** 当前目标对象生成出的根属性节点列表。 */
	UPROPERTY(Transient)
	TArray<TObjectPtr<UGenericProperty>> RootNodes;

	/** 已绑定的集合对象，代理刷新时通过它更新 UI 展示数据。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericPropertyCollection> Collection;

	/** 初始化时指定的数据源类型，目标切换时用它创建新数据源实例。 */
	UPROPERTY(Transient)
	TSubclassOf<UGenericPropertyDataSourceCollection> DataSourceClass;

	/** 当前会话的面板选项，影响建树、编辑、同步和冲突策略。 */
	FGenericPropertyPanelOptions Options;

	/** 是否已经成功创建数据源并绑定至少一个目标对象。 */
	bool bInitialized=false;

	/** 最近一次刷新或变更同步时间，用于自动刷新间隔判断。 */
	double LastRefreshTimeSeconds=0.0;

	/** 节点查找索引是否需要重建。 */
	bool bNodeLookupDirty=true;

	/** 弱引用按顶级属性索引的节点缓存，避免运行时回调延长对象生命周期。 */
	TMap<FName, TArray<TWeakObjectPtr<UGenericProperty>>> NodesByTopLevelProperty;

	/** 弱引用按编辑条件依赖索引的节点缓存，避免运行时回调延长对象生命周期。 */
	TMap<FName, TArray<TWeakObjectPtr<UGenericProperty>>> NodesByEditConditionDependency;

	/** 弱引用按精确属性路径索引的节点缓存，避免运行时回调延长对象生命周期。 */
	TMap<FString, TWeakObjectPtr<UGenericProperty>> NodesByExactPropertyPath;

	/** 按目标对象合并的待处理属性变更队列。 */
	TMap<TObjectKey<UObject>, FGenericPropertyPendingTargetChanges> PendingChangesByTarget;

	/** 当前批量修改的嵌套深度，归零时才刷新待处理队列。 */
	int32 MutationBatchDepth=0;

	/** 描述符和值句柄缓存核心，目标切换时重建。 */
	TSharedPtr<FGenericPropertySessionCore> SessionCore;

	/** 已创建值句柄的强引用列表，保证 UI 使用期间句柄有效。 */
	UPROPERTY(Transient)
	TArray<TObjectPtr<UGenericPropertyValueHandleBase>> RegisteredValueHandles;
};
