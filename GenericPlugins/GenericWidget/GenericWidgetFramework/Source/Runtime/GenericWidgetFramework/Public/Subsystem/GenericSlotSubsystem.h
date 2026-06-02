// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayMessageSubsystem.h"
#include "GameplayTagContainer.h"
#include "Interface/GenericRouteInterface.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "UObject/ScriptInterface.h"
#include "GenericSlotSubsystem.generated.h"

class APlayerController;
struct FOnRouteRegisteredMessage;
class UGameplayTagSlot;
class UWidget;

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnSlotRegisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Slot Registered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Slot Registered Message")
	FGameplayTag SlotTag;

	UPROPERTY(BlueprintReadOnly, Category="Slot Registered Message")
	TObjectPtr<UGameplayTagSlot> Slot = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Slot Registered Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FOnSlotUnregisteredMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Slot Unregistered Message")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Slot Unregistered Message")
	FGameplayTag SlotTag;

	UPROPERTY(BlueprintReadOnly, Category="Slot Unregistered Message")
	TObjectPtr<UGameplayTagSlot> Slot = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Slot Unregistered Message")
	TScriptInterface<IGenericRouteInterface> Owner;
};

/** Registered gameplay tag slot state. */
USTRUCT()
struct GENERICWIDGETFRAMEWORK_API FGenericRegisteredSlot
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UGameplayTagSlot> Slot = nullptr;

	UPROPERTY()
	TScriptInterface<IGenericRouteInterface> Owner;
};

/** Local-player registry and content API for gameplay tagged slots. */
UCLASS(MinimalAPI)
class UGenericSlotSubsystem : public UGenericLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API static UGenericSlotSubsystem* Get(const APlayerController* PlayerController);
	GENERICWIDGETFRAMEWORK_API static UGenericSlotSubsystem* Get(const ULocalPlayer* LocalPlayer);

public:
	/** Register a slot with an explicit route owner. */
	GENERICWIDGETFRAMEWORK_API bool RegisterSlot(UGameplayTagSlot* InSlot, TScriptInterface<IGenericRouteInterface> InOwner);

	/** Register a slot by resolving its nearest active route owner. */
	GENERICWIDGETFRAMEWORK_API bool RegisterSlotAutomatically(UGameplayTagSlot* InSlot);

	/** Unregister an automatically registered slot or remove it from the pending queue. */
	GENERICWIDGETFRAMEWORK_API bool UnregisterSlotAutomatically(UGameplayTagSlot* InSlot);

	/** Unregister a slot object. */
	GENERICWIDGETFRAMEWORK_API bool UnregisterSlot(UGameplayTagSlot* InSlot);

	/** Unregister the slot matching the supplied tag. */
	GENERICWIDGETFRAMEWORK_API bool UnregisterSlotByTag(FGameplayTag InSlotTag);

	/** Return the slot matching the supplied tag. */
	GENERICWIDGETFRAMEWORK_API UGameplayTagSlot* GetSlot(FGameplayTag InSlotTag) const;

	/** Return whether a live slot is registered for the supplied tag. */
	GENERICWIDGETFRAMEWORK_API bool HasSlot(FGameplayTag InSlotTag) const;

	/** 写入集合SlotVisibility并同步通用 UI内部状态。 */
	GENERICWIDGETFRAMEWORK_API bool SetSlotVisibility(FGameplayTag InSlotTag, ESlateVisibility InVisibility);

	/** 写入集合Slot内容并同步通用 UI内部状态。 */
	GENERICWIDGETFRAMEWORK_API bool SetSlotContent(FGameplayTag InSlotTag, UWidget* InContent);

	/** Return content currently assigned to the supplied slot tag. */
	GENERICWIDGETFRAMEWORK_API UWidget* GetSlotContent(FGameplayTag InSlotTag) const;

	/** Clear content from the supplied slot tag. */
	GENERICWIDGETFRAMEWORK_API bool ClearSlotContent(FGameplayTag InSlotTag);

	/** Return all live registered slots. */
	GENERICWIDGETFRAMEWORK_API TArray<UGameplayTagSlot*> GetAllSlots() const;

public:
	GENERICWIDGETFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICWIDGETFRAMEWORK_API virtual void Deinitialize() override;

private:
	bool RegisterSlotInternal(UGameplayTagSlot* InSlot, TScriptInterface<IGenericRouteInterface> InOwner, bool bIsAutomatic);
	bool IsSlotOwnedByThisSubsystem(const UGameplayTagSlot* InSlot) const;
	bool IsValidSlotTag(FGameplayTag InSlotTag) const;
	bool UnregisterSlotInternal(FGameplayTag InSlotTag);
	TScriptInterface<IGenericRouteInterface> ResolveNearestRouteOwner(const UGameplayTagSlot* InSlot) const;
	void RetryPendingAutoSlots();
	void HandleRouteRegistered(FGameplayTag InChannel, const FOnRouteRegisteredMessage& InMessage);
	bool IsMessageForThisPlayer(const APlayerController* InPlayerController) const;

private:
	UPROPERTY()
	TMap<FGameplayTag, FGenericRegisteredSlot> RegisteredSlots;

	UPROPERTY()
	TArray<TObjectPtr<UGameplayTagSlot>> PendingAutoSlots;

	FGameplayMessageListenerHandle RouteRegisteredListenerHandle;
};
