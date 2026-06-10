// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_Layer.h"

#include "Subsystem/GenericLayerSubsystem.h"

UGenericLayerSubsystem* UBPFunctions_Layer::GetGenericLayerSubsystem(APlayerController* PlayerController)
{
	return UGenericLayerSubsystem::Get(PlayerController);
}

UGenericLayer* UBPFunctions_Layer::GetLayer(APlayerController* PlayerController, FGameplayTag InLayerTag)
{
	const UGenericLayerSubsystem* LayerSubsystem = UGenericLayerSubsystem::Get(PlayerController);
	return LayerSubsystem ? LayerSubsystem->GetLayer(InLayerTag) : nullptr;
}

bool UBPFunctions_Layer::HasLayer(APlayerController* PlayerController, FGameplayTag InLayerTag)
{
	const UGenericLayerSubsystem* LayerSubsystem = UGenericLayerSubsystem::Get(PlayerController);
	return LayerSubsystem ? LayerSubsystem->HasLayer(InLayerTag) : false;
}

bool UBPFunctions_Layer::SetLayerVisibility(APlayerController* PlayerController, FGameplayTag InLayerTag, ESlateVisibility InVisibility)
{
	UGenericLayerSubsystem* LayerSubsystem = UGenericLayerSubsystem::Get(PlayerController);
	return LayerSubsystem ? LayerSubsystem->SetLayerVisibility(InLayerTag, InVisibility) : false;
}

TArray<UGenericLayer*> UBPFunctions_Layer::GetAllLayers(APlayerController* PlayerController)
{
	const UGenericLayerSubsystem* LayerSubsystem = UGenericLayerSubsystem::Get(PlayerController);
	return LayerSubsystem ? LayerSubsystem->GetAllLayers() : TArray<UGenericLayer*>();
}
