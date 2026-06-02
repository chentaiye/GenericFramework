// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Interface/IOTPlatformDiscoveryProvider.h"

FName IIOTPlatformDiscoveryProviderInterface::GetModularFeatureName()
{
	static const FName FeatureName(TEXT("GenericIOTPlatformDiscoveryProvider"));
	return FeatureName;
}
