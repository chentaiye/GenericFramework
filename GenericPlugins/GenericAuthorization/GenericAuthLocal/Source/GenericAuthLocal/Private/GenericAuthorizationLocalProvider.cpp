// Copyright ChenTaiye 2026. All Rights Reserved.

#include "GenericAuthorizationLocalProvider.h"

#include "Features/IModularFeatures.h"
#include "Provider/AuthorizationServiceFeature.h"
#include "Provider/LocalFileAuthorizationServiceFeature.h"

void FGenericAuthLocalModule::StartupModule()
{
	RegisteredFeatures =
	{
		new FLocalFileAuthorizationServiceFeature()
	};

	for (IAuthorizationServiceFeatureInterface* RegisteredFeature : RegisteredFeatures)
	{
		if (RegisteredFeature == nullptr)
		{
			continue;
		}

		IModularFeatures::Get().RegisterModularFeature(IAuthorizationServiceFeatureInterface::GetFeatureName(), RegisteredFeature);
	}
}

void FGenericAuthLocalModule::ShutdownModule()
{
	for (IAuthorizationServiceFeatureInterface* RegisteredFeature : RegisteredFeatures)
	{
		if (RegisteredFeature == nullptr)
		{
			continue;
		}

		IModularFeatures::Get().UnregisterModularFeature(IAuthorizationServiceFeatureInterface::GetFeatureName(), RegisteredFeature);
		delete RegisteredFeature;
	}

	RegisteredFeatures.Empty();
}

IMPLEMENT_MODULE(FGenericAuthLocalModule, GenericAuthLocal)
