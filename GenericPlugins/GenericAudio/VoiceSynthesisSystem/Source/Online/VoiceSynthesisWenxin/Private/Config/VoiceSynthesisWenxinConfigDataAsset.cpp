// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceSynthesisWenxinConfigDataAsset.h"

UWenxinSynthesisConfigDataAsset::UWenxinSynthesisConfigDataAsset()
{
	ProviderName = TEXT("Wenxin");
	RouteSource = EVoiceRouteSource::Online;
}

bool UWenxinSynthesisConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (WenxinAccessToken.IsEmpty() && (WenxinApiKey.IsEmpty() || WenxinSecretKey.IsEmpty()))
	{
		OutMessage = TEXT("Wenxin synthesis config requires WenxinAccessToken or WenxinApiKey plus WenxinSecretKey.");
		return false;
	}

	OutMessage = TEXT("Wenxin synthesis config is valid.");
	return true;
}
