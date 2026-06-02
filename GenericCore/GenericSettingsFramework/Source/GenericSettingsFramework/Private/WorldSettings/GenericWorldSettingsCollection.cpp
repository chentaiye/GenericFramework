// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WorldSettings/GenericWorldSettingsCollection.h"

#include "GameFramework/WorldSettings.h"
#include "UObject/ObjectSaveContext.h"
#include "WorldSettings/GenericWorldSettings.h"

UWorld* UGenericWorldSettingsCollection::GetWorld() const
{
	if (const AWorldSettings* WorldSettings = Cast<AWorldSettings>(GetOuter()))
	{
		return WorldSettings->GetWorld();
	}

	return Super::GetWorld();
}

void UGenericWorldSettingsCollection::PostLoad()
{
	Super::PostLoad();
	RemoveInvalidSettings();
}

#if WITH_EDITOR
void UGenericWorldSettingsCollection::PreSave(FObjectPreSaveContext SaveContext)
{
	RemoveInvalidSettings();
	Super::PreSave(SaveContext);
}

void UGenericWorldSettingsCollection::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	RemoveInvalidSettings();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

UGenericWorldSettings* UGenericWorldSettingsCollection::FindSettings(TSubclassOf<UGenericWorldSettings> SettingsClass) const
{
	return FindSettingsByExactClass(SettingsClass.Get());
}

UGenericWorldSettings* UGenericWorldSettingsCollection::FindSettingsByExactClass(const UClass* SettingsClass) const
{
	if (!SettingsClass)
	{
		return nullptr;
	}

	for (UGenericWorldSettings* Setting : Settings)
	{
		if (IsValid(Setting) && Setting->GetClass() == SettingsClass)
		{
			return Setting;
		}
	}

	return nullptr;
}

#if WITH_EDITOR
UGenericWorldSettings* UGenericWorldSettingsCollection::FindOrCreateSettings(TSubclassOf<UGenericWorldSettings> SettingsClass)
{
	UClass* ResolvedClass = SettingsClass.Get();
	if (!ResolvedClass || ResolvedClass->HasAnyClassFlags(CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists))
	{
		return nullptr;
	}

	RemoveInvalidSettings();
	if (UGenericWorldSettings* ExistingSettings = FindSettingsByExactClass(ResolvedClass))
	{
		return ExistingSettings;
	}

	UGenericWorldSettings* NewSettings = NewObject<UGenericWorldSettings>(this, ResolvedClass, NAME_None, RF_Transactional);
	Settings.Add(NewSettings);
	NewSettings->OnWorldSettingsEditorCreated(GetWorld());

	return NewSettings;
}
#endif

void UGenericWorldSettingsCollection::GetAllSettings(TArray<UGenericWorldSettings*>& OutSettings) const
{
	OutSettings.Reset();

	TSet<const UClass*> VisitedClasses;
	for (UGenericWorldSettings* Setting : Settings)
	{
		const UClass* SettingClass = IsValid(Setting) ? Setting->GetClass() : nullptr;
		if (SettingClass && !VisitedClasses.Contains(SettingClass))
		{
			VisitedClasses.Add(SettingClass);
			OutSettings.Add(Setting);
		}
	}
}

bool UGenericWorldSettingsCollection::RemoveInvalidSettings()
{
	bool bChanged = false;
	TSet<const UClass*> VisitedClasses;

	for (int32 Index = 0; Index < Settings.Num();)
	{
		UGenericWorldSettings* Setting = Settings[Index];
		const UClass* SettingClass = IsValid(Setting) ? Setting->GetClass() : nullptr;
		const bool bInvalidClass = !SettingClass || SettingClass->HasAnyClassFlags(CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists);
		const bool bDuplicateClass = SettingClass && VisitedClasses.Contains(SettingClass);

		if (!IsValid(Setting) || bInvalidClass || bDuplicateClass)
		{
			Settings.RemoveAt(Index);
			bChanged = true;
			continue;
		}

		VisitedClasses.Add(SettingClass);
		++Index;
	}

	return bChanged;
}
