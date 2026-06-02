// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_Action.h"

#include "Subsystem/GenericActionSubsystem.h"

UGenericActionSubsystem* UBPFunctions_Action::GetGenericActionSubsystem(APlayerController* PlayerController)
{
	return UGenericActionSubsystem::Get(PlayerController);
}

bool UBPFunctions_Action::RegisterActionWidget(APlayerController* PlayerController, UGenericActionWidget* InWidget)
{
	if (UGenericActionSubsystem* ActionSubsystem = UGenericActionSubsystem::Get(PlayerController))
	{
		return ActionSubsystem->RegisterActionWidget(InWidget);
	}

	return false;
}

bool UBPFunctions_Action::UnregisterActionWidget(APlayerController* PlayerController, UGenericActionWidget* InWidget)
{
	if (UGenericActionSubsystem* ActionSubsystem = UGenericActionSubsystem::Get(PlayerController))
	{
		return ActionSubsystem->UnregisterActionWidget(InWidget);
	}

	return false;
}

TArray<UGenericActionWidget*> UBPFunctions_Action::GetAllActionWidgets(APlayerController* PlayerController)
{
	if (UGenericActionSubsystem* ActionSubsystem = UGenericActionSubsystem::Get(PlayerController))
	{
		return ActionSubsystem->GetAllActionWidgets();
	}

	return TArray<UGenericActionWidget*>();
}
