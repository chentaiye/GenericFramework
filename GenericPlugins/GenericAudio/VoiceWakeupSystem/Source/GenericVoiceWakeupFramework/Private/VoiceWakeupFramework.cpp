// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceWakeupFramework.h"

#include "VoiceTypes.h"

void FVoiceWakeupFrameworkModule::StartupModule()
{
	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupFramework startup."));
}

void FVoiceWakeupFrameworkModule::ShutdownModule()
{
	UE_LOG(LogVoiceWakeup, Log, TEXT("VoiceWakeupFramework shutdown."));
}

IMPLEMENT_MODULE(FVoiceWakeupFrameworkModule, GenericVoiceWakeupFramework)
