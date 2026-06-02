// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceRecognitionVolcengineConfigDataAsset.h"

UVolcengineRecognitionConfigDataAsset::UVolcengineRecognitionConfigDataAsset()
{
	ProviderName = TEXT("Volcengine");
	RouteSource = EVoiceRouteSource::Online;
}

bool UVolcengineRecognitionConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (VolcengineAppId.IsEmpty() || VolcengineAccessToken.IsEmpty())
	{
		OutMessage = TEXT("Volcengine recognition config requires VolcengineAppId and VolcengineAccessToken.");
		return false;
	}

	OutMessage = TEXT("Volcengine recognition config is valid.");
	return true;
}
