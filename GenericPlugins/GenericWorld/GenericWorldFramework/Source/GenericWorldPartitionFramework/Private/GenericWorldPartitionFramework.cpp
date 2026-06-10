#include "GenericWorldPartitionFramework.h"

#define LOCTEXT_NAMESPACE "FGenericWorldPartitionFrameworkModule"

void FGenericWorldPartitionFrameworkModule::StartupModule()
{
	IModuleInterface::StartupModule();
}

void FGenericWorldPartitionFrameworkModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericWorldPartitionFrameworkModule, GenericWorldPartitionFramework)
