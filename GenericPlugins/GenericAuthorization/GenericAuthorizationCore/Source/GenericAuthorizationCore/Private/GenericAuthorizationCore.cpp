// Copyright ChenTaiye 2026. All Rights Reserved.

#include "GenericAuthorizationCore.h"
#include "AuthorizationType.h"

#define LOCTEXT_NAMESPACE "FGenericAuthorizationCoreModule"

DEFINE_LOG_CATEGORY(GenericLogAuthorization);

void FGenericAuthorizationCoreModule::StartupModule()
{
}

void FGenericAuthorizationCoreModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericAuthorizationCoreModule, GenericAuthorizationCore)
