#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GenericPropertyCategory.generated.h"

class UGenericProperty;
class UGenericPropertyCategory;

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegate_OnGenericPropertyListChanged, UGenericPropertyCategory*);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPDelegate_OnGenericPropertyListChanged, UGenericPropertyCategory*, InList);

/** 属性集合中的分类分组，负责聚合同一 Category 的根节点并向分类 UI 广播列表变化。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyCategory : public UObject
{
	GENERATED_BODY()

public:
	/** 分类键，集合重建时用根节点 CategoryName 复用或创建分组。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FName CategoryName=NAME_None;

	/** 分类标题显示文本，默认由 CategoryName 转换而来。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FText DisplayName;

	/** 属于该分类的根属性节点列表，列表项由分类控件展示。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	TArray<TObjectPtr<UGenericProperty>> Properties;

	/** 分类是否至少包含一个可见属性节点。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	bool bIsVisible=true;

	/** 判断VisibleProperties是否满足当前属性面板要求。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool HasVisibleProperties() const;

	/** 根据子属性可见性刷新分类可见状态。 */
	GENERICPROPERTYFRAMEWORK_API void RecalculateVisibility();

	/** 通知分类控件刷新属性列表项。 */
	GENERICPROPERTYFRAMEWORK_API void BroadcastListChanged();

	FDelegate_OnGenericPropertyListChanged Delegate_OnListChanged;
	UPROPERTY(BlueprintAssignable, Category="Events")
	FBPDelegate_OnGenericPropertyListChanged BPDelegate_OnListChanged;
};
