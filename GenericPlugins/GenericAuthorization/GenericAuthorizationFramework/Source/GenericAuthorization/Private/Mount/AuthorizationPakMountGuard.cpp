// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Mount/AuthorizationPakMountGuard.h"
#include "Subsystem/GenericAuthorizationSubsystem.h"

bool FAuthorizationPakMountGuard::CanMountPakFile(const UGenericAuthorizationSubsystem* InSubsystem, const FString& PakFilePath, FName* OutScopeId, EAuthorizationState* OutState)
{
	FName ScopeId = NAME_None;
	EAuthorizationState ScopeState = EAuthorizationState::Unauthorized;
	const bool bCanMount = InSubsystem != nullptr && InSubsystem->CanMountPakFile(PakFilePath, ScopeId, ScopeState);

	if (OutScopeId != nullptr)
	{
		*OutScopeId = ScopeId;
	}

	if (OutState != nullptr)
	{
		*OutState = ScopeState;
	}

	return bCanMount;
}
