// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Settings/NativeAPIWorldSettings.h"

#include "Engine/Engine.h"
#include "NativeAPISubsystem.h"

#if WITH_EDITOR
FName UNativeAPIWorldSettings::GetSettingsCategory_Implementation() const
{
	return FName(TEXT("Communication"));
}
#endif

void UNativeAPIWorldSettings::OnWorldSettingsLoaded_Implementation(UWorld* World)
{
	Super::OnWorldSettingsLoaded_Implementation(World);

	if (GEngine)
	{
		if (UNativeAPISubsystem* NativeAPISubsystem = GEngine->GetEngineSubsystem<UNativeAPISubsystem>())
		{
			NativeAPISubsystem->ActivateWorldSettings(this);
		}
	}
}

void UNativeAPIWorldSettings::OnWorldSettingsBeginTearDown_Implementation(UWorld* World)
{
	if (GEngine)
	{
		if (UNativeAPISubsystem* NativeAPISubsystem = GEngine->GetEngineSubsystem<UNativeAPISubsystem>())
		{
			NativeAPISubsystem->DeactivateWorldSettings(this);
		}
	}

	Super::OnWorldSettingsBeginTearDown_Implementation(World);
}

void UNativeAPIWorldSettings::OnWorldSettingsUnloaded_Implementation(UWorld* World)
{
	if (GEngine)
	{
		if (UNativeAPISubsystem* NativeAPISubsystem = GEngine->GetEngineSubsystem<UNativeAPISubsystem>())
		{
			NativeAPISubsystem->DeactivateWorldSettings(this);
		}
	}

	Super::OnWorldSettingsUnloaded_Implementation(World);
}

void UNativeAPIWorldSettings::OnWorldSettingsBeginDestroy_Implementation()
{
	if (GEngine)
	{
		if (UNativeAPISubsystem* NativeAPISubsystem = GEngine->GetEngineSubsystem<UNativeAPISubsystem>())
		{
			NativeAPISubsystem->DeactivateWorldSettings(this);
		}
	}

	Super::OnWorldSettingsBeginDestroy_Implementation();
}
