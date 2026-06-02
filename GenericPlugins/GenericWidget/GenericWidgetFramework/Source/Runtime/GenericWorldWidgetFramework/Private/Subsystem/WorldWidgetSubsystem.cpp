// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/WorldWidgetSubsystem.h"

#include "Base/WorldWidgetComponent.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "Subsystem/GenericActionSubsystem.h"
#include "Type/GenericType.h"
#include "UObject/UObjectIterator.h"
#include "WidgetType.h"
#include "WorldWidgetType.h"

namespace
{
	void BroadcastWorldWidgetRegisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, UWorldWidgetComponent* WorldWidget)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnWorldWidgetRegisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.WorldWidget = WorldWidget;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnWorldWidgetRegister, Message);
	}

	void BroadcastWorldWidgetUnregisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, UWorldWidgetComponent* WorldWidget)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnWorldWidgetUnregisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.WorldWidget = WorldWidget;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnWorldWidgetUnRegister, Message);
	}
}

UWorldWidgetSubsystem* UWorldWidgetSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<UWorldWidgetSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UWorldWidgetSubsystem* UWorldWidgetSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UWorldWidgetSubsystem>(LocalPlayer);
}

bool UWorldWidgetSubsystem::RegisterWorldWidget(UWorldWidgetComponent* InComponent)
{
	if (!IsValid(InComponent))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWorldWidget failed because component is null."));
		return false;
	}

	if (!IsComponentOwnedByWorld(InComponent))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterWorldWidget failed because component '%s' belongs to another world."), *InComponent->GetName());
		return false;
	}

	const bool bAlreadyRegistered = RegisteredComponents.Contains(InComponent);
	if (!FWorldWidgetRegistry::AddComponent(RegisteredComponents, InComponent))
	{
		return false;
	}

	if (!bAlreadyRegistered)
	{
		BroadcastWorldWidgetRegisteredMessage(this, GetPlayerController(), InComponent);
	}

	return true;
}

bool UWorldWidgetSubsystem::UnregisterWorldWidget(UWorldWidgetComponent* InComponent)
{
	if (!IsValid(InComponent))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterWorldWidget failed because component is null."));
		return false;
	}

	if (!FWorldWidgetRegistry::RemoveComponent(RegisteredComponents, InComponent))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterWorldWidget failed because component '%s' is not registered."), *InComponent->GetName());
		return false;
	}

	InputDispatcher.PruneRuntimeTriggerStates(RegisteredComponents, RuntimeTriggerStates);
	BroadcastWorldWidgetUnregisteredMessage(this, GetPlayerController(), InComponent);
	return true;
}

TArray<UWorldWidgetComponent*> UWorldWidgetSubsystem::GetAllWorldWidgets() const
{
	return FWorldWidgetRegistry::GetAllComponents(RegisteredComponents);
}

TArray<UWorldWidgetComponent*> UWorldWidgetSubsystem::GetWorldWidgetsBySpace(EWidgetSpace InWidgetSpace) const
{
	return FWorldWidgetRegistry::GetComponentsBySpace(RegisteredComponents, InWidgetSpace);
}

void UWorldWidgetSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Collection.InitializeDependency(UGenericActionSubsystem::StaticClass());
	Super::Initialize(Collection);

	BindWorldWidgetComponents();
	BindActionSubsystem();
	RegisterExistingWorldWidgets();

	if (!WorldWidgetInputTickerHandle.IsValid())
	{
		WorldWidgetInputTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &ThisClass::TickWorldWidgetInput));
	}
}

void UWorldWidgetSubsystem::Deinitialize()
{
	if (WorldWidgetInputTickerHandle.IsValid())
	{
		FTSTicker::RemoveTicker(WorldWidgetInputTickerHandle);
		WorldWidgetInputTickerHandle.Reset();
	}

	UnbindActionSubsystem();
	UnbindWorldWidgetComponents();
	RuntimeTriggerStates.Reset();
	RegisteredComponents.Reset();
	Super::Deinitialize();
}

void UWorldWidgetSubsystem::BindActionSubsystem()
{
	if (PostRouteInputHandle.IsValid())
	{
		return;
	}

	if (UGenericActionSubsystem* ActionSubsystem = UGenericActionSubsystem::Get(GetLocalPlayer()))
	{
		PostRouteInputHandle = ActionSubsystem->GetPostRouteViewportInputDelegate().AddUObject(this, &ThisClass::HandlePostRouteViewportInput);
	}
}

void UWorldWidgetSubsystem::UnbindActionSubsystem()
{
	if (!PostRouteInputHandle.IsValid())
	{
		return;
	}

	if (UGenericActionSubsystem* ActionSubsystem = UGenericActionSubsystem::Get(GetLocalPlayer()))
	{
		ActionSubsystem->GetPostRouteViewportInputDelegate().Remove(PostRouteInputHandle);
	}

	PostRouteInputHandle.Reset();
}

void UWorldWidgetSubsystem::RegisterExistingWorldWidgets()
{
	for (TObjectIterator<UWorldWidgetComponent> ComponentIt; ComponentIt; ++ComponentIt)
	{
		UWorldWidgetComponent* Component = *ComponentIt;
		if (IsValid(Component) && Component->IsRegistered() && IsComponentOwnedByWorld(Component))
		{
			RegisterWorldWidget(Component);
		}
	}
}

void UWorldWidgetSubsystem::BindWorldWidgetComponents()
{
	UWorldWidgetComponent::OnComponentRegistered.AddUObject(this, &ThisClass::HandleComponentRegistered);
	UWorldWidgetComponent::OnComponentUnregistered.AddUObject(this, &ThisClass::HandleComponentUnregistered);
	UWorldWidgetComponent::OnComponentChanged.AddUObject(this, &ThisClass::HandleComponentChanged);
}

void UWorldWidgetSubsystem::UnbindWorldWidgetComponents()
{
	UWorldWidgetComponent::OnComponentRegistered.RemoveAll(this);
	UWorldWidgetComponent::OnComponentUnregistered.RemoveAll(this);
	UWorldWidgetComponent::OnComponentChanged.RemoveAll(this);
}

void UWorldWidgetSubsystem::HandleComponentRegistered(UWorldWidgetComponent* InComponent)
{
	if (IsValid(InComponent) && InComponent->IsRegistered() && IsComponentOwnedByWorld(InComponent))
	{
		RegisterWorldWidget(InComponent);
	}
}

void UWorldWidgetSubsystem::HandleComponentUnregistered(UWorldWidgetComponent* InComponent)
{
	if (RegisteredComponents.Contains(InComponent))
	{
		UnregisterWorldWidget(InComponent);
	}
}

void UWorldWidgetSubsystem::HandleComponentChanged(UWorldWidgetComponent* InComponent)
{
	const bool bRegistered = RegisteredComponents.Contains(InComponent);
	const bool bShouldBeRegistered = IsValid(InComponent) && InComponent->IsRegistered() && IsComponentOwnedByWorld(InComponent);
	if (bShouldBeRegistered)
	{
		if (!bRegistered)
		{
			RegisterWorldWidget(InComponent);
		}
		return;
	}

	if (bRegistered)
	{
		UnregisterWorldWidget(InComponent);
	}
}

void UWorldWidgetSubsystem::HandlePostRouteViewportInput(const FGenericActionViewportInputEvent& InInputEvent, bool& bOutConsumed)
{
	if (bOutConsumed)
	{
		return;
	}

	if (InputDispatcher.DispatchViewportInput(RegisteredComponents, InInputEvent, RuntimeTriggerStates, this, true))
	{
		bOutConsumed = true;
	}
}

bool UWorldWidgetSubsystem::TickWorldWidgetInput(float InDeltaTime)
{
	InputDispatcher.TickViewportInput(RegisteredComponents, RuntimeTriggerStates, this, InDeltaTime);
	return true;
}

bool UWorldWidgetSubsystem::IsComponentOwnedByWorld(UWorldWidgetComponent* InComponent) const
{
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	const UWorld* LocalWorld = LocalPlayer ? LocalPlayer->GetWorld() : nullptr;
	return IsValid(InComponent) && InComponent->GetWorld() == LocalWorld;
}
