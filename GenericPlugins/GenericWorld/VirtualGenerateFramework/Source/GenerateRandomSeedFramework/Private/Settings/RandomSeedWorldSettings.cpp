// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Settings/RandomSeedWorldSettings.h"

#include "Subsystem/RandomSeedGenerationSubsystem.h"

#if WITH_EDITOR
FName URandomSeedWorldSettings::GetSettingsCategory_Implementation() const
{
	return FName(TEXT("World"));
}
#endif

void URandomSeedWorldSettings::OnWorldSettingsLoaded_Implementation(UWorld* World)
{
	Super::OnWorldSettingsLoaded_Implementation(World);

	if (!World)
	{
		return;
	}

	if (URandomSeedGenerationSubsystem* RandomSeedSubsystem = World->GetSubsystem<URandomSeedGenerationSubsystem>())
	{
		RandomSeedSubsystem->ApplyWorldSeedSettings(bUseCustomSeed, CustomSeed);
	}
}
