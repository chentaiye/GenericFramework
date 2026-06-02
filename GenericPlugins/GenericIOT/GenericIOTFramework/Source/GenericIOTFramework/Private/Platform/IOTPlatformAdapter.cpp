// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Interface/IOTPlatformAdapter.h"

FName IIOTPlatformAdapterFactoryInterface::GetModularFeatureName()
{
	static const FName FeatureName(TEXT("GenericIOTPlatformAdapterFactory"));
	return FeatureName;
}
