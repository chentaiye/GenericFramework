// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WorldSettings/GenericWorldSettingsSubsystem.h"

#include "Engine/World.h"
#include "GameFramework/WorldSettings.h"
#include "WorldSettings/GenericWorldSettings.h"
#include "WorldSettings/GenericWorldSettingsCollection.h"

UGenericWorldSettingsSubsystem* UGenericWorldSettingsSubsystem::GetWorldSettingsSubsystem(const UObject* WorldContextObject)
{
	const UWorld* World = WorldContextObject ? WorldContextObject->GetWorld() : nullptr;
	return World ? World->GetSubsystem<UGenericWorldSettingsSubsystem>() : nullptr;
}

UGenericWorldSettingsCollection* UGenericWorldSettingsSubsystem::GetSettingsCollection() const
{
	return SettingsCollection;
}

UGenericWorldSettings* UGenericWorldSettingsSubsystem::GetWorldSetting(TSubclassOf<UGenericWorldSettings> SettingsClass) const
{
	return SettingsCollection ? SettingsCollection->FindSettings(SettingsClass) : nullptr;
}

void UGenericWorldSettingsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LoadSettingsCollection();
}

void UGenericWorldSettingsSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	LoadSettingsCollection();
	NotifySettingsBeginPlay();
}

void UGenericWorldSettingsSubsystem::OnWorldMatchStarting()
{
	Super::OnWorldMatchStarting();
	LoadSettingsCollection();
	NotifySettingsMatchStarting();
}

void UGenericWorldSettingsSubsystem::OnWorldPostBeginPlay()
{
	Super::OnWorldPostBeginPlay();
	LoadSettingsCollection();
	NotifySettingsPostBeginPlay();
}

void UGenericWorldSettingsSubsystem::OnWorldBeginTearDown(UWorld* InWorld)
{
	NotifySettingsBeginTearDown();
	NotifySettingsUnloaded();

	Super::OnWorldBeginTearDown(InWorld);

	SettingsCollection = nullptr;
	bSettingsLoadedNotified = false;
	bSettingsBeginPlayNotified = false;
	bSettingsMatchStartingNotified = false;
	bSettingsPostBeginPlayNotified = false;
	bSettingsTearDownNotified = false;
	bSettingsUnloadedNotified = false;
}

void UGenericWorldSettingsSubsystem::Deinitialize()
{
	NotifySettingsUnloaded();
	SettingsCollection = nullptr;

	Super::Deinitialize();
}

bool UGenericWorldSettingsSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

void UGenericWorldSettingsSubsystem::LoadSettingsCollection()
{
	UWorld* World = GetWorld();
	AWorldSettings* WorldSettings = World ? World->GetWorldSettings(false, false) : nullptr;
	SettingsCollection = WorldSettings ? Cast<UGenericWorldSettingsCollection>(WorldSettings->GetAssetUserDataOfClass(UGenericWorldSettingsCollection::StaticClass())) : nullptr;

	if (!SettingsCollection)
	{
		return;
	}

	SettingsCollection->RemoveInvalidSettings();
	NotifySettingsLoaded();
}

void UGenericWorldSettingsSubsystem::GetLoadedSettings(TArray<UGenericWorldSettings*>& OutSettings) const
{
	OutSettings.Reset();
	if (SettingsCollection)
	{
		SettingsCollection->GetAllSettings(OutSettings);
	}
}

void UGenericWorldSettingsSubsystem::NotifySettingsLoaded()
{
	if (bSettingsLoadedNotified || !SettingsCollection)
	{
		return;
	}

	TArray<UGenericWorldSettings*> LoadedSettings;
	GetLoadedSettings(LoadedSettings);

	for (UGenericWorldSettings* Setting : LoadedSettings)
	{
		Setting->OnWorldSettingsLoaded(GetWorld());
	}

	bSettingsLoadedNotified = true;
}

void UGenericWorldSettingsSubsystem::NotifySettingsBeginPlay()
{
	if (bSettingsBeginPlayNotified || !SettingsCollection)
	{
		return;
	}

	TArray<UGenericWorldSettings*> LoadedSettings;
	GetLoadedSettings(LoadedSettings);

	for (UGenericWorldSettings* Setting : LoadedSettings)
	{
		Setting->OnWorldSettingsBeginPlay(GetWorld());
	}

	bSettingsBeginPlayNotified = true;
}

void UGenericWorldSettingsSubsystem::NotifySettingsMatchStarting()
{
	if (bSettingsMatchStartingNotified || !SettingsCollection)
	{
		return;
	}

	TArray<UGenericWorldSettings*> LoadedSettings;
	GetLoadedSettings(LoadedSettings);

	for (UGenericWorldSettings* Setting : LoadedSettings)
	{
		Setting->OnWorldSettingsMatchStarting(GetWorld());
	}

	bSettingsMatchStartingNotified = true;
}

void UGenericWorldSettingsSubsystem::NotifySettingsPostBeginPlay()
{
	if (bSettingsPostBeginPlayNotified || !SettingsCollection)
	{
		return;
	}

	TArray<UGenericWorldSettings*> LoadedSettings;
	GetLoadedSettings(LoadedSettings);

	for (UGenericWorldSettings* Setting : LoadedSettings)
	{
		Setting->OnWorldSettingsPostBeginPlay(GetWorld());
	}

	bSettingsPostBeginPlayNotified = true;
}

void UGenericWorldSettingsSubsystem::NotifySettingsBeginTearDown()
{
	if (bSettingsTearDownNotified || !SettingsCollection)
	{
		return;
	}

	TArray<UGenericWorldSettings*> LoadedSettings;
	GetLoadedSettings(LoadedSettings);

	for (UGenericWorldSettings* Setting : LoadedSettings)
	{
		Setting->OnWorldSettingsBeginTearDown(GetWorld());
	}

	bSettingsTearDownNotified = true;
}

void UGenericWorldSettingsSubsystem::NotifySettingsUnloaded()
{
	if (bSettingsUnloadedNotified || !SettingsCollection)
	{
		return;
	}

	TArray<UGenericWorldSettings*> LoadedSettings;
	GetLoadedSettings(LoadedSettings);
	UWorld* World = GetWorld();

	for (UGenericWorldSettings* Setting : LoadedSettings)
	{
		Setting->OnWorldSettingsUnloaded(World);
	}

	bSettingsUnloadedNotified = true;
}
