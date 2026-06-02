// Copyright ChenTaiye 2025. All Rights Reserved.

#include "GenericCoreFramework.h"

#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FGenericCoreFrameworkModule"

void FGenericCoreFrameworkModule::StartupModule()
{
	FModuleManager::LoadModuleChecked<IModuleInterface>(TEXT("GenericSlateFramework"));
}

void FGenericCoreFrameworkModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericCoreFrameworkModule, GenericCoreFramework);
