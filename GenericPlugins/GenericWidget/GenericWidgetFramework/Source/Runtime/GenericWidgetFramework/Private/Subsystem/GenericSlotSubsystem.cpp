// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericSlotSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "Components/PanelWidget.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "Slate/GameplayTagSlot.h"
#include "Subsystem/GenericRouteSubsystem.h"
#include "WidgetType.h"

namespace
{
	void BroadcastSlotRegisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, FGameplayTag SlotTag, UGameplayTagSlot* Slot, TScriptInterface<IGenericRouteInterface> Owner)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSlotRegisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.SlotTag = SlotTag;
		Message.Slot = Slot;
		Message.Owner = Owner;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnSlotRegister, Message);
	}

	void BroadcastSlotUnregisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, FGameplayTag SlotTag, UGameplayTagSlot* Slot, TScriptInterface<IGenericRouteInterface> Owner)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSlotUnregisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.SlotTag = SlotTag;
		Message.Slot = Slot;
		Message.Owner = Owner;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnSlotUnRegister, Message);
	}
}

UGenericSlotSubsystem* UGenericSlotSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<UGenericSlotSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UGenericSlotSubsystem* UGenericSlotSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UGenericSlotSubsystem>(LocalPlayer);
}

bool UGenericSlotSubsystem::RegisterSlot(UGameplayTagSlot* InSlot, TScriptInterface<IGenericRouteInterface> InOwner)
{
	return RegisterSlotInternal(InSlot, InOwner, false);
}

bool UGenericSlotSubsystem::RegisterSlotAutomatically(UGameplayTagSlot* InSlot)
{
	if (!IsValid(InSlot))
	{
		return false;
	}

	for (const TPair<FGameplayTag, FGenericRegisteredSlot>& RegisteredSlotPair : RegisteredSlots)
	{
		if (RegisteredSlotPair.Value.Slot == InSlot)
		{
			return true;
		}
	}

	TScriptInterface<IGenericRouteInterface> Owner = ResolveNearestRouteOwner(InSlot);
	if (!Owner.GetObject())
	{
		PendingAutoSlots.AddUnique(InSlot);
		return false;
	}

	return RegisterSlotInternal(InSlot, Owner, true);
}

bool UGenericSlotSubsystem::UnregisterSlotAutomatically(UGameplayTagSlot* InSlot)
{
	const int32 RemovedPendingCount = PendingAutoSlots.RemoveAll(
		[InSlot](const TObjectPtr<UGameplayTagSlot>& PendingSlot)
		{
			return PendingSlot == InSlot || !IsValid(PendingSlot);
		}
	);

	if (!IsValid(InSlot))
	{
		return RemovedPendingCount > 0;
	}

	for (const TPair<FGameplayTag, FGenericRegisteredSlot>& RegisteredSlotPair : RegisteredSlots)
	{
		if (RegisteredSlotPair.Value.Slot == InSlot)
		{
			return UnregisterSlotInternal(RegisteredSlotPair.Key);
		}
	}

	return RemovedPendingCount > 0;
}

bool UGenericSlotSubsystem::UnregisterSlot(UGameplayTagSlot* InSlot)
{
	if (!IsValid(InSlot))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterSlot failed because slot is null."));
		return false;
	}

	for (const TPair<FGameplayTag, FGenericRegisteredSlot>& RegisteredSlotPair : RegisteredSlots)
	{
		if (RegisteredSlotPair.Value.Slot == InSlot)
		{
			return UnregisterSlotInternal(RegisteredSlotPair.Key);
		}
	}

	UE_LOG(GenericLogUI, Warning, TEXT("UnregisterSlot failed because slot '%s' is not registered."), *InSlot->GetName());
	return false;
}

bool UGenericSlotSubsystem::UnregisterSlotByTag(FGameplayTag InSlotTag)
{
	return UnregisterSlotInternal(InSlotTag);
}

UGameplayTagSlot* UGenericSlotSubsystem::GetSlot(FGameplayTag InSlotTag) const
{
	const FGenericRegisteredSlot* RegisteredSlot = RegisteredSlots.Find(InSlotTag);
	return RegisteredSlot && IsValid(RegisteredSlot->Slot) ? RegisteredSlot->Slot : nullptr;
}

bool UGenericSlotSubsystem::HasSlot(FGameplayTag InSlotTag) const
{
	return GetSlot(InSlotTag) != nullptr;
}

bool UGenericSlotSubsystem::SetSlotVisibility(FGameplayTag InSlotTag, ESlateVisibility InVisibility)
{
	UGameplayTagSlot* Slot = GetSlot(InSlotTag);
	if (!Slot)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSlotVisibility failed because slot is not registered. SlotTag: %s"), *InSlotTag.ToString());
		return false;
	}

	Slot->SetSlotVisibility(InVisibility);
	return true;
}

bool UGenericSlotSubsystem::SetSlotContent(FGameplayTag InSlotTag, UWidget* InContent)
{
	if (!IsValid(InContent) || !IsValidSlotTag(InSlotTag))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSlotContent failed because content or slot tag is invalid. Content: %s, SlotTag: %s"), InContent ? *InContent->GetName() : TEXT("None"), *InSlotTag.ToString());
		return false;
	}

	UGameplayTagSlot* Slot = GetSlot(InSlotTag);
	if (!Slot)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetSlotContent failed because slot is not registered. Content: %s, SlotTag: %s"), *InContent->GetName(), *InSlotTag.ToString());
		return false;
	}

	if (Slot->SetContent(InContent))
	{
		return true;
	}

	UE_LOG(GenericLogUI, Warning, TEXT("SetSlotContent failed to set content. Content: %s, SlotTag: %s"), *InContent->GetName(), *InSlotTag.ToString());
	return false;
}

UWidget* UGenericSlotSubsystem::GetSlotContent(FGameplayTag InSlotTag) const
{
	const UGameplayTagSlot* Slot = GetSlot(InSlotTag);
	return Slot ? Slot->GetContent() : nullptr;
}

bool UGenericSlotSubsystem::ClearSlotContent(FGameplayTag InSlotTag)
{
	if (!IsValidSlotTag(InSlotTag))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("ClearSlotContent failed because slot tag is invalid. SlotTag: %s"), *InSlotTag.ToString());
		return false;
	}

	UGameplayTagSlot* Slot = GetSlot(InSlotTag);
	if (!Slot)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("ClearSlotContent failed because slot is not registered. SlotTag: %s"), *InSlotTag.ToString());
		return false;
	}

	Slot->ClearChildren();
	return true;
}

TArray<UGameplayTagSlot*> UGenericSlotSubsystem::GetAllSlots() const
{
	TArray<UGameplayTagSlot*> Slots;

	for (const TPair<FGameplayTag, FGenericRegisteredSlot>& RegisteredSlotPair : RegisteredSlots)
	{
		if (UGameplayTagSlot* Slot = RegisteredSlotPair.Value.Slot)
		{
			if (IsValid(Slot))
			{
				Slots.Add(Slot);
			}
		}
	}

	return Slots;
}

void UGenericSlotSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (UGameplayMessageSubsystem::HasInstance(this))
	{
		RouteRegisteredListenerHandle = UGameplayMessageSubsystem::Get(this).RegisterListener<FOnRouteRegisteredMessage>(TAG_GameplayMessage_Channel_UI_OnRouteRegister, this, &UGenericSlotSubsystem::HandleRouteRegistered);
	}
}

void UGenericSlotSubsystem::Deinitialize()
{
	RouteRegisteredListenerHandle.Unregister();
	PendingAutoSlots.Reset();

	TArray<FGameplayTag> SlotTags;
	RegisteredSlots.GenerateKeyArray(SlotTags);

	for (const FGameplayTag& SlotTag : SlotTags)
	{
		UnregisterSlotInternal(SlotTag);
	}

	Super::Deinitialize();
}

bool UGenericSlotSubsystem::RegisterSlotInternal(UGameplayTagSlot* InSlot, TScriptInterface<IGenericRouteInterface> InOwner, bool bIsAutomatic)
{
	if (!IsValid(InSlot))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterSlot failed because slot is null."));
		return false;
	}

	if (!InOwner.GetObject())
	{
		if (!bIsAutomatic)
		{
			UE_LOG(GenericLogUI, Warning, TEXT("RegisterSlot failed because owner route is null. Slot: %s, SlotTag: %s"), *InSlot->GetName(), *InSlot->SlotTag.ToString());
		}
		return false;
	}

	if (!IsSlotOwnedByThisSubsystem(InSlot))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterSlot failed because slot '%s' does not belong to this local player. SlotTag: %s"), *InSlot->GetName(), *InSlot->SlotTag.ToString());
		return false;
	}

	if (!IsValidSlotTag(InSlot->SlotTag))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterSlot failed because slot tag is invalid. Slot: %s, SlotTag: %s"), *InSlot->GetName(), *InSlot->SlotTag.ToString());
		return false;
	}

	const FGameplayTag SlotTag = InSlot->SlotTag;

	if (FGenericRegisteredSlot* ExistingRegisteredSlot = RegisteredSlots.Find(SlotTag))
	{
		UGameplayTagSlot* ExistingSlot = ExistingRegisteredSlot->Slot;

		if (ExistingSlot == InSlot)
		{
			if (ExistingRegisteredSlot->Owner.GetObject() == InOwner.GetObject())
			{
				PendingAutoSlots.Remove(InSlot);
				return true;
			}

			ExistingRegisteredSlot->Owner = InOwner;
			PendingAutoSlots.Remove(InSlot);
			BroadcastSlotRegisteredMessage(this, GetPlayerController(), SlotTag, InSlot, InOwner);
			return true;
		}

		if (IsValid(ExistingSlot))
		{
			UE_LOG(GenericLogUI, Warning, TEXT("RegisterSlot failed because slot tag is already registered by slot '%s'. NewSlot: %s, SlotTag: %s"), *ExistingSlot->GetName(), *InSlot->GetName(), *SlotTag.ToString());
			return false;
		}

		RegisteredSlots.Remove(SlotTag);
	}

	FGenericRegisteredSlot& RegisteredSlot = RegisteredSlots.Add(SlotTag);
	RegisteredSlot.Slot = InSlot;
	RegisteredSlot.Owner = InOwner;
	PendingAutoSlots.Remove(InSlot);

	BroadcastSlotRegisteredMessage(this, GetPlayerController(), SlotTag, InSlot, InOwner);
	return true;
}

bool UGenericSlotSubsystem::IsSlotOwnedByThisSubsystem(const UGameplayTagSlot* InSlot) const
{
	const ULocalPlayer* SlotLocalPlayer = InSlot ? InSlot->GetOwningLocalPlayer() : nullptr;
	return !SlotLocalPlayer || SlotLocalPlayer == GetLocalPlayer();
}

bool UGenericSlotSubsystem::IsValidSlotTag(FGameplayTag InSlotTag) const
{
	return InSlotTag.IsValid() && InSlotTag.MatchesTag(TAG_GameplayUI_Slot);
}

bool UGenericSlotSubsystem::UnregisterSlotInternal(FGameplayTag InSlotTag)
{
	FGenericRegisteredSlot RegisteredSlot;

	if (!RegisteredSlots.RemoveAndCopyValue(InSlotTag, RegisteredSlot))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterSlot failed because slot tag is not registered. SlotTag: %s"), *InSlotTag.ToString());
		return false;
	}

	UGameplayTagSlot* Slot = RegisteredSlot.Slot;
	PendingAutoSlots.Remove(Slot);

	BroadcastSlotUnregisteredMessage(this, GetPlayerController(), InSlotTag, Slot, RegisteredSlot.Owner);
	return true;
}

TScriptInterface<IGenericRouteInterface> UGenericSlotSubsystem::ResolveNearestRouteOwner(const UGameplayTagSlot* InSlot) const
{
	TScriptInterface<IGenericRouteInterface> EmptyOwner;

	if (!IsValid(InSlot))
	{
		return EmptyOwner;
	}

	const UGenericRouteSubsystem* RouteSubsystem = UGenericRouteSubsystem::Get(GetLocalPlayer());
	if (!RouteSubsystem)
	{
		return EmptyOwner;
	}

	const auto ResolveActiveRoute = [RouteSubsystem](UObject* Candidate) -> TScriptInterface<IGenericRouteInterface>
	{
		TScriptInterface<IGenericRouteInterface> CandidateRoute = UGenericRouteSubsystem::MakeRouteInterface(Candidate);
		return CandidateRoute.GetObject() && RouteSubsystem->IsRouteActive(CandidateRoute) ? CandidateRoute : TScriptInterface<IGenericRouteInterface>();
	};

	for (UPanelWidget* Parent = InSlot->GetParent(); Parent; Parent = Parent->GetParent())
	{
		if (Parent->GetClass()->ImplementsInterface(UGenericRouteInterface::StaticClass()))
		{
			return ResolveActiveRoute(Parent);
		}
	}

	if (UUserWidget* OwningUserWidget = InSlot->GetTypedOuter<UUserWidget>())
	{
		if (OwningUserWidget->GetClass()->ImplementsInterface(UGenericRouteInterface::StaticClass()))
		{
			return ResolveActiveRoute(OwningUserWidget);
		}
	}

	return EmptyOwner;
}

void UGenericSlotSubsystem::RetryPendingAutoSlots()
{
	const TArray<TObjectPtr<UGameplayTagSlot>> PendingSlots = PendingAutoSlots;

	for (UGameplayTagSlot* PendingSlot : PendingSlots)
	{
		if (!IsValid(PendingSlot))
		{
			PendingAutoSlots.Remove(PendingSlot);
			continue;
		}

		RegisterSlotAutomatically(PendingSlot);
	}
}

void UGenericSlotSubsystem::HandleRouteRegistered(FGameplayTag InChannel, const FOnRouteRegisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	RetryPendingAutoSlots();
}

bool UGenericSlotSubsystem::IsMessageForThisPlayer(const APlayerController* InPlayerController) const
{
	return InPlayerController && InPlayerController == GetPlayerController();
}
