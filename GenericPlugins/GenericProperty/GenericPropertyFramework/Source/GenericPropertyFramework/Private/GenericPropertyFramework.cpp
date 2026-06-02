#include "GenericPropertyFramework.h"

#define LOCTEXT_NAMESPACE "FGenericPropertyFrameworkModule"

DEFINE_LOG_CATEGORY(LogGenericPropertyFramework);

void FGenericPropertyFrameworkModule::StartupModule()
{
}

void FGenericPropertyFrameworkModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericPropertyFrameworkModule, GenericPropertyFramework)
