// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WorldSettings/GenericWorldSettings.h"

#include "UObject/ObjectSaveContext.h"

UGenericWorldSettings::UGenericWorldSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGenericWorldSettings::PostLoad()
{
	Super::PostLoad();

	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		OnWorldSettingsPostLoad();
	}
}

void UGenericWorldSettings::BeginDestroy()
{
	if (!HasAnyFlags(RF_ClassDefaultObject) && !IsUnreachable())
	{
		OnWorldSettingsBeginDestroy();
	}

	Super::BeginDestroy();
}

#if WITH_EDITOR
void UGenericWorldSettings::PreSave(FObjectPreSaveContext SaveContext)
{
	Super::PreSave(SaveContext);

	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		OnWorldSettingsEditorPreSave(GetWorld());
	}
}

void UGenericWorldSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		OnWorldSettingsEditorChanged(GetWorld());
	}
}

FText UGenericWorldSettings::GetSettingsDisplayName_Implementation() const
{
	const UClass* SettingsClass = GetClass();
	if (!SettingsClass)
	{
		return FText::GetEmpty();
	}

	const FText ClassDisplayName = SettingsClass->GetDisplayNameText();
	return ClassDisplayName.IsEmpty() ? FText::FromString(SettingsClass->GetName()) : ClassDisplayName;
}

FText UGenericWorldSettings::GetSettingsDescription_Implementation() const
{
	return FText::GetEmpty();
}

FName UGenericWorldSettings::GetSettingsCategory_Implementation() const
{
	return FName(TEXT("Default"));
}

bool UGenericWorldSettings::IsWorldSettingsEnabled_Implementation(UWorld* World) const
{
	return true;
}

FText UGenericWorldSettings::GetWorldSettingsDisabledReason_Implementation(UWorld* World) const
{
	return FText::GetEmpty();
}

void UGenericWorldSettings::OnWorldSettingsEditorCreated_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsEditorLoaded_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsEditorChanged_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsEditorPreSave_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsEditorSaved_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsEditorUnloaded_Implementation(UWorld* World)
{
}
#endif

void UGenericWorldSettings::OnWorldSettingsPostLoad_Implementation()
{
}

void UGenericWorldSettings::OnWorldSettingsLoaded_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsBeginPlay_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsMatchStarting_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsPostBeginPlay_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsBeginTearDown_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsUnloaded_Implementation(UWorld* World)
{
}

void UGenericWorldSettings::OnWorldSettingsBeginDestroy_Implementation()
{
}
