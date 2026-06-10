// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Settings/GameplayFlowWorldSettings.h"

#include "Engine/World.h"
#include "GameplayFlowType.h"
#include "Subsystem/GameplayFlowSubsystem.h"

void UGameplayFlowWorldSettings::OnWorldSettingsPostBeginPlay_Implementation(UWorld* World)
{
	Super::OnWorldSettingsPostBeginPlay_Implementation(World);

	UGameplayFlowSubsystem* GameplayFlowSubsystem = World ? World->GetSubsystem<UGameplayFlowSubsystem>() : nullptr;
	if (!GameplayFlowSubsystem)
	{
		UE_LOG(GenericLogGameplayFlow, Warning, TEXT("GameplayFlowWorldSettings failed to enter because GameplayFlowSubsystem is missing."));
		return;
	}

	GameplayFlowSubsystem->StartGameplayFlow(StateTreeReference.GetMutableStateTree());
}

#if WITH_EDITOR
FName UGameplayFlowWorldSettings::GetSettingsCategory_Implementation() const
{
	return FName(TEXT("GameplayFlow"));
}
#endif
