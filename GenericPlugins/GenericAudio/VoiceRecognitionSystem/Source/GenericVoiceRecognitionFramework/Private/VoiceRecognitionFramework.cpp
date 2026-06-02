// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceRecognitionFramework.h"

#include "VoiceTypes.h"

void FVoiceRecognitionFrameworkModule::StartupModule()
{
	UE_LOG(LogVoiceRecognition, Log, TEXT("VoiceRecognitionFramework startup."));
}

void FVoiceRecognitionFrameworkModule::ShutdownModule()
{
	UE_LOG(LogVoiceRecognition, Log, TEXT("VoiceRecognitionFramework shutdown."));
}

IMPLEMENT_MODULE(FVoiceRecognitionFrameworkModule, GenericVoiceRecognitionFramework)
