// Copyright ChenTaiye 2026. All Rights Reserved.

#include "BPFunctions/BPFunctions_Authorization.h"
#include "Subsystem/GenericAuthorizationSubsystem.h"

UGenericAuthorizationSubsystem* UBPFunctions_Authorization::GetAuthorizationSubsystem(const UObject* WorldContextObject)
{
	return UGenericAuthorizationSubsystem::Get(WorldContextObject);
}

bool UBPFunctions_Authorization::IsBaseAppAuthorized(const UObject* WorldContextObject)
{
	if (const UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject))
	{
		return Subsystem->IsBaseAppAuthorized();
	}

	return false;
}

bool UBPFunctions_Authorization::IsScopeAuthorized(const UObject* WorldContextObject, const FName ScopeId)
{
	if (const UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject))
	{
		return Subsystem->IsScopeAuthorized(ScopeId);
	}

	return false;
}

EAuthorizationState UBPFunctions_Authorization::GetScopeState(const UObject* WorldContextObject, const FName ScopeId)
{
	if (const UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject))
	{
		return Subsystem->GetScopeState(ScopeId);
	}

	return EAuthorizationState::Unauthorized;
}

FString UBPFunctions_Authorization::GetCurrentAuthorizationDeviceId(const UObject* WorldContextObject)
{
	if (const UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject))
	{
		return Subsystem->GetCurrentDeviceId();
	}

	return FString();
}

FString UBPFunctions_Authorization::GetCurrentAuthorizationRequestCode(const UObject* WorldContextObject)
{
	if (const UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject))
	{
		return Subsystem->GetCurrentAuthorizationRequestCode();
	}

	return FString();
}

bool UBPFunctions_Authorization::CanMountPakFile(const UObject* WorldContextObject, const FString& PakFilePath, FName& OutScopeId, EAuthorizationState& OutState)
{
	if (const UGenericAuthorizationSubsystem* Subsystem = UGenericAuthorizationSubsystem::Get(WorldContextObject))
	{
		return Subsystem->CanMountPakFile(PakFilePath, OutScopeId, OutState);
	}

	OutScopeId = NAME_None;
	OutState = EAuthorizationState::Unauthorized;
	return false;
}
