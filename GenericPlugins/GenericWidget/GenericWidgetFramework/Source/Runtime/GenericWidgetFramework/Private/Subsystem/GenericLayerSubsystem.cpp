// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericLayerSubsystem.h"

#include "Base/GenericLayer.h"
#include "Blueprint/UserWidget.h"
#include "Components/PanelWidget.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "Subsystem/GenericRouteSubsystem.h"
#include "WidgetType.h"

namespace
{
	void BroadcastLayerRegisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, FGameplayTag LayerTag, UGenericLayer* Layer, TScriptInterface<IGenericRouteInterface> Owner)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnLayerRegisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.LayerTag = LayerTag;
		Message.Layer = Layer;
		Message.Owner = Owner;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnLayerRegister, Message);
	}

	void BroadcastLayerUnregisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, FGameplayTag LayerTag, UGenericLayer* Layer, TScriptInterface<IGenericRouteInterface> Owner)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnLayerUnregisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.LayerTag = LayerTag;
		Message.Layer = Layer;
		Message.Owner = Owner;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnLayerUnRegister, Message);
	}
}

UGenericLayerSubsystem* UGenericLayerSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<UGenericLayerSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UGenericLayerSubsystem* UGenericLayerSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UGenericLayerSubsystem>(LocalPlayer);
}

bool UGenericLayerSubsystem::RegisterLayer(UGenericLayer* InLayer, TScriptInterface<IGenericRouteInterface> InOwner)
{
	return RegisterLayerInternal(InLayer, InOwner, false);
}

bool UGenericLayerSubsystem::RegisterLayerAutomatically(UGenericLayer* InLayer)
{
	if (!IsValid(InLayer))
	{
		return false;
	}

	for (const TPair<FGameplayTag, FGenericRegisteredLayer>& RegisteredLayerPair : RegisteredLayers)
	{
		if (RegisteredLayerPair.Value.Layer == InLayer)
		{
			return true;
		}
	}

	TScriptInterface<IGenericRouteInterface> Owner = ResolveNearestRouteOwner(InLayer);
	if (!Owner.GetObject())
	{
		PendingAutoLayers.AddUnique(InLayer);
		return false;
	}

	return RegisterLayerInternal(InLayer, Owner, true);
}

bool UGenericLayerSubsystem::UnregisterLayerAutomatically(UGenericLayer* InLayer)
{
	const int32 RemovedPendingCount = PendingAutoLayers.RemoveAll(
		[InLayer](const TObjectPtr<UGenericLayer>& PendingLayer)
		{
			return PendingLayer == InLayer || !IsValid(PendingLayer);
		}
	);

	if (!IsValid(InLayer))
	{
		return RemovedPendingCount > 0;
	}

	for (const TPair<FGameplayTag, FGenericRegisteredLayer>& RegisteredLayerPair : RegisteredLayers)
	{
		if (RegisteredLayerPair.Value.Layer == InLayer)
		{
			return UnregisterLayerInternal(RegisteredLayerPair.Key, false);
		}
	}

	return RemovedPendingCount > 0;
}

bool UGenericLayerSubsystem::UnregisterLayer(UGenericLayer* InLayer, bool bRemoveFromParent)
{
	if (!IsValid(InLayer))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterLayer failed because layer is null."));
		return false;
	}

	for (const TPair<FGameplayTag, FGenericRegisteredLayer>& RegisteredLayerPair : RegisteredLayers)
	{
		if (RegisteredLayerPair.Value.Layer == InLayer)
		{
			return UnregisterLayerInternal(RegisteredLayerPair.Key, bRemoveFromParent);
		}
	}

	UE_LOG(GenericLogUI, Warning, TEXT("UnregisterLayer failed because layer '%s' is not registered."), *InLayer->GetName());
	return false;
}

bool UGenericLayerSubsystem::UnregisterLayerByTag(FGameplayTag InLayerTag, bool bRemoveFromParent)
{
	return UnregisterLayerInternal(InLayerTag, bRemoveFromParent);
}

UGenericLayer* UGenericLayerSubsystem::GetLayer(FGameplayTag InLayerTag) const
{
	const FGenericRegisteredLayer* RegisteredLayer = RegisteredLayers.Find(InLayerTag);
	return RegisteredLayer && IsValid(RegisteredLayer->Layer) ? RegisteredLayer->Layer : nullptr;
}

bool UGenericLayerSubsystem::HasLayer(FGameplayTag InLayerTag) const
{
	return GetLayer(InLayerTag) != nullptr;
}

bool UGenericLayerSubsystem::SetLayerVisibility(FGameplayTag InLayerTag, ESlateVisibility InVisibility)
{
	UGenericLayer* Layer = GetLayer(InLayerTag);

	if (!Layer)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("SetLayerVisibility failed because layer is not registered. LayerTag: %s"), *InLayerTag.ToString());
		return false;
	}

	Layer->SetLayerVisibility(InVisibility);
	return true;
}

TArray<UGenericLayer*> UGenericLayerSubsystem::GetAllLayers() const
{
	TArray<UGenericLayer*> Layers;

	for (const TPair<FGameplayTag, FGenericRegisteredLayer>& RegisteredLayerPair : RegisteredLayers)
	{
		if (UGenericLayer* Layer = RegisteredLayerPair.Value.Layer)
		{
			if (IsValid(Layer))
			{
				Layers.Add(Layer);
			}
		}
	}

	return Layers;
}

TArray<UGenericLayer*> UGenericLayerSubsystem::GetAllLayersByPriority() const
{
	struct FLayerPriorityEntry
	{
		UGenericLayer* Layer = nullptr;
		int32 ZOrder = 0;
	};

	TArray<FLayerPriorityEntry> Entries;

	for (const TPair<FGameplayTag, FGenericRegisteredLayer>& RegisteredLayerPair : RegisteredLayers)
	{
		UGenericLayer* Layer = RegisteredLayerPair.Value.Layer;
		if (IsValid(Layer) && Layer->IsVisible())
		{
			FLayerPriorityEntry& Entry = Entries.AddDefaulted_GetRef();
			Entry.Layer = Layer;
			Entry.ZOrder = Layer->ZOrder;
		}
	}

	Entries.Sort(
		[](const FLayerPriorityEntry& Left, const FLayerPriorityEntry& Right)
		{
			return Left.ZOrder > Right.ZOrder;
		}
	);

	TArray<UGenericLayer*> Layers;
	Layers.Reserve(Entries.Num());

	for (const FLayerPriorityEntry& Entry : Entries)
	{
		Layers.Add(Entry.Layer);
	}

	return Layers;
}

void UGenericLayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (UGameplayMessageSubsystem::HasInstance(this))
	{
		RouteRegisteredListenerHandle = UGameplayMessageSubsystem::Get(this).RegisterListener<FOnRouteRegisteredMessage>(TAG_GameplayMessage_Channel_UI_OnRouteRegister, this, &UGenericLayerSubsystem::HandleRouteRegistered);
	}
}

void UGenericLayerSubsystem::Deinitialize()
{
	RouteRegisteredListenerHandle.Unregister();
	PendingAutoLayers.Reset();

	TArray<FGameplayTag> LayerTags;
	RegisteredLayers.GenerateKeyArray(LayerTags);

	for (const FGameplayTag& LayerTag : LayerTags)
	{
		UnregisterLayerInternal(LayerTag, false);
	}

	Super::Deinitialize();
}

bool UGenericLayerSubsystem::RegisterLayerInternal(UGenericLayer* InLayer, TScriptInterface<IGenericRouteInterface> InOwner, bool bIsAutomatic)
{
	if (!IsValid(InLayer))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayer failed because layer is null."));
		return false;
	}

	if (!IsLayerOwnedByThisSubsystem(InLayer))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayer failed because layer '%s' does not belong to this local player. LayerTag: %s"), *InLayer->GetName(), *InLayer->LayerTag.ToString());
		return false;
	}

	if (!IsValidLayerTag(InLayer->LayerTag))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayer failed because layer tag is invalid. Layer: %s, LayerTag: %s"), *InLayer->GetName(), *InLayer->LayerTag.ToString());
		return false;
	}

	if (!InOwner.GetObject() && bIsAutomatic)
	{
		return false;
	}

	const FGameplayTag LayerTag = InLayer->LayerTag;

	if (FGenericRegisteredLayer* ExistingRegisteredLayer = RegisteredLayers.Find(LayerTag))
	{
		UGenericLayer* ExistingLayer = ExistingRegisteredLayer->Layer;

		if (ExistingLayer == InLayer)
		{
			if (ExistingRegisteredLayer->Owner.GetObject() == InOwner.GetObject())
			{
				PendingAutoLayers.Remove(InLayer);
				return true;
			}

			ExistingRegisteredLayer->Owner = InOwner;
			PendingAutoLayers.Remove(InLayer);
			BroadcastLayerRegisteredMessage(this, GetPlayerController(), LayerTag, InLayer, InOwner);
			return true;
		}

		if (IsValid(ExistingLayer))
		{
			UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayer failed because layer tag is already registered by layer '%s'. NewLayer: %s, LayerTag: %s"), *ExistingLayer->GetName(), *InLayer->GetName(), *LayerTag.ToString());
			return false;
		}

		RegisteredLayers.Remove(LayerTag);
	}

	FGenericRegisteredLayer& RegisteredLayer = RegisteredLayers.Add(LayerTag);
	RegisteredLayer.Layer = InLayer;
	RegisteredLayer.Owner = InOwner;
	PendingAutoLayers.Remove(InLayer);

	BroadcastLayerRegisteredMessage(this, GetPlayerController(), LayerTag, InLayer, InOwner);
	return true;
}

bool UGenericLayerSubsystem::IsLayerOwnedByThisSubsystem(const UGenericLayer* InLayer) const
{
	const ULocalPlayer* LayerLocalPlayer = InLayer ? InLayer->GetOwningLocalPlayer() : nullptr;
	return !LayerLocalPlayer || LayerLocalPlayer == GetLocalPlayer();
}

bool UGenericLayerSubsystem::IsValidLayerTag(FGameplayTag InLayerTag) const
{
	return InLayerTag.IsValid() && InLayerTag.MatchesTag(TAG_GameplayUI_Layer);
}

bool UGenericLayerSubsystem::UnregisterLayerInternal(FGameplayTag InLayerTag, bool bRemoveFromParent)
{
	FGenericRegisteredLayer RegisteredLayer;

	if (!RegisteredLayers.RemoveAndCopyValue(InLayerTag, RegisteredLayer))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterLayer failed because layer tag is not registered. LayerTag: %s"), *InLayerTag.ToString());
		return false;
	}

	UGenericLayer* Layer = RegisteredLayer.Layer;
	PendingAutoLayers.Remove(Layer);

	if (IsValid(Layer) && bRemoveFromParent)
	{
		Layer->RemoveFromParent();
	}

	BroadcastLayerUnregisteredMessage(this, GetPlayerController(), InLayerTag, Layer, RegisteredLayer.Owner);
	return true;
}

TScriptInterface<IGenericRouteInterface> UGenericLayerSubsystem::ResolveNearestRouteOwner(const UGenericLayer* InLayer) const
{
	TScriptInterface<IGenericRouteInterface> EmptyOwner;

	if (!IsValid(InLayer))
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

	for (UPanelWidget* Parent = InLayer->GetParent(); Parent; Parent = Parent->GetParent())
	{
		if (Parent->GetClass()->ImplementsInterface(UGenericRouteInterface::StaticClass()))
		{
			return ResolveActiveRoute(Parent);
		}
	}

	if (UUserWidget* OwningUserWidget = InLayer->GetTypedOuter<UUserWidget>())
	{
		if (OwningUserWidget->GetClass()->ImplementsInterface(UGenericRouteInterface::StaticClass()))
		{
			return ResolveActiveRoute(OwningUserWidget);
		}
	}

	return EmptyOwner;
}

void UGenericLayerSubsystem::RetryPendingAutoLayers()
{
	const TArray<TObjectPtr<UGenericLayer>> PendingLayers = PendingAutoLayers;

	for (UGenericLayer* PendingLayer : PendingLayers)
	{
		if (!IsValid(PendingLayer))
		{
			PendingAutoLayers.Remove(PendingLayer);
			continue;
		}

		RegisterLayerAutomatically(PendingLayer);
	}
}

void UGenericLayerSubsystem::HandleRouteRegistered(FGameplayTag InChannel, const FOnRouteRegisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	RetryPendingAutoLayers();
}

bool UGenericLayerSubsystem::IsMessageForThisPlayer(const APlayerController* InPlayerController) const
{
	return InPlayerController && InPlayerController == GetPlayerController();
}
