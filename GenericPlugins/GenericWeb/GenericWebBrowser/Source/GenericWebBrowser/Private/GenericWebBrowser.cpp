#include "GenericWebBrowser.h"

#include "GenericWebFramework.h"

void FGenericWebBrowserModule::StartupModule()
{
	UE_LOG(LogGenericWeb, Log, TEXT("GenericWebBrowser module started."));
}

void FGenericWebBrowserModule::ShutdownModule()
{
	UE_LOG(LogGenericWeb, Log, TEXT("GenericWebBrowser module shutting down."));
}

IMPLEMENT_MODULE(FGenericWebBrowserModule, GenericWebBrowser)
