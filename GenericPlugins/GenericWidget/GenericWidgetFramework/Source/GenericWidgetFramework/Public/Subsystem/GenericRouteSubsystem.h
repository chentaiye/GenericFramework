// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayMessageSubsystem.h"
#include "GameplayTagContainer.h"
#include "Interface/GenericRouteInterface.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "UObject/ScriptInterface.h"
#include "GenericRouteSubsystem.generated.h"

class APlayerController;
struct FOnLayerRegisteredMessage;
struct FOnLayerUnregisteredMessage;
struct FOnLayoutRegisteredMessage;
struct FOnLayoutUnregisteredMessage;
struct FOnSlotRegisteredMessage;
struct FOnSlotUnregisteredMessage;
struct FOnWidgetRegisteredMessage;
struct FOnWidgetUnregisteredMessage;
struct FOnWidgetRegisteredToOwnerMessage;
struct FOnWidgetUnregisteredFromOwnerMessage;
class UGameplayTagSlot;
class UGenericLayer;
class UGenericLayout;
class UGenericWidget;

/** 保存通用 UI流程中的通用路由节点数据，供运行时传递和蓝图访问。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FGenericRouteNode
{
	GENERATED_BODY()

	/** 记录路由。 */
	UPROPERTY()
	TScriptInterface<IGenericRouteInterface> Route;

	/** 记录Owner。 */
	UPROPERTY()
	TScriptInterface<IGenericRouteInterface> Owner;

	/** 记录路由标签。 */
	UPROPERTY()
	FGameplayTag RouteTag;

	/** 保存Children列表。 */
	UPROPERTY()
	TArray<TScriptInterface<IGenericRouteInterface>> Children;

	/** 标记当前路由节点是否已经完成激活。 */
	UPROPERTY()
	bool bIsActive = false;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnRouteRegisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Route Registered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Route Registered Message")
	TScriptInterface<IGenericRouteInterface> Route;

	UPROPERTY(BlueprintReadOnly, Category="Route Registered Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnRouteUnregisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Route Unregistered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Route Unregistered Message")
	TScriptInterface<IGenericRouteInterface> Route;

	UPROPERTY(BlueprintReadOnly, Category="Route Unregistered Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

/** 维护本地玩家通用UI路由树。 */
UCLASS(MinimalAPI)
class UGenericRouteSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API static UGenericRouteSubsystem* Get(const APlayerController* PlayerController);
	GENERICWIDGETFRAMEWORK_API static UGenericRouteSubsystem* Get(const ULocalPlayer* LocalPlayer);

	/** 将实现路由接口的对象包装为脚本接口。 */
	GENERICWIDGETFRAMEWORK_API static TScriptInterface<IGenericRouteInterface> MakeRouteInterface(UObject* InObject);

public:
	/** 注册一个通用UI路由节点。 */
	GENERICWIDGETFRAMEWORK_API bool RegisterRoute(TScriptInterface<IGenericRouteInterface> InRoute, TScriptInterface<IGenericRouteInterface> InOwner = TScriptInterface<IGenericRouteInterface>());

	/** 注销一个通用UI路由节点及其子节点。 */
	GENERICWIDGETFRAMEWORK_API bool UnregisterRoute(TScriptInterface<IGenericRouteInterface> InRoute);

	/** 获取指定路由节点的父级节点。 */
	GENERICWIDGETFRAMEWORK_API TScriptInterface<IGenericRouteInterface> GetRouteOwner(TScriptInterface<IGenericRouteInterface> InRoute) const;

	/** 获取指定路由节点的直接子节点。 */
	GENERICWIDGETFRAMEWORK_API TArray<TScriptInterface<IGenericRouteInterface>> GetRouteChildren(TScriptInterface<IGenericRouteInterface> InRoute) const;

	/** 获取全部已注册的路由节点。 */
	GENERICWIDGETFRAMEWORK_API TArray<TScriptInterface<IGenericRouteInterface>> GetAllRoutes() const;

	/** 获取全部根路由节点。 */
	GENERICWIDGETFRAMEWORK_API TArray<TScriptInterface<IGenericRouteInterface>> GetRootRoutes() const;

	/** 检查指定路由节点是否已经处于激活状态。 */
	GENERICWIDGETFRAMEWORK_API bool IsRouteActive(TScriptInterface<IGenericRouteInterface> InRoute) const;

	/** 检查指定路由节点是否挂在另一个路由节点下。 */
	GENERICWIDGETFRAMEWORK_API bool IsRouteDescendantOf(TScriptInterface<IGenericRouteInterface> InRoute, TScriptInterface<IGenericRouteInterface> InPotentialOwner) const;

public:
	GENERICWIDGETFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICWIDGETFRAMEWORK_API virtual void Deinitialize() override;

private:
	/** 查找指定路由接口对应的节点索引。 */
	void HandleLayoutRegistered(FGameplayTag InChannel, const FOnLayoutRegisteredMessage& InMessage);
	void HandleLayoutUnregistered(FGameplayTag InChannel, const FOnLayoutUnregisteredMessage& InMessage);
	void HandleLayerRegistered(FGameplayTag InChannel, const FOnLayerRegisteredMessage& InMessage);
	void HandleLayerUnregistered(FGameplayTag InChannel, const FOnLayerUnregisteredMessage& InMessage);
	void HandleSlotRegistered(FGameplayTag InChannel, const FOnSlotRegisteredMessage& InMessage);
	void HandleSlotUnregistered(FGameplayTag InChannel, const FOnSlotUnregisteredMessage& InMessage);
	void HandleWidgetRegistered(FGameplayTag InChannel, const FOnWidgetRegisteredMessage& InMessage);
	void HandleWidgetUnregistered(FGameplayTag InChannel, const FOnWidgetUnregisteredMessage& InMessage);
	void HandleWidgetRegisteredToOwner(FGameplayTag InChannel, const FOnWidgetRegisteredToOwnerMessage& InMessage);
	void HandleWidgetUnregisteredFromOwner(FGameplayTag InChannel, const FOnWidgetUnregisteredFromOwnerMessage& InMessage);

	void ActivateRoute(TScriptInterface<IGenericRouteInterface> InRoute);
	void DeactivateRoute(TScriptInterface<IGenericRouteInterface> InRoute);

	/** 获取路由节点声明的本地玩家归属。 */
	ULocalPlayer* GetRouteOwnerPlayer(TScriptInterface<IGenericRouteInterface> InRoute) const;

	/** 检查路由节点是否可以进入当前本地玩家的路由树。 */
	bool CanRegisterRouteForLocalPlayer(TScriptInterface<IGenericRouteInterface> InRoute, TScriptInterface<IGenericRouteInterface> InOwner) const;

	/** 判断Should句柄路由Unregistration是否成立，用于控制通用 UI后续流程。 */
	bool ShouldHandleRouteUnregistration(TScriptInterface<IGenericRouteInterface> InRoute) const;

	int32 FindRouteNodeIndex(TScriptInterface<IGenericRouteInterface> InRoute) const;

	/** 检查路由接口是否可以注册。 */
	bool IsValidRoute(TScriptInterface<IGenericRouteInterface> InRoute, FGameplayTag* OutRouteTag = nullptr) const;

	/** 检查路由标签是否位于允许的根标签下。 */
	bool IsValidRouteTag(FGameplayTag InRouteTag) const;

	/** 将子路由添加到父级节点。 */
	void AddChildRoute(TScriptInterface<IGenericRouteInterface> InOwner, TScriptInterface<IGenericRouteInterface> InChild);

	/** 将子路由从父级节点移除。 */
	void RemoveChildRoute(TScriptInterface<IGenericRouteInterface> InOwner, TScriptInterface<IGenericRouteInterface> InChild);

	/** 判断两个路由接口是否指向同一对象。 */
	bool IsSameRoute(TScriptInterface<IGenericRouteInterface> InLeft, TScriptInterface<IGenericRouteInterface> InRight) const;
	bool IsMessageForThisPlayer(const APlayerController* InPlayerController) const;

private:
	/** 保存路由节点列表，供通用 UI批量处理。 */
	UPROPERTY()
	TArray<FGenericRouteNode> RouteNodes;

	FGameplayMessageListenerHandle LayoutRegisteredListenerHandle;
	FGameplayMessageListenerHandle LayoutUnregisteredListenerHandle;
	FGameplayMessageListenerHandle LayerRegisteredListenerHandle;
	FGameplayMessageListenerHandle LayerUnregisteredListenerHandle;
	FGameplayMessageListenerHandle SlotRegisteredListenerHandle;
	FGameplayMessageListenerHandle SlotUnregisteredListenerHandle;
	FGameplayMessageListenerHandle WidgetRegisteredListenerHandle;
	FGameplayMessageListenerHandle WidgetUnregisteredListenerHandle;
	FGameplayMessageListenerHandle WidgetRegisteredToOwnerListenerHandle;
	FGameplayMessageListenerHandle WidgetUnregisteredFromOwnerListenerHandle;
};
