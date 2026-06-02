#include "GenericWebFramework.h"

#define LOCTEXT_NAMESPACE "FGenericWebFrameworkModule"

DEFINE_LOG_CATEGORY(LogGenericWeb);

void FGenericWebFrameworkModule::StartupModule()
{
	UE_LOG(LogGenericWeb, Log, TEXT("GenericWebFramework module started."));
}

void FGenericWebFrameworkModule::ShutdownModule()
{
	UE_LOG(LogGenericWeb, Log, TEXT("GenericWebFramework module shutting down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericWebFrameworkModule, GenericWebFramework)
