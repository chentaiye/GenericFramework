#include "GenericSlateFramework.h"

#include "Base/GenericSlateStyle.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FGenericSlateFrameworkModule"

void FGenericSlateFrameworkModule::StartupModule()
{
	FModuleManager::LoadModuleChecked<IModuleInterface>(TEXT("UnrealMisc"));
	FGenericSlateStyle::Initialize();
}

void FGenericSlateFrameworkModule::ShutdownModule()
{
	FGenericSlateStyle::ShoutDown();
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FGenericSlateFrameworkModule, GenericSlateFramework)
