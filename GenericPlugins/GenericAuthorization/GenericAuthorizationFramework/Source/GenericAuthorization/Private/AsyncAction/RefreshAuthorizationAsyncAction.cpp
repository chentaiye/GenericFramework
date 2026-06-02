// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/RefreshAuthorizationAsyncAction.h"
#include "Subsystem/GenericAuthorizationSubsystem.h"

URefreshAuthorizationAsyncAction* URefreshAuthorizationAsyncAction::RefreshAuthorization(UObject* WorldContextObject, const FName ProviderName)
{
	URefreshAuthorizationAsyncAction* Action = NewObject<URefreshAuthorizationAsyncAction>();
	Action->WorldContextObject = WorldContextObject;
	Action->ProviderName = ProviderName;
	return Action;
}

void URefreshAuthorizationAsyncAction::Activate()
{
	UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject);
	if (Subsystem == nullptr)
	{
		OnError.Broadcast(EAuthorizationState::Unauthorized, TEXT("Authorization subsystem is unavailable."));
		return;
	}

	FString Message;
	const bool bSuccessful = Subsystem->RefreshAuthorization(ProviderName, Message);
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
