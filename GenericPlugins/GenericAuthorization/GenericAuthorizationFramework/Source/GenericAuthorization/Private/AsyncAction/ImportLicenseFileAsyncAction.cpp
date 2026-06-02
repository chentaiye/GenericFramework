// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/ImportLicenseFileAsyncAction.h"
#include "Subsystem/GenericAuthorizationSubsystem.h"

UImportLicenseFileAsyncAction* UImportLicenseFileAsyncAction::ImportLicenseFile(UObject* WorldContextObject, const FString& LicenseTokenFilePath, const FString& ManifestFilePath)
{
	UImportLicenseFileAsyncAction* Action = NewObject<UImportLicenseFileAsyncAction>();
	Action->WorldContextObject = WorldContextObject;
	Action->LicenseTokenFilePath = LicenseTokenFilePath;
	Action->ManifestFilePath = ManifestFilePath;
	return Action;
}

void UImportLicenseFileAsyncAction::Activate()
{
	UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject);
	if (Subsystem == nullptr)
	{
		OnError.Broadcast(EAuthorizationState::Unauthorized, TEXT("Authorization subsystem is unavailable."));
		return;
	}

	FString Message;
	if (!ManifestFilePath.IsEmpty() && !Subsystem->ImportManifestFile(ManifestFilePath, Message, true))
	{
		OnError.Broadcast(EAuthorizationState::Unauthorized, Message);
		return;
	}

	const bool bSuccessful = Subsystem->ImportLicenseTokenFile(LicenseTokenFilePath, Message, true);
	const EAuthorizationState BaseState = Subsystem->GetBaseAppState();

	if (bSuccessful)
	{
		OnSuccess.Broadcast(BaseState, Message);
	}
	else
	{
		OnError.Broadcast(BaseState, Message);
	}
}
