#include "GenericLevelStreamingFramework.h"

#include "Subsystem/GenericLevelStreamingSubsystem.h"

#define LOCTEXT_NAMESPACE "FGenericLevelStreamingFrameworkModule"

void FGenericLevelStreamingFrameworkModule::StartupModule()
{
	IModuleInterface::StartupModule();
}

void FGenericLevelStreamingFrameworkModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericLevelStreamingFrameworkModule, GenericLevelStreamingFramework)
