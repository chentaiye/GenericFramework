// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_Layout.h"

#include "Subsystem/GenericLayoutSubsystem.h"

UGenericLayoutSubsystem* UBPFunctions_Layout::GetGenericLayoutSubsystem(APlayerController* PlayerController)
{
	return UGenericLayoutSubsystem::Get(PlayerController);
}

bool UBPFunctions_Layout::RegisterLayout(APlayerController* PlayerController, UGenericLayout* InLayout)
{
	UGenericLayoutSubsystem* LayoutSubsystem = UGenericLayoutSubsystem::Get(PlayerController);
	return LayoutSubsystem ? LayoutSubsystem->RegisterLayout(InLayout) : false;
}

UGenericLayout* UBPFunctions_Layout::RegisterLayoutByClass(APlayerController* PlayerController, TSubclassOf<UGenericLayout> InLayoutClass, bool bAddToScreen, ESlateVisibility InVisibility, int32 ZOrder)
{
	UGenericLayoutSubsystem* LayoutSubsystem = UGenericLayoutSubsystem::Get(PlayerController);
	return LayoutSubsystem ? LayoutSubsystem->RegisterLayout(InLayoutClass, bAddToScreen, InVisibility, ZOrder) : nullptr;
}

bool UBPFunctions_Layout::UnregisterLayout(APlayerController* PlayerController, UGenericLayout* InLayout)
{
	UGenericLayoutSubsystem* LayoutSubsystem = UGenericLayoutSubsystem::Get(PlayerController);
	return LayoutSubsystem ? LayoutSubsystem->UnregisterLayout(InLayout) : false;
}

UGenericLayout* UBPFunctions_Layout::GetLayout(APlayerController* PlayerController)
{
	const UGenericLayoutSubsystem* LayoutSubsystem = UGenericLayoutSubsystem::Get(PlayerController);
	return LayoutSubsystem ? LayoutSubsystem->GetLayout() : nullptr;
}

bool UBPFunctions_Layout::HasLayout(APlayerController* PlayerController)
{
	const UGenericLayoutSubsystem* LayoutSubsystem = UGenericLayoutSubsystem::Get(PlayerController);
	return LayoutSubsystem ? LayoutSubsystem->HasLayout() : false;
}
