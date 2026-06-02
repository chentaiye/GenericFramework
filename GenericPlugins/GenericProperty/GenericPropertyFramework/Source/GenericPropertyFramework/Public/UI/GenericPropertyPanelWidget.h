#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"
#include "Base/GenericWidget.h"
#include "GenericPropertyPanelWidget.generated.h"

class UGenericPropertyCollection;
class UGenericPropertyDataSourceCollection;
class UGenericPropertyCategory;
class UGenericProperty;
class UGenericPropertyPanelWidget;
class UListView;
class UUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnGenericPropertyPanelCollectionChanged,
	UGenericPropertyPanelWidget*,
	Widget,
	UGenericPropertyCollection*,
	InCollection
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(
	FOnGenericPropertyPanelCountsChanged,
	UGenericPropertyPanelWidget*,
	Widget,
	int32,
	DirtyCount,
	int32,
	InvalidCount,
	int32,
	ConflictCount
);

/** 顶层属性面板控件，绑定属性集合并把分类列表、统计变化和集合生命周期暴露给蓝图。 */
UCLASS(MinimalAPI, Abstract, Blueprintable)
class UGenericPropertyPanelWidget : public UGenericWidget
{
	GENERATED_BODY()

public:
	/** 构造面板默认状态并保留通用控件初始化入口。 */
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyPanelWidget(const FObjectInitializer& ObjectInitializer);

	GENERICPROPERTYFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICPROPERTYFRAMEWORK_API virtual void NativeDestruct() override;

	/** 供蓝图和分类列表访问当前集合，所有分类、统计和提交操作都以它为根。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCollection* GetPropertyCollection() const;

	/** 替换当前集合，绑定集合委托并按需重建分类项。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetPropertyCollection(UGenericPropertyCollection* InCollection);

	/** 通过属性子系统为单个目标创建集合并绑定到面板。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCollection* InitializePropertyCollectionForObject(
		UObject* InTarget,
		const FGenericPropertyPanelOptions& InOptions,
		TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass);

	/** 初始化属性集合用于对象集合，使运行时状态与输入配置保持一致。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCollection* InitializePropertyCollectionForObjects(
		const TArray<UObject*>& InTargets,
		const FGenericPropertyPanelOptions& InOptions,
		TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass);

	/** 解绑当前集合；如果是面板创建的集合可选择同时交给子系统销毁。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void ClearPropertyCollection(bool bDestroyCollection = true);

	/** 请求当前集合从代理刷新属性树状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void RefreshPropertyCollection();

	/** 应用集合中所有脏属性值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ApplyPropertyCollection();

	/** 按指定模式重置集合中所有可编辑属性值。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API bool ResetPropertyCollection(EGenericPropertyResetMode InMode);

	/** 更新集合搜索文本并刷新可见分类。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetCollectionSearchText(const FString& InSearchText);

	/** 更新集合ShowAdvancedProperties并同步相关运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetCollectionShowAdvancedProperties(bool bInShowAdvancedProperties);

	/** 将当前集合切换为单目标对象会话。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetCollectionTargetObject(UObject* InTarget);

	/** 写入集合集合目标对象集合并同步属性面板内部状态。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void SetCollectionTargetObjects(const TArray<UObject*>& InTargets);

	/** 返回集合中当前可见的分类，供 ListView 填充。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API TArray<UGenericPropertyCategory*> GetVisibleCategories() const;

	/** 用可见分类重新填充绑定的分类 ListView。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void RebuildGeneratedChildren();

	/** 清空绑定 ListView 中由面板生成的分类项。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void ClearGeneratedChildren();

protected:
	/** 蓝图扩展点：集合绑定完成后同步面板外观或外部状态，随后 SetPropertyCollection 会广播绑定事件。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCollectionSet(UGenericPropertyCollection* InCollection);

	/** 蓝图扩展点：集合解绑时清理面板展示状态，旧集合仍可用于迁移蓝图侧显示。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCollectionCleared(UGenericPropertyCollection* InPreviousCollection);

	/** 蓝图扩展点：集合重建后刷新蓝图侧分类展示，原生处理会同步统计并按需重建列表。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCollectionRebuilt(UGenericPropertyCollection* InCollection);

	/** 蓝图扩展点：搜索、高级显示或折叠状态变化后同步面板展示，原生处理会刷新分类列表。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCollectionPresentationChanged(UGenericPropertyCollection* InCollection);

	/** 蓝图扩展点：脏值、无效值和冲突计数变化后更新面板统计展示。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void OnPropertyCollectionCountsChanged(int32 InDirtyCount, int32 InInvalidCount, int32 InConflictCount);

	/** 响应集合结构重建，广播事件、同步计数并重建分类列表。 */
	GENERICPROPERTYFRAMEWORK_API void HandlePropertyCollectionRebuilt(UGenericPropertyCollection* InCollection);

	/** 响应集合展示状态变化，广播事件、同步计数并刷新分类列表。 */
	GENERICPROPERTYFRAMEWORK_API void HandlePropertyCollectionPresentationChanged(UGenericPropertyCollection* InCollection);

	/** 在分类条目控件生成后注入所属面板并触发分类子项重建。 */
	GENERICPROPERTYFRAMEWORK_API void HandleCategoryEntryWidgetGenerated(UUserWidget& InWidget);

	/** 在根属性条目控件生成后注入所属面板并触发行子项重建。 */
	GENERICPROPERTYFRAMEWORK_API void HandleRootPropertyEntryWidgetGenerated(UUserWidget& InWidget);

	/** 面板析构时是否销毁由自身创建并拥有的集合。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	bool bDestroyOwnedCollectionOnDestruct=true;

	/** 集合结构或展示变化后是否自动重建分类 ListView。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	bool bAutoRebuildChildrenOnCollectionChanged=true;

	/** 可选绑定的分类 ListView，面板会向其中写入可见分类。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property", meta=(BindWidgetOptional, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UListView> ListView_Categories=nullptr;

	/** 当前绑定的属性集合实例。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyCollection> PropertyCollection=nullptr;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyPanelCollectionChanged OnPropertyCollectionSetEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyPanelCollectionChanged OnPropertyCollectionClearedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyPanelCollectionChanged OnPropertyCollectionRebuiltEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyPanelCollectionChanged OnPropertyCollectionPresentationChangedEvent;

	UPROPERTY(BlueprintAssignable, Category="Generic Property")
	FOnGenericPropertyPanelCountsChanged OnPropertyCollectionCountsChangedEvent;

	/** 当前集合是否由该面板通过子系统创建并负责销毁。 */
	bool bOwnsPropertyCollection=false;
};
