// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericBlueprintEditorSubsystem.h"

#include "Misc/EngineVersionComparison.h"

UGenericBlueprintEditorSubsystem* UGenericBlueprintEditorSubsystem::Get()
{
	return GEditor->GetEditorSubsystem<UGenericBlueprintEditorSubsystem>();
}

void UGenericBlueprintEditorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UAssetEditorSubsystem* AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
	AssetEditorSubsystem->OnAssetEditorOpened().AddUObject(this, &UGenericBlueprintEditorSubsystem::OnAssetEditorOpened);
	AssetEditorSubsystem->OnAssetEditorRequestClose().AddUObject(this, &UGenericBlueprintEditorSubsystem::OnAssetEditorRequestClose);
}

void UGenericBlueprintEditorSubsystem::Deinitialize()
{
	Super::Deinitialize();

	if (UAssetEditorSubsystem* AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>())
	{
		AssetEditorSubsystem->OnAssetEditorOpened().RemoveAll(this);
		AssetEditorSubsystem->OnAssetEditorRequestClose().RemoveAll(this);
	}
}

UBlueprint* UGenericBlueprintEditorSubsystem::FindOpenedBlueprintByCDO(UObject* InObject)
{
	for (const auto& OpenedBlueprint : OpenedBlueprints)
	{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
		const UObject* DefaultObject = OpenedBlueprint->GeneratedClass->ClassDefaultObject;
#else
		const UObject* DefaultObject = GetDefault<UObject>(OpenedBlueprint->GeneratedClass);
#endif
		if (DefaultObject == InObject)
		{
			return OpenedBlueprint;
		}
	}

	return nullptr;
}

void UGenericBlueprintEditorSubsystem::OnAssetEditorOpened(UObject* InObject)
{
	UBlueprint* Blueprint = Cast<UBlueprint>(InObject);
	if (IsValid(Blueprint) && !OpenedBlueprints.Contains(Blueprint))
	{
		OpenedBlueprints.Add(Blueprint);
	}
}

void UGenericBlueprintEditorSubsystem::OnAssetEditorRequestClose(UObject* InObject, EAssetEditorCloseReason Reason)
{
	UBlueprint* Blueprint = Cast<UBlueprint>(InObject);
	if (IsValid(Blueprint) && OpenedBlueprints.Contains(Blueprint))
	{
		OpenedBlueprints.Remove(Blueprint);
	}
}
