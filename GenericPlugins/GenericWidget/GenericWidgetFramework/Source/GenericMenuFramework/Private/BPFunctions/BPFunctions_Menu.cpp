// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_Menu.h"

#include "Subsystem/MenuSubsystem.h"

UMenuSubsystem* UBPFunctions_Menu::GetMenuSubsystem(APlayerController* PlayerController)
{
	return UMenuSubsystem::Get(PlayerController);
}

bool UBPFunctions_Menu::RegisterMenuCollection(APlayerController* PlayerController, UMenuCollection* InMenuCollection, bool bBuildMenu)
{
	UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
	return MenuSubsystem ? MenuSubsystem->RegisterMenuCollection(InMenuCollection, bBuildMenu) : false;
}

UMenuCollection* UBPFunctions_Menu::RegisterMenuCollectionByClass(APlayerController* PlayerController, TSubclassOf<UMenuCollection> InMenuCollectionClass, bool bBuildMenu)
{
	UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
	return MenuSubsystem ? MenuSubsystem->RegisterMenuCollection(InMenuCollectionClass, bBuildMenu) : nullptr;
}

bool UBPFunctions_Menu::UnregisterMenuCollection(APlayerController* PlayerController, UMenuCollection* InMenuCollection, bool bClearMenu)
{
	UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
	return MenuSubsystem ? MenuSubsystem->UnregisterMenuCollection(InMenuCollection, bClearMenu) : false;
}

void UBPFunctions_Menu::ClearMenuCollections(APlayerController* PlayerController, bool bClearMenu)
{
	if (UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController))
	{
		MenuSubsystem->ClearMenuCollections(bClearMenu);
	}
}

bool UBPFunctions_Menu::HasMenuCollection(APlayerController* PlayerController, UMenuCollection* InMenuCollection)
{
	const UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
	return MenuSubsystem ? MenuSubsystem->HasMenuCollection(InMenuCollection) : false;
}

UMenuCollection* UBPFunctions_Menu::GetMenuCollection(APlayerController* PlayerController, FName InCollectionName)
{
	const UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
	return MenuSubsystem ? MenuSubsystem->GetMenuCollection(InCollectionName) : nullptr;
}

UMenuCollection* UBPFunctions_Menu::GetMenuCollectionByName(APlayerController* PlayerController, FName InCollectionName)
{
	const UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
	return MenuSubsystem ? MenuSubsystem->GetMenuCollectionByName(InCollectionName) : nullptr;
}

bool UBPFunctions_Menu::HasMenuCollectionByName(APlayerController* PlayerController, FName InCollectionName)
{
	const UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
	return MenuSubsystem ? MenuSubsystem->HasMenuCollection(InCollectionName) : false;
}

TArray<UMenuCollection*> UBPFunctions_Menu::GetAllMenuCollections(APlayerController* PlayerController)
{
	const UMenuSubsystem* MenuSubsystem = UMenuSubsystem::Get(PlayerController);
	return MenuSubsystem ? MenuSubsystem->GetAllMenuCollections() : TArray<UMenuCollection*>();
}
