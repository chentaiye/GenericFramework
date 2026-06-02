// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceSynthesisDoubaoConfigDataAsset.h"

UDoubaoSynthesisConfigDataAsset::UDoubaoSynthesisConfigDataAsset()
{
	ProviderName = TEXT("Doubao");
	RouteSource = EVoiceRouteSource::Online;
}

bool UDoubaoSynthesisConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (DoubaoAppId.IsEmpty() || DoubaoAccessToken.IsEmpty())
	{
		OutMessage = TEXT("Doubao synthesis config requires DoubaoAppId and DoubaoAccessToken.");
		return false;
	}

	OutMessage = TEXT("Doubao synthesis config is valid.");
	return true;
}
