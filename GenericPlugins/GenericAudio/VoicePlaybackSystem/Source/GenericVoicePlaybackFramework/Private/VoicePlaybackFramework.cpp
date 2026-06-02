// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoicePlaybackFramework.h"

#include "VoiceTypes.h"

void FVoicePlaybackFrameworkModule::StartupModule()
{
	UE_LOG(LogVoicePlayback, Log, TEXT("VoicePlaybackFramework startup."));
}

void FVoicePlaybackFrameworkModule::ShutdownModule()
{
	UE_LOG(LogVoicePlayback, Log, TEXT("VoicePlaybackFramework shutdown."));
}

IMPLEMENT_MODULE(FVoicePlaybackFrameworkModule, GenericVoicePlaybackFramework)
