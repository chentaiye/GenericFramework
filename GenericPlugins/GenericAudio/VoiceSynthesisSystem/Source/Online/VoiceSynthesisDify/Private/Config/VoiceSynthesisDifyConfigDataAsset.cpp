// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceSynthesisDifyConfigDataAsset.h"

UDifySynthesisConfigDataAsset::UDifySynthesisConfigDataAsset()
{
	ProviderName = TEXT("Dify");
	RouteSource = EVoiceRouteSource::Online;
}

bool UDifySynthesisConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (DifyBaseUrl.IsEmpty() || DifyApiKey.IsEmpty())
	{
		OutMessage = TEXT("Dify synthesis config requires DifyBaseUrl and DifyApiKey.");
		return false;
	}

	OutMessage = TEXT("Dify synthesis config is valid.");
	return true;
}
