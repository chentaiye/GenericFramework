// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceFramework.h"

#include "VoiceTypes.h"

DEFINE_LOG_CATEGORY(LogVoiceFramework);
DEFINE_LOG_CATEGORY(LogVoiceWakeup);
DEFINE_LOG_CATEGORY(LogVoiceRecognition);
DEFINE_LOG_CATEGORY(LogVoiceSynthesis);
DEFINE_LOG_CATEGORY(LogVoicePlayback);
DEFINE_LOG_CATEGORY(LogVoiceConversation);

void FVoiceFrameworkModule::StartupModule()
{
	UE_LOG(LogVoiceFramework, Log, TEXT("VoiceFramework startup."));
}

void FVoiceFrameworkModule::ShutdownModule()
{
	UE_LOG(LogVoiceFramework, Log, TEXT("VoiceFramework shutdown."));
}

IMPLEMENT_MODULE(FVoiceFrameworkModule, GenericVoiceFramework)
