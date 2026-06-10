// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericRouteSubsystem.h"

#include "Base/GenericLayer.h"
#include "Base/GenericLayout.h"
#include "Base/GenericWidget.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "Slate/GameplayTagSlot.h"
#include "Subsystem/GenericLayerSubsystem.h"
#include "Subsystem/GenericLayoutSubsystem.h"
#include "Subsystem/GenericSlotSubsystem.h"
#include "Subsystem/GenericWidgetSubsystem.h"
#include "WidgetType.h"

namespace
{
	void BroadcastRouteRegisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, TScriptInterface<IGenericRouteInterface> Route, TScriptInterface<IGenericRouteInterface> Owner)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnRouteRegisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.Route = Route;
		Message.Owner = Owner;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnRouteRegister, Message);
	}

	void BroadcastRouteUnregisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, TScriptInterface<IGenericRouteInterface> Route, TScriptInterface<IGenericRouteInterface> Owner)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnRouteUnregisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.Route = Route;
		Message.Owner = Owner;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnRouteUnRegister, Message);
	}
}

UGenericRouteSubsystem* UGenericRouteSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<UGenericRouteSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UGenericRouteSubsystem* UGenericRouteSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UGenericRouteSubsystem>(LocalPlayer);
}

TScriptInterface<IGenericRouteInterface> UGenericRouteSubsystem::MakeRouteInterface(UObject* InObject)
{
	TScriptInterface<IGenericRouteInterface> RouteInterface;

	if (IsValid(InObject) && InObject->GetClass()->ImplementsInterface(UGenericRouteInterface::StaticClass()))
	{
		RouteInterface.SetObject(InObject);
		RouteInterface.SetInterface(Cast<IGenericRouteInterface>(InObject));
	}

	return RouteInterface;
}

bool UGenericRouteSubsystem::RegisterRoute(TScriptInterface<IGenericRouteInterface> InRoute, TScriptInterface<IGenericRouteInterface> InOwner)
{
	FGameplayTag RouteTag;
	if (!IsValidRoute(InRoute, &RouteTag))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterRoute failed because route is invalid."));
		return false;
	}

	if (!CanRegisterRouteForLocalPlayer(InRoute, InOwner))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterRoute failed because route does not belong to this local player. Route: %s"), *InRoute.GetObject()->GetName());
		return false;
	}

	if (InOwner.GetObject() && FindRouteNodeIndex(InOwner) == INDEX_NONE)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterRoute failed because owner route is not registered. Route: %s"), *InRoute.GetObject()->GetName());
		return false;
	}

	if (InOwner.GetObject() && IsSameRoute(InRoute, InOwner))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterRoute failed because route cannot own itself. Route: %s"), *InRoute.GetObject()->GetName());
		return false;
	}

	if (InOwner.GetObject() && IsRouteDescendantOf(InOwner, InRoute))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterRoute failed because owner would create a route cycle. Route: %s"), *InRoute.GetObject()->GetName());
		return false;
	}

	const int32 ExistingIndex = FindRouteNodeIndex(InRoute);
	if (ExistingIndex != INDEX_NONE)
	{
		FGenericRouteNode& ExistingNode = RouteNodes[ExistingIndex];
		if (IsSameRoute(ExistingNode.Owner, InOwner))
		{
			ExistingNode.RouteTag = RouteTag;
			return true;
		}

		RemoveChildRoute(ExistingNode.Owner, InRoute);
		ExistingNode.Owner = InOwner;
		ExistingNode.RouteTag = RouteTag;
		AddChildRoute(InOwner, InRoute);
		return true;
	}

	FGenericRouteNode& NewNode = RouteNodes.AddDefaulted_GetRef();
	NewNode.Route = InRoute;
	NewNode.Owner = InOwner;
	NewNode.RouteTag = RouteTag;

	AddChildRoute(InOwner, InRoute);
	ActivateRoute(InRoute);

	BroadcastRouteRegisteredMessage(this, GetPlayerController(), InRoute, InOwner);
	return true;
}

bool UGenericRouteSubsystem::UnregisterRoute(TScriptInterface<IGenericRouteInterface> InRoute)
{
	int32 RouteIndex = FindRouteNodeIndex(InRoute);
	if (RouteIndex == INDEX_NONE)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterRoute failed because route is not registered."));
		return false;
	}

	const TScriptInterface<IGenericRouteInterface> Route = RouteNodes[RouteIndex].Route;
	const TScriptInterface<IGenericRouteInterface> Owner = RouteNodes[RouteIndex].Owner;
	const TArray<TScriptInterface<IGenericRouteInterface>> Children = RouteNodes[RouteIndex].Children;

	DeactivateRoute(Route);

	for (const TScriptInterface<IGenericRouteInterface>& Child : Children)
	{
		UnregisterRoute(Child);
	}

	RouteIndex = FindRouteNodeIndex(Route);
	if (RouteIndex == INDEX_NONE)
	{
		return true;
	}

	RemoveChildRoute(Owner, Route);
	RouteNodes.RemoveAt(RouteIndex);

	BroadcastRouteUnregisteredMessage(this, GetPlayerController(), Route, Owner);
	return true;
}

TScriptInterface<IGenericRouteInterface> UGenericRouteSubsystem::GetRouteOwner(TScriptInterface<IGenericRouteInterface> InRoute) const
{
	const int32 RouteIndex = FindRouteNodeIndex(InRoute);
	return RouteIndex != INDEX_NONE ? RouteNodes[RouteIndex].Owner : TScriptInterface<IGenericRouteInterface>();
}

TArray<TScriptInterface<IGenericRouteInterface>> UGenericRouteSubsystem::GetRouteChildren(TScriptInterface<IGenericRouteInterface> InRoute) const
{
	const int32 RouteIndex = FindRouteNodeIndex(InRoute);
	return RouteIndex != INDEX_NONE ? RouteNodes[RouteIndex].Children : TArray<TScriptInterface<IGenericRouteInterface>>();
}

TArray<TScriptInterface<IGenericRouteInterface>> UGenericRouteSubsystem::GetAllRoutes() const
{
	TArray<TScriptInterface<IGenericRouteInterface>> Routes;
	Routes.Reserve(RouteNodes.Num());

	for (const FGenericRouteNode& RouteNode : RouteNodes)
	{
		if (RouteNode.Route.GetObject())
		{
			Routes.Add(RouteNode.Route);
		}
	}

	return Routes;
}

TArray<TScriptInterface<IGenericRouteInterface>> UGenericRouteSubsystem::GetRootRoutes() const
{
	TArray<TScriptInterface<IGenericRouteInterface>> Routes;

	for (const FGenericRouteNode& RouteNode : RouteNodes)
	{
		if (RouteNode.Route.GetObject() && !RouteNode.Owner.GetObject())
		{
			Routes.Add(RouteNode.Route);
		}
	}

	return Routes;
}

bool UGenericRouteSubsystem::IsRouteActive(TScriptInterface<IGenericRouteInterface> InRoute) const
{
	const int32 RouteIndex = FindRouteNodeIndex(InRoute);
	return RouteIndex != INDEX_NONE && RouteNodes[RouteIndex].bIsActive;
}

void UGenericRouteSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (UGameplayMessageSubsystem::HasInstance(this))
	{
		UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
		LayoutRegisteredListenerHandle = MessageSubsystem.RegisterListener<FOnLayoutRegisteredMessage>(TAG_GameplayMessage_Channel_UI_OnLayoutRegister, this, &UGenericRouteSubsystem::HandleLayoutRegistered);
		LayoutUnregisteredListenerHandle = MessageSubsystem.RegisterListener<FOnLayoutUnregisteredMessage>(TAG_GameplayMessage_Channel_UI_OnLayoutUnRegister, this, &UGenericRouteSubsystem::HandleLayoutUnregistered);
		LayerRegisteredListenerHandle = MessageSubsystem.RegisterListener<FOnLayerRegisteredMessage>(TAG_GameplayMessage_Channel_UI_OnLayerRegister, this, &UGenericRouteSubsystem::HandleLayerRegistered);
		LayerUnregisteredListenerHandle = MessageSubsystem.RegisterListener<FOnLayerUnregisteredMessage>(TAG_GameplayMessage_Channel_UI_OnLayerUnRegister, this, &UGenericRouteSubsystem::HandleLayerUnregistered);
		SlotRegisteredListenerHandle = MessageSubsystem.RegisterListener<FOnSlotRegisteredMessage>(TAG_GameplayMessage_Channel_UI_OnSlotRegister, this, &UGenericRouteSubsystem::HandleSlotRegistered);
		SlotUnregisteredListenerHandle = MessageSubsystem.RegisterListener<FOnSlotUnregisteredMessage>(TAG_GameplayMessage_Channel_UI_OnSlotUnRegister, this, &UGenericRouteSubsystem::HandleSlotUnregistered);
		WidgetRegisteredListenerHandle = MessageSubsystem.RegisterListener<FOnWidgetRegisteredMessage>(TAG_GameplayMessage_Channel_UI_OnWidgetRegister, this, &UGenericRouteSubsystem::HandleWidgetRegistered);
		WidgetUnregisteredListenerHandle = MessageSubsystem.RegisterListener<FOnWidgetUnregisteredMessage>(TAG_GameplayMessage_Channel_UI_OnWidgetUnRegister, this, &UGenericRouteSubsystem::HandleWidgetUnregistered);
		WidgetRegisteredToOwnerListenerHandle = MessageSubsystem.RegisterListener<FOnWidgetRegisteredToOwnerMessage>(TAG_GameplayMessage_Channel_UI_OnWidgetRegisterToOwner, this, &UGenericRouteSubsystem::HandleWidgetRegisteredToOwner);
		WidgetUnregisteredFromOwnerListenerHandle = MessageSubsystem.RegisterListener<FOnWidgetUnregisteredFromOwnerMessage>(TAG_GameplayMessage_Channel_UI_OnWidgetUnRegisterFromOwner, this, &UGenericRouteSubsystem::HandleWidgetUnregisteredFromOwner);
	}
}

void UGenericRouteSubsystem::Deinitialize()
{
	LayoutRegisteredListenerHandle.Unregister();
	LayoutUnregisteredListenerHandle.Unregister();
	LayerRegisteredListenerHandle.Unregister();
	LayerUnregisteredListenerHandle.Unregister();
	SlotRegisteredListenerHandle.Unregister();
	SlotUnregisteredListenerHandle.Unregister();
	WidgetRegisteredListenerHandle.Unregister();
	WidgetUnregisteredListenerHandle.Unregister();
	WidgetRegisteredToOwnerListenerHandle.Unregister();
	WidgetUnregisteredFromOwnerListenerHandle.Unregister();

	while (RouteNodes.Num() > 0)
	{
		UnregisterRoute(RouteNodes.Last().Route);
	}

	Super::Deinitialize();
}

void UGenericRouteSubsystem::HandleLayoutRegistered(FGameplayTag InChannel, const FOnLayoutRegisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGenericLayout* InLayout = InMessage.Layout;
	const TScriptInterface<IGenericRouteInterface> LayoutRoute = MakeRouteInterface(InLayout);
	if (CanRegisterRouteForLocalPlayer(LayoutRoute, TScriptInterface<IGenericRouteInterface>()))
	{
		RegisterRoute(LayoutRoute);
	}
}

void UGenericRouteSubsystem::HandleLayoutUnregistered(FGameplayTag InChannel, const FOnLayoutUnregisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGenericLayout* InLayout = InMessage.Layout;
	const TScriptInterface<IGenericRouteInterface> LayoutRoute = MakeRouteInterface(InLayout);
	if (ShouldHandleRouteUnregistration(LayoutRoute))
	{
		UnregisterRoute(LayoutRoute);
	}
}

void UGenericRouteSubsystem::HandleLayerRegistered(FGameplayTag InChannel, const FOnLayerRegisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGenericLayer* InLayer = InMessage.Layer;
	const TScriptInterface<IGenericRouteInterface> InOwner = InMessage.Owner;
	const TScriptInterface<IGenericRouteInterface> LayerRoute = MakeRouteInterface(InLayer);
	if (CanRegisterRouteForLocalPlayer(LayerRoute, InOwner))
	{
		RegisterRoute(LayerRoute, InOwner);
	}
}

void UGenericRouteSubsystem::HandleLayerUnregistered(FGameplayTag InChannel, const FOnLayerUnregisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGenericLayer* InLayer = InMessage.Layer;
	const TScriptInterface<IGenericRouteInterface> LayerRoute = MakeRouteInterface(InLayer);
	if (ShouldHandleRouteUnregistration(LayerRoute))
	{
		UnregisterRoute(LayerRoute);
	}
}

void UGenericRouteSubsystem::HandleSlotRegistered(FGameplayTag InChannel, const FOnSlotRegisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGameplayTagSlot* InSlot = InMessage.Slot;
	const TScriptInterface<IGenericRouteInterface> InOwner = InMessage.Owner;
	const TScriptInterface<IGenericRouteInterface> SlotRoute = MakeRouteInterface(InSlot);
	if (CanRegisterRouteForLocalPlayer(SlotRoute, InOwner))
	{
		RegisterRoute(SlotRoute, InOwner);
	}
}

void UGenericRouteSubsystem::HandleSlotUnregistered(FGameplayTag InChannel, const FOnSlotUnregisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGameplayTagSlot* InSlot = InMessage.Slot;
	const TScriptInterface<IGenericRouteInterface> SlotRoute = MakeRouteInterface(InSlot);
	if (ShouldHandleRouteUnregistration(SlotRoute))
	{
		UnregisterRoute(SlotRoute);
	}
}

void UGenericRouteSubsystem::HandleWidgetRegistered(FGameplayTag InChannel, const FOnWidgetRegisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	const FGameplayTag InSlotTag = InMessage.SlotTag;
	UGenericWidget* InWidget = InMessage.Widget;
	const TScriptInterface<IGenericRouteInterface> WidgetRoute = MakeRouteInterface(InWidget);
	const ULocalPlayer* WidgetOwnerPlayer = GetRouteOwnerPlayer(WidgetRoute);
	if (WidgetOwnerPlayer && WidgetOwnerPlayer != GetLocalPlayer())
	{
		return;
	}

	UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(GetLocalPlayer());
	UGameplayTagSlot* Slot = SlotSubsystem ? SlotSubsystem->GetSlot(InSlotTag) : nullptr;

	if (!IsValid(Slot))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("Register widget route failed because slot is not registered. Widget: %s, SlotTag: %s"), InWidget ? *InWidget->GetName() : TEXT("None"), *InSlotTag.ToString());
		return;
	}

	const TScriptInterface<IGenericRouteInterface> SlotRoute = MakeRouteInterface(Slot);
	if (CanRegisterRouteForLocalPlayer(WidgetRoute, SlotRoute))
	{
		RegisterRoute(WidgetRoute, SlotRoute);
	}
}

void UGenericRouteSubsystem::HandleWidgetUnregistered(FGameplayTag InChannel, const FOnWidgetUnregisteredMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGenericWidget* InWidget = InMessage.Widget;
	const TScriptInterface<IGenericRouteInterface> WidgetRoute = MakeRouteInterface(InWidget);
	if (ShouldHandleRouteUnregistration(WidgetRoute))
	{
		UnregisterRoute(WidgetRoute);
	}
}

void UGenericRouteSubsystem::HandleWidgetRegisteredToOwner(FGameplayTag InChannel, const FOnWidgetRegisteredToOwnerMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGenericWidget* InWidget = InMessage.Widget;
	const TScriptInterface<IGenericRouteInterface> InOwner = InMessage.Owner;
	const TScriptInterface<IGenericRouteInterface> WidgetRoute = MakeRouteInterface(InWidget);
	if (CanRegisterRouteForLocalPlayer(WidgetRoute, InOwner))
	{
		RegisterRoute(WidgetRoute, InOwner);
	}
}

void UGenericRouteSubsystem::HandleWidgetUnregisteredFromOwner(FGameplayTag InChannel, const FOnWidgetUnregisteredFromOwnerMessage& InMessage)
{
	(void)InChannel;
	if (!IsMessageForThisPlayer(InMessage.PlayerController))
	{
		return;
	}

	UGenericWidget* InWidget = InMessage.Widget;
	const TScriptInterface<IGenericRouteInterface> WidgetRoute = MakeRouteInterface(InWidget);
	if (ShouldHandleRouteUnregistration(WidgetRoute))
	{
		UnregisterRoute(WidgetRoute);
	}
}

void UGenericRouteSubsystem::ActivateRoute(TScriptInterface<IGenericRouteInterface> InRoute)
{
	UObject* RouteObject = InRoute.GetObject();
	if (IsValid(RouteObject))
	{
		IGenericRouteInterface::Execute_HandleRouteActivated(RouteObject);
	}

	const int32 RouteIndex = FindRouteNodeIndex(InRoute);
	if (RouteIndex != INDEX_NONE)
	{
		RouteNodes[RouteIndex].bIsActive = true;
	}
}

void UGenericRouteSubsystem::DeactivateRoute(TScriptInterface<IGenericRouteInterface> InRoute)
{
	UObject* RouteObject = InRoute.GetObject();
	const int32 RouteIndex = FindRouteNodeIndex(InRoute);
	if (RouteIndex != INDEX_NONE)
	{
		RouteNodes[RouteIndex].bIsActive = false;
	}

	if (IsValid(RouteObject))
	{
		IGenericRouteInterface::Execute_HandleRouteDeactivated(RouteObject);
	}
}

ULocalPlayer* UGenericRouteSubsystem::GetRouteOwnerPlayer(TScriptInterface<IGenericRouteInterface> InRoute) const
{
	UObject* RouteObject = InRoute.GetObject();
	return IsValid(RouteObject) && RouteObject->GetClass()->ImplementsInterface(UGenericRouteInterface::StaticClass())
		? IGenericRouteInterface::Execute_GetRouteOwnerPlayer(RouteObject)
		: nullptr;
}

bool UGenericRouteSubsystem::CanRegisterRouteForLocalPlayer(TScriptInterface<IGenericRouteInterface> InRoute, TScriptInterface<IGenericRouteInterface> InOwner) const
{
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer)
	{
		return false;
	}

	const ULocalPlayer* RouteOwnerPlayer = GetRouteOwnerPlayer(InRoute);
	const ULocalPlayer* OwnerPlayer = GetRouteOwnerPlayer(InOwner);

	if ((RouteOwnerPlayer && RouteOwnerPlayer != LocalPlayer) || (OwnerPlayer && OwnerPlayer != LocalPlayer))
	{
		return false;
	}

	return RouteOwnerPlayer == LocalPlayer || OwnerPlayer == LocalPlayer;
}

bool UGenericRouteSubsystem::ShouldHandleRouteUnregistration(TScriptInterface<IGenericRouteInterface> InRoute) const
{
	if (FindRouteNodeIndex(InRoute) != INDEX_NONE)
	{
		return true;
	}

	return GetRouteOwnerPlayer(InRoute) == GetLocalPlayer();
}

int32 UGenericRouteSubsystem::FindRouteNodeIndex(TScriptInterface<IGenericRouteInterface> InRoute) const
{
	for (int32 Index = 0; Index < RouteNodes.Num(); ++Index)
	{
		if (IsSameRoute(RouteNodes[Index].Route, InRoute))
		{
			return Index;
		}
	}

	return INDEX_NONE;
}

bool UGenericRouteSubsystem::IsValidRoute(TScriptInterface<IGenericRouteInterface> InRoute, FGameplayTag* OutRouteTag) const
{
	UObject* RouteObject = InRoute.GetObject();
	if (!IsValid(RouteObject) || !RouteObject->GetClass()->ImplementsInterface(UGenericRouteInterface::StaticClass()))
	{
		return false;
	}

	const FGameplayTag RouteTag = IGenericRouteInterface::Execute_GetRouteTag(RouteObject);
	if (!IsValidRouteTag(RouteTag))
	{
		return false;
	}

	if (OutRouteTag)
	{
		*OutRouteTag = RouteTag;
	}

	return true;
}

bool UGenericRouteSubsystem::IsValidRouteTag(FGameplayTag InRouteTag) const
{
	return InRouteTag.IsValid() && InRouteTag.MatchesTag(TAG_GameplayUI_Route);
}

bool UGenericRouteSubsystem::IsRouteDescendantOf(TScriptInterface<IGenericRouteInterface> InRoute, TScriptInterface<IGenericRouteInterface> InPotentialOwner) const
{
	const int32 OwnerIndex = FindRouteNodeIndex(InPotentialOwner);
	if (OwnerIndex == INDEX_NONE)
	{
		return false;
	}

	for (const TScriptInterface<IGenericRouteInterface>& Child : RouteNodes[OwnerIndex].Children)
	{
		if (IsSameRoute(Child, InRoute) || IsRouteDescendantOf(InRoute, Child))
		{
			return true;
		}
	}

	return false;
}

void UGenericRouteSubsystem::AddChildRoute(TScriptInterface<IGenericRouteInterface> InOwner, TScriptInterface<IGenericRouteInterface> InChild)
{
	const int32 OwnerIndex = FindRouteNodeIndex(InOwner);
	if (OwnerIndex == INDEX_NONE)
	{
		return;
	}

	for (const TScriptInterface<IGenericRouteInterface>& Child : RouteNodes[OwnerIndex].Children)
	{
		if (IsSameRoute(Child, InChild))
		{
			return;
		}
	}

	RouteNodes[OwnerIndex].Children.Add(InChild);
}

void UGenericRouteSubsystem::RemoveChildRoute(TScriptInterface<IGenericRouteInterface> InOwner, TScriptInterface<IGenericRouteInterface> InChild)
{
	const int32 OwnerIndex = FindRouteNodeIndex(InOwner);
	if (OwnerIndex == INDEX_NONE)
	{
		return;
	}

	RouteNodes[OwnerIndex].Children.RemoveAll(
		[this, InChild](const TScriptInterface<IGenericRouteInterface>& Child)
		{
			return IsSameRoute(Child, InChild);
		}
	);
}

bool UGenericRouteSubsystem::IsSameRoute(TScriptInterface<IGenericRouteInterface> InLeft, TScriptInterface<IGenericRouteInterface> InRight) const
{
	return InLeft.GetObject() && InLeft.GetObject() == InRight.GetObject();
}

bool UGenericRouteSubsystem::IsMessageForThisPlayer(const APlayerController* InPlayerController) const
{
	return InPlayerController && InPlayerController == GetPlayerController();
}
