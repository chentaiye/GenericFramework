// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceSynthesisVolcengineConfigDataAsset.h"

UVolcengineSynthesisConfigDataAsset::UVolcengineSynthesisConfigDataAsset()
{
	ProviderName = TEXT("Volcengine");
	RouteSource = EVoiceRouteSource::Online;
}

bool UVolcengineSynthesisConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (VolcengineAppId.IsEmpty() || VolcengineAccessToken.IsEmpty())
	{
		OutMessage = TEXT("Volcengine synthesis config requires VolcengineAppId and VolcengineAccessToken.");
		return false;
	}

	OutMessage = TEXT("Volcengine synthesis config is valid.");
	return true;
}
