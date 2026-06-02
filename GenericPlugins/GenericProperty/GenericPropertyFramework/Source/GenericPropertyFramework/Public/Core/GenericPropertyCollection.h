#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"
#include "UObject/Object.h"
#include "GenericPropertyCollection.generated.h"

class UGenericPropertyCategory;
class UGenericPropertyProxy;
class UGenericPropertyCollection;

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegate_OnGenericPropertyCollectionRebuilt, UGenericPropertyCollection*);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPDelegate_OnGenericPropertyCollectionRebuilt, UGenericPropertyCollection*, InCollection);

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegate_OnGenericPropertyCollectionPresentationChanged, UGenericPropertyCollection*);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPDelegate_OnGenericPropertyCollectionPresentationChanged, UGenericPropertyCollection*, InCollection);

/** 属性面板的数据集合，负责把代理根节点按分类整理，并维护搜索、高级过滤和统计计数。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyCollection : public UObject
{
	GENERATED_BODY()

public:
	/** 绑定代理并从当前目标对象构建分类和节点展示数据。 */
	GENERICPROPERTYFRAMEWORK_API void Initialize(UGenericPropertyProxy* InProxy);

	/** 重新读取代理根节点并复用分类对象，供目标或结构变化后重建列表。 */
	GENERICPROPERTYFRAMEWORK_API void RebuildFromProxy();

	/** 应用搜索和高级属性过滤，并更新脏、无效、冲突统计。 */
	GENERICPROPERTYFRAMEWORK_API void RefreshPresentation();

	/** 更新搜索文本并刷新可见节点和分类。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetSearchText(const FString& InSearchText);

	/** 更新ShowAdvancedProperties并同步相关运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetShowAdvancedProperties(const bool bInShowAdvancedProperties);

	/** 请求代理从目标对象刷新当前属性树状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void Refresh();

	/** 应用所有可编辑且处于脏状态的节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool Apply();

	/** 按指定模式重置所有可编辑节点。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool Reset(EGenericPropertyResetMode InMode);

	/** 将集合代理改为跟踪单个目标对象并触发重建。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetTargetObject(UObject* InTarget);

	/** 写入集合目标对象集合并同步属性面板内部状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetTargetObjects(const TArray<UObject*>& InTargets);

	/** 当前集合关联的代理，所有读写和目标切换都转发给它。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyProxy> Proxy;

	/** 按分类组织后的根属性列表，面板 ListView 直接消费该数组。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	TArray<TObjectPtr<UGenericPropertyCategory>> Categories;

	/** 当前搜索文本，刷新展示时递归匹配节点搜索缓存。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FString SearchText;

	/** 当前是否展示 AdvancedDisplay 属性。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bShowAdvancedProperties=true;

	/** 当前展示树中脏节点数量，用于面板状态栏或蓝图监听。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	int32 DirtyCount=0;

	/** 当前展示树中无效节点数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	int32 InvalidCount=0;

	/** 当前展示树中冲突节点数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	int32 ConflictCount=0;

	FDelegate_OnGenericPropertyCollectionRebuilt Delegate_OnCollectionRebuilt;
	UPROPERTY(BlueprintAssignable, Category="Events")
	FBPDelegate_OnGenericPropertyCollectionRebuilt BPDelegate_OnCollectionRebuilt;
	FDelegate_OnGenericPropertyCollectionPresentationChanged Delegate_OnCollectionPresentationChanged;
	UPROPERTY(BlueprintAssignable, Category="Events")
	FBPDelegate_OnGenericPropertyCollectionPresentationChanged BPDelegate_OnCollectionPresentationChanged;

protected:
	/** 通知面板集合结构已重建，需要重新绑定分类列表。 */
	GENERICPROPERTYFRAMEWORK_API void BroadcastCollectionRebuilt();

	/** 通知面板展示状态或统计计数发生变化。 */
	GENERICPROPERTYFRAMEWORK_API void BroadcastCollectionPresentationChanged();
};
