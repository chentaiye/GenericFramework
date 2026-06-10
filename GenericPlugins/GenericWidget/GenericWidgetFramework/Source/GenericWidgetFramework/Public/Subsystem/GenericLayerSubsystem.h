// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayMessageSubsystem.h"
#include "GameplayTagContainer.h"
#include "Interface/GenericRouteInterface.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "UObject/ScriptInterface.h"
#include "GenericLayerSubsystem.generated.h"

class APlayerController;
struct FOnRouteRegisteredMessage;
class UGenericLayer;

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnLayerRegisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Layer Registered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Layer Registered Message")
	FGameplayTag LayerTag;

	UPROPERTY(BlueprintReadOnly, Category="Layer Registered Message")
	TObjectPtr<UGenericLayer> Layer = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Layer Registered Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnLayerUnregisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Layer Unregistered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Layer Unregistered Message")
	FGameplayTag LayerTag;

	UPROPERTY(BlueprintReadOnly, Category="Layer Unregistered Message")
	TObjectPtr<UGenericLayer> Layer = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Layer Unregistered Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

/** 保存已注册 UI 层及其在路由树中的归属关系。 */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FGenericRegisteredLayer
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UGenericLayer> Layer = nullptr;

	UPROPERTY()
	TScriptInterface<IGenericRouteInterface> Owner;
};

/** 维护当前本地玩家的 UI 层注册表，并为自动注册层补齐最近的路由父级。 */
UCLASS(MinimalAPI)
class UGenericLayerSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API static UGenericLayerSubsystem* Get(const APlayerController* PlayerController);
	GENERICWIDGETFRAMEWORK_API static UGenericLayerSubsystem* Get(const ULocalPlayer* LocalPlayer);

public:
	/** 使用显式路由父级注册已有层；注册过程不修改层自身可见性。 */
	GENERICWIDGETFRAMEWORK_API bool RegisterLayer(UGenericLayer* InLayer, TScriptInterface<IGenericRouteInterface> InOwner = TScriptInterface<IGenericRouteInterface>());

	/** 按层在控件树中的最近有效路由父级自动注册，父级尚未激活时进入待重试队列。 */
	GENERICWIDGETFRAMEWORK_API bool RegisterLayerAutomatically(UGenericLayer* InLayer);

	/** 取消自动注册层，或从待重试队列中移除。 */
	GENERICWIDGETFRAMEWORK_API bool UnregisterLayerAutomatically(UGenericLayer* InLayer);

	/** 注销指定层对象。 */
	GENERICWIDGETFRAMEWORK_API bool UnregisterLayer(UGenericLayer* InLayer, bool bRemoveFromParent = true);

	/** 按标签注销指定层。 */
	GENERICWIDGETFRAMEWORK_API bool UnregisterLayerByTag(FGameplayTag InLayerTag, bool bRemoveFromParent = true);

	/** 获取指定标签对应的有效层。 */
	GENERICWIDGETFRAMEWORK_API UGenericLayer* GetLayer(FGameplayTag InLayerTag) const;

	/** 检查指定标签是否已经注册有效层。 */
	GENERICWIDGETFRAMEWORK_API bool HasLayer(FGameplayTag InLayerTag) const;

	/** 显式设置指定层的可见性；注册流程不会再隐式设置可见性。 */
	GENERICWIDGETFRAMEWORK_API bool SetLayerVisibility(FGameplayTag InLayerTag, ESlateVisibility InVisibility);

	/** 获取所有仍然有效的已注册层。 */
	GENERICWIDGETFRAMEWORK_API TArray<UGenericLayer*> GetAllLayers() const;

	/** 获取可见层，并按层自身 ZOrder 从高到低排序。 */
	GENERICWIDGETFRAMEWORK_API TArray<UGenericLayer*> GetAllLayersByPriority() const;

public:
	GENERICWIDGETFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICWIDGETFRAMEWORK_API virtual void Deinitialize() override;

private:
	bool RegisterLayerInternal(UGenericLayer* InLayer, TScriptInterface<IGenericRouteInterface> InOwner, bool bIsAutomatic);
	bool IsLayerOwnedByThisSubsystem(const UGenericLayer* InLayer) const;
	bool IsValidLayerTag(FGameplayTag InLayerTag) const;
	bool UnregisterLayerInternal(FGameplayTag InLayerTag, bool bRemoveFromParent);
	TScriptInterface<IGenericRouteInterface> ResolveNearestRouteOwner(const UGenericLayer* InLayer) const;
	void RetryPendingAutoLayers();
	void HandleRouteRegistered(FGameplayTag InChannel, const FOnRouteRegisteredMessage& InMessage);
	bool IsMessageForThisPlayer(const APlayerController* InPlayerController) const;

private:
	UPROPERTY()
	TMap<FGameplayTag, FGenericRegisteredLayer> RegisteredLayers;

	UPROPERTY()
	TArray<TObjectPtr<UGenericLayer>> PendingAutoLayers;

	FGameplayMessageListenerHandle RouteRegisteredListenerHandle;
};
