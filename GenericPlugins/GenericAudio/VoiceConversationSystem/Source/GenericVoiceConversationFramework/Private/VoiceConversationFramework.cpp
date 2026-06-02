// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceConversationFramework.h"

#include "VoiceTypes.h"

void FVoiceConversationFrameworkModule::StartupModule()
{
	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationFramework startup."));
}

void FVoiceConversationFrameworkModule::ShutdownModule()
{
	UE_LOG(LogVoiceConversation, Log, TEXT("VoiceConversationFramework shutdown."));
}

IMPLEMENT_MODULE(FVoiceConversationFrameworkModule, GenericVoiceConversationFramework)
