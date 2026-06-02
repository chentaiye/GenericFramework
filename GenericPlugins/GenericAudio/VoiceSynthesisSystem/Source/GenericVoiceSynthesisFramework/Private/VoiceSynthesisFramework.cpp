// Copyright ChenTaiye 2026. All Rights Reserved.

#include "VoiceSynthesisFramework.h"

#include "VoiceTypes.h"

void FVoiceSynthesisFrameworkModule::StartupModule()
{
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisFramework startup."));
}

void FVoiceSynthesisFrameworkModule::ShutdownModule()
{
	UE_LOG(LogVoiceSynthesis, Log, TEXT("VoiceSynthesisFramework shutdown."));
}

IMPLEMENT_MODULE(FVoiceSynthesisFrameworkModule, GenericVoiceSynthesisFramework)
