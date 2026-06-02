// Copyright ChenTaiye 2026. All Rights Reserved.

#include "GenericAuthorization.h"

#include "Startup/AuthorizationStartupGuard.h"

#define LOCTEXT_NAMESPACE "FGenericAuthorizationModule"

void FGenericAuthorizationModule::StartupModule()
{
	StartupGuard = MakeUnique<FAuthorizationStartupGuard>();
	StartupGuard->Startup();
}

void FGenericAuthorizationModule::ShutdownModule()
{
	if (StartupGuard.IsValid())
	{
		StartupGuard->Shutdown();
		StartupGuard.Reset();
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericAuthorizationModule, GenericAuthorization)
