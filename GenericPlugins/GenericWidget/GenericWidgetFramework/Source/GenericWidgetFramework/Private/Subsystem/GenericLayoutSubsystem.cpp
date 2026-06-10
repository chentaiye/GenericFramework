// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericLayoutSubsystem.h"

#include "Base/GenericLayout.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameplayMessageSubsystem.h"
#include "WidgetType.h"

namespace
{
	void BroadcastLayoutRegisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, UGenericLayout* Layout)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnLayoutRegisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.Layout = Layout;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnLayoutRegister, Message);
	}

	void BroadcastLayoutUnregisteredMessage(const UObject* WorldContextObject, APlayerController* PlayerController, UGenericLayout* Layout)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnLayoutUnregisteredMessage Message;
		Message.PlayerController = PlayerController;
		Message.Layout = Layout;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnLayoutUnRegister, Message);
	}
}

UGenericLayoutSubsystem* UGenericLayoutSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<UGenericLayoutSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UGenericLayoutSubsystem* UGenericLayoutSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UGenericLayoutSubsystem>(LocalPlayer);
}

bool UGenericLayoutSubsystem::RegisterLayout(UGenericLayout* InLayout)
{
	if (!IsValid(InLayout))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayout failed because layout is null."));
		return false;
	}

	if (!IsLayoutOwnedByThisSubsystem(InLayout))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayout failed because layout '%s' does not belong to this local player."), *InLayout->GetName());
		return false;
	}

	if (Layout == InLayout)
	{
		return true;
	}

	if (IsValid(Layout))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayout failed because layout '%s' is already registered. NewLayout: %s"), *Layout->GetName(), *InLayout->GetName());
		return false;
	}

	Layout = InLayout;
	bLayoutAddedToScreenBySubsystem = false;

	BroadcastLayoutRegisteredMessage(this, GetPlayerController(), InLayout);
	return true;
}

UGenericLayout* UGenericLayoutSubsystem::RegisterLayout(TSubclassOf<UGenericLayout> InLayoutClass, bool bAddToScreen, ESlateVisibility InVisibility, int32 ZOrder)
{
	if (!InLayoutClass)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayout class failed because layout class is null."));
		return nullptr;
	}

	if (IsValid(Layout))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayout class failed because layout '%s' is already registered. Class: %s"), *Layout->GetName(), *InLayoutClass->GetName());
		return nullptr;
	}

	APlayerController* PlayerController = GetPlayerController();
	if (!PlayerController)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayout class failed because player controller is missing. Class: %s"), *InLayoutClass->GetName());
		return nullptr;
	}

	UGenericLayout* NewLayout = CreateWidget<UGenericLayout>(PlayerController, InLayoutClass);
	if (!NewLayout)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayout class failed to create layout. Class: %s"), *InLayoutClass->GetName());
		return nullptr;
	}

	bool bAddedToScreen = false;
	if (bAddToScreen)
	{
		NewLayout->SetVisibility(InVisibility);

		if (!NewLayout->AddToPlayerScreen(ZOrder))
		{
			UE_LOG(GenericLogUI, Warning, TEXT("RegisterLayout class failed to add layout to player screen. Layout: %s, ZOrder: %d"), *NewLayout->GetName(), ZOrder);
			if (Layout == NewLayout)
			{
				UnregisterLayout(NewLayout);
			}
			return nullptr;
		}

		bAddedToScreen = true;
	}

	if (!RegisterLayout(NewLayout))
	{
		if (bAddedToScreen)
		{
			NewLayout->RemoveFromParent();
		}

		return nullptr;
	}

	bLayoutAddedToScreenBySubsystem = bAddedToScreen;
	return NewLayout;
}

bool UGenericLayoutSubsystem::UnregisterLayout(UGenericLayout* InLayout)
{
	if (!IsValid(InLayout))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterLayout failed because layout is null."));
		return false;
	}

	if (Layout != InLayout)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterLayout failed because layout '%s' is not registered."), *InLayout->GetName());
		return false;
	}

	const bool bShouldRemoveFromParent = bLayoutAddedToScreenBySubsystem;

	Layout = nullptr;
	bLayoutAddedToScreenBySubsystem = false;

	BroadcastLayoutUnregisteredMessage(this, GetPlayerController(), InLayout);

	if (bShouldRemoveFromParent && IsValid(InLayout))
	{
		InLayout->RemoveFromParent();
	}

	return true;
}

UGenericLayout* UGenericLayoutSubsystem::GetLayout() const
{
	return IsValid(Layout) ? Layout : nullptr;
}

bool UGenericLayoutSubsystem::HasLayout() const
{
	return GetLayout() != nullptr;
}

void UGenericLayoutSubsystem::Deinitialize()
{
	if (IsValid(Layout))
	{
		UnregisterLayout(Layout);
	}

	Super::Deinitialize();
}

bool UGenericLayoutSubsystem::IsLayoutOwnedByThisSubsystem(const UGenericLayout* InLayout) const
{
	const ULocalPlayer* LayoutLocalPlayer = InLayout ? InLayout->GetOwningLocalPlayer() : nullptr;
	return !LayoutLocalPlayer || LayoutLocalPlayer == GetLocalPlayer();
}
