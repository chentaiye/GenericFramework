// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/ActivateAuthorizationAsyncAction.h"
#include "Subsystem/GenericAuthorizationSubsystem.h"

UActivateAuthorizationAsyncAction* UActivateAuthorizationAsyncAction::ActivateAuthorization(UObject* WorldContextObject, const FName ProviderName, const FString& AuthorizationCode, const FString& UserId, const FName RequestedScopeId)
{
	UActivateAuthorizationAsyncAction* Action = NewObject<UActivateAuthorizationAsyncAction>();
	Action->WorldContextObject = WorldContextObject;
	Action->ProviderName = ProviderName;
	Action->AuthorizationCode = AuthorizationCode;
	Action->UserId = UserId;
	Action->RequestedScopeId = RequestedScopeId;
	Action->bImportByTokenText = false;
	return Action;
}

UActivateAuthorizationAsyncAction* UActivateAuthorizationAsyncAction::ActivateAuthorizationByTokenText(UObject* WorldContextObject, const FString& LicenseTokenText, const FString& ManifestText)
{
	UActivateAuthorizationAsyncAction* Action = NewObject<UActivateAuthorizationAsyncAction>();
	Action->WorldContextObject = WorldContextObject;
	Action->LicenseTokenText = LicenseTokenText;
	Action->ManifestText = ManifestText;
	Action->bImportByTokenText = true;
	return Action;
}

void UActivateAuthorizationAsyncAction::Activate()
{
	UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject);
	if (Subsystem == nullptr)
	{
		OnError.Broadcast(EAuthorizationState::Unauthorized, TEXT("Authorization subsystem is unavailable."));
		return;
	}

	FString Message;
	bool bSuccessful = false;

	if (bImportByTokenText)
	{
		if (!ManifestText.IsEmpty())
		{
			bSuccessful = Subsystem->ImportManifestText(ManifestText, Message, true);
			if (!bSuccessful)
			{
				OnError.Broadcast(EAuthorizationState::Unauthorized, Message);
				return;
			}
		}

		bSuccessful = Subsystem->ImportLicenseTokenText(LicenseTokenText, Message, true);
	}
	else
	{
		bSuccessful = Subsystem->ActivateWithProvider(ProviderName, AuthorizationCode, UserId, RequestedScopeId, Message);
	}

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
