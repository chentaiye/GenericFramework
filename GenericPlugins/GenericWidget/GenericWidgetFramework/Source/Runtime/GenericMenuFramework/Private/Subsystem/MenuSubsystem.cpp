// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/MenuSubsystem.h"

#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "Base/MenuCollection.h"
#include "GameplayMessageSubsystem.h"
#include "MenuType.h"
#include "WidgetType.h"

namespace
{
	void BroadcastMenuCollectionRegisteredMessage(const UObject* WorldContextObject, UMenuCollection* MenuCollection, APlayerController* PlayerController)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnMenuCollectionRegisteredMessage Message;
		Message.CollectionName = MenuCollection ? MenuCollection->CollectionName : NAME_None;
		Message.MenuCollection = MenuCollection;
		Message.PlayerController = PlayerController;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnMenuCollectionRegister, Message);
	}

	void BroadcastMenuCollectionUnregisteredMessage(const UObject* WorldContextObject, UMenuCollection* MenuCollection, APlayerController* PlayerController)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnMenuCollectionUnregisteredMessage Message;
		Message.CollectionName = MenuCollection ? MenuCollection->CollectionName : NAME_None;
		Message.MenuCollection = MenuCollection;
		Message.PlayerController = PlayerController;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_UI_OnMenuCollectionUnRegister, Message);
	}
}

UMenuSubsystem* UMenuSubsystem::Get(const APlayerController* PlayerController)
{
	return ULocalPlayer::GetSubsystem<UMenuSubsystem>(PlayerController ? PlayerController->GetLocalPlayer() : nullptr);
}

UMenuSubsystem* UMenuSubsystem::Get(const ULocalPlayer* LocalPlayer)
{
	return ULocalPlayer::GetSubsystem<UMenuSubsystem>(LocalPlayer);
}

bool UMenuSubsystem::RegisterMenuCollection(UMenuCollection* InMenuCollection, bool bBuildMenu)
{
	if (!IsValid(InMenuCollection))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterMenuCollection failed because menu collection is null."));
		return false;
	}

	if (FindMenuCollectionIndex(InMenuCollection) != INDEX_NONE)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterMenuCollection failed because menu collection '%s' is already registered."), *InMenuCollection->GetName());
		return false;
	}

	if (!InMenuCollection->CollectionName.IsNone() && FindMenuCollectionIndex(InMenuCollection->CollectionName) != INDEX_NONE)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterMenuCollection failed because collection name '%s' is already registered."), *InMenuCollection->CollectionName.ToString());
		return false;
	}

	APlayerController* PlayerController = GetPlayerController();
	if (!PlayerController)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterMenuCollection failed because player controller is missing. MenuCollection: %s"), *InMenuCollection->GetName());
		return false;
	}

	if (!InMenuCollection->Initialize(PlayerController))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterMenuCollection failed to initialize menu collection '%s'."), *InMenuCollection->GetName());
		return false;
	}

	RegisteredMenuCollections.Add(InMenuCollection);

	BroadcastMenuCollectionRegisteredMessage(this, InMenuCollection, PlayerController);

	if (bBuildMenu)
	{
		InMenuCollection->BuildMenu();
	}

	return true;
}

UMenuCollection* UMenuSubsystem::RegisterMenuCollection(TSubclassOf<UMenuCollection> InMenuCollectionClass, bool bBuildMenu)
{
	if (!InMenuCollectionClass)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterMenuCollection class failed because menu collection class is null."));
		return nullptr;
	}

	UMenuCollection* MenuCollection = NewObject<UMenuCollection>(this, InMenuCollectionClass);
	if (!MenuCollection)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("RegisterMenuCollection class failed to create menu collection. Class: %s"), *InMenuCollectionClass->GetName());
		return nullptr;
	}

	if (!RegisterMenuCollection(MenuCollection, bBuildMenu))
	{
		return nullptr;
	}

	return MenuCollection;
}

bool UMenuSubsystem::UnregisterMenuCollection(UMenuCollection* InMenuCollection, bool bClearMenu)
{
	if (!IsValid(InMenuCollection))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterMenuCollection failed because menu collection is null."));
		return false;
	}

	const int32 MenuCollectionIndex = FindMenuCollectionIndex(InMenuCollection);
	if (MenuCollectionIndex == INDEX_NONE)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("UnregisterMenuCollection failed because menu collection '%s' is not registered."), *InMenuCollection->GetName());
		return false;
	}

	RegisteredMenuCollections.RemoveAt(MenuCollectionIndex);
	APlayerController* PlayerController = GetPlayerController();

	if (bClearMenu)
	{
		InMenuCollection->ClearMenu();
	}

	BroadcastMenuCollectionUnregisteredMessage(this, InMenuCollection, PlayerController);
	return true;
}

void UMenuSubsystem::ClearMenuCollections(bool bClearMenu)
{
	TArray<TObjectPtr<UMenuCollection>> MenuCollections = RegisteredMenuCollections;

	for (UMenuCollection* MenuCollection : MenuCollections)
	{
		if (IsValid(MenuCollection))
		{
			UnregisterMenuCollection(MenuCollection, bClearMenu);
		}
	}

	RegisteredMenuCollections.Reset();
}

bool UMenuSubsystem::HasMenuCollection(UMenuCollection* InMenuCollection) const
{
	return FindMenuCollectionIndex(InMenuCollection) != INDEX_NONE;
}

UMenuCollection* UMenuSubsystem::GetMenuCollection(FName InCollectionName) const
{
	const int32 MenuCollectionIndex = FindMenuCollectionIndex(InCollectionName);
	return MenuCollectionIndex != INDEX_NONE ? RegisteredMenuCollections[MenuCollectionIndex] : nullptr;
}

UMenuCollection* UMenuSubsystem::GetMenuCollectionByName(FName InCollectionName) const
{
	return GetMenuCollection(InCollectionName);
}

bool UMenuSubsystem::HasMenuCollection(FName InCollectionName) const
{
	return GetMenuCollection(InCollectionName) != nullptr;
}

TArray<UMenuCollection*> UMenuSubsystem::GetAllMenuCollections() const
{
	TArray<UMenuCollection*> MenuCollections;

	for (UMenuCollection* MenuCollection : RegisteredMenuCollections)
	{
		if (IsValid(MenuCollection))
		{
			MenuCollections.Add(MenuCollection);
		}
	}

	return MenuCollections;
}

void UMenuSubsystem::Deinitialize()
{
	ClearMenuCollections(true);
	Super::Deinitialize();
}

int32 UMenuSubsystem::FindMenuCollectionIndex(const UMenuCollection* InMenuCollection) const
{
	if (!IsValid(InMenuCollection))
	{
		return INDEX_NONE;
	}

	for (int32 Index = 0; Index < RegisteredMenuCollections.Num(); ++Index)
	{
		if (RegisteredMenuCollections[Index] == InMenuCollection)
		{
			return Index;
		}
	}

	return INDEX_NONE;
}

int32 UMenuSubsystem::FindMenuCollectionIndex(FName InCollectionName) const
{
	if (InCollectionName.IsNone())
	{
		return INDEX_NONE;
	}

	for (int32 Index = 0; Index < RegisteredMenuCollections.Num(); ++Index)
	{
		const UMenuCollection* MenuCollection = RegisteredMenuCollections[Index];
		if (IsValid(MenuCollection) && MenuCollection->CollectionName == InCollectionName)
		{
			return Index;
		}
	}

	return INDEX_NONE;
}
