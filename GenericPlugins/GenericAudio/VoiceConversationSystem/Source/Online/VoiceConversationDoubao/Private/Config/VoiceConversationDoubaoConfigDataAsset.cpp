// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceConversationDoubaoConfigDataAsset.h"

UDoubaoConversationConfigDataAsset::UDoubaoConversationConfigDataAsset()
{
	ProviderName = TEXT("Doubao");
	RouteSource = EVoiceRouteSource::Online;
}

bool UDoubaoConversationConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (DoubaoAppId.IsEmpty() || DoubaoAccessToken.IsEmpty())
	{
		OutMessage = TEXT("Doubao conversation config requires DoubaoAppId and DoubaoAccessToken.");
		return false;
	}

	OutMessage = TEXT("Doubao conversation config is valid.");
	return true;
}
