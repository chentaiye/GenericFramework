#pragma once

#include "Containers/Ticker.h"
#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"
#include "Subsystems/EngineSubsystem.h"
#include "GenericPropertySubsystem.generated.h"

class UGenericPropertyCollection;
class UGenericPropertyDataSourceCollection;
class UGenericPropertyProxy;
class UGenericPropertyVisualData;
struct FPropertyChangedEvent;

/** 引擎级属性面板子系统，集中创建集合、接收 UObject 属性变更并驱动自动同步。 */
UCLASS(MinimalAPI)
class UGenericPropertySubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	GENERICPROPERTYFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICPROPERTYFRAMEWORK_API virtual void Deinitialize() override;

	/** 为单个目标对象创建代理和集合，供属性面板直接绑定。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCollection* CreatePropertyCollectionForObject(UObject* InTarget, const FGenericPropertyPanelOptions& InOptions, TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass);

	/** 为多个目标对象创建集合，并按面板选项处理多对象编辑限制。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API UGenericPropertyCollection* CreatePropertyCollectionForObjects(const TArray<UObject*>& InTargets, const FGenericPropertyPanelOptions& InOptions, TSubclassOf<UGenericPropertyDataSourceCollection> InDataSourceClass);

	/** 销毁并注销属性集合，避免子系统继续向已释放面板发送刷新。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void DestroyPropertyCollection(UGenericPropertyCollection* InCollection);

	/** 刷新所有仍跟踪指定对象的集合。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void RefreshCollectionsForObject(UObject* InTarget);

	/** 从蓝图或外部系统通知成员属性变化，并转发给相关代理。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void NotifyObjectPropertyChanged(UObject* InTarget, FName InMemberPropertyName);

	/** 从蓝图或外部系统通知精确属性路径变化，并转发给相关代理。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API void NotifyObjectPropertyPathChanged(UObject* InTarget, const FString& InPropertyPath, bool bStructuralChange);

	/** 返回全局视觉规则数据，供面板解析默认值控件或样式。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	UGenericPropertyVisualData* GetVisualData() const { return VisualData; }

protected:
	/** 当前由子系统托管的活动属性集合。 */
	UPROPERTY(Transient)
	TArray<TObjectPtr<UGenericPropertyCollection>> ActiveCollections;

	/** 子系统创建的视觉规则容器。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericPropertyVisualData> VisualData;

	/** Ticker 回调，按各代理同步模式刷新待处理外部变化。 */
	GENERICPROPERTYFRAMEWORK_API bool TickAutoRefresh(float InDeltaTime);

	/** 监听引擎 UObject 属性变化，并提取成员名、叶子名和结构变更标记。 */
	GENERICPROPERTYFRAMEWORK_API void HandleObjectPropertyChanged(UObject* InObject, FPropertyChangedEvent& InPropertyChangedEvent);

	FTSTicker::FDelegateHandle AutoRefreshTickerHandle;

	FDelegateHandle PropertyChangedDelegateHandle;
};
