// Copyright ChenTaiye 2025. All Rights Reserved.

#include "PlayerController/GenericPlayerController.h"

#include "PlayerController/GenericPlayerCameraManager.h"

AGenericPlayerController::AGenericPlayerController()
{
	PlayerCameraManagerClass = AGenericPlayerCameraManager::StaticClass();
}

void AGenericPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController())
	{
		NativeOnPlayerGameHUDCreated();
	}
}

void AGenericPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AGenericPlayerController::NativeOnPlayerGameHUDCreated()
{
	OnPlayerGameHUDCreated();
}
