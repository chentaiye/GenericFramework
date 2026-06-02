// Copyright ChenTaiye 2026. All Rights Reserved.


#include "BPFunctions_NativeAPI.h"

#include "NativeAPISubsystem.h"
#include "NativeAPIWorldSubsystem.h"

void UBPFunctions_NativeAPI::SendSimulationNativeAPI(const FString& NativeAPIJson)
{
	if (UNativeAPISubsystem* NativeAPISubsystem = GEngine->GetEngineSubsystem<UNativeAPISubsystem>())
	{
		NativeAPISubsystem->SendSimulationNativeAPI(NativeAPIJson);
	}
}

void UBPFunctions_NativeAPI::StartAllFeatureSession()
{
	if (UNativeAPISubsystem* NativeAPISubsystem = GEngine->GetEngineSubsystem<UNativeAPISubsystem>())
	{
		NativeAPISubsystem->StartAllFeatureSession();
	}
}

void UBPFunctions_NativeAPI::EndAllFeatureSession()
{
	if (UNativeAPISubsystem* NativeAPISubsystem = GEngine->GetEngineSubsystem<UNativeAPISubsystem>())
	{
		NativeAPISubsystem->EndAllFeatureSession();
	}
}

void UBPFunctions_NativeAPI::RegisterNativeAPI(const UObject* WorldContextObject, UNativeAPIProxyComponent* InProxy)
{
	if (UNativeAPIWorldSubsystem* NativeAPIWorldSubsystem = UNativeAPIWorldSubsystem::Get(WorldContextObject))
	{
		NativeAPIWorldSubsystem->RegisterNativeAPI(InProxy);
	}
}

void UBPFunctions_NativeAPI::UnRegisterNativeAPI(const UObject* WorldContextObject, UNativeAPIProxyComponent* InProxy)
{
	if (UNativeAPIWorldSubsystem* NativeAPIWorldSubsystem = UNativeAPIWorldSubsystem::Get(WorldContextObject))
	{
		NativeAPIWorldSubsystem->UnRegisterNativeAPI(InProxy);
	}
}
