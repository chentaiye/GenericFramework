// Copyright ChenTaiye 2025. All Rights Reserved.

#include "NativeAPIModule.h"
#include "INativeAPISessionFeature.h"
#include "Features/IModularFeatures.h"
#include "Session/NativeAPISession_WebSocket.h"
#include "Session/NativeAPISession_HTTPRoute.h"

#define LOCTEXT_NAMESPACE "FNativeAPIModule"

void FNativeAPIModule::StartupModule()
{
	RegisteredSessionFeatures =
	{
		new FNativeAPISession_WebSocket,
		new FNativeAPISession_HTTPRoute
	};

	for (INativeAPISessionFeatureInterface* SessionFeature : RegisteredSessionFeatures)
	{
		IModularFeatures::Get().RegisterModularFeature(INativeAPISessionFeatureInterface::GetFeatureName(), SessionFeature);
	}
}

void FNativeAPIModule::ShutdownModule()
{
	for (INativeAPISessionFeatureInterface* SessionFeature : RegisteredSessionFeatures)
	{
		if (SessionFeature == nullptr)
		{
			continue;
		}

		IModularFeatures::Get().UnregisterModularFeature(INativeAPISessionFeatureInterface::GetFeatureName(), SessionFeature);
		delete SessionFeature;
	}

	RegisteredSessionFeatures.Empty();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNativeAPIModule, NativeAPI)
