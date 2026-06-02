// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceWakeupDoubaoConfigDataAsset.h"

UDoubaoWakeupConfigDataAsset::UDoubaoWakeupConfigDataAsset()
{
	ProviderName = TEXT("Doubao");
	RouteSource = EVoiceRouteSource::Online;
}

bool UDoubaoWakeupConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (DoubaoAppId.IsEmpty() || DoubaoAccessToken.IsEmpty())
	{
		OutMessage = TEXT("Doubao wakeup config requires DoubaoAppId and DoubaoAccessToken.");
		return false;
	}

	OutMessage = TEXT("Doubao wakeup config is valid.");
	return true;
}
