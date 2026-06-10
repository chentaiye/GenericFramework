// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "MenuSubsystem.generated.h"

class APlayerController;
class UMenuCollection;

USTRUCT(BlueprintType)
struct GENERICMENUFRAMEWORK_API FOnMenuCollectionRegisteredMessage
{
	GENERATED_BODY()

	/** 标识触发本次注册的本地玩家控制器，用于同一世界存在多个本地玩家时区分来源。 */
	UPROPERTY(BlueprintReadOnly, Category="Menu Collection Registered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	/** 标识本次注册进入菜单子系统的集合名称，监听方可据此过滤业务菜单。 */
	UPROPERTY(BlueprintReadOnly, Category="Menu Collection Registered Message")
	FName CollectionName = NAME_None;

	/** 指向刚完成注册的菜单集合实例，后续菜单构建和清理都围绕该对象发生。 */
	UPROPERTY(BlueprintReadOnly, Category="Menu Collection Registered Message")
	TObjectPtr<UMenuCollection> MenuCollection = nullptr;
};

USTRUCT(BlueprintType)
struct GENERICMENUFRAMEWORK_API FOnMenuCollectionUnregisteredMessage
{
	GENERATED_BODY()

	/** 标识触发本次反注册的本地玩家控制器，用于按玩家拆分菜单事件。 */
	UPROPERTY(BlueprintReadOnly, Category="Menu Collection Unregistered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	/** 标识刚离开菜单子系统的集合名称，反注册后集合可能已清理运行时 UI。 */
	UPROPERTY(BlueprintReadOnly, Category="Menu Collection Unregistered Message")
	FName CollectionName = NAME_None;

	/** 指向刚完成反注册的菜单集合实例，监听方应只读取必要状态。 */
	UPROPERTY(BlueprintReadOnly, Category="Menu Collection Unregistered Message")
	TObjectPtr<UMenuCollection> MenuCollection = nullptr;
};

/** 管理单个本地玩家拥有的运行时菜单集合实例。 */
UCLASS(MinimalAPI)
class UMenuSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICMENUFRAMEWORK_API static UMenuSubsystem* Get(const APlayerController* PlayerController);
	GENERICMENUFRAMEWORK_API static UMenuSubsystem* Get(const ULocalPlayer* LocalPlayer);

public:
	/** 注册已存在的菜单集合，并可立即构建对应菜单 UI。 */
	GENERICMENUFRAMEWORK_API bool RegisterMenuCollection(UMenuCollection* InMenuCollection, bool bBuildMenu = true);

	/** 为当前本地玩家创建指定类型的菜单集合，并可立即构建对应菜单 UI。 */
	GENERICMENUFRAMEWORK_API UMenuCollection* RegisterMenuCollection(TSubclassOf<UMenuCollection> InMenuCollectionClass, bool bBuildMenu = true);

	/** 注销指定菜单集合，并可清理由其生成的运行时菜单 UI。 */
	GENERICMENUFRAMEWORK_API bool UnregisterMenuCollection(UMenuCollection* InMenuCollection, bool bClearMenu = true);

	/** 注销当前子系统持有的全部菜单集合。 */
	GENERICMENUFRAMEWORK_API void ClearMenuCollections(bool bClearMenu = true);

	/** 检查指定菜单集合是否已经注册到当前本地玩家。 */
	GENERICMENUFRAMEWORK_API bool HasMenuCollection(UMenuCollection* InMenuCollection) const;

	/** 查找第一个使用指定有效名称注册的菜单集合。 */
	GENERICMENUFRAMEWORK_API UMenuCollection* GetMenuCollection(FName InCollectionName) const;

	/** 按名称查找第一个仍然有效的已注册菜单集合。 */
	GENERICMENUFRAMEWORK_API UMenuCollection* GetMenuCollectionByName(FName InCollectionName) const;

	/** 检查指定名称是否存在仍然有效的已注册菜单集合。 */
	GENERICMENUFRAMEWORK_API bool HasMenuCollection(FName InCollectionName) const;

	/** 获取当前本地玩家全部仍然有效的菜单集合。 */
	GENERICMENUFRAMEWORK_API TArray<UMenuCollection*> GetAllMenuCollections() const;

	GENERICMENUFRAMEWORK_API virtual void Deinitialize() override;

private:
	/** 查找指定菜单集合对象在注册列表中的索引。 */
	int32 FindMenuCollectionIndex(const UMenuCollection* InMenuCollection) const;

	/** 查找指定集合名称在注册列表中对应的索引。 */
	int32 FindMenuCollectionIndex(FName InCollectionName) const;

private:
	/** 持有RegisteredMenuCollections实例，供通用 UI运行时复用。 */
	UPROPERTY()
	TArray<TObjectPtr<UMenuCollection>> RegisteredMenuCollections;
};
