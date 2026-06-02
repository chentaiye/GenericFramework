// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealMisc.h"

#define LOCTEXT_NAMESPACE "FUnrealMiscModule"

void FUnrealMiscModule::StartupModule()
{
}

void FUnrealMiscModule::ShutdownModule()
{
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnrealMiscModule, UnrealMisc)