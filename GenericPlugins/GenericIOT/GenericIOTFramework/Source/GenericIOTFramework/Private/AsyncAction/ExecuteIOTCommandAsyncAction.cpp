// Copyright ChenTaiye 2026. All Rights Reserved.

#include "AsyncAction/ExecuteIOTCommandAsyncAction.h"

#include "Subsystem/IOTSubsystem.h"

UExecuteIOTCommandAsyncAction* UExecuteIOTCommandAsyncAction::ExecuteIOTCommand(const UObject* WorldContextObject, FIOTCommandRequest InRequest)
{
	UExecuteIOTCommandAsyncAction* Action = NewObject<UExecuteIOTCommandAsyncAction>();
	Action->WorldContextObject = const_cast<UObject*>(WorldContextObject);
	Action->Request = MoveTemp(InRequest);
	return Action;
}

UExecuteIOTCommandAsyncAction* UExecuteIOTCommandAsyncAction::ExecuteRawIOTService(const UObject* WorldContextObject, const FString& DeviceId, const FName Domain, const FName Service, const TMap<FString, FString>& Params)
{
	UExecuteIOTCommandAsyncAction* Action = NewObject<UExecuteIOTCommandAsyncAction>();
	Action->WorldContextObject = const_cast<UObject*>(WorldContextObject);
	Action->bUseRawService = true;
	Action->Request.DeviceId = DeviceId;
	Action->RawDomain = Domain;
	Action->RawService = Service;
	Action->RawParams = Params;
	return Action;
}

void UExecuteIOTCommandAsyncAction::Activate()
{
	UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject);
	if (!Subsystem)
	{
		FIOTCommandResult Result;
		Result.Status = EIOTCommandStatus::PlatformUnavailable;
		Result.ErrorMessage = TEXT("Unable to resolve IOT Subsystem");
		Finish(Result, false);
		return;
	}

	Subsystem->OnCommandCompleted.AddDynamic(this, &UExecuteIOTCommandAsyncAction::HandleCommandCompleted);

	if (bUseRawService)
	{
		Request.RequestId = Subsystem->ExecuteRawService(Request.DeviceId, RawDomain, RawService, RawParams);
		Request.CommandName = FString::Printf(TEXT("Raw:%s.%s"), *RawDomain.ToString(), *RawService.ToString());
	}
	else
	{
		Request.RequestId = Subsystem->ExecuteCommand(Request);
	}

	if (Request.RequestId.IsEmpty())
	{
		FIOTCommandResult Result;
		Result.Status = EIOTCommandStatus::InvalidArgument;
		Result.ErrorMessage = TEXT("Failed to start command execution");
		Finish(Result, false);
	}
}

void UExecuteIOTCommandAsyncAction::HandleCommandCompleted(FIOTCommandRequest InRequest, FIOTCommandResult InResult)
{
	if (InRequest.RequestId == Request.RequestId)
	{
		Finish(InResult, InResult.bSucceeded);
	}
}

void UExecuteIOTCommandAsyncAction::Finish(const FIOTCommandResult& InResult, const bool bSucceeded)
{
	if (UIOTSubsystem* Subsystem = UIOTSubsystem::Get(WorldContextObject))
	{
		Subsystem->OnCommandCompleted.RemoveAll(this);
	}

	if (bSucceeded)
	{
		OnSuccess.Broadcast(InResult);
	}
	else
	{
		OnError.Broadcast(InResult);
	}

	SetReadyToDestroy();
}
